// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_9f9350 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_9f9350, field_10, 0x10);

// 0x71009f9350
bool Unk_9f9350_check(const Unk_9f9350* self) {
    return self->field_10 == 0;
}
