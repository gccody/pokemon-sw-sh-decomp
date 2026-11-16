// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1262fa0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1262fa0, field_10, 0x10);

// 0x7101262fa0
u32 Unk_1262fa0_getField10(const Unk_1262fa0* self) {
    return self->field_10;
}

struct Unk_1263050 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1263050, field_18, 0x18);

// 0x7101263050
void Unk_1263050_setField18(Unk_1263050* self, u64 value) {
    self->field_18 = value;
}

struct Unk_1263060 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_1263060, field_20, 0x20);

// 0x7101263060
void Unk_1263060_setField20(Unk_1263060* self, u64 value) {
    self->field_20 = value;
}

struct Unk_12635f0 {
    u8 _0[0x88];
    u32 field_88;
};
PKMN_OFFSET_ASSERT(Unk_12635f0, field_88, 0x88);

// 0x71012635f0
u32 Unk_12635f0_getField88(const Unk_12635f0* self) {
    return self->field_88;
}

struct Unk_12637d0 {
    u8 _0[0x8c];
    u8 field_8c;
};
PKMN_OFFSET_ASSERT(Unk_12637d0, field_8c, 0x8c);

// 0x71012637d0
u8 Unk_12637d0_getField8c(const Unk_12637d0* self) {
    return self->field_8c;
}

struct Unk_1263990 {
    u8 _0[0x190];
    f32 field_190;
};
PKMN_OFFSET_ASSERT(Unk_1263990, field_190, 0x190);

// 0x7101263990
void Unk_1263990_setField190(Unk_1263990* self, f32 value) {
    self->field_190 = value;
}
