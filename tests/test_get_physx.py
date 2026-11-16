"""get_physx.py: HEAD's text with v3.4.2's code, rebuilt hunk by hunk. Tiny
hand-written files, no network."""
from __future__ import annotations

import pytest

import get_physx as g

LICENSE = "//\n// BSD license text\n//\n"


def test_decode_makes_lf_text():
    assert g.decode(b"a\r\nb\rc\n") == "a\nb\nc\n"


def test_code_hunks_come_from_v342_and_comment_hunks_keep_head():
    # (adjacent changed lines are one hunk, so an unchanged line separates them)
    head = LICENSE + "int a = 1; // HEAD's comment\nint s;\nint b = 2;\nint c = 3;\n"
    v342 = LICENSE + "int a = 1; // the old comment\nint s;\nint b = 20;\nint c = 3;\n"
    text, ranges = g.restore(v342, head)
    assert text == LICENSE + "int a = 1; // HEAD's comment\nint s;\nint b = 20;\nint c = 3;\n"
    assert ranges == ["6"]  # the license block is lines 1-3


def test_removed_lines_and_line_numbers():
    head = LICENSE + "int a;\nint added_after_342;\nint b;\n"
    v342 = LICENSE + "int a;\nint b;\n"
    text, ranges = g.restore(v342, head)
    assert text == v342
    assert ranges == ["4-"]  # HEAD's line removed after line 4: every line keeps v3.4.2's number


def test_generate_lists_the_v342_lines_on_line_1():
    head = LICENSE + "int b = 2;\n"
    v342 = LICENSE + "int b = 20;\n"
    out = g.generate(v342, head).decode()
    first, rest = out.split("\n", 1)
    assert first.startswith("// Pokemon SwSh decomp: v3.4.2's code") and "at lines 4 " in first
    assert rest == "// BSD license text\n//\nint b = 20;\n"
    assert len(out.splitlines()) == len(v342.splitlines())


def test_generate_refuses_files_without_code_changes_or_the_empty_first_line():
    with pytest.raises(ValueError, match="no hunk"):
        g.generate(LICENSE + "int a; // x\n", LICENSE + "int a; // y\n")
    with pytest.raises(ValueError, match="line 1"):
        g.generate("// a\nint b = 20;\n", "// a\nint b = 2;\n")


def test_stale_and_the_download_cache(tmp_path, monkeypatch):
    dest = tmp_path / "physx"
    (dest / "A").mkdir(parents=True)
    (dest / "A" / "x.h").write_bytes(b"x")
    rows = [("A/x.h", g.sha256(b"x")), ("A/y.h", g.sha256(b"y")), ("A/z.h", g.sha256(b"z"))]
    (dest / "A" / "z.h").write_bytes(b"old")
    assert g.stale(rows, dest) == ["A/y.h", "A/z.h"]

    monkeypatch.setattr(g, "CACHE", tmp_path / "cache")
    (tmp_path / "cache" / g.V342 / "A").mkdir(parents=True)
    (tmp_path / "cache" / g.V342 / "A" / "y.h").write_bytes(b"cached")

    def no_network(*a, **k):
        raise AssertionError("downloaded although cached")

    monkeypatch.setattr(g.urllib.request, "urlopen", no_network)
    assert g.fetch(g.V342, "A/y.h", None) == b"cached"


def test_repository_list_matches_its_gitignore():
    rows = g.read_list()
    assert len(rows) == 83
    ignored = (g.DEST / ".gitignore").read_text(encoding="utf-8").splitlines()
    assert all(f"/{p}" in ignored for p, _ in rows)
