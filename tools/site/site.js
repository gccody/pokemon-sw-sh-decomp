// Progress site for tools/progress_site.py: reads data/summary.json,
// data/history.json and data/functions/<n>.json. No external resources.
(function () {
  "use strict";

  var BASE = 0x7100000000;
  var STATUS_INFO = {
    O: { label: "Matching", desc: "matches the original exactly" },
    m: { label: "Minor diff", desc: "regalloc/ordering differences" },
    M: { label: "Major diff", desc: "non-matching" },
    U: { label: "Not started", desc: "not decompiled yet" },
    L: { label: "Library", desc: "decompiled elsewhere / not our code" },
  };
  var KINDS = [
    { key: "library", label: "Third-party libraries", short: "Libraries",
      desc: "PhysX, Wwise, YEBIS, Protocol Buffers, Lua, libcurl, NintendoWare, the nn SDK…" },
    { key: "gflib", label: "Game Freak libraries", short: "GF libraries",
      desc: "Startup, gflib3 and gflnet3: Game Freak's own engine and network libraries." },
    { key: "game", label: "Game code", short: "Game code",
      desc: "The game itself, split into subsystems (game/<subsystem>; game/unk_<address> isn't placed yet)." },
    { key: "unassigned", label: "Unassigned", short: "Unassigned",
      desc: "Functions outside every range of data/areas.csv." },
  ];
  var GAMES = ["sword", "shield"];
  var GAME_LABEL = { sword: "Sword", shield: "Shield" };
  var PAGE = 250;

  var S = null;          // summary.json
  var H = null;          // history.json (loaded on demand)
  var historyPromise = null;
  var fileCache = {};    // area index -> Promise<rows>
  var game = store("game") === "shield" ? "shield" : "sword";
  var app = document.getElementById("app");
  var tip = document.getElementById("tooltip");

  // ------------------------------------------------------------------ helpers
  function store(k, v) {
    try {
      if (v === undefined) return window.localStorage.getItem("pkmn-progress-" + k);
      window.localStorage.setItem("pkmn-progress-" + k, v);
    } catch (e) { /* private mode, blocked storage */ }
    return null;
  }
  function esc(s) {
    return String(s).replace(/[&<>"']/g, function (c) {
      return { "&": "&amp;", "<": "&lt;", ">": "&gt;", '"': "&quot;", "'": "&#39;" }[c];
    });
  }
  function el(tag, cls, html) {
    var e = document.createElement(tag);
    if (cls) e.className = cls;
    if (html !== undefined) e.innerHTML = html;
    return e;
  }
  function fmtInt(n) { return Number(n).toLocaleString("en-US"); }
  function fmtBytes(b) {
    if (b < 1024) return b + " B";
    if (b < 1024 * 1024) return (b / 1024).toFixed(b < 10240 ? 1 : 0) + " KB";
    return (b / 1024 / 1024).toFixed(2) + " MB";
  }
  // Like tools/progress_svg.py's fmt_pct: never shows 0% or 100% unless exact.
  function fmtPct(p) {
    if (!isFinite(p)) return "–";
    if (p <= 0) return "0%";
    if (p >= 100) return "100%";
    var d = p < 1 || p > 99 ? 3 : 2;
    var s = p.toFixed(d);
    if (Number(s) === 0) s = "<0." + "0".repeat(d - 1) + "1";
    if (Number(s) >= 100) s = ">99." + "9".repeat(d);
    return s + "%";
  }
  function hex(a) { return "0x" + (a + BASE).toString(16); }
  function absHex(a) { return "0x" + a.toString(16); }
  function dateOnly(iso) { return iso ? iso.slice(0, 10) : ""; }
  function parseDate(iso) { return new Date(iso).getTime(); }
  function plural(n, w) { return fmtInt(n) + " " + w + (n === 1 ? "" : "s"); }
  function repo() { return S.source && S.source.repo; }
  function commitUrl(sha) { return repo() ? repo() + "/commit/" + sha : null; }

  // counts: [n per status..., bytes per status...]
  function C(counts) {
    var n = 0, b = 0, ns = S.statuses.length;
    for (var i = 0; i < ns; i++) { n += counts[i]; b += counts[ns + i]; }
    var o = S.statuses.indexOf("O");
    return {
      n: n, bytes: b, doneN: counts[o], doneB: counts[ns + o],
      pct: b ? 100 * counts[ns + o] / b : 0, pctN: n ? 100 * counts[o] / n : 0,
      st: function (s) { var i = S.statuses.indexOf(s); return { n: counts[i], b: counts[ns + i] }; },
    };
  }
  function addCounts(a, b) { for (var i = 0; i < a.length; i++) a[i] += b[i]; return a; }
  function zero() { var z = []; for (var i = 0; i < 2 * S.statuses.length; i++) z.push(0); return z; }

  function statusBar(counts, thin) {
    var c = C(counts), html = "";
    if (!c.bytes) return '<div class="bar' + (thin ? " thin" : "") + '"></div>';
    S.statuses.forEach(function (s) {
      var x = c.st(s);
      if (!x.b || s === "U") return;
      html += '<span class="s-' + s + '" style="width:' + (100 * x.b / c.bytes).toFixed(3) + '%" title="' +
        esc(STATUS_INFO[s].label + ": " + plural(x.n, "function") + ", " + fmtBytes(x.b)) + '"></span>';
    });
    return '<div class="bar' + (thin ? " thin" : "") + '">' + html + "</div>";
  }
  function legend(counts) {
    var c = C(counts);
    return '<div class="legend">' + S.statuses.map(function (s) {
      var x = c.st(s);
      if (!x.n && s !== "O" && s !== "U") return "";
      return '<span title="' + esc(STATUS_INFO[s].desc) + '"><span class="dot s-' + s + '"></span> ' +
        STATUS_INFO[s].label + " <b>" + fmtInt(x.n) + "</b></span>";
    }).join("") + "</div>";
  }
  function badge(s) {
    return '<span class="badge s-' + s + '" title="' + esc(STATUS_INFO[s] ? STATUS_INFO[s].label : s) + '">' + esc(s) + "</span>";
  }
  function confTag(c) { return c ? '<span class="tag ' + esc(c) + '" title="confidence of the area boundary">' + esc(c) + "</span>" : ""; }
  function kindOf(key) { return KINDS.filter(function (k) { return k.key === key; })[0] || KINDS[3]; }
  function moduleLink(i) { return "#/module/" + i; }

  function loadJSON(url) {
    return fetch(url, { cache: "no-cache" }).then(function (r) {
      if (!r.ok) throw new Error(url + ": HTTP " + r.status);
      return r.json();
    });
  }
  function loadFunctions(i) {
    if (!fileCache[i]) fileCache[i] = loadJSON(S.areas[i].file);
    return fileCache[i];
  }
  function loadHistory() {
    if (!historyPromise) {
      historyPromise = loadJSON("data/history.json").then(function (h) { H = prepareHistory(h); return H; });
    }
    return historyPromise;
  }

  // ------------------------------------------------------------------ history model
  // history.json points carry full game totals and only the areas that changed;
  // rebuild per-area and per-kind series once per game.
  function prepareHistory(h) {
    var byName = {};
    S.areas.forEach(function (a, i) { byName[a.name] = i; });
    h.areaToSummary = h.areas.map(function (n) { return byName[n] === undefined ? -1 : byName[n]; });
    h.series = {};
    h.points.forEach(function (p) { p.t = parseDate(p.date); });
    return h;
  }
  function historySeries(g) {
    if (H.series[g]) return H.series[g];
    var cur = {}, kinds = {}, perArea = {}, deltas = [];
    KINDS.forEach(function (k) { kinds[k.key] = []; });
    var ns = S.statuses.length, o = S.statuses.indexOf("O");
    H.points.forEach(function (p, pi) {
      var ch = (p.areas && p.areas[g]) || {}, d = [];
      Object.keys(ch).forEach(function (hk) {
        var si = H.areaToSummary[Number(hk)];
        var prev = cur[hk] || zero();
        var next = ch[hk];
        d.push({ area: si, name: H.areas[Number(hk)], dN: next[o] - prev[o], dB: next[ns + o] - prev[ns + o] });
        cur[hk] = next;
        if (si >= 0) (perArea[si] = perArea[si] || []).push(pi);
      });
      d.sort(function (a, b) { return Math.abs(b.dB) - Math.abs(a.dB); });
      deltas.push(d);
      var sums = {};
      KINDS.forEach(function (k) { sums[k.key] = zero(); });
      Object.keys(cur).forEach(function (hk) {
        var si = H.areaToSummary[Number(hk)];
        var kind = si >= 0 ? S.areas[si].kind : "unassigned";
        addCounts(sums[kind] || sums.unassigned, cur[hk]);
      });
      KINDS.forEach(function (k) { kinds[k.key].push(sums[k.key]); });
    });
    H.series[g] = { kinds: kinds, perArea: perArea, deltas: deltas };
    return H.series[g];
  }
  // [{t, counts, p}] for one summary area in game g, one entry per point.
  function areaSeries(g, si) {
    var target = S.areas[si].name, hk = H.areas.indexOf(target), cur = zero(), out = [];
    H.points.forEach(function (p) {
      var ch = p.areas && p.areas[g];
      if (ch && ch[hk]) cur = ch[hk];
      out.push({ t: p.t, counts: cur, p: p });
    });
    return out;
  }

  // ------------------------------------------------------------------ chart
  // series: [{label, color, values: [number|null]}] over shared points [{t, p}].
  function lineChart(container, points, series, opts) {
    opts = opts || {};
    var box = el("div", "chart");
    var lg = el("div", "chart-legend", series.map(function (s) {
      return '<span><i style="background:' + s.color + (s.dash ? ";opacity:.7" : "") + '"></i>' + esc(s.label) + "</span>";
    }).join(""));
    container.appendChild(lg);
    container.appendChild(box);
    if (!points.length) { box.innerHTML = '<p class="muted">No history yet.</p>'; return; }

    function draw() {
      var W = Math.max(280, box.clientWidth || 600), Hh = opts.height || 240;
      var pad = { l: 46, r: 12, t: 10, b: 24 };
      var t0 = points[0].t, t1 = points[points.length - 1].t;
      if (t1 <= t0) t1 = t0 + 86400000;
      var yMax = 0;
      series.forEach(function (s) { s.values.forEach(function (v) { if (v != null && v > yMax) yMax = v; }); });
      yMax = niceMax(opts.yMax != null ? Math.max(opts.yMax, yMax) : yMax);
      function X(t) { return pad.l + (W - pad.l - pad.r) * (t - t0) / (t1 - t0); }
      function Y(v) { return pad.t + (Hh - pad.t - pad.b) * (1 - v / yMax); }
      var svg = '<svg viewBox="0 0 ' + W + " " + Hh + '" width="' + W + '" height="' + Hh + '" role="img" aria-label="' + esc(opts.label || "chart") + '">';
      for (var i = 0; i <= 4; i++) {
        var v = yMax * i / 4, y = Y(v);
        svg += '<line class="grid-line" x1="' + pad.l + '" x2="' + (W - pad.r) + '" y1="' + y + '" y2="' + y + '"/>';
        svg += '<text class="axis" x="' + (pad.l - 6) + '" y="' + (y + 4) + '" text-anchor="end">' + esc((opts.fmtAxis || fmtPctAxis)(v)) + "</text>";
      }
      var ticks = timeTicks(t0, t1, Math.max(2, Math.floor((W - pad.l - pad.r) / 90)));
      ticks.forEach(function (t) {
        svg += '<text class="axis" x="' + X(t) + '" y="' + (Hh - 6) + '" text-anchor="middle">' + esc(fmtTick(t, t1 - t0)) + "</text>";
      });
      series.forEach(function (s) {
        var d = "", started = false;
        s.values.forEach(function (v, i) {
          if (v == null) return;
          var x = X(points[i].t).toFixed(1), y = Y(v).toFixed(1);
          // Step line: progress holds until the next commit.
          if (!started) { d += "M" + x + " " + y; started = true; }
          else { d += "H" + x + "V" + y; }
        });
        if (started) d += "H" + (W - pad.r);
        svg += '<path d="' + d + '" fill="none" stroke="' + s.color + '" stroke-width="2" stroke-linejoin="round"' + (s.dash ? ' stroke-dasharray="6 4"' : "") + "/>";
      });
      svg += '<line class="hover-line" x1="0" x2="0" y1="' + pad.t + '" y2="' + (Hh - pad.b) + '" visibility="hidden"/>';
      svg += '<rect x="' + pad.l + '" y="0" width="' + (W - pad.l - pad.r) + '" height="' + Hh + '" fill="transparent"/>';
      svg += "</svg>";
      box.innerHTML = svg;
      var svgEl = box.firstChild, hl = svgEl.querySelector(".hover-line");
      function at(ev) {
        var r = svgEl.getBoundingClientRect();
        var x = (ev.clientX - r.left) * (W / r.width);
        var t = t0 + (x - pad.l) / (W - pad.l - pad.r) * (t1 - t0);
        // the last point at or before t
        var lo = 0, hi = points.length - 1;
        while (lo < hi) { var mid = (lo + hi + 1) >> 1; if (points[mid].t <= t) lo = mid; else hi = mid - 1; }
        return lo;
      }
      svgEl.addEventListener("mousemove", function (ev) {
        var i = at(ev), p = points[i];
        hl.setAttribute("x1", X(p.t)); hl.setAttribute("x2", X(p.t)); hl.setAttribute("visibility", "visible");
        var rows = series.map(function (s) {
          var v = s.values[i];
          return '<div class="t-row"><span><i class="dot" style="background:' + s.color + '"></i> ' + esc(s.label) +
            "</span><b>" + (v == null ? "–" : esc((opts.fmt || fmtPct)(v))) + "</b></div>";
        }).join("");
        showTip(ev, '<div><b>' + esc(dateOnly(p.p.date)) + "</b> <span class=\"mono\">" + esc(p.p.sha.slice(0, 8)) +
          '</span></div><div class="t-sub">' + esc(p.p.subject) + "</div>" + rows);
      });
      svgEl.addEventListener("mouseleave", function () { hl.setAttribute("visibility", "hidden"); hideTip(); });
      svgEl.addEventListener("click", function (ev) {
        var url = commitUrl(points[at(ev)].p.sha);
        if (url) window.open(url, "_blank", "noopener");
      });
      svgEl.style.cursor = repo() ? "pointer" : "default";
    }
    draw();
    var w = box.clientWidth;
    var ro = window.ResizeObserver ? new ResizeObserver(function () {
      if (box.clientWidth !== w) { w = box.clientWidth; draw(); }
    }) : null;
    if (ro) ro.observe(box);
  }
  function niceMax(v) {
    if (v <= 0) return 1;
    var steps = [0.01, 0.02, 0.05, 0.1, 0.2, 0.25, 0.5, 1, 2, 2.5, 5, 10, 20, 25, 40, 50, 60, 80, 100];
    for (var i = 0; i < steps.length; i++) if (steps[i] >= v) return steps[i];
    var m = Math.pow(10, Math.ceil(Math.log10(v)));
    return v <= m / 2 ? m / 2 : m;
  }
  function fmtPctAxis(v) { return (v >= 1 ? Math.round(v * 10) / 10 : Number(v.toPrecision(2))) + "%"; }
  function timeTicks(t0, t1, n) {
    var span = t1 - t0, day = 86400000;
    var steps = [3600000, 6 * 3600000, 12 * 3600000, day, 2 * day, 7 * day, 14 * day, 30 * day, 91 * day, 182 * day, 365 * day];
    var step = steps[steps.length - 1];
    for (var i = 0; i < steps.length; i++) if (span / steps[i] <= n) { step = steps[i]; break; }
    var out = [], tz = new Date(t0).getTimezoneOffset() * 60000;
    var start = step >= day ? Math.ceil((t0 - tz) / day) * day + tz : Math.ceil(t0 / step) * step;
    for (var t = start; t <= t1; t += step) out.push(t);
    return out;
  }
  function fmtTick(t, span) {
    var d = new Date(t);
    var mon = d.toLocaleString("en-US", { month: "short" });
    if (span < 2 * 86400000) return d.toLocaleTimeString("en-US", { hour: "numeric" });
    if (span > 300 * 86400000) return mon + " " + d.getFullYear();
    return mon + " " + d.getDate();
  }
  function showTip(ev, html) {
    tip.innerHTML = html;
    tip.hidden = false;
    var w = tip.offsetWidth, h = tip.offsetHeight;
    var x = ev.clientX + 14, y = ev.clientY + 14;
    if (x + w > window.innerWidth - 8) x = ev.clientX - w - 14;
    if (y + h > window.innerHeight - 8) y = ev.clientY - h - 14;
    tip.style.left = Math.max(8, x) + "px";
    tip.style.top = Math.max(8, y) + "px";
  }
  function hideTip() { tip.hidden = true; }

  // ------------------------------------------------------------------ pieces
  function kindTotals(g) {
    var out = {};
    KINDS.forEach(function (k) { out[k.key] = { counts: zero(), modules: 0 }; });
    S.areas.forEach(function (a) {
      var k = out[a.kind] || out.unassigned;
      addCounts(k.counts, a.counts[g]);
      if (C(a.counts[g]).n) k.modules++;
    });
    return out;
  }
  function gameCard(g) {
    var c = C(S.games[g]);
    return '<div class="panel card' + (g === game ? " active" : "") + '">' +
      '<div class="card-title"><span class="name"><span class="dot" style="background:var(--' + g + ')"></span> Pokémon ' +
      GAME_LABEL[g] + '</span><span class="muted small">' + fmtBytes(c.bytes) + " of code</span></div>" +
      '<div class="big">' + fmtPct(c.pct) + '</div><div class="muted">of code matching · ' + fmtInt(c.doneN) + " / " +
      fmtInt(c.n) + " functions (" + fmtPct(c.pctN) + ")</div>" + statusBar(S.games[g]) + legend(S.games[g]) + "</div>";
  }
  function activityList(points, deltasFor, limit) {
    var ul = el("ul", "activity");
    var shown = 0;
    for (var i = points.length - 1; i >= 0 && shown < limit; i--) {
      var p = points[i];
      if (!p.matched_n && !p.lost_n) continue;
      shown++;
      ul.appendChild(activityItem(p, deltasFor ? deltasFor[i] : null));
    }
    if (!shown) ul.innerHTML = '<li class="muted">No matching progress recorded yet.</li>';
    return ul;
  }
  function activityItem(p, deltas) {
    var li = el("li");
    var url = commitUrl(p.sha);
    var sha = '<span class="mono">' + esc(p.sha.slice(0, 8)) + "</span>";
    var delta = (p.matched_n ? '<span class="plus">+' + fmtInt(p.matched_n) + "</span>" : "") +
      (p.lost_n ? ' <span class="minus">−' + fmtInt(p.lost_n) + "</span>" : "");
    var html = '<span class="when" title="' + esc(p.date) + '">' + esc(dateOnly(p.date)) + "</span>" +
      '<span class="subj">' + (url ? '<a href="' + esc(url) + '" target="_blank" rel="noopener">' + sha + "</a>" : sha) +
      " " + esc(p.subject) + "</span>" + '<span class="delta" title="functions that became matching (and stopped matching)">' + delta + "</span>";
    if (deltas && deltas.length) {
      html += '<span class="mods">' + deltas.filter(function (d) { return d.dN || d.dB; }).slice(0, 6).map(function (d) {
        var name = d.area >= 0 ? S.areas[d.area].name : d.name;
        var t = (d.dB >= 0 ? "+" : "−") + fmtBytes(Math.abs(d.dB)) + " matching in " + name;
        var inner = esc(name) + ' <span class="' + (d.dB >= 0 ? "plus" : "minus") + '">' + (d.dN >= 0 ? "+" : "−") + fmtInt(Math.abs(d.dN)) + "</span>";
        return d.area >= 0 ? '<a class="tag" href="' + moduleLink(d.area) + '" title="' + esc(t) + '">' + inner + "</a>"
          : '<span class="tag" title="' + esc(t) + '">' + inner + "</span>";
      }).join("") + "</span>";
    }
    if (p.matched && p.matched.length) {
      html += "<details><summary>Newly matching functions" + (p.matched_n > p.matched.length ? " (largest " + p.matched.length + " of " + fmtInt(p.matched_n) + ")" : "") +
        "</summary><ul>" + p.matched.map(function (n) { return '<li class="mono">' + esc(n) + "</li>"; }).join("") + "</ul></details>";
    }
    li.innerHTML = html;
    return li;
  }

  // ------------------------------------------------------------------ pages
  function pageOverview() {
    app.innerHTML = "";
    var head = el("div", "head-row", "<div><h1>Pokémon Sword &amp; Shield decompilation</h1><div class=\"muted\">A matching decompilation: " +
      "every function is compiled with clang 7.0.1 and checked against both original executables. " +
      "Progress is bytes of code in functions that match exactly.</div></div>");
    app.appendChild(head);
    var cards = el("div", "grid grid-2", GAMES.map(gameCard).join(""));
    cards.style.marginTop = "16px";
    app.appendChild(cards);

    app.appendChild(el("h2", "", "By kind of code <span class=\"muted small\">(" + GAME_LABEL[game] + ")</span>"));
    var kt = kindTotals(game);
    app.appendChild(el("div", "grid grid-3", KINDS.filter(function (k) { return C(kt[k.key].counts).n; }).map(function (k) {
      var c = C(kt[k.key].counts);
      return '<a class="panel card" href="#/modules?kind=' + k.key + '"><div class="card-title"><span class="name"><span class="dot" style="background:var(--k-' +
        k.key + ')"></span> ' + esc(k.label) + '</span><span class="muted small">' + plural(kt[k.key].modules, "module") + "</span></div>" +
        '<div class="mid">' + fmtPct(c.pct) + '</div><div class="muted small">' + fmtInt(c.doneN) + " / " + fmtInt(c.n) +
        " functions · " + fmtBytes(c.doneB) + " / " + fmtBytes(c.bytes) + "</div>" + statusBar(kt[k.key].counts) +
        '<div class="muted small">' + esc(k.desc) + "</div></a>";
    }).join("")));

    var hist = el("div", "grid grid-2");
    var chartPanel = el("div", "panel", "<h3>Progress over time</h3>");
    var actPanel = el("div", "panel", '<div class="head-row"><h3>Recent progress</h3><a class="small" href="#/history">Full history →</a></div>');
    hist.appendChild(chartPanel); hist.appendChild(actPanel);
    app.appendChild(el("h2", "", "History"));
    app.appendChild(hist);
    withHistory(chartPanel, function () {
      var pts = H.points.map(function (p) { return { t: p.t, p: p }; });
      lineChart(chartPanel, pts, GAMES.map(function (g) {
        return { label: GAME_LABEL[g] + " (code)", color: "var(--" + g + ")", dash: g === "shield", values: H.points.map(function (p) { return C(p.games[g]).pct; }) };
      }), { label: "Matching code over time" });
      actPanel.appendChild(activityList(H.points, historySeries(game).deltas, 6));
    }, actPanel);

    var tmHead = el("h2", "", "Map of the executable");
    app.appendChild(tmHead);
    var tm = el("div", "panel");
    tm.innerHTML = '<a href="treemap.svg" target="_blank" rel="noopener" title="Open the treemap (hover cells for details)">' +
      '<img class="treemap" src="treemap.svg" alt="Treemap of the executable: each cell is a run of neighbouring functions, sized by code and coloured by how much of it matches" loading="lazy"></a>' +
      '<p class="muted small">Each cell is a run of neighbouring functions, sized by code: grey means nothing matches yet, brighter green means more of it matches. Open it to see each cell\'s range on hover.</p>';
    // treemap.svg comes from tools/progress.py --svg; without it, drop the section.
    tm.querySelector("img").onerror = function () { tmHead.remove(); tm.remove(); };
    app.appendChild(tm);
  }

  function withHistory(target, fn, alsoTarget) {
    if (!S.history) {
      target.appendChild(el("p", "muted", "This build of the site has no history (tools/progress_site.py --no-history)."));
      if (alsoTarget) alsoTarget.appendChild(el("p", "muted", "—"));
      return;
    }
    var wait = el("p", "muted", "Loading history…");
    target.appendChild(wait);
    loadHistory().then(function () { wait.remove(); fn(); }, function (e) { wait.className = "err"; wait.textContent = String(e); });
  }

  var modState = { q: "", hideDone: false, showUnk: true, sort: "default", asc: false };
  function pageModules(params) {
    app.innerHTML = "";
    app.appendChild(el("div", "head-row", "<div><h1>Modules</h1><div class=\"muted\">Libraries and subsystems from " +
      '<span class="mono">data/areas.csv</span>, for ' + GAME_LABEL[game] + ". Click a module for its functions and history.</div></div>"));
    var ctr = el("div", "controls",
      '<input type="search" placeholder="Filter modules…" aria-label="Filter modules">' +
      '<label class="check"><input type="checkbox" data-k="hideDone"> Hide finished</label>' +
      '<label class="check"><input type="checkbox" data-k="showUnk"> Show unplaced game ranges (<span class="mono">unk_*</span>)</label>');
    app.appendChild(ctr);
    var body = el("div");
    app.appendChild(body);
    var q = ctr.querySelector("input[type=search]");
    q.value = modState.q;
    q.addEventListener("input", function () { modState.q = q.value; render(); });
    ctr.querySelectorAll("input[type=checkbox]").forEach(function (cb) {
      cb.checked = modState[cb.dataset.k];
      cb.addEventListener("change", function () { modState[cb.dataset.k] = cb.checked; render(); });
    });
    var cols = [
      { k: "name", label: "Module" },
      { k: "n", label: "Functions", num: true },
      { k: "bytes", label: "Code", num: true, cls: "hide-sm" },
      { k: "pct", label: "Matching code", prog: true },
      { k: "left", label: "Left", num: true, title: "bytes of code not matching yet" },
    ];
    function render() {
      body.innerHTML = "";
      var ql = modState.q.toLowerCase();
      KINDS.forEach(function (k) {
        var rows = [];
        S.areas.forEach(function (a, i) {
          if (a.kind !== k.key) return;
          var c = C(a.counts[game]);
          if (!c.n) return;
          if (ql && a.name.toLowerCase().indexOf(ql) < 0) return;
          if (modState.hideDone && c.doneB === c.bytes) return;
          if (!modState.showUnk && /(^|\/)unk_/.test(a.name)) return;
          rows.push({ i: i, a: a, c: c, name: a.name, n: c.n, bytes: c.bytes, pct: c.pct, left: c.bytes - c.doneB });
        });
        if (!rows.length) return;
        if (modState.sort !== "default") {
          rows.sort(function (x, y) {
            var a = x[modState.sort], b = y[modState.sort];
            var r = typeof a === "string" ? a.localeCompare(b) : a - b;
            return modState.asc ? r : -r;
          });
        }
        var tot = zero();
        rows.forEach(function (r) { addCounts(tot, r.a.counts[game]); });
        var tc = C(tot);
        var sec = el("section");
        sec.id = "kind-" + k.key;
        sec.innerHTML = '<div class="head-row"><h2><span class="dot" style="background:var(--k-' + k.key + ')"></span> ' + esc(k.label) +
          ' <span class="muted small">' + plural(rows.length, "module") + "</span></h2><span class=\"muted\"><b>" + fmtPct(tc.pct) + "</b> · " +
          fmtInt(tc.doneN) + " / " + fmtInt(tc.n) + " functions · " + fmtBytes(tc.bytes - tc.doneB) + " left</span></div>";
        var panel = el("div", "panel table-wrap");
        panel.style.padding = "0";
        var table = el("table");
        table.innerHTML = "<thead><tr>" + cols.map(function (c) {
          var sorted = modState.sort === c.k;
          return '<th class="sortable' + (c.num ? " num" : "") + (c.cls ? " " + c.cls : "") + (sorted ? " sorted" + (modState.asc ? " asc" : "") : "") +
            '" data-k="' + c.k + '"' + (c.title ? ' title="' + esc(c.title) + '"' : "") + ">" + c.label + "</th>";
        }).join("") + "</tr></thead>";
        var tb = el("tbody");
        tb.innerHTML = rows.map(function (r) {
          var unk = /(^|\/)unk_/.test(r.name);
          return "<tr" + (unk ? ' class="dim"' : "") + '><td><a href="' + moduleLink(r.i) + '">' + esc(r.name) + "</a> " + confTag(r.a.confidence) + "</td>" +
            '<td class="num">' + fmtInt(r.c.doneN) + ' <span class="muted">/ ' + fmtInt(r.c.n) + "</span></td>" +
            '<td class="num hide-sm">' + fmtBytes(r.bytes) + "</td>" +
            '<td class="prog"><div class="prog-cell">' + statusBar(r.a.counts[game], true) + '<span class="p">' + fmtPct(r.pct) + "</span></div></td>" +
            '<td class="num">' + (r.left ? fmtBytes(r.left) : '<span class="plus">done</span>') + "</td></tr>";
        }).join("");
        table.appendChild(tb);
        table.querySelectorAll("th.sortable").forEach(function (th) {
          th.addEventListener("click", function () {
            var key = th.dataset.k;
            if (modState.sort === key) {
              if (modState.asc === (key === "name")) { modState.asc = !modState.asc; }
              else { modState.sort = "default"; }
            } else { modState.sort = key; modState.asc = key === "name"; }
            render();
          });
        });
        panel.appendChild(table);
        sec.appendChild(panel);
        body.appendChild(sec);
      });
      if (!body.children.length) body.appendChild(el("p", "muted", "No modules match."));
    }
    render();
    if (params.kind) {
      var target = document.getElementById("kind-" + params.kind);
      if (target) target.scrollIntoView();
    }
  }

  function pageModule(i) {
    var a = S.areas[i];
    if (!a) { app.innerHTML = '<p class="err">No such module.</p>'; return; }
    app.innerHTML = "";
    var k = kindOf(a.kind);
    app.appendChild(el("div", "crumbs", '<a href="#/modules">Modules</a> › <a href="#/modules?kind=' + k.key + '">' + esc(k.label) + "</a>"));
    app.appendChild(el("div", "head-row", "<h1>" + esc(a.name) + " " + confTag(a.confidence) + "</h1>"));
    app.appendChild(el("div", "grid grid-2", GAMES.map(function (g) {
      var c = C(a.counts[g]);
      if (!c.n) return '<div class="panel muted">Not in ' + GAME_LABEL[g] + ".</div>";
      return '<div class="panel card' + (g === game ? " active" : "") + '"><div class="card-title"><span class="name"><span class="dot" style="background:var(--' + g + ')"></span> ' +
        GAME_LABEL[g] + '</span><span class="muted small">' + fmtBytes(c.bytes) + "</span></div>" +
        '<div class="mid">' + fmtPct(c.pct) + '</div><div class="muted small">' + fmtInt(c.doneN) + " / " + fmtInt(c.n) +
        " functions matching (" + fmtPct(c.pctN) + ") · " + fmtBytes(c.bytes - c.doneB) + " left</div>" + statusBar(a.counts[g]) + legend(a.counts[g]) + "</div>";
    }).join("")));
    var info = el("div", "grid grid-2");
    info.style.marginTop = "12px";
    var ranges = GAMES.map(function (g) {
      var r = a.ranges[g];
      return "<dt>" + GAME_LABEL[g] + "</dt><dd class=\"mono\">" + (r ? absHex(r[0]) + " – " + absHex(r[1]) : "—") + "</dd>";
    }).join("");
    var about = el("div", "panel", "<h3>About</h3><dl class=\"kv\"><dt>Kind</dt><dd>" + esc(k.label) + "</dd>" +
      (a.confidence ? "<dt>Confidence</dt><dd>" + esc(a.confidence) + "</dd>" : "") + ranges + "</dl>" +
      (a.evidence ? '<details' + (a.evidence.length < 400 ? " open" : "") + '><summary class="small">Evidence (data/areas.csv)</summary><p class="evidence">' + esc(a.evidence) + "</p></details>" : ""));
    var hp = el("div", "panel", "<h3>Progress over time</h3>");
    info.appendChild(about); info.appendChild(hp);
    app.appendChild(info);
    var actWrap = el("div");
    withHistory(hp, function () {
      var per = GAMES.map(function (g) { return areaSeries(g, i); });
      var pts = per[0].map(function (x) { return { t: x.t, p: x.p }; });
      lineChart(hp, pts, GAMES.map(function (g, gi) {
        return { label: GAME_LABEL[g], color: "var(--" + g + ")", dash: g === "shield", values: per[gi].map(function (x) { return C(x.counts).bytes ? C(x.counts).pct : null; }) };
      }), { label: "Matching code in " + a.name, height: 200 });
      var hs = historySeries(game), idx = (hs.perArea[i] || []).slice(-8).reverse();
      var ul = el("ul", "activity");
      idx.forEach(function (pi) {
        var d = hs.deltas[pi].filter(function (x) { return x.area === i; });
        if (!d.length || (!d[0].dN && !d[0].dB)) return;
        ul.appendChild(activityItem(H.points[pi], d));
      });
      if (ul.children.length) {
        actWrap.appendChild(el("h2", "", "Recent commits in this module"));
        var p = el("div", "panel"); p.appendChild(ul); actWrap.appendChild(p);
      }
    });
    app.appendChild(actWrap);
    app.appendChild(el("h2", "", "Functions"));
    var ft = el("div");
    app.appendChild(ft);
    ft.appendChild(el("p", "muted", "Loading functions…"));
    loadFunctions(i).then(function (rows) {
      ft.innerHTML = "";
      functionTable(ft, rows.map(function (r) { return [r, i]; }), { area: false });
    }, function (e) { ft.innerHTML = '<p class="err">' + esc(String(e)) + "</p>"; });
  }

  var fnState = { status: "U", q: "", sort: "addr", named: false, area: "all", kind: "all" };
  function pageFunctions(params) {
    app.innerHTML = "";
    app.appendChild(el("div", "head-row", "<div><h1>Functions</h1><div class=\"muted\">Every function in <span class=\"mono\">data/functions.csv</span> (" +
      fmtInt(S.functions) + "). Search by name or address, filter by status, and sort by size to find work.</div></div>"));
    if (params.q !== undefined) fnState.q = params.q;
    var ctr = el("div", "controls");
    var sel = el("select");
    sel.setAttribute("aria-label", "Module");
    sel.innerHTML = '<option value="all">All modules</option>' + KINDS.map(function (k) {
      var opts = S.areas.map(function (a, i) { return a.kind === k.key && C(a.counts[game]).n ? '<option value="' + i + '">' + esc(a.name) + "</option>" : ""; }).join("");
      return opts ? '<option value="kind:' + k.key + '">All ' + esc(k.label.toLowerCase()) + "</option>" + '<optgroup label="' + esc(k.label) + '">' + opts + "</optgroup>" : "";
    }).join("");
    sel.value = fnState.area;
    if (sel.value !== fnState.area) sel.value = "all";
    ctr.appendChild(sel);
    app.appendChild(ctr);
    var ft = el("div");
    app.appendChild(ft);
    function load() {
      fnState.area = sel.value;
      var idx;
      if (sel.value === "all") idx = S.areas.map(function (_, i) { return i; });
      else if (sel.value.indexOf("kind:") === 0) {
        var kk = sel.value.slice(5);
        idx = []; S.areas.forEach(function (a, i) { if (a.kind === kk) idx.push(i); });
      } else idx = [Number(sel.value)];
      ft.innerHTML = '<p class="muted">Loading ' + plural(idx.length, "module") + "…</p>";
      Promise.all(idx.map(loadFunctions)).then(function (lists) {
        var rows = [];
        lists.forEach(function (l, j) { l.forEach(function (r) { rows.push([r, idx[j]]); }); });
        ft.innerHTML = "";
        functionTable(ft, rows, { area: idx.length > 1 });
      }, function (e) { ft.innerHTML = '<p class="err">' + esc(String(e)) + "</p>"; });
    }
    sel.addEventListener("change", load);
    load();
  }

  // rows: [[row, areaIndex]]; row = [sword, swordSize, shield, shieldSize, scope, status, name?, demangled?]
  function functionTable(container, rows, opts) {
    var st = fnState;
    var ai = game === "sword" ? 0 : 2;
    var ctr = el("div", "controls");
    var counts = {};
    rows.forEach(function (x) { counts[x[0][5]] = (counts[x[0][5]] || 0) + 1; });
    var chips = el("div", "chips");
    chips.innerHTML = ['all'].concat(S.statuses).map(function (s) {
      var n = s === "all" ? rows.length : counts[s] || 0;
      if (s !== "all" && !n) return "";
      return '<button type="button" class="chip" data-s="' + s + '">' + (s === "all" ? "All" : '<span class="dot s-' + s + '"></span>' + STATUS_INFO[s].label) +
        ' <span class="muted">' + fmtInt(n) + "</span></button>";
    }).join("");
    if (st.status !== "all" && !counts[st.status]) st.status = "all";
    ctr.appendChild(chips);
    ctr.insertAdjacentHTML("beforeend", '<input type="search" placeholder="Name or address…" aria-label="Search functions">' +
      '<select aria-label="Sort"><option value="addr">Address</option><option value="size-desc">Largest first</option>' +
      '<option value="size-asc">Smallest first</option><option value="name">Name</option></select>' +
      '<label class="check"><input type="checkbox"> Named only</label>');
    container.appendChild(ctr);
    var info = el("div", "muted small");
    container.appendChild(info);
    var wrap = el("div", "panel table-wrap");
    wrap.style.padding = "0";
    wrap.style.marginTop = "8px";
    container.appendChild(wrap);
    var more = el("div", "more");
    container.appendChild(more);
    var q = ctr.querySelector("input[type=search]"), sortSel = ctr.querySelector("select"), named = ctr.querySelector("input[type=checkbox]");
    q.value = st.q; sortSel.value = st.sort; named.checked = st.named;
    var shown = PAGE, filtered = [];

    function addr(r) { return r[ai] != null ? r[ai] : r[2 - ai]; }
    function size(r) { return r[ai + 1] != null ? r[ai + 1] : r[3 - ai]; }
    function apply() {
      chips.querySelectorAll(".chip").forEach(function (c) { c.classList.toggle("on", c.dataset.s === st.status); });
      var ql = st.q.trim().toLowerCase(), qa = null;
      var m = /^(?:0x)?([0-9a-f]{5,10})$/.exec(ql);
      if (m) { qa = parseInt(m[1], 16); if (qa >= BASE) qa -= BASE; }
      filtered = rows.filter(function (x) {
        var r = x[0];
        if (st.status !== "all" && r[5] !== st.status) return false;
        if (st.named && !r[6]) return false;
        if (!ql) return true;
        if (qa !== null && (r[0] === qa || r[2] === qa || (r[0] <= qa && qa < r[0] + r[1]) || (r[2] != null && r[2] <= qa && qa < r[2] + r[3]))) return true;
        if (r[6] && r[6].toLowerCase().indexOf(ql) >= 0) return true;
        if (r[7] && r[7].toLowerCase().indexOf(ql) >= 0) return true;
        return !r[6] && hex(addr(r)).indexOf(ql) >= 0;
      });
      var s = st.sort;
      filtered.sort(function (x, y) {
        var a = x[0], b = y[0];
        if (s === "size-desc") return size(b) - size(a) || addr(a) - addr(b);
        if (s === "size-asc") return size(a) - size(b) || addr(a) - addr(b);
        if (s === "name") return (a[7] || a[6] || "￿").localeCompare(b[7] || b[6] || "￿") || addr(a) - addr(b);
        return (a[0] != null ? a[0] : a[2]) - (b[0] != null ? b[0] : b[2]);
      });
      shown = PAGE;
      draw();
    }
    function draw() {
      var tot = 0;
      filtered.forEach(function (x) { tot += size(x[0]) || 0; });
      info.textContent = plural(filtered.length, "function") + " · " + fmtBytes(tot) + (filtered.length > shown ? " · showing the first " + fmtInt(shown) : "");
      var html = "<table><thead><tr><th>" + GAME_LABEL[game] + ' address</th><th class="num">Size</th><th>Status</th>' +
        (opts.area ? '<th class="hide-sm">Module</th>' : "") + "<th>Name</th></tr></thead><tbody>";
      filtered.slice(0, shown).forEach(function (x) {
        var r = x[0], other = r[ai] == null;
        var name = r[6] ? (r[7] ? esc(r[7]) + '<span class="mangled mono">' + esc(r[6]) + "</span>" : '<span class="mono">' + esc(r[6]) + "</span>")
          : '<span class="unnamed mono">FUN_' + (addr(r) + BASE).toString(16) + "</span>";
        var scope = S.scopes[r[4]];
        html += "<tr><td class=\"mono\" style=\"white-space:nowrap\">" + hex(addr(r)) +
          (other ? ' <span class="tag">' + (ai === 0 ? "Shield" : "Sword") + " only</span>" : "") +
          (scope && scope !== "common" ? ' <span class="tag" title="scope">' + esc(scope) + "</span>" : "") +
          ' <button type="button" class="copy" data-copy="' + hex(addr(r)) + '" title="Copy the address">copy</button></td>' +
          '<td class="num">' + fmtInt(size(r)) + "</td><td>" + badge(r[5]) + "</td>" +
          (opts.area ? '<td class="hide-sm"><a href="' + moduleLink(x[1]) + '">' + esc(S.areas[x[1]].name) + "</a></td>" : "") +
          '<td class="fname">' + name + "</td></tr>";
      });
      if (!filtered.length) html += '<tr><td colspan="5" class="muted">No functions match.</td></tr>';
      wrap.innerHTML = html + "</tbody></table>";
      more.innerHTML = filtered.length > shown ? '<button type="button" class="btn">Show ' + fmtInt(Math.min(PAGE * 4, filtered.length - shown)) + " more</button>" : "";
    }
    chips.addEventListener("click", function (ev) {
      var b = ev.target.closest(".chip");
      if (b) { st.status = b.dataset.s; apply(); }
    });
    var timer = null;
    q.addEventListener("input", function () { clearTimeout(timer); timer = setTimeout(function () { st.q = q.value; apply(); }, 150); });
    sortSel.addEventListener("change", function () { st.sort = sortSel.value; apply(); });
    named.addEventListener("change", function () { st.named = named.checked; apply(); });
    more.addEventListener("click", function (ev) { if (ev.target.closest("button")) { shown += PAGE * 4; draw(); } });
    wrap.addEventListener("click", function (ev) {
      var b = ev.target.closest(".copy");
      if (!b) return;
      var done = function () { b.textContent = "copied"; setTimeout(function () { b.textContent = "copy"; }, 1200); };
      if (navigator.clipboard) navigator.clipboard.writeText(b.dataset.copy).then(done, function () {});
    });
    apply();
  }

  var histState = { metric: "code", onlyProgress: true, shown: 50 };
  function pageHistory() {
    app.innerHTML = "";
    app.appendChild(el("div", "head-row", "<div><h1>History</h1><div class=\"muted\">One point per commit on <span class=\"mono\">master</span> that changed " +
      '<span class="mono">data/functions.csv</span>, back to the first one. Every commit is placed in modules with today\'s <span class="mono">data/areas.csv</span>.</div></div>'));
    var top = el("div");
    app.appendChild(top);
    withHistory(top, function () {
      var ctr = el("div", "controls", '<div class="seg" role="group" aria-label="Metric"><button type="button" data-m="code">Code</button><button type="button" data-m="functions">Functions</button></div>' +
        '<span class="muted small">Click the chart to open a commit.</span>');
      top.appendChild(ctr);
      var charts = el("div", "grid grid-2");
      top.appendChild(charts);
      var c1 = el("div", "panel", "<h3>Both games</h3>"), c2 = el("div", "panel", "<h3>By kind of code (" + GAME_LABEL[game] + ")</h3>");
      charts.appendChild(c1); charts.appendChild(c2);
      var pts = H.points.map(function (p) { return { t: p.t, p: p }; });
      var hs = historySeries(game);
      function val(counts) { var c = C(counts); return histState.metric === "code" ? c.pct : c.pctN; }
      function drawCharts() {
        ctr.querySelectorAll(".seg button").forEach(function (b) { b.classList.toggle("on", b.dataset.m === histState.metric); });
        c1.innerHTML = "<h3>Both games</h3>"; c2.innerHTML = "<h3>By kind of code (" + GAME_LABEL[game] + ")</h3>";
        lineChart(c1, pts, GAMES.map(function (g) {
          return { label: GAME_LABEL[g], color: "var(--" + g + ")", dash: g === "shield", values: H.points.map(function (p) { return val(p.games[g]); }) };
        }), { label: "Matching over time" });
        lineChart(c2, pts, KINDS.filter(function (k) { return C(hs.kinds[k.key][hs.kinds[k.key].length - 1] || zero()).n; }).map(function (k) {
          return { label: k.short, color: "var(--k-" + k.key + ")", values: hs.kinds[k.key].map(function (c) { return C(c).n ? val(c) : null; }) };
        }), { label: "Matching over time by kind" });
      }
      ctr.addEventListener("click", function (ev) {
        var b = ev.target.closest(".seg button");
        if (b) { histState.metric = b.dataset.m; drawCharts(); }
      });
      drawCharts();

      // per-day bars: functions matched per day
      var days = {}, order = [];
      H.points.forEach(function (p) {
        var d = dateOnly(p.date);
        if (!days[d]) { days[d] = { n: 0, commits: 0 }; order.push(d); }
        days[d].n += p.matched_n - p.lost_n; days[d].commits++;
      });
      var stats = el("div", "grid grid-4");
      stats.style.marginTop = "12px";
      var first = H.points[0], last = H.points[H.points.length - 1];
      var week = H.points.filter(function (p) { return p.t >= last.t - 7 * 86400000; });
      var weekN = week.reduce(function (s, p) { return s + p.matched_n - p.lost_n; }, 0);
      var best = order.reduce(function (b, d) { return !b || days[d].n > days[b].n ? d : b; }, null);
      stats.innerHTML = [
        ["Commits", fmtInt(H.points.length), "since " + dateOnly(first.date)],
        ["Matched in the last 7 days", fmtInt(weekN), "functions, " + plural(week.length, "commit")],
        ["Best day", best ? fmtInt(days[best].n) : "–", best ? "functions on " + best : ""],
        ["Matching now (" + GAME_LABEL[game] + ")", fmtPct(C(last.games[game]).pct), fmtInt(C(last.games[game]).doneN) + " functions"],
      ].map(function (s) { return '<div class="panel"><div class="muted small">' + esc(s[0]) + '</div><div class="mid">' + esc(s[1]) + '</div><div class="muted small">' + esc(s[2]) + "</div></div>"; }).join("");
      top.appendChild(stats);

      var log = el("div");
      top.appendChild(log);
      function drawLog() {
        log.innerHTML = "";
        var hr = el("div", "head-row", "<h2>Commits</h2>");
        var lab = el("label", "check", '<input type="checkbox"> Only commits that changed matching');
        lab.firstChild.checked = histState.onlyProgress;
        lab.firstChild.addEventListener("change", function () { histState.onlyProgress = lab.firstChild.checked; histState.shown = 50; drawLog(); });
        hr.appendChild(lab);
        log.appendChild(hr);
        var panel = el("div", "panel"), ul = el("ul", "activity"), n = 0, total = 0;
        for (var i = H.points.length - 1; i >= 0; i--) {
          var p = H.points[i];
          if (histState.onlyProgress && !p.matched_n && !p.lost_n) continue;
          total++;
          if (n >= histState.shown) continue;
          n++;
          ul.appendChild(activityItem(p, hs.deltas[i]));
        }
        panel.appendChild(ul);
        log.appendChild(panel);
        if (total > n) {
          var m = el("div", "more", '<button type="button" class="btn">Show more (' + fmtInt(total - n) + " left)</button>");
          m.firstChild.addEventListener("click", function () { histState.shown += 100; drawLog(); });
          log.appendChild(m);
        }
      }
      drawLog();
    });
  }

  // ------------------------------------------------------------------ routing
  function parseHash() {
    var h = location.hash.replace(/^#\/?/, "");
    var qi = h.indexOf("?"), path = qi >= 0 ? h.slice(0, qi) : h, params = {};
    if (qi >= 0) h.slice(qi + 1).split("&").forEach(function (kv) {
      var p = kv.split("="); if (p[0]) params[decodeURIComponent(p[0])] = decodeURIComponent(p[1] || "");
    });
    return { parts: path.split("/").filter(Boolean), params: params };
  }
  function route() {
    hideTip();
    var r = parseHash(), name = r.parts[0] || "overview";
    document.querySelectorAll("#tabs a").forEach(function (a) {
      a.classList.toggle("active", a.dataset.route === (name === "module" ? "modules" : name));
    });
    document.querySelectorAll(".game-switch button").forEach(function (b) { b.classList.toggle("on", b.dataset.game === game); });
    var titles = { overview: "", modules: "Modules", module: "", functions: "Functions", history: "History" };
    try {
      if (name === "modules") pageModules(r.params);
      else if (name === "module") pageModule(Number(r.parts[1]));
      else if (name === "functions") pageFunctions(r.params);
      else if (name === "history") pageHistory();
      else pageOverview();
    } catch (e) {
      app.innerHTML = '<p class="err">Something went wrong: ' + esc(String(e)) + "</p>";
      throw e;
    }
    var t = name === "module" && S.areas[Number(r.parts[1])] ? S.areas[Number(r.parts[1])].name : titles[name];
    document.title = (t ? t + " · " : "") + "Sword & Shield Decomp Progress";
  }
  function footer() {
    var src = S.source || {}, url = src.sha ? commitUrl(src.sha) : null;
    var sha = src.sha ? '<span class="mono">' + esc(src.sha.slice(0, 12)) + "</span>" : "";
    document.getElementById("foot").innerHTML =
      "Generated " + esc(S.generated.replace("T", " ").replace("+00:00", " UTC")) + (sha ? " from " + (url ? '<a href="' + esc(url) + '">' + sha + "</a>" : sha) : "") +
      " by <span class=\"mono\">tools/progress_site.py</span> on every push to master." +
      (repo() ? ' · <a href="' + esc(repo()) + '">Repository</a> · <a href="' + esc(repo()) + '/blob/master/CONTRIBUTING.md">Contributing</a>' : "");
  }

  document.querySelectorAll(".game-switch button").forEach(function (b) {
    b.addEventListener("click", function () {
      if (game === b.dataset.game) return;
      game = b.dataset.game;
      store("game", game);
      route();
    });
  });
  window.addEventListener("hashchange", function () { route(); window.scrollTo(0, 0); });

  loadJSON("data/summary.json").then(function (s) {
    S = s;
    footer();
    route();
  }, function (e) {
    app.innerHTML = '<p class="err">Couldn\'t load data/summary.json: ' + esc(String(e)) + "</p>";
  });
})();
