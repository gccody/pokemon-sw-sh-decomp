// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_14ee7c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14ee7c0_arg1, field_0, 0x0);

struct Unk_14ee7c0 {
    u8 _0[0x810];
    u64 field_810;
};
PKMN_OFFSET_ASSERT(Unk_14ee7c0, field_810, 0x810);

// 0x71014ee7c0
void Unk_14ee7c0_set(Unk_14ee7c0* self, const Unk_14ee7c0_arg1* value) {
    self->field_810 = value->field_0;
}

struct Unk_14eebd0_750 {
    u8 _0[0x14];
    u32 field_14;
};
PKMN_OFFSET_ASSERT(Unk_14eebd0_750, field_14, 0x14);

struct Unk_14eebd0 {
    u8 _0[0x750];
    Unk_14eebd0_750* field_750;
};
PKMN_OFFSET_ASSERT(Unk_14eebd0, field_750, 0x750);

// 0x71014eebd0
u32 Unk_14eebd0_get(const Unk_14eebd0* self) {
    return self->field_750->field_14;
}

struct Unk_14eebe0_750 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_14eebe0_750, field_10, 0x10);

struct Unk_14eebe0 {
    u8 _0[0x750];
    Unk_14eebe0_750* field_750;
};
PKMN_OFFSET_ASSERT(Unk_14eebe0, field_750, 0x750);

// 0x71014eebe0
u32 Unk_14eebe0_get(const Unk_14eebe0* self) {
    return self->field_750->field_10;
}

struct Unk_14eec70 {
    u8 _0[0x750];
    u64 field_750;
    u8 _758[0xe0];
    u8 field_838;
};
PKMN_OFFSET_ASSERT(Unk_14eec70, field_750, 0x750);
PKMN_OFFSET_ASSERT(Unk_14eec70, field_838, 0x838);

void Unk_14f5920(u64);

// 0x71014eec70
void Unk_14eec70_call(Unk_14eec70* self) {
    self->field_838 = 0;
    Unk_14f5920(self->field_750);
}

struct Unk_14f1840 {
    u8 _0[0x798];
    u32 field_798;
    u8 _79c[0xb1];
    bool field_84d;
};
PKMN_OFFSET_ASSERT(Unk_14f1840, field_798, 0x798);
PKMN_OFFSET_ASSERT(Unk_14f1840, field_84d, 0x84d);

// 0x71014f1840
void Unk_14f1840_set(Unk_14f1840* self, u32 value, bool arg2) {
    self->field_798 = value;
    self->field_84d = arg2;
}

struct Unk_14f1850 {
    u8 _0[0x79c];
    u32 field_79c;
};
PKMN_OFFSET_ASSERT(Unk_14f1850, field_79c, 0x79c);

// 0x71014f1850
void Unk_14f1850_setField79c(Unk_14f1850* self, u32 value) {
    self->field_79c = value;
}

struct Unk_14f1860 {
    u8 _0[0x7a1];
    bool field_7a1;
};
PKMN_OFFSET_ASSERT(Unk_14f1860, field_7a1, 0x7a1);

// 0x71014f1860
void Unk_14f1860_set(Unk_14f1860* self, bool value) {
    self->field_7a1 = value;
}

struct Unk_14f1ef0 {
    u8 _0[0x7a8];
    u64 field_7a8;
    u64 field_7b0;
};
PKMN_OFFSET_ASSERT(Unk_14f1ef0, field_7a8, 0x7a8);
PKMN_OFFSET_ASSERT(Unk_14f1ef0, field_7b0, 0x7b0);

// 0x71014f1ef0
void Unk_14f1ef0_set(Unk_14f1ef0* self, u64 value, u64 arg2) {
    self->field_7b0 = arg2;
    self->field_7a8 = value;
}

struct Unk_14f5b60 {
    u8 _0[0xc];
    s32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_14f5b60, field_c, 0xc);

// 0x71014f5b60
bool Unk_14f5b60_check(const Unk_14f5b60* self) {
    return self->field_c > 0;
}

// 0x71014f5c60
u32 Unk_14f5c60() {
    return 0;
}

struct Unk_14f8030 {
    u8 _0[0x1dc];
    u8 field_1dc;
};
PKMN_OFFSET_ASSERT(Unk_14f8030, field_1dc, 0x1dc);

// 0x71014f8030
u8 Unk_14f8030_getField1dc(const Unk_14f8030* self) {
    return self->field_1dc;
}

struct Unk_14f8840 {
    u8 _0[0x10];
    u32 field_10;
    u8 _14[0x2c];
    u32 field_40;
    u8 _44[0x2c];
    u32 field_70;
    u8 _74[0x2c];
    u32 field_a0;
    u8 _a4[0x2c];
    u32 field_d0;
    u8 _d4[0x2c];
    u32 field_100;
};
PKMN_OFFSET_ASSERT(Unk_14f8840, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_14f8840, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_14f8840, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_14f8840, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_14f8840, field_d0, 0xd0);
PKMN_OFFSET_ASSERT(Unk_14f8840, field_100, 0x100);

// 0x71014f8840
void Unk_14f8840_set(Unk_14f8840* self) {
    self->field_10 = 0xffffffff;
    self->field_40 = 0xffffffff;
    self->field_70 = 0xffffffff;
    self->field_a0 = 0xffffffff;
    self->field_d0 = 0xffffffff;
    self->field_100 = 0;
}

struct Unk_1500e20 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_1500e20, field_58, 0x58);

void Unk_15016d0(u64, u32);

// 0x7101500e20
void Unk_1500e20_call(const Unk_1500e20* self) {
    Unk_15016d0(self->field_58, 0);
}

// 0x71015030d0
u32 Unk_15030d0_get() {
    return 1;
}

// 0x71015030e0
void Unk_15030e0() {}

struct Unk_1505a10 {
    u8 _0[0x120];
    u32 field_120;
};
PKMN_OFFSET_ASSERT(Unk_1505a10, field_120, 0x120);

// 0x7101505a10
bool Unk_1505a10_check(const Unk_1505a10* self) {
    return self->field_120 == 2;
}

struct Unk_1505a20 {
    u8 _0[0x120];
    u32 field_120;
};
PKMN_OFFSET_ASSERT(Unk_1505a20, field_120, 0x120);

// 0x7101505a20
bool Unk_1505a20_check(const Unk_1505a20* self) {
    return self->field_120 == 5;
}

struct Unk_1505fc0 {
    u8 _0[0x1b0];
    u8 field_1b0;
};
PKMN_OFFSET_ASSERT(Unk_1505fc0, field_1b0, 0x1b0);

// 0x7101505fc0
u8* Unk_1505fc0_getField1b0Ptr(Unk_1505fc0* self) {
    return &self->field_1b0;
}
