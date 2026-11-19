// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7101101490
void Unk_1101490_update() {}

struct Unk_11014a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11014a0_arg1, field_0, 0x0);

struct Unk_11014a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11014a0, field_0, 0x0);

// 0x71011014a0
void Unk_11014a0_set(const Unk_11014a0* self, Unk_11014a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11014b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11014b0_arg1, field_0, 0x0);

struct Unk_11014b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11014b0, field_0, 0x0);

// 0x71011014b0
void Unk_11014b0_set(const Unk_11014b0* self, Unk_11014b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_27e514c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e514c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e514c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e514c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e514c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e514c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e514c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e514c_Data, field_18, 0x18);

extern Unk_27e514c_Data Unk_27e514c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71011014c0
void Unk_11014c0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e514c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e514c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e514c.field_10 = 0xffff;
    Unk_27e514c.field_8 = r2;
    Unk_27e514c.field_c = 0xffffffff;
    Unk_27e514c.field_18 = 0;
    Unk_27e514c.field_14 = 0;
}
