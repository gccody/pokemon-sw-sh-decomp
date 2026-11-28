# Worker instructions (parallel units)

A coordinator splits the remaining work into units (`tools/units.py`) and
runs several AI workers at once, one unit each, in worktrees of their own.
The section "The brief" below is the template every worker gets:
`tools/swarm.py brief` fills in the unit, the paths and the co-author line,
so nobody writes briefs by hand. Edit the template here, not a copy. The
placeholders are `{UNIT}`, `{WORKTREE}`, `{BRANCH}`, `{MAIN}`, `{PY}`,
`{COAUTHOR}` and `{BASE}`; a line whose placeholder has no value is dropped.

The tools are `tools/swarm.py` (the coordinator's steps), `tools/units.py`,
`tools/context.py`, `tools/worktree_setup.py` and `tools/integrate.py`. See
their docstrings.

## How the coordinator runs a unit

The coordinator works in a worktree of its own (never the main checkout,
which other sessions may use), on a batch branch `swarm/batch-<N>`:

```sh
python tools/worktree_setup.py create ../swarm-main --branch swarm/batch-1 --base origin/master
cd ../swarm-main
python tools/swarm.py init                       # the batch state, .swarm/batch.json
python tools/swarm.py start <unit>               # ../swarm-w-<unit> + the filled-in brief
# ... hand the brief to a worker; it commits to swarm-unit/<unit> ...
python tools/swarm.py finish <unit> --next <next unit>   # integrate + reuse its worktree + next brief
python tools/swarm.py finish <unit>              # ... or tear the worktree down
python tools/swarm.py status                     # batch, open PR, workers
python tools/swarm.py metrics                    # functions/h, units/h, coordinator min/unit, CI runs
```

`finish` is the whole per-unit step: `integrate.py` onto the batch (with its
checks; on a failure the batch goes back to where it was and the worker's
worktree stays for the fix), the unit's PR section, the worktree reused or
torn down, the unit branch deleted. Then it syncs and, when the batch is due,
opens the batch PR.

**Batch PRs.** Units collect on the batch branch, one commit group per unit,
and the coordinator's fix-ups (a rename, a shared header) are committed there
too. Every 8 units or 60 minutes (`--batch-size`, `--batch-minutes`), `open`
pushes the batch and opens one PR with every unit's section, with auto-merge
(rebase) on that PR only. One batch PR is open at a time. Units finished while
it waits for CI go on the next batch branch, which stays local; when the PR
lands, `sync` replays them onto origin/master. Nothing on GitHub restacks,
so CI runs once per batch instead of once per unit per restack.

Ghidra: only the coordinator runs `.cache/ghidra/ghidra.sh` (it locks the
project), e.g. `ghidra.sh refresh all` with `PKMN_REPO` set to the batch
worktree, between batches.

Timings (2026-11-28, 20 cores): a cold build of both games takes ~2.5 min
(~30 s from a warm ccache in the same worktree; a new worktree's paths
differ, so ccache doesn't share between worktrees), an incremental check.py
10-20 s, and `finish` about a minute, mostly the full check.py run.

## The brief

You are one of several parallel workers on a matching decompilation
(Pokémon Sword/Shield, C++ that clang 7 must compile to the original
executable's instructions). Do the work yourself: don't start subagents or
forks.

Your unit: `{UNIT}`. Your worktree: `{WORKTREE}` (branch `{BRANCH}`, already
checked out there, started at `{BASE}`).

Your shell may start in `{MAIN}`. That is the main checkout, and other
sessions work in it: never edit, build, stash, commit or check out anything
there. Start every shell command with `cd {WORKTREE} && ...`, and edit files
by absolute path under `{WORKTREE}`.

Read `AGENTS.md` first. Its hard rules apply to you, especially: never print
game data or keys, never invent symbol names, and never force a match with
volatile, inline asm or junk temporaries. Then run `{PY} tools/worktree_setup.py`
(safe to run again) and `{PY} tools/units.py show {UNIT}`. Use `{PY}` for
every tool and the venv's clang-format (`.venv/bin/clang-format -i <file>`)
before committing.

Start the first build early: your first `{PY} tools/check.py <name>` builds
both games (a few minutes; a reused worktree is quicker), later runs take
10-20 s. Never start a second check.py while one runs in your worktree, and
never wait on a build with a loop that greps the process list (it matches its
own command line and never ends): run check.py in the foreground.

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
`lib/nex/ddl`, and any other listed in `tools/units.py` `GENERATED_DIRS`):
tools rewrite their files. Before you declare a callee, check
`data/functions.csv` (if it's named, use that name's signature: other workers
name shared callees too) and grep the sources for its address comment (it may
already be defined, e.g. in `src/unsorted/leaf`). Slots of classes a generator
declares (`lib/*/class`, `src/unsorted/virtual`, ...) or a shared header you
can't edit may be written as placeholder free functions over self structs;
destructor thunks of multiply-inherited classes need the class declared with
its bases: skip those with that reason.

**For each function, smallest first:**

1. Read `{PY} tools/context.py <addr>`.
2. Write the function the AGENTS.md way: the `// 0x71...` address comment
   above it, the `// Scope:` line at the top of the file, and size/offset
   asserts on every struct you reconstruct. Follow the matched examples in
   the bundle and the existing code around your file. Treat the Ghidra
   pseudo-C as a draft of the logic (control flow, struct offsets, switches),
   not as source. Rewrite it as natural C++ with real types, and never copy
   Ghidra's names (`FUN_...`, `param_1`, `local_...`, `undefined4`) or its casts.
3. Run `{PY} tools/check.py <name> --diff` and iterate. Pass several names
   at once to save builds.
4. Budget: at most 8 `check.py` runs per function. Then submit your best
   natural version as m/M with a `// NON_MATCHING: <reason>` comment above it,
   and record it:
   `{PY} tools/units.py record status <addr> m|M "<reason>"`
   (`m`: only register allocation or ordering differs; `M`: anything else).
5. Names: a function that has a name in `data/functions.csv` keeps it. Its
   callers were written against it, and renaming breaks them. A new name
   needs evidence (a string, an assert, RTTI, an SDK import, upstream
   source). A name Ghidra made up is not evidence. Without evidence, use a
   placeholder (`Unk_<addr>`, `Unk_<addr>_<what>` for members). Record every
   name you give:
   `{PY} tools/units.py record name <addr> <mangled> --evidence "<what shows it>"`.
   That also applies it to your local functions.csv, so check.py can find it.
6. Skip what can't be written naturally yet, and say why in the report. For
   example: a constructor or member of a class that a generator owns, or a
   thunk whose target class isn't declared.

**Lessons from earlier runs:**

- A callee in the same TU gets inlined (above).
- Return types aren't in the mangled name. If a callee declared elsewhere as
  `u32` really returns a 0/1 flag, declare it `bool` in your file when the
  original's code says so (a tail call where a `cmp`/`cset` would otherwise
  appear).
- The parameter types *are* in the name. When an existing placeholder name's
  parameter types keep a function from matching (a `u8` its name gives as
  `u32`, a variadic callee named with fixed parameters), and the callee's own
  instructions say what the types are, fix the signature yourself if
  `tools/retype.py` is there (see its docstring and the "Retyping a callee"
  section of docs/agents/worker.md); otherwise submit m/M and put
  `RENAME <addr> <current mangled> -> <proposed mangled>` in your report.

**Never** run `check.py --update`, commit `data/functions.csv` or
`data/data_symbols.csv`, run `ghidra.sh` or `analyzeHeadless`, push, open
PRs, or `git stash`. The coordinator does those.

**Commits.** Commit to your branch every function or two, with a real
message (`<area>: <what the functions are>`), adding your source files by
path (`git add <files>`, never `git add -A` or `-a`, which would take your
local functions.csv).

End every commit message with this line: {COAUTHOR}

Keep going until every function of the unit is matched, recorded as m/M, or
skipped with a reason. Aim for 1-2 hours of work; if one function eats its
budget, move on.

**At the end**, write the report into the sidecar with
`{PY} tools/units.py record report "<text>"` (or `@file`). Cover what
matched, what's m/M and why, what you skipped and why, and anything that
would help later: a struct to recover first, or a repeated pattern that
should become a generator (docs/agents/generators.md). Make sure everything
is committed (`git status` shows only data/functions.csv and
data/data_symbols.csv modified). Then reply with the counts (matched / m/M /
skipped), the one-line reasons for m/M and skips, and the branch's last
commit hash.
