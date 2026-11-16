# Contributing

Thanks for helping. This guide covers the whole loop: set up, claim work,
decompile, check, test, and open a PR. If you use an AI coding assistant, point
it at [AGENTS.md](AGENTS.md). That file holds the same rules in a form written
for assistants.

**The one hard rule:** never commit anything extracted from the game: binaries,
assets, keys, or large dumped tables. `.gitignore` covers the usual paths, and
`tools/lint.py` fails CI if something slips through anyway.

## 0. Set up

Follow [Getting started](README.md#getting-started) in the README to extract
both executables and install the toolchain. Then install the dev tools:

```sh
.venv/Scripts/pip install -r tools/requirements-dev.txt   # Linux/macOS: .venv/bin/pip
.venv/Scripts/pre-commit install                          # optional: run the CI checks on every commit
```

`tools/check.py` drives CMake with the Ninja generator, so `ninja` must be on
your `PATH`.

## 1. Claim something

The **unit of tracking** is a function (`data/functions.csv`), but **claim a
group**: a class (a vtable and its methods), a source file's worth of
neighbouring functions, or an address range. Struct layouts are shared across
a class, so splitting one class between people causes conflicts.

- Open a **Claim work** issue titled `Claim: <area> <address range or class>`.
  One claim per person at a time is a good default. Close it with the PR, or
  after two weeks without activity.
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
python tools/progress.py
```

## 2. Decompile

1. Name the function first: `tools/funcs.py name <addr> <mangled name>`. Use real
   names where there's evidence for them (library code, strings, RTTI, asserts).
   Otherwise use placeholders like `Unk_<addr>` for types and keep the address
   in a comment. A wrong confident name is worse than a placeholder.

   **Local symbols are file-qualified.** A `static` function or variable (or a
   C++ internal-linkage / anonymous-namespace symbol) is named
   `<symbol>@<file stem>`, where the stem is the compiled file's name without
   its extension: `getfield` in `lauxlib.c` is `getfield@lauxlib`, the one in
   `loslib.c` is `getfield@loslib`, and a function-local `static` is
   `utf8_decode.limits@lutf8lib`. Every local symbol is qualified, even if
   its name is unique today, and global symbols never are. `check.py`,
   `funcs.py`, `lint.py` and `compiler_sweep.py` all use this rule
   (`tools/symbols.py`). Moving a file to another directory keeps the names.
   Renaming the file renames its local symbols, and two files with the same
   stem can't both define the same local symbol (`check.py` stops with an error).

   Bulk naming: `tools/funcs.py name --from-file map.csv` applies a
   `Name,Sword,Shield` CSV, such as the one
   `tools/compiler_sweep.py ... --map-out map.csv` writes for library code.
2. Write the code under `src/<subsystem>/` (or `src/unsorted/`), or `lib/<library>/`.
   Put a comment with the Sword address (and the Shield address if it differs)
   above each function, and a `// Scope: <scope>` line at the top of the file.
3. Follow the function's **scope**:
   - `common`: plain code, with no `PKMN_*` version macros.
   - `common-data`: plain code. The per-game difference is in a referenced
     string or table, so select that data with `PKMN_SW_SH(...)`.
   - `diverged`: use `PKMN_SW_SH(sword, shield)` or `#if PKMN_IS_SWORD`
     where the games differ. Run `tools/funcs.py show <addr>` to see both.
   - `sword` / `shield`: wrap the whole function in `#if PKMN_IS_SWORD` / `#if PKMN_IS_SHIELD`.
4. Add `PKMN_SIZE_ASSERT` / `PKMN_OFFSET_ASSERT` (from `types.h`) for every
   reconstructed struct.

Look at `src/pkmn/Version.cpp`, `src/unsorted/Unk_7eef40.*` and
`lib/sol/enum_newindex.cpp` for small, complete examples.

### Code style

- C++17, formatted with **clang-format 19.1.7** using the repo's `.clang-format`
  (`clang-format -i <files>`; the pinned version comes with `requirements-dev.txt`).
  Code under `lib/` keeps its upstream formatting and is excluded.
- Write natural code, the way the original programmer would have. Don't reach
  for `volatile`, inline asm or meaningless temporaries to force a match without
  a `// NON_MATCHING` note explaining why.
- Python tooling: `ruff check .` must pass. Formatting isn't enforced, so
  match the style of the file you're editing.

## 3. Check (matching)

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

**Functions that aren't in the executable.** Library code (Lua, ...) is
vendored unchanged, so it can contain functions that aren't in the game: the
linker dropped them as unreferenced (`lua_setallocf`), or a whole file isn't
used (`lbitlib.c`). Keep upstream code as it is and list such functions in
`data/absent_functions.csv` (`Name,Reason`, sorted by name). `check.py` then
skips them instead of printing `??`. Removing them from the source could change
how the compiler inlines the functions around them. Use
`#if 0  /* not in Pokémon SwSh: <reason> */` ... `#endif` only where the game
clearly changed the source. For example, Game Freak's `os` library only
registers `os.clock`, so `luaopen_os` creates a table with 1 field and the other
`os_*` functions don't exist. Lint rejects an absent function that is also a
row of `functions.csv`.

A function is `O` only when it matches in every game it exists in. **Statuses
come from `check.py --update`, never from editing the CSV by hand.** If a
function can't match yet, submit it anyway with status `M` (or `m` for regalloc
or ordering-only differences), set via `tools/funcs.py status <addr> M`, and add
a `// NON_MATCHING: <reason>` comment above it.

## 4. Test

| Check | Command | Needs the game? | In CI? |
|---|---|---|---|
| Data + repo lint | `python tools/lint.py` | no | yes |
| Tooling unit tests | `python -m pytest` | no | yes (Linux + Windows) |
| Python lint | `ruff check .` | no | yes |
| C/C++ formatting | `clang-format --dry-run --Werror <files>` | no | yes |
| Compiles for both games | `cmake --preset sword && cmake --build --preset sword` (and `shield`) | no | yes, with distro clang |
| **Matching** | `python tools/check.py` | **yes** | **no**, paste the output into your PR |

`pre-commit run --all-files` runs everything in the table except the build and
`check.py`.

If you change anything under `tools/`, add or update a test in `tests/`. Tests
must not need game files. Build what you need inline (see `tests/test_refs.py`,
which hand-encodes AArch64 instructions), or use the `functions_csv` fixture
from `tests/conftest.py`. Anything that needs the real executables belongs in
`tools/check.py`.

## 5. Open a PR

- Branch from `master` and keep PRs small, ideally one claim. Everyone edits
  `functions.csv`, so small PRs rebase easily. On a conflict in that file,
  take `master`'s version and re-run your `tools/funcs.py name` /
  `tools/check.py --update` commands rather than merging it by hand.
- Fill in the PR template. The important part is the `tools/check.py` output,
  because CI cannot check matching.
- Commit messages: a short imperative subject (`Decompile Lua lstring.c`,
  `check.py: resolve GOT loads through the PLT`), with a body when the reason
  isn't obvious.
- CI must be green before merge.

## Using an AI assistant

AI assistants are welcome. The matching checker is an objective judge, so
generated code is verified the same way as hand-written code. Some rules:

- **You are responsible for what you submit.** Read the diff before you open
  the PR, the same as you would for your own code.
- Say in the PR template that an assistant helped, and with what.
- Assistants must follow [AGENTS.md](AGENTS.md). Claude Code loads it through
  [CLAUDE.md](CLAUDE.md), and most other assistants read `AGENTS.md` directly.
  The rules that matter most: never read out or commit keys or game data, never
  hand-edit statuses, and don't invent symbol names without evidence.
- Don't open PRs in bulk with generated, unchecked code. Every function in a PR
  must have been run through `tools/check.py`.

## Regenerating the function list

If the pairing logic in `tools/versiondiff.py` improves, run
`python tools/versiondiff.py --update-csv`. It keeps existing names and
statuses. Send that change as its own PR.
