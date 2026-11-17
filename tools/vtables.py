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
    kind: str                       # "dtor" (slots 0+1), "ret", "constant", "zero", "null"
    value: int = 0


def class_name(v: Vtable) -> str:
    """Placeholder class name: Unk_<its vtable's start>, the `_ZTV` symbol's address."""
    return f"Unk_{v.start:x}"


def mangle(cls: str, member: str) -> str:
    """Itanium name of a no-argument member: vfN, or D0/D2 for the destructors."""
    m = member if member in ("D0", "D2") else f"{len(member)}{member}"
    return f"_ZN{len(cls)}{cls}{m}Ev"


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


def placeholder_members(m: Model, v: Vtable, own: dict[int, tuple[int, int]], pickable) -> list[Member]:
    """The members of v's class that write defines: the simple functions it owns."""
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
    return out


def render_class(m: Model, v: Vtable, members: list[Member],
                 here: list[Member] | None = None) -> tuple[str, list[tuple[int, str]], str]:
    """(class declaration, [(function, mangled name)], definitions).

    The declaration comes from all of the class's `members`, so that every file
    declaring the class declares it the same way; only `here` (default: all)
    are defined."""
    cls = class_name(v)
    declared = {x.slot: x for x in members}
    defined = {x.slot: x for x in (members if here is None else here)}
    pair = destructor_pair(m, v)
    decl = [f"class {cls} {{", "public:"]
    names: list[tuple[int, str]] = []
    defs: list[str] = []
    rtype = {"ret": "void", "constant": "u32", "zero": "u32", "null": "void*"}
    start = 0
    if pair is not None:
        decl.append(f"    virtual ~{cls}();")
        start = 2
        if 0 in defined:
            defs.append(f"// 0x{v.slots[0] + BASE:x}, 0x{v.slots[1] + BASE:x}\n{cls}::~{cls}() {{}}")
            names += [(v.slots[0], mangle(cls, "D2")), (v.slots[1], mangle(cls, "D0"))]
    for i in range(start, len(v.slots)):
        f = v.slots[i]
        if isinstance(f, str):
            decl.append(f"    virtual void vf{i}() = 0;")
            continue
        d = declared.get(i)
        decl.append(f"    virtual {rtype[d.kind] if d else 'void'} vf{i}();")
        x = defined.get(i)
        if x is None:
            continue
        body = {"ret": "{}", "constant": f"{{\n    return {x.value if x.value < 10 else hex(x.value)};\n}}",
                "zero": "{\n    return 0;\n}", "null": "{\n    return nullptr;\n}"}[x.kind]
        defs.append(f"// 0x{f + BASE:x}\n{rtype[x.kind]} {cls}::vf{i}() {body}")
        names.append((f, mangle(cls, f"vf{i}")))
    decl.append("};")
    return "\n".join(decl) + "\n", names, "\n\n".join(defs) + "\n"


def cmd_write(m: Model, args) -> None:
    """Placeholder classes for the simple virtual functions of game code."""
    import segments
    from common import in_area, read_functions_csv

    rows = {f.sword: f for f in read_functions_csv() if f.sword is not None}

    def pickable(f: int) -> bool:
        r = rows.get(f)
        return r is not None and r.status == "U" and not r.name and r.scope == "common"

    own = owners(m.vtables)
    groups = args.area or ["game", "gflib3", "gflnet3"]
    picked: list[tuple[Vtable, list[Member]]] = []
    for v in m.vtables:
        if not any(in_area(vtable_area(m, v), g) for g in groups):
            continue
        members = placeholder_members(m, v, own, pickable)
        if members:
            picked.append((v, members))
    # One file per static-initialiser segment, like src/unsorted/leaf: a class
    # whose functions span segments is declared in each of their files.
    from nx.module import DynInfo
    from nx.nso import Nso
    from common import load_module, nso_path
    nso = Nso(nso_path("sword").read_bytes())
    dyn = DynInfo(nso, m.img, load_module("sword")["text_end"])
    inits = set(segments.init_array_targets(segments.dynamic_tags(m.img, nso.mod0.dynamic), dyn.slots))
    starts = [s for s, _ in m.funcs]
    seg_starts = sorted({starts[i + 1] for i, s in enumerate(starts[:-1]) if s in inits} | {0})

    def seg(f: int) -> int:
        return seg_starts[bisect.bisect_right(seg_starts, f) - 1]

    files: dict[int, list[tuple[Vtable, list[Member], list[Member]]]] = defaultdict(list)
    for v, members in picked:
        by_seg: dict[int, list[Member]] = defaultdict(list)
        for x in members:
            by_seg[seg(x.addr)].append(x)
        for s, xs in by_seg.items():
            files[s].append((v, members, xs))
    out_dir = args.out
    out_dir.mkdir(parents=True, exist_ok=True)
    name_rows = []
    n_funcs = 0
    for _, entries in sorted(files.items()):
        entries.sort(key=lambda e: min(x.addr for x in e[2]))
        first = min(x.addr for _, _, xs in entries for x in xs)
        parts = ["// Scope: common",
                 "// Simple virtual functions between two static initialisers (one or more TUs).",
                 "// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename",
                 "// them, and give the functions real signatures, once the classes are known.",
                 "#include <types.h>", ""]
        for v, members, xs in entries:
            decl, names, defs = render_class(m, v, members, xs)
            parts += [decl, defs]
            name_rows += names
            n_funcs += len(names)
        (out_dir / f"Unk_{first:x}.cpp").write_text("\n".join(parts).rstrip("\n") + "\n", encoding="utf-8",
                                                     newline="\n")
    with open(args.names, "w", encoding="utf-8", newline="\n") as fh:
        fh.write("Name,Sword,Shield\n")
        for f, n in sorted(name_rows):
            r = rows[f]
            fh.write(f"{n},{r.sword_str},{r.shield_str}\n")
    print(f"{n_funcs} functions of {len(picked)} classes in {len(files)} files; names in {args.names}",
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
    p.add_argument("--area", action="append", help="area or group (default: game, gflib3, gflnet3)")
    p.add_argument("--out", type=Path, default=ROOT / "src" / "unsorted" / "virtual")
    p.add_argument("--names", type=Path, required=True, help="where to write Name,Sword,Shield")
    args = ap.parse_args(argv)
    if args.cmd == "write" and args.game != "sword":
        raise SystemExit("write works from Sword's vtables (the names cover both games)")
    m = load(args.game)
    {"summary": cmd_summary, "show": cmd_show, "of": cmd_of, "csv": cmd_csv, "write": cmd_write}[args.cmd](m, args)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
