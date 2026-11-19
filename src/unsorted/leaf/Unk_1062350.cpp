// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1062350 {
    u8 _0[0xa0];
    u64 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_1062350, field_a0, 0xa0);

// 0x7101062350
u64 Unk_1062350_getFielda0(const Unk_1062350* self) {
    return self->field_a0;
}

struct Unk_1062370 {
    u8 _0[0x2a0];
    u8 field_2a0;
};
PKMN_OFFSET_ASSERT(Unk_1062370, field_2a0, 0x2a0);

// 0x7101062370
u8* Unk_1062370_getField2a0Ptr(Unk_1062370* self) {
    return &self->field_2a0;
}

struct Unk_1064e20 {
    u8 _0[0xc0];
    u8 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_1064e20, field_c0, 0xc0);

// 0x7101064e20
u8* Unk_1064e20_getFieldc0Ptr(Unk_1064e20* self) {
    return &self->field_c0;
}

struct Unk_27e3b54_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e3b54_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e3b54_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e3b54_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e3b54_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e3b54_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e3b54_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e3b54_Data, field_18, 0x18);

extern Unk_27e3b54_Data Unk_27e3b54 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x710106afa0
void Unk_106afa0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e3b54.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e3b54.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e3b54.field_10 = 0xffff;
    Unk_27e3b54.field_8 = r2;
    Unk_27e3b54.field_c = 0xffffffff;
    Unk_27e3b54.field_18 = 0;
    Unk_27e3b54.field_14 = 0;
}
