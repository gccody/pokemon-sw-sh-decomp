// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d6eef0 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_d6eef0, field_68, 0x68);

// 0x7100d6eef0
bool Unk_d6eef0_check(const Unk_d6eef0* self) {
    return self->field_68 != 0;
}

struct Unk_d6ef30 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_d6ef30, field_60, 0x60);

// 0x7100d6ef30
bool Unk_d6ef30_check(const Unk_d6ef30* self) {
    return self->field_60 == 0;
}

struct Unk_d6ef40_60 {
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
};

struct Unk_d6ef40 {
    u8 _0[0x60];
    Unk_d6ef40_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_d6ef40, field_60, 0x60);

// 0x7100d6ef40
void Unk_d6ef40_call(const Unk_d6ef40* self) {
    if (self->field_60 != nullptr) {
        self->field_60->vf10();
    }
}

struct Unk_d6ef60_60 {
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

struct Unk_d6ef60 {
    u8 _0[0x60];
    Unk_d6ef60_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_d6ef60, field_60, 0x60);

// 0x7100d6ef60
void Unk_d6ef60_call(const Unk_d6ef60* self) {
    if (self->field_60 != nullptr) {
        self->field_60->vf11();
    }
}

struct Unk_d6ef80_60 {
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
};

struct Unk_d6ef80 {
    u8 _0[0x60];
    Unk_d6ef80_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_d6ef80, field_60, 0x60);

// 0x7100d6ef80
void Unk_d6ef80_call(const Unk_d6ef80* self) {
    if (self->field_60 != nullptr) {
        self->field_60->vf12();
    }
}

struct Unk_d6efa0_60 {
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
};

struct Unk_d6efa0 {
    u8 _0[0x60];
    Unk_d6efa0_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_d6efa0, field_60, 0x60);

// 0x7100d6efa0
void Unk_d6efa0_call(const Unk_d6efa0* self) {
    if (self->field_60 != nullptr) {
        self->field_60->vf13();
    }
}

struct Unk_27dd4c4_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27dd4c4_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27dd4c4_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27dd4c4_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27dd4c4_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27dd4c4_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27dd4c4_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27dd4c4_Data, field_18, 0x18);

extern Unk_27dd4c4_Data Unk_27dd4c4 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100d70190
void Unk_d70190_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27dd4c4.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27dd4c4.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27dd4c4.field_18 = 0xffff;
    Unk_27dd4c4.field_10 = 0;
    Unk_27dd4c4.field_8 = r2;
    Unk_27dd4c4.field_c = 0;
    Unk_27dd4c4.field_14 = 0xffffffff;
}
