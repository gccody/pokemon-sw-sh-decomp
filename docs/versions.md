# Sword vs Shield

Target: **1.0.0** cartridges.

| | Sword | Shield |
|---|---|---|
| Title ID | `0100ABF008968000` | `01008DB008C2C000` |
| `main` build ID | `8dafedbb5be81c2c0160161159a791e67e3d6162` | `b56ca071216570e8943206f10c3f3f2fc9eee918` |
| `.text` size | `0x17EC260` | `0x17EC300` (+0xA0) |
| `.rodata` / `.data` / `.bss` | same layout, rodata +8 bytes | |
| `sdk`, `subsdk0`, `subsdk1`, `rtld` | **byte-identical** | |

Both games come from one build of one codebase (build path
`C:\jenkins\workspace\orion\RomBuild\...`, codename *orion*). The `main`
executables have the same 104,005 functions in the same order.

## How functions were paired

1. **Function boundaries** come from `.eh_frame_hdr` / `.eh_frame` (clang emits
   an FDE for every function), so start and size are exact. One FDE-less stub,
   at `0x7101750e90`, is recovered from the gaps.
2. **Alignment:** each function's instructions are hashed with all
   address-dependent fields zeroed (B/BL imm26, ADRP, ADR, LDR-literal and the
   `:lo12:` operand of ADD/LDR/STR after an ADRP). The two sequences are then
   aligned with `difflib`.
3. **Classification:** for each pair, every reference is resolved to a target
   and compared by meaning, not address:
   - calls/branches into code: the target must be the *paired* function at the same offset
   - `.data`/`.bss`: identical layout in both games, so the same address
   - `.rodata`: same contents (exact access width for loads, the string for
     address-of). Switch jump tables (s32 offsets into code that moved) are
     resolved through the function pairing.

## Results

| Scope | Count | Notes |
|---|---:|---|
| `common` | 103,985 | 67,957 are byte-identical; the rest only moved |
| `common-data` | 3 | see below |
| `diverged` | 17 | see below |
| exclusive | 0 | |

**`common-data`** (the code is shared, but it references different data):

- `0x7100e98ab0`: `bin/field/param/encount/encount_k.bin` vs `encount_t.bin`
  (the wild-encounter tables; *k*/*t* is probably *ken* (sword) / *tate* (shield)),
  plus `encount_symbol_{k,t}.bin`
- `0x7101526710`, `0x7101540930`: `ZKN_COMMENT_A_%03d_*` vs `ZKN_COMMENT_B_%03d_*`
  (Pokédex entry text, which differs per game)

**`diverged`** (the code itself differs). Every one looked at so far is the same
source with a version-dependent constant:

- `0x71007c2d80` `pkmn::GetVersion()`: `mov w0, #44` vs `#45`, the in-game
  version IDs (SW = 44, SH = 45). **Matched.**
- Others compare against a version value (`cmp w14, #1` vs `#2`), or embed
  64-bit hashes of version-specific names. Five of them have different sizes
  (`0x7100c48da0`, `0x710106fa30`, `0x7101426ea0`, `0x7101444350`, `0x71014bdd60`),
  where a version check compiled to a different amount of code.

The full list, with per-function notes, is in `data/version_diff.json`.

## What this means for the source tree

There is no need for separate `sword/` and `shield/` trees. Build the single
tree twice (`cmake --preset sword` / `--preset shield`, which differ only in
`-DPKMN_VERSION`). Every function's source is shared. Only the 20 functions above
need `PKMN_SW_SH(...)` / `PKMN_IS_SWORD`.

Later versions (1.1+, Isle of Armor / Crown Tundra) can be added the same way:
add a column to `functions.csv`, a preset and a `PKMN_VERSION_*` value, then
re-run the pairing.
