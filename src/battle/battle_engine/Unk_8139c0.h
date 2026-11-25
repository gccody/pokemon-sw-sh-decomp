#pragma once
// What the battle server's commands act on (0x71008139c0 to 0x7100818810):
// the main module at +0x10, whose getters of single fields are leaf functions
// matched on their own (src/unsorted/leaf/Unk_7fe1d0.cpp), each typing the
// module its own way, and the Pokemon its +8 holds (Unk_7ecc90 looks one up
// by id). Placeholder names: rename once the classes are known.
#include <types.h>

#include "battle/battle_engine/Unk_7ee6b0.h"

struct Unk_7fe1d0;
struct Unk_7fe1e0;
struct Unk_7fe200;
struct Unk_7fe240;
struct Unk_7fe250;
struct Unk_7fe290;

// The battle's Pokemon, by id.
struct Unk_7ecc90_Con;
Unk_7ee6b0* Unk_7ecc90(Unk_7ecc90_Con* self, u8 pokeId);

Unk_7ecc90_Con* Unk_7fe1d0_getField8(const Unk_7fe1d0* self);
void* Unk_7fe1e0_getField28(const Unk_7fe1e0* self);
void* Unk_7fe200_getField48(const Unk_7fe200* self);
void* Unk_7fe240_getField88(const Unk_7fe240* self);
void* Unk_7fe250_getFielda8(const Unk_7fe250* self);
void* Unk_7fe290_getField128(const Unk_7fe290* self);

struct Unk_8139c0_Self {
    u8 _0[0x8];
    void* field_8;
    const Unk_7fe1d0* field_10;
    void* field_18;
};
PKMN_OFFSET_ASSERT(Unk_8139c0_Self, field_10, 0x10);

inline Unk_7ee6b0* Unk_8139c0_Poke(const Unk_8139c0_Self* self, u8 pokeId) {
    return Unk_7ecc90(Unk_7fe1d0_getField8(self->field_10), pokeId);
}

// A list of bytes with its count first.
struct Unk_816910_List {
    u32 field_0;
    u8 _4[0x8 - 0x4];
    u8 field_8[1];
};

// The battle Pokemon's member functions (src/battle/battle_engine/Unk_7ee6b0.cpp)
// and leaf functions on it with types of their own (src/unsorted/leaf).
void Unk_7f26d0(Unk_7ee6b0* self, u32 index, u8 value);
void Unk_7f2700(Unk_7ee6b0* self, u8 index, u32 value);
void Unk_7f2720(Unk_7ee6b0* self, u8 index, u32 value);
void Unk_7f0250(Unk_7ee6b0* self, u8 slot, u8 count);
u8 Unk_7f0010(const Unk_7ee6b0* self, u8 slot);
void Unk_7f0040(Unk_7ee6b0* self, u8 slot, u8 value);
u8 Unk_7f0080(const Unk_7ee6b0* self, u8 slot);
void Unk_7f00b0(Unk_7ee6b0* self, u8 slot, u8 value);
void Unk_7f2590(Unk_7ee6b0* self, const Unk_7ee6b0_Action* action);
void Unk_7f2fe0(Unk_7ee6b0* self, u32 stat, u8 amount);
void Unk_7f2150(Unk_7ee6b0* self, const Unk_7ee6b0* other);
bool Unk_7f22a0(Unk_7ee6b0* self, u16 types, u32 arg2);
void Unk_7f2380(Unk_7ee6b0* self, u32 arg1, bool arg2);
void Unk_7f2a10(Unk_7ee6b0* self, const Unk_7ee6b0* other);
void Unk_7f0750(Unk_7ee6b0* self, u32 stat, u16 value);
void Unk_7f03e0(Unk_7ee6b0* self, u8 slot, u32 move, u8 maxPP, bool original);
void Unk_7f1e00(Unk_7ee6b0* self);
void Unk_7f1a50(Unk_7ee6b0* self);
void Unk_7f13e0(Unk_7ee6b0* self, u16 amount);
void Unk_7f19d0(Unk_7ee6b0* self);
bool Unk_7f15a0(Unk_7ee6b0* self, u32 condition, const u64* value, bool* out);
void Unk_7f24c0(Unk_7ee6b0* self, u8 arg1, u8 arg2, bool same, u32 arg4, u32 arg5);
void Unk_7f0370(Unk_7ee6b0* self, u8 slot);
struct Unk_7ef2e0;
void Unk_7ef2e0_set(Unk_7ef2e0* self);
struct Unk_7f13d0;
void Unk_7f13d0_clearField74(Unk_7f13d0* self);
struct Unk_7f2310;
void Unk_7f2310_set(Unk_7f2310* self, u8 value, u32 arg2);
struct Unk_7ee040;
void Unk_7ee040_set(Unk_7ee040* self);
struct Unk_7f1cd0;
void Unk_7f1cd0_set(Unk_7f1cd0* self);

void Unk_8006e0(void* self, u8 arg1, u8 arg2);
void Unk_8002a0(void* self, u8 arg1, u64 arg2);
void Unk_7ffbd0(void* self, u32 arg1, void* arg2);
void Unk_7ffce0(void* self, u32 arg1, u32 arg2);
void Unk_7ffe50(void* self, u32 arg1, u32 arg2);
bool Unk_8021d0(void* self, u8 arg1, u8 arg2, u32 arg3);
void Unk_7eb130(void* self, u8 arg1, u8 arg2, u32 arg3);
void Unk_802ff0(void* self, u8 pokeId);

void Unk_7f1000(Unk_7ee6b0* self, u32 stat, u8 value);
void Unk_7f1390(Unk_7ee6b0* self, u8 value);
bool Unk_7f1320(Unk_7ee6b0* self, s32 count);
struct Unk_7ffb40;
void Unk_7ffb40_set(Unk_7ffb40* self, u8 value, u32 arg2, u32 arg3, u8 arg4);
struct Unk_7fe350;
void* Unk_7fe350_getField2a8(const Unk_7fe350* self);
void Unk_7ff4f0(void* self, u8 arg1, s32 arg2);
void Unk_7ff570(void* self, u8 arg1, u8 arg2);
// A client's party.
struct Unk_7fc430_Party;
Unk_7fc430_Party* Unk_7ed1a0(Unk_7ecc90_Con* self, u32 client);
const Unk_7ee6b0* Unk_7fc430(const Unk_7fc430_Party* self, u8 index);
void Unk_7cc080(void* self, void* party, u8 pokeId);

// What the battle Pokemon holds at +0x278 (Unk_7ee6b0.cpp matches its member
// functions) and what that holds at +0.
struct Unk_7ee810;
Unk_7f3610_Self* Unk_7ee810_getField278(const Unk_7ee810* self);
struct Unk_7f3700;
void* Unk_7f3700_getField0(const Unk_7f3700* self);
void Unk_7f3800(Unk_7f3610_Self* self);
struct Unk_7f3740;
void Unk_7f3740_set(Unk_7f3740* self);
struct Unk_7f3730;
void Unk_7f3730_setField3d(Unk_7f3730* self, u8 value);
struct Unk_7f37b0;
void Unk_7f37b0_set(Unk_7f37b0* self);
struct Unk_7f37d0;
void Unk_7f37d0_set(Unk_7f37d0* self);
struct Unk_7f37e0;
void Unk_7f37e0_set(Unk_7f37e0* self, u8 value);
struct Unk_7fc870;
void Unk_7fc870_set(Unk_7fc870* self, u8 value);
struct Unk_7fc7d0;
void Unk_7fc7d0_set(Unk_7fc7d0* self);
void Unk_7fc890(void* self, u32 value);
struct Unk_7fc8b0;
void Unk_7fc8b0_set(Unk_7fc8b0* self, u8 value);
void Unk_7fc7b0(void* self);
struct Unk_7fc900;
void Unk_7fc900_set(Unk_7fc900* self);
struct Unk_7fc7e0;
void Unk_7fc7e0_set(Unk_7fc7e0* self);

// Declared as src/unsorted/leaf/Unk_7c2d90.cpp names it.
struct Unk_7cac80;
u8 Unk_7cac80_call(const Unk_7cac80* self, u32 value);
struct Unk_7fe2d0;
void* Unk_7fe2d0_getField188(const Unk_7fe2d0* self);
void* Unk_800990(void* self, u8 index);
void Unk_800b60(void* self, u32 value);

void Unk_868a00(void* self, Unk_7ee6b0* poke, u32 arg2, u32 arg3);
void Unk_868b40(void* self, Unk_7ee6b0* poke, u32 arg2);
void Unk_868bf0(void* self, Unk_7ee6b0* poke, u32 arg2);
void Unk_868ca0(void* self, Unk_7ee6b0* poke);
void Unk_87e3b0(void* self, Unk_7ee6b0* poke);
void Unk_87e4b0(void* self, Unk_7ee6b0* poke);
void Unk_87e540(void* self, Unk_7ee6b0* poke, Unk_7ee6b0* other);
void Unk_859180(void* self, Unk_7ee6b0* poke);
void Unk_859280(void* self, Unk_7ee6b0* poke);
void Unk_818830(void* self, Unk_7ee6b0* poke);
void Unk_8188f0(void* self, Unk_7ee6b0* poke);
void Unk_890950(void* self, Unk_7ee6b0* poke, u32 arg2);
void Unk_890a20(void* self, Unk_7ee6b0* poke, u32 arg2);
