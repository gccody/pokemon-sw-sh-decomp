// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_6a4020 {
    u8 _0[0xb8];
    u64 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_6a4020, field_b8, 0xb8);

// 0x71006a4020
u64 Unk_6a4020_getFieldb8(const Unk_6a4020* self) {
    return self->field_b8;
}

struct Unk_6a4100 {
    u8 _0[0xc0];
    u64 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_6a4100, field_c0, 0xc0);

// 0x71006a4100
u64 Unk_6a4100_getFieldc0(const Unk_6a4100* self) {
    return self->field_c0;
}

struct Unk_6a41e0 {
    u8 _0[0xc8];
    u64 field_c8;
};
PKMN_OFFSET_ASSERT(Unk_6a41e0, field_c8, 0xc8);

// 0x71006a41e0
u64 Unk_6a41e0_getFieldc8(const Unk_6a41e0* self) {
    return self->field_c8;
}

struct Unk_6a42c0 {
    u8 _0[0xd0];
    u64 field_d0;
};
PKMN_OFFSET_ASSERT(Unk_6a42c0, field_d0, 0xd0);

// 0x71006a42c0
u64 Unk_6a42c0_getFieldd0(const Unk_6a42c0* self) {
    return self->field_d0;
}

struct Unk_6a43a0 {
    u8 _0[0xd8];
    u64 field_d8;
};
PKMN_OFFSET_ASSERT(Unk_6a43a0, field_d8, 0xd8);

// 0x71006a43a0
u64 Unk_6a43a0_getFieldd8(const Unk_6a43a0* self) {
    return self->field_d8;
}

struct Unk_6a4480 {
    u8 _0[0xe0];
    u64 field_e0;
};
PKMN_OFFSET_ASSERT(Unk_6a4480, field_e0, 0xe0);

// 0x71006a4480
u64 Unk_6a4480_getFielde0(const Unk_6a4480* self) {
    return self->field_e0;
}

struct Unk_6a4b80 {
    u8 _0[0x91];
    u8 field_91;
};
PKMN_OFFSET_ASSERT(Unk_6a4b80, field_91, 0x91);

// 0x71006a4b80
u8 Unk_6a4b80_getField91(const Unk_6a4b80* self) {
    return self->field_91;
}

struct Unk_6a4b90 {
    u8 _0[0x93];
    u8 field_93;
};
PKMN_OFFSET_ASSERT(Unk_6a4b90, field_93, 0x93);

// 0x71006a4b90
u8 Unk_6a4b90_getField93(const Unk_6a4b90* self) {
    return self->field_93;
}

struct Unk_6a4cc0 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_6a4cc0, field_b0, 0xb0);

void Unk_163ece0(u64);

// 0x71006a4cc0
void Unk_6a4cc0_call(const Unk_6a4cc0* self) {
    if (self->field_b0 != 0) {
        Unk_163ece0(self->field_b0);
    }
}

struct Unk_6a4cd0 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_6a4cd0, field_b0, 0xb0);

void Unk_163ecf0(u64);

// 0x71006a4cd0
void Unk_6a4cd0_call(const Unk_6a4cd0* self) {
    if (self->field_b0 != 0) {
        Unk_163ecf0(self->field_b0);
    }
}

struct Unk_6a4d30_b0 {
    u8 _0[0xc0];
    u64 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_6a4d30_b0, field_c0, 0xc0);

struct Unk_6a4d30 {
    u8 _0[0xb0];
    Unk_6a4d30_b0* field_b0;
};
PKMN_OFFSET_ASSERT(Unk_6a4d30, field_b0, 0xb0);

// 0x71006a4d30
u64 Unk_6a4d30_get(const Unk_6a4d30* self) {
    if (self->field_b0 == nullptr) {
        return 0;
    }
    return self->field_b0->field_c0;
}

struct Unk_6a4d50 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_6a4d50, field_b0, 0xb0);

// 0x71006a4d50
u64 Unk_6a4d50_getFieldb0(const Unk_6a4d50* self) {
    return self->field_b0;
}

// 0x71006a5220
void Unk_6a5220_update() {}

struct Unk_2778d2c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_2778d2c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_2778d2c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_2778d2c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_2778d2c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_2778d2c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_2778d2c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_2778d2c_Data, field_18, 0x18);

extern Unk_2778d2c_Data Unk_2778d2c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71006a56f0
void Unk_6a56f0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_2778d2c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_2778d2c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_2778d2c.field_10 = 0xffff;
    Unk_2778d2c.field_8 = r2;
    Unk_2778d2c.field_c = 0xffffffff;
    Unk_2778d2c.field_18 = 0;
    Unk_2778d2c.field_14 = 0;
}
