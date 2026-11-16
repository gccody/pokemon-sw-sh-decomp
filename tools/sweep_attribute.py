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
    pins the callee's name to the original's branch target, every function whose
    address it takes (adrp/lo12 or GOT) to that address, and every vtable or other
    pointer table it references to the original table's slots. This repeats
    until nothing changes.

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
objects are either compiler_sweep.py's, named `<hash>_<stem>.o`, or those of a
CMake build dir, read through its compile_commands.json:

    python tools/sweep_attribute.py build/sword --source-prefix lib/physx/ \
        --range 0x7100010a90-0x71003035e0 --game sword --out attr.csv
"""
from __future__ import annotations

import argparse
import csv
import json
import re
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
    tu: str = ""  # stem of the object that defines this copy
    order: int = -1  # position in that object: its section index (-ffunction-sections), then offset

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
    return imm << ldst_scale(w)


def read_object(path: Path, stem: str) -> tuple[list[Copy], dict[str, dict[int, str]]]:
    """Functions and pointer tables of one object file: vtables (`_ZTV*`) and
    other data objects with absolute pointers, each as offset -> target name."""
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
                copies.append(Copy(qual(s), cs.words(code), tuple(Reloc(o // 4, t, k, ad) for o, t, k, ad in mine),
                                   stem, (sh << 32) | v))
            elif s.name.startswith("_ZTV") or s["st_info"]["type"] == "STT_OBJECT":
                table = {o: k for o, t, k, _ in mine if t == R_ABS64}
                if table or s.name.startswith("_ZTV"):
                    vtables.setdefault(qual(s), table)
                if table and s["st_info"]["bind"] == "STB_LOCAL":
                    # code refers to a local object through its section symbol
                    sec = f"<{elf.get_section(sh).name}@{stem}>"
                    vtables.setdefault(sec, {}).update({v + o: k for o, k in table.items()})
    return copies, vtables


def build_objects(build_dir: Path, source_prefix: str = "") -> list[tuple[Path, str]]:
    """(object, stem) for the sources of a CMake build dir (its compile_commands.json)
    whose path relative to the repository starts with `source_prefix` (e.g. lib/physx/)."""
    from common import ROOT

    out = []
    for e in json.loads((build_dir / "compile_commands.json").read_text()):
        src = Path(e["file"])
        try:
            rel = src.resolve().relative_to(ROOT.resolve()).as_posix()
        except ValueError:
            rel = src.as_posix()
        obj = Path(e["directory"]) / e["output"]
        if rel.startswith(source_prefix) and obj.exists():
            out.append((obj, symbols.file_stem(src)))
    return sorted(out)


def read_objects(objdir: Path, source_prefix: str = "") -> tuple[list[Copy], dict[str, dict[int, str]]]:
    """Objects of a compiler_sweep.py configuration (`<hash>_<stem>.o`), or of a
    CMake build dir (one with compile_commands.json, filtered by `source_prefix`)."""
    if (objdir / "compile_commands.json").exists():
        objs = build_objects(objdir, source_prefix)
    else:
        objs = [(obj, obj.stem.split("_", 1)[1]) for obj in sorted(objdir.glob("*.o"))]
    copies, vtables = [], {}
    for obj, stem in objs:
        c, v = read_object(obj, stem)
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
    pinned_at: dict[int, set[str]] = defaultdict(set)  # address -> alias keys pinned there
    conflicts: dict[str, set[int]] = defaultdict(set)

    def pin(name: str, addr: int) -> bool:
        if name.startswith("<"):
            return False
        if name in pinned:
            if pinned[name] != addr:
                conflicts[name] |= {pinned[name], addr}
            return False
        pinned[name] = addr
        pinned_at[addr].add(alias_key(name))
        return True

    def calls_agree(c: Copy, a: int) -> bool:
        """Every call of `c`, placed at `a`, reaches where its callee is pinned,
        and no call reaches an original pinned to another function."""
        ws = orig.words[a]
        for r in c.relocs:
            if r.type not in R_CALL:
                continue
            t = branch_target(ws, a, r.index) - r.addend
            if r.target in pinned:
                if pinned[r.target] != t:
                    return False
            elif pinned_at.get(t) and alias_key(r.target) not in pinned_at[t]:
                return False
        return True

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
                    if sym in by_name and d - addend in orig.words:
                        # the function's address taken (a table filled at run time)
                        changed |= pin(sym, d - addend)
                    for off, fn in vtables.get(sym, {}).items():
                        v = orig.slots.get(d - addend + off)
                        if isinstance(v, int) and v in orig.words:
                            changed |= pin(fn, v)
    for name in conflicts:
        pinned.pop(name, None)
    # One original is one function. Where several names are pinned to one
    # original, those whose code differs from it give way to one whose code is
    # the same; then a name pinned by its unique code before its callees were
    # pinned stays only if its calls still agree. Until nothing changes.
    def same_code(name: str, a: int) -> bool:
        return any(a in m for _, m in by_name.get(name, ()))

    def reindex():
        pinned_at.clear()
        for n, b in pinned.items():
            pinned_at[b].add(alias_key(n))

    at: dict[int, list[str]] = defaultdict(list)
    for name, a in pinned.items():
        at[a].append(name)
    for a, names in at.items():
        if len(names) > 1 and any(same_code(n, a) for n in names):
            for n in names:
                if by_name.get(n) and not same_code(n, a):
                    del pinned[n]
    reindex()
    changed = True
    while changed:
        changed = False
        for name, a in list(pinned.items()):
            cl = [c for c, m in by_name.get(name, ()) if a in m]
            if cl and not any(calls_agree(c, a) for c in cl):
                del pinned[name]
                changed = True
        reindex()
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


_STRUCTOR = re.compile(r"([CD])[12](E)")


def alias_key(name: str) -> str:
    """Complete (C1/D1) and base (C2/D2) constructors and destructors share a key:
    clang emits the complete one as an alias of the base one when they're the same code."""
    return _STRUCTOR.sub(r"\1?\2", name, count=1)


def prefer_base(names) -> str:
    """The name to record for a group of aliases: the base (C2/D2) one, as in functions.csv."""
    return min(names, key=lambda n: (not re.search(r"[CD]2E", n), n))


def resolve_layout(res: Result, copies: list[Copy], orig: Original,
                   tables: dict[str, dict[int, str]] | None = None) -> dict[int, tuple[str, str]]:
    """One name per original: address -> (name, "pinned" | "layout").

    Code alone can't place identical copies (a `static` function from a header
    in every TU, one-instruction getters of different classes), and it can pin
    several names to one address. The link order can. With -ffunction-sections
    the linker keeps each object's functions together and in the object's
    section order. So:

      - an original with exactly one pinned name of the same code gets it ("pinned");
      - an original with several candidates (same code, not used elsewhere)
        gets the one defined in the TU of its nearest placed neighbours, between
        them in that TU's section order ("layout"). If the neighbours are in two
        TUs, the candidate must come after the previous one in its TU or before
        the next one in its. Repeated until nothing changes.

    A neighbour counts only if its name is defined in exactly one TU, because
    which copy of a COMDAT (template, inline) function the linker kept isn't
    known. Every name is used at most once. Complete and base constructors or
    destructors at one address (C1/C2, D1/D2: aliases) count as one name, and
    the base one is recorded (alias_key).
    """
    # Work on alias keys; members maps a key back to its names.
    members: dict[str, set[str]] = defaultdict(set)
    tus: dict[str, set[str]] = defaultdict(set)
    order: dict[tuple[str, str], int] = {}
    for c in copies:
        k = alias_key(c.name)
        members[k].add(c.name)
        if c.tu:
            tus[k].add(c.tu)
            order[c.tu, k] = min(order.get((c.tu, k), c.order), c.order)
    cands: dict[int, set[str]] = defaultdict(set)
    for n, m in res.matches.items():
        if n.startswith("<"):
            continue
        for a in m:
            cands[a].add(alias_key(n))
    pinned_at: dict[int, set[str]] = defaultdict(set)
    for n, a in res.pinned.items():
        if a in res.matches.get(n, ()):
            pinned_at[a].add(alias_key(n))

    # Names something refers to (a call, a vtable or another pointer table). With
    # --gc-sections only referenced functions are kept, so of two candidates with
    # the same code the referenced one wins.
    referenced = {alias_key(r.target) for c in copies for r in c.relocs}
    referenced |= {alias_key(fn) for table in (tables or {}).values() for fn in table.values()}

    def pick(keys: set[str]) -> str | None:
        if len(keys) == 1:
            return next(iter(keys))
        live = keys & referenced
        return next(iter(live)) if len(live) == 1 else None

    out: dict[int, tuple[str, str]] = {}
    for a, ns in pinned_at.items():
        k = pick(ns)
        if k is not None:
            out[a] = (k, "pinned")
    used = {n for n, _ in out.values()}
    addrs = sorted(orig.words)
    pos = {a: i for i, a in enumerate(addrs)}

    def anchor(i: int, step: int) -> tuple[str, str] | None:
        """(tu, name) of the nearest placed original before (step -1) or after (+1) index i."""
        i += step
        while 0 <= i < len(addrs):
            hit = out.get(addrs[i])
            if hit is not None and len(tus.get(hit[0], ())) == 1:
                return next(iter(tus[hit[0]])), hit[0]
            i += step
        return None

    changed = True
    while changed:
        changed = False
        for a in addrs:
            if a in out or not cands.get(a):
                continue
            free = cands[a] - used
            if not free:
                continue
            prev, nxt = anchor(pos[a], -1), anchor(pos[a], 1)
            ok = set()
            for n in free:
                for tu in tus.get(n, ()):
                    o = order.get((tu, n))
                    after_prev = prev is not None and prev[0] == tu and o > order[prev]
                    before_next = nxt is not None and nxt[0] == tu and o < order[nxt]
                    if prev is not None and nxt is not None and prev[0] == nxt[0]:
                        good = after_prev and before_next
                    else:
                        good = after_prev or before_next
                    if good:
                        ok.add(n)
            n = pick(ok)
            if n is not None:
                out[a] = (n, "layout")
                used.add(n)
                changed = True
    return {a: (prefer_base(members[k]) if members.get(k) else k, how) for a, (k, how) in out.items()}


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
    ap.add_argument("objdir", type=Path, help="one configuration's objects (compiler_sweep.py --obj-dir DIR/<config>), "
                    "or a CMake build dir such as build/sword")
    ap.add_argument("--source-prefix", default="",
                    help="with a build dir: only sources under this repository path, e.g. lib/physx/")
    ap.add_argument("--range", required=True, help="original address range, e.g. 0x7100010a90-0x71003035e0")
    ap.add_argument("--game", default="sword")
    ap.add_argument("--module", default="main")
    ap.add_argument("--out", type=Path, help="write Address,Size,Class,Names,Name,How (CSV)")
    args = ap.parse_args(argv)

    lo, hi = (int(x, 16) - BASE for x in args.range.split("-"))
    copies, vtables = read_objects(args.objdir, args.source_prefix)
    if not copies:
        raise SystemExit(f"no objects in {args.objdir}")
    orig = load_original(args.game, lo, hi, args.module)
    res = attribute(copies, vtables, orig)
    rows = classify(res, orig)
    print(f"{len(copies)} compiled functions, {len(vtables)} vtables, {len(orig.words)} originals; "
          f"{len(res.pinned)} names pinned, {len(res.conflicts)} pinned to two addresses (left out)\n")
    print(summary(rows))
    chosen = resolve_layout(res, copies, orig, vtables)
    how = Counter(h for _, h in chosen.values())
    print(f"\none name per original: {how['pinned']} pinned, {how['layout']} placed by link order, "
          f"{len(orig.words) - len(chosen)} left without a name")
    if args.out:
        with open(args.out, "w", newline="", encoding="utf-8") as fh:
            w = csv.writer(fh, lineterminator="\n")
            w.writerow(["Address", "Size", "Class", "Names", "Name", "How"])
            for a, n, cls, names in rows:
                name, h = chosen.get(a, ("", ""))
                w.writerow([f"{a + BASE:#x}", n, cls, ";".join(names), name, h])
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
