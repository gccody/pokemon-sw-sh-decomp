// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_c95020_68 {
    u8 _0[0x170];
    u8 field_170;
};
PKMN_OFFSET_ASSERT(Unk_c95020_68, field_170, 0x170);

struct Unk_c95020 {
    u8 _0[0x68];
    Unk_c95020_68* field_68;
};
PKMN_OFFSET_ASSERT(Unk_c95020, field_68, 0x68);

// 0x7100c95020
bool Unk_c95020_check(const Unk_c95020* self) {
    if (self->field_68 == nullptr) {
        return false;
    }
    return self->field_68->field_170 != 0;
}
