// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d1b6a0 {
    u8 _0[0x9e];
    u8 field_9e;
};
PKMN_OFFSET_ASSERT(Unk_d1b6a0, field_9e, 0x9e);

// 0x7100d1b6a0
void Unk_d1b6a0_clearField9e(Unk_d1b6a0* self) {
    self->field_9e = 0;
}

struct Unk_d1d280 {
    u8 _0[0x9e];
    u8 field_9e;
};
PKMN_OFFSET_ASSERT(Unk_d1d280, field_9e, 0x9e);

// 0x7100d1d280
u8 Unk_d1d280_getField9e(const Unk_d1d280* self) {
    return self->field_9e;
}
