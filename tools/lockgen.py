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
with the getters under it.

The candidates are the functions of a seed's shape (their words with branch
targets and adrp/lo12 fields masked, as tools/shapes.py does). A seed says
how T's getter is made:

- `object`: T is a class on the object itself, so its getter holds the
  object's type (`Unk_239a418_GetType()`, itself inline over the root's):
  three guarded statics in the function.

T is named after its descriptor's static in data/data_symbols.csv
(`_ZZN<n><T>11Unk_GetTypeEvE4type`), else `Unk_<the static's address>`
(tools/check.py --record-data then records the static and its guard). Each
instance is a file of its own (`src/unsorted/locks/Unk_<address>.cpp`): in the
executable they're spread over the game's TUs, and a getter with several
callers in one TU isn't inlined the same way.

A row is kept (written again) when its name is the one written for it and
check.py matched it; `--only` adds addresses, `--all` writes every candidate.
"""
from __future__ import annotations

import argparse
import re
import sys
from dataclasses import dataclass
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BASE, ROOT  # noqa: E402

OUT_DIR = ROOT / "src" / "unsorted" / "locks"
OBJECT_TYPE = "_ZZ19Unk_239a418_GetTypevE4type"    # the object's own descriptor
TYPE_STATIC = re.compile(r"^_ZZN(\d+)(\w+)11Unk_GetTypeEvE4type$")
# the shapes, by their first function: how T's getter is made
SEEDS = {0xE840: "object"}


@dataclass
class Lock:
    addr: int
    cls: str        # T
    kind: str       # the seed's


def class_of(static: int, names: dict[int, str]) -> str:
    """T, from its descriptor's static: its name in data_symbols.csv, else a placeholder."""
    m = TYPE_STATIC.match(names.get(static, ""))
    if m and int(m.group(1)) == len(m.group(2)):
        return m.group(2)
    return f"Unk_{static:x}"


def lock_name(cls: str) -> str:
    return f"_Z8Unk_LockI{len(cls)}{cls}E15Unk_239a418_RefIT_EP18Unk_239a418_Handle"


def parse(m, a: int) -> Lock | str | None:
    """The lock at `a`, why it can't be written, or None when it isn't one."""
    r = m.rows[a]
    kind = next((k for s, k in SEEDS.items() if s in m.rows and m.rows[s].sword_size == r.sword_size
                 and m.shape(s) == m.shape(a)), None)
    if kind is None:
        return None
    got = m.got_target(a, r.sword_size)
    # the guard of T's static first, then what T's getter holds, then T's static
    if len(got) < 3:
        return "other globals"
    if kind == "object" and m.data_names.get(got[1]) != OBJECT_TYPE:
        return "its type isn't on the object's"
    return Lock(a, class_of(got[2], m.data_names), kind)


def source(lock: Lock) -> str:
    return f"""// Scope: common
// The lock of a weak handle as {lock.cls} (src/gflib3/Unk_Lock.h). {lock.cls}'s getter is
// its type's: a class on the object itself. Written by tools/lockgen.py:
// regenerate, don't edit.
#include "gflib3/Unk_Lock.h"

class {lock.cls} : public Unk_239a418 {{
public:
    static const Unk_239a418_Type* Unk_GetType() {{
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }}
}};

// 0x{lock.addr + BASE:x}
template Unk_239a418_Ref<{lock.cls}> Unk_Lock<{lock.cls}>(Unk_239a418_Handle*);
"""


def plan(m, only: set[int] | None = None, everything: bool = False):
    """(the locks to write, the candidates' addresses, [(address, why not)])."""
    locks, candidates, skipped, classes = [], [], [], set()
    for a in sorted(m.rows):
        if not m.rows[a].sword_size:
            continue
        lock = parse(m, a)
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


def cmd_census(m, args) -> None:
    locks, candidates, skipped = plan(m, everything=True)
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
    locks, _, _ = plan(m, only, args.all)
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
