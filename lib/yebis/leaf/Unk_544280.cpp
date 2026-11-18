// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_544280 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_544280, field_20, 0x20);

// 0x7100544280
u64 Unk_544280_get(const Unk_544280* self) {
    return self->field_20;
}
