// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1267a90 {
    u8 _0[0x650];
    u64 field_650;
};
PKMN_OFFSET_ASSERT(Unk_1267a90, field_650, 0x650);

void Unk_14bacd0(u64);

// 0x7101267a90
void Unk_1267a90_call(const Unk_1267a90* self) {
    if (self->field_650 != 0) {
        Unk_14bacd0(self->field_650);
    }
}
