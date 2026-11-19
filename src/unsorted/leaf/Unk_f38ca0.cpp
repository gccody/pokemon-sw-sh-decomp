// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_f38ca0_5d8 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_f38ca0_5d8, field_58, 0x58);

struct Unk_f38ca0 {
    u8 _0[0x5d8];
    Unk_f38ca0_5d8* field_5d8;
};
PKMN_OFFSET_ASSERT(Unk_f38ca0, field_5d8, 0x5d8);

// 0x7100f38ca0
void Unk_f38ca0_set(const Unk_f38ca0* self, bool value) {
    self->field_5d8->field_58 = (self->field_5d8->field_58 & 0xfffffffe) | (value);
}

// 0x7100f39b60
void Unk_f39b60_update() {}

struct Unk_f39b70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f39b70_arg1, field_0, 0x0);

struct Unk_f39b70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f39b70, field_0, 0x0);

// 0x7100f39b70
void Unk_f39b70_set(const Unk_f39b70* self, Unk_f39b70_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f39b80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f39b80_arg1, field_0, 0x0);

struct Unk_f39b80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f39b80, field_0, 0x0);

// 0x7100f39b80
void Unk_f39b80_set(const Unk_f39b80* self, Unk_f39b80_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_27e11e4_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e11e4_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e11e4_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e11e4_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e11e4_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e11e4_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e11e4_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e11e4_Data, field_18, 0x18);

extern Unk_27e11e4_Data Unk_27e11e4 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100f39b90
void Unk_f39b90_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e11e4.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e11e4.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e11e4.field_18 = 0xffff;
    Unk_27e11e4.field_10 = 0;
    Unk_27e11e4.field_8 = r2;
    Unk_27e11e4.field_c = 0;
    Unk_27e11e4.field_14 = 0xffffffff;
}
