#pragma once
// The gflib3 object with vtable 0x710239d668 (Unk_239d658): what the setters
// of its interfaces at +0x198 and +0x1a0 (src/unsorted/Unk_633890.cpp and
// src/unsorted/Unk_633a10.cpp) write. Placeholder names.
#include <arm_neon.h>

#include <types.h>

#include "gflib3/Unk_239a418.h"

// A vector of four floats held in a NEON register: copying it copies the two
// halves in turn, the getters return it in q0.
struct Unk_239d658_Vector {
    float32x4_t value;
};
static_assert(sizeof(Unk_239d658_Vector) == 0x10, "Unk_239d658_Vector");

// 16 bytes copied as a whole (not a vector: it isn't 16-byte aligned).
struct Unk_239d658_1a8_a8 {
    u64 field_0;
    u64 field_8;
};
static_assert(sizeof(Unk_239d658_1a8_a8) == 0x10, "Unk_239d658_1a8_a8");

// The object the pointer at +0x1a8 points to.
struct Unk_239d658_1a8 {
    u8 _0[0xa8];
    Unk_239d658_1a8_a8 field_a8;
    u8 _b8[0x28];
    Unk_239d658_Vector field_e0;
    u8 _f0[0x10];
    Unk_239d658_Vector field_100;
    Unk_239d658_Vector field_110;
    Unk_239d658_Vector field_120;
    Unk_239a418_Ref<Unk_239a418_Handle> field_130;
};
PKMN_OFFSET_ASSERT(Unk_239d658_1a8, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_239d658_1a8, field_e0, 0xe0);
PKMN_OFFSET_ASSERT(Unk_239d658_1a8, field_100, 0x100);
PKMN_OFFSET_ASSERT(Unk_239d658_1a8, field_110, 0x110);
PKMN_OFFSET_ASSERT(Unk_239d658_1a8, field_120, 0x120);
PKMN_OFFSET_ASSERT(Unk_239d658_1a8, field_130, 0x130);
