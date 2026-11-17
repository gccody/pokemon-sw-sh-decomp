// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1074c90 {
    u32 field_0;
    u16 field_4;
    u8 _6[0x2];
    u32 field_8;
    u16 field_c;
    u8 _e[0x2];
    u64 field_10;
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1074c90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1074c90, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_1074c90, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1074c90, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_1074c90, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_1074c90, field_18, 0x18);

// 0x7101074c90
void Unk_1074c90_set(Unk_1074c90* self) {
    self->field_0 = 0;
    self->field_4 = 0;
    self->field_8 = 0;
    self->field_c = 0;
    self->field_18 = 0;
    self->field_10 = 0;
}

struct Unk_1074fe0 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1074fe0, field_0, 0x0);

// 0x7101074fe0
bool Unk_1074fe0_check(const Unk_1074fe0* self) {
    return self->field_0 != 0;
}

struct Unk_1074ff0 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1074ff0, field_0, 0x0);

// 0x7101074ff0
u32 Unk_1074ff0_getField0(const Unk_1074ff0* self) {
    return self->field_0;
}

struct Unk_1075000 {
    u8 _0[0x4];
    u16 field_4;
};
PKMN_OFFSET_ASSERT(Unk_1075000, field_4, 0x4);

// 0x7101075000
u16 Unk_1075000_getField4(const Unk_1075000* self) {
    return self->field_4;
}

struct Unk_1075010 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1075010, field_8, 0x8);

// 0x7101075010
u32 Unk_1075010_getField8(const Unk_1075010* self) {
    return self->field_8;
}

struct Unk_1075020 {
    u8 _0[0xc];
    u8 field_c;
};
PKMN_OFFSET_ASSERT(Unk_1075020, field_c, 0xc);

// 0x7101075020
u8 Unk_1075020_getFieldc(const Unk_1075020* self) {
    return self->field_c;
}

struct Unk_1075030 {
    u8 _0[0xd];
    u8 field_d;
};
PKMN_OFFSET_ASSERT(Unk_1075030, field_d, 0xd);

// 0x7101075030
u8 Unk_1075030_getFieldd(const Unk_1075030* self) {
    return self->field_d;
}

struct Unk_1075040 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1075040, field_10, 0x10);

// 0x7101075040
u32 Unk_1075040_getField10(const Unk_1075040* self) {
    return self->field_10;
}

struct Unk_1075050 {
    u8 _0[0x14];
    u32 field_14;
};
PKMN_OFFSET_ASSERT(Unk_1075050, field_14, 0x14);

// 0x7101075050
u32 Unk_1075050_getField14(const Unk_1075050* self) {
    return self->field_14;
}

struct Unk_1075060 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1075060, field_18, 0x18);

// 0x7101075060
u8 Unk_1075060_getField18(const Unk_1075060* self) {
    return self->field_18;
}
