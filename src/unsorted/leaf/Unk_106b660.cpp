// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_106b660_arg1 {
    u32 field_0;
    u16 field_4;
};
PKMN_OFFSET_ASSERT(Unk_106b660_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_106b660_arg1, field_4, 0x4);

struct Unk_106b660 {
    u32 field_0;
    u16 field_4;
};
PKMN_OFFSET_ASSERT(Unk_106b660, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_106b660, field_4, 0x4);

// 0x710106b660
bool Unk_106b660_check(const Unk_106b660* self, const Unk_106b660_arg1* value) {
    if (self->field_0 != value->field_0) {
        return false;
    }
    return self->field_4 == value->field_4;
}

struct Unk_106b690 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_106b690, field_0, 0x0);

// 0x710106b690
u32 Unk_106b690_getField0(const Unk_106b690* self) {
    return self->field_0;
}

struct Unk_106b6a0 {
    u8 _0[0x4];
    u16 field_4;
};
PKMN_OFFSET_ASSERT(Unk_106b6a0, field_4, 0x4);

// 0x710106b6a0
u16 Unk_106b6a0_getField4(const Unk_106b6a0* self) {
    return self->field_4;
}

struct Unk_27e3b94_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e3b94_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e3b94_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e3b94_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e3b94_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e3b94_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e3b94_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e3b94_Data, field_18, 0x18);

extern Unk_27e3b94_Data Unk_27e3b94 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x710106b740
void Unk_106b740_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e3b94.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e3b94.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e3b94.field_10 = 0xffff;
    Unk_27e3b94.field_8 = r2;
    Unk_27e3b94.field_c = 0xffffffff;
    Unk_27e3b94.field_18 = 0;
    Unk_27e3b94.field_14 = 0;
}
