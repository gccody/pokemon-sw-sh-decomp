#pragma once
// Scope: common
// What the battle event handlers of 0x71008798c0-0x710087a8c4 call, and the
// parameter blocks they give the battle state's handler objects (through the
// helpers of 0x7100819600-0x710081a7d0). Placeholder names. The declarations
// come from Unk_85c190.h and Unk_886280.h, with Unk_84a910_Arg's bytes at
// +0x16 and +0x17 split out (0x71008798c0 sets them as bytes).
#include "battle/battle_engine/Unk_7ee6b0.h"
#include "unsorted/unk_82e410/Unk_880840.h"

Unk_7ee6b0* Unk_8196d0(const Unk_819600_Self* self, u8 pokeId);
void Unk_81c300(const Unk_819600_Self* self, u8 pokeId, u32 value);
u64 Unk_7f87a0(u8 index, u8 b);
void Unk_877630(void* self, u8 pokeId, u8 otherId);

// As in Unk_81b200.cpp: a Pokemon and a list of values (Unk_803d20_set,
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

struct Unk_84a910_Arg {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u8 field_4;
    u8 field_5;
    u8 field_6;
    u8 _7;
    u32 field_8;
    u8 field_c;
    u8 field_d;
    u16 field_e;
    u32 field_10;
    u16 field_14;
    u8 field_16;
    u8 field_17;
    u16 field_18;
    u8 field_1a;
    u8 _1b;
    Unk_23acc98_Message field_1c;

    Unk_84a910_Arg()
        : field_0(0x1f),
          field_1(0),
          field_2(0),
          field_3(0),
          field_4(0),
          field_5(0),
          field_6(0),
          field_8(0),
          field_c(0),
          field_d(0),
          field_e(0),
          field_10(0),
          field_14(0),
          field_16(0),
          field_17(0),
          field_18(0),
          field_1a(0) {
        Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_1c));
    }
};
PKMN_OFFSET_ASSERT(Unk_84a910_Arg, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_84a910_Arg, field_e, 0xe);
PKMN_OFFSET_ASSERT(Unk_84a910_Arg, field_16, 0x16);
PKMN_OFFSET_ASSERT(Unk_84a910_Arg, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_84a910_Arg, field_1c, 0x1c);
PKMN_SIZE_ASSERT(Unk_84a910_Arg, 0x40);
bool Unk_819df0(const Unk_819600_Self* self, const Unk_84a910_Arg& arg);

// The parameter block of 0x710082b8b0 (through Unk_81a290): field_0 the
// Pokemon, field_4 a kind, field_10 a packed value (Unk_7f87a0) and a message
// list at +0x1c.
struct Unk_82b8b0_Arg {
    u8 field_0;
    u8 _1[3];
    u32 field_4;
    u16 field_8;
    u8 _a[6];
    u64 field_10;
    u16 field_18;
    u8 _1a[2];
    Unk_840b50_List field_1c;
    u16 field_40;

    Unk_82b8b0_Arg() : field_0(0x1f), field_4(0xa), field_8(0), field_10(0), field_18(0xea) {
        Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_1c));
        field_40 = 0;
    }
};
PKMN_OFFSET_ASSERT(Unk_82b8b0_Arg, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_82b8b0_Arg, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_82b8b0_Arg, field_1c, 0x1c);
PKMN_OFFSET_ASSERT(Unk_82b8b0_Arg, field_40, 0x40);
PKMN_SIZE_ASSERT(Unk_82b8b0_Arg, 0x48);
bool Unk_81a290(const Unk_819600_Self* self, const Unk_82b8b0_Arg& arg);

// As in Unk_819bc0.cpp: the parameter block of 0x7100836520 (through
// Unk_819d00), with a message list at +0x18.
struct Unk_836520_Arg {
    u8 field_0 = 0x1f;
    u8 field_1 = 0x1f;
    u32 field_4 = 0;
    u64 field_8 = 0;
    u8 field_10 = 0;
    u8 field_11 = 0;
    u16 field_12 = 0;
    u32 field_14 = 1;
    Unk_840b50_List field_18;

    Unk_836520_Arg() { Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_18)); }
};
PKMN_SIZE_ASSERT(Unk_836520_Arg, 0x40);
PKMN_OFFSET_ASSERT(Unk_836520_Arg, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_836520_Arg, field_18, 0x18);
bool Unk_819d00(const Unk_819600_Self* self, const Unk_836520_Arg& arg);

// What the handlers of 0x710087a0a0-0x710087a8c4 call.
struct Unk_819650;
struct Unk_819690;
struct Unk_8197a0;
void Unk_819650_call(const Unk_819650* self, u8 value);
u16 Unk_819690_call(const Unk_819690* self);
// Named (..., u32); 0x710087a0a0 passes it a u8 without extending it.
u8 Unk_8197a0_call(const Unk_8197a0* self, u8 value);
u16 Unk_7ef200(const Unk_7ee6b0* self);
u32 Unk_7f05d0(void* object);
u32 Unk_7f79e0(Unk_7ee6b0* self, u32 divisor, bool check);
// Named (u32, u32); 0x710087a310 passes it u8s without extending them.
u64 Unk_7f7940(u8 pokeId, u8 turns);
u32 Unk_82da30(u8 type);
bool Unk_7f0aa0(const Unk_7ee6b0* poke, u32 flag);
bool Unk_86ff60(void* self, u8 pokeId, bool flag);
void Unk_870270(void* self, u8 pokeId, const Unk_7ee6b0* poke, u16 message);
// Named (u32); 0x710087a7b0 passes it a second value (the Pokemon) in w1.
u64 Unk_7f78c0(u32 kind, u8 pokeId);
// Named (void*, u32); they compare the value as a byte.
void Unk_87a210(void* self, u8 pokeId);
void Unk_87a7b0(void* self, u8 pokeId);

// The parameter block of 0x710082fa10 (through Unk_81a190): field_0 the
// Pokemon, field_4 a kind, field_8 a packed value (Unk_7f87a0), a message
// list at +0x14 and a flag at +0x38.
struct Unk_82fa10_Arg {
    u8 field_0;
    u8 _1[3];
    u32 field_4;
    u64 field_8;
    u8 field_10;
    u8 _11;
    u16 field_12;
    Unk_840b50_List field_14;
    u8 field_38;

    Unk_82fa10_Arg() : field_0(0x1f), field_4(0x16), field_8(0), field_10(2), field_12(0xea) {
        Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_14));
    }
};
PKMN_OFFSET_ASSERT(Unk_82fa10_Arg, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_82fa10_Arg, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_82fa10_Arg, field_38, 0x38);
PKMN_SIZE_ASSERT(Unk_82fa10_Arg, 0x40);
bool Unk_81a190(const Unk_819600_Self* self, const Unk_82fa10_Arg& arg);

// As in Unk_886280.h: what 0x710087a210 gives Unk_819b80, with a message
// list at +0x10.
struct Unk_84d950_Arg {
    u8 field_0;
    u8 field_1;
    u16 field_2;
    u8 field_4;
    u8 field_5;
    u8 field_6;
    u8 field_7;
    u8 field_8;
    u8 field_9;
    u8 field_a;
    u8 field_b;
    u8 field_c;
    u8 field_d;
    u8 _e[2];
    Unk_840b50_List field_10;

    Unk_84d950_Arg()
        : field_0(0x1f),
          field_1(0x1f),
          field_2(0),
          field_4(0),
          field_5(0x1f),
          field_6(0),
          field_7(0),
          field_8(0),
          field_9(0),
          field_a(0),
          field_b(0),
          field_c(5),
          field_d(5) {
        Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_10));
    }
};
PKMN_OFFSET_ASSERT(Unk_84d950_Arg, field_2, 0x2);
PKMN_OFFSET_ASSERT(Unk_84d950_Arg, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_84d950_Arg, field_10, 0x10);
PKMN_SIZE_ASSERT(Unk_84d950_Arg, 0x34);
bool Unk_819b80(const Unk_819600_Self* self, const Unk_84d950_Arg& arg);
