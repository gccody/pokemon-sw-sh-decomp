# Contributing

## 1. Claim something

The **unit of tracking** is a function (`data/functions.csv`), but **claim a
group**: a class (a vtable and its methods), a source file's worth of
neighbouring functions, or an address range. Struct layouts are shared across
a class, so splitting one class between people causes conflicts.

- Open a GitHub issue titled `Claim: <area> <address range or class>`. One claim
  per person at a time is a good default. Close it with the PR, or after two
  weeks without activity.
- Don't put claims in `functions.csv`. It would turn every claim into a merge
  conflict.
- Third-party code (`data/areas.csv` rows of kind `library`) comes first or
  separately. PhysX 3.4.2, Lua and sol2 are open source, so their functions can
  be matched largely by compiling upstream source.

Finding work:

```sh
python tools/funcs.py list --status U --max 64 --range 0x71005a0000-0x7101540000
python tools/funcs.py list --scope diverged
python tools/funcs.py show 0x7100bc0b00
```

## 2. Decompile

1. Name the function first: `tools/funcs.py name <addr> <mangled name>`. Use real
   names where they're known (library code, strings, RTTI). Otherwise use
   placeholders like `Unk_<addr>` for types and keep the address in a comment.
2. Write the code under `src/<subsystem>/` (or `src/unsorted/`), or `lib/<library>/`.
3. Follow the function's **scope**:
   - `common`: plain code, with no `PKMN_*` version macros.
   - `common-data`: plain code. The per-game difference is in a referenced
     string or table, so select that data with `PKMN_SW_SH(...)`.
   - `diverged`: use `PKMN_SW_SH(sword, shield)` or `#if PKMN_IS_SWORD`
     where the games differ. Run `tools/funcs.py show <addr>` to see both.
   - `sword` / `shield`: wrap the whole function in `#if PKMN_IS_SWORD` / `#if PKMN_IS_SHIELD`.
4. Add `PKMN_SIZE_ASSERT` / `PKMN_OFFSET_ASSERT` (from `types.h`) for every
   reconstructed struct.

## 3. Check

```sh
python tools/check.py <name> --diff     # builds sword + shield, checks both
python tools/check.py --update          # marks matches as O in functions.csv
```

The checker compares instructions exactly. Addresses are checked by
*meaning*: calls and data references are resolved by symbol name through
`functions.csv` / `data_symbols.csv`, SDK imports go through each game's PLT,
and string/constant literals are compared by content. If your code calls a
function that has no name yet, the checker prints the address the original
calls, so you can name it.

A function is `O` only when it matches in every game it exists in. If it
can't match yet, submit it anyway with status `M` (or `m` for regalloc or
ordering-only differences), set via `tools/funcs.py status <addr> M`, and add a
`// NON_MATCHING: <reason>` comment above it.

## 4. PR

- Keep PRs small, ideally one claim. Everyone edits `functions.csv`, so small
  PRs rebase easily.
- `tools/lint.py` must pass. CI runs it and builds both games, but it has no
  access to the originals. Paste your `tools/check.py` output into the PR.
- Never commit anything extracted from the game.

## Regenerating the function list

If the pairing logic in `tools/versiondiff.py` improves, run
`python tools/versiondiff.py --update-csv`. It keeps existing names and statuses.
