// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_c2e310 {
    u8 _0[0x4c0];
    u64 field_4c0;
    u8 _4c8[0x110];
    u32 field_5d8;
};
PKMN_OFFSET_ASSERT(Unk_c2e310, field_4c0, 0x4c0);
PKMN_OFFSET_ASSERT(Unk_c2e310, field_5d8, 0x5d8);

void Unk_1500c40(u64);

// 0x7100c2e310
void Unk_c2e310_call(Unk_c2e310* self) {
    self->field_5d8 = 1;
    if (self->field_4c0 != 0) {
        Unk_1500c40(self->field_4c0);
    }
}

struct Unk_c2e330 {
    u8 _0[0x4c0];
    void* field_4c0;
    u8 _4c8[0x110];
    u32 field_5d8;
};
PKMN_OFFSET_ASSERT(Unk_c2e330, field_4c0, 0x4c0);
PKMN_OFFSET_ASSERT(Unk_c2e330, field_5d8, 0x5d8);

void Unk_1500c90(void*);

// 0x7100c2e330
void Unk_c2e330_call(Unk_c2e330* self) {
    self->field_5d8 = 0;
    if (self->field_4c0 != nullptr) {
        Unk_1500c90(self->field_4c0);
    }
}

struct Unk_c2eea0 {
    u8 _0[0x660];
    u64 field_660;
};
PKMN_OFFSET_ASSERT(Unk_c2eea0, field_660, 0x660);

void Unk_eb75e0(u64);

// 0x7100c2eea0
void Unk_c2eea0_call(const Unk_c2eea0* self) {
    Unk_eb75e0(self->field_660);
}

// 0x7100c32b20
void Unk_c32b20_update() {}

struct Unk_c32b30 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_c32b30, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_c32b30, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_c32b30, field_10, 0x10);

// 0x7100c32b30
void Unk_c32b30_set(const Unk_c32b30* self, Unk_c32b30* value) {
    *value = *self;
}

struct Unk_c32b50 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_c32b50, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_c32b50, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_c32b50, field_10, 0x10);

// 0x7100c32b50
void Unk_c32b50_set(const Unk_c32b50* self, Unk_c32b50* value) {
    *value = *self;
}

// 0x7100c32c30
void Unk_c32c30_update() {}

struct Unk_c32c40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c32c40_arg1, field_0, 0x0);

struct Unk_c32c40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c32c40, field_0, 0x0);

// 0x7100c32c40
void Unk_c32c40_set(const Unk_c32c40* self, Unk_c32c40_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_c32c50_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c32c50_arg1, field_0, 0x0);

struct Unk_c32c50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c32c50, field_0, 0x0);

// 0x7100c32c50
void Unk_c32c50_set(const Unk_c32c50* self, Unk_c32c50_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100c32d20
void Unk_c32d20_update() {}

struct Unk_c32d30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c32d30_arg1, field_0, 0x0);

struct Unk_c32d30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c32d30, field_0, 0x0);

// 0x7100c32d30
void Unk_c32d30_set(const Unk_c32d30* self, Unk_c32d30_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_c32d40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c32d40_arg1, field_0, 0x0);

struct Unk_c32d40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c32d40, field_0, 0x0);

// 0x7100c32d40
void Unk_c32d40_set(const Unk_c32d40* self, Unk_c32d40_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100c32e10
void Unk_c32e10_update() {}

struct Unk_c32e20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c32e20_arg1, field_0, 0x0);

struct Unk_c32e20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c32e20, field_0, 0x0);

// 0x7100c32e20
void Unk_c32e20_set(const Unk_c32e20* self, Unk_c32e20_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_c32e30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c32e30_arg1, field_0, 0x0);

struct Unk_c32e30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c32e30, field_0, 0x0);

// 0x7100c32e30
void Unk_c32e30_set(const Unk_c32e30* self, Unk_c32e30_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100c32f00
void Unk_c32f00_update() {}

struct Unk_c32f10_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c32f10_arg1, field_0, 0x0);

struct Unk_c32f10 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c32f10, field_0, 0x0);

// 0x7100c32f10
void Unk_c32f10_set(const Unk_c32f10* self, Unk_c32f10_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_c32f20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c32f20_arg1, field_0, 0x0);

struct Unk_c32f20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c32f20, field_0, 0x0);

// 0x7100c32f20
void Unk_c32f20_set(const Unk_c32f20* self, Unk_c32f20_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100c33060
void Unk_c33060_update() {}

struct Unk_c33070_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c33070_arg1, field_0, 0x0);

struct Unk_c33070 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c33070, field_0, 0x0);

// 0x7100c33070
void Unk_c33070_set(const Unk_c33070* self, Unk_c33070_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_c33080_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c33080_arg1, field_0, 0x0);

struct Unk_c33080 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c33080, field_0, 0x0);

// 0x7100c33080
void Unk_c33080_set(const Unk_c33080* self, Unk_c33080_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_c33590 {
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
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
};

void Unk_c335c0(void*);

// 0x7100c33590
void Unk_c33590_call(Unk_c33590* self) {
    Unk_c335c0(self);
    self->vf16();
}

struct Unk_c338a0 {
    u8 _0[0xe8];
    u8 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_c338a0, field_e8, 0xe8);

// 0x7100c338a0
void Unk_c338a0_set(Unk_c338a0* self) {
    self->field_e8 = 1;
}

struct Unk_c33940 {
    u8 _0[0xea];
    u8 field_ea;
};
PKMN_OFFSET_ASSERT(Unk_c33940, field_ea, 0xea);

// 0x7100c33940
void Unk_c33940_set(Unk_c33940* self) {
    self->field_ea = 1;
}
