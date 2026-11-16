#!/usr/bin/env python3
"""Codegen fingerprints of an address range, per game (see docs/compiler.md).

Counts instruction idioms that tell compilers and flag sets apart without any
source code, for a region of `main`:

    python tools/fingerprint.py wwise game physx           # areas.csv names
    python tools/fingerprint.py lua=0x7101548410-0x7101570900 --game both
    python tools/fingerprint.py 0x7100596d20-0x7101548410,0x7100596d20-0x71015484b0

A target is an area name from data/areas.csv or `[label=]LO-HI[,SHLO-SHHI]`
(end exclusive). Addresses without a Shield range are Sword addresses; the
Shield range then comes from the area's ShieldStart/ShieldEnd columns if
data/areas.csv has them, else from the paired rows of data/functions.csv
(the lowest Shield start and highest Shield end of the functions whose Sword
start is in the range). `--game both` (the default) prints both games.

The unit is the function: a function belongs to a range when its start
address is in it, and only its own instructions (the FDE-derived boundaries of
tools/common.py's load_module) are scanned, never alignment padding.

Metrics (W = 32-bit register, X = 64-bit; "consecutive" = adjacent words of
one function; "signed offset" = the `[xN, #imm]` form, no writeback):

functions
    Functions whose start is in the range.
calling / frame_pointer
    `calling`: functions with a `bl` or `blr`. `frame_pointer`: calling
    functions that set up a frame pointer (`add x29, sp, #imm`, which includes
    `mov x29, sp`). Every calling function does with -fno-omit-frame-pointer.
orr_wzr / movz_logical
    The clang 9 constant-materialisation change. Up to clang 8 a 32-bit
    constant that is a valid logical immediate is built with `orr wD, wzr,
    #imm`; from clang 9 on, one that a single `movz` can build uses `movz`.
    `orr_wzr` counts every `orr wD, wzr, #imm`. `movz_logical` counts 32-bit
    `movz wD, #imm16{, lsl #16}` whose value is also a valid 32-bit logical
    immediate, i.e. the ones clang 8 and older would have built with `orr`.
movi_zero
    `movi vD.2d, #0` (q-register zeroing: implicit float).
stp_xzr / stp_xzr_pairs
    `stp xzr, xzr, [xN, #imm]` (signed offset; GPR zeroing). `stp_xzr_pairs`:
    two consecutive ones with the same base and offsets 16 apart, in either
    order (32 contiguous bytes zeroed).
stp_q
    `stp qA, qB, [...]` (any addressing mode).
ldp_stp_x / ldr_str_q
    16-byte copies. `ldp_stp_x`: `ldp xA, xB, [...]` immediately followed by
    `stp xA, xB, [...]` (any addressing modes). `ldr_str_q`: `ldr qA, [xN,
    #imm]` immediately followed by `str qA, [xM, #imm]` (unsigned offsets).
g_ldr_pairs / g_ldr_pairs_desc / g_ldp_base
    The `-g` signal (docs/compiler.md, "Debug info"). `g_ldr_pairs`: two
    consecutive same-size `ldr` (X or W, unsigned offset) `ldr rA, [xN, #i]`,
    `ldr rN, [xN, #i+size]` with N != sp, A != N, and i <= 63 * size (an `ldp`
    could encode it): the second loads the next field into the base register,
    as in Lua's `stackinuse`. `g_ldr_pairs_desc`: the same with the second
    offset `i-size`. `g_ldp_base`: `ldp rA, rN, [xN, #imm]` (X or W, signed
    offset) whose second destination is the base: the pairs that did form.
and_shift / and_shift_funcs
    clang 6's redundant zero extension: `and xD, xS, #0xffffffff` with a
    32-bit variable shift (`lslv`/`lsrv`/`asrv`/`rorv` wR, wN, wD, i.e. the
    shift amount is register D) in one of the next 4 instructions of the same
    function. `and_shift_funcs` is the number of distinct functions.
fde_<aug>
    FDEs in .eh_frame whose initial location is in the range, by their CIE's
    augmentation string (`zR` = no personality, `zPLR` = personality + LSDA,
    i.e. C++ exceptions).

`--typeinfo PREFIX` (repeatable) adds `typeinfo_<PREFIX>`: NUL-terminated
strings in .rodata that are Itanium-mangled class names (the `_ZTS` contents,
`<len><id>` or `N<len><id>...E`, optionally with template arguments) with a
`<len><id>` component, anywhere in the name, whose identifier starts with
PREFIX. It is module-wide, not per range.
"""
from __future__ import annotations

import argparse
import csv
import re
import struct
import sys
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BASE, ROOT, VERSIONS  # noqa: E402

AREAS = ROOT / "data" / "areas.csv"
SHIFT_WINDOW = 4

# Display order of the per-range metrics (fde_* and typeinfo_* follow).
METRICS = [
    "functions", "calling", "frame_pointer", "orr_wzr", "movz_logical",
    "movi_zero", "stp_xzr", "stp_xzr_pairs", "stp_q", "ldp_stp_x", "ldr_str_q",
    "g_ldr_pairs", "g_ldr_pairs_desc", "g_ldp_base", "and_shift", "and_shift_funcs",
]


# --------------------------------------------------------------------------- encodings
def logical_imm(n: int, immr: int, imms: int, width: int) -> int | None:
    """Value of an AArch64 logical (bitmask) immediate, or None if reserved."""
    combined = (n << 6) | (~imms & 0x3F)
    if combined == 0:
        return None
    length = combined.bit_length() - 1
    esize = 1 << length
    if length < 1 or esize > width:
        return None
    levels = esize - 1
    s, r = imms & levels, immr & levels
    if s == levels:
        return None
    elem = (1 << (s + 1)) - 1
    elem = ((elem >> r) | (elem << (esize - r))) & ((1 << esize) - 1)
    out = 0
    for i in range(0, width, esize):
        out |= elem << i
    return out


LOGICAL32 = frozenset(v for immr in range(64) for imms in range(64)
                      if (v := logical_imm(0, immr, imms, 32)) is not None)


def orr_wzr_value(w: int) -> int | None:
    """Immediate of `orr wD, wzr, #imm`, else None."""
    if (w & 0xFFC003E0) != 0x320003E0:  # sf=0, opc=01 (orr), N=0, Rn=wzr
        return None
    return logical_imm(0, (w >> 16) & 0x3F, (w >> 10) & 0x3F, 32)


def movz32_value(w: int) -> int | None:
    """Value of a 32-bit `movz wD, #imm16{, lsl #16}`, else None."""
    if (w & 0xFFC00000) != 0x52800000:  # sf=0, opc=10, hw<2
        return None
    return ((w >> 5) & 0xFFFF) << (16 * ((w >> 21) & 1))


def is_call(w: int) -> bool:
    """bl or blr."""
    return (w & 0xFC000000) == 0x94000000 or (w & 0xFFFFFC1F) == 0xD63F0000


def is_fp_setup(w: int) -> bool:
    """add x29, sp, #imm (including mov x29, sp)."""
    return (w & 0xFF8003FF) == 0x910003FD


def is_stp_xzr(w: int) -> bool:
    """stp xzr, xzr, [xN, #imm] (signed offset)."""
    return (w & 0xFFC07C1F) == 0xA9007C1F


def stp_xzr_contiguous(w1: int, w2: int) -> bool:
    """Two stp xzr, xzr with the same base and offsets 16 bytes apart (either order)."""
    if not (is_stp_xzr(w1) and is_stp_xzr(w2)) or (w1 >> 5) & 0x1F != (w2 >> 5) & 0x1F:
        return False
    return ((w2 >> 15) - (w1 >> 15)) & 0x7F in (2, 0x7E)  # imm7 is scaled by 8


def is_stp_q(w: int) -> bool:
    return (w & 0xFFC00000) in (0xAC800000, 0xAD000000, 0xAD800000)  # post, offset, pre


def is_movi_2d_zero(w: int) -> bool:
    return (w & 0xFFFFFFE0) == 0x6F00E400


def is_ldp_stp_copy(w1: int, w2: int) -> bool:
    """ldp xA, xB, [...] then stp xA, xB, [...] (any addressing mode)."""
    return ((w1 & 0xFFC00000) in (0xA8C00000, 0xA9400000, 0xA9C00000)
            and (w2 & 0xFFC00000) in (0xA8800000, 0xA9000000, 0xA9800000)
            and (w1 & 0x7C1F) == (w2 & 0x7C1F))


def is_ldr_str_q_copy(w1: int, w2: int) -> bool:
    """ldr qA, [xN, #imm] then str qA, [xM, #imm] (unsigned offsets)."""
    return ((w1 & 0xFFC00000) == 0x3DC00000 and (w2 & 0xFFC00000) == 0x3D800000
            and (w1 & 0x1F) == (w2 & 0x1F))


def ldr_uimm(w: int) -> tuple[int, int, int, int] | None:
    """(Rt, Rn, byte offset, size) of `ldr xT|wT, [xN, #imm]` (unsigned offset), else None."""
    if (w & 0xFFC00000) == 0xF9400000:
        size = 8
    elif (w & 0xFFC00000) == 0xB9400000:
        size = 4
    else:
        return None
    return w & 0x1F, (w >> 5) & 0x1F, ((w >> 10) & 0xFFF) * size, size


def g_ldr_pair(w1: int, w2: int) -> int:
    """+1 / -1 if (w1, w2) is an unpaired `ldr` pair into the base (ascending /
    descending offsets, see g_ldr_pairs in the module docstring), else 0."""
    a, b = ldr_uimm(w1), ldr_uimm(w2)
    if a is None or b is None:
        return 0
    (t1, n1, o1, s1), (t2, n2, o2, s2) = a, b
    if s1 != s2 or not (n1 == n2 != 31 and t2 == n2 and t1 != n1) or min(o1, o2) > 63 * s1:
        return 0
    return 1 if o2 - o1 == s1 else -1 if o1 - o2 == s1 else 0


def is_ldp_base(w: int) -> bool:
    """ldp rA, rN, [xN, #imm] (X or W, signed offset): second destination is the base."""
    return (w & 0x7FC00000) == 0x29400000 and ((w >> 10) & 0x1F) == ((w >> 5) & 0x1F)


def and_ffffffff_rd(w: int) -> int | None:
    """Rd of `and xD, xS, #0xffffffff`, else None."""
    return w & 0x1F if (w & 0xFFFFFC00) == 0x92407C00 else None


def shift32_amount_reg(w: int) -> int | None:
    """Rm of a 32-bit lslv/lsrv/asrv/rorv, else None."""
    return (w >> 16) & 0x1F if (w & 0xFFE0F000) == 0x1AC02000 else None


# --------------------------------------------------------------------------- per-function scan
def scan_function(words) -> Counter:
    """Metric counts for one function's instruction words."""
    c: Counter = Counter(functions=1)
    calls = fp = False
    and_hits = 0
    prev = None
    for i, w in enumerate(words):
        calls = calls or is_call(w)
        fp = fp or is_fp_setup(w)
        if orr_wzr_value(w) is not None:
            c["orr_wzr"] += 1
        elif movz32_value(w) in LOGICAL32:
            c["movz_logical"] += 1
        if is_movi_2d_zero(w):
            c["movi_zero"] += 1
        if is_stp_xzr(w):
            c["stp_xzr"] += 1
        if is_stp_q(w):
            c["stp_q"] += 1
        if is_ldp_base(w):
            c["g_ldp_base"] += 1
        if prev is not None:
            c["stp_xzr_pairs"] += stp_xzr_contiguous(prev, w)
            c["ldp_stp_x"] += is_ldp_stp_copy(prev, w)
            c["ldr_str_q"] += is_ldr_str_q_copy(prev, w)
            d = g_ldr_pair(prev, w)
            if d:
                c["g_ldr_pairs" if d > 0 else "g_ldr_pairs_desc"] += 1
        rd = and_ffffffff_rd(w)
        if rd is not None and any(shift32_amount_reg(x) == rd for x in words[i + 1:i + 1 + SHIFT_WINDOW]):
            and_hits += 1
        prev = w
    if calls:
        c["calling"] = 1
        c["frame_pointer"] = int(fp)
    if and_hits:
        c["and_shift"] = and_hits
        c["and_shift_funcs"] = 1
    return c


# --------------------------------------------------------------------------- eh_frame CIEs
def fde_augmentations(img: bytes, hdr_start: int) -> list[tuple[int, str]]:
    """(initial location, CIE augmentation string) for every FDE in .eh_frame_hdr."""
    from nx.ehframe import _cie_fde_encoding, _read_enc

    version, eh_ptr_enc, count_enc, table_enc = img[hdr_start:hdr_start + 4]
    if version != 1:
        raise ValueError(f"unsupported .eh_frame_hdr version {version}")
    o = hdr_start + 4
    _, o = _read_enc(img, o, eh_ptr_enc)
    count, o = _read_enc(img, o, count_enc)
    cies: dict[int, tuple[str, int]] = {}
    out = []
    for _ in range(count):
        _, o = _read_enc(img, o, table_enc, hdr_start)
        fde, o = _read_enc(img, o, table_enc, hdr_start)
        cie = fde + 4 - struct.unpack_from("<I", img, fde + 4)[0]
        if cie not in cies:
            aug_end = img.index(b"\0", cie + 9)
            cies[cie] = (img[cie + 9:aug_end].decode(), _cie_fde_encoding(img, cie))
        aug, enc = cies[cie]
        start, _ = _read_enc(img, fde + 8, enc)
        out.append((start, aug))
    return out


# --------------------------------------------------------------------------- typeinfo names
_IDENT = re.compile(rb"[A-Za-z_][A-Za-z0-9_]*")
_SOURCE_NAME = re.compile(rb"([1-9][0-9]*)")


def mangled_components(s: bytes) -> list[bytes] | None:
    """The `<len><id>` identifiers of an Itanium-mangled class name (`_ZTS`
    contents: `<len><id>[I...E]` or `N<len><id>...E`), else None.

    The first component is validated strictly; later ones are collected
    wherever a decimal length is followed by a valid identifier that long."""
    nested = s[:1] == b"N"
    if nested and not s.endswith(b"E"):
        return None
    m = _SOURCE_NAME.match(s, int(nested))
    if not m:
        return None
    n, p = int(m.group(1)), m.end()
    first = s[p:p + n]
    if len(first) != n or not _IDENT.fullmatch(first):
        return None
    p += n
    if not nested and p < len(s) and s[p:p + 1] != b"I":
        return None
    out = [first]
    while p < len(s):
        m = _SOURCE_NAME.match(s, p)
        if not m:
            p += 1
            continue
        n, q = int(m.group(1)), m.end()
        ident = s[q:q + n]
        if len(ident) == n and _IDENT.fullmatch(ident):
            out.append(ident)
            p = q + n
        else:
            p = q
    return out


def typeinfo_names(rodata: bytes, prefixes: list[str]) -> Counter:
    """typeinfo_<PREFIX> -> .rodata mangled class names with a component starting with PREFIX."""
    c: Counter = Counter({f"typeinfo_{p}": 0 for p in prefixes})
    for s in rodata.split(b"\0"):
        if not s or len(s) > 1024:
            continue
        comps = mangled_components(s)
        if not comps:
            continue
        for p in prefixes:
            if any(x.startswith(p.encode()) for x in comps):
                c[f"typeinfo_{p}"] += 1
    return c


# --------------------------------------------------------------------------- module + ranges
def load(game: str) -> dict:
    """load_module() plus the .eh_frame_hdr FDE list."""
    from common import load_module, nso_path
    from nx.nso import Nso

    mod = load_module(game)
    if "fdes" not in mod:
        nso = Nso(nso_path(game).read_bytes())
        mod["fdes"] = fde_augmentations(mod["image"], nso.mod0.eh_frame_hdr_start)
    return mod


def fingerprint(mod: dict, lo: int, hi: int) -> Counter:
    """Metrics for the functions starting in [lo, hi) (image offsets)."""
    img = mod["image"]
    c: Counter = Counter({m: 0 for m in METRICS})
    for a, s in mod["functions"]:
        if lo <= a < hi and s >= 4:
            n = s // 4
            c.update(scan_function(struct.unpack_from(f"<{n}I", img, a)))
    for start, aug in mod["fdes"]:
        if lo <= start < hi:
            c[f"fde_{aug}"] += 1
    return c


def read_areas(path: Path = AREAS) -> dict[str, dict[str, tuple[int, int]]]:
    """area -> {game: (lo, hi)} from areas.csv (Start/End or SwordStart/.../ShieldEnd)."""
    out: dict[str, dict[str, tuple[int, int]]] = {}
    with open(path, newline="", encoding="utf-8") as fh:
        for r in csv.DictReader(fh):
            sw = (r.get("SwordStart") or r.get("Start"), r.get("SwordEnd") or r.get("End"))
            ranges = {"sword": (int(sw[0], 16), int(sw[1], 16))}
            if r.get("ShieldStart") and r.get("ShieldEnd"):
                ranges["shield"] = (int(r["ShieldStart"], 16), int(r["ShieldEnd"], 16))
            out.setdefault(r["Area"], ranges)  # first row of a split area wins
    return out


def shield_from_functions(lo: int, hi: int, funcs=None) -> tuple[int, int]:
    """Shield range paired with the Sword range [lo, hi) through functions.csv."""
    from common import read_functions_csv

    rows = [f for f in (funcs or read_functions_csv())
            if f.sword is not None and lo - BASE <= f.sword < hi - BASE and f.shield is not None]
    if not rows:
        raise SystemExit(f"no Shield functions pair with {lo:#x}-{hi:#x}")
    return (min(f.shield for f in rows) + BASE,
            max(f.shield + (f.shield_size or 0) for f in rows) + BASE)


def _range(s: str) -> tuple[int, int]:
    lo, hi = (int(x, 16) for x in s.split("-"))
    if hi <= lo:
        raise SystemExit(f"empty range {s}")
    return lo, hi


def parse_target(spec: str, areas: dict) -> tuple[str, dict[str, tuple[int, int]]]:
    """`area` or `[label=]LO-HI[,SHLO-SHHI]` -> (label, {game: (lo, hi)})."""
    label, _, body = spec.rpartition("=")
    if not label and spec in areas:
        return spec, dict(areas[spec])
    if not label and "-" not in body:
        raise SystemExit(f"unknown area {spec!r} (areas: {', '.join(areas)})")
    sw, _, sh = body.partition(",")
    ranges = {"sword": _range(sw)}
    if sh:
        ranges["shield"] = _range(sh)
    return label or body, ranges


def resolve(ranges: dict[str, tuple[int, int]], game: str, funcs=None) -> tuple[tuple[int, int], str]:
    """Range for `game`, and where it came from."""
    if game in ranges:
        return ranges[game], "given"
    return shield_from_functions(*ranges["sword"], funcs), "functions.csv"


# --------------------------------------------------------------------------- output
def markdown(results: dict[str, dict[str, Counter]], labels: list[str], games: list[str]) -> str:
    cols = [(t, g) for t in labels for g in games]
    head = [f"{t} ({g})" if len(games) > 1 else t for t, g in cols]
    keys = list(METRICS) + sorted({k for t, g in cols for k in results[t][g] if k not in METRICS})
    lines = ["| Metric | " + " | ".join(head) + " |", "|---|" + "---:|" * len(cols)]
    for k in keys:
        lines.append(f"| `{k}` | " + " | ".join(f"{results[t][g].get(k, 0):,}" for t, g in cols) + " |")
    return "\n".join(lines)


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("targets", nargs="+", help="area name or [label=]LO-HI[,SHLO-SHHI] (Sword[,Shield])")
    ap.add_argument("--game", choices=[*VERSIONS, "both"], default="both")
    ap.add_argument("--typeinfo", action="append", default=[], metavar="PREFIX",
                    help="count .rodata mangled class names starting with PREFIX (module-wide)")
    args = ap.parse_args(argv)

    games = list(VERSIONS) if args.game == "both" else [args.game]
    areas = read_areas() if AREAS.exists() else {}
    targets = [parse_target(t, areas) for t in args.targets]
    funcs = None
    results: dict[str, dict[str, Counter]] = {}
    for g in games:
        mod = load(g)
        ti = typeinfo_names(mod["image"][mod["rodata"][0]:mod["rodata"][1]], args.typeinfo) if args.typeinfo else None
        for label, ranges in targets:
            if g not in ranges and funcs is None:
                from common import read_functions_csv
                funcs = read_functions_csv()
            (lo, hi), src = resolve(ranges, g, funcs)
            print(f"{g:6} {label}: {lo:#x}-{hi:#x} ({src})", file=sys.stderr)
            c = fingerprint(mod, lo - BASE, hi - BASE)
            if ti is not None:
                c.update(ti)
            results.setdefault(label, {})[g] = c
    print(markdown(results, [t for t, _ in targets], games))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
