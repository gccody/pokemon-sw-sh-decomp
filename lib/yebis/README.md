# lib/yebis: placeholders

Functions of Silicon Studio YEBIS 3 (the `yebis` area of `data/areas.csv`). Their source isn't public, so nothing here is upstream
code: `leaf/` is written by `tools/leafgen.py` (`--out lib/yebis/leaf`), placeholder
structs and `Unk_<addr>` names like `src/unsorted/leaf`, from the executable.
Rename them when the library's real names are known (its RTTI names some of
its classes). They're built with the game's flags: docs/compiler.md, "Nintendo
SDK middleware" and "Other middleware". See docs/game_code.md, Batch 22.
