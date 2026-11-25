#pragma once
// Scope: common
// What the battle event handlers of 0x7100890010-0x71008907a0 call, and the
// parameter blocks they give the battle state's handler objects (through the
// helpers of 0x7100819600-0x710081a7d0). Placeholder names. The blocks are
// copied from Unk_85c190.h, Unk_85e150.h, Unk_886280.h and Unk_8798c0.h,
// which can't be included together; Unk_84a910_Arg's +0x14 is split into
// bytes here (0x71008905d0 sets it as a byte).
#include "battle/battle_engine/Unk_7ee6b0.h"
#include "unsorted/unk_82e410/Unk_880840.h"

// The leaf accessors of the event variables (src/unsorted/leaf), each with
// its own placeholder type for the handler object.
struct Unk_819640;
struct Unk_819660;
struct Unk_819950;
struct Unk_819960;
void Unk_819660_call(const Unk_819660* self, u32 value, u32 arg2);
// Defined as void; they return what their tail calls give.
bool Unk_819950_call(const Unk_819950* self, u32 value);
bool Unk_819960_call(const Unk_819960* self);

// The battle Pokemon and its accessors.
struct Unk_7eef40;
struct Unk_7ef220;
struct Unk_7f0b70;
Unk_7ee6b0* Unk_8196d0(const Unk_819600_Self* self, u8 pokeId);
u16 Unk_7eef40_getField70(const Unk_7eef40* self);
bool Unk_7ef220_get(const Unk_7ef220* self);
bool Unk_7f0b70_check(const Unk_7f0b70* self);
bool Unk_7ef2b0_call(void* self);
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);
u32 Unk_7eef50(void* self, u32 index);
u32 Unk_7f7990(Unk_7ee6b0* self, u32 divisor, bool check);
u32 Unk_7f79e0(Unk_7ee6b0* self, u32 divisor, bool check);
u64 Unk_7f78c0(u32 kind, u8 pokeId);

inline u16 Unk_890010_Species(const Unk_7ee6b0* poke) {
    return Unk_7eef40_getField70(reinterpret_cast<const Unk_7eef40*>(poke));
}

// The battle state's helpers.
void Unk_819a80(const Unk_819600_Self* self, u8 pokeId);
void Unk_819ac0(const Unk_819600_Self* self, u8 pokeId);
// Defined as u32; 0x71008900d0 tests only bit 0.
bool Unk_819a30(const Unk_819600_Self* self, u8 pokeId);
u8 Unk_81bf40(const Unk_819600_Self* self, u8 pokeId);

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

// field_0 the Pokemon, field_1 the form it gets.
struct Unk_8557b0_Arg {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u8 field_4;
    u8 field_5;
    u8 _6[2];
    Unk_840b50_List field_8;

    Unk_8557b0_Arg() : field_0(0x1f), field_1(0), field_2(0), field_3(0), field_4(0), field_5(1) {
        Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_8));
    }
};
PKMN_OFFSET_ASSERT(Unk_8557b0_Arg, field_5, 0x5);
PKMN_OFFSET_ASSERT(Unk_8557b0_Arg, field_8, 0x8);
PKMN_SIZE_ASSERT(Unk_8557b0_Arg, 0x2c);
bool Unk_81aa70(const Unk_819600_Self* self, const Unk_8557b0_Arg& arg);

// As in Unk_85e150.h, with the 16-bit value at +0xa.
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
    u16 field_a;
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
          field_c(5),
          field_d(5) {
        Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_10));
    }
};
PKMN_OFFSET_ASSERT(Unk_84d950_Arg, field_2, 0x2);
PKMN_OFFSET_ASSERT(Unk_84d950_Arg, field_a, 0xa);
PKMN_OFFSET_ASSERT(Unk_84d950_Arg, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_84d950_Arg, field_10, 0x10);
PKMN_SIZE_ASSERT(Unk_84d950_Arg, 0x34);
bool Unk_819b80(const Unk_819600_Self* self, const Unk_84d950_Arg& arg);

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
    u8 field_14;
    u8 field_15;
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
          field_15(0),
          field_16(0),
          field_17(0),
          field_18(0),
          field_1a(0) {
        Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_1c));
    }
};
PKMN_OFFSET_ASSERT(Unk_84a910_Arg, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_84a910_Arg, field_e, 0xe);
PKMN_OFFSET_ASSERT(Unk_84a910_Arg, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_84a910_Arg, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_84a910_Arg, field_1c, 0x1c);
PKMN_SIZE_ASSERT(Unk_84a910_Arg, 0x40);
bool Unk_819df0(const Unk_819600_Self* self, const Unk_84a910_Arg& arg);

// As in Unk_8798c0.h: the parameter block of 0x7100836520, with a message
// list at +0x18.
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
