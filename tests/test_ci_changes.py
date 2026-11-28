"""tools/ci_changes.py: which tests a pull request needs."""
from __future__ import annotations

import ci_changes as C


def test_classify():
    assert C.classify(["src/game/a.cpp", "lib/lua/x.c", "include/types.h", "README.md"]) == "none"
    assert C.classify([]) == "none"
    assert C.classify(["src/a.cpp", "data/functions.csv"]) == "data"
    assert C.classify(["data/functions.csv", "tools/leafgen.py"]) == "all"
    for p in ("tests/test_x.py", ".github/workflows/ci.yml", "cmake/toolchain-nx64.cmake", "CMakeLists.txt",
              "pyproject.toml", "tools/requirements-dev.txt", "docs/agents/worker.md", "tools\\units.py"):
        assert C.classify(["src/a.cpp", p]) == "all", p
    assert C.classify(["docs/game_code.md"]) == "none"   # only docs/agents is read by a test


def test_data_tests_exist():
    from pathlib import Path

    root = Path(__file__).resolve().parent.parent
    assert all((root / t).is_file() for t in C.DATA_TESTS)


def test_main(monkeypatch, tmp_path, capsys):
    out = tmp_path / "out"
    monkeypatch.setenv("GITHUB_OUTPUT", str(out))
    assert C.main(["--all"]) == 0
    monkeypatch.setattr("sys.stdin", __import__("io").StringIO("src/a.cpp\ndata/functions.csv\n"))
    assert C.main(["--stdin"]) == 0
    assert capsys.readouterr().out.split() == ["all", "data"]
    assert out.read_text(encoding="utf-8") == "tests=all\ntests=data\n"
