// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8ec4c0 {
    u8 _0[0x42];
    u8 field_42;
};
PKMN_OFFSET_ASSERT(Unk_8ec4c0, field_42, 0x42);

// 0x71008ec4c0
u8 Unk_8ec4c0_getField42(const Unk_8ec4c0* self) {
    return self->field_42;
}

struct Unk_8ec540 {
    u8 _0[0x3a];
    u8 field_3a;
};
PKMN_OFFSET_ASSERT(Unk_8ec540, field_3a, 0x3a);

// 0x71008ec540
u8 Unk_8ec540_getField3a(const Unk_8ec540* self) {
    return self->field_3a;
}
