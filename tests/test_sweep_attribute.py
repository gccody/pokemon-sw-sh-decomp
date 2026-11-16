"""sweep_attribute.py: pinning compiled names to originals through relocation
targets, and the per-original classes. Hand-encoded words, no game files."""
from __future__ import annotations

import json

import compiler_sweep
import sweep_attribute as sa
from sweep_attribute import Copy, Original, Reloc
from test_compiler_sweep import pack, tiny_elf

RET = 0xD65F03C0
NOP = 0xD503201F
MOV_X0_X1 = 0xAA0103E0
MOV_X0_X2 = 0xAA0203E0
BL_0 = 0x94000000  # bl <reloc>
ADRP_X8_0 = 0x90000008
ADD_X8_X8_0 = 0x91000108
STR_X8_X0 = 0xF9000008  # str x8, [x0]
BRK_1 = 0xD4200020


def bl(pc: int, target: int) -> int:
    return 0x94000000 | (((target - pc) // 4) & 0x3FFFFFF)


def adrp_x8(pc: int, target: int) -> int:
    imm = ((target & ~0xFFF) - (pc & ~0xFFF)) >> 12
    return 0x90000008 | ((imm & 3) << 29) | (((imm >> 2) & 0x7FFFF) << 5)


def add_x8(target: int) -> int:
    return 0x91000108 | ((target & 0xFFF) << 10)


def call(i: int, name: str) -> Reloc:
    return Reloc(i, 283, name, 0)


def test_branch_and_adrp_decoding():
    ws = (bl(0x1004, 0x2000), adrp_x8(0x1004, 0x5010), add_x8(0x5010))
    assert sa.branch_target(ws, 0x1004, 0) == 0x2000
    assert sa.adrp_page(ws, 0x1000, 1) == 0x5000
    assert sa.lo12(ws[2]) == 0x10
    # load/store offsets are scaled by the access size
    assert sa.lo12(0x394D0129) == 0x340  # ldrb w9, [x9, #0x340]
    assert sa.lo12(0xB9400D08) == 0xC  # ldr w8, [x8, #0xc]
    assert sa.lo12(0xF9400D08) == 0x18  # ldr x8, [x8, #0x18]
    assert sa.lo12(0x3DC00500) == 0x10  # ldr q0, [x8, #0x10]


def test_imports_pin_identical_code():
    # 0x100 and 0x200 have the same code up to the call target; one calls the
    # import impX, the other impY, and so do the two compiled functions.
    plt = {0x8000: "impX", 0x8010: "impY"}
    orig = Original({0x100: (NOP, bl(0x104, 0x8000), RET), 0x200: (NOP, bl(0x204, 0x8010), RET)}, plt, {})
    f = Copy("f", (NOP, BL_0, RET), (call(1, "impX"),))
    g = Copy("g", (NOP, BL_0, RET), (call(1, "impY"),))
    res = sa.attribute([f, g], {}, orig)
    assert res.pinned == {"f": 0x100, "g": 0x200}
    assert [r[2] for r in sa.classify(res, orig)] == ["attributed", "attributed"]


def test_calls_pin_callees_and_find_differing_code():
    orig = Original({
        0x100: (MOV_X0_X1, bl(0x104, 0x200), bl(0x108, 0x300), RET),  # caller: unique shape
        0x200: (NOP, NOP, RET),  # same code as 0x400, but it's the one the caller calls
        0x300: (MOV_X0_X2, RET),  # the compiled `other` is different code
        0x400: (NOP, NOP, RET),
    }, {}, {})
    caller = Copy("caller", (MOV_X0_X1, BL_0, BL_0, RET), (call(1, "callee"), call(2, "other@tu")))
    callee = Copy("callee", (NOP, NOP, RET))
    other = Copy("other@tu", (MOV_X0_X1, RET))
    res = sa.attribute([caller, callee, other], {}, orig)
    assert res.pinned == {"caller": 0x100, "callee": 0x200, "other@tu": 0x300}
    rows = {a: (cls, names) for a, _, cls, names in sa.classify(res, orig)}
    assert rows == {0x100: ("attributed", ["caller"]), 0x200: ("attributed", ["callee"]),
                    0x300: ("differs", ["other@tu"]), 0x400: ("same-code", ["callee"])}


def test_vtable_slots_pin_virtual_functions():
    # The constructor at 0x100 stores the vtable address point (0x5010); the
    # vtable's first slot points at 0x300, which has the same code as 0x200.
    ctor_ws = (adrp_x8(0x100, 0x5010), add_x8(0x5010), STR_X8_X0, RET)
    orig = Original({0x100: ctor_ws, 0x200: (NOP, RET), 0x300: (NOP, RET)}, {}, {0x5010: 0x300})
    ctor = Copy("ctor", (ADRP_X8_0, ADD_X8_X8_0, STR_X8_X0, RET),
                (Reloc(0, 275, "_ZTV3Foo", 16), Reloc(1, 277, "_ZTV3Foo", 16)))
    vf = Copy("vf", (NOP, RET))
    res = sa.attribute([ctor, vf], {"_ZTV3Foo": {16: "vf"}}, orig)
    assert res.pinned == {"ctor": 0x100, "vf": 0x300}


def test_taken_addresses_pin_functions():
    # The registration function at 0x100 stores the address of the solver at
    # 0x300 (adrp/add) into a table; 0x200 has the same code as 0x300.
    reg_ws = (adrp_x8(0x100, 0x300), add_x8(0x300), STR_X8_X0, RET)
    orig = Original({0x100: reg_ws, 0x200: (NOP, RET), 0x300: (NOP, RET)}, {}, {})
    reg = Copy("register", (ADRP_X8_0, ADD_X8_X8_0, STR_X8_X0, RET),
               (Reloc(0, 275, "solve", 0), Reloc(1, 277, "solve", 0)))
    res = sa.attribute([reg, Copy("solve", (NOP, RET))], {}, orig)
    assert res.pinned == {"register": 0x100, "solve": 0x300}


def test_a_call_to_an_original_pinned_to_another_function_disagrees():
    # register_new and register_old have the same code; the original at 0x100
    # calls 0x200, the unique `impl_new`. register_old calls impl_old, which
    # isn't in the original: only register_new is pinned to 0x100.
    orig = Original({0x100: (NOP, bl(0x104, 0x200), RET), 0x200: (MOV_X0_X1, RET)}, {}, {})
    new = Copy("register_new", (NOP, BL_0, RET), (call(1, "impl_new"),))
    old = Copy("register_old", (NOP, BL_0, RET), (call(1, "impl_old"),))
    res = sa.attribute([old, new, Copy("impl_new", (MOV_X0_X1, RET)), Copy("impl_old", (MOV_X0_X2, RET))], {}, orig)
    assert res.pinned == {"register_new": 0x100, "impl_new": 0x200}


def test_trap_word_and_unpinned_names():
    orig = Original({0x100: (sa.TRAP_NX,), 0x200: (MOV_X0_X1, bl(0x204, 0x300), RET), 0x300: (RET,)}, {}, {})
    trap = Copy("D0", (BRK_1,))
    caller = Copy("caller", (MOV_X0_X1, BL_0, RET), (call(1, "undefined_here"),))
    res = sa.attribute([trap, caller], {}, orig)
    rows = {a: (cls, names) for a, _, cls, names in sa.classify(res, orig)}
    assert rows == {0x100: ("attributed-trap", ["D0"]), 0x200: ("attributed", ["caller"]),
                    0x300: ("pinned-no-copy", ["undefined_here"])}


def test_conflicting_pins_are_left_out():
    orig = Original({0x100: (MOV_X0_X1, bl(0x104, 0x300), RET), 0x200: (MOV_X0_X2, bl(0x204, 0x400), RET),
                     0x300: (NOP, RET), 0x400: (NOP, RET)}, {}, {})
    a = Copy("a", (MOV_X0_X1, BL_0, RET), (call(1, "same"),))
    b = Copy("b", (MOV_X0_X2, BL_0, RET), (call(1, "same"),))
    res = sa.attribute([a, b, Copy("same", (NOP, RET))], {}, orig)
    assert "same" not in res.pinned and res.conflicts == {"same": {0x300, 0x400}}


def test_read_object_qualifies_names_and_resolves_relocations(tmp_path):
    text = pack(NOP, RET, NOP, BL_0, RET)
    obj = tmp_path / "0123abcd_GuFoo.o"
    obj.write_bytes(tiny_elf(text, [("pad", 0, 2, 0, 8), ("foo", 1, 2, 8, 12), ("bar", 1, 0, 0, 0)],
                             [(12, 3, 283)]))
    copies, vtables = sa.read_objects(tmp_path)
    assert copies == [Copy("pad@GuFoo", (NOP, RET), (), "GuFoo", (1 << 32) | 0),
                      Copy("foo", (NOP, BL_0, RET), (Reloc(1, 283, "bar", 0),), "GuFoo", (1 << 32) | 8)]
    assert vtables == {}


def test_local_tables_are_found_through_their_section(tmp_path):
    # A static table (+8) pointing at fn: the assembler turns references to a
    # local object into its section symbol plus an offset, so the table is
    # also keyed by its section, with offsets from the section's start.
    text = pack(NOP, RET, 0, 0)
    obj = tmp_path / "0123abcd_GuFoo.o"
    obj.write_bytes(tiny_elf(text, [("tbl", 0, 1, 8, 8), ("fn", 1, 2, 0, 8)], [(8, 2, sa.R_ABS64)]))
    _, tables = sa.read_objects(tmp_path)
    assert tables == {"tbl@GuFoo": {0: "fn"}, "<.text.foo@GuFoo>": {8: "fn"}}


def test_summary_counts_every_class():
    rows = [(0x100, 8, "attributed", ["f"]), (0x200, 64, "attributed", ["g"]), (0x300, 4, "none", [])]
    text = sa.summary(rows)
    assert "attributed" in text and text.splitlines()[-1].split() == ["total", "3", "76"]


def test_sweep_keeps_objects_in_obj_dir(tmp_path):
    args = compiler_sweep.arg_parser().parse_args(["--compiler", "cc", "--src", "a.cpp", "--obj-dir", str(tmp_path)])
    assert args.obj_dir == tmp_path


def test_read_objects_from_a_cmake_build_dir(tmp_path):
    text = pack(NOP, RET)
    (tmp_path / "obj").mkdir()
    (tmp_path / "obj" / "GuBar.cpp.obj").write_bytes(tiny_elf(text, [("bar", 0, 2, 0, 8)], []))
    (tmp_path / "obj" / "Other.cpp.obj").write_bytes(tiny_elf(text, [("other", 0, 2, 0, 8)], []))
    entries = [{"directory": str(tmp_path), "file": str(tmp_path / "lib" / "px" / "GuBar.cpp"), "output": "obj/GuBar.cpp.obj"},
               {"directory": str(tmp_path), "file": str(tmp_path / "src" / "Other.cpp"), "output": "obj/Other.cpp.obj"}]
    (tmp_path / "compile_commands.json").write_text(json.dumps(entries))
    copies, _ = sa.read_objects(tmp_path)
    assert [(c.name, c.tu) for c in copies] == [("bar@GuBar", "GuBar"), ("other@Other", "Other")]
    copies, _ = sa.read_objects(tmp_path, (tmp_path / "lib").as_posix() + "/")
    assert [c.name for c in copies] == ["bar@GuBar"]



def test_alias_keys_prefer_the_base_structor():
    assert sa.alias_key("_ZN3FooC1Ev") == sa.alias_key("_ZN3FooC2Ev") != sa.alias_key("_ZN3FooD2Ev")
    assert sa.alias_key("_ZN3FooD0Ev") != sa.alias_key("_ZN3FooD2Ev")
    assert sa.prefer_base({"_ZN3FooD1Ev", "_ZN3FooD2Ev"}) == "_ZN3FooD2Ev"
    assert sa.prefer_base({"plain"}) == "plain"


def layout_case():
    # Three TUs laid out in order: A (0x100-0x2ff), B (0x300-0x5ff). 0x200 and
    # 0x400 are identical `ret` functions; each TU has its own static copy.
    unique = {0x100: (MOV_X0_X1, NOP, RET), 0x300: (MOV_X0_X2, NOP, RET), 0x500: (MOV_X0_X2, MOV_X0_X1, RET)}
    orig = Original({**unique, 0x200: (RET,), 0x400: (RET,)}, {}, {})
    copies = [Copy("a1", unique[0x100], (), "A", 1), Copy("ret@A", (RET,), (), "A", 2),
              Copy("b1", unique[0x300], (), "B", 1), Copy("ret@B", (RET,), (), "B", 2),
              Copy("b2", unique[0x500], (), "B", 3)]
    return orig, copies


def test_layout_places_identical_copies_in_their_tu():
    orig, copies = layout_case()
    res = sa.attribute(copies, {}, orig)
    assert "ret@A" not in res.pinned and "ret@B" not in res.pinned
    out = sa.resolve_layout(res, copies, orig)
    assert out[0x200] == ("ret@A", "layout") and out[0x400] == ("ret@B", "layout")
    assert out[0x100] == ("a1", "pinned")


def test_layout_respects_section_order_within_a_tu():
    # In TU B the static copy comes after b2, so it can't be between b1 and b2.
    orig, copies = layout_case()
    copies = [c._replace(order=4) if c.name == "ret@B" else c for c in copies]
    out = sa.resolve_layout(sa.attribute(copies, {}, orig), copies, orig)
    assert 0x400 not in out


def test_two_names_on_one_address_prefer_the_referenced_one():
    # f and g have the same code and both equal one original; only g is called.
    orig = Original({0x100: (MOV_X0_X1, RET), 0x200: (NOP, bl(0x204, 0x100), RET)}, {}, {})
    copies = [Copy("f", (MOV_X0_X1, RET), (), "T", 1), Copy("g", (MOV_X0_X1, RET), (), "T", 2),
              Copy("caller", (NOP, BL_0, RET), (call(1, "g"),), "T", 3)]
    out = sa.resolve_layout(sa.attribute(copies, {}, orig), copies, orig)
    assert out[0x100] == ("g", "pinned")


def test_complete_and_base_structors_are_one_name():
    orig = Original({0x100: (MOV_X0_X1, RET)}, {}, {})
    copies = [Copy("_ZN3FooC1Ev", (MOV_X0_X1, RET), (), "T", 1), Copy("_ZN3FooC2Ev", (MOV_X0_X1, RET), (), "T", 1)]
    out = sa.resolve_layout(sa.attribute(copies, {}, orig), copies, orig)
    assert out == {0x100: ("_ZN3FooC2Ev", "pinned")}
