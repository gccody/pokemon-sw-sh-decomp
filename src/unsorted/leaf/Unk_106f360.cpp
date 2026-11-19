// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_106f360 {
    u8 _0[0x1c];
    u8 field_1c;
};
PKMN_OFFSET_ASSERT(Unk_106f360, field_1c, 0x1c);

// 0x710106f360
u8 Unk_106f360_getField1c(const Unk_106f360* self) {
    return self->field_1c;
}

struct Unk_106f370 {
    u8 _0[0x1d];
    u8 field_1d;
};
PKMN_OFFSET_ASSERT(Unk_106f370, field_1d, 0x1d);

// 0x710106f370
u8 Unk_106f370_getField1d(const Unk_106f370* self) {
    return self->field_1d;
}

struct Unk_106f380 {
    u8 _0[0x1e];
    u8 field_1e;
};
PKMN_OFFSET_ASSERT(Unk_106f380, field_1e, 0x1e);

// 0x710106f380
u8 Unk_106f380_getField1e(const Unk_106f380* self) {
    return self->field_1e;
}

struct Unk_106f390 {
    u8 _0[0x1f];
    u8 field_1f;
};
PKMN_OFFSET_ASSERT(Unk_106f390, field_1f, 0x1f);

// 0x710106f390
u8 Unk_106f390_getField1f(const Unk_106f390* self) {
    return self->field_1f;
}

struct Unk_106f3a0 {
    u8 _0[0x20];
    u8 field_20;
};
PKMN_OFFSET_ASSERT(Unk_106f3a0, field_20, 0x20);

// 0x710106f3a0
u8 Unk_106f3a0_getField20(const Unk_106f3a0* self) {
    return self->field_20;
}

struct Unk_106f3b0 {
    u8 _0[0x21];
    u8 field_21;
};
PKMN_OFFSET_ASSERT(Unk_106f3b0, field_21, 0x21);

// 0x710106f3b0
u8 Unk_106f3b0_getField21(const Unk_106f3b0* self) {
    return self->field_21;
}

struct Unk_106f3c0 {
    u8 _0[0x24];
    u32 field_24;
};
PKMN_OFFSET_ASSERT(Unk_106f3c0, field_24, 0x24);

// 0x710106f3c0
u32 Unk_106f3c0_getField24(const Unk_106f3c0* self) {
    return self->field_24;
}

struct Unk_106f3d0 {
    u8 _0[0x28];
    u16 field_28;
};
PKMN_OFFSET_ASSERT(Unk_106f3d0, field_28, 0x28);

// 0x710106f3d0
u16 Unk_106f3d0_getField28(const Unk_106f3d0* self) {
    return self->field_28;
}

struct Unk_106f3e0 {
    u8 _0[0x2a];
    u8 field_2a;
};
PKMN_OFFSET_ASSERT(Unk_106f3e0, field_2a, 0x2a);

// 0x710106f3e0
u8 Unk_106f3e0_getField2a(const Unk_106f3e0* self) {
    return self->field_2a;
}

struct Unk_106f3f0 {
    u8 _0[0x2b];
    u8 field_2b;
};
PKMN_OFFSET_ASSERT(Unk_106f3f0, field_2b, 0x2b);

// 0x710106f3f0
u8 Unk_106f3f0_getField2b(const Unk_106f3f0* self) {
    return self->field_2b;
}

struct Unk_27e3c94_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e3c94_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e3c94_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e3c94_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e3c94_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e3c94_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e3c94_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e3c94_Data, field_18, 0x18);

extern Unk_27e3c94_Data Unk_27e3c94 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x710106f830
void Unk_106f830_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e3c94.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e3c94.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e3c94.field_10 = 0xffff;
    Unk_27e3c94.field_8 = r2;
    Unk_27e3c94.field_c = 0xffffffff;
    Unk_27e3c94.field_18 = 0;
    Unk_27e3c94.field_14 = 0;
}
