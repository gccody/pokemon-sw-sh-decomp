// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_ff23d0 {
    u8 _0[0x178];
    u32 field_178;
};
PKMN_OFFSET_ASSERT(Unk_ff23d0, field_178, 0x178);

// 0x7100ff23d0
void Unk_ff23d0_set(Unk_ff23d0* self) {
    self->field_178 = 0xb;
}

struct Unk_ff23e0 {
    u8 _0[0x178];
    u32 field_178;
};
PKMN_OFFSET_ASSERT(Unk_ff23e0, field_178, 0x178);

// 0x7100ff23e0
bool Unk_ff23e0_check(const Unk_ff23e0* self) {
    return self->field_178 == 0xd;
}
