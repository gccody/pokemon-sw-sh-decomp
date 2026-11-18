// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u64 Unk_2771590;

// 0x7100596d30
u64 Unk_596d30_get() {
    return Unk_2771590;
}

struct Unk_596e60 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_596e60, field_8, 0x8);

// 0x7100596e60
u8* Unk_596e60_getField8Ptr(Unk_596e60* self) {
    return &self->field_8;
}

struct Unk_596e70 {
    u8 _0[0x68];
    u8 field_68;
};
PKMN_OFFSET_ASSERT(Unk_596e70, field_68, 0x68);

// 0x7100596e70
u8* Unk_596e70_getField68Ptr(Unk_596e70* self) {
    return &self->field_68;
}

struct Unk_596e80 {
    u8 _0[0xc8];
    u8 field_c8;
};
PKMN_OFFSET_ASSERT(Unk_596e80, field_c8, 0xc8);

// 0x7100596e80
u8* Unk_596e80_getFieldc8Ptr(Unk_596e80* self) {
    return &self->field_c8;
}

struct Unk_597920 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_597920, field_8, 0x8);

// 0x7100597920
u8* Unk_597920_getField8Ptr(Unk_597920* self) {
    return &self->field_8;
}

struct Unk_597930_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_597930_arg1, field_0, 0x0);

struct Unk_597930 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_597930, field_8, 0x8);

// 0x7100597930
bool Unk_597930_check(const Unk_597930* self, const Unk_597930_arg1* value) {
    return self->field_8 == value->field_0;
}

extern u64 Unk_2771598;

// 0x7100597960
u64 Unk_597960_get() {
    return Unk_2771598;
}

struct Unk_597b40 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_597b40, field_8, 0x8);

// 0x7100597b40
u8* Unk_597b40_getField8Ptr(Unk_597b40* self) {
    return &self->field_8;
}

struct Unk_597b50 {
    u8 _0[0x28];
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_597b50, field_28, 0x28);

// 0x7100597b50
u8* Unk_597b50_getField28Ptr(Unk_597b50* self) {
    return &self->field_28;
}

struct Unk_597b60 {
    u8 _0[0x88];
    u8 field_88;
};
PKMN_OFFSET_ASSERT(Unk_597b60, field_88, 0x88);

// 0x7100597b60
u8* Unk_597b60_getField88Ptr(Unk_597b60* self) {
    return &self->field_88;
}

struct Unk_597b70 {
    u8 _0[0xe8];
    u8 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_597b70, field_e8, 0xe8);

// 0x7100597b70
u8* Unk_597b70_getFielde8Ptr(Unk_597b70* self) {
    return &self->field_e8;
}

struct Unk_59a250 {
    u8 _0[0x1d0];
    u64 field_1d0;
    u64 field_1d8;
};
PKMN_OFFSET_ASSERT(Unk_59a250, field_1d0, 0x1d0);
PKMN_OFFSET_ASSERT(Unk_59a250, field_1d8, 0x1d8);

// 0x710059a250
u64 Unk_59a250_get(const Unk_59a250* self) {
    return (self->field_1d8 - self->field_1d0) >> 3;
}

struct Unk_59a4f0 {
    u8 _0[0x40c];
    f32 field_40c;
};
PKMN_OFFSET_ASSERT(Unk_59a4f0, field_40c, 0x40c);

// 0x710059a4f0
void Unk_59a4f0_setField40c(Unk_59a4f0* self, f32 value) {
    self->field_40c = value;
}

struct Unk_59a500 {
    u8 _0[0x40c];
    f32 field_40c;
};
PKMN_OFFSET_ASSERT(Unk_59a500, field_40c, 0x40c);

// 0x710059a500
f32 Unk_59a500_getField40c(const Unk_59a500* self) {
    return self->field_40c;
}

struct Unk_59a510 {
    u8 _0[0x400];
    bool field_400;
};
PKMN_OFFSET_ASSERT(Unk_59a510, field_400, 0x400);

// 0x710059a510
void Unk_59a510_set(Unk_59a510* self, bool value) {
    self->field_400 = value;
}

struct Unk_59a520 {
    u8 _0[0x401];
    bool field_401;
};
PKMN_OFFSET_ASSERT(Unk_59a520, field_401, 0x401);

// 0x710059a520
void Unk_59a520_set(Unk_59a520* self, bool value) {
    self->field_401 = value;
}

struct Unk_59a530 {
    u8 _0[0x401];
    u8 field_401;
};
PKMN_OFFSET_ASSERT(Unk_59a530, field_401, 0x401);

// 0x710059a530
u8 Unk_59a530_getField401(const Unk_59a530* self) {
    return self->field_401;
}

struct Unk_59a650_230 {
    u8 _0[0x40];
    u64 field_40;
    u64 field_48;
};
PKMN_OFFSET_ASSERT(Unk_59a650_230, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_59a650_230, field_48, 0x48);

struct Unk_59a650_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_59a650_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_59a650_arg1, field_8, 0x8);

struct Unk_59a650 {
    u8 _0[0x230];
    Unk_59a650_230* field_230;
};
PKMN_OFFSET_ASSERT(Unk_59a650, field_230, 0x230);

// 0x710059a650
void Unk_59a650_set(const Unk_59a650* self, const Unk_59a650_arg1* value) {
    Unk_59a650_230* p0 = self->field_230;
    if (p0 != nullptr) {
        p0->field_48 = value->field_8;
        p0->field_40 = value->field_0;
    }
}

struct Unk_59b060 {
    u8 _0[0x270];
    u64 field_270;
};
PKMN_OFFSET_ASSERT(Unk_59b060, field_270, 0x270);

// 0x710059b060
bool Unk_59b060_check(const Unk_59b060* self) {
    return self->field_270 != 0;
}

struct Unk_59b2c0 {
    u8 _0[0x402];
    u8 field_402;
};
PKMN_OFFSET_ASSERT(Unk_59b2c0, field_402, 0x402);

// 0x710059b2c0
void Unk_59b2c0_set(Unk_59b2c0* self) {
    self->field_402 = 1;
}

struct Unk_59b2d0 {
    u8 _0[0x402];
    u8 field_402;
};
PKMN_OFFSET_ASSERT(Unk_59b2d0, field_402, 0x402);

// 0x710059b2d0
void Unk_59b2d0_clearField402(Unk_59b2d0* self) {
    self->field_402 = 0;
}

struct Unk_59b2e0 {
    u8 _0[0x402];
    u8 field_402;
};
PKMN_OFFSET_ASSERT(Unk_59b2e0, field_402, 0x402);

// 0x710059b2e0
u8 Unk_59b2e0_getField402(const Unk_59b2e0* self) {
    return self->field_402;
}

// 0x710059cda0
void Unk_59cda0_update() {}

struct Unk_59cdb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_59cdb0_arg1, field_0, 0x0);

struct Unk_59cdb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_59cdb0, field_0, 0x0);

// 0x710059cdb0
void Unk_59cdb0_set(const Unk_59cdb0* self, Unk_59cdb0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_59cdc0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_59cdc0_arg1, field_0, 0x0);

struct Unk_59cdc0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_59cdc0, field_0, 0x0);

// 0x710059cdc0
void Unk_59cdc0_set(const Unk_59cdc0* self, Unk_59cdc0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710059cf20
void Unk_59cf20_update() {}

struct Unk_59cf30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_59cf30_arg1, field_0, 0x0);

struct Unk_59cf30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_59cf30, field_0, 0x0);

// 0x710059cf30
void Unk_59cf30_set(const Unk_59cf30* self, Unk_59cf30_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_59cf40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_59cf40_arg1, field_0, 0x0);

struct Unk_59cf40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_59cf40, field_0, 0x0);

// 0x710059cf40
void Unk_59cf40_set(const Unk_59cf40* self, Unk_59cf40_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710059d0b0
void Unk_59d0b0_update() {}

struct Unk_59d0c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_59d0c0_arg1, field_0, 0x0);

struct Unk_59d0c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_59d0c0, field_0, 0x0);

// 0x710059d0c0
void Unk_59d0c0_set(const Unk_59d0c0* self, Unk_59d0c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_59d0d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_59d0d0_arg1, field_0, 0x0);

struct Unk_59d0d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_59d0d0, field_0, 0x0);

// 0x710059d0d0
void Unk_59d0d0_set(const Unk_59d0d0* self, Unk_59d0d0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710059d1d0
void Unk_59d1d0_update() {}

struct Unk_59d1e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_59d1e0_arg1, field_0, 0x0);

struct Unk_59d1e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_59d1e0, field_0, 0x0);

// 0x710059d1e0
void Unk_59d1e0_set(const Unk_59d1e0* self, Unk_59d1e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_59d1f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_59d1f0_arg1, field_0, 0x0);

struct Unk_59d1f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_59d1f0, field_0, 0x0);

// 0x710059d1f0
void Unk_59d1f0_set(const Unk_59d1f0* self, Unk_59d1f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_59d590_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_59d590_arg1, field_0, 0x0);

struct Unk_59d590 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_59d590, field_8, 0x8);

// 0x710059d590
void Unk_59d590_set(Unk_59d590* self, const Unk_59d590_arg1* value) {
    self->field_8 = value->field_0;
}

void Unk_5ac1f0(u64, void*);

// 0x710059d690
void Unk_59d690_call(void* self, u64 value) {
    Unk_5ac1f0(value, self);
}

struct Unk_59e970 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_59e970, field_0, 0x0);

// 0x710059e970
void Unk_59e970_setField0(Unk_59e970* self, u64 value) {
    self->field_0 = value;
}

struct Unk_59f220 {
    u8 _0[0x130];
    u8 field_130;
};
PKMN_OFFSET_ASSERT(Unk_59f220, field_130, 0x130);

// 0x710059f220
u8* Unk_59f220_getField130Ptr(Unk_59f220* self) {
    return &self->field_130;
}

struct Unk_59f230 {
    u8 _0[0x130];
    u8 field_130;
};
PKMN_OFFSET_ASSERT(Unk_59f230, field_130, 0x130);

// 0x710059f230
u8* Unk_59f230_getField130Ptr(Unk_59f230* self) {
    return &self->field_130;
}

struct Unk_59f2b0 {
    u8 _0[0x1b0];
    u64 field_1b0;
};
PKMN_OFFSET_ASSERT(Unk_59f2b0, field_1b0, 0x1b0);

void Unk_5a8370(u64);

// 0x710059f2b0
void Unk_59f2b0_call(const Unk_59f2b0* self) {
    Unk_5a8370(self->field_1b0);
}

struct Unk_59f2c0_0 {
    u8 _0[0x350];
    u64 field_350;
};
PKMN_OFFSET_ASSERT(Unk_59f2c0_0, field_350, 0x350);

struct Unk_59f2c0 {
    Unk_59f2c0_0* field_0;
    u8 _8[0x148];
    u64 field_150;
};
PKMN_OFFSET_ASSERT(Unk_59f2c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_59f2c0, field_150, 0x150);

void Unk_5a0a10(u64, u64, u32);

// 0x710059f2c0
void Unk_59f2c0_call(const Unk_59f2c0* self, u32 value) {
    Unk_5a0a10(self->field_150, self->field_0->field_350, value);
}

struct Unk_59f2e0 {
    u64 field_0;
    u8 _8[0x168];
    u64 field_170;
};
PKMN_OFFSET_ASSERT(Unk_59f2e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_59f2e0, field_170, 0x170);

void Unk_5a5a90(u64, u64, u64);

// 0x710059f2e0
void Unk_59f2e0_call(const Unk_59f2e0* self, u64 value) {
    Unk_5a5a90(self->field_170, value, self->field_0);
}

struct Unk_59f2f0 {
    u8 _0[0x190];
    u64 field_190;
};
PKMN_OFFSET_ASSERT(Unk_59f2f0, field_190, 0x190);

void Unk_5a90c0(u64);

// 0x710059f2f0
void Unk_59f2f0_call(const Unk_59f2f0* self) {
    Unk_5a90c0(self->field_190);
}

struct Unk_59f300 {
    u8 _0[0x1f0];
    f32 field_1f0;
};
PKMN_OFFSET_ASSERT(Unk_59f300, field_1f0, 0x1f0);

// 0x710059f300
void Unk_59f300_setField1f0(Unk_59f300* self, f32 value) {
    self->field_1f0 = value;
}

struct Unk_59f310 {
    u8 _0[0x1f0];
    f32 field_1f0;
};
PKMN_OFFSET_ASSERT(Unk_59f310, field_1f0, 0x1f0);

// 0x710059f310
f32 Unk_59f310_getField1f0(const Unk_59f310* self) {
    return self->field_1f0;
}

struct Unk_59f320 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_59f320, field_10, 0x10);

// 0x710059f320
void Unk_59f320_setField10(Unk_59f320* self, u64 value) {
    self->field_10 = value;
}

struct Unk_5a00c0 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_5a00c0, field_8, 0x8);

// 0x71005a00c0
u8* Unk_5a00c0_getField8Ptr(Unk_5a00c0* self) {
    return &self->field_8;
}

struct Unk_5a0600 {
    u8 _0[0x28];
    u32 field_28;
};
PKMN_OFFSET_ASSERT(Unk_5a0600, field_28, 0x28);

// 0x71005a0600
u32 Unk_5a0600_getField28(const Unk_5a0600* self) {
    return self->field_28;
}

struct Unk_5a0790 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5a0790, field_0, 0x0);

// 0x71005a0790
void Unk_5a0790_setField0(Unk_5a0790* self, u32 value) {
    self->field_0 = value;
}

struct Unk_5a07a0 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5a07a0, field_0, 0x0);

// 0x71005a07a0
u32 Unk_5a07a0_getField0(const Unk_5a07a0* self) {
    return self->field_0;
}

struct Unk_5a07b0 {
    u8 _0[0x4];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_5a07b0, field_4, 0x4);

// 0x71005a07b0
void Unk_5a07b0_setField4(Unk_5a07b0* self, u32 value) {
    self->field_4 = value;
}

struct Unk_5a07c0 {
    u8 _0[0x4];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_5a07c0, field_4, 0x4);

// 0x71005a07c0
u32 Unk_5a07c0_getField4(const Unk_5a07c0* self) {
    return self->field_4;
}

struct Unk_5a0810 {
    u8 _0[0x14];
    f32 field_14;
};
PKMN_OFFSET_ASSERT(Unk_5a0810, field_14, 0x14);

// 0x71005a0810
f32 Unk_5a0810_getField14(const Unk_5a0810* self) {
    return self->field_14;
}

struct Unk_5a0820 {
    u8 _0[0x8];
    f32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_5a0820, field_8, 0x8);

// 0x71005a0820
void Unk_5a0820_setField8(Unk_5a0820* self, f32 value) {
    self->field_8 = value;
}

struct Unk_5a08f0 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_5a08f0, field_18, 0x18);

// 0x71005a08f0
u8 Unk_5a08f0_getField18(const Unk_5a08f0* self) {
    return self->field_18;
}

struct Unk_5a9a60 {
    u8 _0[0x8];
    f32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_5a9a60, field_8, 0x8);

// 0x71005a9a60
f32 Unk_5a9a60_getField8(const Unk_5a9a60* self) {
    return self->field_8;
}

struct Unk_5abb00 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_5abb00, field_10, 0x10);

// 0x71005abb00
u8* Unk_5abb00_getField10Ptr(Unk_5abb00* self) {
    return &self->field_10;
}

struct Unk_5ac2f0 {
    u8 _0[0x40];
    f32 field_40;
};
PKMN_OFFSET_ASSERT(Unk_5ac2f0, field_40, 0x40);

// 0x71005ac2f0
void Unk_5ac2f0_setField40(Unk_5ac2f0* self, f32 value) {
    self->field_40 = value;
}

struct Unk_5ac300 {
    u8 _0[0x40];
    f32 field_40;
};
PKMN_OFFSET_ASSERT(Unk_5ac300, field_40, 0x40);

// 0x71005ac300
f32 Unk_5ac300_getField40(const Unk_5ac300* self) {
    return self->field_40;
}

struct Unk_5acc80 {
    u8 _0[0x50];
    bool field_50;
    u8 _51[0x7];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_5acc80, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_5acc80, field_58, 0x58);

// 0x71005acc80
void Unk_5acc80_set(Unk_5acc80* self, bool value) {
    self->field_50 = value;
    self->field_58 = 0;
}

struct Unk_5b4770 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_5b4770, field_8, 0x8);

// 0x71005b4770
u32 Unk_5b4770_getField8(const Unk_5b4770* self) {
    return self->field_8;
}

struct Unk_5b4dc0 {
    u8 _0[0x68];
    u8 field_68;
};
PKMN_OFFSET_ASSERT(Unk_5b4dc0, field_68, 0x68);

// 0x71005b4dc0
u8* Unk_5b4dc0_getField68Ptr(Unk_5b4dc0* self) {
    return &self->field_68;
}

struct Unk_5b50f0 {
    u8 _0[0x1b0];
    u64 field_1b0;
};
PKMN_OFFSET_ASSERT(Unk_5b50f0, field_1b0, 0x1b0);

void Unk_5b6b20(u64);

// 0x71005b50f0
void Unk_5b50f0_call(const Unk_5b50f0* self) {
    Unk_5b6b20(self->field_1b0);
}

struct Unk_5b5120 {
    u8 _0[0x1b0];
    u64 field_1b0;
};
PKMN_OFFSET_ASSERT(Unk_5b5120, field_1b0, 0x1b0);

void Unk_5b6eb0(u64);

// 0x71005b5120
void Unk_5b5120_call(const Unk_5b5120* self) {
    Unk_5b6eb0(self->field_1b0);
}

struct Unk_5b5790 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_5b5790, field_8, 0x8);

// 0x71005b5790
u8* Unk_5b5790_getField8Ptr(Unk_5b5790* self) {
    return &self->field_8;
}

struct Unk_5b6420 {
    u8 _0[0x28];
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_5b6420, field_28, 0x28);

// 0x71005b6420
u8* Unk_5b6420_getField28Ptr(Unk_5b6420* self) {
    return &self->field_28;
}

struct Unk_5b6430 {
    u8 _0[0x48];
    u8 field_48;
};
PKMN_OFFSET_ASSERT(Unk_5b6430, field_48, 0x48);

// 0x71005b6430
u8* Unk_5b6430_getField48Ptr(Unk_5b6430* self) {
    return &self->field_48;
}

struct Unk_5b6440 {
    u8 _0[0x68];
    u8 field_68;
};
PKMN_OFFSET_ASSERT(Unk_5b6440, field_68, 0x68);

// 0x71005b6440
u8* Unk_5b6440_getField68Ptr(Unk_5b6440* self) {
    return &self->field_68;
}

struct Unk_5b6490 {
    u8 _0[0x88];
    u64 field_88;
};
PKMN_OFFSET_ASSERT(Unk_5b6490, field_88, 0x88);

// 0x71005b6490
u64 Unk_5b6490_getField88(const Unk_5b6490* self) {
    return self->field_88;
}

struct Unk_5b6530 {
    u8 _0[0x118];
    u64 field_118;
};
PKMN_OFFSET_ASSERT(Unk_5b6530, field_118, 0x118);

// 0x71005b6530
u64 Unk_5b6530_getField118(const Unk_5b6530* self) {
    return self->field_118;
}

struct Unk_5b6ea0 {
    u8 _0[0x130];
    u8 field_130;
};
PKMN_OFFSET_ASSERT(Unk_5b6ea0, field_130, 0x130);

// 0x71005b6ea0
u8* Unk_5b6ea0_getField130Ptr(Unk_5b6ea0* self) {
    return &self->field_130;
}

struct Unk_5b7990 {
    u8 _0[0x38];
    u8 field_38;
};
PKMN_OFFSET_ASSERT(Unk_5b7990, field_38, 0x38);

// 0x71005b7990
u8* Unk_5b7990_getField38Ptr(Unk_5b7990* self) {
    return &self->field_38;
}

struct Unk_5b8140 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_5b8140, field_78, 0x78);

// 0x71005b8140
u64 Unk_5b8140_getField78(const Unk_5b8140* self) {
    return self->field_78;
}

struct Unk_5b8150 {
    u8 _0[0x80];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_5b8150, field_80, 0x80);

// 0x71005b8150
u64 Unk_5b8150_getField80(const Unk_5b8150* self) {
    return self->field_80;
}

struct Unk_5b8160 {
    u8 _0[0x80];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_5b8160, field_80, 0x80);

// 0x71005b8160
u64 Unk_5b8160_getField80(const Unk_5b8160* self) {
    return self->field_80;
}

struct Unk_5b8170 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_5b8170, field_58, 0x58);

void Unk_5b8970(u64);

// 0x71005b8170
void Unk_5b8170_call(const Unk_5b8170* self) {
    if (self->field_58 != 0) {
        Unk_5b8970(self->field_58);
    }
}

struct Unk_5b90b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5b90b0, field_0, 0x0);

// 0x71005b90b0
void Unk_5b90b0_setField0(Unk_5b90b0* self, u64 value) {
    self->field_0 = value;
}

struct Unk_5b9120 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5b9120, field_0, 0x0);

// 0x71005b9120
void Unk_5b9120_setField0(Unk_5b9120* self, u64 value) {
    self->field_0 = value;
}

struct Unk_5b9130_0 {
    u8 _0[0x90];
    u64 field_90;
    u64 field_98;
};
PKMN_OFFSET_ASSERT(Unk_5b9130_0, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_5b9130_0, field_98, 0x98);

struct Unk_5b9130 {
    Unk_5b9130_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_5b9130, field_0, 0x0);

// 0x71005b9130
bool Unk_5b9130_check(const Unk_5b9130* self) {
    if (self->field_0 == nullptr) {
        return false;
    }
    return self->field_0->field_90 != self->field_0->field_98;
}

// 0x71005b95e0
void Unk_5b95e0() {}

struct Unk_5b95f0 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_5b95f0, field_28, 0x28);

// 0x71005b95f0
u64 Unk_5b95f0_getField28(const Unk_5b95f0* self) {
    return self->field_28;
}

// 0x71005b9660
void Unk_5b9660() {}

struct Unk_5b9670 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_5b9670, field_28, 0x28);

// 0x71005b9670
u64 Unk_5b9670_getField28(const Unk_5b9670* self) {
    return self->field_28;
}

struct Unk_5b9a80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5b9a80, field_0, 0x0);

// 0x71005b9a80
bool Unk_5b9a80_check(const Unk_5b9a80* self) {
    return self->field_0 != 0;
}

struct Unk_5b9a90 {
    u8 _0[0x18];
    u64 field_18;
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_5b9a90, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_5b9a90, field_20, 0x20);

void Unk_5ba880(u64, u64);

// 0x71005b9a90
void Unk_5b9a90_call(const Unk_5b9a90* self) {
    Unk_5ba880(self->field_18, self->field_20);
}

struct Unk_5b9aa0 {
    u8 _0[0x40];
    u64 field_40;
};
PKMN_OFFSET_ASSERT(Unk_5b9aa0, field_40, 0x40);

// 0x71005b9aa0
u64 Unk_5b9aa0_getField40(const Unk_5b9aa0* self) {
    return self->field_40;
}

struct Unk_5b9d70 {
    u64 field_0;
    u8 _8[0x38];
    u64 field_40;
};
PKMN_OFFSET_ASSERT(Unk_5b9d70, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_5b9d70, field_40, 0x40);

void Unk_5ac130(u64);

// 0x71005b9d70
void Unk_5b9d70_call(const Unk_5b9d70* self) {
    if (self->field_0 != 0) {
        Unk_5ac130(self->field_40);
    }
}

struct Unk_5bbe30 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_5bbe30, field_8, 0x8);

// 0x71005bbe30
u8* Unk_5bbe30_getField8Ptr(Unk_5bbe30* self) {
    return &self->field_8;
}

struct Unk_5be7b0 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_5be7b0, field_8, 0x8);

// 0x71005be7b0
u8* Unk_5be7b0_getField8Ptr(Unk_5be7b0* self) {
    return &self->field_8;
}

struct Unk_5bee90 {
    u8 _0[0x1b0];
    u64 field_1b0;
};
PKMN_OFFSET_ASSERT(Unk_5bee90, field_1b0, 0x1b0);

// 0x71005bee90
u64 Unk_5bee90_getField1b0(const Unk_5bee90* self) {
    return self->field_1b0;
}

struct Unk_5beea0 {
    u8 _0[0x200];
    u32 field_200;
};
PKMN_OFFSET_ASSERT(Unk_5beea0, field_200, 0x200);

// 0x71005beea0
u32 Unk_5beea0_getField200(const Unk_5beea0* self) {
    return self->field_200;
}

struct Unk_5beec0 {
    u8 _0[0x208];
    u64 field_208;
};
PKMN_OFFSET_ASSERT(Unk_5beec0, field_208, 0x208);

void Unk_5c0460(u64);

// 0x71005beec0
void Unk_5beec0_call(const Unk_5beec0* self) {
    if (self->field_208 != 0) {
        Unk_5c0460(self->field_208);
    }
}

struct Unk_5c0440_30 {
    u8 _0[0x30];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_5c0440_30, field_30, 0x30);

struct Unk_5c0440 {
    u8 _0[0x30];
    Unk_5c0440_30* field_30;
    u8 _38[0x18];
    u64 field_50;
};
PKMN_OFFSET_ASSERT(Unk_5c0440, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_5c0440, field_50, 0x50);

// 0x71005c0440
u64 Unk_5c0440_get(const Unk_5c0440* self) {
    if (self->field_50 == 0) {
        return 0;
    }
    return self->field_30->field_30;
}

struct Unk_5c0a90 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_5c0a90, field_8, 0x8);

// 0x71005c0a90
u8* Unk_5c0a90_getField8Ptr(Unk_5c0a90* self) {
    return &self->field_8;
}

struct Unk_5c0aa0 {
    u8 _0[0x50];
    u8 field_50;
};
PKMN_OFFSET_ASSERT(Unk_5c0aa0, field_50, 0x50);

// 0x71005c0aa0
u8* Unk_5c0aa0_getField50Ptr(Unk_5c0aa0* self) {
    return &self->field_50;
}

struct Unk_5c4b60 {
    u8 _0[0x218];
    f32 field_218;
};
PKMN_OFFSET_ASSERT(Unk_5c4b60, field_218, 0x218);

// 0x71005c4b60
void Unk_5c4b60_setField218(Unk_5c4b60* self, f32 value) {
    self->field_218 = value;
}

struct Unk_5c4b70 {
    u8 _0[0x220];
    u8 field_220;
};
PKMN_OFFSET_ASSERT(Unk_5c4b70, field_220, 0x220);

// 0x71005c4b70
void Unk_5c4b70_set(Unk_5c4b70* self) {
    self->field_220 = 1;
}

struct Unk_5c51a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5c51a0, field_0, 0x0);

// 0x71005c51a0
void Unk_5c51a0_setField0(Unk_5c51a0* self, u64 value) {
    self->field_0 = value;
}

struct Unk_5c5480 {
    u8 _0[0x120];
    u8 field_120;
};
PKMN_OFFSET_ASSERT(Unk_5c5480, field_120, 0x120);

// 0x71005c5480
u8* Unk_5c5480_getField120Ptr(Unk_5c5480* self) {
    return &self->field_120;
}

struct Unk_5c5490 {
    u8 _0[0x120];
    u8 field_120;
};
PKMN_OFFSET_ASSERT(Unk_5c5490, field_120, 0x120);

// 0x71005c5490
u8* Unk_5c5490_getField120Ptr(Unk_5c5490* self) {
    return &self->field_120;
}

struct Unk_5c54a0 {
    u64 field_0;
    u32 field_8;
    u8 _c[0x34];
    u32 field_40;
    u8 _44[0x1c];
    u64 field_60;
    u32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_5c54a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_5c54a0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_5c54a0, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_5c54a0, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_5c54a0, field_68, 0x68);

// 0x71005c54a0
void Unk_5c54a0_set(Unk_5c54a0* self) {
    self->field_0 = 0;
    self->field_8 = 0;
    self->field_40 = 0;
    self->field_60 = 0;
    self->field_68 = 0;
}

struct Unk_5c5e30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5c5e30, field_0, 0x0);

// 0x71005c5e30
void Unk_5c5e30_setField0(Unk_5c5e30* self, u64 value) {
    self->field_0 = value;
}

// 0x71005c6110
void Unk_5c6110() {}

struct Unk_5c6120_arg1 {
    u8 _0[0x70];
    u64 field_70;
    u64 field_78;
    u64 field_80;
    u64 field_88;
    u64 field_90;
    u64 field_98;
    u32 field_a0;
    u8 _a4[0x4];
    u32 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_5c6120_arg1, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_5c6120_arg1, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_5c6120_arg1, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_5c6120_arg1, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_5c6120_arg1, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_5c6120_arg1, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_5c6120_arg1, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_5c6120_arg1, field_a8, 0xa8);

struct Unk_5c6120 {
    u32 field_0;
    u32 field_4;
    u8 _8[0x8];
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u64 field_30;
    u64 field_38;
};
PKMN_OFFSET_ASSERT(Unk_5c6120, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_5c6120, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_5c6120, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_5c6120, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_5c6120, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_5c6120, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_5c6120, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_5c6120, field_38, 0x38);

// 0x71005c6120
void Unk_5c6120_set(Unk_5c6120* self, const Unk_5c6120_arg1* value) {
    self->field_0 = value->field_a8;
    self->field_4 = value->field_a0;
    self->field_18 = value->field_98;
    self->field_10 = value->field_90;
    self->field_28 = value->field_88;
    self->field_20 = value->field_80;
    self->field_38 = value->field_78;
    self->field_30 = value->field_70;
}

struct Unk_5c6380_arg1 {
    u8 _0[0x70];
    u64 field_70;
    u64 field_78;
    u64 field_80;
    u64 field_88;
    u64 field_90;
    u64 field_98;
    u32 field_a0;
    u8 _a4[0x4];
    u32 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_5c6380_arg1, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_5c6380_arg1, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_5c6380_arg1, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_5c6380_arg1, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_5c6380_arg1, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_5c6380_arg1, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_5c6380_arg1, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_5c6380_arg1, field_a8, 0xa8);

struct Unk_5c6380 {
    u32 field_0;
    u32 field_4;
    u8 _8[0x8];
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u64 field_30;
    u64 field_38;
};
PKMN_OFFSET_ASSERT(Unk_5c6380, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_5c6380, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_5c6380, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_5c6380, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_5c6380, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_5c6380, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_5c6380, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_5c6380, field_38, 0x38);

// 0x71005c6380
void Unk_5c6380_set(const Unk_5c6380* self, Unk_5c6380_arg1* value) {
    value->field_a8 = self->field_0;
    value->field_a0 = self->field_4;
    value->field_98 = self->field_18;
    value->field_90 = self->field_10;
    value->field_88 = self->field_28;
    value->field_80 = self->field_20;
    value->field_78 = self->field_38;
    value->field_70 = self->field_30;
}

struct Unk_5c6450 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5c6450, field_0, 0x0);

// 0x71005c6450
u64 Unk_5c6450_getField0(const Unk_5c6450* self) {
    return self->field_0;
}

struct Unk_5c6930 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_5c6930, field_8, 0x8);

// 0x71005c6930
u8 Unk_5c6930_getField8(const Unk_5c6930* self) {
    return self->field_8;
}

struct Unk_5c83e0 {
    u8 _0[0xa8];
    u64 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_5c83e0, field_a8, 0xa8);

void Unk_5cb430(u64);

// 0x71005c83e0
void Unk_5c83e0_call(const Unk_5c83e0* self) {
    Unk_5cb430(self->field_a8);
}

struct Unk_5c83f0 {
    u8 _0[0xe8];
    u64 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_5c83f0, field_e8, 0xe8);

void Unk_5cb760(u64);

// 0x71005c83f0
void Unk_5c83f0_call(const Unk_5c83f0* self) {
    Unk_5cb760(self->field_e8);
}

// 0x71005cf830
void Unk_5cf830() {}

// 0x71005cf840
u32 Unk_5cf840_get() {
    return 1;
}

struct Unk_5cf940 {
    u8 _0[0x90];
    u32 field_90;
};
PKMN_OFFSET_ASSERT(Unk_5cf940, field_90, 0x90);

// 0x71005cf940
void Unk_5cf940_setField90(Unk_5cf940* self, u32 value) {
    self->field_90 = value;
}
