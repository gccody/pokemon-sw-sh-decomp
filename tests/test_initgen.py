"""tools/initgen.py: static initialisers read from hand-encoded instructions, the orders their
statements are tried in and what is written for them (no game files)."""
from __future__ import annotations

import struct
from types import SimpleNamespace

import familygen as F
import initgen as I
import pytest

RET = 0xD65F03C0
LDN_AT = 0x17E8F30
PLT = {LDN_AT: I.LDN}
RODATA = (0x1A00000, 0x1C00000)
OBJ = 0x27D9000 + 0x5B0             # a TU's statics
PROLOGUE = [0xF81E0FF3, 0xA9017BFD, 0x910043FD]     # str x19, [sp, #-0x20]! ; stp x29, x30, [sp, #0x10] ; add x29, sp, #0x10
EPILOGUE = [0xA9417BFD, 0xF84207F3]                 # ldp x29, x30, [sp, #0x10] ; ldr x19, [sp], #0x20


def movz(rd: int, imm: int, hw: int = 0, x: bool = False) -> int:
    return (0xD2800000 if x else 0x52800000) | (hw << 21) | (imm << 5) | rd


def movk(rd: int, imm: int, hw: int) -> int:
    return 0xF2800000 | (hw << 21) | (imm << 5) | rd


def mov_wzr(rd: int) -> int:
    return 0x2A1F03E0 | rd


def adrp(rd: int, pc: int, target: int) -> int:
    imm = ((target & ~0xFFF) - (pc & ~0xFFF)) >> 12
    return 0x90000000 | ((imm & 3) << 29) | (((imm >> 2) & 0x7FFFF) << 5) | rd


def add(rd: int, rn: int, imm: int) -> int:
    return 0x91000000 | (imm << 10) | (rn << 5) | rd


def address(rd: int, pc: int, target: int) -> list[int]:
    return [adrp(rd, pc, target), add(rd, rd, target & 0xFFF)]


def str_w(rt: int, rn: int, off: int) -> int:
    return 0xB9000000 | ((off // 4) << 10) | (rn << 5) | rt


def str_x(rt: int, rn: int, off: int) -> int:
    return 0xF9000000 | ((off // 8) << 10) | (rn << 5) | rt


def strh(rt: int, rn: int, off: int) -> int:
    return 0x79000000 | ((off // 2) << 10) | (rn << 5) | rt


def stp_x(rt: int, rt2: int, rn: int, off: int) -> int:
    return 0xA9000000 | (((off // 8) & 0x7F) << 15) | (rt2 << 10) | (rn << 5) | rt


def stur_x(rt: int, rn: int, off: int) -> int:
    return 0xF8000000 | ((off & 0x1FF) << 12) | (rn << 5) | rt


def ldr_q(rt: int, rn: int, off: int) -> int:
    return 0x3DC00000 | ((off // 16) << 10) | (rn << 5) | rt


def stur_q(rt: int, rn: int, off: int) -> int:
    return 0x3C800000 | ((off & 0x1FF) << 12) | (rn << 5) | rt


def bl(pc: int, target: int) -> int:
    return 0x94000000 | (((target - pc) >> 2) & 0x3FFFFFF)


def b(pc: int, target: int) -> int:
    return 0x14000000 | (((target - pc) >> 2) & 0x3FFFFFF)


def module(funcs: dict[int, list[int]], data: dict[int, bytes] | None = None, names: dict | None = None,
           rows: dict | None = None, slots: dict | None = None) -> F.Module:
    img = bytearray(0x2800000)
    out = {}
    for at, words in funcs.items():
        struct.pack_into(f"<{len(words)}I", img, at, *words)
        out[at] = SimpleNamespace(sword_size=4 * len(words), status="U", name="", sword_str=f"0x{at:016x}",
                                  shield_str=f"0x{at:016x}")
    for at, raw in (data or {}).items():
        img[at:at + len(raw)] = raw
    out.update(rows or {})
    return F.Module(bytes(img), out, slots or {}, data_names=names or {})


def numbers(a: int) -> list[int]:
    """Two integers stored into the TU's statics, and a return."""
    return (address(8, a, OBJ) + [movz(9, 5), str_w(9, 8, 0), movz(10, 0x1234, x=True), movk(10, 0x5678, 1),
                                 str_x(10, 8, 8), RET])


def with_calls(a: int) -> list[int]:
    """The nn::ldn header's statics: an address made by a call, then two numbers."""
    words = PROLOGUE + [movz(0, 0x7F), movz(3, 1), mov_wzr(1), mov_wzr(2)]
    words.append(bl(a + 4 * len(words), LDN_AT))
    words += address(19, a + 4 * len(words), OBJ)
    words += [str_w(0, 19, 0), movz(8, 0xFFFF), strh(8, 19, 0x18), mov_wzr(8), str_w(8, 19, 0x14)]
    return words + EPILOGUE + [RET]


def test_parse_numbers():
    a = 0x1000
    init = I.parse(module({a: numbers(a)}), a, PLT)
    assert init.events == [I.Store(OBJ, False, 0, 4, I.Const(5)), I.Store(OBJ, False, 8, 8, I.Const(0x56781234))]
    assert init.atexit is None


def test_parse_calls():
    a = 0x1000
    init = I.parse(module({a: with_calls(a)}), a, PLT)
    assert init.events == [I.Call(0, (0x7F, 0, 0, 1)), I.Store(OBJ, False, 0, 4, I.Ret(0)),
                           I.Store(OBJ, False, 0x18, 2, I.Const(0xFFFF)), I.Store(OBJ, False, 0x14, 4, I.Const(0))]


def test_parse_pairs_vectors_and_atexit():
    a, lit, fn, text = 0x1000, 0x1B13960, 0x2000, 0x1AB1657
    words = address(8, a, OBJ)
    words += address(10, a + 4 * len(words), text)
    words += [movz(9, 0xACC5, x=True), stp_x(9, 10, 8, 0)]                 # a hash and its string
    words += [adrp(11, a + 4 * len(words), lit), ldr_q(0, 11, lit & 0xFFF), stur_q(0, 8, 0x1C)]
    words += address(0, a + 4 * len(words), fn)
    words += address(2, a + 4 * len(words), I.DSO)
    words += [add(1, 8, 0x40)]
    words.append(b(a + 4 * len(words), I.ATEXIT))
    m = module({a: words, fn: [RET]}, {lit: struct.pack("<4f", 1.0, 0.0, 2.5, 0.0), text: b"name\0"})
    init = I.parse(m, a, PLT)
    vec = struct.unpack("<4I", struct.pack("<4f", 1.0, 0.0, 2.5, 0.0))
    assert init.events == [I.Store(OBJ, False, 0, 8, I.Const(0xACC5)),
                           I.Store(OBJ, False, 8, 8, I.Addr(text, False, text)),
                           I.Store(OBJ, False, 0x1C, 16, I.Vec(vec))]
    assert init.atexit == (I.Addr(fn, False, fn), I.Addr(OBJ + 0x40, False, OBJ))


@pytest.mark.parametrize("words, why", [
    (lambda a: address(8, a, OBJ) + [movz(9, 5), str_w(9, 8, 0), bl(a + 16, 0x3000), RET], "a call"),
    (lambda a: [movz(9, 5), str_w(9, 8, 0), RET], "a store through what isn't an address"),
    (lambda a: address(8, a, OBJ) + [str_w(9, 8, 0), RET], "w9 isn't set"),
    (lambda a: address(8, a, OBJ) + [RET], "no store"),
    (lambda a: address(8, a, OBJ) + [movz(9, 5), str_w(9, 8, 0), b(a + 16, 0x3000)], "a tail call"),
])
def test_parse_refuses(words, why):
    a = 0x1000
    with pytest.raises(I.Refuse, match=why):
        I.parse(module({a: words(a)}), a, PLT)


def test_is_candidate():
    a, c = 0x1000, 0x2000
    tail = address(8, c, OBJ) + [movz(9, 5), str_w(9, 8, 0)]
    tail.append(b(c + 4 * len(tail), I.ATEXIT))
    branch = with_calls(a)
    branch[5] = 0x34000040                                     # cbz w0: a conditional branch
    m = module({a: with_calls(a), c: tail, 0x3000: numbers(0x3000), 0x4000: branch})
    assert I.is_candidate(m, a, PLT)                           # calls MakeIpv4Address
    assert I.is_candidate(m, c, PLT)                           # ends in b __cxa_atexit
    assert not I.is_candidate(m, 0x3000, PLT)                  # neither
    assert not I.is_candidate(m, 0x4000, PLT)


def stores(*offs_widths_vec) -> list:
    return [I.Store(OBJ, False, off, width, I.Vec((0, 0, 0, 0)) if vec else I.Const(1))
            for off, width, vec in offs_widths_vec]


def test_ordered():
    run = stores((0x18, 2, False), (0x4C, 16, True), (0x14, 4, False), (0x1C, 16, True), (0x20, 8, False),
                 (0x8, 4, False))
    offs = lambda order: [e.off for e in I.ordered(run, order)]  # noqa: E731
    assert offs("asm") == [0x18, 0x4C, 0x14, 0x1C, 0x20, 0x8]
    assert offs("split") == [0x18, 0x14, 0x20, 0x8, 0x1C, 0x4C]            # the vectors last, by address
    assert offs("delay") == [0x4C, 0x18, 0x1C, 0x14, 0x20, 0x8]            # each one after the next vector
    assert offs("address") == [0x8, 0x14, 0x18, 0x1C, 0x20, 0x4C]
    assert offs("wide") == [0x18, 0x14, 0x8, 0x1C, 0x20, 0x4C]             # the narrow ones first, as they come
    assert I.ordered(run, "asm") is not run


def test_literals():
    bits = lambda v: struct.unpack("<I", struct.pack("<f", v))[0]  # noqa: E731
    assert I.f32_literal(0) == "0"
    assert I.f32_literal(bits(1.0)) == "1.0f"
    assert I.f32_literal(bits(2e4)) == "2e+04f"
    assert I.f32_literal(bits(-0.1)) == "-0.1f"
    for v in (3.1415927, 1.965e4, 1e-3, 123456.79):
        assert struct.pack("<f", float(I.f32_literal(bits(v))[:-1])) == struct.pack("<f", v)
    with pytest.raises(I.Refuse):
        I.f32_literal(0x7FC00000)                              # a NaN
    with pytest.raises(I.Refuse):
        I.f32_literal(1)                                       # a denormal
    assert I.f64_literal(struct.unpack("<Q", struct.pack("<d", 0.5))[0]) == "0.5"
    assert I.f64_literal(struct.unpack("<Q", struct.pack("<d", 3.0))[0]) == "3.0"
    assert I.int_literal(9) == "9" and I.int_literal(0x27) == "0x27"


def test_c_string():
    at = RODATA[0] + 0x100
    m = module({}, {at: b'say "hi"??\\\0', at + 0x40: b"\x01\x02\0", 0x100: b"text\0"})
    assert I.c_string(m, at, RODATA) == '"say \\"hi\\"?\\?\\\\"'
    assert I.c_string(m, at + 0x40, RODATA) is None             # not printable
    assert I.c_string(m, 0x100, RODATA) is None                 # not in .rodata


def test_function_name():
    assert I.function_name(0x1119CD0) == "_Z16Unk_1119cd0_initv"


def test_emit_numbers_and_calls():
    a = 0x1000
    m = module({a: with_calls(a)})
    src = I.emit(m, I.parse(m, a, PLT), "asm", RODATA)
    assert src.names == {a: "_Z13Unk_1000_initv"}
    text = src.text
    assert text.startswith("// Scope: common\n")
    assert "// Order: asm\n" in text
    assert "struct Unk_27d95b0_Data {" in text
    assert "    u32 field_0;\n    u8 _4[0x10];\n    u32 field_14;\n    u16 field_18;\n" in text
    assert "PKMN_OFFSET_ASSERT(Unk_27d95b0_Data, field_18, 0x18);" in text
    assert 'extern Unk_27d95b0_Data Unk_27d95b0 __attribute__((visibility("hidden")));' in text
    assert "u64 MakeIpv4Address(u8, u8, u8, u8);" in text
    body = text[text.index("void Unk_1000_init() {"):]
    assert body.split("\n")[1:6] == [
        "    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);",
        "    Unk_27d95b0.field_0 = r0;",
        "    Unk_27d95b0.field_18 = 0xffff;",
        "    Unk_27d95b0.field_14 = 0;",
        "}",
    ]
    assert "arm_neon.h" not in text and "__cxa_atexit" not in text


def table(a: int, fn: int, lit: int, text: int) -> list[int]:
    words = address(8, a, OBJ + 4)                              # the register points into the merged statics
    words += address(10, a + 4 * len(words), text)
    words += [movz(9, 0xACC5, x=True), stur_x(9, 8, 4), stur_x(10, 8, 0xC)]
    words += [adrp(11, a + 4 * len(words), lit), ldr_q(0, 11, lit & 0xFFF), stur_q(0, 8, 0x1C)]
    words += address(0, a + 4 * len(words), fn)
    words += address(2, a + 4 * len(words), I.DSO)
    words += [add(1, 8, 4)]
    words.append(b(a + 4 * len(words), I.ATEXIT))
    return words


def test_emit_table_vector_and_atexit():
    a, lit, fn, text = 0x1000, 0x1B13960, 0x2000, 0x1AB1657
    data = {lit: struct.pack("<4f", 1.0, 0.0, 2.5, 0.0), text: b"name\0"}
    m = module({a: table(a, fn, lit, text), fn: [RET]}, data)
    src = I.emit(m, I.parse(m, a, PLT), "split", RODATA)
    assert src.names == {a: "_Z13Unk_1000_initv", fn: "_Z8Unk_2000Pv"}
    t = src.text
    assert "#include <arm_neon.h>" in t and "struct Unk_Init_Vec4 {" in t
    # the struct starts where its widest field is aligned: the register's address is 4 past it
    assert "struct Unk_27d95b0_Data {" in t
    assert "    u8 _0[0x8];\n    u64 field_8;\n    const char* field_10;\n" in t
    assert "    Unk_Init_Vec4 field_20;\n" in t
    assert 'void Unk_2000(void*) __attribute__((visibility("hidden")));' in t
    body = t[t.index("void Unk_1000_init() {"):].split("\n")
    assert body[1:5] == [
        "    Unk_27d95b0.field_8 = 0xacc5;",
        '    Unk_27d95b0.field_10 = "name";',
        "    Unk_27d95b0.field_20.Set(1.0f, 0, 2.5f, 0);",
        "    __cxa_atexit(Unk_2000, &Unk_27d95b0.field_8, &__dso_handle);",
    ]

    # a named function is declared by its name, and one that isn't a plain function's is refused
    m.rows[fn].name = "_Z3Foov"
    t = I.emit(m, I.parse(m, a, PLT), "split", RODATA).text
    assert "__cxa_atexit(reinterpret_cast<void (*)(void*)>(Foo), &Unk_27d95b0.field_8, &__dso_handle);" in t
    m.rows[fn].name = "_ZN3FooD1Ev"
    with pytest.raises(I.Refuse, match="isn't a plain function's"):
        I.emit(m, I.parse(m, a, PLT), "split", RODATA)


def test_emit_refuses_named_data():
    a = 0x1000
    m = module({a: numbers(a)}, names={OBJ: "g_Real"})
    with pytest.raises(I.Refuse, match="a name of its own"):
        I.emit(m, I.parse(m, a, PLT), "asm", RODATA)


def test_plan():
    a, c, d = 0x1000, 0x2000, 0x3000
    funcs = {a: with_calls(a), c: with_calls(c), d: with_calls(d), 0x4000: numbers(0x4000)}
    m = module(funcs)
    m.rows[a].status, m.rows[a].name = "O", I.function_name(a)        # matched: kept, in its file's order
    m.rows[d].name = "_Z3Foov"                                        # someone else's
    out, candidates, skipped = I.plan(m, PLT, RODATA, order="delay", orders={a: "split", c: "split"})
    assert candidates == [a, c] and skipped == []
    assert sorted(out) == [a]
    assert "// Order: split\n" in out[a].text
    out, _, _ = I.plan(m, PLT, RODATA, only={c}, order="delay", orders={a: "split", c: "split"})
    assert sorted(out) == [a, c]
    assert "// Order: delay\n" in out[c].text                         # a trial takes the order asked for
    out, _, _ = I.plan(m, PLT, RODATA, everything=True)
    assert sorted(out) == [a, c] and "// Order: asm\n" in out[c].text


def test_plan_reports_what_it_skips():
    a = 0x1000
    words = with_calls(a)
    words.insert(len(words) - 3, bl(a + 4 * (len(words) - 3), 0x5000))  # another call
    m = module({a: words})
    out, candidates, skipped = I.plan(m, PLT, RODATA, everything=True)
    assert out == {} and candidates == [a] and skipped == [(a, "a call")]
