// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_800bf0 {
    u8 _0[0x38];
    u8 field_38;
};
PKMN_OFFSET_ASSERT(Unk_800bf0, field_38, 0x38);

// 0x7100800bf0
u8 Unk_800bf0_getField38(const Unk_800bf0* self) {
    return self->field_38;
}
