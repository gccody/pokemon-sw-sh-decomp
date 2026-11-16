// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_7fc7f0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7fc7f0, field_0, 0x0);

// 0x71007fc7f0
u8 Unk_7fc7f0_getField0(const Unk_7fc7f0* self) {
    return self->field_0;
}

struct Unk_7fc850 {
    u8 _0[0x1];
    u8 field_1;
};
PKMN_OFFSET_ASSERT(Unk_7fc850, field_1, 0x1);

// 0x71007fc850
u8 Unk_7fc850_getField1(const Unk_7fc850* self) {
    return self->field_1;
}

struct Unk_7fc860 {
    u8 _0[0x2];
    u8 field_2;
};
PKMN_OFFSET_ASSERT(Unk_7fc860, field_2, 0x2);

// 0x71007fc860
u8 Unk_7fc860_getField2(const Unk_7fc860* self) {
    return self->field_2;
}

struct Unk_7fc8f0 {
    u8 _0[0x4];
    u8 field_4;
};
PKMN_OFFSET_ASSERT(Unk_7fc8f0, field_4, 0x4);

// 0x71007fc8f0
u8 Unk_7fc8f0_getField4(const Unk_7fc8f0* self) {
    return self->field_4;
}
