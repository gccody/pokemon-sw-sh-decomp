// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_115f590 {
    u8 _0[0x18];
    f32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_115f590, field_18, 0x18);

// 0x710115f590
f32 Unk_115f590_getField18(const Unk_115f590* self) {
    return self->field_18;
}
