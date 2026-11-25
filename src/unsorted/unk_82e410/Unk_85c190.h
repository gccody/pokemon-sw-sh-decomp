#pragma once
// Scope: common
// What the battle event handlers of 0x710085c190-0x710085d1dc call, and the
// parameter blocks they give the battle state's handler objects (through the
// helpers of 0x7100819600-0x710081a7d0). Placeholder names.
#include "unsorted/unk_82e410/Unk_880840.h"

// The leaf accessors of the event variables (src/unsorted/leaf), each with
// its own placeholder type for the handler object, and the types they return
// here.
struct Unk_819630;
struct Unk_819660;
struct Unk_819690;
struct Unk_819a10;
struct Unk_819a60;
u32 Unk_819630_call(const Unk_819630* self);
void Unk_819660_call(const Unk_819660* self, u32 value, u32 arg2);
u16 Unk_819690_call(const Unk_819690* self);
void Unk_819a10_call(const Unk_819a10* self);
bool Unk_819a60_call(const Unk_819a60* self, u8 pokeId);

// The battle Pokemon and its accessors.
struct Unk_7eef40;
struct Unk_7e9ba0;
struct Unk_7ef220;
struct Unk_7ee6c0;
Unk_7ee6b0* Unk_8196d0(const Unk_819600_Self* self, u8 pokeId);
u16 Unk_7eef40_getField70(const Unk_7eef40* self);
u16 Unk_7e9ba0_getField38(const Unk_7e9ba0* self);
bool Unk_7ef220_get(const Unk_7ef220* self);
bool Unk_7ee6c0_getField298(const Unk_7ee6c0* self);
bool Unk_7ef4c0(const Unk_7ee6b0* poke, u32 condition);
bool Unk_7f0aa0(const Unk_7ee6b0* poke, u32 flag);
s32 Unk_7f7ae0_call(u16 self, u32 value);
bool Unk_7f7ff0(u32 percent);
bool Unk_82cd00(void* self, u8 pokeId);
bool Unk_859570(void* self, u8 pokeId, u32 arg2, u32 arg3);
bool Unk_819d40(const Unk_819600_Self* self, u8 pokeId, u32 id, u32 other);

inline u16 Unk_85c190_Species(const Unk_7ee6b0* poke) {
    return Unk_7eef40_getField70(reinterpret_cast<const Unk_7eef40*>(poke));
}

// The value of 0x7100819690's object (+0x40), as 0x71007f7ae0 is given it.
inline s32 Unk_85c190_Value(const Unk_819600_Self* self, u32 kind) {
    return Unk_7f7ae0_call(
        Unk_7e9ba0_getField38(reinterpret_cast<const Unk_7e9ba0*>(self->field_40)), kind);
}

// A percentage as a 4096-based fixed-point ratio, rounded.
#define UNK_85C190_FX_PERCENT(percent) \
    (static_cast<s32>((percent) * 4096 + ((percent) > 0 ? 0.5f : -0.5f)) / 100)

// The parameter blocks.
struct Unk_856020_Arg {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    Unk_23acc98_Message field_4;

    Unk_856020_Arg() : field_0(0x1f), field_1(0), field_2(0), field_3(0) {
        Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_4));
    }
};
PKMN_OFFSET_ASSERT(Unk_856020_Arg, field_4, 0x4);
PKMN_SIZE_ASSERT(Unk_856020_Arg, 0x28);
void Unk_81a640(const Unk_819600_Self* self, const Unk_856020_Arg& arg);

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
    u32 field_14;
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
          field_18(0),
          field_1a(0) {
        Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_1c));
    }
};
PKMN_OFFSET_ASSERT(Unk_84a910_Arg, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_84a910_Arg, field_e, 0xe);
PKMN_OFFSET_ASSERT(Unk_84a910_Arg, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_84a910_Arg, field_1c, 0x1c);
PKMN_SIZE_ASSERT(Unk_84a910_Arg, 0x40);
bool Unk_819df0(const Unk_819600_Self* self, const Unk_84a910_Arg& arg);

struct Unk_850fb0_Arg {
    u8 field_0;
    u8 field_1;
    u8 field_2;

    Unk_850fb0_Arg() : field_0(0x1f), field_1(0), field_2(0) {}
};
PKMN_SIZE_ASSERT(Unk_850fb0_Arg, 0x3);
void Unk_81a5c0(const Unk_819600_Self* self, const Unk_850fb0_Arg& arg);

struct Unk_853920_Arg {
    u8 field_0;
    u8 field_1;
};
PKMN_SIZE_ASSERT(Unk_853920_Arg, 0x2);
bool Unk_81a7d0(const Unk_819600_Self* self, const Unk_853920_Arg& arg);

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

// What 0x710085cfe0 gives Unk_819c80: Unk_880b40_Arg's block, with a 16-bit
// value at +0x28 and a flag at +0x2b.
struct Unk_85cfe0_Arg {
    u8 field_0;
    u8 _1[3];
    u32 field_4;
    u8 field_8;
    u8 field_9[0x1d];
    u8 field_26;
    u8 _27;
    u16 field_28;
    u8 field_2a;
    u8 field_2b;
    Unk_23acc98_Message field_2c;

    Unk_85cfe0_Arg()
        : field_0(0x1f),
          field_4(0x2d),
          field_8(0),
          field_9(),
          field_26(0),
          field_28(0),
          field_2a(0),
          field_2b(0) {
        Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&field_2c));
    }
};
PKMN_OFFSET_ASSERT(Unk_85cfe0_Arg, field_26, 0x26);
PKMN_OFFSET_ASSERT(Unk_85cfe0_Arg, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_85cfe0_Arg, field_2b, 0x2b);
PKMN_OFFSET_ASSERT(Unk_85cfe0_Arg, field_2c, 0x2c);
PKMN_SIZE_ASSERT(Unk_85cfe0_Arg, 0x50);
