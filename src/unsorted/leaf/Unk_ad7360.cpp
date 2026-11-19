// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_ad7360_0 {
    u8 _0[0x600];
    u32 field_600;
};
PKMN_OFFSET_ASSERT(Unk_ad7360_0, field_600, 0x600);

struct Unk_ad7360 {
    Unk_ad7360_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad7360, field_0, 0x0);

// 0x7100ad7360
void Unk_ad7360_set(const Unk_ad7360* self) {
    self->field_0->field_600 = 1;
}

// 0x7100ad7370
void Unk_ad7370_update() {}

struct Unk_ad7380_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad7380_arg1, field_0, 0x0);

struct Unk_ad7380 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad7380, field_0, 0x0);

// 0x7100ad7380
void Unk_ad7380_set(const Unk_ad7380* self, Unk_ad7380_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ad7390_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad7390_arg1, field_0, 0x0);

struct Unk_ad7390 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad7390, field_0, 0x0);

// 0x7100ad7390
void Unk_ad7390_set(const Unk_ad7390* self, Unk_ad7390_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ad9730_0 {
    u8 _0[0x600];
    u32 field_600;
};
PKMN_OFFSET_ASSERT(Unk_ad9730_0, field_600, 0x600);

struct Unk_ad9730 {
    Unk_ad9730_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad9730, field_0, 0x0);

// 0x7100ad9730
void Unk_ad9730_set(const Unk_ad9730* self) {
    self->field_0->field_600 = 1;
}

// 0x7100ad9740
void Unk_ad9740_update() {}

struct Unk_ad9750_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad9750_arg1, field_0, 0x0);

struct Unk_ad9750 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad9750, field_0, 0x0);

// 0x7100ad9750
void Unk_ad9750_set(const Unk_ad9750* self, Unk_ad9750_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ad9760_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad9760_arg1, field_0, 0x0);

struct Unk_ad9760 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ad9760, field_0, 0x0);

// 0x7100ad9760
void Unk_ad9760_set(const Unk_ad9760* self, Unk_ad9760_arg1* value) {
    value->field_0 = self->field_0;
}

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

struct Unk_14d9c20;
struct Unk_ada4f0_arg1 {
    u8 _0[0x4];
    u32 field_4;
    u32 field_8;
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_ada4f0_arg1, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_ada4f0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_ada4f0_arg1, field_c, 0xc);

struct Unk_ada4f0 {
    u8 _0[0x848];
    Unk_14d9c20* field_848;
    u8 field_850;
};
PKMN_OFFSET_ASSERT(Unk_ada4f0, field_848, 0x848);
PKMN_OFFSET_ASSERT(Unk_ada4f0, field_850, 0x850);

void Unk_14d9c20_set(Unk_14d9c20*, u32, u32, u32, u32);

// 0x7100ada4f0
void Unk_ada4f0_call(Unk_ada4f0* self, const Unk_ada4f0_arg1* value) {
    self->field_850 = 1;
    Unk_14d9c20_set(self->field_848, value->field_4, value->field_8, value->field_c, 0x1e);
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

// 0x7100adc9e0
void Unk_adc9e0_update() {}

struct Unk_adc9f0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_adc9f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_adc9f0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_adc9f0, field_10, 0x10);

// 0x7100adc9f0
void Unk_adc9f0_set(const Unk_adc9f0* self, Unk_adc9f0* value) {
    *value = *self;
}

struct Unk_adca10 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_adca10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_adca10, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_adca10, field_10, 0x10);

// 0x7100adca10
void Unk_adca10_set(const Unk_adca10* self, Unk_adca10* value) {
    *value = *self;
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

// 0x7100adee70
void Unk_adee70_update() {}

struct Unk_adee80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_adee80_arg1, field_0, 0x0);

struct Unk_adee80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_adee80, field_0, 0x0);

// 0x7100adee80
void Unk_adee80_set(const Unk_adee80* self, Unk_adee80_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_adee90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_adee90_arg1, field_0, 0x0);

struct Unk_adee90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_adee90, field_0, 0x0);

// 0x7100adee90
void Unk_adee90_set(const Unk_adee90* self, Unk_adee90_arg1* value) {
    value->field_0 = self->field_0;
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

// 0x7100ae0c40
void Unk_ae0c40_update() {}

struct Unk_ae0c50 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_ae0c50, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ae0c50, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_ae0c50, field_10, 0x10);

// 0x7100ae0c50
void Unk_ae0c50_set(const Unk_ae0c50* self, Unk_ae0c50* value) {
    *value = *self;
}

struct Unk_ae0c70 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_ae0c70, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ae0c70, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_ae0c70, field_10, 0x10);

// 0x7100ae0c70
void Unk_ae0c70_set(const Unk_ae0c70* self, Unk_ae0c70* value) {
    *value = *self;
}

// 0x7100ae0ca0
void Unk_ae0ca0_update() {}

struct Unk_ae0cb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ae0cb0_arg1, field_0, 0x0);

struct Unk_ae0cb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ae0cb0, field_0, 0x0);

// 0x7100ae0cb0
void Unk_ae0cb0_set(const Unk_ae0cb0* self, Unk_ae0cb0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ae0cc0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ae0cc0_arg1, field_0, 0x0);

struct Unk_ae0cc0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ae0cc0, field_0, 0x0);

// 0x7100ae0cc0
void Unk_ae0cc0_set(const Unk_ae0cc0* self, Unk_ae0cc0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100ae0ce0
void Unk_ae0ce0_update() {}

struct Unk_ae0cf0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ae0cf0_arg1, field_0, 0x0);

struct Unk_ae0cf0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ae0cf0, field_0, 0x0);

// 0x7100ae0cf0
void Unk_ae0cf0_set(const Unk_ae0cf0* self, Unk_ae0cf0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ae0d00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ae0d00_arg1, field_0, 0x0);

struct Unk_ae0d00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ae0d00, field_0, 0x0);

// 0x7100ae0d00
void Unk_ae0d00_set(const Unk_ae0d00* self, Unk_ae0d00_arg1* value) {
    value->field_0 = self->field_0;
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

struct Unk_ae90e0_0 {
    u8 _0[0x600];
    u32 field_600;
};
PKMN_OFFSET_ASSERT(Unk_ae90e0_0, field_600, 0x600);

struct Unk_ae90e0 {
    Unk_ae90e0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_ae90e0, field_0, 0x0);

// 0x7100ae90e0
void Unk_ae90e0_set(const Unk_ae90e0* self) {
    self->field_0->field_600 = 1;
}

// 0x7100ae90f0
void Unk_ae90f0_update() {}

struct Unk_ae9100_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ae9100_arg1, field_0, 0x0);

struct Unk_ae9100 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ae9100, field_0, 0x0);

// 0x7100ae9100
void Unk_ae9100_set(const Unk_ae9100* self, Unk_ae9100_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ae9110_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ae9110_arg1, field_0, 0x0);

struct Unk_ae9110 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ae9110, field_0, 0x0);

// 0x7100ae9110
void Unk_ae9110_set(const Unk_ae9110* self, Unk_ae9110_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100aeb0b0
void Unk_aeb0b0_update() {}

struct Unk_aeb0c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_aeb0c0_arg1, field_0, 0x0);

struct Unk_aeb0c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_aeb0c0, field_0, 0x0);

// 0x7100aeb0c0
void Unk_aeb0c0_set(const Unk_aeb0c0* self, Unk_aeb0c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_aeb0d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_aeb0d0_arg1, field_0, 0x0);

struct Unk_aeb0d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_aeb0d0, field_0, 0x0);

// 0x7100aeb0d0
void Unk_aeb0d0_set(const Unk_aeb0d0* self, Unk_aeb0d0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100aed2a0
void Unk_aed2a0_update() {}

struct Unk_aed2b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_aed2b0_arg1, field_0, 0x0);

struct Unk_aed2b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_aed2b0, field_0, 0x0);

// 0x7100aed2b0
void Unk_aed2b0_set(const Unk_aed2b0* self, Unk_aed2b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_aed2c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_aed2c0_arg1, field_0, 0x0);

struct Unk_aed2c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_aed2c0, field_0, 0x0);

// 0x7100aed2c0
void Unk_aed2c0_set(const Unk_aed2c0* self, Unk_aed2c0_arg1* value) {
    value->field_0 = self->field_0;
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

struct Unk_af00f0_0 {
    u8 _0[0x600];
    u32 field_600;
};
PKMN_OFFSET_ASSERT(Unk_af00f0_0, field_600, 0x600);

struct Unk_af00f0 {
    Unk_af00f0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_af00f0, field_0, 0x0);

// 0x7100af00f0
void Unk_af00f0_set(const Unk_af00f0* self) {
    self->field_0->field_600 = 1;
}

// 0x7100af0100
void Unk_af0100_update() {}

struct Unk_af0110_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_af0110_arg1, field_0, 0x0);

struct Unk_af0110 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_af0110, field_0, 0x0);

// 0x7100af0110
void Unk_af0110_set(const Unk_af0110* self, Unk_af0110_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_af0120_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_af0120_arg1, field_0, 0x0);

struct Unk_af0120 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_af0120, field_0, 0x0);

// 0x7100af0120
void Unk_af0120_set(const Unk_af0120* self, Unk_af0120_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_af0130_0 {
    u8 _0[0x4c0];
    u64 field_4c0;
    u8 _4c8[0x138];
    u32 field_600;
};
PKMN_OFFSET_ASSERT(Unk_af0130_0, field_4c0, 0x4c0);
PKMN_OFFSET_ASSERT(Unk_af0130_0, field_600, 0x600);

struct Unk_af0130 {
    Unk_af0130_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_af0130, field_0, 0x0);

void Unk_1500c40(u64);

// 0x7100af0130
void Unk_af0130_call(const Unk_af0130* self) {
    Unk_af0130_0* p0 = self->field_0;
    p0->field_600 = 3;
    if (p0->field_4c0 != 0) {
        Unk_1500c40(p0->field_4c0);
    }
}

// 0x7100af0150
void Unk_af0150_update() {}

struct Unk_af0160_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_af0160_arg1, field_0, 0x0);

struct Unk_af0160 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_af0160, field_0, 0x0);

// 0x7100af0160
void Unk_af0160_set(const Unk_af0160* self, Unk_af0160_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_af0170_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_af0170_arg1, field_0, 0x0);

struct Unk_af0170 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_af0170, field_0, 0x0);

// 0x7100af0170
void Unk_af0170_set(const Unk_af0170* self, Unk_af0170_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100af1e00
void Unk_af1e00_update() {}

struct Unk_af1e10_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_af1e10_arg1, field_0, 0x0);

struct Unk_af1e10 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_af1e10, field_0, 0x0);

// 0x7100af1e10
void Unk_af1e10_set(const Unk_af1e10* self, Unk_af1e10_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_af1e20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_af1e20_arg1, field_0, 0x0);

struct Unk_af1e20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_af1e20, field_0, 0x0);

// 0x7100af1e20
void Unk_af1e20_set(const Unk_af1e20* self, Unk_af1e20_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_af3350 {
    u8 _0[0x600];
    u32 field_600;
    u8 _604[0x4];
    u32 field_608;
};
PKMN_OFFSET_ASSERT(Unk_af3350, field_600, 0x600);
PKMN_OFFSET_ASSERT(Unk_af3350, field_608, 0x608);

// 0x7100af3350
void Unk_af3350_set(Unk_af3350* self, u32 value) {
    self->field_608 = value;
    self->field_600 = 1;
}

struct Unk_af4ad0 {
    u8 _0[0x8a8];
    u32 field_8a8;
};
PKMN_OFFSET_ASSERT(Unk_af4ad0, field_8a8, 0x8a8);

// 0x7100af4ad0
void Unk_af4ad0_set(Unk_af4ad0* self, u32 /*unused*/, u32 /*unused*/, u32 arg3) {
    self->field_8a8 = arg3;
}

// 0x7100af5970
void Unk_af5970_update() {}

struct Unk_af5980 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_af5980, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_af5980, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_af5980, field_10, 0x10);

// 0x7100af5980
void Unk_af5980_set(const Unk_af5980* self, Unk_af5980* value) {
    *value = *self;
}

struct Unk_af59a0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_af59a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_af59a0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_af59a0, field_10, 0x10);

// 0x7100af59a0
void Unk_af59a0_set(const Unk_af59a0* self, Unk_af59a0* value) {
    *value = *self;
}

// 0x7100af5c10
void Unk_af5c10_update() {}

struct Unk_af5c20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_af5c20_arg1, field_0, 0x0);

struct Unk_af5c20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_af5c20, field_0, 0x0);

// 0x7100af5c20
void Unk_af5c20_set(const Unk_af5c20* self, Unk_af5c20_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_af5c30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_af5c30_arg1, field_0, 0x0);

struct Unk_af5c30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_af5c30, field_0, 0x0);

// 0x7100af5c30
void Unk_af5c30_set(const Unk_af5c30* self, Unk_af5c30_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_afa820 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_afa820, field_8, 0x8);

// 0x7100afa820
void Unk_afa820_call(Unk_afa820* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_afa860_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_afa860_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afa860_arg1, field_8, 0x8);

struct Unk_afa860 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_afa860, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afa860, field_8, 0x8);

// 0x7100afa860
void Unk_afa860_call(const Unk_afa860* self, Unk_afa860_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_afa890_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_afa890_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afa890_arg1, field_8, 0x8);

struct Unk_afa890 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_afa890, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afa890, field_8, 0x8);

// 0x7100afa890
void Unk_afa890_call(const Unk_afa890* self, Unk_afa890_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_afa8f0 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_afa8f0, field_8, 0x8);

// 0x7100afa8f0
void Unk_afa8f0_call(Unk_afa8f0* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_afa930_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_afa930_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afa930_arg1, field_8, 0x8);

struct Unk_afa930 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_afa930, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afa930, field_8, 0x8);

// 0x7100afa930
void Unk_afa930_call(const Unk_afa930* self, Unk_afa930_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_afa960_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_afa960_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afa960_arg1, field_8, 0x8);

struct Unk_afa960 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_afa960, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afa960, field_8, 0x8);

// 0x7100afa960
void Unk_afa960_call(const Unk_afa960* self, Unk_afa960_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_afa9c0 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_afa9c0, field_8, 0x8);

// 0x7100afa9c0
void Unk_afa9c0_call(Unk_afa9c0* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_afaa00_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_afaa00_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afaa00_arg1, field_8, 0x8);

struct Unk_afaa00 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_afaa00, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afaa00, field_8, 0x8);

// 0x7100afaa00
void Unk_afaa00_call(const Unk_afaa00* self, Unk_afaa00_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_afaa30_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_afaa30_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afaa30_arg1, field_8, 0x8);

struct Unk_afaa30 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_afaa30, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afaa30, field_8, 0x8);

// 0x7100afaa30
void Unk_afaa30_call(const Unk_afaa30* self, Unk_afaa30_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_afaa90 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_afaa90, field_8, 0x8);

// 0x7100afaa90
void Unk_afaa90_call(Unk_afaa90* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_afaad0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_afaad0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afaad0_arg1, field_8, 0x8);

struct Unk_afaad0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_afaad0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afaad0, field_8, 0x8);

// 0x7100afaad0
void Unk_afaad0_call(const Unk_afaad0* self, Unk_afaad0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_afab00_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_afab00_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afab00_arg1, field_8, 0x8);

struct Unk_afab00 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_afab00, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afab00, field_8, 0x8);

// 0x7100afab00
void Unk_afab00_call(const Unk_afab00* self, Unk_afab00_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_afae50 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afae50, field_10, 0x10);

// 0x7100afae50
void Unk_afae50_call(Unk_afae50* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_afae90_head {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_afae90_head, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afae90_head, field_8, 0x8);

struct Unk_afae90_arg1 {
    Unk_afae90_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afae90_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afae90_arg1, field_10, 0x10);

struct Unk_afae90 {
    Unk_afae90_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afae90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afae90, field_10, 0x10);

// 0x7100afae90
void Unk_afae90_call(const Unk_afae90* self, Unk_afae90_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_10;
    value->field_10 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_afaec0_head {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_afaec0_head, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afaec0_head, field_8, 0x8);

struct Unk_afaec0_arg1 {
    Unk_afaec0_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afaec0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afaec0_arg1, field_10, 0x10);

struct Unk_afaec0 {
    Unk_afaec0_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afaec0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afaec0, field_10, 0x10);

// 0x7100afaec0
void Unk_afaec0_call(const Unk_afaec0* self, Unk_afaec0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_10;
    value->field_10 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_afaf20 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afaf20, field_10, 0x10);

// 0x7100afaf20
void Unk_afaf20_call(Unk_afaf20* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_afaf60_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afaf60_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afaf60_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_afaf60_arg1, field_10, 0x10);

struct Unk_afaf60 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afaf60, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afaf60, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_afaf60, field_10, 0x10);

// 0x7100afaf60
void Unk_afaf60_call(const Unk_afaf60* self, Unk_afaf60_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_afaf90_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afaf90_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afaf90_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_afaf90_arg1, field_10, 0x10);

struct Unk_afaf90 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afaf90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afaf90, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_afaf90, field_10, 0x10);

// 0x7100afaf90
void Unk_afaf90_call(const Unk_afaf90* self, Unk_afaf90_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_afafe0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_afafe0, field_0, 0x0);

// 0x7100afafe0
void Unk_afafe0_call(Unk_afafe0* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_afb020_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_afb020_arg1, field_0, 0x0);

struct Unk_afb020 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_afb020, field_0, 0x0);

// 0x7100afb020
void Unk_afb020_call(const Unk_afb020* self, Unk_afb020_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_afb040_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_afb040_arg1, field_0, 0x0);

struct Unk_afb040 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_afb040, field_0, 0x0);

// 0x7100afb040
void Unk_afb040_call(const Unk_afb040* self, Unk_afb040_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_afb090 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afb090, field_10, 0x10);

// 0x7100afb090
void Unk_afb090_call(Unk_afb090* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_afb0d0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afb0d0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afb0d0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_afb0d0_arg1, field_10, 0x10);

struct Unk_afb0d0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afb0d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afb0d0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_afb0d0, field_10, 0x10);

// 0x7100afb0d0
void Unk_afb0d0_call(const Unk_afb0d0* self, Unk_afb0d0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_afb100_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afb100_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afb100_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_afb100_arg1, field_10, 0x10);

struct Unk_afb100 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afb100, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afb100, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_afb100, field_10, 0x10);

// 0x7100afb100
void Unk_afb100_call(const Unk_afb100* self, Unk_afb100_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_afb160 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afb160, field_10, 0x10);

// 0x7100afb160
void Unk_afb160_call(Unk_afb160* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_afb1a0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afb1a0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afb1a0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_afb1a0_arg1, field_10, 0x10);

struct Unk_afb1a0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afb1a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afb1a0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_afb1a0, field_10, 0x10);

// 0x7100afb1a0
void Unk_afb1a0_call(const Unk_afb1a0* self, Unk_afb1a0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_afb1d0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afb1d0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afb1d0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_afb1d0_arg1, field_10, 0x10);

struct Unk_afb1d0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afb1d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afb1d0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_afb1d0, field_10, 0x10);

// 0x7100afb1d0
void Unk_afb1d0_call(const Unk_afb1d0* self, Unk_afb1d0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_afb230 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afb230, field_10, 0x10);

// 0x7100afb230
void Unk_afb230_call(Unk_afb230* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_afb270_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afb270_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afb270_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_afb270_arg1, field_10, 0x10);

struct Unk_afb270 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afb270, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afb270, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_afb270, field_10, 0x10);

// 0x7100afb270
void Unk_afb270_call(const Unk_afb270* self, Unk_afb270_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_afb2a0_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afb2a0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afb2a0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_afb2a0_arg1, field_10, 0x10);

struct Unk_afb2a0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afb2a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afb2a0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_afb2a0, field_10, 0x10);

// 0x7100afb2a0
void Unk_afb2a0_call(const Unk_afb2a0* self, Unk_afb2a0_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_afb320 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afb320, field_10, 0x10);

// 0x7100afb320
void Unk_afb320_call(Unk_afb320* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_afb360_head {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_afb360_head, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afb360_head, field_8, 0x8);

struct Unk_afb360_arg1 {
    Unk_afb360_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afb360_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afb360_arg1, field_10, 0x10);

struct Unk_afb360 {
    Unk_afb360_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afb360, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afb360, field_10, 0x10);

// 0x7100afb360
void Unk_afb360_call(const Unk_afb360* self, Unk_afb360_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_10;
    value->field_10 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_afb390_head {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_afb390_head, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afb390_head, field_8, 0x8);

struct Unk_afb390_arg1 {
    Unk_afb390_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afb390_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afb390_arg1, field_10, 0x10);

struct Unk_afb390 {
    Unk_afb390_head field_0;
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afb390, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afb390, field_10, 0x10);

// 0x7100afb390
void Unk_afb390_call(const Unk_afb390* self, Unk_afb390_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_10;
    value->field_10 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_afb3f0 {
    u8 _0[0x10];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afb3f0, field_10, 0x10);

// 0x7100afb3f0
void Unk_afb3f0_call(Unk_afb3f0* self) {
    if (self->field_10 != nullptr) {
        static_cast<Unk_239a458*>(self->field_10)->vf5();
        self->field_10 = nullptr;
    }
}

struct Unk_afb430_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afb430_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afb430_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_afb430_arg1, field_10, 0x10);

struct Unk_afb430 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afb430, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afb430, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_afb430, field_10, 0x10);

// 0x7100afb430
void Unk_afb430_call(const Unk_afb430* self, Unk_afb430_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}

struct Unk_afb460_arg1 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afb460_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afb460_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_afb460_arg1, field_10, 0x10);

struct Unk_afb460 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    Unk_239a418* field_10;
};
PKMN_OFFSET_ASSERT(Unk_afb460, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_afb460, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_afb460, field_10, 0x10);

// 0x7100afb460
void Unk_afb460_call(const Unk_afb460* self, Unk_afb460_arg1* value) {
    u64 v0 = self->field_0;
    value->field_8 = self->field_8;
    value->field_0 = v0;
    Unk_239a418* v1 = self->field_10;
    value->field_10 = v1;
    if (v1 != nullptr) {
        static_cast<Unk_239a458*>(v1)->vf4();
    }
}
