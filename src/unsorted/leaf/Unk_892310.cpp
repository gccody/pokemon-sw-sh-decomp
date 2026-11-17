// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_892310 {
    u16 field_0;
};
PKMN_OFFSET_ASSERT(Unk_892310, field_0, 0x0);

// 0x7100892310
u16 Unk_892310_getField0(const Unk_892310* self) {
    return self->field_0;
}

struct Unk_892320 {
    u8 _0[0x6];
    u8 field_6;
};
PKMN_OFFSET_ASSERT(Unk_892320, field_6, 0x6);

// 0x7100892320
u8 Unk_892320_getField6(const Unk_892320* self) {
    return self->field_6;
}

struct Unk_892330 {
    u8 _0[0x2];
    u8 field_2;
};
PKMN_OFFSET_ASSERT(Unk_892330, field_2, 0x2);

// 0x7100892330
u8 Unk_892330_getField2(const Unk_892330* self) {
    return self->field_2;
}

struct Unk_892340 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_892340, field_8, 0x8);

// 0x7100892340
u8* Unk_892340_getField8Ptr(Unk_892340* self) {
    return &self->field_8;
}

struct Unk_892350 {
    u8 _0[0x4];
    u16 field_4;
};
PKMN_OFFSET_ASSERT(Unk_892350, field_4, 0x4);

// 0x7100892350
u16 Unk_892350_getField4(const Unk_892350* self) {
    return self->field_4;
}

struct Unk_892380 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_892380, field_8, 0x8);

// 0x7100892380
void Unk_892380_set(Unk_892380* self) {
    self->field_8 = 0x33000000000000;
}

struct Unk_8923d0 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_8923d0, field_8, 0x8);

// 0x71008923d0
u8* Unk_8923d0_getField8Ptr(Unk_8923d0* self) {
    return &self->field_8;
}

struct Unk_892490 {
    u8 _0[0x8];
    u16 field_8;
};
PKMN_OFFSET_ASSERT(Unk_892490, field_8, 0x8);

// 0x7100892490
u16 Unk_892490_getField8(const Unk_892490* self) {
    return self->field_8;
}

struct Unk_8924a0 {
    u8 _0[0xe];
    u8 field_e;
};
PKMN_OFFSET_ASSERT(Unk_8924a0, field_e, 0xe);

// 0x71008924a0
u8 Unk_8924a0_getFielde(const Unk_8924a0* self) {
    return self->field_e;
}

struct Unk_8924b0 {
    u8 _0[0xa];
    u8 field_a;
};
PKMN_OFFSET_ASSERT(Unk_8924b0, field_a, 0xa);

// 0x71008924b0
u8 Unk_8924b0_getFielda(const Unk_8924b0* self) {
    return self->field_a;
}

struct Unk_8924c0 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_8924c0, field_10, 0x10);

// 0x71008924c0
u8* Unk_8924c0_getField10Ptr(Unk_8924c0* self) {
    return &self->field_10;
}

struct Unk_8924d0 {
    u8 _0[0xc];
    u16 field_c;
};
PKMN_OFFSET_ASSERT(Unk_8924d0, field_c, 0xc);

// 0x71008924d0
u16 Unk_8924d0_getFieldc(const Unk_8924d0* self) {
    return self->field_c;
}

struct Unk_8924e0 {
    u8 _0[0xc];
    u16 field_c;
};
PKMN_OFFSET_ASSERT(Unk_8924e0, field_c, 0xc);

// 0x71008924e0
u32 Unk_8924e0_get(const Unk_8924e0* self) {
    return self->field_c + 8;
}

struct Unk_8925a0 {
    u8 _0[0x84];
    u8 field_84;
};
PKMN_OFFSET_ASSERT(Unk_8925a0, field_84, 0x84);

// 0x71008925a0
u8 Unk_8925a0_getField84(const Unk_8925a0* self) {
    return self->field_84;
}

struct Unk_8925b0 {
    u8 _0[0x83];
    u8 field_83;
};
PKMN_OFFSET_ASSERT(Unk_8925b0, field_83, 0x83);

// 0x71008925b0
u8 Unk_8925b0_getField83(const Unk_8925b0* self) {
    return self->field_83;
}

struct Unk_8925c0 {
    u8 _0[0x48];
    u8 field_48;
};
PKMN_OFFSET_ASSERT(Unk_8925c0, field_48, 0x48);

// 0x71008925c0
void Unk_8925c0_setField48(Unk_8925c0* self, u8 value) {
    self->field_48 = value;
}

struct Unk_892b10 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_892b10, field_0, 0x0);

// 0x7100892b10
void Unk_892b10_clearField0(Unk_892b10* self) {
    self->field_0 = 0;
}

// 0x7100892b20
void Unk_892b20() {}

struct Unk_892bb0_arg1 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_892bb0_arg1, field_0, 0x0);

// 0x7100892bb0
u32 Unk_892bb0_get(void* /*unused*/, const Unk_892bb0_arg1* value) {
    return value->field_0 & 0x7f;
}

struct Unk_892bd0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_892bd0, field_0, 0x0);

// 0x7100892bd0
void Unk_892bd0_clearField0(Unk_892bd0* self) {
    self->field_0 = 0;
}

// 0x7100892be0
void Unk_892be0() {}

struct Unk_8944f0 {
    u8 _0[0x358];
    u64 field_358;
};
PKMN_OFFSET_ASSERT(Unk_8944f0, field_358, 0x358);

// 0x71008944f0
void Unk_8944f0_clearField358(Unk_8944f0* self) {
    self->field_358 = 0;
}

struct Unk_894500 {
    u8 _0[0x141];
    u8 field_141;
};
PKMN_OFFSET_ASSERT(Unk_894500, field_141, 0x141);

// 0x7100894500
u8 Unk_894500_getField141(const Unk_894500* self) {
    return self->field_141;
}

struct Unk_894f90 {
    u8 _0[0x211];
    u8 field_211;
};
PKMN_OFFSET_ASSERT(Unk_894f90, field_211, 0x211);

// 0x7100894f90
bool Unk_894f90_check(const Unk_894f90* self) {
    return self->field_211 != 5;
}

struct Unk_894fd0 {
    u8 _0[0x211];
    u8 field_211;
};
PKMN_OFFSET_ASSERT(Unk_894fd0, field_211, 0x211);

// 0x7100894fd0
u32 Unk_894fd0_get(const Unk_894fd0* self) {
    return self->field_211 == 5 ? 0x6e : self->field_211;
}

struct Unk_8954a0 {
    u8 _0[0x3b8];
    u64 field_3b8;
};
PKMN_OFFSET_ASSERT(Unk_8954a0, field_3b8, 0x3b8);

void Unk_8a7000(u64);

// 0x71008954a0
void Unk_8954a0_call(const Unk_8954a0* self) {
    Unk_8a7000(self->field_3b8);
}

struct Unk_895540 {
    u8 _0[0x234];
    u8 field_234;
};
PKMN_OFFSET_ASSERT(Unk_895540, field_234, 0x234);

// 0x7100895540
u8 Unk_895540_getField234(const Unk_895540* self) {
    return self->field_234;
}

struct Unk_895550 {
    u8 _0[0x220];
    u8 field_220;
};
PKMN_OFFSET_ASSERT(Unk_895550, field_220, 0x220);

// 0x7100895550
u8* Unk_895550_getField220Ptr(Unk_895550* self) {
    return &self->field_220;
}

extern u32 Unk_27d1040;

// 0x7100896170
void Unk_896170_set() {
    Unk_27d1040 = Unk_27d1040 + 1;
}

struct Unk_896c60 {
    u8 _0[0x360];
    u64 field_360;
};
PKMN_OFFSET_ASSERT(Unk_896c60, field_360, 0x360);

// 0x7100896c60
void Unk_896c60_clearField360(Unk_896c60* self) {
    self->field_360 = 0;
}

struct Unk_898b40 {
    u8 _0[0x3b0];
    u32 field_3b0;
};
PKMN_OFFSET_ASSERT(Unk_898b40, field_3b0, 0x3b0);

// 0x7100898b40
void Unk_898b40_setField3b0(Unk_898b40* self, u32 value) {
    self->field_3b0 = value;
}
