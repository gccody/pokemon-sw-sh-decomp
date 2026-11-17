// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_12f0100_168 {
    u8 _0[0x170];
    u8 field_170;
};
PKMN_OFFSET_ASSERT(Unk_12f0100_168, field_170, 0x170);

struct Unk_12f0100 {
    u8 _0[0x168];
    Unk_12f0100_168* field_168;
};
PKMN_OFFSET_ASSERT(Unk_12f0100, field_168, 0x168);

// 0x71012f0100
u8 Unk_12f0100_get(const Unk_12f0100* self) {
    if (self->field_168 == nullptr) {
        return 0;
    }
    return self->field_168->field_170;
}
