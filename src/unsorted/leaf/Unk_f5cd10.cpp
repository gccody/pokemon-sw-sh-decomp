// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_f5cd10 {
    u8 _0[0x90];
    u64 field_90;
};
PKMN_OFFSET_ASSERT(Unk_f5cd10, field_90, 0x90);

void Unk_67bfa0(u64);

// 0x7100f5cd10
void Unk_f5cd10_call(const Unk_f5cd10* self) {
    Unk_67bfa0(self->field_90);
}
