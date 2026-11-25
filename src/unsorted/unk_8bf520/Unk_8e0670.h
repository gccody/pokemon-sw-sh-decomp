#pragma once
// The object with vtable 0x71023bc560 (Unk_23bc550, its type getter is
// src/unsorted/types/Unk_8e1510.cpp) and the two blocks of data it holds at
// +0x180 and +0x188 (src/unsorted/unk_8bf520/Unk_8e1620.cpp makes the first
// and declares both classes), as what reads them sees them: plain pointers,
// laid out to the fields the readers use. Each block ends in a 16-bit value
// that follows what Unk_65c7c0 computes over the rest. Placeholder names:
// rename once the classes are known.
#include <types.h>

u16 Unk_65c7c0(void* data, u32 size);

// Strings, one per language (Unk_8e0840 picks one).
static constexpr u32 Unk_8e0670_LanguageCount = 9;

struct Unk_8e0670_Text1 {
    u16 field_0[37];
    u16 field_4a[199];
};
PKMN_SIZE_ASSERT(Unk_8e0670_Text1, 0x1d8);

struct Unk_8e0670_Text2 {
    u16 field_0[37];
    u16 field_4a[37];
};
PKMN_SIZE_ASSERT(Unk_8e0670_Text2, 0x94);

// An entry of the first block's list (Unk_8e0f50 looks one up).
struct Unk_8e0670_Entry {
    u16 field_0;
    u8 field_2;
    u8 _3;
};
PKMN_SIZE_ASSERT(Unk_8e0670_Entry, 4);

// The first block's object (Unk_23bc600, 0x2360 bytes): its data from +0x60.
struct Unk_8e0670_Block1 {
    u8 _0[0x60];
    u32 field_60[0x400];
    Unk_8e0670_Entry field_1060[40];
    u8 _1100[4];
    Unk_8e0670_Text1 field_1104[Unk_8e0670_LanguageCount];
    u16 field_219c[9];
    u8 field_21ae[9];
    u8 field_21b7[0x80];
    u8 field_2237[0x80];
    u8 _22b7[0x80];
    u8 field_2337[8];
    u8 field_233f[4];
    u8 field_2343;
    u8 _2344;
    u8 field_2345;
    u8 _2346[6];
    u8 field_234c;
    u8 field_234d;
    u8 field_234e;
    u8 field_234f;
    u8 field_2350;
    u8 field_2351;
    u8 field_2352;
    u8 field_2353;
    u8 field_2354;
    u8 _2355[3];
    u8 field_2358;
    u8 field_2359;
    u8 field_235a;
    u8 _235b;
    u16 field_235c;
    u8 _235e[2];
};
PKMN_OFFSET_ASSERT(Unk_8e0670_Block1, field_1060, 0x1060);
PKMN_OFFSET_ASSERT(Unk_8e0670_Block1, field_1104, 0x1104);
PKMN_OFFSET_ASSERT(Unk_8e0670_Block1, field_219c, 0x219c);
PKMN_OFFSET_ASSERT(Unk_8e0670_Block1, field_21ae, 0x21ae);
PKMN_OFFSET_ASSERT(Unk_8e0670_Block1, field_21b7, 0x21b7);
PKMN_OFFSET_ASSERT(Unk_8e0670_Block1, field_2237, 0x2237);
PKMN_OFFSET_ASSERT(Unk_8e0670_Block1, field_2337, 0x2337);
PKMN_OFFSET_ASSERT(Unk_8e0670_Block1, field_233f, 0x233f);
PKMN_OFFSET_ASSERT(Unk_8e0670_Block1, field_2343, 0x2343);
PKMN_OFFSET_ASSERT(Unk_8e0670_Block1, field_2345, 0x2345);
PKMN_OFFSET_ASSERT(Unk_8e0670_Block1, field_234c, 0x234c);
PKMN_OFFSET_ASSERT(Unk_8e0670_Block1, field_2352, 0x2352);
PKMN_OFFSET_ASSERT(Unk_8e0670_Block1, field_2354, 0x2354);
PKMN_OFFSET_ASSERT(Unk_8e0670_Block1, field_2358, 0x2358);
PKMN_OFFSET_ASSERT(Unk_8e0670_Block1, field_235c, 0x235c);
PKMN_SIZE_ASSERT(Unk_8e0670_Block1, 0x2360);

// A date: year, month and day.
struct Unk_8e0670_Date {
    u32 field_0;
    u32 field_4;
    u32 field_8;
};

// The second block's object (Unk_23bc6b0, 0x6a8 bytes): its data from +0x60.
struct Unk_8e0670_Block2 {
    u8 _0[0x60];
    u8 _60[4];
    Unk_8e0670_Text2 field_64[Unk_8e0670_LanguageCount];
    u8 _598[9];
    u8 field_5a1;
    u8 field_5a2;
    u8 _5a3[5];
    u32 field_5a8[12];
    Unk_8e0670_Date field_5d8;  // from
    Unk_8e0670_Date field_5e4;  // to
    u16 field_5f0[13];
    u8 _60a[0xa];
    u32 field_614;
    u8 _618[0x88];
    u16 field_6a0;
    u8 _6a2[6];
};
PKMN_SIZE_ASSERT(Unk_8e0670_Block2, 0x6a8);
PKMN_OFFSET_ASSERT(Unk_8e0670_Block2, field_64, 0x64);
PKMN_OFFSET_ASSERT(Unk_8e0670_Block2, field_5a1, 0x5a1);
PKMN_OFFSET_ASSERT(Unk_8e0670_Block2, field_5a8, 0x5a8);
PKMN_OFFSET_ASSERT(Unk_8e0670_Block2, field_5d8, 0x5d8);
PKMN_OFFSET_ASSERT(Unk_8e0670_Block2, field_5e4, 0x5e4);
PKMN_OFFSET_ASSERT(Unk_8e0670_Block2, field_5f0, 0x5f0);
PKMN_OFFSET_ASSERT(Unk_8e0670_Block2, field_614, 0x614);
PKMN_OFFSET_ASSERT(Unk_8e0670_Block2, field_6a0, 0x6a0);

class Unk_239a418_Allocator;

struct Unk_8e0670_Owner {
    u8 _0[0x60];
    Unk_239a418_Allocator* field_60;
    u8 _68[0x118];
    Unk_8e0670_Block1* field_180;
    Unk_8e0670_Block2* field_188;
};
PKMN_OFFSET_ASSERT(Unk_8e0670_Owner, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_8e0670_Owner, field_180, 0x180);
PKMN_OFFSET_ASSERT(Unk_8e0670_Owner, field_188, 0x188);
