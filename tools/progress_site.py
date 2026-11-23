#!/usr/bin/env python3
"""The progress website (GitHub Pages) from data/functions.csv, data/areas.csv and git history.

    tools/progress_site.py OUT                 # write the site to OUT
    tools/progress_site.py OUT --no-history    # skip the git history (faster, no git needed)

OUT gets index.html, site.css and site.js (copied from tools/site/) and data/:

    data/summary.json        per game: status totals, and per area status counts
    data/history.json        one point per commit that changed data/functions.csv
    data/functions/<n>.json  every function of one area (n = the area's index in summary.json)

CI runs it after tools/progress.py --svg, into the same directory, and
publishes the result to the `progress` branch, which GitHub Pages serves
(.github/workflows/progress.yml). The README links to the site.

History comes from `git log -p` of data/functions.csv along the first parent
of HEAD: each commit's diff removes and adds rows, and the tallies follow
the rows. Every commit is placed in areas with *today's* data/areas.csv (the
executable doesn't change, only the map of it gets better), so the history of
an area means the same thing at every point. Rows are read by column name,
with each commit's own header, so old commits keep working if the CSV gains
columns. A shallow clone only has part of the history: CI checks out with
fetch-depth 0.

Functions are counted the way tools/progress.py counts them: per game, in that
game's area, by bytes and by count, for every status. Function lists place a
function by its Sword address (Shield's for Shield-only ones), like the
treemap; tools/lint.py guarantees it's the same area in both games.
"""
from __future__ import annotations

import argparse
import csv
import json
import os
import re
import shutil
import subprocess
import sys
from dataclasses import dataclass, field
from datetime import datetime, timezone
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import (  # noqa: E402
    BASE,
    ROOT,
    SCOPES,
    STATUSES,
    VERSIONS,
    AreaMap,
    read_areas_csv,
    read_functions_csv,
)

STATIC = Path(__file__).resolve().parent / "site"
STATIC_FILES = ("index.html", "site.css", "site.js")
UNASSIGNED = "unassigned"
FUNCTIONS_CSV = "data/functions.csv"
MATCHED_LIST_MAX = 100  # newly matched names kept per commit
COMMIT_MARK = "\x1e"    # starts each commit's line in the `git log` output
SUBJECT_MAX = 200


# --------------------------------------------------------------------------- tallies
def empty_counts() -> list[int]:
    """[n per status..., bytes per status...], in STATUSES order."""
    return [0] * (2 * len(STATUSES))


STATUS_INDEX = {s: i for i, s in enumerate(STATUSES)}


def area_order(areas) -> list[str]:
    names = []
    for a in areas:
        if a.name not in names:
            names.append(a.name)
    return names + [UNASSIGNED]


def area_kind(area) -> str:
    """Which section of the site an area is listed in."""
    if area.kind == "library":
        return "library"
    return "game" if area.name.startswith("game/") else "gflib"


class Tallies:
    """{game: {area: counts}}; add/remove one row at a time."""

    def __init__(self, areas):
        self.maps = {v: AreaMap(areas, v) for v in VERSIONS}
        self.counts = {v: {} for v in VERSIONS}

    def apply(self, row: dict, sign: int) -> None:
        si = STATUS_INDEX.get(row["status"])
        if si is None:
            return
        for v in VERSIONS:
            addr, size = row[v], row[v + "_size"]
            if addr is None:
                continue
            area = self.maps[v].area_of(addr) or UNASSIGNED
            c = self.counts[v].get(area)
            if c is None:
                c = self.counts[v][area] = empty_counts()
            c[si] += sign
            c[len(STATUSES) + si] += sign * (size or 0)

    def game_totals(self, v: str) -> list[int]:
        out = empty_counts()
        for c in self.counts[v].values():
            for i, x in enumerate(c):
                out[i] += x
        return out


# --------------------------------------------------------------------------- functions.csv rows
def _addr(s: str | None) -> int | None:
    return int(s, 16) - BASE if s else None


def _int(s: str | None) -> int | None:
    return int(s) if s else None


def parse_row(header: list[str], line: str) -> dict | None:
    """One functions.csv line (read with that commit's header) as the fields history needs."""
    values = next(csv.reader([line]))
    r = dict(zip(header, values))
    try:
        row = {"sword": _addr(r.get("Sword")), "sword_size": _int(r.get("SwordSize")),
               "shield": _addr(r.get("Shield")), "shield_size": _int(r.get("ShieldSize")),
               "status": r.get("Status", ""), "name": r.get("Name", "")}
    except ValueError:
        return None
    if row["sword"] is None and row["shield"] is None:
        return None
    return row


def row_key(row: dict) -> str:
    return f"sw:{row['sword']:x}" if row["sword"] is not None else f"sh:{row['shield']:x}"


def row_label(row: dict) -> str:
    if row["name"]:
        return row["name"]
    if row["sword"] is not None:
        return f"FUN_{row['sword'] + BASE:010x}"
    return f"FUN_sh_{row['shield'] + BASE:010x}"


# --------------------------------------------------------------------------- git history
@dataclass
class Commit:
    sha: str
    date: str
    subject: str
    removed: list[str] = field(default_factory=list)
    added: list[str] = field(default_factory=list)


def parse_log(lines) -> list[Commit]:
    """Commits from `git log -p -U0 --format=<COMMIT_MARK>%H %cI %s` of functions.csv.

    Rows start with an address or a comma, so '+++ '/'--- ' file headers,
    hunk headers and '\\ No newline' notes can't be mistaken for rows."""
    commits = []
    cur = None
    for raw in lines:
        line = raw.rstrip("\r\n")
        if line.startswith(COMMIT_MARK):
            sha, date, subject = (line[1:].split(" ", 2) + ["", ""])[:3]
            cur = Commit(sha, date, subject[:SUBJECT_MAX])
            commits.append(cur)
        elif cur is None or line.startswith(("+++ ", "--- ")):
            continue
        elif line.startswith("+"):
            cur.added.append(line[1:])
        elif line.startswith("-"):
            cur.removed.append(line[1:])
    return commits


def git_log(repo: Path, rev: str = "HEAD") -> list[Commit]:
    shallow = subprocess.run(["git", "rev-parse", "--is-shallow-repository"], cwd=repo,
                             capture_output=True, text=True, check=True).stdout.strip()
    if shallow == "true":
        print("warning: shallow clone, history starts at its oldest commit", file=sys.stderr)
    cmd = ["git", "-c", "core.quotepath=off", "log", "--first-parent", "--diff-merges=first-parent",
           "--reverse", "-p", "-U0", "--no-color", "--no-ext-diff", "--no-renames",
           f"--format={COMMIT_MARK}%H %cI %s", rev, "--", FUNCTIONS_CSV]
    out = subprocess.run(cmd, cwd=repo, capture_output=True, check=True).stdout
    # Not splitlines(): it also splits at \x1e (COMMIT_MARK) and other separators.
    return parse_log(out.decode("utf-8", errors="replace").split("\n"))


def build_history(commits: list[Commit], areas) -> list[dict]:
    """One point per commit: game totals, the areas whose counts changed, and
    which functions became (or stopped being) matching."""
    tallies = Tallies(areas)
    order = {a: i for i, a in enumerate(area_order(areas))}
    header: list[str] = []
    last_area: dict[str, dict[str, tuple]] = {v: {} for v in VERSIONS}
    points = []
    last_date = ""
    for c in commits:
        before: dict[str, dict] = {}
        after: dict[str, dict] = {}
        for sign, lines, seen in ((-1, c.removed, before), (1, c.added, after)):
            for line in lines:
                if line.startswith(("Sword,", "Sword\t")):
                    if sign > 0:
                        header = next(csv.reader([line]))
                    continue
                if not header:
                    continue
                row = parse_row(header, line)
                if row is None:
                    continue
                tallies.apply(row, sign)
                seen[row_key(row)] = row
        matched = [r for k, r in after.items()
                   if r["status"] == "O" and before.get(k, {}).get("status") != "O"]
        lost = [r for k, r in before.items()
                if r["status"] == "O" and after.get(k, {}).get("status") != "O"]
        changed = {}
        for v in VERSIONS:
            cur = {a: tuple(x) for a, x in tallies.counts[v].items()}
            diff = {a: list(x) for a, x in cur.items() if last_area[v].get(a) != x}
            diff.update({a: empty_counts() for a in last_area[v] if a not in cur})
            last_area[v] = cur
            if diff:
                changed[v] = {order.get(a, -1): x for a, x in sorted(diff.items())}
        # Dates go forward along the first parent; clamp the odd out-of-order commit.
        date = max(c.date, last_date)
        last_date = date
        matched.sort(key=lambda r: -(r["sword_size"] or r["shield_size"] or 0))
        points.append({
            "sha": c.sha, "date": date, "subject": c.subject,
            "games": {v: tallies.game_totals(v) for v in VERSIONS},
            "areas": changed,
            "matched_n": len(matched), "lost_n": len(lost),
            "matched": [row_label(r) for r in matched[:MATCHED_LIST_MAX]],
        })
    return points


# --------------------------------------------------------------------------- snapshot
def demangle(names: set[str]) -> dict[str, str]:
    """Demangled names, with c++filt or llvm-cxxfilt if one is on PATH ({} otherwise)."""
    names = sorted(n for n in names if n.startswith("_Z"))
    exe = shutil.which("llvm-cxxfilt") or shutil.which("c++filt")
    llvm19 = ROOT / "toolchain" / "llvm-19" / "bin" / "llvm-cxxfilt"
    if exe is None:
        for cand in (llvm19, llvm19.with_suffix(".exe")):
            if cand.exists():
                exe = str(cand)
    if exe is None or not names:
        return {}
    try:
        out = subprocess.run([exe], input="\n".join(names) + "\n", capture_output=True,
                             text=True, encoding="utf-8", check=True).stdout.splitlines()
    except (OSError, subprocess.CalledProcessError):
        return {}
    if len(out) != len(names):
        return {}
    return {n: d for n, d in zip(names, out) if d != n}


def place(f, maps) -> str:
    """The area a function is listed under: by its Sword address, else Shield's."""
    v = "sword" if f.sword is not None else "shield"
    return maps[v].area_of(f.addr(v)) or UNASSIGNED


def snapshot(funcs, areas) -> tuple[dict, dict[str, list]]:
    """(summary.json, {area: function rows})."""
    tallies = Tallies(areas)
    maps = tallies.maps
    lists: dict[str, list] = {}
    scopes = {s: empty_counts() for s in SCOPES}
    for f in funcs:
        row = {"sword": f.sword, "sword_size": f.sword_size, "shield": f.shield,
               "shield_size": f.shield_size, "status": f.status, "name": f.name}
        tallies.apply(row, 1)
        si = STATUS_INDEX.get(f.status)
        if si is not None and f.scope in scopes:
            size = f.sword_size if f.sword_size is not None else f.shield_size
            scopes[f.scope][si] += 1
            scopes[f.scope][len(STATUSES) + si] += size or 0
        lists.setdefault(place(f, maps), []).append(f)

    names = area_order(areas)
    meta = {a.name: a for a in areas}
    area_rows = []
    for name in names:
        a = meta.get(name)
        entry = {"name": name,
                 "kind": area_kind(a) if a else "unassigned",
                 "confidence": a.confidence if a else "",
                 "evidence": a.evidence if a else "Functions outside every row of data/areas.csv.",
                 "ranges": {v: [a.range(v)[0] + BASE, a.range(v)[1] + BASE] if a and a.in_version(v)
                            else None for v in VERSIONS},
                 "counts": {v: tallies.counts[v].get(name, empty_counts()) for v in VERSIONS}}
        if a is None and not any(any(c) for c in entry["counts"].values()):
            continue
        area_rows.append(entry)
    summary = {
        "statuses": list(STATUSES),
        "scopes": list(SCOPES),
        "games": {v: tallies.game_totals(v) for v in VERSIONS},
        "scope_counts": {s: c for s, c in scopes.items() if any(c)},
        "areas": area_rows,
        "functions": len(funcs),
    }
    return summary, {name: lists.get(name, []) for name in names}


def function_rows(funcs, demangled: dict[str, str], scope_index: dict[str, int]) -> list[list]:
    """[sword, sword size, shield, shield size, scope, status, name, demangled], trailing blanks dropped.
    Addresses are relative to BASE."""
    out = []
    for f in funcs:
        r = [f.sword, f.sword_size, f.shield, f.shield_size, scope_index.get(f.scope, -1), f.status]
        if f.name:
            r.append(f.name)
            if f.name in demangled:
                r.append(demangled[f.name])
        out.append(r)
    return out


# --------------------------------------------------------------------------- output
def git_info(repo: Path) -> dict:
    def git(*args):
        try:
            return subprocess.run(["git", *args], cwd=repo, capture_output=True, text=True,
                                  check=True).stdout.strip()
        except (OSError, subprocess.CalledProcessError):
            return ""
    info = {"sha": os.environ.get("GITHUB_SHA") or git("rev-parse", "HEAD"),
            "date": git("log", "-1", "--format=%cI")}
    url = ""
    if os.environ.get("GITHUB_REPOSITORY"):
        url = f"{os.environ.get('GITHUB_SERVER_URL', 'https://github.com')}/{os.environ['GITHUB_REPOSITORY']}"
    else:
        remote = git("remote", "get-url", "origin")
        m = re.match(r"(?:https://|git@)(github\.com)[/:](.+?)(?:\.git)?$", remote)
        if m:
            url = f"https://{m.group(1)}/{m.group(2)}"
    info["repo"] = url
    return info


def dump(path: Path, obj) -> int:
    path.parent.mkdir(parents=True, exist_ok=True)
    text = json.dumps(obj, separators=(",", ":"), ensure_ascii=False)
    path.write_text(text + "\n", encoding="utf-8", newline="\n")
    return len(text)


def write_site(out: Path, funcs, areas, commits: list[Commit] | None, repo: Path = ROOT) -> dict:
    """Write the site to `out`; returns {relative path: bytes} of what it wrote."""
    summary, lists = snapshot(funcs, areas)
    history = build_history(commits, areas) if commits is not None else []

    names = {f.name for f in funcs if f.name}
    names.update(n for p in history for n in p["matched"])
    demangled = demangle(names)
    for p in history:
        p["matched"] = [demangled.get(n, n) for n in p["matched"]]

    summary["generated"] = datetime.now(timezone.utc).replace(microsecond=0).isoformat()
    summary["source"] = git_info(repo)
    summary["history"] = bool(history)

    written = {}
    out.mkdir(parents=True, exist_ok=True)
    for name in STATIC_FILES:
        shutil.copyfile(STATIC / name, out / name)
        written[name] = (out / name).stat().st_size
    (out / ".nojekyll").write_text("", encoding="utf-8")

    scope_index = {s: i for i, s in enumerate(SCOPES)}
    for i, entry in enumerate(summary["areas"]):
        entry["file"] = f"data/functions/{i}.json"
        rows = function_rows(lists.get(entry["name"], []), demangled, scope_index)
        written[entry["file"]] = dump(out / entry["file"], rows)
    written["data/summary.json"] = dump(out / "data" / "summary.json", summary)
    written["data/history.json"] = dump(out / "data" / "history.json", {
        "areas": area_order(areas), "points": history})
    return written


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("out", type=Path, help="directory to write the site to")
    ap.add_argument("--no-history", action="store_true", help="don't read git history")
    ap.add_argument("--rev", default="HEAD", help="revision whose first-parent history to read")
    args = ap.parse_args()

    funcs = read_functions_csv()
    areas = read_areas_csv()
    commits = None if args.no_history else git_log(ROOT, args.rev)
    written = write_site(args.out, funcs, areas, commits)
    total = sum(written.values())
    print(f"wrote {len(written)} files to {args.out} ({total / 1024 / 1024:.1f} MB)"
          + (f", {len(commits)} commits of history" if commits is not None else ""))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
