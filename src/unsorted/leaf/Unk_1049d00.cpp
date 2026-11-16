// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1049d00 {
    u8 _0[0x70];
    u8 field_70;
};
PKMN_OFFSET_ASSERT(Unk_1049d00, field_70, 0x70);

// 0x7101049d00
u8 Unk_1049d00_getField70(const Unk_1049d00* self) {
    return self->field_70;
}

struct Unk_1049d10 {
    u8 _0[0x71];
    u8 field_71;
};
PKMN_OFFSET_ASSERT(Unk_1049d10, field_71, 0x71);

// 0x7101049d10
u8 Unk_1049d10_getField71(const Unk_1049d10* self) {
    return self->field_71;
}
