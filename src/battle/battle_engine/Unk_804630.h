#pragma once
// What the functions of Unk_804630.cpp are members of, and what they take.
// Placeholder names: rename once the classes are known.
#include <types.h>

#include "battle/battle_engine/Unk_7e8a20.h"

// A battle Pokemon. Its getters are leaf functions matched on their own
// (src/unsorted/leaf/Unk_7ed7d0.cpp): +0x7d is its id.
struct Unk_7ee6b0;
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);

// What holds the event system at +0x10.
struct Unk_804630_Flow {
    u8 _0[0x10];
    Unk_7e8a20* field_10;
};
PKMN_OFFSET_ASSERT(Unk_804630_Flow, field_10, 0x10);

// What Unk_806e40 takes third: flags in the word at +4.
struct Unk_806e40_Arg {
    u32 field_0;
    u32 field_4;
};
PKMN_SIZE_ASSERT(Unk_806e40_Arg, 0x8);

u32 Unk_7810b0(u32 arg1, u32 arg2, u32* out);
u32 Unk_780dd0(u32 move);
u8 Unk_780d40(u32 move);

// What Unk_82d7e0 takes: a Pokemon and a value.
struct Unk_82d7e0_Arg {
    const Unk_7ee6b0* field_0;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_82d7e0_Arg, field_8, 0x8);
u32 Unk_82d7e0(const Unk_82d7e0_Arg* arg);

bool Unk_7ef4c0(const Unk_7ee6b0* poke, u32 arg);

// What Unk_807e00 and Unk_807f30 take: a move (its number at +0, a byte at +0xe).
struct Unk_807e00_Move {
    u32 field_0;
    u32 field_4;
    u8 _8[0xe - 0x8];
    u8 field_e;
    u32 field_10;
    u8 field_14;
    u8 _15[0x18 - 0x15];
    u32 field_18;
    u32 field_1c;
    u8 _20[0x24 - 0x20];
    u32 field_24;
};
PKMN_OFFSET_ASSERT(Unk_807e00_Move, field_e, 0xe);

// A list of target Pokemon: Unk_813110 returns one by index (nullptr past the
// last), +0x4c is their count.
struct Unk_813270;
u32 Unk_813270_getField4c(const Unk_813270* self);
const Unk_7ee6b0* Unk_813110(const Unk_813270* self, u32 index);

// What Unk_8087d0 takes third.
struct Unk_8087d0_Arg {
    u32 field_0;
    u8 _4[0x14 - 0x4];
    u8 field_14;
};
PKMN_OFFSET_ASSERT(Unk_8087d0_Arg, field_14, 0x14);

bool Unk_780e30(u32 move);

bool Unk_8131d0(const Unk_813270* self, const Unk_7ee6b0* poke, u32* out);
bool Unk_813170(const Unk_813270* self, const Unk_7ee6b0* poke, u32* out);
u32 Unk_780f80(u32 move);
u16 Unk_780fe0(u32 move);
u32 Unk_780fb0(u32 move);
void Unk_7f7df0(u64 kind, const Unk_7ee6b0* poke, u64* out);
u32 Unk_7f7690(u32 max);

u8 Unk_781130(u32 move, u32 arg);
void Unk_7f8ab0(void* self, s32 value);
void Unk_7f8990(void* self, s32 value);

// The target list as src/unsorted/leaf/Unk_812cf0.cpp's getter of +0x4d
// types it.
struct Unk_813280;
u8 Unk_813280_getField4d(const Unk_813280* self);

// What Unk_80b290 fills in.
struct Unk_80b290_Out {
    u32 field_0;
    u8 field_4;
};
PKMN_SIZE_ASSERT(Unk_80b290_Out, 0x8);

// The Pokemon as src/unsorted/leaf/Unk_7ed7d0.cpp's getter of +0x342 types it.
struct Unk_7ef300;
u8 Unk_7ef300_getField342(const Unk_7ef300* self);

// What Unk_80b610 fills in, cleared by a leaf function of its own
// (src/unsorted/leaf).
struct Unk_803c70;
void Unk_803c70_set(Unk_803c70* self);

// What Unk_80b770 sets a value in (a leaf function of its own sets it).
struct Unk_812dc0;
void Unk_812dc0_setField0(Unk_812dc0* self, u32 value);

u32 Unk_780e90(u32 move);
u16 Unk_7f7720(u32 value, u32 ratio);
