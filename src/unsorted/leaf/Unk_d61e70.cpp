// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d61e70 {
    u8 _0[0x4c0];
    u32 field_4c0;
};
PKMN_OFFSET_ASSERT(Unk_d61e70, field_4c0, 0x4c0);

// 0x7100d61e70
bool Unk_d61e70_check(const Unk_d61e70* self, u32 value) {
    return self->field_4c0 == value;
}
