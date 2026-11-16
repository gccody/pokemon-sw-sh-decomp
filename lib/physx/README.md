# NVIDIA PhysX 3.4 (PhysX SDK and PxShared)

The PhysX in Sword and Shield, `0x7100010a90`-`0x71003035e0` in both games.
It is the public `v3.4.2` tag of
[NVIDIAGameWorks/PhysX-3.4](https://github.com/NVIDIAGameWorks/PhysX-3.4)
(`b99b378`, "patch release @24214033"), built with clang 6.0.1. See
`docs/compiler.md`, "PhysX", for the evidence. Only the 385 translation units
in the executable are here, with the headers they read. The layout is
upstream's, so the `__FILE__` paths resolve the same way
(`data/source_paths.csv`).

## Where the text comes from

- **Every file starts from the repository's HEAD revision** (Perforce CL
  25354359), which NVIDIA released under the 3-clause BSD license in
  [LICENSE.md](LICENSE.md). Upstream formatting is kept. `lib/.clang-format`
  disables formatting here. Line endings are LF, like the rest of the
  repository (`.gitattributes`), where upstream has CRLF.
- **83 files need v3.4.2's code in a few places**, where HEAD's code compiles
  differently from the binary. v3.4.2 isn't BSD-licensed, so **those files
  aren't in the repository**. Generate them before building:

  ```sh
  python tools/get_physx.py              # downloads ~170 files from NVIDIA's public repository
  python tools/get_physx.py --clone DIR  # or reads them from a local PhysX-3.4 clone
  ```

  Each file is HEAD's text with v3.4.2's version of every hunk whose code
  differs. Hunks that differ only in comments keep HEAD's text. Line 1 (the
  license block's empty `//` line) lists the lines that are v3.4.2's. Every
  line stays on its v3.4.2 line number, because `__LINE__` is part of the code
  (`PX_ALLOC`, error reports). `data/physx_v342.csv` lists the files with
  their SHA-256, `.gitignore` here keeps them out of git, and CMake won't
  configure until they're all there and up to date.
- **The Nintendo Switch platform sources aren't public.** These files are
  reconstructed from the binary, and each says so in a "Pokemon SwSh decomp"
  comment after the license block:
  - `PxShared/src/foundation/src/switch/PsSwitch{Atomic,FPU,Mutex,PrintString,SList,Sync,Thread}.cpp`.
    The binary names `PsSwitchMutex.cpp` and `PsSwitchPrintString.cpp` in
    `__FILE__` strings. The other names follow upstream's per-platform naming
    (`unix/PsUnixAtomic.cpp`, ...). The original's `__LINE__` values are pinned
    with `#line`.
  - `PhysX_3.4/Source/PhysX/src/switch/NpMiddlewareInfo.cpp` and
    `PhysX_3.4/Source/PhysXExtensions/src/switch/ExtSwitchDefaultCpuDispatcher.cpp`.
    Both file names are guesses.
  - The headers `PxSwitchIntrinsics.h`, `PsSwitchIntrinsics.h`,
    `PsSwitchAbort.h` and `NpMiddlewareInfo.h`. Only the inline functions that
    the code shows (`PxIsFinite`, `lowestSetBitUnsafe`, `highestSetBitUnsafe`)
    are known to be right. The rest are the Unix versions.

The Switch code calls the Nintendo SDK through `include/nn/os.h`. That file
holds only the declarations whose mangled names the binary imports.
