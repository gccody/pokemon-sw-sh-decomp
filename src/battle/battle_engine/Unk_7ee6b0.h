#pragma once
// A battle Pokemon (its getters of single fields are leaf functions matched
// on their own, in src/unsorted/leaf/Unk_7ed7d0.cpp, each with a placeholder
// type of its own). Its member functions are 0x71007ed7b0 to 0x71007f7690.
// Placeholder names: rename once the class is known.
#include <types.h>

// One move slot: the move as it is in the party (field_0) and as it is in
// battle (field_c), which field_18 says are the same move.
struct Unk_7ee6b0_Move {
    u32 field_0;
    u8 field_4;  // PP
    u8 field_5;  // max PP
    u8 field_6;
    u8 field_7;
    u8 field_8;
    u8 field_9;
    u8 _a[0xc - 0xa];
};
PKMN_SIZE_ASSERT(Unk_7ee6b0_Move, 0xc);

struct Unk_7ee6b0_Slot {
    Unk_7ee6b0_Move field_0;
    Unk_7ee6b0_Move field_c;
    bool field_18;
};
PKMN_SIZE_ASSERT(Unk_7ee6b0_Slot, 0x1c);

// What the battle Pokemon remembers of a turn: up to 6 actions.
struct Unk_7ee6b0_Action {
    u16 field_0;
    u16 field_2;
    u32 field_4;
    u8 field_8;
    u8 field_9;
    u8 field_a;
};
PKMN_SIZE_ASSERT(Unk_7ee6b0_Action, 0xc);
struct Unk_7ee6b0_Turn {
    Unk_7ee6b0_Action field_0[6];
};
PKMN_SIZE_ASSERT(Unk_7ee6b0_Turn, 0x48);

// What the battle Pokemon holds at +0x460 (a field effect's state).
struct Unk_7ee6b0_Field;
bool Unk_7ffe20(const Unk_7ee6b0_Field* self, u32 effect);

// What the battle Pokemon holds at +0x60: the party Pokemon, HP, and the
// conditions (Unk_7f8780_get() for none) with their turn counters.
struct Unk_7ee6b0_Core {
    void* field_0;
    u8 _8[0x10 - 0x8];
    u16 field_10;
    u16 field_12;  // max HP
    u16 field_14;  // HP
    u16 field_16;
    u8 _18[0x1d - 0x18];
    u8 field_1d;  // id
    u8 _1e[0x27 - 0x1e];
    u8 field_27_0 : 5;
    u8 field_27_5 : 1;
    u8 field_27_6 : 1;
    u8 field_27_7 : 1;
    u8 field_28_0 : 1;
    u8 field_28_1 : 1;
    u8 _28_2 : 6;
    u8 _29[0x30 - 0x29];
    u64 field_30[0x2d];
    u8 field_198[0x2d];
    u8 field_1c5;
    u8 field_1c6[0x1e];
    u8 _1e4[0x1e6 - 0x1e4];
    u8 field_1e6;
};
PKMN_SIZE_ASSERT(Unk_7ee6b0_Core, 0x1e8);
PKMN_OFFSET_ASSERT(Unk_7ee6b0_Core, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_7ee6b0_Core, field_198, 0x198);

struct Unk_7ee6b0 {
    u8 _0[0x60];
    Unk_7ee6b0_Core field_60;
    u8 _248[0x270 - 0x248];
    u8 field_270;
    u8 field_271;
    u8 _272[0x299 - 0x272];
    u8 field_299;
    u8 _29a[0x2a0 - 0x29a];
    u16 field_2a0;
    u16 field_2a2;  // stats 8 to 12
    u16 field_2a4;
    u16 field_2a6;
    u16 field_2a8;
    u16 field_2aa;
    u8 field_2ac;  // types
    u8 field_2ad;
    u8 field_2ae;
    u8 _2af;
    u32 field_2b0;
    s8 field_2b4;  // stat stages 1 to 7
    s8 field_2b5;
    s8 field_2b6;
    s8 field_2b7;
    s8 field_2b8;
    s8 field_2b9;
    s8 field_2ba;
    u8 _2bb;
    u16 field_2bc;  // effort values: their total, then each stat's
    u8 field_2be;
    u8 field_2bf;
    u8 field_2c0;
    u8 field_2c1;
    u8 field_2c2;
    u8 field_2c3;
    u8 field_2c4;
    u8 _2c5;
    u8 field_2c6;
    u8 _2c7;
    Unk_7ee6b0_Slot field_2c8[4];
    u16 field_338;
    u16 field_33a;
    u8 field_33c;  // number of moves
    u8 field_33d;
    u8 _33e;
    u8 field_33f;
    u8 field_340;
    u8 field_341;
    u8 field_342;
    u8 _343[0x344 - 0x343];
    u16 field_344;
    u8 _346[0x348 - 0x346];
    u16 field_348;
    u8 field_34a;
    u8 _34b;
    u32 field_34c;
    u32 field_350;
    u8 _354[0x358 - 0x354];
    u8 field_358[4];  // bit flags
    u8 field_35c[4];
    u8 field_360[1];
    u8 field_361[3];
    u8 _364[0x368 - 0x364];
    u32 field_368[4];
    Unk_7ee6b0_Turn field_378[3];
    u8 field_450[3];
    u8 field_453;
    u8 _454[0x456 - 0x454];
    u16 field_456;
    u8 _458[0x460 - 0x458];
    Unk_7ee6b0_Field* field_460;
};
PKMN_OFFSET_ASSERT(Unk_7ee6b0, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_7ee6b0, field_2c8, 0x2c8);
PKMN_OFFSET_ASSERT(Unk_7ee6b0, field_33c, 0x33c);
PKMN_OFFSET_ASSERT(Unk_7ee6b0, field_340, 0x340);
PKMN_OFFSET_ASSERT(Unk_7ee6b0, field_358, 0x358);
PKMN_OFFSET_ASSERT(Unk_7ee6b0, field_460, 0x460);
PKMN_OFFSET_ASSERT(Unk_7ee6b0, field_2a2, 0x2a2);
PKMN_OFFSET_ASSERT(Unk_7ee6b0, field_450, 0x450);
PKMN_OFFSET_ASSERT(Unk_7ee6b0, field_378, 0x378);
PKMN_OFFSET_ASSERT(Unk_7ee6b0, field_34c, 0x34c);
PKMN_OFFSET_ASSERT(Unk_7ee6b0, field_2c4, 0x2c4);

void Unk_765b00(void* party, u8 slot, u8 pp);
u8 Unk_780ca0(u32 move, u32 arg);
// Declared as src/unsorted/leaf/Unk_7ed7d0.cpp declares it.
u32 Unk_7eef50(void* self, u32 value);

u64 Unk_7f8780_get();
// A leaf function (src/unsorted/leaf/Unk_7f8780.cpp) types the condition its own way.
struct Unk_7f8790;
bool Unk_7f8790_check(const Unk_7f8790* condition);
bool Unk_7f7c40(s32 condition);
u8 Unk_7f8960(const u64* condition);
u8 Unk_7f88e0(const u64* condition);
u16 Unk_7f89e0(const u64* condition);
bool Unk_767950(void* party, u32 arg);

// Leaf functions (src/unsorted/leaf/Unk_7ff860.cpp) on what +0x460 holds.
struct Unk_800280;
bool Unk_800280_check(const Unk_800280* self);
bool Unk_800290_call(void* self, u32 value);

u32 Unk_7f7b60(u16 species, u8 form, u32 value);
// Declared as src/unsorted/leaf/Unk_803a10.cpp declares it.
u32 Unk_803e30_get();

// The random number generator (src/unsorted/leaf/Unk_7ed7d0.cpp returns it).
extern void* Unk_27ced28 __attribute__((visibility("hidden")));
u64 Unk_7f8c00(void* random, u64 max);
u64 Unk_7f8c20(void* random, u64 range);

// What 0x71007f3610 to 0x71007f3880 act on.
struct Unk_7f4450_Data {
    u8 _0[0x6];
    u8 field_6;
    u8 field_7;
    u8 field_8;
    u8 field_9[2];
    u8 _b;
    u32 field_c[2];
    u32 field_14[2];
};
PKMN_SIZE_ASSERT(Unk_7f4450_Data, 0x1c);
// In another TU (src/battle/battle_engine/Unk_7f4450.cpp): it isn't inlined.
void Unk_7f4450(Unk_7f4450_Data* self, const Unk_7f4450_Data* other);

struct Unk_7f3610_Self {
    void* field_0;
    u8 _8[0x20 - 0x8];
    Unk_7f4450_Data field_20;
    u8 field_3c;
    u8 field_3d;
    u8 field_3e;
    u8 field_3f;
    u8 field_40;
};
PKMN_OFFSET_ASSERT(Unk_7f3610_Self, field_3c, 0x3c);

// Leaf functions (src/unsorted/leaf/Unk_7fc740.cpp) on what +0 points to.
struct Unk_7fc750;
struct Unk_7fc750_arg1;
void Unk_7fc750_set(Unk_7fc750* self, const Unk_7fc750_arg1* value);
struct Unk_7fc920;
void Unk_7fc920_set(Unk_7fc920* self);

// Tables of stage ratios ({numerator, denominator} for stages 0 to 12) and
// chances the TU defines (their contents are data, not written here).
struct Unk_7ee6b0_Ratio {
    u8 field_0;
    u8 field_1;
};
extern const Unk_7ee6b0_Ratio Unk_1f118f4[13] __attribute__((visibility("hidden")));
extern const Unk_7ee6b0_Ratio Unk_1f1190e[13] __attribute__((visibility("hidden")));
extern const u8 Unk_1b14ad0[4] __attribute__((visibility("hidden")));

// Declared as src/unsorted/leaf/Unk_7ed7d0.cpp declares them.
struct Unk_7ee6c0;
bool Unk_7ee6c0_getField298(const Unk_7ee6c0* self);
extern u64 Unk_27cecf0;
u32 Unk_785c80(u64 self, u16 arg1, u32 arg2);

void Unk_76bc60(u16 species, u8 form);
u32 Unk_76bc80(u32 param);
void Unk_76bd60(u16 species, u8 form);
u32 Unk_76bdf0(u32 param);

// Declared as src/unsorted/leaf/Unk_7ed7d0.cpp names it (the battle
// Pokemon's TU, called out of line).
bool Unk_7f0670(const Unk_7ee6b0* poke, u32 type);
u32 Unk_7eb660(u32 index);
bool Unk_7ef4c0(const Unk_7ee6b0* poke, u32 condition);
u8 Unk_7811e0(u32 move);
