// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3d57b0 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_3d57b0, field_78, 0x78);

extern u32 Unk_2382e78;

struct Unk_3d57e0_70 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_3d57e0_70, field_10, 0x10);

struct Unk_3d57e0 {
    u8 _0[0x70];
    Unk_3d57e0_70* field_70;
};
PKMN_OFFSET_ASSERT(Unk_3d57e0, field_70, 0x70);

class Unk_23842a8 {
public:
    u64 vf2();
    u32 vf22();
    u32 vf26();
    u32 vf27();
    u32 vf28();
    u32 vf30();
    u32 vf31();
    void vf39();
    u32 vf7();
    u32 vf8();
    u32 vf9();
    u32 vf13();
};

// 0x71003d2fb0
u32 Unk_23842a8::vf26() {
    return 2;
}

// 0x71003d2fc0
u32 Unk_23842a8::vf7() {
    return 2;
}

// 0x71003d2fd0
u32 Unk_23842a8::vf27() {
    return 0;
}

// 0x71003d2fe0
u32 Unk_23842a8::vf8() {
    return 0;
}

// 0x71003d2ff0
u32 Unk_23842a8::vf28() {
    return 2;
}

// 0x71003d3000
u32 Unk_23842a8::vf9() {
    return 2;
}

// 0x71003d31d0
u32 Unk_23842a8::vf31() {
    return 0;
}

// 0x71003d31e0
u32 Unk_23842a8::vf13() {
    return 0;
}

// 0x71003d57b0
u64 Unk_23842a8::vf2() {
    const Unk_3d57b0* self = reinterpret_cast<const Unk_3d57b0*>(this);
    return self->field_78;
}

// 0x71003d57d0
u32 Unk_23842a8::vf22() {
    return Unk_2382e78;
}

// 0x71003d57e0
u32 Unk_23842a8::vf30() {
    const Unk_3d57e0* self = reinterpret_cast<const Unk_3d57e0*>(this);
    if (self->field_70 == nullptr) {
        return 0;
    }
    return self->field_70->field_10;
}

// 0x71003d5800
void Unk_23842a8::vf39() {
}
