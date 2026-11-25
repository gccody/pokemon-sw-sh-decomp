"""tools/autoname.py: the one-row-per-name rule (no game files)."""
from __future__ import annotations

from common import Function

import autoname


def fn(addr: int) -> Function:
    return Function(addr, addr, 8, 8, "common", "U", "")


def test_unique_matches():
    a, b, c = fn(0x10), fn(0x20), fn(0x30)
    candidates = {"_Z1fv": [a, b], "_Z1gv": [c], "_Z1hv": [a, c], "_Z1iv": [b]}
    good = {("_Z1fv", 0x10), ("_Z1gv", 0x30), ("_Z1hv", 0x10), ("_Z1hv", 0x30), ("_Z1iv", 0x20)}
    found = autoname.unique_matches(candidates, lambda n, r: (n, r.sword) in good)
    # _Z1hv matches two rows, so it gets none; a row that is only another name's
    # candidate isn't claimed by it
    assert {n: r.sword for n, r in found.items()} == {"_Z1fv": 0x10, "_Z1gv": 0x30, "_Z1iv": 0x20}


def test_two_names_one_row_drops_both():
    a = fn(0x10)
    found = autoname.unique_matches({"_Z1fv": [a], "_Z1gv": [a]}, lambda n, r: True)
    assert found == {}
