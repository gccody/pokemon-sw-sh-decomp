// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x710106de90
void Unk_106de90() {}

struct Unk_106dea0 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_106dea0, field_10, 0x10);

// 0x710106dea0
u8* Unk_106dea0_getField10Ptr(Unk_106dea0* self) {
    return &self->field_10;
}

struct Unk_106deb0 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_106deb0, field_20, 0x20);

// 0x710106deb0
u64 Unk_106deb0_getField20(const Unk_106deb0* self) {
    return self->field_20;
}

// 0x710106dfd0
void Unk_106dfd0() {}
