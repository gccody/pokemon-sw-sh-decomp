// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1262fa0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1262fa0, field_10, 0x10);

// 0x7101262fa0
u32 Unk_1262fa0_getField10(const Unk_1262fa0* self) {
    return self->field_10;
}

struct Unk_1263050 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1263050, field_18, 0x18);

// 0x7101263050
void Unk_1263050_setField18(Unk_1263050* self, u64 value) {
    self->field_18 = value;
}

struct Unk_1263060 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_1263060, field_20, 0x20);

// 0x7101263060
void Unk_1263060_setField20(Unk_1263060* self, u64 value) {
    self->field_20 = value;
}

struct Unk_12632e0_20_5d0 {
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
    virtual void vf14(u32);
};

struct Unk_12632e0_20 {
    u8 _0[0x5d0];
    Unk_12632e0_20_5d0* field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_12632e0_20, field_5d0, 0x5d0);

struct Unk_12632e0 {
    u8 _0[0x20];
    Unk_12632e0_20* field_20;
};
PKMN_OFFSET_ASSERT(Unk_12632e0, field_20, 0x20);

// 0x71012632e0
void Unk_12632e0_call(const Unk_12632e0* self) {
    if (self->field_20 != nullptr) {
        self->field_20->field_5d0->vf14(0);
    }
}

struct Unk_12635f0 {
    u8 _0[0x88];
    u32 field_88;
};
PKMN_OFFSET_ASSERT(Unk_12635f0, field_88, 0x88);

// 0x71012635f0
u32 Unk_12635f0_getField88(const Unk_12635f0* self) {
    return self->field_88;
}

struct Unk_12637d0 {
    u8 _0[0x8c];
    u8 field_8c;
};
PKMN_OFFSET_ASSERT(Unk_12637d0, field_8c, 0x8c);

// 0x71012637d0
u8 Unk_12637d0_getField8c(const Unk_12637d0* self) {
    return self->field_8c;
}

struct Unk_1263990 {
    u8 _0[0x190];
    f32 field_190;
};
PKMN_OFFSET_ASSERT(Unk_1263990, field_190, 0x190);

// 0x7101263990
void Unk_1263990_setField190(Unk_1263990* self, f32 value) {
    self->field_190 = value;
}

// 0x7101264840
void Unk_1264840_update() {}

struct Unk_1264850_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1264850_arg1, field_0, 0x0);

struct Unk_1264850 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1264850, field_0, 0x0);

// 0x7101264850
void Unk_1264850_set(const Unk_1264850* self, Unk_1264850_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1264860_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1264860_arg1, field_0, 0x0);

struct Unk_1264860 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1264860, field_0, 0x0);

// 0x7101264860
void Unk_1264860_set(const Unk_1264860* self, Unk_1264860_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_27edc34_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27edc34_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27edc34_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27edc34_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27edc34_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27edc34_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27edc34_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27edc34_Data, field_18, 0x18);

extern Unk_27edc34_Data Unk_27edc34 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7101264870
void Unk_1264870_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27edc34.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27edc34.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27edc34.field_18 = 0xffff;
    Unk_27edc34.field_10 = 0;
    Unk_27edc34.field_8 = r2;
    Unk_27edc34.field_c = 0;
    Unk_27edc34.field_14 = 0xffffffff;
}
