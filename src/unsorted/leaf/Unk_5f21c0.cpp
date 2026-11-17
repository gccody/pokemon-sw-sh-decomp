// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_5f21c0 {
    u8 _0[0xa8];
    u64 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_5f21c0, field_a8, 0xa8);

void Unk_5f3280(u64);

// 0x71005f21c0
void Unk_5f21c0_call(const Unk_5f21c0* self) {
    Unk_5f3280(self->field_a8);
}

struct Unk_5f22d0 {
    u8 _0[0x8a0];
    u8 field_8a0;
};
PKMN_OFFSET_ASSERT(Unk_5f22d0, field_8a0, 0x8a0);

// 0x71005f22d0
void Unk_5f22d0_clearField8a0(Unk_5f22d0* self) {
    self->field_8a0 = 0;
}
