"""tools/typegen.py: reading type getters and writing their classes, on
hand-encoded instructions (no game files)."""
from __future__ import annotations

import struct
from types import SimpleNamespace

import typegen as T

ACQ, REL = 0x9000, 0x9010        # __cxa_guard_acquire / release
GOT = 0x8000                     # GOT page: slot -> type object or guard
RET = 0xD65F03C0
FRAME = (0xA9BF7BFD, 0x910003FD)  # stp x29, x30, [sp, #-0x10]! ; mov x29, sp
UNFRAME = 0xA8C17BFD             # ldp x29, x30, [sp], #0x10


def adrp(rd: int, pc: int, target: int) -> int:
    imm = ((target & ~0xFFF) - (pc & ~0xFFF)) >> 12
    return 0x90000000 | ((imm & 3) << 29) | (((imm >> 2) & 0x7FFFF) << 5) | rd


def ldr(rt: int, rn: int, off: int) -> int:
    return 0xF9400000 | ((off // 8) << 10) | (rn << 5) | rt


def bl(pc: int, target: int) -> int:
    return 0x94000000 | (((target - pc) >> 2) & 0x3FFFFFF)


def getter(at: int, guard_slot: int, type_slot: int, parent: tuple) -> list[int]:
    """One level: guard test, then (under the guard) the type's parent stored into it.
    parent: ("call", getter) or ("slot", GOT slot of the parent's type) or ("zero",)."""
    w = [*FRAME]

    def emit(x):
        w.append(x if isinstance(x, int) else x(at + 4 * len(w)))

    emit(lambda pc: adrp(8, pc, GOT))
    emit(ldr(8, 8, guard_slot))
    emit(0x08DFFD08)                                  # ldarb w8, [x8]
    emit(lambda pc: adrp(0, pc, GOT))
    emit(ldr(0, 0, guard_slot))
    emit(lambda pc: bl(pc, ACQ))
    if parent[0] == "call":
        emit(lambda pc: bl(pc, parent[1]))
        emit(lambda pc: adrp(8, pc, GOT))
        emit(ldr(8, 8, type_slot))
        emit(0xF9000100)                              # str x0, [x8]
    elif parent[0] == "slot":
        emit(lambda pc: adrp(8, pc, GOT))
        emit(lambda pc: adrp(9, pc, GOT))
        emit(ldr(8, 8, type_slot))
        emit(ldr(9, 9, parent[1]))
        emit(0xF9000109)                              # str x9, [x8]
    else:
        emit(lambda pc: adrp(8, pc, GOT))
        emit(ldr(8, 8, type_slot))
        emit(0xF900011F)                              # str xzr, [x8]
    emit(lambda pc: adrp(0, pc, GOT))
    emit(ldr(0, 0, guard_slot))
    emit(lambda pc: bl(pc, REL))
    emit(lambda pc: adrp(0, pc, GOT))
    emit(ldr(0, 0, type_slot))
    emit(UNFRAME)
    emit(RET)
    return w


# GOT slots: 0x00/0x08 guard/type A, 0x10/0x18 guard/type B
SLOTS = {GOT + 0x00: 0xA000, GOT + 0x08: 0xA008, GOT + 0x10: 0xA010, GOT + 0x18: 0xA018}


def image(funcs: dict[int, list[int]]) -> bytes:
    img = bytearray(0xB000)
    for at, words in funcs.items():
        struct.pack_into(f"<{len(words)}I", img, at, *words)
    return bytes(img)


def test_parse_getter_cut():
    # A's getter calls B's (0x200) out of line.
    a = getter(0x100, 0x00, 0x08, ("call", 0x200))
    img = image({0x100: a})
    g = T.parse_getter(img, 0x100, len(a) * 4, SLOTS, (ACQ, REL))
    assert g is not None
    assert g.top == 0xA008
    assert g.stores == {0xA008: ("ret", 0x200)}
    assert g.calls == [0x200]


def test_parse_getter_inlined_and_root():
    # A's parent B inlined: B's type loaded from the GOT and stored into A's.
    a = getter(0x100, 0x00, 0x08, ("slot", 0x18))
    b = getter(0x200, 0x10, 0x18, ("zero",))
    img = image({0x100: a, 0x200: b})
    ga = T.parse_getter(img, 0x100, len(a) * 4, SLOTS, (ACQ, REL))
    gb = T.parse_getter(img, 0x200, len(b) * 4, SLOTS, (ACQ, REL))
    assert ga.stores == {0xA008: ("obj", 0xA018)} and ga.top == 0xA008 and not ga.calls
    assert gb.stores == {0xA018: ("zero",)} and gb.top == 0xA018


def test_parse_getter_refuses_other_code():
    a = getter(0x100, 0x00, 0x08, ("zero",))
    a.insert(2, 0x8B010000)  # add x0, x0, x1
    img = image({0x100: a})
    assert T.parse_getter(img, 0x100, len(a) * 4, SLOTS, (ACQ, REL)) is None


def test_parse_getter_extra_words():
    a = getter(0x100, 0x00, 0x08, ("zero",))
    a.insert(2, 0xEB08001F)  # cmp x0, x8: refused, unless allowed
    img = image({0x100: a})
    assert T.parse_getter(img, 0x100, len(a) * 4, SLOTS, (ACQ, REL)) is None
    assert T.parse_getter(img, 0x100, len(a) * 4, SLOTS, (ACQ, REL), {0xEB08001F: None}) is not None


def test_names():
    assert T.static_getter("_ZZN11Unk_239bb5811Unk_GetTypeEvE4type") == "Unk_239bb58::Unk_GetType()"
    assert T.static_getter("_ZZ19Unk_239a418_GetTypevE4type") == "Unk_239a418_GetType()"
    assert T.static_getter("_ZZ20Unk_239a418_RootTypevE4type") == "&Unk_239a418_RootType()"
    assert T.static_getter("_ZZN3Foo3barEvE1x") is None
    assert T.member_getter("_ZN11Unk_239b8d811Unk_GetTypeEv") == "Unk_239b8d8"
    assert T.member_getter("_Z10Unk_5b2f90Pv") is None
    assert T.getter_symbol("Unk_239b8d8::Unk_GetType()") == "_ZN11Unk_239b8d811Unk_GetTypeEv"
    assert T.getter_symbol("Unk_239a418_GetType()") == "_Z19Unk_239a418_GetTypev"
    assert T.FORWARD_NAME.fullmatch("_Z10Unk_5b2f90Pv")
    assert T.is_global("&Unk_239a418_RootType()") and not T.is_global("Unk_1::Unk_GetType()")


def fake(getters: dict[int, T.Getter], parent: dict) -> SimpleNamespace:
    return SimpleNamespace(getters=getters, parent=parent, conflicts=set(), slot_of={}, kind_of={})


def test_chain_and_render():
    # Class C (vf_type 0x300) inlines its type 0xA008 and A's parent 0xA018, then
    # calls 0xA028's getter (0x400) out of line.
    v = T.Getter(0x300, {0xA008: ("obj", 0xA018), 0xA018: ("ret", 0x400)}, 0xA008, [0x400])
    g = T.Getter(0x400, {0xA028: ("zero",)}, 0xA028, [])
    t = fake({0x300: v, 0x400: g}, {0xA008: ("obj", 0xA018), 0xA018: ("obj", 0xA028), 0xA028: ("zero",)})
    expr = {0xA008: "Unk_C::Unk_GetType()", 0xA018: "Unk_a018::Unk_GetType()", 0xA028: "Unk_a028::Unk_GetType()"}
    ch = T.chain_of(t, expr, 0x300)
    assert ch == ([0xA008, 0xA018], ("cut", 0x400))
    c = T.ClassPlan("Unk_C", 0x5000, 0x300, [(0x48, 0x310), (0x50, 0x320)], 0xA008, *ch)
    src = T.render(t, expr, [c])
    # the cut getter only declared, the inlined parent defined, the class with its own getter
    assert "struct Unk_a028 {\n    static const Unk_239a418_Type* Unk_GetType();\n};" in src
    assert "static Unk_239a418_Type type(Unk_a028::Unk_GetType());" in src
    assert "static Unk_239a418_Type type(Unk_a018::Unk_GetType());" in src
    assert src.index("struct Unk_a018") < src.index("class Unk_C")
    assert "const Unk_239a418_Type* Unk_C::vf_type() {\n    return Unk_GetType();\n}" in src
    assert "// 0x7100000300\n// 0x7100000310\n// 0x7100000320\n" in src


def test_partition_keeps_inlined_and_declared_apart():
    t = fake({0x400: T.Getter(0x400, {}, 0xA028, [])}, {})
    expr = {0xA008: "Unk_C::Unk_GetType()", 0xA018: "Unk_D::Unk_GetType()", 0xA028: "Unk_a028::Unk_GetType()"}
    # C cuts at 0xA028's getter; D inlines 0xA028: not in one file.
    c = T.ClassPlan("Unk_C", 1, 0x300, [], 0xA008, [0xA008], ("cut", 0x400))
    d = T.ClassPlan("Unk_D", 2, 0x500, [], 0xA018, [0xA018, 0xA028], ("zero",))
    e = T.ClassPlan("Unk_E", 3, 0x600, [], 0xA038, [0xA038], ("zero",))
    expr[0xA038] = "Unk_E::Unk_GetType()"
    parts = T.partition(t, expr, [c, d, e])
    assert [[x.name for x in p] for p in parts] == [["Unk_C", "Unk_E"], ["Unk_D"]]


def test_written_addresses(tmp_path):
    (tmp_path / "Unk_1.cpp").write_text("// 0x7100000300\n// 0x7100000310\ncode\n// not 0x7100000999\n")
    assert T.written_addresses(tmp_path) == {0x300, 0x310}
