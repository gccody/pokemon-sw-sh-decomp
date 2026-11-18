"""tools/leafgen.py: lifting straight-line leaf functions to placeholder C++,
on hand-encoded instruction words (no game files)."""
from __future__ import annotations

import struct

import leafgen
import pytest

ADDR = 0x7100123450
RET = 0xD65F03C0
COND = {"eq": 0, "ne": 1, "hs": 2, "lo": 3, "hi": 8, "ls": 9, "ge": 10, "lt": 11, "gt": 12, "le": 13}


def code(*words: int) -> bytes:
    return struct.pack(f"<{len(words)}I", *words)


# A few encoders (ARMv8 ARM, C6), enough for the cases below.
def ldr_w(rt, rn, off):
    return 0xB9400000 | (off // 4) << 10 | rn << 5 | rt


def ldr_x(rt, rn, off):
    return 0xF9400000 | (off // 8) << 10 | rn << 5 | rt


def ldrb(rt, rn, off):
    return 0x39400000 | off << 10 | rn << 5 | rt


def ldrsh(rt, rn, off):
    return 0x79C00000 | (off // 2) << 10 | rn << 5 | rt  # 32-bit destination


def strb(rt, rn, off):
    return 0x39000000 | off << 10 | rn << 5 | rt


def str_w(rt, rn, off):
    return 0xB9000000 | (off // 4) << 10 | rn << 5 | rt


def str_x(rt, rn, off):
    return 0xF9000000 | (off // 8) << 10 | rn << 5 | rt


def str_s(rt, rn, off):
    return 0xBD000000 | (off // 4) << 10 | rn << 5 | rt


def movz_w(rd, imm):
    return 0x52800000 | imm << 5 | rd


def cmp_w(rn, imm):
    return 0x7100001F | imm << 10 | rn << 5


def sub_w(rd, rn, imm):
    return 0x51000000 | imm << 10 | rn << 5 | rd


def cset_w(rd, cond):
    return 0x1A9F07E0 | (COND[cond] ^ 1) << 12 | rd


def ubfx_w(rd, rn, lsb, width):
    return 0x53000000 | lsb << 16 | (lsb + width - 1) << 10 | rn << 5 | rd


AND_W8_W1_1 = 0x12000028  # and w8, w1, #1
BL_0 = 0x94000000


def gen(*words: int) -> str:
    structs, func = leafgen.generate(ADDR, code(*words))
    return structs + "\n" + func


def test_compare_getter():
    out = gen(ldr_w(8, 0, 0x10), cmp_w(8, 3), cset_w(0, "eq"), RET)
    assert "struct Unk_123450 {\n    u8 _0[0x10];\n    u32 field_10;\n};" in out
    assert "PKMN_OFFSET_ASSERT(Unk_123450, field_10, 0x10);" in out
    assert "bool Unk_123450_check(const Unk_123450* self) {\n    return self->field_10 == 3;\n}" in out


def test_signed_compare_makes_the_field_signed():
    out = gen(ldr_w(8, 0, 0x8), cmp_w(8, 0), cset_w(0, "gt"), RET)
    assert "s32 field_8;" in out
    assert "return self->field_8 > 0;" in out


def test_bool_setter():
    out = gen(AND_W8_W1_1, strb(8, 0, 0x20), RET)
    assert "bool field_20;" in out
    assert "void Unk_123450_set(Unk_123450* self, bool value) {\n    self->field_20 = value;\n}" in out


def test_constant_store_and_float_argument():
    out = gen(movz_w(8, 7), str_w(8, 0, 0x4), str_s(0, 0, 0x8), RET)
    assert "    self->field_4 = 7;\n    self->field_8 = fvalue;" in out
    assert "void Unk_123450_set(Unk_123450* self, f32 fvalue)" in out
    assert "f32 field_8;" in out


def test_nested_getter_defines_the_child_struct_first():
    out = gen(ldr_x(8, 0, 0x8), ldrb(0, 8, 0x30), RET)
    child, parent = out.index("struct Unk_123450_8 {"), out.index("struct Unk_123450 {")
    assert child < parent
    assert "Unk_123450_8* field_8;" in out
    assert "u8 Unk_123450_get(const Unk_123450* self) {\n    return self->field_8->field_30;\n}" in out


def test_range_check():
    out = gen(ldrb(8, 0, 0x4), sub_w(8, 8, 5), cmp_w(8, 3), cset_w(0, "lo"), RET)
    assert "return self->field_4 >= 5 && self->field_4 <= 7;" in out


def test_bitfield_getter():
    out = gen(ldrb(8, 0, 0xC), ubfx_w(0, 8, 3, 1), RET)
    assert "u32 Unk_123450_get(const Unk_123450* self) {\n    return (self->field_c >> 3) & 1;\n}" in out


def test_pointer_store_and_null_test():
    out = gen(str_x(1, 0, 0x18), RET)
    assert "void Unk_123450_set(Unk_123450* self, u64 value) {\n    self->field_18 = value;\n}" in out
    # x0 = self->field_8 != 0, where field_8 is also dereferenced: a null test of a pointer.
    cmp_x = 0xF100001F | 8 << 5  # cmp x8, #0
    out = gen(ldr_x(8, 0, 0x8), ldrb(9, 8, 0x4), str_x(9, 0, 0x10), cmp_x, cset_w(0, "ne"), RET)
    assert "return self->field_8 != nullptr;" in out


@pytest.mark.parametrize("words, why", [
    ((BL_0, RET), "bl"),
    ((ldr_w(0, 0, 4),), "ret"),                                  # no ret at the end
    ((0x34000040, RET), "cbz"),                                  # cbz w0, +8: a branch
    ((ldr_w(8, 9, 0), RET), "before"),                           # x9 isn't an argument
    ((ldrsh(8, 0, 2), sub_w(8, 8, 5), cmp_w(8, 3), cset_w(0, "lo"), RET), "signed"),
])
def test_refused(words, why):
    with pytest.raises(leafgen.LiftError, match=why):
        leafgen.generate(ADDR, code(*words))


def test_tail_call():
    """ldr x0, [x0, #8] ; b +0x100: the call gets the field (a u64: nothing
    dereferences it). Pointer arguments are void*, so the callee's name
    doesn't depend on its callers' placeholder structs."""
    structs, func = leafgen.generate(ADDR, code(ldr_x(0, 0, 8), 0x14000000 | 0x100 >> 2))
    assert "void Unk_123554(u64);\n" in structs
    assert func == "void Unk_123450_call(const Unk_123450* self) {\n    Unk_123554(self->field_8);\n}\n"
    assert leafgen.callee_name(ADDR + 0x104, ["void*"]) == ("Unk_123554", "_Z10Unk_123554Pv")


def test_tail_call_passes_unwritten_arguments_through():
    """mov w1, #5 ; b +0x100: x0 is passed on as it came."""
    structs, func = leafgen.generate(ADDR, code(0x528000A1, 0x14000000 | 0x100 >> 2))
    assert "void Unk_123554(void*, u32);\n" in structs
    assert func == "void Unk_123450_call(void* self) {\n    Unk_123554(self, 5);\n}\n"
    with pytest.raises(leafgen.LiftError, match="ret"):  # without an address, no tail call
        leafgen.lift(code(0x528000A1, 0x14000000 | 0x100 >> 2))


def test_tail_call_to_a_known_function(monkeypatch):
    """ldr x0, [x0, #8] ; b +0x100, where the target is a leaf function already
    written: it's called by its own prototype, and field_8 points to its struct."""
    monkeypatch.setitem(leafgen.KNOWN, ADDR + 0x104, ("u8", "Unk_123554_get", ["const Unk_123554*"]))
    structs, func = leafgen.generate(ADDR, code(ldr_x(0, 0, 8), 0x14000000 | 0x100 >> 2))
    assert structs.startswith("struct Unk_123554;\n")
    assert "    Unk_123554* field_8;\n" in structs
    assert structs.endswith("u8 Unk_123554_get(const Unk_123554*);\n")
    assert func == "void Unk_123450_call(const Unk_123450* self) {\n    Unk_123554_get(self->field_8);\n}\n"
    monkeypatch.setitem(leafgen.KNOWN, ADDR + 0x104, ("void", "Unk_123554_set", ["Unk_123554*", "bool"]))
    with pytest.raises(leafgen.LiftError, match="other parameters"):
        leafgen.generate(ADDR, code(ldr_x(0, 0, 8), 0x14000000 | 0x100 >> 2))


def test_callers_that_pass_fewer_arguments_on():
    """One caller writes x0 and w1 for Unk_123554, another only x0: the
    second passes its w1 on, typed as the first sets it."""
    lifted = {1: ("void Unk_123554(u64, u32);\n", "void Unk_1_call() {}\n"),
              2: ("void Unk_123554(u64);\n", "void Unk_2_call() {}\n"),
              3: ("void Unk_123560(u64);\n", "void Unk_3_call() {}\n")}
    assert leafgen.unify_arity(lifted) == {ADDR + 0x104: ["u64", "u32"]}
    lifted[4] = ("void Unk_123554(u32);\n", "void Unk_4_call() {}\n")  # another type: no
    assert leafgen.unify_arity(lifted) == {}
    leafgen.TAIL_TYPES[ADDR + 0x104] = ["u64", "u32"]
    try:
        structs, func = leafgen.generate(ADDR, code(ldr_x(0, 0, 8), 0x14000000 | 0x100 >> 2))
    finally:
        del leafgen.TAIL_TYPES[ADDR + 0x104]
    assert "void Unk_123554(u64, u32);" in structs
    assert func == "void Unk_123450_call(const Unk_123450* self, u32 value) {\n    Unk_123554(self->field_8, value);\n}\n"


def test_mangle_and_param_types():
    assert leafgen.param_types("const Unk_1* self, u32 value, void* /*unused*/") == ["const Unk_1*", "u32", "void*"]
    assert leafgen.mangle("Unk_1_set", ["Unk_1*", "bool"]) == "_Z9Unk_1_setP5Unk_1b"
    assert leafgen.mangle("Unk_1_get", ["const Unk_1*"]) == "_Z9Unk_1_getPK5Unk_1"
    assert leafgen.mangle("Unk_1_get", []) == "_Z9Unk_1_getv"
    assert leafgen.mangle("Unk_1_set", ["Unk_1*", "const Unk_1*"]) is None  # needs a substitution


def test_tail_call_argument_moved_as_32_bits():
    """mov x0, x1 ; mov w1, w2 ; b +0x100: the second argument is a u32 (a w move)."""
    structs, func = leafgen.generate(ADDR, code(0xAA0103E0, 0x2A0203E1, 0x14000000 | 0x100 >> 2))
    assert "void Unk_123558(u64, u32);" in structs
    assert func == "void Unk_123450_call(void* /*unused*/, u64 value, u32 arg2) {\n    Unk_123558(value, arg2);\n}\n"


def test_pointer_loaded_once_is_a_local():
    """ldr x8, [x0, #0x230] ; cbz x8, L ; ldr x9, [x1, #8] ; str x9, [x8, #0x48] ;
    ldr x9, [x1] ; str x9, [x8, #0x40] ; L: ret. With -fno-strict-aliasing the first
    store could change self->field_230, so the source held it in a local."""
    _, func = leafgen.generate(ADDR, code(ldr_x(8, 0, 0x230), cbz_x(8, 5), ldr_x(9, 1, 8), str_x(9, 8, 0x48),
                                          ldr_x(9, 1, 0), str_x(9, 8, 0x40), RET))
    assert func == ("void Unk_123450_set(const Unk_123450* self, const Unk_123450_arg1* value) {\n"
                    "    Unk_123450_230* p0 = self->field_230;\n    if (p0 != nullptr) {\n"
                    "        p0->field_48 = value->field_8;\n        p0->field_40 = value->field_0;\n    }\n}\n")
    # loaded again after the first store: written as it reads
    _, func = leafgen.generate(ADDR, code(ldr_x(8, 0, 0x10), str_w(1, 8, 0), ldr_x(8, 0, 0x10), str_w(1, 8, 4), RET))
    assert "    self->field_10->field_0 = value;\n    self->field_10->field_4 = value;\n" in func


def test_pairs():
    """ldp x8, x9, [x0, #0x10] ; stp x9, x8, [x0, #0x20] ; ret: two loads, two stores."""
    ldp = 0xA9400000 | (0x10 // 8) << 15 | 9 << 10 | 0 << 5 | 8
    stp = 0xA9000000 | (0x20 // 8) << 15 | 8 << 10 | 0 << 5 | 9
    _, func = leafgen.generate(ADDR, code(ldp, stp, RET))
    assert "    self->field_20 = self->field_18;\n    self->field_28 = self->field_10;\n" in func
    with pytest.raises(leafgen.LiftError, match="address"):  # stp x29, x30, [sp, #-0x10]!: a frame
        leafgen.generate(ADDR, code(0xA9BF7BFD, RET))


def test_global(monkeypatch):
    """adrp x8, +1 page ; ldr x8, [x8, #0x10] ; ldr w0, [x8] ; ret: the GOT slot
    at 0x124010 holds a global's address, so it's an extern variable."""
    adrp = 0x90000000 | 1 << 29 | 8  # immlo = 1: one page past the function's
    monkeypatch.setitem(leafgen.GOT, 0x124010, 0x200000)
    structs, func = leafgen.generate(ADDR, code(adrp, ldr_x(8, 8, 0x10), ldr_w(0, 8, 0), RET))
    assert structs == "extern u32 Unk_200000;"
    assert func == "u32 Unk_123450_get() {\n    return Unk_200000;\n}\n"
    with pytest.raises(leafgen.LiftError, match="offset"):  # a field of a global
        leafgen.generate(ADDR, code(adrp, ldr_x(8, 8, 0x10), ldr_w(0, 8, 4), RET))
    with pytest.raises(leafgen.LiftError, match="GOT"):  # not a slot it knows
        leafgen.generate(ADDR, code(adrp, ldr_x(8, 8, 0x18), ldr_w(0, 8, 0), RET))


def test_guard_with_a_constant_and_a_store_before_it():
    """str w1, [x0, #0x10] ; ldr x8, [x0, #8] ; cbz x8, L ; ldr w0, [x8] ; ret ; L: mov w0, #1 ; ret."""
    _, func = leafgen.generate(ADDR, code(str_w(1, 0, 0x10), ldr_x(8, 0, 8), cbz_x(8, 3), ldr_w(0, 8, 0), RET,
                                          0x52800020, RET))
    assert func == ("u32 Unk_123450_update(Unk_123450* self, u32 value) {\n    self->field_10 = value;\n"
                    "    if (self->field_8 == nullptr) {\n        return 1;\n    }\n"
                    "    return self->field_8->field_0;\n}\n")


def cbz_x(rt, insns):
    return 0xB4000000 | insns << 5 | rt  # cbz xN, +4*insns


def test_guarded_tail_call():
    """ldr x0, [x0, #8] ; cbz x0, L ; b +0x100 ; L: ret: the call only if the field isn't 0."""
    _, func = leafgen.generate(ADDR, code(ldr_x(0, 0, 8), cbz_x(0, 2), 0x14000000 | 0x100 >> 2, RET))
    assert func == ("void Unk_123450_call(const Unk_123450* self) {\n    if (self->field_8 != 0) {\n"
                    "        Unk_123558(self->field_8);\n    }\n}\n")


def test_guarded_getter_returns_0_otherwise():
    """ldr x8, [x0, #0x10] ; cbz x8, L ; ldrb w0, [x8, #4] ; ret ; L: mov w0, wzr ; ret."""
    mov_w0_wzr = 0x2A1F03E0
    _, func = leafgen.generate(ADDR, code(ldr_x(8, 0, 0x10), cbz_x(8, 3), ldrb(0, 8, 4), RET, mov_w0_wzr, RET))
    assert func == ("u8 Unk_123450_get(const Unk_123450* self) {\n    if (self->field_10 == nullptr) {\n"
                    "        return 0;\n    }\n    return self->field_10->field_4;\n}\n")
    # ldrb w0, [x0, #4] ; cbz w0, L ; strb wzr, [x0, #5] ; L: ret: a store on one path only
    out = gen(ldrb(8, 0, 4), 0x34000048, strb(31, 0, 5), RET)  # cbz w8, +8
    assert "    if (self->field_4 != 0) {\n        self->field_5 = 0;\n    }\n" in out


@pytest.mark.parametrize("words, why", [
    ((ldr_x(8, 0, 8), cbz_x(8, 2), ldr_w(0, 8, 0), 0x52800020, RET), "falls"),   # into L: mov w0, #1
    ((ldr_x(8, 0, 8), cbz_x(8, 2), ldr_w(0, 8, 0), 0xAA0103E0, RET), "other code"),  # L: mov x0, x1
    ((ldr_x(8, 0, 8), cbz_x(8, 3), cbz_x(8, 2), str_w(1, 8, 0), RET), "more than one"),
    ((cbz_x(1, 2), 0x14000000 | 0x40, 0x2A1F03E0, RET), "tail call"),   # 0, or what the tail call returns
])
def test_guard_refused(words, why):
    with pytest.raises(leafgen.LiftError, match=why):
        leafgen.generate(ADDR, code(*words))


def test_wide_constant():
    """mov w8, #0x5678 ; movk w8, #0x1234, lsl #16 ; str w8, [x0, #4] ; ret."""
    out = gen(movz_w(8, 0x5678), 0x72A00000 | 0x1234 << 5 | 8, str_w(8, 0, 4), RET)
    assert "    self->field_4 = 0x12345678;\n" in out
    with pytest.raises(leafgen.LiftError, match="movk of a computed"):  # movk w1, #1, lsl #16: an argument
        leafgen.generate(ADDR, code(0x72A00021, str_w(1, 0, 4), RET))


def test_misaligned_field_is_refused():
    # ldur w0, [x0, #2]: a u32 at offset 2 can't be a plain struct member.
    ldur_w = 0xB8400000 | 2 << 12 | 0 << 5 | 0
    with pytest.raises(leafgen.LiftError, match="misaligned"):
        leafgen.generate(ADDR, code(ldur_w, RET))


def test_file_round_trip():
    a = leafgen.generate(ADDR, code(ldr_w(8, 0, 0x10), cmp_w(8, 3), cset_w(0, "eq"), RET))
    empty = ("", "void Unk_123460() {}\n")  # batch 1's form of an empty function
    text = leafgen.render_file([(ADDR + 0x10, *empty), (ADDR, *a)])
    assert text.startswith("// Scope: common\n")
    assert text.index("// 0x7100123450") < text.index("// 0x7100123460")
    assert "\n\n// 0x7100123460\nvoid Unk_123460() {}\n" in text and text.endswith("{}\n")
    blocks = leafgen.parse_file(text)
    assert [b[0] for b in blocks] == [ADDR, ADDR + 0x10]
    assert blocks[1] == (ADDR + 0x10, *empty)
    assert leafgen.render_file(blocks) == text


def test_move_reads_into_a_local():
    """ldr x8, [x0] ; str xzr, [x0] ; str x8, [x1] ; ret: the load comes before a
    store that may overwrite it (a move), so the source held it in a local. A
    store to another field of the same pointer can't overwrite it: no local."""
    _, func = leafgen.generate(ADDR, code(ldr_x(8, 0, 0), str_x(31, 0, 0), str_x(8, 1, 0), RET))
    assert func == ("void Unk_123450_set(Unk_123450* self, Unk_123450_arg1* value) {\n"
                    "    u64 v0 = self->field_0;\n    self->field_0 = 0;\n    value->field_0 = v0;\n}\n")
    _, func = leafgen.generate(ADDR, code(ldr_x(8, 0, 8), str_x(31, 0, 0), str_x(8, 0, 0x10), RET))
    assert "v0" not in func


def test_struct_copy():
    """ldp x8, x9, [x0] ; ldr x10, [x0, #0x10] ; stp x9, x10, [x1, #8] ; str x8, [x1] ;
    ret: clang's copy of a 24-byte struct (memcpy order), `*value = *self`."""
    ldp = 0xA9400000 | 9 << 10 | 0 << 5 | 8
    stp = 0xA9000000 | (8 // 8) << 15 | 10 << 10 | 1 << 5 | 9
    structs, func = leafgen.generate(ADDR, code(ldp, ldr_x(10, 0, 0x10), stp, str_x(8, 1, 0), RET))
    assert func == "void Unk_123450_set(const Unk_123450* self, Unk_123450* value) {\n    *value = *self;\n}\n"
    assert "    u64 field_10;\n" in structs
    # without ldp it's field by field
    _, func = leafgen.generate(ADDR, code(ldr_x(8, 0, 0), str_x(8, 1, 0), ldr_x(8, 0, 8), str_x(8, 1, 8), RET))
    assert "value->field_8 = self->field_8;" in func


def adrp(rd, pc, target):
    imm = ((target & ~0xFFF) - (pc & ~0xFFF)) >> 12
    return 0x90000000 | (imm & 3) << 29 | ((imm >> 2) & 0x7FFFF) << 5 | rd


def add_imm(rd, rn, imm):
    return 0x91000000 | imm << 10 | rn << 5 | rd


def test_returns_a_table_or_a_string(monkeypatch):
    """mov w8, #0x1fb ; str w8, [x0] ; adrp x0, T ; add x0, x0, T ; ret: a table
    this TU defines (adrp + add, not the GOT), declared hidden; a string
    literal where T is one; refused where T is code or a vtable."""
    table = 0x7101F10C68
    words = (0x52803F68, str_w(8, 0, 0), adrp(0, ADDR + 8, table), add_imm(0, 0, table & 0xFFF), RET)
    monkeypatch.setattr(leafgen, "DATA_AT", lambda a: "" if a == table else None)
    structs, func = leafgen.generate(ADDR, code(*words))
    assert 'extern const u8 Unk_1f10c68[] __attribute__((visibility("hidden")));' in structs
    assert func.startswith("const u8* Unk_123450_update(Unk_123450* self) {\n    self->field_0 = 0x1fb;\n")
    assert "    return Unk_1f10c68;\n" in func
    monkeypatch.setattr(leafgen, "DATA_AT", lambda a: "a \\\"b\\\"")
    _, func = leafgen.generate(ADDR, code(*words))
    assert '    return "a \\"b\\"";\n' in func
    monkeypatch.setattr(leafgen, "DATA_AT", None)
    with pytest.raises(leafgen.LiftError, match="code or a vtable"):
        leafgen.generate(ADDR, code(*words))
