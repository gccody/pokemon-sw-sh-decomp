// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8acb50 {
    u8 _0[0x24];
    u8 field_24;
};
PKMN_OFFSET_ASSERT(Unk_8acb50, field_24, 0x24);

// 0x71008acb50
u8 Unk_8acb50_getField24(const Unk_8acb50* self) {
    return self->field_24;
}
