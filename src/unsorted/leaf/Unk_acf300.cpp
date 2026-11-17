// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_acf300_638 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_acf300_638, field_58, 0x58);

struct Unk_acf300 {
    u8 _0[0x638];
    Unk_acf300_638* field_638;
};
PKMN_OFFSET_ASSERT(Unk_acf300, field_638, 0x638);

// 0x7100acf300
void Unk_acf300_set(const Unk_acf300* self, bool value) {
    self->field_638->field_58 = (self->field_638->field_58 & 0xfffffffe) | (value);
}
