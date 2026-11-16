// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_10457e0 {
    u8 _0[0x6c];
    u32 field_6c;
};
PKMN_OFFSET_ASSERT(Unk_10457e0, field_6c, 0x6c);

// 0x71010457e0
u32 Unk_10457e0_getField6c(const Unk_10457e0* self) {
    return self->field_6c;
}
