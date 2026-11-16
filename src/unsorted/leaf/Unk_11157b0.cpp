// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_11157b0 {
    u8 _0[0x6c];
    u32 field_6c;
};
PKMN_OFFSET_ASSERT(Unk_11157b0, field_6c, 0x6c);

// 0x71011157b0
u32 Unk_11157b0_getField6c(const Unk_11157b0* self) {
    return self->field_6c;
}
