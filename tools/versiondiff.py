#!/usr/bin/env python3
"""Pair every function in Sword's main with its Shield counterpart and classify it.

Scopes written to data/functions.csv:
  common       same code in both games (identical bytes, or identical modulo
               addresses: every call/ADRP/literal points at the equivalent target)
  common-data  same instructions, but some referenced rodata differs per game
               (e.g. a different string literal / constant) -> one implementation,
               the difference lives in data
  diverged     both games have the function but the code differs -> one
               implementation with PKMN_VERSION conditionals, checked against both
  sword        exists only in Sword
  shield       exists only in Shield

Usage: tools/versiondiff.py [--update-csv] [--report FILE]
"""
from __future__ import annotations

import argparse
import bisect
import difflib
import hashlib
import json
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import ROOT, VERSIONS, load_module, read_functions_csv, write_functions_csv, Function  # noqa: E402
from nx.refs import decode, is_ldr_literal, is_ldst_uimm, ldst_scale  # noqa: E402


class Mod:
    def __init__(self, version: str):
        m = load_module(version)
        self.version = version
        self.img: bytes = m["image"]
        self.funcs: list[tuple[int, int]] = m["functions"]
        self.text_end: int = m["text_end"]
        self.rodata: tuple[int, int] = m["rodata"]
        self.data_start: int = m["data_start"]
        self.starts = [a for a, _ in self.funcs]
        self.last_end = self.funcs[-1][0] + self.funcs[-1][1]
        self._decoded: dict[int, list] = {}

    def decoded(self, idx: int):
        d = self._decoded.get(idx)
        if d is None:
            a, s = self.funcs[idx]
            d = self._decoded[idx] = list(decode(self.img, a, s))
        return d

    def shape_key(self, idx: int) -> bytes:
        return hashlib.blake2b(b"".join(m.to_bytes(4, "little") for _, _, m, _ in self.decoded(idx)), digest_size=12).digest()

    def locate_text(self, addr: int):
        i = bisect.bisect_right(self.starts, addr) - 1
        if i >= 0:
            a, s = self.funcs[i]
            if addr < a + s:
                return ("f", i, addr - a)
        if addr >= self.last_end:
            return ("tail", addr - self.last_end)  # PLT / trailing stubs
        return ("raw", addr)


def align(sw: Mod, sh: Mod) -> list[tuple[int | None, int | None]]:
    ka = [sw.shape_key(i) for i in range(len(sw.funcs))]
    kb = [sh.shape_key(i) for i in range(len(sh.funcs))]
    pairs: list[tuple[int | None, int | None]] = []
    sm = difflib.SequenceMatcher(None, ka, kb, autojunk=False)
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == "equal":
            pairs += [(i1 + k, j1 + k) for k in range(i2 - i1)]
            continue
        # differing block: pair positionally when counts match, else greedy by size
        a_idx, b_idx = list(range(i1, i2)), list(range(j1, j2))
        if len(a_idx) == len(b_idx):
            pairs += list(zip(a_idx, b_idx))
            continue
        used = set()
        for i in a_idx:
            sa = sw.funcs[i][1]
            best = min((j for j in b_idx if j not in used), key=lambda j: abs(sh.funcs[j][1] - sa), default=None)
            if best is not None and abs(sh.funcs[best][1] - sa) <= max(16, sa // 4):
                used.add(best); pairs.append((i, best))
            else:
                pairs.append((i, None))
        pairs += [(None, j) for j in b_idx if j not in used]
    pairs.sort(key=lambda p: (sw.funcs[p[0]][0] if p[0] is not None else sh.funcs[p[1]][0]))
    return pairs


def same_jump_table(sw: Mod, sh: Mod, ta: int, tb: int, func_map: dict[int, int]) -> bool:
    """True if ta/tb are switch tables of s32 offsets (relative to the table) whose
    entries all land on corresponding code. Code moving between the games
    changes every entry even though the switch itself is identical."""
    n = 0
    while n < 4096 and ta + 4 * n + 4 <= sw.data_start:
        ea = struct.unpack_from("<i", sw.img, ta + 4 * n)[0]
        eb = struct.unpack_from("<i", sh.img, tb + 4 * n)[0]
        la, lb = sw.locate_text(ta + ea), sh.locate_text(tb + eb)
        if la[0] != "f" or lb[0] != "f" or not (0 <= ta + ea < sw.text_end):
            break  # end of table
        if func_map.get(la[1]) != lb[1] or la[2] != lb[2]:
            return False
        n += 1
    return n >= 2


def same_rodata(sw: Mod, sh: Mod, w: int, ta: int, tb: int, shift: int) -> bool:
    """Compare the rodata an instruction references in both games."""
    if is_ldst_uimm(w) or is_ldr_literal(w):
        width = 1 << ldst_scale(w) if is_ldst_uimm(w) else (8 if (w >> 30) & 1 else 4)
        return sw.img[ta:ta + width] == sh.img[tb:tb + width]
    # address taken (ADD/ADR): a string, or an object of unknown size.
    a, b = sw.img, sh.img
    end = a.find(b"\0", ta, ta + 256)
    if end > ta and all(32 <= c < 127 or c in (9, 10, 13) for c in a[ta:end]):
        return a[ta:end + 1] == b[tb:tb + end + 1 - ta]
    if a[ta:ta + 16] == b[tb:tb + 16]:
        return True
    # Compare aligned words covering the window; words differing by exactly the
    # code shift are entries of a neighbouring switch jump table (s32 offsets to
    # code that moved), not a real data difference.
    p0 = ta & ~3
    for p in range(p0, ta + 16, 4):
        q = p + (tb - ta)
        wa, wb = struct.unpack_from("<i", a, p)[0], struct.unpack_from("<i", b, q)[0]
        if wa != wb and wb - wa != shift:
            return False
    return True


def classify(sw: Mod, sh: Mod, i: int, j: int, func_map: dict[int, int]) -> tuple[str, list[str]]:
    # Note: no byte-identical fast path - identical bytes at the same address can
    # still BL into a function that moved, so every reference is always checked.
    da, db = sw.decoded(i), sh.decoded(j)
    if len(da) != len(db) or any(x[2] != y[2] for x, y in zip(da, db)):
        return "diverged", ["instructions differ"]
    notes: list[str] = []
    data_diff = False
    ro0, ro1 = sw.rodata
    shift = sh.funcs[j][0] - sw.funcs[i][0]
    for (off, w, _, ta), (_, _, _, tb) in zip(da, db):
        if ta is None:
            continue
        if ta < sw.text_end:
            la, lb = sw.locate_text(ta), sh.locate_text(tb)
            if la[0] == "f" and lb[0] == "f":
                if func_map.get(la[1]) != lb[1] or la[2] != lb[2]:
                    return "diverged", [f"+{off:#x}: calls/refs a different function"]
            elif la != lb:
                return "diverged", [f"+{off:#x}: text ref mismatch"]
        elif ta < sw.data_start:
            if not same_rodata(sw, sh, w, ta, tb, shift) and not same_jump_table(sw, sh, ta, tb, func_map):
                data_diff = True
                notes.append(f"+{off:#x}: rodata {ta + 0x7100000000:#x}/{tb + 0x7100000000:#x} differs")
        elif ta != tb:
            return "diverged", [f"+{off:#x}: data ref {ta:#x} vs {tb:#x}"]
    return ("common-data" if data_diff else "common"), notes


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--update-csv", action="store_true", help="(re)write data/functions.csv, keeping existing names/status")
    ap.add_argument("--report", type=Path, default=ROOT / "data" / "version_diff.json")
    args = ap.parse_args()

    sw, sh = Mod("sword"), Mod("shield")
    pairs = align(sw, sh)
    func_map = {i: j for i, j in pairs if i is not None and j is not None}

    rows: list[Function] = []
    report: dict[str, list] = {"diverged": [], "common-data": [], "sword": [], "shield": []}
    counts: dict[str, int] = {}
    for i, j in pairs:
        if i is None:
            b, t = sh.funcs[j]
            scope, notes, sa, ss = "shield", [], None, None
            rows.append(Function(sword=None, shield=b, sword_size=None, shield_size=t, scope="shield"))
        elif j is None:
            a, s = sw.funcs[i]
            scope, notes = "sword", []
            rows.append(Function(sword=a, shield=None, sword_size=s, shield_size=None, scope="sword"))
        else:
            (a, s), (b, t) = sw.funcs[i], sh.funcs[j]
            scope, notes = classify(sw, sh, i, j, func_map)
            rows.append(Function(sword=a, shield=b, sword_size=s, shield_size=t, scope=scope))
        counts[scope] = counts.get(scope, 0) + 1
        if scope != "common":
            r = rows[-1]
            report[scope].append({"sword": r.sword_str, "shield": r.shield_str,
                                  "sword_size": r.sword_size, "shield_size": r.shield_size, "notes": notes[:4]})

    total = len(rows)
    print(f"{total} functions")
    for k in ("common", "common-data", "diverged", "sword", "shield"):
        print(f"  {k:12} {counts.get(k, 0):7}  ({100 * counts.get(k, 0) / total:.2f}%)")

    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_text(json.dumps({"counts": counts, **report}, indent=1) + "\n")
    print(f"wrote {args.report.relative_to(ROOT)}")

    if args.update_csv:
        csv_path = ROOT / "data" / "functions.csv"
        old = {r.key: r for r in read_functions_csv(csv_path)} if csv_path.exists() else {}
        for r in rows:
            if r.key in old:
                r.status, r.name = old[r.key].status, old[r.key].name
        write_functions_csv(csv_path, rows)
        print(f"wrote {csv_path.relative_to(ROOT)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
