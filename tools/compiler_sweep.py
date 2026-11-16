#!/usr/bin/env python3
"""Compiler identification: compile known source with candidate compilers and
flag sets, and count how many compiled functions appear *exactly* in the
original executable (see docs/compiler.md).

    python tools/compiler_sweep.py \\
        --compiler toolchain/candidates/clang-* \\
        --variant O3=-O3 --variant O2=-O2 \\
        --src 'toolchain/candidates/src/lua-5.3.4/src/l*.c' \\
        --range 0x7101540000-0x7101570000 \\
        -- -isystem toolchain/candidates/sysroot/include -DLUA_COMPAT_5_2 -DLUA_USE_POSIX

No names or addresses are needed. Every instruction is compared with its
address-dependent fields masked out (B/BL, ADRP, the lo12 half, ADR, LDR
literal), on both sides, using tools/nx/refs.py. An exact hit is a compiled
function whose masked words equal an original function's masked words.

Hits from all configurations together give a name -> address map. For every
mapped function, each configuration also gets a similarity score, so near
misses still rank the candidates.

    --map-out lua_map.csv

also writes the consensus map for both games as `Name,Sword,Shield` (local
symbols file-qualified as in tools/symbols.py). `--range` is in --game's
addresses; the other game's range comes from the paired rows of
data/functions.csv. Apply the map with `tools/funcs.py name --from-file`.
"""
from __future__ import annotations

import argparse
import csv
import difflib
import glob
import hashlib
import shlex
import subprocess
import sys
import tempfile
from collections import defaultdict
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BASE, VERSIONS, load_module  # noqa: E402
from nx.refs import decode  # noqa: E402
import symbols  # noqa: E402

from elftools.elf.elffile import ELFFile  # noqa: E402
from elftools.elf.sections import SymbolTableSection  # noqa: E402

# The identified NX codegen flags (C-safe subset of cmake/toolchain-nx64.cmake),
# minus the optimisation level. Variants are appended after these, so a variant
# can switch one off (-fno-unwind-tables, -mimplicit-float, -fstrict-aliasing,
# -U__ELF__, ...) to measure what it contributes.
BASE_FLAGS = [
    "--target=aarch64-none-elf", "-mcpu=cortex-a57+fp+simd+crypto+crc", "-D__ELF__",
    "-funwind-tables", "-mno-implicit-float", "-fPIC", "-fno-omit-frame-pointer",
    "-fno-strict-aliasing", "-ffunction-sections", "-fdata-sections", "-fno-common",
    "-fno-short-enums", "-nostdlibinc",
]
MIN_SIZE = 16  # smaller functions match too many places to be evidence


def masked(buf: bytes, start: int = 0, size: int | None = None) -> tuple[int, ...]:
    """Instruction words with address fields zeroed (independent of load address)."""
    size = len(buf) - start if size is None else size
    return tuple(m for _, _, m, _ in decode(buf, start, size - size % 4))


def object_functions(path: Path, source: Path | None = None) -> dict[str, bytes]:
    """Functions of an object file. With `source`, local symbols are file-qualified."""
    out = {}
    with open(path, "rb") as fh:
        elf = ELFFile(fh)
        symtab = elf.get_section_by_name(".symtab")
        if not isinstance(symtab, SymbolTableSection):
            return out
        for s in symtab.iter_symbols():
            if s["st_info"]["type"] != "STT_FUNC" or s["st_shndx"] in ("SHN_UNDEF", "SHN_ABS"):
                continue
            sec = elf.get_section(s["st_shndx"])
            name = symbols.qualify(s.name, source, s["st_info"]["bind"] == "STB_LOCAL")
            out[name] = sec.data()[s["st_value"]:s["st_value"] + s["st_size"]]
    return out


def compiler_label(root: Path) -> str:
    return root.name


def compile_all(cc: Path, flags: list[str], srcs: list[Path], outdir: Path) -> tuple[dict[str, bytes], list[str]]:
    funcs: dict[str, bytes] = {}
    errors: list[str] = []

    def one(src: Path):
        lang = ["-x", "c++"] if src.suffix in (".cpp", ".cc", ".cxx") else []
        obj = outdir / (hashlib.md5(str(src).encode()).hexdigest()[:8] + "_" + src.stem + ".o")
        cmd = [str(cc), *BASE_FLAGS, *flags, *lang, "-c", str(src), "-o", str(obj)]
        p = subprocess.run(cmd, capture_output=True, text=True)
        if p.returncode != 0:
            return src, None, p.stderr.strip().splitlines()[:3]
        return src, obj, None

    with ThreadPoolExecutor(8) as ex:
        for src, obj, err in ex.map(one, srcs):
            if obj is None:
                errors.append(f"{src.name}: {' | '.join(err or [])}")
                continue
            for name, code in object_functions(obj, src).items():
                # local symbols are already qualified; this only guards two TUs with one stem
                key = name if name not in funcs else f"{name}#{src}"
                funcs[key] = code
    return funcs, errors


def original_index(game: str, lo: int, hi: int):
    """masked words -> addresses, and address -> masked words, for originals in [lo, hi)."""
    mod = load_module(game)
    img = mod["image"]
    index: dict[tuple[int, ...], list[int]] = defaultdict(list)
    orig_masked: dict[int, tuple[int, ...]] = {}
    for a, s in mod["functions"]:
        if lo <= a < hi and s >= 4:
            m = masked(img, a, s)
            orig_masked[a] = m
            index[m].append(a)
    return index, orig_masked


def find_hits(funcs: dict[str, bytes], index) -> dict[str, list[int]]:
    hits = {}
    for name, code in funcs.items():
        if len(code) < MIN_SIZE:
            continue
        addrs = index.get(masked(code))
        if addrs:
            hits[name] = addrs
    return hits


def consensus(all_hits) -> dict[str, int]:
    """name -> address for names that every configuration hit at the same single address."""
    votes: dict[str, set[int]] = defaultdict(set)
    for hits in all_hits:
        for name, addrs in hits.items():
            if len(addrs) == 1:
                votes[name].add(addrs[0])
            else:
                votes[name].add(-1)  # ambiguous somewhere: never map it
    return {n: next(iter(a)) for n, a in votes.items() if len(a) == 1 and -1 not in a}


def other_game_range(game: str, other: str, lo: int, hi: int, funcs) -> tuple[int, int]:
    """[lo, hi) in `game` translated to `other` through the paired functions.csv rows."""
    rows = [f for f in funcs if f.addr(game) is not None and lo <= f.addr(game) < hi and f.in_version(other)]
    if not rows:
        raise SystemExit(f"no {other} functions pair with the {game} range")
    return min(f.addr(other) for f in rows), max(f.addr(other) + f.size(other) for f in rows)


def write_map(path: Path, maps: dict[str, dict[str, int]]) -> int:
    """Write `Name,Sword,Shield` for every name mapped in at least one game."""
    names = sorted(set().union(*(m.keys() for m in maps.values())))
    with open(path, "w", newline="", encoding="utf-8") as fh:
        w = csv.writer(fh, lineterminator="\n")
        w.writerow(["Name", "Sword", "Shield"])
        for n in names:
            w.writerow([n] + [f"{maps[v][n] + BASE:#x}" if n in maps.get(v, {}) else "" for v in VERSIONS])
    return len(names)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--compiler", nargs="+", required=True, help="compiler root dirs (containing bin/clang)")
    ap.add_argument("--variant", action="append", default=[], help='NAME="flags" (repeatable)')
    ap.add_argument("--src", action="append", required=True, help="source glob (repeatable)")
    ap.add_argument("--range", help="original address range to search, e.g. 0x7101540000-0x7101570000 (default: all)")
    ap.add_argument("--game", default="sword")
    ap.add_argument("--show", type=int, default=0, help="list up to N mapped functions per config that miss")
    ap.add_argument("--map-out", type=Path, help="write the consensus name -> address map for both games (CSV)")
    ap.add_argument("common", nargs=argparse.REMAINDER, help="-- extra flags for every compile")
    args = ap.parse_args()
    common = [a for a in args.common if a != "--"]

    srcs = sorted({Path(p) for g in args.src for p in glob.glob(g)})
    if not srcs:
        raise SystemExit("no sources matched")
    roots = []
    for pattern in args.compiler:
        roots += [Path(p) for p in sorted(glob.glob(pattern))] or [Path(pattern)]
    exe = ".exe" if sys.platform == "win32" else ""
    roots = [r for r in roots if (r / "bin" / f"clang{exe}").exists()]
    variants = [v.split("=", 1) for v in args.variant] or [["O2", "-O2"]]

    # ---- original index: masked words -> addresses
    lo, hi = 0, 1 << 62
    if args.range:
        lo, hi = (int(x, 16) - BASE for x in args.range.split("-"))
    index, orig_masked = original_index(args.game, lo, hi)
    print(f"{len(orig_masked)} original functions in range, {len(srcs)} sources, "
          f"{len(roots)} compilers x {len(variants)} variants\n")

    # ---- compile + exact hits
    results = {}
    tmp = Path(tempfile.mkdtemp(prefix="sweep_"))
    for root in roots:
        cc = root / "bin" / f"clang{exe}"
        for vname, vflags in variants:
            out = tmp / f"{root.name}_{vname}"
            out.mkdir()
            funcs, errors = compile_all(cc, shlex.split(vflags) + common, srcs, out)
            hits = find_hits(funcs, index)
            results[(root.name, vname)] = (funcs, hits, errors)

    # ---- consensus name -> address map from unambiguous hits
    votes: dict[str, set[int]] = defaultdict(set)
    for _funcs, hits, _ in results.values():
        for name, addrs in hits.items():
            if len(addrs) == 1:
                votes[name].add(addrs[0])
    mapping = {n: next(iter(a)) for n, a in votes.items() if len(a) == 1}

    print(f"{'compiler':14} {'variant':10} {'funcs':>6} {'hits':>5} {'hit bytes':>9}  "
          f"{'mapped':>6} {'exact':>5} {'avg sim':>7}  errors")
    for (cname, vname), (funcs, hits, errors) in results.items():
        nbytes = sum(len(funcs[n]) for n in hits)
        sims, exact = [], 0
        for name, a in mapping.items():
            code = funcs.get(name)
            if code is None:
                continue
            mine, theirs = masked(code), orig_masked[a]
            if mine == theirs:
                exact += 1
                sims.append(1.0)
            else:
                sims.append(difflib.SequenceMatcher(None, mine, theirs, autojunk=False).ratio())
        avg = sum(sims) / len(sims) if sims else 0.0
        print(f"{cname:14} {vname:10} {len(funcs):6} {len(hits):5} {nbytes:9}  "
              f"{len(sims):6} {exact:5} {avg:7.4f}  {len(errors)}")
        for e in errors[:3]:
            print(f"      ! {e}")
        if args.show:
            misses = [n for n in mapping if n in funcs and masked(funcs[n]) != orig_masked[mapping[n]]]
            for n in misses[:args.show]:
                print(f"      miss {n} ({len(funcs[n])} vs {len(orig_masked[mapping[n]]) * 4} bytes) "
                      f"@ {mapping[n] + BASE:#x}")
    print(f"\n{len(mapping)} functions mapped by consensus")

    if args.map_out:
        from common import read_functions_csv
        maps: dict[str, dict[str, int]] = {}
        for v in VERSIONS:
            if v == args.game:
                vlo, vhi, vindex = lo, hi, index
            else:
                vlo, vhi = other_game_range(args.game, v, lo, hi, read_functions_csv()) if args.range else (lo, hi)
                vindex, _ = original_index(v, vlo, vhi)
            maps[v] = consensus(find_hits(f, vindex) for f, _, _ in results.values())
        n = write_map(args.map_out, maps)
        print(f"wrote {n} names to {args.map_out} "
              f"({', '.join(f'{v}: {len(m)}' for v, m in maps.items())})")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
