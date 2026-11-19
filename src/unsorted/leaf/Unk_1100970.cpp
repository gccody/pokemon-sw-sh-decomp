// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1100970 {
    u8 _0[0x60];
    u8 field_60;
    u8 _61[0xf];
    u64 field_70;
    u8 field_78;
    u8 _79[0x3];
    u32 field_7c;
};
PKMN_OFFSET_ASSERT(Unk_1100970, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_1100970, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_1100970, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_1100970, field_7c, 0x7c);
void Unk_1100840(void*, u64);

// 0x7101100970
void Unk_1100970_call(Unk_1100970* self, u32 value, u64 arg2) {
    if ((value & 0xff) != 0) {
        Unk_1100840(&self->field_60, arg2);
        self->field_7c = 0;
        self->field_78 = 1;
        return;
    }
    Unk_1100840(&self->field_60, self->field_70);
    self->field_7c = 0;
    self->field_78 = 1;
}

struct Unk_11009c0 {
    u8 _0[0x78];
    u8 field_78;
};
PKMN_OFFSET_ASSERT(Unk_11009c0, field_78, 0x78);

// 0x71011009c0
void Unk_11009c0_clearField78(Unk_11009c0* self) {
    self->field_78 = 0;
}

struct Unk_27e50ec_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e50ec_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e50ec_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e50ec_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e50ec_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e50ec_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e50ec_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e50ec_Data, field_18, 0x18);

extern Unk_27e50ec_Data Unk_27e50ec __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7101100a20
void Unk_1100a20_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e50ec.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e50ec.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e50ec.field_10 = 0xffff;
    Unk_27e50ec.field_8 = r2;
    Unk_27e50ec.field_c = 0xffffffff;
    Unk_27e50ec.field_18 = 0;
    Unk_27e50ec.field_14 = 0;
}
