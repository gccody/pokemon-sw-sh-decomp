// Scope: common
#include "unsorted/Unk_14f5fb0.h"
#include <math.h>

s32 Unk_14f5e30(const Unk_14f5fb0* self);
s32 Unk_14f5ea0(const Unk_14f5fb0* self, const Unk_14f5fb0_Pair* pos);

// The line the current page starts on.
static inline s32 startLine(const Unk_14f5fb0* self) {
    Unk_14f5fb0_Pair start = Unk_14f5fb0_position(*self, self->field_14);
    return Unk_14f5fb0_major(*self, start);
}

// NON_MATCHING: register allocation: the quotient/remainder registers of the inlined
// position() diamonds are swapped (w13/w14, w15/w16); instructions and order match.
// 0x71014f5c70
bool Unk_14f5c70(const Unk_14f5fb0* self, const Unk_14f5fb0_Pair* pos) {
    s32 step = Unk_14f5fb0_major(*self, *pos);
    s32 line = startLine(self);
    s32 last = Unk_14f5e30(self);
    s32 scroll = self->field_10;
    if (step > 0 && line == last && scroll == self->field_c) {
        return true;
    }
    line = startLine(self);
    last = Unk_14f5e30(self);
    s32 index = Unk_14f5ea0(self, pos);
    if (step > 0 && line == last - 1) {
        return self->field_10 == self->field_c && index >= self->field_8;
    }
    return false;
}

// NON_MATCHING: register allocation: w9/w10 swapped in the position() diamond.
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
           self->field_10 * Unk_14f5fb0_lineSize(*self);
}

// 0x71014f5ef0
s32 Unk_14f5ef0(const Unk_14f5fb0* self, const Unk_14f5fb0_Pair* pos) {
    return Unk_14f5fb0_minor(*self, *pos);
}

// 0x71014f5f10
s32 Unk_14f5f10(void* self, u32 minor, u32 major) {
    return minor + Unk_14f5fb0_lineSize(*static_cast<const Unk_14f5fb0*>(self)) * major;
}

// NON_MATCHING: register allocation: w9/w10 swapped in the position() diamond.
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

// NON_MATCHING: `first == -index` compiles to `cmn`; the original materialises
// `neg w2, w10` and uses `cmp` (otherwise identical).
// 0x71014f5ff0
bool Unk_14f5ff0(const Unk_14f5fb0* self, const Unk_14f5fb0_Pair* pos) {
    s32 scroll = self->field_10;
    s32 index = self->field_14;
    s32 lineSize = Unk_14f5fb0_lineSize(*self);
    Unk_14f5fb0_Pair start = Unk_14f5fb0_position(*self, index);
    s32 offset = Unk_14f5fb0_minor(*self, start);
    s32 first = lineSize * scroll;
    s32 step = Unk_14f5fb0_minor(*self, *pos);
    if (step <= 0) {
        if (first == -index && step != 0 && step + offset < 0 && self->field_2c != 0) {
            return true;
        }
    } else if (first + index == self->field_8 - 1 && self->field_2c != 0) {
        return true;
    }
    s32 dir = Unk_14f5fb0_major(*self, *pos);
    s32 line = startLine(self);
    if (dir < 0 && line == 0 && self->field_10 == 0) {
        return true;
    }
    return Unk_14f5c70(self, pos);
}

// NON_MATCHING: same `cmn` vs `neg; cmp` as Unk_14f5ff0, the original keeps
// field_8 and field_8 - 1 in callee-saved registers across the call (GVN PRE), and
// register allocation differs.
// 0x71014f60c0
s32 Unk_14f60c0(const Unk_14f5fb0* self, const Unk_14f5fb0_Pair* pos) {
    s32 scroll = self->field_10;
    s32 index = self->field_14;
    s32 lineSize = Unk_14f5fb0_lineSize(*self);
    Unk_14f5fb0_Pair start = Unk_14f5fb0_position(*self, index);
    s32 offset = Unk_14f5fb0_minor(*self, start);
    s32 first = lineSize * scroll;
    s32 step = Unk_14f5fb0_minor(*self, *pos);
    if (step <= 0) {
        if (step != 0 && step + offset < 0 && first == -index && self->field_2c != 0) {
            return 5;
        }
    } else if (first + index == self->field_8 - 1 && self->field_2c != 0) {
        return 6;
    }
    s32 count = self->field_8;
    s32 dir = Unk_14f5fb0_major(*self, *pos);
    s32 line = startLine(self);
    if (dir < 0 && line == 0 && scroll == 0) {
        s32 item = first + index + Unk_14f5fb0_index(*self, *pos);
        s32 total = lineSize *
                    static_cast<s32>(ceilf(static_cast<f32>(count) / static_cast<f32>(lineSize)));
        bool inLast;
        if (item < 0) {
            inLast = total + item >= count;
        } else {
            inLast = item >= count && item < total;
        }
        return inLast ? 2 : 1;
    }
    if (!Unk_14f5c70(self, pos)) {
        return 0;
    }
    line = startLine(self);
    s32 last = Unk_14f5e30(self);
    if (dir > 0 && line == last - 1) {
        s32 item = first + index + Unk_14f5fb0_index(*self, *pos);
        if (scroll == self->field_c && item >= count) {
            return 4;
        }
    }
    return 3;
}

// 0x71014f6320
s32 Unk_14f6320(const Unk_14f5fb0* self, const Unk_14f5fb0_Pair* pos) {
    return Unk_14f5fb0_index(*self, *pos);
}

// NON_MATCHING: the original loads field_20/field_24 in two branches before a single
// sdiv; this selects the address and loads once.
// 0x71014f6350
s32 Unk_14f6350(const Unk_14f5fb0* self, s32 index) {
    s32 line = index / Unk_14f5fb0_lineSize(*self) - self->field_18;
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
