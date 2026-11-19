#pragma once
// Scope: common
// The objects on Unk_23acc98 that Unk_7e0080 holds (src/unsorted/Unk_7e0080.h,
// 0x710081c630 creates all 239): each of their classes has a TU of its own
// in game/unk_82e410, with a static initialiser, and one or more functions
// that take the object, a result and a parameter block, and call the other
// objects through Unk_7e0080. The classes come from tools/vtables.py, whose
// header holds only their constructors, so their functions are free
// functions here, named after their addresses.
//
// The base's accessors (0x710082a9b0-0x710082aa80) and Unk_7e0080's
// (0x7100828410-...) are tools/leafgen.py placeholders that take a placeholder
// type each and return u64: the inline functions below give them the
// objects' types. Placeholder names: rename once the classes are known.
#include <types.h>

#include "unsorted/Unk_7e0080.h"
#include "unsorted/ctor/Unk_23acc98.h"
#include "unsorted/unk_82e410/Holder.h"

struct Unk_82a9b0;
struct Unk_82a9c0;
struct Unk_82a9d0;
struct Unk_82a9e0;
struct Unk_82a9f0;
struct Unk_82aa00;
struct Unk_82aa10;
struct Unk_82aa20;
struct Unk_82aa50;
struct Unk_82aa60;
struct Unk_82aa70;
struct Unk_82aa80;
u64 Unk_82a9b0_getField8(const Unk_82a9b0* self);
u64 Unk_82a9c0_getField10(const Unk_82a9c0* self);
u64 Unk_82a9d0_getField18(const Unk_82a9d0* self);
u64 Unk_82a9e0_getField20(const Unk_82a9e0* self);
u64 Unk_82a9f0_getField28(const Unk_82a9f0* self);
u64 Unk_82aa00_getField30(const Unk_82aa00* self);
u64 Unk_82aa10_getField38(const Unk_82aa10* self);
u64 Unk_82aa20_getField40(const Unk_82aa20* self);
u64 Unk_82aa50_getField48(const Unk_82aa50* self);
u64 Unk_82aa60_getField50(const Unk_82aa60* self);
u64 Unk_82aa70_getField58(const Unk_82aa70* self);
u64 Unk_82aa80_getField60(const Unk_82aa80* self);

// 0x710082a9e0: what most of them hand their messages to (field_8.field_0[3])
inline void* Unk_23acc98_Field20(const Unk_23acc98* self) {
    return reinterpret_cast<void*>(
        Unk_82a9e0_getField20(reinterpret_cast<const Unk_82a9e0*>(self)));
}

// The others of field_8 (field_0[0..10]), as they're passed on
inline void* Unk_23acc98_Field8(const Unk_23acc98* self) {
    return reinterpret_cast<void*>(Unk_82a9b0_getField8(reinterpret_cast<const Unk_82a9b0*>(self)));
}
inline void* Unk_23acc98_Field10(const Unk_23acc98* self) {
    return reinterpret_cast<void*>(
        Unk_82a9c0_getField10(reinterpret_cast<const Unk_82a9c0*>(self)));
}
inline void* Unk_23acc98_Field18(const Unk_23acc98* self) {
    return reinterpret_cast<void*>(
        Unk_82a9d0_getField18(reinterpret_cast<const Unk_82a9d0*>(self)));
}
inline void* Unk_23acc98_Field28(const Unk_23acc98* self) {
    return reinterpret_cast<void*>(
        Unk_82a9f0_getField28(reinterpret_cast<const Unk_82a9f0*>(self)));
}
inline void* Unk_23acc98_Field30(const Unk_23acc98* self) {
    return reinterpret_cast<void*>(
        Unk_82aa00_getField30(reinterpret_cast<const Unk_82aa00*>(self)));
}
inline void* Unk_23acc98_Field38(const Unk_23acc98* self) {
    return reinterpret_cast<void*>(
        Unk_82aa10_getField38(reinterpret_cast<const Unk_82aa10*>(self)));
}
inline void* Unk_23acc98_Field40(const Unk_23acc98* self) {
    return reinterpret_cast<void*>(
        Unk_82aa20_getField40(reinterpret_cast<const Unk_82aa20*>(self)));
}
inline void* Unk_23acc98_Field48(const Unk_23acc98* self) {
    return reinterpret_cast<void*>(
        Unk_82aa50_getField48(reinterpret_cast<const Unk_82aa50*>(self)));
}
inline void* Unk_23acc98_Field50(const Unk_23acc98* self) {
    return reinterpret_cast<void*>(
        Unk_82aa60_getField50(reinterpret_cast<const Unk_82aa60*>(self)));
}
inline void* Unk_23acc98_Field58(const Unk_23acc98* self) {
    return reinterpret_cast<void*>(
        Unk_82aa70_getField58(reinterpret_cast<const Unk_82aa70*>(self)));
}

// 0x710082aa80: the Unk_7e0080 that holds all of them (field_8.field_0[11])
inline const Unk_7e0080* Unk_23acc98_Holder(const Unk_23acc98* self) {
    return reinterpret_cast<const Unk_7e0080*>(
        Unk_82aa80_getField60(reinterpret_cast<const Unk_82aa80*>(self)));
}

// 0x710082ab10, 0x710082abb0: an object by its index (u8)
u64 Unk_82ab10(void* self, u8 index);
inline void* Unk_23acc98_Object(Unk_23acc98* self, u8 index) {
    return reinterpret_cast<void*>(Unk_82ab10(self, index));
}
u8 Unk_82abb0(void* self, u8 index);

// What they return: a flag (most only set it) and a value.
struct Unk_23acc98_Result {
    bool field_0;
    u32 field_4;
};
PKMN_SIZE_ASSERT(Unk_23acc98_Result, 0x8);

// A message block (cleared by 0x7100803c60, Unk_803c60_set) inside the
// parameter blocks.
struct Unk_23acc98_Message {
    u8 data[0x24];
};
PKMN_SIZE_ASSERT(Unk_23acc98_Message, 0x24);

// --- Unk_23aceb8 (Unk_7e0080::field_16e0), 0x710082ec20
struct Unk_82ec20_Arg {
    u8 field_0;
    u8 field_1;
    u16 field_2;
    u16 field_4;
    u8 field_6;
    u8 field_7;
    u8 field_8;
    u8 field_9;
    u8 field_a;
    u8 _b;
    Unk_23acc98_Message field_c;
};
PKMN_SIZE_ASSERT(Unk_82ec20_Arg, 0x30);
PKMN_OFFSET_ASSERT(Unk_82ec20_Arg, field_c, 0xc);
void Unk_82ec20(Unk_23aceb8* self, Unk_23acc98_Result& result, const Unk_82ec20_Arg& arg);

// --- Unk_23aced8 (Unk_7e0080::field_1740), 0x710082ee70
struct Unk_82ee70_Arg {
    void* field_0;
    u16 field_8;
    u8 field_a;
};
PKMN_OFFSET_ASSERT(Unk_82ee70_Arg, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_82ee70_Arg, field_a, 0xa);
void Unk_82ee70(Unk_23aced8* self, Unk_23acc98_Result& result, const Unk_82ee70_Arg& arg);

// --- Unk_23acef8 (Unk_7e0080::field_1720), 0x710082efc0
struct Unk_82efc0_Arg {
    void* field_0;
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_82efc0_Arg, field_8, 0x8);
void Unk_82efc0(Unk_23acef8* self, Unk_23acc98_Result& result, const Unk_82efc0_Arg& arg);

// --- Unk_23acf18 (Unk_7e0080::field_1700), 0x710082f100
struct Unk_82f100_Arg {
    void* field_0;
};
void Unk_82f100(Unk_23acf18* self, Unk_23acc98_Result& result, const Unk_82f100_Arg& arg);

// --- Unk_23acf58 (Unk_7e0080::field_16a0), 0x710082f450
struct Unk_82f450_Arg {
    u8 field_0;
    u8 field_1;
    u32 field_4;
    u32 field_8;
    u8 field_c;
    u16 field_e;
    u32 field_10;
    u8 field_14;
    u8 field_15;
    u64 field_18;
};
PKMN_SIZE_ASSERT(Unk_82f450_Arg, 0x20);
PKMN_OFFSET_ASSERT(Unk_82f450_Arg, field_e, 0xe);
PKMN_OFFSET_ASSERT(Unk_82f450_Arg, field_15, 0x15);
PKMN_OFFSET_ASSERT(Unk_82f450_Arg, field_18, 0x18);
void Unk_82f450(Unk_23acf58* self, Unk_23acc98_Result& result, const Unk_82f450_Arg& arg);
bool Unk_82f6e0(Unk_23acf58* self, void* object1, void* object2);

// --- Unk_23acf38 (Unk_7e0080::field_1680), 0x710082f210
struct Unk_82f210_Arg {
    u8 field_0;
    void* field_8;
    u32 field_10;
    u32 field_14;
    u8 field_18;
    u16 field_1a;
    u32 field_1c;
    u8 field_20;
    u8 field_21;
    u64 field_28;
    u8 field_30;
    const Unk_23acc98_Message* field_38;
    u8 field_40;
};
PKMN_SIZE_ASSERT(Unk_82f210_Arg, 0x48);
PKMN_OFFSET_ASSERT(Unk_82f210_Arg, field_1a, 0x1a);
PKMN_OFFSET_ASSERT(Unk_82f210_Arg, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_82f210_Arg, field_40, 0x40);
void Unk_82f210(Unk_23acf38* self, Unk_23acc98_Result& result, const Unk_82f210_Arg& arg);
