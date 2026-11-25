#pragma once
// Scope: common
// What the battle event handlers of 0x710086dd10-0x710086ec94 call, and the
// parameter blocks they give the battle state's handler objects (through the
// helpers of 0x7100819600-0x710081a7d0). Placeholder names. The declarations
// shared with the handlers of 0x710085c190 and 0x7100886280 come from those
// headers.
#include "battle/battle_engine/Unk_7ee6b0.h"
#include "unsorted/unk_82e410/Unk_880840.h"

// The leaf accessors of the event variables (src/unsorted/leaf), each with
// its own placeholder type for the handler object.
struct Unk_819650;
struct Unk_819660;
struct Unk_819690;
struct Unk_8196c0;
struct Unk_8197f0;
void Unk_819650_call(const Unk_819650* self, u8 value);
void Unk_819660_call(const Unk_819660* self, u32 value, u32 arg2);
u16 Unk_819690_call(const Unk_819690* self);
void Unk_8196c0_call(const Unk_8196c0* self);
// Forwards both values to Unk_7cbf80(void*, u8, u8) and returns its result.
bool Unk_8197f0_call(const Unk_8197f0* self, u8 value, u8 arg2);

// The battle Pokemon and its accessors.
struct Unk_7f09c0;
Unk_7ee6b0* Unk_8196d0(const Unk_819600_Self* self, u8 pokeId);
u16 Unk_7f09c0_getField76(const Unk_7f09c0* self);
bool Unk_7f05a0(const Unk_7ee6b0* self, u32 flag);
bool Unk_7f0670(const Unk_7ee6b0* poke, u32 type);
bool Unk_7f7db0(u8 value);
bool Unk_7f7dd0(u8 value);
u32 Unk_82da30(u8 type);

// The battle state's helpers.
u8 Unk_81a310(const Unk_819600_Self* self);
u8 Unk_81a350(const Unk_819600_Self* self, u8 arg);
bool Unk_81ae20(const Unk_819600_Self* self, u8 pokeId);
bool Unk_81b100(const Unk_819600_Self* self, u8 pokeId, u8 otherId);
// Named (void*, u32); it forwards the value as a u8, and 0x710086e930 passes
// it unextended.
void Unk_81b230(void* arg, u8 pokeId);
void Unk_81b430(const Unk_819600_Self* self, u8 pokeId);
bool Unk_81b500(const Unk_819600_Self* self, u32 ratio);
u8 Unk_81b7a0(const Unk_819600_Self* self, u8 pokeId);
bool Unk_81b8d0(const Unk_819600_Self* self, u8 pokeId);
bool Unk_81bfc0(const Unk_819600_Self* self, u8 pokeId);

inline u16 Unk_86dd10_Item(const Unk_7ee6b0* poke) {
    return Unk_7f09c0_getField76(reinterpret_cast<const Unk_7f09c0*>(poke));
}

// As in Unk_85c190.h: a Pokemon and a list of values (Unk_803d20_set,
// Unk_803d60).
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

// What 0x710086dd10, 0x710086e5a0 and 0x710086eb50 give Unk_81aab0: only its
// first byte is set.
struct Unk_8643c0_Arg {
    u8 field_0;
    u8 _1[7];
};
PKMN_SIZE_ASSERT(Unk_8643c0_Arg, 0x8);
void Unk_81aab0(const Unk_819600_Self* self, const Unk_8643c0_Arg& arg);

// What 0x710086e830 gives Unk_81a510 (field_0 and field_1 two Pokemon), with
// a message list at +0xc.
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

// What 0x710086eb50 gives Unk_81a550 (field_0 and field_1 two Pokemon), with
// three message lists.
struct Unk_854b80_Arg {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    Unk_840b50_List field_4;
    Unk_840b50_List field_28;
    Unk_840b50_List field_4c;

    Unk_854b80_Arg() : field_0(0x1f), field_1(0x1f), field_2(0), field_3(0) {
        Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_4));
        Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_28));
        Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_4c));
    }
};
PKMN_OFFSET_ASSERT(Unk_854b80_Arg, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_854b80_Arg, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_854b80_Arg, field_4c, 0x4c);
PKMN_SIZE_ASSERT(Unk_854b80_Arg, 0x70);
bool Unk_81a550(const Unk_819600_Self* self, const Unk_854b80_Arg& arg);
