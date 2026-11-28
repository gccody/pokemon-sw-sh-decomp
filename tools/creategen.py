#!/usr/bin/env python3
"""The creators' wrappers: Unk_790260_Owner::Unk_790140<T>, an instance per class.

    python tools/creategen.py census                     # candidates, their creators, what's written
    python tools/creategen.py write --names n.csv        # src/gflib3/create, and the names to give
    python tools/creategen.py write --names n.csv --all  # a trial: every candidate
    python tools/creategen.py write --names n.csv --only add.txt   # the kept ones and these

The owner of tools/familygen.py's creators (`Unk_790260_Owner`,
src/gflib3/Unk_790260.h) makes its objects through a second template member,
written once per class, that wraps the creator (`Create<T>`). Its first
instance is 0x7100790140, the function right before the first creator. The
others are the same code calling another creator: shape group
`5f6118bb324c` of tools/shapes.py (docs/agents/generators.md, family 3).
A wrapper

- takes the parent by value (its callers copy a reference into a temporary
  and drop it after the call). A null parent becomes the owner's `field_58`,
  assigned (the new reference added, stored, the old one dropped);
- calls `Create<T>` with a copy of the parent and the name, a string literal
  in every caller (the object's name, Unk_23f4660's `field_5c0`);
- hands the new object to `target` (or the owner's `field_70` when it's
  null), held by a reference for the call: `Unk_e809c0_call(target, object)`
  (0x7100e809c0, src/unsorted/leaf/Unk_e7c1a0.cpp);
- returns the creator's reference.

The candidates are the functions of the seed's shape whose other calls are
`Unk_e809c0_call`; T is the class of the first call, the creator. A creator
that familygen wrote is named `Create<T>`, and T is read from its name. One
that isn't written is named here the way familygen names a creator: the
wrapper only needs its name, not its code. Its class is what familygen's
parse of it gives, or of its factory (`Unk_New::Create<T>`, when the
creator doesn't inline it), or failing both the primary vtable the
construction stores last (`primary_vtable`). A creator none of these name
leaves its wrapper unwritten (census says why).

None of the wrappers match yet: the template's NON_MATCHING note says how
they differ (docs/game_code.md, "The creators' wrappers").

The classes are only declared in the wrappers' file, as far as a reference
to one needs: a class on Unk_23f4660. Their members are familygen's (in the
creators' file) or unknown.

A row is kept (written again) when its name is the one written for it and
check.py matched it, or it's m/M (the template's NON_MATCHING note);
`--only` adds addresses, `--all` writes every candidate. A trial: `write
--all`, name (`tools/funcs.py name --from-file`), check.py, then mark
check.py's BAD wrappers M (`tools/funcs.py status <addr> M`), or `write
--only` without them to leave them U.
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

OUT_DIR = ROOT / "src" / "gflib3" / "create"
OUT_FILE = "Unk_790140.cpp"
SEED = 0x790140                 # Unk_790260_Owner::Unk_790140<Unk_23f5fa8>
HAND_OVER = 0xE809C0            # Unk_e809c0_call(const Unk_e809c0*, void*)
OWNER = "Unk_790260_Owner"
KEPT = "OmM"                    # statuses a named row keeps its wrapper written with
WRAPPER = "Unk_790140"
REF = "15Unk_239a418_Ref"
# Create<T>(Unk_Ref, const char*) and Unk_790140<T>(Unk_Ref, Unk_23f4660*, const char*):
# S_ the owner, S0_ T, S1_ the template's name, S2_ the reference
CREATE_RE = re.compile(rf"^_ZN16{OWNER}6CreateI(\d+)(\w+?)EE{REF}IT_ES2_I11Unk_239a418EPKc$")


def mangled_class(name: str) -> str:
    return f"{len(name)}{name}"


def creator_name(cls: str) -> str:
    """Unk_790260_Owner::Create<cls>(Unk_Ref, const char*), as tools/familygen.py names it."""
    return f"_ZN16{OWNER}6CreateI{mangled_class(cls)}EE{REF}IT_ES2_I11Unk_239a418EPKc"


def wrapper_name(cls: str) -> str:
    """Unk_790260_Owner::Unk_790140<cls>(Unk_Ref, Unk_23f4660*, const char*)."""
    return (f"_ZN16{OWNER}{mangled_class(WRAPPER)}I{mangled_class(cls)}EE{REF}IT_E"
            f"S2_I11Unk_239a418EP11Unk_23f4660PKc")


def creator_class(name: str) -> str | None:
    """T of a creator's mangled name, or None when it isn't one."""
    mt = CREATE_RE.match(name or "")
    if mt is None or int(mt.group(1)) != len(mt.group(2)):
        return None
    return mt.group(2)


def bl_targets(img: bytes, a: int, size: int) -> list[int]:
    """The targets of the BLs of the function at `a`, in order."""
    out = []
    for o in range(a, a + size, 4):
        w = struct.unpack_from("<I", img, o)[0]
        if (w & 0xFC000000) == 0x94000000:
            out.append(o + (((w & 0x3FFFFFF) ^ 0x2000000) - 0x2000000) * 4)
    return out


def candidates(img: bytes, rows: dict, seed: int = SEED, hand_over: int = HAND_OVER) -> dict[int, int]:
    """wrapper -> its creator, for the functions of the seed's shape (any status but L) that
    call a creator and then `hand_over` (twice: once for a null target, a block
    of its own)."""
    from shapes import shape

    want = shape(img[seed:seed + rows[seed].sword_size])
    out = {}
    for a, r in sorted(rows.items()):
        if r.status not in "UOmM" or r.sword_size != rows[seed].sword_size:
            continue
        if shape(img[a:a + r.sword_size]) != want:
            continue
        calls = bl_targets(img, a, r.sword_size)
        if len(calls) == 3 and calls[1:] == [hand_over, hand_over]:
            out[a] = calls[0]
    return out


TEMPLATE = """\
// Scope: common
//
// The creators' wrappers (Unk_790260_Owner::Unk_790140<T>, placeholder,
// src/gflib3/Unk_790260.h): each makes a T with its creator (Create<T>, in
// src/gflib3/families/Unk_790260.cpp when it's written) under a parent and
// hands it to a target. One template, an instance per class.
// Written by tools/creategen.py: regenerate, don't edit.
#include "gflib3/Unk_790260.h"

// 0x7100e809c0 (src/unsorted/leaf/Unk_e7c1a0.cpp): hands `value` to the
// object's field_5a0. The wrappers' target is that object, an Unk_23f4660.
struct Unk_e809c0;
void Unk_e809c0_call(const Unk_e809c0* self, void* value);

// NON_MATCHING: two of LLVM's block duplications differ from the original's.
// It threads the parent's copy past the copy's null test (as it does here for
// a copy made from the pointer, Unk_Ref(parent.m_ptr): Unk_239a418_Ref's copy
// tests the other reference's pointer through an i64 load, which LVI can't see
// through). And it computes the target's +0x48 interface again for the drop,
// where here GVN merges it with the add's, the drop's null test being folded
// before GVN runs (a copy of field_70 as a reference keeps the two apart, but
// then the test isn't folded at all).
template <class T>
Unk_239a418_Ref<T> Unk_790260_Owner::Unk_790140(Unk_Ref parent, Unk_23f4660* target, const char* name) {
    if (!parent.m_ptr)
        parent = field_58;
    Unk_239a418_Ref<T> result = Create<T>(parent, name);
    Unk_239a418_Ref<Unk_23f4660> to(target ? target : field_70);
    Unk_e809c0_call(reinterpret_cast<const Unk_e809c0*>(to.m_ptr), result.m_ptr);
    return result;
}

// The classes, declared only as far as a reference to one needs: classes on
// Unk_23f4660 (their members are in the creators' file, or unknown).
"""


def render(instances: list[tuple[int, str]]) -> str:
    """The wrappers' file: (Sword address relative to BASE, class) per instance."""
    classes = sorted({cls for _, cls in instances})
    out = [TEMPLATE]
    out += [f"class {cls} : public Unk_23f4660 {{}};\n" for cls in classes]
    for a, cls in sorted(instances):
        out.append(f"\n// 0x{a + BASE:x}\n"
                   f"template Unk_239a418_Ref<{cls}> {OWNER}::{WRAPPER}<{cls}>(Unk_Ref parent, Unk_23f4660* target,\n"
                   f"                                                     const char* name);\n")
    return "".join(out)


@dataclass
class Plan:
    instances: list = field(default_factory=list)   # (wrapper, class)
    names: dict = field(default_factory=dict)       # address -> name
    candidates: dict = field(default_factory=dict)  # wrapper -> creator
    classes: dict = field(default_factory=dict)     # wrapper -> class, of every one that has one
    skipped: list = field(default_factory=list)     # (wrapper, reason)


def plan(img: bytes, rows: dict, parse=None, only: set[int] | None = None, everything: bool = False,
         seed: int = SEED, hand_over: int = HAND_OVER) -> Plan:
    """What to write. `parse(creator)` gives an unnamed creator's class (or None)
    and why there's none (familygen's parse)."""
    p = Plan(candidates=candidates(img, rows, seed, hand_over))
    by_class: dict[str, int] = {}
    for a, c in sorted(p.candidates.items()):
        cr = rows.get(c)
        if cr is None:
            p.skipped.append((a, "its creator isn't in functions.csv"))
            continue
        cls = creator_class(cr.name)
        if cls is None and cr.name:
            p.skipped.append((a, "its creator has another name"))
            continue
        if cls is None:
            cls, why = parse(c) if parse is not None else (None, "no parse")
            if cls is None:
                p.skipped.append((a, f"its creator isn't parsed: {why}"))
                continue
        if by_class.setdefault(cls, a) != a:
            p.skipped.append((a, f"{cls}'s wrapper is 0x{by_class[cls] + BASE:x}"))
            continue
        p.classes[a] = cls
        n = wrapper_name(cls)
        r = rows[a]
        if not (everything or (only is not None and a in only) or (r.status in KEPT and r.name == n)):
            continue
        p.instances.append((a, cls))
        p.names[a] = n
        if cr.status != "O":
            p.names[c] = creator_name(cls)   # a creator that isn't written: named for the call
    return p


BASE_CTOR = 0xE7F820             # Unk_23f4660::Unk_23f4660(void*, u64, u64)


def primary_vtable(img: bytes, a: int, size: int, slots: dict, base_ctor: int = BASE_CTOR) -> int | None:
    """The vtable (its _ZTV address) a constructing function last stores at +0 of
    the object it calls `base_ctor` on, after that call: the most derived class's,
    since the parents' vptrs are stored first. The vtable comes through the GOT
    (`slots`: GOT entry -> its target) and is stored at +0x10. None when the
    object or the store isn't found."""
    from nx.refs import decode

    ins = list(decode(img, a, size))
    at = next((i for i, (_, w, _, t) in enumerate(ins) if (w & 0xFC000000) == 0x94000000 and t == base_ctor), None)
    if at is None:
        return None
    obj = next(((w >> 16) & 31 for _, w, _, _ in reversed(ins[:at]) if (w & 0xFFE0FFFF) == 0xAA0003E0), None)
    if obj is None:                         # mov x0, x<obj>
        return None
    regs: dict[int, tuple[int, int]] = {}   # register -> (vtable, offset added)
    last = None
    for _, w, _, t in ins[at + 1:]:
        if (w & 0xFC000000) == 0x94000000 or (w & 0xFFFFFC1F) == 0xD63F0000:
            regs = {}                       # bl, blr: what's in flight is gone (the object is callee-saved)
        elif t is not None and t in slots and (w & 0xFFC00000) == 0xF9400000:
            v = slots[t]                    # ldr x<d>, [x<d>, :got_lo12:...]
            if isinstance(v, int):
                regs[w & 31] = (v, 0)
            else:
                regs.pop(w & 31, None)
        elif (w & 0xFF800000) == 0x91000000:    # add x<d>, x<n>, #imm
            src = regs.get((w >> 5) & 31)
            if src is not None:
                regs[w & 31] = (src[0], src[1] + ((w >> 10) & 0xFFF))
            else:
                regs.pop(w & 31, None)
        elif (w & 0xFFC00000) in (0xF9000000, 0xA9000000):   # str / stp x<t>, [x<n>, #imm]
            off = ((w >> 10) & 0xFFF) * 8 if (w & 0xFFC00000) == 0xF9000000 else ((((w >> 15) & 0x7F) ^ 0x40) - 0x40) * 8
            got = regs.get(w & 31)
            if (w >> 5) & 31 == obj and off == 0 and got is not None and got[1] == 0x10:
                last = got[0]
        else:
            regs.pop(w & 31, None)
    return last


FACTORY_RE = re.compile(r"^_ZN7Unk_New6CreateI(\d+)(\w+?)J")


def factory_class(name: str) -> str | None:
    """T of an `Unk_New::Create<T>` (tools/familygen.py's objects), or None."""
    mt = FACTORY_RE.match(name or "")
    if mt is None or int(mt.group(1)) > len(mt.group(2)):
        return None
    return mt.group(2)[:int(mt.group(1))]


def _familygen_parse(m):
    """parse(creator) -> (class, why not): familygen's parse of a creator, or of
    its factory when the creator calls one (`Unk_New::Create<T>` not inlined:
    named, or parsed as one of familygen's objects); failing those, the class
    of the primary vtable the construction stores last (`primary_vtable`,
    which gives familygen's class for every creator and factory it parses)."""
    import familygen

    seed = familygen.parse_creator(m, familygen.CREATOR_SEED)
    seed_tail = None if isinstance(seed, str) else seed.creator_tail
    inlined = set(familygen.CREATOR_CALLS) - {BASE_CTOR}

    def parse(c: int):
        f = familygen.parse_creator(m, c, seed_tail)
        if not isinstance(f, str):
            return f.cls, ""
        calls = set(bl_targets(m.img, c, m.rows[c].sword_size)) - inlined
        if BASE_CTOR in calls:
            v = primary_vtable(m.img, c, m.rows[c].sword_size, m.slots)
            return (None, f) if v is None else (familygen.placeholder(v), "")
        if len(calls) != 1:
            return None, f
        t = calls.pop()
        cls = factory_class(m.rows[t].name) if t in m.rows else None
        if cls is not None:
            return cls, ""
        o = familygen.parse_object(m, t)
        if not isinstance(o, str):
            return o.cls, ""
        v = primary_vtable(m.img, t, m.rows[t].sword_size, m.slots) if t in m.rows else None
        return (None, f"its factory isn't parsed: {o}") if v is None else (familygen.placeholder(v), "")

    return parse


def load():
    import familygen

    m = familygen.load()
    return m, _familygen_parse(m)


def cmd_write(args) -> None:
    from common import clang_format

    m, parse = load()
    only = {int(x, 16) - BASE for x in args.only.read_text(encoding="utf-8").split()} if args.only else None
    p = plan(m.img, m.rows, parse, only, args.all)
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    path = OUT_DIR / OUT_FILE
    path.unlink(missing_ok=True)
    if p.instances:
        path.write_text(render(p.instances), encoding="utf-8", newline="\n")
        if not clang_format([path]):
            print("clang-format isn't on PATH: format the written file before committing it", file=sys.stderr)
    with open(args.names, "w", encoding="utf-8", newline="\n") as fh:
        fh.write("Name,Sword,Shield\n")
        for a, n in sorted(p.names.items()):
            r = m.rows[a]
            fh.write(f"{n},{r.sword_str},{r.shield_str}\n")
    print(f"{len(p.instances)} wrappers; {len(p.names)} names in {args.names}", file=sys.stderr)


def cmd_census(args) -> None:
    m, parse = load()
    p = plan(m.img, m.rows, parse, everything=True)
    rows = m.rows
    wrappers = sorted(p.candidates)
    done = [a for a in wrappers if rows[a].status == "O"]
    near = [a for a in wrappers if rows[a].status in "mM"]
    print(f"{len(wrappers)} candidates ({sum(rows[a].sword_size for a in wrappers)} bytes), "
          f"{len(done)} matched, {len(near)} m/M")
    by_creator: dict[str, int] = {}
    for a in p.classes:
        st = rows[p.candidates[a]].status
        key = f"creator {st}" + (" (named here)" if not rows[p.candidates[a]].name else "")
        by_creator[key] = by_creator.get(key, 0) + 1
    for k, n in sorted(by_creator.items()):
        print(f"  {k}: {n}")
    reasons: dict[str, int] = {}
    for _, why in p.skipped:
        key = why.split(" at ")[0]
        reasons[key] = reasons.get(key, 0) + 1
    for why, n in sorted(reasons.items(), key=lambda kv: -kv[1]):
        print(f"  not written: {n:4d} {why}")


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("census")
    w = sub.add_parser("write")
    w.add_argument("--names", type=Path, required=True, help="where to write the Name,Sword,Shield CSV")
    w.add_argument("--all", action="store_true", help="every candidate (a trial)")
    w.add_argument("--only", type=Path, help="addresses to write besides the kept ones")
    args = ap.parse_args(argv)
    if args.cmd == "write":
        cmd_write(args)
    else:
        cmd_census(args)
    return 0


if __name__ == "__main__":
    sys.exit(main())
