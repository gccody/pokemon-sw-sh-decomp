// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_a77140 {
    u8 _0[0x68];
    u32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_a77140, field_68, 0x68);

// 0x7100a77140
u32 Unk_a77140_getField68(const Unk_a77140* self) {
    return self->field_68;
}

struct Unk_a77150 {
    u8 _0[0x64];
    u32 field_64;
};
PKMN_OFFSET_ASSERT(Unk_a77150, field_64, 0x64);

// 0x7100a77150
void Unk_a77150_setField64(Unk_a77150* self, u32 value) {
    self->field_64 = value;
}

struct Unk_a77160 {
    u8 _0[0x70];
    u64 field_70;
};
PKMN_OFFSET_ASSERT(Unk_a77160, field_70, 0x70);

// 0x7100a77160
u64 Unk_a77160_getField70(const Unk_a77160* self) {
    return self->field_70;
}

struct Unk_a77460 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_a77460, field_78, 0x78);

// 0x7100a77460
void Unk_a77460_setField78(Unk_a77460* self, u32 value) {
    self->field_78 = value;
}

struct Unk_a774c0_70 {
    u8 _0[0x188];
    u64 field_188;
    u8 field_190;
};
PKMN_OFFSET_ASSERT(Unk_a774c0_70, field_188, 0x188);
PKMN_OFFSET_ASSERT(Unk_a774c0_70, field_190, 0x190);

struct Unk_a774c0 {
    u8 _0[0x70];
    Unk_a774c0_70* field_70;
};
PKMN_OFFSET_ASSERT(Unk_a774c0, field_70, 0x70);

// 0x7100a774c0
void Unk_a774c0_set(const Unk_a774c0* self) {
    Unk_a774c0_70* p0 = self->field_70;
    p0->field_190 = 0;
    p0->field_188 = 0;
}

struct Unk_a775e0 {
    u8 _0[0x88];
    u32 field_88;
};
PKMN_OFFSET_ASSERT(Unk_a775e0, field_88, 0x88);

// 0x7100a775e0
u32 Unk_a775e0_getField88(const Unk_a775e0* self) {
    return self->field_88;
}

struct Unk_a775f0_80_198 {
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
    virtual void vf14(u32, u32);
};

struct Unk_a775f0_80 {
    u8 _0[0x198];
    Unk_a775f0_80_198* field_198;
};
PKMN_OFFSET_ASSERT(Unk_a775f0_80, field_198, 0x198);

struct Unk_a775f0 {
    u8 _0[0x80];
    Unk_a775f0_80* field_80;
};
PKMN_OFFSET_ASSERT(Unk_a775f0, field_80, 0x80);

// 0x7100a775f0
void Unk_a775f0_call(const Unk_a775f0* self, bool value) {
    self->field_80->field_198->vf14(value, 0);
}

struct Unk_a77780_70 {
    u8 _0[0x170];
    u64 field_170;
};
PKMN_OFFSET_ASSERT(Unk_a77780_70, field_170, 0x170);

struct Unk_a77780 {
    u8 _0[0x70];
    Unk_a77780_70* field_70;
};
PKMN_OFFSET_ASSERT(Unk_a77780, field_70, 0x70);

void Unk_a77610(void*, u64);

// 0x7100a77780
void Unk_a77780_call(Unk_a77780* self) {
    Unk_a77610(self, self->field_70->field_170);
}

struct Unk_a77790 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_a77790, field_b0, 0xb0);

// 0x7100a77790
void Unk_a77790_setFieldb0(Unk_a77790* self, u64 value) {
    self->field_b0 = value;
}

struct Unk_a777c0 {
    u8 _0[0x7c0];
    u64 field_7c0;
};
PKMN_OFFSET_ASSERT(Unk_a777c0, field_7c0, 0x7c0);

// 0x7100a777c0
void Unk_a777c0_setField7c0(Unk_a777c0* self, u64 value) {
    self->field_7c0 = value;
}

struct Unk_27d70ac_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27d70ac_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27d70ac_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27d70ac_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27d70ac_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27d70ac_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27d70ac_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27d70ac_Data, field_18, 0x18);

extern Unk_27d70ac_Data Unk_27d70ac __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100a7e2a0
void Unk_a7e2a0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27d70ac.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27d70ac.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27d70ac.field_18 = 0xffff;
    Unk_27d70ac.field_10 = 0;
    Unk_27d70ac.field_8 = r2;
    Unk_27d70ac.field_c = 0;
    Unk_27d70ac.field_14 = 0xffffffff;
}
