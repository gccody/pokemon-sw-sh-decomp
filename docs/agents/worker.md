# Worker instructions (parallel units)

This is the brief each parallel worker gets, with `{UNIT}` filled in. The
main thread creates the worker's worktree and branch, and does everything
that touches the stack afterwards: `tools/integrate.py`, the PR, and
`ghidra.sh refresh`. The tools are `tools/units.py`, `tools/context.py`,
`tools/worktree_setup.py` and `tools/integrate.py`. See their docstrings.

## How the main thread runs a unit

```sh
# in the stack worktree, at the stack tip
python tools/worktree_setup.py create ../swarm-w-<unit> --branch swarm-unit/<unit> --unit <unit> --workers 6
# ... the worker runs, commits to swarm-unit/<unit> ...
python tools/integrate.py swarm-unit/<unit> --new-branch swarm/<NNN>-<unit>
git push -u origin swarm/<NNN>-<unit>      # then the PR, from .swarm/integrate-<unit>.md
python tools/worktree_setup.py teardown ../swarm-w-<unit> --force   # --force: its functions.csv is changed
git branch -D swarm-unit/<unit>
```

The pilot (unit `u7e97b0`, 9 functions, 2026-11-24) took one first build of
2m40s at `-j10` (both games), check runs of ~10 s after it, and an
integration of ~30 s. With 6 workers at `-j3`, plan on a first build of
several minutes per worker.

## The brief

You are one of several parallel workers on a matching decomp. Read AGENTS.md
first. Its hard rules apply to you, especially: never print game data or
keys, never invent symbol names, and never force a match with volatile,
inline asm or junk temporaries. Don't start subagents or forks.

Your unit: `{UNIT}`. Your worktree is `{WORKTREE}` (work only there; run every
command from it). Run `python tools/worktree_setup.py` first (use the venv's
python, `.venv/bin/python`), then `python tools/units.py show {UNIT}`.

**Files.** Only edit the source files `units.py show` lists for your unit.
You may also:

- create headers next to one of them, named after it (`<stem>*.h`);
- create `Unk_<addr>.cpp` (`addr` = one of your functions, as in the other
  file names) in the same directory, when a function needs a TU of its own.
  That's the case when it calls a function defined in its file: clang would
  inline the callee, and the original calls it. `context.py` flags this with
  `!`.

Don't edit other files, not even shared headers. If you need a declaration,
write it in your own file. Never touch generated directories
(`src/unsorted/{leaf,virtual,ctor,types,clone,families,init,locks,registry}`,
`src/gflib3/families`, `lib/*/leaf`, `lib/*/class`, `lib/pia/gen`,
`lib/nex/ddl`). Their files are rewritten by tools.

**For each function, smallest first:**

1. Read `python tools/context.py <addr>`.
2. Write the function the AGENTS.md way: the `// 0x71...` address comment
   above it, the `// Scope:` line at the top of the file, and size/offset
   asserts on every struct you reconstruct. Follow the matched examples in
   the bundle and the existing code around your file. Treat the Ghidra
   pseudo-C as a draft of the logic (control flow, struct offsets, switches),
   not as source. Rewrite it as natural C++ with real types, and never copy
   Ghidra's names (`FUN_...`, `param_1`, `local_...`, `undefined4`) or its casts.
3. Run `python tools/check.py <name> --diff` and iterate. Pass several names
   at once to save builds. A check after an edit takes ~10 s once the first
   build is done. The first `check.py` builds everything (several minutes).
   Run it once, early, so later runs are fast.
4. Budget: at most 8 `check.py` runs per function. Then submit your best
   natural version as m/M with a `// NON_MATCHING: <reason>` comment above it,
   and record it:
   `python tools/units.py record status <addr> m|M "<reason>"`
   (`m`: only register allocation or ordering differs; `M`: anything else).
5. Names: a function that has a name in `data/functions.csv` keeps it. Its
   callers were written against it, and renaming breaks them. A new name
   needs evidence (a string, an assert, RTTI, an SDK import, upstream
   source). A name Ghidra made up is not evidence. Without evidence, use a
   placeholder (`Unk_<addr>`, `Unk_<addr>_<what>` for members). Record every
   name you give:
   `python tools/units.py record name <addr> <mangled> --evidence "<what shows it>"`.
   That also applies it to your local functions.csv, so check.py can find it.
6. Skip what can't be written naturally yet, and say why in the report. For
   example: a constructor or member of a class that a generator owns, or a
   thunk whose target class isn't declared.

**Lessons from the pilot:**

- A callee in the same TU gets inlined (above).
- Return types aren't in the mangled name. If a callee declared elsewhere as
  `u32` really returns a 0/1 flag, declare it `bool` in your file when the
  original's code says so (a tail call where a `cmp`/`cset` would otherwise
  appear).
- The parameter types *are* in the name. When the existing name's types
  can't give the original's code (for example a `u8` the callers declared as
  `u32`), submit it as m/M and say so. Don't rename it.

**Never** run `check.py --update`, commit `data/functions.csv` or
`data/data_symbols.csv`, run `ghidra.sh` or `analyzeHeadless`, push, open
PRs, or `git stash`. The main thread does those.

**Commits.** Commit to your branch every function or two, with a real
message (`<area>: <what the functions are>`), adding your source files by
path (`git add <files>`, never `git add -A` or `-a`, which would take your
local functions.csv). End messages with the `Co-Authored-By` line the main
thread gives you.

**At the end**, write the report into the sidecar with
`python tools/units.py record report "<text>"` (or `@file`). Cover what
matched, what's m/M and why, what you skipped and why, and anything that
would help later: a struct to recover first, or a repeated pattern that
should become a generator (docs/agents/generators.md). Then reply with the
same summary and the branch's last commit.
