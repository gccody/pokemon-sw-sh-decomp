#!/usr/bin/env python3
"""Validate the repository without needing the game (runs in CI).

    python tools/lint.py             # everything below
    python tools/lint.py --no-git    # skip the tracked-files check

data/functions.csv: header/columns, valid scope/status letters, address & size
sanity, scope consistency (common rows exist in both games, sword-only rows only
in Sword ...), unique names, and that rows stay sorted by address.

data/data_symbols.csv: header, hex addresses, unique names.
data/areas.csv: header, valid kind/confidence, sorted and non-overlapping ranges.

Tracked files: nothing extracted from the game (NSO/XCI/NCA/keys ...) and no
large binaries may be committed.
"""
from __future__ import annotations

import argparse
import csv
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BASE, HEADER, ROOT, SCOPES, STATUSES, read_functions_csv  # noqa: E402

DATA_SYMBOLS_HEADER = ["Sword", "Shield", "Size", "Name"]
AREAS_HEADER = ["Start", "End", "Area", "Kind", "Confidence", "Evidence"]
AREA_KINDS = ("game", "library")
AREA_CONFIDENCE = ("low", "medium", "high")

# Never commit game data. Mirrors the "copyrighted game data" block of .gitignore,
# so a `git add -f` still fails CI.
FORBIDDEN_SUFFIXES = (".xci", ".nsp", ".nca", ".nso", ".nro", ".elf", ".keys", ".bin", ".bfres", ".bntx")
FORBIDDEN_PREFIXES = ("data/original/", "assets/Pokemon Sword/", "assets/Pokemon Shield/")
MAX_TRACKED_BYTES = 1024 * 1024  # functions.csv (~6 MB) is allowed explicitly below
LARGE_FILE_ALLOWLIST = {"data/functions.csv"}


def _read_header(path: Path) -> list[str]:
    with open(path, newline="", encoding="utf-8") as f:
        return next(csv.reader(f), [])


def lint_functions(path: Path) -> tuple[list[str], int, int]:
    """Returns (errors, number of functions, number named)."""
    errors: list[str] = []
    header = _read_header(path)
    if header != HEADER:
        return [f"{path.name} header is {header}, expected {HEADER}"], 0, 0
    funcs = read_functions_csv(path)
    names: dict[str, int] = {}
    prev = -1
    for i, fn in enumerate(funcs, start=2):
        where = f"{path.name}:{i}"
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
        if key is None:
            errors.append(f"{where}: no address for either game")
            continue
        if key <= prev:
            errors.append(f"{where}: rows must be sorted by address")
        prev = key
        if fn.name:
            if " " in fn.name or "(" in fn.name:
                errors.append(f"{where}: name must be a symbol name (mangled), not {fn.name!r}")
            if fn.name in names:
                errors.append(f"{where}: duplicate name {fn.name} (also line {names[fn.name]})")
            names[fn.name] = i
    return errors, len(funcs), len(names)


def _hex(s: str) -> int | None:
    try:
        return int(s, 16) if s.lower().startswith("0x") else None
    except ValueError:
        return None


def lint_data_symbols(path: Path) -> list[str]:
    if not path.exists():
        return []
    header = _read_header(path)
    if header != DATA_SYMBOLS_HEADER:
        return [f"{path.name} header is {header}, expected {DATA_SYMBOLS_HEADER}"]
    errors: list[str] = []
    names: dict[str, int] = {}
    with open(path, newline="", encoding="utf-8") as f:
        for i, r in enumerate(csv.DictReader(f), start=2):
            where = f"{path.name}:{i}"
            if not r["Sword"] and not r["Shield"]:
                errors.append(f"{where}: needs a Sword or Shield address")
            for col in ("Sword", "Shield"):
                if r[col] and (_hex(r[col]) is None or _hex(r[col]) < BASE):
                    errors.append(f"{where}: bad {col} address {r[col]!r} (expected 0x71...)")
            if r["Size"] and not r["Size"].isdigit():
                errors.append(f"{where}: Size must be a decimal byte count, not {r['Size']!r}")
            name = r["Name"]
            if not name or " " in name:
                errors.append(f"{where}: bad name {name!r}")
            elif name in names:
                errors.append(f"{where}: duplicate name {name} (also line {names[name]})")
            names[name] = i
    return errors


def lint_areas(path: Path) -> list[str]:
    if not path.exists():
        return []
    header = _read_header(path)
    if header != AREAS_HEADER:
        return [f"{path.name} header is {header}, expected {AREAS_HEADER}"]
    errors: list[str] = []
    prev_end = -1
    with open(path, newline="", encoding="utf-8") as f:
        for i, r in enumerate(csv.DictReader(f), start=2):
            where = f"{path.name}:{i}"
            start, end = _hex(r["Start"]), _hex(r["End"])
            if start is None or end is None or start >= end:
                errors.append(f"{where}: bad range {r['Start']}-{r['End']}")
                continue
            if start < prev_end:
                errors.append(f"{where}: range overlaps the previous row or is out of order")
            prev_end = end
            if r["Kind"] not in AREA_KINDS:
                errors.append(f"{where}: Kind must be one of {AREA_KINDS}, not {r['Kind']!r}")
            if r["Confidence"] not in AREA_CONFIDENCE:
                errors.append(f"{where}: Confidence must be one of {AREA_CONFIDENCE}, not {r['Confidence']!r}")
            if not r["Area"]:
                errors.append(f"{where}: empty Area")
    return errors


def lint_tracked_files(paths: list[str], root: Path = ROOT) -> list[str]:
    errors: list[str] = []
    for p in paths:
        low = p.lower()
        if low.endswith(FORBIDDEN_SUFFIXES) or p.startswith(FORBIDDEN_PREFIXES):
            errors.append(f"{p}: looks like game data or keys - never commit these")
            continue
        f = root / p
        if p not in LARGE_FILE_ALLOWLIST and f.is_file() and f.stat().st_size > MAX_TRACKED_BYTES:
            errors.append(f"{p}: {f.stat().st_size // 1024} KiB is too large to commit")
    return errors


def git_tracked_files(root: Path = ROOT) -> list[str] | None:
    try:
        out = subprocess.run(["git", "ls-files", "-z"], cwd=root, capture_output=True, check=True)
    except (OSError, subprocess.CalledProcessError):
        return None
    return [p for p in out.stdout.decode("utf-8").split("\0") if p]


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--data", type=Path, default=ROOT / "data", help="directory holding the CSVs")
    ap.add_argument("--no-git", action="store_true", help="skip the tracked-files check")
    args = ap.parse_args(argv)

    errors, n_funcs, n_named = lint_functions(args.data / "functions.csv")
    errors += lint_data_symbols(args.data / "data_symbols.csv")
    errors += lint_areas(args.data / "areas.csv")
    if not args.no_git:
        tracked = git_tracked_files()
        if tracked is None:
            print("warning: not a git checkout, skipping the tracked-files check")
        else:
            errors += lint_tracked_files(tracked)

    for e in errors[:200]:
        print(e)
    if len(errors) > 200:
        print(f"... and {len(errors) - 200} more")
    print(f"{n_funcs} functions, {n_named} named, {len(errors)} problems")
    return 1 if errors else 0


if __name__ == "__main__":
    raise SystemExit(main())
