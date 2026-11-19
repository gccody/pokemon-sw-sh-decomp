// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u64 Unk_240bfb0;

// 0x710105b2c0
u64 Unk_105b2c0_get() {
    return Unk_240bfb0;
}

extern u64 Unk_24ba598;
extern u64 Unk_24ba5b8;
void Unk_104e0e0(u64);
void Unk_1064e30(u64);
void Unk_6a0ab0();

// 0x710105c360
void Unk_105c360_call() {
    Unk_1064e30(Unk_24ba5b8);
    Unk_6a0ab0();
    Unk_104e0e0(Unk_24ba598);
}

u32 Unk_6a0d40();

// 0x710105c3c0
bool Unk_105c3c0_call() {
    u32 r0 = Unk_6a0d40();
    return (r0 & 0xff) == 0;
}

struct Unk_27e3a94_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e3a94_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e3a94_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e3a94_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e3a94_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e3a94_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e3a94_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e3a94_Data, field_18, 0x18);

extern Unk_27e3a94_Data Unk_27e3a94 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x710105e9d0
void Unk_105e9d0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e3a94.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e3a94.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e3a94.field_10 = 0xffff;
    Unk_27e3a94.field_8 = r2;
    Unk_27e3a94.field_c = 0xffffffff;
    Unk_27e3a94.field_18 = 0;
    Unk_27e3a94.field_14 = 0;
}
