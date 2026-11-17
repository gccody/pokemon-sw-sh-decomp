// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_c5a8d0 {
    u8 _0[0x85];
    bool field_85;
};
PKMN_OFFSET_ASSERT(Unk_c5a8d0, field_85, 0x85);

// 0x7100c5a8d0
void Unk_c5a8d0_set(Unk_c5a8d0* self, bool value) {
    self->field_85 = value;
}

struct Unk_c68570 {
    u8 _0[0xe0];
    u64 field_e0;
    u64 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_c68570, field_e0, 0xe0);
PKMN_OFFSET_ASSERT(Unk_c68570, field_e8, 0xe8);

// 0x7100c68570
void Unk_c68570_set(Unk_c68570* self) {
    self->field_e8 = self->field_e0;
}
