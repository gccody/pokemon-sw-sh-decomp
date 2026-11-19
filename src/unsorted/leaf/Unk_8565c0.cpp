// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8565c0_arg1 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8565c0_arg1, field_0, 0x0);

struct Unk_8565c0_arg2 {
    u8 field_0;
    u8 _1[0x3];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_8565c0_arg2, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8565c0_arg2, field_4, 0x4);

u32 Unk_7ef2b0();
u64 Unk_82ab10(void*, u8);
void Unk_7f1400(u64, u32);

// 0x71008565c0
void Unk_8565c0_call(void* self, Unk_8565c0_arg1* value, const Unk_8565c0_arg2* arg2) {
    value->field_0 = 0;
    u64 r0 = Unk_82ab10(self, arg2->field_0);
    u32 r1 = Unk_7ef2b0();
    if ((r1 & 1) == 0) {
        Unk_7f1400(r0, arg2->field_4);
        value->field_0 = 1;
    }
}

struct Unk_27d0b04_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27d0b04_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27d0b04_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27d0b04_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27d0b04_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27d0b04_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27d0b04_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27d0b04_Data, field_18, 0x18);

extern Unk_27d0b04_Data Unk_27d0b04 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100856630
void Unk_856630_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27d0b04.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27d0b04.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27d0b04.field_18 = 0xffff;
    Unk_27d0b04.field_10 = 0;
    Unk_27d0b04.field_8 = r2;
    Unk_27d0b04.field_c = 0;
    Unk_27d0b04.field_14 = 0xffffffff;
}
