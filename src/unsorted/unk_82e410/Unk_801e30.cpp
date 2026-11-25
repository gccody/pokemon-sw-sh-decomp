// Scope: common
// Looking up the entries of the table (src/unsorted/unk_82e410/Unk_801e30.h)
// by side and kind, resetting them all and swapping two sides' entries.
#include "unsorted/unk_82e410/Unk_801e30.h"

// src/battle/battle_engine/Unk_7f9a10.cpp
bool Unk_7fa9c0(u8 position);
// src/unsorted/leaf/Unk_801780.cpp
struct Unk_802460;
bool Unk_802460_check(const Unk_802460* self);

static inline Unk_8022b0_Entry* Unk_Find(const Unk_8022b0_Table* self, u8 pos, s32 kind) {
    if (!Unk_7fa9c0(pos) || kind >= 0x16)
        return nullptr;
    return self->field_0[pos][static_cast<u32>(kind)].field_8;
}

static inline bool Unk_IsSet(const Unk_8022b0_Entry* entry) {
    return Unk_802460_check(reinterpret_cast<const Unk_802460*>(entry));
}

// 0x7100801e30
void Unk_801e30(Unk_8022b0_Table* self) {
    for (u32 pos = 0; pos < 2; ++pos) {
        for (u32 kind = 0; kind < 0x16; ++kind)
            Unk_802430(Unk_Find(self, pos, kind));
    }
}

// 0x71008021d0
bool Unk_8021d0(void* self, u8 pos1, u8 pos2, u32 kind) {
    const Unk_8022b0_Table* table = static_cast<const Unk_8022b0_Table*>(self);
    Unk_8022b0_Entry* a = Unk_Find(table, pos1, kind);
    Unk_8022b0_Entry* b = Unk_Find(table, pos2, kind);
    if (a == nullptr || b == nullptr)
        return false;
    if (!Unk_IsSet(a) && !Unk_IsSet(b))
        return false;
    Unk_802370(a, b);
    return true;
}

// 0x71008022b0
Unk_8022b0_Entry* Unk_8022b0(u64 self, u8 pos, u32 kind) {
    return Unk_Find(reinterpret_cast<const Unk_8022b0_Table*>(self), pos, kind);
}
