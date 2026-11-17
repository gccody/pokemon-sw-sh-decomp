// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8a8bb0 {
    u8 _0[0x28];
    u32 field_28;
    u8 field_2c;
};
PKMN_OFFSET_ASSERT(Unk_8a8bb0, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_8a8bb0, field_2c, 0x2c);

// 0x71008a8bb0
void Unk_8a8bb0_set(Unk_8a8bb0* self) {
    self->field_28 = 0;
    self->field_2c = 0;
}

struct Unk_8a8bc0 {
    u8 _0[0x2c];
    u8 field_2c;
};
PKMN_OFFSET_ASSERT(Unk_8a8bc0, field_2c, 0x2c);

// 0x71008a8bc0
u8 Unk_8a8bc0_getField2c(const Unk_8a8bc0* self) {
    return self->field_2c;
}
