"""tools/viewgen.py: reading the views' lookups and writing their instances,
on hand-encoded instructions (no game files)."""
from __future__ import annotations

import struct

import viewgen as V

ACQ, REL = 0x9000, 0x9010        # __cxa_guard_acquire / release
GOT = 0x8000                     # GOT page: slot -> type object or guard


def adrp(rd: int, pc: int, target: int) -> int:
    imm = ((target & ~0xFFF) - (pc & ~0xFFF)) >> 12
    return 0x90000000 | ((imm & 3) << 29) | (((imm >> 2) & 0x7FFFF) << 5) | rd


def ldr(rt: int, rn: int, off: int) -> int:
    return 0xF9400000 | ((off // 8) << 10) | (rn << 5) | rt


def bl(pc: int, target: int) -> int:
    return 0x94000000 | (((target - pc) >> 2) & 0x3FFFFFF)


def assemble(at: int, items) -> tuple[bytes, int]:
    img = bytearray(0xB000)
    words = []
    for x in items:
        words.append(x if isinstance(x, int) else x(at + 4 * len(words)))
    struct.pack_into(f"<{len(words)}I", img, at, *words)
    return bytes(img), 4 * len(words)


# GOT slots: 0x00 guard of T's type, 0x08 T's type
SLOTS = {GOT + 0x00: 0xA000, GOT + 0x08: 0xA008}


def test_names():
    n = V.instance_name("Unk_23f6118")
    assert n == "_ZN16Unk_a7bb80_Views10Unk_a7bb80I11Unk_23f6118EEPT_RK15Unk_5cfaf0_Name"
    assert V.instance_class(n) == "Unk_23f6118"
    assert V.instance_class("_ZN11Unk_23f611811Unk_GetTypeEv") is None
    assert V.instance_class(None) is None


def test_scan_types_lets_other_code_through():
    # the lookup's tail: a virtual call (vf_type), then T's getter inlined over a
    # call of its parent's (0x400), stored into T's type; other code in between
    items = [0xF9400268,                                   # ldr x8, [x19]
             0xD63F0100,                                   # blr x8
             0xAA0003F4,                                   # mov x20, x0
             lambda pc: adrp(0, pc, GOT), ldr(0, 0, 0x00),
             lambda pc: bl(pc, ACQ),
             0x34000040,                                   # cbz w0, +8
             lambda pc: bl(pc, 0x400),
             lambda pc: adrp(8, pc, GOT), ldr(8, 8, 0x08),
             0xF9000100,                                   # str x0, [x8]
             0xEB08029F,                                   # cmp x20, x8
             lambda pc: adrp(0, pc, GOT), ldr(0, 0, 0x00),
             lambda pc: bl(pc, REL),
             0xD65F03C0]
    img, size = assemble(0x100, items)
    stores, calls = V.scan_types(img, 0x100, size, SLOTS, (ACQ, REL))
    assert stores == {0xA008: ("ret", 0x400)}
    assert calls == [0x400]


def test_scan_types_forgets_overwritten_registers():
    # x8 is loaded from the GOT, then overwritten: its store isn't a type's
    items = [lambda pc: adrp(8, pc, GOT), ldr(8, 8, 0x08),
             0x91002108,                                   # add x8, x8, #8
             0xF9000100]                                   # str x0, [x8]
    img, size = assemble(0x100, items)
    assert V.scan_types(img, 0x100, size, SLOTS, (ACQ, REL)) == ({}, [])


def test_emitted_elsewhere():
    texts = {
        "a.cpp": '#include "contents/common/views.h"\nvoid f() { v->Unk_a7bb80<Unk_A>("x"); }\n'
                 'Unk_StateView<Unk_B>(this, "y");\n',
        "b.cpp": '#include "contents/common/views.h"\n'
                 'template <>\nUnk_C* Unk_a7bb80_Views::Unk_a7bb80<Unk_C>(const Unk_5cfaf0_Name& name);\n'
                 'void g() { v->Unk_a7bb80<Unk_C>(n); }\n',
        "c.cpp": '#include "contents/common/framework.h"\nvoid h() { v->Unk_a7bb80<Unk_D>(n); }\n',
    }
    assert V.emitted_elsewhere(texts) == {"Unk_A", "Unk_B"}


def test_ancestors():
    parent = {1: ("obj", 2), 2: ("obj", 3), 3: ("zero",), 4: ("?", 0x100)}
    assert V.ancestors(parent, 1) == [2, 3]
    assert V.ancestors(parent, 4) == []


def test_source_inlined_with_cut():
    v = V.View(0x795BC0, "Unk_23f6118", 0xA008, [0xA008], ("cut", 0x400))
    expr = {0xA008: "Unk_23f6118::Unk_GetType()"}
    src = V.source(v, expr, V.VIEW, 0xA018)
    # the view class's getter only declared, T's inline over it, the instance
    assert "class Unk_23f4660 : public Unk_239a418 {\npublic:\n    static const Unk_239a418_Type* Unk_GetType();" in src
    assert "class Unk_23f6118 : public Unk_23f4660 {" in src
    assert "static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());" in src
    assert '#include "contents/common/views.inl"' in src
    assert src.index("views.inl") < src.index("class Unk_23f6118")
    assert src.rstrip().endswith("// 0x7100795bc0\ntemplate Unk_23f6118* Unk_a7bb80_Views::Unk_a7bb80<Unk_23f6118>"
                                 "(const Unk_5cfaf0_Name& name);")


def test_source_called_getter_and_other_cut():
    # T's getter called (no stores), on the object; another class's getter cut in a second instance
    v = V.View(0x790F90, "Unk_23f5fa8", 0xA008, [], ("cut", 0x400), base="Unk_239a418")
    src = V.source(v, {0xA008: "Unk_23f5fa8::Unk_GetType()"}, "Unk_23f5fa8", 0xA008)
    assert "class Unk_23f5fa8 : public Unk_239a418 {\npublic:\n    static const Unk_239a418_Type* Unk_GetType();\n};" in src
    assert "struct Unk_23f5fa8" not in src
    w = V.View(0x100, "Unk_T", 0xA008, [0xA008, 0xA018], ("cut", 0x400))
    expr = {0xA008: "Unk_T::Unk_GetType()", 0xA018: "Unk_M::Unk_GetType()"}
    src = V.source(w, expr, "Unk_P", 0xA028)
    assert "struct Unk_P {\n    static const Unk_239a418_Type* Unk_GetType();\n};" in src
    assert "struct Unk_M {" in src and "static Unk_239a418_Type type(Unk_P::Unk_GetType());" in src
    assert "static Unk_239a418_Type type(Unk_M::Unk_GetType());" in src
