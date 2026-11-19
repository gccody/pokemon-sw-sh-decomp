// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_812cf0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_812cf0, field_10, 0x10);

// 0x7100812cf0
void Unk_812cf0_clearField10(Unk_812cf0* self) {
    self->field_10 = 0;
}

struct Unk_812db0 {
    u8 _0[0x4];
    u8 field_4;
};
PKMN_OFFSET_ASSERT(Unk_812db0, field_4, 0x4);

// 0x7100812db0
void Unk_812db0_setField4(Unk_812db0* self, u8 value) {
    self->field_4 = value;
}

struct Unk_812dc0 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_812dc0, field_0, 0x0);

// 0x7100812dc0
void Unk_812dc0_setField0(Unk_812dc0* self, u32 value) {
    self->field_0 = value;
}

struct Unk_812dd0 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_812dd0, field_0, 0x0);

// 0x7100812dd0
u32 Unk_812dd0_getField0(const Unk_812dd0* self) {
    return self->field_0;
}

struct Unk_812de0 {
    u8 _0[0x9];
    u8 field_9;
};
PKMN_OFFSET_ASSERT(Unk_812de0, field_9, 0x9);

// 0x7100812de0
void Unk_812de0_set(Unk_812de0* self) {
    self->field_9 = 1;
}

struct Unk_812e10 {
    u8 _0[0x9];
    u8 field_9;
};
PKMN_OFFSET_ASSERT(Unk_812e10, field_9, 0x9);

// 0x7100812e10
u8 Unk_812e10_getField9(const Unk_812e10* self) {
    return self->field_9;
}

struct Unk_812e20 {
    u8 _0[0xa];
    u8 field_a;
};
PKMN_OFFSET_ASSERT(Unk_812e20, field_a, 0xa);

// 0x7100812e20
u8 Unk_812e20_getFielda(const Unk_812e20* self) {
    return self->field_a;
}

struct Unk_812e30 {
    u8 _0[0x6];
    u8 field_6;
};
PKMN_OFFSET_ASSERT(Unk_812e30, field_6, 0x6);

// 0x7100812e30
void Unk_812e30_setField6(Unk_812e30* self, u8 value) {
    self->field_6 = value;
}

struct Unk_812e90 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_812e90, field_10, 0x10);

// 0x7100812e90
bool Unk_812e90_check(const Unk_812e90* self) {
    return (self->field_10 & 0x1f) != 0;
}

struct Unk_812ea0 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_812ea0, field_8, 0x8);

// 0x7100812ea0
void Unk_812ea0_set(Unk_812ea0* self) {
    self->field_8 = 1;
}

struct Unk_812eb0 {
    u8 _0[0xe];
    u8 field_e;
};
PKMN_OFFSET_ASSERT(Unk_812eb0, field_e, 0xe);

// 0x7100812eb0
void Unk_812eb0_set(Unk_812eb0* self) {
    self->field_e = 1;
}

struct Unk_813130 {
    u8 _0[0x4e];
    u8 field_4e;
};
PKMN_OFFSET_ASSERT(Unk_813130, field_4e, 0x4e);

// 0x7100813130
void Unk_813130_clearField4e(Unk_813130* self) {
    self->field_4e = 0;
}

struct Unk_813270 {
    u8 _0[0x4c];
    u8 field_4c;
};
PKMN_OFFSET_ASSERT(Unk_813270, field_4c, 0x4c);

// 0x7100813270
u8 Unk_813270_getField4c(const Unk_813270* self) {
    return self->field_4c;
}

struct Unk_813280 {
    u8 _0[0x4d];
    u8 field_4d;
};
PKMN_OFFSET_ASSERT(Unk_813280, field_4d, 0x4d);

// 0x7100813280
u8 Unk_813280_getField4d(const Unk_813280* self) {
    return self->field_4d;
}

struct Unk_813320 {
    u8 _0[0x4f];
    u8 field_4f;
};
PKMN_OFFSET_ASSERT(Unk_813320, field_4f, 0x4f);

// 0x7100813320
void Unk_813320_setField4f(Unk_813320* self, u8 value) {
    self->field_4f = value;
}

struct Unk_813330 {
    u8 _0[0x4c];
    u8 field_4c;
    u8 field_4d;
    u8 _4e[0x1];
    u8 field_4f;
};
PKMN_OFFSET_ASSERT(Unk_813330, field_4c, 0x4c);
PKMN_OFFSET_ASSERT(Unk_813330, field_4d, 0x4d);
PKMN_OFFSET_ASSERT(Unk_813330, field_4f, 0x4f);

// 0x7100813330
bool Unk_813330_check(const Unk_813330* self) {
    if (self->field_4d == 0) {
        if (self->field_4f != 0) {
            return self->field_4c == 0;
        }
        return 0;
    }
    return self->field_4c == 0;
}

struct Unk_27cef54_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27cef54_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27cef54_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27cef54_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27cef54_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27cef54_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27cef54_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27cef54_Data, field_18, 0x18);

extern Unk_27cef54_Data Unk_27cef54 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100813940
void Unk_813940_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27cef54.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27cef54.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27cef54.field_18 = 0xffff;
    Unk_27cef54.field_10 = 0;
    Unk_27cef54.field_8 = r2;
    Unk_27cef54.field_c = 0;
    Unk_27cef54.field_14 = 0xffffffff;
}
