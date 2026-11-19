// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_106e9f0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_106e9f0, field_0, 0x0);

// 0x710106e9f0
bool Unk_106e9f0_check(const Unk_106e9f0* self) {
    return self->field_0 != 0xff;
}

struct Unk_106ea00 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_106ea00, field_0, 0x0);

// 0x710106ea00
u8 Unk_106ea00_getField0(const Unk_106ea00* self) {
    return self->field_0;
}

struct Unk_106ea10 {
    u8 _0[0x4];
    u8 field_4;
};
PKMN_OFFSET_ASSERT(Unk_106ea10, field_4, 0x4);

// 0x710106ea10
u8* Unk_106ea10_getField4Ptr(Unk_106ea10* self) {
    return &self->field_4;
}

struct Unk_106ea20 {
    u8 _0[0x24];
    u8 field_24;
};
PKMN_OFFSET_ASSERT(Unk_106ea20, field_24, 0x24);

// 0x710106ea20
u8* Unk_106ea20_getField24Ptr(Unk_106ea20* self) {
    return &self->field_24;
}

struct Unk_106ea30 {
    u8 _0[0x40];
    u32 field_40;
};
PKMN_OFFSET_ASSERT(Unk_106ea30, field_40, 0x40);

// 0x710106ea30
u32 Unk_106ea30_getField40(const Unk_106ea30* self) {
    return self->field_40;
}

struct Unk_106ea40 {
    u8 _0[0x44];
    u8 field_44;
};
PKMN_OFFSET_ASSERT(Unk_106ea40, field_44, 0x44);

// 0x710106ea40
u8 Unk_106ea40_getField44(const Unk_106ea40* self) {
    return self->field_44;
}

struct Unk_106eab0 {
    u8 _0[0x45];
    u8 field_45;
};
PKMN_OFFSET_ASSERT(Unk_106eab0, field_45, 0x45);

// 0x710106eab0
u8 Unk_106eab0_getField45(const Unk_106eab0* self) {
    return self->field_45;
}

struct Unk_106eac0 {
    u8 _0[0x45];
    u8 field_45;
};
PKMN_OFFSET_ASSERT(Unk_106eac0, field_45, 0x45);

// 0x710106eac0
void Unk_106eac0_setField45(Unk_106eac0* self, u8 value) {
    self->field_45 = value;
}

struct Unk_106ead0 {
    u8 _0[0x46];
    u16 field_46;
};
PKMN_OFFSET_ASSERT(Unk_106ead0, field_46, 0x46);

// 0x710106ead0
u16 Unk_106ead0_getField46(const Unk_106ead0* self) {
    return self->field_46;
}

struct Unk_106eae0 {
    u8 _0[0x46];
    u16 field_46;
};
PKMN_OFFSET_ASSERT(Unk_106eae0, field_46, 0x46);

// 0x710106eae0
void Unk_106eae0_setField46(Unk_106eae0* self, u16 value) {
    self->field_46 = value;
}

struct Unk_106eaf0 {
    u8 _0[0x48];
    u8 field_48;
};
PKMN_OFFSET_ASSERT(Unk_106eaf0, field_48, 0x48);

// 0x710106eaf0
u8 Unk_106eaf0_getField48(const Unk_106eaf0* self) {
    return self->field_48;
}

struct Unk_106eb00 {
    u8 _0[0x48];
    bool field_48;
};
PKMN_OFFSET_ASSERT(Unk_106eb00, field_48, 0x48);

// 0x710106eb00
void Unk_106eb00_set(Unk_106eb00* self, bool value) {
    self->field_48 = value;
}

struct Unk_106eb10 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_106eb10, field_0, 0x0);

// 0x710106eb10
bool Unk_106eb10_check(const Unk_106eb10* self) {
    return self->field_0 >= 0x11 && self->field_0 <= 0x1a;
}

struct Unk_27e3c74_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e3c74_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e3c74_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e3c74_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e3c74_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e3c74_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e3c74_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e3c74_Data, field_18, 0x18);

extern Unk_27e3c74_Data Unk_27e3c74 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x710106eea0
void Unk_106eea0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e3c74.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e3c74.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e3c74.field_10 = 0xffff;
    Unk_27e3c74.field_8 = r2;
    Unk_27e3c74.field_c = 0xffffffff;
    Unk_27e3c74.field_18 = 0;
    Unk_27e3c74.field_14 = 0;
}
