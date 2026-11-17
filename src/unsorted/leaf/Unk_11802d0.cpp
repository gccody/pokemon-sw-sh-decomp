// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_11802d0 {
    u8 _0[0x410];
    u8 field_410;
};
PKMN_OFFSET_ASSERT(Unk_11802d0, field_410, 0x410);

// 0x71011802d0
u8 Unk_11802d0_getField410(const Unk_11802d0* self) {
    return self->field_410;
}

struct Unk_11802e0 {
    u8 _0[0x7c];
    u32 field_7c;
};
PKMN_OFFSET_ASSERT(Unk_11802e0, field_7c, 0x7c);

// 0x71011802e0
bool Unk_11802e0_check(const Unk_11802e0* self) {
    return self->field_7c >= 4 && self->field_7c <= 9;
}
