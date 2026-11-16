// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_11bd1b0 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_11bd1b0, field_78, 0x78);

// 0x71011bd1b0
u32 Unk_11bd1b0_getField78(const Unk_11bd1b0* self) {
    return self->field_78;
}

struct Unk_11bd1c0 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_11bd1c0, field_78, 0x78);

// 0x71011bd1c0
void Unk_11bd1c0_setField78(Unk_11bd1c0* self, u32 value) {
    self->field_78 = value;
}
