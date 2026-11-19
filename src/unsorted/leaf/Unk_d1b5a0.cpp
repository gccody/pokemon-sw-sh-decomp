// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d1b5a0_arg1 {
    u32 field_0;
    u8 field_4;
    u8 field_5;
};
PKMN_OFFSET_ASSERT(Unk_d1b5a0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_d1b5a0_arg1, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_d1b5a0_arg1, field_5, 0x5);

struct Unk_d1b5a0 {
    u8 _0[0x98];
    u32 field_98;
    u8 field_9c;
    u8 _9d[0x38];
    u8 field_d5;
    u8 field_d6;
};
PKMN_OFFSET_ASSERT(Unk_d1b5a0, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_d1b5a0, field_9c, 0x9c);
PKMN_OFFSET_ASSERT(Unk_d1b5a0, field_d5, 0xd5);
PKMN_OFFSET_ASSERT(Unk_d1b5a0, field_d6, 0xd6);

// 0x7100d1b5a0
void Unk_d1b5a0_set(Unk_d1b5a0* self, const Unk_d1b5a0_arg1* value) {
    self->field_d6 = value->field_4;
    self->field_98 = value->field_0;
    self->field_9c = value->field_5 != 0;
    self->field_d5 = 1;
}

struct Unk_d1b6a0 {
    u8 _0[0x9e];
    u8 field_9e;
};
PKMN_OFFSET_ASSERT(Unk_d1b6a0, field_9e, 0x9e);

// 0x7100d1b6a0
void Unk_d1b6a0_clearField9e(Unk_d1b6a0* self) {
    self->field_9e = 0;
}

struct Unk_d1b6b0 {
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
    virtual void vf17();
    virtual void vf18();
    u8 _8[0x58];
    u32 field_60;
    u8 _64[0x6];
    u8 field_6a;
};
PKMN_OFFSET_ASSERT(Unk_d1b6b0, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_d1b6b0, field_6a, 0x6a);

u32 Unk_d1ba70(void*);

// 0x7100d1b6b0
void Unk_d1b6b0_call(Unk_d1b6b0* self) {
    u32 r0 = Unk_d1ba70(self);
    if ((r0 & 1) != 0) {
        self->vf18();
        self->field_60 = 2;
        self->field_6a = 0;
    }
}

struct Unk_d1b7a0 {
    u8 _0[0x90];
    u32 field_90;
};
PKMN_OFFSET_ASSERT(Unk_d1b7a0, field_90, 0x90);
void Unk_d1c330(void*);
void Unk_d1c8d0(void*);

// 0x7100d1b7a0
void Unk_d1b7a0_call(Unk_d1b7a0* self) {
    if (self->field_90 != 1) {
        if (self->field_90 == 0) {
            Unk_d1c330(self);
            return;
        }
        return;
    }
    Unk_d1c8d0(self);
}

struct Unk_d1ba50 {
    u8 _0[0x9c];
    u8 field_9c;
    u8 _9d[0x1];
    u8 field_9e;
    u8 field_9f;
};
PKMN_OFFSET_ASSERT(Unk_d1ba50, field_9c, 0x9c);
PKMN_OFFSET_ASSERT(Unk_d1ba50, field_9e, 0x9e);
PKMN_OFFSET_ASSERT(Unk_d1ba50, field_9f, 0x9f);

// 0x7100d1ba50
void Unk_d1ba50_set(Unk_d1ba50* self) {
    if (self->field_9e != 0) {
        self->field_9c = self->field_9f;
    }
}

struct Unk_d1d280 {
    u8 _0[0x9e];
    u8 field_9e;
};
PKMN_OFFSET_ASSERT(Unk_d1d280, field_9e, 0x9e);

// 0x7100d1d280
u8 Unk_d1d280_getField9e(const Unk_d1d280* self) {
    return self->field_9e;
}

struct Unk_27dc05c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27dc05c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27dc05c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27dc05c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27dc05c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27dc05c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27dc05c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27dc05c_Data, field_18, 0x18);

extern Unk_27dc05c_Data Unk_27dc05c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100d1da40
void Unk_d1da40_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27dc05c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27dc05c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27dc05c.field_18 = 0xffff;
    Unk_27dc05c.field_10 = 0;
    Unk_27dc05c.field_8 = r2;
    Unk_27dc05c.field_c = 0;
    Unk_27dc05c.field_14 = 0xffffffff;
}
