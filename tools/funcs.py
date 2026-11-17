#!/usr/bin/env python3
"""Query and edit data/functions.csv.

    tools/funcs.py list [--scope diverged] [--status U] [--min 0 --max 64] [--range 0x7100800000-0x7100900000] [-n 50]
    tools/funcs.py list --area lua            # rows in a data/areas.csv area (each game's own columns)
    tools/funcs.py patterns --area game --status U --max 8   # group by instruction pattern + how it's reached
                                              # (an area name covers the rows under it: game -> game/bag, ...)
    tools/funcs.py show 0x71007c2d80          # original asm (both games side-by-side if they differ)
    tools/funcs.py name 0x71007c2d80 _ZN4pkmn10GetVersionEv
    tools/funcs.py name 0x710154fb60 GCTM@lgc              # static: <symbol>@<file stem>
    tools/funcs.py name --from-file lua_map.csv           # bulk: Name,Sword,Shield (compiler_sweep.py --map-out)
    tools/funcs.py status 0x71007c2d80 m      # manual status (m/M for non-matching submissions, L for library)

Addresses may be given for either game; Sword addresses are canonical.
Local (static) symbols are file-qualified, see tools/symbols.py.
"""
from __future__ import annotations

import argparse
import csv
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import (  # noqa: E402
    BASE, ROOT, SCOPES, STATUSES, VERSIONS, AreaMap, area_names, in_area, load_module, read_areas_csv,
    read_functions_csv,
    write_functions_csv,
)
import symbols  # noqa: E402

CSV = ROOT / "data" / "functions.csv"


def find(funcs, q: str):
    if q.lower().startswith("0x") or all(c in "0123456789abcdefABCDEF" for c in q):
        a = int(q, 16)
        a = a - BASE if a >= BASE else a
        # Sword addresses are canonical: one row's Shield address can be another row's Sword address
        for v in VERSIONS:
            for f in funcs:
                if f.addr(v) == a:
                    return f
    for f in funcs:
        if q in (f.name, f.display_name):
            return f
    raise SystemExit(f"no function matching {q!r}")


def select(args, funcs):
    """The rows `list` and `patterns` filter with --scope/--status/--min/--max/--range/--area/--unnamed."""
    lo, hi = (None, None)
    if args.range:
        lo, hi = (int(x, 16) - BASE for x in args.range.split("-"))
    area_maps = None
    if args.area:
        areas = read_areas_csv(args.areas_csv)
        if args.area not in area_names(areas):
            raise SystemExit(f"no area {args.area!r} in {args.areas_csv.name}: {', '.join(a.name for a in areas)}")
        area_maps = {v: AreaMap(areas, v) for v in VERSIONS}
    for f in funcs:
        size = f.sword_size if f.sword_size is not None else f.shield_size
        if args.scope and f.scope != args.scope:
            continue
        if args.status and f.status not in args.status:
            continue
        if args.min is not None and size < args.min:
            continue
        if args.max is not None and size > args.max:
            continue
        if lo is not None and not (lo <= (f.sword if f.sword is not None else f.shield) < hi):
            continue
        if area_maps and not any(f.in_version(v) and in_area(area_maps[v].area_of(f.addr(v)), args.area)
                                 for v in VERSIONS):
            continue
        if args.unnamed and f.name:
            continue
        yield f


def cmd_list(args, funcs):
    n = 0
    for f in select(args, funcs):
        size = f.sword_size if f.sword_size is not None else f.shield_size
        print(f"{f.sword_str or '-':18} {f.shield_str or '-':18} {size:6} {f.scope:11} {f.status} {f.display_name}")
        n += 1
        if args.n and n >= args.n:
            break


# --------------------------------------------------------------------------- patterns
_IMM = re.compile(r"#-?(?:0x[0-9a-f]+|\d+)")
NX_TRAP = 0xE7FFDEFE  # same word as tools/fix_traps.py


def pattern_of(code: bytes, addr: int = 0) -> str:
    """A function's instructions with immediates as #N and branch targets as T.

    Functions with the same pattern can usually be written the same way, e.g.
    `ldr x0, [x0, #N] ; ret` is a getter and `sub x0, x0, #N ; b T` a thunk
    that adjusts `this` for a secondary base."""
    import struct

    import capstone
    md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
    out = []
    for off in range(0, len(code) - len(code) % 4, 4):
        if struct.unpack_from("<I", code, off)[0] == NX_TRAP:
            out.append("trap")  # __builtin_trap(): the A32 encoding the NX toolchain emits
            continue
        i = next(md.disasm(code[off:off + 4], addr + off), None)
        if i is None:
            out.append(".word")
            continue
        op = "T" if i.mnemonic in ("b", "bl") else _IMM.sub("#N", i.op_str)
        out.append(f"{i.mnemonic} {op}".rstrip())
    return " ; ".join(out)


def branch_targets(img: bytes, start: int, end: int) -> set[int]:
    """Targets of every B/BL word in img[start:end] (offsets into img)."""
    import struct
    out = set()
    for i, w in enumerate(struct.unpack_from(f"<{(end - start) // 4}I", img, start)):
        if (w & 0x7C000000) == 0x14000000:
            imm = w & 0x3FFFFFF
            if imm & (1 << 25):
                imm -= 1 << 26
            out.add(start + i * 4 + imm * 4)
    return out


def reference_kind(addr: int, called: set[int], in_data: set[int]) -> str:
    """How a function is reached: `data` (a pointer to it in .data: a vtable or a
    function table, so usually a virtual function), `call` (B/BL only), `both` or `none`
    (neither: its address is only taken in code, or it's unused)."""
    d, c = addr in in_data, addr in called
    return "both" if d and c else "data" if d else "call" if c else "none"


def cmd_patterns(args, funcs):
    from collections import Counter, defaultdict

    from nx.module import DynInfo
    from nx.nso import Nso
    from common import nso_path

    rows = [f for f in select(args, funcs) if f.in_version("sword")]
    mod = load_module("sword")
    img = mod["image"]
    dyn = DynInfo(Nso(nso_path("sword").read_bytes()), img, mod["text_end"])
    in_data = {v for v in dyn.slots.values() if isinstance(v, int)}
    called = branch_targets(img, 0, mod["text_end"] & ~3)
    count: Counter = Counter()
    kinds: dict[str, Counter] = defaultdict(Counter)
    examples: dict[str, list[int]] = defaultdict(list)
    for f in rows:
        a = f.addr("sword")
        p = pattern_of(img[a:a + f.size("sword")], a + BASE)
        count[p] += 1
        kinds[p][reference_kind(a, called, in_data)] += 1
        if len(examples[p]) < 2:
            examples[p].append(a + BASE)
    print(f"{len(rows)} functions, {len(count)} patterns (Sword; reached via data = vtable/table entry, "
          "call = B/BL, both, none)")
    for p, c in count.most_common(args.n or None):
        k = " ".join(f"{x}={kinds[p][x]}" for x in ("data", "call", "both", "none") if kinds[p][x])
        ex = " ".join(f"{e:#x}" for e in examples[p])
        print(f"{c:7}  {p[:70]:70}  {k:34} {ex}")


def cmd_show(args, funcs):
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
    f = find(funcs, args.func)
    print(f"{f.display_name}  scope={f.scope} status={f.status}")
    cols = []
    for v in VERSIONS:
        if not f.in_version(v):
            continue
        img = load_module(v)["image"]
        a, s = f.addr(v), f.size(v)
        cols.append((v, a, [f"{i.mnemonic:8} {i.op_str}" for i in md.disasm(img[a:a + s], a + BASE)]))
    if len(cols) == 2 and f.scope not in ("diverged",) and not args.both:
        cols = cols[:1]
    header = "".join(f"{v} {a + BASE:#x}".ljust(52) for v, a, _ in cols)
    print("      " + header)
    for i in range(max(len(c[2]) for c in cols)):
        row = [c[2][i] if i < len(c[2]) else "" for c in cols]
        mark = "  " if len(set(row)) == 1 or len(row) == 1 else "!="
        print(f"{mark}{i * 4:4x}  " + "".join(x[:50].ljust(52) for x in row))


NAME_RULES = ("names must be symbol names: mangled C++ (e.g. _ZN4pkmn10GetVersionEv) or a plain C "
              "identifier, with local symbols qualified as <symbol>@<file stem> (tools/symbols.py)")


def cmd_name(args, funcs):
    if args.from_file:
        if args.func or args.name:
            raise SystemExit("give either FUNC NAME or --from-file, not both")
        return cmd_name_from_file(args, funcs)
    if not (args.func and args.name):
        raise SystemExit("usage: funcs.py name FUNC NAME | funcs.py name --from-file MAP.csv")
    f = find(funcs, args.func)
    if not symbols.is_valid_name(args.name) and not args.force:
        raise SystemExit(f"{NAME_RULES}; --force to override")
    clash = [g for g in funcs if g.name == args.name and g is not f]
    if clash:
        raise SystemExit(f"{args.name} is already used by {clash[0].sword_str or clash[0].shield_str}")
    f.name = args.name
    write_functions_csv(CSV, funcs)
    print(f"{f.sword_str or f.shield_str} -> {args.name}")


def apply_names(funcs, entries, force: bool = False) -> tuple[int, list[str]]:
    """Name rows from (name, sword addr | None, shield addr | None) entries.

    Addresses are absolute (0x71...) or BASE-relative. Both given -> they must be
    the same functions.csv row. Returns (rows renamed, problems); a problem
    skips only its own entry."""
    by_addr = {v: {f.addr(v): f for f in funcs if f.in_version(v)} for v in VERSIONS}
    by_name = {f.name: f for f in funcs if f.name}
    changed, problems = 0, []
    for name, *addrs in entries:
        if not symbols.is_valid_name(name):
            problems.append(f"{name}: not a valid symbol name")
            continue
        rows = []
        for v, a in zip(VERSIONS, addrs):
            if a is None:
                continue
            a = a - BASE if a >= BASE else a
            f = by_addr[v].get(a)
            if f is None:
                problems.append(f"{name}: no {v} function starts at {a + BASE:#x}")
                break
            rows.append(f)
        else:
            if not rows:
                problems.append(f"{name}: no address")
                continue
            f = rows[0]
            if any(g is not f for g in rows):
                problems.append(f"{name}: the Sword and Shield addresses are different functions.csv rows")
                continue
            if f.name == name:
                continue
            other = by_name.get(name)
            if other is not None and other is not f:
                problems.append(f"{name}: already used by {other.sword_str or other.shield_str}")
                continue
            if f.name and not force:
                problems.append(f"{name}: {f.sword_str or f.shield_str} is already named {f.name} (--force to rename)")
                continue
            by_name.pop(f.name, None)
            f.name = name
            by_name[name] = f
            changed += 1
    return changed, problems


def read_name_map(path: Path) -> list[tuple[str, int | None, int | None]]:
    """Name,Sword,Shield CSV (as written by compiler_sweep.py --map-out)."""
    with open(path, newline="", encoding="utf-8") as fh:
        rows = list(csv.DictReader(fh))
    if rows and not {"Name", "Sword", "Shield"} <= rows[0].keys():
        raise SystemExit(f"{path}: expected the columns Name,Sword,Shield")
    return [(r["Name"], int(r["Sword"], 16) if r["Sword"] else None,
             int(r["Shield"], 16) if r["Shield"] else None) for r in rows]


def cmd_name_from_file(args, funcs):
    changed, problems = apply_names(funcs, read_name_map(args.from_file), args.force)
    for p in problems:
        print(p)
    if changed:
        write_functions_csv(CSV, funcs)
    print(f"named {changed} functions, {len(problems)} skipped")
    return 1 if problems else 0


def cmd_status(args, funcs):
    f = find(funcs, args.func)
    f.status = args.status
    write_functions_csv(CSV, funcs)
    print(f"{f.display_name} -> {args.status}")


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("list")
    p.add_argument("--scope", choices=SCOPES)
    p.add_argument("--status", help="one or more status letters, e.g. U or mM")
    p.add_argument("--min", type=int)
    p.add_argument("--max", type=int)
    p.add_argument("--range", help="address range, e.g. 0x7100800000-0x7100900000")
    p.add_argument("--area", help="area name from data/areas.csv, e.g. lua, or a group of them, e.g. game for "
                   "game/bag, game/pokecamp, ... (each game's addresses use its own columns)")
    p.add_argument("--areas-csv", type=Path, default=ROOT / "data" / "areas.csv", help=argparse.SUPPRESS)
    p.add_argument("--unnamed", action="store_true")
    p.add_argument("-n", type=int, default=100, help="max rows (0 = all)")
    p = sub.add_parser("patterns", help="group functions by instruction pattern (Sword) and how they're reached")
    p.add_argument("--scope", choices=SCOPES)
    p.add_argument("--status", help="one or more status letters, e.g. U")
    p.add_argument("--min", type=int)
    p.add_argument("--max", type=int)
    p.add_argument("--range")
    p.add_argument("--area")
    p.add_argument("--areas-csv", type=Path, default=ROOT / "data" / "areas.csv", help=argparse.SUPPRESS)
    p.add_argument("--unnamed", action="store_true")
    p.add_argument("-n", type=int, default=40, help="max patterns (0 = all)")
    p = sub.add_parser("show")
    p.add_argument("func")
    p.add_argument("--both", action="store_true", help="show both games even if the code is common")
    p = sub.add_parser("name")
    p.add_argument("func", nargs="?")
    p.add_argument("name", nargs="?")
    p.add_argument("--from-file", type=Path, help="Name,Sword,Shield CSV to apply in bulk")
    p.add_argument("--force", action="store_true", help="allow any name / renaming already named rows")
    p = sub.add_parser("status")
    p.add_argument("func")
    p.add_argument("status", choices=STATUSES)
    args = ap.parse_args()
    funcs = read_functions_csv(CSV)
    return {"list": cmd_list, "patterns": cmd_patterns, "show": cmd_show, "name": cmd_name, "status": cmd_status}[args.cmd](args, funcs) or 0


if __name__ == "__main__":
    raise SystemExit(main())
