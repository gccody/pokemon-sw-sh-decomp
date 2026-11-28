#!/usr/bin/env python3
"""Split the remaining work into units that parallel workers can take, one each.

    python tools/units.py list                     # units of U functions, easiest first
    python tools/units.py list --mm                # the later list: units of m/M functions
    python tools/units.py list --area game/bag -n 20
    python tools/units.py show u7c3a40             # one unit: its file, its functions, their callees
    python tools/units.py record name 0x71007c3a40 _ZN4pkmn3FooEv     # name it here + in the sidecar
    python tools/units.py record status 0x71007c3a40 M "loop is unrolled differently"
    python tools/units.py record retype 0x71007cd220 _Z15Unk_7cd220_callPK10Unk_7cd220h   # tools/retype.py here
    python tools/units.py record report "matched 9; the struct at x0 is Unk_7c3a40 (0x48 bytes)"
    python tools/units.py sidecar                  # print this checkout's sidecar

A unit is a run of consecutive functions inside one segment (tools/segments.py:
the functions between two static initialisers, one or more whole TUs) and one
area of data/areas.csv. Long segments are cut into chunks of at most
MAX_FUNCS functions and MAX_BYTES bytes, counting every function whatever its
status, so a unit's ID (`u` + the Sword offset of its first function) and its
extent stay the same as functions get matched. A unit is listed while it still
has a function of the statuses asked for (U, or m/M with --mm).

No cut goes through a *tied block* (tied_blocks): functions that have to be
in one file, a TU's local call graph (a call to a helper only the segment
calls, from nearby) and a class (the functions that address its vtable group,
and the slot functions it owns). Such a block can make a part or a unit
larger than the limits, up to GROUP_CAP_FUNCS functions and GROUP_CAP_BYTES
bytes. A block above the cap is tied again with fewer ties (TIE_LEVELS); what
is still above it is cut as before, and `show` says so. Only the stretches
that a block crosses are cut again, so the other units keep their IDs.
`show` also lists, per function, its callees in the unit: the original calls
them out of line, so a small one in the same file needs one of the two in an
`Unk_<addr>.cpp` of its own (clang would inline it).

Every unit gets one source file, and no two units share one:

- a hand-written file that already holds functions of the unit (found by the
  `// 0x71...` address comments above functions) if no earlier unit took it;
- otherwise a new `Unk_<start>.cpp` in the directory where the area's
  hand-written files mostly are (`src/unsorted/<area>` or `lib/<area>` if
  there's none yet).

The generators' directories (GENERATED_DIRS) are never a unit's file: their
files are rewritten by tools, not edited by hand. Areas in EXCLUDED_AREAS
(yebis, worked on separately) have no units.

Units are ordered easiest first by a score: the bytes of their remaining
functions, plus CALL_COST per call and UNKNOWN_COST per call to a function
that is neither matched nor named, per function to do (so small leaf
functions come first), and among units of about the same difficulty, the
ones with more functions to do first. A function of a shape that waits for
its class (a lone `b T` forwarder, a `sub x0, x0, #N ; b T` thunk: see
docs/game_code.md, "What's left of the small functions") costs BLOCKED_COST
more, so those come after code that can be written now.

The sidecar (`.swarm/sidecar.json`, untracked) records what a worker found
that belongs in data/functions.csv: names (with the evidence) and m/M
statuses with their NON_MATCHING reasons, plus a free-form report.
`record name` and `record status` also apply the change to this checkout's
data/functions.csv through tools/funcs.py, so check.py works here, but
workers never commit that file: tools/integrate.py re-applies the sidecar on
top of the stack, where check.py --update decides the statuses. `record
retype` (a callee's parameter types) runs tools/retype.py --apply here and
records it only if that succeeds; integrate.py runs it again on the stack.
"""
from __future__ import annotations

import argparse
import bisect
import json
import re
import subprocess
import sys
from collections import Counter
from dataclasses import dataclass, field
from functools import cached_property
from pathlib import Path, PurePosixPath

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BASE, ROOT, AreaMap, Function, in_area, read_areas_csv, read_functions_csv  # noqa: E402

MAX_FUNCS = 16        # per part (one source file)
MAX_BYTES = 2048
UNIT_FUNCS = 32       # per unit (consecutive parts of one area)
UNIT_BYTES = 4096
GROUP_CAP_FUNCS = 6 * UNIT_FUNCS   # a tied block (tied_blocks) larger than this is cut as before
GROUP_CAP_BYTES = 6 * UNIT_BYTES
NEAR_CALL = 8                      # a call ties caller and callee up to this many functions apart
INLINE_BYTES = 128                 # `show`: a same-file callee up to this size, clang would likely inline
# A tied block above the cap is tied again with fewer ties (tied_blocks), level by level; what's
# still above the cap after the last level is cut as if it weren't tied.
TIE_LEVELS = ({}, {"members": False}, {"classes": False, "near": 4}, {"classes": False, "near": 1})
CALL_COST = 8
UNKNOWN_COST = 48
DIFFICULTY_STEP = 16
BLOCKED_COST = 256
EXCLUDED_AREAS = ("yebis",)
GENERATED_DIRS = (
    "src/unsorted/leaf", "src/unsorted/virtual", "src/unsorted/ctor", "src/unsorted/types",
    "src/unsorted/clone", "src/unsorted/families", "src/unsorted/init", "src/unsorted/locks",
    "src/unsorted/registry", "src/gflib3/families", "lib/nx_middleware/leaf", "lib/nx_middleware/class",
    "lib/wwise/leaf", "lib/wwise/class", "lib/pia/gen", "lib/nex/ddl",
)
# Directories of vendored code compiled from upstream source: not scanned for address comments.
UNSCANNED_DIRS = ("lib/physx", "lib/yebis", "lib/protobuf", "lib/lua", "lib/curl", "lib/freetype",
                  "lib/zlib", "lib/miniz", "lib/sol", "lib/tlsf")
SOURCE_SUFFIXES = (".cpp", ".cc", ".c", ".h", ".hpp", ".inl")
SIDECAR = ROOT / ".swarm" / "sidecar.json"

# `// 0x7100bc0b00 ...` or `// Sword 0x7100bc0b00, Shield ...` above a function
ADDR_COMMENT = re.compile(r"^[ \t]*//[ \t]*(?:sword:?[ \t]*)?0x(71[0-9a-f]{8})\b", re.M | re.I)


# --------------------------------------------------------------------------- pure parts (tested)
def is_generated(path: str) -> bool:
    return any(path == d or path.startswith(d + "/") for d in GENERATED_DIRS)


def address_comments(text: str) -> list[int]:
    """Offsets (relative to BASE) named by the address comments of a source file."""
    return [int(m.group(1), 16) - BASE for m in ADDR_COMMENT.finditer(text)]


def _bytes(funcs: list[Function]) -> int:
    return sum(f.sword_size or 0 for f in funcs)


def pack(atoms: list[list[Function]], max_funcs: int = MAX_FUNCS, max_bytes: int = MAX_BYTES) -> list[list[Function]]:
    """Cut a run of atoms (runs of consecutive functions that stay together)
    into chunks of at most max_funcs functions and max_bytes bytes. An atom
    larger than that is a chunk of its own."""
    out: list[list[Function]] = []
    cur: list[Function] = []
    size = 0
    for atom in atoms:
        n = _bytes(atom)
        if cur and (len(cur) + len(atom) > max_funcs or size + n > max_bytes):
            out.append(cur)
            cur, size = [], 0
        cur.extend(atom)
        size += n
    if cur:
        out.append(cur)
    return out


def chunk(funcs: list[Function], max_funcs: int = MAX_FUNCS, max_bytes: int = MAX_BYTES) -> list[list[Function]]:
    """Cut a run of consecutive functions (sorted by Sword address) into chunks
    of at most max_funcs functions and max_bytes bytes. A function larger than
    max_bytes is a chunk of its own."""
    return pack([[f] for f in funcs], max_funcs, max_bytes)


@dataclass
class Links:
    """What ties functions to one file, from the executable (load_links)."""
    calls: dict[int, set[int]] = field(default_factory=dict)    # function -> the functions it calls (B/BL)
    vtables: dict[int, set[int]] = field(default_factory=dict)  # function -> the vtable groups it addresses
    members: dict[int, set[int]] = field(default_factory=dict)  # vtable group -> the slot functions it owns
    taken: set[int] = field(default_factory=set)  # functions whose address code or data takes (not B/BL)

    @cached_property
    def callers(self) -> dict[int, set[int]]:
        out: dict[int, set[int]] = {}
        for f, ts in self.calls.items():
            for t in ts:
                out.setdefault(t, set()).add(f)
        return out

    @cached_property
    def referrers(self) -> dict[int, set[int]]:
        out: dict[int, set[int]] = {}
        for f, gs in self.vtables.items():
            for g in gs:
                out.setdefault(g, set()).add(f)
        return out


def tied_blocks(run: list[Function], links: Links, near: int = NEAR_CALL, classes: bool = True,
                members: bool = True, bounds: tuple[int, int] | None = None) -> list[tuple[int, int]]:
    """[lo, hi] index ranges of `run` (the functions of one segment and area,
    in address order) that no cut may go through: the span of each group of
    functions tied together, with overlapping spans merged. Ties:

    - a call (B/BL) to a function of the run that only the run calls, from at
      most `near` functions away: a TU's own helper (clang emits a static
      function next to its first caller);
    - the functions that address one vtable group, when all of them are in
      the run (a class's constructors and destructors, and whatever else sets
      its vptr: the class's TU), together with the slot functions of the
      group that it owns (tools/vtables.py owners: the class's members).

    Calls from far away, or to a function other code calls too, and vtables
    that code outside the run addresses as well (a base class whose inline
    destructor every derived class's has), don't tie: they're what chains
    separate TUs of a segment together.

    `classes` and `members` turn the vtable ties (all, or the slot functions)
    off; `bounds` ([start, end) offsets, default the run's) is what "the run"
    means for "only the run calls it", when `run` is part of a longer one."""
    last = run[-1]
    lo_a, hi_a = bounds or (run[0].sword, last.sword + (last.sword_size or 0))
    idx = {f.sword: i for i, f in enumerate(run)}
    parent = list(range(len(run)))

    def find(i: int) -> int:
        while parent[i] != i:
            parent[i] = parent[parent[i]]
            i = parent[i]
        return i

    def union(i: int, j: int) -> None:
        a, b = find(i), find(j)
        if a != b:
            parent[max(a, b)] = min(a, b)

    def local(fs) -> bool:
        return all(lo_a <= x < hi_a for x in fs)

    first_of: dict[int, int] = {}
    for i, f in enumerate(run):
        for t in links.calls.get(f.sword, ()):
            j = idx.get(t)
            if j is not None and abs(i - j) <= near and local(links.callers.get(t, ())):
                union(i, j)
        for g in links.vtables.get(f.sword, ()) if classes else ():
            if g not in first_of:
                first_of[g] = i if local(links.referrers[g]) else -1
                if first_of[g] >= 0 and members:
                    for x in links.members.get(g, ()):
                        j = idx.get(x)
                        if j is not None:
                            union(i, j)
            if first_of[g] >= 0:
                union(i, first_of[g])
    span: dict[int, list[int]] = {}
    for i in range(len(run)):
        lo_hi = span.setdefault(find(i), [i, i])
        lo_hi[1] = i
    out: list[tuple[int, int]] = []
    for lo, hi in sorted(tuple(v) for v in span.values() if v[0] < v[1]):
        if out and lo <= out[-1][1]:
            out[-1] = (out[-1][0], max(out[-1][1], hi))
        else:
            out.append((lo, hi))
    return out


def tie_run(run: list[Function], links: Links, cap_funcs: int | None = None,
             cap_bytes: int | None = None) -> tuple[list[tuple[int, int]], list[tuple[int, int]]]:
    """The tied blocks of a run ([lo, hi] indexes, in order) within the cap,
    and the (start, end) offsets of the blocks above it with every tie (a
    region where some ties get cut: crossing_ties says which). A block above
    the cap at one level is tied again, inside itself, at the next
    (TIE_LEVELS). The caps default to GROUP_CAP_FUNCS/GROUP_CAP_BYTES."""
    cap_funcs = cap_funcs or GROUP_CAP_FUNCS
    cap_bytes = cap_bytes or GROUP_CAP_BYTES
    keep: list[tuple[int, int]] = []
    over: list[tuple[int, int]] = []
    last = run[-1]
    bounds = (run[0].sword, last.sword + (last.sword_size or 0))

    def split(lo: int, hi: int, level: int) -> None:
        sub = run[lo:hi + 1]
        for a, b in tied_blocks(sub, links, bounds=bounds, **TIE_LEVELS[level]):
            if b - a + 1 <= cap_funcs and _bytes(sub[a:b + 1]) <= cap_bytes:
                keep.append((lo + a, lo + b))
                continue
            if level == 0:
                end = sub[b]
                over.append((sub[a].sword, end.sword + (end.sword_size or 0)))
            if level + 1 < len(TIE_LEVELS):
                split(lo + a, lo + b, level + 1)

    split(0, len(run) - 1, 0)
    return sorted(keep), over


def cut_run(run: list[Function], links: Links | None, max_funcs: int = MAX_FUNCS, max_bytes: int = MAX_BYTES,
            cap_funcs: int | None = None, cap_bytes: int | None = None
            ) -> tuple[list[list[Function]], list[tuple[int, int]]]:
    """The parts of a run (tie_run), and the (start, end) offsets of the tied
    blocks above the cap, which are cut as if they weren't tied.

    The cuts are chunk()'s, minus the ones inside a tied block; only a stretch
    between two cuts that survive is cut again (with the blocks as atoms), so
    the parts elsewhere, and their starts, stay what chunk() gives."""
    old = chunk(run, max_funcs, max_bytes)
    if links is None:
        return old, []
    keep, over = tie_run(run, links, cap_funcs, cap_bytes)
    if not keep:
        return old, over
    inside: set[int] = set()
    for lo, hi in keep:
        inside.update(range(lo + 1, hi + 1))
    cuts, i = set(), 0
    for c in old:
        if i not in inside:
            cuts.add(i)
        i += len(c)
    block_at = dict(keep)
    stretches: list[list[list[Function]]] = []
    i = 0
    while i < len(run):
        hi = block_at.get(i, i)
        if i in cuts or not stretches:
            stretches.append([])
        stretches[-1].append(run[i:hi + 1])
        i = hi + 1
    return [p for st in stretches for p in pack(st, max_funcs, max_bytes)], over


def unit_id(start: int) -> str:
    return f"u{start:x}"


def parse_unit_id(s: str) -> int:
    s = s.strip().lower()
    if not re.fullmatch(r"u[0-9a-f]+", s):
        raise SystemExit(f"{s!r} isn't a unit ID (u<hex>)")
    return int(s[1:], 16)


@dataclass
class Part:
    """A chunk of one segment: the functions that go in one source file."""
    funcs: list[Function]
    segment: tuple[int, int]
    area: str
    file: str = ""
    new_file: bool = True

    @property
    def start(self) -> int:
        return self.funcs[0].sword


@dataclass
class Unit:
    id: str
    area: str
    kind: str
    parts: list[Part]
    score: int = 0
    work: list[Function] = field(default_factory=list)   # the functions of the statuses asked for
    calls: dict[int, list[int]] = field(default_factory=dict)  # function -> its callees (Sword offsets)
    loose: list[tuple[int, int]] = field(default_factory=list)  # tied blocks above the cap (tie_run)

    @property
    def funcs(self) -> list[Function]:
        return [f for p in self.parts for f in p.funcs]

    @property
    def start(self) -> int:
        return self.parts[0].start

    @property
    def end(self) -> int:
        last = self.parts[-1].funcs[-1]
        return last.sword + (last.sword_size or 0)

    @property
    def work_bytes(self) -> int:
        return sum(f.sword_size or 0 for f in self.work)

    @property
    def files(self) -> list[str]:
        return [p.file for p in self.parts]

    def file_of(self, f: Function) -> str:
        return next(p.file for p in self.parts if f in p.funcs)


def area_dirs(index: dict[int, str], amap: AreaMap, areas) -> dict[str, str]:
    """Area -> the directory most of its hand-written files are in (by address comments)."""
    per: dict[str, Counter] = {}
    for addr, path in index.items():
        if is_generated(path):
            continue
        a = amap.area_of(addr)
        if a is not None:
            per.setdefault(a, Counter())[str(PurePosixPath(path).parent)] += 1
    out = {}
    for a in areas:
        if a.name in per:
            out[a.name] = per[a.name].most_common(1)[0][0]
        else:
            leaf = a.name.split("/")[-1]
            out[a.name] = f"src/unsorted/{leaf}" if a.kind == "game" else f"lib/{leaf}"
    return out


def source_files(index: dict[int, str]) -> list[tuple[int, str]]:
    """The hand-written files of `index` a new file may go next to: sorted
    (offset, path), without generated files and headers under `include`.
    Built once per run: nearest_dir runs for every new part (~13k)."""
    return sorted((a, p) for a, p in index.items()
                  if not is_generated(p) and "include" not in PurePosixPath(p).parts)


def nearest_dir(addr: int, area: str, hand: list[tuple[int, str]], amap: AreaMap) -> str | None:
    """The directory of the hand-written file whose address comment is nearest
    to `addr` in the same area (`hand`: sorted (offset, path), without the
    files under an `include` directory: a new source file never goes there;
    see source_files)."""
    i = bisect.bisect_left(hand, (addr, ""))
    best = None
    for j in (i - 1, i):
        if 0 <= j < len(hand) and amap.area_of(hand[j][0]) == area:
            d = abs(hand[j][0] - addr)
            if best is None or d < best[0]:
                best = (d, hand[j][1])
    return str(PurePosixPath(best[1]).parent) if best else None


def assign_files(parts: list[Part], index: dict[int, str], dirs: dict[str, str], amap: AreaMap | None = None,
                 exists=lambda p: False) -> None:
    """Give every part its own source file (see the module docstring). `parts`
    must be every part (whatever its status), in address order, so the choice
    doesn't depend on which units are listed. A new file goes in the directory
    of the nearest hand-written file of the area (libraries of one area, like
    NEX and Pia in `middleware`, are built with different settings), else in
    the area's directory."""
    hand = source_files(index)
    claimed: set[str] = set()
    for u in parts:
        homes = Counter(index[f.sword] for f in u.funcs if f.sword in index and not is_generated(index[f.sword]))
        pick = next((p for p, _ in homes.most_common() if p not in claimed and p.endswith((".cpp", ".cc", ".c"))),
                    None)
        if pick is None:
            d = (nearest_dir(u.start, u.area, hand, amap) if amap else None) or dirs[u.area]
            u.file = f"{d}/Unk_{u.start:x}.cpp"
            u.new_file = not exists(u.file)
        else:
            u.file = pick
            u.new_file = False
        claimed.add(u.file)


B_MASK, B_OP = 0xFC000000, 0x14000000


def blocked_shape(words: list[int]) -> bool:
    """A lone `b T`, or `sub x0, x0, #N ; b T`: forwarders and thunks that the
    compiler emits with the class they belong to (docs/game_code.md)."""
    if len(words) == 1:
        return words[0] & B_MASK == B_OP
    if len(words) == 2:
        sub_x0 = (words[0] & 0xFF8003FF) == 0xD1000000  # sub x0, x0, #imm
        return sub_x0 and words[1] & B_MASK == B_OP
    return False


def score_unit(u: Unit, by_addr: dict[int, Function], blocked=lambda f: False) -> int:
    total = 0
    for f in u.work:
        total += f.sword_size or 0
        if blocked(f):
            total += BLOCKED_COST
        for t in u.calls.get(f.sword, []):
            callee = by_addr.get(t)
            total += CALL_COST
            if callee is None or (callee.status != "O" and not callee.name):
                total += UNKNOWN_COST
    return total


def group_parts(parts: list[Part], max_funcs: int = UNIT_FUNCS, max_bytes: int = UNIT_BYTES) -> list[list[Part]]:
    """Consecutive parts of one area, together up to max_funcs functions and
    max_bytes bytes (every function counts, whatever its status, so the groups
    don't move as functions match)."""
    out: list[list[Part]] = []
    n = size = 0
    for p in parts:
        pn, ps = len(p.funcs), sum(f.sword_size or 0 for f in p.funcs)
        if out and out[-1][-1].area == p.area and n + pn <= max_funcs and size + ps <= max_bytes:
            out[-1].append(p)
            n += pn
            size += ps
        else:
            out.append([p])
            n, size = pn, ps
    return out


def group_stable(parts: list[Part], old_parts: list[Part], max_funcs: int = UNIT_FUNCS,
                 max_bytes: int = UNIT_BYTES) -> list[list[Part]]:
    """group_parts(parts), keeping the units that group_parts(old_parts) gives
    where they didn't change: `parts` are old_parts with some of them merged
    or re-cut (cut_run), so only a stretch between two old unit starts that
    are still part starts is grouped again."""
    old_starts = {g[0].start for g in group_parts(old_parts, max_funcs, max_bytes)}
    stretches: list[list[Part]] = []
    for p in parts:
        if not stretches or p.start in old_starts:
            stretches.append([])
        stretches[-1].append(p)
    return [g for st in stretches for g in group_parts(st, max_funcs, max_bytes)]


def build_units(rows: list[Function], areas, seg_bounds: list[tuple[int, int]],
                index: dict[int, str], statuses: str = "U", exists=lambda p: False,
                calls_of=lambda f: [], unit_funcs: int = UNIT_FUNCS, unit_bytes: int = UNIT_BYTES,
                blocked=lambda f: False, links: Links | None = None) -> list[Unit]:
    """Every unit of the executable (the ones without work too), in address
    order. `calls_of(f)` gives the Sword offsets function f calls. With
    `links`, no part or unit splits a tied block (cut_run)."""
    amap = AreaMap(areas, "sword")
    kinds = {a.name: a.kind for a in areas}
    funcs = sorted((r for r in rows if r.sword is not None), key=lambda r: r.sword)
    starts = [f.sword for f in funcs]
    parts: list[Part] = []
    old_parts: list[Part] = []
    loose: list[tuple[int, int]] = []
    for a, b in seg_bounds:
        run = funcs[bisect.bisect_left(starts, a):bisect.bisect_left(starts, b)]
        # cut at area boundaries too
        groups: list[tuple[str | None, list[Function]]] = []
        for f in run:
            area = amap.area_of(f.sword)
            if not groups or groups[-1][0] != area:
                groups.append((area, []))
            groups[-1][1].append(f)
        for area, g in groups:
            if area is None or any(in_area(area, x) for x in EXCLUDED_AREAS):
                continue
            cut, over = cut_run(g, links)
            parts.extend(Part(c, (a, b), area) for c in cut)
            old_parts.extend(Part(c, (a, b), area) for c in chunk(g))
            loose.extend(over)
    assign_files(parts, index, area_dirs(index, amap, areas), amap, exists)
    by_addr = {f.sword: f for f in funcs}
    units = []
    for g in group_stable(parts, old_parts, unit_funcs, unit_bytes):
        u = Unit(unit_id(g[0].start), g[0].area, kinds.get(g[0].area, ""), g)
        u.loose = [(lo, hi) for lo, hi in loose if lo < u.end and u.start < hi]
        u.work = [f for f in u.funcs if f.status in statuses]
        for f in u.work:
            u.calls[f.sword] = [t for t in calls_of(f) if t != f.sword]
        u.score = score_unit(u, by_addr, blocked)
        units.append(u)
    return units


def difficulty(u: Unit) -> int:
    """A unit's score per function to do, in steps of DIFFICULTY_STEP."""
    return u.score // max(1, len(u.work)) // DIFFICULTY_STEP


def ordered(units: list[Unit]) -> list[Unit]:
    """Units with work, easiest first: by score per function, then the ones with
    more to do first (a worker's setup and first build cost the same either way)."""
    return sorted((u for u in units if u.work), key=lambda u: (difficulty(u), -len(u.work), u.start))


# --------------------------------------------------------------------------- sidecar (tested)
def read_sidecar(path: Path = SIDECAR) -> dict:
    if not path.exists():
        return {"unit": "", "base": "", "names": [], "statuses": [], "report": ""}
    data = json.loads(path.read_text(encoding="utf-8"))
    data.setdefault("unit", "")
    data.setdefault("base", "")
    data.setdefault("names", [])
    data.setdefault("statuses", [])
    data.setdefault("retypes", [])
    data.setdefault("report", "")
    return data


def write_sidecar(data: dict, path: Path = SIDECAR) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(data, indent=2) + "\n", encoding="utf-8")


def sidecar_name(data: dict, addr: str, name: str, evidence: str = "") -> None:
    data["names"] = [n for n in data["names"] if n["addr"] != addr]
    data["names"].append({"addr": addr, "name": name, "evidence": evidence})


def sidecar_retype(data: dict, addr: str, name: str, old: str) -> None:
    data.setdefault("retypes", [])
    data["retypes"] = [r for r in data["retypes"] if r["addr"] != addr]
    data["retypes"].append({"addr": addr, "name": name, "old": old})


def sidecar_status(data: dict, addr: str, status: str, reason: str) -> None:
    if status not in ("m", "M"):
        raise SystemExit("a recorded status is m or M (matches come from check.py --update)")
    if not reason.strip():
        raise SystemExit("give the NON_MATCHING reason")
    data["statuses"] = [s for s in data["statuses"] if s["addr"] != addr]
    data["statuses"].append({"addr": addr, "status": status, "reason": reason})


def norm_addr(s: str) -> str:
    a = int(s, 16)
    return f"0x{a if a >= BASE else a + BASE:x}"


# --------------------------------------------------------------------------- executable-backed parts
def source_index(root: Path = ROOT) -> dict[int, str]:
    """Sword offset -> the source file (repo-relative, POSIX) whose address comment names it."""
    out: dict[int, str] = {}
    for top in ("src", "lib"):
        base = root / top
        if not base.exists():
            continue
        for p in sorted(base.rglob("*")):
            if p.suffix not in SOURCE_SUFFIXES or not p.is_file():
                continue
            rel = p.relative_to(root).as_posix()
            if any(rel.startswith(d + "/") for d in UNSCANNED_DIRS):
                continue
            try:
                text = p.read_text(encoding="utf-8", errors="replace")
            except OSError:
                continue
            for a in address_comments(text):
                # a .cpp beats the header that declares it
                if a not in out or (out[a].endswith((".h", ".hpp", ".inl")) and not rel.endswith((".h", ".hpp"))):
                    out[a] = rel
    return out


def exe_segments(game: str = "sword") -> list[tuple[int, int]]:
    """Segment bounds (tools/segments.py) over the whole of `game`'s code."""
    from nx.module import DynInfo
    from nx.nso import Nso
    from common import load_module, nso_path
    import segments as seg

    mod = load_module(game)
    img = mod["image"]
    nso = Nso(nso_path(game).read_bytes())
    dyn = DynInfo(nso, img, mod["text_end"])
    inits = seg.init_array_targets(seg.dynamic_tags(img, nso.mod0.dynamic), dyn.slots)
    starts = [s for s, _ in mod["functions"]]
    return seg.segments(starts, inits, 0, mod["text_end"])


def callees_fn(img: bytes):
    from nx.refs import decode, is_b_bl

    def calls_of(f: Function) -> list[int]:
        a, n = f.sword, f.sword_size or 0
        out = []
        for _, w, _, t in decode(img, a, n):
            if t is not None and is_b_bl(w) and not a <= t < a + n and t not in out:
                out.append(t)
        return out
    return calls_of


def blocked_fn(img: bytes):
    import struct

    def blocked(f: Function) -> bool:
        n = (f.sword_size or 0) // 4
        return n <= 2 and blocked_shape(list(struct.unpack_from(f"<{n}I", img, f.sword)))
    return blocked


def exe_links(img: bytes, funcs: list[tuple[int, int]], slots: dict[int, int | str], vtables) -> Links:
    """Links of every function in `funcs` ((start, size), relative): its B/BL
    targets that are function starts, the vtable groups (tools/vtables.py) it
    addresses, directly (adrp+add/ldr of the vtable or its address point) or
    through a GOT slot, the slot functions each vtable group owns, and which
    functions have their address taken (by code, or by a relocated slot in the
    data: vtables, function tables)."""
    from nx.refs import decode, is_b_bl

    starts = {s for s, _ in funcs}
    group = {}
    for v in vtables:
        group[v.addr] = group[v.start] = v.group
    got = {s: group[t] for s, t in slots.items() if isinstance(t, int) and t in group}
    import vtables as V

    links = Links(taken={t for t in slots.values() if isinstance(t, int) and t in starts})
    for f, (vt, _) in V.owners(vtables).items():
        links.members.setdefault(group[vt], set()).add(f)
    for s, n in funcs:
        calls: set[int] = set()
        vts: set[int] = set()
        for _, w, _, t in decode(img, s, n):
            if t is None:
                continue
            if is_b_bl(w):
                if t in starts and t != s:
                    calls.add(t)
            elif (g := group.get(t, got.get(t))) is not None:
                vts.add(g)
            elif t in starts and t != s:
                links.taken.add(t)
        if calls:
            links.calls[s] = calls
        if vts:
            links.vtables[s] = vts
    return links


def load_links(game: str = "sword") -> Links:
    from common import load_module, nso_path
    from nx.module import DynInfo
    from nx.nso import Nso
    import vtables as V

    mod = load_module(game)
    img = mod["image"]
    nso = Nso(nso_path(game).read_bytes())
    dyn = DynInfo(nso, img, mod["text_end"])
    vts, _ = V.find_vtables(img, dyn.slots, {s for s, _ in mod["functions"]}, nso.data.mem_off, nso.data.end)
    return exe_links(img, mod["functions"], dyn.slots, vts)


def load_units(statuses: str = "U", links: Links | None = None,
               index: dict[int, str] | None = None) -> tuple[list[Unit], list[Function]]:
    from common import load_module

    rows = read_functions_csv()
    img = load_module("sword")["image"]
    units = build_units(rows, read_areas_csv(), exe_segments("sword"), index or source_index(), statuses,
                        exists=lambda p: (ROOT / p).exists(), calls_of=callees_fn(img), blocked=blocked_fn(img),
                        links=links or load_links("sword"))
    return units, rows


def find_unit(units: list[Unit], uid: str) -> Unit:
    start = parse_unit_id(uid)
    for u in units:
        if u.start == start:
            return u
    raise SystemExit(f"no unit {uid}")


# --------------------------------------------------------------------------- commands
def cmd_list(args) -> int:
    units, _ = load_units("mM" if args.mm else "U")
    todo = [u for u in ordered(units) if args.area is None or in_area(u.area, args.area)]
    print(f"{'unit':12} {'area':24} {'work':>5} {'bytes':>6} {'score':>6}  file")
    for u in todo[:args.n]:
        files = [p.file for p in u.parts if any(f in u.work for f in p.funcs)]
        print(f"{u.id:12} {u.area[:24]:24} {len(u.work):5} {u.work_bytes:6} {u.score:6}  "
              f"{files[0]}{f' +{len(files) - 1}' if len(files) > 1 else ''}")
    print(f"{len(todo)} units, {sum(len(u.work) for u in todo)} functions, "
          f"{sum(u.work_bytes for u in todo)} bytes", file=sys.stderr)
    return 0


def local_calls(u: Unit, links: Links, index: dict[int, str] | None = None
                ) -> dict[int, list[tuple[int, str, bool]]]:
    """Function of the unit -> its callees in the unit, each with its source
    file and whether that's the caller's: the hand-written file an address
    comment puts a function in (`index`, source_index), else its part's. The original calls
    all of them out of line; clang inlines a small callee defined in the
    caller's file, so a same-file one needs one of the two in a file of its
    own."""
    index = index or {}
    file_of = {f.sword: index.get(f.sword, p.file) for p in u.parts for f in p.funcs}
    out = {}
    for f in u.funcs:
        cs = sorted(t for t in links.calls.get(f.sword, ()) if t in file_of)
        if cs:
            out[f.sword] = [(t, file_of[t], file_of[t] == file_of[f.sword]) for t in cs]
    return out


def crossing_ties(u: Unit, links: Links, pos: dict[int, int], near: int = NEAR_CALL) -> list[tuple]:
    """The ties (tied_blocks, all of them) between the unit and other units,
    which a block above the cap (u.loose) can leave: ("call", caller, callee)
    and ("class", vtable group, [its functions outside the unit]). `pos` is
    each function's index in address order. Only ties inside u.loose count:
    elsewhere no tie crosses a unit."""
    mine = {f.sword for f in u.funcs}
    seg = {f.sword: p.segment for p in u.parts for f in p.funcs}
    out: list[tuple] = []

    def loose(x: int) -> bool:
        return any(lo <= x < hi for lo, hi in u.loose)

    def local(fs, bounds) -> bool:
        return all(bounds[0] <= x < bounds[1] for x in fs)

    seen: set[int] = set()
    for f in sorted(mine):
        b = seg[f]
        for c, t in [(f, t) for t in links.calls.get(f, ())] + [(c, f) for c in links.callers.get(f, ())]:
            other = t if c == f else c
            if (other not in mine and loose(other) and other in pos and abs(pos[c] - pos[t]) <= near
                    and local(links.callers.get(t, ()), b)):
                out.append(("call", c, t))
        for g in links.vtables.get(f, ()):
            if g in seen or not local(links.referrers[g], b):
                continue
            seen.add(g)
            rest = sorted(x for x in links.referrers[g] | links.members.get(g, set())
                          if x not in mine and b[0] <= x < b[1])
            if rest:
                out.append(("class", g, rest))
    return out


def inlined_in_original(u: Unit, links: Links) -> list[int]:
    """Functions of the unit to do that nothing calls and whose address nothing
    takes: emitted (external linkage) but inlined wherever the original uses
    them, or unused. Defining one next to its users is right: clang inlines it
    there too."""
    called = links.callers
    return [f.sword for f in u.work if f.sword not in called and f.sword not in links.taken]


def cmd_show(args) -> int:
    links = load_links("sword")
    index = source_index()
    units, rows = load_units("mM" if args.mm else "U", links, index)
    u = find_unit(units, args.unit)
    by_addr = {r.sword: r for r in rows if r.sword is not None}
    print(f"unit {u.id}: {u.area} ({u.kind}), 0x{u.start + BASE:x}-0x{u.end + BASE:x}, score {u.score}")
    if u.loose:
        pos = {a: i for i, a in enumerate(sorted(by_addr))}
        unit_of = {f.sword: x.id for x in units for f in x.funcs}
        cross = crossing_ties(u, links, pos)
        if cross:
            print(f"  note: the functions tied together around here are more than {GROUP_CAP_FUNCS} functions or"
                  f" {GROUP_CAP_BYTES} bytes, so units cut through them. Ties to other units:")
            for kind, a, b in cross[:12]:
                if kind == "call":
                    other = b if unit_of.get(a) == u.id else a
                    print(f"    0x{a + BASE:x} calls 0x{b + BASE:x} (0x{other + BASE:x} is in {unit_of.get(other, '?')})")
                else:
                    print(f"    the class of vtable 0x{a + BASE:x} also has "
                          + ", ".join(f"0x{x + BASE:x} ({unit_of.get(x, '?')})" for x in b[:6])
                          + (" ..." if len(b) > 6 else ""))
            if len(cross) > 12:
                print(f"    ... {len(cross) - 12} more")
    calls_in = local_calls(u, links, index)
    print(f"{len(u.work)} functions to do ({u.work_bytes} bytes). Only edit these files; new headers")
    print("next to one must be named after it (<stem>*.h):")
    for p in u.parts:
        work = sorted((f for f in p.funcs if f in u.work), key=lambda f: (f.sword_size or 0, f.sword))
        if not work:
            continue
        print(f"\n{p.file}{' (new: create it)' if p.new_file else ''}   "
              f"[segment 0x{p.segment[0] + BASE:x}-0x{p.segment[1] + BASE:x}]")
        for f in work:
            calls = u.calls.get(f.sword, [])
            unknown = sum(1 for t in calls
                          if t not in by_addr or (by_addr[t].status != "O" and not by_addr[t].name))
            print(f"  0x{f.sword + BASE:x} {f.sword_size:6} {f.scope:9} {f.status}  calls {len(calls)}"
                  f" ({unknown} unknown)  {f.name or '-'}")
            same = [t for t, _, here in calls_in.get(f.sword, []) if here]
            small = [t for t in same if (by_addr[t].sword_size or 0) <= INLINE_BYTES]
            large = [t for t in same if t not in small]
            other = [(t, file) for t, file, here in calls_in.get(f.sword, []) if not here]
            if small:
                print("      ! out of line in the original, same file: "
                      + ", ".join(f"0x{t + BASE:x}" for t in small)
                      + " (clang would inline them: put this function, or them, in an Unk_<addr>.cpp)")
            if large:
                print("      out of line, same file, large (clang likely keeps the call): "
                      + ", ".join(f"0x{t + BASE:x}" for t in large))
            if other:
                print("      out of line, another file: " + ", ".join(f"0x{t + BASE:x} ({file})" for t, file in other))
    inl = inlined_in_original(u, links)
    if inl:
        print("\nnothing calls or takes the address of " + ", ".join(f"0x{a + BASE:x}" for a in inl)
              + ": the original inlined them into their callers (or they're unused). Define them next to"
              " their callers; clang inlines them there too.")
    done = [f for f in u.funcs if f not in u.work]
    if done:
        print(f"{len(done)} other functions of the unit: "
              + ", ".join(f"0x{f.sword + BASE:x} {f.status}" for f in done[:12])
              + (" ..." if len(done) > 12 else ""))
    print(f"\nnext: python tools/context.py 0x{min(u.work, key=lambda f: f.sword_size or 0).sword + BASE:x}"
          if u.work else "nothing left to do")
    return 0


def _funcs_py(*argv: str) -> None:
    subprocess.run([sys.executable, str(ROOT / "tools" / "funcs.py"), *argv], check=True)


def cmd_record(args) -> int:
    data = read_sidecar()
    if args.what == "name":
        addr = norm_addr(args.addr)
        _funcs_py("name", addr, args.value)
        sidecar_name(data, addr, args.value, args.evidence or "")
    elif args.what == "retype":
        addr = norm_addr(args.addr)
        rows = {r.sword: r for r in read_functions_csv() if r.sword is not None}
        old = rows.get(int(addr, 16) - BASE)
        if old is None or not old.name:
            raise SystemExit(f"{addr}: no named function starts there")
        r = subprocess.run([sys.executable, str(ROOT / "tools" / "retype.py"), addr, args.value, "--apply"])
        if r.returncode:
            raise SystemExit("retype.py didn't apply it: nothing recorded")
        sidecar_retype(data, addr, args.value, old.name)
    elif args.what == "status":
        addr = norm_addr(args.addr)
        sidecar_status(data, addr, args.value, args.reason or "")
        _funcs_py("status", addr, args.value)
    elif args.what == "report":
        text = args.addr
        if text.startswith("@"):
            text = Path(text[1:]).read_text(encoding="utf-8")
        data["report"] = text.strip()
    write_sidecar(data)
    print(f"recorded in {SIDECAR.relative_to(ROOT).as_posix()}")
    return 0


def cmd_sidecar(args) -> int:
    print(json.dumps(read_sidecar(), indent=2))
    return 0


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("list", help="units with work, easiest first")
    p.add_argument("--mm", action="store_true", help="units of m/M functions instead of U")
    p.add_argument("--area", help="only units in this area (or group: game)")
    p.add_argument("-n", type=int, default=40)
    p = sub.add_parser("show", help="one unit")
    p.add_argument("unit")
    p.add_argument("--mm", action="store_true")
    p = sub.add_parser("record", help="record a name, a retype, an m/M status or the report in the sidecar")
    p.add_argument("what", choices=("name", "retype", "status", "report"))
    p.add_argument("addr", help="the function's address (report: the text, or @file)")
    p.add_argument("value", nargs="?", help="name/retype: the (new) mangled name; status: m or M")
    p.add_argument("reason", nargs="?", help="status: the NON_MATCHING reason")
    p.add_argument("--evidence", help="name: what shows the name is right")
    sub.add_parser("sidecar", help="print this checkout's sidecar")
    args = ap.parse_args(argv)
    if args.cmd == "record" and args.what in ("name", "retype", "status") and not args.value:
        ap.error(f"record {args.what} needs a value")
    return {"list": cmd_list, "show": cmd_show, "record": cmd_record, "sidecar": cmd_sidecar}[args.cmd](args)


if __name__ == "__main__":
    raise SystemExit(main())
