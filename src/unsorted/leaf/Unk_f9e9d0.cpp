// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_f9e9d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f9e9d0, field_0, 0x0);

// 0x7100f9e9d0
u64 Unk_f9e9d0_getField0(const Unk_f9e9d0* self) {
    return self->field_0;
}
