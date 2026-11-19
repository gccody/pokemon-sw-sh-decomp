// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_c9be80_arg1 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u16 field_20;
};
PKMN_OFFSET_ASSERT(Unk_c9be80_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_c9be80_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_c9be80_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_c9be80_arg1, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_c9be80_arg1, field_20, 0x20);

struct Unk_c9be80 {
    u8 _0[0xb0];
    u64 field_b0;
    u64 field_b8;
    u64 field_c0;
    u64 field_c8;
    u16 field_d0;
};
PKMN_OFFSET_ASSERT(Unk_c9be80, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_c9be80, field_b8, 0xb8);
PKMN_OFFSET_ASSERT(Unk_c9be80, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(Unk_c9be80, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_c9be80, field_d0, 0xd0);

// 0x7100c9be80
void Unk_c9be80_set(Unk_c9be80* self, const Unk_c9be80_arg1* value) {
    u16 v0 = value->field_20;
    u64 v1 = value->field_8;
    self->field_c8 = value->field_18;
    self->field_b8 = v1;
    self->field_b0 = value->field_0;
    u64 v2 = value->field_10;
    self->field_d0 = v0;
    self->field_c0 = v2;
}

struct Unk_c9e610_70 {
    u8 _0[0xa0];
    u64 field_a0;
    u64 field_a8;
    u8 _b0[0x10];
    u8 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_c9e610_70, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_c9e610_70, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_c9e610_70, field_c0, 0xc0);

struct Unk_c9e610 {
    u8 _0[0x70];
    Unk_c9e610_70* field_70;
    u8 _78[0x48];
    u64 field_c0;
    u64 field_c8;
};
PKMN_OFFSET_ASSERT(Unk_c9e610, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_c9e610, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(Unk_c9e610, field_c8, 0xc8);

// 0x7100c9e610
void Unk_c9e610_set(const Unk_c9e610* self) {
    Unk_c9e610_70* p0 = self->field_70;
    p0->field_a8 = self->field_c8;
    p0->field_a0 = self->field_c0;
    p0->field_c0 = 1;
}

struct Unk_c9ecd0 {
    u8 _0[0xa4];
    u32 field_a4;
};
PKMN_OFFSET_ASSERT(Unk_c9ecd0, field_a4, 0xa4);

// 0x7100c9ecd0
void Unk_c9ecd0_set(Unk_c9ecd0* self) {
    self->field_a4 = 0x2d;
}

// 0x7100c9ffd0
void Unk_c9ffd0_update() {}

struct Unk_c9ffe0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_c9ffe0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_c9ffe0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_c9ffe0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_c9ffe0, field_18, 0x18);

// 0x7100c9ffe0
void Unk_c9ffe0_set(const Unk_c9ffe0* self, Unk_c9ffe0* value) {
    *value = *self;
}

struct Unk_ca0000 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_ca0000, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ca0000, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_ca0000, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_ca0000, field_18, 0x18);

// 0x7100ca0000
void Unk_ca0000_set(const Unk_ca0000* self, Unk_ca0000* value) {
    *value = *self;
}

struct Unk_ca07d0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_ca07d0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ca07d0_arg1, field_8, 0x8);

struct Unk_ca07d0 {
    u8 _0[0x80];
    u64 field_80;
    u64 field_88;
    u8 _90[0x24];
    u32 field_b4;
};
PKMN_OFFSET_ASSERT(Unk_ca07d0, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_ca07d0, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_ca07d0, field_b4, 0xb4);

// 0x7100ca07d0
void Unk_ca07d0_set(Unk_ca07d0* self, const Unk_ca07d0_arg1* value, u32 arg2) {
    self->field_88 = value->field_8;
    self->field_80 = value->field_0;
    self->field_b4 = arg2;
}

struct Unk_ca4e10 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_ca4e10, field_60, 0x60);

void Unk_785960(u64);

// 0x7100ca4e10
void Unk_ca4e10_call(const Unk_ca4e10* self) {
    Unk_785960(self->field_60);
}

struct Unk_ca4e20 {
    u8 _0[0xf0];
    u32 field_f0;
};
PKMN_OFFSET_ASSERT(Unk_ca4e20, field_f0, 0xf0);

// 0x7100ca4e20
bool Unk_ca4e20_check(const Unk_ca4e20* self) {
    return self->field_f0 == 2;
}

struct Unk_27da58c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27da58c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27da58c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27da58c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27da58c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27da58c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27da58c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27da58c_Data, field_18, 0x18);

extern Unk_27da58c_Data Unk_27da58c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100ca50c0
void Unk_ca50c0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27da58c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27da58c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27da58c.field_18 = 0xffff;
    Unk_27da58c.field_10 = 0;
    Unk_27da58c.field_8 = r2;
    Unk_27da58c.field_c = 0;
    Unk_27da58c.field_14 = 0xffffffff;
}
