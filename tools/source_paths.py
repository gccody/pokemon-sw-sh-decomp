"""Source-path literals: the `__FILE__` strings of vendored code.

`__FILE__` is the path the compiler was given for a file, so it names the
*vendor's* checkout: PhysX's TUs are
`C:/gitlab-runner/builds/.../physx/PhysX/PhysX_3.4/Source/PhysX/src/NpScene.cpp`,
and its headers are spelled relative to the vendor's build directory, with the
separator clang on Windows used (`./../../PhysX/src\\NpActorTemplate.h` for a
header found through `-I`, `/` for one found next to its includer). No source
can reproduce that: the spelling of a header depends on which TU included it
first, and the backslashes on the host. So check.py compares such a literal by
the file it names instead of byte for byte.

data/source_paths.csv says where the vendor's files were. One row per directory
of TUs (the longest matching `Source` wins):

    Source      repository directory of the TUs the row covers (lib/physx/PxShared/)
    Root        repository directory that `Original` corresponds to (lib/physx/)
    Original    the original's absolute path of `Root`
                (C:/gitlab-runner/builds/ba119cc0/0/research_and_development/physx/PhysX/)
    WorkDir     the original compiler's working directory, relative to `Root`;
                relative paths in the original are resolved against it. It may
                be outside `Root` (leading `../` segments): YEBIS compiled
                `src/GPU/miniz.c` as `../src/GPU/miniz.c`, from a sibling of
                `src/`, and lib/miniz/ is its `src/GPU/`
    Evidence    where the paths come from

A compiled literal of a TU under `Source` that is a path into `Root` (after
`\\` -> `/` and `..` folding) matches an original literal that names the same
file under `Root`: `Original` + the path, or a relative path from `WorkDir`.
Everything else is compared byte for byte, as before. `__LINE__` is an ordinary
immediate and is still compared exactly.
"""
from __future__ import annotations

import csv
import posixpath
import re
from dataclasses import dataclass
from pathlib import Path

HEADER = ["Source", "Root", "Original", "WorkDir", "Evidence"]
_ABSOLUTE = re.compile(r"^(?:[A-Za-z]:)?/")


def _norm(path: str) -> str:
    """Forward slashes, `.` and `..` folded (lexically, like the compiler's spelling)."""
    return posixpath.normpath(path.replace("\\", "/"))


def _under(path: str, root: str) -> str | None:
    """`path` relative to directory `root` (both normalised, case-insensitive), or None."""
    p, r = path.rstrip("/"), root.rstrip("/")
    if p.lower().startswith(r.lower() + "/"):
        return p[len(r) + 1:]
    return None


@dataclass(frozen=True)
class SourcePathRule:
    source: str
    root: str
    original: str
    workdir: str
    evidence: str = ""

    def original_rel(self, s: str) -> str | None:
        """The file under `root` that the original literal `s` names, or None."""
        n = _norm(s)
        rel = _under(n, _norm(self.original))
        if rel is not None:
            return rel
        if _ABSOLUTE.match(n):
            return None
        # resolved against the vendor's absolute work directory, so a WorkDir
        # outside Root (../../build/) and a path back into it (../src/GPU/x.c) fold
        work = posixpath.join(_norm(self.original), self.workdir)
        return _under(_norm(posixpath.join(work, s.replace("\\", "/"))), _norm(self.original))


class SourcePaths:
    def __init__(self, rules: list[SourcePathRule], repo: Path):
        self.rules = sorted(rules, key=lambda r: len(r.source), reverse=True)
        self.repo = _norm(repo.resolve().as_posix())

    def rule_for(self, source: str) -> SourcePathRule | None:
        """The row whose `Source` holds TU `source` (absolute or repository-relative)."""
        n = _norm(str(source))
        rel = _under(n, self.repo)
        if rel is None:
            rel = n
        for r in self.rules:
            if (rel + "/").lower().startswith(_norm(r.source).lower() + "/"):
                return r
        return None

    def compare(self, source: str, compiled: str, original: str) -> bool | None:
        """Whether a literal of TU `source` matches the original's, if it is a
        source path (True/False); None if the rule doesn't apply (compare bytes)."""
        rule = self.rule_for(source)
        if rule is None:
            return None
        n = _norm(compiled)
        rel = _under(n, posixpath.join(self.repo, _norm(rule.root)))
        if rel is None:
            return None
        return rule.original_rel(original) == rel


def read_source_paths(path: Path) -> list[SourcePathRule]:
    if not path.exists():
        return []
    with open(path, newline="", encoding="utf-8") as fh:
        return [SourcePathRule(r["Source"], r["Root"], r["Original"], r["WorkDir"], r.get("Evidence", ""))
                for r in csv.DictReader(fh)]


def lint_source_paths(path: Path, repo: Path) -> list[str]:
    """Problems with data/source_paths.csv (empty list if it's fine or absent)."""
    if not path.exists():
        return []
    with open(path, newline="", encoding="utf-8") as fh:
        reader = csv.reader(fh)
        header = next(reader, [])
    if header != HEADER:
        return [f"{path.name} header is {header}, expected {HEADER}"]
    errors, seen = [], set()
    for i, r in enumerate(read_source_paths(path), start=2):
        where = f"{path.name}:{i}"
        for col, v in (("Source", r.source), ("Root", r.root), ("WorkDir", r.workdir)):
            inner = v
            while col == "WorkDir" and inner.startswith("../"):
                inner = inner[3:]  # WorkDir may leave Root, but only by leading ../
            if not v.endswith("/") or v.startswith("/") or "\\" in v or ".." in inner.split("/"):
                errors.append(f"{where}: {col} {v!r} must be a relative directory ending in '/' with forward slashes")
        if not r.original.endswith("/") or not _ABSOLUTE.match(r.original):
            errors.append(f"{where}: Original {r.original!r} must be an absolute directory ending in '/'")
        if not (r.source.startswith(r.root) or r.source == r.root):
            errors.append(f"{where}: Source {r.source} must be inside Root {r.root}")
        if not r.evidence.strip():
            errors.append(f"{where}: give the evidence")
        if r.source in seen:
            errors.append(f"{where}: duplicate Source {r.source}")
        seen.add(r.source)
        if r.root.endswith("/") and not (repo / r.root).is_dir():
            errors.append(f"{where}: Root {r.root} is not a directory of the repository")
    return errors
