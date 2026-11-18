// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_4afa90 {
    u8 _0[0x3e4];
    f32 field_3e4;
};
PKMN_OFFSET_ASSERT(Unk_4afa90, field_3e4, 0x3e4);

// 0x71004afa90
f32 Unk_4afa90_get(const Unk_4afa90* self) {
    return self->field_3e4;
}

struct Unk_4aff30 {
    u8 _0[0x1c8];
    u32 field_1c8;
    u8 _1cc[0x8];
    f32 field_1d4;
    f32 field_1d8;
};
PKMN_OFFSET_ASSERT(Unk_4aff30, field_1c8, 0x1c8);
PKMN_OFFSET_ASSERT(Unk_4aff30, field_1d4, 0x1d4);
PKMN_OFFSET_ASSERT(Unk_4aff30, field_1d8, 0x1d8);

// 0x71004aff30
u32 Unk_4aff30_update(Unk_4aff30* self, f32 fvalue, f32 farg1) {
    self->field_1c8 = 1;
    self->field_1d4 = fvalue;
    self->field_1d8 = farg1;
    return 0;
}

// 0x71004b72b0
u32 Unk_4b72b0_get() {
    return 1;
}

struct Unk_4b72c0 {
    u8 _0[0x12d];
    u8 field_12d;
};
PKMN_OFFSET_ASSERT(Unk_4b72c0, field_12d, 0x12d);

// 0x71004b72c0
u8 Unk_4b72c0_get(const Unk_4b72c0* self) {
    return self->field_12d;
}
