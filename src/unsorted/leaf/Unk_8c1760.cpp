// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8c1760 {
    u8 _0[0xbc];
    u32 field_bc;
};
PKMN_OFFSET_ASSERT(Unk_8c1760, field_bc, 0xbc);

// 0x71008c1760
u32 Unk_8c1760_getFieldbc(const Unk_8c1760* self) {
    return self->field_bc;
}
