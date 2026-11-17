// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_ada4c0_848 {
    u8 _0[0x198];
    u8 field_198;
};
PKMN_OFFSET_ASSERT(Unk_ada4c0_848, field_198, 0x198);

struct Unk_ada4c0 {
    u8 _0[0x848];
    Unk_ada4c0_848* field_848;
};
PKMN_OFFSET_ASSERT(Unk_ada4c0, field_848, 0x848);

// 0x7100ada4c0
u8 Unk_ada4c0_get(const Unk_ada4c0* self) {
    return self->field_848->field_198;
}

struct Unk_ada4d0_arg1 {
    u8 _0[0x14];
    u32 field_14;
    u32 field_18;
    u32 field_1c;
};
PKMN_OFFSET_ASSERT(Unk_ada4d0_arg1, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_ada4d0_arg1, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_ada4d0_arg1, field_1c, 0x1c);

struct Unk_ada4d0 {
    u8 _0[0x848];
    u64 field_848;
};
PKMN_OFFSET_ASSERT(Unk_ada4d0, field_848, 0x848);

void Unk_14d9790(u64, u32, u32, u32, u32);

// 0x7100ada4d0
void Unk_ada4d0_call(const Unk_ada4d0* self, const Unk_ada4d0_arg1* value) {
    Unk_14d9790(self->field_848, value->field_14, value->field_18, value->field_1c, 1);
}

struct Unk_adb110_arg1 {
    u8 _0[0x4];
    u32 field_4;
    u32 field_8;
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_adb110_arg1, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_adb110_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_adb110_arg1, field_c, 0xc);

struct Unk_adb110 {
    u8 _0[0x848];
    u64 field_848;
};
PKMN_OFFSET_ASSERT(Unk_adb110, field_848, 0x848);

void Unk_14d9790(u64, u32, u32, u32, u32);

// 0x7100adb110
void Unk_adb110_call(const Unk_adb110* self, const Unk_adb110_arg1* value) {
    Unk_14d9790(self->field_848, value->field_4, value->field_8, value->field_c, 1);
}

struct Unk_adcdd0 {
    u8 _0[0x5e0];
    u8 field_5e0;
};
PKMN_OFFSET_ASSERT(Unk_adcdd0, field_5e0, 0x5e0);

// 0x7100adcdd0
void Unk_adcdd0_clearField5e0(Unk_adcdd0* self) {
    self->field_5e0 = 0;
}

struct Unk_adf480_878 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_adf480_878, field_58, 0x58);

struct Unk_adf480 {
    u8 _0[0x878];
    Unk_adf480_878* field_878;
};
PKMN_OFFSET_ASSERT(Unk_adf480, field_878, 0x878);

// 0x7100adf480
void Unk_adf480_set(const Unk_adf480* self, bool value) {
    self->field_878->field_58 = (self->field_878->field_58 & 0xfffffffe) | (value);
}

struct Unk_ae1070 {
    u8 _0[0xb40];
    u32 field_b40;
    u8 field_b44;
};
PKMN_OFFSET_ASSERT(Unk_ae1070, field_b40, 0xb40);
PKMN_OFFSET_ASSERT(Unk_ae1070, field_b44, 0xb44);

// 0x7100ae1070
void Unk_ae1070_set(Unk_ae1070* self) {
    self->field_b40 = 0x3e7;
    self->field_b44 = 0;
}

struct Unk_ae1600 {
    u8 _0[0x6f8];
    u32 field_6f8;
};
PKMN_OFFSET_ASSERT(Unk_ae1600, field_6f8, 0x6f8);

// 0x7100ae1600
bool Unk_ae1600_check(const Unk_ae1600* self) {
    return self->field_6f8 == 4;
}

struct Unk_ae1800 {
    u8 _0[0xb40];
    u64 field_b40;
};
PKMN_OFFSET_ASSERT(Unk_ae1800, field_b40, 0xb40);

// 0x7100ae1800
u64 Unk_ae1800_getFieldb40(const Unk_ae1800* self) {
    return self->field_b40;
}

struct Unk_aee0e0_850 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_aee0e0_850, field_58, 0x58);

struct Unk_aee0e0 {
    u8 _0[0x850];
    Unk_aee0e0_850* field_850;
};
PKMN_OFFSET_ASSERT(Unk_aee0e0, field_850, 0x850);

// 0x7100aee0e0
void Unk_aee0e0_set(const Unk_aee0e0* self, bool value) {
    self->field_850->field_58 = (self->field_850->field_58 & 0xfffffffe) | (value);
}
