"""tools/vtables.py: finding vtables, groups, owners, bases and the placeholder
classes, on a hand-built image (no game files)."""
from __future__ import annotations

import struct

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
    which stores Unk_1040's vptr), then store Unk_1000's vptr from the GOT."""
    from types import SimpleNamespace

    img = bytearray(0x1100)
    bl = 0x94000000 | ((0x300 - 0x210) >> 2)
    ctor = [0xF81E0FF3, 0xA9017BFD, 0x910043FD, 0xAA0003F3, bl,  # str x19 ; stp ; add x29 ; mov x19, x0 ; bl
            0x90000008, 0xF9405108, 0x91004108, 0xF9000268,      # adrp x8 ; ldr x8, [x8, #0xa0] ; add #16 ; str
            0xA9417BFD, 0xF84207F3, RET]                         # ldp ; ldr x19, [sp], #0x20 ; ret
    struct.pack_into("<12I", img, 0x200, *ctor)
    struct.pack_into("<I", img, 0x300, RET)
    struct.pack_into("<I", img, 0x400, RET)
    slots = {0x1010: 0x400, 0x1050: 0x400}                       # vtables at 0x1000 and 0x1040, one slot each
    vts, tables = V.find_vtables(bytes(img), slots, {0x200, 0x300, 0x400}, DATA, len(img))
    vts[0].referrers, vts[1].referrers = {0x200}, {0x300}
    sizes = {0x200: 48, 0x300: 4, 0x400: 4}
    m = V.Model("sword", bytes(img), sorted(sizes.items()), vts, tables, sizes, {}, {}, lambda a: "game", DELETE)
    rows = {a: SimpleNamespace(name="", status="U", scope="common", shield=a) for a in sizes}
    ctors = V.find_ctors(m, rows, set())
    assert ctors == [V.Ctor(0x200, 0x300, "Unk_1000", "Unk_1040")]
    assert V.find_ctors(m, rows, {"Unk_1040"}) == []             # a class defined elsewhere
    rows[0x300].name = "_ZN8Unk_1040C2Ev"                        # the base constructor named as that: fine
    assert V.find_ctors(m, rows, set()) == ctors
    rows[0x300].name = "_Z3foov"
    assert V.find_ctors(m, rows, set()) == []
    text = V.render_ctor_file(ctors, {"Unk_1000": "Unk_1040"})
    assert "class Unk_1040 {\npublic:\n    Unk_1040();\n    virtual ~Unk_1040();\n};\n\n" \
           "class Unk_1000 : public Unk_1040 {\npublic:\n    Unk_1000();\n    ~Unk_1000() override;\n};\n" in text
    assert text.endswith("// 0x7100000200\nUnk_1000::Unk_1000() {}\n")
    assert V.ctor_name("Unk_1000") == "_ZN8Unk_1000C2Ev"
