"""Minimal readers for Switch containers: XCI -> HFS0 -> NCA -> PFS0 (ExeFS).

Only what the decomp needs: pull the ExeFS (main, main.npdm, rtld, sdk, subsdk*)
out of a cartridge dump without copying the multi-GB program NCA to disk.
"""
from __future__ import annotations

import struct
from dataclasses import dataclass
from pathlib import Path
from typing import BinaryIO

from Crypto.Cipher import AES


# --------------------------------------------------------------------------- keys
def load_keys(path: Path) -> dict[str, bytes]:
    keys: dict[str, bytes] = {}
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        if "=" not in line:
            continue
        name, _, value = line.partition("=")
        value = value.strip().replace(" ", "")
        try:
            keys[name.strip().lower()] = bytes.fromhex(value)
        except ValueError:
            continue  # ignore malformed / unusual entries
    return keys


def default_keys_path() -> Path:
    return Path.home() / ".switch" / "prod.keys"


# --------------------------------------------------------------------------- HFS0 / XCI
@dataclass
class Entry:
    name: str
    offset: int  # absolute offset in the backing file
    size: int


def read_hfs0(f: BinaryIO, off: int) -> list[Entry]:
    f.seek(off)
    magic, count, strsize = struct.unpack("<4sII4x", f.read(16))
    if magic != b"HFS0":
        raise ValueError(f"bad HFS0 magic at {off:#x}: {magic!r}")
    raw = [struct.unpack("<QQII8x32s", f.read(0x40)) for _ in range(count)]
    strings = f.read(strsize)
    data = off + 16 + count * 0x40 + strsize
    out = []
    for rel, size, stroff, _hashsz, _hash in raw:
        name = strings[stroff:strings.index(b"\0", stroff)].decode()
        out.append(Entry(name, data + rel, size))
    return out


def xci_secure_partition(f: BinaryIO) -> list[Entry]:
    f.seek(0x100)
    if f.read(4) != b"HEAD":
        raise ValueError("not an XCI (missing HEAD magic)")
    f.seek(0x130)
    (root_off,) = struct.unpack("<Q", f.read(8))
    root = {e.name: e for e in read_hfs0(f, root_off)}
    return read_hfs0(f, root["secure"].offset)


# --------------------------------------------------------------------------- AES-XTS (Nintendo tweak)
def _gf_mul_alpha(t: bytearray) -> None:
    carry = 0
    for i in range(16):
        nc = t[i] >> 7
        t[i] = ((t[i] << 1) | carry) & 0xFF
        carry = nc
    if carry:
        t[0] ^= 0x87


def xts_decrypt(key: bytes, data: bytes, sector: int, sector_size: int = 0x200) -> bytes:
    k1 = AES.new(key[:16], AES.MODE_ECB)
    k2 = AES.new(key[16:32], AES.MODE_ECB)
    out = bytearray()
    for s in range(0, len(data), sector_size):
        tweak = bytearray(k2.encrypt(sector.to_bytes(16, "big")))  # Nintendo: big-endian sector no.
        chunk = data[s:s + sector_size]
        for b in range(0, len(chunk), 16):
            blk = bytes(x ^ y for x, y in zip(chunk[b:b + 16], tweak))
            out += bytes(x ^ y for x, y in zip(k1.decrypt(blk), tweak))
            _gf_mul_alpha(tweak)
        sector += 1
    return bytes(out)


# --------------------------------------------------------------------------- NCA
CONTENT_TYPES = {0: "Program", 1: "Meta", 2: "Control", 3: "Manual", 4: "Data", 5: "PublicData"}


@dataclass
class NcaSection:
    index: int
    start: int  # offset inside NCA
    end: int
    fs_type: int
    crypt_type: int
    header: bytes


class Nca:
    def __init__(self, f: BinaryIO, base: int, keys: dict[str, bytes]):
        self.f, self.base, self.keys = f, base, keys
        f.seek(base)
        self.header = xts_decrypt(keys["header_key"], f.read(0xC00), 0)
        h = self.header
        if h[0x200:0x204] != b"NCA3":
            raise ValueError(f"unsupported NCA magic {h[0x200:0x204]!r}")
        self.content_type = h[0x205]
        self.title_id = struct.unpack_from("<Q", h, 0x210)[0]
        self.sdk_version = struct.unpack_from("<I", h, 0x21C)[0]
        if any(h[0x230:0x240]):
            raise ValueError("NCA uses a rights ID (titlekey crypto) - use a cartridge dump or decrypted NCA")
        gen = max(h[0x206], h[0x220])
        rev = gen - 1 if gen > 0 else 0
        kak_idx = h[0x207]
        kak_name = ("key_area_key_application", "key_area_key_ocean", "key_area_key_system")[kak_idx]
        kak = keys.get(f"{kak_name}_{rev:02x}")
        if kak is None:
            raise KeyError(f"missing {kak_name}_{rev:02x} in keys file")
        ecb = AES.new(kak, AES.MODE_ECB)
        self.key_area = [ecb.decrypt(h[0x300 + i * 16:0x310 + i * 16]) for i in range(4)]
        self.sections: list[NcaSection] = []
        for i in range(4):
            start, end = struct.unpack_from("<II", h, 0x240 + i * 0x10)
            if start == end == 0:
                continue
            fsh = h[0x400 + i * 0x200:0x600 + i * 0x200]
            self.sections.append(NcaSection(i, start * 0x200, end * 0x200, fsh[0x2], fsh[0x4], fsh))

    def read_section(self, sec: NcaSection, rel_off: int, size: int) -> bytes:
        """Read `size` decrypted bytes from offset `rel_off` within section `sec`."""
        abs_off = sec.start + rel_off
        aligned = abs_off & ~0xF
        lead = abs_off - aligned
        self.f.seek(self.base + aligned)
        raw = self.f.read(lead + size)
        if sec.crypt_type == 1:  # none
            return raw[lead:]
        if sec.crypt_type != 3:
            raise NotImplementedError(f"section crypto type {sec.crypt_type}")
        upper = sec.header[0x140:0x148][::-1]  # generation + secure value, reversed
        ctr = upper + (aligned >> 4).to_bytes(8, "big")
        aes = AES.new(self.key_area[2], AES.MODE_CTR, nonce=b"", initial_value=ctr)
        return aes.decrypt(raw)[lead:]

    def pfs0_base(self, sec: NcaSection) -> int:
        """Offset of the PFS0 inside a HierarchicalSha256 section."""
        if sec.header[0x3] != 2:
            raise NotImplementedError("only HierarchicalSha256 PFS0 sections are supported")
        layer_count = struct.unpack_from("<I", sec.header, 0x2C)[0]
        # layer regions start at 0x30, each (offset u64, size u64); PFS0 is the last one
        off, _size = struct.unpack_from("<QQ", sec.header, 0x30 + (layer_count - 1) * 0x10)
        return off


def read_pfs0(nca: Nca, sec: NcaSection) -> dict[str, bytes]:
    base = nca.pfs0_base(sec)
    hdr = nca.read_section(sec, base, 0x10)
    magic, count, strsize = struct.unpack("<4sII4x", hdr)
    if magic != b"PFS0":
        raise ValueError("section is not PFS0")
    meta = nca.read_section(sec, base + 0x10, count * 0x18 + strsize)
    strings = meta[count * 0x18:]
    data_base = base + 0x10 + count * 0x18 + strsize
    files = {}
    for i in range(count):
        off, size, stroff = struct.unpack_from("<QQI", meta, i * 0x18)
        name = strings[stroff:strings.index(b"\0", stroff)].decode()
        files[name] = nca.read_section(sec, data_base + off, size)
    return files


def extract_exefs_from_xci(xci: Path, keys: dict[str, bytes]) -> tuple[dict[str, bytes], Nca]:
    with open(xci, "rb") as f:
        for entry in xci_secure_partition(f):
            if not entry.name.endswith(".nca") or entry.name.endswith(".cnmt.nca"):
                continue
            nca = Nca(f, entry.offset, keys)
            if nca.content_type != 0:
                continue
            for sec in nca.sections:
                if sec.fs_type != 1:  # PFS0
                    continue
                files = read_pfs0(nca, sec)
                if "main" in files and "main.npdm" in files:
                    return files, nca
    raise ValueError(f"no Program NCA with an ExeFS found in {xci}")
