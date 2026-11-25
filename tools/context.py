#!/usr/bin/env python3
"""Everything needed to decompile one function, in one compact bundle.

    python tools/context.py 0x7100debce0
    python tools/context.py 0x7100debce0 --no-similar --ghidra-lines 80

Sections:

1. the function: name, addresses, size, scope, status, area, and its unit
   and source file (tools/units.py: the file the function belongs in);
2. the original asm (tools/funcs.py show; both games if it's diverged);
3. Ghidra's pseudo-C from the local export cache
   (`.cache/ghidra/export/<game>/<addr>.c`, written by `ghidra.sh export`).
   It's a rough draft of the logic only: rewrite it as natural C++, never
   copy its names or casts. context.py never opens the Ghidra project; if
   the function isn't in the cache it says so;
4. what it calls (name, status, where it's defined) and the data it
   references (data/data_symbols.csv names, short strings);
5. the headers that declare the classes it touches, where its name, its
   callees' names or the vtables it references name one;
6. the most similar functions that already match (by shape distance: the
   instruction words with call targets and data addresses masked, as in
   tools/shapes.py), with their source.

The Ghidra output and the asm come from the game: keep them local, never
paste them into commits or PRs in bulk.
"""
from __future__ import annotations

import argparse
import csv
import difflib
import os
import re
import shutil
import struct
import subprocess
import sys
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BASE, ROOT, VERSIONS, Function, read_functions_csv  # noqa: E402

GHIDRA_EXPORT = Path(os.environ.get("PKMN_GHIDRA_EXPORT") or ROOT / ".cache" / "ghidra" / "export")
SIMILAR = 3
SNIPPET_LINES = 40
HEADER_DIRS = ("include", "src", "lib")
HEADER_SKIP = ("lib/physx", "lib/yebis", "lib/protobuf", "lib/curl", "lib/freetype", "lib/lua", "lib/zlib",
               "lib/miniz", "include/libc", "include/libcxx")


# --------------------------------------------------------------------------- pure parts (tested)
def ghidra_path(game: str, addr: int, root: Path = GHIDRA_EXPORT) -> Path:
    """The export cache file of the function at `addr` (relative to BASE)."""
    return root / game / f"{addr + BASE:010x}.c"


def source_snippet(text: str, addr: int, max_lines: int = SNIPPET_LINES) -> str | None:
    """The function under the `// 0x<addr>` comment of a source file: from the
    comment to the brace that closes the function (at most max_lines lines)."""
    pat = re.compile(rf"^[ \t]*//.*\b0x{addr + BASE:x}\b", re.I)
    lines = text.splitlines()
    for i, line in enumerate(lines):
        if not pat.match(line):
            continue
        out, depth, opened = [], 0, False
        for line2 in lines[i:i + max_lines]:
            out.append(line2)
            code = re.sub(r"//.*", "", line2)
            depth += code.count("{") - code.count("}")
            opened = opened or "{" in code
            if opened and depth <= 0:
                break
            if not opened and code.rstrip().endswith(";") and len(out) > 1:
                break  # a declaration or a one-line definition without braces
        return "\n".join(out)
    return None


def similarity(a: list[int], b: list[int]) -> float:
    return difflib.SequenceMatcher(None, a, b, autojunk=False).ratio()


def rank_similar(target: list[int], candidates: list[tuple[int, list[int]]], n: int = SIMILAR,
                 prefilter: int = 40) -> list[tuple[float, int]]:
    """The n candidates (addr, masked words) closest to `target`: an opcode
    histogram prefilter, then difflib's ratio on the masked words."""
    hist = Counter(w >> 22 for w in target)
    pre = []
    for addr, words in candidates:
        h = Counter(w >> 22 for w in words)
        overlap = sum((hist & h).values()) / max(len(target), len(words), 1)
        pre.append((overlap, addr, words))
    pre.sort(key=lambda t: (-t[0], t[1]))
    scored = [(similarity(target, w), a) for _, a, w in pre[:prefilter]]
    scored.sort(key=lambda t: (-t[0], t[1]))
    return scored[:n]


_SOURCE_NAME = re.compile(r"(\d+)")


def class_names(mangled: str) -> list[str]:
    """Class-like components of a mangled nested name (`_ZN5field7content3FooEv`
    -> ["field", "content", "Foo"]; the last component, the function, is
    dropped). Vtables (`_ZTV...`) give their class."""
    name = mangled.split("@", 1)[0]
    if name.startswith("_ZTV"):
        s, keep_last = name[4:], True
    elif name.startswith("_ZN"):
        s, keep_last = name[3:], False
    else:
        return []
    if s.startswith("N"):
        s = s[1:]
    while s[:1] in ("K", "V", "r"):
        s = s[1:]
    parts = []
    while True:
        m = _SOURCE_NAME.match(s)
        if not m:
            break
        n = int(m.group(1))
        part = s[m.end():m.end() + n]
        if len(part) < n:
            break
        parts.append(part)
        s = s[m.end() + n:]
    if not keep_last:
        parts = parts[:-1]
    return [p for p in parts if not p.startswith("St") and p != "std"]


def inline_hazards(calls: list[int], index: dict[int, str], file: str | None) -> list[int]:
    """The callees defined in `file`, the function's own source file: clang
    inlines a small callee of the same TU, and the original calls it."""
    return [t for t in calls if file and index.get(t) == file]


# --------------------------------------------------------------------------- helpers
def demangle(names: list[str]) -> dict[str, str]:
    exe = shutil.which("llvm-cxxfilt") or next((str(p) for p in ROOT.glob("toolchain/*/bin/llvm-cxxfilt*")), None)
    plain = [n.split("@", 1)[0] for n in names]
    if exe is None or not names:
        return {n: n for n in names}
    out = subprocess.run([exe], input="\n".join(plain), capture_output=True, text=True).stdout.splitlines()
    res = {n: (o.strip() or n) for n, o in zip(names, out)}
    for n in names:
        if "@" in n:
            res[n] += "  [static in " + n.split("@", 1)[1] + "]"
    return res


def read_data_symbols() -> dict[int, str]:
    out = {}
    with open(ROOT / "data" / "data_symbols.csv", newline="", encoding="utf-8") as f:
        for r in csv.DictReader(f):
            if r.get("Sword"):
                out[int(r["Sword"], 16) - BASE] = r["Name"]
    return out


def header_index() -> dict[str, list[str]]:
    """Class/struct name -> the headers that define it."""
    pat = re.compile(r"^\s*(?:template\s*<[^>]*>\s*)?(?:class|struct|union)\s+(?:alignas\([^)]*\)\s*)?(\w+)"
                     r"[^;]*$", re.M)
    out: dict[str, list[str]] = {}
    for top in HEADER_DIRS:
        for p in sorted((ROOT / top).rglob("*.h")):
            rel = p.relative_to(ROOT).as_posix()
            if any(rel.startswith(d + "/") for d in HEADER_SKIP):
                continue
            for m in pat.finditer(p.read_text(encoding="utf-8", errors="replace")):
                out.setdefault(m.group(1), [])
                if rel not in out[m.group(1)]:
                    out[m.group(1)].append(rel)
    return out


def masked(img: bytes, f: Function) -> list[int]:
    from shapes import mask_words

    n = (f.sword_size or 0) // 4
    return mask_words(list(struct.unpack_from(f"<{n}I", img, f.sword)))


def c_string(img: bytes, addr: int, rodata: tuple[int, int]) -> str | None:
    import segments
    return segments.c_string(img, addr, *rodata)


# --------------------------------------------------------------------------- the bundle
def section(title: str) -> None:
    print(f"\n===== {title} " + "=" * max(0, 70 - len(title)))


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("addr", help="the function's address (either game's; Sword is canonical)")
    ap.add_argument("--ghidra-lines", type=int, default=200, help="most lines of pseudo-C to show (default 200)")
    ap.add_argument("--no-similar", action="store_true", help="skip the similar matched functions")
    ap.add_argument("-n", type=int, default=SIMILAR, help=f"similar functions to show (default {SIMILAR})")
    args = ap.parse_args(argv)

    from common import load_module
    from funcs import find
    from nx.refs import decode, is_b_bl
    import units as U

    rows = read_functions_csv()
    fn = find(rows, args.addr)
    by_addr = {r.sword: r for r in rows if r.sword is not None}
    mod = load_module("sword")
    img = mod["image"]
    index = U.source_index()

    # 1. the function
    names = [fn.name] if fn.name else []
    section("function")
    dm = demangle(names)
    print(f"{dm.get(fn.name, fn.display_name)}")
    if fn.name:
        print(f"  mangled: {fn.name}")
    print("  " + ", ".join(f"{v} 0x{fn.addr(v) + BASE:x} ({fn.size(v)} bytes)" for v in VERSIONS if fn.in_version(v)))
    print(f"  scope {fn.scope}, status {fn.status}")
    own_file = None
    if fn.sword is not None:
        all_units = U.build_units(rows, U.read_areas_csv(), U.exe_segments("sword"), index, "UmMO",
                                  exists=lambda p: (ROOT / p).exists())
        u = next((u for u in all_units if any(f is fn for f in u.funcs)), None)
        if u is not None:
            part = next(p for p in u.parts if any(f is fn for f in p.funcs))
            print(f"  area {u.area}, unit {u.id}, segment 0x{part.segment[0] + BASE:x}-0x{part.segment[1] + BASE:x}")
            print(f"  source file: {part.file}{' (new)' if part.new_file else ''}")
            own_file = part.file
        else:
            print("  in no unit (an excluded area)")
    if fn.scope == "diverged":
        print("  diverged: compare both columns below and use PKMN_SW_SH / #if PKMN_IS_SWORD where they differ")
    elif fn.scope in ("sword", "shield"):
        print(f"  {fn.scope} only: the whole function goes inside #if PKMN_IS_{fn.scope.upper()}")

    # 2. asm
    section("original asm (tools/funcs.py show)")
    sys.stdout.flush()
    subprocess.run([sys.executable, str(ROOT / "tools" / "funcs.py"), "show", args.addr], check=False)

    # 3. Ghidra
    section("Ghidra pseudo-C: a ROUGH DRAFT of the logic, not source (rewrite it; never copy its names/casts)")
    games = ["sword"] + (["shield"] if fn.scope in ("diverged", "shield") else [])
    if fn.scope == "shield":
        games = ["shield"]
    for g in games:
        a = fn.addr(g)
        p = ghidra_path(g, a) if a is not None else None
        if p is None or not p.exists():
            print(f"[{g}] not in the export cache (the main thread refreshes it with ghidra.sh refresh; "
                  "never open the Ghidra project yourself)")
            continue
        lines = p.read_text(encoding="utf-8", errors="replace").splitlines()
        if len(games) > 1:
            print(f"[{g}]")
        print("\n".join(lines[:args.ghidra_lines]))
        if len(lines) > args.ghidra_lines:
            print(f"... {len(lines) - args.ghidra_lines} more lines ({p})")

    # 4. callees and data
    section("calls and data")
    if fn.sword is None:
        print("(no Sword copy)")
        return 0
    data_syms = read_data_symbols()
    calls: list[tuple[int, bool]] = []
    refs: list[int] = []
    a, n = fn.sword, fn.sword_size or 0
    for _, w, _, t in decode(img, a, n):
        if t is None:
            continue
        if is_b_bl(w):
            if not a <= t < a + n and all(t != c for c, _ in calls):
                calls.append((t, not (w >> 31) & 1))  # B (tail call) has bit 31 clear
        elif t not in refs:
            refs.append(t)
    from nx.module import DynInfo
    from nx.nso import Nso
    from common import nso_path

    plt = DynInfo(Nso(nso_path("sword").read_bytes()), img, mod["text_end"]).plt if calls else {}
    callee_names = [by_addr[t].name for t, _ in calls if t in by_addr and by_addr[t].name]
    ref_names = [data_syms[t] for t in refs if t in data_syms]
    dm = demangle(callee_names + ref_names)
    if not calls:
        print("calls nothing (a leaf)")
    for t, tail in calls:
        r = by_addr.get(t)
        where = index.get(t, "")
        if r is None:
            imp = plt.get(t)
            what = f"SDK import {demangle([imp])[imp]}  [{imp}]" if imp else "not a function row"
            print(f"  {'b ' if tail else 'bl'} 0x{t + BASE:x}  {what}")
            continue
        label = dm.get(r.name, r.name) if r.name else f"(unnamed: placeholder Unk_{t:x} unless there's evidence)"
        print(f"  {'b ' if tail else 'bl'} 0x{t + BASE:x} {r.status} {label}" + (f"   [{where}]" if where else ""))
    for t in inline_hazards([t for t, _ in calls], index, own_file):
        print(f"  ! 0x{t + BASE:x} is defined in {own_file}: clang would inline it, and the original calls it."
              f" Put this function in another file (one of the unit's, or a new Unk_{fn.sword:x}.cpp next to it)")
    strings = []
    for t in refs:
        if t in data_syms:
            print(f"  data 0x{t + BASE:x} {dm.get(data_syms[t], data_syms[t])}")
        else:
            s = c_string(img, t, mod["rodata"])
            if s is not None:
                strings.append((t, s))
    for t, s in strings[:10]:
        print(f"  str  0x{t + BASE:x} {s[:80]!r}")
    unnamed = [t for t in refs if t not in data_syms and all(t != x for x, _ in strings)]
    if unnamed:
        print(f"  {len(unnamed)} other data references without a data_symbols.csv name: "
              + ", ".join(f"0x{t + BASE:x}" for t in unnamed[:8]))

    # 5. headers
    section("headers of the classes it touches")
    wanted = Counter()
    for nm in [fn.name, *callee_names, *ref_names]:
        if nm:
            for c in class_names(nm):
                wanted[c] += 1
    hidx = header_index() if wanted else {}
    shown = 0
    for c, _ in wanted.most_common():
        if c in hidx:
            print(f"  {c}: {', '.join(hidx[c][:3])}")
            shown += 1
    if not shown:
        print("  none found: declare what you need in the unit's file (with size/offset asserts)")

    # 6. similar matched functions
    if args.no_similar or not n:
        return 0
    section("most similar matched functions (shape distance), with their source")
    target = masked(img, fn)
    lo, hi = int(n * 0.7), int(n * 1.4) + 4
    cands = [(r.sword, masked(img, r)) for r in rows
             if r.status == "O" and r.sword is not None and r.sword != fn.sword
             and lo <= (r.sword_size or 0) <= hi and r.sword in index]
    best = rank_similar(target, cands, args.n * 3)
    shown = 0
    for score, ca in best:
        path = index[ca]
        snippet = source_snippet((ROOT / path).read_text(encoding="utf-8", errors="replace"), ca)
        if snippet is None:
            continue
        r = by_addr[ca]
        print(f"\n--- {score:.2f}  0x{ca + BASE:x} ({r.sword_size} bytes) {path}")
        print(snippet)
        shown += 1
        if shown >= args.n:
            break
    if not shown:
        print("  none with source found")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
