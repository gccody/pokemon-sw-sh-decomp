#!/usr/bin/env python3
"""Validate data/*.csv without needing the game (runs in CI).

Checks: header/columns, valid scope/status letters, address & size sanity,
scope consistency (common rows exist in both games, sword-only rows only in
Sword ...), unique names, and that rows stay sorted by address.
"""
from __future__ import annotations

import csv
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import HEADER, ROOT, SCOPES, STATUSES, read_functions_csv  # noqa: E402


def main() -> int:
    errors: list[str] = []
    path = ROOT / "data" / "functions.csv"
    with open(path, newline="", encoding="utf-8") as f:
        header = next(csv.reader(f))
    if header != HEADER:
        errors.append(f"functions.csv header is {header}, expected {HEADER}")
        print("\n".join(errors))
        return 1
    funcs = read_functions_csv(path)
    names: dict[str, int] = {}
    prev = -1
    for i, fn in enumerate(funcs, start=2):
        where = f"functions.csv:{i}"
        if fn.scope not in SCOPES:
            errors.append(f"{where}: bad scope {fn.scope!r}")
        if fn.status not in STATUSES:
            errors.append(f"{where}: bad status {fn.status!r}")
        in_sw, in_sh = fn.sword is not None, fn.shield is not None
        expect = {"sword": (True, False), "shield": (False, True)}.get(fn.scope, (True, True))
        if (in_sw, in_sh) != expect:
            errors.append(f"{where}: scope {fn.scope} but present in sword={in_sw} shield={in_sh}")
        for a, s, v in ((fn.sword, fn.sword_size, "sword"), (fn.shield, fn.shield_size, "shield")):
            if a is not None and (s is None or s <= 0 or s % 4 or a % 4):
                errors.append(f"{where}: bad {v} address/size")
        if fn.scope == "common" and fn.sword_size != fn.shield_size:
            errors.append(f"{where}: common function with different sizes")
        key = fn.sword if fn.sword is not None else fn.shield
        if key <= prev:
            errors.append(f"{where}: rows must be sorted by address")
        prev = key
        if fn.name:
            if " " in fn.name or "(" in fn.name:
                errors.append(f"{where}: name must be a symbol name (mangled), not {fn.name!r}")
            if fn.name in names:
                errors.append(f"{where}: duplicate name {fn.name} (also line {names[fn.name]})")
            names[fn.name] = i
    for e in errors[:200]:
        print(e)
    print(f"{len(funcs)} functions, {len(names)} named, {len(errors)} problems")
    return 1 if errors else 0


if __name__ == "__main__":
    raise SystemExit(main())
