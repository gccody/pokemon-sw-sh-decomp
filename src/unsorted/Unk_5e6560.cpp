// Scope: common
#include "unsorted/Unk_5e6560.h"

// 0x71005e6560
void Unk_5e6560_reset(Unk_5e6560* self) {
    if (self->ptr) {
        self->ptr->vf_18();
        self->ptr = nullptr;
    }
}

struct Unk_5e65a0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_5e65a0, field_10, 0x10);

// 0x71005e65a0
u32 Unk_5e65a0_getField10(const Unk_5e65a0* self) {
    return self->field_10;
}

struct Unk_5e65b0 {
    u8 _0[0x18];
    Unk_5e6560_Value field_18;
};
PKMN_OFFSET_ASSERT(Unk_5e65b0, field_18, 0x18);

// 0x71005e65b0 - the last two loads are not paired (see Unk_5e6560_Value).
Unk_5e6560_Value Unk_5e65b0_getField18(const Unk_5e65b0* self) {
    return self->field_18;
}
