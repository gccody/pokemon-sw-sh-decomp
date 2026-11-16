// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_adcdd0 {
    u8 _0[0x5e0];
    u8 field_5e0;
};
PKMN_OFFSET_ASSERT(Unk_adcdd0, field_5e0, 0x5e0);

// 0x7100adcdd0
void Unk_adcdd0_clearField5e0(Unk_adcdd0* self) {
    self->field_5e0 = 0;
}

struct Unk_ae1800 {
    u8 _0[0xb40];
    u64 field_b40;
};
PKMN_OFFSET_ASSERT(Unk_ae1800, field_b40, 0xb40);

// 0x7100ae1800
u64 Unk_ae1800_getFieldb40(const Unk_ae1800* self) {
    return self->field_b40;
}
