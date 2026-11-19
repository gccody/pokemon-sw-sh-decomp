# lib/nx_middleware: placeholders

Functions of NEX 4.6.8, Pia 5.18, NintendoWare and the nn SDK static libraries (the `middleware` and `middleware-nw` areas of `data/areas.csv`). Their source isn't public, so nothing here is upstream
code: `leaf/` is written by `tools/leafgen.py` (`--out lib/nx_middleware/leaf`), placeholder
structs and `Unk_<addr>` names like `src/unsorted/leaf`, from the executable.
Rename them when the library's real names are known (its RTTI names some of
its classes). They're built with the game's flags: docs/compiler.md, "Nintendo
SDK middleware" and "Other middleware". See docs/game_code.md, Batch 22.

`class/` (tools/leafgen.py members) holds the RTTI-named classes' small virtual functions, placeholder member names `vf<slot>`. See docs/game_code.md, Batch 39.
