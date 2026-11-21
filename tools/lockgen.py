#!/usr/bin/env python3
"""The locks of weak handles: `Unk_Lock<T>` (src/gflib3/Unk_Lock.h), an instance per type.

    python tools/lockgen.py census                      # the instances, and what's matched
    python tools/lockgen.py write --names n.csv         # src/unsorted/locks, and the names to give
    python tools/lockgen.py write --names n.csv --all   # a trial: every candidate
    python tools/lockgen.py write --names n.csv --only add.txt

A weak reference to one of gflib3's objects (src/gflib3/Unk_239a418.h) is the
object's handle. Locking it as a type T gives a reference to the object if
the handle still counts references and the object's type is T or derives
from it: `Unk_Lock<T>(handle)`, one template (src/gflib3/Unk_Lock.h). Its
instances are the same code but for T's type descriptor, the static of T's
getter (`T::Unk_GetType()`, tools/typegen.py), which the template inlines
with the getters under it, as far as clang's inliner went in each.

A candidate is a function that starts by reading the count of the handle it
is given (`ldr wN, [x0, #0x54] ; cbz wN`) and has one exclusive load and
store (the weak compare and exchange). Its type getters are read from the
guards of their statics, in the order the function's GOT loads name them: T's
first, then each parent's whose getter is inlined. The chain ends

- with the object's own type (`Unk_239a418_GetType()`, inline over the
  root's): T, or its last inlined parent, is a class on the object itself;
- or with a call of the next parent's getter, out of line: its class is
  declared with the getter's name in data/functions.csv
  (`_ZN<n><Class>11Unk_GetTypeEv`).

A type is named after its static in data/data_symbols.csv
(`_ZZN<n><T>11Unk_GetTypeEvE4type`, the guard's `_ZGVZN...`), else
`Unk_<the static's address>` (tools/check.py --record-data then records the
static and its guard). Each instance is a file of its own
(`src/unsorted/locks/Unk_<address>.cpp`): in the executable they're spread
over the game's TUs, and a getter with several callers in one TU isn't
inlined the same way.

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

OUT_DIR = ROOT / "src" / "unsorted" / "locks"
OBJECT_GUARD = "_ZGVZ19Unk_239a418_GetTypevE4type"   # the guard of the object's own descriptor
ROOT_GUARD = "_ZGVZ20Unk_239a418_RootTypevE4type"
TYPE_GUARD = re.compile(r"^_ZGVZN(\d+)(\w+)11Unk_GetTypeEvE4type$")
GETTER = re.compile(r"^_ZN(\d+)(\w+)11Unk_GetTypeEv$")
GUARD_CALLS = ("__cxa_guard_acquire", "__cxa_guard_release")


@dataclass
class Lock:
    addr: int
    chain: list = field(default_factory=list)   # T, then each parent whose getter is inlined
    called: str | None = None                   # the class whose getter is called, None: the object's type
    offset: int = 0x50                          # where T has the interface the handle keeps

    @property
    def cls(self) -> str:
        return self.chain[0]


def is_lock(m, a: int) -> bool:
    """Whether the function reads the count of the handle in x0 first and has one exclusive load and store."""
    size = m.rows[a].sword_size
    if not size or not 300 <= size <= 700:
        return False
    ws = struct.unpack_from(f"<{size // 4}I", m.img, a)
    first = next((i for i, w in enumerate(ws[:8]) if (w & 0xFFFFFFE0) == 0xB9405400), None)   # ldr wN, [x0, #0x54]
    if first is None or (ws[first + 1] & 0xFF00001F) != (0x34000000 | (ws[first] & 31)):       # cbz wN
        return False
    return (sum(1 for w in ws if (w & 0xFFFFFC00) == 0x885F7C00) == 1               # ldxr
            and sum(1 for w in ws if (w & 0xFFE0FC00) == 0x88007C00) == 1)          # stxr


def guard_class(name: str | None, guard: int) -> str | None:
    """The class a guard's name gives; a placeholder after its static (8 bytes before it) for an unnamed one."""
    if name is None:
        return f"Unk_{guard - 8:x}"
    g = TYPE_GUARD.match(name)
    if g and int(g.group(1)) == len(g.group(2)):
        return g.group(2)
    return None


def parse(m, a: int, guards: tuple[int, ...] = ()) -> Lock | str | None:
    """The lock at `a`, why it can't be written, or None when it isn't one. `guards` are the
    addresses the guard functions are called at (the PLT's): every other call is a getter's."""
    if not is_lock(m, a):
        return None
    size = m.rows[a].sword_size
    got = list(dict.fromkeys(m.got_target(a, size)))
    names = [m.data_names.get(g) for g in got]
    chain, ends = [], False
    for k, (g, n) in enumerate(zip(got, names)):
        if n == OBJECT_GUARD:
            ends = True
        elif n == ROOT_GUARD or (n is not None and not n.startswith("_ZGV")):
            continue
        elif n is None and (k > 0 or (g - 8) not in got):
            # unnamed: T's guard is the first load, 8 bytes after its static; a parent's can't be told
            # from its static
            if (g - 8) in got or (g + 8) in got:
                continue
            return "a parent type that isn't named"
        elif ends:
            return "a type under the object's"
        else:
            cls = guard_class(n, g)
            if cls is None:
                return "a guard that isn't a type getter's"
            chain.append(cls)
    unnamed = sum(1 for n in names if n is None)
    if unnamed > (2 if chain and chain[0].startswith("Unk_") and names[0] is None else 0):
        return "a parent type that isn't named"
    calls = [c for c in _bl_targets(m, a, size) if c not in guards]
    if not chain:
        return "no type"
    offset = interface_offset(m, a, size)
    if offset is None:
        return "no cast from the interface"
    if ends:
        return Lock(a, chain, None, offset) if not calls else "the object's type and a call"
    if len(calls) != 1 or calls[0] not in m.rows:
        return "its last getter isn't called once"
    g = GETTER.match(m.rows[calls[0]].name or "")
    if not g or int(g.group(1)) != len(g.group(2)):
        return "the getter it calls isn't named as one"
    return Lock(a, chain, g.group(2), offset)


def interface_offset(m, a: int, size: int) -> int | None:
    """Where T has the interface the handle keeps (+0x60): the `sub xB, xA, #N` after `ldr xA, [x0, #0x60]`."""
    ws = struct.unpack_from(f"<{size // 4}I", m.img, a)
    for i, w in enumerate(ws[:-1]):
        if (w & 0xFFFFFFE0) == 0xF9403000:                      # ldr xA, [x0, #0x60]
            nxt = ws[i + 1]
            if (nxt & 0xFFC00000) == 0xD1000000 and ((nxt >> 5) & 31) == (w & 31):   # sub xB, xA, #N
                return (nxt >> 10) & 0xFFF
    return None


def _bl_targets(m, a: int, size: int) -> list[int]:
    out = []
    for o in range(a, a + size, 4):
        w = struct.unpack_from("<I", m.img, o)[0]
        if (w & 0xFC000000) == 0x94000000:
            d = w & 0x3FFFFFF
            out.append(o + ((d - (1 << 26)) if d & (1 << 25) else d) * 4)
    return out


def lock_name(cls: str) -> str:
    return f"_Z8Unk_LockI{len(cls)}{cls}E15Unk_239a418_RefIT_EP18Unk_239a418_Handle"


GETTER_BODY = """    static const Unk_239a418_Type* Unk_GetType() {{
        static Unk_239a418_Type type({parent});
        return &type;
    }}
"""


def source(lock: Lock) -> str:
    out = ["// Scope: common",
           f"// The lock of a weak handle as {lock.cls} (src/gflib3/Unk_Lock.h), with the type getters it",
           "// inlines. Written by tools/lockgen.py: regenerate, don't edit.",
           '#include "gflib3/Unk_Lock.h"', ""]
    parent = "Unk_239a418_GetType()"
    if lock.called is not None:
        out += ["// Its getter is out of line.", f"struct {lock.called} {{",
                "    static const Unk_239a418_Type* Unk_GetType();", "};", ""]
        parent = f"{lock.called}::Unk_GetType()"
    for cls in reversed(lock.chain[1:]):
        out += [f"struct {cls} {{", GETTER_BODY.format(parent=parent).rstrip("\n"), "};", ""]
        parent = f"{cls}::Unk_GetType()"
    if lock.offset == 0x50:
        out += [f"class {lock.cls} : public Unk_239a418 {{"]
    else:
        # not on the object: what comes before the interface is only its size, and where it
        # counts its references (Unk_239a458, for the reference's destructor) isn't known
        pad = [f"    u8 _8[{lock.offset - 8:#x}];"] if lock.offset > 8 else []
        out += [f"struct {lock.cls}_Base {{", "    virtual void vf0();"] + pad + ["};", "",
                f"class {lock.cls} : public {lock.cls}_Base, public Unk_239a498, public Unk_239a458 {{"]
    out += ["public:", GETTER_BODY.format(parent=parent).rstrip("\n"), "};",
            "", f"// 0x{lock.addr + BASE:x}",
            f"template Unk_239a418_Ref<{lock.cls}> Unk_Lock<{lock.cls}>(Unk_239a418_Handle*);", ""]
    return "\n".join(out)


def plan(m, only: set[int] | None = None, everything: bool = False, guards: tuple[int, ...] = ()):
    """(the locks to write, the candidates' addresses, [(address, why not)])."""
    locks, candidates, skipped, classes = [], [], [], set()
    for a in sorted(m.rows):
        lock = parse(m, a, guards)
        if lock is None:
            continue
        candidates.append(a)
        if isinstance(lock, str):
            skipped.append((a, lock))
            continue
        if lock.cls in classes:     # the linker keeps one instance of a type: a second isn't this template's
            skipped.append((a, "a second lock of its type"))
            continue
        classes.add(lock.cls)
        r = m.rows[a]
        if everything or (only is not None and a in only) or (r.status == "O" and r.name == lock_name(lock.cls)):
            locks.append(lock)
    return locks, candidates, skipped


def guard_calls(m) -> tuple[int, ...]:
    """Where the guard functions are called: the PLT stubs of the SDK's imports."""
    from common import load_module, nso_path
    from nx.module import DynInfo
    from nx.nso import Nso

    mod = load_module("sword")
    dyn = DynInfo(Nso(nso_path("sword").read_bytes()), mod["image"], mod["text_end"])
    by_name = {n: a for a, n in dyn.plt.items()}
    return tuple(by_name[n] for n in GUARD_CALLS if n in by_name)


def cmd_census(m, args) -> None:
    locks, candidates, skipped = plan(m, everything=True, guards=guard_calls(m))
    done = [a for a in candidates if m.rows[a].status == "O"]
    print(f"{len(candidates)} candidates ({sum(m.rows[a].sword_size for a in candidates)} bytes), "
          f"{len(done)} matched ({sum(m.rows[a].sword_size for a in done)} bytes), {len(locks)} writable")
    why: dict[str, int] = {}
    for _, w in skipped:
        why[w] = why.get(w, 0) + 1
    for w, n in sorted(why.items(), key=lambda kv: -kv[1]):
        print(f"  not written: {n:4d} {w}")


def cmd_write(m, args) -> None:
    from common import clang_format

    only = {int(x, 16) - BASE for x in args.only.read_text(encoding="utf-8").split()} if args.only else None
    locks, _, _ = plan(m, only, args.all, guard_calls(m))
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    for old in OUT_DIR.glob("Unk_*.cpp"):
        old.unlink()
    written = []
    for lock in locks:
        path = OUT_DIR / f"Unk_{lock.addr:x}.cpp"
        path.write_text(source(lock), encoding="utf-8", newline="\n")
        written.append(path)
    if written and not clang_format(written):
        print("clang-format isn't on PATH: format the written files before committing them", file=sys.stderr)
    with open(args.names, "w", encoding="utf-8", newline="\n") as fh:
        fh.write("Name,Sword,Shield\n")
        for lock in locks:
            r = m.rows[lock.addr]
            fh.write(f"{lock_name(lock.cls)},{r.sword_str},{r.shield_str}\n")
    print(f"{len(locks)} locks; their names in {args.names}", file=sys.stderr)


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
    import familygen
    m = familygen.load()
    {"census": cmd_census, "write": cmd_write}[args.cmd](m, args)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
