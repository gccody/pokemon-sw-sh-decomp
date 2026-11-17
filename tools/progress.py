#!/usr/bin/env python3
"""Decomp progress from data/functions.csv - per game, per scope and per area.

    tools/progress.py            # human-readable table
    tools/progress.py --json     # machine-readable (CI badges / decomp.dev-style sites)
    tools/progress.py --svg DIR  # README images: a badge per game + a treemap

Progress is measured in bytes of code (what matching projects usually report)
and in function counts. A function counts as done for a game when its status
is O (matching); m (minor diff) is reported separately. Per-area numbers are
per game: each game's functions are placed with that game's columns of
data/areas.csv (tools/common.py's read_areas_csv/AreaMap).

--svg writes <game>.svg (one badge per game), treemap.svg and progress.json
(the same document as --json). There is one treemap for both games, not one
per game: status is shared and lint guarantees each function is in the same
area in both games, so two maps would differ only in a few function sizes.
Each function is placed with its own game's range (Sword's for functions in
Sword, Shield's for Shield-only ones); see tools/progress_svg.py.
"""
from __future__ import annotations

import argparse
import json
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import SCOPES, VERSIONS, AreaMap, read_areas_csv, read_functions_csv  # noqa: E402

GAME_LABELS = {"sword": "Sword", "shield": "Shield"}


class Tally:
    def __init__(self):
        self.n = self.bytes = 0
        self.done_n = self.done_bytes = 0
        self.minor_n = 0

    def add(self, size: int, status: str):
        self.n += 1
        self.bytes += size
        if status == "O":
            self.done_n += 1
            self.done_bytes += size
        elif status == "m":
            self.minor_n += 1

    def pct(self) -> float:
        return 100.0 * self.done_bytes / self.bytes if self.bytes else 0.0

    def pct_functions(self) -> float:
        return 100.0 * self.done_n / self.n if self.n else 0.0

    def as_dict(self):
        return {"functions": self.n, "bytes": self.bytes, "matching_functions": self.done_n,
                "matching_bytes": self.done_bytes, "minor_functions": self.minor_n,
                "percent_bytes": round(self.pct(), 4)}


def area_tallies(funcs, areas) -> dict[str, dict[str, Tally]]:
    """{game: {area: Tally}}; functions outside every area of a game count as "unassigned"."""
    out = {}
    for v in VERSIONS:
        amap = AreaMap(areas, v)
        per_area = defaultdict(Tally)
        for f in funcs:
            if f.in_version(v):
                per_area[amap.area_of(f.addr(v)) or "unassigned"].add(f.size(v), f.status)
        out[v] = per_area
    return out


def tally(funcs, areas):
    """(per game, per scope, per game and area) Tally dicts."""
    per_game = {v: Tally() for v in VERSIONS}
    per_scope = defaultdict(Tally)
    for f in funcs:
        for v in VERSIONS:
            if f.in_version(v):
                per_game[v].add(f.size(v), f.status)
        size = f.sword_size if f.sword_size is not None else f.shield_size
        per_scope[f.scope].add(size, f.status)
    return per_game, per_scope, area_tallies(funcs, areas)


def as_json(per_game, per_scope, per_area) -> dict:
    return {"games": {v: t.as_dict() for v, t in per_game.items()},
            "scopes": {k: t.as_dict() for k, t in per_scope.items()},
            "areas": {v: {k: t.as_dict() for k, t in per_area[v].items()} for v in VERSIONS}}


def write_svgs(out: Path, funcs, areas) -> list[Path]:
    """<game>.svg badges, treemap.svg and progress.json in `out`."""
    from progress_svg import badge, fmt_pct, treemap

    per_game, per_scope, per_area = tally(funcs, areas)
    out.mkdir(parents=True, exist_ok=True)
    files = {}
    for v, t in per_game.items():
        files[f"{v}.svg"] = badge(GAME_LABELS.get(v, v), [
            f"{fmt_pct(t.pct())} code",
            f"{t.done_n:,} / {t.n:,} functions",
        ], done=t.done_n == t.n > 0)
    files["treemap.svg"] = treemap(funcs, areas)
    files["progress.json"] = json.dumps(as_json(per_game, per_scope, per_area), indent=1) + "\n"
    paths = []
    for name, text in files.items():
        p = out / name
        p.write_text(text, encoding="utf-8", newline="\n")
        paths.append(p)
    return paths


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--json", action="store_true")
    ap.add_argument("--svg", type=Path, metavar="DIR", help="write README badges and treemap to DIR")
    args = ap.parse_args()

    funcs = read_functions_csv()
    areas = read_areas_csv()

    if args.svg:
        for p in write_svgs(args.svg, funcs, areas):
            print(f"wrote {p} ({p.stat().st_size / 1024:.0f} KB)")
        return 0

    per_game, per_scope, per_area = tally(funcs, areas)
    if args.json:
        print(json.dumps(as_json(per_game, per_scope, per_area), indent=1))
        return 0

    def table(title, items):
        print(f"\n{title}")
        items = list(items)
        w = max([14] + [len(k) for k, _ in items])
        print(f"  {'':{w}} {'matching':>18} {'functions':>10} {'code':>12}")
        for k, t in items:
            print(f"  {k:{w}} {t.done_n:>8} ({t.pct():6.3f}%) {t.n:>10} {t.bytes / 1024:>10.0f}KB")

    table("Per game (bytes-weighted %)", per_game.items())
    table("Per scope", [(s, per_scope[s]) for s in SCOPES if s in per_scope])
    for v in VERSIONS:
        names = [a.name for a in areas if a.in_version(v)]
        order = names + sorted(set(per_area[v]) - set(names))
        table(f"Per area, {v} (data/areas.csv)", [(a, per_area[v][a]) for a in order if a in per_area[v]])
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
