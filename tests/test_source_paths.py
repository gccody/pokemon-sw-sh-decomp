"""source_paths.py: __FILE__ literals of vendored code compared by the file they name."""
from __future__ import annotations

from pathlib import Path

from source_paths import HEADER, SourcePathRule, SourcePaths, lint_source_paths, read_source_paths

ORIGINAL = "C:/gitlab-runner/builds/ba119cc0/0/research_and_development/physx/PhysX/"
RULES = [
    SourcePathRule("lib/physx/PhysX_3.4/", "lib/physx/", ORIGINAL, "PhysX_3.4/Source/compiler/nx/"),
    SourcePathRule("lib/physx/PxShared/", "lib/physx/", ORIGINAL, "PxShared/src/compiler/nx/"),
]


def paths(repo: Path) -> SourcePaths:
    return SourcePaths(RULES, repo)


def test_tu_path_matches_the_vendors_absolute_path(tmp_path):
    p = paths(tmp_path)
    tu = f"{tmp_path.as_posix()}/lib/physx/PhysX_3.4/Source/PhysX/src/NpScene.cpp"
    assert p.compare(tu, tu, ORIGINAL + "PhysX_3.4/Source/PhysX/src/NpScene.cpp") is True
    assert p.compare(tu, tu, ORIGINAL + "PhysX_3.4/Source/PhysX/src/NpActor.cpp") is False


def test_header_paths_resolve_against_the_vendors_work_dir(tmp_path):
    p = paths(tmp_path)
    tu = f"{tmp_path.as_posix()}/lib/physx/PhysX_3.4/Source/PhysX/src/NpScene.cpp"
    # clang on Windows joins an -I directory and the name with a backslash
    mine = f"{tmp_path.as_posix()}/lib/physx/PxShared/src/foundation/include\\PsArray.h"
    assert p.compare(tu, mine, "./../../../../PxShared/src/foundation/include\\PsArray.h") is True
    assert p.compare(tu, mine, "./../../../../PxShared/src/foundation/include/PsArray.h") is True
    assert p.compare(tu, mine, "./../../PhysX/src\\NpActorTemplate.h") is False
    # PxFoundation's TUs were built from another directory
    foundation = f"{tmp_path.as_posix()}/lib/physx/PxShared/src/foundation/src/PsFoundation.cpp"
    assert p.compare(foundation, mine, "./../../foundation/include/PsArray.h") is True


def test_other_literals_and_other_tus_are_compared_as_bytes(tmp_path):
    p = paths(tmp_path)
    tu = f"{tmp_path.as_posix()}/lib/physx/PhysX_3.4/Source/PhysX/src/NpScene.cpp"
    assert p.compare(tu, "NonTrackedAlloc", "NonTrackedAlloc") is None
    lua = f"{tmp_path.as_posix()}/lib/lua/lapi.c"
    assert p.compare(lua, lua, ORIGINAL + "lua/lapi.c") is None
    # a relative original path that leaves the vendor's tree names nothing
    assert RULES[0].original_rel("./../../../../../../outside.h") is None


def test_work_dir_outside_root(tmp_path):
    # YEBIS compiled C:/workspace/YEBIS_draft/src/GPU/miniz.c as ../src/GPU/miniz.c,
    # from a sibling of src/; lib/miniz/ stands for src/GPU/
    rule = SourcePathRule("lib/miniz/", "lib/miniz/", "C:/workspace/YEBIS_draft/src/GPU/", "../../nx/")
    p = SourcePaths([rule], tmp_path)
    tu = f"{tmp_path.as_posix()}/lib/miniz/miniz.c"
    assert p.compare(tu, tu, "../src/GPU/miniz.c") is True
    assert p.compare(tu, tu, "../src/GPU/other.c") is False
    assert p.compare(tu, tu, "C:/workspace/YEBIS_draft/src/GPU/miniz.c") is True
    # names a file outside Root: not one of ours
    assert rule.original_rel("../include/PPFX/ppfxTypes.h") is None
    assert rule.original_rel("../../../../../../../x.h") is None


def test_longest_source_wins(tmp_path):
    rules = RULES + [SourcePathRule("lib/physx/", "lib/physx/", "D:/elsewhere/", "x/")]
    p = SourcePaths(rules, tmp_path)
    assert p.rule_for("lib/physx/PxShared/src/a.cpp").workdir == "PxShared/src/compiler/nx/"
    assert p.rule_for("lib/physx/other/b.cpp").original == "D:/elsewhere/"


def test_read_and_lint(tmp_path, write_csv):
    (tmp_path / "lib" / "physx").mkdir(parents=True)
    good = write_csv("source_paths.csv", ",".join(HEADER) + "\n"
                     f"lib/physx/PxShared/,lib/physx/,{ORIGINAL},PxShared/src/compiler/nx/,strings\n")
    assert lint_source_paths(good, tmp_path) == []
    outside = write_csv("outside.csv", ",".join(HEADER) + "\n"
                        f"lib/physx/,lib/physx/,{ORIGINAL},../../nx/,strings\n"
                        f"lib/physx/a/,lib/physx/,{ORIGINAL},nx/../x/,strings\n")
    errors = lint_source_paths(outside, tmp_path)
    assert len(errors) == 1 and "nx/../x/" in errors[0]
    assert read_source_paths(good)[0].workdir == "PxShared/src/compiler/nx/"
    bad = write_csv("bad.csv", ",".join(HEADER) + "\n"
                    "lib/physx,lib/other/,relative/,..\\x/,\n")
    errors = lint_source_paths(bad, tmp_path)
    assert any("Source 'lib/physx'" in e for e in errors)
    assert any("Original" in e for e in errors)
    assert any("evidence" in e for e in errors)
    assert any("not a directory" in e for e in errors)
    assert lint_source_paths(tmp_path / "missing.csv", tmp_path) == []
