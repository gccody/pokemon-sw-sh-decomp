"""tools/creategen.py: names, the candidates and the class of a creator from
hand-encoded instructions, the written file. No game files."""
from __future__ import annotations

import struct
from types import SimpleNamespace

import creategen as C
import familygen

RET = 0xD65F03C0
HAND = 0x800                # the hand-over function, as C.HAND_OVER


def bl(pc: int, target: int) -> int:
    return 0x94000000 | (((target - pc) >> 2) & 0x3FFFFFF)


def adrp(rd: int, pc: int, target: int) -> int:
    imm = ((target & ~0xFFF) - (pc & ~0xFFF)) >> 12
    return 0x90000000 | ((imm & 3) << 29) | (((imm >> 2) & 0x7FFFF) << 5) | rd


def ldr(rt: int, rn: int, off: int) -> int:     # ldr x<rt>, [x<rn>, #off]
    return 0xF9400000 | ((off // 8) << 10) | (rn << 5) | rt


def str_(rt: int, rn: int, off: int) -> int:    # str x<rt>, [x<rn>, #off]
    return 0xF9000000 | ((off // 8) << 10) | (rn << 5) | rt


def add(rd: int, rn: int, imm: int) -> int:     # add x<rd>, x<rn>, #imm
    return 0x91000000 | (imm << 10) | (rn << 5) | rd


def mov(rd: int, rm: int) -> int:               # mov x<rd>, x<rm>
    return 0xAA0003E0 | (rm << 16) | rd


def image(funcs: dict[int, list[int]], size: int = 0x6000) -> bytes:
    img = bytearray(size)
    for at, words in funcs.items():
        struct.pack_into(f"<{len(words)}I", img, at, *words)
    return bytes(img)


def row(size: int, status: str = "U", name: str = "") -> SimpleNamespace:
    return SimpleNamespace(sword_size=size, status=status, name=name)


def test_names():
    assert C.creator_name("Unk_23f5fa8") == (
        "_ZN16Unk_790260_Owner6CreateI11Unk_23f5fa8EE15Unk_239a418_RefIT_ES2_I11Unk_239a418EPKc")
    assert C.wrapper_name("Unk_23f5fa8") == (
        "_ZN16Unk_790260_Owner10Unk_790140I11Unk_23f5fa8EE15Unk_239a418_RefIT_E"
        "S2_I11Unk_239a418EP11Unk_23f4660PKc")
    assert C.creator_class(C.creator_name("Unk_2449970")) == "Unk_2449970"
    assert C.creator_name("Unk_2449970") == familygen.creator_name("Unk_2449970")   # one name for a creator
    # the creators' old name (a const& and a u64), another member, a length that lies
    assert C.creator_class("_ZN16Unk_790260_Owner6CreateI11Unk_23f5fa8EE15Unk_239a418_RefIT_ERKS2_I11Unk_239a418Em") is None
    assert C.creator_class(C.wrapper_name("Unk_23f5fa8")) is None
    assert C.creator_class(C.creator_name("Unk_23f5fa8").replace("I11Unk", "I12Unk")) is None
    assert C.creator_class("") is None
    assert C.factory_class("_ZN7Unk_New6CreateI11Unk_23c9028JRKPvRKmS6_EEEPT_P21Unk_239a418_AllocatorDpOT0_") == (
        "Unk_23c9028")
    assert C.factory_class("_ZN7Unk_New6CreateI11Unk_23c9028EEPT_v") is None
    assert C.factory_class(C.creator_name("Unk_23c9028")) is None


def test_bl_targets():
    img = image({0x100: [bl(0x100, 0x400), RET, bl(0x108, 0x40), bl(0x10C, 0x2000)]})
    assert C.bl_targets(img, 0x100, 16) == [0x400, 0x40, 0x2000]


def wrapper(at: int, creator: int, hand: int = HAND) -> list[int]:
    # the shape that matters: a creator's call, then the hand-over twice
    return [mov(21, 0), bl(at + 4, creator), mov(0, 19), bl(at + 12, hand), RET, mov(0, 31), bl(at + 24, hand), RET]


def test_candidates():
    funcs = {0x100: wrapper(0x100, 0x1000), 0x200: wrapper(0x200, 0x1100),
             0x300: wrapper(0x300, 0x1200, hand=0x900),             # hands over elsewhere
             0x400: wrapper(0x400, 0x1300)[:-1] + [0xD503201F]}     # another shape (a nop)
    img = image(funcs)
    rows = {a: row(32) for a in funcs}
    rows[0x200].status = "M"
    assert C.candidates(img, rows, seed=0x100, hand_over=HAND) == {0x100: 0x1000, 0x200: 0x1100}
    rows[0x200].status = "L"
    assert C.candidates(img, rows, seed=0x100, hand_over=HAND) == {0x100: 0x1000}


def test_primary_vtable():
    got_a, got_b = 0x5010, 0x5018
    slots = {got_a: 0x23F5FA8, got_b: 0x23F6118, 0x5020: "an_import"}
    at = 0x1000
    w = [mov(0, 21), bl(at + 4, 0x2000)]                      # Unk_23f4660's constructor on x21

    def vptr(reg: int, got: int, dst: int, off: int = 0) -> list[int]:
        pc = at + 4 * len(w)
        return [adrp(reg, pc, got), ldr(reg, reg, got & 0xFFF), add(reg, reg, 0x10), str_(reg, dst, off)]

    w += vptr(8, got_a, 21)                                   # the parent's vptr
    w += vptr(9, got_b, 22)                                   # into another object: not it
    w += vptr(10, got_b, 21, 0x48)                            # a secondary vptr: not it
    img = image({at: w + [RET]})
    assert C.primary_vtable(img, at, 4 * (len(w) + 1), slots, base_ctor=0x2000) == 0x23F5FA8
    w += vptr(8, got_b, 21)                                   # the class's own, stored last
    img = image({at: w + [RET]})
    assert C.primary_vtable(img, at, 4 * (len(w) + 1), slots, base_ctor=0x2000) == 0x23F6118
    # a call in between: what was loaded before it is gone
    w2 = [mov(0, 21), bl(at + 4, 0x2000), adrp(8, at + 8, got_a), ldr(8, 8, got_a & 0xFFF), add(8, 8, 0x10),
          bl(at + 20, 0x3000), str_(8, 21, 0), RET]
    assert C.primary_vtable(image({at: w2}), at, 4 * len(w2), slots, base_ctor=0x2000) is None
    # no constructor call, no object
    assert C.primary_vtable(image({at: [RET]}), at, 4, slots, base_ctor=0x2000) is None
    w3 = [bl(at, 0x2000), RET]
    assert C.primary_vtable(image({at: w3}), at, 8, slots, base_ctor=0x2000) is None


def test_render():
    text = C.render([(0x79A420, "Unk_23a99d8"), (0x790140, "Unk_23f5fa8")])
    assert text.startswith("// Scope: common\n")
    assert "// NON_MATCHING:" in text
    assert text.index("class Unk_23a99d8 : public Unk_23f4660 {};") < text.index(
        "class Unk_23f5fa8 : public Unk_23f4660 {};")
    first = text.index("// 0x7100790140\ntemplate Unk_239a418_Ref<Unk_23f5fa8> Unk_790260_Owner::Unk_790140<Unk_23f5fa8>(")
    assert first < text.index("// 0x710079a420\n")
    assert C.render([(0x790140, "Unk_23f5fa8"), (0x79A420, "Unk_23a99d8")]) == text


def test_plan():
    funcs = {a: wrapper(a, c) for a, c in ((0x100, 0x1000), (0x200, 0x1100), (0x300, 0x1200), (0x400, 0x1300),
                                           (0x500, 0x1400))}
    img = image(funcs, 0x8000)
    rows = {a: row(32) for a in funcs}
    rows[0x1000] = row(64, "O", C.creator_name("Unk_23f5fa8"))      # written by familygen
    rows[0x1100] = row(64)                                            # unnamed: parsed
    rows[0x1200] = row(64)                                            # unnamed, not parsed
    rows[0x1300] = row(64, "U", "_ZN3Foo3BarEv")                       # named otherwise
    rows[0x1400] = row(64, "U", C.creator_name("Unk_23f5fa8"))        # a second wrapper of one class
    rows[0x100].status, rows[0x100].name = "M", C.wrapper_name("Unk_23f5fa8")
    seen = []

    def parse(c):
        seen.append(c)
        return ("Unk_2400000", "") if c == 0x1100 else (None, "vptrs")

    p = C.plan(img, rows, parse, seed=0x100, hand_over=HAND)
    assert sorted(seen) == [0x1100, 0x1200]
    assert p.classes == {0x100: "Unk_23f5fa8", 0x200: "Unk_2400000"}
    assert p.instances == [(0x100, "Unk_23f5fa8")]                 # M with its name: kept; U: not
    assert p.names == {0x100: C.wrapper_name("Unk_23f5fa8")}
    assert dict(p.skipped) == {0x300: "its creator isn't parsed: vptrs", 0x400: "its creator has another name",
                               0x500: "Unk_23f5fa8's wrapper is 0x7100000100"}
    p = C.plan(img, rows, parse, everything=True, seed=0x100, hand_over=HAND)
    assert p.instances == [(0x100, "Unk_23f5fa8"), (0x200, "Unk_2400000")]
    # the creator that isn't written is named too, so the wrapper's call resolves
    assert p.names == {0x100: C.wrapper_name("Unk_23f5fa8"), 0x200: C.wrapper_name("Unk_2400000"),
                       0x1100: C.creator_name("Unk_2400000")}
    p = C.plan(img, rows, parse, only={0x200}, seed=0x100, hand_over=HAND)
    assert p.instances == [(0x100, "Unk_23f5fa8"), (0x200, "Unk_2400000")]
