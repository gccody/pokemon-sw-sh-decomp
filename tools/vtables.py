#!/usr/bin/env python3
"""Find the vtables in `main` and group them into classes.

    python tools/vtables.py summary                     # counts, per area, and what the slots hold
    python tools/vtables.py summary --area game/pokecamp
    python tools/vtables.py show 0x71024a6390           # one vtable group: slots, patterns, referrers
    python tools/vtables.py of 0x7100dee870             # the vtables a function is in, and its slot
    python tools/vtables.py csv vtables.csv             # one row per vtable

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
                 {f.addr(game): f.status for f in rows}, AreaMap(read_areas_csv(), game).area_of, delete)


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


RTYPE = {"ret": "void", "constant": "u32", "zero": "u32", "null": "void*", "forward": "void"}
WRITTEN = re.compile(r"_ZN\d+(Unk_[0-9a-f]+)(?:D0|D2|\d+vf\d+)E[a-z]+")  # the names write gives


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

    @property
    def name(self) -> str:
        return class_name(self.v)


def signature(x: Member, cls: str = "") -> tuple[str, tuple[str, ...]] | None:
    """(return type, parameters) of a member write defines, None for destructors
    (a lifted one's struct names are its class's, `cls`)."""
    if x.kind == "lifted":
        return x.lifted.named(x.lifted.rtype, cls), x.lifted.params
    return (RTYPE[x.kind], ()) if x.kind in RTYPE else None


def _width(t) -> int:
    from leafgen import WIDTH
    return WIDTH[t] if isinstance(t, str) else 8


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

    if m.sizes.get(f, 0) > 32:
        return None
    try:
        lf = L.lift(m.img[f:f + m.sizes[f]])
        first = L.Emitter(f + BASE, lf)
        first.render()
        e = L.Emitter(f + BASE, lf)
        e.structs, e.arg_types, e.fp_types = first.structs, first.arg_types, first.fp_types
        _, func = e.render()
    except (L.LiftError, ValueError, KeyError):
        return None
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
    params = [p.strip() for p in x.group(2).split(",")]
    if not params[0].endswith(" self") and params[0] != "void* /*unused*/":
        return None
    params = params[1:]
    if any(p.split()[0] not in PARAM_CODES for p in params):
        return None
    rtype = x.group(1).replace("const ", "") if "*" in x.group(1) else x.group(1)
    return Lifted(rtype, tuple(params), x.group(3).replace("self->", ""), fields, f"Unk_{e.short}")


def placeholder_members(m: Model, v: Vtable, own: dict[int, tuple[int, int]], pickable,
                        callee=None, lifter=None) -> list[Member]:
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
        elif k in ("small", "other") and lifter is not None and (x := lifter(f)) is not None:
            out.append(Member(i, f, "lifted", lifted=x))
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
                seg, pickable) -> dict[int, ClassSpec]:
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
        s.sigs = {x.slot: sig for x in s.members if (sig := signature(x, s.name)) is not None}
    guess = bases(m.vtables)
    has_secondary = {v.group for v in m.vtables if v.group != v.addr}
    families: dict[int, dict[int, tuple[str, tuple[str, ...]]]] = {}
    for a, d in sorted(specs.items()):
        if any(x.kind == "lifted" for x in d.members):
            simple = ClassSpec(d.v, [x for x in d.members if x.kind != "lifted"], d.pair)
            if not _derive(m, simple, specs, own, guess, has_secondary, families, seg, pickable):
                continue
            specs[a] = d = simple
            d.sigs = {x.slot: sig for x in d.members if (sig := signature(x)) is not None}
        else:
            _derive(m, d, specs, own, guess, has_secondary, families, seg, pickable)
    for d in specs.values():
        if d.base is not None:
            n = len(d.base.v.slots)
            d.sigs = {**{i: t for i, t in d.sigs.items() if i >= n},
                      **{i: t for i, t in d.base.sigs.items() if i < n}}
    return specs


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
        elif x.kind == "forward":
            body = f"{{\n    {callee_name(x.value)[0]}(this);\n}}"
        else:
            body = {"ret": "{}", "constant": f"{{\n    return {x.value if x.value < 10 else hex(x.value)};\n}}",
                    "zero": "{\n    return 0;\n}", "null": "{\n    return nullptr;\n}"}[x.kind]
        defs.append(f"// 0x{f + BASE:x}\n{rt} {cls}::vf{i}({ps}) {body}")
        names.append((f, mangle(cls, f"vf{i}", x.lifted.codes if x.kind == "lifted" else "v")))
        if x.kind == "forward":
            names.append((x.value, callee_name(x.value)[1]))
    decl += field_lines(spec.fields, cls, 8)  # after the vptr
    decl.append("};")
    decl += [f"PKMN_OFFSET_ASSERT({cls}, field_{off:x}, 0x{off:x});" for off in sorted(spec.fields)]
    return "\n".join(structs(spec.fields, cls) + decl) + "\n", names, "\n\n".join(defs) + "\n"


def field_lines(fields: dict, name: str, pos: int) -> list[str]:
    """The members of the placeholder class or struct `name`, from offset
    `pos`: padding, then each field (a pointer field points to `<name>_<offset>`)."""
    out = []
    for off, t in sorted(fields.items()):
        if off > pos:
            out.append(f"    u8 _{pos:x}[0x{off - pos:x}];")
        out.append(f"    {t if isinstance(t, str) else f'{name}_{off:x}*'} field_{off:x};")
        pos = off + _width(t)
    return out


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


def render_file(m: Model, entries: list[tuple[ClassSpec, list[Member]]]) -> tuple[str, list[tuple[int, str]]]:
    """One file's source and names: its classes in address order of what they
    define here, each base declared before its first derived class."""
    parts = ["// Scope: common",
             "// Simple virtual functions between two static initialisers (one or more TUs).",
             "// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename",
             "// them, and give the functions real signatures, once the classes are known.",
             "#include <types.h>", ""]
    callees = sorted({x.value for _, xs in entries for x in xs if x.kind == "forward"})
    if callees:
        parts += ["// Called by forwarders. Placeholders: their real signatures aren't known.",
                  *(f"void {callee_name(t)[0]}(void* self);" for t in callees), ""]
    here = {spec.v.addr: xs for spec, xs in entries}
    done: set[int] = set()
    names: list[tuple[int, str]] = []

    def emit(spec: ClassSpec) -> None:
        if spec.v.addr in done:
            return
        if spec.base is not None:
            emit(spec.base)
        done.add(spec.v.addr)
        decl, ns, defs = render_class(m, spec, here.get(spec.v.addr, []))
        parts.append(decl)
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


def cmd_write(m: Model, args) -> None:
    """Placeholder classes for the simple virtual functions of game code."""
    from common import in_area, read_functions_csv

    rows = {f.sword: f for f in read_functions_csv() if f.sword is not None}

    def pickable(f: int) -> bool:
        r = rows.get(f)
        return r is not None and r.status == "U" and not r.name and r.scope == "common"

    holders: dict[int, set[str]] = defaultdict(set)
    for v in m.vtables:
        for f in v.slots:
            holders[f].add(class_name(v))

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

    def kept(f: int) -> bool:
        return written(f) and (only is None or f in only or bool(rows[f].name))

    own = owners(m.vtables)
    groups = args.area or ["game", "gflib3", "gflnet3"]
    picked: dict[int, list[Member]] = {}
    for v in m.vtables:
        if not any(in_area(vtable_area(m, v), g) for g in groups):
            continue
        members = placeholder_members(m, v, own, kept, None if args.no_forward else callee,
                                      None if args.no_lift else (lambda f: lift_member(m, f)))
        if members:
            picked[v.addr] = members
    seg_starts = segment_starts(m)

    def seg(f: int) -> int:
        return seg_starts[bisect.bisect_right(seg_starts, f) - 1]

    specs = class_specs(m, picked, own, seg, kept)
    # One file per static-initialiser segment, like src/unsorted/leaf: a class
    # whose functions span segments is declared in each of their files.
    files: dict[int, list[tuple[ClassSpec, list[Member]]]] = defaultdict(list)
    for spec in specs.values():
        by_seg: dict[int, list[Member]] = defaultdict(list)
        for x in spec.members:
            by_seg[seg(x.addr)].append(x)
        for s, xs in by_seg.items():
            files[s].append((spec, xs))
    out_dir = args.out
    out_dir.mkdir(parents=True, exist_ok=True)
    for old in out_dir.glob("Unk_*.cpp"):  # everything here is written again (a file's name can change)
        old.unlink()
    name_rows: dict[int, str] = {}  # a forwarders' callee is named once
    for _, entries in sorted(files.items()):
        first = min(x.addr for _, xs in entries for x in xs)
        text, names = render_file(m, entries)
        name_rows.update(names)
        (out_dir / f"Unk_{first:x}.cpp").write_text(text, encoding="utf-8", newline="\n")
    with open(args.names, "w", encoding="utf-8", newline="\n") as fh:
        fh.write("Name,Sword,Shield\n")
        for f, n in sorted(name_rows.items()):
            r = rows[f]
            fh.write(f"{n},{r.sword_str},{r.shield_str}\n")
    derived = sum(s.base is not None for s in specs.values())
    n_callees = sum(n.startswith("_Z") and not n.startswith("_ZN") for n in name_rows.values())
    print(f"{len(name_rows) - n_callees} functions of {len(specs)} classes ({derived} derived, "
          f"{sum(s.inline_dtor for s in specs.values())} bases with an inline destructor) in {len(files)} files, "
          f"{n_callees} forwarders' callees; names in {args.names}", file=sys.stderr)


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
    p.add_argument("--area", action="append", help="area or group (default: game, gflib3, gflnet3)")
    p.add_argument("--out", type=Path, default=ROOT / "src" / "unsorted" / "virtual")
    p.add_argument("--names", type=Path, required=True, help="where to write Name,Sword,Shield")
    p.add_argument("--only", type=Path, help="file of Sword addresses: of the unnamed functions, write only these")
    p.add_argument("--no-forward", action="store_true", help="leave out forwarders (b T)")
    p.add_argument("--no-lift", action="store_true", help="leave out what leafgen.py lifts")
    args = ap.parse_args(argv)
    if args.cmd == "write" and args.game != "sword":
        raise SystemExit("write works from Sword's vtables (the names cover both games)")
    m = load(args.game)
    {"summary": cmd_summary, "show": cmd_show, "of": cmd_of, "csv": cmd_csv, "write": cmd_write}[args.cmd](m, args)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
