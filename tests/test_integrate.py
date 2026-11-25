"""tools/integrate.py: path checks, the summary and the sidecar's names (no game files)."""
from __future__ import annotations

import pytest
from common import BASE, Function

import integrate


def fn(addr: int, status: str, name: str = "", size: int = 8) -> Function:
    return Function(addr, addr, size, size, "common", status, name)


def test_bad_paths():
    assert integrate.bad_paths(["src/a.cpp", "data/functions.csv", "data/original/sword/main",
                                ".cache/ghidra/x.c", "src/x/y.pb.cc", "foo.keys", "build/sword/a.o",
                                "data/data_symbols.csv", "src/build_things.cpp"]) == [
        "data/functions.csv", "data/original/sword/main", ".cache/ghidra/x.c", "src/x/y.pb.cc", "foo.keys",
        "build/sword/a.o"]


def test_summarize():
    before = [fn(0x10, "U"), fn(0x20, "U"), fn(0x30, "U"), fn(0x40, "O", "_Z1av"), fn(0x50, "U")]
    after = [fn(0x10, "O", "_Z1bv", 12), fn(0x20, "M", "_Z1cv"), fn(0x30, "U"), fn(0x40, "M", "_Z1av"),
             fn(0x50, "O")]
    s = integrate.summarize(before, after, {f.key for f in before[:3]})
    assert [f.sword for f in s.matched] == [0x10] and s.matched_bytes == 12
    assert [f.sword for f in s.nonmatching] == [0x20]
    assert [f.sword for f in s.skipped] == [0x30]
    assert [f.sword for f in s.regressions] == [0x40]
    assert [(f.sword, c) for f, c in s.other] == [(0x50, "U->O")]
    assert s.named == 2
    assert "matched 1 (12 bytes), m/M 1, skipped 1" in s.text()


def test_names_csv():
    rows = [Function(0x10, 0x18, 8, 8, "common", "U", ""), Function(0x20, None, 8, None, "sword", "U", "")]
    text = integrate.names_csv([{"addr": f"0x{BASE + 0x10:x}", "name": "_Z1fv"},
                                {"addr": f"0x{BASE + 0x20:x}", "name": "_Z1gv"}], rows)
    assert text.splitlines() == ["Name,Sword,Shield", f"_Z1fv,0x{BASE + 0x10:x},0x{BASE + 0x18:x}",
                                 f"_Z1gv,0x{BASE + 0x20:x},"]
    with pytest.raises(SystemExit):
        integrate.names_csv([{"addr": "0x7100000099", "name": "x"}], rows)


def test_check_lines():
    log = ("OK  common      f()  [sword:0x7100000010, shield:0x7100000010]\n"
           "BAD common      g()  [sword:0x7100000020, shield:0x7100000028]\n"
           "      sword: differs at +0x4\n"
           "BAD common      h()  [sword:0x7100000030, shield:0x7100000030]\n"
           "      sword: differs\n"
           "\n5 matching, 2 not matching\n")
    lines = integrate.check_lines(log, [fn(0x10, "O"), fn(0x20, "M")])
    assert lines == ["OK  common      f()  [sword:0x7100000010, shield:0x7100000010]",
                     "BAD common      g()  [sword:0x7100000020, shield:0x7100000028]",
                     "      sword: differs at +0x4"]
