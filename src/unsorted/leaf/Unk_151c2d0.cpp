// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_151c2d0 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_151c2d0, field_60, 0x60);

// 0x710151c2d0
u64 Unk_151c2d0_getField60(const Unk_151c2d0* self) {
    return self->field_60;
}

struct Unk_151c2e0 {
    u8 _0[0x70];
    u32 field_70;
};
PKMN_OFFSET_ASSERT(Unk_151c2e0, field_70, 0x70);

// 0x710151c2e0
u32 Unk_151c2e0_getField70(const Unk_151c2e0* self) {
    return self->field_70;
}

struct Unk_151c2f0 {
    u8 _0[0x6c];
    u32 field_6c;
};
PKMN_OFFSET_ASSERT(Unk_151c2f0, field_6c, 0x6c);

// 0x710151c2f0
void Unk_151c2f0_setField6c(Unk_151c2f0* self, u32 value) {
    self->field_6c = value;
}

struct Unk_151c300 {
    u8 _0[0x74];
    u32 field_74;
};
PKMN_OFFSET_ASSERT(Unk_151c300, field_74, 0x74);

// 0x710151c300
u32 Unk_151c300_getField74(const Unk_151c300* self) {
    return self->field_74;
}

struct Unk_151c310 {
    u8 _0[0x7c];
    u32 field_7c;
};
PKMN_OFFSET_ASSERT(Unk_151c310, field_7c, 0x7c);

// 0x710151c310
u32 Unk_151c310_getField7c(const Unk_151c310* self) {
    return self->field_7c;
}

struct Unk_151c320 {
    u8 _0[0x7c];
    u32 field_7c;
};
PKMN_OFFSET_ASSERT(Unk_151c320, field_7c, 0x7c);

// 0x710151c320
void Unk_151c320_setField7c(Unk_151c320* self, u32 value) {
    self->field_7c = value;
}

struct Unk_151c330 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_151c330, field_78, 0x78);

// 0x710151c330
u32 Unk_151c330_getField78(const Unk_151c330* self) {
    return self->field_78;
}

struct Unk_151c340 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_151c340, field_78, 0x78);

// 0x710151c340
void Unk_151c340_setField78(Unk_151c340* self, u32 value) {
    self->field_78 = value;
}

struct Unk_151c350 {
    u8 _0[0x74];
    u32 field_74;
    u32 field_78;
    u32 field_7c;
};
PKMN_OFFSET_ASSERT(Unk_151c350, field_74, 0x74);
PKMN_OFFSET_ASSERT(Unk_151c350, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_151c350, field_7c, 0x7c);

// 0x710151c350
void Unk_151c350_set(Unk_151c350* self) {
    self->field_7c = self->field_74;
    self->field_74 = self->field_78;
}

struct Unk_151ca40 {
    u8 _0[0xa8];
    u8 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_151ca40, field_a8, 0xa8);

// 0x710151ca40
u8* Unk_151ca40_getFielda8Ptr(Unk_151ca40* self) {
    return &self->field_a8;
}

struct Unk_151cd10 {
    u8 _0[0x6e8];
    u64 field_6e8;
};
PKMN_OFFSET_ASSERT(Unk_151cd10, field_6e8, 0x6e8);

void Unk_1503210(u64);

// 0x710151cd10
void Unk_151cd10_call(const Unk_151cd10* self) {
    Unk_1503210(self->field_6e8);
}

struct Unk_151cf70 {
    u8 _0[0x70c];
    u32 field_70c;
};
PKMN_OFFSET_ASSERT(Unk_151cf70, field_70c, 0x70c);

// 0x710151cf70
u32 Unk_151cf70_getField70c(const Unk_151cf70* self) {
    return self->field_70c;
}

struct Unk_151d560 {
    u8 _0[0x738];
    u64 field_738;
};
PKMN_OFFSET_ASSERT(Unk_151d560, field_738, 0x738);

void Unk_151a410(u64);

// 0x710151d560
void Unk_151d560_call(const Unk_151d560* self) {
    Unk_151a410(self->field_738);
}

struct Unk_151d580 {
    u8 _0[0x740];
    u32 field_740;
};
PKMN_OFFSET_ASSERT(Unk_151d580, field_740, 0x740);

// 0x710151d580
void Unk_151d580_setField740(Unk_151d580* self, u32 value) {
    self->field_740 = value;
}

struct Unk_151d590 {
    u8 _0[0x740];
    u32 field_740;
};
PKMN_OFFSET_ASSERT(Unk_151d590, field_740, 0x740);

// 0x710151d590
u32 Unk_151d590_getField740(const Unk_151d590* self) {
    return self->field_740;
}

struct Unk_151d5a0 {
    u8 _0[0xa5c];
    bool field_a5c;
};
PKMN_OFFSET_ASSERT(Unk_151d5a0, field_a5c, 0xa5c);

// 0x710151d5a0
void Unk_151d5a0_set(Unk_151d5a0* self, bool value) {
    self->field_a5c = value;
}

struct Unk_151d5b0 {
    u8 _0[0xa5c];
    u8 field_a5c;
};
PKMN_OFFSET_ASSERT(Unk_151d5b0, field_a5c, 0xa5c);

// 0x710151d5b0
u8 Unk_151d5b0_getFielda5c(const Unk_151d5b0* self) {
    return self->field_a5c;
}

struct Unk_151d5c0 {
    u8 _0[0xc20];
    u16 field_c20;
};
PKMN_OFFSET_ASSERT(Unk_151d5c0, field_c20, 0xc20);

// 0x710151d5c0
bool Unk_151d5c0_check(const Unk_151d5c0* self) {
    return self->field_c20 > 7;
}

struct Unk_151e0d0 {
    u8 _0[0x780];
    u64 field_780;
};
PKMN_OFFSET_ASSERT(Unk_151e0d0, field_780, 0x780);

// 0x710151e0d0
void Unk_151e0d0_setField780(Unk_151e0d0* self, u64 value) {
    self->field_780 = value;
}

struct Unk_15247d0 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_15247d0, field_5cc, 0x5cc);

// 0x71015247d0
void Unk_15247d0_clearField5cc(Unk_15247d0* self) {
    self->field_5cc = 0;
}

void Unk_eb6230(void*, u32);

// 0x71015248c0
void Unk_15248c0_call(void* self) {
    Unk_eb6230(self, 3);
}

struct Unk_15248f0 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_15248f0, field_5cc, 0x5cc);

// 0x71015248f0
u32 Unk_15248f0_getField5cc(const Unk_15248f0* self) {
    return self->field_5cc;
}

struct Unk_1524900 {
    u8 _0[0xa10];
    u64 field_a10;
};
PKMN_OFFSET_ASSERT(Unk_1524900, field_a10, 0xa10);

// 0x7101524900
void Unk_1524900_setFielda10(Unk_1524900* self, u64 value) {
    self->field_a10 = value;
}

struct Unk_1525130 {
    u8 _0[0x5d8];
    u64 field_5d8;
};
PKMN_OFFSET_ASSERT(Unk_1525130, field_5d8, 0x5d8);

// 0x7101525130
u64 Unk_1525130_getField5d8(const Unk_1525130* self) {
    return self->field_5d8;
}

struct Unk_1525940 {
    u8 _0[0x5d4];
    u32 field_5d4;
};
PKMN_OFFSET_ASSERT(Unk_1525940, field_5d4, 0x5d4);

// 0x7101525940
u32 Unk_1525940_getField5d4(const Unk_1525940* self) {
    return self->field_5d4;
}

struct Unk_1527bd0 {
    u8 _0[0xa18];
    u64 field_a18;
    u32 field_a20;
};
PKMN_OFFSET_ASSERT(Unk_1527bd0, field_a18, 0xa18);
PKMN_OFFSET_ASSERT(Unk_1527bd0, field_a20, 0xa20);

// 0x7101527bd0
void Unk_1527bd0_set(Unk_1527bd0* self, u64 value, u32 arg2) {
    self->field_a18 = value;
    self->field_a20 = arg2;
}

struct Unk_1527be0 {
    u8 _0[0xa24];
    bool field_a24;
};
PKMN_OFFSET_ASSERT(Unk_1527be0, field_a24, 0xa24);

// 0x7101527be0
void Unk_1527be0_set(Unk_1527be0* self, bool value) {
    self->field_a24 = value;
}

void Unk_eb6230(void*, u32);

// 0x7101528890
void Unk_1528890_call(void* self) {
    Unk_eb6230(self, 2);
}

void Unk_eb6230(void*, u32);

// 0x71015288a0
void Unk_15288a0_call(void* self) {
    Unk_eb6230(self, 3);
}

struct Unk_15288d0 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_15288d0, field_5cc, 0x5cc);

// 0x71015288d0
u32 Unk_15288d0_getField5cc(const Unk_15288d0* self) {
    return self->field_5cc;
}

struct Unk_1529670 {
    u8 _0[0x5d0];
    u8 field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_1529670, field_5d0, 0x5d0);

// 0x7101529670
u8* Unk_1529670_getField5d0Ptr(Unk_1529670* self) {
    return &self->field_5d0;
}

void Unk_eb6230(void*, u32);

// 0x710152a790
void Unk_152a790_call(void* self) {
    Unk_eb6230(self, 3);
}

struct Unk_152c1b0 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_152c1b0, field_5cc, 0x5cc);

// 0x710152c1b0
void Unk_152c1b0_clearField5cc(Unk_152c1b0* self) {
    self->field_5cc = 0;
}

void Unk_eb6230(void*, u32);

// 0x710152c2a0
void Unk_152c2a0_call(void* self) {
    Unk_eb6230(self, 3);
}

struct Unk_152c2d0 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_152c2d0, field_5cc, 0x5cc);

// 0x710152c2d0
u32 Unk_152c2d0_getField5cc(const Unk_152c2d0* self) {
    return self->field_5cc;
}

struct Unk_152c2e0 {
    u8 _0[0x5d0];
    u64 field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_152c2e0, field_5d0, 0x5d0);

void Unk_152c2f0();

// 0x710152c2e0
void Unk_152c2e0_call(Unk_152c2e0* self, u64 value) {
    self->field_5d0 = value;
    Unk_152c2f0();
}

struct Unk_152e630 {
    u8 _0[0x5cc];
    u32 field_5cc;
    u8 _5d0[0x1c];
    u32 field_5ec;
    u8 field_5f0;
};
PKMN_OFFSET_ASSERT(Unk_152e630, field_5cc, 0x5cc);
PKMN_OFFSET_ASSERT(Unk_152e630, field_5ec, 0x5ec);
PKMN_OFFSET_ASSERT(Unk_152e630, field_5f0, 0x5f0);

// 0x710152e630
void Unk_152e630_set(Unk_152e630* self, u32 value) {
    self->field_5ec = value;
    self->field_5f0 = 0;
    self->field_5cc = 5;
}

// 0x710152fd80
void Unk_152fd80_update() {}

struct Unk_152fd90 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_152fd90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_152fd90, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_152fd90, field_10, 0x10);

// 0x710152fd90
void Unk_152fd90_set(const Unk_152fd90* self, Unk_152fd90* value) {
    *value = *self;
}

struct Unk_152fdb0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_152fdb0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_152fdb0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_152fdb0, field_10, 0x10);

// 0x710152fdb0
void Unk_152fdb0_set(const Unk_152fdb0* self, Unk_152fdb0* value) {
    *value = *self;
}

// 0x710152fdf0
void Unk_152fdf0_update() {}

struct Unk_152fe00 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_152fe00, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_152fe00, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_152fe00, field_10, 0x10);

// 0x710152fe00
void Unk_152fe00_set(const Unk_152fe00* self, Unk_152fe00* value) {
    *value = *self;
}

struct Unk_152fe20 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_152fe20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_152fe20, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_152fe20, field_10, 0x10);

// 0x710152fe20
void Unk_152fe20_set(const Unk_152fe20* self, Unk_152fe20* value) {
    *value = *self;
}

struct Unk_15317e0 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_15317e0, field_5cc, 0x5cc);

// 0x71015317e0
void Unk_15317e0_clearField5cc(Unk_15317e0* self) {
    self->field_5cc = 0;
}

void Unk_eb6230(void*, u32);

// 0x71015318d0
void Unk_15318d0_call(void* self) {
    Unk_eb6230(self, 3);
}

struct Unk_1531900 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_1531900, field_5cc, 0x5cc);

// 0x7101531900
u32 Unk_1531900_getField5cc(const Unk_1531900* self) {
    return self->field_5cc;
}

struct Unk_1531910 {
    u8 _0[0x5d4];
    u32 field_5d4;
    u64 field_5d8;
};
PKMN_OFFSET_ASSERT(Unk_1531910, field_5d4, 0x5d4);
PKMN_OFFSET_ASSERT(Unk_1531910, field_5d8, 0x5d8);

// 0x7101531910
void Unk_1531910_set(Unk_1531910* self, u32 value, u64 arg2) {
    self->field_5d4 = value;
    self->field_5d8 = arg2;
}

struct Unk_1532790 {
    u8 _0[0x5f8];
    u8 field_5f8;
};
PKMN_OFFSET_ASSERT(Unk_1532790, field_5f8, 0x5f8);

// 0x7101532790
u8 Unk_1532790_getField5f8(const Unk_1532790* self) {
    return self->field_5f8;
}

struct Unk_15327a0 {
    u8 _0[0x5d8];
    u64 field_5d8;
};
PKMN_OFFSET_ASSERT(Unk_15327a0, field_5d8, 0x5d8);

// 0x71015327a0
u64 Unk_15327a0_getField5d8(const Unk_15327a0* self) {
    return self->field_5d8;
}

// 0x7101536ab0
void Unk_1536ab0_update() {}

struct Unk_1536ac0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1536ac0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1536ac0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1536ac0, field_10, 0x10);

// 0x7101536ac0
void Unk_1536ac0_set(const Unk_1536ac0* self, Unk_1536ac0* value) {
    *value = *self;
}

struct Unk_1536ae0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1536ae0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1536ae0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1536ae0, field_10, 0x10);

// 0x7101536ae0
void Unk_1536ae0_set(const Unk_1536ae0* self, Unk_1536ae0* value) {
    *value = *self;
}

// 0x7101536b20
void Unk_1536b20_update() {}

struct Unk_1536b30 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1536b30, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1536b30, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1536b30, field_10, 0x10);

// 0x7101536b30
void Unk_1536b30_set(const Unk_1536b30* self, Unk_1536b30* value) {
    *value = *self;
}

struct Unk_1536b50 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1536b50, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1536b50, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1536b50, field_10, 0x10);

// 0x7101536b50
void Unk_1536b50_set(const Unk_1536b50* self, Unk_1536b50* value) {
    *value = *self;
}
