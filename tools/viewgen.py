#!/usr/bin/env python3
"""Views' lookups by name: `Unk_a7bb80_Views::Unk_a7bb80<T>`, an instance per T.

    python tools/viewgen.py census                      # the instances, and what's matched
    python tools/viewgen.py write --names n.csv         # src/unsorted/views, and the names to give
    python tools/viewgen.py write --names n.csv --all   # a trial: every candidate
    python tools/viewgen.py write --names n.csv --only add.txt

An app's frame keeps its views (src/unsorted/Unk_23f4660.h) in a vector and
finds one by name as a T: `Unk_a7bb80<T>(name)`, one template
(src/contents/common/views.inl). It looks for the view whose name hashes the
same, then casts it to T through its +0x50 interface: T's type getter
(`T::Unk_GetType()`, tools/typegen.py) inlined, and the getters under it as
far as clang's inliner went, the next one called out of line. In some
instances T's own getter is called.

The instances are the functions of the shapes (tools/shapes.py) of the named
ones, whatever their status. Each one's types are read from its code the way
typegen.py reads a getter's: the stores of each type's parent into its
static, and the getter called where the chain is cut (or, with no store, T's
getter called). A type is named as typegen.py names it (its static in
data/data_symbols.csv, a getter named in data/functions.csv, the class whose
vf_type returns it, else its type object), so T is that type's class. T is
declared on the view class when the view's type is one of its ancestors (the
type tree's), else on the object. The getter called out of line must be
named as its type's (`_ZN<n><Class>11Unk_GetTypeEv`), or as another class's
getter (that class is declared instead), or not at all (it's named here).

Each instance is a file of its own (`src/unsorted/views/Unk_<address>.cpp`)
that declares the classes it needs rather than including the hand-written
headers, which define the view class's getter inline: in the executable the
instances are spread over the game's TUs, and which getters each inlines
depends on what else its TU calls them from. So each file spells it out: the
getters an instance inlines are defined inline, the one it calls is only
declared. An instance that a hand-written TU instantiates already (one that
includes contents/common/views.h and looks up that T) isn't written here.

A row is kept (written again) when its name is the one written for it and
check.py matched it; `--only` adds addresses, `--all` writes every candidate.
"""
from __future__ import annotations

import argparse
import re
import struct
import sys
from dataclasses import dataclass, field
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BASE, ROOT  # noqa: E402

OUT_DIR = ROOT / "src" / "unsorted" / "views"
TYPE = "const Unk_239a418_Type*"
VIEW = "Unk_23f4660"                      # the view class: its name at +0x5c0
VIEWS_HEADER = "contents/common/views.h"  # what a hand-written TU that instantiates the lookups includes
INSTANCE = re.compile(r"_ZN16Unk_a7bb80_Views10Unk_a7bb80I(\d+)(\w+?)EEPT_RK15Unk_5cfaf0_Name")
# What a hand-written TU looks a view up with: the lookup, or framework.h's
# Unk_StateView (which calls it); a `template <>` declaration of an
# instance keeps the TU from instantiating it.
USE_RE = re.compile(r"\bUnk_(?:a7bb80|StateView)<(\w+)>")
SPECIALIZED_RE = re.compile(r"template\s*<>\s*\w+\*\s*Unk_a7bb80_Views::Unk_a7bb80<(\w+)>")


def instance_name(cls: str) -> str:
    return f"_ZN16Unk_a7bb80_Views10Unk_a7bb80I{len(cls)}{cls}EEPT_RK15Unk_5cfaf0_Name"


def instance_class(name: str | None) -> str | None:
    """The T of an instance's name."""
    m = INSTANCE.fullmatch(name or "")
    return m[2] if m is not None and len(m[2]) == int(m[1]) else None


def _bl_target(a: int, w: int) -> int:
    return a + (((w & 0x3FFFFFF) ^ 0x2000000) - 0x2000000) * 4


def scan_types(img: bytes, f: int, size: int, got: dict[int, int], guards: tuple[int, ...]):
    """The stores of a function (type object -> ("obj", parent) | ("ret", callee)
    | ("zero",)) and its calls but the guards', reading it as typegen.py reads
    a getter but letting other code through: an instruction it doesn't model
    forgets the register it writes (these functions reload the statics from
    the GOT before each use)."""
    regs: dict[int, tuple] = {}
    pages: dict[int, int] = {}
    stores: dict[int, tuple] = {}
    calls: list[int] = []
    for off in range(0, size, 4):
        a = f + off
        w = struct.unpack_from("<I", img, a)[0]
        if (w & 0x9F000000) == 0x90000000:  # adrp
            imm = ((w >> 29) & 3) | (((w >> 5) & 0x7FFFF) << 2)
            if imm & (1 << 20):
                imm -= 1 << 21
            pages[w & 31] = (a & ~0xFFF) + (imm << 12)
            regs.pop(w & 31, None)
        elif (w & 0xFFC00000) == 0xF9400000 and ((w >> 5) & 31) in pages:  # ldr x, [x, #imm]: a GOT slot
            rn, rt = (w >> 5) & 31, w & 31
            t = got.get(pages.pop(rn) + ((w >> 10) & 0xFFF) * 8)
            regs.pop(rt, None)
            pages.pop(rt, None)
            if t is not None:
                regs[rt] = ("obj", t)
        elif (w & 0xFC000000) == 0x94000000:  # bl
            t = _bl_target(a, w)
            if t not in guards:
                calls.append(t)
            regs = {0: ("ret", t)} if t not in guards else {}
            pages = {}
        elif (w & 0xFFC00000) == 0xF9000000 and ((w >> 10) & 0xFFF) == 0:  # str x, [x]
            d = regs.get((w >> 5) & 31)
            s = ("zero",) if (w & 31) == 31 else regs.get(w & 31)
            if d is not None and d[0] == "obj" and s is not None:
                stores[d[1]] = s
        elif (w & 0xFFC00000) == 0xF9000000 or (w & 0x7E000000) in (0x34000000, 0x36000000) \
                or (w & 0xFC000000) == 0x14000000 or (w & 0xFF000010) == 0x54000000 or w == 0xD65F03C0:
            pass  # other stores, branches: write no register
        else:
            regs.pop(w & 31, None)
            pages.pop(w & 31, None)
    return stores, calls


@dataclass
class View:
    """An instance: T's class, the types it initialises from T's up, what the last one's parent is."""
    addr: int
    cls: str
    top: int
    inlined: list[int] = field(default_factory=list)  # T's type first; empty: T's getter is called
    end: tuple = ()                                   # ("cut", getter[, its class]) | ("global", type) | ("zero",)
    base: str = VIEW


def emitted_elsewhere(texts: dict[str, str]) -> set[str]:
    """The Ts whose lookups hand-written TUs instantiate: those that include
    the views' header and look a T up, but haven't declared its instance a
    specialization."""
    out = set()
    for text in texts.values():
        if f'#include "{VIEWS_HEADER}"' not in text:
            continue
        out |= set(USE_RE.findall(text)) - set(SPECIALIZED_RE.findall(text))
    return out


def hand_sources(root: Path = ROOT) -> dict[str, str]:
    """The .cpp files outside the generators' directories (repo-relative path -> text)."""
    import units

    out = {}
    for p in sorted((root / "src").rglob("*.cpp")):
        rel = p.relative_to(root).as_posix()
        if not units.is_generated(rel):
            out[rel] = p.read_text(encoding="utf-8", errors="replace")
    return out


def ancestors(parent: dict[int, tuple], ty: int) -> list[int]:
    """A type's parents, nearest first (typegen.Types.parent's tree)."""
    out = []
    while ty in parent and parent[ty][0] == "obj" and parent[ty][1] not in out:
        ty = parent[ty][1]
        out.append(ty)
    return out


def getter(parent: str) -> list[str]:
    return [f"    static {TYPE} Unk_GetType() {{", f"        static Unk_239a418_Type type({parent});",
            "        return &type;", "    }"]


def source(v: View, expr: dict[int, str], cut_cls: str | None, cut_top: int | None) -> str:
    """The file of one instance."""
    def cls(ty: int) -> str:
        return expr[ty].split("::")[0]

    # each inlined type's parent, as this file calls it
    parent: dict[int, str] = {}
    for i, ty in enumerate(v.inlined):
        if i + 1 < len(v.inlined):
            parent[ty] = expr[v.inlined[i + 1]]
        elif v.end[0] == "zero":
            parent[ty] = "nullptr"
        elif v.end[0] == "global":
            parent[ty] = expr[v.end[1]]
        else:
            parent[ty] = f"{cut_cls}::Unk_GetType()"
    view_getter = ["    static const Unk_239a418_Type* Unk_GetType();"]
    out = ["// Scope: common",
           f"// The lookup of a view by name as a {v.cls} (contents/common/views.inl), with the type",
           "// getters it inlines. Written by tools/viewgen.py: regenerate, don't edit. Placeholder",
           "// classes, named after their vtables or type objects: rename them once they're known.",
           "#include <vector>", "", "#include <types.h>", "",
           '#include "contents/common/cast.h"', '#include "gflib3/Unk_239a418.h"', '#include "unsorted/Unk_d0c0.h"',
           ""]
    if cut_cls is not None and cut_cls not in (VIEW, v.cls):
        out += [f"// The type 0x{cut_top + BASE:x}: its getter is out of line.", f"struct {cut_cls} {{",
                f"    static {TYPE} Unk_GetType();", "};", ""]
    inl = {cls(ty): ty for ty in v.inlined}
    # the inlined types between T and the view's (or the cut), parents first
    for ty in reversed(v.inlined[1:]):
        if cls(ty) != VIEW:
            out += [f"// The type 0x{ty + BASE:x}.", f"struct {cls(ty)} {{", *getter(parent[ty]), "};", ""]
    if VIEW in inl:
        view_getter = getter(parent[inl[VIEW]])
    out += ["// The views (src/unsorted/Unk_23f4660.h): what the lookup reads of them.",
            f"class {VIEW} : public Unk_239a418 {{", "public:", *view_getter, "",
            "    u8 _60[0x5c0 - 0x60];", "    Unk_d0c0_String field_5c0;", "};", "",
            "// An app's frame's views (contents/common/framework.h).",
            "class Unk_a7bb80_Views {", "public:", "    template <class T>",
            "    T* Unk_a7bb80(const Unk_5cfaf0_Name& name);", "", "    u8 _0[0x78];",
            f"    std::vector<{VIEW}*> field_78;", "};", "",
            '#include "contents/common/views.inl"', ""]
    t_getter = getter(parent[v.top]) if v.inlined else [f"    static {TYPE} Unk_GetType();"]
    how = "its getter is out of line" if not v.inlined else "its getter inlined"
    out += [f"// The type 0x{v.top + BASE:x} ({how}).", f"class {v.cls} : public {v.base} {{", "public:",
            *t_getter, "};", "",
            f"// 0x{v.addr + BASE:x}",
            f"template {v.cls}* Unk_a7bb80_Views::Unk_a7bb80<{v.cls}>(const Unk_5cfaf0_Name& name);", ""]
    return "\n".join(out)


class Model:
    """typegen.py's types of Sword, the getters' names and the instances' shapes."""

    def __init__(self):
        import typegen

        self.t = typegen.load()
        taken = set(typegen.header_getters(ROOT / "src")) | typegen.vf_type_classes(ROOT / "src")
        _, self.expr, _ = typegen.plan(self.t, taken, set())
        self.guards = tuple(typegen.Types._imports("sword", ("__cxa_guard_acquire", "__cxa_guard_release")))
        self.view_type = next((ty for ty, e in self.expr.items() if e == f"{VIEW}::Unk_GetType()"), None)

    def candidates(self) -> list[int]:
        """The functions of the shapes of the named instances."""
        from shapes import shape

        img, rows = self.t.m.img, self.t.rows
        named = {shape(img[a:a + r.sword_size]) for a, r in rows.items()
                 if r.sword_size and instance_class(r.name) is not None}
        return sorted(a for a, r in rows.items() if r.sword_size and r.shield is not None and r.scope == "common"
                      and shape(img[a:a + r.sword_size]) in named)


def parse(md: Model, a: int, used: dict[str, int]) -> tuple[View | str, list[tuple[int, str]]]:
    """The instance at a (or why it can't be written), and the names to give the getter it calls."""
    import typegen

    t, expr = md.t, md.expr
    r = t.rows[a]
    stores, calls = scan_types(t.m.img, a, r.sword_size, t.m.got, md.guards)
    names: list[tuple[int, str]] = []
    if stores:
        parents = {s[1] for s in stores.values() if s[0] == "obj"}
        tops = [d for d in stores if d not in parents]
        if len(tops) != 1:
            return "its stores aren't one chain", names
        g = typegen.Getter(a, stores, tops[0], calls)
        ch = typegen.chain_of(t, expr, a, g)
        if ch is None:
            return "its type's chain", names
        v = View(a, "", tops[0], *ch)
    else:
        gs = [c for c in calls if c in t.getters]
        if len(gs) != 1:
            return "no type getter", names
        v = View(a, "", t.getters[gs[0]].top, [], ("cut", gs[0]))
    if v.top not in expr or typegen.is_global(expr[v.top]):
        return "its type isn't named", names
    v.cls = expr[v.top].split("::")[0]
    named = instance_class(r.name)
    if named is not None and v.cls == f"Unk_{v.top:x}":
        v.cls = named  # its type is named after its type object: the instance's name says more
    if v.cls == VIEW:
        return "a lookup of the view class itself", names
    if r.name and named != v.cls:
        return f"named for another class ({named or r.name})", names
    if md.view_type not in ancestors(t.parent, v.top):
        v.base = "Unk_239a418"
    if v.end[0] == "cut":
        cg = v.end[1]
        cr = t.rows.get(cg)
        top = t.getters[cg].top
        if cr is None or cr.shield is None or top not in expr or typegen.is_global(expr[top]):
            return "the getter it calls isn't one of a named type", names
        want = typegen.getter_symbol(expr[top])
        other = typegen.member_getter(cr.name or "")
        if cr.name == want:
            pass
        elif not cr.name and used.get(want, cg) == cg:
            names.append((cg, want))
        elif other is not None and other != v.cls:
            v.end = ("cut", cg, other)
        else:
            return "the getter it calls is named otherwise", names
    return v, names


def cut_of(md: Model, v: View) -> tuple[str | None, int | None]:
    """The class whose getter v calls out of line, and that getter's type."""
    if v.end[0] != "cut":
        return None, None
    top = md.t.getters[v.end[1]].top
    return (v.end[2] if len(v.end) > 2 else md.expr[top].split("::")[0]), top


def plan(md: Model, only: set[int] | None = None, everything: bool = False):
    """(the instances to write with the names to give, the candidates, [(address, why not)])."""
    rows = md.t.rows
    used = {r.name: a for a, r in rows.items() if r.name}
    elsewhere = emitted_elsewhere(hand_sources())
    keep, candidates, skipped, classes = [], md.candidates(), [], set()
    for a in candidates:
        v, names = parse(md, a, used)
        if isinstance(v, str):
            skipped.append((a, v))
            continue
        if v.cls in classes:  # the linker keeps one instance per T: a second isn't this template's
            skipped.append((a, "a second lookup of its class"))
            continue
        classes.add(v.cls)
        if v.cls in elsewhere:
            skipped.append((a, "a hand-written TU instantiates it"))
            continue
        r = rows[a]
        if r.name != instance_name(v.cls):
            names.insert(0, (a, instance_name(v.cls)))
        if everything or (only is not None and a in only) or (r.status == "O" and r.name == instance_name(v.cls)):
            keep.append((v, names))
    return keep, candidates, skipped


def cmd_census(md: Model, args) -> None:
    keep, candidates, skipped = plan(md, everything=True)
    rows = md.t.rows
    done = [a for a in candidates if rows[a].status == "O"]
    print(f"{len(candidates)} candidates ({sum(rows[a].sword_size for a in candidates)} bytes), "
          f"{len(done)} matched ({sum(rows[a].sword_size for a in done)} bytes), {len(keep)} writable")
    why: dict[str, int] = {}
    for _, w in skipped:
        why[w] = why.get(w, 0) + 1
    for w, n in sorted(why.items(), key=lambda kv: -kv[1]):
        print(f"  not written: {n:4d} {w}")


def cmd_write(md: Model, args) -> None:
    from common import clang_format

    only = {int(x, 16) - BASE for x in args.only.read_text(encoding="utf-8").split()} if args.only else None
    keep, _, _ = plan(md, only, args.all)
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    for old in OUT_DIR.glob("Unk_*.cpp"):
        old.unlink()
    written = []
    for v, _ in keep:
        path = OUT_DIR / f"Unk_{v.addr:x}.cpp"
        path.write_text(source(v, md.expr, *cut_of(md, v)), encoding="utf-8", newline="\n")
        written.append(path)
    if written and not clang_format(written):
        print("clang-format isn't on PATH: format the written files before committing them", file=sys.stderr)
    rows = md.t.rows
    with open(args.names, "w", encoding="utf-8", newline="\n") as fh:
        fh.write("Name,Sword,Shield\n")
        for f, n in sorted({f: n for _, ns in keep for f, n in ns}.items()):
            fh.write(f"{n},{rows[f].sword_str},{rows[f].shield_str}\n")
    print(f"{len(keep)} lookups; the names to give in {args.names}", file=sys.stderr)


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("census")
    w = sub.add_parser("write")
    w.add_argument("--names", type=Path, required=True)
    g = w.add_mutually_exclusive_group()
    g.add_argument("--only", type=Path, help="addresses to write besides the kept ones")
    g.add_argument("--all", action="store_true", help="write every candidate (a trial)")
    args = ap.parse_args(argv)
    md = Model()
    {"census": cmd_census, "write": cmd_write}[args.cmd](md, args)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
