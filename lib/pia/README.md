# lib/pia: Pia 5.18.0

Nintendo's networking middleware (SDK MW tags `PiaCommon-5_18_0`,
`Pia-5_18_0`, `PiaLan-5_18_0`, `PiaLocal-5_18_0`,
`PiaNex-5_18_0-forNEX-4_6_2`, `PiaSession-5_18_0`, `PiaTransport-5_18_0`),
the second part of the `middleware` area in `data/areas.csv` (Sword
`0x7101651510` on, after NEX). Its source isn't public: everything here is
decompiled from the executable.

- **Names.** Classes with a vtable have RTTI, and their names are its
  (`N2nn3pia6common10Md5ContextE` is `nn::pia::common::Md5Context`). Member
  functions keep placeholder names: `vf<slot>` for virtual functions (as
  `tools/leafgen.py members` names them), `Unk_<addr>` otherwise. Types
  without RTTI are `Unk_<addr>`, after a function of theirs (their copy
  constructor, their serializer), and a struct only known as a function's
  object is `Unk_<addr>_arg0`.
- **Build.** The game's clang and global flags, plus `-fno-builtin`
  (`pkmn_library_settings(lib/pia ...)` in `CMakeLists.txt`; the evidence is
  in docs/compiler.md, "Pia 5.18.0").
- **Layout.** One directory per namespace (`common`, ...), one file per class
  or per group of functions that sit together in the executable. `gen/` is
  written by `tools/piagen.py write` (one file per class: the families of
  small members it recognises, the network factories' create and destroy
  members and the members that return a fixed result); don't edit it by
  hand, rerun the tool.
- **Result.** Most functions return `nn::pia::Unk_165e060`, Pia's result
  type (`common/Unk_165e060.h`): a 32-bit value and an
  `nn::err::ErrorResultVariant`. A function that returns a fixed value
  copies it into the caller's result (the copy constructor), so those
  returns are written `return Unk_165e060Value<value>();`, a derived type
  that slices. A local result is constructed in place: `Unk_165e060 result(0);`.
- **What it calls.** Pia's functions that tools/leafgen.py matched
  (`lib/nx_middleware/leaf`, `lib/nx_middleware/class`) keep their names;
  the classes written here take over their `class/` members (that file is
  removed). The SDK's functions are declared in `include/nn` from the
  imports' mangled names.

Functions marked `// NON_MATCHING` compile to code that's close but not the
same; their reason is in the comment, and their status is `M`.
