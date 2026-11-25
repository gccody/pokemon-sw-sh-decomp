#!/usr/bin/env python3
"""Name the rows of functions the sources already compile but functions.csv
doesn't know yet.

    python tools/autoname.py                     # report: compiled name -> the row it matches
    python tools/autoname.py --out names.csv     # Name,Sword,Shield for funcs.py name --from-file

check.py lists such a function as `?? ... is not in data/functions.csv`. The
compiler emits many of them without anyone writing them: the non-virtual
thunks (`_ZThn<N>_...`) and complete/deleting destructors of a class whose
key function is defined, copies of inline functions, template instances.
They're in the executable, as unnamed U rows. For each compiled function
without a row, autoname.py takes the unnamed rows of the same size and shape
(tools/shapes.py: the code with call targets and data addresses masked) and
compares each with check.py's own compare(), in both games. A name is
proposed only when exactly one row matches in every game the row is in.

Absent, unidentified and foreign functions and aliases are left out, the same
as check.py does. Run it after a build (`check.py` builds); it doesn't build.
"""
from __future__ import annotations

import argparse
import csv
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BASE, ROOT, VERSIONS, Function, load_module, read_functions_csv  # noqa: E402


def unique_matches(candidates: dict[str, list[Function]], ok) -> dict[str, Function]:
    """name -> its row, for the names with exactly one candidate row `ok`
    accepts, where no row is claimed by two names."""
    found = {}
    for name, rows in candidates.items():
        good = [r for r in rows if ok(name, r)]
        if len(good) == 1:
            found[name] = good[0]
    claimed: dict[int, list[str]] = defaultdict(list)
    for name, r in found.items():
        claimed[r.sword if r.sword is not None else -1 - (r.shield or 0)].append(name)
    return {n: r for n, r in found.items()
            if len(claimed[r.sword if r.sword is not None else -1 - (r.shield or 0)]) == 1}


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--out", type=Path, help="write Name,Sword,Shield of the proposed names")
    args = ap.parse_args(argv)

    import check as C
    from shapes import shape

    funcs = read_functions_csv()
    syms = C.load_symbol_tables(funcs)
    by_name = syms[0]
    origs = {v: C.Original(v) for v in VERSIONS}
    compiled = {v: C.load_objects(ROOT / "build" / v) for v in VERSIONS}
    syms = (C.with_aliases(by_name, compiled.values()), *syms[1:])
    paths = C.SourcePaths(C.read_source_paths(C.SOURCE_PATHS_CSV), ROOT)
    skip = set(C.read_absent()) | set(C.read_absent(C.UNIDENTIFIED_CSV)) | set(C.read_absent(C.FOREIGN_CSV))
    aliases = {a for c in compiled.values() for cf in c.values() for a in cf.aliases}

    img = load_module("sword")["image"]
    pool: dict[tuple[int, str], list[Function]] = defaultdict(list)
    for f in funcs:
        if f.status == "U" and not f.name and f.sword is not None and f.sword_size:
            pool[(f.sword_size, shape(img[f.sword:f.sword + f.sword_size]))].append(f)

    candidates: dict[str, list[Function]] = {}
    for name, cf in compiled["sword"].items():
        if name in by_name or name in skip or name in aliases or any(a in by_name for a in cf.aliases):
            continue
        rows = pool.get((len(cf.code), shape(cf.code)), [])
        if rows:
            candidates[name] = rows

    def ok(name: str, row: Function) -> bool:
        trial = Function(row.sword, row.shield, row.sword_size, row.shield_size, row.scope, row.status, name)
        for v in VERSIONS:
            if not trial.in_version(v):
                continue
            cf = compiled[v].get(name)
            if cf is None:
                return False
            if not C.merge_results(C.compare_copies(cf, trial, origs[v], syms, str, paths)).ok:
                return False
        return True

    found = unique_matches(candidates, ok)
    for name, r in sorted(found.items(), key=lambda kv: kv[1].sword or 0):
        print(f"0x{r.sword + BASE:x} {name}")
    print(f"{len(found)} of {len(candidates)} compiled functions without a row match exactly one unnamed row",
          file=sys.stderr)
    if args.out:
        with open(args.out, "w", newline="", encoding="utf-8") as fh:
            w = csv.writer(fh, lineterminator="\n")
            w.writerow(["Name", "Sword", "Shield"])
            for name, r in sorted(found.items(), key=lambda kv: kv[1].sword or 0):
                w.writerow([name, f"0x{r.sword + BASE:x}" if r.sword is not None else "",
                            f"0x{r.shield + BASE:x}" if r.shield is not None else ""])
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
