// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d4fb90 {
    u8 _0[0x5bc];
    u32 field_5bc;
};
PKMN_OFFSET_ASSERT(Unk_d4fb90, field_5bc, 0x5bc);

// 0x7100d4fb90
u32 Unk_d4fb90_getField5bc(const Unk_d4fb90* self) {
    return self->field_5bc;
}

struct Unk_d4fba0 {
    u8 _0[0x5c0];
    u16 field_5c0;
};
PKMN_OFFSET_ASSERT(Unk_d4fba0, field_5c0, 0x5c0);

// 0x7100d4fba0
u16 Unk_d4fba0_getField5c0(const Unk_d4fba0* self) {
    return self->field_5c0;
}
