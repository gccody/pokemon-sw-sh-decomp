# lib/freetype: FreeType 2.8.1

The FreeType that Silicon Studio's YEBIS links for SiGfx's font rendering
(`SiGfx_FreeType_Manager.cpp`, `SiGfx_FreeType_Face.h`), in the `yebis` area,
Sword and Shield `0x7100501c60`-`0x71005339d0`. It's built with clang 7.0.x
`-O3` and the game's global flags. See `docs/compiler.md`, section
"FreeType 2.8.1".

What's here, from `freetype-2.8.1.tar.gz` (unchanged but for the one change below):

- `include/`: FreeType's public, configuration and internal headers.
- `src/base`: `ftbase.c` (it #includes `ftadvanc.c` ... `ftutil.c`, all
  here), `ftsystem.c`, `ftinit.c`, `ftbitmap.c`, and the headers they read.
- `src/truetype`, `src/sfnt`, `src/smooth`, `src/pshinter`, `src/psnames`,
  `src/gzip`: the modules in the executable, each built as one TU
  (`truetype.c`, `sfnt.c`, `smooth.c`, `pshinter.c`, `psnames.c`, and
  `ftgzip.c` with the zlib it bundles), the way FreeType's own build does.
- `FTL.TXT`, `LICENSE.TXT`: FreeType's license. FreeType is dual-licensed;
  this copy is used under the FreeType License (FTL), a BSD-style license.

One change to an upstream file, marked `YEBIS:` in it:

- `src/base/ftobjs.c`, `FT_New_Memory_Face`: `args` is zero-initialised.
  The executable's (`0x7100504250`) zeroes all 0x40 bytes of it before the
  `file_base` check; no FreeType release from 2.8 to 2.10.1 does that.

Not from FreeType:

- `nx/freetype/config/ftmodule.h`: the module list. The executable's
  `FT_Init_FreeType` (`0x710050c880`, with `FT_Add_Default_Modules` inlined)
  adds 7 modules, whose names and flags are in their classes:
  `truetype`, `psnames`, `pshinter`, `sfnt`, `smooth`, `smooth-lcd` and
  `smooth-lcdv`. That is the default `ftmodule.h`'s order without the other
  drivers. `nx/` is searched before `include/`, as FreeType's
  `docs/CUSTOMIZE` describes for a custom configuration, so the upstream
  `include/freetype/config/ftmodule.h` stays as it is.

`CMakeLists.txt` compiles only the 10 TUs above of this directory (the files
they #include aren't TUs of their own), with `FT2_BUILD_LIBRARY` and
`lib/freetype/nx`, `lib/freetype/include` as include directories
(`pkmn_library_settings(lib/freetype ...)`). The default `ftoption.h` is
used.

The TUs that have no function in the executable (the other drivers, `psaux`,
the cache, the stroker, ...) aren't vendored. The functions of these TUs that
aren't in the executable either (unreferenced, so the linker dropped them)
are listed in `data/absent_functions.csv`.
