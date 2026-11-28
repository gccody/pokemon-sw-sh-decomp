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


def test_vf_type_classes_counts_definitions_only(tmp_path):
    (tmp_path / "a.cpp").write_text(
        "class Unk_1 : public B {\npublic:\n    const T* vf_type() override;\n};\n"
        "class Unk_2 : public B {\npublic:\n    const T* vf_type() override { return x(); }\n};\n"
        "const T* Unk_3::vf_type() {\n    return y();\n}\n")
    assert T.vf_type_classes(tmp_path, tmp_path / "types") == {"Unk_2", "Unk_3"}
    assert T.vf_type_classes(tmp_path, tmp_path / "types", inline=False) == {"Unk_3"}


def test_taken_classes_keeps_what_is_written_here(tmp_path):
    out = tmp_path / "types"
    out.mkdir()
    (tmp_path / "a.h").write_text(
        "class Unk_1 : public B {\npublic:\n    static const T* Unk_GetType() {\n        return x();\n    }\n};\n"
        "class Unk_2 : public B {\npublic:\n    const T* vf_type() override { return x(); }\n};\n"
        "class Unk_5 : public B {\npublic:\n    const T* vf_type() override { return x(); }\n};\n")
    (tmp_path / "b.cpp").write_text("const T* Unk_3::vf_type() {\n    return y();\n}\n")
    # Written here: Unk_2 (inline elsewhere: kept), Unk_3 (strong elsewhere: taken), Unk_4.
    (out / "Unk_1.cpp").write_text(
        "// 0x7100000300\nconst Unk_239a418_Type* Unk_2::vf_type() {\n    return Unk_GetType();\n}\n"
        "// 0x7100000310\nconst Unk_239a418_Type* Unk_3::vf_type() {\n    return Unk_GetType();\n}\n"
        "// 0x7100000320\nconst Unk_239a418_Type* Unk_4::vf6() {\n    return Unk_4::Unk_GetType();\n}\n")
    assert T.written_classes(out) == {"Unk_2", "Unk_3", "Unk_4"}
    taken, declared = T.taken_classes(tmp_path, out)
    assert taken == {"Unk_1", "Unk_3", "Unk_5"}
    assert declared == {"Unk_1", "Unk_2", "Unk_3", "Unk_5"}


def test_kept_needs_a_match_not_only_a_name():
    rows = {0x300: SimpleNamespace(status="O", name="_ZN5Unk_C7vf_typeEv"),
            0x400: SimpleNamespace(status="U", name="_ZN5Unk_C11Unk_GetTypeEv")}
    names = [(0x300, "_ZN5Unk_C7vf_typeEv"), (0x400, "_ZN5Unk_C11Unk_GetTypeEv")]
    assert not T.kept(rows, set(), names)        # the getter is named (by a trial), not matched
    assert T.kept(rows, {0x400}, names)          # it matched in the trial
    rows[0x400].status = "O"
    assert T.kept(rows, set(), names)
    assert not T.kept(rows, set(), [(0x300, "_ZN5Unk_C3vf6Ev")])  # matched, under another name


# The object's vtable group, as offset in the object -> slots: D2, D0, vf2-vf5;
# the +0x48 interface's D1/D0 thunks, three thunks and its vf_type; the +0x50
# one's vf_type and D1/D0 thunks.
OBJ = {0: [0x10, 0x11, 0x12, 0x13, 0x14, 0x15], 0x48: [0x20, 0x21, 0x22, 0x23, 0x24, 0x25], 0x50: [0x30, 0x31, 0x32]}


def derived(**changes) -> dict[int, list]:
    """A class on the object: its own D0 and destructor thunks (0x1xx), its
    vf_type (slot 6) and the interfaces' type slots, the rest the object's."""
    out = {0: [0x10, 0x111, 0x12, 0x13, 0x14, 0x15, 0x116], 0x48: [0x120, 0x121, 0x22, 0x23, 0x24, 0x125],
           0x50: [0x130, 0x131, 0x132]}
    for k, v in changes.items():
        o, i = (int(x, 16) for x in k[1:].split("_"))
        out[o][i] = v
    return out


def copies(f: int, g: int) -> bool:
    return f - 0x100 == g  # 0x1xx is a copy of the object's 0xx


def test_emitted_dtors_names_the_d0_and_the_thunks():
    assert T.emitted_dtors("Unk_X", derived(), OBJ, copies) == [
        (0x111, "_ZN5Unk_XD0Ev"), (0x120, "_ZThn72_N5Unk_XD1Ev"), (0x121, "_ZThn72_N5Unk_XD0Ev"),
        (0x131, "_ZThn80_N5Unk_XD1Ev"), (0x132, "_ZThn80_N5Unk_XD0Ev")]


def test_emitted_dtors_refuses_other_classes():
    # a D2 of its own: its destructor isn't implicit
    assert T.emitted_dtors("Unk_X", derived(s0_0=0x100), OBJ, copies) is None
    # an override of its own (vf3), or a slot more: its key function is elsewhere
    assert T.emitted_dtors("Unk_X", derived(s0_3=0x113), OBJ, copies) is None
    longer = derived()
    longer[0].append(0x107)
    assert T.emitted_dtors("Unk_X", longer, OBJ, copies) is None
    # a D0 that isn't a copy of the object's (a trap, a tail call)
    assert T.emitted_dtors("Unk_X", derived(s48_1=0x999), OBJ, copies) is None
    # the object's own D0 (inherited): nothing of its own to emit
    assert T.emitted_dtors("Unk_X", derived(s0_1=0x11), OBJ, copies) is None
    # another layout (one interface)
    assert T.emitted_dtors("Unk_X", {0: derived()[0], 0x48: derived()[0x48]}, OBJ, copies) is None


def test_same_code_compares_shape_and_size():
    # two copies that reach different vtables through the GOT (masked), and one that stores elsewhere
    def d0(at: int, got: int, off: int) -> list[int]:
        return [lambda pc: adrp(8, pc, got), ldr(8, 8, 0x150), 0xF9000008 | (off // 8) << 10, RET]

    funcs = {0x100: d0(0x100, 0x8000, 0), 0x200: d0(0x200, 0x9000, 0), 0x300: d0(0x300, 0x8000, 8)}
    img = image({a: [w(a + 4 * i) if callable(w) else w for i, w in enumerate(ws)] for a, ws in funcs.items()})
    m = SimpleNamespace(img=img, sizes={0x100: 16, 0x200: 16, 0x300: 16, 0x400: 12})
    assert T.same_code(m, 0x100, 0x200)
    assert not T.same_code(m, 0x100, 0x300)
    assert not T.same_code(m, 0x100, 0x400)


def test_render_declares_a_class_with_emitted_dtors_on_the_object():
    t = fake({}, {0xA008: ("zero",)})
    expr = {0xA008: "Unk_C::Unk_GetType()"}
    dtors = [(0x101, "_ZN5Unk_CD0Ev"), (0x120, "_ZThn72_N5Unk_CD1Ev")]
    # vf_type's thunks are getter copies: they're written as before
    c = T.ClassPlan("Unk_C", 0x5000, 0x300, [(0x48, 0x310), (0x50, 0x320)], 0xA008, [0xA008], ("zero",),
                    dtors=dtors)
    src = T.render(t, expr, [c])
    assert "class Unk_C : public Unk_239a418 {\npublic:\n" in src
    assert "~Unk_C()" not in src  # implicit: vf_type is the key function
    assert "// 0x7100000101\n// 0x7100000120\nclass Unk_C" in src
    assert "// 0x7100000300\n// 0x7100000310\n// 0x7100000320\nconst Unk_239a418_Type* Unk_C::vf_type()" in src
    # a bare one (its thunks `sub ; b vf_type`) is declared on the object too, its thunks listed
    b = T.ClassPlan("Unk_C", 0x5000, 0x300, [(0x48, 0x310), (0x50, 0x320)], 0xA008, [0xA008], ("zero",),
                    bare=True, dtors=dtors)
    src = T.render(t, expr, [b])
    assert "class Unk_C : public Unk_239a418 {" in src and "vf_type() override;" in src
    assert "// 0x7100000300\n// 0x7100000310\n// 0x7100000320\n" in src
    # without them, a bare class stays a plain struct
    src = T.render(t, expr, [T.ClassPlan("Unk_C", 0x5000, 0x300, [(0x48, 0x310)], 0xA008, [0xA008], ("zero",),
                                         bare=True)])
    assert "struct Unk_C {" in src and "// 0x7100000310" not in src
