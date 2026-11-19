// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_db70f0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_db70f0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_db70f0_arg1, field_8, 0x8);

struct Unk_db70f0 {
    u8 _0[0x130];
    f32 field_130;
    f32 field_134;
    f32 field_138;
    u8 _13c[0x4];
    u64 field_140;
    u64 field_148;
};
PKMN_OFFSET_ASSERT(Unk_db70f0, field_130, 0x130);
PKMN_OFFSET_ASSERT(Unk_db70f0, field_134, 0x134);
PKMN_OFFSET_ASSERT(Unk_db70f0, field_138, 0x138);
PKMN_OFFSET_ASSERT(Unk_db70f0, field_140, 0x140);
PKMN_OFFSET_ASSERT(Unk_db70f0, field_148, 0x148);

// 0x7100db70f0
void Unk_db70f0_set(Unk_db70f0* self, const Unk_db70f0_arg1* value, f32 fvalue, f32 farg1) {
    self->field_130 = farg1;
    self->field_134 = farg1;
    self->field_148 = value->field_8;
    self->field_140 = value->field_0;
    self->field_138 = fvalue;
}

struct Unk_27dead4_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27dead4_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27dead4_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27dead4_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27dead4_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27dead4_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27dead4_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27dead4_Data, field_18, 0x18);

extern Unk_27dead4_Data Unk_27dead4 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100dbf510
void Unk_dbf510_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27dead4.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27dead4.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27dead4.field_18 = 0xffff;
    Unk_27dead4.field_10 = 0;
    Unk_27dead4.field_8 = r2;
    Unk_27dead4.field_c = 0;
    Unk_27dead4.field_14 = 0xffffffff;
}
