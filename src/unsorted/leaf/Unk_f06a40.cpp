// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_f06a40 {
    u8 _0[0x98];
    u64 field_98;
    u8 _a0[0x1];
    u8 field_a1;
};
PKMN_OFFSET_ASSERT(Unk_f06a40, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_f06a40, field_a1, 0xa1);

// 0x7100f06a40
void Unk_f06a40_set(Unk_f06a40* self, u64 value) {
    self->field_98 = value;
    self->field_a1 = 1;
}
