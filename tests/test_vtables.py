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
