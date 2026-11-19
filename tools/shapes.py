#!/usr/bin/env python3
"""Group functions by shape, and find a compiled template's instances among them.

    python tools/shapes.py groups --area game -n 40       # the largest groups of undecompiled functions
    python tools/shapes.py members 0x7101347350           # the group of one function
    python tools/shapes.py sweep build/sweep.o            # which groups an object's functions have the shape of

A function's *shape* is its instruction words with the fields that differ
between instances of one template masked: the immediates of B and BL (their
targets) and the page and low 12 bits of an ADRP and of the ADD or LDR/STR
(unsigned offset) that uses its register (the data it reaches). Two functions
of one shape are the same code calling other functions and reaching other
data: one template instantiated twice, for example, or two copies of an inline
function. A *group* is the functions of one shape, from Sword's executable
and data/functions.csv (only those with the statuses --status lists,
undecompiled by default).

`sweep` hashes the functions of an object file the same way (their B/BL and
ADRP/lo12 fields are relocations, zero before linking), so compiling a
template for many types (every element size of a container, ...) and sweeping
the object names the groups that are its instances. A shape match isn't a
match: what the masked fields refer to still has to be right, which check.py
tells once the instances are named.
"""
from __future__ import annotations

import argparse
import hashlib
import struct
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from common import BASE  # noqa: E402


def mask_words(words: list[int]) -> list[int]:
    """The words of a function with its B/BL targets and ADRP pairs' fields masked."""
    pages: set[int] = set()  # registers an ADRP set
    out = []
    for w in words:
        if (w & 0x7C000000) == 0x14000000:          # B, BL
            w &= 0xFC000000
        elif (w & 0x9F000000) == 0x90000000:        # ADRP
            pages.add(w & 31)
            w &= 0x9F00001F
        elif (w & 0x7F800000) == 0x11000000 and ((w >> 5) & 31) in pages:  # ADD (immediate) on a page
            w &= 0xFFC003FF
        elif (w & 0x3B000000) == 0x39000000 and ((w >> 5) & 31) in pages:  # LDR/STR (unsigned offset) on a page
            w &= 0xFFC003FF
        out.append(w)
    return out


def shape(code: bytes) -> str:
    """A function's shape: a hash of its masked words."""
    words = list(struct.unpack_from(f"<{len(code) // 4}I", code))
    return hashlib.sha1(struct.pack(f"<{len(words)}I", *mask_words(words))).hexdigest()[:12]


def executable_groups(statuses: str = "U", area: str | None = None) -> dict[str, list]:
    """shape -> the functions.csv rows (Sword) of that shape, with the given statuses."""
    from common import AreaMap, in_area, load_module, read_areas_csv, read_functions_csv

    img = load_module("sword")["image"]
    amap = AreaMap(read_areas_csv(), "sword")
    groups: dict[str, list] = defaultdict(list)
    for r in read_functions_csv():
        if r.status not in statuses or r.sword is None or not r.sword_size:
            continue
        if area is not None and not in_area(amap.area_of(r.sword), area):
            continue
        groups[shape(img[r.sword:r.sword + r.sword_size])].append(r)
    return groups


def object_shapes(data: bytes) -> dict[str, str]:
    """symbol -> shape, for the defined functions of an ELF object."""
    import elfobj

    obj = elfobj.parse(data)
    out = {}
    for sym in obj.symbols:
        if sym.type != "STT_FUNC" or not isinstance(sym.shndx, int) or sym.size == 0:
            continue
        code = obj.get_section(sym.shndx).contents[sym.value:sym.value + sym.size]
        if len(code) == sym.size:
            out[sym.name] = shape(code)
    return out


def ranked(groups: dict[str, list], min_count: int = 2) -> list[tuple[str, list]]:
    """The groups of at least min_count functions, largest (in bytes) first."""
    return sorted(((s, g) for s, g in groups.items() if len(g) >= min_count),
                  key=lambda sg: (-sum(r.sword_size for r in sg[1]), sg[0]))


def cmd_groups(args) -> int:
    for s, g in ranked(executable_groups(args.status, args.area), args.min_count)[:args.n]:
        print(f"{s}  {len(g):5} x {g[0].sword_size:5}  {sum(r.sword_size for r in g):8} bytes"
              f"  first 0x{g[0].sword + BASE:x}")
    return 0


def cmd_members(args) -> int:
    from common import load_module, read_functions_csv

    addr = int(args.addr, 16) - BASE
    img = load_module("sword")["image"]
    rows = read_functions_csv()
    row = next((r for r in rows if r.sword == addr), None)
    if row is None:
        raise SystemExit(f"no function at {args.addr}")
    want = shape(img[row.sword:row.sword + row.sword_size])
    for r in rows:
        if r.sword is not None and r.sword_size == row.sword_size and \
                shape(img[r.sword:r.sword + r.sword_size]) == want:
            print(f"0x{r.sword + BASE:x}  {r.status}  {r.name}")
    return 0


def cmd_sweep(args) -> int:
    groups = executable_groups(args.status, args.area)
    found = 0
    for name, s in sorted(object_shapes(Path(args.obj).read_bytes()).items()):
        if s in groups:
            g = groups[s]
            found += 1
            print(f"{s}  {len(g):4} x {g[0].sword_size:5}  {name}")
            if args.members:
                print("      " + " ".join(f"0x{r.sword + BASE:x}" for r in g))
    print(f"{found} functions of the object have the shape of a group", file=sys.stderr)
    return 0


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("groups", help="the largest groups of one shape")
    p.add_argument("--area", help="an area of data/areas.csv, or a group of them (game)")
    p.add_argument("--status", default="U", help="the statuses to group (default U)")
    p.add_argument("--min-count", type=int, default=2)
    p.add_argument("-n", type=int, default=40)
    p = sub.add_parser("members", help="the functions of one function's shape")
    p.add_argument("addr")
    p = sub.add_parser("sweep", help="the groups an object's functions have the shape of")
    p.add_argument("obj")
    p.add_argument("--area")
    p.add_argument("--status", default="U")
    p.add_argument("--members", action="store_true", help="list each group's functions")
    args = ap.parse_args(argv)
    return {"groups": cmd_groups, "members": cmd_members, "sweep": cmd_sweep}[args.cmd](args)


if __name__ == "__main__":
    raise SystemExit(main())
