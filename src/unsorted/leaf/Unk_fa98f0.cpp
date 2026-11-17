// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_fa98f0 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_fa98f0, field_28, 0x28);

void Unk_eb8e80(u64);

// 0x7100fa98f0
void Unk_fa98f0_call(const Unk_fa98f0* self) {
    Unk_eb8e80(self->field_28);
}
