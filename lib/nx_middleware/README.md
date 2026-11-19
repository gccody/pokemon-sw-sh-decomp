# lib/nx_middleware: placeholders

Functions of NEX 4.6.8, Pia 5.18, NintendoWare and the nn SDK static libraries (the `middleware` and `middleware-nw` areas of `data/areas.csv`). Their source isn't public, so nothing here is upstream
code: `leaf/` is written by `tools/leafgen.py` (`--out lib/nx_middleware/leaf`), placeholder
structs and `Unk_<addr>` names like `src/unsorted/leaf`, from the executable.
Rename them when the library's real names are known (its RTTI names some of
its classes). They're built with the game's flags: docs/compiler.md, "Nintendo
SDK middleware" and "Other middleware". See docs/game_code.md, Batch 22.

`class/` (tools/leafgen.py members) holds the RTTI-named classes' small virtual functions, placeholder member names `vf<slot>`. See docs/game_code.md, Batch 39.

`gfx/` and `font/` are decompiled by hand. `gfx/` is NintendoSDK_gfx 7.3.2's
NVN code (its SDK MW tag is referenced from Sword `0x7101787740`): `nvn.h`
declares NVN's C entry points, the globals that the loader at
`0x7101789d10` fills by name (each named after its Sword address, with an
inline function named after the string the loader looks it up by), and
`gfx.h` the structs that more than one TU uses. The TUs follow the inlining
in the executable: a function that the original calls instead of inlining
is in another file. `PrimitiveShape.cpp` is `nn::gfx::util::PrimitiveShape`
and `CircleShape` (RTTI names). See docs/compiler.md, "NintendoSDK_gfx".

