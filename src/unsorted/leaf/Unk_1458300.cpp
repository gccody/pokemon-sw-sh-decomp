// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1458300_58 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1458300_58, field_18, 0x18);

struct Unk_1458300 {
    u8 _0[0x58];
    Unk_1458300_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_1458300, field_58, 0x58);

// 0x7101458300
void Unk_1458300_set(const Unk_1458300* self, u64 value) {
    self->field_58->field_18 = value;
}
