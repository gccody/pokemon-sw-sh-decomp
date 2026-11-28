"""tools/worktree_setup.py: jobs, git excludes, links and the teardown check (no game files)."""
from __future__ import annotations

import os

import pytest

import worktree_setup as W


def test_default_jobs():
    assert W.default_jobs(20, 6) == 3
    assert W.default_jobs(4, 6) == 1
    assert W.default_jobs(None, 0) == 1


def test_add_excludes_is_idempotent(tmp_path):
    p = tmp_path / "info" / "exclude"
    p.parent.mkdir()
    p.write_text("# comment\n/.venv", encoding="utf-8")
    assert W.add_excludes(p) == ["/toolchain", "/data/original", "/.swarm"]
    assert W.add_excludes(p) == []
    lines = p.read_text(encoding="utf-8").splitlines()
    assert lines[1] == "/.venv" and lines.count("/.swarm") == 1


@pytest.mark.skipif(os.name == "nt", reason="symlinks need privileges on Windows (junctions are used there)")
def test_link_dir(tmp_path):
    target = tmp_path / "main" / ".venv"
    target.mkdir(parents=True)
    link = tmp_path / "wt" / ".venv"
    assert W.link_dir(link, target) == "linked"
    assert W.link_dir(link, target) == "ok"
    other = tmp_path / "other"
    other.mkdir()
    assert "elsewhere" in W.link_dir(link, other)
    real = tmp_path / "wt" / "toolchain"
    real.mkdir()
    assert "not a link" in W.link_dir(real, target)
    assert "doesn't exist" in W.link_dir(tmp_path / "wt" / "x", tmp_path / "missing")


def test_cmake_args():
    assert W.cmake_args("sword", 3, None) == ["--preset", "sword", "-DCMAKE_JOB_POOLS=compile=3",
                                              "-DCMAKE_JOB_POOL_COMPILE=compile"]
    assert W.cmake_args("shield", 2, "/usr/bin/ccache")[-1] == "-DCMAKE_CXX_COMPILER_LAUNCHER=/usr/bin/ccache"


def test_unexpected_changes():
    porcelain = " M data/functions.csv\n M src/a.cpp\n?? .swarm/sidecar.json\nR  src/b.cpp -> src/c.cpp\n"
    assert W.unexpected_changes(porcelain) == ["src/a.cpp", "src/c.cpp"]
    # the first line keeps its leading space (git() only strips the end)
    assert W.unexpected_changes(" M data/functions.csv\n M data/data_symbols.csv") == []


def test_archived_sidecar_never_overwrites(tmp_path):
    assert W.archived_sidecar(tmp_path, "u10").name == "sidecar-u10.json"
    (tmp_path / "sidecar-u10.json").write_text("{}")
    assert W.archived_sidecar(tmp_path, "u10").name == "sidecar-u10-2.json"
    assert W.archived_sidecar(tmp_path, "").name == "sidecar-unknown.json"


def test_workers_and_jobs_after_the_subcommand(monkeypatch):
    """`create ... --workers 6` (as the docs write it) sets the job count, like `--workers 6 create ...`."""
    seen = {}
    monkeypatch.setattr(W, "cmd_create", lambda args: seen.update(vars(args)) or 0)
    monkeypatch.setattr(W.os, "cpu_count", lambda: 20)
    monkeypatch.delenv("PKMN_JOBS", raising=False)
    assert W.main(["create", "../w", "--branch", "b", "--workers", "5"]) == 0
    assert seen["workers"] == 5 and seen["jobs"] == 4
    assert W.main(["--workers", "2", "create", "../w", "--branch", "b"]) == 0
    assert seen["jobs"] == 10
    assert W.main(["create", "../w", "--branch", "b", "--jobs", "3"]) == 0
    assert seen["jobs"] == 3
