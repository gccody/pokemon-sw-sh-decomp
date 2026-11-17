// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_f280f0_5f8 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_f280f0_5f8, field_58, 0x58);

struct Unk_f280f0 {
    u8 _0[0x5f8];
    Unk_f280f0_5f8* field_5f8;
};
PKMN_OFFSET_ASSERT(Unk_f280f0, field_5f8, 0x5f8);

// 0x7100f280f0
void Unk_f280f0_set(const Unk_f280f0* self, bool value) {
    self->field_5f8->field_58 = (self->field_5f8->field_58 & 0xfffffffe) | (value);
}

struct Unk_f28570 {
    u8 _0[0x5f0];
    u64 field_5f0;
};
PKMN_OFFSET_ASSERT(Unk_f28570, field_5f0, 0x5f0);

void Unk_14e1b40(u64);

// 0x7100f28570
void Unk_f28570_call(const Unk_f28570* self) {
    Unk_14e1b40(self->field_5f0);
}
