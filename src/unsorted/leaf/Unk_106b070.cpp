// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x710106b070
void Unk_106b070() {}

struct Unk_106b080 {
    u8 _0[0x28];
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_106b080, field_28, 0x28);

// 0x710106b080
u8* Unk_106b080_getField28Ptr(Unk_106b080* self) {
    return &self->field_28;
}

struct Unk_106b090 {
    u8 _0[0x38];
    u8 field_38;
};
PKMN_OFFSET_ASSERT(Unk_106b090, field_38, 0x38);

// 0x710106b090
u8* Unk_106b090_getField38Ptr(Unk_106b090* self) {
    return &self->field_38;
}

struct Unk_106b4d0 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_106b4d0, field_8, 0x8);

// 0x710106b4d0
u64 Unk_106b4d0_getField8(const Unk_106b4d0* self) {
    return self->field_8;
}

struct Unk_106b4e0 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_106b4e0, field_10, 0x10);

// 0x710106b4e0
u64 Unk_106b4e0_getField10(const Unk_106b4e0* self) {
    return self->field_10;
}
