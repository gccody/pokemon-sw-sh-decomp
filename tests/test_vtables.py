"""tools/vtables.py: finding vtables, groups, owners, bases and the placeholder
classes, on a hand-built image (no game files)."""
from __future__ import annotations

import struct

import pytest

import vtables as V

RET = 0xD65F03C0
TRAP = 0xE7FFDEFE
DATA = 0x1000          # the "data segment" of the image
DELETE = 0x80          # operator delete(void*)


def b(pc: int, target: int) -> int:
    return 0x14000000 | (((target - pc) >> 2) & 0x3FFFFFF)


def build():
    """Functions at 0x100.. and three vtables plus a function table in data.

    0x1010 A: primary, slots [0x100 ret (D2), 0x110 b delete (D0), 0x120 mov w0,#5 ; ret, 0x130 big]
    0x1038.. A's secondary (offset-to-top -16): [0x140 thunk]
    0x1058 B: primary, derived from A: [0x100 (A's D2), 0x150 b delete, 0x120 (inherited), 0x160 ret, pure]
    0x1090: two function pointers with no vtable header (a plain table)
    """
    img = bytearray(0x1100)
    code = {0x100: [RET], 0x110: [b(0x110, DELETE)], 0x120: [0x528000A0, RET],  # mov w0, #5 ; ret
            0x130: [0xAA0003E8, 0xAA0003E9, RET], 0x140: [0xD1004000, b(0x144, 0x120)],
            0x150: [b(0x150, DELETE)], 0x160: [RET], 0x170: [RET], 0x180: [RET], DELETE: [RET]}
    for addr, words in code.items():
        struct.pack_into(f"<{len(words)}I", img, addr, *words)
    slots = {}

    def vt(start, ott, fns):
        struct.pack_into("<q", img, start, ott)   # offset-to-top
        struct.pack_into("<q", img, start + 8, 0)  # no typeinfo
        for i, f in enumerate(fns):
            slots[start + 16 + 8 * i] = f
        return start + 16 + 8 * len(fns)

    end = vt(0x1000, 0, [0x100, 0x110, 0x120, 0x130])
    end = vt(end, -16, [0x140])
    vt(end, 0, [0x100, 0x150, 0x120, 0x160, "__cxa_pure_virtual"])
    struct.pack_into("<q", img, 0x1088, 7)        # not an offset-to-top
    slots[0x1090], slots[0x1098] = 0x170, 0x180
    starts = {s for s in code if s != DELETE} | {DELETE}
    sizes = {s: 4 * len(w) for s, w in code.items()}
    return bytes(img), slots, starts, sizes


def test_find_vtables_and_groups():
    img, slots, starts, _ = build()
    vts, tables = V.find_vtables(img, slots, starts, DATA, len(img))
    assert [(v.addr, v.offset_to_top, len(v.slots)) for v in vts] == [
        (0x1010, 0, 4), (0x1040, -16, 1), (0x1058, 0, 5)]
    assert [v.group for v in vts] == [0x1010, 0x1010, 0x1058]
    assert vts[2].slots[4] == "__cxa_pure_virtual"
    assert vts[0].start == 0x1000
    assert tables == [(0x1090, 2)]


def test_owners_and_bases():
    img, slots, starts, _ = build()
    vts, _ = V.find_vtables(img, slots, starts, DATA, len(img))
    own = V.owners(vts)
    # A's D2 is shared with B (B's empty destructor aliases it): A, the shorter vtable, owns it.
    assert own[0x100] == (0x1010, 0)
    assert own[0x120] == (0x1010, 2)
    assert own[0x160] == (0x1058, 3)
    assert own[0x140] == (0x1040, 0)
    assert V.bases(vts)[0x1058] == (0x1010, 2)
    assert 0x1010 not in V.bases(vts)


def test_find_referrers_through_the_got():
    img, slots, starts, _ = build()
    vts, _ = V.find_vtables(img, slots, starts, DATA, len(img))
    img = bytearray(img)
    # A function at 0x200 loads A's _ZTV from a GOT slot: adrp x8, 0x1000 ; ldr x8, [x8, #0xa0]
    got = 0x10A0
    slots[got] = 0x1000
    struct.pack_into("<3I", img, 0x200, 0xB0000008, 0xF9400000 | (0xA0 // 8) << 10 | 8 << 5 | 8, RET)
    V.find_referrers(bytes(img), [(0x200, 12)], vts, slots)
    assert vts[0].referrers == {0x200}
    assert vts[1].referrers == {0x200}       # the secondary shares its group's
    assert not vts[2].referrers


def model():
    img, slots, starts, sizes = build()
    vts, tables = V.find_vtables(img, slots, starts, DATA, len(img))
    return V.Model("sword", img, sorted(sizes.items()), vts, tables, sizes, {}, {}, lambda a: "game", DELETE)


def test_slot_kinds():
    m = model()
    assert V.slot_kind(m.pattern(0x100)) == "ret"
    assert V.slot_kind(m.pattern(0x120)) == "constant"
    assert V.slot_kind(m.pattern(0x140)) == "thunk"
    assert V.slot_kind(m.pattern(0x110)) == "forward"
    assert V.slot_kind(None) == "pure"


def test_destructor_pairs():
    m = model()
    a, _, bvt = m.vtables
    assert V.destructor_pair(m, a) == "empty"
    assert V.destructor_pair(m, bvt) == "empty"      # D0 deletes, D2 is A's (an alias)
    assert V.destructor_pair(m, m.vtables[1]) is None


def specs(m, seg=lambda f: 0):
    own = V.owners(m.vtables)
    picked = {v.addr: ms for v in m.vtables if (ms := V.placeholder_members(m, v, own, lambda f: True))}
    return V.class_specs(m, picked, own, seg, lambda f: True)


def test_placeholder_class():
    m = model()
    a, _, bvt = m.vtables
    own = V.owners(m.vtables)
    members = V.placeholder_members(m, a, own, lambda f: True)
    assert [(x.slot, x.kind, x.value) for x in members] == [(0, "dtor", 0), (2, "constant", 5)]
    spec = V.class_specs(m, {a.addr: members}, own, lambda f: 0, lambda f: True)[a.addr]
    decl, names, defs = V.render_class(m, spec)
    assert decl == ("class Unk_1000 {\npublic:\n    virtual ~Unk_1000();\n    virtual u32 vf2();\n"
                    "    virtual void vf3();\n};\n")
    assert "Unk_1000::~Unk_1000() {}" in defs
    assert "u32 Unk_1000::vf2() {\n    return 5;\n}" in defs
    assert names == [(0x100, "_ZN8Unk_1000D2Ev"), (0x110, "_ZN8Unk_1000D0Ev"), (0x120, "_ZN8Unk_10003vf2Ev")]
    # B doesn't own its slot 0 (A's D2), so its destructors aren't written; its own ret is.
    members = V.placeholder_members(m, bvt, own, lambda f: True)
    assert [(x.slot, x.kind) for x in members] == [(3, "ret")]


def test_derived_class():
    """B's slot 0 is A's D2 and its D0 is `b operator delete`: B derives from A,
    its destructor is implicit and its D0 is named. It declares only what
    differs from A: slot 3 (an override, its key function) and slot 4 (new)."""
    m = model()
    a, _, bvt = m.vtables
    s = specs(m)
    b, base = s[bvt.addr], s[a.addr]
    assert b.base is base and b.order == [3, 4] and not base.inline_dtor
    assert [(x.slot, x.kind) for x in b.members] == [(3, "ret"), (1, "d0")]
    decl, names, defs = V.render_class(m, b)
    assert decl == ("class Unk_1048 : public Unk_1000 {\npublic:\n    void vf3() override;\n"
                    "    virtual void vf4() = 0;\n};\n")
    assert names == [(0x150, "_ZN8Unk_1048D0Ev"), (0x160, "_ZN8Unk_10483vf3Ev")]
    assert "void Unk_1048::vf3() {}" in defs
    text, names = V.render_file(m, [(b, b.members)])
    assert text.index("class Unk_1000 {") < text.index("class Unk_1048 : public Unk_1000 {")
    assert "~Unk_1000() {}" not in text      # A is only declared here: its destructor is defined elsewhere


def test_derived_class_in_another_file_makes_the_base_destructor_inline():
    m = model()
    a, _, bvt = m.vtables
    s = specs(m, seg=lambda f: 1 if f in (0x150, 0x160) else 0)
    assert s[bvt.addr].base is s[a.addr] and s[a.addr].inline_dtor
    decl, names, defs = V.render_class(m, s[a.addr])
    assert "    virtual ~Unk_1000() {}\n" in decl and "~Unk_1000() {}" not in defs
    # Still named in A's file: A's key function (vf2, defined there) emits its vtable and destructors.
    assert names[:2] == [(0x100, "_ZN8Unk_1000D2Ev"), (0x110, "_ZN8Unk_1000D0Ev")]


def test_derived_class_needs_a_key_function_in_its_d0s_file():
    m = model()
    _, _, bvt = m.vtables
    assert specs(m, seg=lambda f: 1 if f == 0x150 else 0)[bvt.addr].base is None


def test_forwarder():
    """A `b T` slot becomes `Unk_<T>(this);` when callee() accepts T, and T is named too."""
    img, slots, starts, sizes = build()
    img = bytearray(img)
    struct.pack_into("<I", img, 0x130, b(0x130, 0x170))     # A's slot 3: b 0x170
    sizes[0x130] = 4
    vts, tables = V.find_vtables(bytes(img), slots, starts, DATA, len(img))
    m = V.Model("sword", bytes(img), sorted(sizes.items()), vts, tables, sizes, {}, {}, lambda a: "game", DELETE)
    a = m.vtables[0]
    own = V.owners(m.vtables)
    assert [x.kind for x in V.placeholder_members(m, a, own, lambda f: True)] == ["dtor", "constant"]
    assert V.branch_target(m, 0x130) == 0x170
    members = V.placeholder_members(m, a, own, lambda f: True, lambda f: V.branch_target(m, f))
    assert [(x.slot, x.kind, x.value) for x in members][-1] == (3, "forward", 0x170)
    spec = V.class_specs(m, {a.addr: members}, own, lambda f: 0, lambda f: True)[a.addr]
    _, names, defs = V.render_class(m, spec)
    assert "void Unk_1000::vf3() {\n    Unk_170(this);\n}" in defs
    assert names[-2:] == [(0x130, "_ZN8Unk_10003vf3Ev"), (0x170, "_Z7Unk_170Pv")]
    text, _ = V.render_file(m, [(spec, members)])
    assert "\nvoid Unk_170(void* self);\n" in text


def lifted_model(words):
    """build(), with A's slot 3 (0x130) replaced by `words`."""
    img, slots, starts, sizes = build()
    img = bytearray(img)
    struct.pack_into(f"<{len(words)}I", img, 0x130, *words)
    sizes[0x130] = 4 * len(words)
    vts, tables = V.find_vtables(bytes(img), slots, starts, DATA, len(img))
    return V.Model("sword", bytes(img), sorted(sizes.items()), vts, tables, sizes, {}, {}, lambda a: "game", DELETE)


def test_lifted_member():
    """A setter in a vtable becomes a member that sets the class's own field."""
    m = lifted_model([0xB9001001, RET])                      # str w1, [x0, #0x10] ; ret
    x = V.lift_member(m, 0x130)
    assert x == V.Lifted("void", ("u32 value",), "    field_10 = value;\n", ((0x10, "u32"),), "Unk_130")
    a = m.vtables[0]
    own = V.owners(m.vtables)
    members = V.placeholder_members(m, a, own, lambda f: True, None, lambda f: V.lift_member(m, f))
    spec = V.class_specs(m, {a.addr: members}, own, lambda f: 0, lambda f: True)[a.addr]
    decl, names, defs = V.render_class(m, spec)
    assert "    virtual void vf3(u32 value);\n    u8 _8[0x8];\n    u32 field_10;\n};\n" in decl
    assert "PKMN_OFFSET_ASSERT(Unk_1000, field_10, 0x10);" in decl
    assert "void Unk_1000::vf3(u32 value) {\n    field_10 = value;\n}" in defs
    assert names[-1] == (0x130, "_ZN8Unk_10003vf3Ej")


def test_lifted_member_refuses_the_vptr():
    assert V.lift_member(lifted_model([0xB9400000, RET]), 0x130) is None     # ldr w0, [x0]


def test_lifted_member_through_a_pointer_field():
    """ldr x0, [x0, #0x10] ; ldr w0, [x0, #0x10]: field_10 points to the struct Unk_1000_10."""
    m = lifted_model([0xF9400800, 0xB9401000, RET])
    x = V.lift_member(m, 0x130)
    assert x.fields == ((0x10, ("*", ((0x10, "u32"),))),)
    a = m.vtables[0]
    own = V.owners(m.vtables)
    members = V.placeholder_members(m, a, own, lambda f: True, None, lambda f: V.lift_member(m, f))
    spec = V.class_specs(m, {a.addr: members}, own, lambda f: 0, lambda f: True)[a.addr]
    assert spec.fields == {0x10: {0x10: "u32"}}
    decl, names, defs = V.render_class(m, spec)
    assert decl.startswith("struct Unk_1000_10 {\n    u8 _0[0x10];\n    u32 field_10;\n};\n"
                           "PKMN_OFFSET_ASSERT(Unk_1000_10, field_10, 0x10);\n\nclass Unk_1000 {")
    assert "    u8 _8[0x8];\n    Unk_1000_10* field_10;\n};\n" in decl
    assert "u32 Unk_1000::vf3() {\n    return field_10->field_10;\n}" in defs
    # Another member reading field_10 as a plain integer conflicts with it.
    assert not V.merge_fields(spec.fields, [(0x10, "u64")])
    assert V.merge_fields(spec.fields, [(0x10, ("*", ((0x18, "u8"),)))])
    assert spec.fields == {0x10: {0x10: "u32", 0x18: "u8"}}


def test_lifted_member_with_a_tail_call():
    """ldr x0, [x0, #0x10] ; b +0x100: field_10 passed to the tail call's target."""
    m = lifted_model([0xF9400800, b(0x134, 0x234)])
    x = V.lift_member(m, 0x130)
    assert x.callee == (0x234, ("u64",)) and x.body == "    Unk_234(field_10);\n"
    assert V.tail_callee(x.callee) == (0x234, "_Z7Unk_234m")
    m = lifted_model([0x528000A1, b(0x134, 0x234)])        # mov w1, #5: this is passed on
    assert V.lift_member(m, 0x130).body == "    Unk_234(this, 5);\n"


def test_lifted_member_with_a_global():
    """adrp x8, +1 page ; ldr x8, [x8, #0x10] ; ldr w0, [x8] ; ret: the GOT slot holds a global's address."""
    m = lifted_model([0xB0000008, 0xF9400000 | (0x10 // 8) << 10 | 8 << 5 | 8, 0xB9400100, RET])
    assert V.lift_member(m, 0x130) is None                  # no GOT: refused
    m.got = {0x1010: 0x5000}
    x = V.lift_member(m, 0x130)
    assert x.globals == ((0x5000, "u32"),) and x.body == "    return Unk_5000;\n"
    a = m.vtables[0]
    own = V.owners(m.vtables)
    members = V.placeholder_members(m, a, own, lambda f: True, None, lambda f: V.lift_member(m, f))
    spec = V.class_specs(m, {a.addr: members}, own, lambda f: 0, lambda f: True)[a.addr]
    text, _ = V.render_file(m, [(spec, members)])
    assert "\nextern u32 Unk_5000;\n" in text and "u32 Unk_1000::vf3() {\n    return Unk_5000;\n}" in text
    m.got = {0x1010: 0x130}                                 # a function's address: refused
    assert V.lift_member(m, 0x130) is None


def test_string_member():
    """adrp x0, S ; add x0, x0, S ; ret with S a string: `return "...";`."""
    m = lifted_model([0x90000000, 0x91100000, RET])        # adrp x0, 0 ; add x0, x0, #0x400
    img = bytearray(m.img)
    img[0x400:0x40e] = b'Say "hi" \\ 1\0'
    m = V.Model("sword", bytes(img), m.funcs, m.vtables, m.tables, m.sizes, {}, {}, lambda a: "game", DELETE)
    m._rodata = (0x400, 0x500)
    assert V.string_return(m, 0x130) == 'Say \\"hi\\" \\\\ 1'
    x = V.Member(3, 0x130, "string", V.string_return(m, 0x130))
    assert V.simple_body(x) == '{\n    return "Say \\"hi\\" \\\\ 1";\n}'
    m._rodata = (0x500, 0x600)                              # not a string there
    assert V.string_return(m, 0x130) is None


def test_element_member():
    """add x8, x0, x1, lsl #5 ; ldr x0, [x8, #8] ; ret: field_0 of 32-byte entries right after the vptr."""
    m = lifted_model([0x8B011408, 0xF9400500, RET])
    x = V.element_member(m, 0x130, 3)
    assert (x.slot, x.kind, x.value) == (3, "element", (5, 8))
    a = m.vtables[0]
    own = V.owners(m.vtables)
    members = V.placeholder_members(m, a, own, lambda f: True, None, None, True)
    assert members[-1].kind == "element"
    spec = V.class_specs(m, {a.addr: members}, own, lambda f: 0, lambda f: True)[a.addr]
    decl, names, defs = V.render_class(m, spec)
    assert "struct Unk_1000_Entry {\n    void* field_0;\n    u8 _8[0x18];\n};\n" in decl
    assert "    virtual void* vf3(u64 index);\n    Unk_1000_Entry m_entries[1];\n};\n" in decl
    assert "void* Unk_1000::vf3(u64 index) {\n    return m_entries[index].field_0;\n}" in defs
    assert names[-1] == (0x130, "_ZN8Unk_10003vf3Em")
    assert V.element_member(lifted_model([0x8B011408, 0xF9400100, RET]), 0x130, 3) is None  # [x8]: the vptr


def test_table_merge():
    t = V.Table(0x20)
    assert t.merge(V.Member(1, 0, "element", (5, 0x10)))
    assert t.merge(V.Member(3, 0, "element_call", (5, 0x10, 0x18, 0x80)))
    assert t.fields == {8: "obj", 0x10: "u64"} and t.obj_slot == 16
    assert not t.merge(V.Member(4, 0, "element", (4, 0x10)))              # another stride
    assert not t.merge(V.Member(5, 0, "element_call", (5, 0x10, 0x18, 0x88)))  # another slot


def test_derived_from_an_external_base():
    """D derives from hand-written E: its slot 0 is E's D2, its D0 is `b <E's D2>`,
    its secondary vtable's destructor slots are `sub x0, x0, #8 ; b <E's D2>`, and
    its type slot and the secondary one are `b T` to its own type getter."""
    img = bytearray(0x1200)
    sub8 = 0xD1002000                                       # sub x0, x0, #8
    code = {0x100: [0xAA0003E8, 0xAA0003E9, RET],           # E's D2
            0x120: [RET], 0x130: [0xAA0003E8, RET],         # E's slot 2, its type getter
            0x140: [b(0x140, 0x100)],                        # D's D0
            0x150: [sub8, b(0x154, 0x100)], 0x160: [sub8, b(0x164, 0x100)],
            0x170: [b(0x170, 0x300)], 0x180: [b(0x180, 0x300)],  # D's type slot, its thunk
            0x300: [0xAA0003E8, 0xAA0003E9, RET],           # D's type getter
            0x110: [RET], 0x190: [RET], 0x1a0: [RET], 0x1b0: [RET]}
    for a, w in code.items():
        struct.pack_into(f"<{len(w)}I", img, a, *w)
    slots = {}

    def vt(start, ott, fns):
        struct.pack_into("<q", img, start, ott)
        for i, f in enumerate(fns):
            slots[start + 16 + 8 * i] = f
        return start + 16 + 8 * len(fns)

    end = vt(0x1000, 0, [0x100, 0x110, 0x120, 0x130])           # E
    end = vt(end, -8, [0x190, 0x1a0, 0x1b0])                    # E at +8
    end = vt(end, 0, [0x100, 0x140, 0x120, 0x170])              # D
    vt(end, -8, [0x150, 0x160, 0x180])                          # D at +8
    sizes = {a: 4 * len(w) for a, w in code.items()}
    vts, tables = V.find_vtables(bytes(img), slots, set(code), DATA, len(img))
    m = V.Model("sword", bytes(img), sorted(sizes.items()), vts, tables, sizes, {}, {}, lambda a: "game", DELETE)
    e = V.ExternalBase(vts[0].addr, "Unk_E", "unsorted/Unk_E.h", ((2, "void", "vf2"), (3, V.TYPE, "vf_type")), 3,
                       "Unk_E::Unk_GetType", ((8, (0, 1), 2),))
    d = vts[2]
    specs = {}
    V.derive_external(m, e, specs, {}, V.owners(vts), lambda f: 0, lambda f: True, lambda t: True)
    spec = specs[d.addr]
    assert spec.ext is e and spec.order == [3]
    decl, names, defs = V.render_class(m, spec)
    assert decl.startswith(f"class {spec.name} : public Unk_E {{\npublic:\n    static const Unk_239a418_Type* "
                           "Unk_GetType() {\n        static Unk_239a418_Type type(Unk_E::Unk_GetType());")
    assert "    const Unk_239a418_Type* vf_type() override;\n};\n" in decl
    assert f"{spec.name}::vf_type() {{\n    return Unk_GetType();\n}}" in defs
    cls = f"{len(spec.name)}{spec.name}"
    assert sorted(names) == [(0x140, f"_ZN{cls}D0Ev"), (0x150, f"_ZThn8_N{cls}D1Ev"), (0x160, f"_ZThn8_N{cls}D0Ev"),
                             (0x170, f"_ZN{cls}7vf_typeEv"), (0x180, f"_ZThn8_N{cls}7vf_typeEv"),
                             (0x300, f"_ZN{cls}11Unk_GetTypeEv")]
    # T called from anywhere else isn't its own type getter: D isn't derived.
    specs = {}
    struct.pack_into("<I", img, 0x110, 0x94000000 | ((0x300 - 0x110) >> 2))  # bl T in E's D0
    m = V.Model("sword", bytes(img), sorted(sizes.items()), vts, tables, sizes, {}, {}, lambda a: "game", DELETE)
    V.derive_external(m, e, specs, {}, V.owners(vts), lambda f: 0, lambda f: True, lambda t: True)
    assert d.addr not in specs


def test_merge_fields():
    fields = {0x10: "u32"}
    assert V.merge_fields(fields, [(0x10, "u32"), (0x18, "u8")]) and fields == {0x10: "u32", 0x18: "u8"}
    assert not V.merge_fields(fields, [(0x10, "f32")])          # another type
    assert not V.merge_fields(fields, [(0x12, "u16")])          # inside field_10
    assert not V.merge_fields(fields, [(0x1a, "u32")])          # misaligned
    assert fields == {0x10: "u32", 0x18: "u8"}


def test_derived_order():
    """Overrides can move to the front; a new function only when no new one is before it."""
    base = V.Vtable(0, 0, None, [1, 2, 3, 4])
    d = V.Vtable(0, 0, None, [1, 9, 3, 13, 14, 15])
    ms = [V.Member(3, 13, "ret"), V.Member(5, 15, "ret")]
    assert V.derived_order(d, base, ms, lambda f: 0) == [3, 4, 5]
    assert V.derived_order(d, base, ms[1:], lambda f: 0) is None
    d = V.Vtable(0, 0, None, [1, 9, 3, 13, 14])
    assert V.derived_order(d, base, [V.Member(4, 14, "ret")], lambda f: 0) == [4, 3]


def test_mangle():
    assert V.mangle("Unk_23b8650", "vf12") == "_ZN11Unk_23b86504vf12Ev"
    assert V.mangle("Unk_23b8650", "D0") == "_ZN11Unk_23b8650D0Ev"


def test_a_class_split_over_files_is_declared_the_same_in_each():
    m = model()
    spec = specs(m)[m.vtables[0].addr]
    dtor, constant = spec.members
    decl_1, names_1, defs_1 = V.render_class(m, spec, [dtor])
    decl_2, names_2, defs_2 = V.render_class(m, spec, [constant])
    assert decl_1 == decl_2 and "    virtual u32 vf2();\n" in decl_1
    assert "~Unk_1000() {}" in defs_1 and "vf2" not in defs_1
    assert "vf2() {" in defs_2 and "~" not in defs_2
    assert [n for _, n in names_1 + names_2] == ["_ZN8Unk_1000D2Ev", "_ZN8Unk_1000D0Ev", "_ZN8Unk_10003vf2Ev"]


def test_constructors():
    """At 0x200, `Unk_1000::Unk_1000() {}`: call the base's constructor (0x300,
    which stores Unk_1040's vptr: a class without a base), then store
    Unk_1000's vptr from the GOT."""
    from types import SimpleNamespace

    img = bytearray(0x1100)
    bl = 0x94000000 | ((0x300 - 0x210) >> 2)
    ctor = [0xF81E0FF3, 0xA9017BFD, 0x910043FD, 0xAA0003F3, bl,  # str x19 ; stp ; add x29 ; mov x19, x0 ; bl
            0x90000008, 0xF9405108, 0x91004108, 0xF9000268,      # adrp x8 ; ldr x8, [x8, #0xa0] ; add #16 ; str
            0xA9417BFD, 0xF84207F3, RET]                         # ldp ; ldr x19, [sp], #0x20 ; ret
    struct.pack_into("<12I", img, 0x200, *ctor)
    struct.pack_into("<5I", img, 0x300, 0x90000008, 0xF9405508, 0x91004108, 0xF9000008, RET)  # ... str x8, [x0]
    struct.pack_into("<I", img, 0x400, RET)
    slots = {0x1010: 0x400, 0x1050: 0x400}                       # vtables at 0x1000 and 0x1040, one slot each
    vts, tables = V.find_vtables(bytes(img), slots, {0x200, 0x300, 0x400}, DATA, len(img))
    vts[0].referrers, vts[1].referrers = {0x200}, {0x300}
    sizes = {0x200: 48, 0x300: 20, 0x400: 4}
    m = V.Model("sword", bytes(img), sorted(sizes.items()), vts, tables, sizes, {}, {}, lambda a: "game", DELETE)
    rows = {a: SimpleNamespace(name="", status="U", scope="common", shield=a) for a in sizes}
    ctors = V.find_ctors(m, rows, set())
    assert ctors == [V.Ctor(0x200, 0x300, "Unk_1000", "Unk_1040"), V.Ctor(0x300, None, "Unk_1040", None)]
    assert V.find_ctors(m, rows, {"Unk_1040"}) == []             # a class defined elsewhere
    vts[0].referrers = {0x200, 0x400}                            # 0x400 isn't a constructor: still one
    assert V.find_ctors(m, rows, set()) == ctors
    rows[0x300].name = "_ZN8Unk_1040C2Ev"                        # the base constructor named as that: fine
    assert V.find_ctors(m, rows, set()) == ctors
    rows[0x300].name = "_Z3foov"
    assert V.find_ctors(m, rows, set()) == []
    text = V.render_ctor_file(ctors[:1], {"Unk_1000": "Unk_1040"})
    assert "class Unk_1040 {\npublic:\n    Unk_1040();\n    virtual ~Unk_1040();\n};\n\n" \
           "class Unk_1000 : public Unk_1040 {\npublic:\n    Unk_1000();\n    ~Unk_1000() override;\n};\n" in text
    assert text.endswith("// 0x7100000200\nUnk_1000::Unk_1000() {}\n")
    assert V.ctor_name("Unk_1000") == "_ZN8Unk_1000C2Ev"


def test_derived_class_lifted_members_use_the_base_fields():
    """B derives from A: B's lifted members, left out to derive it, are added
    back with their fields declared by A (the same offsets in the object)."""
    m = model()
    a, b = m.vtables[0], m.vtables[2]
    base = V.ClassSpec(a, [], "empty")
    d = V.ClassSpec(b, [], "empty", base=base)
    families = {a.addr: base.sigs}
    set0 = V.Member(3, 0x160, "lifted", lifted=V.Lifted("void", (), "    field_10 = 0;\n", ((0x10, "u32"),), "Unk_160"))
    ptr = V.Member(4, 0x170, "lifted", lifted=V.Lifted("u8", (), "    return field_18->field_4;\n",
                                                       ((0x18, ("*", ((4, "u8"),))),), "Unk_170"))
    V._readd_lifted(d, [set0, ptr], families)
    assert d.members == [set0, ptr]
    assert base.fields == {0x10: "u32", 0x18: {4: "u8"}}
    assert base.sigs == {3: ("void", ())}                    # an override: the base's family has it
    assert d.sigs == {4: ("u8", ())}                         # a new slot (A has 4): B's own
    # another signature for slot 3, a conflicting field, a struct the return type names: left out
    other = V.Member(3, 0x160, "lifted", lifted=V.Lifted("u32", (), "    return 1;\n", (), "Unk_160"))
    clash = V.Member(5, 0x180, "lifted", lifted=V.Lifted("void", (), "    field_10 = 0;\n", ((0x10, "u8"),), "Unk_180"))
    named = V.Member(6, 0x190, "lifted", lifted=V.Lifted("Unk_190_8*", (), "    return field_8;\n",
                                                         ((8, ("*", ())),), "Unk_190"))
    d2 = V.ClassSpec(b, [], "empty", base=base)
    V._readd_lifted(d2, [other, clash, named], families)
    assert d2.members == []


def test_constructor_that_zeroes_fields():
    """bl <base> ; adrp x8 ; ldr x8 ; str xzr, [x19, #0x10] ; add x8, x8, #16 ;
    str x8, [x19] ; stp xzr, xzr, [x19, #0x20]: `Unk_D() : field_10(0), ... {}`."""
    img = bytearray(0x1100)
    words = [0xF81E0FF3, 0xA9017BFD, 0x910043FD, 0xAA0003F3, 0x94000000 | ((0x300 - 0x210) >> 2),
             0x90000008, 0xF9405108, 0xF9000A7F, 0x91004108, 0xF9000268, 0xA9027E7F,
             0xA9417BFD, 0xF84207F3, RET]
    struct.pack_into(f"<{len(words)}I", img, 0x200, *words)
    sizes = {0x200: 4 * len(words)}
    m = V.Model("sword", bytes(img), sorted(sizes.items()), [], [], sizes, {}, {}, lambda a: "game", DELETE)
    assert V.ctor_fields(m, 0x200) == ((0x10, "u64"), (0x20, "u64"), (0x28, "u64"))
    c = V.Ctor(0x200, 0x300, "Unk_1000", "Unk_1040", V.ctor_fields(m, 0x200))
    text = V.render_ctor_file([c], {"Unk_1000": "Unk_1040"}, {"Unk_1000": c.fields})
    assert "#include <types.h>\n" in text
    assert ("    ~Unk_1000() override;\n    u8 _8[0x8];\n    u64 field_10;\n    u8 _18[0x8];\n"
            "    u64 field_20;\n    u64 field_28;\n};\nPKMN_OFFSET_ASSERT(Unk_1000, field_10, 0x10);\n") in text
    assert text.endswith("Unk_1000::Unk_1000() : field_10(0), field_20(0), field_28(0) {}\n")
    assert V.ctor_layout({"Unk_1000": "Unk_1040"}, {"Unk_1000": c.fields}) == {"Unk_1000": 0x30, "Unk_1040": 8}


def test_intermediate_type():
    """A vf_type that loads four statics (guard, type, guard, type) and makes
    five calls, one to the base's getter: the fourth static is the type of a
    class in between."""
    img = bytearray(0x1100)
    words = []
    for slot in (0x1010, 0x1018, 0x1020, 0x1028):       # adrp x8, 0x1000 ; ldr x8, [x8, #slot]
        words += [0xB0000008, 0xF9400000 | ((slot - 0x1000) // 8) << 10 | 8 << 5 | 8]
    pc = 0x200 + 4 * len(words)
    for i, t in enumerate((0x400, 0x500, 0x400, 0x600, 0x500)):  # guard acquire, release, ..., the getter
        words.append(0x94000000 | ((t - (pc + 4 * i)) >> 2))
    words.append(RET)
    struct.pack_into(f"<{len(words)}I", img, 0x200, *words)
    sizes = {0x200: 4 * len(words)}
    m = V.Model("sword", bytes(img), sorted(sizes.items()), [], [], sizes, {0x600: "_ZN8Unk_100011Unk_GetTypeEv"},
                {}, lambda a: "game", DELETE, {0x1010: 0x3000, 0x1018: 0x3008, 0x1020: 0x3010, 0x1028: 0x3018})
    assert V.intermediate_type(m, 0x200) == (0x3018, 0x600)   # the in-between type, the getter it calls
    assert V.getter_type(m, 0x200) == 0x3008                   # what a getter returns: its second static
    m.got = {0x1010: 0x3000, 0x1018: 0x3008}                   # two statics: another shape
    assert V.intermediate_type(m, 0x200) is None


def test_derived_from_an_external_base_slot_with_a_parameter():
    """An override of a base slot declared with a parameter takes it too (unnamed),
    and its name is mangled with it; a lifted member can't be such an override."""
    img = bytearray(0x1200)
    sub8 = 0xD1002000                                       # sub x0, x0, #8
    code = {0x100: [0xAA0003E8, 0xAA0003E9, RET],           # E's D2
            0x120: [RET], 0x130: [0xAA0003E8, RET],         # E's slot 2, its type getter
            0x140: [b(0x140, 0x100)],                        # D's D0
            0x150: [sub8, b(0x154, 0x100)], 0x160: [sub8, b(0x164, 0x100)],
            0x1c0: [RET],                                    # D's slot 2
            0x110: [RET], 0x190: [RET], 0x1a0: [RET], 0x1b0: [RET]}
    for a, w in code.items():
        struct.pack_into(f"<{len(w)}I", img, a, *w)
    slots = {}

    def vt(start, ott, fns):
        struct.pack_into("<q", img, start, ott)
        for i, f in enumerate(fns):
            slots[start + 16 + 8 * i] = f
        return start + 16 + 8 * len(fns)

    end = vt(0x1000, 0, [0x100, 0x110, 0x120, 0x130])           # E
    end = vt(end, -8, [0x190, 0x1a0, 0x1b0])                    # E at +8
    end = vt(end, 0, [0x100, 0x140, 0x1c0, 0x130])              # D
    vt(end, -8, [0x150, 0x160, 0x1b0])                          # D at +8
    sizes = {a: 4 * len(w) for a, w in code.items()}
    vts, tables = V.find_vtables(bytes(img), slots, set(code), DATA, len(img))
    m = V.Model("sword", bytes(img), sorted(sizes.items()), vts, tables, sizes, {}, {}, lambda a: "game", DELETE)
    e = V.ExternalBase(vts[0].addr, "Unk_E", "unsorted/Unk_E.h",
                       ((2, "void", "vf2", "Unk_A*"), (3, V.TYPE, "vf_type")), 3, "Unk_E::Unk_GetType",
                       ((8, (0, 1), 2),))
    assert e.params(2) == "Unk_A*" and e.params(3) == "" and e.slot(2) == ("void", "vf2")
    d = vts[2]
    specs = {}
    V.derive_external(m, e, specs, {d.addr: [V.Member(2, 0x1c0, "ret")]}, V.owners(vts), lambda f: 0,
                      lambda f: True, lambda t: True)
    decl, names, defs = V.render_class(m, specs[d.addr])
    cls = specs[d.addr].name
    assert "    void vf2(Unk_A*) override;\n" in decl
    assert f"void {cls}::vf2(Unk_A*) {{}}" in defs
    assert (0x1c0, f"_ZN{len(cls)}{cls}3vf2EP5Unk_A") in names
    lifted = V.Member(2, 0x1c0, "lifted", lifted=V.Lifted("void", (), "", (), "Unk_1c0"))
    assert not V._ext_lifted_ok(e, vts[0], lifted, {})
    assert V.param_codes("") == "v" and V.param_codes("Unk_2399590_Arg*") == "P15Unk_2399590_Arg"
    # scalars of include/types.h: s32 is int, u64 unsigned long
    assert V.param_codes("s32") == "i" and V.param_codes("u64") == "m" and V.param_codes("bool") == "b"
    with pytest.raises(ValueError):
        V.param_codes("int")


def test_lifted_member_of_a_class_on_a_hand_written_base():
    """Its fields come after the base's (e.size); an override is declared as the base declares it."""
    e = V.ExternalBase(0x1010, "Unk_B", "b.h", ((2, "void", "vf2"), (3, "u32", "vf3")), 6, "Unk_B::Unk_GetType",
                       (), size=0x60)
    m = model()
    ev = m.vtables[0]
    fields = {}
    get = V.Member(3, 0x130, "lifted", lifted=V.Lifted("u32", (), "    return field_70;\n", ((0x70, "u32"),), "Unk_130"))
    assert V._ext_lifted_ok(e, ev, get, fields) and fields == {0x70: "u32"}
    inside = V.Member(3, 0x130, "lifted", lifted=V.Lifted("u32", (), "    return field_10;\n", ((0x10, "u32"),), "Unk_130"))
    assert not V._ext_lifted_ok(e, ev, inside, fields)          # a field of the base's
    other = V.Member(3, 0x130, "lifted", lifted=V.Lifted("bool", (), "    return field_78;\n", ((0x78, "u8"),), "Unk_130"))
    assert not V._ext_lifted_ok(e, ev, other, fields)           # the base declares vf3 as u32
    # a tail call or a global is fine: the file declares them
    calls = V.Member(2, 0x140, "lifted", lifted=V.Lifted(
        "void", (), "    if (field_80)\n        Unk_150(field_80);\n", ((0x80, "u64"),), "Unk_140",
        callee=(0x150, ("void*",)), globals=((0x3000, "u32"),)))
    assert V._ext_lifted_ok(e, ev, calls, fields) and fields[0x80] == "u64"


def test_out_of_line_parent():
    """vf_type at 0x200: one guarded static, three calls (guard, getter, guard).
    The getter at 0x700 has the object's shape (three guarded statics), so the
    class is on another direct descendant of the object."""
    img = bytearray(0x1100)

    def got_loads(slots):
        return [w for slot in slots for w in (0xB0000008, 0xF9400000 | ((slot - 0x1000) // 8) << 10 | 8 << 5 | 8)]

    f = got_loads((0x1010, 0x1018))
    pc = 0x200 + 4 * len(f)
    f += [0x94000000 | ((t - (pc + 4 * i)) >> 2) for i, t in enumerate((0x400, 0x700, 0x500))] + [RET]
    g = got_loads((0x1020, 0x1028, 0x1030, 0x1038, 0x1040, 0x1048)) + [RET]
    struct.pack_into(f"<{len(f)}I", img, 0x200, *f)
    struct.pack_into(f"<{len(g)}I", img, 0x700, *g)
    sizes = {0x200: 4 * len(f), 0x700: 4 * len(g)}
    got = {0x1010 + 8 * i: 0x3000 + 8 * i for i in range(8)}
    m = V.Model("sword", bytes(img), sorted(sizes.items()), [], [], sizes, {}, {}, lambda a: "game", DELETE, got)
    e = V.ExternalBase(0x1010, "Unk_239a418", "h", (), 6, "Unk_239a418_GetType", ())
    assert V.out_of_line_parent(m, 0x200, e) == 0x700
    assert V.getter_type(m, 0x700) == 0x3018                  # its type: the second static it loads
    other = V.ExternalBase(0x1010, "Unk_B", "h", (), 6, "Unk_B::Unk_GetType", ())
    assert V.out_of_line_parent(m, 0x200, other) is None      # only for the object's family


def test_direct_getter():
    """Three guarded statics (its type, the object's, the root's) and only the
    guard calls: a direct descendant's getter, its parent's inlined."""
    img = bytearray(0x1100)
    words = [w for slot in range(0x1010, 0x1040, 8) for w in (0xB0000008, 0xF9400000 | ((slot - 0x1000) // 8) << 10 | 8 << 5 | 8)]
    pc = 0x200 + 4 * len(words)
    words += [0x94000000 | ((t - (pc + 4 * i)) >> 2) for i, t in enumerate((0x400, 0x500) * 3)] + [RET]
    struct.pack_into(f"<{len(words)}I", img, 0x200, *words)
    sizes = {0x200: 4 * len(words)}
    got = {0x1010 + 8 * i: 0x3000 + 8 * i for i in range(6)}
    m = V.Model("sword", bytes(img), sorted(sizes.items()), [], [], sizes, {}, {}, lambda a: "game", DELETE, got)
    assert V.direct_getter(m, 0x200)
    assert V.getter_type(m, 0x200) == 0x3008
    struct.pack_into("<I", img, pc + 4, 0x94000000 | ((0x600 - (pc + 4)) >> 2))  # another call: not this shape
    m = V.Model("sword", bytes(img), sorted(sizes.items()), [], [], sizes, {}, {}, lambda a: "game", DELETE, got)
    assert not V.direct_getter(m, 0x200)


def test_render_file_with_a_class_whose_getter_others_call():
    """A's getter (0x700) is named after its type object (0x3008) and defined
    first; B, on A, declares that struct too, but the file has it once."""
    m = model()
    a, _, b = m.vtables
    e = V.ExternalBase(0x1010, "Unk_239a418", "gflib3/Unk_239a418.h", (), 6, "Unk_239a418_GetType", (),
                       inline_dtor=True)
    owner = V.ClassSpec(a, [V.Member(6, 0x200, "ext_type", 0x700), V.Member(-1, 0x700, "ext_getter", 0x3008)],
                        None, ext=e, order=[6])
    derived = V.ClassSpec(b, [V.Member(6, 0x300, "ext_type", ("copy", None, 0x3008, 0x700))], None, ext=e, order=[6])
    text, names = V.render_file(m, [(derived, derived.members), (owner, owner.members)])
    assert text.count("struct Unk_3008 {") == 1
    assert text.index("struct Unk_3008 {") < text.index(f"class {derived.name}")
    assert "        static Unk_239a418_Type type(Unk_239a418_GetType());\n" in text
    assert f"{V.TYPE} {owner.name}::vf_type() {{\n    return Unk_3008::Unk_GetType();\n}}" in text
    assert "static Unk_239a418_Type type(Unk_3008::Unk_GetType());" in text
    assert (0x700, "_ZN8Unk_300811Unk_GetTypeEv") in names


def test_ref_dtor_pattern():
    """A D2 that releases n reference members, then the object's D2 inlined:
    the object's pattern with the members' releases and its own part spliced in."""
    pro = ("str x19, [sp, #N]! ; stp x29, x30, [sp, #N] ; add x29, sp, #N ; adrp x8, #N ; ldr x8, [x8, #N] ;"
           " add x9, x8, #N ; add x10, x8, #N ; add x8, x8, #N ; mov x19, x0 ; str x9, [x0] ;"
           " stp x10, x8, [x0, #N]")
    release = " ; cbz x0, #N ; ldr x8, [x0, #N]! ; ldr x8, [x8, #N] ; blr x8 ; str xzr, [x19, #N]"
    epi = " ; ldp x29, x30, [sp, #N] ; ldr x19, [sp], #N ; ret"
    base = pro + " ; ldr x0, [x0, #N]" + release + epi
    obj = (" ; adrp x8, #N ; ldr x8, [x8, #N] ; ldr x0, [x19, #N] ; add x9, x8, #N ; add x10, x8, #N ;"
           " add x8, x8, #N ; str x9, [x19] ; stp x10, x8, [x19, #N]" + release)
    assert V.ref_dtor_pattern(base, 1) == pro + " ; ldr x0, [x0, #N]" + release + obj + epi
    assert V.ref_dtor_pattern(base, 2) == (pro + " ; ldr x0, [x0, #N]" + release + " ; ldr x0, [x19, #N]" + release
                                           + obj + epi)
    assert V.ref_dtor_pattern("ret", 1) is None
    assert V._width(V.REF) == 8


def test_field_lines_tail_padding():
    """A class on a hand-written base: the padding within 0x50 bytes of its
    end is u64 fields, the rest bytes (and nothing changes without it)."""
    fields = {0x88: V.REF, 0x100: V.REF}
    assert V.tail_padding_start(fields) == 0xb8
    assert V.field_lines(fields, "X", 0x88) == [
        f"    {V.REF} field_88;", "    u8 _90[0x70];", f"    {V.REF} field_100;"]
    assert V.field_lines(fields, "X", 0x88, V.tail_padding_start(fields)) == [
        f"    {V.REF} field_88;", "    u8 _90[0x28];", *(f"    u64 _{o:x};" for o in range(0xb8, 0x100, 8)),
        f"    {V.REF} field_100;"]
    # unaligned padding stays bytes
    assert V.field_lines({0x8c: "u32"}, "X", 0x88, 0) == ["    u8 _88[0x4];", "    u32 field_8c;"]
    assert V.tail_padding_start({}) is None


def test_ref_members_tail():
    """A D2 that stores its vptrs (its vtable through GOT slot 0x1010),
    releases its reference members (+0x80, then +0x78) and tail-calls its
    base's D2 (0x600), out of line."""
    def release(off: int, base: int) -> list[int]:
        # ldr x0, [x<base>, #off] ; cbz x0 ; ldr x8, [x0, #0x48]! ; ldr x8, [x8, #0x18] ; blr x8 ; str xzr, [x19, #off]
        return [0xF9400000 | (off // 8) << 10 | base << 5, 0xB40000A0, 0xF8448C08, 0xF9400D08, 0xD63F0100,
                0xF900027F | (off // 8) << 10]

    words = [0xF81E0FF3, 0xA9017BFD, 0x910043FD,                # str x19, [sp, #-0x20]! ; stp x29, x30 ; add x29
             0xB0000008, 0xF9400908,                            # adrp x8 ; ldr x8, [x8, #0x10]: the vtable
             0x91004109, 0x9101E10A, 0x9102E108, 0xAA0003F3,    # add x9/x10/x8, x8, #N ; mov x19, x0
             0xF9000009, 0xA904A00A]                            # str x9, [x0] ; stp x10, x8, [x0, #0x48]
    words += release(0x80, 0) + release(0x78, 19)
    words += [0xA9417BFD, 0xAA1303E0, 0xF84207F3]               # ldp x29, x30 ; mov x0, x19 ; ldr x19, [sp], #0x20
    pc = 0x200 + 4 * len(words)
    words.append(0x14000000 | ((0x600 - pc) >> 2))              # b <the base's D2>
    img = bytearray(0x1100)
    struct.pack_into(f"<{len(words)}I", img, 0x200, *words)
    sizes = {0x200: 4 * len(words)}
    m = V.Model("sword", bytes(img), sorted(sizes.items()), [], [], sizes, {}, {}, lambda a: "game", DELETE,
                {0x1010: 0x3000})
    assert m.pattern(0x200) == V.ref_tail_pattern(2)
    assert V.ref_members_tail(m, 0x200, 0x600, 0x3000, 0x78) == (0x78, 0x80)  # in declaration order
    assert V.ref_members_tail(m, 0x200, 0x600, 0x3000, 0x80) is None   # +0x78 is the base's
    assert V.ref_members_tail(m, 0x200, 0x700, 0x3000, 0x78) is None   # another base's D2
    assert V.ref_members_tail(m, 0x200, 0x600, 0x3008, 0x78) is None   # it stores another class's vtable


def test_parent_getters_on_another_base():
    """On a base whose own getter loads six statics (GOT slots 0x1020-0x1048):
    a vf_type calling a getter that loads exactly those is on the base's own
    getter (out of line); one calling a getter that loads two more first is
    on another class's getter on that base."""
    img = bytearray(0x1100)

    def got_loads(slots):
        return [w for slot in slots for w in (0xB0000008, 0xF9400000 | ((slot - 0x1000) // 8) << 10 | 8 << 5 | 8)]

    def vf_type(at, getter):
        f = got_loads((0x1050, 0x1058))
        pc = at + 4 * len(f)
        f += [0x94000000 | ((t - (pc + 4 * i)) >> 2) & 0x3FFFFFF for i, t in enumerate((0x400, getter, 0x500))] + [RET]
        struct.pack_into(f"<{len(f)}I", img, at, *f)
        return 4 * len(f)

    base = (0x1020, 0x1028, 0x1030, 0x1038, 0x1040, 0x1048)
    sizes = {0x200: vf_type(0x200, 0x700), 0x300: vf_type(0x300, 0x800)}
    g = got_loads(base) + [RET]
    struct.pack_into(f"<{len(g)}I", img, 0x700, *g)
    h = got_loads((0x1010, 0x1018, *base)) + [RET]
    struct.pack_into(f"<{len(h)}I", img, 0x800, *h)
    sizes |= {0x700: 4 * len(g), 0x800: 4 * len(h)}
    got = {0x1010 + 8 * i: 0x3000 + 8 * i for i in range(10)}
    m = V.Model("sword", bytes(img), sorted(sizes.items()), [], [], sizes, {}, {}, lambda a: "game", DELETE, got)
    e = V.ExternalBase(0x1010, "Unk_B", "h", (), 6, "Unk_B::Unk_GetType", ())
    statics = [0x3010 + 8 * i for i in range(6)]
    assert V.base_getter_copy(m, 0x200, statics) == 0x700
    assert V.out_of_line_parent(m, 0x200, e, statics) is None
    assert V.base_getter_copy(m, 0x300, statics) is None
    assert V.out_of_line_parent(m, 0x300, e, statics) == 0x800
    assert V.out_of_line_parent(m, 0x300, e, None) is None
    assert V.getter_name("Unk_B::Unk_GetType") == "_ZN5Unk_B11Unk_GetTypeEv"


def test_tail_members_with_a_callable():
    """A D2 that releases a reference (+0x100), then a callable (+0x80: clear
    its four words, its manager at +0x88 disposes of the storage at +0xa0),
    then tail-calls its base's D2 (0x600)."""
    words = [0xF81E0FF3, 0xA9017BFD, 0x910043FD, 0xB0000008, 0xF9400908,
             0x91004109, 0x9101E10A, 0x9102E108, 0xAA0003F3, 0xF9000009, 0xA904A00A]
    words += [0xF9400000 | (0x100 // 8) << 10, 0xB40000A0, 0xF8448C08, 0xF9400D08, 0xD63F0100,
              0xF900027F | (0x100 // 8) << 10]                       # the reference
    words += [0xF9404668, 0xB40000A8, 0x91028260, 0xA9097E7F, 0xA9087E7F, 0xD63F0100]  # the callable
    words += [0xA9417BFD, 0xAA1303E0, 0xF84207F3]
    pc = 0x200 + 4 * len(words)
    words.append(0x14000000 | ((0x600 - pc) >> 2))
    img = bytearray(0x1100)
    struct.pack_into(f"<{len(words)}I", img, 0x200, *words)
    sizes = {0x200: 4 * len(words)}
    m = V.Model("sword", bytes(img), sorted(sizes.items()), [], [], sizes, {}, {}, lambda a: "game", DELETE,
                {0x1010: 0x3000})
    assert V.tail_members(m, 0x200, 0x600, 0x3000, 0x78) == {0x80: V.CALLABLE, 0x100: V.REF}
    assert V.tail_members(m, 0x200, 0x600, 0x3000, 0x88) is None       # inside the base
    assert V._width(V.CALLABLE) == 0x80


def test_header_structs(tmp_path, monkeypatch):
    """The placeholder structs a hand-written header declares, and those of the
    headers it includes: a generated file that includes it declares them no more."""
    (tmp_path / "src" / "a").mkdir(parents=True)
    (tmp_path / "src" / "a" / "b.h").write_text('#include "a/c.h"\nstruct Unk_10 {\n};\nclass Unk_20 {\n};\n')
    (tmp_path / "src" / "a" / "c.h").write_text("struct Unk_30 {\n    static int f();\n};\n")
    monkeypatch.setattr(V, "ROOT", tmp_path)
    assert V.header_structs(["a/b.h", "a/missing.h"]) == {"Unk_10", "Unk_30"}


def test_ref_dtor_pattern_with_an_interface():
    """A class with an interface after the object stores four vptrs: the
    object's three places and the interface's (+0x60)."""
    pro = ("str x19, [sp, #N]! ; stp x29, x30, [sp, #N] ; add x29, sp, #N ; adrp x8, #N ; ldr x8, [x8, #N] ;"
           " add x9, x8, #N ; add x10, x8, #N")
    release = " ; cbz x0, #N ; ldr x8, [x0, #N]! ; ldr x8, [x8, #N] ; blr x8 ; str xzr, [x19, #N]"
    epi = " ; ldp x29, x30, [sp, #N] ; ldr x19, [sp], #N ; ret"
    base = pro + " ; add x8, x8, #N ; mov x19, x0 ; str x9, [x0] ; stp x10, x8, [x0, #N]" + \
        " ; ldr x0, [x0, #N]" + release + epi
    four = (pro + " ; add x11, x8, #N ; add x8, x8, #N ; mov x19, x0 ; str x9, [x0] ; str x8, [x0, #N] ;"
            " stp x10, x11, [x0, #N]")
    got = V.ref_dtor_pattern(base, 1, iface=True)
    assert got.startswith(four + " ; ldr x0, [x0, #N]" + release) and got.endswith(epi)
    assert V.ref_dtor_pattern(base, 1) != got
    assert V.ref_dtor_pattern("ret", 1, iface=True) is None


def test_render_external_with_a_written_out_destructor():
    """An inline-shaped class on the object with nothing else to be its key
    function: its destructor is declared first, and defined only in the file
    that holds its D2."""
    m = model()
    a = m.vtables[0]
    e = V.ExternalBase(0x1010, "Unk_239a418", "gflib3/Unk_239a418.h", (), 6, "Unk_239a418_GetType", (),
                       inline_dtor=True, size=0x60)
    members = [V.Member(0, 0x100, "d2"), V.Member(1, 0x110, "d0"), V.Member(6, 0x120, "ext_type", None)]
    spec = V.ClassSpec(a, members, None, ext=e, order=[6, 7], fields={0x68: V.REF}, explicit_dtor=True)
    decl, names, defs = V.render_external(m, spec, members)
    lines = decl.splitlines()
    assert lines.index(f"    ~{spec.name}() override;") < lines.index("    virtual void vf7();")
    assert f"{spec.name}::~{spec.name}() {{}}" in defs
    decl, names, defs = V.render_external(m, spec, [])     # another file that declares it
    assert f"    ~{spec.name}() override;" in decl and "::~" not in defs


def _empty_base_d2(vtable_slot: int, refs: tuple[int, ...]) -> list[int]:
    """The words of a D2 on a base whose D2 is empty (Unk_239a4c0's shape):
    its vptrs (its vtable from the GOT slot at 0x1000 + vtable_slot, stored at
    +0 and +0x48), its reference members released (in this order), `ret`."""
    words = [0xF81E0FF3, 0xA9017BFD, 0x910043FD,                # str x19, [sp, #-0x20]! ; stp x29, x30 ; add x29
             0xB0000008, 0xF9400108 | (vtable_slot // 8) << 10,  # adrp x8 ; ldr x8, [x8, #slot]: the vtable
             0x91004109, 0x91012108, 0xAA0003F3,                # add x9, x8, #0x10 ; add x8, x8, #0x48 ; mov x19, x0
             0xF9000009, 0xF9002408]                            # str x9, [x0] ; str x8, [x0, #0x48]
    for i, off in enumerate(refs):
        # ldr x0, [x0|x19, #off] ; cbz x0 ; ldr x8, [x0, #0x48]! ; ldr x8, [x8, #0x18] ; blr x8 ; str xzr, [x19, #off]
        words += [0xF9400000 | (off // 8) << 10 | (19 if i else 0) << 5, 0xB40000A0, 0xF8448C08, 0xF9400D08,
                  0xD63F0100, 0xF900027F | (off // 8) << 10]
    return words + [0xA9417BFD, 0xF84207F3, RET]               # ldp x29, x30 ; ldr x19, [sp], #0x20 ; ret


def test_ref_empty_pattern():
    """The D2 of a class with reference members on a base whose D2 is empty:
    its two vptrs (three with two secondary bases), the releases, and nothing
    of the base's before the epilogue."""
    release = " ; cbz x0, #N ; ldr x8, [x0, #N]! ; ldr x8, [x8, #N] ; blr x8 ; str xzr, [x19, #N]"
    two = ("str x19, [sp, #N]! ; stp x29, x30, [sp, #N] ; add x29, sp, #N ; adrp x8, #N ; ldr x8, [x8, #N] ;"
           " add x9, x8, #N ; add x8, x8, #N ; mov x19, x0 ; str x9, [x0] ; str x8, [x0, #N]")
    epi = " ; ldp x29, x30, [sp, #N] ; ldr x19, [sp], #N ; ret"
    assert V.ref_empty_pattern(1) == two + " ; ldr x0, [x0, #N]" + release + epi
    assert V.ref_empty_pattern(2) == two + " ; ldr x0, [x0, #N]" + release + " ; ldr x0, [x19, #N]" + release + epi
    assert V.ref_empty_pattern(1, 3).startswith(V._VPTRS + " ; ldr x0, [x0, #N]")
    assert V.ref_empty_pattern(0) is None
    assert V.ref_empty_pattern(1, 4) is None


def test_ref_members_empty():
    """Its members' offsets, in declaration order, from a D2 that stores its own
    vtable (GOT slot 0x1800) and releases +0x68, then +0x60."""
    words = _empty_base_d2(0x800, (0x68, 0x60))
    img = bytearray(0x400)
    struct.pack_into(f"<{len(words)}I", img, 0x200, *words)
    sizes = {0x200: 4 * len(words)}
    m = V.Model("sword", bytes(img), sorted(sizes.items()), [], [], sizes, {}, {}, lambda a: "game", DELETE,
                {0x1800: 0x3000})
    assert m.pattern(0x200) == V.ref_empty_pattern(2)
    assert V.ref_members_empty(m, 0x200, 0x3000, 0x54) == (0x60, 0x68)
    assert V.ref_members_empty(m, 0x200, 0x3000, 0x64) is None     # +0x60 is the base's
    assert V.ref_members_empty(m, 0x200, 0x3008, 0x54) is None     # it stores another class's vtable
    assert V.ref_members_empty(m, 0x200, 0x3000, 0x54, 3) is None  # three vptrs aren't these
    last = 0x200 + 4 * (len(words) - 1)
    struct.pack_into("<I", img, last, b(last, 0x300))
    m = V.Model("sword", bytes(img), sorted(sizes.items()), [], [], sizes, {}, {}, lambda a: "game", DELETE,
                {0x1800: 0x3000})
    assert V.ref_members_empty(m, 0x200, 0x3000, 0x54) is None     # a tail call: its base's D2 isn't empty


def _abstract_base_model(with_p: bool = True):
    """An abstract base E whose destructor is inline (Unk_241b640's shape: its
    D0 and its D0 thunk are traps), whose vf_type inlines its getter (two
    statics), and three classes on it whose D0s and thunks are copies of E's D2:

    - D inherits E's vf_type and overrides vf2;
    - P overrides vf_type: its getter inlined, calling E's out of line (G,
      0x500), and its secondary type slot is a copy of it;
    - X inherits P's vf_type and type slots, and overrides vf2."""
    img = bytearray(0x2000)

    def got_loads(slots):
        return [w for slot in slots for w in (0xB0000008, 0xF9400000 | ((slot - 0x1000) // 8) << 10 | 8 << 5 | 8)]

    def typed(pc):          # a vf_type: its guard and type, then guard, getter G, guard
        w = got_loads((0x1810, 0x1818))
        return w + [0x94000000 | (((t - (pc + 4 * (len(w) + i))) >> 2) & 0x3FFFFFF)
                    for i, t in enumerate((0x700, 0x500, 0x710))] + [RET]

    dtor = [0xAA0003E8, 0xAA0003E9, RET]
    getter = got_loads((0x1800, 0x1808)) + [RET]
    code = {0x100: dtor, 0x110: [TRAP], 0x120: [RET], 0x130: getter,               # E
            0x140: dtor, 0x150: [TRAP], 0x160: [0xD1002000, b(0x164, 0x130)],      # E at +8
            0x200: dtor, 0x210: [RET], 0x220: dtor, 0x230: dtor,                    # D
            0x400: dtor, 0x420: dtor, 0x430: dtor, 0x600: typed(0x600), 0x680: typed(0x680),  # P
            0x500: getter, 0x700: [RET], 0x710: [RET],
            0x800: dtor, 0x810: [RET], 0x820: dtor, 0x830: dtor}                    # X
    for a, w in code.items():
        struct.pack_into(f"<{len(w)}I", img, a, *w)
    slots = {}

    def vt(start, ott, fns):
        struct.pack_into("<q", img, start, ott)
        for i, f in enumerate(fns):
            slots[start + 16 + 8 * i] = f
        return start + 16 + 8 * len(fns)

    end = vt(0x1000, 0, [0x100, 0x110, 0x120, 0x130])                 # E
    end = vt(end, -8, [0x140, 0x150, 0x160])
    if with_p:
        end = vt(end, 0, [0x100, 0x400, 0x120, 0x600])                # P
        end = vt(end, -8, [0x420, 0x430, 0x680])
        end = vt(end, 0, [0x100, 0x800, 0x810, 0x600])                # X
        end = vt(end, -8, [0x820, 0x830, 0x680])
    end = vt(end, 0, [0x100, 0x200, 0x210, 0x130])                    # D
    vt(end, -8, [0x220, 0x230, 0x160])
    sizes = {a: 4 * len(w) for a, w in code.items()}
    vts, tables = V.find_vtables(bytes(img), slots, set(code), DATA, len(img))
    got = {0x1800 + 8 * i: 0x3000 + 8 * i for i in range(4)}
    m = V.Model("sword", bytes(img), sorted(sizes.items()), vts, tables, sizes, {}, {}, lambda a: "game", DELETE, got)
    e = V.ExternalBase(vts[0].addr, "Unk_E", "unsorted/Unk_E.h", ((2, "void", "vf2"), (3, V.TYPE, "vf_type")), 3,
                       "Unk_E::Unk_GetType", ((8, (0, 1), 2),), inline_dtor=True, size=0x10)
    return m, e, [v for v in vts if not v.offset_to_top][1:]


def test_derived_from_an_abstract_base_with_an_inline_destructor():
    """D's D0 thunk is a copy of E's D2 where E's is a trap: it's compared with
    E's D1 thunk."""
    m, e, (d,) = _abstract_base_model(with_p=False)
    specs = {}
    V.derive_external(m, e, specs, {d.addr: [V.Member(2, 0x210, "ret")]}, V.owners(m.vtables), lambda f: 0,
                      lambda f: True, lambda t: True)
    spec = specs[d.addr]
    assert spec.ext is e and spec.parent is None and spec.order == [2]
    cls = f"{len(spec.name)}{spec.name}"
    assert sorted(V.render_class(m, spec)[1]) == [(0x200, f"_ZN{cls}D0Ev"), (0x210, f"_ZN{cls}3vf2Ev"),
                                                  (0x220, f"_ZThn8_N{cls}D1Ev"), (0x230, f"_ZThn8_N{cls}D0Ev")]


def test_derived_from_another_class_on_the_base():
    """X derives from P, whose vf_type it inherits. P is alone in its file, so
    its vf_type (calling E's getter out of line) isn't written, but P stays,
    declared, so that X can derive from it."""
    m, e, (p, x, d) = _abstract_base_model()
    own = V.owners(m.vtables)
    assert own[0x600] == (p.addr, 3)
    specs = {}
    picked = {d.addr: [V.Member(2, 0x210, "ret")], x.addr: [V.Member(2, 0x810, "ret")]}
    V.derive_external(m, e, specs, picked, own, lambda f: 0, lambda f: True, lambda t: True)
    sp, sx = specs[p.addr], specs[x.addr]
    assert sp.ext is e and sp.members == [] and sp.order == [3]
    assert sx.ext is e and sx.parent is sp and sx.order == [2]
    assert specs[d.addr].parent is None
    decl, names, defs = V.render_class(m, sp)
    assert "    const Unk_239a418_Type* vf_type() override;\n};\n" in decl and not names and not defs.strip()
    decl, names, _ = V.render_class(m, sx)
    assert decl == f"class {sx.name} : public {sp.name} {{\npublic:\n    void vf2() override;\n}};\n"
    cls = f"{len(sx.name)}{sx.name}"
    assert sorted(names) == [(0x800, f"_ZN{cls}D0Ev"), (0x810, f"_ZN{cls}3vf2Ev"), (0x820, f"_ZThn8_N{cls}D1Ev"),
                             (0x830, f"_ZThn8_N{cls}D0Ev")]
    text, _ = V.render_file(m, [(sx, sx.members)])
    assert text.index(f"class {sp.name} : public Unk_E {{") < text.index(f"class {sx.name} : public {sp.name} {{")
    # P's own functions needn't be kept (`write --only`): it's only declared anyway.
    specs = {}
    V.derive_external(m, e, specs, picked, own, lambda f: 0, lambda f: f not in (0x400, 0x420, 0x430, 0x600, 0x680),
                      lambda t: True)
    assert specs[p.addr].members == [] and specs[x.addr].parent is specs[p.addr]
    # With nothing to be X's key function, X isn't written, and P isn't either.
    for pickable in (lambda f: True, lambda f: f != 0x400):
        specs = {}
        V.derive_external(m, e, specs, {d.addr: picked[d.addr]}, own, lambda f: 0, pickable, lambda t: True)
        assert p.addr not in specs and x.addr not in specs and d.addr in specs


def test_parent_slot_signatures():
    """An override of a parent's own slot has the parent's signature; a slot the
    parent doesn't define takes the first one a class on it gives."""
    p = V.ClassSpec(V.Vtable(0x10, 0, None, [0] * 6), [], None, sigs={4: ("u32", ())})
    adopt = {}
    assert V._parent_sig(p, adopt, 4, ("u32", ())) and not V._parent_sig(p, adopt, 4, ("void", ()))
    assert V._parent_sig(p, adopt, 5, ("u32", ())) and adopt == {5: ("u32", ())}
    assert not V._parent_sig(p, adopt, 5, ("void", ())) and V._parent_sig(p, adopt, 5, ("u32", ()))
    e = V.ExternalBase(0x10, "Unk_E", "h", ((2, "void", "vf2"),), None, "", ())
    x = V.ClassSpec(V.Vtable(0x40, 0, None, [0] * 7), [], None, ext=e, order=[4, 6], parent=p)
    decl = V.render_class(V.Model("sword", b"", [], [], [], {}, {}, {}, lambda a: "game"), x)[0]
    assert decl == f"class {x.name} : public {p.name} {{\npublic:\n    u32 vf4() override;\n    virtual void vf6();\n}};\n"


def test_derived_from_an_empty_base():
    """Classes on a hand-written base without types whose D2 is empty and
    inline (`ret`, Unk_239a4c0's shape), with one interface at +0x48:

    - D has nothing to destroy: its slot 0 is the base's D2, its D0 and its
      destructor thunks are `ret`s like the base's, and it overrides slot 2,
      its key function;
    - R releases a reference (+0x60) and defines nothing else: its D0 and
      thunks are copies of its D2, and its destructor is its key function."""
    img = bytearray(0x2000)
    d2 = _empty_base_d2(0x800, (0x60,))
    code = {0x100: [RET], 0x110: [RET], 0x120: [0xAA0003E8, RET], 0x130: [0xAA0003E9, RET],  # E
            0x140: [0xAA0003EA, RET], 0x150: [RET], 0x160: [RET], 0x170: [0xAA0003EB, RET],
            0x180: [0xAA0003EC, RET],
            0x200: [RET], 0x210: [RET], 0x220: [RET], 0x230: [RET],                         # D
            0x300: d2, 0x350: d2, 0x400: d2, 0x450: d2}                                     # R
    for a, w in code.items():
        struct.pack_into(f"<{len(w)}I", img, a, *w)
    slots = {}

    def vt(start, ott, fns):
        struct.pack_into("<q", img, start, ott)
        for i, f in enumerate(fns):
            slots[start + 16 + 8 * i] = f
        return start + 16 + 8 * len(fns)

    end = vt(0x1000, 0, [0x100, 0x110, 0x120, 0x130, 0x140])          # E
    end = vt(end, -0x48, [0x150, 0x160, 0x170, 0x180])                # E at +0x48
    d_start = end
    end = vt(end, 0, [0x100, 0x200, 0x210, 0x130, 0x140])             # D
    end = vt(end, -0x48, [0x220, 0x230, 0x170, 0x180])
    r_start = end
    end = vt(end, 0, [0x300, 0x350, 0x120, 0x130, 0x140])             # R
    vt(end, -0x48, [0x400, 0x450, 0x170, 0x180])
    sizes = {a: 4 * len(w) for a, w in code.items()}
    vts, tables = V.find_vtables(bytes(img), slots, set(code), DATA, len(img))
    m = V.Model("sword", bytes(img), sorted(sizes.items()), vts, tables, sizes, {}, {}, lambda a: "game", DELETE,
                {0x1800: r_start})
    e = V.ExternalBase(vts[0].addr, "Unk_E", "gflib3/Unk_E.h", ((2, "void", "vf2"), (3, "void", "vf3"),
                       (4, "void", "vf4")), None, "", ((0x48, (0, 1), None),), inline_dtor=True, size=0x54)
    d, r = (next(v for v in vts if v.start == s) for s in (d_start, r_start))
    specs = {}
    V.derive_external(m, e, specs, {d.addr: [V.Member(2, 0x210, "ret")]}, V.owners(vts), lambda f: 0,
                      lambda f: True, lambda t: True)
    # D: an implicit destructor, its override the key function
    spec = specs[d.addr]
    assert spec.ext is e and spec.order == [2] and not spec.explicit_dtor and not spec.fields
    decl, names, defs = V.render_class(m, spec)
    assert decl == f"class {spec.name} : public Unk_E {{\npublic:\n    void vf2() override;\n}};\n"
    assert f"void {spec.name}::vf2() {{}}" in defs
    cls = f"{len(spec.name)}{spec.name}"
    assert sorted(names) == [(0x200, f"_ZN{cls}D0Ev"), (0x210, f"_ZN{cls}3vf2Ev"), (0x220, f"_ZThn72_N{cls}D1Ev"),
                             (0x230, f"_ZThn72_N{cls}D0Ev")]
    # R: its destructor out of line, its key function
    spec = specs[r.addr]
    assert spec.ext is e and spec.order == [] and spec.explicit_dtor and spec.fields == {0x60: V.REF}
    decl, names, defs = V.render_class(m, spec)
    assert decl == (f"class {spec.name} : public Unk_E {{\npublic:\n    ~{spec.name}() override;\n"
                    f"    u8 _54[0xc];\n    {V.REF} field_60;\n}};\nPKMN_OFFSET_ASSERT({spec.name}, field_60, 0x60);\n")
    assert f"// 0x7100000300: its key function\n{spec.name}::~{spec.name}() {{}}" in defs
    cls = f"{len(spec.name)}{spec.name}"
    assert sorted(names) == [(0x300, f"_ZN{cls}D2Ev"), (0x350, f"_ZN{cls}D0Ev"), (0x400, f"_ZThn72_N{cls}D1Ev"),
                             (0x450, f"_ZThn72_N{cls}D0Ev")]
    # Its D0 tail-calls its D2 when that's too big to be inlined, and its thunks do too.
    sub = 0xD1012000                                                   # sub x0, x0, #0x48
    for a, w in {0x350: [b(0x350, 0x300)], 0x400: [sub, b(0x404, 0x300)], 0x450: [sub, b(0x454, 0x300)]}.items():
        struct.pack_into(f"<{len(w)}I", img, a, *w)
        sizes[a] = 4 * len(w)
    m = V.Model("sword", bytes(img), sorted(sizes.items()), vts, tables, sizes, {}, {}, lambda a: "game", DELETE,
                {0x1800: r_start})
    specs = {}
    V.derive_external(m, e, specs, {}, V.owners(vts), lambda f: 0, lambda f: True, lambda t: True)
    assert specs[r.addr].explicit_dtor and sorted(x.addr for x in specs[r.addr].members) == [0x300, 0x350, 0x400, 0x450]


def test_tail_called_destructor_is_written_out():
    """R, on hand-written E (out-of-line D2 0x600, no types, secondaries at
    +0x48 and +0x50), releases two references (+0x80, then +0x78), tail-calls
    E's D2 (Batch 9's tail form) and overrides vf2. When its D0 and thunks
    tail-call its D2, the original's destructor wasn't inline-hinted: it's
    written out. When they're copies of its D2, it stays implicit."""
    def release(off: int, base: int) -> list[int]:
        # ldr x0, [x<base>, #off] ; cbz x0 ; ldr x8, [x0, #0x48]! ; ldr x8, [x8, #0x18] ; blr x8 ; str xzr, [x19, #off]
        return [0xF9400000 | (off // 8) << 10 | base << 5, 0xB40000A0, 0xF8448C08, 0xF9400D08, 0xD63F0100,
                0xF900027F | (off // 8) << 10]

    def d2_at(at: int) -> list[int]:
        words = [0xF81E0FF3, 0xA9017BFD, 0x910043FD,                # str x19, [sp, #-0x20]! ; stp x29, x30 ; add x29
                 0xB0000008, 0xF9400108 | (0x800 // 8) << 10,       # adrp x8 ; ldr x8, [x8, #0x800]: the vtable
                 0x91004109, 0x9101E10A, 0x9102E108, 0xAA0003F3,    # add x9/x10/x8, x8, #N ; mov x19, x0
                 0xF9000009, 0xA904A00A]                            # str x9, [x0] ; stp x10, x8, [x0, #0x48]
        words += release(0x80, 0) + release(0x78, 19)
        words += [0xA9417BFD, 0xAA1303E0, 0xF84207F3]               # ldp x29, x30 ; mov x0, x19 ; ldr x19, [sp], #0x20
        return words + [b(at + 4 * len(words), 0x600)]              # b <E's D2>

    sub48, sub50 = 0xD1012000, 0xD1014000                           # sub x0, x0, #0x48 / #0x50
    e_code = {0x600: [0xAA0003E8, 0xAA0003E9, RET], 0x610: [b(0x610, 0x600)], 0x620: [RET],
              0x630: [sub48, b(0x634, 0x600)], 0x640: [sub48, b(0x644, 0x600)],
              0x650: [sub50, b(0x654, 0x600)], 0x660: [sub50, b(0x664, 0x600)]}
    called = {0x200: d2_at(0x200), 0x280: [b(0x280, 0x200)],
              0x290: [sub48, b(0x294, 0x200)], 0x2a0: [sub48, b(0x2a4, 0x200)],
              0x2b0: [sub50, b(0x2b4, 0x200)], 0x2c0: [sub50, b(0x2c4, 0x200)], 0x500: [RET]}
    inlined = {0x200: d2_at(0x200), 0x280: d2_at(0x280), 0x300: d2_at(0x300), 0x380: d2_at(0x380),
               0x400: d2_at(0x400), 0x480: d2_at(0x480), 0x500: [RET]}

    def derive(r_code, r_slots):
        img = bytearray(0x2000)
        code = {**e_code, **r_code}
        for a, w in code.items():
            struct.pack_into(f"<{len(w)}I", img, a, *w)
        slots = {}

        def vt(start, ott, fns):
            struct.pack_into("<q", img, start, ott)
            for i, f in enumerate(fns):
                slots[start + 16 + 8 * i] = f
            return start + 16 + 8 * len(fns)

        end = vt(0x1000, 0, [0x600, 0x610, 0x620])                  # E
        end = vt(end, -0x48, [0x630, 0x640])
        end = vt(end, -0x50, [0x650, 0x660])
        r_start = end
        end = vt(end, 0, [0x200, r_slots[0], 0x500])                # R
        end = vt(end, -0x48, r_slots[1:3])
        vt(end, -0x50, r_slots[3:5])
        sizes = {a: 4 * len(w) for a, w in code.items()}
        vts, tables = V.find_vtables(bytes(img), slots, set(code), DATA, len(img))
        m = V.Model("sword", bytes(img), sorted(sizes.items()), vts, tables, sizes, {}, {}, lambda a: "game", DELETE,
                    {0x1800: r_start})
        e = V.ExternalBase(vts[0].addr, "Unk_E", "unsorted/Unk_E.h", ((2, "void", "vf2"),), None, "",
                           ((0x48, (0, 1), None), (0x50, (0, 1), None)), size=0x78)
        r = next(v for v in vts if v.start == r_start)
        specs = {}
        V.derive_external(m, e, specs, {r.addr: [V.Member(2, 0x500, "ret")]}, V.owners(vts), lambda f: 0,
                          lambda f: True, lambda t: True)
        return m, specs[r.addr]

    m, spec = derive(called, [0x280, 0x290, 0x2a0, 0x2b0, 0x2c0])
    assert spec.order == [2] and spec.explicit_dtor and spec.fields == {0x78: V.REF, 0x80: V.REF}
    decl, names, defs = V.render_class(m, spec)
    assert decl.startswith(f"class {spec.name} : public Unk_E {{\npublic:\n    ~{spec.name}() override;\n"
                           "    void vf2() override;\n")
    assert f"// 0x7100000200: its key function\n{spec.name}::~{spec.name}() {{}}" in defs
    cls = f"{len(spec.name)}{spec.name}"
    assert sorted(names) == [(0x200, f"_ZN{cls}D2Ev"), (0x280, f"_ZN{cls}D0Ev"),
                             (0x290, f"_ZThn72_N{cls}D1Ev"), (0x2a0, f"_ZThn72_N{cls}D0Ev"),
                             (0x2b0, f"_ZThn80_N{cls}D1Ev"), (0x2c0, f"_ZThn80_N{cls}D0Ev"), (0x500, f"_ZN{cls}3vf2Ev")]
    m, spec = derive(inlined, [0x280, 0x300, 0x380, 0x400, 0x480])
    assert spec.order == [2] and not spec.explicit_dtor
    decl, names, defs = V.render_class(m, spec)
    assert "~" not in decl and "::~" not in defs


def test_tail_members_with_two_vptrs():
    """On a base with one secondary vtable (+0x48), a D2 that stores two vptrs
    and releases a reference (+0x198) before it tail-calls its base's D2
    (0x600); or that is only that tail call (an out-of-line destructor with
    nothing to do: clang skips the vptr stores): no members."""
    words = [0xF81E0FF3, 0xA9017BFD, 0x910043FD,                # str x19, [sp, #-0x20]! ; stp x29, x30 ; add x29
             0xB0000008, 0xF9400908,                            # adrp x8 ; ldr x8, [x8, #0x10]: the vtable
             0x91004109, 0x91014108, 0xAA0003F3,                # add x9, x8, #0x10 ; add x8, x8, #0x50 ; mov x19, x0
             0xF9000009, 0xF9002408]                            # str x9, [x0] ; str x8, [x0, #0x48]
    words += [0xF9400000 | (0x198 // 8) << 10, 0xB40000A0, 0xF8448C08, 0xF9400D08, 0xD63F0100,
              0xF900027F | (0x198 // 8) << 10]                  # the reference
    words += [0xA9417BFD, 0xAA1303E0, 0xF84207F3]               # ldp x29, x30 ; mov x0, x19 ; ldr x19, [sp], #0x20
    words.append(b(0x200 + 4 * len(words), 0x600))
    img = bytearray(0x1100)
    struct.pack_into(f"<{len(words)}I", img, 0x200, *words)
    struct.pack_into("<I", img, 0x300, b(0x300, 0x600))
    sizes = {0x200: 4 * len(words), 0x300: 4}
    m = V.Model("sword", bytes(img), sorted(sizes.items()), [], [], sizes, {}, {}, lambda a: "game", DELETE,
                {0x1010: 0x3000})
    assert V.tail_members(m, 0x200, 0x600, 0x3000, 0x180, 2) == {0x198: V.REF}
    assert V.tail_members(m, 0x200, 0x600, 0x3000, 0x180) is None          # three vptrs aren't these
    assert V.tail_members(m, 0x200, 0x600, 0x3000, 0x1a0, 2) is None       # +0x198 is the base's
    assert V.tail_members(m, 0x200, 0x600, 0x3000, 0x180, 4) is None
    assert V.tail_members(m, 0x300, 0x600, 0x3000, 0x180, 2) == {}
    assert V.tail_members(m, 0x300, 0x600, 0x3000, 0x180) == {}
    assert V.tail_members(m, 0x300, 0x700, 0x3000, 0x180, 2) is None       # another base's D2


def test_derived_from_an_out_of_line_base_with_one_interface():
    """A class Z on a hand-written base without types whose D2 is out of line
    (0x100, its D0 and thunks tail-call it), with one interface at +0x48. Z
    has nothing to destroy, but a D2 of its own, `b <the base's D2>`: its
    destructor is out of line (so clang can't alias it) and empty (so it
    stores no vptrs). Its D0 and its thunks tail-call the base's D2 too. Its
    destructor is written out as its key function, and its slot 5 is declared
    as the base declares it."""
    img = bytearray(0x2000)
    sub = 0xD1012000                                                   # sub x0, x0, #0x48
    code = {0x100: [0xAA0003E8, RET], 0x110: [b(0x110, 0x100)], 0x120: [0xAA0003E9, RET],    # E
            0x130: [0xAA0003EA, RET], 0x140: [0xAA0003EB, RET], 0x150: [0x90000000, 0x91000000, RET],
            0x160: [sub, b(0x164, 0x100)], 0x170: [sub, b(0x174, 0x100)],
            0x180: [0xAA0003EC, RET], 0x190: [0xAA0003ED, RET],
            0x300: [b(0x300, 0x100)], 0x350: [b(0x350, 0x100)], 0x380: [0x90000000, 0x91004000, RET],  # Z
            0x400: [sub, b(0x404, 0x100)], 0x450: [sub, b(0x454, 0x100)]}
    for a, w in code.items():
        struct.pack_into(f"<{len(w)}I", img, a, *w)
    slots = {}

    def vt(start, ott, fns):
        struct.pack_into("<q", img, start, ott)
        for i, f in enumerate(fns):
            slots[start + 16 + 8 * i] = f
        return start + 16 + 8 * len(fns)

    end = vt(0x1000, 0, [0x100, 0x110, 0x120, 0x130, 0x140, 0x150])   # E
    end = vt(end, -0x48, [0x160, 0x170, 0x180, 0x190])                # E at +0x48
    z_start = end
    end = vt(end, 0, [0x300, 0x350, 0x120, 0x130, 0x140, 0x380])      # Z
    vt(end, -0x48, [0x400, 0x450, 0x180, 0x190])
    sizes = {a: 4 * len(w) for a, w in code.items()}
    vts, tables = V.find_vtables(bytes(img), slots, set(code), DATA, len(img))
    m = V.Model("sword", bytes(img), sorted(sizes.items()), vts, tables, sizes, {}, {}, lambda a: "game", DELETE)
    e = V.ExternalBase(vts[0].addr, "Unk_E", "unsorted/Unk_E.h", ((2, "void", "vf2"), (3, "void", "vf3"),
                       (4, "void", "vf4"), (5, "u8*", "vf5")), None, "", ((0x48, (0, 1), None),), size=0x180)
    z = next(v for v in vts if v.start == z_start)
    specs = {}
    V.derive_external(m, e, specs, {}, V.owners(vts), lambda f: 0, lambda f: True, lambda t: True)
    spec = specs[z.addr]
    assert spec.ext is e and spec.order == [5] and spec.explicit_dtor and not spec.fields
    decl, names, defs = V.render_class(m, spec)
    assert decl == f"class {spec.name} : public Unk_E {{\npublic:\n    ~{spec.name}() override;\n" \
                   f"    u8* vf5() override;\n}};\n"
    assert f"// 0x7100000300: its key function\n{spec.name}::~{spec.name}() {{}}" in defs
    cls = f"{len(spec.name)}{spec.name}"
    assert sorted(names) == [(0x300, f"_ZN{cls}D2Ev"), (0x350, f"_ZN{cls}D0Ev"), (0x400, f"_ZThn72_N{cls}D1Ev"),
                             (0x450, f"_ZThn72_N{cls}D0Ev")]
    # A D0 that tail-calls its own D2 isn't this shape: Z isn't written.
    struct.pack_into("<I", img, 0x350, b(0x350, 0x300))
    m = V.Model("sword", bytes(img), sorted(sizes.items()), vts, tables, sizes, {}, {}, lambda a: "game", DELETE)
    specs = {}
    V.derive_external(m, e, specs, {}, V.owners(vts), lambda f: 0, lambda f: True, lambda t: True)
    assert z.addr not in specs


def test_stored_vtable_owners():
    """A D2 (0x100) in slot 0 of A's and B's vtables stores B's vtable (its
    GOT slot 0x1800): it's B's, though the owner heuristic gives it to A,
    the shorter vtable. A's own D2 (0x140) stores A's: not listed."""
    def d2(slot: int) -> list[int]:
        # adrp x8 ; ldr x8, [x8, #slot] ; add x9, x8, #0x10 ; str x9, [x0] ; ret
        return [0xB0000008, 0xF9400108 | (slot // 8) << 10, 0x91004109, 0xF9000009, RET]

    img = bytearray(0x2000)
    code = {0x100: d2(0x800), 0x140: d2(0x808), 0x110: [RET], 0x120: [RET], 0x130: [0xAA0003E8, RET]}
    for a, w in code.items():
        struct.pack_into(f"<{len(w)}I", img, a, *w)
    slots = {}

    def vt(start, ott, fns):
        struct.pack_into("<q", img, start, ott)
        for i, f in enumerate(fns):
            slots[start + 16 + 8 * i] = f
        return start + 16 + 8 * len(fns)

    end = vt(0x1000, 0, [0x100, 0x110])                     # A
    b_start = end
    vt(end, 0, [0x100, 0x120, 0x130])                       # B
    end = vt(0x1100, 0, [0x140, 0x110])                     # C, with a D2 of its own
    sizes = {a: 4 * len(w) for a, w in code.items()}
    vts, tables = V.find_vtables(bytes(img), slots, set(code), DATA, len(img))
    m = V.Model("sword", bytes(img), sorted(sizes.items()), vts, tables, sizes, {}, {}, lambda a: "game", DELETE,
                {0x1800: b_start, 0x1808: 0x1100})
    a, b = (next(v for v in vts if v.start == s) for s in (0x1000, b_start))
    assert V.owners(vts)[0x100] == (a.addr, 0)
    assert V.stored_vtable_owners(m) == [(0x100, a.addr, b.addr, 2)]


def test_prefer_stored():
    """A and B have vtables of the same length that share a D2 (0x100) and
    slot 2 (0x120); A's comes first, so owners() gives both to A. The D2
    stores B's vtable: B is the base, and they're B's. Each one's D0 (0x110,
    0x130) stays its own."""
    img = bytearray(0x2000)
    # adrp x8 ; ldr x8, [x8, #0x800] ; add x9, x8, #0x10 ; str x9, [x0] ; ret
    code = {0x100: [0xB0000008, 0xF9440108, 0x91004109, 0xF9000009, RET],
            0x110: [RET], 0x120: [0xAA0003E8, RET], 0x130: [0xAA0003E9, RET]}
    for a, w in code.items():
        struct.pack_into(f"<{len(w)}I", img, a, *w)
    slots = {}

    def vt(start, ott, fns):
        struct.pack_into("<q", img, start, ott)
        for i, f in enumerate(fns):
            slots[start + 16 + 8 * i] = f
        return start + 16 + 8 * len(fns)

    b_start = vt(0x1000, 0, [0x100, 0x110, 0x120])          # A
    vt(b_start, 0, [0x100, 0x130, 0x120])                   # B
    sizes = {a: 4 * len(w) for a, w in code.items()}
    vts, tables = V.find_vtables(bytes(img), slots, set(code), DATA, len(img))
    m = V.Model("sword", bytes(img), sorted(sizes.items()), vts, tables, sizes, {}, {}, lambda a: "game", DELETE,
                {0x1800: b_start})
    a, b = (next(v for v in vts if v.start == s) for s in (0x1000, b_start))
    own = V.owners(vts)
    assert own[0x100] == (a.addr, 0) and own[0x120] == (a.addr, 2)
    got = V.prefer_stored(m, own)
    assert got[0x100] == (b.addr, 0) and got[0x120] == (b.addr, 2)
    assert got[0x110] == (a.addr, 1) and got[0x130] == (b.addr, 1)
