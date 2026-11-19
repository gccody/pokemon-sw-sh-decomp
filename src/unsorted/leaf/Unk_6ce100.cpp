// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_6ce100 {
    u8 _0[0x110];
    u32 field_110;
};
PKMN_OFFSET_ASSERT(Unk_6ce100, field_110, 0x110);

// 0x71006ce100
u32 Unk_6ce100_getField110(const Unk_6ce100* self) {
    return self->field_110;
}

struct Unk_6ce3c0 {
    u8 _0[0x110];
    u32 field_110;
};
PKMN_OFFSET_ASSERT(Unk_6ce3c0, field_110, 0x110);

// 0x71006ce3c0
void Unk_6ce3c0_setField110(Unk_6ce3c0* self, u32 value) {
    self->field_110 = value;
}

struct Unk_27791d4_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27791d4_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27791d4_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27791d4_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27791d4_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27791d4_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27791d4_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27791d4_Data, field_18, 0x18);

extern Unk_27791d4_Data Unk_27791d4 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71006cec80
void Unk_6cec80_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27791d4.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27791d4.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27791d4.field_10 = 0xffff;
    Unk_27791d4.field_8 = r2;
    Unk_27791d4.field_c = 0xffffffff;
    Unk_27791d4.field_18 = 0;
    Unk_27791d4.field_14 = 0;
}
