// Scope: common
// The entries of the table (src/unsorted/unk_82e410/Unk_801e30.h): copying,
// swapping, resetting and setting them.
#include "unsorted/unk_82e410/Unk_801e30.h"

// src/battle/battle_engine/Unk_7ee6b0.h
u16 Unk_7f89e0(const u64* condition);

// 0x7100802350
void Unk_802350(Unk_8022b0_Entry* self, const Unk_8022b0_Entry* other) {
    self->field_8 = other->field_8;
}

// 0x7100802370
void Unk_802370(Unk_8022b0_Entry* self, Unk_8022b0_Entry* other) {
    Unk_8022b0_Entry::Data data = other->field_8;
    other->field_8 = self->field_8;
    self->field_8 = data;
}

// 0x71008023b0
bool Unk_8023b0(Unk_8022b0_Entry* self, const u64* value) {
    u32 count = self->field_8.field_14;
    if (count == 0) {
        self->field_8.field_10 = 0;
        self->field_8.field_14 = 1;
        self->field_8.field_8 = *value;
        return true;
    }
    if (count >= Unk_802530(self->field_8.field_0))
        return false;
    ++self->field_8.field_14;
    return true;
}

// 0x7100802430
bool Unk_802430(Unk_8022b0_Entry* self) {
    if (self->field_8.field_14 == 0)
        return false;
    self->field_8.field_8 &= ~u64(7);
    self->field_8.field_10 = 0;
    self->field_8.field_14 = 0;
    return true;
}

// 0x71008024c0
u32 Unk_8024c0(const Unk_8022b0_Entry* self) {
    return Unk_7f89e0(&self->field_8.field_8);
}
