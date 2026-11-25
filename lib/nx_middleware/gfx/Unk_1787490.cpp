// Scope: common
// NintendoSDK_gfx 7.3.2 for NVN: the info structs' functions that set their
// defaults. Neither the structs nor their fields are named in the executable:
// placeholders (gfx.h).
#include <types.h>

// A byte of flags, then six bytes and a mask (0xf: every channel).
struct Unk_1787490_Info {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u8 field_4;
    u8 field_5;
    u8 field_6;
    u8 field_7;
};
PKMN_SIZE_ASSERT(Unk_1787490_Info, 0x8);

// 0x7101787490
void Unk_1787490(Unk_1787490_Info* self) {
    self->field_0 &= ~1;
    self->field_1 = 1;
    self->field_2 = 0;
    self->field_3 = 0;
    self->field_4 = 1;
    self->field_5 = 0;
    self->field_6 = 0;
    self->field_7 = 0xf;
}

struct Unk_17874c0_Info {
    u8 field_0;
    u8 field_1;
    u16 field_2;
    u32 field_4;
    u32 field_8;
    f32 field_c;
    f32 field_10;
    u8 _14[0x4];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_17874c0_Info, field_2, 0x2);
PKMN_OFFSET_ASSERT(Unk_17874c0_Info, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_17874c0_Info, field_18, 0x18);

// 0x71017874c0
void Unk_17874c0(Unk_17874c0_Info* self) {
    self->field_2 &= ~0xf;
    self->field_4 = 0;
    self->field_8 = 0;
    self->field_c = 0.0f;
    self->field_10 = 1.0f;
    self->field_18 = 0;
    self->field_0 = 0;
    self->field_1 = 5;
}

// Two of them in Unk_1787500_Info (their defaults: Unk_17874f0_set).
struct Unk_1787500_Stencil {
    u32 field_0;
    u8 field_4;
    u8 _5[0xb];
};
PKMN_SIZE_ASSERT(Unk_1787500_Stencil, 0x10);

struct Unk_1787500_Info {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 _3[0x1];
    u16 field_4;
    u8 _6[0x2];
    Unk_1787500_Stencil field_8;
    Unk_1787500_Stencil field_18;
};
PKMN_OFFSET_ASSERT(Unk_1787500_Info, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_1787500_Info, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1787500_Info, field_18, 0x18);

// 0x7101787500
void Unk_1787500(Unk_1787500_Info* self) {
    self->field_0 = 1;
    self->field_1 = 0xff;
    self->field_2 = 0xff;
    self->field_4 &= ~0xf;
    self->field_8.field_0 = 0x7000000;
    self->field_8.field_4 = 0;
    self->field_18.field_0 = 0x7000000;
    self->field_18.field_4 = 0;
}

struct Unk_1787540_Info {
    u8 field_0;
    u8 _1[0x1];
    u16 field_2;
    u16 field_4;
    u8 _6[0x2];
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1787540_Info, field_2, 0x2);
PKMN_OFFSET_ASSERT(Unk_1787540_Info, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1787540_Info, field_10, 0x10);

// 0x7101787540
void Unk_1787540(Unk_1787540_Info* self) {
    self->field_0 = 0;
    self->field_2 = 0xffff;
    self->field_4 = 0;
    self->field_8 = 0;
    self->field_10 = 0;
}

struct Unk_17875a0_Info {
    u8 field_0;
    u8 _1[0x1];
    u16 field_2;
    u16 field_4;
    u8 _6[0x2];
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_17875a0_Info, field_2, 0x2);
PKMN_OFFSET_ASSERT(Unk_17875a0_Info, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_17875a0_Info, field_10, 0x10);

// 0x71017875a0
void Unk_17875a0(Unk_17875a0_Info* self) {
    self->field_0 &= ~1;
    self->field_2 = 0;
    self->field_4 = 0;
    self->field_8 = 0;
    self->field_10 = 0;
}

struct Unk_17875c0_Info {
    u8 field_0;
    u8 _1[0x3];
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u8 _10[0x8];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_17875c0_Info, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_17875c0_Info, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_17875c0_Info, field_18, 0x18);

// 0x71017875c0
void Unk_17875c0(Unk_17875c0_Info* self) {
    self->field_0 = 2;
    self->field_4 = 0xb01;
    self->field_8 = 0x500;
    self->field_c = 0x2d0;
    self->field_18 = 0;
}

struct Unk_1787610_Info {
    u8 _0[0x1];
    u8 field_1;
    u16 field_2;
    u16 field_4;
    u16 field_6;
    u16 field_8;
    u8 _a[0x2];
    u32 field_c;
    u32 field_10;
    u32 field_14;
    u32 field_18;
    u32 field_1c;
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_1787610_Info, field_2, 0x2);
PKMN_OFFSET_ASSERT(Unk_1787610_Info, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_1787610_Info, field_20, 0x20);

// 0x7101787610
void Unk_1787610(Unk_1787610_Info* self) {
    self->field_1 = 2;
    self->field_2 = 0;
    self->field_4 = 0;
    self->field_6 = 1;
    self->field_8 = 1;
    self->field_c = 0;
    self->field_10 = 0;
    self->field_14 = 1;
    self->field_18 = 1;
    self->field_1c = 1;
    self->field_20 = 0;
}

struct Unk_1787640_Info {
    u8 field_0;
    u8 field_1;
    u8 _2[0x2];
    u32 field_4;
    u8 field_8;
    u8 field_9;
    u8 field_a;
    u8 field_b;
    u8 _c[0x4];
    u32 field_10;
    u8 _14[0xc];
    u32 field_20;
    u32 field_24;
    u8 _28[0x8];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_1787640_Info, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_1787640_Info, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_1787640_Info, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_1787640_Info, field_30, 0x30);

// 0x7101787640
void Unk_1787640(Unk_1787640_Info* self) {
    self->field_0 = 1;
    self->field_1 = 0;
    self->field_4 = 0;
    self->field_8 = 2;
    self->field_9 = 3;
    self->field_a = 4;
    self->field_b = 5;
    self->field_10 = 0x10000;
    self->field_20 = 0;
    self->field_24 = 1;
    self->field_30 = 0;
}

struct Unk_1787670_Info {
    u8 field_0;
    u8 _1[0x1];
    u16 field_2;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u8 _10[0x8];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1787670_Info, field_2, 0x2);
PKMN_OFFSET_ASSERT(Unk_1787670_Info, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_1787670_Info, field_18, 0x18);

// 0x7101787670
void Unk_1787670(Unk_1787670_Info* self) {
    self->field_0 = 1;
    self->field_4 = 0;
    self->field_8 = 0;
    self->field_2 = 0;
    self->field_c = 1;
    self->field_18 = 0;
}
