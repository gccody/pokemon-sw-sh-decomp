// Scope: common
#include "unsorted/Unk_14f5fb0.h"

// NON_MATCHING: ordering: the original speculates the field_24 division of
// position() before the field_20 one (and selects field_4 first); same instructions.
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

// NON_MATCHING: the original computes the item index per branch as
// index(pos shifted by field_10/field_14) and divides it directly; this reuses the
// page start and keeps position()'s remainder.
// 0x71014f5a60
bool Unk_14f5a60(const Unk_14f5fb0* self, const Unk_14f5fb0_Pair* pos) {
    if (self->field_c <= 0) {
        return false;
    }
    s32 first = self->field_14 + self->field_10 * Unk_14f5fb0_lineSize(*self);
    Unk_14f5fb0_Pair firstPos = Unk_14f5fb0_position(*self, first);
    s32 firstLine = Unk_14f5fb0_major(*self, firstPos);
    s32 index = self->field_14 + Unk_14f5fb0_index(*self, *pos) +
                self->field_10 * Unk_14f5fb0_lineSize(*self);
    Unk_14f5fb0_Pair indexPos = Unk_14f5fb0_position(*self, index);
    s32 line = Unk_14f5fb0_major(*self, indexPos);
    if (line > firstLine) {
        if (self->field_10 == self->field_c || line <= self->field_1c + self->field_10) {
            return false;
        }
    } else if (line < firstLine) {
        if (self->field_10 == 0 || line >= self->field_18 + self->field_10) {
            return false;
        }
    } else {
        return false;
    }
    s32 step = Unk_14f5fb0_major(*self, *pos);
    if (step > 0) {
        return self->field_10 < self->field_c;
    }
    return step != 0 && self->field_10 > 0;
}

// NON_MATCHING: same item-index shape difference as Unk_14f5a60.
// 0x71014f5b70
bool Unk_14f5b70(const Unk_14f5fb0* self, const Unk_14f5fb0_Pair* pos) {
    s32 first = self->field_14 + self->field_10 * Unk_14f5fb0_lineSize(*self);
    Unk_14f5fb0_Pair firstPos = Unk_14f5fb0_position(*self, first);
    s32 firstLine = Unk_14f5fb0_major(*self, firstPos);
    s32 index = self->field_14 + Unk_14f5fb0_index(*self, *pos) +
                self->field_10 * Unk_14f5fb0_lineSize(*self);
    Unk_14f5fb0_Pair indexPos = Unk_14f5fb0_position(*self, index);
    s32 line = Unk_14f5fb0_major(*self, indexPos);
    if (line > firstLine) {
        if (line <= self->field_1c + self->field_10) {
            return false;
        }
        return self->field_10 != self->field_c;
    }
    if (line < firstLine) {
        return self->field_10 != 0 && line < self->field_18 + self->field_10;
    }
    return false;
}
