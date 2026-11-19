// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x710126ec40
void Unk_126ec40_update() {}

struct Unk_126ec50_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_126ec50_arg1, field_0, 0x0);

struct Unk_126ec50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_126ec50, field_0, 0x0);

// 0x710126ec50
void Unk_126ec50_set(const Unk_126ec50* self, Unk_126ec50_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_126ec60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_126ec60_arg1, field_0, 0x0);

struct Unk_126ec60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_126ec60, field_0, 0x0);

// 0x710126ec60
void Unk_126ec60_set(const Unk_126ec60* self, Unk_126ec60_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_27edef4_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27edef4_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27edef4_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27edef4_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27edef4_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27edef4_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27edef4_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27edef4_Data, field_18, 0x18);

extern Unk_27edef4_Data Unk_27edef4 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x710126edd0
void Unk_126edd0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27edef4.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27edef4.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27edef4.field_18 = 0xffff;
    Unk_27edef4.field_10 = 0;
    Unk_27edef4.field_8 = r2;
    Unk_27edef4.field_c = 0;
    Unk_27edef4.field_14 = 0xffffffff;
}
