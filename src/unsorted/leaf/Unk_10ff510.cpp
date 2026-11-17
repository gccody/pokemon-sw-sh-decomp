// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_10ff510 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10ff510, field_8, 0x8);

void Unk_15c90e0(u64);

// 0x71010ff510
void Unk_10ff510_call(const Unk_10ff510* self) {
    if (self->field_8 != 0) {
        Unk_15c90e0(self->field_8);
    }
}

struct Unk_10ff520 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10ff520, field_8, 0x8);

// 0x71010ff520
bool Unk_10ff520_check(const Unk_10ff520* self) {
    return self->field_8 != 0;
}
