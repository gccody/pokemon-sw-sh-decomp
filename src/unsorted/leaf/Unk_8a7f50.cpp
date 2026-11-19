// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8a7f50 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_8a7f50, field_8, 0x8);

// 0x71008a7f50
void Unk_8a7f50_clearField8(Unk_8a7f50* self) {
    self->field_8 = 0;
}

struct Unk_8a7f60 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_8a7f60, field_8, 0x8);

// 0x71008a7f60
void Unk_8a7f60_setField8(Unk_8a7f60* self, u32 value) {
    self->field_8 = value;
}

struct Unk_8a7f70 {
    u8 _0[0xc];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_8a7f70, field_c, 0xc);

// 0x71008a7f70
void Unk_8a7f70_setFieldc(Unk_8a7f70* self, u32 value) {
    self->field_c = value;
}

struct Unk_8a7f80 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_8a7f80, field_8, 0x8);

// 0x71008a7f80
u32 Unk_8a7f80_getField8(const Unk_8a7f80* self) {
    return self->field_8;
}

struct Unk_8a7f90 {
    u8 _0[0xc];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_8a7f90, field_c, 0xc);

// 0x71008a7f90
u32 Unk_8a7f90_getFieldc(const Unk_8a7f90* self) {
    return self->field_c;
}

struct Unk_8a8010 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_8a8010, field_10, 0x10);

// 0x71008a8010
u8 Unk_8a8010_getField10(const Unk_8a8010* self) {
    return self->field_10;
}

struct Unk_8a8020 {
    u8 _0[0x11];
    u8 field_11;
};
PKMN_OFFSET_ASSERT(Unk_8a8020, field_11, 0x11);

// 0x71008a8020
void Unk_8a8020_set(Unk_8a8020* self) {
    self->field_11 = 1;
}

struct Unk_8a80e0 {
    u8 _0[0x31];
    u8 field_31;
};
PKMN_OFFSET_ASSERT(Unk_8a80e0, field_31, 0x31);

// 0x71008a80e0
void Unk_8a80e0_set(Unk_8a80e0* self) {
    if (self->field_31 != 0) {
        self->field_31 = self->field_31 - 1;
    }
}

struct Unk_8a8100 {
    u8 _0[0x33];
    bool field_33;
};
PKMN_OFFSET_ASSERT(Unk_8a8100, field_33, 0x33);

// 0x71008a8100
void Unk_8a8100_set(Unk_8a8100* self, bool value) {
    self->field_33 = value;
}

struct Unk_8a8110 {
    u8 _0[0x33];
    u8 field_33;
};
PKMN_OFFSET_ASSERT(Unk_8a8110, field_33, 0x33);

// 0x71008a8110
bool Unk_8a8110_check(const Unk_8a8110* self) {
    return self->field_33 != 0;
}

// 0x71008a8250
void Unk_8a8250() {}

extern u64 Unk_27d1300;

// 0x71008a82d0
u64 Unk_8a82d0_get() {
    return Unk_27d1300;
}

struct Unk_27d130c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27d130c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27d130c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27d130c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27d130c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27d130c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27d130c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27d130c_Data, field_18, 0x18);

extern Unk_27d130c_Data Unk_27d130c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71008a8800
void Unk_8a8800_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27d130c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27d130c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27d130c.field_18 = 0xffff;
    Unk_27d130c.field_10 = 0;
    Unk_27d130c.field_8 = r2;
    Unk_27d130c.field_c = 0;
    Unk_27d130c.field_14 = 0xffffffff;
}
