// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_27f18b8_Data {
    u8 field_0;
    u8 _1[0xf];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_27f18b8_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27f18b8_Data, field_10, 0x10);

struct Unk_14eb1b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14eb1b0, field_0, 0x0);

extern Unk_27f18b8_Data Unk_27f18b8 __attribute__((visibility("hidden")));

// 0x71014eb1b0
void Unk_14eb1b0_set(const Unk_14eb1b0* self) {
    Unk_27f18b8.field_10 = self->field_0;
    Unk_27f18b8.field_0 = 1;
}

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

struct Unk_14eebf0_750 {
    u8 _0[0x10];
    u32 field_10;
    u32 field_14;
};
PKMN_OFFSET_ASSERT(Unk_14eebf0_750, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_14eebf0_750, field_14, 0x14);

struct Unk_14eebf0 {
    u8 _0[0x750];
    Unk_14eebf0_750* field_750;
};
PKMN_OFFSET_ASSERT(Unk_14eebf0, field_750, 0x750);

void Unk_14f5f10(void*, u32, u32);

// 0x71014eebf0
void Unk_14eebf0_call(const Unk_14eebf0* self) {
    Unk_14f5f10(self->field_750, self->field_750->field_14, self->field_750->field_10);
}

struct Unk_14eec70 {
    u8 _0[0x750];
    void* field_750;
    u8 _758[0xe0];
    u8 field_838;
};
PKMN_OFFSET_ASSERT(Unk_14eec70, field_750, 0x750);
PKMN_OFFSET_ASSERT(Unk_14eec70, field_838, 0x838);

void Unk_14f5920(void*, u32, u32);

// 0x71014eec70
void Unk_14eec70_call(Unk_14eec70* self, u32 value, u32 arg2) {
    self->field_838 = 0;
    Unk_14f5920(self->field_750, value, arg2);
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

// 0x71014f22e0
void Unk_14f22e0_update() {}

struct Unk_14f22f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14f22f0_arg1, field_0, 0x0);

struct Unk_14f22f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14f22f0, field_0, 0x0);

// 0x71014f22f0
void Unk_14f22f0_set(const Unk_14f22f0* self, Unk_14f22f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_14f2300_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14f2300_arg1, field_0, 0x0);

struct Unk_14f2300 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14f2300, field_0, 0x0);

// 0x71014f2300
void Unk_14f2300_set(const Unk_14f2300* self, Unk_14f2300_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_14f2310_0_b0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
};

struct Unk_14f2310_0 {
    u8 _0[0xb0];
    Unk_14f2310_0_b0* field_b0;
};
PKMN_OFFSET_ASSERT(Unk_14f2310_0, field_b0, 0xb0);

struct Unk_14f2310 {
    Unk_14f2310_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_14f2310, field_0, 0x0);

// 0x71014f2310
void Unk_14f2310_call(const Unk_14f2310* self) {
    if (self->field_0->field_b0 != nullptr) {
        self->field_0->field_b0->vf9();
    }
}

// 0x71014f2330
void Unk_14f2330_update() {}

struct Unk_14f2340_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14f2340_arg1, field_0, 0x0);

struct Unk_14f2340 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14f2340, field_0, 0x0);

// 0x71014f2340
void Unk_14f2340_set(const Unk_14f2340* self, Unk_14f2340_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_14f2350_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14f2350_arg1, field_0, 0x0);

struct Unk_14f2350 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14f2350, field_0, 0x0);

// 0x71014f2350
void Unk_14f2350_set(const Unk_14f2350* self, Unk_14f2350_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71014f2360
void Unk_14f2360_update() {}

// 0x71014f2370
void Unk_14f2370_update() {}

// 0x71014f2380
void Unk_14f2380_update() {}

// 0x71014f2390
void Unk_14f2390_update() {}

// 0x71014f3140
void Unk_14f3140_update() {}

struct Unk_14f3150 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_14f3150, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14f3150, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_14f3150, field_10, 0x10);

// 0x71014f3150
void Unk_14f3150_set(const Unk_14f3150* self, Unk_14f3150* value) {
    *value = *self;
}

struct Unk_14f3170 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_14f3170, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14f3170, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_14f3170, field_10, 0x10);

// 0x71014f3170
void Unk_14f3170_set(const Unk_14f3170* self, Unk_14f3170* value) {
    *value = *self;
}

// 0x71014f31b0
void Unk_14f31b0_update() {}

struct Unk_14f31c0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_14f31c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14f31c0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_14f31c0, field_10, 0x10);

// 0x71014f31c0
void Unk_14f31c0_set(const Unk_14f31c0* self, Unk_14f31c0* value) {
    *value = *self;
}

struct Unk_14f31e0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_14f31e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14f31e0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_14f31e0, field_10, 0x10);

// 0x71014f31e0
void Unk_14f31e0_set(const Unk_14f31e0* self, Unk_14f31e0* value) {
    *value = *self;
}

// 0x71014f4070
void Unk_14f4070_update() {}

struct Unk_14f4080_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14f4080_arg1, field_0, 0x0);

struct Unk_14f4080 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14f4080, field_0, 0x0);

// 0x71014f4080
void Unk_14f4080_set(const Unk_14f4080* self, Unk_14f4080_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_14f4090_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14f4090_arg1, field_0, 0x0);

struct Unk_14f4090 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14f4090, field_0, 0x0);

// 0x71014f4090
void Unk_14f4090_set(const Unk_14f4090* self, Unk_14f4090_arg1* value) {
    value->field_0 = self->field_0;
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

struct Unk_1500d10 {
    u8 _0[0x58];
    void* field_58;
    u8 _60[0x2];
    u8 field_62;
};
PKMN_OFFSET_ASSERT(Unk_1500d10, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_1500d10, field_62, 0x62);
void Unk_1501470(void*, u32);

// 0x7101500d10
void Unk_1500d10_update(const Unk_1500d10* self) {
    if (self->field_62 != 0) {
        return;
    }
    Unk_1501470(self->field_58, 0);
}

struct Unk_1500e20 {
    u8 _0[0x58];
    void* field_58;
};
PKMN_OFFSET_ASSERT(Unk_1500e20, field_58, 0x58);

void Unk_15016d0(void*, u32);

// 0x7101500e20
void Unk_1500e20_call(const Unk_1500e20* self) {
    Unk_15016d0(self->field_58, 0);
}

// 0x71015030d0
u32 Unk_15030d0_get(u64 /*unused*/) {
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

// 0x7101506360
void Unk_1506360_update() {}

struct Unk_1506370_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1506370_arg1, field_0, 0x0);

struct Unk_1506370 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1506370, field_0, 0x0);

// 0x7101506370
void Unk_1506370_set(const Unk_1506370* self, Unk_1506370_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1506380_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1506380_arg1, field_0, 0x0);

struct Unk_1506380 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1506380, field_0, 0x0);

// 0x7101506380
void Unk_1506380_set(const Unk_1506380* self, Unk_1506380_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101506440
void Unk_1506440_update() {}

struct Unk_1506450_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1506450_arg1, field_0, 0x0);

struct Unk_1506450 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1506450, field_0, 0x0);

// 0x7101506450
void Unk_1506450_set(const Unk_1506450* self, Unk_1506450_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1506460_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1506460_arg1, field_0, 0x0);

struct Unk_1506460 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1506460, field_0, 0x0);

// 0x7101506460
void Unk_1506460_set(const Unk_1506460* self, Unk_1506460_arg1* value) {
    value->field_0 = self->field_0;
}
