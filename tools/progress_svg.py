"""SVG progress images for the README: one badge per game and a treemap.

Written by `tools/progress.py --svg DIR`. CI runs that on every push to master
and publishes the files to the `progress` branch (.github/workflows/progress.yml),
so nobody commits generated images and PRs never conflict over them.

One treemap covers both games. Each function is drawn once, at its own game's
address, size and area: Sword's for every function in Sword, Shield's for
Shield-only ones, each looked up in that game's columns of data/areas.csv.
tools/lint.py makes every function land in the same area in both games, and
the status column is shared, so a per-game map would look the same.

Standard library only: the progress workflow doesn't install anything.
"""
from __future__ import annotations

from dataclasses import dataclass
from xml.sax.saxutils import escape

from common import BASE, VERSIONS, Area, AreaMap, Function

# --------------------------------------------------------------------------- formatting


def fmt_pct(p: float) -> str:
    """Two decimals, but never round real progress down to "0.00%" or up to "100.00%"."""
    if 0 < p < 0.01:
        return "<0.01%"
    if 99.99 < p < 100:
        return ">99.99%"
    return f"{p:.2f}%"


def fmt_kb(n: int) -> str:
    return f"{n / 1024:,.0f} KB" if n >= 1024 else f"{n} B"


# --------------------------------------------------------------------------- badges

# Approximate advance widths of 11px Verdana (the shields.io badge font), so the
# badge segments fit their text without measuring it in a browser.
_NARROW = set("fijlrtI.,:;!|'()[] ")
_WIDE = set("mwMW%@")


def text_width(s: str) -> float:
    w = 0.0
    for c in s:
        if c in _NARROW:
            w += 3.9
        elif c in _WIDE:
            w += 10.5
        elif c.isupper() or c.isdigit() or c in "<>~#&?+=_-/":
            w += 7.2 if c.isupper() else 7.0
        else:
            w += 6.3
    return w


LABEL_BG = "#555"
VALUE_BG = "#0e7bbd"
DONE_BG = "#2ea44f"


def badge(label: str, values: list[str], *, done: bool = False) -> str:
    """A flat shields.io-style badge: a grey label followed by one segment per value."""
    texts = [label, *values]
    widths = [round(text_width(t) + 12) for t in texts]
    fills = [LABEL_BG] + [DONE_BG if done else VALUE_BG] * len(values)
    total, h = sum(widths), 20
    rects, texts_svg = [], []
    x = 0
    for i, (t, w, fill) in enumerate(zip(texts, widths, fills)):
        rects.append(f'<rect x="{x}" width="{w}" height="{h}" fill="{fill}"/>')
        if i > 1:  # thin separator between value segments
            rects.append(f'<rect x="{x}" width="1" height="{h}" fill="#000" fill-opacity=".25"/>')
        cx = x + w / 2
        texts_svg.append(f'<text x="{cx:g}" y="15" fill="#010101" fill-opacity=".3">{escape(t)}</text>')
        texts_svg.append(f'<text x="{cx:g}" y="14">{escape(t)}</text>')
        x += w
    title = escape(f"{label}: {', '.join(values)}")
    return (
        f'<svg xmlns="http://www.w3.org/2000/svg" width="{total}" height="{h}" role="img" aria-label="{title}">'
        f"<title>{title}</title>"
        '<linearGradient id="s" x2="0" y2="100%"><stop offset="0" stop-color="#bbb" stop-opacity=".1"/>'
        '<stop offset="1" stop-opacity=".1"/></linearGradient>'
        f'<clipPath id="r"><rect width="{total}" height="{h}" rx="3" fill="#fff"/></clipPath>'
        f'<g clip-path="url(#r)">{"".join(rects)}'
        f'<rect width="{total}" height="{h}" fill="url(#s)"/></g>'
        '<g fill="#fff" text-anchor="middle" font-family="Verdana,Geneva,DejaVu Sans,sans-serif" '
        f'text-rendering="geometricPrecision" font-size="11">{"".join(texts_svg)}</g></svg>\n'
    )


# --------------------------------------------------------------------------- treemap layout


def squarify(sizes: list[float], x: float, y: float, w: float, h: float) -> list[tuple[float, float, float, float]]:
    """Squarified treemap (Bruls et al.) that keeps the input order.

    Returns one (x, y, w, h) per size, tiling the rectangle exactly. Not sorting
    keeps neighbouring addresses next to each other on the map."""
    total = sum(s for s in sizes if s > 0)
    if total <= 0 or w <= 0 or h <= 0:
        return [(x, y, 0.0, 0.0) for _ in sizes]
    scale = w * h / total
    vals = [s * scale for s in sizes if s > 0]
    placed: list[tuple[float, float, float, float]] = []

    def worst(row: list[float], side: float) -> float:
        s2, side2 = sum(row) ** 2, side * side
        return max(side2 * max(row) / s2, s2 / (side2 * min(row)))

    row: list[float] = []
    for v in vals:
        if row and worst(row + [v], min(w, h)) > worst(row, min(w, h)):
            x, y, w, h = _place_row(row, x, y, w, h, placed)
            row = []
        row.append(v)
    if row:
        _place_row(row, x, y, w, h, placed, last=True)
    # Zero-sized inputs get an empty rect so the output lines up with `sizes`.
    it = iter(placed)
    return [next(it) if s > 0 else (x, y, 0.0, 0.0) for s in sizes]


def _place_row(row, x, y, w, h, out, last=False):
    s = sum(row)
    if w >= h:  # column along the left edge
        cw = w if last else (s / h if h else 0.0)
        cy = y
        for r in row:
            rh = r / cw if cw else 0.0
            out.append((x, cy, cw, rh))
            cy += rh
        return x + cw, y, w - cw, h
    rh = h if last else (s / w if w else 0.0)  # row along the top edge
    cx = x
    for r in row:
        rw = r / rh if rh else 0.0
        out.append((cx, y, rw, rh))
        cx += rw
    return x, y + rh, w, h - rh


# --------------------------------------------------------------------------- treemap content


@dataclass
class Cell:
    """A run of consecutive functions of one game inside one area: one rectangle on the map."""
    area: str
    game: str  # whose addresses start/end are: "sword", or "shield" for Shield-only functions
    start: int  # address of the first function (relative to BASE)
    end: int  # end of the last function
    functions: int = 0
    bytes: int = 0
    matching: int = 0
    matching_bytes: int = 0

    @property
    def fraction(self) -> float:
        return self.matching_bytes / self.bytes if self.bytes else 0.0


def place(funcs: list[Function], areas: list[Area]) -> list[tuple[str, str, int, int, str]]:
    """(area, game, address, size, status) of each function, in the first game it exists in.

    The address is relative to BASE and the area comes from that game's columns
    of data/areas.csv ("unassigned" outside every area)."""
    maps = {v: AreaMap(areas, v) for v in VERSIONS}
    out = []
    for f in funcs:
        v = next((v for v in VERSIONS if f.in_version(v)), None)
        if v is None:
            continue
        addr = f.addr(v)
        out.append((maps[v].area_of(addr) or "unassigned", v, addr, f.size(v) or 0, f.status))
    return out


def build_cells(funcs: list[Function], areas: list[Area], target_bytes: int) -> dict[str, list[Cell]]:
    """Group functions, in address order, into cells of about `target_bytes` each.

    Areas come in data/areas.csv order, then "unassigned". A cell never spans
    two areas or mixes Sword and Shield addresses. A function larger than the
    target is a cell of its own."""
    by_area: dict[str, list[tuple[int, str, int, str]]] = {}
    for area, game, addr, size, status in place(funcs, areas):
        if size:
            by_area.setdefault(area, []).append((addr, game, size, status))
    area_order = [a.name for a in areas]
    order = list(dict.fromkeys(area_order + sorted(set(by_area) - set(area_order))))
    out: dict[str, list[Cell]] = {}
    for area in order:
        items = sorted(by_area.get(area, ()))
        cells: list[Cell] = []
        cur: Cell | None = None
        for addr, game, size, status in items:
            if (cur is None or cur.game != game or cur.bytes >= target_bytes
                    or (cur.bytes and cur.bytes + size > 2 * target_bytes)):
                cur = Cell(area, game, addr, addr)
                cells.append(cur)
            cur.end = addr + size
            cur.functions += 1
            cur.bytes += size
            if status == "O":
                cur.matching += 1
                cur.matching_bytes += size
        if cells:
            out[area] = cells
    return out


EMPTY = "#2d333b"
# GitHub's contribution-graph greens: anything above 0% is visibly green.
GREENS = ["#0e4429", "#006d32", "#26a641", "#39d353"]
PANEL = "#0d1117"
GRID = "#0d1117"
TEXT = "#e6edf3"
MUTED = "#8b949e"


def _hex(c: str) -> tuple[int, int, int]:
    return int(c[1:3], 16), int(c[3:5], 16), int(c[5:7], 16)


def cell_color(fraction: float) -> str:
    if fraction <= 0:
        return EMPTY
    if fraction >= 1:
        return GREENS[-1]
    t = fraction * (len(GREENS) - 1)
    i = min(int(t), len(GREENS) - 2)
    a, b = _hex(GREENS[i]), _hex(GREENS[i + 1])
    k = t - i
    return "#" + "".join(f"{round(p + (q - p) * k):02x}" for p, q in zip(a, b))


def _n(v: float) -> str:
    return f"{v:.1f}".rstrip("0").rstrip(".")


def treemap(funcs: list[Function], areas: list[Area], *,
            width: int = 1000, height: int = 500, cells: int = 1500) -> str:
    """Treemap of the whole executable: areas, then runs of functions, sized by code bytes."""
    total = sum(size for _, _, _, size, _ in place(funcs, areas))
    target = max(1, total // max(1, cells))
    groups = build_cells(funcs, areas, target)
    # Squarify lays out big items first. Sorting by size class (stable) puts the
    # few oversized functions first and keeps ordinary cells in address order.
    groups = {a: sorted(cs, key=lambda c: -round(c.bytes / target)) for a, cs in groups.items()}
    pad, legend_h = 8, 28
    mx, my, mw, mh = pad, pad, width - 2 * pad, height - 2 * pad - legend_h
    names = list(groups)
    area_rects = squarify([sum(c.bytes for c in groups[a]) for a in names], mx, my, mw, mh)

    body, outlines, labels = [], [], []
    for area, (ax, ay, aw, ah) in zip(names, area_rects):
        cs = groups[area]
        for c, (x, y, w, h) in zip(cs, squarify([c.bytes for c in cs], ax, ay, aw, ah)):
            where = "" if c.game == VERSIONS[0] else f"{c.game.capitalize()} only, "
            tip = (f"{area} · {where}0x{c.start + BASE:x}–0x{c.end + BASE:x} · {fmt_kb(c.bytes)}\n"
                   f"{c.matching} / {c.functions:,} functions matching · {fmt_pct(100 * c.fraction)} of code")
            body.append(f'<rect x="{_n(x)}" y="{_n(y)}" width="{_n(w)}" height="{_n(h)}" '
                        f'fill="{cell_color(c.fraction)}"><title>{escape(tip)}</title></rect>')
        outlines.append(f'<rect x="{_n(ax)}" y="{_n(ay)}" width="{_n(aw)}" height="{_n(ah)}"/>')
        name = area
        if aw >= text_width(name) * 1.05 + 10 and ah >= 20:
            labels.append(f'<text x="{_n(ax + 5)}" y="{_n(ay + 15)}">{escape(name)}</text>')

    ly = height - pad - 9
    legend = [
        (EMPTY, "not matching yet"), (GREENS[0], "partly matching"), (GREENS[-1], "matching"),
    ]
    lg, lx = [], pad
    for color, text in legend:
        lg.append(f'<rect x="{lx}" y="{ly - 9}" width="10" height="10" rx="2" fill="{color}"/>')
        lg.append(f'<text x="{lx + 15}" y="{ly}">{escape(text)}</text>')
        lx += 15 + round(text_width(text) * 0.95) + 18
    note = "Each cell is a run of neighbouring functions, sized by code; grouped by area (data/areas.csv)"
    lg.append(f'<text x="{width - pad}" y="{ly}" text-anchor="end">{escape(note)}</text>')

    return (
        f'<svg xmlns="http://www.w3.org/2000/svg" width="{width}" height="{height}" '
        f'viewBox="0 0 {width} {height}" role="img" aria-label="Decompilation progress treemap">'
        "<title>Decompilation progress treemap</title>"
        f'<rect width="{width}" height="{height}" rx="8" fill="{PANEL}"/>'
        f'<g stroke="{GRID}" stroke-width=".6">{"".join(body)}</g>'
        f'<g fill="none" stroke="{PANEL}" stroke-width="2">{"".join(outlines)}</g>'
        f'<g fill="{TEXT}" font-family="Verdana,Geneva,DejaVu Sans,sans-serif" font-size="11" '
        f'font-weight="bold" stroke="{PANEL}" stroke-width="3" paint-order="stroke">{"".join(labels)}</g>'
        f'<g fill="{MUTED}" font-family="Verdana,Geneva,DejaVu Sans,sans-serif" font-size="10">{"".join(lg)}</g>'
        "</svg>\n"
    )
