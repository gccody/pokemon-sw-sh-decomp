// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1249eb0_5e8 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_1249eb0_5e8, field_58, 0x58);

struct Unk_1249eb0 {
    u8 _0[0x5e8];
    Unk_1249eb0_5e8* field_5e8;
};
PKMN_OFFSET_ASSERT(Unk_1249eb0, field_5e8, 0x5e8);

// 0x7101249eb0
void Unk_1249eb0_set(const Unk_1249eb0* self) {
    self->field_5e8->field_58 = self->field_5e8->field_58 & 0xfe;
}

struct Unk_1249ed0_9b8 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_1249ed0_9b8, field_58, 0x58);

struct Unk_1249ed0 {
    u8 _0[0x9b8];
    Unk_1249ed0_9b8* field_9b8;
};
PKMN_OFFSET_ASSERT(Unk_1249ed0, field_9b8, 0x9b8);

// 0x7101249ed0
void Unk_1249ed0_set(const Unk_1249ed0* self) {
    self->field_9b8->field_58 = self->field_9b8->field_58 & 0xfe;
}
