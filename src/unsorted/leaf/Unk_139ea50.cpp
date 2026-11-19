// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_139ea50 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_139ea50, field_0, 0x0);

// 0x710139ea50
u32 Unk_139ea50_getField0(const Unk_139ea50* self) {
    return self->field_0;
}

struct Unk_139ffb0 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_139ffb0, field_0, 0x0);

// 0x710139ffb0
u32 Unk_139ffb0_getField0(const Unk_139ffb0* self) {
    return self->field_0;
}

struct Unk_13a0f80 {
    u64 field_0;
    u8 field_8;
    u8 _9[0x77];
    u32 field_80;
};
PKMN_OFFSET_ASSERT(Unk_13a0f80, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_13a0f80, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_13a0f80, field_80, 0x80);

// 0x71013a0f80
void Unk_13a0f80_set(Unk_13a0f80* self) {
    self->field_0 = 0;
    self->field_8 = 0;
    self->field_80 = 0;
}

struct Unk_13a11f0 {
    u8 _0[0x4];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_13a11f0, field_4, 0x4);

// 0x71013a11f0
bool Unk_13a11f0_check(const Unk_13a11f0* self) {
    return self->field_4 == 2;
}

struct Unk_13a1200 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_13a1200, field_8, 0x8);

// 0x71013a1200
u32 Unk_13a1200_getField8(const Unk_13a1200* self) {
    return self->field_8;
}

struct Unk_13a1800 {
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
    virtual void vf10(u32);
    virtual void vf11();
    virtual void vf12();
    u8 _8[0x278];
    u8 field_280;
};
PKMN_OFFSET_ASSERT(Unk_13a1800, field_280, 0x280);

u32 Unk_13a3290();
void Unk_13a3220(void*, u64);
void Unk_66b8c0(void*);

// 0x71013a1800
void Unk_13a1800_call(Unk_13a1800* self, u64 value) {
    if (self->field_280 != 0) {
        u32 r0 = Unk_13a3290();
        self->vf10(r0);
        Unk_13a3220(self, value);
        Unk_66b8c0(self);
        self->vf12();
    }
}

struct Unk_13a2320_60_8 {
    u8 _0[0x170];
    u8 field_170;
};
PKMN_OFFSET_ASSERT(Unk_13a2320_60_8, field_170, 0x170);
struct Unk_13a2320_60 {
    u8 _0[0x8];
    Unk_13a2320_60_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_13a2320_60, field_8, 0x8);
struct Unk_13a2320 {
    u8 _0[0x60];
    Unk_13a2320_60* field_60;
    u8 _68[0x60];
    u64 field_c8;
};
PKMN_OFFSET_ASSERT(Unk_13a2320, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_13a2320, field_c8, 0xc8);
void Unk_13a2370(void*);

// 0x71013a2320
u32 Unk_13a2320_get(Unk_13a2320* self) {
    if (self->field_c8 != 0) {
        return 1;
    }
    if (self->field_60->field_8 != nullptr) {
        if (self->field_60->field_8->field_170 != 0) {
            Unk_13a2370(self);
            return 1;
        }
        return 0;
    }
    return 0;
}

struct Unk_27efd04_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27efd04_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27efd04_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27efd04_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27efd04_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27efd04_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27efd04_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27efd04_Data, field_18, 0x18);

extern Unk_27efd04_Data Unk_27efd04 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71013a34b0
void Unk_13a34b0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27efd04.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27efd04.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27efd04.field_18 = 0xffff;
    Unk_27efd04.field_10 = 0;
    Unk_27efd04.field_8 = r2;
    Unk_27efd04.field_c = 0;
    Unk_27efd04.field_14 = 0xffffffff;
}
