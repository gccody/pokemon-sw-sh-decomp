// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

u32 Unk_eb6530();

// 0x7100f4e980
u32 Unk_f4e980_call() {
    u32 r0 = Unk_eb6530();
    return ~r0 & 1;
}

struct Unk_f4eb00 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_f4eb00, field_5cc, 0x5cc);

// 0x7100f4eb00
void Unk_f4eb00_clearField5cc(Unk_f4eb00* self) {
    self->field_5cc = 0;
}

struct Unk_f4eb10 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_f4eb10, field_5cc, 0x5cc);

// 0x7100f4eb10
u32 Unk_f4eb10_getField5cc(const Unk_f4eb10* self) {
    return self->field_5cc;
}

struct Unk_27e13b4_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e13b4_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e13b4_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e13b4_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e13b4_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e13b4_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e13b4_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e13b4_Data, field_18, 0x18);

extern Unk_27e13b4_Data Unk_27e13b4 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100f4fa10
void Unk_f4fa10_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e13b4.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e13b4.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e13b4.field_18 = 0xffff;
    Unk_27e13b4.field_10 = 0;
    Unk_27e13b4.field_8 = r2;
    Unk_27e13b4.field_c = 0;
    Unk_27e13b4.field_14 = 0xffffffff;
}
