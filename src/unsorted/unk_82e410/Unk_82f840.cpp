// Scope: common
// A list of up to five u32s with a switch, from the TU of
// 0x710082f7f0-0x710082f9e0 (its constructors and clear are leaf functions:
// 0x710082f7f0, 0x710082f810, 0x710082f830, in src/unsorted/leaf/Unk_82f7f0.cpp).
// 0x710082f450 and 0x710083ae70 add to it, 0x71008419c0 reads it.
#include <types.h>

struct Unk_82f840_List {
    u32 field_0[5];
    u32 field_14;
    bool field_18;
};
PKMN_SIZE_ASSERT(Unk_82f840_List, 0x1c);
PKMN_OFFSET_ASSERT(Unk_82f840_List, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_82f840_List, field_18, 0x18);

// 0x710082f840
void Unk_82f840(Unk_82f840_List* self, u32 value) {
    if (self->field_18 && self->field_14 < 5)
        self->field_0[self->field_14++] = value;
}

static u32 Unk_82f870_Count(const Unk_82f840_List* self, u32 value) {
    u32 n = 0;
    for (u32 i = 0; i < self->field_14; i++)
        if (self->field_0[i] == value)
            n++;
    return n;
}

// 0x710082f870
u32 Unk_82f870(const Unk_82f840_List* self) {
    if (self->field_18 && self->field_14 != 0) {
        if (Unk_82f870_Count(self, 1) != 0)
            return 0;
        if (Unk_82f870_Count(self, 3) != 0)
            return 1;
    }
    return 2;
}
