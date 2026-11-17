// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d6d590 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d6d590, field_0, 0x0);

void Unk_d6d5a0(u64);

// 0x7100d6d590
void Unk_d6d590_call(const Unk_d6d590* self) {
    Unk_d6d5a0(self->field_0);
}
