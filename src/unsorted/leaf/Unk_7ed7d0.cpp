// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_7ed7d0_arg1 {
    u32 field_0;
    u8 field_4;
    u8 field_5;
    u8 field_6;
    u8 field_7;
    u8 field_8;
    u8 _9[0x7];
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_7ed7d0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7ed7d0_arg1, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_7ed7d0_arg1, field_5, 0x5);
PKMN_OFFSET_ASSERT(Unk_7ed7d0_arg1, field_6, 0x6);
PKMN_OFFSET_ASSERT(Unk_7ed7d0_arg1, field_7, 0x7);
PKMN_OFFSET_ASSERT(Unk_7ed7d0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_7ed7d0_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_7ed7d0_arg1, field_18, 0x18);

struct Unk_7ed7d0 {
    u32 field_0;
    u8 field_4;
    u8 field_5;
    u8 field_6;
    u8 field_7;
    u8 field_8;
    u8 _9[0x7];
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_7ed7d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7ed7d0, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_7ed7d0, field_5, 0x5);
PKMN_OFFSET_ASSERT(Unk_7ed7d0, field_6, 0x6);
PKMN_OFFSET_ASSERT(Unk_7ed7d0, field_7, 0x7);
PKMN_OFFSET_ASSERT(Unk_7ed7d0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_7ed7d0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_7ed7d0, field_18, 0x18);

// 0x71007ed7d0
void Unk_7ed7d0_set(Unk_7ed7d0* self, const Unk_7ed7d0_arg1* value) {
    self->field_0 = value->field_0;
    self->field_4 = value->field_4;
    self->field_5 = value->field_5;
    self->field_6 = value->field_6;
    self->field_7 = value->field_7;
    self->field_8 = value->field_8;
    self->field_18 = value->field_18;
    self->field_10 = value->field_10;
}

struct Unk_7ee040 {
    u8 _0[0x270];
    u16 field_270;
};
PKMN_OFFSET_ASSERT(Unk_7ee040, field_270, 0x270);

// 0x71007ee040
void Unk_7ee040_set(Unk_7ee040* self) {
    self->field_270 = 0x1f00;
}

struct Unk_7ee6b0 {
    u8 _0[0x7d];
    u8 field_7d;
};
PKMN_OFFSET_ASSERT(Unk_7ee6b0, field_7d, 0x7d);

// 0x71007ee6b0
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self) {
    return self->field_7d;
}

struct Unk_7ee6c0 {
    u8 _0[0x298];
    u8 field_298;
};
PKMN_OFFSET_ASSERT(Unk_7ee6c0, field_298, 0x298);

// 0x71007ee6c0
u8 Unk_7ee6c0_getField298(const Unk_7ee6c0* self) {
    return self->field_298;
}

struct Unk_7ee7e0 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_7ee7e0, field_60, 0x60);

void Unk_768f00(u64);

// 0x71007ee7e0
void Unk_7ee7e0_call(const Unk_7ee7e0* self) {
    Unk_768f00(self->field_60);
}

struct Unk_7ee7f0 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_7ee7f0, field_60, 0x60);

void Unk_768fa0(u64);

// 0x71007ee7f0
void Unk_7ee7f0_call(const Unk_7ee7f0* self) {
    Unk_768fa0(self->field_60);
}

struct Unk_7ee800 {
    u8 _0[0x273];
    u8 field_273;
};
PKMN_OFFSET_ASSERT(Unk_7ee800, field_273, 0x273);

// 0x71007ee800
u8 Unk_7ee800_getField273(const Unk_7ee800* self) {
    return self->field_273;
}

struct Unk_7ee810 {
    u8 _0[0x278];
    u64 field_278;
};
PKMN_OFFSET_ASSERT(Unk_7ee810, field_278, 0x278);

// 0x71007ee810
u64 Unk_7ee810_getField278(const Unk_7ee810* self) {
    return self->field_278;
}

struct Unk_7ef220 {
    u8 _0[0x87];
    u8 field_87;
};
PKMN_OFFSET_ASSERT(Unk_7ef220, field_87, 0x87);

// 0x71007ef220
u32 Unk_7ef220_get(const Unk_7ef220* self) {
    return (self->field_87 >> 5) & 1;
}

struct Unk_7ef230 {
    u8 _0[0x250];
    u8 field_250;
};
PKMN_OFFSET_ASSERT(Unk_7ef230, field_250, 0x250);

// 0x71007ef230
u8* Unk_7ef230_getField250Ptr(Unk_7ef230* self) {
    return &self->field_250;
}

struct Unk_7ef240 {
    u8 _0[0x270];
    u8 field_270;
};
PKMN_OFFSET_ASSERT(Unk_7ef240, field_270, 0x270);

// 0x71007ef240
u8 Unk_7ef240_getField270(const Unk_7ef240* self) {
    return self->field_270;
}

struct Unk_7ef250 {
    u8 _0[0x271];
    u8 field_271;
};
PKMN_OFFSET_ASSERT(Unk_7ef250, field_271, 0x271);

// 0x71007ef250
u8 Unk_7ef250_getField271(const Unk_7ef250* self) {
    return self->field_271;
}

struct Unk_7ef2d0 {
    u8 _0[0x272];
    u8 field_272;
};
PKMN_OFFSET_ASSERT(Unk_7ef2d0, field_272, 0x272);

// 0x71007ef2d0
u8 Unk_7ef2d0_getField272(const Unk_7ef2d0* self) {
    return self->field_272;
}

struct Unk_7ef300 {
    u8 _0[0x342];
    u8 field_342;
};
PKMN_OFFSET_ASSERT(Unk_7ef300, field_342, 0x342);

// 0x71007ef300
u8 Unk_7ef300_getField342(const Unk_7ef300* self) {
    return self->field_342;
}

struct Unk_7ef310 {
    u8 _0[0x342];
    u8 field_342;
};
PKMN_OFFSET_ASSERT(Unk_7ef310, field_342, 0x342);

// 0x71007ef310
void Unk_7ef310_setField342(Unk_7ef310* self, u8 value) {
    self->field_342 = value;
}

struct Unk_7ef320 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_7ef320, field_60, 0x60);

// 0x71007ef320
u64 Unk_7ef320_getField60(const Unk_7ef320* self) {
    return self->field_60;
}

struct Unk_7ef330 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_7ef330, field_60, 0x60);

// 0x71007ef330
u64 Unk_7ef330_getField60(const Unk_7ef330* self) {
    return self->field_60;
}

struct Unk_7ef530 {
    u8 _0[0x2bc];
    u16 field_2bc;
};
PKMN_OFFSET_ASSERT(Unk_7ef530, field_2bc, 0x2bc);

// 0x71007ef530
bool Unk_7ef530_check(const Unk_7ef530* self) {
    return self->field_2bc == 0x1fe;
}

struct Unk_7efe00 {
    u8 _0[0x33c];
    u8 field_33c;
};
PKMN_OFFSET_ASSERT(Unk_7efe00, field_33c, 0x33c);

// 0x71007efe00
u8 Unk_7efe00_getField33c(const Unk_7efe00* self) {
    return self->field_33c;
}

struct Unk_7efee0 {
    u8 _0[0x340];
    u8 field_340;
};
PKMN_OFFSET_ASSERT(Unk_7efee0, field_340, 0x340);

// 0x71007efee0
u8 Unk_7efee0_getField340(const Unk_7efee0* self) {
    return self->field_340;
}

struct Unk_7f09c0 {
    u8 _0[0x76];
    u16 field_76;
};
PKMN_OFFSET_ASSERT(Unk_7f09c0, field_76, 0x76);

// 0x71007f09c0
u16 Unk_7f09c0_getField76(const Unk_7f09c0* self) {
    return self->field_76;
}

struct Unk_7f09d0 {
    u8 _0[0x76];
    u16 field_76;
};
PKMN_OFFSET_ASSERT(Unk_7f09d0, field_76, 0x76);

// 0x71007f09d0
void Unk_7f09d0_setField76(Unk_7f09d0* self, u16 value) {
    self->field_76 = value;
}

struct Unk_7f0a70 {
    u8 _0[0x244];
    u16 field_244;
};
PKMN_OFFSET_ASSERT(Unk_7f0a70, field_244, 0x244);

// 0x71007f0a70
u16 Unk_7f0a70_getField244(const Unk_7f0a70* self) {
    return self->field_244;
}

struct Unk_7f0a80 {
    u8 _0[0x244];
    u16 field_244;
};
PKMN_OFFSET_ASSERT(Unk_7f0a80, field_244, 0x244);

// 0x71007f0a80
void Unk_7f0a80_set(Unk_7f0a80* self) {
    self->field_244 = self->field_244 + 1;
}

struct Unk_7f0a90 {
    u8 _0[0x344];
    u16 field_344;
};
PKMN_OFFSET_ASSERT(Unk_7f0a90, field_344, 0x344);

// 0x71007f0a90
u16 Unk_7f0a90_getField344(const Unk_7f0a90* self) {
    return self->field_344;
}

struct Unk_7f0b70 {
    u8 _0[0x35c];
    u8 field_35c;
};
PKMN_OFFSET_ASSERT(Unk_7f0b70, field_35c, 0x35c);

// 0x71007f0b70
bool Unk_7f0b70_check(const Unk_7f0b70* self) {
    return (self->field_35c & 0x78) != 0;
}

struct Unk_7f0b80 {
    u8 _0[0x365];
    u8 field_365;
};
PKMN_OFFSET_ASSERT(Unk_7f0b80, field_365, 0x365);

// 0x71007f0b80
u32 Unk_7f0b80_get(const Unk_7f0b80* self) {
    return (self->field_365 != 0) & (self->field_365 >= 1 && self->field_365 <= 0x1e);
}

struct Unk_7f11b0 {
    u8 _0[0x2b4];
    u32 field_2b4;
    u16 field_2b8;
    u8 field_2ba;
};
PKMN_OFFSET_ASSERT(Unk_7f11b0, field_2b4, 0x2b4);
PKMN_OFFSET_ASSERT(Unk_7f11b0, field_2b8, 0x2b8);
PKMN_OFFSET_ASSERT(Unk_7f11b0, field_2ba, 0x2ba);

// 0x71007f11b0
void Unk_7f11b0_set(Unk_7f11b0* self) {
    self->field_2ba = 6;
    self->field_2b8 = 0x606;
    self->field_2b4 = 0x6060606;
}

struct Unk_7f1310 {
    u8 _0[0x33f];
    u8 field_33f;
};
PKMN_OFFSET_ASSERT(Unk_7f1310, field_33f, 0x33f);

// 0x71007f1310
u8 Unk_7f1310_getField33f(const Unk_7f1310* self) {
    return self->field_33f;
}

struct Unk_7f13d0 {
    u8 _0[0x74];
    u16 field_74;
};
PKMN_OFFSET_ASSERT(Unk_7f13d0, field_74, 0x74);

// 0x71007f13d0
void Unk_7f13d0_clearField74(Unk_7f13d0* self) {
    self->field_74 = 0;
}

struct Unk_7f1d10 {
    u8 _0[0x456];
    u16 field_456;
};
PKMN_OFFSET_ASSERT(Unk_7f1d10, field_456, 0x456);

// 0x71007f1d10
void Unk_7f1d10_clearField456(Unk_7f1d10* self) {
    self->field_456 = 0;
}

struct Unk_7f2340 {
    u8 _0[0x2ae];
    u8 field_2ae;
};
PKMN_OFFSET_ASSERT(Unk_7f2340, field_2ae, 0x2ae);

// 0x71007f2340
u8 Unk_7f2340_getField2ae(const Unk_7f2340* self) {
    return self->field_2ae;
}

struct Unk_7f2350 {
    u8 _0[0x2ae];
    u8 field_2ae;
};
PKMN_OFFSET_ASSERT(Unk_7f2350, field_2ae, 0x2ae);

// 0x71007f2350
bool Unk_7f2350_check(const Unk_7f2350* self) {
    return self->field_2ae != 0x12;
}

struct Unk_7f2360 {
    u8 _0[0x2b0];
    u32 field_2b0;
};
PKMN_OFFSET_ASSERT(Unk_7f2360, field_2b0, 0x2b0);

// 0x71007f2360
u32 Unk_7f2360_getField2b0(const Unk_7f2360* self) {
    return self->field_2b0;
}

struct Unk_7f2370 {
    u8 _0[0x338];
    u16 field_338;
};
PKMN_OFFSET_ASSERT(Unk_7f2370, field_338, 0x338);

// 0x71007f2370
void Unk_7f2370_setField338(Unk_7f2370* self, u16 value) {
    self->field_338 = value;
}

struct Unk_7f2490 {
    u8 _0[0x76];
    u16 field_76;
    u16 field_78;
};
PKMN_OFFSET_ASSERT(Unk_7f2490, field_76, 0x76);
PKMN_OFFSET_ASSERT(Unk_7f2490, field_78, 0x78);

// 0x71007f2490
void Unk_7f2490_set(Unk_7f2490* self, u16 value) {
    self->field_78 = value;
    self->field_76 = 0;
}

struct Unk_7f24a0 {
    u8 _0[0x78];
    u16 field_78;
};
PKMN_OFFSET_ASSERT(Unk_7f24a0, field_78, 0x78);

// 0x71007f24a0
void Unk_7f24a0_clearField78(Unk_7f24a0* self) {
    self->field_78 = 0;
}

struct Unk_7f24b0 {
    u8 _0[0x78];
    u16 field_78;
};
PKMN_OFFSET_ASSERT(Unk_7f24b0, field_78, 0x78);

// 0x71007f24b0
u16 Unk_7f24b0_getField78(const Unk_7f24b0* self) {
    return self->field_78;
}

struct Unk_7f2510 {
    u8 _0[0x348];
    u16 field_348;
};
PKMN_OFFSET_ASSERT(Unk_7f2510, field_348, 0x348);

// 0x71007f2510
u16 Unk_7f2510_getField348(const Unk_7f2510* self) {
    return self->field_348;
}

struct Unk_7f2520 {
    u8 _0[0x34c];
    u32 field_34c;
};
PKMN_OFFSET_ASSERT(Unk_7f2520, field_34c, 0x34c);

// 0x71007f2520
u32 Unk_7f2520_getField34c(const Unk_7f2520* self) {
    return self->field_34c;
}

struct Unk_7f2530 {
    u8 _0[0x341];
    u8 field_341;
};
PKMN_OFFSET_ASSERT(Unk_7f2530, field_341, 0x341);

// 0x71007f2530
u8 Unk_7f2530_getField341(const Unk_7f2530* self) {
    return self->field_341;
}

struct Unk_7f2540 {
    u8 _0[0x350];
    u32 field_350;
};
PKMN_OFFSET_ASSERT(Unk_7f2540, field_350, 0x350);

// 0x71007f2540
u32 Unk_7f2540_getField350(const Unk_7f2540* self) {
    return self->field_350;
}

struct Unk_7f2550 {
    u8 _0[0x34a];
    u8 field_34a;
};
PKMN_OFFSET_ASSERT(Unk_7f2550, field_34a, 0x34a);

// 0x71007f2550
u8 Unk_7f2550_getField34a(const Unk_7f2550* self) {
    return self->field_34a;
}

struct Unk_7f2560 {
    u8 _0[0x87];
    u8 field_87;
};
PKMN_OFFSET_ASSERT(Unk_7f2560, field_87, 0x87);

// 0x71007f2560
u32 Unk_7f2560_get(const Unk_7f2560* self) {
    return self->field_87 >> 7;
}

struct Unk_7f2580 {
    u8 _0[0x33a];
    u16 field_33a;
};
PKMN_OFFSET_ASSERT(Unk_7f2580, field_33a, 0x33a);

// 0x71007f2580
u16 Unk_7f2580_getField33a(const Unk_7f2580* self) {
    return self->field_33a;
}

struct Unk_7f29c0 {
    u8 _0[0x87];
    u8 field_87;
};
PKMN_OFFSET_ASSERT(Unk_7f29c0, field_87, 0x87);

// 0x71007f29c0
u32 Unk_7f29c0_get(const Unk_7f29c0* self) {
    return (self->field_87 >> 6) & 1;
}

struct Unk_7f29d0 {
    u8 _0[0x246];
    u8 field_246;
};
PKMN_OFFSET_ASSERT(Unk_7f29d0, field_246, 0x246);

// 0x71007f29d0
u8 Unk_7f29d0_getField246(const Unk_7f29d0* self) {
    return self->field_246;
}

struct Unk_7f2e60 {
    u8 _0[0x456];
    u16 field_456;
};
PKMN_OFFSET_ASSERT(Unk_7f2e60, field_456, 0x456);

void Unk_7f1820(void*, u32);

// 0x71007f2e60
void Unk_7f2e60_call(Unk_7f2e60* self, u16 value) {
    self->field_456 = value;
    Unk_7f1820(self, 8);
}

struct Unk_7f2e70 {
    u8 _0[0x456];
    u16 field_456;
};
PKMN_OFFSET_ASSERT(Unk_7f2e70, field_456, 0x456);

// 0x71007f2e70
bool Unk_7f2e70_check(const Unk_7f2e70* self) {
    return self->field_456 != 0;
}

struct Unk_7f2e80 {
    u8 _0[0x456];
    u16 field_456;
};
PKMN_OFFSET_ASSERT(Unk_7f2e80, field_456, 0x456);

// 0x71007f2e80
u16 Unk_7f2e80_getField456(const Unk_7f2e80* self) {
    return self->field_456;
}

struct Unk_7f2f80 {
    u8 _0[0x458];
    u32 field_458;
    u8 field_45c;
};
PKMN_OFFSET_ASSERT(Unk_7f2f80, field_458, 0x458);
PKMN_OFFSET_ASSERT(Unk_7f2f80, field_45c, 0x45c);

// 0x71007f2f80
void Unk_7f2f80_set(Unk_7f2f80* self, u8 value, u32 arg2) {
    self->field_45c = value;
    self->field_458 = arg2;
}

struct Unk_7f2fc0 {
    u8 _0[0x45c];
    u8 field_45c;
};
PKMN_OFFSET_ASSERT(Unk_7f2fc0, field_45c, 0x45c);

// 0x71007f2fc0
bool Unk_7f2fc0_check(const Unk_7f2fc0* self) {
    return self->field_45c != 0x1f;
}

struct Unk_7f2fd0 {
    u8 _0[0x2c5];
    u8 field_2c5;
};
PKMN_OFFSET_ASSERT(Unk_7f2fd0, field_2c5, 0x2c5);

// 0x71007f2fd0
bool Unk_7f2fd0_check(const Unk_7f2fd0* self) {
    return self->field_2c5 != 0;
}

struct Unk_7f34f0 {
    u8 _0[0x299];
    u8 field_299;
};
PKMN_OFFSET_ASSERT(Unk_7f34f0, field_299, 0x299);

// 0x71007f34f0
u8 Unk_7f34f0_getField299(const Unk_7f34f0* self) {
    return self->field_299;
}

struct Unk_7f36e0 {
    u8 _0[0x20];
    f32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_7f36e0, field_20, 0x20);

// 0x71007f36e0
f32 Unk_7f36e0_getField20(const Unk_7f36e0* self) {
    return self->field_20;
}

struct Unk_7f36f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7f36f0, field_0, 0x0);

// 0x71007f36f0
u64 Unk_7f36f0_getField0(const Unk_7f36f0* self) {
    return self->field_0;
}

struct Unk_7f3700 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7f3700, field_0, 0x0);

// 0x71007f3700
u64 Unk_7f3700_getField0(const Unk_7f3700* self) {
    return self->field_0;
}

struct Unk_7f3710 {
    u8 _0[0x3c];
    u8 field_3c;
};
PKMN_OFFSET_ASSERT(Unk_7f3710, field_3c, 0x3c);

// 0x71007f3710
u8 Unk_7f3710_getField3c(const Unk_7f3710* self) {
    return self->field_3c;
}

struct Unk_7f3720 {
    u8 _0[0x3d];
    u8 field_3d;
};
PKMN_OFFSET_ASSERT(Unk_7f3720, field_3d, 0x3d);

// 0x71007f3720
u8 Unk_7f3720_getField3d(const Unk_7f3720* self) {
    return self->field_3d;
}

struct Unk_7f3730 {
    u8 _0[0x3d];
    u8 field_3d;
};
PKMN_OFFSET_ASSERT(Unk_7f3730, field_3d, 0x3d);

// 0x71007f3730
void Unk_7f3730_setField3d(Unk_7f3730* self, u8 value) {
    self->field_3d = value;
}

struct Unk_7f3740 {
    u8 _0[0x3d];
    u8 field_3d;
};
PKMN_OFFSET_ASSERT(Unk_7f3740, field_3d, 0x3d);

// 0x71007f3740
void Unk_7f3740_set(Unk_7f3740* self) {
    if (self->field_3d != 0) {
        self->field_3d = self->field_3d - 1;
    }
}

struct Unk_7f3760 {
    u8 _0[0x25];
    u8 field_25;
};
PKMN_OFFSET_ASSERT(Unk_7f3760, field_25, 0x25);

// 0x71007f3760
u8 Unk_7f3760_getField25(const Unk_7f3760* self) {
    return self->field_25;
}

struct Unk_7f3770 {
    u8 _0[0x24];
    u8 field_24;
};
PKMN_OFFSET_ASSERT(Unk_7f3770, field_24, 0x24);

// 0x71007f3770
u8 Unk_7f3770_getField24(const Unk_7f3770* self) {
    return self->field_24;
}

struct Unk_7f37b0 {
    u8 _0[0x3f];
    u8 field_3f;
};
PKMN_OFFSET_ASSERT(Unk_7f37b0, field_3f, 0x3f);

// 0x71007f37b0
void Unk_7f37b0_set(Unk_7f37b0* self) {
    if (self->field_3f != 0) {
        self->field_3f = self->field_3f - 1;
    }
}

struct Unk_7f37d0 {
    u8 _0[0x40];
    u8 field_40;
};
PKMN_OFFSET_ASSERT(Unk_7f37d0, field_40, 0x40);

// 0x71007f37d0
void Unk_7f37d0_set(Unk_7f37d0* self) {
    self->field_40 = 1;
}

struct Unk_7f37e0 {
    u8 _0[0x3f];
    u8 field_3f;
    u8 field_40;
};
PKMN_OFFSET_ASSERT(Unk_7f37e0, field_3f, 0x3f);
PKMN_OFFSET_ASSERT(Unk_7f37e0, field_40, 0x40);

// 0x71007f37e0
void Unk_7f37e0_set(Unk_7f37e0* self, u8 value) {
    self->field_40 = 0;
    self->field_3f = value;
}

struct Unk_7f4fb0 {
    u8 _0[0x310];
    u8 field_310;
    u8 _311[0x94];
    u8 field_3a5;
};
PKMN_OFFSET_ASSERT(Unk_7f4fb0, field_310, 0x310);
PKMN_OFFSET_ASSERT(Unk_7f4fb0, field_3a5, 0x3a5);

void Unk_e87fe0(u64, void*);

// 0x71007f4fb0
void Unk_7f4fb0_call(Unk_7f4fb0* self) {
    self->field_3a5 = 1;
    Unk_e87fe0(0xcdb8b54649071c03, &self->field_310);
}

void Unk_7870a0();

// 0x71007f7140
void Unk_7f7140_call() {
    Unk_7870a0();
}

extern u64 Unk_27cecf0;
void Unk_785c80(u64, u32, u32);

// 0x71007f7ae0
void Unk_7f7ae0_call(u32 self, u32 value) {
    Unk_785c80(Unk_27cecf0, self, value);
}

void Unk_787110();

// 0x71007f7fe0
void Unk_7f7fe0_call() {
    Unk_787110();
}

void Unk_7f80f0(void*, u64, u64, u64, u32);

// 0x71007f8320
void Unk_7f8320_call(void* self, u64 value, u64 arg2, u64 arg3) {
    Unk_7f80f0(self, value, arg2, arg3, 1);
}

// 0x71007f8340
u32 Unk_7f8340_get(void* /*unused*/, u32 value) {
    return value;
}
