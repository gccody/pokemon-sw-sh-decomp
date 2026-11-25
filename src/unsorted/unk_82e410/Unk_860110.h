#pragma once
// Scope: common
// What the battle event handlers of 0x7100860110-0x7100861124 call, beyond
// Unk_85c190.h and Unk_886280.h, and the checks several of them share.
// Placeholder names.
#include "unsorted/unk_82e410/Unk_886280.h"

struct Unk_819680;
// Declared elsewhere returning Unk_840b50_List*; 0x7100860320 gives the
// variable to Unk_7f8a20.
u64* Unk_819680_call(const Unk_819680* self, u32 value);
void Unk_7f8a20(u64* self, bool value);
bool Unk_7f0c00(const Unk_7ee6b0* self, u32 stat, s32 direction);
bool Unk_8199a0(const Unk_819600_Self* self, u8 pokeId);
bool Unk_81c220(const Unk_819600_Self* self, u8 pokeId);
bool Unk_81be40(const Unk_819600_Self* self);
u8 Unk_81bf40(const Unk_819600_Self* self, u8 pokeId);
bool Unk_81be10(const Unk_819600_Self* self, u8 pokeId);
// Defined as u8 (void); 0x7100860b00 tests only bit 0 of what they return.
bool Unk_81bd20(const Unk_819600_Self* self);
struct Unk_819a20;
bool Unk_819a20_call(const Unk_819a20* self);
bool Unk_81b750(const Unk_819600_Self* self, u8 pokeId);

// As in Unk_86dd10.h: what Unk_81a510 is given (field_0 and field_1 two
// Pokemon), with a message list at +0xc.
struct Unk_838f90_Arg {
    u8 field_0;
    u8 field_1;
    u16 field_2;
    u8 field_4;
    u8 field_5;
    u8 field_6;
    u8 field_7;
    u16 field_8;
    u8 _a[2];
    Unk_840b50_List field_c;

    Unk_838f90_Arg()
        : field_0(0x1f),
          field_1(0x1f),
          field_2(0),
          field_4(0),
          field_5(0),
          field_6(0x1f),
          field_7(0),
          field_8(0) {
        Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_c));
    }
};
PKMN_OFFSET_ASSERT(Unk_838f90_Arg, field_6, 0x6);
PKMN_OFFSET_ASSERT(Unk_838f90_Arg, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_838f90_Arg, field_c, 0xc);
PKMN_SIZE_ASSERT(Unk_838f90_Arg, 0x30);
bool Unk_81a510(const Unk_819600_Self* self, const Unk_838f90_Arg& arg);

// What Unk_81a840 gives 0x710083c7b0: two Pokemon, two flags, a 16-bit value
// and a 64-bit one.
struct Unk_83c7b0_Arg {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u16 field_4;
    u8 _6[2];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_83c7b0_Arg, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_83c7b0_Arg, field_8, 0x8);
PKMN_SIZE_ASSERT(Unk_83c7b0_Arg, 0x10);
bool Unk_81a840(const Unk_819600_Self* self, const Unk_83c7b0_Arg& arg);

// What Unk_81a760 gives 0x71008566e0 (field_0 the Pokemon), with two message
// lists.
struct Unk_8566e0_Arg {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 _3;
    Unk_840b50_List field_4;
    Unk_840b50_List field_28;

    Unk_8566e0_Arg() : field_0(0x1f), field_1(0), field_2(0) {
        Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_4));
        Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_28));
    }
};
PKMN_OFFSET_ASSERT(Unk_8566e0_Arg, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_8566e0_Arg, field_28, 0x28);
PKMN_SIZE_ASSERT(Unk_8566e0_Arg, 0x4c);
bool Unk_81a760(const Unk_819600_Self* self, const Unk_8566e0_Arg& arg);

// 0x7100860d10, called by 0x7100860dd0 (Unk_860d10.cpp).
void Unk_860d10(void* self, u8 pokeId);

// Shows the effect of `pokeId` (0x7100819a10, then 0x710081a5c0).
static inline void Unk_860370_Show(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    Unk_819a10_call(static_cast<const Unk_819a10*>(self));
    Unk_850fb0_Arg arg;
    arg.field_0 = pokeId;
    Unk_81a5c0(flow, arg);
}

// When the event's variable 4 is `pokeId`, its variable 0x4d is 0 and its
// variable 0x16 is `kind`, and the Pokemon's `stat` can rise, shows the
// effect (0x71008608d0).
static inline void Unk_860370_Check(void* self, u8 pokeId, u8 kind, u32 stat) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 4) != pokeId)
        return;
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 0x4d) != 0)
        return;
    if (static_cast<u8>(Unk_819600_call(static_cast<const Unk_819600*>(self), 0x16)) != kind)
        return;
    if (!Unk_7f0c00(Unk_8196d0(flow, pokeId), stat, 1))
        return;
    Unk_860370_Show(self, pokeId);
}

// Raises the Pokemon's `stat` (0x7100819df0) when the event's variable 2 is
// `pokeId`, then shows the effect and sets variable 0x50.
static inline void Unk_860410_Raise(void* self, u8 pokeId, u32 stat) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) != pokeId)
        return;
    {
        Unk_84a910_Arg arg;
        arg.field_0 = pokeId;
        arg.field_1 = 1;
        arg.field_2 = pokeId;
        arg.field_8 = stat;
        arg.field_c = 1;
        arg.field_e = Unk_819690_call(static_cast<const Unk_819690*>(self));
        if (!Unk_819df0(flow, arg))
            return;
    }
    {
        Unk_856020_Arg arg;
        arg.field_0 = pokeId;
        arg.field_1 = 1;
        arg.field_3 = 1;
        Unk_81a640(flow, arg);
    }
    Unk_819640_call(static_cast<const Unk_819640*>(self), 0x50, 1);
}

// Whether the battle state lets `pokeId`'s effect show (0x7100860b00,
// 0x7100860d10).
static inline bool Unk_860b00_CanShow(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    if (Unk_81be10(flow, pokeId))
        return false;
    if (Unk_81be40(flow))
        return false;
    if (Unk_81bd20(flow))
        return false;
    if (!Unk_8199a0(flow, pokeId))
        return false;
    if (!Unk_81c220(flow, pokeId))
        return false;
    if (Unk_819a20_call(static_cast<const Unk_819a20*>(self)))
        return false;
    return true;
}
