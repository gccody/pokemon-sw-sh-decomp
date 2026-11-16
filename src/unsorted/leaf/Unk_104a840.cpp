// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_104a840 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_104a840, field_0, 0x0);

// 0x710104a840
u32 Unk_104a840_getField0(const Unk_104a840* self) {
    return self->field_0;
}
