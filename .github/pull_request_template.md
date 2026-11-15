<!--
Thanks for contributing! Keep PRs small (ideally one claim) so the
functions.csv changes rebase cleanly. See CONTRIBUTING.md.
-->

## What this does

<!-- Class / file / address range, and anything a reviewer should know. -->

Closes #<!-- claim issue number, if any -->

## `tools/check.py` output

CI has no game files, so it can't check matching. Paste the summary from
`python tools/check.py <names...>`. Include `--diff` output for anything not `OK`.

```
```

## Checklist

- [ ] `python tools/check.py` was run against **both** Sword and Shield, and the statuses in `data/functions.csv` come from `--update` (not edited by hand)
- [ ] Non-matching functions are marked `m`/`M` and have a `// NON_MATCHING: <reason>` comment
- [ ] Code follows each function's scope (no `PKMN_*` macros in `common` code)
- [ ] Reconstructed structs have `PKMN_SIZE_ASSERT` / `PKMN_OFFSET_ASSERT`
- [ ] `python tools/lint.py` and `python -m pytest` pass, and the code is `clang-format`ted
- [ ] Nothing extracted from the game is included (binaries, assets, large dumped tables, keys)

## AI assistance

<!-- Not a problem, but reviewers want to know. check.py is the judge of
     correctness either way. -->

- [ ] No AI tools were used
- [ ] An AI assistant helped (say which, and with what: naming, struct layouts, code, tooling)
