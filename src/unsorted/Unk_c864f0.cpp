// Scope: common
#include "unsorted/Unk_5e6560.h"

struct Unk_c864f0 {
    u8 _0[0x8];
    Unk_5e6560_Value field_8;
};
PKMN_OFFSET_ASSERT(Unk_c864f0, field_8, 0x8);

// 0x7100c864f0 - same shape as 0x71005e65b0.
Unk_5e6560_Value Unk_c864f0_getField8(const Unk_c864f0* self) {
    return self->field_8;
}
