#pragma once
// The owner of the creators (Unk_790260_Owner, placeholder): it makes classes
// on Unk_23f4660 (src/unsorted/Unk_23f4660.h) with its allocator and keeps a
// reference to each. Create<T> (the creators, src/gflib3/families/Unk_790260.cpp,
// tools/familygen.py) makes one; Unk_790140<T> (the creators' wrappers,
// src/gflib3/create, tools/creategen.py) gives it a parent and a place first.
#include <vector>

#include "unsorted/Unk_23f4660.h"
#include "unsorted/Unk_2771620.h"

using Unk_Ref = Unk_239a418_Ref<Unk_239a418>;

// The element of the owner's vector (its push_back's slow path is
// 0x7100790490, in src/gflib3/families/Unk_5ac520.cpp).
struct Unk_790490 : Unk_239a418 {};

class Unk_790260_Owner {
public:
    // The parent by value: the wrappers copy theirs for the call and drop
    // the copy after it. The name is the new object's (Unk_23f4660::field_5c0):
    // the wrappers' callers pass string literals.
    template <class T>
    Unk_239a418_Ref<T> Create(Unk_Ref parent, const char* name);
    // Create<T> under `parent` (field_58 when it's null), then hands the new
    // object to `target` (field_70 when it's null) through Unk_e809c0_call.
    template <class T>
    Unk_239a418_Ref<T> Unk_790140(Unk_Ref parent, Unk_23f4660* target, const char* name);

    u64 field_0;
    Unk_239a418_Allocator* field_8;
    u8 _10[0x48];
    Unk_Ref field_58;
    u8 _60[0x10];
    Unk_23f4660* field_70;
    std::vector<Unk_239a418_Ref2<Unk_790490>, Unk_2771620_Allocator<Unk_239a418_Ref2<Unk_790490>>>
        field_78;
    u64 field_a8;
    u8 _b0[0x10];
    bool field_c0;
};
PKMN_OFFSET_ASSERT(Unk_790260_Owner, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_790260_Owner, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_790260_Owner, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_790260_Owner, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_790260_Owner, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_790260_Owner, field_c0, 0xc0);
