// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_6ddde0 {
    u32 field_0;
    u8 _4[0x4];
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_6ddde0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_6ddde0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_6ddde0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_6ddde0, field_18, 0x18);

// 0x71006ddde0
u32 Unk_6ddde0_update(Unk_6ddde0* self) {
    self->field_0 = self->field_10;
    self->field_8 = self->field_18;
    return 0;
}

struct Unk_6de620 {
    u8 _0[0x8];
    u32 field_8;
    u8 _c[0xa4];
    u32 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_6de620, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_6de620, field_b0, 0xb0);

// 0x71006de620
bool Unk_6de620_check(const Unk_6de620* self) {
    if (self->field_8 != 0) {
        return 0;
    }
    return self->field_b0 == 0;
}

struct Unk_6de660 {
    u8 _0[0xb0];
    u8 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_6de660, field_b0, 0xb0);

// 0x71006de660
u8* Unk_6de660_getFieldb0Ptr(Unk_6de660* self) {
    return &self->field_b0;
}

struct Unk_6de670 {
    u8 _0[0x10];
    u64 field_10;
    u8 _18[0xa0];
    u64 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_6de670, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_6de670, field_b8, 0xb8);

// 0x71006de670
u64 Unk_6de670_get(const Unk_6de670* self) {
    if (self->field_10 != 0) {
        return 0;
    }
    return self->field_b8;
}

// 0x71006de7d0
void Unk_6de7d0_update() {}

struct Unk_6de7e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6de7e0_arg1, field_0, 0x0);

struct Unk_6de7e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6de7e0, field_0, 0x0);

// 0x71006de7e0
void Unk_6de7e0_set(const Unk_6de7e0* self, Unk_6de7e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_6de7f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6de7f0_arg1, field_0, 0x0);

struct Unk_6de7f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6de7f0, field_0, 0x0);

// 0x71006de7f0
void Unk_6de7f0_set(const Unk_6de7f0* self, Unk_6de7f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_277958c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_277958c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_277958c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_277958c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_277958c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_277958c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_277958c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_277958c_Data, field_18, 0x18);

extern Unk_277958c_Data Unk_277958c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71006de800
void Unk_6de800_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_277958c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_277958c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_277958c.field_10 = 0xffff;
    Unk_277958c.field_8 = r2;
    Unk_277958c.field_c = 0xffffffff;
    Unk_277958c.field_18 = 0;
    Unk_277958c.field_14 = 0;
}
