#!/usr/bin/env python3
"""Split the remaining work into units that parallel workers can take, one each.

    python tools/units.py list                     # units of U functions, easiest first
    python tools/units.py list --mm                # the later list: units of m/M functions
    python tools/units.py list --area game/bag -n 20
    python tools/units.py show u7c3a40             # one unit: its file, its functions, their callees
    python tools/units.py record name 0x71007c3a40 _ZN4pkmn3FooEv     # name it here + in the sidecar
    python tools/units.py record status 0x71007c3a40 M "loop is unrolled differently"
    python tools/units.py record report "matched 9; the struct at x0 is Unk_7c3a40 (0x48 bytes)"
    python tools/units.py sidecar                  # print this checkout's sidecar

A unit is a run of consecutive functions inside one segment (tools/segments.py:
the functions between two static initialisers, one or more whole TUs) and one
area of data/areas.csv. Long segments are cut into chunks of at most
MAX_FUNCS functions and MAX_BYTES bytes, counting every function whatever its
status, so a unit's ID (`u` + the Sword offset of its first function) and its
extent stay the same as functions get matched. A unit is listed while it still
has a function of the statuses asked for (U, or m/M with --mm).

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
top of the stack, where check.py --update decides the statuses.
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
from pathlib import Path, PurePosixPath

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BASE, ROOT, AreaMap, Function, in_area, read_areas_csv, read_functions_csv  # noqa: E402

MAX_FUNCS = 16        # per part (one source file)
MAX_BYTES = 2048
UNIT_FUNCS = 32       # per unit (consecutive parts of one area)
UNIT_BYTES = 4096
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


def chunk(funcs: list[Function], max_funcs: int = MAX_FUNCS, max_bytes: int = MAX_BYTES) -> list[list[Function]]:
    """Cut a run of consecutive functions (sorted by Sword address) into chunks
    of at most max_funcs functions and max_bytes bytes. A function larger than
    max_bytes is a chunk of its own."""
    out: list[list[Function]] = []
    cur: list[Function] = []
    size = 0
    for f in funcs:
        n = f.sword_size or 0
        if cur and (len(cur) >= max_funcs or size + n > max_bytes):
            out.append(cur)
            cur, size = [], 0
        cur.append(f)
        size += n
    if cur:
        out.append(cur)
    return out


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


def nearest_dir(addr: int, area: str, hand: list[tuple[int, str]], amap: AreaMap) -> str | None:
    """The directory of the hand-written file whose address comment is nearest
    to `addr` in the same area (`hand`: sorted (offset, path)). Files under an
    `include` directory don't count: a new source file never goes there."""
    hand = [h for h in hand if "include" not in PurePosixPath(h[1]).parts]
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
    hand = sorted((a, p) for a, p in index.items() if not is_generated(p))
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


def build_units(rows: list[Function], areas, seg_bounds: list[tuple[int, int]],
                index: dict[int, str], statuses: str = "U", exists=lambda p: False,
                calls_of=lambda f: [], unit_funcs: int = UNIT_FUNCS, unit_bytes: int = UNIT_BYTES,
                blocked=lambda f: False) -> list[Unit]:
    """Every unit of the executable (the ones without work too), in address
    order. `calls_of(f)` gives the Sword offsets function f calls."""
    amap = AreaMap(areas, "sword")
    kinds = {a.name: a.kind for a in areas}
    funcs = sorted((r for r in rows if r.sword is not None), key=lambda r: r.sword)
    starts = [f.sword for f in funcs]
    parts: list[Part] = []
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
            parts.extend(Part(c, (a, b), area) for c in chunk(g))
    assign_files(parts, index, area_dirs(index, amap, areas), amap, exists)
    by_addr = {f.sword: f for f in funcs}
    units = []
    for g in group_parts(parts, unit_funcs, unit_bytes):
        u = Unit(unit_id(g[0].start), g[0].area, kinds.get(g[0].area, ""), g)
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
    data.setdefault("report", "")
    return data


def write_sidecar(data: dict, path: Path = SIDECAR) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(data, indent=2) + "\n", encoding="utf-8")


def sidecar_name(data: dict, addr: str, name: str, evidence: str = "") -> None:
    data["names"] = [n for n in data["names"] if n["addr"] != addr]
    data["names"].append({"addr": addr, "name": name, "evidence": evidence})


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


def load_units(statuses: str = "U") -> tuple[list[Unit], list[Function]]:
    from common import load_module

    rows = read_functions_csv()
    img = load_module("sword")["image"]
    units = build_units(rows, read_areas_csv(), exe_segments("sword"), source_index(), statuses,
                        exists=lambda p: (ROOT / p).exists(), calls_of=callees_fn(img), blocked=blocked_fn(img))
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


def cmd_show(args) -> int:
    units, rows = load_units("mM" if args.mm else "U")
    u = find_unit(units, args.unit)
    by_addr = {r.sword: r for r in rows if r.sword is not None}
    print(f"unit {u.id}: {u.area} ({u.kind}), 0x{u.start + BASE:x}-0x{u.end + BASE:x}, score {u.score}")
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
    p = sub.add_parser("record", help="record a name, an m/M status or the report in the sidecar")
    p.add_argument("what", choices=("name", "status", "report"))
    p.add_argument("addr", help="the function's address (report: the text, or @file)")
    p.add_argument("value", nargs="?", help="name: the mangled name; status: m or M")
    p.add_argument("reason", nargs="?", help="status: the NON_MATCHING reason")
    p.add_argument("--evidence", help="name: what shows the name is right")
    sub.add_parser("sidecar", help="print this checkout's sidecar")
    args = ap.parse_args(argv)
    if args.cmd == "record" and args.what in ("name", "status") and not args.value:
        ap.error(f"record {args.what} needs a value")
    return {"list": cmd_list, "show": cmd_show, "record": cmd_record, "sidecar": cmd_sidecar}[args.cmd](args)


if __name__ == "__main__":
    raise SystemExit(main())
