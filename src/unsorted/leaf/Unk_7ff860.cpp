// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_7ff860 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_7ff860, field_8, 0x8);

// 0x71007ff860
void Unk_7ff860_clearField8(Unk_7ff860* self) {
    self->field_8 = 0;
}

// 0x71007ffa70
void Unk_7ffa70() {}

struct Unk_7ffaa0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7ffaa0, field_0, 0x0);

// 0x71007ffaa0
u8 Unk_7ffaa0_getField0(const Unk_7ffaa0* self) {
    return self->field_0;
}

struct Unk_7ffab0 {
    u8 _0[0xc];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_7ffab0, field_c, 0xc);

// 0x71007ffab0
u32 Unk_7ffab0_getFieldc(const Unk_7ffab0* self) {
    return self->field_c;
}

struct Unk_7ffaf0 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_7ffaf0, field_10, 0x10);

// 0x71007ffaf0
u8 Unk_7ffaf0_getField10(const Unk_7ffaf0* self) {
    return self->field_10;
}

struct Unk_7ffb30 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_7ffb30, field_8, 0x8);

// 0x71007ffb30
u32 Unk_7ffb30_getField8(const Unk_7ffb30* self) {
    return self->field_8;
}

struct Unk_8003c0 {
    u8 _0[0x11];
    u8 field_11;
};
PKMN_OFFSET_ASSERT(Unk_8003c0, field_11, 0x11);

// 0x71008003c0
u8 Unk_8003c0_getField11(const Unk_8003c0* self) {
    return self->field_11;
}

struct Unk_8003d0 {
    u8 _0[0x88];
    u32 field_88;
};
PKMN_OFFSET_ASSERT(Unk_8003d0, field_88, 0x88);

// 0x71008003d0
u32 Unk_8003d0_getField88(const Unk_8003d0* self) {
    return self->field_88;
}
