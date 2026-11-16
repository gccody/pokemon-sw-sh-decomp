// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_143fce0 {
    u8 _0[0x700];
    u64 field_700;
};
PKMN_OFFSET_ASSERT(Unk_143fce0, field_700, 0x700);

// 0x710143fce0
void Unk_143fce0_setField700(Unk_143fce0* self, u64 value) {
    self->field_700 = value;
}
