// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3d11c0_20_10 {
    u8 _0[0x48];
    u64 field_48;
};
PKMN_OFFSET_ASSERT(Unk_3d11c0_20_10, field_48, 0x48);

struct Unk_3d11c0_20 {
    u8 _0[0x10];
    Unk_3d11c0_20_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_3d11c0_20, field_10, 0x10);

struct Unk_3d11c0 {
    u8 _0[0x20];
    Unk_3d11c0_20* field_20;
};
PKMN_OFFSET_ASSERT(Unk_3d11c0, field_20, 0x20);

struct Unk_3d11f0_20_10_38_0 {
    u8 _0[0x38];
    u16 field_38;
};
PKMN_OFFSET_ASSERT(Unk_3d11f0_20_10_38_0, field_38, 0x38);

struct Unk_3d11f0_20_10_38 {
    Unk_3d11f0_20_10_38_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_3d11f0_20_10_38, field_0, 0x0);

struct Unk_3d11f0_20_10 {
    u8 _0[0x38];
    Unk_3d11f0_20_10_38* field_38;
};
PKMN_OFFSET_ASSERT(Unk_3d11f0_20_10, field_38, 0x38);

struct Unk_3d11f0_20 {
    u8 _0[0x10];
    Unk_3d11f0_20_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_3d11f0_20, field_10, 0x10);

struct Unk_3d11f0 {
    u8 _0[0x20];
    Unk_3d11f0_20* field_20;
};
PKMN_OFFSET_ASSERT(Unk_3d11f0, field_20, 0x20);

struct Unk_3d1220_20_10_38_0 {
    u8 _0[0x3a];
    u8 field_3a;
};
PKMN_OFFSET_ASSERT(Unk_3d1220_20_10_38_0, field_3a, 0x3a);

struct Unk_3d1220_20_10_38 {
    Unk_3d1220_20_10_38_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_3d1220_20_10_38, field_0, 0x0);

struct Unk_3d1220_20_10 {
    u8 _0[0x38];
    Unk_3d1220_20_10_38* field_38;
};
PKMN_OFFSET_ASSERT(Unk_3d1220_20_10, field_38, 0x38);

struct Unk_3d1220_20 {
    u8 _0[0x10];
    Unk_3d1220_20_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_3d1220_20, field_10, 0x10);

struct Unk_3d1220 {
    u8 _0[0x20];
    Unk_3d1220_20* field_20;
};
PKMN_OFFSET_ASSERT(Unk_3d1220, field_20, 0x20);

struct Unk_3d1240_20_10_38_0 {
    u8 _0[0x40];
    f32 field_40;
};
PKMN_OFFSET_ASSERT(Unk_3d1240_20_10_38_0, field_40, 0x40);

struct Unk_3d1240_20_10_38 {
    Unk_3d1240_20_10_38_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_3d1240_20_10_38, field_0, 0x0);

struct Unk_3d1240_20_10 {
    u8 _0[0x38];
    Unk_3d1240_20_10_38* field_38;
};
PKMN_OFFSET_ASSERT(Unk_3d1240_20_10, field_38, 0x38);

struct Unk_3d1240_20 {
    u8 _0[0x10];
    Unk_3d1240_20_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_3d1240_20, field_10, 0x10);

struct Unk_3d1240 {
    u8 _0[0x20];
    Unk_3d1240_20* field_20;
};
PKMN_OFFSET_ASSERT(Unk_3d1240, field_20, 0x20);

class Unk_23841b0 {
public:
    u64 vf2();
    u16 vf5();
    u32 vf7();
    f32 vf8();
};

// 0x71003d11c0
u64 Unk_23841b0::vf2() {
    const Unk_3d11c0* self = reinterpret_cast<const Unk_3d11c0*>(this);
    return self->field_20->field_10->field_48;
}

// 0x71003d11f0
u16 Unk_23841b0::vf5() {
    const Unk_3d11f0* self = reinterpret_cast<const Unk_3d11f0*>(this);
    return self->field_20->field_10->field_38->field_0->field_38;
}

// 0x71003d1220
u32 Unk_23841b0::vf7() {
    const Unk_3d1220* self = reinterpret_cast<const Unk_3d1220*>(this);
    return self->field_20->field_10->field_38->field_0->field_3a & 7;
}

// 0x71003d1240
f32 Unk_23841b0::vf8() {
    const Unk_3d1240* self = reinterpret_cast<const Unk_3d1240*>(this);
    return self->field_20->field_10->field_38->field_0->field_40;
}
