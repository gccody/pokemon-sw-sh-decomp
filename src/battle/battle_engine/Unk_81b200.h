#pragma once
// Scope: common
// What the battle's event handlers are given (as in Unk_819600.cpp and
// Unk_81a030.h), with the field at +0x28 that the functions of
// 0x710081b200-0x710081bf38 also read. Placeholder names: rename once the
// functions are known.
#include "battle/battle_engine/Unk_7e8a20.h"
#include "unsorted/unk_82e410/Handler.h"

struct Unk_7fe1d0;
struct Unk_7fe250;
struct Unk_82b4f0;
struct Unk_7ee6b0;
struct Unk_7ecc90_Con;

struct Unk_819600_Self {
    void* field_0;
    const Unk_7fe1d0* field_8;
    const void* field_10;
    const void* field_18;
    const Unk_7e0080* field_20;
    const Unk_82b4f0* field_28;
    void* field_30;
    u8 _38[0x40 - 0x38];
    void* field_40;
};
PKMN_OFFSET_ASSERT(Unk_819600_Self, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_819600_Self, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_819600_Self, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_819600_Self, field_40, 0x40);

// What +0x28 holds: entries of 0x38 bytes at +8, the current one picked by
// the byte at +0x158 (Unk_82afd0). Each has a list of up to five Pokemon,
// with two bytes each, and a flag at +0x36.
struct Unk_82afd0_List {
    u8 count;
    u8 field_1[5];
    u8 field_6[5];
    u8 field_b[5];
};
PKMN_SIZE_ASSERT(Unk_82afd0_List, 0x10);
struct Unk_82afd0_Entry {
    u8 _0[0x24];
    Unk_82afd0_List list;
    u8 _34[0x36 - 0x34];
    u8 field_36;
    u8 _37;
};
PKMN_OFFSET_ASSERT(Unk_82afd0_Entry, list, 0x24);
PKMN_OFFSET_ASSERT(Unk_82afd0_Entry, field_36, 0x36);
PKMN_SIZE_ASSERT(Unk_82afd0_Entry, 0x38);

// The main module's getters (leaf functions with their own placeholder
// types, src/unsorted/leaf) and the battle Pokemon's.
Unk_7ecc90_Con* Unk_7fe1d0_getField8(const Unk_7fe1d0* self);
void* Unk_7fe250_getFielda8(const Unk_7fe250* self);
void* Unk_82b4f0_getField8(const Unk_82b4f0* self);
// NON_MATCHING callee: named without the object it's given (0x710082afd0
// reads +0x158 of x0).
Unk_82afd0_Entry* Unk_82afd0(void* self);
Unk_7ee6b0* Unk_7ecc90(Unk_7ecc90_Con* self, u8 pokeId);
Unk_7ee6b0* Unk_7ed1e0(Unk_7ecc90_Con* self, u8 pokeId);
bool Unk_7cbf80(void* self, u8 pokeId, u8 otherId);
u8 Unk_7cb490(u8 position);
u8 Unk_803600(void* self, u8 pokeId);
u32 Unk_780da0(u32 id);
bool Unk_780c60(u32 id, u32 flag);

inline Unk_82afd0_Entry* Unk_81b200_Entry(const Unk_819600_Self* self) {
    return Unk_82afd0(Unk_82b4f0_getField8(self->field_28));
}

// Adds a Pokemon to a list, when there's room.
inline void Unk_81b200_Add(Unk_82afd0_List* list, u8 pokeId, u8 otherId, u8 value) {
    u8 count = list->count;
    if (count < 5) {
        list->field_1[count] = pokeId;
        list->field_b[count] = otherId;
        list->field_6[count] = value;
        list->count = count + 1;
    }
}
