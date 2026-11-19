// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3d5990 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_3d5990, field_10, 0x10);

struct Unk_3d59a0 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_3d59a0, field_20, 0x20);

struct Unk_3d59b0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_3d59b0, field_18, 0x18);

struct Unk_3d59c0 {
    u8 _0[0x40];
    f32 field_40;
};
PKMN_OFFSET_ASSERT(Unk_3d59c0, field_40, 0x40);

class Unk_23847d8 {
public:
    u64 vf2();
    u64 vf3();
    u64 vf4();
    f32 vf5();
};

// 0x71003d5990
u64 Unk_23847d8::vf2() {
    const Unk_3d5990* self = reinterpret_cast<const Unk_3d5990*>(this);
    return self->field_10;
}

// 0x71003d59a0
u64 Unk_23847d8::vf3() {
    const Unk_3d59a0* self = reinterpret_cast<const Unk_3d59a0*>(this);
    return self->field_20;
}

// 0x71003d59b0
u64 Unk_23847d8::vf4() {
    const Unk_3d59b0* self = reinterpret_cast<const Unk_3d59b0*>(this);
    return self->field_18;
}

// 0x71003d59c0
f32 Unk_23847d8::vf5() {
    const Unk_3d59c0* self = reinterpret_cast<const Unk_3d59c0*>(this);
    return self->field_40;
}
