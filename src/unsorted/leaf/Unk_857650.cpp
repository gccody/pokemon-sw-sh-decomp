// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_857650_arg1 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_857650_arg1, field_0, 0x0);

struct Unk_857650_arg2 {
    u8 field_0;
    u8 _1[0x3];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_857650_arg2, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_857650_arg2, field_4, 0x4);

struct Unk_7ee6b0;
u32 Unk_7ef2b0(const Unk_7ee6b0*);
u64 Unk_82ab10(void*, u8);
void Unk_7f1a20(u64, u32);

// 0x7100857650
void Unk_857650_call(void* self, Unk_857650_arg1* value, const Unk_857650_arg2* arg2) {
    value->field_0 = 0;
    u64 r0 = Unk_82ab10(self, arg2->field_0);
    u32 r1 = Unk_7ef2b0(reinterpret_cast<const Unk_7ee6b0*>(r0));
    if ((r1 & 1) == 0) {
        Unk_7f1a20(r0, arg2->field_4);
        value->field_0 = 1;
    }
}

struct Unk_27d0c04_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27d0c04_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27d0c04_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27d0c04_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27d0c04_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27d0c04_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27d0c04_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27d0c04_Data, field_18, 0x18);

extern Unk_27d0c04_Data Unk_27d0c04 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71008576c0
void Unk_8576c0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27d0c04.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27d0c04.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27d0c04.field_18 = 0xffff;
    Unk_27d0c04.field_10 = 0;
    Unk_27d0c04.field_8 = r2;
    Unk_27d0c04.field_c = 0;
    Unk_27d0c04.field_14 = 0xffffffff;
}
