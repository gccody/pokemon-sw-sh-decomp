// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_104e9d0 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_104e9d0, field_0, 0x0);

// 0x710104e9d0
bool Unk_104e9d0_check(const Unk_104e9d0* self) {
    return (self->field_0 & 0x3fffff) == 0x27c;
}
