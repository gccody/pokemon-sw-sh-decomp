// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_4534d0 {
    u8 _0[0x218];
    u64 field_218;
    u32 field_220;
};
PKMN_OFFSET_ASSERT(Unk_4534d0, field_218, 0x218);
PKMN_OFFSET_ASSERT(Unk_4534d0, field_220, 0x220);

// 0x71004534d0
u32 Unk_4534d0_update(Unk_4534d0* self, u32 value, u64 arg2) {
    self->field_220 = value;
    self->field_218 = arg2;
    return 0;
}

struct Unk_4534e0 {
    u8 _0[0x210];
    u32 field_210;
};
PKMN_OFFSET_ASSERT(Unk_4534e0, field_210, 0x210);

// 0x71004534e0
u32 Unk_4534e0_update(Unk_4534e0* self, u32 value) {
    self->field_210 = value;
    return 0;
}

struct Unk_4554f0 {
    u8 _0[0x190];
    f32 field_190;
    f32 field_194;
    f32 field_198;
};
PKMN_OFFSET_ASSERT(Unk_4554f0, field_190, 0x190);
PKMN_OFFSET_ASSERT(Unk_4554f0, field_194, 0x194);
PKMN_OFFSET_ASSERT(Unk_4554f0, field_198, 0x198);

// 0x71004554f0
u32 Unk_4554f0_update(Unk_4554f0* self, f32 fvalue, f32 farg1, f32 farg2) {
    self->field_190 = fvalue;
    self->field_194 = farg1;
    self->field_198 = farg2;
    return 0;
}

struct Unk_455510 {
    u8 _0[0x1b0];
    f32 field_1b0;
    f32 field_1b4;
    u8 _1b8[0x10];
    f32 field_1c8;
};
PKMN_OFFSET_ASSERT(Unk_455510, field_1b0, 0x1b0);
PKMN_OFFSET_ASSERT(Unk_455510, field_1b4, 0x1b4);
PKMN_OFFSET_ASSERT(Unk_455510, field_1c8, 0x1c8);

// 0x7100455510
u32 Unk_455510_update(Unk_455510* self, f32 fvalue, f32 farg1, f32 farg2) {
    self->field_1b0 = fvalue;
    self->field_1c8 = farg1;
    self->field_1b4 = farg2;
    return 0;
}

struct Unk_45e920 {
    u8 _0[0x360];
    u64 field_360;
};
PKMN_OFFSET_ASSERT(Unk_45e920, field_360, 0x360);

// 0x710045e920
u32 Unk_45e920_update(Unk_45e920* self, u64 value) {
    self->field_360 = value;
    return 0;
}

struct Unk_45e930 {
    u8 _0[0x368];
    bool field_368;
};
PKMN_OFFSET_ASSERT(Unk_45e930, field_368, 0x368);

// 0x710045e930
u32 Unk_45e930_update(Unk_45e930* self, bool value) {
    self->field_368 = value;
    return 0;
}
