// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_126a9b0 {
    u8 _0[0xaa0];
    u8 field_aa0;
};
PKMN_OFFSET_ASSERT(Unk_126a9b0, field_aa0, 0xaa0);

// 0x710126a9b0
u8 Unk_126a9b0_getFieldaa0(const Unk_126a9b0* self) {
    return self->field_aa0;
}

struct Unk_126ac90 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_126ac90, field_68, 0x68);

// 0x710126ac90
u64 Unk_126ac90_getField68(const Unk_126ac90* self) {
    return self->field_68;
}
