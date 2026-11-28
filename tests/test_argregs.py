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


# The narrow uses of w1 (llvm-mc's encodings).
AND_W2_W1_FF = 0x12001C22     # and w2, w1, #0xff
UXTB_W8_W1 = 0x53001C28       # uxtb w8, w1
SXTB_W8_W1 = 0x13001C28       # sxtb w8, w1
UXTH_W8_W1 = 0x53003C28       # uxth w8, w1
SXTH_W8_W1 = 0x13003C28       # sxth w8, w1
STRB_W1 = 0x39002001          # strb w1, [x0, #8]
STRH_W1 = 0x79001001          # strh w1, [x0, #8]
CMP_UXTB = 0x6B21011F         # cmp w8, w1, uxtb
CMP_SXTB = 0x6B21811F         # cmp w8, w1, sxtb
CMP_UXTH = 0x6B21211F         # cmp w8, w1, uxth
TST_FF = 0x72001C3F           # tst w1, #0xff
TBZ_3 = 0x36180201            # tbz w1, #3, +0x40
TBZ_12 = 0x36600201           # tbz w1, #12, +0x40
CMP_5 = 0x7100143F            # cmp w1, #5
AND_3F = 0x12001428           # and w8, w1, #0x3f
AND_FFFF = 0x12003C28         # and w8, w1, #0xffff
UBFIZ_8 = 0x531D1C28          # ubfiz w8, w1, #3, #8
MOV_W19_W1 = 0x2A0103F3       # mov w19, w1
STR_W1 = 0xB9000801           # str w1, [x0, #8]
AND_X9_X1_FF = 0x92401C29     # and x9, x1, #0xff
ADD_W8_W1_1 = 0x11000428      # add w8, w1, #1


def narrow(words: list[int]) -> str | None:
    return A.analyze(insns(words + [RET]), 0, 4 * len(words) + 4).int_type(1)


def test_width_use():
    """Each instruction's use of register 1, from capstone's text."""
    cases = {AND_W2_W1_FF: "u8", UXTB_W8_W1: "u8", SXTB_W8_W1: "s8", UXTH_W8_W1: "u16", SXTH_W8_W1: "s16",
             STRB_W1: "8", STRH_W1: "16", CMP_UXTB: "u8", CMP_SXTB: "s8", CMP_UXTH: "u16", TST_FF: "8",
             TBZ_3: "n8", TBZ_12: "n16", CMP_5: "full", AND_3F: "n8", AND_FFFF: "u16", UBFIZ_8: "u8",
             STR_W1: "full", AND_X9_X1_FF: "u8", ADD_W8_W1_1: "full"}
    for word, want in cases.items():
        (_, mn, ops), = insns([word])
        assert A.width_use(mn, ops, 1) == want, (hex(word), mn, ops)
    (_, mn, ops), = insns([ldr_w(8, 1, 0)])
    assert A.width_use(mn, ops, 1) == "full"     # an address
    (_, mn, ops), = insns([STRB_W1])
    assert A.width_use(mn, ops, 0) == "full"     # strb's base


def test_narrow_type():
    assert A.narrow_type({"u8", "8", "n8"}) == "u8"
    assert A.narrow_type({"s8", "n8"}) == "s8"
    assert A.narrow_type({"16", "n8", "n16"}) == "u16"
    assert A.narrow_type({"n8"}) is None            # bits inside a byte: a u32 does that too
    assert A.narrow_type({"u8", "full"}) is None    # one read uses more
    assert A.narrow_type({"u8", "u16"}) is None     # the widths disagree
    assert A.narrow_type({"u8", "n16"}) is None
    assert A.narrow_type({"u8", "s8"}) is None      # the signedness does
    assert A.narrow_type(set()) is None


def test_int_type_from_its_own_code():
    """An argument is u8 (u16, s8, s16) only when every read of it is one of
    those widths and one of them uses all of its bits."""
    assert narrow([AND_W2_W1_FF]) == "u8"                  # `and w2, w1, #0xff ; b T`'s shape
    assert narrow([CMP_UXTB, STRB_W1]) == "u8"
    assert narrow([STRB_W1, TBZ_3]) == "u8"
    assert narrow([SXTB_W8_W1]) == "s8"
    assert narrow([UXTH_W8_W1, STRH_W1]) == "u16"
    assert narrow([SXTH_W8_W1]) == "s16"
    assert narrow([AND_X9_X1_FF]) == "u8"                  # the 64-bit mask of it
    assert narrow([MOV_W19_W1, 0x53001E68]) == "u8"        # through a copy: uxtb w8, w19
    assert narrow([TBZ_3]) is None                         # a bit test alone proves nothing
    assert narrow([AND_3F]) is None
    assert narrow([CMP_UXTB, CMP_5]) is None               # cmp w1, #5 reads all 32 bits
    assert narrow([STRB_W1, STR_W1]) is None
    assert narrow([UXTB_W8_W1, UXTH_W8_W1]) is None        # u8 and u16 reads: they disagree
    assert narrow([UXTB_W8_W1, SXTB_W8_W1]) is None
    assert narrow([STRB_W1, ADD_W8_W1_1]) is None
    assert narrow([mov_w(19, 1)]) is None                  # copied, never read: nothing says
    assert narrow([ldr_w(8, 1, 0)]) is None                # a pointer


def test_int_type_on_one_path_only():
    """Every path counts: cbz x0 skips the strb, the other path compares all 32 bits."""
    words = [cbz_x(0, 0x0, 0xC), STRB_W1, RET, CMP_5]
    assert A.analyze(insns(words + [RET]), 0, 20).int_type(1) is None
    words = [cbz_x(0, 0x0, 0xC), STRB_W1, RET, TST_FF]
    assert A.analyze(insns(words + [RET]), 0, 20).int_type(1) == "u8"


def test_int_type_passed_on():
    """A register only passed on to a callee proves nothing, even to a u8
    parameter (a u32 passed to one needs no instruction either); passed on
    to one and extended here, it's that."""
    leaf = [mov_w(2, 1), b(0x4, 0x100)]
    callee = [0x53001C48, RET]   # uxtb w8, w2
    img, funcs = image({0: leaf, 0x100: callee})
    res = A.Resolver(img, funcs)
    assert res.params(0x100).int_type(2) == "u8"
    assert res.params(0).int_type(1) is None
    leaf = [STRB_W1, mov_w(2, 1), b(0x8, 0x100)]
    img, funcs = image({0: leaf, 0x100: callee})
    assert A.Resolver(img, funcs).params(0).int_type(1) == "u8"
    wide = [ADD_W8_W1_1 & ~0x3E0 | 2 << 5, RET]   # add w8, w2, #1: all 32 bits
    img, funcs = image({0: leaf, 0x100: wide})
    assert A.Resolver(img, funcs).params(0).int_type(1) is None


def test_params_from_types():
    p = A.Params.from_types(["void*", "u8", "f32", "s16", "u32", "u64", "bool"])
    assert [p.kind(i) for i in range(6)] == ["ptr", "w", "w", "w", "x", "w"]   # f32 is in s0
    assert [p.int_type(i) for i in range(6)] == [None, "u8", "s16", None, None, None]
