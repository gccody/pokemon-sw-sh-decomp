"""tools/shapes.py: the shapes functions are grouped by, on hand-encoded words
and a hand-written object (no game files)."""
from __future__ import annotations

import struct
from types import SimpleNamespace

import shapes
from test_elfobj import SHF_ALLOC, SHF_EXECINSTR, SHT_PROGBITS, write_elf

RET = 0xD65F03C0
BL = 0x94000000            # bl #0
B = 0x14000000             # b #0
ADRP_X8 = 0x90000008       # adrp x8, #0
ADD_X8_X8 = 0x91000108     # add x8, x8, #0
LDR_X8_X8 = 0xF9400108     # ldr x8, [x8]
ADD_X0_X1 = 0x91000020     # add x0, x1, #0
LDR_X0_X1 = 0xF9400020     # ldr x0, [x1]


def imm26(w: int, n: int) -> int:
    return w | (n & 0x3FFFFFF)


def adrp(w: int, page: int) -> int:
    return w | ((page & 3) << 29) | (((page >> 2) & 0x7FFFF) << 5)


def lo12(w: int, n: int) -> int:
    return w | ((n & 0xFFF) << 10)


def test_mask_words_masks_branch_targets_and_page_pairs():
    words = [imm26(BL, 0x1234), imm26(B, 0x3FFFFFF), adrp(ADRP_X8, 0x55), lo12(ADD_X8_X8, 0x10),
             lo12(LDR_X8_X8, 0x2A), RET]
    assert shapes.mask_words(words) == [BL, B, ADRP_X8, ADD_X8_X8, LDR_X8_X8, RET]


def test_mask_words_keeps_offsets_off_a_page():
    # x1 was never set by an ADRP: its offsets are fields of an object, part of the shape
    words = [lo12(ADD_X0_X1, 0x78), lo12(LDR_X0_X1, 0x7), RET]
    assert shapes.mask_words(words) == words


def test_shape_ignores_what_calls_and_pages_reach():
    a = struct.pack("<4I", imm26(BL, 5), adrp(ADRP_X8, 1), lo12(LDR_X8_X8, 3), RET)
    b = struct.pack("<4I", imm26(BL, 9), adrp(ADRP_X8, 7), lo12(LDR_X8_X8, 4), RET)
    c = struct.pack("<4I", imm26(BL, 5), adrp(ADRP_X8, 1), lo12(LDR_X0_X1, 3), RET)
    assert shapes.shape(a) == shapes.shape(b) != shapes.shape(c)


def test_object_shapes_hashes_each_function():
    f = struct.pack("<2I", imm26(BL, 0), RET)
    g = struct.pack("<2I", imm26(BL, 0x40), RET)   # the same shape, called elsewhere
    text = f + g
    data = write_elf([(".text", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR, text, 0, 0, 0)],
                     [("f", 0x12, 1, 0, 8), ("g", 0x12, 1, 8, 8), ("d", 0x11, 1, 0, 4)])
    out = shapes.object_shapes(data)
    assert set(out) == {"f", "g"}   # "d" is an object, not a function
    assert out["f"] == out["g"] == shapes.shape(f)


def test_ranked_orders_by_bytes():
    row = lambda size: SimpleNamespace(sword_size=size, sword=0)  # noqa: E731
    groups = {"a": [row(8)] * 3, "b": [row(100)] * 2, "c": [row(500)]}
    assert [s for s, _ in shapes.ranked(groups)] == ["b", "a"]
    assert [s for s, _ in shapes.ranked(groups, min_count=1)] == ["c", "b", "a"]
