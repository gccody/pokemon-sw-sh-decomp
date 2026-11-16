// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_101b7c0 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_101b7c0, field_60, 0x60);

// 0x710101b7c0
u64 Unk_101b7c0_getField60(const Unk_101b7c0* self) {
    return self->field_60;
}
