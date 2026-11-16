from __future__ import annotations

import json
import xml.etree.ElementTree as ET

import pytest

import progress
from common import read_functions_csv
from progress_svg import GREENS, EMPTY, badge, build_cells, cell_color, fmt_pct, squarify, treemap

SVG = "{http://www.w3.org/2000/svg}"


@pytest.fixture
def areas(write_csv):
    path = write_csv("areas.csv", (
        "Start,End,Area,Kind,Confidence,Evidence\n"
        "0x7100000000,0x7100001000,lib,library,high,x\n"
        "0x7100001000,0x7100002000,game,game,low,y\n"
    ))
    return progress.load_areas(path)


@pytest.fixture
def funcs(functions_csv):
    return read_functions_csv(functions_csv(
        "0x0000007100000000,64,0x0000007100000000,64,common,O,_ZN1a1fEv",
        "0x0000007100000040,64,0x0000007100000040,64,common,U,",
        "0x0000007100001000,128,0x0000007100001010,128,common,U,",
        "0x0000007100001080,32,0x0000007100001090,32,diverged,O,_ZN1b1gEv",
        "0x0000007100005000,16,0x0000007100005000,16,common,m,",  # outside every area
    ))


@pytest.mark.parametrize("pct, text", [
    (0.0, "0.00%"), (0.004, "<0.01%"), (12.345, "12.35%"), (99.995, ">99.99%"), (100.0, "100.00%"),
])
def test_fmt_pct_never_rounds_to_zero_or_hundred(pct, text):
    assert fmt_pct(pct) == text


def test_squarify_tiles_the_rectangle_in_order():
    sizes = [5, 0, 3, 3, 2, 1, 1, 8]
    rects = squarify(sizes, 10, 20, 300, 200)
    assert len(rects) == len(sizes)
    for s, (x, y, w, h) in zip(sizes, rects):
        assert x >= 10 - 1e-6 and y >= 20 - 1e-6 and x + w <= 310 + 1e-6 and y + h <= 220 + 1e-6
        assert w * h == pytest.approx(s / sum(sizes) * 300 * 200)


def test_squarify_degenerate_inputs():
    assert squarify([], 0, 0, 10, 10) == []
    assert squarify([0, 0], 0, 0, 10, 10) == [(0, 0, 0.0, 0.0)] * 2


def test_cells_respect_areas_and_target(funcs, areas):
    area_of, names = areas
    cells = build_cells(funcs, area_of, names, target_bytes=64)
    assert list(cells) == ["lib", "game", "unassigned"]
    assert [(c.functions, c.bytes, c.matching_bytes) for c in cells["lib"]] == [(1, 64, 64), (1, 64, 0)]
    # The 128-byte function is a cell of its own; a cell never crosses into another area.
    assert [(c.functions, c.bytes, c.matching) for c in cells["game"]] == [(1, 128, 0), (1, 32, 1)]
    assert sum(c.bytes for cs in cells.values() for c in cs) == 64 + 64 + 128 + 32 + 16


def test_cell_color_scale():
    assert cell_color(0) == EMPTY
    assert cell_color(1) == GREENS[-1]
    assert cell_color(1e-9) != EMPTY  # any progress shows up
    assert cell_color(0.5) not in (EMPTY, GREENS[-1])


def test_badge_is_valid_svg_sized_to_text():
    root = ET.fromstring(badge("Sword", ["<0.01% code", "4 / 104,005 functions"]))
    texts = [t.text for t in root.iter(f"{SVG}text")]
    assert "<0.01% code" in texts and "Sword" in texts
    widths = [int(r.get("width")) for r in root.find(f"{SVG}g").iter(f"{SVG}rect") if r.get("fill") != "#000"]
    assert sum(widths[:3]) == int(root.get("width"))


def test_treemap_is_valid_svg_with_one_rect_per_cell(funcs, areas):
    area_of, names = areas
    root = ET.fromstring(treemap(funcs, area_of, names, cells=1000))
    cells = [r for r in root.iter(f"{SVG}rect") if r.find(f"{SVG}title") is not None]
    assert len(cells) == 5  # target rounds down to 1 byte: every function is its own cell
    fills = sorted(r.get("fill") for r in cells)
    assert fills.count(GREENS[-1]) == 2 and fills.count(EMPTY) == 3


def test_write_svgs(tmp_path, funcs, areas):
    area_of, names = areas
    paths = progress.write_svgs(tmp_path / "out", funcs, area_of, names)
    assert sorted(p.name for p in paths) == ["progress.json", "shield.svg", "sword.svg", "treemap.svg"]
    for p in paths:
        assert b"\r\n" not in p.read_bytes()
        if p.suffix == ".svg":
            ET.fromstring(p.read_text(encoding="utf-8"))
    data = json.loads((tmp_path / "out" / "progress.json").read_text(encoding="utf-8"))
    assert data["games"]["sword"]["matching_functions"] == 2
    assert data["games"]["sword"]["matching_bytes"] == 96
    assert "2 / 5 functions" in (tmp_path / "out" / "shield.svg").read_text(encoding="utf-8")
