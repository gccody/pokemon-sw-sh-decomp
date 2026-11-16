// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_113f1b0 {
    u8 _0[0x90];
    u8 field_90;
};
PKMN_OFFSET_ASSERT(Unk_113f1b0, field_90, 0x90);

// 0x710113f1b0
u8 Unk_113f1b0_getField90(const Unk_113f1b0* self) {
    return self->field_90;
}
