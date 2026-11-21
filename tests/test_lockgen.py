"""tools/lockgen.py: the locks found on hand-encoded instructions, their types' names and
what is written for them (no game files)."""
from __future__ import annotations

import struct
from types import SimpleNamespace

import familygen as F
import lockgen as L

RET = 0xD65F03C0
SEED = 0xE840
OBJECT_STATIC = 0x24BA7F8


def adrp(rd: int, pc: int, target: int) -> int:
    imm = ((target & ~0xFFF) - (pc & ~0xFFF)) >> 12
    return 0x90000000 | ((imm & 3) << 29) | (((imm >> 2) & 0x7FFFF) << 5) | rd


def ldr(rt: int, rn: int, off: int) -> int:
    return 0xF9400000 | ((off // 8) << 10) | (rn << 5) | rt


def body(at: int, got: int, extra: int = RET) -> list[int]:
    """Three GOT loads (the guard, what the getter holds, the type's static), as a lock makes them."""
    return [adrp(10, at, got), adrp(19, at + 4, got), adrp(11, at + 8, got),
            ldr(10, 10, got & 0xFFF), ldr(19, 19, (got + 8) & 0xFFF), ldr(11, 11, (got + 16) & 0xFFF), extra]


def module(funcs: dict[int, tuple[int, int]], slots: dict, names: dict, rows: dict | None = None) -> F.Module:
    """funcs: address -> (its GOT slots' address, its last word)."""
    img = bytearray(0x20000)
    out_rows = {}
    for at, (got, last) in funcs.items():
        words = body(at, got, last)
        struct.pack_into(f"<{len(words)}I", img, at, *words)
        out_rows[at] = SimpleNamespace(sword_size=4 * len(words), status="U", name="", sword_str=f"0x{at:016x}",
                                       shield_str=f"0x{at:016x}")
    out_rows.update(rows or {})
    return F.Module(bytes(img), out_rows, slots, data_names=names)


def test_names():
    names = {0x24BA7E8: "_ZZN11Unk_239a36011Unk_GetTypeEvE4type", 0x1000: "_ZZN3Foo11Unk_GetTypeEvE4type",
             0x2000: "_ZZN12Unk_239a36011Unk_GetTypeEvE4type", 0x3000: "_ZN11Unk_239a36011Unk_GetTypeEv"}
    assert L.class_of(0x24BA7E8, names) == "Unk_239a360"
    assert L.class_of(0x1000, names) == "Foo"
    assert L.class_of(0x2000, names) == "Unk_2000"       # the length doesn't fit the name: not a getter's static
    assert L.class_of(0x3000, names) == "Unk_3000"       # a function's name
    assert L.class_of(0x27E0A38, names) == "Unk_27e0a38"   # not named: after its address
    assert L.lock_name("Unk_239a360") == "_Z8Unk_LockI11Unk_239a360E15Unk_239a418_RefIT_EP18Unk_239a418_Handle"


def test_parse_and_plan():
    got_a, got_b, got_c, got_d = 0x10000, 0x10020, 0x10040, 0x10060
    slots = {
        got_a: 0x24BA7F0, got_a + 8: OBJECT_STATIC, got_a + 16: 0x24BA7E8,
        got_b: 0x27E0A40, got_b + 8: OBJECT_STATIC, got_b + 16: 0x27E0A38,
        got_c: 0x5008, got_c + 8: 0x6000, got_c + 16: 0x5000,           # held by another type's getter
        got_d: 0x24BA7F0, got_d + 8: OBJECT_STATIC, got_d + 16: 0x24BA7E8,   # the seed's type again
    }
    names = {OBJECT_STATIC: L.OBJECT_TYPE, 0x24BA7E8: "_ZZN11Unk_239a36011Unk_GetTypeEvE4type"}
    other, third, fourth, shaped = 0x1000, 0x2000, 0x3000, 0x4000
    m = module({SEED: (got_a, RET), other: (got_b, RET), third: (got_c, RET), fourth: (got_d, RET),
                shaped: (got_b, 0xD503201F)}, slots, names)
    assert L.parse(m, SEED) == L.Lock(SEED, "Unk_239a360", "object")
    assert L.parse(m, other) == L.Lock(other, "Unk_27e0a38", "object")
    assert L.parse(m, third) == "its type isn't on the object's"
    assert L.parse(m, shaped) is None                    # another shape: not a lock
    locks, candidates, skipped = L.plan(m, everything=True)
    # in address order: the first lock of a type is the one written
    assert [k.addr for k in locks] == [other, fourth]
    assert candidates == [other, third, fourth, SEED]
    assert skipped == [(third, "its type isn't on the object's"), (SEED, "a second lock of its type")]
    # kept: matched rows with the name written for them, and what --only adds
    assert L.plan(m)[0] == []
    m.rows[other].status, m.rows[other].name = "O", L.lock_name("Unk_27e0a38")
    assert [k.addr for k in L.plan(m)[0]] == [other]
    m.rows[other].name = "_Z5otherv"
    assert L.plan(m)[0] == []
    assert [k.addr for k in L.plan(m, only={other})[0]] == [other]


def test_source():
    text = L.source(L.Lock(SEED, "Unk_239a360", "object"))
    assert text.startswith("// Scope: common\n")
    assert '#include "gflib3/Unk_Lock.h"' in text
    assert "class Unk_239a360 : public Unk_239a418 {" in text
    assert "        static Unk_239a418_Type type(Unk_239a418_GetType());" in text
    assert text.endswith("// 0x710000e840\n"
                         "template Unk_239a418_Ref<Unk_239a360> Unk_Lock<Unk_239a360>(Unk_239a418_Handle*);\n")
