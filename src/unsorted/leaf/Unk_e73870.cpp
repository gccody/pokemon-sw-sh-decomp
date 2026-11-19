// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_e734a0(void*);

// 0x7100e73870
void Unk_e73870_call(void* self) {
    Unk_e734a0(self);
}

struct Unk_e748c0 {
    u8 _0[0x700];
    u64 field_700;
};
PKMN_OFFSET_ASSERT(Unk_e748c0, field_700, 0x700);

// 0x7100e748c0
void Unk_e748c0_setField700(Unk_e748c0* self, u64 value) {
    self->field_700 = value;
}

struct Unk_e76460_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e76460_arg1, field_0, 0x0);

struct Unk_e76460 {
    u8 _0[0x5d0];
    u64 field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_e76460, field_5d0, 0x5d0);

// 0x7100e76460
void Unk_e76460_set(Unk_e76460* self, const Unk_e76460_arg1* value) {
    self->field_5d0 = value->field_0;
}

// 0x7100e76a20
u64 Unk_e76a20() {
    return 0;
}

struct Unk_27e0544_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e0544_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e0544_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e0544_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e0544_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e0544_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e0544_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e0544_Data, field_18, 0x18);

extern Unk_27e0544_Data Unk_27e0544 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100e7b1e0
void Unk_e7b1e0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e0544.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e0544.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e0544.field_18 = 0xffff;
    Unk_27e0544.field_10 = 0;
    Unk_27e0544.field_8 = r2;
    Unk_27e0544.field_c = 0;
    Unk_27e0544.field_14 = 0xffffffff;
}
