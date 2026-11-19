"""tools/nx/argregs.py: the argument registers a function reads and its
callers write, on hand-encoded instruction words (no game files)."""
from __future__ import annotations

import struct

from nx import argregs as A

RET = 0xD65F03C0


def image(funcs: dict[int, list[int]]) -> tuple[bytes, list[tuple[int, int]]]:
    """An image with each function's words at its offset, and its function list."""
    end = max(a + 4 * len(w) for a, w in funcs.items())
    img = bytearray(end)
    for a, words in funcs.items():
        struct.pack_into(f"<{len(words)}I", img, a, *words)
    return bytes(img), sorted((a, 4 * len(w)) for a, w in funcs.items())


def ldr_x(rt, rn, off):
    return 0xF9400000 | (off // 8) << 10 | rn << 5 | rt


def ldr_w(rt, rn, off):
    return 0xB9400000 | (off // 4) << 10 | rn << 5 | rt


def str_w(rt, rn, off):
    return 0xB9000000 | (off // 4) << 10 | rn << 5 | rt


def b(frm, to):
    return 0x14000000 | ((to - frm) >> 2) & 0x3FFFFFF


def bl(frm, to):
    return 0x94000000 | ((to - frm) >> 2) & 0x3FFFFFF


def cbz_x(rt, frm, to):
    return 0xB4000000 | (((to - frm) >> 2) & 0x7FFFF) << 5 | rt


def mov_x(rd, rm):
    return 0xAA0003E0 | rm << 16 | rd   # orr xd, xzr, xm


def mov_w(rd, rm):
    return 0x2A0003E0 | rm << 16 | rd


def movz_w(rd, imm):
    return 0x52800000 | imm << 5 | rd


def stp_x(rt, rt2, rn, off):
    return 0xA9000000 | ((off // 8) & 0x7F) << 15 | rt2 << 10 | rn << 5 | rt


def insns(words: list[int], at: int = 0):
    img, _ = image({at: words})
    return A.decode(img, at, 4 * len(words))


def test_access():
    """Reads (register, width, address base) and writes of a few shapes."""
    assert A.access("ldr", ["x0", "[x1, #8]"]) == ([(1, 8, True)], [(0, 8)])
    assert A.access("str", ["w2", "[x0, x3, lsl #2]"]) == ([(0, 8, True), (3, 8, False), (2, 4, False)], [])
    assert A.access("ldr", ["x8", "[x0, #0x48]!"]) == ([(0, 8, True)], [(0, 8), (8, 8)])
    assert A.access("ldp", ["x29", "x30", "[sp]", "#0x10"]) == ([], [(29, 8), (30, 8)])
    assert A.access("cmp", ["w1", "#3"]) == ([(1, 4, False)], [])
    assert A.access("add", ["x1", "x1", "#8"]) == ([(1, 8, False)], [(1, 8)])
    assert A.access("movk", ["x2", "#1, lsl #16"]) == ([(2, 8, False)], [(2, 8)])
    assert A.access("stxr", ["w8", "x1", "[x0]"]) == ([(0, 8, True), (1, 8, False)], [(8, 4)])
    assert A.access("cbz", ["x3", "#0x10"]) == ([(3, 8, False)], [])


def test_tail_call_passes_on_what_the_callee_reads():
    """ldr x0, [x0, #0x5a0] ; b T, where T reads x1 (cbz x1) and x0 as a base:
    the leaf takes two arguments, x0 a pointer, x1 what T makes of it."""
    leaf = [ldr_x(0, 0, 0x5A0), b(0x4, 0x100)]
    callee = [cbz_x(1, 0x100, 0x10C), ldr_x(8, 1, 0x10), ldr_w(9, 0, 0), RET]
    img, funcs = image({0: leaf, 0x100: callee})
    res = A.Resolver(img, funcs)
    p = res.params(0)
    assert p.count == 2 and p.kind(0) == "ptr" and p.kind(1) == "ptr"
    assert res.params(0x100).count == 2


def test_copies_and_widths():
    """mov x19, x2 ; mov w20, w1 ; cmp w20, #3 ; str w19, [x0] ; ret: x0 a
    pointer, x1 read as 32 bits through its copy, x2 stored as 32 bits."""
    p = A.analyze(insns([mov_x(19, 2), mov_w(20, 1), 0x7100069F, str_w(19, 0, 0), RET]), 0, 20)
    assert p.count == 3
    assert (p.kind(0), p.kind(1), p.kind(2)) == ("ptr", "w", "w")


def test_untouched_registers_at_an_indirect_call():
    """ldr x8, [x0] ; ldr x2, [x8, #0x738] ; br x2: x1 isn't read (nothing says
    the target takes it), x0 is a base."""
    p = A.analyze(insns([ldr_x(8, 0, 0), ldr_x(2, 8, 0x738), 0xD61F0040]), 0, 12)
    assert p.uses == {0: {"ptr"}}


def test_variadic_save_area():
    """stp x6, x7, [sp, #0x30] (a `...` function saving its registers): those
    stores aren't parameters."""
    p = A.analyze(insns([stp_x(6, 7, 31, 0x30), ldr_w(0, 0, 0), RET]), 0, 12)
    assert p.variadic and p.uses == {0: {"ptr"}}
    p = A.analyze(insns([stp_x(1, 2, 31, 0x30), RET]), 0, 8)  # a spill of two arguments: read
    assert not p.variadic and p.count == 3


def test_call_sites():
    """mov w1, #5 ; mov x0, x19 ; bl F: two arguments. A write before a
    conditional branch may be for the other path, and one read again is a
    temporary: neither counts."""
    words = [movz_w(1, 5), mov_x(0, 19), bl(0x8, 0x100)]
    sites = A.call_sites(insns(words), 0, 12, {0x100})
    assert sites == {0x100: [(0x8, 2, {1: "w", 0: "x"})]}
    words = [movz_w(1, 5), cbz_x(0, 0x4, 0xC), bl(0x8, 0x100), RET]   # cbz: x1 may be for the other path
    assert A.call_sites(insns(words), 0, 16, {0x100}) == {0x100: [(0x8, 0, {})]}
    words = [movz_w(2, 5), mov_w(1, 2), bl(0x8, 0x100)]    # x2 read again: a temporary, x1 the argument
    assert A.call_sites(insns(words), 0, 12, {0x100})[0x100][0][1:] == (2, {1: "w"})


def test_callers():
    """B/BL words to the targets, by the function they're in."""
    img, funcs = image({0: [bl(0, 0x100), RET], 0x40: [b(0x40, 0x100)], 0x100: [RET]})
    assert A.callers(img, funcs, {0x100}, len(img)) == {0x100: {0, 0x40}}
