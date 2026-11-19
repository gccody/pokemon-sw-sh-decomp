// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1048890 {
    u8 _0[0x118];
    u8 field_118;
};
PKMN_OFFSET_ASSERT(Unk_1048890, field_118, 0x118);

// 0x7101048890
u8* Unk_1048890_getField118Ptr(Unk_1048890* self) {
    return &self->field_118;
}

struct Unk_10488a0 {
    u8 _0[0x100];
    u8 field_100;
};
PKMN_OFFSET_ASSERT(Unk_10488a0, field_100, 0x100);

// 0x71010488a0
u8* Unk_10488a0_getField100Ptr(Unk_10488a0* self) {
    return &self->field_100;
}

// 0x71010488b0
void Unk_10488b0() {}

// 0x71010489f0
void Unk_10489f0() {}

struct Unk_27e3734_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e3734_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e3734_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e3734_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e3734_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e3734_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e3734_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e3734_Data, field_18, 0x18);

extern Unk_27e3734_Data Unk_27e3734 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7101048a00
void Unk_1048a00_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e3734.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e3734.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e3734.field_10 = 0xffff;
    Unk_27e3734.field_8 = r2;
    Unk_27e3734.field_c = 0xffffffff;
    Unk_27e3734.field_18 = 0;
    Unk_27e3734.field_14 = 0;
}
