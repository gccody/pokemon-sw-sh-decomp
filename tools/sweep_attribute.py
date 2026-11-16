#!/usr/bin/env python3
"""Attribute the original functions of a range to the compiled functions of a
compiler_sweep.py run, and classify the ones that don't match (docs/compiler.md,
"PhysX", "What the sweep doesn't reproduce").

    python tools/compiler_sweep.py ... --obj-dir build/sweep @lib.rsp
    python tools/sweep_attribute.py build/sweep/clang-6.0.1_O3 \\
        --range 0x7100010a90-0x71003035e0 --game sword --out attr.csv

compiler_sweep.py counts a hit only where a compiled function's code equals one
original's. Identical instances (a template instantiated for several types, a
`static` function from a header in several TUs) equal several originals, and
there it can't say which is which. This tool uses what the masking ignores, the
relocation *targets*, to pin names to addresses:

  - a compiled function whose code equals exactly one original is pinned there;
  - a call that reaches a PLT stub in the original must call that import by name
    in the compiled code (otherwise the code isn't the same);
  - once a name is pinned to an original with the same code, every call in it
    pins the callee's name to the original's branch target, and every vtable it
    references (adrp/lo12 or GOT) pins the virtual functions to the original
    vtable's slots. This repeats until nothing changes.

Each original then gets a class:

  attributed       same code as a compiled function whose name is pinned to it
  attributed-trap  the same, once the compile's `brk #1` (upstream llvm.trap) is
                   read as the binary's trap word 0xe7ffdefe
  same-code        same code as some compiled function, but no name is pinned to
                   it (identical copies that nothing references from code)
  differs          a compiled function's name is pinned to it, but the code differs
  pinned-no-copy   a name is pinned to it (a call target), but nothing compiled
                   defines that name
  none             none of the above

Names are file-qualified like compiler_sweep.py's (tools/symbols.py). The
object files must be compiler_sweep.py's, named `<hash>_<stem>.o`.
"""
from __future__ import annotations

import argparse
import csv
import sys
from collections import Counter, defaultdict
from pathlib import Path
from typing import NamedTuple

sys.path.insert(0, str(Path(__file__).resolve().parent))
import compiler_sweep as cs  # noqa: E402
import symbols  # noqa: E402
from common import BASE  # noqa: E402
from nx.refs import ldst_scale  # noqa: E402

from elftools.elf.elffile import ELFFile  # noqa: E402
from elftools.elf.relocation import RelocationSection  # noqa: E402

R_ABS64 = 257
R_ADR_PREL_PG_HI21 = 275
R_LO12 = {277, 278, 284, 285, 286, 299}  # ADD_ABS_LO12_NC, LDST{8,16,32,64,128}_ABS_LO12_NC
R_CALL = {282, 283}  # JUMP26, CALL26
R_GOT_PAGE, R_GOT_LO12 = 311, 312
TRAP_BRK, TRAP_NX = 0xD4200020, 0xE7FFDEFE  # brk #1 / the binary's trap word
CLASSES = ["attributed", "attributed-trap", "same-code", "differs", "pinned-no-copy", "none"]


class Reloc(NamedTuple):
    index: int  # word index in the function
    type: int
    target: str  # file-qualified symbol name, or "<section@stem>" for an anonymous section
    addend: int


class Copy(NamedTuple):
    """One compiled function (template and inline functions have a copy per TU)."""
    name: str
    words: tuple[int, ...]
    relocs: tuple[Reloc, ...] = ()

    @property
    def reloc_indices(self) -> frozenset[int]:
        return frozenset(r.index for r in self.relocs)


class Original(NamedTuple):
    """The original side: function words by address, plus PLT stubs and pointer slots."""
    words: dict[int, tuple[int, ...]]
    plt: dict[int, str]  # stub address -> import name
    slots: dict[int, int | str]  # data address -> pointer target (int) or import name

    def index(self) -> dict[tuple[int, ...], list[int]]:
        out: dict[tuple[int, ...], list[int]] = defaultdict(list)
        for a, ws in self.words.items():
            out[cs.coarse_key(ws)].append(a)
        return out


def _sext(v: int, bits: int) -> int:
    return v - (1 << bits) if v & (1 << (bits - 1)) else v


def branch_target(ws: tuple[int, ...], addr: int, i: int) -> int:
    return addr + 4 * i + 4 * _sext(ws[i] & 0x3FFFFFF, 26)


def adrp_page(ws: tuple[int, ...], addr: int, i: int) -> int:
    w = ws[i]
    imm = ((w >> 29) & 3) | (((w >> 5) & 0x7FFFF) << 2)
    return ((addr + 4 * i) & ~0xFFF) + (_sext(imm, 21) << 12)


def lo12(w: int) -> int:
    imm = (w >> 10) & 0xFFF
    if (w & 0x1F000000) == 0x11000000:  # add/sub immediate
        return imm << (12 if w & (1 << 22) else 0)
    return imm * ldst_scale(w)


def read_object(path: Path, stem: str) -> tuple[list[Copy], dict[str, dict[int, str]]]:
    """Functions and vtables (`_ZTV*`: offset -> function name) of one object file."""
    copies, vtables = [], {}
    src = Path(stem + ".cpp")
    with open(path, "rb") as fh:
        elf = ELFFile(fh)
        syms = list(elf.get_section_by_name(".symtab").iter_symbols())

        def qual(s) -> str:
            return symbols.qualify(s.name, src, s["st_info"]["bind"] == "STB_LOCAL")

        funcs_at: dict[int, dict[int, str]] = defaultdict(dict)  # section -> offset -> name
        for s in syms:
            if s["st_info"]["type"] == "STT_FUNC" and isinstance(s["st_shndx"], int):
                funcs_at[s["st_shndx"]][s["st_value"]] = qual(s)

        def target(r) -> tuple[str, int]:
            s = syms[r["r_info_sym"]]
            if s["st_info"]["type"] == "STT_SECTION":
                name = funcs_at.get(s["st_shndx"], {}).get(r["r_addend"])
                if name:
                    return name, 0
                return f"<{elf.get_section(s['st_shndx']).name}@{stem}>", r["r_addend"]
            return (s.name if s["st_shndx"] == "SHN_UNDEF" else qual(s)), r["r_addend"]

        rels: dict[int, list[tuple[int, int, str, int]]] = defaultdict(list)
        for sec in elf.iter_sections():
            if isinstance(sec, RelocationSection):
                rels[sec["sh_info"]] += [(r["r_offset"], r["r_info_type"], *target(r)) for r in sec.iter_relocations()]
        for s in syms:
            sh = s["st_shndx"]
            if not isinstance(sh, int):
                continue
            v, n = s["st_value"], s["st_size"]
            mine = [(o - v, t, k, ad) for o, t, k, ad in rels.get(sh, ()) if v <= o < v + n]
            if s["st_info"]["type"] == "STT_FUNC" and n >= 4:
                code = elf.get_section(sh).data()[v:v + n]
                copies.append(Copy(qual(s), cs.words(code), tuple(Reloc(o // 4, t, k, ad) for o, t, k, ad in mine)))
            elif s.name.startswith("_ZTV"):
                vtables.setdefault(qual(s), {o: k for o, t, k, _ in mine if t == R_ABS64})
    return copies, vtables


def read_objects(objdir: Path) -> tuple[list[Copy], dict[str, dict[int, str]]]:
    copies, vtables = [], {}
    for obj in sorted(objdir.glob("*.o")):
        c, v = read_object(obj, obj.stem.split("_", 1)[1])
        copies += c
        for k, t in v.items():
            vtables.setdefault(k, t)
    return copies, vtables


def imports_agree(c: Copy, ws: tuple[int, ...], addr: int, plt: dict[int, str]) -> bool:
    """Every call of the original that reaches a PLT stub calls that import in `c`."""
    for r in c.relocs:
        if r.type in R_CALL:
            t = branch_target(ws, addr, r.index)
            if t in plt and plt[t] != r.target:
                return False
    return True


def code_matches(c: Copy, orig: Original, index) -> tuple[set[int], set[int]]:
    """Originals with the same code as `c`, and those that only match with the trap word."""
    rel = c.reloc_indices

    def match(ws):
        return {a for a in index.get(cs.coarse_key(ws), ())
                if cs.same_code(ws, rel, orig.words[a]) and imports_agree(c, orig.words[a], a, orig.plt)}

    exact = match(c.words)
    trap = set()
    if TRAP_BRK in c.words:
        trap = match(tuple(TRAP_NX if w == TRAP_BRK else w for w in c.words)) - exact
    return exact, trap


class Result(NamedTuple):
    pinned: dict[str, int]  # name -> original address (conflicting names left out)
    conflicts: dict[str, set[int]]
    matches: dict[str, set[int]]  # name -> originals with the same code (any copy)
    trap_only: dict[str, set[int]]  # name -> originals that match only with the trap word


def attribute(copies: list[Copy], vtables: dict[str, dict[int, str]], orig: Original) -> Result:
    index = orig.index()
    by_name: dict[str, list[tuple[Copy, set[int]]]] = defaultdict(list)
    trap_only: dict[str, set[int]] = defaultdict(set)
    for c in copies:
        exact, trap = code_matches(c, orig, index)
        by_name[c.name].append((c, exact | trap))
        trap_only[c.name] |= trap
    pinned: dict[str, int] = {}
    conflicts: dict[str, set[int]] = defaultdict(set)

    def pin(name: str, addr: int) -> bool:
        if name.startswith("<"):
            return False
        if name in pinned:
            if pinned[name] != addr:
                conflicts[name] |= {pinned[name], addr}
            return False
        pinned[name] = addr
        return True

    def calls_agree(c: Copy, a: int) -> bool:
        ws = orig.words[a]
        return all(r.type not in R_CALL or r.target not in pinned
                   or pinned[r.target] == branch_target(ws, a, r.index) - r.addend for r in c.relocs)

    def data_refs(c: Copy, a: int):
        """(symbol, addend) -> address, resolved from the original's adrp/lo12 and GOT pairs."""
        ws = orig.words[a]
        pages, los, out = {}, {}, {}
        got_pages, got_los = {}, {}
        for r in c.relocs:
            if r.type == R_ADR_PREL_PG_HI21:
                pages[r.target, r.addend] = adrp_page(ws, a, r.index)
            elif r.type in R_LO12:
                los[r.target, r.addend] = lo12(ws[r.index])
            elif r.type == R_GOT_PAGE:
                got_pages[r.target] = adrp_page(ws, a, r.index)
            elif r.type == R_GOT_LO12:
                got_los[r.target] = ((ws[r.index] >> 10) & 0xFFF) * 8
        for key, p in pages.items():
            if key in los:
                out[key] = p + los[key]
        for sym, p in got_pages.items():
            v = orig.slots.get(p + got_los.get(sym, -1))
            if isinstance(v, int):
                out[sym, 0] = v
        return out

    changed = True
    while changed:
        changed = False
        for name, cl in by_name.items():
            if name not in pinned:
                cand = {a for c, m in cl for a in m if calls_agree(c, a)}
                if len(cand) == 1:
                    changed |= pin(name, cand.pop())
        for name, a in list(pinned.items()):
            for c, m in by_name.get(name, ()):
                if a not in m:
                    continue
                ws = orig.words[a]
                for r in c.relocs:
                    t = branch_target(ws, a, r.index) if r.type in R_CALL else None
                    if t is not None and t not in orig.plt:
                        changed |= pin(r.target, t - r.addend)
                for (sym, addend), d in data_refs(c, a).items():
                    for off, fn in vtables.get(sym, {}).items():
                        v = orig.slots.get(d - addend + off)
                        if isinstance(v, int) and v in orig.words:
                            changed |= pin(fn, v)
    for name in conflicts:
        pinned.pop(name, None)
    matches = {n: set().union(*(m for _, m in cl)) for n, cl in by_name.items()}
    return Result(pinned, dict(conflicts), matches, dict(trap_only))


def classify(res: Result, orig: Original) -> list[tuple[int, int, str, list[str]]]:
    """(address, size, class, names) for every original, in address order."""
    names_at: dict[int, set[str]] = defaultdict(set)
    for n, a in res.pinned.items():
        names_at[a].add(n)
    same_code: dict[int, set[str]] = defaultdict(set)
    for n, m in res.matches.items():
        for a in m:
            same_code[a].add(n)
    rows = []
    for a, ws in sorted(orig.words.items()):
        here = names_at.get(a, set())
        good = sorted(n for n in here if a in res.matches.get(n, ()))
        if good:
            exact = any(a not in res.trap_only.get(n, ()) for n in good)
            rows.append((a, len(ws) * 4, "attributed" if exact else "attributed-trap", good))
        elif a in same_code:
            rows.append((a, len(ws) * 4, "same-code", sorted(same_code[a])))
        elif here & res.matches.keys():
            rows.append((a, len(ws) * 4, "differs", sorted(here & res.matches.keys())))
        elif here:
            rows.append((a, len(ws) * 4, "pinned-no-copy", sorted(here)))
        else:
            rows.append((a, len(ws) * 4, "none", []))
    return rows


def load_original(game: str, lo: int, hi: int, module: str = "main") -> Original:
    from common import ORIGINAL
    from nx.module import DynInfo
    from nx.nso import Nso

    mod = cs.load_original(game, module)
    img = mod["image"]
    nso = Nso((ORIGINAL / game / module).read_bytes())
    dyn = DynInfo(nso, img, mod.get("text_end", nso.text.end))
    ws = {a: cs.words(img, a, s - s % 4) for a, s in mod["functions"] if lo <= a < hi and s >= 4}
    return Original(ws, dyn.plt, dyn.slots)


def summary(rows) -> str:
    count: Counter = Counter()
    size: Counter = Counter()
    for _, n, cls, _ in rows:
        k = (cls, n < 16)
        count[k] += 1
        size[k] += n
    out = [f"{'class':16} {'functions':>9} {'bytes':>9}   {'of them < 16 B':>14} {'bytes':>7}"]
    for cls in CLASSES:
        big, small = (cls, False), (cls, True)
        out.append(f"{cls:16} {count[big] + count[small]:9} {size[big] + size[small]:9}   "
                   f"{count[small]:14} {size[small]:7}")
    out.append(f"{'total':16} {len(rows):9} {sum(r[1] for r in rows):9}")
    return "\n".join(out)


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("objdir", type=Path, help="one configuration's objects (compiler_sweep.py --obj-dir DIR/<config>)")
    ap.add_argument("--range", required=True, help="original address range, e.g. 0x7100010a90-0x71003035e0")
    ap.add_argument("--game", default="sword")
    ap.add_argument("--module", default="main")
    ap.add_argument("--out", type=Path, help="write Address,Size,Class,Names (CSV)")
    args = ap.parse_args(argv)

    lo, hi = (int(x, 16) - BASE for x in args.range.split("-"))
    copies, vtables = read_objects(args.objdir)
    if not copies:
        raise SystemExit(f"no objects in {args.objdir}")
    orig = load_original(args.game, lo, hi, args.module)
    res = attribute(copies, vtables, orig)
    rows = classify(res, orig)
    print(f"{len(copies)} compiled functions, {len(vtables)} vtables, {len(orig.words)} originals; "
          f"{len(res.pinned)} names pinned, {len(res.conflicts)} pinned to two addresses (left out)\n")
    print(summary(rows))
    if args.out:
        with open(args.out, "w", newline="", encoding="utf-8") as fh:
            w = csv.writer(fh, lineterminator="\n")
            w.writerow(["Address", "Size", "Class", "Names"])
            for a, n, cls, names in rows:
                w.writerow([f"{a + BASE:#x}", n, cls, ";".join(names)])
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
