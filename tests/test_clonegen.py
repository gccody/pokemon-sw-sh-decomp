"""tools/clonegen.py on hand-encoded instructions (no game files)."""
from __future__ import annotations

import struct

import clonegen as C

NEW = 0x800
VT = 0x5010


def adrp_add(rd: int, pc: int, target: int) -> list[int]:
    imm = ((target & ~0xFFF) - (pc & ~0xFFF)) >> 12
    return [0x90000000 | ((imm & 3) << 29) | (((imm >> 2) & 0x7FFFF) << 5) | rd,
            0x91000000 | ((target & 0xFFF) << 10) | (rd << 5) | rd]


def clone(at: int, mov: int) -> list[int]:
    w = [0xF81E0FF3, 0xA9017BFD, 0x910043FD, 0xAA0003F3, mov]
    w.append(0x94000000 | (((NEW - (at + 20)) >> 2) & 0x3FFFFFF))
    w += adrp_add(8, at + 24, VT)
    w += [0xF9000008, 0xA9417BFD, 0xF9400668, 0xF9000408, 0xF84207F3, 0xD65F03C0]
    return w


def image(funcs: dict[int, list[int]]) -> bytes:
    img = bytearray(0x6000)
    for at, words in funcs.items():
        struct.pack_into(f"<{len(words)}I", img, at, *words)
    return bytes(img)


def test_mov_w0():
    assert C.mov_w0(0x52800200) == 16          # movz w0, #16
    assert C.mov_w0(0x321C03E0) == 16          # orr w0, wzr, #0x10
    assert C.mov_w0(0x321D03E0) == 8
    assert C.mov_w0(0x321E03E0) == 4
    assert C.mov_w0(0xAA0003F3) is None


def test_shapes():
    c = clone(0x100, 0x321C03E0)
    p = [*adrp_add(8, 0x200, VT), 0xF9000028, 0xF9400408, 0xF9000428, 0xD65F03C0]
    img = image({0x100: c, 0x200: p})
    size, at = C.clone_shape(img, 0x100, len(c) * 4, NEW)
    assert size == 16 and C.adrp_add(img, at) == VT
    assert C.place_shape(img, 0x200, len(p) * 4) == 0x200
    assert C.clone_shape(img, 0x100, len(c) * 4, NEW + 4) is None   # calls something else


def test_render():
    src = C.render([("Unk_5000", 0x5010, 0x100, 0x200, 0x18)])
    assert 'class __attribute__((visibility("hidden"))) Unk_5000 {' in src
    assert "    u64 field_8;\n    u64 field_10;\n};" in src
    assert "// 0x7100000100\nUnk_5000* Unk_5000::vf2() {\n    return new Unk_5000(*this);\n}" in src
    assert "// 0x7100000200\nvoid Unk_5000::vf3(Unk_5000* p) {\n    new (p) Unk_5000(*this);\n}" in src
