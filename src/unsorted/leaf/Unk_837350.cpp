// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_837350 {
    u64 field_0;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_837350, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_837350, field_8, 0x8);

// 0x7100837350
void Unk_837350_set(Unk_837350* self, u64 value) {
    self->field_0 = value;
    self->field_8 = 0;
}

struct Unk_8384b0 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_8384b0, field_20, 0x20);

// 0x71008384b0
u64 Unk_8384b0_getField20(const Unk_8384b0* self) {
    return self->field_20;
}

struct Unk_8384c0 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_8384c0, field_10, 0x10);

// 0x71008384c0
u64 Unk_8384c0_getField10(const Unk_8384c0* self) {
    return self->field_10;
}

struct Unk_8384d0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_8384d0, field_18, 0x18);

// 0x71008384d0
u64 Unk_8384d0_getField18(const Unk_8384d0* self) {
    return self->field_18;
}

struct Unk_8384e0 {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_8384e0, field_30, 0x30);

// 0x71008384e0
u8 Unk_8384e0_getField30(const Unk_8384e0* self) {
    return self->field_30;
}

struct Unk_27cf724_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27cf724_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27cf724_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27cf724_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27cf724_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27cf724_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27cf724_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27cf724_Data, field_18, 0x18);

extern Unk_27cf724_Data Unk_27cf724 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100838820
void Unk_838820_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27cf724.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27cf724.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27cf724.field_18 = 0xffff;
    Unk_27cf724.field_10 = 0;
    Unk_27cf724.field_8 = r2;
    Unk_27cf724.field_c = 0;
    Unk_27cf724.field_14 = 0xffffffff;
}
