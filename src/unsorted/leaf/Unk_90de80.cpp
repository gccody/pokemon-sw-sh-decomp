// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_90de80 {
    u8 _0[0x738];
    u64 field_738;
};
PKMN_OFFSET_ASSERT(Unk_90de80, field_738, 0x738);

void Unk_8f4430(u64);

// 0x710090de80
void Unk_90de80_call(const Unk_90de80* self) {
    if (self->field_738 != 0) {
        Unk_8f4430(self->field_738);
    }
}
