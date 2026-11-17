// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1475be0 {
    u8 _0[0x600];
    u64 field_600;
};
PKMN_OFFSET_ASSERT(Unk_1475be0, field_600, 0x600);

void Unk_14e1a00(u64, u32);

// 0x7101475be0
void Unk_1475be0_call(const Unk_1475be0* self, bool value) {
    Unk_14e1a00(self->field_600, value);
}

struct Unk_1476880 {
    u8 _0[0x5d0];
    u64 field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_1476880, field_5d0, 0x5d0);

void Unk_1459dd0(u64);

// 0x7101476880
void Unk_1476880_call(const Unk_1476880* self) {
    Unk_1459dd0(self->field_5d0);
}
