// Scope: common
#include "unsorted/Unk_14f5fb0.h"

// 0x71014f58b0
s32 Unk_14f58b0(const Unk_14f5fb0* self, s32 index) {
    s32 partial = index % Unk_14f5fb0_lineSize(*self) != 0;
    Unk_14f5fb0_Pair pos = Unk_14f5fb0_position(*self, index);
    s32 count = partial - Unk_14f5fb0_lineCount(*self) + Unk_14f5fb0_major(*self, pos);
    f32 value = static_cast<f32>(count);
    return static_cast<s32>(value < 0.0f ? 0.0f : value);
}

// 0x71014f5920
void Unk_14f5920(void* self, u32 first, u32 last) {
    Unk_14f5fb0* grid = static_cast<Unk_14f5fb0*>(self);
    grid->field_18 = first;
    grid->field_1c = last;
}

// Index of the last item of the current page.
static inline s32 lastIndex(const Unk_14f5fb0* self) {
    if (self->field_10 < self->field_c) {
        return self->field_20 * self->field_24 - 1;
    }
    return self->field_8 - Unk_14f5fb0_lineSize(*self) * self->field_c - 1;
}

// 0x71014f5930
bool Unk_14f5930(const Unk_14f5fb0* self, const Unk_14f5fb0_Pair* pos) {
    s32 index = self->field_14 + Unk_14f5fb0_index(*self, *pos);
    if (index < 0) {
        return false;
    }
    return index <= lastIndex(self);
}

// 0x71014f59d0
s32 Unk_14f59d0(const Unk_14f5fb0* self, const Unk_14f5fb0_Pair* pos) {
    return self->field_14 + Unk_14f5fb0_index(*self, *pos);
}

// 0x71014f5a10
s32 Unk_14f5a10(const Unk_14f5fb0* self) {
    return lastIndex(self);
}

// 0x71014f5c40
s32 Unk_14f5c40(const Unk_14f5fb0* self, const Unk_14f5fb0_Pair* pos) {
    return Unk_14f5fb0_major(*self, *pos);
}
