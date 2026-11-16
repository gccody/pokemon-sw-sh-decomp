// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_939650 {
    u8 _0[0x38];
    u64 field_38;
};
PKMN_OFFSET_ASSERT(Unk_939650, field_38, 0x38);

// 0x7100939650
void Unk_939650_setField38(Unk_939650* self, u64 value) {
    self->field_38 = value;
}
