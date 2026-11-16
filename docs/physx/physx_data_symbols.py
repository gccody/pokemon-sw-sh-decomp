"""Original addresses of lib/physx's data objects (vtables, tables, globals),
from the adrp/lo12 and GOT references of functions attributed in both games.

    python docs/physx/physx_data_symbols.py <out.csv>      (from the repo root,
                                                            after building both games)

A data object is placed where every attributed reference to it agrees. The
output is Sword,Shield,Size,Name rows for data/data_symbols.csv.
"""
import csv
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, "tools")
import sweep_attribute as sa  # noqa: E402
import symbols  # noqa: E402
from common import BASE  # noqa: E402
from elftools.elf.elffile import ELFFile  # noqa: E402

LO, HI = 0x10A90, 0x3035E0  # offsets from the module base
OUT = Path(sys.argv[1])


def objects_info(build: Path):
    """Data symbols: qualified name -> size; section key -> [(value, size, name)]."""
    sizes, by_sec = {}, defaultdict(list)
    for obj, stem in sa.build_objects(build, "lib/physx/"):
        src = Path(stem + ".cpp")
        with open(obj, "rb") as fh:
            elf = ELFFile(fh)
            for s in elf.get_section_by_name(".symtab").iter_symbols():
                if s["st_info"]["type"] != "STT_OBJECT" or not isinstance(s["st_shndx"], int):
                    continue
                q = symbols.qualify(s.name, src, s["st_info"]["bind"] == "STB_LOCAL")
                sizes[q] = s["st_size"]
                by_sec[f"<{elf.get_section(s['st_shndx']).name}@{stem}>"].append((s["st_value"], s["st_size"], q))
    return sizes, by_sec


def places(game: str):
    build = Path("build") / game
    copies, tables = sa.read_objects(build, "lib/physx/")
    orig = sa.load_original(game, LO, HI)
    res = sa.attribute(copies, tables, orig)
    sizes, by_sec = objects_info(build)
    by_name = defaultdict(list)
    for c in copies:
        by_name[c.name].append(c)
    found: dict[str, set[int]] = defaultdict(set)
    for name, a in res.pinned.items():
        for c in by_name.get(name, ()):
            if a not in res.matches.get(name, ()):
                continue
            ws = orig.words[a]
            pages, los = {}, {}
            for r in c.relocs:
                if r.type == sa.R_ADR_PREL_PG_HI21:
                    pages[r.target, r.addend] = sa.adrp_page(ws, a, r.index)
                elif r.type in sa.R_LO12:
                    los[r.target, r.addend] = sa.lo12(ws[r.index])
                elif r.type == sa.R_GOT_PAGE:
                    pages[r.target, "got"] = sa.adrp_page(ws, a, r.index)
                elif r.type == sa.R_GOT_LO12:
                    los[r.target, "got"] = ((ws[r.index] >> 10) & 0xFFF) * 8
            for (sym, addend), p in pages.items():
                if (sym, addend) not in los:
                    continue
                d = p + los[sym, addend]
                if addend == "got":
                    v = orig.slots.get(d)
                    if not isinstance(v, int):
                        continue
                    start, addend = v, 0
                else:
                    start = d - addend
                if sym.startswith("<"):
                    # a local object through its section symbol
                    hit = [(v, n) for v, s, n in by_sec.get(sym, ()) if v <= addend < v + max(s, 1)]
                    if len(hit) != 1:
                        continue
                    v, sym = hit[0]
                    start = d - addend + v
                if sym in sizes:
                    found[sym].add(start)
    return {n: next(iter(s)) for n, s in found.items() if len(s) == 1}, sizes


sw, sizes = places("sword")
sh, _ = places("shield")
names = sorted(set(sw) & set(sh), key=lambda n: sw[n])
with open(OUT, "w", newline="") as fh:
    w = csv.writer(fh, lineterminator="\n")
    w.writerow(["Sword", "Shield", "Size", "Name"])
    for n in names:
        w.writerow([f"{sw[n] + BASE:#x}", f"{sh[n] + BASE:#x}", sizes[n], n])
print(len(sw), "sword,", len(sh), "shield,", len(names), "in both")
