// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_ba7530 {
    u8 _0[0x5d0];
    u64 field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_ba7530, field_5d0, 0x5d0);

void Unk_13133a0(u64, u64, u64, u32, u32);

// 0x7100ba7530
void Unk_ba7530_call(const Unk_ba7530* self, u64 value, u64 arg2) {
    Unk_13133a0(self->field_5d0, value, arg2, 0, 0);
}

struct Unk_ba75f0 {
    u8 _0[0x5d0];
    u64 field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_ba75f0, field_5d0, 0x5d0);

void Unk_1315b90(u64, u64, u64, u32, u32, u32);

// 0x7100ba75f0
void Unk_ba75f0_call(const Unk_ba75f0* self, u64 value, u64 arg2) {
    Unk_1315b90(self->field_5d0, value, arg2, 2, 0, 1);
}

struct Unk_ba7610 {
    u8 _0[0x5d0];
    u64 field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_ba7610, field_5d0, 0x5d0);

void Unk_1315b90(u64, u64, u64, u32, u32, u32);

// 0x7100ba7610
void Unk_ba7610_call(const Unk_ba7610* self, u64 value, u64 arg2) {
    Unk_1315b90(self->field_5d0, value, arg2, 2, 0, 1);
}
