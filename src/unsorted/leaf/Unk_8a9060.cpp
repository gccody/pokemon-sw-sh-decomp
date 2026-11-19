// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8a9060 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_8a9060, field_58, 0x58);

// 0x71008a9060
u64 Unk_8a9060_getField58(const Unk_8a9060* self) {
    return self->field_58;
}

struct Unk_8a9070 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_8a9070, field_58, 0x58);

// 0x71008a9070
u64 Unk_8a9070_getField58(const Unk_8a9070* self) {
    return self->field_58;
}

struct Unk_8aac00 {
    u8 _0[0x2];
    u8 field_2;
};
PKMN_OFFSET_ASSERT(Unk_8aac00, field_2, 0x2);

// 0x71008aac00
void Unk_8aac00_setField2(Unk_8aac00* self, u8 value) {
    self->field_2 = value;
}

struct Unk_27d136c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27d136c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27d136c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27d136c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27d136c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27d136c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27d136c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27d136c_Data, field_18, 0x18);

extern Unk_27d136c_Data Unk_27d136c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71008abd70
void Unk_8abd70_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27d136c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27d136c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27d136c.field_18 = 0xffff;
    Unk_27d136c.field_10 = 0;
    Unk_27d136c.field_8 = r2;
    Unk_27d136c.field_c = 0;
    Unk_27d136c.field_14 = 0xffffffff;
}
