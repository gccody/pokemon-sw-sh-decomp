// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_4ffbd0 {
    u8 _0[0x78];
    u8 field_78;
};
PKMN_OFFSET_ASSERT(Unk_4ffbd0, field_78, 0x78);

// 0x71004ffbd0
const u8* Unk_4ffbd0_get(const Unk_4ffbd0* self) {
    return &self->field_78;
}
