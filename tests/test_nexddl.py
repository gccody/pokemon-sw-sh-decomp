"""tools/nexddl.py: the analysis of NEX's DDL stream functions and protocol
calls, and the C++ it writes. The instructions are given as text (the
disassembler is replaced), so no game files are needed."""
from __future__ import annotations

import pytest

import nexddl as N
from common import BASE

W = N.WRITE + BASE
SEEK = N.SEEK + BASE


def fake(monkeypatch, text: str, addr: int = 0x1000):
    """Make nexddl.disasm return these instructions (one per line, `mnemonic
    operands`), at consecutive addresses from addr."""
    ins = []
    for k, line in enumerate(x.strip() for x in text.strip().splitlines()):
        m, _, o = line.partition(" ")
        ins.append(N.Ins(addr + BASE + 4 * k, m, o.strip()))
    monkeypatch.setattr(N, "disasm", lambda code, a: ins)
    return b"\0" * (4 * len(ins))


HEADER = f"""
    sub sp, sp, #0x40
    ldrb w22, [x0, #0x69]
    mov x20, x1
    mov x19, x0
    cbz w22, #0x7100001030
    mov x21, xzr
    b #0x7100001074
    ldrb w8, [x20, #8]
    strb w8, [sp, #0xc]
    cmp w8, #0
    add x8, sp, #8
    add x9, sp, #0xc
    csel x1, x9, x8, eq
    mov w2, #1
    mov x0, x19
    strb wzr, [sp, #8]
    bl #{W:#x}
    ldr x8, [x19, #0x10]
    ldr x21, [x8, #0x18]
    add x1, sp, #4
    mov w2, #4
    mov x0, x19
    str wzr, [sp, #4]
    bl #{W:#x}
"""

TRAILER = f"""
    cbnz w22, #0x7100001100
    ldr x8, [x19, #0x10]
    ldr x20, [x8, #0x18]
    mov x0, x19
    mov x1, x21
    bl #{SEEK:#x}
    ret
"""


def test_stream_out_scalars_and_calls(monkeypatch):
    code = fake(monkeypatch, HEADER + f"""
        add x1, x20, #0xc
        mov w2, #4
        mov x0, x19
        bl #{W:#x}
        add x1, x20, #0x10
        mov x0, x19
        bl #{N.STRING_OUT + BASE:#x}
    """ + TRAILER)
    s = N.stream_out(code, 0x1000)
    assert [(f.kind, f.offset, f.size, f.callee) for f in s.fields] == [
        ("scalar", 0xc, 4, None), ("call", 0x10, 0, N.STRING_OUT)]
    assert s.version == 0


def test_stream_out_container(monkeypatch):
    # count = (end - begin) / 40, then each String
    code = fake(monkeypatch, HEADER + f"""
        ldp x8, x9, [x20, #0x28]
        sub x8, x9, x8
        mov w9, #0xcccd
        movk w9, #0xcccc, lsl #16
        lsr x8, x8, #3
        mul w8, w8, w9
        add x1, sp, #0x1c
        mov w2, #4
        mov x0, x19
        str w8, [sp, #0x1c]
        bl #{W:#x}
        ldp x22, x21, [x20, #0x28]
        cmp x22, x21
        b.eq #0x7100001200
        mov x0, x19
        mov x1, x22
        bl #{N.STRING_OUT + BASE:#x}
        add x22, x22, #0x28
        cmp x21, x22
        b.ne #0x7100001190
    """ + TRAILER)
    s = N.stream_out(code, 0x1000)
    assert [(f.kind, f.offset, f.size, f.callee) for f in s.fields] == [("vector", 0x28, 0x28, N.STRING_OUT)]


def test_stream_out_refuses_other_functions(monkeypatch):
    code = fake(monkeypatch, "mov x0, x1\nret")
    with pytest.raises(N.Unrecognized):
        N.stream_out(code, 0x1000)


def test_stream_in_fields_by_offset(monkeypatch):
    # the failure paths zero the fields; a String is read by a call
    code = fake(monkeypatch, f"""
        strb wzr, [x1, #8]
        ldrb w9, [x0, #0x69]
        mov x19, x1
        str wzr, [x19, #0x18]
        str xzr, [x19, #0x10]
        add x1, x19, #0x20
        mov x0, x20
        bl #{N.STRING_IN + BASE:#x}
        ret
    """)
    s = N.stream_in(code, 0x1000)
    assert s.read
    assert [(f.kind, f.offset, f.size) for f in s.fields] == [("scalar", 0x10, 8), ("scalar", 0x18, 4),
                                                               ("call", 0x20, 0)]


def test_render_write_and_read():
    w = N.StreamOut(0x158EC60, 228, fields=[N.Field("scalar", 0xC, 4), N.Field("scalar", 0x10, 8)])
    text = N.render_write(w)
    assert "void Unk_158ec60_write(nn::nex::ByteStream* s, const Unk_158ec60& v)" in text
    assert "s->Write(std::min(v.GetVersion(), (u8)0));" in text
    assert "s->Write(v.field_c);\n    s->Write(v.field_10);" in text
    r = N.StreamOut(0x158B6F0, 408, read=True, fields=[N.Field("scalar", 0x10, 8), N.Field("scalar", 0x18, 8)])
    text = N.render_read(r)
    assert "if (!ReadField(s, v.field_10)) return;" in text
    assert "bool err = !ReadField(s, v.field_18);" in text
    assert "if (noHeader | err) return;" in text


def test_layouts_struct_sizes():
    inner = N.StreamOut(0x2000, 0, fields=[N.Field("scalar", 0x10, 8)])
    outer = N.StreamOut(0x3000, 0, fields=[N.Field("vector", 0x10, 0x20, callee=0x2000),
                                           N.Field("call", 0x28, callee=N.STRING_OUT)])
    lay = N.Layouts({0x2000: inner, 0x3000: outer})
    assert lay.size_of(0x2000) == 0x20  # a container's element size wins
    assert lay.size_of(0x3000) == 0x50
    text = N.render_struct(0x3000, lay)
    assert "nn::nex::qVector<Unk_2000> field_10;" in text
    assert "nn::nex::String field_28;" in text
    assert "PKMN_SIZE_ASSERT(Unk_3000, 0x50);" in text


def test_mangled_names():
    assert N.mangled_name(0x158EC60, False) == "_Z17Unk_158ec60_writePN2nn3nex10ByteStreamERK11Unk_158ec60"
    assert N.mangled_name(0x158B6F0, True) == "_Z16Unk_158b6f0_readPN2nn3nex10ByteStreamER11Unk_158b6f0"
    assert N.mangled_name(N.STRING_OUT, False) == "_Z17Unk_162cec0_writePN2nn3nex10ByteStreamERKNS0_6StringE"


def test_magic_div():
    ins = [N.Ins(0, "sub", "x8, x9, x8"), N.Ins(4, "mov", "w9, #0xcccd"), N.Ins(8, "movk", "w9, #0xcccc, lsl #16"),
           N.Ins(12, "lsr", "x8, x8, #3"), N.Ins(16, "mul", "w8, w8, w9"), N.Ins(20, "str", "w8, [sp]")]
    assert N._magic_div(ins, 5, "")[0] == 40
    ins = [N.Ins(0, "sub", "x8, x9, x8"), N.Ins(4, "lsr", "x8, x8, #3"), N.Ins(8, "str", "w8, [sp]")]
    assert N._magic_div(ins, 2, "")[0] == 8


def test_protocol_call(monkeypatch):
    code = fake(monkeypatch, f"""
        mov x20, x0
        mov x21, x2
        mov x19, x1
        bl #{N.MESSAGE_CTOR + BASE:#x}
        blr x8
        bl #{N.SET_PROTOCOL + BASE:#x}
        bl #{N.REGISTER + BASE:#x}
        mov w1, #0x1a
        add x0, sp, #0x20
        bl #{N.SET_METHOD + BASE:#x}
        add x0, sp, #0x20
        mov x1, x21
        bl #{0x158A460 + BASE:#x}
        ldrb w8, [sp, #0x28]
        bl #{N.QRESULT + BASE:#x}
        bl #{N.SET_OUTCOME + BASE:#x}
        adrp x8, #0x71024b2000
        adrp x9, #0x71024b2000
        ldr x8, [x8, #0x4f8]
        ldr x9, [x9, #0x528]
        str x9, [x8, #0xc8]
        ldrb w8, [x20, #0x70]
        bl #{N.SEND + BASE:#x}
        bl #{N.MESSAGE_DTOR + BASE:#x}
        ret
    """)
    c = N.protocol_call(code, 0x1000)
    assert c.method == 0x1A
    assert [(a.reg, a.kind, a.callee) for a in c.args] == [("x2", "write", 0x158A460)]
    assert c.slot == 0xC8 // 8 and c.table == 0x24B24F8 and c.handler == 0x24B2528  # GOT slots until resolved
    N.resolve_got({0x24B24F8: 0x27F20D8, 0x24B2528: 0x158E040}, c)
    text = N.render_call(c, {0x158E040: "Unk_158e040"})
    assert "bool Unk_1000(nn::nex::ClientProtocol* self, nn::nex::ProtocolCallContext* ctx, " \
           "const Unk_158a460& arg2)" in text
    assert "msg.Unk_1630a90(0x1a);" in text
    assert "Unk_158a460_write(&msg, arg2);" in text
    assert "Unk_15c9360(ctx, Unk_15bbc10(0x8001000a));" in text
    assert "Unk_27f20d8.m_handlers[25] = Unk_158e040;" in text


def test_handler_decl():
    assert N.handler_decl(0x164E850, None) == ("void Unk_164e850();", "Unk_164e850")
    assert N.handler_decl(0x158CFA0, "_Z18Unk_158cfa0_updatev") == ("void Unk_158cfa0_update();", "Unk_158cfa0_update")
    assert N.handler_decl(0x158C0F0, "_Z15Unk_158c0f0_setP11Unk_158c0f0") is None
    assert N.handler_decl(0x164E850, "_Z11Unk_164e850PN2nn3nex10ByteStreamEPNS0_19ProtocolCallContextE") == (
        "void Unk_164e850(nn::nex::ByteStream* s, nn::nex::ProtocolCallContext* ctx);",
        "reinterpret_cast<void (*)()>(Unk_164e850)")
    # other parameters stay unsupported
    assert N.handler_decl(0x164E850, "_Z11Unk_164e850PN2nn3nex10ByteStreamE") is None
