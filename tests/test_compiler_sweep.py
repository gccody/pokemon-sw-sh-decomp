"""compiler_sweep.py: the consensus name -> address map for both games
(--map-out), and the --src globs used for the corpora in docs/compiler.md
(Lua: one directory, PhysX: a recursive tree)."""
from __future__ import annotations

import struct

import compiler_sweep
import funcs
from common import BASE, read_functions_csv
from compiler_sweep import find_sources
from nx.refs import decode


def test_consensus_keeps_only_unanimous_unique_hits():
    configs = [
        {"a": [0x10], "b": [0x20], "c": [0x30, 0x40], "d": [0x50]},
        {"a": [0x10], "b": [0x24], "c": [0x30], "e": [0x60]},
    ]
    assert compiler_sweep.consensus(configs) == {"a": 0x10, "d": 0x50, "e": 0x60}


def test_find_hits_ignores_tiny_functions():
    ret = (0xD65F03C0).to_bytes(4, "little")
    nop = (0xD503201F).to_bytes(4, "little")
    big = nop * 3 + ret
    ws = {0x100: compiler_sweep.words(big), 0x200: compiler_sweep.words(ret)}
    index = {compiler_sweep.coarse_key(w): [a] for a, w in ws.items()}
    funcs_ = {n: compiler_sweep.Func(c) for n, c in (("big", big), ("tiny", ret), ("miss", nop * 4))}
    assert compiler_sweep.find_hits(funcs_, index, ws) == {"big": [0x100]}
    # --min-size 4 counts the 4-byte `ret` too
    assert compiler_sweep.find_hits(funcs_, index, ws, min_size=4) == {"big": [0x100], "tiny": [0x200]}


def test_min_size_option_and_hits_csv(tmp_path):
    args = compiler_sweep.arg_parser().parse_args(["--compiler", "cc", "--src", "a.cpp", "--min-size", "4"])
    assert args.min_size == 4
    assert compiler_sweep.arg_parser().parse_args(["--compiler", "cc", "--src", "a.cpp"]).min_size == 16
    orig = {0x100: (NOP, RET), 0x200: (RET,)}
    results = {("clang-6.0.1", "O3"): ({}, {"f": [0x100], "r": [0x200, 0x100]}, [])}
    path = tmp_path / "hits.csv"
    assert compiler_sweep.write_hits(path, results, orig) == 2
    assert path.read_text(encoding="utf-8").splitlines() == [
        "Address,Size,Config,Name",
        f"{0x100 + BASE:#x},8,clang-6.0.1/O3,f",
        f"{0x100 + BASE:#x},8,clang-6.0.1/O3,r",
        f"{0x200 + BASE:#x},4,clang-6.0.1/O3,r",
    ]


# Hand-encoded words for the relocation-masking tests.
RET = 0xD65F03C0
NOP = 0xD503201F
B_PLUS3 = 0x14000003  # b .+12
B_MINUS3 = 0x17FFFFFD  # b .-12
BL_0 = 0x94000000  # bl <reloc>
ADRP_X8_0 = 0x90000008  # adrp x8, <reloc>
ADRP_X8_3 = 0xF0000008  # adrp x8, .+3 pages (linked)
LDR_S15_X8_0 = 0xBD40010F  # ldr s15, [x8, #<lo12>]
LDR_S15_X8_N = 0xBD49310F  # ldr s15, [x8, #0x930] (linked)
LDR_X0_X0_8 = 0xF9400400  # ldr x0, [x0, #8] (a struct offset)
LDR_X0_X0_16 = 0xF9400800  # ldr x0, [x0, #16]
ADD_X0_X8_0 = 0x91000100  # add x0, x8, #<lo12>
ADD_X0_X8_N = 0x91123100  # add x0, x8, #0x48c (linked)
ADD_X0_X1_X2 = 0x8B020020  # add x0, x1, x2 (register: no immediate)


def pack(*ws: int) -> bytes:
    return struct.pack(f"<{len(ws)}I", *ws)


def linear_masked(ws) -> list[int]:
    """The old masking: tools/nx/refs.py's linear ADRP tracking."""
    buf = pack(*ws)
    return [m for _, _, m, _ in decode(buf, 0, len(buf))]


def test_field_mask_clears_only_the_relocatable_field():
    fm = compiler_sweep.field_mask
    assert 0x94001234 & fm(0x94001234) == BL_0
    assert B_MINUS3 & fm(B_MINUS3) == 0x14000000
    assert ADRP_X8_3 & fm(ADRP_X8_3) == ADRP_X8_0
    assert LDR_S15_X8_N & fm(LDR_S15_X8_N) == LDR_S15_X8_0
    assert ADD_X0_X8_N & fm(ADD_X0_X8_N) == ADD_X0_X8_0
    assert 0xD2A00020 & fm(0xD2A00020) == 0xD2A00000  # movz x0, #1, lsl #16: imm16 cleared, hw kept
    assert 0x54000041 & fm(0x54000041) == 0x54000001  # b.ne .+8: imm19 cleared, cond kept
    assert 0xB4000040 & fm(0xB4000040) == 0xB4000000  # cbz x0, .+8
    assert 0x36080040 & fm(0x36080040) == 0x36080000  # tbz w0, #1, .+8: bit number kept
    for w in (RET, NOP, ADD_X0_X1_X2):
        assert fm(w) == 0xFFFFFFFF


def test_lo12_whose_adrp_is_on_another_path_matches():
    # The block with the adrp is laid out after the ldr that uses it, as in
    # triangleConvexTest, so linear adrp tracking reaches the ldr first:
    #   0: b 3   1: ldr s15, [x8, #lo12]   2: ret   3: adrp x8, page   4: b 1
    compiled = (B_PLUS3, LDR_S15_X8_0, RET, ADRP_X8_0, B_MINUS3)
    original = (B_PLUS3, LDR_S15_X8_N, RET, ADRP_X8_3, B_MINUS3)
    relocs = frozenset({1, 3})  # the intra-function branches have none
    assert compiler_sweep.same_code(compiled, relocs, original)
    assert compiler_sweep.coarse_key(compiled) == compiler_sweep.coarse_key(original)
    assert linear_masked(compiled) != linear_masked(original)  # what the sweep used to compare


def test_unrelocated_fields_are_compared_raw():
    # A struct offset (no relocation) must match exactly, even though the
    # coarse key masks it, and so must an intra-function branch.
    relocs = frozenset({0})
    assert compiler_sweep.same_code((BL_0, LDR_X0_X0_8, RET), relocs, (0x94000777, LDR_X0_X0_8, RET))
    assert not compiler_sweep.same_code((BL_0, LDR_X0_X0_8, RET), relocs, (0x94000777, LDR_X0_X0_16, RET))
    assert not compiler_sweep.same_code((B_PLUS3, NOP, RET), frozenset(), (0x14000002, NOP, RET))
    # the original is masked by its own instruction class: an ldr can't stand in for an add
    assert not compiler_sweep.same_code((ADRP_X8_0, ADD_X0_X8_0, RET), frozenset({0, 1}),
                                        (ADRP_X8_3, LDR_S15_X8_N, RET))
    assert not compiler_sweep.same_code((NOP, RET), frozenset(), (NOP, NOP, RET))


def test_find_hits_picks_the_bucket_entry_with_the_same_offsets():
    # Two originals that differ only in a struct offset share a coarse key.
    orig = {0x100: (ADRP_X8_3, ADD_X0_X8_N, LDR_X0_X0_8, RET),
            0x200: (ADRP_X8_3, ADD_X0_X8_N, LDR_X0_X0_16, RET)}
    index: dict = {}
    for a, ws in orig.items():
        index.setdefault(compiler_sweep.coarse_key(ws), []).append(a)
    assert len(index) == 1
    f = compiler_sweep.Func(pack(ADRP_X8_0, ADD_X0_X8_0, LDR_X0_X0_16, RET), frozenset({0, 1}))
    assert compiler_sweep.find_hits({"f": f}, index, orig) == {"f": [0x200]}


def test_similarity_is_one_only_for_same_code():
    f = compiler_sweep.Func(pack(ADRP_X8_0, LDR_S15_X8_0, LDR_X0_X0_8, RET), frozenset({0, 1}))
    assert compiler_sweep.similarity(f, (ADRP_X8_3, LDR_S15_X8_N, LDR_X0_X0_8, RET)) == 1.0
    near = compiler_sweep.similarity(f, (ADRP_X8_3, LDR_S15_X8_N, LDR_X0_X0_16, RET))
    assert 0.5 < near < 1.0
    # An inserted instruction shifts the relocation indices. The original's own
    # address fields are masked as well, so the rest still lines up.
    assert compiler_sweep.similarity(f, (NOP, ADRP_X8_3, LDR_S15_X8_N, LDR_X0_X0_8, RET)) > near


def tiny_elf(text: bytes, syms, relocs) -> bytes:
    """A minimal ELF64 AArch64 relocatable object with one code section.

    syms: (name, bind, type, value, size), locals first; functions (type 2)
    are in the code section, anything else is undefined.
    relocs: (offset, symbol index, type), in the code section's .rela."""
    strtab, symtab = b"\0", b"\0" * 24
    for name, bind, typ, value, size in syms:
        symtab += struct.pack("<IBBHQQ", len(strtab), (bind << 4) | typ, 0, 1 if typ == 2 else 0, value, size)
        strtab += name.encode() + b"\0"
    rela = b"".join(struct.pack("<QQq", off, (sym << 32) | typ, 0) for off, sym, typ in relocs)
    names = [b".text.foo", b".rela.text.foo", b".symtab", b".strtab", b".shstrtab"]
    shstrtab = b"\0" + b"\0".join(names) + b"\0"
    blobs = [text, rela, symtab, strtab, shstrtab]
    first_global = 1 + sum(1 for s in syms if s[1] == 0)
    # sh_type, sh_flags, sh_link, sh_info, sh_addralign, sh_entsize
    meta = [(1, 6, 0, 0, 4, 0), (4, 0x40, 3, 1, 8, 24), (2, 0, 4, first_global, 8, 24),
            (3, 0, 0, 0, 1, 0), (3, 0, 0, 0, 1, 0)]
    data, shdrs = b"", b"\0" * 64
    for name, blob, (typ, flags, link, info, align, ent) in zip(names, blobs, meta):
        shdrs += struct.pack("<IIQQQQIIQQ", shstrtab.index(b"\0" + name + b"\0") + 1, typ, flags, 0,
                             64 + len(data), len(blob), link, info, align, ent)
        data += blob + b"\0" * (-len(blob) % 8)
    ident = b"\x7fELF\x02\x01\x01" + b"\0" * 9
    hdr = ident + struct.pack("<HHIQQQIHHHHHH", 1, 183, 1, 0, 0, 64 + len(data), 0, 64, 0, 0, 64, 6, 5)
    return hdr + data + shdrs


def test_object_functions_reads_relocation_indices(tmp_path):
    # Two functions in one section: pad (+0, 2 words) and foo (+8, 3 words).
    # pad's ADRP (+0, ADR_PREL_PG_HI21) belongs to pad only, and foo's call
    # to bar (+12, CALL26) is foo's word 1.
    text = pack(ADRP_X8_0, RET, NOP, BL_0, RET)
    obj = tmp_path / "t.o"
    obj.write_bytes(tiny_elf(text, [("pad", 0, 2, 0, 8), ("foo", 1, 2, 8, 12), ("bar", 1, 0, 0, 0)],
                             [(0, 1, 275), (12, 3, 283)]))
    assert compiler_sweep.object_functions(obj, tmp_path / "t.cpp") == {
        "pad@t": compiler_sweep.Func(text[:8], frozenset({0})),
        "foo": compiler_sweep.Func(text[8:], frozenset({1})),
    }


def test_other_game_range_follows_paired_rows(functions_csv):
    rows = read_functions_csv(functions_csv(
        "0x0000007101540000,16,0x0000007101540100,16,common,U,",
        "0x0000007101540010,32,0x0000007101540110,32,common,U,",
        "0x0000007101541000,16,0x0000007101541100,16,common,U,",
        "0x0000007101541010,8,,,sword,U,",
    ))
    lo, hi = 0x1540000, 0x1541000  # first two rows only
    assert compiler_sweep.other_game_range("sword", "shield", lo, hi, rows) == (0x1540100, 0x1540130)


def test_written_map_is_what_funcs_name_reads(tmp_path):
    maps = {"sword": {"getfield@lauxlib": 0x1546000, "only_sword": 0x1546300},
            "shield": {"getfield@lauxlib": 0x15460A0}}
    path = tmp_path / "map.csv"
    assert compiler_sweep.write_map(path, maps) == 2
    assert path.read_text(encoding="utf-8").splitlines()[0] == "Name,Sword,Shield"
    assert funcs.read_name_map(path) == [
        ("getfield@lauxlib", 0x1546000 + BASE, 0x15460A0 + BASE),
        ("only_sword", 0x1546300 + BASE, None),
    ]


def test_find_sources_recursive_and_dedup(tmp_path):
    for rel in ("a.cpp", "sub/b.cpp", "sub/deep/c.cpp", "sub/d.h"):
        p = tmp_path / rel
        p.parent.mkdir(parents=True, exist_ok=True)
        p.write_text("", encoding="utf-8")
    flat = find_sources([str(tmp_path / "*.cpp")])
    assert [p.name for p in flat] == ["a.cpp"]
    deep = find_sources([str(tmp_path / "**" / "*.cpp"), str(tmp_path / "sub" / "*.cpp")])
    assert sorted(p.name for p in deep) == ["a.cpp", "b.cpp", "c.cpp"]


def test_find_sources_no_match(tmp_path):
    assert find_sources([str(tmp_path / "*.c")]) == []


def test_variant_flags_come_after_common_flags(tmp_path):
    # clang takes the last of conflicting options, so the variant must come last
    # to override both the base flags and the common flags after `--`.
    cmd = compiler_sweep.compile_command(
        tmp_path / "clang", ["-O2", "-std=gnu++11", "-fno-strict-aliasing"],
        ["-O3", "-std=gnu++14", "-DPX_SUPPORT_PVD=0"], tmp_path / "a.cpp", tmp_path / "a.o")
    base = compiler_sweep.BASE_FLAGS
    assert cmd[1:1 + len(base)] == base
    rest = cmd[1 + len(base):]
    assert rest[:6] == ["-O3", "-std=gnu++14", "-DPX_SUPPORT_PVD=0", "-O2", "-std=gnu++11", "-fno-strict-aliasing"]
    assert rest[6:] == ["-x", "c++", "-c", str(tmp_path / "a.cpp"), "-o", str(tmp_path / "a.o")]
    # the last occurrence of each conflicting option is the variant's
    assert [a for a in cmd if a.startswith("-O")][-1] == "-O2"
    assert [a for a in cmd if a.endswith("strict-aliasing")][-1] == "-fno-strict-aliasing"


def test_compile_all_passes_variant_last(tmp_path, monkeypatch):
    seen = []

    class Done:
        returncode, stderr = 1, "error: stub"

    def fake_run(cmd, **_kw):
        seen.append(cmd)
        return Done()

    monkeypatch.setattr(compiler_sweep.subprocess, "run", fake_run)
    src = tmp_path / "l.c"
    funcs_, errors = compiler_sweep.compile_all(tmp_path / "clang", ["-fno-unwind-tables"], ["-DX=1"],
                                                [src], tmp_path)
    assert funcs_ == {} and len(errors) == 1
    (cmd,) = seen
    assert "-x" not in cmd  # C source
    assert cmd.index("-DX=1") < cmd.index("-fno-unwind-tables") < cmd.index("-c")
    assert cmd.index("-funwind-tables") < cmd.index("-fno-unwind-tables")



def test_debug_info_is_a_base_flag_a_variant_can_drop(tmp_path):
    # The originals were built with -g (docs/compiler.md, "Debug info"), and it
    # changes LLVM's codegen. A -g0 variant must still be able to switch it off.
    assert "-g" in compiler_sweep.BASE_FLAGS
    cmd = compiler_sweep.compile_command(tmp_path / "clang", ["-g0"], [], tmp_path / "l.c", tmp_path / "l.o")
    assert cmd.index("-g") < cmd.index("-g0")


def test_arguments_from_a_response_file(tmp_path):
    # A corpus with hundreds of --src entries doesn't fit on a Windows command line.
    rsp = tmp_path / "args.txt"
    rsp.write_text("--src\na.cpp\n--src\nsub/b.cpp\n", encoding="utf-8")
    args = compiler_sweep.arg_parser().parse_args(
        ["--compiler", "clang", f"@{rsp}", "--src", "c.cpp", "--", "-O3", "-DX=1"])
    assert args.src == ["a.cpp", "sub/b.cpp", "c.cpp"]
    assert [a for a in args.common if a != "--"] == ["-O3", "-DX=1"]


def test_module_option_selects_the_nso(tmp_path, monkeypatch):
    # main goes through common.load_module; any other module is read from
    # data/original/<game>/<module> (here: missing, so it stops with a message).
    seen = []
    monkeypatch.setattr(compiler_sweep, "load_module", lambda game: seen.append(game) or {"main": game})
    assert compiler_sweep.load_original("shield") == {"main": "shield"} and seen == ["shield"]
    monkeypatch.setattr(compiler_sweep.common, "ORIGINAL", tmp_path)
    try:
        compiler_sweep.load_original("sword", "sdk")
    except SystemExit as e:
        assert str(tmp_path / "sword" / "sdk") in str(e)
    else:
        raise AssertionError("expected SystemExit for a missing module")
    assert seen == ["shield"]
    assert compiler_sweep.arg_parser().parse_args(["--compiler", "c", "--src", "a.c"]).module == "main"
    assert compiler_sweep.arg_parser().parse_args(["--compiler", "c", "--src", "a.c", "--module", "sdk"]).module == "sdk"


def test_original_index_reads_the_chosen_module(monkeypatch):
    ret = (0xD65F03C0).to_bytes(4, "little")
    nop = (0xD503201F).to_bytes(4, "little")
    img = nop * 4 + ret * 2
    calls = []

    def fake(game, module="main"):
        calls.append((game, module))
        return {"image": img, "functions": [(0, 16), (16, 8)]}
    monkeypatch.setattr(compiler_sweep, "load_original", fake)
    index, words = compiler_sweep.original_index("sword", 0, 16, "sdk")
    assert calls == [("sword", "sdk")]
    assert list(words) == [0] and index == {compiler_sweep.coarse_key(compiler_sweep.words(nop * 4)): [0]}
