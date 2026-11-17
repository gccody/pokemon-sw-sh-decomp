#!/usr/bin/env python3
"""Split code into the runs of translation units that static initialisers mark,
and show the evidence in each: the strings it references, the namespaces of its
named functions, and the namespaces of the named functions it calls.

    python tools/segments.py game                        # an area of data/areas.csv, or a group (game/*)
    python tools/segments.py 0x7100890000-0x71008c0000   # an address range (--game's addresses)
    python tools/segments.py game --grep pokecamp        # only segments whose evidence matches
    python tools/segments.py game --csv segments.csv     # one row per segment

clang emits a TU's dynamic initialiser (`_GLOBAL__sub_I_<file>`) after all of
the TU's other functions, and `.init_array` lists one per TU that has one, so
every function an `.init_array` slot points at is the last function of its TU
(docs/game_code.md, "Areas"). A *segment* is the run of functions from the one
after an initialiser up to and including the next initialiser: one or more
whole TUs. Segment boundaries are the places where an area boundary can go
without splitting a TU. Inside a segment, nothing in `.init_array` says where
one TU ends and the next begins.

Evidence per segment:

- **strings**: printable C strings in `.rodata` that its code references
  (ADRP+ADD/LDR pairs and ADR, as in tools/nx/refs.py), in first-use order.
  `__FILE__` paths, resource paths and message labels name the subsystem.
- **own**: the namespaces (first two components of the nested name) of the
  segment's functions that data/functions.csv names, with counts.
- **calls**: the namespaces of named functions outside the segment that its
  code calls (B/BL), with counts. Callers of a subsystem's classes are usually
  that subsystem's own code, so this shows how far a subsystem reaches past the
  TUs that name it.

Addresses are --game's (default sword). Every figure is computed from that
game's executable and its column of data/functions.csv.
"""
from __future__ import annotations

import argparse
import bisect
import csv
import re
import struct
import sys
from collections import Counter
from dataclasses import dataclass, field
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import (  # noqa: E402
    BASE, ROOT, VERSIONS, area_names, area_span, load_module, nso_path, read_areas_csv, read_functions_csv,
)

DT_INIT_ARRAY = 25
DT_INIT_ARRAYSZ = 27
MIN_STRING = 4


def dynamic_tags(img: bytes, dynamic: int) -> dict[int, int]:
    """The DT_* entries of the dynamic section at `dynamic` (image offset)."""
    tags: dict[int, int] = {}
    while True:
        tag, value = struct.unpack_from("<qQ", img, dynamic)
        dynamic += 16
        if tag == 0:
            return tags
        tags.setdefault(tag, value)


def init_array_targets(tags: dict[int, int], slots: dict[int, int | str]) -> list[int]:
    """The functions `.init_array` points at, in slot order.

    `slots` maps a relocated slot to its target (tools/nx/module.py's
    DynInfo.slots): a PIE's `.init_array` holds R_AARCH64_RELATIVE slots."""
    start, size = tags.get(DT_INIT_ARRAY), tags.get(DT_INIT_ARRAYSZ, 0)
    if start is None:
        return []
    out = []
    for slot in range(start, start + size, 8):
        target = slots.get(slot)
        if isinstance(target, int):
            out.append(target)
    return out


def segments(starts: list[int], inits: list[int], lo: int, hi: int) -> list[tuple[int, int]]:
    """[start, end) runs of the functions in [lo, hi) that the initialisers end.

    `starts` are the sorted function starts. A segment ends after each
    initialiser; `lo` and `hi` cut too (a range needn't start at a segment
    boundary)."""
    cuts = {lo, hi}
    init_set = set(inits)
    for i, s in enumerate(starts):
        if s in init_set and lo <= s < hi and i + 1 < len(starts) and starts[i + 1] < hi:
            cuts.add(starts[i + 1])
    edges = sorted(c for c in cuts if lo <= c <= hi)
    return [(a, b) for a, b in zip(edges, edges[1:]) if a < b]


_LEN = re.compile(r"\d+")


def name_scope(name: str, depth: int = 2) -> str | None:
    """The first `depth` components of a mangled nested name ("btl::net"), or
    None when the name isn't a nested `_ZN...E` one (C functions, file-local
    `name@stem` of C code). Substitutions and templates end the scan."""
    name = name.split("@", 1)[0]
    if not name.startswith("_ZN"):
        return None
    s = name[3:]
    while s[:1] in ("K", "V", "r"):  # cv-qualifiers of a member function
        s = s[1:]
    parts: list[str] = []
    while len(parts) < depth:
        m = _LEN.match(s)
        if not m:
            break
        n = int(m.group(0))
        part = s[m.end():m.end() + n]
        if len(part) < n:
            break
        parts.append(part)
        s = s[m.end() + n:]
    if not parts:
        return None
    if parts[0] == "St3__1" or parts[0].startswith("__"):
        return None
    return "::".join(parts)


def c_string(img: bytes, addr: int, lo: int, hi: int, max_len: int = 512) -> str | None:
    """The printable NUL-terminated string at `addr` if it lies in [lo, hi)."""
    if not lo <= addr < hi:
        return None
    end = img.find(b"\0", addr, min(hi, addr + max_len))
    if end < 0 or end - addr < MIN_STRING:
        return None
    raw = img[addr:end]
    if not all(32 <= c < 127 for c in raw):
        return None
    return raw.decode("ascii")


@dataclass
class Segment:
    start: int
    end: int
    functions: int = 0
    matching: int = 0
    strings: list[str] = field(default_factory=list)
    own: Counter = field(default_factory=Counter)
    calls: Counter = field(default_factory=Counter)

    @property
    def size(self) -> int:
        return self.end - self.start

    def evidence(self) -> str:
        return " ".join([*self.strings, *self.own, *self.calls])


def analyse(img: bytes, funcs: list[tuple[int, int]], inits: list[int], names: dict[int, str],
            statuses: dict[int, str], rodata: tuple[int, int], lo: int, hi: int) -> list[Segment]:
    """Segments of [lo, hi) with their evidence (see the module docstring)."""
    from nx.refs import decode, is_b_bl

    starts = [s for s, _ in funcs]
    sizes = dict(funcs)
    scopes = {a: sc for a, n in names.items() if (sc := name_scope(n))}
    out = []
    for a, b in segments(starts, inits, lo, hi):
        seg = Segment(a, b)
        seen: set[str] = set()
        for s in starts[bisect.bisect_left(starts, a):bisect.bisect_left(starts, b)]:
            seg.functions += 1
            seg.matching += statuses.get(s) == "O"
            if s in scopes:
                seg.own[scopes[s]] += 1
            for _, w, _, target in decode(img, s, sizes[s]):
                if target is None:
                    continue
                if is_b_bl(w):
                    if not a <= target < b and target in scopes:
                        seg.calls[scopes[target]] += 1
                    continue
                text = c_string(img, target, *rodata)
                if text is not None and text not in seen:
                    seen.add(text)
                    seg.strings.append(text)
        out.append(seg)
    return out


def parse_range(spec: str, game: str, areas_csv: Path) -> tuple[int, int]:
    if "-" in spec and spec.lower().startswith("0x"):
        lo, hi = (int(x, 16) for x in spec.split("-"))
        return lo - BASE if lo >= BASE else lo, hi - BASE if hi >= BASE else hi
    areas = read_areas_csv(areas_csv)
    if spec not in area_names(areas):
        raise SystemExit(f"{spec!r} is neither LO-HI nor an area of {areas_csv.name}")
    try:
        rng = area_span(areas, spec, game)
    except ValueError as e:
        raise SystemExit(str(e)) from None
    if rng is None:
        raise SystemExit(f"area {spec} has no {game} range")
    return rng


def format_segment(seg: Segment, max_strings: int) -> list[str]:
    lines = [f"0x{seg.start + BASE:x}-0x{seg.end + BASE:x}  {seg.functions} functions, "
             f"{seg.size} bytes, {seg.matching} matching"]
    if seg.own:
        lines.append("    own:   " + ", ".join(f"{k} {v}" for k, v in seg.own.most_common()))
    if seg.calls:
        lines.append("    calls: " + ", ".join(f"{k} {v}" for k, v in seg.calls.most_common()))
    for text in seg.strings[:max_strings]:
        lines.append(f"    {text[:120]}")
    if len(seg.strings) > max_strings:
        lines.append(f"    ... {len(seg.strings) - max_strings} more strings")
    return lines


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("target", help="an area of data/areas.csv, or LO-HI in --game's addresses")
    ap.add_argument("--game", choices=VERSIONS, default="sword")
    ap.add_argument("--grep", help="only segments whose evidence matches this regular expression")
    ap.add_argument("--strings", type=int, default=8, help="strings shown per segment (default 8)")
    ap.add_argument("--csv", type=Path, help="write Start,End,Functions,Bytes,Matching,Own,Calls,Strings")
    ap.add_argument("--areas-csv", type=Path, default=ROOT / "data" / "areas.csv")
    ap.add_argument("--functions-csv", type=Path, default=ROOT / "data" / "functions.csv")
    args = ap.parse_args(argv)

    from nx.module import DynInfo
    from nx.nso import Nso

    lo, hi = parse_range(args.target, args.game, args.areas_csv)
    mod = load_module(args.game)
    img = mod["image"]
    nso = Nso(nso_path(args.game).read_bytes())
    dyn = DynInfo(nso, img, mod["text_end"])
    inits = init_array_targets(dynamic_tags(img, nso.mod0.dynamic), dyn.slots)
    rows = [f for f in read_functions_csv(args.functions_csv) if f.in_version(args.game)]
    names = {f.addr(args.game): f.name for f in rows if f.name}
    statuses = {f.addr(args.game): f.status for f in rows}
    segs = analyse(img, mod["functions"], inits, names, statuses, mod["rodata"], lo, hi)
    if args.grep:
        pat = re.compile(args.grep)
        segs = [s for s in segs if pat.search(s.evidence())]
    if args.csv:
        with open(args.csv, "w", newline="", encoding="utf-8") as f:
            w = csv.writer(f, lineterminator="\n")
            w.writerow(["Start", "End", "Functions", "Bytes", "Matching", "Own", "Calls", "Strings"])
            for s in segs:
                w.writerow([f"0x{s.start + BASE:x}", f"0x{s.end + BASE:x}", s.functions, s.size, s.matching,
                            "; ".join(f"{k} {v}" for k, v in s.own.most_common()),
                            "; ".join(f"{k} {v}" for k, v in s.calls.most_common()),
                            " | ".join(s.strings)])
    else:
        for s in segs:
            print("\n".join(format_segment(s, args.strings)))
    print(f"{len(segs)} segments, {sum(s.functions for s in segs)} functions", file=sys.stderr)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
