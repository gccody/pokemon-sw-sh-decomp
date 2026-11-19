"""tools/nexclasses.py: NEX's DDL data classes read from their destructors.
The instructions are given as text, so no game files are needed."""
from __future__ import annotations

import pytest

import nexclasses as C
from common import BASE
from nexddl import Ins, Unrecognized

STRING_GOT, OWN_GOT, BASE_GOT, ELEM_GOT = 0x24B2000 + 0x6B8, 0x24B2000 + 0x6F0, 0x24B2000 + 0x8, 0x24B2000 + 0x10
OWN_VT, DERIVED_VT, INLINE_VT = 0x244C3B8 + 0x10, 0x244C358 + 0x10, 0x240D1C8
GOT = {STRING_GOT: C.STRING_VT - 0x10, OWN_GOT: OWN_VT - 0x10, ELEM_GOT: INLINE_VT - 0x10}
FREE, SFREE = C.FREE + BASE, C.STRING_FREE + BASE


def ins(text: str, addr: int = 0x1000) -> list[Ins]:
    out = []
    for k, line in enumerate(x.strip() for x in text.strip().splitlines()):
        m, _, o = line.partition(" ")
        out.append(Ins(addr + BASE + 4 * k, m, o.strip()))
    return out


# _DDL_DataStoreReqGetInfoV1's D2 (0x7101592120): a String at 0x10, a vector of
# 0x60-byte objects at 0x38 and one of scalars at 0x58.
D2 = f"""
    str x21, [sp, #-0x30]!
    stp x20, x19, [sp, #0x10]
    stp x29, x30, [sp, #0x20]
    add x29, sp, #0x20
    adrp x8, #{0x24B2000 + BASE:#x}
    ldr x8, [x8, #0x6f0]
    add x8, x8, #0x10
    mov x19, x0
    str x8, [x0]
    ldr x0, [x0, #0x58]
    cbz x0, #0x7100001034
    str x0, [x19, #0x60]
    bl #{FREE:#x}
    ldr x21, [x19, #0x38]
    cbz x21, #0x7100001074
    ldr x20, [x19, #0x40]
    cmp x20, x21
    b.eq #0x7100001068
    ldr x8, [x20, #-0x60]!
    ldr x8, [x8]
    mov x0, x20
    blr x8
    cmp x21, x20
    b.ne #0x7100001048
    ldr x0, [x19, #0x38]
    b #0x710000106c
    mov x0, x21
    str x21, [x19, #0x40]
    bl #{FREE:#x}
    adrp x8, #{0x24B2000 + BASE:#x}
    ldr x8, [x8, #0x6b8]
    add x8, x8, #0x10
    str x8, [x19, #0x10]!
    mov x0, x19
    ldp x29, x30, [sp, #0x20]
    ldp x20, x19, [sp, #0x10]
    ldr x21, [sp], #0x30
    b #{SFREE:#x}
"""


def test_events_and_members():
    ev = C.events(ins(D2), GOT)
    assert ev[0] == ("vptr", 0, OWN_VT)
    own, mem = C.members(ev, lambda vt: None)
    assert own == OWN_VT
    assert [(m.offset, m.kind, m.elem) for m in mem] == [(0x10, "string", 0), (0x38, "vector", 0x60),
                                                          (0x58, "vector", 0)]


# An inline member (its vtable, then its vector) and an out-of-line one.
INLINE_D2 = f"""
    adrp x8, #{0x24B2000 + BASE:#x}
    ldr x8, [x8, #0x10]
    add x8, x8, #0x10
    str x8, [x0]
    ldr x8, [x0, #0x10]
    cbz x8, #0x7100001024
    str x8, [x0, #0x18]
    mov x0, x8
    b #{FREE:#x}
    ret
"""

OUTER_D2 = f"""
    stp x20, x19, [sp, #-0x20]!
    adrp x8, #{0x24B2000 + BASE:#x}
    ldr x8, [x8, #0x6f0]
    add x8, x8, #0x10
    mov x19, x0
    str x8, [x0]
    adrp x8, #{0x24B2000 + BASE:#x}
    ldr x8, [x8, #0x10]
    add x8, x8, #0x10
    ldr x0, [x19, #0x58]
    str x8, [x19, #0x48]
    cbz x0, #0x7100001034
    str x0, [x19, #0x60]
    bl #{FREE:#x}
    add x0, x19, #0x10
    ldp x20, x19, [sp], #0x20
    b #{0x7101500000:#x}
"""


def test_inline_and_called_members():
    inner = C.events(ins(INLINE_D2, 0x2000), GOT)
    own, mem = C.members(C.events(ins(OUTER_D2), GOT), lambda vt: (0x2000, inner) if vt == INLINE_VT else None)
    assert own == OWN_VT
    assert [(m.offset, m.kind) for m in mem] == [(0x10, "call"), (0x48, "inline")]
    assert mem[0].target == 0x1500000
    assert [(m.offset, m.kind) for m in mem[1].members] == [(0x10, "vector")]


def test_refuses_other_code():
    with pytest.raises(Unrecognized):
        C.members(C.events(ins("mov x8, x0\nret"), GOT), lambda vt: None)
    # a call with something else in x0
    text = f"""
        adrp x8, #{0x24B2000 + BASE:#x}
        ldr x8, [x8, #0x6f0]
        add x8, x8, #0x10
        str x8, [x0]
        mov x0, xzr
        b #{0x7101500000:#x}
    """
    with pytest.raises(Unrecognized):
        C.members(C.events(ins(text), GOT), lambda vt: None)


def test_build_and_render():
    vts = {
        OWN_VT: C.Vt(OWN_VT, "N2nn3nex26_DDL_DataStoreReqGetInfoV1E", [0x1000, 0x1100], OWN_VT - 0x10),
        DERIVED_VT: C.Vt(DERIVED_VT, "N2nn3nex21DataStoreReqGetInfoV1E", [0x1000, 0x1200], DERIVED_VT - 0x10),
    }
    code = {0x1000: ins(D2)}
    model = C.build(vts, code.__getitem__, GOT, {}, lo=0, hi=0x10000)
    assert [k.name for k in model.classes] == ["_DDL_DataStoreReqGetInfoV1"]
    k = model.classes[0]
    assert k.d0 == 0x1100 and k.derived == [("DataStoreReqGetInfoV1", 0x1200)]
    src = C.render(model)
    assert "class _DDL_DataStoreReqGetInfoV1 : public nn::nex::RootObject {" in src
    assert "    nn::nex::String m_10;" in src
    assert "    nn::nex::qVector<Unk_Element<0x60>> m_38;" in src
    assert "    nn::nex::qVector<u8> m_58;" in src
    assert "class DataStoreReqGetInfoV1 : public _DDL_DataStoreReqGetInfoV1 {" in src
    assert "_DDL_DataStoreReqGetInfoV1::~_DDL_DataStoreReqGetInfoV1() {}" in src
    assert C.names(model) == {
        0x1000: "_ZN2nn3nex26_DDL_DataStoreReqGetInfoV1D2Ev",
        0x1100: "_ZN2nn3nex26_DDL_DataStoreReqGetInfoV1D0Ev",
        0x1200: "_ZN2nn3nex21DataStoreReqGetInfoV1D0Ev",
    }
    # a class already written elsewhere is left out
    assert C.build(vts, code.__getitem__, GOT, {}, lo=0, hi=0x10000, done={0x1000}).classes == []


def test_simple_name_and_mangle():
    assert C.simple_name("N2nn3nex6StringE") == "String"
    assert C.simple_name("N2nn3nex5qListINS0_8URLProbeEEE") is None
    assert C.mangle("Key", True, "D2") == "_ZN2nn3nex3KeyD2Ev"
    assert C.mangle("Unk_240d1b8", False, "D0") == "_ZN11Unk_240d1b8D0Ev"


def test_trivial_classes():
    vt = 0x2451B88 + 0x10
    vts = {vt: C.Vt(vt, "N2nn3nex7TimeoutE", [0x1000, 0x1010], vt - 0x10, C.ROOT_OBJECT)}
    code = {0x1000: ins("ret"), 0x1010: ins(f"b #{C.DELETE + BASE:#x}", 0x1010)}
    model = C.build(vts, code.__getitem__, GOT, {}, lo=0, hi=0x10000)
    assert model.classes == [] and model.trivial == [("Timeout", 0x1000, 0x1010)]
    assert "Timeout::~Timeout() {}" in C.render(model)
    assert C.names(model) == {0x1000: "_ZN2nn3nex7TimeoutD2Ev", 0x1010: "_ZN2nn3nex7TimeoutD0Ev"}
    # another base, or a destructor that does something, isn't one
    vts[vt].base = "N2nn3nex16RefCountedObjectE"
    assert C.build(vts, code.__getitem__, GOT, {}, lo=0, hi=0x10000).trivial == []
