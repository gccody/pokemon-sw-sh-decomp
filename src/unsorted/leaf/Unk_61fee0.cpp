// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_61fee0 {
    u8 _0[0x1c8];
    u64 field_1c8;
    u32 field_1d0;
};
PKMN_OFFSET_ASSERT(Unk_61fee0, field_1c8, 0x1c8);
PKMN_OFFSET_ASSERT(Unk_61fee0, field_1d0, 0x1d0);

void Unk_615d40(u64, u32);

// 0x710061fee0
void Unk_61fee0_call(const Unk_61fee0* self) {
    Unk_615d40(self->field_1c8, self->field_1d0);
}

struct Unk_620820 {
    f32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_620820, field_0, 0x0);

// 0x7100620820
void Unk_620820_setField0(Unk_620820* self, f32 value) {
    self->field_0 = value;
}

struct Unk_620d60 {
    u8 _0[0x8];
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_620d60, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_620d60, field_10, 0x10);

// 0x7100620d60
u64 Unk_620d60_get(const Unk_620d60* self) {
    return (self->field_10 - self->field_8) >> 3;
}

struct Unk_621410 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_621410, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_621410, field_8, 0x8);

// 0x7100621410
u64 Unk_621410_get(const Unk_621410* self) {
    return (self->field_8 - self->field_0) >> 3;
}

struct Unk_623b70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_623b70, field_0, 0x0);

void Unk_623a00(u64);

// 0x7100623b70
void Unk_623b70_call(const Unk_623b70* self) {
    Unk_623a00(self->field_0);
}

// 0x7100623b80
void Unk_623b80_update() {}

struct Unk_623b90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_623b90_arg1, field_0, 0x0);

struct Unk_623b90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_623b90, field_0, 0x0);

// 0x7100623b90
void Unk_623b90_set(const Unk_623b90* self, Unk_623b90_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_623ba0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_623ba0_arg1, field_0, 0x0);

struct Unk_623ba0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_623ba0, field_0, 0x0);

// 0x7100623ba0
void Unk_623ba0_set(const Unk_623ba0* self, Unk_623ba0_arg1* value) {
    value->field_0 = self->field_0;
}

void Unk_623bc0();

// 0x7100623bb0
void Unk_623bb0_call() {
    Unk_623bc0();
}

struct Unk_6323a0 {
    u8 _0[0x1a8];
    u64 field_1a8;
};
PKMN_OFFSET_ASSERT(Unk_6323a0, field_1a8, 0x1a8);

void Unk_6342b0(u64);

// 0x71006323a0
void Unk_6323a0_call(const Unk_6323a0* self) {
    Unk_6342b0(self->field_1a8);
}

struct Unk_63bea0_arg1 {
    u16 field_0;
};
PKMN_OFFSET_ASSERT(Unk_63bea0_arg1, field_0, 0x0);

struct Unk_63bea0_arg2 {
    u16 field_0;
};
PKMN_OFFSET_ASSERT(Unk_63bea0_arg2, field_0, 0x0);

struct Unk_63bea0 {
    u8 _0[0x634];
    u16 field_634;
    u16 field_636;
};
PKMN_OFFSET_ASSERT(Unk_63bea0, field_634, 0x634);
PKMN_OFFSET_ASSERT(Unk_63bea0, field_636, 0x636);

// 0x710063bea0
void Unk_63bea0_set(Unk_63bea0* self, const Unk_63bea0_arg1* value, const Unk_63bea0_arg2* arg2) {
    self->field_634 = value->field_0;
    self->field_636 = arg2->field_0;
}

struct Unk_63bec0_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_63bec0_arg1, field_0, 0x0);

struct Unk_63bec0 {
    u8 _0[0x6c0];
    u32 field_6c0;
};
PKMN_OFFSET_ASSERT(Unk_63bec0, field_6c0, 0x6c0);

// 0x710063bec0
void Unk_63bec0_set(Unk_63bec0* self, const Unk_63bec0_arg1* value) {
    self->field_6c0 = value->field_0;
}

struct Unk_63bed0_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_63bed0_arg1, field_0, 0x0);

struct Unk_63bed0 {
    u8 _0[0x6c4];
    u32 field_6c4;
};
PKMN_OFFSET_ASSERT(Unk_63bed0, field_6c4, 0x6c4);

// 0x710063bed0
void Unk_63bed0_set(Unk_63bed0* self, const Unk_63bed0_arg1* value) {
    self->field_6c4 = value->field_0;
}

struct Unk_63bee0_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_63bee0_arg1, field_0, 0x0);

struct Unk_63bee0 {
    u8 _0[0x628];
    u32 field_628;
};
PKMN_OFFSET_ASSERT(Unk_63bee0, field_628, 0x628);

// 0x710063bee0
void Unk_63bee0_set(Unk_63bee0* self, const Unk_63bee0_arg1* value) {
    self->field_628 = value->field_0;
}

struct Unk_63bef0_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_63bef0_arg1, field_0, 0x0);

struct Unk_63bef0 {
    u8 _0[0x62c];
    u32 field_62c;
};
PKMN_OFFSET_ASSERT(Unk_63bef0, field_62c, 0x62c);

// 0x710063bef0
void Unk_63bef0_set(Unk_63bef0* self, const Unk_63bef0_arg1* value) {
    self->field_62c = value->field_0;
}

struct Unk_63bf00_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_63bf00_arg1, field_0, 0x0);

struct Unk_63bf00 {
    u8 _0[0x630];
    u32 field_630;
};
PKMN_OFFSET_ASSERT(Unk_63bf00, field_630, 0x630);

// 0x710063bf00
void Unk_63bf00_set(Unk_63bf00* self, const Unk_63bf00_arg1* value) {
    self->field_630 = value->field_0;
}

struct Unk_63bf10_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_63bf10_arg1, field_0, 0x0);

struct Unk_63bf10 {
    u8 _0[0x6c8];
    u32 field_6c8;
};
PKMN_OFFSET_ASSERT(Unk_63bf10, field_6c8, 0x6c8);

// 0x710063bf10
void Unk_63bf10_set(Unk_63bf10* self, const Unk_63bf10_arg1* value) {
    self->field_6c8 = value->field_0;
}

// 0x710063e2f0
void Unk_63e2f0_update() {}

struct Unk_63e300_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_63e300_arg1, field_0, 0x0);

struct Unk_63e300 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_63e300, field_0, 0x0);

// 0x710063e300
void Unk_63e300_set(const Unk_63e300* self, Unk_63e300_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_63e310_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_63e310_arg1, field_0, 0x0);

struct Unk_63e310 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_63e310, field_0, 0x0);

// 0x710063e310
void Unk_63e310_set(const Unk_63e310* self, Unk_63e310_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71006403d0
void Unk_6403d0_update() {}

// 0x71006403e0
void Unk_6403e0_update() {}

// 0x71006403f0
void Unk_6403f0_update() {}

// 0x7100640400
void Unk_640400_update() {}

struct Unk_640410_8 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_640410_8, field_60, 0x60);

struct Unk_640410 {
    u64 field_0;
    Unk_640410_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_640410, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_640410, field_8, 0x8);

void Unk_63d940(u64, u64);

// 0x7100640410
void Unk_640410_call(const Unk_640410* self) {
    Unk_63d940(self->field_0, self->field_8->field_60);
}

// 0x7100640420
void Unk_640420_update() {}

struct Unk_640430 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_640430, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_640430, field_8, 0x8);

// 0x7100640430
void Unk_640430_set(const Unk_640430* self, Unk_640430* value) {
    *value = *self;
}

struct Unk_640440 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_640440, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_640440, field_8, 0x8);

// 0x7100640440
void Unk_640440_set(const Unk_640440* self, Unk_640440* value) {
    *value = *self;
}

void Unk_641370();
void Unk_6418a0(void*);
void Unk_641e30(void*);
void Unk_6425a0(void*);

// 0x7100641330
void Unk_641330_call(void* self) {
    Unk_641370();
    Unk_6418a0(self);
    Unk_641e30(self);
    Unk_6425a0(self);
}

// 0x71006431e0
void Unk_6431e0_update() {}

struct Unk_6431f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6431f0_arg1, field_0, 0x0);

struct Unk_6431f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6431f0, field_0, 0x0);

// 0x71006431f0
void Unk_6431f0_set(const Unk_6431f0* self, Unk_6431f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_643200_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_643200_arg1, field_0, 0x0);

struct Unk_643200 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_643200, field_0, 0x0);

// 0x7100643200
void Unk_643200_set(const Unk_643200* self, Unk_643200_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_645e20_arg1 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u64 field_30;
    u64 field_38;
};
PKMN_OFFSET_ASSERT(Unk_645e20_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_645e20_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_645e20_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_645e20_arg1, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_645e20_arg1, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_645e20_arg1, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_645e20_arg1, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_645e20_arg1, field_38, 0x38);

struct Unk_645e20 {
    u8 _0[0x290];
    u64 field_290;
    u64 field_298;
    u64 field_2a0;
    u64 field_2a8;
    u64 field_2b0;
    u64 field_2b8;
    u64 field_2c0;
    u64 field_2c8;
};
PKMN_OFFSET_ASSERT(Unk_645e20, field_290, 0x290);
PKMN_OFFSET_ASSERT(Unk_645e20, field_298, 0x298);
PKMN_OFFSET_ASSERT(Unk_645e20, field_2a0, 0x2a0);
PKMN_OFFSET_ASSERT(Unk_645e20, field_2a8, 0x2a8);
PKMN_OFFSET_ASSERT(Unk_645e20, field_2b0, 0x2b0);
PKMN_OFFSET_ASSERT(Unk_645e20, field_2b8, 0x2b8);
PKMN_OFFSET_ASSERT(Unk_645e20, field_2c0, 0x2c0);
PKMN_OFFSET_ASSERT(Unk_645e20, field_2c8, 0x2c8);

// 0x7100645e20
void Unk_645e20_set(Unk_645e20* self, const Unk_645e20_arg1* value) {
    u64 v0 = value->field_8;
    self->field_2a8 = value->field_18;
    self->field_298 = v0;
    u64 v1 = value->field_28;
    self->field_2c8 = value->field_38;
    self->field_2b8 = v1;
    u64 v2 = value->field_0;
    self->field_2a0 = value->field_10;
    self->field_290 = v2;
    u64 v3 = value->field_20;
    self->field_2c0 = value->field_30;
    self->field_2b0 = v3;
}

struct Unk_6469e0 {
    u64 field_0;
    u8 _8[0x48];
    u64 field_50;
    u64 field_58;
    u64 field_60;
    u64 field_68;
    u64 field_70;
    u64 field_78;
    u64 field_80;
    u64 field_88;
    u8 _90[0x40];
    u64 field_d0;
    u32 field_d8;
};
PKMN_OFFSET_ASSERT(Unk_6469e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_6469e0, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_6469e0, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_6469e0, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_6469e0, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_6469e0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_6469e0, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_6469e0, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_6469e0, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_6469e0, field_d0, 0xd0);
PKMN_OFFSET_ASSERT(Unk_6469e0, field_d8, 0xd8);

// 0x71006469e0
void Unk_6469e0_set(Unk_6469e0* self) {
    self->field_80 = 0;
    self->field_88 = 0;
    self->field_0 = 0x45bb800042000000;
    self->field_d0 = 0;
    self->field_70 = 0;
    self->field_78 = 0;
    self->field_d8 = 0x3ecccccd;
    self->field_60 = 0;
    self->field_68 = 0;
    self->field_50 = 0;
    self->field_58 = 0;
}

struct Unk_64d770 {
    u8 _0[0x270];
    f32 field_270;
};
PKMN_OFFSET_ASSERT(Unk_64d770, field_270, 0x270);

// 0x710064d770
void Unk_64d770_setField270(Unk_64d770* self, f32 value) {
    self->field_270 = value;
}

struct Unk_64e500 {
    u8 _0[0x330];
    f32 field_330;
    u8 _334[0x9c];
    u8 field_3d0;
};
PKMN_OFFSET_ASSERT(Unk_64e500, field_330, 0x330);
PKMN_OFFSET_ASSERT(Unk_64e500, field_3d0, 0x3d0);

// 0x710064e500
void Unk_64e500_set(Unk_64e500* self, f32 fvalue) {
    self->field_3d0 = 0;
    self->field_330 = fvalue;
}

void Unk_64fe20(void*, u64, u64, u64, u32);

// 0x7100650240
void Unk_650240_call(void* self, u64 value, u64 arg2, u64 arg3) {
    Unk_64fe20(self, value, arg2, arg3, 0);
}

void Unk_64fe20(void*, u64, u64, u64, u32);

// 0x7100650250
void Unk_650250_call(void* self, u64 value, u64 arg2) {
    Unk_64fe20(self, value, arg2, 0, 1);
}

struct Unk_650800_arg1_108 {
    u8 _0[0x60];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_650800_arg1_108, field_60, 0x60);

struct Unk_650800_arg1 {
    u8 _0[0x108];
    Unk_650800_arg1_108* field_108;
};
PKMN_OFFSET_ASSERT(Unk_650800_arg1, field_108, 0x108);

void Unk_650270(void*, void*, u64, void*, u32, u64);

// 0x7100650800
void Unk_650800_call(void* self, Unk_650800_arg1* value, u64 arg2, u64 arg3) {
    Unk_650270(self, value, arg2, &value->field_108->field_60, 1, arg3);
}

struct Unk_6580c0_arg1 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_6580c0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_6580c0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_6580c0_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_6580c0_arg1, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_6580c0_arg1, field_20, 0x20);

struct Unk_6580c0 {
    u8 _0[0x460];
    u64 field_460;
    u64 field_468;
    u64 field_470;
    u64 field_478;
    u32 field_480;
};
PKMN_OFFSET_ASSERT(Unk_6580c0, field_460, 0x460);
PKMN_OFFSET_ASSERT(Unk_6580c0, field_468, 0x468);
PKMN_OFFSET_ASSERT(Unk_6580c0, field_470, 0x470);
PKMN_OFFSET_ASSERT(Unk_6580c0, field_478, 0x478);
PKMN_OFFSET_ASSERT(Unk_6580c0, field_480, 0x480);

// 0x71006580c0
void Unk_6580c0_set(Unk_6580c0* self, const Unk_6580c0_arg1* value) {
    self->field_460 = value->field_0;
    u64 v0 = value->field_10;
    u64 v1 = value->field_18;
    u64 v2 = value->field_8;
    self->field_480 = value->field_20;
    self->field_478 = v1;
    self->field_470 = v0;
    self->field_468 = v2;
}

struct Unk_6580f0_268 {
    u8 _0[0xfc];
    u32 field_fc;
};
PKMN_OFFSET_ASSERT(Unk_6580f0_268, field_fc, 0xfc);

struct Unk_6580f0 {
    u8 _0[0x268];
    Unk_6580f0_268* field_268;
    u8 _270[0x214];
    bool field_484;
    u8 field_485;
    u8 _486[0x2];
    u32 field_488;
};
PKMN_OFFSET_ASSERT(Unk_6580f0, field_268, 0x268);
PKMN_OFFSET_ASSERT(Unk_6580f0, field_484, 0x484);
PKMN_OFFSET_ASSERT(Unk_6580f0, field_485, 0x485);
PKMN_OFFSET_ASSERT(Unk_6580f0, field_488, 0x488);

// 0x71006580f0
void Unk_6580f0_set(Unk_6580f0* self, bool value) {
    self->field_484 = value;
    self->field_488 = ((value) & 0xfffffe01) | ((self->field_485 & 0xff) << 1);
    self->field_268->field_fc = ((value) & 0xfffffe01) | ((self->field_485 & 0xff) << 1);
}

struct Unk_658df0 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_658df0, field_60, 0x60);

// 0x7100658df0
u32 Unk_658df0_getField60(const Unk_658df0* self) {
    return self->field_60;
}

struct Unk_65a0c0_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_65a0c0_arg1, field_0, 0x0);

struct Unk_65a0c0 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_65a0c0, field_60, 0x60);

void Unk_659980();

// 0x710065a0c0
void Unk_65a0c0_call(Unk_65a0c0* self, const Unk_65a0c0_arg1* value) {
    self->field_60 = value->field_0;
    Unk_659980();
}

struct Unk_65a5d0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_65a5d0, field_0, 0x0);

// 0x710065a5d0
void Unk_65a5d0_call(Unk_65a5d0* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}
