// Scope: common
#include "unsorted/Unk_14f5fb0.h"

// 0x71014f5e30
s32 Unk_14f5e30(const Unk_14f5fb0* self) {
    if (self->field_c > 0) {
        return Unk_14f5fb0_lineCount(*self) - 1;
    }
    Unk_14f5fb0_Pair last = Unk_14f5fb0_position(*self, self->field_8 - 1);
    return Unk_14f5fb0_major(*self, last);
}

// 0x71014f5ea0
s32 Unk_14f5ea0(const Unk_14f5fb0* self, const Unk_14f5fb0_Pair* pos) {
    return self->field_14 + Unk_14f5fb0_index(*self, *pos) +
           Unk_14f5fb0_lineSize(*self) * self->field_10;
}

// 0x71014f5ef0
s32 Unk_14f5ef0(const Unk_14f5fb0* self, const Unk_14f5fb0_Pair* pos) {
    return Unk_14f5fb0_minor(*self, *pos);
}

// 0x71014f5f10
s32 Unk_14f5f10(void* self, u32 minor, u32 major) {
    return minor + Unk_14f5fb0_lineSize(*static_cast<const Unk_14f5fb0*>(self)) * major;
}

// 0x71014f5f30
bool Unk_14f5f30(const Unk_14f5fb0* self, const Unk_14f5fb0_Pair* delta) {
    Unk_14f5fb0_Pair start = Unk_14f5fb0_position(*self, self->field_14);
    s32 offset = Unk_14f5fb0_minor(*self, start);
    s32 step = Unk_14f5fb0_minor(*self, *delta);
    if (step > 0) {
        return step + offset >= Unk_14f5fb0_lineSize(*self);
    }
    if (step < 0) {
        return step + offset < 0;
    }
    return false;
}

// 0x71014f5fb0 (Shield 0x71014f6050)
// Splits an index into quotient and remainder, in an order chosen by field_28.
// -O3 only: the 3-instruction `mov; bfi; ret` tail is duplicated.
Unk_14f5fb0_Pair Unk_14f5fb0_split(const Unk_14f5fb0* self, s32 index) {
    return Unk_14f5fb0_position(*self, index);
}

// 0x71014f6320
s32 Unk_14f6320(const Unk_14f5fb0* self, const Unk_14f5fb0_Pair* pos) {
    return Unk_14f5fb0_index(*self, *pos);
}

// 0x71014f6350
s32 Unk_14f6350(const Unk_14f5fb0* self, s32 index) {
    Unk_14f5fb0_Pair pos = Unk_14f5fb0_position(*self, index);
    s32 line = Unk_14f5fb0_major(*self, pos) - self->field_18;
    if (line > self->field_c) {
        line = self->field_c;
    }
    if (line < 0) {
        line = 0;
    }
    return line;
}

// 0x71014f6390
s32 Unk_14f6390(const Unk_14f5fb0* self, s32 minor, s32 major) {
    return minor - (self->field_28 == 0 ? self->field_20 : self->field_24) * major;
}
