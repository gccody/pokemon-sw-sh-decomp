// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_104a170 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_104a170, field_0, 0x0);

// 0x710104a170
u32 Unk_104a170_getField0(const Unk_104a170* self) {
    return self->field_0;
}

struct Unk_104a180 {
    u8 _0[0x8];
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_104a180, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_104a180, field_10, 0x10);

// 0x710104a180
u64 Unk_104a180_get(const Unk_104a180* self) {
    return self->field_10 - self->field_8;
}

struct Unk_104a190 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_104a190, field_8, 0x8);

// 0x710104a190
u64 Unk_104a190_getField8(const Unk_104a190* self) {
    return self->field_8;
}

struct Unk_104a300 {
    u8 _0[0x8];
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_104a300, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_104a300, field_10, 0x10);

void Unk_65c700(u64, u64);

// 0x710104a300
void Unk_104a300_call(const Unk_104a300* self) {
    Unk_65c700(self->field_8, self->field_10 - self->field_8);
}

struct Unk_27e37a4_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e37a4_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e37a4_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e37a4_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e37a4_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e37a4_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e37a4_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e37a4_Data, field_18, 0x18);

extern Unk_27e37a4_Data Unk_27e37a4 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x710104a400
void Unk_104a400_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e37a4.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e37a4.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e37a4.field_10 = 0xffff;
    Unk_27e37a4.field_8 = r2;
    Unk_27e37a4.field_c = 0xffffffff;
    Unk_27e37a4.field_18 = 0;
    Unk_27e37a4.field_14 = 0;
}
