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

Every compile gets the base flags (the identified NX codegen flags), then the
common flags after `--`, then the variant's flags, in that order. With clang
the last of conflicting options wins, so a variant always overrides both: it
can switch a base or common flag off (-fno-unwind-tables, -U__ELF__, -O2, ...)
to measure what that flag contributes.

No names or addresses are needed. The compiled object's relocations say which
instructions hold an address: every instruction with a relocation at its
offset (CALL26/JUMP26, ADR_PREL_PG_HI21, ADD/LDST *_LO12_NC, GOT, ...) has its
immediate field masked, by instruction class (see field_mask), and the
original's instruction at the same offset gets the same treatment. Every other
instruction is compared raw, so struct offsets and intra-function branches
count. An exact hit is a compiled function whose masked words equal an
original function's masked words (see same_code). Original functions are first
bucketed by a coarse key that masks those fields in *every* instruction
(coarse_key), which only narrows the candidates.

Earlier versions masked both sides with tools/nx/refs.py's linear ADRP
tracking instead. That compared a lo12 load raw when its ADRP was on another
path (docs/compiler.md, "Method"), and missed such functions.

Hits from all configurations together give a name -> address map. For every
mapped function, each configuration also gets a similarity score, so near
misses still rank the candidates.

    --map-out lua_map.csv

also writes the consensus map for both games as `Name,Sword,Shield` (local
symbols file-qualified as in tools/symbols.py). `--range` is in --game's
addresses; the other game's range comes from the paired rows of
data/functions.csv. Apply the map with `tools/funcs.py name --from-file`.

`@FILE` reads arguments from FILE, one per line (for long --src lists).
`--module sdk` (or any other NSO of the game) searches that module instead of
`main`. functions.csv only covers `main`, so the other game's range can't be
derived there: use --map-out without --range.
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
import struct
from collections import defaultdict
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
from typing import NamedTuple

sys.path.insert(0, str(Path(__file__).resolve().parent))
import common  # noqa: E402
from common import BASE, VERSIONS, load_module  # noqa: E402
from nx.refs import decode, is_adr, is_adrp, is_b_bl, is_ldr_literal, is_ldst_uimm  # noqa: E402
import symbols  # noqa: E402

from elftools.elf.elffile import ELFFile  # noqa: E402
from elftools.elf.relocation import RelocationSection  # noqa: E402
from elftools.elf.sections import SymbolTableSection  # noqa: E402

# The identified NX codegen flags (C-safe subset of cmake/toolchain-nx64.cmake),
# minus the optimisation level. The common flags and then the variant's flags
# come after these (see compile_command), so a variant can switch one off
# (-fno-unwind-tables, -mimplicit-float, -fstrict-aliasing, -U__ELF__, -g0, ...)
# to measure what it contributes. -g matters: debug instructions change LLVM's
# load/store pairing and scheduling (docs/compiler.md, "Debug info").
BASE_FLAGS = [
    "--target=aarch64-none-elf", "-mcpu=cortex-a57+fp+simd+crypto+crc", "-g", "-D__ELF__",
    "-funwind-tables", "-mno-implicit-float", "-fPIC", "-fno-omit-frame-pointer",
    "-fno-strict-aliasing", "-ffunction-sections", "-fdata-sections", "-fno-common",
    "-fno-short-enums", "-nostdlibinc",
]
MIN_SIZE = 16  # smaller functions match too many places to be evidence


class Func(NamedTuple):
    """A compiled function: its code, and the word indices that carry a relocation."""
    code: bytes
    relocs: frozenset[int] = frozenset()


def words(buf: bytes, start: int = 0, size: int | None = None) -> tuple[int, ...]:
    size = len(buf) - start if size is None else size
    return struct.unpack_from(f"<{size // 4}I", buf, start)


def field_mask(w: int) -> int:
    """AND-mask that clears the address/immediate field of `w`, by instruction class.

    These are the classes an AArch64 code relocation can patch: B/BL (CALL26,
    JUMP26), B.cond/CBZ/TBZ (CONDBR19, TSTBR14), ADRP/ADR (*_PG_HI21, ADR_PREL_LO21,
    ADR_GOT_PAGE), LDR literal (LD_PREL_LO19), ADD/SUB immediate (ADD_ABS_LO12_NC,
    TLS lo12) and LDR/STR unsigned offset (LDST*_ABS_LO12_NC, LD64_GOT_LO12_NC),
    and MOVZ/MOVK/MOVN (MOVW_*). Anything else is left alone (all ones)."""
    if is_b_bl(w):
        return 0xFC000000
    if (w & 0x7E000000) == 0x34000000 or (w & 0xFF000010) == 0x54000000:  # cbz/cbnz, b.cond: imm19
        return 0xFF00001F
    if (w & 0x7E000000) == 0x36000000:  # tbz/tbnz: imm14
        return 0xFFF8001F
    if is_adrp(w) or is_adr(w):
        return 0x9F00001F
    if is_ldr_literal(w):
        return 0xFF00001F
    if (w & 0x1F000000) == 0x11000000 or is_ldst_uimm(w):  # add/sub imm, ldr/str uimm: imm12
        return 0xFFC003FF
    if (w & 0x1F800000) == 0x12800000 and (w >> 29) & 3 != 1:  # movn/movz/movk: imm16
        return 0xFFE0001F
    return 0xFFFFFFFF


def coarse_key(ws: tuple[int, ...]) -> tuple[int, ...]:
    """Every word with its relocatable field masked: equal code always has equal keys."""
    return tuple(w & field_mask(w) for w in ws)


def reloc_masked(ws: tuple[int, ...], relocs: frozenset[int]) -> tuple[int, ...]:
    """`ws` with only the words at indices `relocs` masked (by their own class)."""
    return tuple(w & field_mask(w) if i in relocs else w for i, w in enumerate(ws))


def same_code(mine: tuple[int, ...], relocs: frozenset[int], theirs: tuple[int, ...]) -> bool:
    """Compiled words (relocated at `relocs`) equal the original's, up to addresses."""
    return len(mine) == len(theirs) and reloc_masked(mine, relocs) == reloc_masked(theirs, relocs)


def address_offsets(ws: tuple[int, ...]) -> frozenset[int]:
    """Word indices of an original function that tools/nx/refs.py finds an address in."""
    buf = struct.pack(f"<{len(ws)}I", *ws)
    return frozenset(off // 4 for off, w, m, _ in decode(buf, 0, len(buf)) if m != w)


def similarity(f: Func, theirs: tuple[int, ...]) -> float:
    """Near-miss score in [0, 1]: 1.0 exactly when same_code().

    The original side also masks what refs.py's linear tracking finds, so an
    inserted or dropped instruction (which shifts the relocation indices)
    doesn't turn every later address field into a difference."""
    mine = words(f.code)
    if same_code(mine, f.relocs, theirs):
        return 1.0
    a = reloc_masked(mine, f.relocs)
    b = reloc_masked(theirs, f.relocs | address_offsets(theirs))
    return min(difflib.SequenceMatcher(None, a, b, autojunk=False).ratio(), 0.9999)


def object_functions(path: Path, source: Path | None = None) -> dict[str, Func]:
    """Functions of an object file. With `source`, local symbols are file-qualified."""
    out = {}
    with open(path, "rb") as fh:
        elf = ELFFile(fh)
        symtab = elf.get_section_by_name(".symtab")
        if not isinstance(symtab, SymbolTableSection):
            return out
        rel_by_sec: dict[int, set[int]] = defaultdict(set)
        for sec in elf.iter_sections():
            if isinstance(sec, RelocationSection):
                rel_by_sec[sec["sh_info"]].update(r["r_offset"] for r in sec.iter_relocations())
        for s in symtab.iter_symbols():
            if s["st_info"]["type"] != "STT_FUNC" or s["st_shndx"] in ("SHN_UNDEF", "SHN_ABS"):
                continue
            sec = elf.get_section(s["st_shndx"])
            name = symbols.qualify(s.name, source, s["st_info"]["bind"] == "STB_LOCAL")
            v, n = s["st_value"], s["st_size"]
            relocs = frozenset((o - v) // 4 for o in rel_by_sec.get(s["st_shndx"], ()) if v <= o < v + n)
            out[name] = Func(sec.data()[v:v + n], relocs)
    return out


def find_sources(patterns: list[str]) -> list[Path]:
    """Expand --src globs (`**` recurses into subdirectories), sorted and deduplicated."""
    return sorted({Path(p) for g in patterns for p in glob.glob(g, recursive=True)})


def compiler_label(root: Path) -> str:
    return root.name


def compile_command(cc: Path, variant_flags: list[str], common: list[str], src: Path, obj: Path) -> list[str]:
    """Base flags, then the common flags, then the variant's: the variant wins any conflict."""
    lang = ["-x", "c++"] if src.suffix in (".cpp", ".cc", ".cxx") else []
    return [str(cc), *BASE_FLAGS, *common, *variant_flags, *lang, "-c", str(src), "-o", str(obj)]


def compile_all(cc: Path, variant_flags: list[str], common: list[str], srcs: list[Path],
                outdir: Path) -> tuple[dict[str, Func], list[str]]:
    funcs: dict[str, Func] = {}
    errors: list[str] = []

    def one(src: Path):
        obj = outdir / (hashlib.md5(str(src).encode()).hexdigest()[:8] + "_" + src.stem + ".o")
        cmd = compile_command(cc, variant_flags, common, src, obj)
        p = subprocess.run(cmd, capture_output=True, text=True)
        if p.returncode != 0:
            return src, None, p.stderr.strip().splitlines()[:3]
        return src, obj, None

    with ThreadPoolExecutor(8) as ex:
        for src, obj, err in ex.map(one, srcs):
            if obj is None:
                errors.append(f"{src.name}: {' | '.join(err or [])}")
                continue
            for name, f in object_functions(obj, src).items():
                # local symbols are already qualified; this only guards two TUs with one stem
                key = name if name not in funcs else f"{name}#{src}"
                funcs[key] = f
    return funcs, errors


def load_original(game: str, module: str = "main") -> dict:
    """Image and function list of one of `game`'s NSOs (data/original/<game>/<module>).

    `main` goes through common.load_module (cached). Other modules (`sdk`,
    `subsdk*`) are decoded the same way, without the cache."""
    if module == "main":
        return load_module(game)
    from nx.ehframe import functions_from_eh_frame
    from nx.nso import Nso

    src = common.ORIGINAL / game / module
    if not src.exists():
        raise SystemExit(f"{src} missing - run tools/setup.py first")
    nso = Nso(src.read_bytes())
    img = nso.image()
    funcs = functions_from_eh_frame(img, nso.mod0.eh_frame_hdr_start)
    return {"image": img, "functions": sorted(funcs + common._fde_less_functions(img, funcs))}


def original_index(game: str, lo: int, hi: int, module: str = "main"):
    """coarse key -> addresses, and address -> words, for originals in [lo, hi)."""
    mod = load_original(game, module)
    img = mod["image"]
    index: dict[tuple[int, ...], list[int]] = defaultdict(list)
    orig_words: dict[int, tuple[int, ...]] = {}
    for a, s in mod["functions"]:
        if lo <= a < hi and s >= 4:
            ws = words(img, a, s - s % 4)
            orig_words[a] = ws
            index[coarse_key(ws)].append(a)
    return index, orig_words


def find_hits(funcs: dict[str, Func], index, orig_words) -> dict[str, list[int]]:
    """name -> original addresses whose code is the same (same_code), for every name with any."""
    hits = {}
    for name, f in funcs.items():
        if len(f.code) < MIN_SIZE:
            continue
        ws = words(f.code)
        addrs = [a for a in index.get(coarse_key(ws), ()) if same_code(ws, f.relocs, orig_words[a])]
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


def arg_parser() -> argparse.ArgumentParser:
    # @FILE reads more arguments from FILE, one per line: a big corpus's --src
    # list doesn't fit on a Windows command line (32,767 characters).
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter,
                                 fromfile_prefix_chars="@")
    ap.add_argument("--compiler", nargs="+", required=True, help="compiler root dirs (containing bin/clang)")
    ap.add_argument("--variant", action="append", default=[],
                    help='NAME="flags" (repeatable); they come after the common flags, so they win')
    ap.add_argument("--src", action="append", required=True,
                    help="source glob, quoted; ** recurses (repeatable)")
    ap.add_argument("--range", help="original address range to search, e.g. 0x7101540000-0x7101570000 (default: all)")
    ap.add_argument("--game", default="sword")
    ap.add_argument("--module", default="main",
                    help="NSO to search: main (default), sdk, subsdk0, ... Addresses are then that module's. "
                         "functions.csv covers main only, so for other modules --map-out needs no --range "
                         "(both games are searched whole), and its rows aren't for funcs.py name")
    ap.add_argument("--show", type=int, default=0, help="list up to N mapped functions per config that miss")
    ap.add_argument("--map-out", type=Path, help="write the consensus name -> address map for both games (CSV)")
    ap.add_argument("common", nargs=argparse.REMAINDER, help="-- flags for every compile (before each variant's flags)")
    return ap


def main() -> int:
    args = arg_parser().parse_args()
    common = [a for a in args.common if a != "--"]

    srcs = find_sources(args.src)
    if not srcs:
        raise SystemExit("no sources matched")
    roots = []
    for pattern in args.compiler:
        roots += [Path(p) for p in sorted(glob.glob(pattern))] or [Path(pattern)]
    exe = ".exe" if sys.platform == "win32" else ""
    roots = [r for r in roots if (r / "bin" / f"clang{exe}").exists()]
    variants = [v.split("=", 1) for v in args.variant] or [["O2", "-O2"]]

    # ---- original index: coarse key -> addresses
    lo, hi = 0, 1 << 62
    if args.range:
        lo, hi = (int(x, 16) - BASE for x in args.range.split("-"))
    if args.module != "main" and args.map_out and args.range:
        raise SystemExit("--map-out with --range translates the range through functions.csv, which only covers "
                         "main: drop --range for other modules")
    index, orig_words = original_index(args.game, lo, hi, args.module)
    print(f"{len(orig_words)} original functions in range, {len(srcs)} sources, "
          f"{len(roots)} compilers x {len(variants)} variants\n")

    # ---- compile + exact hits
    results = {}
    tmp = Path(tempfile.mkdtemp(prefix="sweep_"))
    for root in roots:
        cc = root / "bin" / f"clang{exe}"
        for vname, vflags in variants:
            out = tmp / f"{root.name}_{vname}"
            out.mkdir()
            funcs, errors = compile_all(cc, shlex.split(vflags), common, srcs, out)
            hits = find_hits(funcs, index, orig_words)
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
        nbytes = sum(len(funcs[n].code) for n in hits)
        sims = [similarity(funcs[n], orig_words[a]) for n, a in mapping.items() if n in funcs]
        exact = sims.count(1.0)
        avg = sum(sims) / len(sims) if sims else 0.0
        print(f"{cname:14} {vname:10} {len(funcs):6} {len(hits):5} {nbytes:9}  "
              f"{len(sims):6} {exact:5} {avg:7.4f}  {len(errors)}")
        for e in errors[:3]:
            print(f"      ! {e}")
        if args.show:
            misses = [n for n in mapping if n in funcs
                      and not same_code(words(funcs[n].code), funcs[n].relocs, orig_words[mapping[n]])]
            for n in misses[:args.show]:
                print(f"      miss {n} ({len(funcs[n].code)} vs {len(orig_words[mapping[n]]) * 4} bytes) "
                      f"@ {mapping[n] + BASE:#x}")
    print(f"\n{len(mapping)} functions mapped by consensus")

    if args.map_out:
        from common import read_functions_csv
        maps: dict[str, dict[str, int]] = {}
        for v in VERSIONS:
            if v == args.game:
                vlo, vhi, vindex, vwords = lo, hi, index, orig_words
            else:
                vlo, vhi = other_game_range(args.game, v, lo, hi, read_functions_csv()) if args.range else (lo, hi)
                vindex, vwords = original_index(v, vlo, vhi, args.module)
            maps[v] = consensus(find_hits(f, vindex, vwords) for f, _, _ in results.values())
        n = write_map(args.map_out, maps)
        print(f"wrote {n} names to {args.map_out} "
              f"({', '.join(f'{v}: {len(m)}' for v, m in maps.items())})")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
