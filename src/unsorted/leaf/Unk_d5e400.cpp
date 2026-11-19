// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d5e400 {
    u8 _0[0x64];
    u32 field_64;
};
PKMN_OFFSET_ASSERT(Unk_d5e400, field_64, 0x64);

// 0x7100d5e400
bool Unk_d5e400_check(const Unk_d5e400* self) {
    return (self->field_64 & 0xfffffffe) == 0xa;
}

struct Unk_d5e420 {
    u8 _0[0x27c];
    u32 field_27c;
};
PKMN_OFFSET_ASSERT(Unk_d5e420, field_27c, 0x27c);

// 0x7100d5e420
u32 Unk_d5e420_getField27c(const Unk_d5e420* self) {
    return self->field_27c;
}

struct Unk_d5e430 {
    u8 _0[0xd6];
    u8 field_d6;
    u8 _d7[0x1b1];
    u32 field_288;
};
PKMN_OFFSET_ASSERT(Unk_d5e430, field_d6, 0xd6);
PKMN_OFFSET_ASSERT(Unk_d5e430, field_288, 0x288);

// 0x7100d5e430
u32 Unk_d5e430_get(const Unk_d5e430* self) {
    if ((self->field_d6 & 0xfe) != 0xa) {
        return 0xffffffff;
    }
    return self->field_288;
}

struct Unk_27dcedc_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27dcedc_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27dcedc_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27dcedc_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27dcedc_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27dcedc_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27dcedc_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27dcedc_Data, field_18, 0x18);

extern Unk_27dcedc_Data Unk_27dcedc __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100d5eae0
void Unk_d5eae0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27dcedc.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27dcedc.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27dcedc.field_18 = 0xffff;
    Unk_27dcedc.field_10 = 0;
    Unk_27dcedc.field_8 = r2;
    Unk_27dcedc.field_c = 0;
    Unk_27dcedc.field_14 = 0xffffffff;
}
