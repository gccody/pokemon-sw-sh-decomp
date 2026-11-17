// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_829d30 {
    u8 _0[0x8];
    u32 field_8;
    u8 field_c;
};
PKMN_OFFSET_ASSERT(Unk_829d30, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_829d30, field_c, 0xc);

// 0x7100829d30
void Unk_829d30_set(Unk_829d30* self) {
    self->field_c = 5;
    self->field_8 = 0x5050505;
}
