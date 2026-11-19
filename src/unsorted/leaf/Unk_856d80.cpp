// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_856d80_arg2 {
    u8 field_0;
    u8 field_1;
    u8 _2[0x2];
    u8 field_4;
    u8 _5[0x3];
    u8 field_8;
    u8 _9[0x23];
    u8 field_2c;
};
PKMN_OFFSET_ASSERT(Unk_856d80_arg2, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_856d80_arg2, field_1, 0x1);
PKMN_OFFSET_ASSERT(Unk_856d80_arg2, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_856d80_arg2, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_856d80_arg2, field_2c, 0x2c);
struct Unk_856d80_arg1 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_856d80_arg1, field_0, 0x0);
u32 Unk_856f50(void*, void*);
void Unk_856e00(void*, u8, u8, void*);
void Unk_856e90();

// 0x7100856d80
void Unk_856d80_call(void* self, Unk_856d80_arg1* value, Unk_856d80_arg2* arg2) {
    value->field_0 = 0;
    if (arg2->field_1 != 0) {
        u32 r0 = Unk_856f50(self, arg2);
        value->field_0 = r0 & 1;
        return;
    }
    if (arg2->field_4 != 0) {
        Unk_856e00(self, arg2->field_0, arg2->field_2c, &arg2->field_8);
        value->field_0 = 1;
        return;
    }
    Unk_856e90();
}

struct Unk_27d0b84_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27d0b84_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27d0b84_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27d0b84_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27d0b84_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27d0b84_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27d0b84_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27d0b84_Data, field_18, 0x18);

extern Unk_27d0b84_Data Unk_27d0b84 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71008571d0
void Unk_8571d0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27d0b84.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27d0b84.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27d0b84.field_18 = 0xffff;
    Unk_27d0b84.field_10 = 0;
    Unk_27d0b84.field_8 = r2;
    Unk_27d0b84.field_c = 0;
    Unk_27d0b84.field_14 = 0xffffffff;
}
