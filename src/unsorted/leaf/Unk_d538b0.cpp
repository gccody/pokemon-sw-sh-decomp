// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100d538b0
void Unk_d538b0_update() {}

struct Unk_d538c0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_d538c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_d538c0, field_8, 0x8);

// 0x7100d538c0
void Unk_d538c0_set(const Unk_d538c0* self, Unk_d538c0* value) {
    *value = *self;
}

struct Unk_d538d0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_d538d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_d538d0, field_8, 0x8);

// 0x7100d538d0
void Unk_d538d0_set(const Unk_d538d0* self, Unk_d538d0* value) {
    *value = *self;
}
