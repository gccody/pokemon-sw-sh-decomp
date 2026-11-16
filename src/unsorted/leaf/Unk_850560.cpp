// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_850560 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_850560, field_0, 0x0);

// 0x7100850560
void Unk_850560_clearField0(Unk_850560* self) {
    self->field_0 = 0;
}
