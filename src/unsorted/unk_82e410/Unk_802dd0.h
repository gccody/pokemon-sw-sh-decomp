#pragma once
// Scope: common
// Five entries, each with a kind and the id of the Pokemon in it (0x1f when
// none), and a table from Pokemon id to entry index, read and written through
// a pointer and size with a fallback byte for ids out of range (0x7100802dd0
// to 0x71008035f4). Placeholder names: rename once the class is known.
#include <types.h>

struct Unk_7ecc90_Con;

struct Unk_802dd0_Self {
    struct Entry {
        u8 field_0;  // set when the entry is in use
        u8 field_1;  // the kind
        u8 field_2;  // the Pokemon id, 0x1f when none
    };

    Entry field_0[5];
    u8 field_f[30];
    u8* field_30;
    u32 field_38;
    u8 field_3c;

    u8& at(u32 pokeId) {
        if (field_30 != nullptr && pokeId < field_38)
            return field_30[pokeId];
        return field_3c;
    }
};
PKMN_SIZE_ASSERT(Unk_802dd0_Self::Entry, 0x3);
PKMN_OFFSET_ASSERT(Unk_802dd0_Self, field_f, 0xf);
PKMN_OFFSET_ASSERT(Unk_802dd0_Self, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_802dd0_Self, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_802dd0_Self, field_3c, 0x3c);
PKMN_SIZE_ASSERT(Unk_802dd0_Self, 0x40);

void Unk_802dd0(Unk_802dd0_Self* self);
void Unk_802df0(Unk_802dd0_Self* self, const Unk_802dd0_Self* other);
void Unk_802e30(Unk_802dd0_Self* self, void* main, Unk_7ecc90_Con* con);
void Unk_802ff0(void* self, u8 pokeId);
void Unk_803080(Unk_802dd0_Self* self, void* main, u8 index, u8 pokeId, Unk_7ecc90_Con* con);
void Unk_8030d0(Unk_802dd0_Self* self, void* main, u8 index, Unk_7ecc90_Con* con);
void Unk_8032d0(Unk_802dd0_Self* self, u8 a, u8 b);
u8 Unk_803390(const Unk_802dd0_Self* self, u8 kind, u8* out);
u8 Unk_8034a0(const Unk_802dd0_Self* self, u8 kind);
bool Unk_803560(void* self, u8 pokeId);
