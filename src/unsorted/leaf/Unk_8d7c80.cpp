// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8d7c80 {
    u8 _0[0x6b4];
    u32 field_6b4;
};
PKMN_OFFSET_ASSERT(Unk_8d7c80, field_6b4, 0x6b4);

// 0x71008d7c80
u32 Unk_8d7c80_getField6b4(const Unk_8d7c80* self) {
    return self->field_6b4;
}
