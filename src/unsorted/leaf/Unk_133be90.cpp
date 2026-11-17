// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_133be90 {
    u8 _0[0x600];
    u64 field_600;
};
PKMN_OFFSET_ASSERT(Unk_133be90, field_600, 0x600);

void Unk_14e1a00(u64, u32);

// 0x710133be90
void Unk_133be90_call(const Unk_133be90* self, bool value) {
    Unk_14e1a00(self->field_600, value);
}
