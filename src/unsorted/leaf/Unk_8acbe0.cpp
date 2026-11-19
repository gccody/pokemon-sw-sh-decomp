// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8acbe0 {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_8acbe0, field_30, 0x30);

// 0x71008acbe0
u8 Unk_8acbe0_getField30(const Unk_8acbe0* self) {
    return self->field_30;
}

struct Unk_8acbf0_arg1 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u8 field_20;
};
PKMN_OFFSET_ASSERT(Unk_8acbf0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8acbf0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_8acbf0_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_8acbf0_arg1, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_8acbf0_arg1, field_20, 0x20);

struct Unk_8acbf0 {
    u8 _0[0x8];
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u8 field_28;
    u8 _29[0x3];
    u32 field_2c;
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_8acbf0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_8acbf0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_8acbf0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_8acbf0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_8acbf0, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_8acbf0, field_2c, 0x2c);
PKMN_OFFSET_ASSERT(Unk_8acbf0, field_30, 0x30);

// 0x71008acbf0
void Unk_8acbf0_set(Unk_8acbf0* self, const Unk_8acbf0_arg1* value) {
    self->field_8 = value->field_8;
    self->field_10 = value->field_10;
    self->field_18 = value->field_0;
    self->field_20 = value->field_18;
    self->field_28 = value->field_20;
    self->field_2c = 0;
    self->field_30 = 0;
}

struct Unk_27d13cc_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27d13cc_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27d13cc_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27d13cc_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27d13cc_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27d13cc_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27d13cc_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27d13cc_Data, field_18, 0x18);

extern Unk_27d13cc_Data Unk_27d13cc __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71008ad280
void Unk_8ad280_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27d13cc.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27d13cc.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27d13cc.field_18 = 0xffff;
    Unk_27d13cc.field_10 = 0;
    Unk_27d13cc.field_8 = r2;
    Unk_27d13cc.field_c = 0;
    Unk_27d13cc.field_14 = 0xffffffff;
}
