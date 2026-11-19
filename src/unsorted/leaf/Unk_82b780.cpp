// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_82b780 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_82b780, field_0, 0x0);

// 0x710082b780
void Unk_82b780_clearField0(Unk_82b780* self) {
    self->field_0 = 0;
}

struct Unk_82b790 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_82b790, field_0, 0x0);

// 0x710082b790
void Unk_82b790_clearField0(Unk_82b790* self) {
    self->field_0 = 0;
}

struct Unk_82b7a0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_82b7a0, field_0, 0x0);

// 0x710082b7a0
void Unk_82b7a0_setField0(Unk_82b7a0* self, u8 value) {
    self->field_0 = value;
}

struct Unk_82b7b0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_82b7b0, field_0, 0x0);

// 0x710082b7b0
bool Unk_82b7b0_check(const Unk_82b7b0* self, u8 value) {
    return self->field_0 == (value);
}

struct Unk_82b7c0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_82b7c0, field_0, 0x0);

// 0x710082b7c0
bool Unk_82b7c0_check(const Unk_82b7c0* self) {
    return self->field_0 != 0;
}

struct Unk_82b7d0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_82b7d0, field_0, 0x0);

// 0x710082b7d0
u8 Unk_82b7d0_getField0(const Unk_82b7d0* self) {
    return self->field_0;
}

struct Unk_27cf104_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27cf104_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27cf104_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27cf104_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27cf104_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27cf104_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27cf104_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27cf104_Data, field_18, 0x18);

extern Unk_27cf104_Data Unk_27cf104 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x710082bd40
void Unk_82bd40_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27cf104.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27cf104.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27cf104.field_18 = 0xffff;
    Unk_27cf104.field_10 = 0;
    Unk_27cf104.field_8 = r2;
    Unk_27cf104.field_c = 0;
    Unk_27cf104.field_14 = 0xffffffff;
}
