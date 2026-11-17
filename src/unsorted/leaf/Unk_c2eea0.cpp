// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_c2eea0 {
    u8 _0[0x660];
    u64 field_660;
};
PKMN_OFFSET_ASSERT(Unk_c2eea0, field_660, 0x660);

void Unk_eb75e0(u64);

// 0x7100c2eea0
void Unk_c2eea0_call(const Unk_c2eea0* self) {
    Unk_eb75e0(self->field_660);
}

struct Unk_c338a0 {
    u8 _0[0xe8];
    u8 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_c338a0, field_e8, 0xe8);

// 0x7100c338a0
void Unk_c338a0_set(Unk_c338a0* self) {
    self->field_e8 = 1;
}

struct Unk_c33940 {
    u8 _0[0xea];
    u8 field_ea;
};
PKMN_OFFSET_ASSERT(Unk_c33940, field_ea, 0xea);

// 0x7100c33940
void Unk_c33940_set(Unk_c33940* self) {
    self->field_ea = 1;
}
