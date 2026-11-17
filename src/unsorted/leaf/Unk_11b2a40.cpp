// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_11b2a40 {
    u8 _0[0x80];
    u64 field_80;
    u8 _88[0x58];
    u8 field_e0;
};
PKMN_OFFSET_ASSERT(Unk_11b2a40, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_11b2a40, field_e0, 0xe0);

// 0x71011b2a40
bool Unk_11b2a40_check(const Unk_11b2a40* self) {
    if (self->field_e0 == 0) {
        return false;
    }
    return self->field_80 != 0;
}
