// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_34c1e0 {
    u8 _0[0xc0];
    u32 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_34c1e0, field_c0, 0xc0);

class Unk_237f528 {
public:
    u32 vf74();
    u32 vf17();
    u32 vf71();
};

// 0x710034b090
u32 Unk_237f528::vf17() {
    return 1;
}

// 0x710034b130
u32 Unk_237f528::vf71() {
    return 0;
}

// 0x710034c1e0
u32 Unk_237f528::vf74() {
    const Unk_34c1e0* self = reinterpret_cast<const Unk_34c1e0*>(this);
    return self->field_c0;
}
