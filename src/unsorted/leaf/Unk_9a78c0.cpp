// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_9a78c0 {
    u8 _0[0x100];
    u8 field_100;
};
PKMN_OFFSET_ASSERT(Unk_9a78c0, field_100, 0x100);

// 0x71009a78c0
void Unk_9a78c0_clearField100(Unk_9a78c0* self) {
    self->field_100 = 0;
}
