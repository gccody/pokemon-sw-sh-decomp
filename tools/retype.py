#!/usr/bin/env python3
"""Change a function's parameter types: its name and every declaration of it.

    python tools/retype.py 0x71007cd220 _Z15Unk_7cd220_callPK10Unk_7cd220h          # dry run: the diff
    python tools/retype.py 0x71007cd220 _Z15Unk_7cd220_callPK10Unk_7cd220h --apply  # write, then re-check
    python tools/retype.py 0x71007cd220 _Z15Unk_7cd220_callPK10Unk_7cd220h --update # ... and record statuses
    python tools/retype.py --from-file retypes.csv --apply                         # Address,Name rows

A callee named with the wrong parameter types (a `u32` that is a `u8`:
`j` -> `h`) can't be called the way the original calls it, so its callers
don't match. Fixing it means renaming it and every declaration its callers
compile against, and that's what this does:

1. renames it in data/functions.csv (as `tools/funcs.py name` does);
2. rewrites its declarations, in the generated directories (units.py
   GENERATED_DIRS: leaf, virtual, families, ...) and in hand-written headers
   and sources, that declare it by its old prototype (the parameter types
   its old name spells), and its definition if a generator wrote it (a
   hand-written one only with `--hand-definitions`: the coordinator's
   option, for a callee chain; a worker changes its own by hand). A
   declaration of the same identifier with other types (a hand-written
   wrapper's) is left alone and listed. A struct the new types name gets a
   forward declaration where the file has none;
3. re-checks only what it affected (`tools/check.py <addrs...>`): the
   function, every function defined in a file it rewrote and in every file
   that mentions the function. It prints each one's status before and
   after. If a function that was O isn't any more, or the build fails,
   everything goes back as it was (`--keep` keeps it). `--update` then
   records the statuses through `check.py --update`, never by hand.

It changes types, not identity: the new name must spell the same function
(scope, name, constness) with as many parameters, unless `--force-name`;
and no other row may have it. Without `--apply`/`--update` (or with
`--dry-run`) it only prints the rename and the diff.

Mangled names are read with leafgen.py's helpers (decode_params,
encode_params): free functions (`_Z<n><name><params>`) and nested names of
plain source names (`_ZN[K]<n><scope>...<n><name>E<params>`, constructors
and destructors too), with parameters of builtins, source-name types,
pointers, const and substitutions. It says so and stops for anything else
(templates, operators, references, nested parameter types, `std::`).
"""
from __future__ import annotations

import argparse
import csv
import difflib
import re
import subprocess
import sys
from dataclasses import dataclass, field
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import BASE, ROOT, read_functions_csv, write_functions_csv  # noqa: E402

FUNCTIONS_CSV = ROOT / "data" / "functions.csv"
SOURCE_SUFFIXES = (".c", ".cc", ".cpp", ".h", ".hpp", ".inl")
_XTOR = re.compile(r"(C[123]|D[012])")


class RetypeError(Exception):
    pass


# --------------------------------------------------------------------------- mangled names (tested)
@dataclass
class Sig:
    """A mangled name, as far as retype reads it."""
    prefix: str             # everything before the parameters: the function's identity
    scope: list[str]        # enclosing namespaces/classes ([] for a free function)
    ident: str              # its identifier (a constructor/destructor: its class's name)
    params: list[str]       # leafgen spellings of the parameter types
    subs: list[str] = field(default_factory=list)   # substitution candidates its name made
    xtor: str = ""          # "C2", "D1", ... for a constructor/destructor

    @property
    def codes(self) -> str:
        import leafgen

        return leafgen.encode_params(self.params, self.subs)

    @property
    def qualified(self) -> str:
        return "::".join([*self.scope, ("~" if self.xtor.startswith("D") else "") + self.ident])


def parse_name(name: str) -> Sig:
    """Sig of a mangled name, or RetypeError saying what it can't read."""
    import leafgen

    if not name.startswith("_Z"):
        raise RetypeError(f"{name}: not a mangled C++ name")
    rest = name[2:]
    parts: list[str] = []
    xtor = ""
    if rest.startswith("N"):
        rest = rest[1:]
        if rest.startswith("K"):
            rest = rest[1:]
        while rest and not rest.startswith("E"):
            m = re.match(r"\d+", rest)
            if m:
                n = int(m.group())
                rest = rest[m.end():]
                if len(rest) < n:
                    raise RetypeError(f"{name}: a source name runs past the end")
                parts.append(rest[:n])
                rest = rest[n:]
                continue
            m = _XTOR.match(rest)
            if m and parts:
                xtor = m.group()
                rest = rest[m.end():]
                continue
            raise RetypeError(f"{name}: can't read the nested name at {rest[:12]!r} "
                              "(templates, operators and std:: aren't handled)")
        if not rest.startswith("E") or not parts:
            raise RetypeError(f"{name}: unterminated nested name")
        rest = rest[1:]
        subs = ["::".join(parts[:i + 1]) for i in range(len(parts) - (0 if xtor else 1))]
    else:
        m = re.match(r"\d+", rest)
        if not m:
            raise RetypeError(f"{name}: can't read the name at {rest[:12]!r} (operators aren't handled)")
        n = int(m.group())
        parts = [rest[m.end():m.end() + n]]
        rest = rest[m.end() + n:]
        subs = []
    if any(not re.fullmatch(r"[A-Za-z_]\w*", p) for p in parts):
        raise RetypeError(f"{name}: a name part isn't an identifier")
    if not rest:
        raise RetypeError(f"{name}: no parameter types (a variable?)")
    params = leafgen.decode_params(rest, subs)
    if params is None or leafgen.encode_params(params, subs) != rest:
        raise RetypeError(f"{name}: can't read the parameter types {rest!r} (references, nested or template "
                          "types aren't handled)")
    prefix = name[:len(name) - len(rest)]
    ident = parts[-1]
    return Sig(prefix, parts if xtor else parts[:-1], ident, params, subs, xtor)


def check_rename(old: str, new: str, force_name: bool = False) -> tuple[Sig, Sig]:
    """(old, new) Sigs, or RetypeError when the new name isn't the same
    function with other parameter types."""
    o, n = parse_name(old), parse_name(new)
    if not force_name:
        if (o.prefix, o.xtor) != (n.prefix, n.xtor):
            raise RetypeError(f"{new} is another function than {old} ({n.qualified} vs {o.qualified}): "
                              "retype changes parameter types, not identity (--force-name)")
        if len(o.params) != len(n.params):
            raise RetypeError(f"{new} takes {len(n.params)} parameters, {old} {len(o.params)}: "
                              "retype changes their types, not their number (--force-name)")
    if old == new:
        raise RetypeError(f"{old}: the same name")
    return o, n


# --------------------------------------------------------------------------- source rewriting (tested)
def split_params(text: str) -> list[str]:
    """`const A* a, u32 b /*x*/` -> its parameters, as written (no splitting
    inside parentheses or angle brackets)."""
    out, depth, cur = [], 0, ""
    for ch in text:
        if ch in "(<":
            depth += 1
        elif ch in ")>":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur)
            cur = ""
        else:
            cur += ch
    if cur.strip():
        out.append(cur)
    return out


_STATEMENT = {"return", "else", "case", "goto", "throw", "new", "delete", "co_return", "sizeof"}
_NOT_A_NAME = {"const", "unsigned", "signed", "struct", "class", "volatile", "long", "short", "int", "char"}


def param_type(param: str) -> tuple[str, str]:
    """(type, the rest: name, comment, default) of one written parameter:
    `u32 value` -> ("u32", " value"), `const Unk_1*` -> ("const Unk_1*", "")."""
    p = param.strip()
    tail = ""
    m = re.search(r"\s*(=.*|/\*.*\*/)$", p)
    if m:
        p, tail = p[:m.start()], p[m.start():]
    m = re.fullmatch(r"(.*?[\s*&])\s*([A-Za-z_]\w*)", p)
    if m and m.group(1).strip() and m.group(1).strip() not in _NOT_A_NAME and m.group(2) not in _NOT_A_NAME:
        return m.group(1).strip(), " " + m.group(2) + tail
    return p.strip(), tail


def _norm(t: str) -> str:
    t = re.sub(r"\s+", " ", t.strip())
    t = re.sub(r"\s*\*", "*", t)
    t = re.sub(r"^struct |^class ", "", t)
    return t.replace("const struct ", "const ")


def prototype_codes(params_text: str, subs: list[str]) -> str | None:
    """The parameter encoding a written parameter list spells (leafgen's types
    only), None for one it can't spell."""
    import leafgen

    params = split_params(params_text)
    if [p.strip() for p in params] in ([], ["void"]):
        return "v"
    types = [_norm(param_type(p)[0]) for p in params]
    return leafgen.encode_params(types, subs)


def rewrite_params(params_text: str, new_types: list[str]) -> str:
    """params_text with each parameter's type replaced by new_types' (names,
    comments and spacing kept)."""
    params = split_params(params_text)
    if [p.strip() for p in params] in ([], ["void"]):
        return params_text
    out = []
    for p, t in zip(params, new_types):
        lead = p[:len(p) - len(p.lstrip())]
        old_t, rest = param_type(p)
        out.append(f"{lead}{t}{rest}")
    return ",".join(out)


@dataclass
class Match:
    start: int          # of the parameter list's text
    end: int
    definition: bool
    line: int


def _spans(text: str, pattern: str) -> list[tuple[int, int]]:
    """The bodies `{...}` of the `struct/class/namespace <name>` the pattern finds."""
    out = []
    for m in re.finditer(pattern, text):
        depth, i = 0, m.end() - 1
        while i < len(text):
            if text[i] == "{":
                depth += 1
            elif text[i] == "}":
                depth -= 1
                if depth == 0:
                    break
            i += 1
        out.append((m.end(), i))
    return out


def find_prototypes(text: str, sig: Sig) -> list[Match]:
    """Where text declares or defines the function (identifier, and for a
    nested name the enclosing class or namespace, or its qualification): the
    parameter lists, whatever their types."""
    ident = ("~" if sig.xtor.startswith("D") else "") + sig.ident
    pat = re.compile(r"^[ \t]*((?:[\w:<>,]+[ \t*&]+)*?)((?:\w+::)*)" + re.escape(ident)
                     + r"\(([^()]*)\)[ \t]*(?:const[ \t]*)?(?:noexcept[ \t]*)?(?:override[ \t]*)?"
                     + r"(?:final[ \t]*)?(;|\{|:|$)", re.M)
    if sig.scope:
        last = re.escape(sig.scope[-1])
        inside = _spans(text, rf"\b(?:struct|class)\s+{last}\b[^;{{()]*\{{") + \
            _spans(text, rf"\bnamespace\s+{last}\s*\{{")
    out = []
    for m in pat.finditer(text):
        head, qual = m.group(1), m.group(2)
        if set(re.findall(r"\w+", head)) & _STATEMENT or not (head.strip() or sig.xtor):
            continue  # a call: `return f(x);`, `f(x);`
        if sig.scope:
            if qual:
                if qual.rstrip(":").split("::")[-1] != sig.scope[-1]:
                    continue
            elif not any(a <= m.start() < b for a, b in inside):
                continue
        elif qual:
            continue
        if sig.xtor and not qual and not any(a <= m.start() < b for a, b in inside):
            continue
        tail = m.group(4)
        out.append(Match(m.start(3), m.end(3), tail in ("{", ":") or tail == "" and
                         text[m.end():].lstrip().startswith("{"), text.count("\n", 0, m.start()) + 1))
    return out


@dataclass
class FileEdit:
    path: Path
    old: str
    new: str
    rewrote: list[int] = field(default_factory=list)       # lines of the prototypes rewritten
    already: list[int] = field(default_factory=list)       # ... already of the new types
    other: list[int] = field(default_factory=list)         # ... of the identifier with other types
    hand_definition: list[int] = field(default_factory=list)


def edit_text(text: str, old: Sig, new: Sig, generated: bool) -> tuple[str, FileEdit]:
    """text with the function's prototypes of the old types rewritten to the
    new ones (a definition only when `generated`), plus forward declarations
    of the structs the new types name that the file doesn't declare."""
    e = FileEdit(Path(), text, text)
    pieces, pos = [], 0
    old_codes, new_codes = old.codes, new.codes
    for m in find_prototypes(text, old):
        codes = prototype_codes(text[m.start:m.end], old.subs)
        if codes == new_codes and codes != old_codes:
            e.already.append(m.line)
            continue
        if codes != old_codes:
            e.other.append(m.line)
            continue
        if m.definition and not generated:
            e.hand_definition.append(m.line)
            continue
        pieces += [text[pos:m.start], rewrite_params(text[m.start:m.end], new.params)]
        pos = m.end
        e.rewrote.append(m.line)
    out = "".join(pieces) + text[pos:]
    if e.rewrote:
        structs = sorted({re.sub(r"^const |\*+$", "", t).strip() for t in new.params if t.endswith("*")}
                         - {"void", "const void", "char", "const char"})
        missing = [s for s in structs if re.match(r"^[A-Za-z_]\w*$", s)
                   and not re.search(rf"\b(?:struct|class|union|using|typedef)\s+{re.escape(s)}\b", out)
                   and not re.search(rf"\b{re.escape(s)}\s*;\s*$", out, re.M)]
        if missing:
            lines = out.split("\n")
            at = e.rewrote[0] - 1
            # before the first rewritten prototype's line (or the comment block right above it)
            while at > 0 and lines[at - 1].lstrip().startswith("//"):
                at -= 1
            lines[at:at] = [f"struct {s};" for s in missing]
            out = "\n".join(lines)
    e.new = out
    return out, e


def address_comments(text: str) -> list[int]:
    """The Sword offsets of the `// 0x71...` comments above functions."""
    return [int(m.group(1), 16) - BASE for m in re.finditer(r"^\s*//\s*(0x71[0-9a-fA-F]{8})\b", text, re.M)]


# --------------------------------------------------------------------------- the files
def is_generated(rel: str) -> bool:
    import units

    return units.is_generated(rel)


def source_files(root: Path | None = None) -> list[Path]:
    root = root or ROOT
    out = []
    for top in ("src", "lib", "include"):
        d = root / top
        if d.is_dir():
            out += [p for p in d.rglob("*") if p.suffix in SOURCE_SUFFIXES and p.is_file()]
    return sorted(out)


def plan(old: Sig, new: Sig, files: list[Path], texts: dict[Path, str] | None = None,
         root: Path | None = None, hand: bool = False) -> tuple[list[FileEdit], list[Path]]:
    """The edits for one rename, and every file that mentions the identifier
    (whose functions may compile differently). `texts`: the files already
    edited by an earlier rename of the same run, as they are now."""
    edits, mentions = [], []
    word = re.compile(r"\b" + re.escape(old.ident) + r"\b")
    for p in files:
        text = (texts or {}).get(p)
        if text is None:
            text = p.read_text(encoding="utf-8", errors="replace")
        if not word.search(text):
            continue
        mentions.append(p)
        out, e = edit_text(text, old, new, hand or is_generated(p.relative_to(root or ROOT).as_posix()))
        e.path = p
        if out != text or e.other or e.hand_definition or e.already:
            edits.append(e)
    return edits, mentions


def diff(edits: list[FileEdit], root: Path | None = None) -> str:
    root = root or ROOT
    out = []
    for e in edits:
        if e.old == e.new:
            continue
        rel = e.path.relative_to(root).as_posix()
        out += difflib.unified_diff(e.old.splitlines(keepends=True), e.new.splitlines(keepends=True),
                                    f"a/{rel}", f"b/{rel}")
    return "".join(out)


# --------------------------------------------------------------------------- check.py
_RESULT = re.compile(r"^(OK |BAD) .*\[([^\]]*)\]\s*$")


def parse_check(log: str) -> dict[int, bool]:
    """Sword offset -> OK, from check.py's result lines."""
    out = {}
    for line in log.splitlines():
        m = _RESULT.match(line)
        if m is None:
            continue
        for tag in m.group(2).split(","):
            v, _, a = tag.strip().partition(":")
            if v == "sword" and a:
                out[int(a, 16) - BASE] = m.group(1) == "OK "
    return out


def run_check(addrs: list[int], update: bool = False, build: bool = True) -> tuple[bool, str, dict[int, bool]]:
    argv = [sys.executable, str(ROOT / "tools" / "check.py"), *[f"0x{a + BASE:x}" for a in sorted(addrs)]]
    if update:
        argv.append("--update")
    if not build:
        argv.append("--no-build")
    r = subprocess.run(argv, cwd=ROOT, capture_output=True, text=True)
    log = r.stdout + r.stderr
    return "matching," in log, log, parse_check(log)


# --------------------------------------------------------------------------- CLI
def read_requests(args) -> list[tuple[str, str]]:
    if args.from_file:
        with open(args.from_file, newline="", encoding="utf-8") as fh:
            rows = list(csv.reader(fh))
        if rows and rows[0] and rows[0][0].strip().lower() in ("address", "addr", "sword"):
            rows = rows[1:]
        return [(r[0].strip(), r[1].strip()) for r in rows if len(r) >= 2 and r[0].strip()]
    if not (args.addr and args.name):
        raise SystemExit("usage: retype.py ADDR NEW_NAME | retype.py --from-file FILE.csv")
    return [(args.addr, args.name)]


def find_row(funcs, addr: str):
    a = int(addr, 16)
    a = a - BASE if a >= BASE else a
    row = next((f for f in funcs if f.sword == a), None) or next((f for f in funcs if f.shield == a), None)
    if row is None:
        raise RetypeError(f"{addr}: no function starts there")
    return row


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("addr", nargs="?", help="the function's address (either game's)")
    ap.add_argument("name", nargs="?", help="its new mangled name")
    ap.add_argument("--from-file", type=Path, help="CSV of Address,Name rows (a header row is skipped)")
    ap.add_argument("--dry-run", action="store_true", help="print the rename and the diff only (the default)")
    ap.add_argument("--apply", action="store_true", help="write the files and functions.csv, then re-check")
    ap.add_argument("--update", action="store_true", help="--apply, then record the statuses (check.py --update)")
    ap.add_argument("--no-check", action="store_true", help="with --apply: don't re-check (tools/integrate.py "
                                                            "checks everything afterwards)")
    ap.add_argument("--keep", action="store_true", help="keep the changes even if something that matched doesn't")
    ap.add_argument("--force-name", action="store_true", help="allow a name of another identity or arity")
    ap.add_argument("--hand-definitions", action="store_true",
                    help="rewrite a hand-written definition's parameter types too (not for workers)")
    args = ap.parse_args(argv)
    apply = (args.apply or args.update) and not args.dry_run

    funcs = read_functions_csv(FUNCTIONS_CSV)
    by_name = {f.name: f for f in funcs if f.name}
    files = source_files()
    todo = []   # (row, old Sig, new Sig)
    try:
        for addr, new in read_requests(args):
            row = find_row(funcs, addr)
            if not row.name:
                raise RetypeError(f"{addr} has no name yet: name it with tools/funcs.py name")
            if row.name == new:
                print(f"{addr}: already {new}")
                continue
            other = by_name.get(new)
            if other is not None and other is not row:
                raise RetypeError(f"{new} is already the name of {other.sword_str or other.shield_str}")
            old_sig, new_sig = check_rename(row.name, new, args.force_name)
            todo.append((row, old_sig, new_sig))
    except RetypeError as e:
        print(f"retype: {e}", file=sys.stderr)
        return 2
    if not todo:
        return 0

    edits: dict[Path, FileEdit] = {}
    mentions: set[Path] = set()
    problems = []
    for row, o, n in todo:
        print(f"{row.sword_str or row.shield_str}: {row.name} -> {n.prefix}{n.codes}")
        print(f"  ({', '.join(o.params) or 'void'}) -> ({', '.join(n.params) or 'void'})")
        # each rename's edits apply on top of the previous ones' (two renames in one file)
        es, ms = plan(o, n, files, {p: e.new for p, e in edits.items()}, hand=args.hand_definitions)
        mentions |= set(ms)
        for e in es:
            rel = e.path.relative_to(ROOT).as_posix()
            for ln in e.other:
                print(f"  {rel}:{ln}: declares {o.ident} with other parameters: left alone")
            for ln in e.hand_definition:
                problems.append(f"{rel}:{ln}: the definition is hand-written: change its parameters there "
                                "(retype rewrites generated definitions only)")
            for ln in e.already:
                print(f"  {rel}:{ln}: already the new types")
            if e.path in edits:
                edits[e.path].new = e.new
                edits[e.path].rewrote += e.rewrote
            else:
                edits[e.path] = e
    for p in problems:
        print(f"  {p}")
    changed = [e for e in edits.values() if e.old != e.new]
    text = diff(changed)
    if text:
        print(text, end="")
    print(f"{len(changed)} files to rewrite, {sum(len(e.rewrote) for e in changed)} prototypes")
    if problems:
        print("retype: not applied", file=sys.stderr)
        return 1
    if not apply:
        print("(dry run: --apply writes it)")
        return 0

    before = {f.key: f.status for f in funcs}
    old_names = {row.key: row.name for row, _, _ in todo}
    for row, _, n in todo:
        row.name = n.prefix + n.codes
    write_functions_csv(FUNCTIONS_CSV, funcs)
    for e in changed:
        e.path.write_text(e.new, encoding="utf-8", newline="\n")
    if args.no_check:
        print("applied (not re-checked)")
        return 0

    affected = {row.sword for row, _, _ in todo if row.sword is not None}
    for p in {e.path for e in changed} | mentions:
        affected |= set(address_comments(p.read_text(encoding="utf-8", errors="replace")))
    rows = {f.sword: f for f in funcs if f.sword is not None}
    affected = {a for a in affected if a in rows}
    print(f"re-checking {len(affected)} functions")
    done, log, results = run_check(sorted(affected))
    regressed = [a for a in affected if before[rows[a].key] == "O" and not results.get(a, False)]
    for a in sorted(affected):
        f = rows[a]
        after = "OK" if results.get(a) else "not checked" if a not in results else "BAD"
        print(f"  0x{a + BASE:x} {f.name}: {before[f.key]} -> {after}")
    if (not done or regressed) and not args.keep:
        for row, _, _ in todo:
            row.name = old_names[row.key]
        write_functions_csv(FUNCTIONS_CSV, funcs)
        for e in changed:
            e.path.write_text(e.old, encoding="utf-8", newline="\n")
        why = "the build failed" if not done else f"{len(regressed)} functions that matched don't"
        tail = "\n".join(log.splitlines()[-30:]) if not done else ""
        print(f"retype: {why}; everything is back as it was (--keep keeps it)\n{tail}", file=sys.stderr)
        return 1
    if args.update:
        _, log, _ = run_check(sorted(affected), update=True, build=False)
        print(next((ln for ln in log.splitlines() if ln.startswith("updated ")), "no status changes"))
    gained = [a for a in affected if before[rows[a].key] != "O" and results.get(a)]
    print(f"{len(gained)} newly matching, {len(regressed)} no longer matching")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
