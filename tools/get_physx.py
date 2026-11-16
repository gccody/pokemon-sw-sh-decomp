#!/usr/bin/env python3
"""Generate the lib/physx files that need PhysX v3.4.2's code.

    python tools/get_physx.py                # download what it needs (about 170 files)
    python tools/get_physx.py --clone DIR    # or read it from a local clone of PhysX-3.4
    python tools/get_physx.py --check        # only check the generated files

lib/physx is NVIDIA's PhysX 3.4 at the BSD-3 HEAD revision (5e42a5f), the text
the repository may carry. The binary was built from v3.4.2 (b99b378), whose
code differs from HEAD's in 83 of the vendored files. Those files aren't in the
repository: this tool rebuilds each one from NVIDIA's public repository
(https://github.com/NVIDIAGameWorks/PhysX-3.4), from HEAD's text with v3.4.2's
version of every hunk whose code differs. Hunks that differ only in comments
keep HEAD's text. Every line keeps its v3.4.2 line number, because __LINE__ is
part of the code. Line 1 of each file (the license block's empty `//`) then
lists the lines that are v3.4.2's.

data/physx_v342.csv lists the files and the SHA-256 of each generated file,
and CMake refuses to configure until they all match. lib/physx/.gitignore keeps
them out of git. Downloads are cached in toolchain/physx/<revision>/.
"""
from __future__ import annotations

import argparse
import csv
import difflib
import hashlib
import re
import subprocess
import sys
import urllib.request
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import ROOT  # noqa: E402

V342 = "b99b3783cd7e3fb1bb0a07dc472b2fc000c4cdc1"  # tag v3.4.2, "patch release @24214033"
HEAD = "5e42a5f112351a223c19c17bb331e6c55037b8eb"  # BSD-3, "patch release @25354359"
RAW = "https://raw.githubusercontent.com/NVIDIAGameWorks/PhysX-3.4/{rev}/{path}"
LIST_CSV = ROOT / "data" / "physx_v342.csv"
LIST_HEADER = ["Path", "SHA256"]
DEST = ROOT / "lib" / "physx"
CACHE = ROOT / "toolchain" / "physx"

_COMMENT = re.compile(r'//[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'', re.S)


def read_list(path: Path = LIST_CSV) -> list[tuple[str, str]]:
    """(path under lib/physx, SHA-256 of the generated file) rows."""
    with open(path, newline="", encoding="utf-8") as fh:
        return [(r["Path"], r["SHA256"]) for r in csv.DictReader(fh)]


def decode(data: bytes) -> str:
    """Text with "\\n" line ends (upstream files are CRLF)."""
    return data.decode("utf-8", errors="surrogateescape").replace("\r\n", "\n").replace("\r", "\n")


def strip(text: str) -> list[str]:
    """Lines with comments removed (newlines inside block comments kept) and
    whitespace normalised: what the compiler sees, line by line."""
    def repl(m):
        s = m.group()
        return "\n" * s.count("\n") if s.startswith(("//", "/*")) else s
    return [" ".join(line.split()) for line in _COMMENT.sub(repl, text).split("\n")]


def _split_license(text: str) -> tuple[list[str], list[str]]:
    lines = text.splitlines(True)
    i = 0
    while i < len(lines) and lines[i].startswith("//"):
        i += 1
    return lines[:i], lines[i:]


def _build(ops, head: list[str], v342: list[str], choice: dict[int, str]) -> list[str]:
    out: list[str] = []
    for k, (tag, i1, i2, j1, j2) in enumerate(ops):
        out += head[i1:i2] if tag == "equal" or choice.get(k) == "head" else v342[j1:j2]
    return out


def restore(v342_text: str, head_text: str) -> tuple[str, list[str]]:
    """HEAD's file with v3.4.2's code: (text, v3.4.2 line ranges). A range
    "N-" means HEAD lines were removed after line N."""
    _, body342 = _split_license(v342_text)
    lic, bodyh = _split_license(head_text)
    target = strip("".join(body342))
    ops = difflib.SequenceMatcher(None, bodyh, body342, autojunk=False).get_opcodes()
    choice = {k: "342" for k, op in enumerate(ops) if op[0] != "equal"}
    for k in list(choice):  # keep HEAD's text wherever the code stays v3.4.2's
        trial = dict(choice)
        trial[k] = "head"
        if strip("".join(_build(ops, bodyh, body342, trial))) == target:
            choice = trial
    body = _build(ops, bodyh, body342, choice)
    assert strip("".join(body)) == target
    ranges = []
    for k in sorted(k for k, c in choice.items() if c == "342"):
        _, _, _, j1, j2 = ops[k]
        a, b = j1 + len(lic) + 1, j2 + len(lic)
        ranges.append(f"{b}-" if b < a else (str(a) if a == b else f"{a}-{b}"))
    return "".join(lic + body), ranges


def generate(v342_text: str, head_text: str) -> bytes:
    """The lib/physx file: restore()'s text, with line 1 listing v3.4.2's lines."""
    text, ranges = restore(v342_text, head_text)
    if not ranges:
        raise ValueError("no hunk needs v3.4.2's code")
    first, rest = text.split("\n", 1)
    if first != "//":
        raise ValueError(f"line 1 is {first!r}, not the license block's empty //")
    note = ("// Pokemon SwSh decomp: v3.4.2's code, not this (BSD) revision's, at lines " + ", ".join(ranges)
            + " (\"N-\": lines removed after line N). See lib/physx/README.md.")
    return (note + "\n" + rest).encode("utf-8", errors="surrogateescape")


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def fetch(rev: str, path: str, clone: Path | None) -> bytes:
    """`path` at `rev`: from the clone (git show), else downloaded (cached)."""
    if clone is not None:
        return subprocess.run(["git", "-C", str(clone), "show", f"{rev}:{path}"], check=True,
                              capture_output=True).stdout
    cached = CACHE / rev / path
    if cached.exists():
        return cached.read_bytes()
    req = urllib.request.Request(RAW.format(rev=rev, path=path), headers={"User-Agent": "get_physx.py"})
    with urllib.request.urlopen(req, timeout=60) as r:
        data = r.read()
    cached.parent.mkdir(parents=True, exist_ok=True)
    cached.write_bytes(data)
    return data


def stale(rows: list[tuple[str, str]], dest: Path = DEST) -> list[str]:
    """The listed files that are missing or don't have their SHA-256."""
    return [p for p, h in rows if not (dest / p).is_file() or sha256((dest / p).read_bytes()) != h]


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--clone", type=Path, help="a clone of NVIDIAGameWorks/PhysX-3.4 to read instead of downloading")
    ap.add_argument("--check", action="store_true", help="only check that the generated files are up to date")
    args = ap.parse_args(argv)

    rows = read_list()
    todo = stale(rows)
    if args.check or not todo:
        for p in todo:
            print(f"missing or out of date: lib/physx/{p}")
        print(f"{len(rows) - len(todo)} of {len(rows)} files up to date")
        return 1 if todo else 0

    def one(row: tuple[str, str]) -> str | None:
        p, h = row
        data = generate(decode(fetch(V342, p, args.clone)), decode(fetch(HEAD, p, args.clone)))
        if sha256(data) != h:
            return f"lib/physx/{p}: the generated file's SHA-256 isn't the listed one"
        (DEST / p).parent.mkdir(parents=True, exist_ok=True)
        (DEST / p).write_bytes(data)
        return None

    wanted = [r for r in rows if r[0] in set(todo)]
    with ThreadPoolExecutor(max_workers=8) as pool:
        errors = [e for e in pool.map(one, wanted) if e]
    for e in errors:
        print(f"error: {e}", file=sys.stderr)
    print(f"generated {len(wanted) - len(errors)} of {len(wanted)} files in lib/physx")
    return 1 if errors else 0


if __name__ == "__main__":
    raise SystemExit(main())
