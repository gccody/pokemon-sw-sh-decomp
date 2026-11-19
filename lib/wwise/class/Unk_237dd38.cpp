// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_31c8a0 {
    u8 _0[0x90];
    u64 field_90;
};
PKMN_OFFSET_ASSERT(Unk_31c8a0, field_90, 0x90);

struct Unk_31cba0 {
    u8 _0[0xe0];
    u8 field_e0;
};
PKMN_OFFSET_ASSERT(Unk_31cba0, field_e0, 0xe0);

class Unk_237dd38 {
public:
    u64 vf22();
    u8 vf29();
    void vf34();
    void vf35();
};

// 0x710031c8a0
u64 Unk_237dd38::vf22() {
    const Unk_31c8a0* self = reinterpret_cast<const Unk_31c8a0*>(this);
    return self->field_90;
}

// 0x710031cb80
void Unk_237dd38::vf34() {
}

// 0x710031cb90
void Unk_237dd38::vf35() {
}

// 0x710031cba0
u8 Unk_237dd38::vf29() {
    const Unk_31cba0* self = reinterpret_cast<const Unk_31cba0*>(this);
    return self->field_e0;
}
