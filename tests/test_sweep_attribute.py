"""sweep_attribute.py: pinning compiled names to originals through relocation
targets, and the per-original classes. Hand-encoded words, no game files."""
from __future__ import annotations

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
    assert copies == [Copy("pad@GuFoo", (NOP, RET)), Copy("foo", (NOP, BL_0, RET), (Reloc(1, 283, "bar", 0),))]
    assert vtables == {}


def test_summary_counts_every_class():
    rows = [(0x100, 8, "attributed", ["f"]), (0x200, 64, "attributed", ["g"]), (0x300, 4, "none", [])]
    text = sa.summary(rows)
    assert "attributed" in text and text.splitlines()[-1].split() == ["total", "3", "76"]


def test_sweep_keeps_objects_in_obj_dir(tmp_path):
    args = compiler_sweep.arg_parser().parse_args(["--compiler", "cc", "--src", "a.cpp", "--obj-dir", str(tmp_path)])
    assert args.obj_dir == tmp_path
