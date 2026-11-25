"""tools/context.py: source snippets, class names and shape ranking (no game files)."""
from __future__ import annotations

from pathlib import Path

import context

SRC = """// Scope: common
#include <types.h>

// 0x7100000010
int f(int a) {
    if (a) {
        return 1;
    }
    return 2;
}

// 0x7100000040 - a one-liner
int g() { return 3; }

// 0x7100000050
int h();
"""


def test_source_snippet():
    s = context.source_snippet(SRC, 0x10)
    assert s.splitlines()[0] == "// 0x7100000010" and s.splitlines()[-1] == "}"
    assert len(s.splitlines()) == 7
    assert context.source_snippet(SRC, 0x40).splitlines()[-1] == "int g() { return 3; }"
    assert context.source_snippet(SRC, 0x50).splitlines()[-1] == "int h();"
    assert context.source_snippet(SRC, 0x99) is None


def test_class_names():
    assert context.class_names("_ZNK5field7content23HaxeSymbolPokemonObject10GetMotion1Ev") == [
        "field", "content", "HaxeSymbolPokemonObject"]
    assert context.class_names("_ZN11Unk_23f46604initEv") == ["Unk_23f4660"]
    assert context.class_names("_ZTV11Unk_23f4660") == ["Unk_23f4660"]
    assert context.class_names("_Z3foov") == []
    assert context.class_names("getfield@lauxlib") == []


def test_rank_similar():
    target = [1 << 22, 2 << 22, 3 << 22, 4 << 22]
    cands = [(0x10, [9 << 22, 9 << 22]), (0x20, list(target)), (0x30, [1 << 22, 2 << 22, 3 << 22, 5 << 22])]
    best = context.rank_similar(target, cands, n=2)
    assert [a for _, a in best] == [0x20, 0x30]
    assert best[0][0] == 1.0


def test_ghidra_path(tmp_path: Path):
    assert context.ghidra_path("sword", 0xbc0b00, tmp_path) == tmp_path / "sword" / "7100bc0b00.c"
