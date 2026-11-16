# AGENTS.md

Instructions for AI coding assistants working in this repository. Human
contributors: the same rules, with more explanation, are in
[CONTRIBUTING.md](CONTRIBUTING.md).

## What this project is

This is a **matching decompilation** of Pokémon Sword and Shield 1.0.0
(Nintendo Switch, AArch64). The C++ in `src/` and `lib/` has to compile, with
clang 7.0.1 `-O3`, to the **exact same instructions** as the original `main`
executable. One source tree builds both games (`-DPKMN_VERSION`), and every
function is checked against **both** originals. "Looks equivalent" doesn't
count. A function is done only when `tools/check.py` reports `OK`.

## Hard rules

1. **Never commit, print, or copy game data or keys.** `data/original/`,
   `assets/Pokemon */`, `*.xci`, `*.nso`, `*.nca` and `*.keys` stay local and
   gitignored. Never `cat`/`Read` `prod.keys` or `title.keys`, and never echo
   key values. Short asm excerpts from `tools/funcs.py show` are fine in code
   comments and PR text. Bulk dumps of data or rodata are not.
   Don't commit the 83 `lib/physx` files listed in `data/physx_v342.csv`
   either: they hold PhysX v3.4.2 code, which isn't BSD-licensed.
   `tools/get_physx.py` generates them, and `lib/physx/.gitignore` and lint
   keep them out.
2. **Never hand-edit the `Status` column of `data/functions.csv`.** `O` comes
   only from `python tools/check.py --update`. Use `tools/funcs.py status <addr> m|M`
   for non-matching submissions.
3. **Don't invent symbol names.** Only use a real name when there's evidence:
   upstream library source, strings, RTTI, assert messages, or an SDK import.
   Otherwise use placeholders (`Unk_<addr>`, `field_<offset>`). Names are
   mangled symbols (`_ZN4pkmn10GetVersionEv`), set with `tools/funcs.py name`.
4. **Respect the function's scope** (the `Scope` column):
   - `common`: no `PKMN_*` macros at all.
   - `common-data`: plain code. Pick the per-game string or table with `PKMN_SW_SH(...)`.
   - `diverged`: `PKMN_SW_SH(sword, shield)` / `#if PKMN_IS_SWORD` only where the games differ.
   - `sword` / `shield`: the whole function goes inside `#if PKMN_IS_SWORD` / `#if PKMN_IS_SHIELD`.
5. **Don't make one source tree per game**, and don't add tooling that only
   handles one game. Everything is version-aware: two address columns, two
   builds, two checks.
6. **Don't change the global codegen flags** in `cmake/toolchain-nx64.cmake`
   (or add flags anywhere else) to make one function match. They're fixed by
   evidence (`docs/compiler.md`) and apply to every TU. A library that was
   built differently (other defines, `-fexceptions`, another clang version
   via `COMPILER_VERSION`, ...) gets a `pkmn_library_settings(<dir> ...)`
   entry in `CMakeLists.txt`, and only there. It needs a `docs/compiler.md`
   section with the evidence, named in the entry's `EVIDENCE`. See
   `cmake/LibrarySettings.cmake`. A missing library clang (e.g. PhysX's 6.0.1)
   fails the configure: install it with `tools/get_llvm.py --compiler <ver>`,
   don't switch on `PKMN_ALLOW_LIBRARY_COMPILER_FALLBACK` to get past it.
7. The project is MIT-licensed (`LICENSE`). Code under `lib/` keeps its
   upstream license. Don't copy code from sources whose license isn't
   MIT-compatible, and don't copy from leaked material at all.
8. Don't force matches with `volatile`, inline asm or meaningless temporaries.
   If it won't match with natural code, submit it as `M`/`m` with
   `// NON_MATCHING: <reason>`.

## Commands

Use the venv's Python: `.venv/Scripts/python` on Windows, `.venv/bin/python`
elsewhere. `ninja` must be on `PATH` for builds.

```sh
python tools/get_physx.py                                # once: lib/physx's v3.4.2 files (not in git)
python tools/funcs.py list --status U --max 64 -n 20     # find small undecompiled functions
python tools/funcs.py patterns --area game --status U --max 8   # group by pattern + how reached (docs/game_code.md)
python tools/funcs.py show 0x7100bc0b00                  # original asm (both games if diverged)
python tools/funcs.py name 0x7100bc0b00 _ZN4pkmn3FooEv   # assign a mangled name
python tools/check.py _ZN4pkmn3FooEv --diff              # build both games, compare, show diff
python tools/check.py --update                           # record matches in functions.csv
python tools/lint.py                                     # CSV + tracked-files validation
python -m pytest                                         # tooling tests (no game files needed)
ruff check .                                             # Python lint
clang-format -i src/path/File.cpp                        # format C/C++ (v19.1.7, from requirements-dev.txt)
```

`check.py`, `funcs.py show` and `progress.py` need the extracted originals in
`data/original/`. If they're missing, say so and stop. Don't try to obtain
game files.

## Layout

```
data/functions.csv     104k rows, ~6 MB: Sword/Shield address+size, Scope, Status, Name
data/data_symbols.csv  named globals/rodata (check.py resolves data references through it)
data/areas.csv         address range -> library/subsystem
data/absent_functions.csv, data/unidentified_functions.csv, data/foreign_copies.csv
                       compiled functions check.py skips (not in the executable / original not found yet /
                       another library's copy kept)
data/source_paths.csv  vendored dirs whose __FILE__ literals check.py compares by the file they name
data/physx_v342.csv    lib/physx files tools/get_physx.py generates (v3.4.2 code, never committed) + SHA-256
cmake/                 toolchain (global flags) + LibrarySettings.cmake (per-library flags)
include/types.h        u8..u64, f32, PKMN_SIZE_ASSERT, PKMN_OFFSET_ASSERT
include/pkmn/version.h PKMN_SW_SH, PKMN_IS_SWORD, PKMN_IS_SHIELD
src/                   Game Freak code (src/unsorted/ until a subsystem is known)
lib/                   third-party code (lua, sol2, physx, zlib...): upstream formatting and license, not clang-formatted
tools/                 Python tooling; tools/nx/ = XCI/NCA/NSO/eh_frame/AArch64 helpers
tests/                 pytest suite for tools/ (must not need game files)
docs/                  compiler identification, Sword/Shield version notes, Game Freak code areas + triage
```

`data/functions.csv` is too large to read whole. Query it with
`tools/funcs.py list`/`show` or a targeted grep for an address or name.
Write it only through the tools (`funcs.py`, `check.py --update`,
`versiondiff.py --update-csv`). They keep it sorted with LF line endings.

`data/areas.csv` is small and edited by hand. Each row has a range per game
(`SwordStart,SwordEnd,ShieldStart,ShieldEnd`), with boundaries at function
starts. Move a boundary in both games, then run `tools/lint.py`.

## Workflow for decompiling a function

1. `tools/funcs.py show <addr>` to read the original. For `diverged`, compare both columns.
2. Name it (`tools/funcs.py name`) if there's evidence. Otherwise use the placeholder.
3. Write the function in the right file under `src/` or `lib/`, with a
   `// <sword addr>` comment above it (and the Shield address if different) and
   a `// Scope: <scope>` line at the top of the file. Add size/offset asserts
   for every struct you reconstruct.
4. `tools/check.py <name> --diff`. Iterate on the source until it reports `OK`
   for every game the function exists in. If `check.py` names an unnamed callee,
   name that callee too.
5. `tools/check.py --update`, then `tools/lint.py`, `pytest` and `clang-format`.
6. Report the `check.py` summary to the user. It goes in the PR, because CI
   can't check matching.

Small complete examples: `src/pkmn/Version.cpp` (diverged),
`src/unsorted/Unk_7eef40.*` and `src/unsorted/Unk_7cc390.cpp` (common,
cross-TU call), `lib/lua/lauxlib.c` (vendored library, string literals),
`src/field/content/Unk_df22f0.cpp` (game code instantiating the header-only
`lib/sol`, with its own `pkmn_library_settings` entry).

## Changing the tooling

- Python 3.10+, stdlib plus `tools/requirements.txt`. Keep `ruff check .` clean.
- Add or update tests in `tests/` for any change under `tools/`. Hand-encode
  instruction words or build tiny CSVs with the `functions_csv` fixture. Never
  depend on `data/original/`.
- `tests/test_common.py` asserts that `functions.csv` round-trips byte for byte.
  Don't change the CSV format without updating every reader and writer.
- The tools must work on Windows (the maintainer's platform), Linux and macOS.
  Use `pathlib` and don't depend on a particular shell.

## Definition of done

- `tools/check.py` reports `OK` for the work in question in **both** games (or
  it's marked `m`/`M` with a `NON_MATCHING` reason).
- `tools/lint.py`, `python -m pytest`, `ruff check .` and the clang-format check pass.
- No game data, keys or build output are staged (`git status` before committing).
- Commit or open a PR only when the user asks. Fill in the PR template,
  including the AI-assistance section.
- PRs land with rebase and merge (`gh pr merge --rebase`), the only method
  the repository allows. Every commit reaches `master` unchanged, so each
  one needs a real message. Rebase on `master`; don't merge it in.
