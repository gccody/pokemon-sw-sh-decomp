#pragma once
// gflib3's heap scope (src/gflib3/Unk_65d670.cpp): while one is alive, the
// heap it was given takes the default heap's place, for the calling thread
// only or for all of them. Its constructor and destructor are out of line;
// callers pass the scope's address (a local of one byte) though neither
// function uses it. Placeholder names: rename once the class is known.
#include <types.h>

class Unk_239a418_Allocator;

class Unk_65da00_Scope {
public:
    // `heap` is gflib3's heap, the allocator its reference-counted objects
    // are made with (Unk_239a418_Base::field_8).
    Unk_65da00_Scope(Unk_239a418_Allocator* heap, bool value, bool thisThreadOnly);
    ~Unk_65da00_Scope();
};
