#!/usr/bin/env python3
"""Decomp progress from data/functions.csv - per game, per scope and per area.

    tools/progress.py            # human-readable table
    tools/progress.py --json     # machine-readable (CI badges / decomp.dev-style sites)
    tools/progress.py --svg DIR  # README images: a badge per game + a treemap

Progress is measured in bytes of code (what matching projects usually report)
and in function counts. A function counts as done for a game when its status
is O (matching); m (minor diff) is reported separately.
"""
from __future__ import annotations

import argparse
import bisect
import csv
import json
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BASE, ROOT, SCOPES, VERSIONS, read_functions_csv  # noqa: E402

GAME_LABELS = {"sword": "Sword", "shield": "Shield"}


def load_areas(path: Path | None = None):
    rows = []
    with open(path or ROOT / "data" / "areas.csv", newline="", encoding="utf-8") as f:
        for r in csv.DictReader(f):
            rows.append((int(r["Start"], 16) - BASE, int(r["End"], 16) - BASE, r["Area"]))
    rows.sort()
    starts = [s for s, _, _ in rows]

    def area_of(addr: int) -> str:
        i = bisect.bisect_right(starts, addr) - 1
        return rows[i][2] if i >= 0 and addr < rows[i][1] else "unassigned"
    return area_of, [a for _, _, a in rows]


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


def tally(funcs, area_of):
    """(per game, per scope, per area) Tally dicts."""
    per_game = {v: Tally() for v in VERSIONS}
    per_scope = defaultdict(Tally)
    per_area = defaultdict(Tally)
    for f in funcs:
        for v in VERSIONS:
            if f.in_version(v):
                per_game[v].add(f.size(v), f.status)
        size = f.sword_size if f.sword_size is not None else f.shield_size
        per_scope[f.scope].add(size, f.status)
        per_area[area_of(f.sword if f.sword is not None else f.shield)].add(size, f.status)
    return per_game, per_scope, per_area


def as_json(per_game, per_scope, per_area) -> dict:
    return {"games": {v: t.as_dict() for v, t in per_game.items()},
            "scopes": {k: t.as_dict() for k, t in per_scope.items()},
            "areas": {k: t.as_dict() for k, t in per_area.items()}}


def write_svgs(out: Path, funcs, area_of, area_names) -> list[Path]:
    """<game>.svg badges, treemap.svg and progress.json in `out`."""
    from progress_svg import badge, fmt_pct, treemap

    per_game, per_scope, per_area = tally(funcs, area_of)
    out.mkdir(parents=True, exist_ok=True)
    files = {}
    for v, t in per_game.items():
        files[f"{v}.svg"] = badge(GAME_LABELS.get(v, v), [
            f"{fmt_pct(t.pct())} code",
            f"{t.done_n:,} / {t.n:,} functions",
        ], done=t.done_n == t.n > 0)
    files["treemap.svg"] = treemap(funcs, area_of, area_names)
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
    area_of, area_names = load_areas()

    if args.svg:
        for p in write_svgs(args.svg, funcs, area_of, area_names):
            print(f"wrote {p} ({p.stat().st_size / 1024:.0f} KB)")
        return 0

    per_game, per_scope, per_area = tally(funcs, area_of)
    if args.json:
        print(json.dumps(as_json(per_game, per_scope, per_area), indent=1))
        return 0

    def table(title, items):
        print(f"\n{title}")
        print(f"  {'':14} {'matching':>18} {'functions':>10} {'code':>12}")
        for k, t in items:
            print(f"  {k:14} {t.done_n:>8} ({t.pct():6.3f}%) {t.n:>10} {t.bytes / 1024:>10.0f}KB")

    table("Per game (bytes-weighted %)", per_game.items())
    table("Per scope", [(s, per_scope[s]) for s in SCOPES if s in per_scope])
    order = area_names + sorted(set(per_area) - set(area_names))
    table("Per area (data/areas.csv)", [(a, per_area[a]) for a in dict.fromkeys(order) if a in per_area])
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
