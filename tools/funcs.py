#!/usr/bin/env python3
"""Query and edit data/functions.csv.

    tools/funcs.py list [--scope diverged] [--status U] [--min 0 --max 64] [--range 0x7100800000-0x7100900000] [-n 50]
    tools/funcs.py show 0x71007c2d80          # original asm (both games side-by-side if they differ)
    tools/funcs.py name 0x71007c2d80 _ZN4pkmn10GetVersionEv
    tools/funcs.py status 0x71007c2d80 m      # manual status (m/M for non-matching submissions, L for library)

Addresses may be given for either game; Sword addresses are canonical.
"""
from __future__ import annotations

import argparse
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BASE, ROOT, SCOPES, STATUSES, VERSIONS, load_module, read_functions_csv, write_functions_csv  # noqa: E402

CSV = ROOT / "data" / "functions.csv"


def find(funcs, q: str):
    if q.lower().startswith("0x") or all(c in "0123456789abcdefABCDEF" for c in q):
        a = int(q, 16)
        a = a - BASE if a >= BASE else a
        for f in funcs:
            if a in (f.sword, f.shield):
                return f
    for f in funcs:
        if q in (f.name, f.display_name):
            return f
    raise SystemExit(f"no function matching {q!r}")


def cmd_list(args, funcs):
    lo, hi = (None, None)
    if args.range:
        lo, hi = (int(x, 16) - BASE for x in args.range.split("-"))
    n = 0
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
        if args.unnamed and f.name:
            continue
        print(f"{f.sword_str or '-':18} {f.shield_str or '-':18} {size:6} {f.scope:11} {f.status} {f.display_name}")
        n += 1
        if args.n and n >= args.n:
            break


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


def cmd_name(args, funcs):
    f = find(funcs, args.func)
    if not (args.name.startswith("_Z") or args.name.replace("_", "a").isalnum()) and not args.force:
        raise SystemExit("names must be symbol names: mangled C++ (e.g. _ZN4pkmn10GetVersionEv) "
                         "or a plain C identifier; --force to override")
    clash = [g for g in funcs if g.name == args.name and g is not f]
    if clash:
        raise SystemExit(f"{args.name} is already used by {clash[0].sword_str or clash[0].shield_str}")
    f.name = args.name
    write_functions_csv(CSV, funcs)
    print(f"{f.sword_str or f.shield_str} -> {args.name}")


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
    p.add_argument("--unnamed", action="store_true")
    p.add_argument("-n", type=int, default=100, help="max rows (0 = all)")
    p = sub.add_parser("show")
    p.add_argument("func")
    p.add_argument("--both", action="store_true", help="show both games even if the code is common")
    p = sub.add_parser("name")
    p.add_argument("func")
    p.add_argument("name")
    p.add_argument("--force", action="store_true")
    p = sub.add_parser("status")
    p.add_argument("func")
    p.add_argument("status", choices=STATUSES)
    args = ap.parse_args()
    funcs = read_functions_csv(CSV)
    {"list": cmd_list, "show": cmd_show, "name": cmd_name, "status": cmd_status}[args.cmd](args, funcs)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
