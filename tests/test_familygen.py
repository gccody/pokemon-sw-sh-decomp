"""tools/familygen.py: instruction decoding, member layout, names, a factory parsed
from hand-encoded words. No game files."""
from __future__ import annotations

import struct
from types import SimpleNamespace

import familygen as F


def test_bitmask_and_constants():
    assert F.bitmask(0, 0x1D, 0, 32) == 8          # orr w2, wzr, #0x8
    assert F.bitmask(1, 28, 0, 64) == 1 << 36
    assert F.bitmask(0, 0, 28, 32) == 0x1FFFFFFF
    assert F.const_def(0x52801101) == (1, 0x88)      # mov w1, #0x88
    assert F.const_def(0x321D03E2) == (2, 8)         # orr w2, wzr, #0x8
    assert F.const_def(0x321C03E2) == (2, 16)
    orr_x8 = 0xB2000000 | (1 << 22) | (28 << 16) | (0 << 10) | (31 << 5) | 8
    assert F.const_def(orr_x8) == (8, 1 << 36)       # mov x8, #0x1000000000
    assert F.const_def(0x12800008) == (8, 0xFFFFFFFF)  # mov w8, #-1 (movn)
    assert F.const_def(0xF2A00028) == (8, ("movk", 16, 1))
    assert F.const_def(0xAA1503E0) is None           # mov x0, x21


def test_stores():
    assert F.store(0xF9003EBF) == (21, [(31, 0x78, 8)])                 # str xzr, [x21, #0x78]
    assert F.store(0xF807C2A8) == (21, [(8, 0x7C, 8)])                  # stur x8, [x21, #0x7c]
    assert F.store(0xA907FEBF) == (21, [(31, 0x78, 8), (31, 0x80, 8)])  # stp xzr, xzr, [x21, #0x78]
    assert F.store(0x390202BF) == (21, [(31, 0x80, 1)])                 # strb wzr, [x21, #0x80]
    assert F.store(0x7900F2A8) == (21, [(8, 0x78, 2)])                  # strh w8, [x21, #0x78]
    assert F.store(0xFD000000) == "simd"                                # str d0, [x0]
    assert F.store(0xF9400508) is None                                  # ldr x8, [x8, #8]


def test_layout():
    stored = {0x78: 0}
    stored.update({0x7C + k: b for k, b in enumerate((0x1000000000).to_bytes(8, "little"))})
    stored.update({b: 0 for b in range(0x88, 0xA0)})
    stored[0xA0] = 0
    assert F.layout(0x78, 0xA8, stored) == [
        (0x78, 1, 0), (0x79, 1, None), (0x7A, 2, None), (0x7C, 4, 0), (0x80, 4, 0x10),
        (0x84, 4, None), (0x88, 8, 0), (0x90, 8, 0), (0x98, 8, 0), (0xA0, 1, 0)]
    assert F.layout(0x78, 0x80, {}) == [(0x78, 8, None)]
    assert F.member(0x80, 4, 0x10) == "    u32 field_80 = 0x10;"
    assert F.member(0x84, 4, None) == "    u32 field_84;"


def test_names():
    assert F.vector_name("ptr", "Unk_5ac520") == (
        "_ZNSt3__16vectorIP10Unk_5ac52021Unk_2771620_AllocatorIS2_EE21__push_back_slow_pathIRKS2_EEvOT_")
    assert F.vector_name("refm", "Unk_5e7430") == (
        "_ZNSt3__16vectorI16Unk_239a418_Ref2I10Unk_5e7430E21Unk_2771620_AllocatorIS3_EE"
        "21__push_back_slow_pathIS3_EEvOT_")
    assert F.vector_name("reserve", "Unk_115a520") == (
        "_ZNSt3__16vectorI16Unk_239a418_Ref2I11Unk_115a520E21Unk_2771620_AllocatorIS3_EE7reserveEm")
    assert F.vector_name("refc", "Unk_641110").endswith("21__push_back_slow_pathIRKS3_EEvOT_")
    assert F.vector_name("s16c", "Unk_5a9500") == (
        "_ZNSt3__16vectorI10Unk_5a950021Unk_2771620_AllocatorIS1_EE21__push_back_slow_pathIRKS1_EEvOT_")
    assert F.factory_name("Unk_23bc050") == (
        "_ZN7Unk_New6CreateI11Unk_23bc050J15Unk_239a418_RefI11Unk_239a418ES4_EEEPT_"
        "P21Unk_239a418_AllocatorDpOT0_")
    s = F.Singleton(0x7C20, 0x7CA0, "Unk_236d328", "Unk_24ba608", 0)
    assert F.singleton_names(s) == {0x7C20: "_ZN11Unk_236d3283vf3Ev", 0x7CA0: "_ZThn72_N11Unk_236d3283vf3Ev"}
    assert "Unk_7c20_Reset(Unk_24ba608);" in F.singleton_class(s)


def test_vector_instance():
    assert F.vector_instance("ptr", "Unk_1") == (
        "struct Unk_1;\ntemplate void Unk_2771620_Vector<Unk_1*>::__push_back_slow_path<Unk_1* const&>"
        "(Unk_1* const&);")
    assert F.vector_instance("refm", "Unk_1").endswith(
        "__push_back_slow_path<Unk_239a418_Ref2<Unk_1>>(Unk_239a418_Ref2<Unk_1>&&);")
    assert F.vector_instance("reserve", "Unk_1").endswith("::reserve(size_t);")


def test_masked():
    words = [0x94000010, 0x14000003, 0xD0000008, 0xF9400508, 0x91004108]
    img = struct.pack("<5I", *words)
    out = struct.unpack("<5I", F.masked(img, 0, 20))
    assert out == (0x94000000, 0x14000000, 0x90000008, 0xF9400108, 0x91000108)


def adrp(rd: int, pc: int, target: int) -> int:
    imm = ((target & ~0xFFF) - (pc & ~0xFFF)) >> 12
    return 0x90000000 | ((imm & 3) << 29) | (((imm >> 2) & 0x7FFFF) << 5) | rd


def bl(pc: int, target: int) -> int:
    return 0x94000000 | (((target - pc) >> 2) & 0x3FFFFFF)


def fake_module(at: int, words: list[int], slots: dict) -> F.Module:
    img = bytearray(0x10000)
    struct.pack_into(f"<{len(words)}I", img, at, *words)
    row = SimpleNamespace(sword_size=4 * len(words), status="U", name="")
    return F.Module(bytes(img), {at: row}, slots)


def test_parse_factory():
    at, got, vt = 0x1000, 0x3008, 0x5000
    ctor_call = at + 0x10
    words = [
        0x52801101,                     # mov w1, #0x88
        0xD63F0100,                     # blr x8
        0xAA1503E0,                     # mov x0, x21
        0xD503201F,                     # nop
        0,                              # bl <the base's constructor>
        adrp(8, at + 0x14, got),        # adrp x8, <got>
        0xF9400508,                     # ldr x8, [x8, #8]
        0xA907FEBF,                     # stp xzr, xzr, [x21, #0x78]
        0x91004109,                     # add x9, x8, #0x10
        0xF90002A9,                     # str x9, [x21]
        0x9101E109,                     # add x9, x8, #0x78
        0x9102E108,                     # add x8, x8, #0xb8
        0xA904A2A9,                     # stp x9, x8, [x21, #0x48]
        F.LDR_X0_SP_8,
    ]
    words[4] = bl(ctor_call, F.FACTORY_BASE_CTOR)
    m = fake_module(at, words, {got: vt})
    f = F.parse_factory(m, at)
    assert isinstance(f, F.Factory), f
    assert (f.cls, f.size, f.extra_slots, f.parented) == ("Unk_5000", 0x88, 0, False)
    assert f.fields == [(0x78, 8, 0), (0x80, 8, 0)]
    text = F.factory_class(f)
    assert "class Unk_5000 : public Unk_23f43c8 {" in text
    assert "template Unk_5000* Unk_New::Create<Unk_5000>(" in text

    # members stored before the vptr's adrp: a parent holds them
    words2 = words[:5] + [0xA907FEBF] + words[5:7] + words[8:]
    m2 = fake_module(at, words2, {got: vt})
    f2 = F.parse_factory(m2, at)
    assert isinstance(f2, F.Factory) and f2.parented
    assert "class Unk_5000_Parent : public Unk_23f43c8 {" in F.factory_class(f2)

    m3 = fake_module(at, words[:4], {})
    assert F.parse_factory(m3, at) == "no call to the base's constructor"
