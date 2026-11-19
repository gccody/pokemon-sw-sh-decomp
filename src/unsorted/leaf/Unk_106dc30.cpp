// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_106dc30 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_106dc30, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_106dc30, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_106dc30, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_106dc30, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_106dc30, field_20, 0x20);

// 0x710106dc30
void Unk_106dc30_set(Unk_106dc30* self) {
    self->field_18 = 0;
    self->field_20 = 0;
    self->field_0 = 0;
    self->field_8 = 0;
    self->field_10 = 0;
}

// 0x710106de90
void Unk_106de90() {}

struct Unk_106dea0 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_106dea0, field_10, 0x10);

// 0x710106dea0
u8* Unk_106dea0_getField10Ptr(Unk_106dea0* self) {
    return &self->field_10;
}

struct Unk_106deb0 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_106deb0, field_20, 0x20);

// 0x710106deb0
u64 Unk_106deb0_getField20(const Unk_106deb0* self) {
    return self->field_20;
}

// 0x710106dfd0
void Unk_106dfd0() {}

struct Unk_27e3c34_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e3c34_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e3c34_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e3c34_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e3c34_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e3c34_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e3c34_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e3c34_Data, field_18, 0x18);

extern Unk_27e3c34_Data Unk_27e3c34 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x710106e0a0
void Unk_106e0a0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e3c34.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e3c34.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e3c34.field_10 = 0xffff;
    Unk_27e3c34.field_8 = r2;
    Unk_27e3c34.field_c = 0xffffffff;
    Unk_27e3c34.field_18 = 0;
    Unk_27e3c34.field_14 = 0;
}
