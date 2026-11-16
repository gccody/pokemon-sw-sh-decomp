// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x710082f800
void Unk_82f800() {}

struct Unk_82f830 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_82f830, field_18, 0x18);

// 0x710082f830
void Unk_82f830_clearField18(Unk_82f830* self) {
    self->field_18 = 0;
}
