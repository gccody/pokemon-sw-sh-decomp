"""Recover function boundaries (start, size) from .eh_frame_hdr / .eh_frame.

Clang emits an FDE for (practically) every function, so this gives exact
function sizes - better than heuristic disassembler analysis.
"""
from __future__ import annotations

import struct

DW_EH_PE_omit = 0xFF


def _uleb(b: bytes, o: int) -> tuple[int, int]:
    r = s = 0
    while True:
        x = b[o]; o += 1
        r |= (x & 0x7F) << s; s += 7
        if not x & 0x80:
            return r, o


def _sleb(b: bytes, o: int) -> tuple[int, int]:
    r = s = 0
    while True:
        x = b[o]; o += 1
        r |= (x & 0x7F) << s; s += 7
        if not x & 0x80:
            if x & 0x40:
                r -= 1 << s
            return r, o


def _read_enc(img: bytes, o: int, enc: int, data_base: int = 0) -> tuple[int, int]:
    fmt = enc & 0x0F
    app = enc & 0x70
    pos = o
    if fmt == 0x00 or fmt == 0x04:
        v = struct.unpack_from("<Q", img, o)[0]; o += 8
    elif fmt == 0x01:
        v, o = _uleb(img, o)
    elif fmt == 0x02:
        v = struct.unpack_from("<H", img, o)[0]; o += 2
    elif fmt == 0x03:
        v = struct.unpack_from("<I", img, o)[0]; o += 4
    elif fmt == 0x09:
        v, o = _sleb(img, o)
    elif fmt == 0x0A:
        v = struct.unpack_from("<h", img, o)[0]; o += 2
    elif fmt == 0x0B:
        v = struct.unpack_from("<i", img, o)[0]; o += 4
    elif fmt == 0x0C:
        v = struct.unpack_from("<q", img, o)[0]; o += 8
    else:
        raise ValueError(f"unsupported pointer encoding {enc:#x}")
    if app == 0x10:
        v += pos
    elif app == 0x30:
        v += data_base
    elif app not in (0x00,):
        raise ValueError(f"unsupported pointer application {enc:#x}")
    return v & 0xFFFFFFFFFFFFFFFF, o


def _cie_fde_encoding(img: bytes, cie: int) -> int:
    length = struct.unpack_from("<I", img, cie)[0]
    o = cie + 8  # length + CIE id
    o += 1  # version
    aug_end = img.index(b"\0", o)
    aug = img[o:aug_end].decode()
    o = aug_end + 1
    _, o = _uleb(img, o)  # code align
    _, o = _sleb(img, o)  # data align
    _, o = _uleb(img, o)  # return reg (version 3+)
    enc = 0x00
    if aug.startswith("z"):
        _, o = _uleb(img, o)  # aug data length
        for c in aug[1:]:
            if c == "R":
                enc = img[o]; o += 1
            elif c == "P":
                penc = img[o]; o += 1
                _, o = _read_enc(img, o, penc)
            elif c == "L":
                o += 1
            elif c in "SB":
                pass
            else:
                break
    assert o <= cie + 4 + length
    return enc


def functions_from_eh_frame(img: bytes, hdr_start: int) -> list[tuple[int, int]]:
    """Return sorted [(start, size)] for every FDE in the module."""
    version, eh_ptr_enc, count_enc, table_enc = img[hdr_start:hdr_start + 4]
    assert version == 1, version
    o = hdr_start + 4
    _eh_frame_ptr, o = _read_enc(img, o, eh_ptr_enc)
    count, o = _read_enc(img, o, count_enc)
    cie_cache: dict[int, int] = {}
    out = []
    for _ in range(count):
        _loc, o = _read_enc(img, o, table_enc, hdr_start)
        fde, o = _read_enc(img, o, table_enc, hdr_start)
        cie_ptr = struct.unpack_from("<I", img, fde + 4)[0]
        cie = fde + 4 - cie_ptr
        enc = cie_cache.get(cie)
        if enc is None:
            enc = cie_cache[cie] = _cie_fde_encoding(img, cie)
        p = fde + 8
        start, p = _read_enc(img, p, enc)
        size, p = _read_enc(img, p, enc & 0x0F)
        out.append((start, size))
    out.sort()
    return out
