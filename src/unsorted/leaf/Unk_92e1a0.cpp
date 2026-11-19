// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_92e1a0 {
    u8 _0[0x5d4];
    u32 field_5d4;
    u64 field_5d8;
    u8 _5e0[0x52];
    u8 field_632;
};
PKMN_OFFSET_ASSERT(Unk_92e1a0, field_5d4, 0x5d4);
PKMN_OFFSET_ASSERT(Unk_92e1a0, field_5d8, 0x5d8);
PKMN_OFFSET_ASSERT(Unk_92e1a0, field_632, 0x632);

void Unk_14e6550(u64, void*, u32, u32);

// 0x710092e1a0
void Unk_92e1a0_call(Unk_92e1a0* self, bool value) {
    u64 l8;
    self->field_632 = 5;
    self->field_5d4 = 0;
    if (value != 0) {
        u64 v0 = self->field_5d8;
        l8 = 0;
        Unk_14e6550(v0, &l8, 1, 0);
    }
}
