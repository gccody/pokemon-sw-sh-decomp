#pragma once
// Scope: common
// What the battle event handlers of 0x71008758d0-0x71008768a8 call, and the
// parameter blocks they give the battle state's handler objects (through the
// helpers of 0x7100819600-0x710081a7d0). Placeholder names. The shared
// declarations are copied from Unk_85c190.h, Unk_86dd10.h and Unk_885b20.cpp,
// which can't be included together.
#include "battle/battle_engine/Unk_7ee6b0.h"
#include "unsorted/unk_82e410/Unk_880840.h"

// The leaf accessors of the event variables (src/unsorted/leaf), each with
// its own placeholder type for the handler object.
struct Unk_819660;
struct Unk_819680;
struct Unk_819690;
struct Unk_8196c0;
struct Unk_8197f0;
struct Unk_819a70;
void Unk_819660_call(const Unk_819660* self, u32 value, u32 arg2);
u16 Unk_819690_call(const Unk_819690* self);
void Unk_8196c0_call(const Unk_8196c0* self);
bool Unk_8197f0_call(const Unk_8197f0* self, u8 value, u8 arg2);
void Unk_819a70_call(const Unk_819a70* self);

// The battle Pokemon and its accessors.
Unk_7ee6b0* Unk_8196d0(const Unk_819600_Self* self, u8 pokeId);
u32 Unk_7e9830(void* self, u16 label);
struct Unk_7e9ba0;
u16 Unk_7e9ba0_getField38(const Unk_7e9ba0* self);
bool Unk_7ef2b0_call(void* self);
struct Unk_7ee6c0;
bool Unk_7ee6c0_getField298(const Unk_7ee6c0* self);
bool Unk_7ef4c0(const Unk_7ee6b0* poke, u32 condition);
bool Unk_7eb230(u16 move);

// A Pokemon and a list of values (Unk_803d20_set, Unk_803d60).
struct Unk_840b50_List {
    u16 field_0;
    u16 field_2;
    u32 field_4[8];
};
PKMN_SIZE_ASSERT(Unk_840b50_List, 0x24);
struct Unk_803d20;
void Unk_803d20_set(Unk_803d20* self, u32 value, u16 arg2);
void Unk_803d60(Unk_840b50_List* self, u32 value);

// The parameter blocks.
struct Unk_840b50_Arg {
    u8 field_0;
    u8 field_1;
    u8 _2[2];
    Unk_840b50_List field_4;

    Unk_840b50_Arg() : field_0(0x1f), field_1(0) {
        Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_4));
    }
};
PKMN_OFFSET_ASSERT(Unk_840b50_Arg, field_4, 0x4);
PKMN_SIZE_ASSERT(Unk_840b50_Arg, 0x28);
void Unk_81a030(const Unk_819600_Self* self, const Unk_840b50_Arg& arg);

// What 0x710081a0e0 and 0x710081a120 are given: a Pokemon and a value.
struct Unk_856390_Arg {
    u8 field_0;
    u8 _1[3];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_856390_Arg, field_4, 0x4);
PKMN_SIZE_ASSERT(Unk_856390_Arg, 0x8);
void Unk_81a0e0(const Unk_819600_Self* self, const Unk_856390_Arg& arg);
struct Unk_857530_Arg {
    u8 field_0;
    u8 _1[3];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_857530_Arg, field_4, 0x4);
PKMN_SIZE_ASSERT(Unk_857530_Arg, 0x8);
void Unk_81a120(const Unk_819600_Self* self, const Unk_857530_Arg& arg);
