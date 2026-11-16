// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_14a92b0 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_14a92b0, field_78, 0x78);

// 0x71014a92b0
u32 Unk_14a92b0_getField78(const Unk_14a92b0* self) {
    return self->field_78;
}

struct Unk_14a92c0 {
    u8 _0[0xb0];
    u32 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_14a92c0, field_b0, 0xb0);

// 0x71014a92c0
u32 Unk_14a92c0_getFieldb0(const Unk_14a92c0* self) {
    return self->field_b0;
}

struct Unk_14ac420 {
    u8 _0[0x2fc];
    u8 field_2fc;
};
PKMN_OFFSET_ASSERT(Unk_14ac420, field_2fc, 0x2fc);

// 0x71014ac420
u8 Unk_14ac420_getField2fc(const Unk_14ac420* self) {
    return self->field_2fc;
}
