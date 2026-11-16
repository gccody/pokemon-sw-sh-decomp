// Scope: common
#include "unsorted/Unk_5e6560.h"

struct Unk_601110 {
    u8 _0[0x80];
    Unk_5e6560_Value field_80;
};
PKMN_OFFSET_ASSERT(Unk_601110, field_80, 0x80);

// 0x7100601110 - same shape as 0x71005e65b0.
Unk_5e6560_Value Unk_601110_getField80(const Unk_601110* self) {
    return self->field_80;
}
