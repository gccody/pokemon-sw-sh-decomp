// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_132b470 {
    u8 _0[0x5f8];
    u64 field_5f8;
};
PKMN_OFFSET_ASSERT(Unk_132b470, field_5f8, 0x5f8);

void Unk_14e1a30(u64, u32);

// 0x710132b470
void Unk_132b470_call(const Unk_132b470* self, bool value) {
    if (self->field_5f8 != 0) {
        Unk_14e1a30(self->field_5f8, value);
    }
}
