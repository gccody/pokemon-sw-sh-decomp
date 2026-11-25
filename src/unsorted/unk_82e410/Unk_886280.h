#pragma once
// Scope: common
// What the battle event handlers of 0x7100886280-0x7100887240 call, and the
// parameter blocks they give the battle state's handler objects. Placeholder
// names. The handler parameter blocks and accessors shared with the handlers
// of 0x710085c190 come from Unk_85c190.h.
#include "battle/battle_engine/Unk_7ee6b0.h"
#include "unsorted/unk_82e410/Unk_85c190.h"

struct Unk_7f09c0;
struct Unk_7e9a60;
struct Unk_819a70;
struct Unk_7fe1d0;
u16 Unk_7f09c0_getField76(const Unk_7f09c0* self);
u8 Unk_7e9a60_getField3b(const Unk_7e9a60* self);
void Unk_819a70_call(const Unk_819a70* self);
bool Unk_7eb330(u16 move);
bool Unk_81bba0(u32 id);
bool Unk_81acc0(const Unk_819600_Self* self, u8 pokeId);
u8 Unk_81a350(const Unk_819600_Self* self, u8 arg);
void Unk_81bd40(const Unk_819600_Self* self, u8 pokeId, u8 count, u8 value);
void Unk_819840(const Unk_819600_Self* self, u64 value);
void Unk_819850(const Unk_819600_Self* self);
void Unk_884a50(void* self, u8 pokeId, u32 stat, u8 amount);

// The helpers of 0x7100886420 and 0x7100886520 (Unk_886420.cpp).
void Unk_886420(void* self, u8 pokeId);
void Unk_886520(void* self, u8 pokeId);

// What 0x7100886420 and 0x7100886520 give Unk_81aa70 (field_0 the Pokemon,
// field_1 the form it gets), with a message list at +0x8.
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

// What 0x7100886b60 gives Unk_819b80, with a message list at +0x10.
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

// Handler.h's Unk_82c210_Arg.
void Unk_81a590(const Unk_819600_Self* self, const Unk_82c210_Arg& arg);

// The object 0x7100886f30 is given: the battle state at +0x8 (as in
// Unk_819600_Self), an event entry at +0x10 and three values.
struct Unk_886f30_Self {
    u8 _0[8];
    const Unk_7fe1d0* field_8;
    const Unk_7e9a60* field_10;
    u16 field_18;
    u8 field_1a;
    u8 _1b;
    u16 field_1c;
    u8 field_1e;
};
PKMN_OFFSET_ASSERT(Unk_886f30_Self, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_886f30_Self, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_886f30_Self, field_1c, 0x1c);
PKMN_OFFSET_ASSERT(Unk_886f30_Self, field_1e, 0x1e);
