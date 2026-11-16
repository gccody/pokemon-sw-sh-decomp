// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_b6fb40 {
    u8 _0[0x5];
    u8 field_5;
};
PKMN_OFFSET_ASSERT(Unk_b6fb40, field_5, 0x5);

// 0x7100b6fb40
u8 Unk_b6fb40_getField5(const Unk_b6fb40* self) {
    return self->field_5;
}

struct Unk_b6fb50 {
    u8 _0[0x5];
    u8 field_5;
};
PKMN_OFFSET_ASSERT(Unk_b6fb50, field_5, 0x5);

// 0x7100b6fb50
void Unk_b6fb50_setField5(Unk_b6fb50* self, u8 value) {
    self->field_5 = value;
}

// 0x7100b70ea0
void Unk_b70ea0() {}
