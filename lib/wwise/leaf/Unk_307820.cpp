// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u64 Unk_24bb988;
void Unk_306930(u64, void*, u32);

// 0x7100307820
void Unk_307820_call(void* self) {
    if (Unk_24bb988 != 0) {
        Unk_306930(Unk_24bb988, self, 1);
    }
}

struct Unk_309380 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2(u32);
};

// 0x7100309380
void Unk_309380_call(Unk_309380* self) {
    self->vf2(0);
}

struct Unk_3095b0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(u64);
};

// 0x71003095b0
void Unk_3095b0_call(Unk_3095b0* self, u64 value) {
    self->vf6(value);
}

struct Unk_3095c0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};

// 0x71003095c0
void Unk_3095c0_call(Unk_3095c0* self) {
    self->vf7();
}

struct Unk_309740 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_309740, field_10, 0x10);

void Unk_3089c0(u64, void*);

// 0x7100309740
void Unk_309740_call(Unk_309740* self) {
    Unk_3089c0(self->field_10, self);
}

struct Unk_30adf0 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_30adf0, field_60, 0x60);

// 0x710030adf0
void Unk_30adf0_set(Unk_30adf0* self, u64 value) {
    self->field_60 = value;
}

struct Unk_30b000 {
    u8 _0[0x20];
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_30b000, field_20, 0x20);

// 0x710030b000
void Unk_30b000_set(Unk_30b000* self, u32 value) {
    self->field_20 = value;
}

struct Unk_30b6a0 {
    u8 _0[0x28];
    u32 field_28;
    u32 field_2c;
    u32 field_30;
    u8 _34[0x10];
    u8 field_44;
};
PKMN_OFFSET_ASSERT(Unk_30b6a0, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_30b6a0, field_2c, 0x2c);
PKMN_OFFSET_ASSERT(Unk_30b6a0, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_30b6a0, field_44, 0x44);

// 0x710030b6a0
void Unk_30b6a0_set(Unk_30b6a0* self, u32 value, u32 arg2, u32 arg3) {
    self->field_28 = value;
    self->field_2c = arg2;
    self->field_30 = arg3;
    self->field_44 = self->field_44 | 1;
}

struct Unk_30b9d0 {
    u8 _0[0x10];
    u64 field_10;
    u64 field_18;
    u8 _20[0x24];
    u8 field_44;
};
PKMN_OFFSET_ASSERT(Unk_30b9d0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_30b9d0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_30b9d0, field_44, 0x44);

// 0x710030b9d0
bool Unk_30b9d0_get(const Unk_30b9d0* self) {
    if (self->field_18 != 0) {
        return 0;
    }
    if ((self->field_44 & 2) == 0) {
        return self->field_10 == 0;
    }
    return 0;
}

struct Unk_30c7d0_10 {
    u8 _0[0x20];
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_30c7d0_10, field_20, 0x20);

struct Unk_30c7d0 {
    u8 _0[0x10];
    Unk_30c7d0_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_30c7d0, field_10, 0x10);

// 0x710030c7d0
u32 Unk_30c7d0_get(const Unk_30c7d0* self) {
    return self->field_10->field_20 & 0x7f00;
}

struct Unk_30e9f0_e8 {
    u8 _0[0x4];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_30e9f0_e8, field_4, 0x4);

struct Unk_30e9f0 {
    u8 _0[0xe8];
    Unk_30e9f0_e8* field_e8;
};
PKMN_OFFSET_ASSERT(Unk_30e9f0, field_e8, 0xe8);

// 0x710030e9f0
u32 Unk_30e9f0_get(const Unk_30e9f0* self) {
    return self->field_e8->field_4;
}

struct Unk_314ae0_100 {
    u8 _0[0x4];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_314ae0_100, field_4, 0x4);

struct Unk_314ae0 {
    u8 _0[0x100];
    Unk_314ae0_100* field_100;
};
PKMN_OFFSET_ASSERT(Unk_314ae0, field_100, 0x100);

// 0x7100314ae0
u32 Unk_314ae0_get(const Unk_314ae0* self) {
    if (self->field_100 == nullptr) {
        return 0;
    }
    return self->field_100->field_4;
}
