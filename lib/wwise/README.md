# lib/wwise: placeholders

Functions of Audiokinetic Wwise 2017.2 (the `wwise` area of `data/areas.csv`).
Its source isn't public, so nothing here is upstream code: `leaf/` is written
by `tools/leafgen.py` (`--out lib/wwise/leaf`), placeholder structs and
`Unk_<addr>` names like `src/unsorted/leaf`, from the executable. Wwise was
built with clang 6.0.1, not the game's 7.0.1 (docs/compiler.md, "Wwise"), so
this directory has its own `pkmn_library_settings` entry in `CMakeLists.txt`.
See docs/game_code.md, Batch 29.

`class/` (tools/leafgen.py members) holds its classes' small virtual functions as members `vf<slot>` of `Unk_<vtable>` classes (Wwise has no RTTI). See docs/game_code.md, Batch 39.
