// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100782dd0
void Unk_782dd0() {}

// 0x7100782df0
void Unk_782df0() {}

struct Unk_7847d0 {
    u8 _0[0x88];
    u8 field_88;
};
PKMN_OFFSET_ASSERT(Unk_7847d0, field_88, 0x88);

// 0x71007847d0
u8 Unk_7847d0_getField88(const Unk_7847d0* self) {
    return self->field_88;
}

// 0x7100784f30
u32 Unk_784f30() {
    return 0x810;
}

// 0x7100786410
void Unk_786410() {}
