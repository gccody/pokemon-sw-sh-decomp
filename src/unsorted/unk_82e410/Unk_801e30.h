#pragma once
// Scope: common
// A table of entries per battle side (two) and kind (22), each counting how
// often its kind was set, up to a per-kind limit (0x7100802530), with the
// condition value it was first set with. Unk_8022b0_Entry is the object of
// vtable Unk_23ac9d8 (0x7100802310 constructs it). Placeholder names: rename
// once the classes are known.
#include <types.h>

struct Unk_8022b0_Entry {
    u8 _0[0x8];  // vtable Unk_23ac9d8
    struct Data {
        u32 field_0;  // the kind
        u64 field_8;  // the condition value
        u32 field_10;
        u32 field_14;  // how often it was set
    } field_8;
};
PKMN_OFFSET_ASSERT(Unk_8022b0_Entry, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_8022b0_Entry::Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_8022b0_Entry::Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_8022b0_Entry::Data, field_14, 0x14);
PKMN_SIZE_ASSERT(Unk_8022b0_Entry, 0x20);

struct Unk_8022b0_Slot {
    u8 _0[0x8];
    Unk_8022b0_Entry* field_8;
    u8 _10[0x10];
};
PKMN_OFFSET_ASSERT(Unk_8022b0_Slot, field_8, 0x8);
PKMN_SIZE_ASSERT(Unk_8022b0_Slot, 0x20);

struct Unk_8022b0_Table {
    Unk_8022b0_Slot field_0[2][0x16];
};
PKMN_SIZE_ASSERT(Unk_8022b0_Table, 0x580);

void Unk_801e30(Unk_8022b0_Table* self);
Unk_8022b0_Entry* Unk_8022b0(u64 self, u8 pos, u32 kind);
bool Unk_8021d0(void* self, u8 pos1, u8 pos2, u32 kind);

void Unk_802350(Unk_8022b0_Entry* self, const Unk_8022b0_Entry* other);
void Unk_802370(Unk_8022b0_Entry* self, Unk_8022b0_Entry* other);
bool Unk_802430(Unk_8022b0_Entry* self);
bool Unk_8023b0(Unk_8022b0_Entry* self, const u64* value);
u32 Unk_8024c0(const Unk_8022b0_Entry* self);

// src/unsorted/unk_82e410/Unk_8024e0.cpp
u32 Unk_802530(s32 kind);
