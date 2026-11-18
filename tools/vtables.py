#!/usr/bin/env python3
"""Find the vtables in `main` and group them into classes.

    python tools/vtables.py summary                     # counts, per area, and what the slots hold
    python tools/vtables.py summary --area game/pokecamp
    python tools/vtables.py show 0x71024a6390           # one vtable group: slots, patterns, referrers
    python tools/vtables.py of 0x7100dee870             # the vtables a function is in, and its slot
    python tools/vtables.py csv vtables.csv             # one row per vtable
    python tools/vtables.py write --names n.csv         # placeholder classes for simple virtual functions
    python tools/vtables.py ctors --names n.csv         # constructors that only call their base's

Game Freak's code has no RTTI (docs/game_code.md), so a class's name can't
come from its typeinfo, but its vtables are still there. With the Itanium C++
ABI a vtable is, in `.data.rel.ro`:

    offset-to-top   (0 for a primary vtable, -N for the one of a base at offset N)
    typeinfo        (0 with -fno-rtti, or a typeinfo object)
    slot 0, 1, ...  (function pointers: R_AARCH64_RELATIVE relocations to
                     function starts, or __cxa_pure_virtual)

and the *address point*, what an object's vptr holds, is slot 0. A class
with secondary bases has a vtable group: its primary vtable, then one
vtable per secondary base, each with its offset-to-top. So a vtable is a
run of function-pointer slots right after an offset-to-top and a typeinfo
word, and a run that follows another without a gap and has a negative
offset-to-top belongs to the same group. A run of function pointers without
that header (a plain function table) isn't a vtable.

Constructors and destructors store the address point into the object
(`adrp`+`add`, or a GOT load of it). `referrers` are the functions that
reference an address point either way: a class's constructors, destructors,
and anything else that sets a vptr.

Each slot is classified by the function's code (tools/funcs.py patterns):
`ret` (an empty override), `thunk` (`sub x0, x0, #N ; b T`: this-adjusting,
for an override reached through a secondary base), `trap` (the deleting
destructor of an abstract class), `pure` (__cxa_pure_virtual), and so on.
"""
from __future__ import annotations

import argparse
import bisect
import csv
import re
import struct
import sys
from collections import Counter, defaultdict
from dataclasses import dataclass, field
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BASE, ROOT, VERSIONS  # noqa: E402

PURE = ("__cxa_pure_virtual", "__cxa_deleted_virtual")
MAX_OFFSET_TO_TOP = 0x100000


@dataclass
class Vtable:
    addr: int                       # address point (slot 0), relative to BASE
    offset_to_top: int              # 0, or minus the base's offset in the object
    typeinfo: int | None            # typeinfo object, None with -fno-rtti
    slots: list[int | str]          # function addresses (relative) or a PURE name
    group: int = 0                  # address point of the group's primary vtable
    referrers: set[int] = field(default_factory=set)

    @property
    def start(self) -> int:
        return self.addr - 16


def find_vtables(img: bytes, slots: dict[int, int | str], function_starts: set[int],
                 lo: int, hi: int) -> tuple[list[Vtable], list[tuple[int, int]]]:
    """Vtables in [lo, hi) (the data segment), and the function-pointer runs
    that aren't vtables, as (start, number of slots)."""

    def is_fn(p: int) -> bool:
        t = slots.get(p)
        return (isinstance(t, int) and t in function_starts) or t in PURE

    def word(p: int) -> int:
        return struct.unpack_from("<q", img, p)[0]

    vtables: list[Vtable] = []
    tables: list[tuple[int, int]] = []
    p = lo
    while p < hi:
        if not is_fn(p):
            p += 8
            continue
        start = p
        while p < hi and is_fn(p):
            p += 8
        n = (p - start) // 8
        ott_p, ti_p = start - 16, start - 8
        ott_ok = ott_p >= lo and ott_p not in slots and -MAX_OFFSET_TO_TOP < word(ott_p) <= 0 \
            and word(ott_p) % 8 == 0
        ti = slots.get(ti_p)
        if ti_p in slots:
            ti_ok = isinstance(ti, int) and ti not in function_starts
        else:
            ti_ok = ti_p >= lo and word(ti_p) == 0
        if not (ott_ok and ti_ok):
            tables.append((start, n))
            continue
        vtables.append(Vtable(start, word(ott_p), ti if ti_p in slots else None,
                              [slots[start + 8 * i] for i in range(n)]))
    # Groups: a vtable with a negative offset-to-top that starts where the previous one ends.
    prev: Vtable | None = None
    for v in vtables:
        if prev is not None and v.offset_to_top < 0 and v.start == prev.addr + 8 * len(prev.slots):
            v.group = prev.group
        else:
            v.group = v.addr
        prev = v
    return vtables, tables


def find_referrers(img: bytes, funcs: list[tuple[int, int]], vtables: list[Vtable],
                   slots: dict[int, int | str]) -> None:
    """Fill each vtable's referrers: functions that address it (its start, the
    `_ZTV` symbol, or its address point), directly (adrp+add/ldr) or through a
    GOT slot holding it. Game code loads `_ZTV` from the GOT and adds 16."""
    from nx.refs import decode

    by_addr = {v.addr: v for v in vtables}
    by_addr.update({v.start: v for v in vtables})
    got = {s: by_addr[t] for s, t in slots.items() if isinstance(t, int) and t in by_addr}
    for start, size in funcs:
        for _, _, _, target in decode(img, start, size):
            if target is None:
                continue
            v = by_addr.get(target) or got.get(target)
            if v is not None:
                v.referrers.add(start)
    # A constructor loads the group's _ZTV once and adds each vtable's offset,
    # so a secondary vtable's referrers are its group's.
    primary = {v.addr: v for v in vtables if v.group == v.addr}
    for v in vtables:
        if v.group != v.addr:
            primary[v.group].referrers |= v.referrers
            v.referrers = primary[v.group].referrers


def owners(vtables: list[Vtable]) -> dict[int, tuple[int, int]]:
    """function -> (vtable, slot) of the smallest vtable that holds it.

    A class that doesn't override a base's virtual function inherits the
    base's slot, so the same function appears in the base's vtable and in
    every derived one. A base's vtable is shorter than a derived class's
    (whose vtable extends it), so the smallest vtable holding a function is
    the best guess at the class that defines it."""
    out: dict[int, tuple[int, int, int]] = {}
    for v in vtables:
        for i, f in enumerate(v.slots):
            if isinstance(f, int):
                key = (len(v.slots), v.addr, i)
                if f not in out or key < out[f]:
                    out[f] = key
    return {f: (k[1], k[2]) for f, k in out.items()}


def bases(vtables: list[Vtable]) -> dict[int, tuple[int, int]]:
    """vtable -> (base vtable, slots shared): the guess at its class's base.

    A derived class's vtable starts with its base's slots, and every slot it
    doesn't override holds the base's function. So the base is the other,
    no longer, vtable that holds the most of the same functions at the same
    indices. That includes the destructor: when both destructors are inline
    and empty, clang uses the base's D2 for the derived class's, so a derived
    class's slot 0 often is its base's D2 (docs/game_code.md, "Bases")."""
    at: dict[tuple[int, int], list[Vtable]] = defaultdict(list)
    for v in vtables:
        for i, f in enumerate(v.slots):
            if isinstance(f, int):
                at[(i, f)].append(v)
    length = {v.addr: len(v.slots) for v in vtables}
    out = {}
    for v in vtables:
        shared: Counter = Counter()
        for i, f in enumerate(v.slots):
            if isinstance(f, int):
                for b in at[(i, f)]:
                    if b is not v and len(b.slots) <= len(v.slots):
                        shared[b.addr] += 1
        if shared:
            # The most slots shared; then the longest such vtable (the nearest base).
            best = max(shared, key=lambda a: (shared[a], length[a], -a))
            out[v.addr] = (best, shared[best])
    return out


SLOT_KINDS = [
    ("pure", None),
    ("trap", "trap"),
    ("ret", "ret"),
    ("thunk", "sub x0, x0, #N ; b T"),
    ("forward", "b T"),
    ("constant", "mov w0, #N ; ret"),
    ("zero", "mov w0, wzr ; ret"),
    ("null", "mov x0, xzr ; ret"),
]


def slot_kind(pattern: str | None) -> str:
    if pattern is None:
        return "pure"
    for kind, pat in SLOT_KINDS[1:]:
        if pattern == pat:
            return kind
    if pattern.count(";") <= 2 and pattern.endswith("ret") and "T" not in pattern:
        return "small"
    return "other"


@dataclass
class Model:
    """Everything the subcommands need, computed once for one game."""
    game: str
    img: bytes
    funcs: list[tuple[int, int]]
    vtables: list[Vtable]
    tables: list[tuple[int, int]]
    sizes: dict[int, int]
    names: dict[int, str]
    statuses: dict[int, str]
    area_of: object
    delete: int | None = None       # operator delete(void*), what an empty D0 tail-calls
    got: dict[int, int] = field(default_factory=dict)  # GOT slot -> the address it holds, for globals

    def pattern(self, f: int | str) -> str | None:
        if not isinstance(f, int):
            return None
        from funcs import pattern_of
        return pattern_of(self.img[f:f + self.sizes.get(f, 4)], f + BASE)


def load(game: str) -> Model:
    from common import AreaMap, load_module, nso_path, read_areas_csv, read_functions_csv
    from nx.module import DynInfo
    from nx.nso import Nso

    mod = load_module(game)
    img = mod["image"]
    nso = Nso(nso_path(game).read_bytes())
    dyn = DynInfo(nso, img, mod["text_end"])
    starts = {s for s, _ in mod["functions"]}
    vtables, tables = find_vtables(img, dyn.slots, starts, nso.data.mem_off, nso.data.end)
    find_referrers(img, mod["functions"], vtables, dyn.slots)
    rows = [f for f in read_functions_csv() if f.in_version(game)]
    names = {f.addr(game): f.name for f in rows if f.name}
    delete = next((a for a, n in names.items() if n == "_ZdlPv"), None)
    return Model(game, img, mod["functions"], vtables, tables, dict(mod["functions"]), names,
                 {f.addr(game): f.status for f in rows}, AreaMap(read_areas_csv(), game).area_of, delete,
                 {slot: t for slot, t in dyn.slots.items() if isinstance(t, int)})


def vtable_area(m: Model, v: Vtable) -> str:
    """The area most of its functions (or its referrers) are in."""
    c = Counter(m.area_of(f) for f in [*v.slots, *v.referrers] if isinstance(f, int))
    c.pop(None, None)
    return c.most_common(1)[0][0] if c else "?"


# --------------------------------------------------------------------------- subcommands
def cmd_summary(m: Model, args) -> None:
    from common import in_area

    vts = [v for v in m.vtables if not args.area or in_area(vtable_area(m, v), args.area)]
    groups = {v.group for v in vts}
    own = owners(m.vtables)
    print(f"{m.game}: {len(vts)} vtables in {len(groups)} groups, {sum(len(v.slots) for v in vts)} slots "
          f"({len(m.tables)} other function-pointer runs, {sum(n for _, n in m.tables)} slots, aren't vtables)")
    print(f"  with typeinfo: {sum(v.typeinfo is not None for v in vts)}; secondary vtables: "
          f"{sum(v.offset_to_top < 0 for v in vts)}; with no referrer: {sum(not v.referrers for v in vts)}")
    per_area = Counter(vtable_area(m, v) for v in vts)
    print("  per area: " + ", ".join(f"{a} {n}" for a, n in per_area.most_common()))
    kinds: Counter = Counter()
    status: dict[str, Counter] = defaultdict(Counter)
    seen = set()
    for v in vts:
        for f in v.slots:
            if f in seen:
                continue
            seen.add(f)
            k = slot_kind(m.pattern(f))
            kinds[k] += 1
            if isinstance(f, int):
                status[k][m.statuses.get(f, "?")] += 1
    owned = sum(1 for f in seen if isinstance(f, int) and own.get(f, (None,))[0] in {v.addr for v in vts})
    print(f"  distinct slot functions: {len(seen)} ({owned} owned by these vtables)")
    for k, _ in SLOT_KINDS + [("small", None), ("other", None)]:
        if kinds[k]:
            st = " ".join(f"{s}={n}" for s, n in sorted(status[k].items()))
            print(f"    {k:9} {kinds[k]:7}  {st}")


def cmd_show(m: Model, args) -> None:
    a = int(args.addr, 16)
    a = a - BASE if a >= BASE else a
    hits = [v for v in m.vtables if v.group == a or v.addr == a or v.start <= a < v.addr + 8 * len(v.slots)]
    if not hits:
        raise SystemExit(f"no vtable at 0x{a + BASE:x}")
    group = [v for v in m.vtables if v.group == hits[0].group]
    own = owners(m.vtables)
    base = bases(m.vtables)
    for v in group:
        print(f"vtable 0x{v.addr + BASE:x} (starts 0x{v.start + BASE:x}, class {class_name(v)}), offset-to-top "
              f"{v.offset_to_top}, {len(v.slots)} slots, area {vtable_area(m, v)}")
        if v.addr in base:
            b, n = base[v.addr]
            print(f"  base guess: 0x{b + BASE:x} ({n} slots shared)")
        for i, f in enumerate(v.slots):
            if isinstance(f, str):
                print(f"  {i:3}  {f}")
                continue
            o = own.get(f)
            inherited = "" if o == (v.addr, i) else f"  (from 0x{o[0] + BASE:x} slot {o[1]})"
            print(f"  {i:3}  0x{f + BASE:x} {m.sizes.get(f, 0):5} {m.statuses.get(f, '?')} "
                  f"{(m.names.get(f) or '')[:50]:50} {(m.pattern(f) or '')[:50]}{inherited}")
        refs = sorted(v.referrers)
        print(f"  referrers ({len(refs)}): " + " ".join(f"0x{r + BASE:x}" for r in refs[:12])
              + (" ..." if len(refs) > 12 else ""))


def cmd_of(m: Model, args) -> None:
    a = int(args.addr, 16)
    a = a - BASE if a >= BASE else a
    found = [(v, i) for v in m.vtables for i, f in enumerate(v.slots) if f == a]
    if not found:
        print(f"0x{a + BASE:x} is in no vtable")
    for v, i in found:
        print(f"vtable 0x{v.addr + BASE:x} slot {i} (group 0x{v.group + BASE:x}, {len(v.slots)} slots)")
    o = owners(m.vtables).get(a)
    if o:
        print(f"owner: vtable 0x{o[0] + BASE:x} slot {o[1]}")


def cmd_csv(m: Model, args) -> None:
    with open(args.out, "w", newline="", encoding="utf-8") as fh:
        w = csv.writer(fh, lineterminator="\n")
        w.writerow(["Vtable", "Group", "OffsetToTop", "Slots", "Referrers", "Area", "Base", "Shared"])
        base = bases(m.vtables)
        for v in m.vtables:
            b, n = base.get(v.addr, (None, 0))
            w.writerow([f"0x{v.addr + BASE:x}", f"0x{v.group + BASE:x}", v.offset_to_top, len(v.slots),
                        len(v.referrers), vtable_area(m, v), f"0x{b + BASE:x}" if b is not None else "", n])
    print(f"wrote {len(m.vtables)} vtables to {args.out}", file=sys.stderr)


# --------------------------------------------------------------------------- placeholder classes
@dataclass
class Member:
    slot: int
    addr: int                       # the function (relative), for both games through functions.csv
    kind: str                       # "dtor" (slots 0+1), "d0" (a derived class's D0), "ret", "constant", ...
    value: int = 0
    lifted: Lifted | None = None    # kind "lifted"


RTYPE = {"ret": "void", "constant": "u32", "zero": "u32", "null": "void*", "forward": "void", "string": "const char*"}
# The names write gives: members (vfN, vf_type, Unk_GetType, destructors) and thunks.
WRITTEN = re.compile(r"_Z(?:Thn\d+_)?N\d+(Unk_[0-9a-f]+)(?:D0|D1|D2|\d+vf\d+|7vf_type|11Unk_GetType)E[a-z]+")


@dataclass(frozen=True)
class ExternalBase:
    """A class written by hand (in `header`) that write's classes derive from.

    A class derives from it when its slot 0 is the base's D2 and its D0 is
    `b <that D2>`: its destructor is implicit, so clang uses the base's D2,
    and the family's operator delete is empty. Its secondary vtables'
    destructor slots are then `sub x0, x0, #N ; b <D2>` thunks. When it
    overrides the type getter (`type_slot`, also in the secondary vtables)
    with a `b T`, T is its own inline type getter, whose type has the base's
    (`get_type`) as its parent, and the secondary slots are thunks of the
    override (the adjustment is dead, T takes no `this`)."""
    vtable: int                     # its primary vtable's address point (relative)
    name: str
    header: str
    slots: tuple                    # (slot, return type, name) of its virtual functions from slot 2
    type_slot: int
    get_type: str
    secondaries: tuple              # (offset in the object, its 2 destructor slots, its type slot) each
    inline_dtor: bool = False       # its D2 is inline: the D0s and thunks are copies of it, not `b`s
    shared_tu: bool = False         # it and its derived classes are one TU: no file of their own
    source: str | None = None       # its own definitions, included in its TU's file (a shared TU)
    size: int = 0                   # sizeof (its header asserts it): a derived class's fields follow

    def slot(self, i: int) -> tuple[str, str]:
        return next(((rt, n) for j, rt, n in self.slots if j == i), ("void", f"vf{i}"))


TYPE = "const Unk_239a418_Type*"
EXTERNAL_BASES = (
    ExternalBase(0x23f43d8, "Unk_23f43c8", "unsorted/Unk_23f43c8.h",
                 ((2, "Unk_239a418_Ref<Unk_239a418_Handle>", "vf2"), (3, "void", "vf3"), (4, "void", "vf4"),
                  (5, "void", "vf5"), (6, TYPE, "vf_type"), (7, "void", "vf7"), (8, "u32", "vf8"), (9, "void", "vf9"),
                  (10, "u32", "vf10")),
                 6, "Unk_23f43c8::Unk_GetType", ((0x48, (0, 1), 5), (0x50, (1, 2), 0)), size=0x78),
    ExternalBase(0x23f4328, "Unk_23f4318", "unsorted/Unk_23f43c8.h",
                 ((2, "Unk_239a418_Ref<Unk_239a418_Handle>", "vf2"), (3, "void", "vf3"), (4, "void", "vf4"),
                  (5, "void", "vf5"), (6, TYPE, "vf_type")),
                 6, "Unk_23f4318::Unk_GetType", ((0x48, (0, 1), 5), (0x50, (1, 2), 0)), size=0x60),
    ExternalBase(0x23c1a78, "Unk_23c1a68", "unsorted/Unk_23c1a68.h",
                 ((2, "Unk_239a418_Ref<Unk_239a418_Handle>", "vf2"), (3, "void", "vf3"), (4, "void", "vf4"),
                  (5, "void", "vf5"), (6, TYPE, "vf_type")),
                 6, "Unk_23c1a68::Unk_GetType", ((0x48, (0, 1), 5), (0x50, (1, 2), 0)), size=0x188),
    # On Unk_23c1a68. Its destructor is inline, but too big to be inlined: the D0s and thunks
    # tail-call its D2. Its slots 7-46 return void unless this says otherwise.
    ExternalBase(0x23dc950, "Unk_23dc940", "unsorted/Unk_23dc940.h",
                 ((2, "Unk_239a418_Ref<Unk_239a418_Handle>", "vf2"), (3, "void", "vf3"), (4, "void", "vf4"),
                  (5, "void", "vf5"), (6, TYPE, "vf_type"),
                  *((i, {9: "u32", 10: "u32", 11: "u8", 12: "u32", 14: "u8", 15: "u8", 17: "bool", 33: "u32",
                         36: "u32", 38: "f32", 43: "u32", 46: "u32"}.get(i, "void"), f"vf{i}") for i in range(7, 47))),
                 6, "Unk_23dc940::Unk_GetType", ((0x48, (0, 1), 5), (0x50, (1, 2), 0)), size=0x390),
    # On Unk_23dc940, its destructor out of line; slots 47-68 are its own.
    ExternalBase(0x23dcde0, "Unk_23dcdd0", "unsorted/Unk_23dcdd0.h",
                 ((2, "Unk_239a418_Ref<Unk_239a418_Handle>", "vf2"), (3, "void", "vf3"), (4, "void", "vf4"),
                  (5, "void", "vf5"), (6, TYPE, "vf_type"),
                  *((i, {9: "u32", 10: "u32", 11: "u8", 12: "u32", 14: "u8", 15: "u8", 17: "bool", 33: "u32",
                         36: "u32", 38: "f32", 43: "u32", 46: "u32", 68: "u32"}.get(i, "void"), f"vf{i}")
                    for i in range(7, 69))),
                 6, "Unk_23dcdd0::Unk_GetType", ((0x48, (0, 1), 5), (0x50, (1, 2), 0)), size=0x4b0),
    ExternalBase(0x23d4480, "Unk_23d4470", "unsorted/Unk_23d4470.h",
                 ((2, "Unk_239a418_Ref<Unk_239a418_Handle>", "vf2"), (3, "void", "vf3"), (4, "void", "vf4"),
                  (5, "void", "vf5"), (6, TYPE, "vf_type"), (7, "void", "vf7"), (8, "u32", "vf8")),
                 6, "Unk_23d4470::Unk_GetType", ((0x48, (0, 1), 5), (0x50, (1, 2), 0)),
                 shared_tu=True, source="unsorted/Unk_23d4470.inl", size=0x348),
    ExternalBase(0x23f4e50, "Unk_23f4e40", "unsorted/Unk_23f4e40.h",
                 ((2, "Unk_239a418_Ref<Unk_239a418_Handle>", "vf2"), (3, "void", "vf3"), (4, "void", "vf4"),
                  (5, "void", "vf5"), (6, TYPE, "vf_type"), (7, "u32", "vf7"), (8, "void", "vf8"), (9, "u32", "vf9"),
                  (10, "void", "vf10")),
                 6, "Unk_23f4e40::Unk_GetType", ((0x48, (0, 1), 5), (0x50, (1, 2), 0)), size=0x88),
    ExternalBase(0x23f4670, "Unk_23f4660", "unsorted/Unk_23f4660.h",
                 ((2, "Unk_239a418_Ref<Unk_239a418_Handle>", "vf2"), (3, "void", "vf3"), (4, "void", "vf4"),
                  (5, "void", "vf5"), (6, TYPE, "vf_type"), (7, "u32", "vf7"), (8, "void", "vf8"), (9, "u32", "vf9"),
                  (10, "void", "vf10"), (11, "void", "vf11"), (12, "void", "vf12"), (13, "void", "vf13"),
                  (14, "void", "vf14"), (15, "void", "vf15"), (16, "u32", "vf16")),
                 6, "Unk_23f4660::Unk_GetType", ((0x48, (0, 1), 5), (0x50, (1, 2), 0)), size=0x5d0),
    # gflib3's reference-counted object: its destructor is inline, and it has no type slot of
    # its own (a class that overrides the interfaces' getter gets slot 6 for it).
    ExternalBase(0x239a428, "Unk_239a418", "gflib3/Unk_239a418.h",
                 ((2, "Unk_239a418_Ref<Unk_239a418_Handle>", "vf2"), (3, "void", "vf3"), (4, "void", "vf4"),
                  (5, "void", "vf5")),
                 6, "Unk_239a418_GetType", ((0x48, (0, 1), 5), (0x50, (1, 2), 0)), inline_dtor=True,
                 size=0x60),
)
# Vtable groups whose classes are written by hand: write leaves their functions alone.
HANDWRITTEN = {e.vtable for e in EXTERNAL_BASES}


@dataclass
class ClassSpec:
    """How `write` declares one placeholder class. Every file that declares
    it declares it the same way, so this is decided once for all of them."""
    v: Vtable
    members: list[Member]           # the functions it defines, in one file or another
    pair: str | None                # destructor_pair()
    base: ClassSpec | None = None   # a derived class: its D2 is the base's, only its D0 is its own
    inline_dtor: bool = False       # `virtual ~X() {}` in the class, for a derived D0 in another TU
    order: list[int] = field(default_factory=list)  # a derived class's declared slots, key function first
    sigs: dict[int, tuple[str, tuple[str, ...]]] = field(default_factory=dict)  # slot -> (return type, params)
    fields: dict[int, str] = field(default_factory=dict)  # offset -> type, what lifted members use
    table: Table | None = None      # the entry array that element members index
    ext: ExternalBase | None = None  # a hand-written base (EXTERNAL_BASES) it derives from
    scalar_tail: bool = False       # padding near its end is u64 fields (tail_padding_start)

    @property
    def name(self) -> str:
        return class_name(self.v)


@dataclass
class Table:
    """An array of entries right after the vptr, which element members index:
    `m_entries[index].field_N`. The entries' fields are what the members
    read: pointers, an object pointer whose virtual function `obj_slot` an
    element call makes (with an entry field as its argument), u64 arguments."""
    stride: int
    count: int = 1                  # the class's constant slot 0, when it has one (its entry count)
    fields: dict[int, str] = field(default_factory=dict)  # entry offset -> "void*", "obj" or "u64"
    obj_slot: int | None = None

    def merge(self, x: Member) -> bool:
        shift, *offs = x.value
        if 1 << shift != self.stride:
            return False
        want = ({offs[0] - 8: "void*"} if x.kind == "element"
                else {offs[0] - 8: "obj", offs[1] - 8: "u64"})
        if x.kind == "element_call" and self.obj_slot not in (None, offs[2] // 8):
            return False
        out = dict(self.fields)
        for off, t in want.items():
            old = out.get(off)
            if old == "obj" and t == "void*":
                continue                # read as the object pointer it is
            if old not in (None, t) and not (old == "void*" and t == "obj"):
                return False
            out[off] = t
        if x.kind == "element_call":
            self.obj_slot = offs[2] // 8
        self.fields = out
        return True


def signature(x: Member, cls: str = "") -> tuple[str, tuple[str, ...]] | None:
    """(return type, parameters) of a member write defines, None for destructors
    (a lifted one's struct names are its class's, `cls`)."""
    if x.kind == "lifted":
        return x.lifted.named(x.lifted.rtype, cls), x.lifted.params
    if x.kind == "element":
        return "void*", ("u64 index",)
    if x.kind == "element_call":
        return "void", ("u64 index",)
    return (RTYPE[x.kind], ()) if x.kind in RTYPE else None


FIELD_KINDS = ("lifted", "element", "element_call")  # members that use fields of their class
ELEMENT = re.compile(r"add x8, x0, x1, lsl #(\d+) ; ldr x0, \[x8, #(\w+)\] ; ret")
ELEMENT_CALL = re.compile(r"add x8, x0, x1, lsl #(\d+) ; ldr x0, \[x8, #(\w+)\] ; cbz x0, #\w+ ; "
                          r"ldr x1, \[x8, #(\w+)\] ; ldr x8, \[x0\] ; ldr x2, \[x8, #(\w+)\] ; br x2 ; ret")


def element_member(m: Model, f: int, slot: int) -> Member | None:
    """An element member: `return m_entries[index].field_N;` (the entries
    right after the vptr, `index` a 64-bit argument), or one that calls a
    virtual function of an entry's object, if it's there, with another of
    the entry's fields: `if (obj) obj->vfK(field);`."""
    import capstone

    md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
    text = " ; ".join(f"{i.mnemonic} {i.op_str}".strip() for i in md.disasm(m.img[f:f + m.sizes.get(f, 0)], f))
    if x := ELEMENT.fullmatch(text):
        value, kind = (int(x.group(1)), int(x.group(2), 0)), "element"
    elif x := ELEMENT_CALL.fullmatch(text):
        value, kind = (int(x.group(1)), *(int(g, 0) for g in x.groups()[1:])), "element_call"
    else:
        return None
    shift, *offs = value
    entry = [o - 8 for o in offs[:2]]
    if not 3 <= shift <= 8 or any(o < 0 or o % 8 or o >= 1 << shift for o in entry) or offs[-1] % 8:
        return None
    return Member(slot, f, kind, value)


def _width(t) -> int:
    from leafgen import WIDTH
    return 8 if t == REF or not isinstance(t, str) else 0x80 if t == CALLABLE else WIDTH[t]


def _merge(fields: dict, new) -> dict | None:
    out = dict(fields)
    for off, t in new:
        w = _width(t)
        old = out.get(off)
        if off % w:
            return None
        if old is None:
            if any(o < off + w and off < o + _width(u) for o, u in out.items()):
                return None
            old = {} if isinstance(t, tuple) else t
        if isinstance(t, tuple) and isinstance(old, dict):
            old = _merge(old, t[1])
            if old is None:
                return None
        elif old != t:
            return None
        out[off] = old
    return out


def merge_fields(fields: dict, new) -> bool:
    """Add a member's fields to its class's, unless one conflicts with them
    (another type at the offset, or overlapping). A field is a type, or
    ("*", fields) for a pointer to a placeholder struct: in `fields` that is
    the struct's own fields dict, merged the same way."""
    out = _merge(fields, new)
    if out is None:
        return False
    fields.clear()
    fields.update(out)
    return True


def class_name(v: Vtable) -> str:
    """Placeholder class name: Unk_<its vtable's start>, the `_ZTV` symbol's address."""
    return f"Unk_{v.start:x}"


def mangle(cls: str, member: str, params: str = "v") -> str:
    """Itanium name of a member, vfN or D0/D2 for the destructors, with its
    parameters' codes (`v` for none)."""
    m = member if member in ("D0", "D2") else f"{len(member)}{member}"
    return f"_ZN{len(cls)}{cls}{m}E{params}"


def _mov_w0(m: Model, f: int) -> int:
    """The value of `mov w0, #N` (movz or movn, as capstone shows it)."""
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
    i = next(md.disasm(m.img[f:f + 4], f))
    return int(i.op_str.split("#", 1)[1], 0) & 0xFFFFFFFF


def destructor_pair(m: Model, v: Vtable) -> str | None:
    """'empty' (D2 is ret, D0 deletes), 'abstract' (D0 traps), 'other' (slots 0
    and 1 are destructors, not empty ones) or None (no destructor pair found)."""
    from nx.refs import decode, is_b_bl

    if len(v.slots) < 2 or not all(isinstance(f, int) for f in v.slots[:2]):
        return None
    s0, s1 = v.slots[:2]
    p0, p1 = m.pattern(s0), m.pattern(s1)
    targets = {t for _, w, _, t in decode(m.img, s1, m.sizes[s1]) if t is not None and is_b_bl(w)}
    delete = m.delete
    if p1 == "trap":
        return "abstract" if p0 == "ret" and any(isinstance(f, str) for f in v.slots) else "other"
    if s0 in targets or delete in targets:
        if p0 == "ret" and p1 == "b T" and targets == {delete}:
            return "empty"
        return "other"
    return None



def branch_target(m: Model, f: int) -> int | None:
    """Where a `b T` function goes."""
    from nx.refs import decode, is_b_bl
    return next((t for _, w, _, t in decode(m.img, f, m.sizes[f]) if t is not None and is_b_bl(w)), None)


def callee_name(t: int) -> tuple[str, str]:
    """(placeholder name, mangled name) of a forwarder's callee: `void Unk_<addr>(void* self)`."""
    name = f"Unk_{t:x}"
    return name, f"_Z{len(name)}{name}Pv"


PARAM_CODES = {"bool": "b", "u8": "h", "s8": "a", "u16": "t", "s16": "s", "u32": "j", "s32": "i",
               "u64": "m", "s64": "l", "f32": "f", "f64": "d"}
_LIFTED = re.compile(r"(.+) Unk_\w+\((.*)\) \{\n((?:.*\n)*)\}\n")


@dataclass(frozen=True)
class Lifted:
    """A small virtual function as a member: tools/leafgen.py's C++, with
    `self->field_N` as the class's own field_N."""
    rtype: str
    params: tuple[str, ...]         # "u32 value", "f32 /*unused*/", ...
    body: str                       # the statements, indented
    fields: tuple                   # ((offset, type or ("*", fields of the struct it points to)), ...)
    prefix: str = ""                # leafgen's name of the first argument's struct (Unk_<addr>)
    callee: tuple | None = None     # a final tail call: (its target, its parameter types)
    globals: tuple = ()             # ((address, type), ...): the extern Unk_<address> it reads or writes

    def named(self, text: str, cls: str) -> str:
        """`text` with leafgen's names of the structs the class's fields point
        to renamed after the class: Unk_<addr>_1a8 -> <cls>_1a8."""
        return text.replace(self.prefix + "_", cls + "_") if self.prefix else text

    @property
    def codes(self) -> str:
        return "".join(PARAM_CODES[p.split()[0]] for p in self.params) or "v"


def lift_member(m: Model, f: int) -> Lifted | None:
    """Lifted for f if leafgen can lift it and it touches nothing but fields
    of `this` (after the vptr), the fields they point to, and scalar arguments."""
    import leafgen as L

    if m.sizes.get(f, 0) > 64:
        return None
    saved = dict(L.GOT)
    L.GOT.clear()
    L.GOT.update(m.got)
    try:
        lf = L.lift(m.img[f:f + m.sizes[f]], f + BASE)
        render = L.Emitter.render_tail if lf.tail is not None else L.Emitter.render
        first = L.Emitter(f + BASE, lf)
        render(first)
        e = L.Emitter(f + BASE, lf)
        e.structs, e.arg_types, e.fp_types = first.structs, first.arg_types, first.fp_types
        e.globals = first.globals
        _, func = render(e)
    except (L.LiftError, ValueError, KeyError):
        return None
    finally:
        L.GOT.clear()
        L.GOT.update(saved)
    if any(g in m.sizes or g in {v.addr for v in m.vtables} for g in e.globals):
        return None  # named like a function or a class
    if any(isinstance(b, L.Arg) and (b.index != 0 or b.fp) for b in e.structs):
        return None
    byname = {s.name: s for s in e.structs.values()}

    def tree(s) -> tuple:
        out = []
        for off, t in sorted(s.fields.items()):
            if t.endswith("*"):
                if t[:-1] not in byname:
                    raise LookupError(t)
                t = ("*", tree(byname[t[:-1]]))
            out.append((off, t))
        return tuple(out)

    try:
        fields = tree(e.structs[L.Arg(0)]) if L.Arg(0) in e.structs else ()
    except LookupError:
        return None
    if any(off < 8 for off, _ in fields):
        return None
    x = _LIFTED.fullmatch(func)
    if x is None:
        return None
    params = [p.strip() for p in x.group(2).split(",")] if x.group(2) else []  # () if it uses no argument
    if params and not params[0].endswith(" self") and params[0] != "void* /*unused*/":
        return None
    params = params[1:]
    if any(p.split()[0] not in PARAM_CODES for p in params):
        return None
    rtype = x.group(1).replace("const ", "") if "*" in x.group(1) else x.group(1)
    body = re.sub(r"\bself\b", "this", x.group(3).replace("self->", ""))  # passed on to a tail call
    callee = (lf.tail - BASE, e.callee[1]) if lf.tail is not None else None
    return Lifted(rtype, tuple(params), body, fields, f"Unk_{e.short}", callee, tuple(sorted(e.globals.items())))


def simple_body(x: Member) -> str:
    """The body of a member of a simple kind (ret, constant, zero, null, string)."""
    if x.kind == "ret":
        return "{}"
    if x.kind == "constant":
        return f"{{\n    return {x.value if x.value < 10 else hex(x.value)};\n}}"
    if x.kind == "string":
        return f'{{\n    return "{x.value}";\n}}'
    return {"zero": "{\n    return 0;\n}", "null": "{\n    return nullptr;\n}"}[x.kind]


def string_return(m: Model, f: int) -> str | None:
    """The C++ spelling of the string literal f returns, if it is
    `adrp x0, S ; add x0, x0, S ; ret` with S a string (check.py compares
    literals by their contents)."""
    from common import load_module
    from nx.refs import decode
    from segments import c_string

    if m.pattern(f) != "adrp x0, #N ; add x0, x0, #N ; ret":
        return None
    targets = [t for _, _, _, t in decode(m.img, f, m.sizes[f]) if t is not None]
    if not hasattr(m, "_rodata"):
        m._rodata = load_module(m.game)["rodata"]
    text = c_string(m.img, targets[-1], *m._rodata) if targets else None
    return text.replace("\\", "\\\\").replace('"', '\\"') if text is not None else None


def tail_callee(callee: tuple) -> tuple[int, str]:
    """(function, mangled name) of a lifted member's tail-call target."""
    import leafgen as L
    t, types = callee
    return t, L.callee_name(t + BASE, list(types))[1]


def placeholder_members(m: Model, v: Vtable, own: dict[int, tuple[int, int]], pickable,
                        callee=None, lifter=None, elements: bool = False) -> list[Member]:
    """The members of v's class that write defines: the simple functions it owns.

    A forwarder (`b T`) is one when callee(f) gives its target: it passes all
    of its arguments on, so `Unk_<T>(this);` compiles to the same tail call."""
    out = []
    pair = destructor_pair(m, v)
    first = 0
    if pair is not None:
        first = 2
        if pair in ("empty", "abstract") and all(own.get(f) == (v.addr, i) and pickable(f)
                                                 for i, f in enumerate(v.slots[:2])):
            out.append(Member(0, v.slots[0], "dtor"))
    for i, f in enumerate(v.slots[first:], start=first):
        if not isinstance(f, int) or own.get(f) != (v.addr, i) or not pickable(f):
            continue
        k = slot_kind(m.pattern(f))
        if k in ("ret", "zero", "null"):
            out.append(Member(i, f, k))
        elif k == "constant":
            out.append(Member(i, f, k, _mov_w0(m, f)))
        elif k == "forward" and callee is not None and (t := callee(f)) is not None:
            out.append(Member(i, f, k, t))
        elif k == "small" and (text := string_return(m, f)) is not None:
            out.append(Member(i, f, "string", text))
        elif k in ("small", "other") and lifter is not None and (x := lifter(f)) is not None:
            out.append(Member(i, f, "lifted", lifted=x))
        elif k in ("small", "other") and elements and (x := element_member(m, f, i)) is not None:
            out.append(x)
    return out


def derived_order(d: Vtable, base: Vtable, members: list[Member], seg) -> list[int] | None:
    """The slots a class derived from `base` declares, its key function first,
    or None if none of its defined functions can be the key function.

    It declares the slots where it differs from its base: overrides (slots
    the base has) and new virtual functions (after them). Its key function,
    the first non-pure virtual function it declares out of line, decides where
    its vtable, and with it its implicit D0, is emitted: so it has to be one of
    the functions it defines, in the D0's file. Overrides can be declared in
    any order, new functions only in slot order, so a new function can only
    move to the front when no other new function is declared before it."""
    order = [i for i in range(2, len(d.slots)) if i >= len(base.slots) or d.slots[i] != base.slots[i]]
    here = {x.slot for x in members if signature(x) is not None and seg(x.addr) == seg(d.slots[1])}
    for n, i in enumerate(order):
        new_before = any(j >= len(base.slots) for j in order[:n])
        if i in here and (i < len(base.slots) or not new_before):
            return [i, *order[:n], *order[n + 1:]]
    return None


def class_specs(m: Model, picked: dict[int, list[Member]], own: dict[int, tuple[int, int]],
                seg, pickable, getter_ok=lambda t: False) -> dict[int, ClassSpec]:
    """A ClassSpec for every picked vtable, with the derived classes modelled.

    A derived class is one whose destructor is implicit (or inline and empty)
    and whose base's destructor is user-declared: clang uses the base's D2 for
    its D2 (its slot 0 holds the base's), and its D0 is weak, emitted with its
    vtable in the TU of its key function. When the base's D2 is empty and
    visible there (inline, or defined in that TU) the D0 is a bare
    `b operator delete` (docs/game_code.md, "Bases"). This models the classes
    whose D0 is that, whose base is a picked class with its empty destructor
    pair, and that define a function in the D0's TU to be their key function.
    The base's destructor becomes inline when such a D0 is in another TU; then
    the base needs a key function of its own in the TU of its destructors.

    Lifted members use fields of their class: one whose fields conflict with
    those of an earlier one (in slot order) is left out, and so are a derived
    class's (its fields would follow its base's)."""
    by = {v.addr: v for v in m.vtables}
    specs = {}
    for a, ms in picked.items():
        s = specs[a] = ClassSpec(by[a], [], destructor_pair(m, by[a]))
        s.members = [x for x in ms if x.kind != "lifted" or merge_fields(s.fields, x.lifted.fields)]
        s.members = [x for x in s.members if x.kind not in ("element", "element_call") or _table(s, x)]
        s.sigs = {x.slot: sig for x in s.members if (sig := signature(x, s.name)) is not None}
    guess = bases(m.vtables)
    has_secondary = {v.group for v in m.vtables if v.group != v.addr}
    families: dict[int, dict[int, tuple[str, tuple[str, ...]]]] = {}
    dropped: dict[int, list[Member]] = {}
    for a, d in sorted(specs.items()):
        if any(x.kind in FIELD_KINDS for x in d.members):
            simple = ClassSpec(d.v, [x for x in d.members if x.kind not in FIELD_KINDS], d.pair)
            if not _derive(m, simple, specs, own, guess, has_secondary, families, seg, pickable):
                continue
            dropped[a] = [x for x in d.members if x.kind == "lifted"]
            specs[a] = d = simple
            d.sigs = {x.slot: sig for x in d.members if (sig := signature(x)) is not None}
        else:
            _derive(m, d, specs, own, guess, has_secondary, families, seg, pickable)
    for a, xs in dropped.items():
        _readd_lifted(specs[a], xs, families)
    for e in EXTERNAL_BASES:
        derive_external(m, e, specs, picked, own, seg, pickable, getter_ok)
    for d in specs.values():
        if d.base is not None:
            n = len(d.base.v.slots)
            d.sigs = {**{i: t for i, t in d.sigs.items() if i >= n},
                      **{i: t for i, t in d.base.sigs.items() if i < n}}
    return specs


SIMPLE_KINDS = ("ret", "constant", "zero", "null", "forward", "string")


def _calls_and_statics(m: Model, f: int) -> tuple[list[int], list[int]]:
    """f's calls (out of f) and the statics it loads from the GOT, in order."""
    from nx.refs import decode, is_b_bl

    n = m.sizes.get(f, 0)
    calls, statics = [], []
    for _, w, _, t in decode(m.img, f, n):
        if t is None:
            continue
        if is_b_bl(w):
            if not f <= t < f + n:  # not a branch within f
                calls.append(t)
        elif t in m.got and m.got[t] not in statics:
            statics.append(m.got[t])
    return calls, statics


def intermediate_type(m: Model, f: int) -> tuple[int, int] | None:
    """(type object, getter) of the class between a hand-written base and the
    class whose vf_type f is, when f inlines that class's getter too: five
    calls (two guarded statics, then a getter out of line) instead of three.
    Its type is the fourth static f loads from the GOT (guard, type, guard,
    type); the getter is the call that isn't a guard's (those come twice)."""
    calls, statics = _calls_and_statics(m, f)
    once = [t for t in calls if calls.count(t) == 1]
    if len(calls) != 5 or len(statics) != 4 or len(once) != 1:
        return None
    return statics[3], once[0]


def _guarded_call(m: Model, f: int) -> int | None:
    """What a vf_type f calls between its guard's acquire and release (three
    calls, one guarded static): its own getter inlined, its parent's not."""
    calls, statics = _calls_and_statics(m, f)
    if len(calls) != 3 or len(statics) != 2 or len(set(calls)) != 3:
        return None
    return calls[1]


def out_of_line_parent(m: Model, f: int, e: ExternalBase, base_statics: list[int] | None = None) -> int | None:
    """The getter a vf_type f of a class on e calls for its type's parent,
    when that's another class's getter on e, out of line. On the object, a
    direct descendant's: three statics deep, like Unk_23d4470::Unk_GetType.
    On another base, whose own getter loads `base_statics`: a getter whose
    parent is that one, inlined (its statics, then the base's)."""
    g = _guarded_call(m, f)
    if g is None:
        return None
    _, gstatics = _calls_and_statics(m, g)
    if e.get_type == "Unk_239a418_GetType":
        return g if len(gstatics) == 6 else None
    return g if base_statics and len(gstatics) == len(base_statics) + 2 and gstatics[2:] == base_statics else None


def base_getter_copy(m: Model, f: int, base_statics: list[int] | None) -> int | None:
    """The base's own getter, out of line, when a vf_type f calls it for its
    type's parent (the base's getter is inline: a TU with several callers
    keeps it out of line, and the linker one copy of it)."""
    g = _guarded_call(m, f)
    return g if g is not None and base_statics and _calls_and_statics(m, g)[1] == base_statics else None


def base_type_statics(m: Model, e: ExternalBase, ev: Vtable) -> list[int] | None:
    """The statics e's own type getter loads (guard and type, then its
    parent's), from its type slot: the getter inlined there, or `b <it>`."""
    f = ev.slots[e.type_slot] if e.type_slot < len(ev.slots) else None
    if isinstance(f, int) and m.pattern(f) == "b T":
        f = branch_target(m, f)
    return _calls_and_statics(m, f)[1] if isinstance(f, int) else None


def getter_name(get_type: str) -> str:
    """The mangled name of a base's getter (`Unk_X::Unk_GetType`)."""
    cls, _, fn = get_type.partition("::")
    return mangle(cls, fn)


REF = "Unk_239a418_Ref<Unk_239a418>"   # a reference member (gflib3/Unk_239a418.h)
_RELEASE = " ; cbz x0, #N ; ldr x8, [x0, #N]! ; ldr x8, [x8, #N] ; blr x8 ; str xzr, [x19, #N]"
_OBJECT_PART = (" ; adrp x8, #N ; ldr x8, [x8, #N] ; ldr x0, [x19, #N] ; add x9, x8, #N ; add x10, x8, #N ;"
                " add x8, x8, #N ; str x9, [x19] ; stp x10, x8, [x19, #N]" + _RELEASE)


def ref_dtor_pattern(base: str, n: int) -> str | None:
    """The D2 of a class on the object (whose D2's pattern is `base`) with n
    reference members and nothing else to destroy: its vtable, its members
    released (the last declared first), then the object's D2 inlined."""
    first = " ; ldr x0, [x0, #N]" + _RELEASE
    head, sep, tail = base.partition(first)
    if not sep:
        return None
    return head + first + (" ; ldr x0, [x19, #N]" + _RELEASE) * (n - 1) + _OBJECT_PART + tail


def ref_members(m: Model, f: int, d2: int, vtable: int) -> tuple[int, ...] | None:
    """The offsets of the reference members a D2 f releases, when that's all
    it does before the object's D2 (d2, inlined): see ref_dtor_pattern."""
    from nx.refs import decode
    offs = [((w >> 10) & 0xFFF) * 8 for _, w, _, _ in decode(m.img, f, m.sizes.get(f, 4))
            if w & 0xFFC0001F == 0xF9400000 and (w >> 5) & 31 in (0, 19)]  # ldr x0, [x0|x19, #off]
    if len(offs) < 2 or offs[-1] != 0x58 or any(a <= b for a, b in zip(offs, offs[1:])) or offs[-2] < 0x60:
        return None
    if m.pattern(f) != ref_dtor_pattern(m.pattern(d2) or "", len(offs) - 1):
        return None
    calls, statics = _calls_and_statics(m, f)
    if calls or statics[:1] != [vtable] or len(statics) != 2 or statics[1] not in _calls_and_statics(m, d2)[1][:1]:
        return None
    return tuple(reversed(offs[:-1]))


# A D2's start that stores the vptrs of a class with the object's two secondary bases (+0x48, +0x50),
# and its end when the base's D2 is out of line: a tail call of it.
_VPTRS = ("str x19, [sp, #N]! ; stp x29, x30, [sp, #N] ; add x29, sp, #N ; adrp x8, #N ; ldr x8, [x8, #N] ;"
          " add x9, x8, #N ; add x10, x8, #N ; add x8, x8, #N ; mov x19, x0 ; str x9, [x0] ; stp x10, x8, [x0, #N]")
_TAIL_D2 = " ; ldp x29, x30, [sp, #N] ; mov x0, x19 ; ldr x19, [sp], #N ; b T"


def ref_tail_pattern(n: int) -> str:
    """The D2 of a class with n reference members and nothing else to
    destroy, on a base whose D2 is out of line: its vptrs, its members
    released (the last declared first), then a tail call of the base's D2."""
    return _VPTRS + " ; ldr x0, [x0, #N]" + _RELEASE + (" ; ldr x0, [x19, #N]" + _RELEASE) * (n - 1) + _TAIL_D2


def ref_members_tail(m: Model, f: int, d2: int, vtable: int, size: int) -> tuple[int, ...] | None:
    """The offsets of the reference members a D2 f releases before it
    tail-calls its base's D2 (d2, out of line), when that's all it does: see
    ref_tail_pattern. They come after the base's `size` bytes, and f stores
    the class's own vtable."""
    from nx.refs import decode
    offs = [((w >> 10) & 0xFFF) * 8 for _, w, _, _ in decode(m.img, f, m.sizes.get(f, 4))
            if w & 0xFFC0001F == 0xF9400000 and (w >> 5) & 31 in (0, 19)]  # ldr x0, [x0|x19, #off]
    if not offs or offs[-1] < size or any(a <= b for a, b in zip(offs, offs[1:])):
        return None
    if m.pattern(f) != ref_tail_pattern(len(offs)):
        return None
    calls, statics = _calls_and_statics(m, f)
    if calls != [d2] or statics != [vtable]:
        return None
    return tuple(reversed(offs))


CALLABLE = "Unk_23d4470_Callable"   # a callable member (unsorted/Unk_23d4470.h), 0x80 bytes
CALLABLE_HEADER = "unsorted/Unk_23d4470.h"
_ZERO4 = r"(?: ; str xzr, \[x19, #N\]){4}|(?: ; stp xzr, xzr, \[x19, #N\]){2}"
_REF_RE = r" ; ldr x0, \[x(?:0|19), #N\]" + re.escape(_RELEASE)
_CALL_RE = r" ; ldr x8, \[x(?:0|19), #N\] ; cbz x8, #N ; add x0, x19, #N(?:" + _ZERO4 + r") ; blr x8"
# a callable first: its manager's load is scheduled between the vptr stores
_VPTRS_CALL = (re.escape(_VPTRS.replace(" ; str x9, [x0] ; stp x10, x8, [x0, #N]", ""))
               + r" ; stp x10, x8, \[x0, #N\] ; ldr x8, \[x0, #N\] ; str x9, \[x0\] ; cbz x8, #N ;"
               + r" add x0, x19, #N(?:" + _ZERO4 + r") ; blr x8")
_TAIL_MEMBERS = re.compile(rf"(?:{re.escape(_VPTRS)}|{_VPTRS_CALL})(?:{_REF_RE}|{_CALL_RE})*{re.escape(_TAIL_D2)}")


def tail_members(m: Model, f: int, d2: int, vtable: int, size: int) -> dict[int, str] | None:
    """The members a D2 f destroys before it tail-calls its base's D2 (d2, out
    of line), when they're references (REF) and callables (CALLABLE: if it
    holds one, its four words are cleared and its manager disposes of the
    storage at +0x20): offset -> type, after the base's `size` bytes, the
    last declared destroyed first. f stores the class's own vtable."""
    from nx.refs import decode
    if not _TAIL_MEMBERS.fullmatch(m.pattern(f) or ""):
        return None
    calls, statics = _calls_and_statics(m, f)
    if calls != [d2] or statics != [vtable]:
        return None
    order: list[tuple[int, str]] = []
    managers = set()
    for _, w, _, _ in decode(m.img, f, m.sizes.get(f, 4)):
        rn, off = (w >> 5) & 31, ((w >> 10) & 0xFFF) * 8
        if w & 0xFFC0001F == 0xF9400000 and rn in (0, 19):       # ldr x0, [x0|x19, #off]: a reference
            order.append((off, REF))
        elif w & 0xFFC0001F == 0xF9400008 and rn in (0, 19):     # ldr x8, [x0|x19, #off]: a manager
            managers.add(off)
        elif w & 0xFFC003FF == 0x91000260:                       # add x0, x19, #imm: a callable's storage
            order.append((((w >> 10) & 0xFFF) - 0x20, CALLABLE))
    offs = [o for o, _ in order]
    if not order or offs[-1] < size or any(a <= b for a, b in zip(offs, offs[1:])) \
            or managers != {o + 8 for o, k in order if k == CALLABLE}:
        return None
    ends = sorted((o, o + (0x80 if k == CALLABLE else 8)) for o, k in order)
    if any(a[1] > b[0] for a, b in zip(ends, ends[1:])):
        return None
    return dict(sorted(order))


def direct_getter(m: Model, g: int) -> bool:
    """Whether g is the type getter of a direct descendant of the object, its
    parent's getter inlined: three guarded statics (its type, the object's,
    the root's) and no other call."""
    calls, statics = _calls_and_statics(m, g)
    return len(statics) == 6 and len(calls) == 6 and len(set(calls)) == 2


def getter_type(m: Model, g: int) -> int | None:
    """The type object getter g returns: the second static it loads (its guard first)."""
    _, statics = _calls_and_statics(m, g)
    return statics[1] if len(statics) >= 2 else None


def _ext_lifted_ok(e: ExternalBase, ev: Vtable, x: Member, fields: dict) -> bool:
    """Whether a lifted member can be one of a class derived from e: its
    fields after e's (merged into `fields`), no struct named after the class
    in its signature or body, and an override declared as e declares it (no
    parameters). Its callee and globals are declared by the file, as for
    any lifted member."""
    lf = x.lifted
    if not e.size or any(off < e.size for off, _ in lf.fields):
        return False
    if lf.prefix and any(lf.prefix + "_" in t for t in (lf.rtype, *lf.params, lf.body)):
        return False
    if x.slot < len(ev.slots) and (lf.params or e.slot(x.slot)[0] != lf.rtype):
        return False
    return merge_fields(fields, lf.fields)


def derive_external(m: Model, e: ExternalBase, specs: dict[int, ClassSpec], picked: dict[int, list[Member]],
                    own: dict[int, tuple[int, int]], seg, pickable, getter_ok) -> None:
    """Model the classes derived from hand-written base e (see ExternalBase)."""
    from nx.refs import decode, is_b_bl

    by = {v.addr: v for v in m.vtables}
    ev = by.get(e.vtable)
    if ev is None:
        return
    groups: dict[int, list[Vtable]] = defaultdict(list)
    for v in m.vtables:
        groups[v.group].append(v)
    in_vtables = {f for v in m.vtables for f in v.slots if isinstance(f, int)}
    callers: dict[int, set[int]] = defaultdict(set)
    d2 = ev.slots[0]
    esecs = [w for w in groups[ev.addr] if w is not ev]
    base_statics = base_type_statics(m, e, ev)
    # every vtable's type slots, in the primary vtables and the secondary ones
    type_fns = {w.slots[i] for w in m.vtables
                for i in ([e.type_slot] if not w.offset_to_top else
                          [ts for off, _, ts in e.secondaries if -w.offset_to_top == off])
                if i < len(w.slots)}

    def tail(v: Vtable) -> bool:
        f = v.slots[e.type_slot] if e.type_slot < len(v.slots) else None
        return isinstance(f, int) and m.pattern(f) == "b T"

    # A class whose getter other classes call (on the object: see the tail
    # shape below) goes first, so that they know it's written: getter -> class.
    owners: dict[int, int] = {}
    gone_of: dict[int, tuple[list[Vtable], set[int]]] = {}
    before: dict[int, ClassSpec | None] = {}  # what a class was, if it isn't written on e after all
    for v in sorted(m.vtables, key=lambda v: not tail(v)):
        if v.group != v.addr or v.offset_to_top or v.addr == ev.addr or len(v.slots) < len(ev.slots):
            continue
        s0, s1 = v.slots[0], v.slots[1]
        # Its destructor is implicit: the base's D2, or one that only releases
        # reference members, then runs the base's (inlined, or tail-called
        # when it's out of line).
        refs = None
        if s0 != d2 and isinstance(s0, int):
            refs = ref_members(m, s0, d2, v.start) if e.inline_dtor else \
                tail_members(m, s0, d2, v.start, e.size)
            if refs is None or own.get(s0) != (v.addr, 0) or not pickable(s0):
                continue
        if (s0 != d2 and refs is None) or not isinstance(s1, int) or s1 == ev.slots[1] \
                or own.get(s1) != (v.addr, 1) or not pickable(s1):
            continue
        # A D2 too big to be inlined into the D0 and the thunks (only with
        # reference members, on an out-of-line base) is tail-called instead.
        called = bool(refs) and not e.inline_dtor and m.pattern(s1) == "b T" and branch_target(m, s1) == s0
        if e.inline_dtor or refs:   # the D0 is the D2, inlined (the operator delete is empty)
            if m.pattern(s1) != m.pattern(s0) and not called:
                continue
        elif m.pattern(s1) != "b T" or branch_target(m, s1) != d2:
            continue
        secs = [w for w in groups[v.addr] if w is not v]
        if [(w.offset_to_top, len(w.slots)) for w in secs] != [(w.offset_to_top, len(w.slots)) for w in esecs] \
                or any(isinstance(f, str) for f in v.slots):
            continue
        extra = [Member(1, s1, "d0")] + ([Member(0, s0, "d2")] if refs else [])
        ok = True
        for w, ew, (off, dslots, _) in zip(secs, esecs, e.secondaries):
            for j, which in zip(dslots, ("D1", "D0")):
                f = w.slots[j]
                if called:              # thunks that tail-call its D2
                    same = m.pattern(f) == "sub x0, x0, #N ; b T" and branch_target(m, f) == s0
                elif refs:              # thunks with its D2 inlined, the D1's and D0's alike
                    # (before a tail call, one may keep its own `this` too, in another register: see
                    # Unk_239a418_Base's fields)
                    sizes = (m.sizes.get(s0),) if e.inline_dtor else (m.sizes.get(s0), m.sizes.get(s0, 0) + 4)
                    same = m.pattern(f) == m.pattern(w.slots[dslots[0]]) and m.sizes.get(f) in sizes
                elif e.inline_dtor:     # thunks with the D2 inlined, like the base's
                    same = m.pattern(f) == m.pattern(ew.slots[j])
                else:
                    same = m.pattern(f) == "sub x0, x0, #N ; b T" and branch_target(m, f) == d2
                if not same or own.get(f) != (w.addr, j) or not pickable(f):
                    ok = False
                extra.append(Member(j, f, "ext_thunk", (off, which)))
        # It overrides the type getter when its secondary type slots differ from the base's.
        f6 = v.slots[e.type_slot] if e.type_slot < len(v.slots) else None
        thunks = [w.slots[ts] for w, (_, _, ts) in zip(secs, e.secondaries)]
        overrides = any(f != ew.slots[ts] for f, ew, (_, _, ts) in zip(thunks, esecs, e.secondaries))
        t = branch_target(m, f6) if isinstance(f6, int) and m.pattern(f6) == "b T" else None
        if ok and overrides and t is None and e.shared_tu:
            # In a TU with many classes: its getter is inlined into vf_type (out
            # of line, its key function) and calls the base's out of line, and
            # the secondary type slots are copies of vf_type (thunks with it inlined).
            if not isinstance(f6, int) or not pickable(f6) or any(
                    m.pattern(f) != m.pattern(f6) or not pickable(f) for f in thunks):
                ok = False
            else:
                it = intermediate_type(m, f6)
                inter = it is not None and m.names.get(it[1], "").endswith("11Unk_GetTypeEv")
                extra.append(Member(e.type_slot, f6, "ext_type", ("copy", it[0], None, None) if inter else "copy"))
                extra += [Member(-1, f, "ext_thunk", (off, "vf_type"))
                          for f, (off, _, _) in zip(thunks, e.secondaries)]
        elif ok and overrides and t is None and isinstance(f6, int) and (it := intermediate_type(m, f6)) \
                and (x := getter_type(m, it[1])) is not None \
                and (it[1] in owners or m.names.get(it[1], "") in ("", mangle(f"Unk_{x:x}", "Unk_GetType"))) \
                and all(m.pattern(f) == m.pattern(f6) for f in thunks):
            # Two below the base, under a class whose getter (out of line: it
            # has many callers) isn't the base's: vf_type inlines its getter
            # and the in-between class's, and its secondary type slots are
            # copies of it. That class's getter is only named here.
            if not pickable(f6) or any(not pickable(f) for f in thunks):
                ok = False
            else:
                extra.append(Member(e.type_slot, f6, "ext_type", ("copy", it[0], x, it[1])))
                extra += [Member(-1, f, "ext_thunk", (off, "vf_type"))
                          for f, (off, _, _) in zip(thunks, e.secondaries)]
        elif ok and overrides and t is None and isinstance(f6, int) \
                and (g := out_of_line_parent(m, f6, e, base_statics)) \
                and (x := getter_type(m, g)) is not None \
                and (g in owners or m.names.get(g, "") in ("", mangle(f"Unk_{x:x}", "Unk_GetType"))) \
                and all(m.pattern(f) == m.pattern(f6) for f in thunks):
            # On another direct descendant of the object, whose getter is out
            # of line: vf_type inlines its own getter, which calls that one,
            # and its secondary type slots are copies of it.
            if not pickable(f6) or any(not pickable(f) for f in thunks):
                ok = False
            else:
                extra.append(Member(e.type_slot, f6, "ext_type", ("copy", None, x, g)))
                extra += [Member(-1, f, "ext_thunk", (off, "vf_type"))
                          for f, (off, _, _) in zip(thunks, e.secondaries)]
        elif ok and overrides and t is None and isinstance(f6, int) \
                and (g := base_getter_copy(m, f6, base_statics)) is not None \
                and m.names.get(g, "") in ("", getter_name(e.get_type)) \
                and all(m.pattern(f) == m.pattern(f6) for f in thunks):
            # Its getter inlined into vf_type, calling the base's out of line:
            # a file with another such class keeps the base's getter out of
            # line (written only then, below). Its secondary type slots are
            # copies of vf_type.
            if not pickable(f6) or any(not pickable(f) for f in thunks):
                ok = False
            else:
                extra.append(Member(e.type_slot, f6, "ext_type", ("copy", None, None, g)))
                extra += [Member(-1, f, "ext_thunk", (off, "vf_type"))
                          for f, (off, _, _) in zip(thunks, e.secondaries)]
        elif ok and overrides and t is None:
            # Its getter is inlined into vf_type (the one caller in its TU), and
            # the secondary type slots are thunks that tail-call vf_type.
            if not isinstance(f6, int) or not pickable(f6) or any(
                    m.pattern(f) != "sub x0, x0, #N ; b T" or branch_target(m, f) != f6 or not pickable(f)
                    for f in thunks):
                ok = False
            else:
                extra.append(Member(e.type_slot, f6, "ext_type", None))
                extra += [Member(-1, f, "ext_thunk", (off, "vf_type"))
                          for f, (off, _, _) in zip(thunks, e.secondaries)]
        elif ok and overrides:
            # T's type has the base's as its parent. On the object (no type
            # slot of its own), T is a direct descendant's getter, three
            # statics deep, and other classes' getters may call it: it's named
            # after its type object (x), as they name it (out_of_line_parent).
            x = None
            if e.type_slot >= len(ev.slots):
                x = getter_type(m, t) if direct_getter(m, t) else None
            if (e.type_slot >= len(ev.slots) and x is None) or t in in_vtables or not getter_ok(t) \
                    or not pickable(f6) \
                    or any(branch_target(m, f) != t or m.pattern(f) != "b T" or not pickable(f) for f in thunks):
                ok = False
            else:
                if not callers:
                    for a, n in m.funcs:
                        for _, w, _, tt in decode(m.img, a, n):
                            if tt is not None and is_b_bl(w):
                                callers[tt].add(a)
                # Other code of the class may call its getter too; another
                # class's vtable function may not (then T isn't this class's),
                # unless it's the getter of a class derived from this one,
                # inlined: its type's parent is T's. On another base, T is
                # named after its type object then too, when it loads its
                # type and the base's getter's statics (a child's getter).
                others = (callers[t] - {f6, *thunks}) & in_vtables
                if x is None and others and base_statics:
                    ts = _calls_and_statics(m, t)[1]
                    if len(ts) == len(base_statics) + 2 and ts[2:] == base_statics:
                        x = getter_type(m, t)
                # (On another base, only a caller in another class's type slot
                # says T is shared: other virtual functions may check a type.)
                if x is not None and e.type_slot < len(ev.slots):
                    others &= type_fns
                foreign = {c for c in others
                           if x is None or (out_of_line_parent(m, c, e, base_statics) != t
                                            and (intermediate_type(m, c) or (0, None))[1] != t)}
                if foreign:
                    ok = False
                extra.append(Member(e.type_slot, f6, "ext_type", t))
                extra.append(Member(-1, t, "ext_getter", x or 0))
                extra += [Member(-1, f, "ext_thunk", (off, "vf_type"))
                          for f, (off, _, _) in zip(thunks, e.secondaries)]
        if not ok or any(seg(x.addr) != seg(s1) for x in extra):
            continue
        mine = []
        # the members its D2 destroys, then lifted members' fields
        fields: dict = dict(refs) if isinstance(refs, dict) else {o: REF for o in refs or ()}
        for x in picked.get(v.addr, []):
            if x.kind == "lifted" and x.slot >= 2 and x.slot != e.type_slot and _ext_lifted_ok(e, ev, x, fields):
                mine.append(x)
                continue
            if x.kind not in SIMPLE_KINDS or x.slot < 2 or x.slot == e.type_slot:
                if x.kind not in SIMPLE_KINDS and m.statuses.get(x.addr) == "O" and x.slot != e.type_slot:
                    ok = False  # a matched member this shape can't write: keep the class as it is
                continue
            if x.slot < len(ev.slots):
                if v.slots[x.slot] == ev.slots[x.slot]:
                    continue
                if e.slot(x.slot)[0] != RTYPE[x.kind]:
                    ok = False
            mine.append(x)
        declared = [i for i in range(2, len(v.slots)) if i >= len(ev.slots) or v.slots[i] != ev.slots[i]]
        if not ok:
            continue
        inline_type = any(x.kind == "ext_type" and x.value is None for x in extra)
        if inline_type:
            # vf_type is inline in the class (else clang inlines it into its
            # thunks), so the key function is the first other function it
            # declares: one it defines in the D0's file. An override can move
            # to the front; a new function only stays where it is.
            here = {x.slot for x in mine if seg(x.addr) == seg(s1)}
            rest = [i for i in declared if i != e.type_slot]
            key = next((i for i in rest if i in here and i < len(ev.slots)), None)
            if key is not None:
                order = [key, *(i for i in declared if i != key)]
            elif rest and rest[0] in here:
                order = declared
            else:
                continue
        elif e.type_slot in declared:
            order = [e.type_slot, *(i for i in declared if i != e.type_slot)]
        else:
            order = derived_order(v, ev, mine, seg)
            if order is None:
                continue
        before[v.addr] = specs.get(v.addr)
        # Its thunks with its D2 inlined say what's at the end of the class:
        # a field when they're as long as the D2, bytes when they keep their
        # own `this` too (tail_padding_start).
        scalar_tail = bool(refs) and not e.inline_dtor and all(
            m.sizes.get(x.addr) == m.sizes.get(s0) for x in extra if x.kind == "ext_thunk" and x.value[1] in ("D0", "D1"))
        d = specs[v.addr] = ClassSpec(v, mine + extra, None, ext=e, order=order, fields=fields,
                                      scalar_tail=scalar_tail)
        d.sigs = {x.slot: signature(x) if x.kind == "lifted" else (RTYPE[x.kind], ()) for x in mine}
        gone_of[v.addr] = (secs, {x.addr for x in extra})
        owners.update((x.addr, v.addr) for x in extra if x.kind == "ext_getter" and x.value)
    # A class whose getter calls the base's out of line is written only with
    # another such class in its file: alone there, clang inlines the base's.
    def base_copy(d: ClassSpec) -> int | None:
        return next((x.addr for x in d.members if x.kind == "ext_type" and isinstance(x.value, tuple)
                     and x.value[1] is None and x.value[2] is None and x.value[3] is not None), None)

    copies = Counter(seg(a) for d in specs.values() if d.ext is e and (a := base_copy(d)) is not None)
    for d in [d for d in specs.values() if d.ext is e and (a := base_copy(d)) is not None and copies[seg(a)] < 2]:
        del gone_of[d.v.addr]
        if before[d.v.addr] is None:
            del specs[d.v.addr]
        else:
            specs[d.v.addr] = before[d.v.addr]
    # A class whose getter other classes call is written only with one of them
    # in its TU: with no other caller there, clang inlines the getter.
    used = {(seg(x.value[3]), x.value[3]) for d in specs.values() if d.ext is e for x in d.members
            if x.kind == "ext_type" and isinstance(x.value, tuple) and x.value[3] is not None
            and seg(x.addr) == seg(x.value[3])}
    dropped = {g for g, a in owners.items() if (seg(g), g) not in used}
    for d in [d for d in specs.values() if d.ext is e and (any(owners.get(g) == d.v.addr for g in dropped) or any(
            x.kind == "ext_type" and isinstance(x.value, tuple) and x.value[3] in dropped for x in d.members))]:
        # (on such a class: its getter keeps its old name)
        del gone_of[d.v.addr]
        if before[d.v.addr] is None:
            del specs[d.v.addr]
        else:
            specs[d.v.addr] = before[d.v.addr]
    for secs, gone in gone_of.values():
        for w in secs:              # its secondary vtables' functions are its own now
            if w.addr in specs:
                specs[w.addr].members = [x for x in specs[w.addr].members if x.addr not in gone]
                if not specs[w.addr].members:
                    del specs[w.addr]


def _table(s: ClassSpec, x: Member) -> bool:
    """Add element member x's entry fields to s's table, unless they conflict
    (or the class has lifted fields, which the entries would overlap)."""
    if s.fields:
        return False
    if s.table is None:
        count = next((y.value for y in s.members if y.slot == 0 and y.kind == "constant"), 1)
        s.table = Table(1 << x.value[0], max(count, 1))
    return s.table.merge(x)


def _readd_lifted(d: ClassSpec, xs: list[Member], families) -> None:
    """A derived class's lifted members, which class_specs left out to derive
    it: their fields are at the same offsets of the object if its base
    declares them, so they go to the base's fields (unless they conflict), and
    an override's signature to the base's family (unless it has another).
    A field may point to a placeholder struct: the base declares it, named
    after itself. One whose return or parameter type or body (a local's type)
    names it stays out."""
    r = d.base
    if r is None or r.table is not None or r.ext is not None:
        return
    family = families.setdefault(r.v.addr, r.sigs)
    n = len(r.v.slots)
    for x in sorted(xs, key=lambda y: y.slot):
        lf = x.lifted
        if lf.prefix and any(lf.prefix + "_" in t for t in (lf.rtype, *lf.params, lf.body)):
            continue
        sig = signature(x)
        if x.slot < n and family.get(x.slot, sig) != sig:
            continue
        if not merge_fields(r.fields, x.lifted.fields):
            continue
        if x.slot < n:
            family[x.slot] = sig
        else:
            d.sigs[x.slot] = sig
        d.members.append(x)


def _derive(m: Model, d: ClassSpec, specs: dict[int, ClassSpec], own, guess, has_secondary, families, seg,
            pickable) -> bool:
    """Model d as derived from its base (class_specs), if it is one."""
    a, v = d.v.addr, d.v
    if v.offset_to_top != 0 or a in has_secondary or d.pair != "empty" or len(v.slots) < 2:
        return False
    s0, s1 = v.slots[:2]
    if own.get(s0, (None,))[0] == a or own.get(s1) != (a, 1) or not pickable(s1):
        return False
    r = specs.get(own.get(s0, (None,))[0])
    if r is None or guess.get(a, (None,))[0] != r.v.addr or not any(x.kind == "dtor" for x in r.members):
        return False
    order = derived_order(v, r.v, d.members, seg)
    if order is None:
        return False
    inline = seg(r.v.slots[0]) != seg(s1)
    if inline and not r.inline_dtor:
        key = next((i for i in range(2, len(r.v.slots)) if isinstance(r.v.slots[i], int)), None)
        if key is None or not any(x.slot == key and seg(x.addr) == seg(r.v.slots[0]) for x in r.members):
            return False
    family = families.setdefault(r.v.addr, r.sigs)
    mine = {x.slot: sig for x in d.members if (sig := signature(x)) is not None and x.slot < len(r.v.slots)}
    if any(family.get(i, t) != t for i, t in mine.items()):
        return False
    family.update(mine)
    d.base, d.order = r, order
    d.members = [*d.members, Member(1, s1, "d0")]
    r.inline_dtor |= inline
    return True


def render_class(m: Model, spec: ClassSpec,
                 here: list[Member] | None = None) -> tuple[str, list[tuple[int, str]], str]:
    """(class declaration, [(function, mangled name)], definitions).

    The declaration comes from the spec alone, so that every file declaring
    the class declares it the same way; only `here` (default: all of its
    members) are defined, and named."""
    if spec.ext is not None:
        return render_external(m, spec, spec.members if here is None else here)
    v, cls, base = spec.v, spec.name, spec.base
    defined = {x.slot: x for x in (spec.members if here is None else here)}
    decl = [f"class {cls} : public {base.name} {{" if base else f"class {cls} {{", "public:"]
    names: list[tuple[int, str]] = []
    defs: list[str] = []
    if base is not None:
        slots = spec.order
        if 1 in defined:  # implicit: the D2 is the base's, the D0 comes with the vtable
            names.append((v.slots[1], mangle(cls, "D0")))
    else:
        slots = list(range(2 if spec.pair is not None else 0, len(v.slots)))
        if spec.pair is not None:
            decl.append(f"    virtual ~{cls}() {{}}" if spec.inline_dtor else f"    virtual ~{cls}();")
            if 0 in defined:
                if not spec.inline_dtor:
                    defs.append(f"// 0x{v.slots[0] + BASE:x}, 0x{v.slots[1] + BASE:x}\n{cls}::~{cls}() {{}}")
                names += [(v.slots[0], mangle(cls, "D2")), (v.slots[1], mangle(cls, "D0"))]
    for i in slots:
        f = v.slots[i]
        rt, params = spec.sigs.get(i, ("void", ()))
        ps = ", ".join(params)
        sig = (f"{rt} vf{i}({ps}) override" if base is not None and i < len(base.v.slots)
               else f"virtual {rt} vf{i}({ps})")
        if isinstance(f, str):
            decl.append(f"    {sig} = 0;")
            continue
        decl.append(f"    {sig};")
        x = defined.get(i)
        if x is None or signature(x) is None:
            continue
        if x.kind == "lifted":
            body = "{\n" + x.lifted.named(x.lifted.body, cls) + "}"
        elif x.kind == "element":
            body = f"{{\n    return m_entries[index].field_{x.value[1] - 8:x};\n}}"
        elif x.kind == "element_call":
            o, a = x.value[1] - 8, x.value[2] - 8
            body = (f"{{\n    if ({cls}_Obj* obj = m_entries[index].field_{o:x})\n"
                    f"        obj->vf{spec.table.obj_slot}(m_entries[index].field_{a:x});\n}}")
        elif x.kind == "forward":
            body = f"{{\n    {callee_name(x.value)[0]}(this);\n}}"
        else:
            body = simple_body(x)
        defs.append(f"// 0x{f + BASE:x}\n{rt} {cls}::vf{i}({ps}) {body}")
        codes = x.lifted.codes if x.kind == "lifted" else "m" if x.kind in ("element", "element_call") else "v"
        names.append((f, mangle(cls, f"vf{i}", codes)))
        if x.kind == "forward":
            names.append((x.value, callee_name(x.value)[1]))
        if x.kind == "lifted" and x.lifted.callee is not None:
            names.append(tail_callee(x.lifted.callee))
    decl += field_lines(spec.fields, cls, 8)  # after the vptr
    pre = structs(spec.fields, cls)
    if spec.table is not None:
        pre += table_structs(spec.table, cls)
        decl.append(f"    {cls}_Entry m_entries[{spec.table.count}];")
    decl.append("};")
    decl += [f"PKMN_OFFSET_ASSERT({cls}, field_{off:x}, 0x{off:x});" for off in sorted(spec.fields)]
    if spec.table is not None:
        decl.append(f"PKMN_OFFSET_ASSERT({cls}, m_entries, 0x8);")
    return "\n".join(pre + decl) + "\n", names, "\n\n".join(defs) + "\n"


def table_structs(t: Table, cls: str) -> list[str]:
    """The entry struct of a class's table, and the class of its entries'
    objects when an element member calls one."""
    out = []
    if t.obj_slot is not None:
        out += [f"class {cls}_Obj {{", "public:", *(f"    virtual void vf{i}();" for i in range(t.obj_slot)),
                f"    virtual void vf{t.obj_slot}(u64 value);", "};", ""]
    lines, pos = [f"struct {cls}_Entry {{"], 0
    for off, kind in sorted(t.fields.items()):
        if off > pos:
            lines.append(f"    u8 _{pos:x}[0x{off - pos:x}];")
        lines.append(f"    {dict(obj=f'{cls}_Obj*').get(kind, kind)} field_{off:x};")
        pos = off + 8
    if pos < t.stride:
        lines.append(f"    u8 _{pos:x}[0x{t.stride - pos:x}];")
    return out + lines + ["};", f"PKMN_SIZE_ASSERT({cls}_Entry, 0x{t.stride:x});", ""]


def field_lines(fields: dict, name: str, pos: int, scalar_from: int | None = None) -> list[str]:
    """The members of the placeholder class or struct `name`, from offset
    `pos`: padding, then each field (a pointer field points to `<name>_<offset>`).
    Padding from `scalar_from` on is u64 fields where it's 8-aligned, not
    bytes (see tail_padding_start)."""
    out = []

    def pad(a: int, b: int) -> None:
        s = b if scalar_from is None else min(b, max(a, scalar_from + -scalar_from % 8))
        if s % 8 or b % 8:
            s = b
        if s > a:
            out.append(f"    u8 _{a:x}[0x{s - a:x}];")
        out.extend(f"    u64 _{o:x};" for o in range(s, b, 8))

    for off, t in sorted(fields.items()):
        if off > pos:
            pad(pos, off)
        out.append(f"    {t if isinstance(t, str) else f'{name}_{off:x}*'} field_{off:x};")
        pos = off + _width(t)
    return out


def tail_padding_start(fields: dict) -> int | None:
    """Where the padding of a class on a hand-written base becomes u64 fields:
    0x50 bytes before its end. A destructor thunk passes `this - 0x48` (or
    `- 0x50`) on as the class, and InstCombine rewrites that pointer as an
    element of X[-1] at `sizeof(X) - 0x48`: on a field, the members are
    addressed from it, as the originals' thunks do; inside a byte array, they
    fold into one index from the thunk's own `this` (docs/game_code.md,
    Batch 9)."""
    if not fields:
        return None
    return max(off + _width(t) for off, t in fields.items()) - 0x50


def structs(fields: dict, name: str) -> list[str]:
    """Definitions of the structs the pointer fields of `name` point to, each
    before the struct that points to it."""
    out = []
    for off, t in sorted(fields.items()):
        if isinstance(t, dict):
            sub = f"{name}_{off:x}"
            out += structs(t, sub)
            out += [f"struct {sub} {{", *field_lines(t, sub, 0), "};",
                    *(f"PKMN_OFFSET_ASSERT({sub}, field_{o:x}, 0x{o:x});" for o in sorted(t)), ""]
    return out


def render_external(m: Model, spec: ClassSpec, here: list[Member]) -> tuple[str, list[tuple[int, str]], str]:
    """render_class for a class derived from a hand-written base."""
    cls, e = spec.name, spec.ext
    decl = [f"class {cls} : public {e.name} {{", "public:"]
    names: list[tuple[int, str]] = []
    defs: list[str] = []
    inter = next((x.value for x in spec.members if x.kind == "ext_type" and isinstance(x.value, tuple)), None)
    parent = e.get_type
    if inter is not None:
        # A class between the base and this one, whose getter this one's
        # inlines: only that getter is known, named after its type object.
        _, it, above, getter = inter
        it_parent = e.get_type
        pre = []
        if above is not None:
            # and the class above it, whose getter is out of line
            it_parent = f"Unk_{above:x}::Unk_GetType"
            pre = [f"// A class on {e.name} whose type getter (0x{getter + BASE:x}) is out of line.",
                   f"struct Unk_{above:x} {{", f"    static {TYPE} Unk_GetType();", "};", ""]
            names.append((getter, mangle(f"Unk_{above:x}", "Unk_GetType")))
        elif it is None and getter is not None:
            names.append((getter, getter_name(e.get_type)))  # the base's own, out of line
        if it is None:  # directly on that class
            parent = it_parent
            decl[:0] = pre
        else:
            parent = f"Unk_{it:x}::Unk_GetType"
            decl[:0] = [*pre, f"// The type between {e.name} and {cls} (its class isn't known yet).",
                        f"struct Unk_{it:x} {{", f"    static {TYPE} Unk_GetType() {{",
                        f"        static Unk_239a418_Type type({it_parent}());", "        return &type;", "    }",
                        "};", ""]
    own_type = next((x.value for x in spec.members if x.kind == "ext_getter" and x.value), None)
    if own_type is not None:
        # Its getter, which other classes' getters call: named after its type
        # object, as they name it (they can't name this class). Inline, like
        # Unk_23d4470's (render_file moves it to the top of the file).
        decl[:0] = [f"// The type of {cls}: other classes' getters call its getter.",
                    f"struct Unk_{own_type:x} {{", f"    static {TYPE} Unk_GetType() {{",
                    f"        static Unk_239a418_Type type({parent}());", "        return &type;", "    }",
                    "};", ""]
    elif e.type_slot in spec.order:
        # Its type, whose parent is the base's: inline, but too big to be
        # inlined into vf_type, which tail-calls it.
        decl += [f"    static {TYPE} Unk_GetType() {{", f"        static Unk_239a418_Type type({parent}());",
                 "        return &type;", "    }", ""]
    inline_type = any(x.kind == "ext_type" and x.value is None for x in spec.members)
    for i in spec.order:
        if i == e.type_slot:
            decl.append(f"    {TYPE} vf_type() override {{ return Unk_GetType(); }}" if inline_type
                        else f"    {TYPE} vf_type() override;")
            continue
        base_slot = any(j == i for j, _, _ in e.slots)
        rt, params = (e.slot(i)[0], ()) if base_slot else spec.sigs.get(i, ("void", ()))
        decl.append(f"    {rt} {e.slot(i)[1]}() override;" if base_slot else
                    f"    virtual {rt} vf{i}({', '.join(params)});")
    if spec.fields:
        decl += field_lines(spec.fields, cls, e.size, tail_padding_start(spec.fields) if spec.scalar_tail else None)
    decl.append("};")
    if spec.fields:
        decl[:0] = structs(spec.fields, cls)
        decl += [f"PKMN_OFFSET_ASSERT({cls}, field_{o:x}, 0x{o:x});" for o in sorted(spec.fields)]
    for x in sorted(here, key=lambda x: (x.kind != "ext_getter", x.addr)):  # the getter before its use
        if x.kind == "d2":
            names.append((x.addr, mangle(cls, "D2")))
        elif x.kind == "d0":
            names.append((x.addr, mangle(cls, "D0")))
        elif x.kind == "ext_thunk":
            off, which = x.value
            inner = f"{len(cls)}{cls}" + (which if which in ("D0", "D1") else f"{len(which)}{which}")
            names.append((x.addr, f"_ZThn{off}_N{inner}Ev"))
        elif x.kind == "ext_getter" and x.value:  # inline in its struct, emitted where vf_type calls it
            names.append((x.addr, mangle(f"Unk_{x.value:x}", "Unk_GetType")))
        elif x.kind == "ext_getter":  # Unk_GetType, emitted where vf_type calls it
            names.append((x.addr, mangle(cls, "Unk_GetType")))
        elif x.kind == "ext_type":
            if x.value is not None:     # out of line, its key function; inline in the class otherwise
                where = f"; its type 0x{x.value + BASE:x}" if isinstance(x.value, int) else ""
                getter = "Unk_GetType" if own_type is None else f"Unk_{own_type:x}::Unk_GetType"
                defs.append(f"// 0x{x.addr + BASE:x}{where}\n{TYPE} {cls}::vf_type() {{\n"
                            f"    return {getter}();\n}}")
            names.append((x.addr, mangle(cls, "vf_type")))
        elif x.kind == "lifted":
            name = e.slot(x.slot)[1]
            defs.append(f"// 0x{x.addr + BASE:x}\n{x.lifted.rtype} {cls}::{name}({', '.join(x.lifted.params)}) "
                        f"{{\n{x.lifted.named(x.lifted.body, cls)}}}")
            names.append((x.addr, mangle(cls, name, x.lifted.codes)))
            if x.lifted.callee is not None:
                names.append(tail_callee(x.lifted.callee))
        else:
            rt, name = RTYPE[x.kind], e.slot(x.slot)[1]
            if x.kind == "forward":
                body = f"{{\n    {callee_name(x.value)[0]}(this);\n}}"
                names.append((x.value, callee_name(x.value)[1]))
            else:
                body = simple_body(x)
            defs.append(f"// 0x{x.addr + BASE:x}\n{rt} {cls}::{name}() {body}")
            names.append((x.addr, mangle(cls, name)))
    return "\n".join(decl) + "\n", names, "\n\n".join(defs) + "\n"


GETTER_STRUCT = re.compile(r"(// .*\n)struct (Unk_[0-9a-f]+) \{\n    static .* Unk_GetType\(\);\n\};\n\n")
# A class's own type, defined in a struct named after the type object (render_external).
TYPE_STRUCT = re.compile(r"// The type of .*\nstruct Unk_[0-9a-f]+ \{\n    static .* Unk_GetType\(\) \{\n(?:.*\n)*?\};\n\n")


def render_file(m: Model, entries: list[tuple[ClassSpec, list[Member]]],
                source: str | None = None) -> tuple[str, list[tuple[int, str]]]:
    """One file's source and names: its classes in address order of what they
    define here, each base declared before its first derived class."""
    parts = ["// Scope: common",
             "// Simple virtual functions between two static initialisers (one or more TUs).",
             "// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename",
             "// them, and give the functions real signatures, once the classes are known.",
             "#include <types.h>", ""]
    headers = sorted({spec.ext.header for spec, _ in entries if spec.ext is not None}
                     | ({CALLABLE_HEADER} if any(CALLABLE in spec.fields.values() for spec, _ in entries) else set()))
    if headers:
        parts[-1:] = [*(f'#include "{h}"' for h in headers), ""]
    if source:  # the base's own definitions: one TU with the classes derived from it
        parts += [f'#include "{source}"', ""]
    callees = sorted({x.value for _, xs in entries for x in xs if x.kind == "forward"})
    if callees:
        parts += ["// Called by forwarders. Placeholders: their real signatures aren't known.",
                  *(f"void {callee_name(t)[0]}(void* self);" for t in callees), ""]
    tails = sorted({x.lifted.callee for _, xs in entries for x in xs
                    if x.kind == "lifted" and x.lifted.callee is not None} - {(t, ("void*",)) for t in callees})
    if tails:
        parts += ["// Tail-called by lifted functions. Placeholders, like the forwarders' callees.",
                  *(f"void {callee_name(t)[0]}({', '.join(types)});" for t, types in tails), ""]
    externs = sorted({g for _, xs in entries for x in xs if x.kind == "lifted" for g in x.lifted.globals})
    if externs:
        parts += ["// Globals other TUs define, named after their addresses.",
                  *(f"extern {t} Unk_{a:x};" for a, t in externs), ""]
    here = {spec.v.addr: xs for spec, xs in entries}
    done: set[int] = set()
    names: list[tuple[int, str]] = []

    # A getter's placeholder struct is declared by each class that calls it:
    # only the file's first declares it, and none where the file defines it
    # (the class whose getter it is: its struct goes before every class).
    declared = {f"Unk_{x.value:x}" for _, xs in entries for x in xs if x.kind == "ext_getter" and x.value}
    top = len(parts)

    def once(match: re.Match) -> str:
        if match[2] in declared:
            return ""
        declared.add(match[2])
        return match[0]

    def emit(spec: ClassSpec) -> None:
        if spec.v.addr in done:
            return
        if spec.base is not None:
            emit(spec.base)
        done.add(spec.v.addr)
        decl, ns, defs = render_class(m, spec, here.get(spec.v.addr, []))
        decl = GETTER_STRUCT.sub(once, decl)
        for match in TYPE_STRUCT.finditer(decl):
            parts.insert(top, match[0])
        parts.append(TYPE_STRUCT.sub("", decl))
        if defs.strip():
            parts.append(defs)
        names.extend(ns)

    for spec, _ in sorted(entries, key=lambda e: min(x.addr for x in e[1])):
        emit(spec)
    return "\n".join(parts).rstrip("\n") + "\n", names


def segment_starts(m: Model) -> list[int]:
    """Where the static-initialiser segments of Sword's code start (tools/segments.py)."""
    import segments
    from common import load_module, nso_path
    from nx.module import DynInfo
    from nx.nso import Nso

    nso = Nso(nso_path("sword").read_bytes())
    dyn = DynInfo(nso, m.img, load_module("sword")["text_end"])
    inits = set(segments.init_array_targets(segments.dynamic_tags(m.img, nso.mod0.dynamic), dyn.slots))
    starts = [s for s, _ in m.funcs]
    return sorted({starts[i + 1] for i, s in enumerate(starts[:-1]) if s in inits} | {0})


# --------------------------------------------------------------------------- constructors
# `Derived::Derived() : Base() {}` for a polymorphic class with nothing else to
# initialise: call the base's constructor, then store the class's vptr (its
# _ZTV, from the GOT, + 16).
CTOR_PATTERN = ("str x19, [sp, #N]! ; stp x29, x30, [sp, #N] ; add x29, sp, #N ; mov x19, x0 ; bl T ; "
                "adrp x8, #N ; ldr x8, [x8, #N] ; add x8, x8, #N ; str x8, [x19] ; ldp x29, x30, [sp, #N] ; "
                "ldr x19, [sp], #N ; ret")
ROOT_CTOR_PATTERN = "adrp x8, #N ; ldr x8, [x8, #N] ; add x8, x8, #N ; str x8, [x0] ; ret"  # no base
CTOR_DIR = ROOT / "src" / "unsorted" / "ctor"
_CLASS_DEF = re.compile(r"^(?:class|struct) (Unk_[0-9a-f]+)\b", re.M)


def ctor_name(cls: str) -> str:
    """The base-object constructor (C2; the complete one, C1, is its alias)."""
    return f"_ZN{len(cls)}{cls}C2Ev"


def defined_classes(root: Path, skip: Path | None = None) -> set[str]:
    """The placeholder classes the sources under root define, outside `skip`."""
    out: set[str] = set()
    for f in root.rglob("*"):
        if f.suffix in (".cpp", ".h", ".inl") and (skip is None or skip not in f.parents):
            out |= set(_CLASS_DEF.findall(f.read_text(encoding="utf-8")))
    return out


@dataclass(frozen=True)
class Ctor:
    addr: int       # the constructor
    base_ctor: int | None  # what it calls first (None: a class without a base)
    cls: str
    base: str | None
    fields: tuple = ()  # ((offset, type), ...): the fields it zeroes, after the base


ZERO_STORES = {("str", "xzr"): ("u64",), ("str", "wzr"): ("u32",), ("strh", "wzr"): ("u16",),
               ("strb", "wzr"): ("u8",), ("stp", "xzr"): ("u64", "u64")}


def ctor_fields(m: Model, f: int) -> tuple | None:
    """The fields a CTOR_PATTERN constructor with zeroed fields zeroes:
    `bl <base> ; adrp x8 ; ldr x8` (the _ZTV) then `str/stp xzr|wzr, [x19, #N]`
    stores around the vptr's `add x8, x8, #16 ; str x8, [x19]`. None if it's
    another shape."""
    import leafgen as L

    n = m.sizes.get(f, 0)
    if not 52 <= n <= 96:
        return None
    try:
        insns = L.disassemble(m.img[f:f + n], f + BASE)
    except L.LiftError:
        return None
    head = [mn for mn, _ in insns[:7]]
    tail = [mn for mn, _ in insns[-3:]]
    if head != ["str", "stp", "add", "mov", "bl", "adrp", "ldr"] or tail != ["ldp", "ldr", "ret"] \
            or insns[3][1] != ["x19", "x0"] or insns[5][1][0] != "x8" or insns[6][1][0] != "x8":
        return None
    fields, vptr = [], 0
    for mn, ops in insns[7:-3]:
        if mn == "add" and ops[:2] == ["x8", "x8"] and ops[2] == "#0x10":
            continue
        if mn == "str" and ops == ["x8", "[x19]"]:
            vptr += 1
            continue
        m_ = re.fullmatch(r"\[x19, #(0x[0-9a-f]+|\d+)\]", ops[-1])
        key = (mn, ops[0])
        if m_ is None or key not in ZERO_STORES or (mn == "stp" and ops[1] != "xzr"):
            return None
        off = int(m_.group(1), 0)
        for i, t in enumerate(ZERO_STORES[key]):
            fields.append((off + 8 * i, t))
    if vptr != 1 or not fields:
        return None
    return tuple(sorted(fields))

def find_ctors(m: Model, rows: dict, taken: set[str]) -> list[Ctor]:
    """The constructors of CTOR_PATTERN: common, unnamed and U in both games;
    the function a referrer of one vtable group only (its class's) and the base
    constructor of another; neither group with a secondary vtable, a
    hand-written base, or a class defined elsewhere (`taken`). Both are
    unnamed and U, or named as constructors already (by an earlier run)."""
    from funcs import pattern_of

    by = {v.addr: v for v in m.vtables}
    refs: dict[int, set[int]] = defaultdict(set)
    for v in m.vtables:
        for f in v.referrers:
            refs[f].add(v.group)
    secondary = {v.group for v in m.vtables if v.group != v.addr}
    out = []
    for f, size in m.funcs:
        r = rows.get(f)
        if size == 20 and pattern_of(m.img[f:f + size], f + BASE) == ROOT_CTOR_PATTERN:
            # A class without a base: only its vptr to set.
            if r is None or r.scope != "common" or r.shield is None or len(refs[f]) != 1:
                continue
            (d,) = refs[f]
            cls = class_name(by[d])
            if d not in secondary | HANDWRITTEN and cls not in taken and \
                    (r.name == ctor_name(cls) or not r.name and r.status == "U"):
                out.append(Ctor(f, None, cls, None))
            continue
        fields = ()
        if size != 48 or pattern_of(m.img[f:f + size], f + BASE) != CTOR_PATTERN:
            fields = ctor_fields(m, f)
            if fields is None:
                continue
        t = branch_target_at(m, f + 16)
        rt = rows.get(t)
        if r is None or r.scope != "common" or r.shield is None:
            continue
        if rt is None or rt.scope != "common" or rt.shield is None or len(refs[f]) != 1 or len(refs[t]) != 1:
            continue
        (d,), (b,) = refs[f], refs[t]
        cls, base = class_name(by[d]), class_name(by[b])
        if d == b or {d, b} & (secondary | HANDWRITTEN) or {cls, base} & taken:
            continue
        # unnamed and undecompiled, or named so by an earlier run
        if not (r.name == ctor_name(cls) or not r.name and r.status == "U"):
            continue
        if not (rt.name == ctor_name(base) or not rt.name and rt.status == "U"):
            continue
        out.append(Ctor(f, t, cls, base, fields))
    # A class with more than one constructor (a copy constructor too, say) can't
    # have them both as C2: not the one it defines here and the one a derived
    # class calls, nor two that derived classes call.
    n = Counter(c.cls for c in out)
    called: dict[str, set[int]] = defaultdict(set)
    for c in out:
        if c.base is not None:
            called[c.base].add(c.base_ctor)
    two = {b for b, ts in called.items() if len(ts) > 1}
    return [c for c in out if n[c.cls] == 1 and c.base not in two and called.get(c.cls, {c.addr}) == {c.addr}]


def branch_target_at(m: Model, at: int) -> int | None:
    """The target of the b/bl at `at`."""
    w = struct.unpack_from("<I", m.img, at)[0]
    if w >> 26 not in (0b000101, 0b100101):
        return None
    return at + 4 * (((w & 0x3FFFFFF) ^ 0x2000000) - 0x2000000)


def ctor_layout(base_of: dict[str, str], fields_of: dict[str, tuple]) -> dict[str, int]:
    """Where each class's own fields may start: after its base's (8, the vptr,
    for a class without one)."""
    from leafgen import WIDTH

    end: dict[str, int] = {}

    def extent(c: str, depth: int = 0) -> int:
        if c not in end:
            start = extent(base_of[c], depth + 1) if c in base_of and depth < 32 else 8
            fs = fields_of.get(c, ())
            end[c] = max([start] + [o + WIDTH[t] for o, t in fs])
        return end[c]

    for c in set(base_of) | set(fields_of):
        extent(c)
    return end


def render_ctor_file(ctors: list[Ctor], base_of: dict[str, str], fields_of: dict[str, tuple] | None = None) -> str:
    """One TU of constructors, with the classes they need declared: each the
    same way in every file (from base_of and fields_of), bases first."""
    from leafgen import WIDTH

    fields_of = fields_of or {}
    out = ["// Scope: common",
           "// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.",
           "// Placeholder classes, named after their vtables: only what the constructors",
           "// need (a base constructor to call, and a key function elsewhere, so that the",
           "// vtable is another TU's).",
           ""]
    need: list[str] = []

    def add(c: str, seen: tuple = ()) -> None:
        if c in need or c in seen:
            return
        if c in base_of:
            add(base_of[c], seen + (c,))
        need.append(c)

    for c in sorted(ctors, key=lambda x: x.addr):
        add(c.cls)
    if any(c in fields_of for c in need):
        out[-1:] = ["#include <types.h>", ""]
    layout = ctor_layout(base_of, fields_of)
    for c in need:
        fs = fields_of.get(c, ())
        members = []
        pos = layout[base_of[c]] if c in base_of else 8
        for off, t in fs:
            if off > pos:
                members.append(f"    u8 _{pos:x}[0x{off - pos:x}];")
            members.append(f"    {t} field_{off:x};")
            pos = off + WIDTH[t]
        asserts = [f"PKMN_OFFSET_ASSERT({c}, field_{off:x}, 0x{off:x});" for off, _ in fs]
        if c in base_of:
            out += [f"class {c} : public {base_of[c]} {{", "public:", f"    {c}();", f"    ~{c}() override;",
                    *members, "};", *asserts, ""]
        else:
            out += [f"class {c} {{", "public:", f"    {c}();", f"    virtual ~{c}();", *members, "};", *asserts, ""]
    for c in sorted(ctors, key=lambda x: x.addr):
        init = ", ".join(f"field_{off:x}(0)" for off, _ in c.fields)
        out += [f"// {c.addr + BASE:#x}", f"{c.cls}::{c.cls}(){' : ' + init if init else ''} {{}}", ""]
    return "\n".join(out[:-1]) + "\n"


def cmd_ctors(m: Model, args) -> None:
    """Constructors of placeholder classes that only call their base's (find_ctors)."""
    from common import read_functions_csv

    rows = {f.sword: f for f in read_functions_csv() if f.sword is not None}
    taken = defined_classes(ROOT / "src", skip=args.out)
    ctors = find_ctors(m, rows, taken)
    if args.only:
        only = {int(x, 16) - BASE for x in args.only.read_text(encoding="utf-8").split()}
        ctors = [c for c in ctors if c.addr in only]
    base_of = {c.cls: c.base for c in ctors if c.base is not None}
    fields_of = {c.cls: c.fields for c in ctors if c.fields}
    # A class's fields go after its base's: a constructor that zeroes one
    # inside them (the base's own) is left out.
    layout = ctor_layout(base_of, fields_of)
    bad = {c for c, fs in fields_of.items() if fs[0][0] < (layout[base_of[c]] if c in base_of else 8)}
    if bad:
        ctors = [c for c in ctors if c.cls not in bad and c.base not in bad]
        base_of = {c.cls: c.base for c in ctors if c.base is not None}
        fields_of = {c.cls: c.fields for c in ctors if c.fields}
    seg_starts = segment_starts(m)

    def seg_of(a: int) -> int:
        return seg_starts[bisect.bisect_right(seg_starts, a) - 1]

    # A base's constructor in the same file as one that calls it would be
    # inlined there; the original calls it, so it's another TU's: leave it out.
    called_here = {(seg_of(c.addr), c.base) for c in ctors if c.base is not None}
    ctors = [c for c in ctors if (seg_of(c.addr), c.cls) not in called_here]
    files: dict[int, list[Ctor]] = defaultdict(list)
    for c in ctors:
        files[seg_of(c.addr)].append(c)
    args.out.mkdir(parents=True, exist_ok=True)
    for old in args.out.glob("*.cpp"):
        old.unlink()
    for cs in files.values():
        name = f"Unk_{min(c.addr for c in cs):x}.cpp"
        (args.out / name).write_text(render_ctor_file(cs, base_of, fields_of), encoding="utf-8", newline="\n")
    from common import clang_format
    if not clang_format(sorted(args.out.glob("*.cpp"))):
        print("clang-format isn't on PATH: format the written files before committing them", file=sys.stderr)
    names: dict[int, str] = {}
    for c in ctors:
        names[c.addr] = ctor_name(c.cls)
        if c.base is not None and not rows[c.base_ctor].name:
            names[c.base_ctor] = ctor_name(c.base)
    with open(args.names, "w", encoding="utf-8", newline="\n") as fh:
        fh.write("Name,Sword,Shield\n")
        for a, n in sorted(names.items()):
            fh.write(f"{n},{rows[a].sword_str},{rows[a].shield_str}\n")
    print(f"{len(ctors)} constructors ({sum(c.base is None for c in ctors)} without a base) in {len(files)} files; "
          f"{len(names)} names in {args.names}", file=sys.stderr)


def cmd_write(m: Model, args) -> None:
    """Placeholder classes for the simple virtual functions of game code."""
    from common import in_area, read_functions_csv

    rows = {f.sword: f for f in read_functions_csv() if f.sword is not None}

    def pickable(f: int) -> bool:
        r = rows.get(f)
        return r is not None and r.status == "U" and not r.name and r.scope == "common"

    holders: dict[int, set[str]] = defaultdict(set)
    by_addr = {v.addr: v for v in m.vtables}
    for v in m.vtables:
        for f in v.slots:
            holders[f] |= {class_name(v), class_name(by_addr[v.group])}  # a secondary's: its group's too

    def written(f: int) -> bool:
        """Picked again: unnamed and undecompiled, or named by an earlier write
        (a member of the class of a vtable that holds it)."""
        r = rows.get(f)
        if pickable(f):
            return True
        w = WRITTEN.fullmatch(r.name) if r is not None and r.scope == "common" else None
        return w is not None and w.group(1) in holders[f]

    def callee(f: int) -> int | None:
        """A forwarder's target, if it can be the placeholder `Unk_<T>(void*)`:
        in both games, in no vtable (a virtual function is called by its
        class's name), not operator delete, and unnamed (or named that)."""
        t = branch_target(m, f)
        r = rows.get(t)
        if t is None or t in holders or t == m.delete or r is None or r.shield is None:
            return None
        return t if not r.name or r.name == callee_name(t)[1] else None

    # --only: of the functions not named yet, only these (the ones that matched in a trial run).
    only = {int(x, 16) - BASE for x in args.only.read_text(encoding="utf-8").split()} if args.only else None

    # The functions of the hand-written classes' vtables are theirs, whatever
    # vtable the owner heuristic gives them to.
    handwritten = {f for v in m.vtables if v.group in HANDWRITTEN for f in v.slots}
    # The constructor files' classes (cmd_ctors), declared there for a
    # constructor only, aren't written here. (What their vtables inherit still
    # is, by the classes that own it.)
    ctor_classes = defined_classes(CTOR_DIR) if CTOR_DIR.exists() else set()
    skipped = HANDWRITTEN | {v.addr for v in m.vtables if class_name(v) in ctor_classes}

    def kept(f: int) -> bool:
        return written(f) and f not in handwritten and (only is None or f in only or bool(rows[f].name))

    own = owners(m.vtables)
    groups = args.area or ["game", "gflib3", "gflnet3", "startup"]
    picked: dict[int, list[Member]] = {}
    for v in m.vtables:
        if not any(in_area(vtable_area(m, v), g) for g in groups) or v.group in skipped:
            continue
        members = placeholder_members(m, v, own, kept, None if args.no_forward else callee,
                                      None if args.no_lift else (lambda f: lift_member(m, f)),
                                      not args.no_elements)
        if members:
            picked[v.addr] = members
    seg_starts = segment_starts(m)

    def seg(f: int) -> int:
        return seg_starts[bisect.bisect_right(seg_starts, f) - 1]

    def getter_ok(t: int) -> bool:
        """A derived class's type getter: unnamed, or named as a forwarder's
        callee (`Unk_<T>(void*)`) or as the getter (`Unk_<T>()`)."""
        r = rows.get(t)
        if r is None or r.shield is None or r.scope != "common":
            return False
        name = callee_name(t)[0]
        named = r.name in (f"_Z{len(name)}{name}Pv", f"_Z{len(name)}{name}v") or (
            r.name.endswith("11Unk_GetTypeEv") and WRITTEN.fullmatch(r.name) is not None)
        return (not r.name or named) and \
            (only is None or t in only or bool(r.name))

    # A lifted member's tail call: its target in no vtable, unnamed or named as
    # this callee, and called with the same types by every caller (forwarders
    # call theirs with one void*).
    sigs: dict[int, set] = defaultdict(set)
    for ms in picked.values():
        for x in ms:
            if x.kind == "forward":
                sigs[x.value].add(("void*",))
            elif x.kind == "lifted" and x.lifted.callee is not None:
                sigs[x.lifted.callee[0]].add(x.lifted.callee[1])

    def tail_ok(c: tuple) -> bool:
        t = c[0]
        r = rows.get(t)
        return (t not in holders and r is not None and r.shield is not None and len(sigs[t]) == 1
                and (not r.name or r.name == tail_callee(c)[1]))

    # A global is read or written with one type by every lifted member.
    gtypes: dict[int, set] = defaultdict(set)
    for ms in picked.values():
        for x in ms:
            if x.kind == "lifted":
                for g, t in x.lifted.globals:
                    gtypes[g].add(t)

    def lifted_ok(x: Member) -> bool:
        return x.kind != "lifted" or ((x.lifted.callee is None or tail_ok(x.lifted.callee))
                                      and all(len(gtypes[g]) == 1 for g, _ in x.lifted.globals))

    for a, ms in list(picked.items()):
        picked[a] = [x for x in ms if lifted_ok(x)]
        if not picked[a]:
            del picked[a]
    specs = class_specs(m, picked, own, seg, kept, getter_ok)
    # One file per static-initialiser segment, like src/unsorted/leaf: a class
    # whose functions span segments is declared in each of their files.
    # A class derived from a hand-written base with a type getter of its own
    # gets a file of its own: its base's getter is inlined into its getter
    # only when that is the base getter's one caller in the TU.
    # A class whose getter other classes call shares its file with those in
    # its segment (else clang inlines the getter: derive_external).
    owner_of = {x.addr: spec.v.addr for spec in specs.values() for x in spec.members
                if x.kind == "ext_getter" and x.value}
    files: dict[tuple[int, int], list[tuple[ClassSpec, list[Member]]]] = defaultdict(list)
    for spec in specs.values():
        own_file = spec.ext is not None and spec.ext.type_slot in spec.order and not spec.ext.shared_tu
        on = next((x.value[3] for x in spec.members if x.kind == "ext_type" and isinstance(x.value, tuple)
                   and x.value[3] in owner_of and seg(x.value[3]) == seg(x.addr)), None)
        by_seg: dict[int, list[Member]] = defaultdict(list)
        for x in spec.members:
            by_seg[seg(x.addr)].append(x)
        for s, xs in by_seg.items():
            key = owner_of[on] if on is not None and s == seg(on) else spec.v.addr if own_file else 0
            files[(s, key)].append((spec, xs))
    out_dir = args.out
    out_dir.mkdir(parents=True, exist_ok=True)
    for old in out_dir.glob("Unk_*.cpp"):  # everything here is written again (a file's name can change)
        old.unlink()
    # A shared TU's file includes its base's hand-written definitions.
    by_addr = {v.addr: v for v in m.vtables}
    sources = {(seg(by_addr[e.vtable].slots[0]), 0): e.source for e in EXTERNAL_BASES
               if e.source and e.vtable in by_addr}
    name_rows: dict[int, str] = {}  # a forwarders' callee is named once
    for key, entries in sorted(files.items()):
        first = min(x.addr for _, xs in entries for x in xs)
        text, names = render_file(m, entries, sources.get(key))
        name_rows.update(names)
        (out_dir / f"Unk_{first:x}.cpp").write_text(text, encoding="utf-8", newline="\n")
    from common import clang_format
    if not clang_format(sorted(out_dir.glob("Unk_*.cpp"))):
        print("clang-format isn't on PATH: format the written files before committing them", file=sys.stderr)
    with open(args.names, "w", encoding="utf-8", newline="\n") as fh:
        fh.write("Name,Sword,Shield\n")
        for f, n in sorted(name_rows.items()):
            r = rows[f]
            fh.write(f"{n},{r.sword_str},{r.shield_str}\n")
    derived = sum(s.base is not None for s in specs.values())
    n_callees = len({x.value for s in specs.values() for x in s.members if x.kind == "forward"})
    n_ext = sum(s.ext is not None for s in specs.values())
    print(f"{len(name_rows) - n_callees} functions of {len(specs)} classes ({derived} derived, "
          f"{sum(s.inline_dtor for s in specs.values())} bases with an inline destructor, {n_ext} derived from "
          f"hand-written bases) in {len(files)} files, {n_callees} forwarders' callees; names in {args.names}",
          file=sys.stderr)


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--game", choices=VERSIONS, default="sword")
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("summary")
    p.add_argument("--area", help="only vtables in this area or group (by their functions)")
    p = sub.add_parser("show")
    p.add_argument("addr")
    p = sub.add_parser("of")
    p.add_argument("addr")
    p = sub.add_parser("csv")
    p.add_argument("out", type=Path)
    p = sub.add_parser("write", help="placeholder classes for simple virtual functions (Sword's vtables)")
    p.add_argument("--area", action="append", help="area or group (default: game, gflib3, gflnet3, startup)")
    p.add_argument("--out", type=Path, default=ROOT / "src" / "unsorted" / "virtual")
    p.add_argument("--names", type=Path, required=True, help="where to write Name,Sword,Shield")
    p.add_argument("--only", type=Path, help="file of Sword addresses: of the unnamed functions, write only these")
    p.add_argument("--no-forward", action="store_true", help="leave out forwarders (b T)")
    p.add_argument("--no-lift", action="store_true", help="leave out what leafgen.py lifts")
    p.add_argument("--no-elements", action="store_true", help="leave out element members (entry arrays)")
    p = sub.add_parser("ctors", help="constructors that only call their base's (Sword's vtables)")
    p.add_argument("--out", type=Path, default=CTOR_DIR)
    p.add_argument("--names", type=Path, required=True, help="where to write Name,Sword,Shield")
    p.add_argument("--only", type=Path, help="file of Sword addresses: write only these constructors")
    args = ap.parse_args(argv)
    if args.cmd in ("write", "ctors") and args.game != "sword":
        raise SystemExit("write works from Sword's vtables (the names cover both games)")
    m = load(args.game)
    {"summary": cmd_summary, "show": cmd_show, "of": cmd_of, "csv": cmd_csv, "write": cmd_write,
     "ctors": cmd_ctors}[args.cmd](m, args)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
