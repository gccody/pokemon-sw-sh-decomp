// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_ce6050 {
    u8 _0[0x3e8];
    u64 field_3e8;
};
PKMN_OFFSET_ASSERT(Unk_ce6050, field_3e8, 0x3e8);

void Unk_c545c0(u64, u32);

// 0x7100ce6050
void Unk_ce6050_call(const Unk_ce6050* self) {
    Unk_c545c0(self->field_3e8, 1);
}
