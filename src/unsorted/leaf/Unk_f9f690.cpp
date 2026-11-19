// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_f9f690 {
    u8 _0[0x68];
    u8 field_68;
    u8 _69[0x3];
    u8 field_6c;
    u8 _6d[0x3];
    u32 field_70;
};
PKMN_OFFSET_ASSERT(Unk_f9f690, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_f9f690, field_6c, 0x6c);
PKMN_OFFSET_ASSERT(Unk_f9f690, field_70, 0x70);

// 0x7100f9f690
void Unk_f9f690_update(Unk_f9f690* self) {
    if (self->field_6c != 0) {
        return;
    }
    self->field_68 = 0;
    self->field_70 = 0;
    self->field_6c = 1;
}
