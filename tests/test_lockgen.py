"""tools/lockgen.py: the locks found on hand-encoded instructions, their types' chains and
what is written for them (no game files)."""
from __future__ import annotations

import struct
from types import SimpleNamespace

import familygen as F
import lockgen as L

RET = 0xD65F03C0
NOP = 0xD503201F
ACQUIRE, RELEASE = 0x17E8F60, 0x17E8F70
GUARDS = (ACQUIRE, RELEASE)


def adrp(rd: int, pc: int, target: int) -> int:
    imm = ((target & ~0xFFF) - (pc & ~0xFFF)) >> 12
    return 0x90000000 | ((imm & 3) << 29) | (((imm >> 2) & 0x7FFFF) << 5) | rd


def ldr(rt: int, rn: int, off: int) -> int:
    return 0xF9400000 | ((off // 8) << 10) | (rn << 5) | rt


def bl(pc: int, target: int) -> int:
    return 0x94000000 | (((target - pc) >> 2) & 0x3FFFFFF)


def lock_words(at: int, got: int, n_got: int, calls: tuple[int, ...] = (), offset: int = 0x50,
               exclusive: bool = True) -> list[int]:
    """A function shaped like a lock: the count read first, GOT loads, calls, the exchange and the cast."""
    words = [0xB940540D, 0x3400000D | (4 << 5)]                 # ldr w13, [x0, #0x54] ; cbz w13
    for k in range(n_got):
        pc = at + 4 * len(words)
        words += [adrp(10, pc, got + 8 * k), ldr(10, 10, (got + 8 * k) & 0xFFF)]
    for c in calls:
        words.append(bl(at + 4 * len(words), c))
    if exclusive:
        words += [0x885F7D89, 0x880E7D8D]                       # ldxr w9, [x12] ; stxr w14, w13, [x12]
    words += [ldr(9, 0, 0x60), 0xD1000000 | (offset << 10) | (9 << 5) | 10]   # ldr x9, [x0, #0x60] ; sub x10, x9, #N
    words += [NOP] * (80 - len(words)) + [RET]
    return words


def module(funcs: dict[int, list[int]], slots: dict, names: dict, rows: dict | None = None) -> F.Module:
    img = bytearray(0x1900000)
    out = {}
    for at, words in funcs.items():
        struct.pack_into(f"<{len(words)}I", img, at, *words)
        out[at] = SimpleNamespace(sword_size=4 * len(words), status="U", name="", sword_str=f"0x{at:016x}",
                                  shield_str=f"0x{at:016x}")
    out.update(rows or {})
    return F.Module(bytes(img), out, slots, data_names=names)


def guard(cls: str) -> str:
    return f"_ZGVZN{len(cls)}{cls}11Unk_GetTypeEvE4type"


def static(cls: str) -> str:
    return f"_ZZN{len(cls)}{cls}11Unk_GetTypeEvE4type"


def test_names():
    assert L.guard_class(guard("Unk_239a360"), 0x24BA7F0) == "Unk_239a360"
    assert L.guard_class(guard("Foo"), 0x1008) == "Foo"
    assert L.guard_class("_ZGVZN12Unk_239a36011Unk_GetTypeEvE4type", 0x1008) is None   # the length doesn't fit
    assert L.guard_class(None, 0x27715A8) == "Unk_27715a0"       # unnamed: after its static, 8 bytes before
    assert L.lock_name("Unk_239a360") == "_Z8Unk_LockI11Unk_239a360E15Unk_239a418_RefIT_EP18Unk_239a418_Handle"


def test_is_lock():
    a = 0x1000
    assert L.is_lock(module({a: lock_words(a, 0x10000, 3)}, {}, {}), a)
    assert not L.is_lock(module({a: lock_words(a, 0x10000, 3, exclusive=False)}, {}, {}), a)
    assert not L.is_lock(module({a: [NOP, NOP] + lock_words(a, 0x10000, 3)[2:]}, {}, {}), a)   # no count read
    assert not L.is_lock(module({a: lock_words(a, 0x10000, 3)[:40] + [RET]}, {}, {}), a)       # too small


def test_parse_chains():
    obj, called, plain, other, unnamed, off8 = 0x1000, 0x2000, 0x3000, 0x4000, 0x5000, 0x6000
    getter, stray = 0x8000, 0x9000
    slots, names = {}, {}

    def got(at: int, entries: list[tuple[int, str | None]]) -> int:
        for k, (target, name) in enumerate(entries):
            slots[at + 8 * k] = target
            if name:
                names[target] = name
        return at

    # T on the object itself: its guard, the object's static, its static, the object's and the root's guards
    g1 = got(0x10000, [(0x24BA7F0, guard("Unk_239a360")), (0x24BA7F8, "_ZZ19Unk_239a418_GetTypevE4type"),
                       (0x24BA7E8, static("Unk_239a360")), (0x24BA800, L.OBJECT_GUARD), (0x24BA558, L.ROOT_GUARD)])
    # T, two inlined parents, then a getter called
    g2 = got(0x10100, [(0x1008, guard("Unk_23d1de8")), (0x1100, static("Unk_27d8538")), (0x1000, static("Unk_23d1de8")),
                       (0x1108, guard("Unk_27d8538")), (0x1208, guard("Unk_23cf760")), (0x1200, static("Unk_23cf760"))])
    # an unnamed T (its guard 8 bytes after its static), 8 bytes into its object
    g3 = got(0x10200, [(0x27715A8, None), (0x24BA7F8, None), (0x27715A0, None), (0x24BA800, L.OBJECT_GUARD)])
    # an unnamed parent
    g4 = got(0x10300, [(0x1308, guard("Unk_2300000")), (0x1400, None), (0x1300, static("Unk_2300000")),
                       (0x1410, None)])
    funcs = {
        obj: lock_words(obj, g1, 5, (ACQUIRE, RELEASE)),
        called: lock_words(called, g2, 6, (ACQUIRE, getter, RELEASE)),
        plain: lock_words(plain, g2, 6, (ACQUIRE, RELEASE)),             # no getter called
        other: lock_words(other, g2, 6, (ACQUIRE, stray, RELEASE)),      # what it calls isn't named as a getter
        off8: lock_words(off8, g3, 4, (ACQUIRE, RELEASE), offset=8),
        unnamed: lock_words(unnamed, g4, 4, (ACQUIRE, getter, RELEASE)),
    }
    rows = {getter: SimpleNamespace(sword_size=8, status="O", name="_ZN11Unk_27d852811Unk_GetTypeEv"),
            stray: SimpleNamespace(sword_size=8, status="O", name="_Z5otherv")}
    m = module(funcs, slots, names, rows)
    assert L.parse(m, obj, GUARDS) == L.Lock(obj, ["Unk_239a360"], None, 0x50)
    assert L.parse(m, called, GUARDS) == L.Lock(called, ["Unk_23d1de8", "Unk_27d8538", "Unk_23cf760"], "Unk_27d8528", 0x50)
    assert L.parse(m, plain, GUARDS) == "its last getter isn't called once"
    assert L.parse(m, other, GUARDS) == "the getter it calls isn't named as one"
    assert L.parse(m, off8, GUARDS) == L.Lock(off8, ["Unk_27715a0"], None, 8)
    assert L.parse(m, unnamed, GUARDS) == "a parent type that isn't named"
    assert L.parse(m, getter, GUARDS) is None
    assert L.interface_offset(m, off8, m.rows[off8].sword_size) == 8

    # the plan: every candidate, the first lock of a type, what's kept
    locks, candidates, skipped = L.plan(m, everything=True, guards=GUARDS)
    assert [k.addr for k in locks] == [obj, called, off8]
    assert candidates == [obj, called, plain, other, unnamed, off8]
    assert (plain, "its last getter isn't called once") in skipped
    assert L.plan(m, guards=GUARDS)[0] == []
    m.rows[called].status, m.rows[called].name = "O", L.lock_name("Unk_23d1de8")
    assert [k.addr for k in L.plan(m, guards=GUARDS)[0]] == [called]
    assert [k.addr for k in L.plan(m, only={obj}, guards=GUARDS)[0]] == [obj, called]


def test_source():
    text = L.source(L.Lock(0xE840, ["Unk_239a360"]))
    assert text.startswith("// Scope: common\n")
    assert '#include "gflib3/Unk_Lock.h"' in text
    assert "class Unk_239a360 : public Unk_239a418 {" in text
    assert "        static Unk_239a418_Type type(Unk_239a418_GetType());" in text
    assert text.endswith("// 0x710000e840\n"
                         "template Unk_239a418_Ref<Unk_239a360> Unk_Lock<Unk_239a360>(Unk_239a418_Handle*);\n")
    # a chain: the called getter declared, each inlined parent's defined over the one under it
    text = L.source(L.Lock(0xB3AEE0, ["Unk_23d1de8", "Unk_27d8538", "Unk_23cf760"], "Unk_27d8528"))
    assert "struct Unk_27d8528 {\n    static const Unk_239a418_Type* Unk_GetType();\n};" in text
    assert text.index("struct Unk_23cf760 {") < text.index("struct Unk_27d8538 {") < text.index("class Unk_23d1de8 :")
    assert "static Unk_239a418_Type type(Unk_27d8528::Unk_GetType());" in text
    assert "static Unk_239a418_Type type(Unk_23cf760::Unk_GetType());" in text
    assert "static Unk_239a418_Type type(Unk_27d8538::Unk_GetType());" in text
    # a type that isn't on the object: the interface at its offset
    text = L.source(L.Lock(0x8D2A20, ["Unk_27d1a28"], None, 0x58))
    assert "struct Unk_27d1a28_Base {\n    virtual void vf0();\n    u8 _8[0x50];\n};" in text
    assert "class Unk_27d1a28 : public Unk_27d1a28_Base, public Unk_239a498, public Unk_239a458 {" in text
    assert "u8 _8[" not in L.source(L.Lock(0x5B4A50, ["Unk_27715a0"], None, 8))
