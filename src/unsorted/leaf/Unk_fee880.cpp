// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_fee880 {
    u8 _0[0xc1];
    u8 field_c1;
    u8 field_c2;
};
PKMN_OFFSET_ASSERT(Unk_fee880, field_c1, 0xc1);
PKMN_OFFSET_ASSERT(Unk_fee880, field_c2, 0xc2);

// 0x7100fee880
bool Unk_fee880_check(const Unk_fee880* self) {
    if (self->field_c2 == 0) {
        return false;
    }
    return self->field_c1 != 0;
}
