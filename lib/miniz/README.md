# lib/miniz: miniz 1.15 (r4)

The miniz that Silicon Studio's YEBIS keeps in its own tree as
`src/GPU/miniz.c` (`__FILE__` `../src/GPU/miniz.c`), in the `yebis` area,
Sword and Shield `0x710045fe50`-`0x7100461d5c`. Built with clang 7.0.x `-O3`
and the game's global flags, like YEBIS's zlib. See `docs/compiler.md`,
section "miniz 1.15".

`miniz.c` is Rich Geldreich's single-file miniz v1.15, the last commit of the
single-file era (`28f5066e33`, 2013-10-14, released as `miniz_v115_r4`). It's
public domain (the Unlicense statement at its end). It's unchanged but for the
three lines marked `YEBIS:`, each replaced in place so that every line keeps
its number: the executable's `def_alloc_func` passes `__LINE__` 1010, which is
`def_alloc_func`'s line in upstream r4 and in no earlier commit.

- line 940 (blank upstream): `#include "miniz_yebis.h"`
- line 946: `MZ_MALLOC(x)` calls YEBIS's allocation function with YEBIS's
  allocator, `x`, `__FILE__`, `__LINE__` and 0
  (`def_alloc_func`, `0x710045fe50`, and the copy inlined into
  `mz_uncompress`), in place of `malloc(x)`
- line 947: `MZ_FREE(x)` calls YEBIS's free function with the allocator and `x`
  (`def_free_func`, `0x710045fe80`), in place of `free(x)`

`MZ_REALLOC` is upstream's `realloc`: its users (`def_realloc_func`,
`tinfl_decompress_mem_to_heap`, the zip writer) aren't in the executable, so
nothing says what YEBIS used. How YEBIS spelled the redirection isn't known
either; any spelling that keeps line 1010 gives the same code. (YEBIS's
`__FILE__` literals include `../src/GPU/GPUMemoryAllocator.h`, a candidate for
where its macros live.)

`miniz_yebis.h` isn't part of miniz: it declares the YEBIS allocator with C
linkage and placeholder names (`Unk_238d5f8`, `Unk_4b99a0`, `Unk_4b9a60`),
whose definitions are in `lib/yebis/leaf/Unk_4b99a0.cpp`.

Of the 82 functions `miniz.c` compiles, 5 are in the executable:
`def_alloc_func`, `def_free_func`, `mz_inflate`, `tinfl_decompress` and
`mz_uncompress`, in that order (clang lays out a TU's functions in the order it
first references or defines them, and `mz_inflate` references
`tinfl_decompress`, which upstream defines later). The other 77, among them
`mz_inflateInit`, `mz_inflateInit2` and `mz_inflateEnd`, which are inlined into
`mz_uncompress`, are in `data/absent_functions.csv`.
`data/source_paths.csv` maps `../src/GPU/miniz.c` onto this directory.
