// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_ffa4b0 {
    u8 _0[0x70];
    u32 field_70;
    u32 field_74;
};
PKMN_OFFSET_ASSERT(Unk_ffa4b0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_ffa4b0, field_74, 0x74);

// 0x7100ffa4b0
void Unk_ffa4b0_set(Unk_ffa4b0* self, u32 value, u32 arg2) {
    self->field_70 = value;
    self->field_74 = arg2;
}

struct Unk_ffa4c0 {
    u8 _0[0x70];
    u32 field_70;
};
PKMN_OFFSET_ASSERT(Unk_ffa4c0, field_70, 0x70);

// 0x7100ffa4c0
u32 Unk_ffa4c0_getField70(const Unk_ffa4c0* self) {
    return self->field_70;
}

struct Unk_ffa4d0 {
    u8 _0[0x74];
    u32 field_74;
};
PKMN_OFFSET_ASSERT(Unk_ffa4d0, field_74, 0x74);

// 0x7100ffa4d0
u32 Unk_ffa4d0_getField74(const Unk_ffa4d0* self) {
    return self->field_74;
}

struct Unk_ffa640 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_ffa640, field_78, 0x78);

// 0x7100ffa640
bool Unk_ffa640_check(const Unk_ffa640* self) {
    return (self->field_78 | 1) == 9;
}

struct Unk_ffc570 {
    u8 _0[0xa0];
    u8 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_ffc570, field_a0, 0xa0);

// 0x7100ffc570
u8 Unk_ffc570_getFielda0(const Unk_ffc570* self) {
    return self->field_a0;
}

struct Unk_ffd310 {
    u8 _0[0x108];
    u8 field_108;
};
PKMN_OFFSET_ASSERT(Unk_ffd310, field_108, 0x108);

// 0x7100ffd310
bool Unk_ffd310_check(const Unk_ffd310* self) {
    return self->field_108 != 0;
}

struct Unk_ffd7b0 {
    u8 _0[0x110];
    u64 field_110;
};
PKMN_OFFSET_ASSERT(Unk_ffd7b0, field_110, 0x110);

// 0x7100ffd7b0
bool Unk_ffd7b0_check(const Unk_ffd7b0* self) {
    return self->field_110 != 0;
}

struct Unk_ffd7c0 {
    u8 _0[0x110];
    u64 field_110;
};
PKMN_OFFSET_ASSERT(Unk_ffd7c0, field_110, 0x110);

// 0x7100ffd7c0
u64 Unk_ffd7c0_getField110(const Unk_ffd7c0* self) {
    return self->field_110;
}

struct Unk_ffd7d0 {
    u8 _0[0x110];
    u64 field_110;
};
PKMN_OFFSET_ASSERT(Unk_ffd7d0, field_110, 0x110);

// 0x7100ffd7d0
void Unk_ffd7d0_clearField110(Unk_ffd7d0* self) {
    self->field_110 = 0;
}

struct Unk_ffd7e0 {
    u8 _0[0xa8];
    u64 field_a8;
    u8 _b0[0x60];
    u64 field_110;
};
PKMN_OFFSET_ASSERT(Unk_ffd7e0, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_ffd7e0, field_110, 0x110);

// 0x7100ffd7e0
bool Unk_ffd7e0_check(const Unk_ffd7e0* self) {
    if (self->field_110 == 0) {
        return false;
    }
    return self->field_110 == self->field_a8;
}

struct Unk_ffe0f0 {
    u8 _0[0x120];
    u8 field_120;
};
PKMN_OFFSET_ASSERT(Unk_ffe0f0, field_120, 0x120);

// 0x7100ffe0f0
void Unk_ffe0f0_clearField120(Unk_ffe0f0* self) {
    self->field_120 = 0;
}

struct Unk_ffe100 {
    u8 _0[0x120];
    u8 field_120;
};
PKMN_OFFSET_ASSERT(Unk_ffe100, field_120, 0x120);

// 0x7100ffe100
bool Unk_ffe100_check(const Unk_ffe100* self) {
    return self->field_120 != 0;
}

struct Unk_ffe110 {
    u8 _0[0x138];
    u64 field_138;
};
PKMN_OFFSET_ASSERT(Unk_ffe110, field_138, 0x138);

void Unk_8e0670(u64);

// 0x7100ffe110
void Unk_ffe110_call(const Unk_ffe110* self) {
    if (self->field_138 != 0) {
        Unk_8e0670(self->field_138);
    }
}

struct Unk_ffe190 {
    u8 _0[0x120];
    u8 field_120;
};
PKMN_OFFSET_ASSERT(Unk_ffe190, field_120, 0x120);

// 0x7100ffe190
u8 Unk_ffe190_getField120(const Unk_ffe190* self) {
    return self->field_120;
}

struct Unk_ffe4d0_88 {
    u8 _0[0x84];
    u16 field_84;
};
PKMN_OFFSET_ASSERT(Unk_ffe4d0_88, field_84, 0x84);

struct Unk_ffe4d0 {
    u8 _0[0x88];
    Unk_ffe4d0_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_ffe4d0, field_88, 0x88);

// 0x7100ffe4d0
bool Unk_ffe4d0_check(const Unk_ffe4d0* self) {
    return self->field_88->field_84 == 3;
}

struct Unk_ffe4f0 {
    u8 _0[0x148];
    u8 field_148;
};
PKMN_OFFSET_ASSERT(Unk_ffe4f0, field_148, 0x148);

// 0x7100ffe4f0
u8 Unk_ffe4f0_getField148(const Unk_ffe4f0* self) {
    return self->field_148;
}

struct Unk_fff170 {
    u8 _0[0x158];
    u8 field_158;
};
PKMN_OFFSET_ASSERT(Unk_fff170, field_158, 0x158);

// 0x7100fff170
u8 Unk_fff170_getField158(const Unk_fff170* self) {
    return self->field_158;
}

struct Unk_fff710_88 {
    u8 _0[0x84];
    u16 field_84;
};
PKMN_OFFSET_ASSERT(Unk_fff710_88, field_84, 0x84);

struct Unk_fff710 {
    u8 _0[0x88];
    Unk_fff710_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_fff710, field_88, 0x88);

// 0x7100fff710
bool Unk_fff710_check(const Unk_fff710* self) {
    return self->field_88->field_84 == 4;
}

struct Unk_fff730 {
    u8 _0[0x270];
    u8 field_270;
};
PKMN_OFFSET_ASSERT(Unk_fff730, field_270, 0x270);

// 0x7100fff730
u8 Unk_fff730_getField270(const Unk_fff730* self) {
    return self->field_270;
}

struct Unk_fffca0 {
    u8 _0[0x278];
    u64 field_278;
    u8 field_280;
    u8 _281[0x7];
    u64 field_288;
    u8 field_290;
    u8 _291[0x7];
    u64 field_298;
    u8 field_2a0;
    u8 _2a1[0x7];
    u64 field_2a8;
    u8 field_2b0;
    u8 _2b1[0x7];
    u64 field_2b8;
    u8 field_2c0;
    u8 _2c1[0x7];
    u64 field_2c8;
    u8 field_2d0;
    u8 _2d1[0x7];
    u64 field_2d8;
    u8 field_2e0;
    u8 _2e1[0x7];
    u64 field_2e8;
    u8 field_2f0;
};
PKMN_OFFSET_ASSERT(Unk_fffca0, field_278, 0x278);
PKMN_OFFSET_ASSERT(Unk_fffca0, field_280, 0x280);
PKMN_OFFSET_ASSERT(Unk_fffca0, field_288, 0x288);
PKMN_OFFSET_ASSERT(Unk_fffca0, field_290, 0x290);
PKMN_OFFSET_ASSERT(Unk_fffca0, field_298, 0x298);
PKMN_OFFSET_ASSERT(Unk_fffca0, field_2a0, 0x2a0);
PKMN_OFFSET_ASSERT(Unk_fffca0, field_2a8, 0x2a8);
PKMN_OFFSET_ASSERT(Unk_fffca0, field_2b0, 0x2b0);
PKMN_OFFSET_ASSERT(Unk_fffca0, field_2b8, 0x2b8);
PKMN_OFFSET_ASSERT(Unk_fffca0, field_2c0, 0x2c0);
PKMN_OFFSET_ASSERT(Unk_fffca0, field_2c8, 0x2c8);
PKMN_OFFSET_ASSERT(Unk_fffca0, field_2d0, 0x2d0);
PKMN_OFFSET_ASSERT(Unk_fffca0, field_2d8, 0x2d8);
PKMN_OFFSET_ASSERT(Unk_fffca0, field_2e0, 0x2e0);
PKMN_OFFSET_ASSERT(Unk_fffca0, field_2e8, 0x2e8);
PKMN_OFFSET_ASSERT(Unk_fffca0, field_2f0, 0x2f0);

// 0x7100fffca0
void Unk_fffca0_set(Unk_fffca0* self) {
    self->field_278 = 0;
    self->field_280 = 0;
    self->field_288 = 0;
    self->field_290 = 0;
    self->field_298 = 0;
    self->field_2a0 = 0;
    self->field_2a8 = 0;
    self->field_2b0 = 0;
    self->field_2b8 = 0;
    self->field_2c0 = 0;
    self->field_2c8 = 0;
    self->field_2d0 = 0;
    self->field_2d8 = 0;
    self->field_2e0 = 0;
    self->field_2e8 = 0;
    self->field_2f0 = 0;
}

struct Unk_1000280_88 {
    u8 _0[0x84];
    u16 field_84;
};
PKMN_OFFSET_ASSERT(Unk_1000280_88, field_84, 0x84);

struct Unk_1000280 {
    u8 _0[0x88];
    Unk_1000280_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_1000280, field_88, 0x88);

// 0x7101000280
bool Unk_1000280_check(const Unk_1000280* self) {
    return self->field_88->field_84 == 5;
}

struct Unk_1001130 {
    u8 _0[0x360];
    u8 field_360;
};
PKMN_OFFSET_ASSERT(Unk_1001130, field_360, 0x360);

// 0x7101001130
u8 Unk_1001130_getField360(const Unk_1001130* self) {
    return self->field_360;
}

struct Unk_1001170 {
    u8 _0[0x348];
    u8 field_348;
};
PKMN_OFFSET_ASSERT(Unk_1001170, field_348, 0x348);

// 0x7101001170
void Unk_1001170_set(Unk_1001170* self) {
    self->field_348 = 1;
}

struct Unk_10014b0_88 {
    u8 _0[0x84];
    u16 field_84;
};
PKMN_OFFSET_ASSERT(Unk_10014b0_88, field_84, 0x84);

struct Unk_10014b0 {
    u8 _0[0x88];
    Unk_10014b0_88* field_88;
};
PKMN_OFFSET_ASSERT(Unk_10014b0, field_88, 0x88);

// 0x71010014b0
bool Unk_10014b0_check(const Unk_10014b0* self) {
    return self->field_88->field_84 == 6;
}

struct Unk_10014d0 {
    u8 _0[0x348];
    u8 field_348;
};
PKMN_OFFSET_ASSERT(Unk_10014d0, field_348, 0x348);

// 0x71010014d0
u8 Unk_10014d0_getField348(const Unk_10014d0* self) {
    return self->field_348;
}

// 0x7101005800
void Unk_1005800_update() {}

struct Unk_1005810 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1005810, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1005810, field_8, 0x8);

// 0x7101005810
void Unk_1005810_set(const Unk_1005810* self, Unk_1005810* value) {
    *value = *self;
}

struct Unk_1005820 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1005820, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1005820, field_8, 0x8);

// 0x7101005820
void Unk_1005820_set(const Unk_1005820* self, Unk_1005820* value) {
    *value = *self;
}

// 0x71010058b0
void Unk_10058b0_update() {}

struct Unk_10058c0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_10058c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10058c0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_10058c0, field_10, 0x10);

// 0x71010058c0
void Unk_10058c0_set(const Unk_10058c0* self, Unk_10058c0* value) {
    *value = *self;
}

struct Unk_10058e0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_10058e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10058e0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_10058e0, field_10, 0x10);

// 0x71010058e0
void Unk_10058e0_set(const Unk_10058e0* self, Unk_10058e0* value) {
    *value = *self;
}

// 0x71010059e0
void Unk_10059e0_update() {}

struct Unk_10059f0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_10059f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10059f0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_10059f0, field_10, 0x10);

// 0x71010059f0
void Unk_10059f0_set(const Unk_10059f0* self, Unk_10059f0* value) {
    *value = *self;
}

struct Unk_1005a10 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1005a10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1005a10, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1005a10, field_10, 0x10);

// 0x7101005a10
void Unk_1005a10_set(const Unk_1005a10* self, Unk_1005a10* value) {
    *value = *self;
}
