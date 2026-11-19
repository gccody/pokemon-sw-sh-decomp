// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_13e4b60(void*, u64, u64, u32, u32);

// 0x71013e4b50
void Unk_13e4b50_call(void* self, u64 value, u64 arg2, bool arg3) {
    Unk_13e4b60(self, value, arg2, arg3, 0);
}

extern const u8 Unk_24360d8[] __attribute__((visibility("hidden")));

// 0x71013e6560
const u8* Unk_13e6560_get() {
    return Unk_24360d8;
}

struct Unk_13e67c0_arg1 {
    u8 _0[0x8];
    u16 field_8;
};
PKMN_OFFSET_ASSERT(Unk_13e67c0_arg1, field_8, 0x8);

u64 Unk_786b80(u16);

// 0x71013e67c0
u64 Unk_13e67c0_call(void* /*unused*/, const Unk_13e67c0_arg1* value) {
    u64 r0 = Unk_786b80(value->field_8);
    return r0 & 1;
}

struct Unk_13e6800_arg1 {
    u8 _0[0x8];
    u16 field_8;
};
PKMN_OFFSET_ASSERT(Unk_13e6800_arg1, field_8, 0x8);

u64 Unk_786e20(u16);

// 0x71013e6800
u64 Unk_13e6800_call(void* /*unused*/, const Unk_13e6800_arg1* value) {
    u64 r0 = Unk_786e20(value->field_8);
    return r0 & 1;
}

struct Unk_13e68e0_arg1 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_13e68e0_arg1, field_8, 0x8);

u64 Unk_786de0(u8);

// 0x71013e68e0
u64 Unk_13e68e0_call(void* /*unused*/, const Unk_13e68e0_arg1* value) {
    u64 r0 = Unk_786de0(value->field_8);
    return r0 & 0xffff;
}

struct Unk_13e6900_arg1 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_13e6900_arg1, field_8, 0x8);

u64 Unk_786ad0(u32);

// 0x71013e6900
u64 Unk_13e6900_call(void* /*unused*/, const Unk_13e6900_arg1* value) {
    u64 r0 = Unk_786ad0(value->field_8);
    return r0 & 1;
}

struct Unk_27f02ec_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27f02ec_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27f02ec_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27f02ec_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27f02ec_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27f02ec_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27f02ec_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27f02ec_Data, field_18, 0x18);

extern Unk_27f02ec_Data Unk_27f02ec __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71013e7e60
void Unk_13e7e60_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27f02ec.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27f02ec.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27f02ec.field_18 = 0xffff;
    Unk_27f02ec.field_10 = 0;
    Unk_27f02ec.field_8 = r2;
    Unk_27f02ec.field_c = 0;
    Unk_27f02ec.field_14 = 0xffffffff;
}
