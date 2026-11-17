// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_9bad40 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_9bad40, field_10, 0x10);

// 0x71009bad40
bool Unk_9bad40_check(const Unk_9bad40* self) {
    return self->field_10 == 4;
}
