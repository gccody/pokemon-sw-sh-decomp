// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_831020 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_831020, field_0, 0x0);

// 0x7100831020
void Unk_831020_set(Unk_831020* self) {
    self->field_0 = 0xffffffff;
}

struct Unk_831030 {
    u8 _0[0x2];
    s16 field_2;
};
PKMN_OFFSET_ASSERT(Unk_831030, field_2, 0x2);

// 0x7100831030
bool Unk_831030_check(const Unk_831030* self) {
    return self->field_2 != -1;
}
