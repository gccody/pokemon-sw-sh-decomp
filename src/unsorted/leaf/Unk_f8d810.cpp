// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_f8d810 {
    u8 _0[0x640];
    u32 field_640;
};
PKMN_OFFSET_ASSERT(Unk_f8d810, field_640, 0x640);

// 0x7100f8d810
bool Unk_f8d810_check(const Unk_f8d810* self) {
    return self->field_640 < 0x80;
}
