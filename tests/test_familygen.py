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


def object_factory_words(at: int, got: int) -> list[int]:
    """A factory of a class on the object: an allocation of 0x70 bytes, a
    reference moved in (the argument cleared) to +0x60, a u32 zero at +0x68."""
    words = [
        0xAA0103F4, 0xAA0203F6, 0,          # mov x20, x1 ; mov x22, x2 ; bl GetTlsValue
        0xAA0003F3, 0xF9400288, 0xF9400908,  # mov x19, x0 ; ldr x8, [x20] ; ldr x8, [x8, #0x10]
        0x52800E01, 0x52800102, 0xAA1403E0,  # mov w1, #0x70 ; mov w2, #8 ; mov x0, x20
        0xD63F0100, 0xAA0003F5, 0xB50000A0,  # blr x8 ; mov x21, x0 ; cbnz x0, +0x14
        0xF9400288, 0xF9405D08, 0xAA1403E0, 0xD63F0100,  # the allocator's slot 23
        0xF94002D7, 0xF90002DF, 0xAA1503E0, 0,  # ldr x23, [x22] ; str xzr, [x22] ; mov x0, x21 ; bl ctor
        0, 0xF9400508,                      # adrp x8, <got> ; ldr x8, [x8, #8]
        0x91004109, 0xF90002A9, 0x91014109, 0x9102410A,  # the vptrs
        0xA904AAA9, 0xF90032B7, 0xB9006ABF,  # stp x9, x10, [x21, #0x48] ; str x23, [x21, #0x60] ; str wzr, [x21, #0x68]
        0x52800E08, 0x52800109, 0xA900D6B4, 0xA901A6A8,  # the allocation recorded
        0xD65F03C0,                         # ret
    ]
    words[2] = bl(at + 8, F.GET_TLS)
    words[19] = bl(at + 0x4C, F.OBJECT_CTOR)
    words[20] = adrp(8, at + 0x50, got)
    return words


def test_walk():
    at = 0x1000
    words = [0xF9400428, 0xF9000808, 0xD65F03C0]   # ldr x8, [x1, #8] ; str x8, [x0, #0x10] ; ret
    m = fake_module(at, words, {})
    w = F.walk(m, at, 12, {0: F.Sym("obj"), 1: F.Sym("arg", (1,))}, lambda *_: None)
    loaded = F.Sym("mem", (("arg", (1,)), 8, 8))
    assert w.events == [("load", F.Sym("arg", (1,)), 8, 8, loaded), ("store", F.Sym("obj"), 0x10, 8, loaded),
                        ("ret",)]


def test_parse_object():
    at, got, vt = 0x1000, 0x3008, 0x5000
    m = fake_module(at, object_factory_words(at, got), {got: vt})
    f = F.parse_object(m, at)
    assert isinstance(f, F.ObjectFactory), f
    assert (f.cls, f.size, f.align, f.extra_slots, f.interface, f.parented) == ("Unk_5000", 0x70, 8, 0, False, False)
    assert f.params == [F.Param("ref", True, True)]
    assert f.members == [F.Member(0x60, "ref", 0, moved=True), F.Member(0x68, "u32", value=0)]
    assert F.object_name(f) == ("_ZN7Unk_New6CreateI8Unk_5000J15Unk_239a418_RefI11Unk_239a418EEEEPT_"
                                "P21Unk_239a418_AllocatorDpOT0_")
    text = F.object_class(f)
    assert "Unk_5000(Unk_Ref a0) : field_60(std::move(a0)) {}" in text
    assert "    u32 field_68 = 0;" in text
    assert text.endswith("template Unk_5000* Unk_New::Create<Unk_5000>(Unk_239a418_Allocator*, Unk_Ref&&);\n")

    # not cleared, and no reference added: a u64 passed by value
    words = object_factory_words(at, got)
    words[17] = 0xD503201F                   # nop instead of clearing the argument
    f2 = F.parse_object(fake_module(at, words, {got: vt}), at)
    assert f2.params == [F.Param("u64", True, False)] and f2.members[0] == F.Member(0x60, "u64", 0)

    # a call the family doesn't make
    words[16] = bl(at + 0x40, 0x9000)
    assert F.parse_object(fake_module(at, words, {got: vt}), at) == f"a call to {0x9000 + F.BASE:#x}"


def test_object_names():
    def factory(cls, kinds, base=F.OBJECT_BASES[F.OBJECT_CTOR]):
        params = [F.Param(k, True, moved) for k, moved in kinds]
        return F.ObjectFactory(0, cls, 0, 8, 0, False, params, [], base)

    assert F.object_name(factory("Unk_240d540", [("pair", True), ("ref", False)])) == (
        "_ZN7Unk_New6CreateI11Unk_240d540J19Unk_239a418_RefPairRK15Unk_239a418_RefI11Unk_239a418EEEEPT_"
        "P21Unk_239a418_AllocatorDpOT0_")
    assert F.object_name(factory("Unk_2411db0", [("pair", True), ("words2", False)])) == (
        "_ZN7Unk_New6CreateI11Unk_2411db0J19Unk_239a418_RefPairRK18Unk_1085320_Words2EEEPT_"
        "P21Unk_239a418_AllocatorDpOT0_")
    base = F.OBJECT_BASES[0xE7F820]
    f = factory("Unk_23c9028", [(t, False) for t in base.args], base)
    assert F.object_name(f) == "_ZN7Unk_New6CreateI11Unk_23c9028JRKPvRKmS6_EEEPT_P21Unk_239a418_AllocatorDpOT0_"
    assert "    using Unk_23f4660::Unk_23f4660;" in F.object_class(f)
    assert F.creator_name("Unk_23f5fa8") == (
        "_ZN16Unk_790260_Owner6CreateI11Unk_23f5fa8EE15Unk_239a418_RefIT_ERKS2_I11Unk_239a418Em")
    f.parented = True
    text = F.object_class(f)
    assert "class Unk_23c9028_Parent : public Unk_23f4660 {" in text
    assert "class Unk_23c9028 : public Unk_23c9028_Parent {" in text
    assert F.creator_class(f).endswith(
        "template Unk_239a418_Ref<Unk_23c9028> Unk_790260_Owner::Create<Unk_23c9028>(const Unk_Ref& parent, u64 a2);\n")


def test_adders():
    def factory(cls, kinds):
        params = [F.Param(k, True, moved) for k, moved in kinds]
        return F.ObjectFactory(0, cls, 0, 8, 0, False, params, [])

    # what an adder hands its factory after the weak reference, and its name
    f = factory("Unk_240b658", [("pair", True), ("u32", False)])
    assert F.adder_args(f) == ["u32"]
    assert F.adder_name(f) == (
        "_ZN17Unk_1050c60_Owner7Unk_AddI11Unk_240b658JjEEE15Unk_239a418_RefI11Unk_239a418EDpRKT0_")
    assert F.adder_instance(0x1050C60, f) == (
        "// 0x7101050c60\ntemplate Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_240b658>(const u32&);\n")
    f = factory("Unk_240d540", [("pair", True), ("ref", False)])
    assert F.adder_name(f) == (
        "_ZN17Unk_1050c60_Owner7Unk_AddI11Unk_240d540J15Unk_239a418_RefI11Unk_239a418EEEES4_DpRKT0_")
    f = factory("Unk_2411db0", [("pair", True), ("words2", False)])
    assert F.adder_name(f) == (
        "_ZN17Unk_1050c60_Owner7Unk_AddI11Unk_2411db0J18Unk_1085320_Words2EEE"
        "15Unk_239a418_RefI11Unk_239a418EDpRKT0_")
    f = factory("Unk_240c1b0", [("pair", True)])
    assert F.adder_args(f) == []
    assert F.adder_name(f) == (
        "_ZN17Unk_1050c60_Owner7Unk_AddI11Unk_240c1b0JEEE15Unk_239a418_RefI11Unk_239a418EDpRKT0_")
    assert F.adder_instance(0x1052DF0, f).endswith("Unk_1050c60_Owner::Unk_Add<Unk_240c1b0>();\n")
    # not an adder's factory: no weak reference first, or an argument moved in
    assert F.adder_name(factory("Unk_5000", [("ref", True)])) is None
    assert F.adder_name(factory("Unk_5000", [("pair", True), ("ref", True)])) is None


def test_adder_candidates():
    # the seed's shape with the calls an adder makes: the getter, a factory, the list
    def body(at, factory, getter=F.ADDER_GETTER):
        return [bl(at, getter), 0xAA0003F3, bl(at + 8, factory), bl(at + 12, F.ADDER_LIST), 0xD65F03C0]

    seed, other, third = F.ADDER_SEEDS[0], 0x2000, 0x3000
    img = bytearray(max(F.ADDER_SEEDS[0], F.ADDER_LIST) + 0x1000)
    rows = {}
    for at, words in ((seed, body(seed, 0x4000)), (other, body(other, 0x5000)),
                      (third, body(third, 0x5000, getter=0x6000))):
        struct.pack_into(f"<{len(words)}I", img, at, *words)
        rows[at] = SimpleNamespace(sword_size=4 * len(words), status="U", name="")
    m = F.Module(bytes(img), rows, {})
    # the third has the shape but calls another getter
    assert F.adder_candidates(m) == {seed: 0x4000, other: 0x5000}


def test_steps():
    members = [F.Member(0x68, "pair", 0), F.Member(0x78, "u64", None, 0), F.Member(0x80, "u32", 1)]
    f = F.ObjectFactory(0x1054340, "Unk_240b658", 0x88, 8, 6, True,
                        [F.Param("pair", True, True), F.Param("u32", False, False)], members)
    owner = F.STEP_OWNERS[0x1054690]
    funcs = {"vf7": 0x1054610, "vf9": 0x1054660, "vf10": 0x1054690, "vf11": 0x1054750,
             "t9": 0x1054AE0, "t10": 0x1054B10, "t11": 0x1054BD0}
    s = F.Step("Unk_240b658", funcs, owner, 0x1054D30, 0x1053F20)
    # the class declares the interface it overrides
    text = F.object_class(f, s)
    assert "public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {" in text
    assert "    virtual u64 vf7();" in text and "    void vf11() override;" in text
    assert "    void vf10(const Unk_1085320_Optional<u32>* code) override;" in text
    assert "public Unk_1085320_Interface {" in F.object_class(f)
    # names: the four functions, the interface's thunks, and the two callees
    rows = {a: SimpleNamespace(name="") for a in (0x1054D30, 0x1053F20)}
    names = F.step_names(SimpleNamespace(rows=rows), s)
    assert names[0x1054610] == "_ZN11Unk_240b6583vf7Ev"
    assert names[0x1054690] == "_ZN11Unk_240b6584vf10EPK20Unk_1085320_OptionalIjE"
    assert names[0x1054B10] == "_ZThn96_N11Unk_240b6584vf10EPK20Unk_1085320_OptionalIjE"
    assert names[0x1054BD0] == "_ZThn96_N11Unk_240b6584vf11Ev"
    assert names[0x1054D30] == "_Z11Unk_1054d30P11Unk_240b658Pv"
    assert names[0x1053F20] == "_Z11Unk_1053f20P17Unk_1050c60_Owner"
    # a callee someone named otherwise: the step isn't written
    rows[0x1053F20].name = "_Z5otherv"
    assert F.step_names(SimpleNamespace(rows=rows), s) == "0x7101053f20 is named otherwise"
    # the functions, each with its thunk's address, and the owner's kind
    body = F.step_functions(s)
    assert "// 0x7101054690\n// 0x7101054b10\nvoid Unk_240b658::vf10(const Unk_1085320_Optional<u32>* code) {" in body
    assert "Unk_WeakGet<Unk_1054690_Owner>(field_68))\n        owner->Unk_Fail(*code);" in body
    assert "field_78 = Unk_1054d30(this, &field_80);" in body
    header = F.step_header([s])
    assert "class Unk_1054690_Owner : public Unk_1050c60_Owner {" in header
    assert "Unk_1056d00_Owner" not in header
    assert "u64 Unk_1054d30(Unk_240b658* self, void* arg);" in header
    # a kind whose failure is a u64, by value
    by_value = F.Step("Unk_240bd60", funcs, F.STEP_OWNERS[0x1059AA0], 0x1054D30, 0x1053F20)
    assert "owner->Unk_Fail(code);" in F.step_functions(by_value)
    assert F.step_names(SimpleNamespace(rows={}), by_value) == "0x7101054d30 isn't a function"
    # not a step: no weak reference first, or no interface
    f.params[0] = F.Param("ref", True, True)
    assert F.parse_step(None, f) == "not a class with a weak reference and the interface"


def test_makes():
    funcs = {k: 0x1000 + 0x100 * n for n, k in enumerate(("vf7", "vf9", "vf10", "vf11", "t9", "t10", "t11"))}
    step = F.Step("Unk_240b658", funcs, F.STEP_OWNERS[0x1054690], 0x1054D30, 0x1053F20)
    k = F.Make(0x1054D30, step, F.MAKE_SEEDS[0x1054D30], 0x240CB78, 0x240B758)
    body = F.make_function(k)
    assert body.startswith("// 0x7101054d30\nu64 Unk_1054d30(Unk_240b658* self, void* arg) {\n")
    assert "auto task = Unk_2771620_MakeUnique<Unk_240cb78>(allocator);" in body
    assert ("task->field_18 = Unk_1054d30_MakeWeak<Unk_1085320_Step<const Unk_1085320_Optional<u32>*>>(self);"
            in body)
    assert "task->field_28 = *static_cast<const u32*>(arg);" in body
    # two makes of one task: its classes are written once
    other = F.Step("Unk_240b970", funcs, F.STEP_OWNERS[0x1054690], 0x10572B0, 0x1053F20)
    k2 = F.Make(0x10572B0, other, F.MAKE_SEEDS[0x1054D30], 0x240CB78, 0x240B758)
    classes = F.make_classes([k, k2])
    assert classes == [
        "class Unk_240b758 {\npublic:\n    virtual void vf0();\n};\n",
        "class Unk_240cb78\n    : public Unk_1054d30_TaskOf<Unk_1085320_Step<const Unk_1085320_Optional<u32>*>, "
        "u32, Unk_240b758> {\npublic:\n    ~Unk_240cb78() override;\n};\n"]
    # a task made with another member: neither can be written
    k3 = F.Make(0x10868C0, other, F.MAKE_SEEDS[0x10868C0], 0x240CB78, 0x240B758)
    assert F.make_classes([k, k3]) == "the task Unk_240cb78 is made two ways"
    # a task with a member after the one with a vtable: a class of its own between the two
    k4 = F.Make(0x10B2610, other, F.MAKE_SEEDS[0x10B2610], 0x2412AF8, 0x240B758)
    classes = F.make_classes([k, k4])
    assert len(classes) == 4 and classes[0].startswith("class Unk_240b758 {")   # the member's class, once
    assert classes[2] == (
        "class Unk_2412af8_Members\n    : public Unk_1054d30_TaskOf<Unk_1085320_Step<const Unk_1085320_Optional<u32>*>, "
        "u32, Unk_240b758> {\npublic:\n    u32 field_38 = 0;\n};\n")
    assert classes[3] == "class Unk_2412af8\n    : public Unk_2412af8_Members {\npublic:\n    ~Unk_2412af8() override;\n};\n"
    # two words copied, the task's vtable loaded first
    assert F.MAKE_SEEDS[0x10B3120].task_first and not F.MAKE_SEEDS[0x1054D30].task_first
    assert F.MAKE_SEEDS[0x10B3120].arg == "Unk_1085320_Words2"
    # the manager's name carries the tasks' base
    assert F.MAKE_NAMES[F.MAKE_RUN].endswith("unique_ptrI15Unk_6a1f80_Task19Unk_23f4660_DeleterEE")


def test_parse_make():
    # a make of the seed's shape: its globals and calls decide
    seed = 0x1054D30
    got_mgr, got_tls, got_tail, got_task = 0x8000, 0x8008, 0x8010, 0x8018

    def body(at):
        return [adrp(8, at, got_mgr), 0xF9400108 | ((got_mgr & 0xFFF) >> 3 << 10), bl(at + 8, F.MAKE_ALLOCATOR),
                adrp(8, at + 12, got_tls), 0xF9400108 | ((got_tls & 0xFFF) >> 3 << 10),
                adrp(8, at + 20, got_tail), 0xF9400108 | ((got_tail & 0xFFF) >> 3 << 10),
                adrp(9, at + 28, got_task), 0xF9400129 | ((got_task & 0xFFF) >> 3 << 10),
                bl(at + 36, F.MAKE_RUN), 0xD65F03C0]

    other = 0x3000
    img = bytearray(max(seed, F.MAKE_RUN) + 0x1000)
    rows = {}
    for at in (seed, other):
        words = body(at)
        struct.pack_into(f"<{len(words)}I", img, at, *words)
        rows[at] = SimpleNamespace(sword_size=4 * len(words), status="U", name="")
    slots = {got_mgr: F.MAKE_MANAGER, got_tls: 0x2771620, got_tail: 0x240B758, got_task: 0x240CB78}
    m = F.Module(bytes(img), rows, slots)
    step = F.Step("Unk_240b970", {}, F.STEP_OWNERS[0x1054690], other, 0x1053F20)
    k = F.parse_make(m, step)
    assert isinstance(k, F.Make), k
    assert (k.addr, k.arg, k.task, k.tail) == (other, "u32", 0x240CB78, 0x240B758)
    # another global first: not the manager
    slots[got_mgr] = 0x1234
    assert F.parse_make(F.Module(bytes(img), rows, slots), step) == "other globals"
    # another shape
    rows[other] = SimpleNamespace(sword_size=8, status="U", name="")
    assert F.parse_make(m, step) == "another shape"


def test_calls():
    # bl targets, and b targets outside the function (tail calls)
    at = 0x1000
    words = [bl(at, 0x4000), 0x14000002, 0xD65F03C0, 0x14000000 | (((0x5000 - (at + 12)) >> 2) & 0x3FFFFFF)]
    m = fake_module(at, words, {})
    assert F._calls(m, at) == ([0x4000], [0x5000])


def test_copied_reference_is_ref2():
    # a reference copied from the factory's const& argument: kept as Unk_239a418_Ref2
    f = F.ObjectFactory(0, "Unk_5000", 0x68, 8, 0, False, [F.Param("ref", True, False)],
                        [F.Member(0x60, "ref", 0)])
    text = F.object_class(f)
    assert "Unk_5000(Unk_239a418_Ref2<Unk_239a418> a0) : field_60(a0) {}" in text
    assert "    Unk_239a418_Ref2<Unk_239a418> field_60;" in text
    assert text.endswith("(Unk_239a418_Allocator*, const Unk_Ref&);\n")
    # moved in: a plain reference
    f.params, f.members = [F.Param("ref", True, True)], [F.Member(0x60, "ref", 0, moved=True)]
    assert "    Unk_Ref field_60;" in F.object_class(f)


def test_written_elsewhere(tmp_path):
    (tmp_path / "a.cpp").write_text("// 0x71006157f0\nstruct X {};\n// not 0x7100000010\n")
    assert F.written_elsewhere([tmp_path]) == {0x6157F0}
