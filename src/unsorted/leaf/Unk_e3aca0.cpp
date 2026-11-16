// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_e3aca0 {
    u8 _0[0x80];
    u8 field_80;
};
PKMN_OFFSET_ASSERT(Unk_e3aca0, field_80, 0x80);

// 0x7100e3aca0
u8* Unk_e3aca0_getField80Ptr(Unk_e3aca0* self) {
    return &self->field_80;
}
