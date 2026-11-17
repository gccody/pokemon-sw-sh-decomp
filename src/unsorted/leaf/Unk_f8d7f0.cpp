// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_f8d7f0 {
    u8 _0[0x628];
    u64 field_628;
};
PKMN_OFFSET_ASSERT(Unk_f8d7f0, field_628, 0x628);

void Unk_14e1a30(u64, u32);

// 0x7100f8d7f0
void Unk_f8d7f0_call(const Unk_f8d7f0* self) {
    Unk_14e1a30(self->field_628, 1);
}

struct Unk_f8d800 {
    u8 _0[0x628];
    u64 field_628;
};
PKMN_OFFSET_ASSERT(Unk_f8d800, field_628, 0x628);

void Unk_14e1a30(u64, u32);

// 0x7100f8d800
void Unk_f8d800_call(const Unk_f8d800* self) {
    Unk_14e1a30(self->field_628, 0);
}

struct Unk_f8d810 {
    u8 _0[0x640];
    u32 field_640;
};
PKMN_OFFSET_ASSERT(Unk_f8d810, field_640, 0x640);

// 0x7100f8d810
bool Unk_f8d810_check(const Unk_f8d810* self) {
    return self->field_640 < 0x80;
}
