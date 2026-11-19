// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d07d60 {
    u8 _0[0xc48];
    u64 field_c48;
    u8 _c50[0x5];
    u8 field_c55;
};
PKMN_OFFSET_ASSERT(Unk_d07d60, field_c48, 0xc48);
PKMN_OFFSET_ASSERT(Unk_d07d60, field_c55, 0xc55);
extern "C" [[noreturn]] void abort();

// 0x7100d07d60
void Unk_d07d60_set(Unk_d07d60* self, u32 value) {
    if (value == 0) {
        self->field_c48 = 0xcbf29ce484222645;
        self->field_c55 = 0;
        return;
    }
    abort();
}

struct Unk_27dbed4_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27dbed4_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27dbed4_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27dbed4_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27dbed4_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27dbed4_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27dbed4_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27dbed4_Data, field_18, 0x18);

extern Unk_27dbed4_Data Unk_27dbed4 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100d088d0
void Unk_d088d0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27dbed4.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27dbed4.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27dbed4.field_18 = 0xffff;
    Unk_27dbed4.field_10 = 0;
    Unk_27dbed4.field_8 = r2;
    Unk_27dbed4.field_c = 0;
    Unk_27dbed4.field_14 = 0xffffffff;
}
