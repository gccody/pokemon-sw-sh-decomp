// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8a7bd0 {
    u8 _0[0x2730];
    u8 field_2730;
};
PKMN_OFFSET_ASSERT(Unk_8a7bd0, field_2730, 0x2730);

// 0x71008a7bd0
const u8* Unk_8a7bd0_get(const Unk_8a7bd0* self) {
    return &self->field_2730;
}
