#pragma once
// Scope: common
// What the battle event handlers of 0x7100880870-0x7100880f10 call, and the
// parameter block they give Unk_819c80. Placeholder names.
#include "battle/battle_engine/Unk_81b200.h"

// The leaf accessors of the event variables, each with its own placeholder
// type for the handler object.
struct Unk_819600;
struct Unk_819640;
struct Unk_8196a0;
struct Unk_8196b0;
u32 Unk_819600_call(const Unk_819600* self, u32 value);
bool Unk_819640_call(const Unk_819640* self, u32 value, u32 arg2);
u32 Unk_8196a0_call(const Unk_8196a0* self, u32 value);
void Unk_8196b0_call(const Unk_8196b0* self, u32 value, u32 arg2);
bool Unk_81b7e0(const Unk_819600_Self* self, u8 pokeId, u32 value);
// Named (void*, u64, u32); it takes a u8 (0x7100880b40 keeps only w1).
void Unk_880b40(void* self, u8 pokeId, u32 index);

struct Unk_803c60;
void Unk_803c60_set(Unk_803c60* self);
u8 Unk_819c80(const Unk_819600_Self* self, const void* arg);

// What 0x7100880b40 and 0x7100880e30 give Unk_819c80 (field_0 and field_8
// the Pokemon, field_4 a value).
struct Unk_880b40_Arg {
    u8 field_0;
    u8 _1[3];
    u32 field_4;
    u8 field_8;
    u8 field_9[0x1d];
    u8 field_26;
    u8 _27;
    u32 field_28;
    Unk_23acc98_Message field_2c;

    Unk_880b40_Arg()
        : field_0(0x1f), field_4(0x2d), field_8(0), field_9(), field_26(0), field_28(0) {
        Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_2c));
    }
};
PKMN_OFFSET_ASSERT(Unk_880b40_Arg, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_880b40_Arg, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_880b40_Arg, field_26, 0x26);
PKMN_OFFSET_ASSERT(Unk_880b40_Arg, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_880b40_Arg, field_2c, 0x2c);
PKMN_SIZE_ASSERT(Unk_880b40_Arg, 0x50);
