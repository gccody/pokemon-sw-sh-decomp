// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_6d7aa0 {
    u8 _0[0xc0];
    u8 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_6d7aa0, field_c0, 0xc0);

// 0x71006d7aa0
u8* Unk_6d7aa0_getFieldc0Ptr(Unk_6d7aa0* self) {
    return &self->field_c0;
}

struct Unk_6d7ab0 {
    u8 _0[0x120];
    u8 field_120;
};
PKMN_OFFSET_ASSERT(Unk_6d7ab0, field_120, 0x120);

// 0x71006d7ab0
u8* Unk_6d7ab0_getField120Ptr(Unk_6d7ab0* self) {
    return &self->field_120;
}

struct Unk_2779384_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_2779384_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_2779384_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_2779384_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_2779384_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_2779384_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_2779384_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_2779384_Data, field_18, 0x18);

extern Unk_2779384_Data Unk_2779384 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71006d8c20
void Unk_6d8c20_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_2779384.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_2779384.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_2779384.field_10 = 0xffff;
    Unk_2779384.field_8 = r2;
    Unk_2779384.field_c = 0xffffffff;
    Unk_2779384.field_18 = 0;
    Unk_2779384.field_14 = 0;
}
