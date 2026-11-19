// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x710106b070
void Unk_106b070() {}

struct Unk_106b080 {
    u8 _0[0x28];
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_106b080, field_28, 0x28);

// 0x710106b080
u8* Unk_106b080_getField28Ptr(Unk_106b080* self) {
    return &self->field_28;
}

struct Unk_106b090 {
    u8 _0[0x38];
    u8 field_38;
};
PKMN_OFFSET_ASSERT(Unk_106b090, field_38, 0x38);

// 0x710106b090
u8* Unk_106b090_getField38Ptr(Unk_106b090* self) {
    return &self->field_38;
}

struct Unk_106b4d0 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_106b4d0, field_8, 0x8);

// 0x710106b4d0
u64 Unk_106b4d0_getField8(const Unk_106b4d0* self) {
    return self->field_8;
}

struct Unk_106b4e0 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_106b4e0, field_10, 0x10);

// 0x710106b4e0
u64 Unk_106b4e0_getField10(const Unk_106b4e0* self) {
    return self->field_10;
}

struct Unk_106b4f0 {
    u8 _0[0x8];
    u64 field_8;
    u64 field_10;
    u8 _18[0x20];
    u64 field_38;
    u64 field_40;
};
PKMN_OFFSET_ASSERT(Unk_106b4f0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_106b4f0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_106b4f0, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_106b4f0, field_40, 0x40);

// 0x710106b4f0
void Unk_106b4f0_set(Unk_106b4f0* self) {
    self->field_10 = self->field_8;
    self->field_40 = self->field_38;
}

struct Unk_106b510 {
    u8 _0[0x38];
    u64 field_38;
    u64 field_40;
};
PKMN_OFFSET_ASSERT(Unk_106b510, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_106b510, field_40, 0x40);

// 0x710106b510
void Unk_106b510_set(Unk_106b510* self) {
    self->field_40 = self->field_38;
}

struct Unk_27e3b74_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e3b74_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e3b74_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e3b74_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e3b74_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e3b74_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e3b74_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e3b74_Data, field_18, 0x18);

extern Unk_27e3b74_Data Unk_27e3b74 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x710106b520
void Unk_106b520_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e3b74.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e3b74.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e3b74.field_10 = 0xffff;
    Unk_27e3b74.field_8 = r2;
    Unk_27e3b74.field_c = 0xffffffff;
    Unk_27e3b74.field_18 = 0;
    Unk_27e3b74.field_14 = 0;
}
