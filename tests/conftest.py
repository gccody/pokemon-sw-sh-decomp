"""Shared fixtures. Tests run without game files: anything that needs
data/original/ belongs in tools/check.py, not here."""
from __future__ import annotations

import sys
from pathlib import Path

import pytest

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))

HEADER = "Sword,SwordSize,Shield,ShieldSize,Scope,Status,Name\n"


@pytest.fixture
def write_csv(tmp_path):
    """write_csv(name, text) -> path of a file in a temporary directory."""

    def write(name: str, text: str) -> Path:
        p = tmp_path / name
        p.write_text(text, encoding="utf-8", newline="\n")
        return p

    return write


@pytest.fixture
def functions_csv(write_csv):
    """functions_csv(*rows) -> path of a functions.csv with the real header."""

    def make(*rows: str) -> Path:
        return write_csv("functions.csv", HEADER + "".join(r + "\n" for r in rows))

    return make
