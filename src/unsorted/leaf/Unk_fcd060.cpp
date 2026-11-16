// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_fcd060 {
    u8 _0[0x700];
    u64 field_700;
};
PKMN_OFFSET_ASSERT(Unk_fcd060, field_700, 0x700);

// 0x7100fcd060
void Unk_fcd060_setField700(Unk_fcd060* self, u64 value) {
    self->field_700 = value;
}

struct Unk_fd4770 {
    u8 _0[0xb30];
    u64 field_b30;
};
PKMN_OFFSET_ASSERT(Unk_fd4770, field_b30, 0xb30);

// 0x7100fd4770
u64 Unk_fd4770_getFieldb30(const Unk_fd4770* self) {
    return self->field_b30;
}
