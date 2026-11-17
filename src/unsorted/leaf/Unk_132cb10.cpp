// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_132cb10 {
    u8 _0[0x20];
    u64 field_20;
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_132cb10, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_132cb10, field_28, 0x28);

// 0x710132cb10
void Unk_132cb10_set(Unk_132cb10* self, u64 value, u64 arg2) {
    self->field_20 = value;
    self->field_28 = arg2;
}

struct Unk_132cca0 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_132cca0, field_28, 0x28);

void Unk_eb8a30(u64, u32);

// 0x710132cca0
void Unk_132cca0_call(const Unk_132cca0* self) {
    Unk_eb8a30(self->field_28, 1);
}
