// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_57d840 {
    u8 _0[0x40];
    u64 field_40;
};
PKMN_OFFSET_ASSERT(Unk_57d840, field_40, 0x40);

// 0x710057d840
u64 Unk_57d840_get(const Unk_57d840* self) {
    return self->field_40;
}
