// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71007fc1e0
void Unk_7fc1e0() {}

struct Unk_7fc2e0 {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_7fc2e0, field_30, 0x30);

// 0x71007fc2e0
u8 Unk_7fc2e0_getField30(const Unk_7fc2e0* self) {
    return self->field_30;
}
