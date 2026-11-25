#pragma once
// Scope: common
// What the battle event handlers of 0x7100860110-0x71008608cc call, beyond
// Unk_85c190.h and Unk_886280.h. Placeholder names.
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
