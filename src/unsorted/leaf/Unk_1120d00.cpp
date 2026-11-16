// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1120d00 {
    u8 _0[0x908];
    u32 field_908;
};
PKMN_OFFSET_ASSERT(Unk_1120d00, field_908, 0x908);

// 0x7101120d00
u32 Unk_1120d00_getField908(const Unk_1120d00* self) {
    return self->field_908;
}
