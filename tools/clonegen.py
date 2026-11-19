#!/usr/bin/env python3
"""Copies of type-erased callables: slots 2 and 3 of their vtables.

    python tools/clonegen.py census
    python tools/clonegen.py write --names n.csv [--only keep.txt]   # src/unsorted/clone

libc++'s std::function keeps its callable in a `__func` object whose vtable
is D2, D0, `__clone()`, `__clone(p)`, `destroy()`, `destroy_deallocate()`,
`operator()`. vtables.py writes the classes' simple slots as members of
placeholder classes named after their vtables (`Unk_<_ZTV address>`). The
two copies it doesn't write are:

    slot 2: allocate the object's size (operator new), copy-construct into it
            (the vptr: the class's own vtable, then its fields), return it;
    slot 3: copy-construct into the given storage.

Both are what an implicitly copied class does, so each class gets
`return new Unk_C(*this);` and `new (p) Unk_C(*this);`, with as many u64
fields as the copy moves. The vptr store references `_ZTV<n>Unk_C`, which
check.py checks against the address the name gives. The classes are only
declared here (their destructors aren't defined, so no vtable is emitted).
vtables.py write skips the functions this writes (their address comments).
"""
from __future__ import annotations

import argparse
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BASE, ROOT  # noqa: E402

OUT_DIR = ROOT / "src" / "unsorted" / "clone"
NEW = "_Znwm"


def _b_target(pc: int, w: int) -> int:
    return pc + (((w & 0x3FFFFFF) ^ 0x2000000) - 0x2000000) * 4


def mov_w0(w: int) -> int | None:
    """The value of `mov w0, #imm`: movz, or orr from wzr with a bitmask immediate."""
    if (w & 0xFFE0001F) == 0x52800000:
        return (w >> 5) & 0xFFFF
    if (w & 0xFFC003FF) != 0x320003E0:
        return None
    immr, imms = (w >> 16) & 0x3F, (w >> 10) & 0x3F
    for size in (32, 16, 8, 4, 2):  # element size: the highest clear bit of imms selects it
        if size == 32 or (imms & (0x3F & ~(size * 2 - 1) | size)) == (0x3F & ~(size * 2 - 1)):
            break
    ones = (imms & (size - 1)) + 1
    if ones >= size:
        return None
    elem = ((1 << ones) - 1)
    elem = ((elem >> (immr % size)) | (elem << (size - immr % size))) & ((1 << size) - 1)
    out = 0
    for i in range(0, 32, size):
        out |= elem << i
    return out


def clone_shape(img: bytes, f: int, size: int, new: int) -> tuple[int, int] | None:
    """(object size, vptr page/offset words' address) of slot 2's code:
    `str x19 ; frame ; mov x19, x0 ; mov w0, #size ; bl new ; adrp/add vptr ;
    str ; copy fields ; ret`, or None."""
    w = struct.unpack_from(f"<{size // 4}I", img, f)
    if len(w) < 8 or w[3] != 0xAA0003F3:            # mov x19, x0
        return None
    size = mov_w0(w[4])
    if size is None:
        return None
    if (w[5] & 0xFC000000) != 0x94000000 or _b_target(f + 20, w[5]) != new:
        return None
    return size, f + 24


def place_shape(img: bytes, f: int, size: int) -> int | None:
    """Slot 3: `adrp x8 ; add x8 ; str x8, [x1] ; (copy fields) ; ret`: the vptr's adrp address."""
    w = struct.unpack_from(f"<{size // 4}I", img, f)
    if (w[0] & 0x9F00001F) != 0x90000008 or (w[1] & 0xFFC003FF) != 0x91000108 or w[2] != 0xF9000028:
        return None
    return f if w[-1] == 0xD65F03C0 else None


def adrp_add(img: bytes, at: int) -> int:
    """The address an adrp+add pair at `at` makes."""
    w0, w1 = struct.unpack_from("<II", img, at)
    imm = ((w0 >> 29) & 3) | (((w0 >> 5) & 0x7FFFF) << 2)
    if imm & (1 << 20):
        imm -= 1 << 21
    return (at & ~0xFFF) + (imm << 12) + ((w1 >> 10) & 0xFFF)


def candidates(m, rows: dict) -> list[tuple[object, int, int, int]]:
    """(vtable, slot 2, slot 3, object size) of every class whose slots 2 and
    3 copy it, both storing the class's own vtable (address point)."""
    new = next((a for a, r in rows.items() if r.name == NEW), None)
    out = []
    for v in m.vtables:
        if v.offset_to_top != 0 or len(v.slots) < 4:
            continue
        f2, f3 = v.slots[2], v.slots[3]
        if not isinstance(f2, int) or not isinstance(f3, int) or new is None:
            continue
        s2 = clone_shape(m.img, f2, m.sizes.get(f2, 0), new)
        p3 = place_shape(m.img, f3, m.sizes.get(f3, 0))
        if s2 is None or p3 is None or s2[0] < 8 or s2[0] % 8:
            continue
        if adrp_add(m.img, s2[1]) != v.addr or adrp_add(m.img, p3) != v.addr:
            continue
        out.append((v, f2, f3, s2[0]))
    return out


def render(classes: list[tuple[str, int, int, int, int]]) -> str:
    """One file: each class (name, vtable, slot 2, slot 3, size) and its two copies."""
    out = ["// Scope: common",
           "// Copies of type-erased callables, slots 2 and 3 of their vtables",
           "// (tools/clonegen.py, generated: rewrite, don't edit). Placeholder classes",
           "// named after their vtables, as tools/vtables.py names them.",
           "#include <new>", "", "#include <types.h>", ""]
    for name, vt_addr, f2, f3, size in classes:
        fields = [f"    u64 field_{8 + 8 * i:x};" for i in range((size - 8) // 8)]
        out += [f"// vtable 0x{vt_addr + BASE:x}: what it holds is copied whole. Its vtable is",
                "// reached directly (adrp/add), not through the GOT: the callable's class is",
                "// local to its TU (a lambda's), so the vtable isn't preemptible.",
                f"class __attribute__((visibility(\"hidden\"))) {name} {{", "public:", f"    virtual ~{name}();",
                f"    virtual {name}* vf2();", f"    virtual void vf3({name}* p);", "",
                *fields, "};", f"static_assert(sizeof({name}) == 0x{size:x}, \"{name}\");", "",
                f"// 0x{f2 + BASE:x}", f"{name}* {name}::vf2() {{", f"    return new {name}(*this);", "}", "",
                f"// 0x{f3 + BASE:x}", f"void {name}::vf3({name}* p) {{", f"    new (p) {name}(*this);", "}", ""]
    return "\n".join(out).rstrip("\n") + "\n"


def selection(m, rows: dict, only: set[int] | None):
    import vtables as vt

    def free(f: int, name: str) -> bool:
        r = rows.get(f)
        return r is not None and r.scope == "common" and r.shield is not None \
            and (only is None or f in only or r.status == "O") and (not r.name and r.status == "U" or r.name == name)

    keep = []
    for v, f2, f3, size in candidates(m, rows):
        name = vt.class_name(v)
        n2, n3 = vt.mangle(name, "vf2"), vt.mangle(name, "vf3", "PS_")
        if not (free(f2, n2) and free(f3, n3)):
            continue
        keep.append(((name, v.addr, f2, f3, size), [(f2, n2), (f3, n3)]))
    return keep


def load():
    import vtables as vt
    from common import read_functions_csv

    m = vt.load("sword")
    return m, {f.sword: f for f in read_functions_csv() if f.sword is not None}


def main(argv: list[str] | None = None) -> int:
    import bisect

    import vtables as vt
    from common import clang_format

    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("census")
    w = sub.add_parser("write")
    w.add_argument("--names", type=Path, required=True)
    w.add_argument("--only", type=Path)
    args = ap.parse_args(argv)
    m, rows = load()
    only = None
    if getattr(args, "only", None):
        only = {int(x, 16) - BASE for x in args.only.read_text(encoding="utf-8").split()}
    keep = selection(m, rows, only)
    if args.cmd == "census":
        n = sum(m.sizes[f] for _, names in keep for f, _ in names if rows[f].status != "O")
        print(f"{len(candidates(m, rows))} classes copy themselves; {len(keep)} writable, {n} bytes not matched yet")
        return 0
    starts = vt.segment_starts(m)
    files: dict[int, list] = {}
    for c, _ in keep:
        files.setdefault(starts[bisect.bisect_right(starts, c[2]) - 1], []).append(c)
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    for old in OUT_DIR.glob("Unk_*.cpp"):
        old.unlink()
    for cs in files.values():
        cs.sort(key=lambda c: c[2])
        (OUT_DIR / f"Unk_{cs[0][2]:x}.cpp").write_text(render(cs), encoding="utf-8", newline="\n")
    if not clang_format(sorted(OUT_DIR.glob("Unk_*.cpp"))):
        print("clang-format isn't on PATH: format the written files before committing them", file=sys.stderr)
    with open(args.names, "w", encoding="utf-8", newline="\n") as fh:
        fh.write("Name,Sword,Shield\n")
        for _, names in sorted(keep, key=lambda k: k[0][2]):
            for f, n in names:
                fh.write(f"{n},{rows[f].sword_str},{rows[f].shield_str}\n")
    print(f"{len(keep)} classes in {len(files)} files", file=sys.stderr)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
