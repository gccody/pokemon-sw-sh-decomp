// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_f248d0_5d8 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_f248d0_5d8, field_58, 0x58);

struct Unk_f248d0 {
    u8 _0[0x5d8];
    Unk_f248d0_5d8* field_5d8;
};
PKMN_OFFSET_ASSERT(Unk_f248d0, field_5d8, 0x5d8);

// 0x7100f248d0
void Unk_f248d0_set(const Unk_f248d0* self, bool value) {
    self->field_5d8->field_58 = (self->field_5d8->field_58 & 0xfffffffe) | (value);
}

struct Unk_f26620 {
    u8 _0[0x5d0];
    u64 field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_f26620, field_5d0, 0x5d0);

void Unk_14eaa70(u64);

// 0x7100f26620
void Unk_f26620_call(const Unk_f26620* self) {
    Unk_14eaa70(self->field_5d0);
}

struct Unk_f267e0_0 {
    u8 _0[0x4c0];
    u64 field_4c0;
    u8 _4c8[0x104];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_f267e0_0, field_4c0, 0x4c0);
PKMN_OFFSET_ASSERT(Unk_f267e0_0, field_5cc, 0x5cc);

struct Unk_f267e0 {
    Unk_f267e0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f267e0, field_0, 0x0);

void Unk_1500c40(u64);

// 0x7100f267e0
void Unk_f267e0_call(const Unk_f267e0* self) {
    Unk_f267e0_0* p0 = self->field_0;
    p0->field_5cc = 1;
    if (p0->field_4c0 != 0) {
        Unk_1500c40(p0->field_4c0);
    }
}

// 0x7100f26800
void Unk_f26800_update() {}

struct Unk_f26810_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f26810_arg1, field_0, 0x0);

struct Unk_f26810 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f26810, field_0, 0x0);

// 0x7100f26810
void Unk_f26810_set(const Unk_f26810* self, Unk_f26810_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f26820_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f26820_arg1, field_0, 0x0);

struct Unk_f26820 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f26820, field_0, 0x0);

// 0x7100f26820
void Unk_f26820_set(const Unk_f26820* self, Unk_f26820_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f26830_0 {
    u8 _0[0x4c0];
    u64 field_4c0;
    u8 _4c8[0x104];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_f26830_0, field_4c0, 0x4c0);
PKMN_OFFSET_ASSERT(Unk_f26830_0, field_5cc, 0x5cc);

struct Unk_f26830 {
    Unk_f26830_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f26830, field_0, 0x0);

void Unk_1500c40(u64);

// 0x7100f26830
void Unk_f26830_call(const Unk_f26830* self) {
    Unk_f26830_0* p0 = self->field_0;
    p0->field_5cc = 1;
    if (p0->field_4c0 != 0) {
        Unk_1500c40(p0->field_4c0);
    }
}

// 0x7100f26850
void Unk_f26850_update() {}

struct Unk_f26860_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f26860_arg1, field_0, 0x0);

struct Unk_f26860 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f26860, field_0, 0x0);

// 0x7100f26860
void Unk_f26860_set(const Unk_f26860* self, Unk_f26860_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f26870_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f26870_arg1, field_0, 0x0);

struct Unk_f26870 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f26870, field_0, 0x0);

// 0x7100f26870
void Unk_f26870_set(const Unk_f26870* self, Unk_f26870_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f26880_0 {
    u8 _0[0x610];
    u32 field_610;
};
PKMN_OFFSET_ASSERT(Unk_f26880_0, field_610, 0x610);

struct Unk_f26880_arg1 {
    u8 _0[0x4];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_f26880_arg1, field_4, 0x4);

struct Unk_f26880 {
    Unk_f26880_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f26880, field_0, 0x0);

// 0x7100f26880
void Unk_f26880_set(const Unk_f26880* self, const Unk_f26880_arg1* value) {
    self->field_0->field_610 = value->field_4;
}

// 0x7100f26890
void Unk_f26890_update() {}

struct Unk_f268a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f268a0_arg1, field_0, 0x0);

struct Unk_f268a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f268a0, field_0, 0x0);

// 0x7100f268a0
void Unk_f268a0_set(const Unk_f268a0* self, Unk_f268a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f268b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f268b0_arg1, field_0, 0x0);

struct Unk_f268b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f268b0, field_0, 0x0);

// 0x7100f268b0
void Unk_f268b0_set(const Unk_f268b0* self, Unk_f268b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_27e10d4_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e10d4_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e10d4_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e10d4_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e10d4_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e10d4_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e10d4_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e10d4_Data, field_18, 0x18);

extern Unk_27e10d4_Data Unk_27e10d4 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100f268c0
void Unk_f268c0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e10d4.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e10d4.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e10d4.field_18 = 0xffff;
    Unk_27e10d4.field_10 = 0;
    Unk_27e10d4.field_8 = r2;
    Unk_27e10d4.field_c = 0;
    Unk_27e10d4.field_14 = 0xffffffff;
}
