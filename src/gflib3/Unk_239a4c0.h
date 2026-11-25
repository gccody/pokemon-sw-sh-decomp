#pragma once
// gflib3's other reference-counted object (vtable 0x710239a4c0): it keeps its
// count itself, at +0x50, where Unk_239a418 keeps it in a handle. 256 other
// vtables have its vf3 and vf4 (slots 3 and 4): 212 its vf2 as well, among
// them Unk_2398c40 (vtable 0x7102398c40), and 44 override vf2. Placeholder
// names: rename once the classes are known.
//
// Its primary base and the interface at +0x48 declare the same functions (add
// a reference, drop one), so one override fills both vtables: the +0x48
// vtable gets this-adjusting thunks with the body inlined. vf2 destroys the
// object and gives its memory back to its allocator, as Unk_239a418::vf3
// does; the family's operator delete is empty.
//
// Its destructor is inline and empty, and none of its fields has a
// destructor, so its D2 stores no vptrs: it is a `ret`. Every copy of it is
// one function, the linker's (0x710000d500, emitted with an earlier TU's
// static object of a class on it), and a derived class with nothing to
// destroy uses it as its own D2 (docs/game_code.md, "Bases"): Unk_2399470
// (vtable 0x7102399470) does. Its D0 and the thunks of both are `ret`s too.
//
// vf2 is its key function, defined in Unk_239a418's TU (src/gflib3/
// Unk_5e2700.cpp): its D0 and thunks follow the object's functions there. vf3
// and vf4 are inline: their one copy (0x71005cfe90-0x71005cff4c) is the one
// emitted with Unk_2399470's vtable, in an earlier TU.
//
// The classes themselves are in src/gflib3/Unk_239a418.h: the handle
// Unk_239a418 keeps its count in is on this object.
#include "gflib3/Unk_239a418.h"
