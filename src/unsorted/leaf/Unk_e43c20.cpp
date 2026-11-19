// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100e43c20
void Unk_e43c20() {}

struct Unk_e44040 {
    u8 _0[0x188];
    void* field_188;
};
PKMN_OFFSET_ASSERT(Unk_e44040, field_188, 0x188);

void Unk_68d9f0(void*);

// 0x7100e44040
void Unk_e44040_call(const Unk_e44040* self) {
    if (self->field_188 != nullptr) {
        Unk_68d9f0(self->field_188);
    }
}

struct Unk_e44050 {
    u8 _0[0x188];
    void* field_188;
};
PKMN_OFFSET_ASSERT(Unk_e44050, field_188, 0x188);

void Unk_68d630(void*, void*);

// 0x7100e44050
void Unk_e44050_call(const Unk_e44050* self, void* value) {
    if (self->field_188 != nullptr) {
        Unk_68d630(self->field_188, value);
    }
}

struct Unk_e44e00 {
    u8 _0[0x90];
    u64 field_90;
};
PKMN_OFFSET_ASSERT(Unk_e44e00, field_90, 0x90);

// 0x7100e44e00
bool Unk_e44e00_check(const Unk_e44e00* self) {
    return self->field_90 != 0;
}

struct Unk_e46b80_2e0 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_e46b80_2e0, field_60, 0x60);

struct Unk_e46b80 {
    u8 _0[0x2e0];
    Unk_e46b80_2e0* field_2e0;
};
PKMN_OFFSET_ASSERT(Unk_e46b80, field_2e0, 0x2e0);

// 0x7100e46b80
u32 Unk_e46b80_get(const Unk_e46b80* self) {
    if (self->field_2e0 == nullptr) {
        return 0;
    }
    return self->field_2e0->field_60;
}

struct Unk_e47200 {
    u8 _0[0x54];
    u32 field_54;
    u8 field_58;
    u8 _59[0x2];
    bool field_5b;
    u32 field_5c;
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_e47200, field_54, 0x54);
PKMN_OFFSET_ASSERT(Unk_e47200, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_e47200, field_5b, 0x5b);
PKMN_OFFSET_ASSERT(Unk_e47200, field_5c, 0x5c);
PKMN_OFFSET_ASSERT(Unk_e47200, field_60, 0x60);

// 0x7100e47200
void Unk_e47200_set(Unk_e47200* self, u32 value, bool arg2) {
    self->field_5c = 0;
    self->field_60 = value;
    self->field_58 = 0;
    self->field_54 = 1;
    self->field_5b = arg2;
}

struct Unk_e47260 {
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
    u8 _8[0x4c];
    u32 field_54;
    u8 _58[0x1];
    u8 field_59;
    u8 _5a[0x2];
    u32 field_5c;
};
PKMN_OFFSET_ASSERT(Unk_e47260, field_54, 0x54);
PKMN_OFFSET_ASSERT(Unk_e47260, field_59, 0x59);
PKMN_OFFSET_ASSERT(Unk_e47260, field_5c, 0x5c);

// 0x7100e47260
void Unk_e47260_call(Unk_e47260* self) {
    self->field_5c = 0;
    self->vf9();
    self->field_59 = 1;
    self->field_54 = 3;
}

struct Unk_e47350 {
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
};

// 0x7100e47350
void Unk_e47350_call(Unk_e47350* self) {
    self->vf11();
}

void Unk_e4c3c0(void*);

// 0x7100e4c3b0
void Unk_e4c3b0_call(void* self) {
    Unk_e4c3c0(self);
}

struct Unk_e4c660 {
    u8 _0[0x45];
    u8 field_45;
};
PKMN_OFFSET_ASSERT(Unk_e4c660, field_45, 0x45);
void Unk_e4c670(void*);

// 0x7100e4c660
void Unk_e4c660_update(Unk_e4c660* self) {
    if (self->field_45 != 0) {
        return;
    }
    Unk_e4c670(self);
}

// 0x7100e4cc50
void Unk_e4cc50() {}

struct Unk_e51bf0 {
    u8 _0[0x1c8];
    u8 field_1c8;
};
PKMN_OFFSET_ASSERT(Unk_e51bf0, field_1c8, 0x1c8);

// 0x7100e51bf0
void Unk_e51bf0_setField1c8(Unk_e51bf0* self, u8 value) {
    self->field_1c8 = value;
}

struct Unk_e51c00 {
    u8 _0[0x1c9];
    u8 field_1c9;
};
PKMN_OFFSET_ASSERT(Unk_e51c00, field_1c9, 0x1c9);

// 0x7100e51c00
void Unk_e51c00_setField1c9(Unk_e51c00* self, u8 value) {
    self->field_1c9 = value;
}

struct Unk_27e01ac_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e01ac_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e01ac_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e01ac_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e01ac_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e01ac_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e01ac_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e01ac_Data, field_18, 0x18);

extern Unk_27e01ac_Data Unk_27e01ac __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100e568f0
void Unk_e568f0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e01ac.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e01ac.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e01ac.field_18 = 0xffff;
    Unk_27e01ac.field_10 = 0;
    Unk_27e01ac.field_8 = r2;
    Unk_27e01ac.field_c = 0;
    Unk_27e01ac.field_14 = 0xffffffff;
}
