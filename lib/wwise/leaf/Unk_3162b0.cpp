// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_3162b0_38 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

struct Unk_3162b0 {
    u8 _0[0x38];
    Unk_3162b0_38* field_38;
};
PKMN_OFFSET_ASSERT(Unk_3162b0, field_38, 0x38);

// 0x71003162b0
void Unk_3162b0_call(Unk_3162b0* self) {
    if (self->field_38 != nullptr) {
        self->field_38->vf2();
        self->field_38 = nullptr;
    }
}

// 0x71003168d0
void Unk_3168d0_update() {
}

struct Unk_318780 {
    u8 _0[0x100];
    u32 field_100;
    u8 _104[0x4];
    u64 field_108;
    u64 field_110;
    u32 field_118;
    u8 _11c[0x4];
    u64 field_120;
    u16 field_128;
    u8 field_12a;
    bool field_12b;
};
PKMN_OFFSET_ASSERT(Unk_318780, field_100, 0x100);
PKMN_OFFSET_ASSERT(Unk_318780, field_108, 0x108);
PKMN_OFFSET_ASSERT(Unk_318780, field_110, 0x110);
PKMN_OFFSET_ASSERT(Unk_318780, field_118, 0x118);
PKMN_OFFSET_ASSERT(Unk_318780, field_120, 0x120);
PKMN_OFFSET_ASSERT(Unk_318780, field_128, 0x128);
PKMN_OFFSET_ASSERT(Unk_318780, field_12a, 0x12a);
PKMN_OFFSET_ASSERT(Unk_318780, field_12b, 0x12b);

// 0x7100318780
void Unk_318780_set(Unk_318780* self, bool value) {
    self->field_100 = 0;
    self->field_120 = 0;
    self->field_118 = 0;
    self->field_128 = 1;
    self->field_12a = 0;
    self->field_12b = value;
    self->field_108 = 0;
    self->field_110 = 0;
}

// 0x7100318820
void Unk_318820_update() {
}

struct Unk_318fd0 {
    u8 _0[0x120];
    u64 field_120;
    bool field_128;
};
PKMN_OFFSET_ASSERT(Unk_318fd0, field_120, 0x120);
PKMN_OFFSET_ASSERT(Unk_318fd0, field_128, 0x128);

// 0x7100318fd0
void Unk_318fd0_set(Unk_318fd0* self, u64 value, bool arg2) {
    self->field_120 = value;
    self->field_128 = arg2;
}

struct Unk_31a180_10_60 {
    u8 _0[0x30];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_31a180_10_60, field_30, 0x30);

struct Unk_31a180_10 {
    u8 _0[0x60];
    Unk_31a180_10_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_31a180_10, field_60, 0x60);

struct Unk_31a180 {
    u8 _0[0x10];
    Unk_31a180_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_31a180, field_10, 0x10);

// 0x710031a180
u64 Unk_31a180_get(const Unk_31a180* self) {
    return self->field_10->field_60->field_30;
}

struct Unk_31a190_10_60 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_31a190_10_60, field_18, 0x18);

struct Unk_31a190_10 {
    u8 _0[0x60];
    Unk_31a190_10_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_31a190_10, field_60, 0x60);

struct Unk_31a190 {
    u8 _0[0x10];
    Unk_31a190_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_31a190, field_10, 0x10);

// 0x710031a190
u8* Unk_31a190_get(const Unk_31a190* self) {
    return &self->field_10->field_60->field_18;
}

struct Unk_31a1a0_10_60 {
    u8 _0[0x38];
    u8 field_38;
};
PKMN_OFFSET_ASSERT(Unk_31a1a0_10_60, field_38, 0x38);

struct Unk_31a1a0_10 {
    u8 _0[0x60];
    Unk_31a1a0_10_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_31a1a0_10, field_60, 0x60);

struct Unk_31a1a0 {
    u8 _0[0x10];
    Unk_31a1a0_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_31a1a0, field_10, 0x10);

// 0x710031a1a0
u8 Unk_31a1a0_get(const Unk_31a1a0* self) {
    return self->field_10->field_60->field_38;
}

struct Unk_31b050_10_60 {
    u8 _0[0x2c];
    u32 field_2c;
};
PKMN_OFFSET_ASSERT(Unk_31b050_10_60, field_2c, 0x2c);

struct Unk_31b050_10 {
    u8 _0[0x60];
    Unk_31b050_10_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_31b050_10, field_60, 0x60);

struct Unk_31b050 {
    u8 _0[0x10];
    Unk_31b050_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_31b050, field_10, 0x10);

// 0x710031b050
u32 Unk_31b050_get(const Unk_31b050* self) {
    return self->field_10->field_60->field_2c;
}

struct Unk_31b060 {
    u8 _0[0x10];
    u64 field_10;
    u8 _18[0x60];
    u64 field_78;
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_31b060, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_31b060, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_31b060, field_80, 0x80);

u32 Unk_30e9f0(u64);
u32 Unk_319300(u64, u64);

// 0x710031b060
u32 Unk_31b060_call(const Unk_31b060* self) {
    u32 r0 = Unk_319300(self->field_10, self->field_80);
    u32 r1 = Unk_30e9f0(self->field_78);
    return r1 + r0;
}

struct Unk_31b0a0_10_60 {
    u8 _0[0x48];
    u32 field_48;
};
PKMN_OFFSET_ASSERT(Unk_31b0a0_10_60, field_48, 0x48);

struct Unk_31b0a0_10 {
    u8 _0[0x60];
    Unk_31b0a0_10_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_31b0a0_10, field_60, 0x60);

struct Unk_31b0a0 {
    u8 _0[0x10];
    Unk_31b0a0_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_31b0a0, field_10, 0x10);

// 0x710031b0a0
u32 Unk_31b0a0_get(const Unk_31b0a0* self) {
    return self->field_10->field_60->field_48;
}

// 0x710031b530
void Unk_31b530_update() {
}

struct Unk_31ce50 {
    u8 _0[0xa8];
    u32 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_31ce50, field_a8, 0xa8);

// 0x710031ce50
void Unk_31ce50_set(Unk_31ce50* self, u32 value) {
    self->field_a8 = value;
}
