// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1458120 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_1458120, field_58, 0x58);

void Unk_1458130(u64);

// 0x7101458120
void Unk_1458120_call(const Unk_1458120* self) {
    Unk_1458130(self->field_58);
}

struct Unk_1458300_58 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1458300_58, field_18, 0x18);

struct Unk_1458300 {
    u8 _0[0x58];
    Unk_1458300_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_1458300, field_58, 0x58);

// 0x7101458300
void Unk_1458300_set(const Unk_1458300* self, u64 value) {
    self->field_58->field_18 = value;
}

struct Unk_1459ac0 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_1459ac0, field_58, 0x58);

void Unk_1459ad0(u64);

// 0x7101459ac0
void Unk_1459ac0_call(const Unk_1459ac0* self) {
    Unk_1459ad0(self->field_58);
}

struct Unk_1459f50 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_1459f50, field_58, 0x58);

void Unk_1459f60(u64);

// 0x7101459f50
void Unk_1459f50_call(const Unk_1459f50* self) {
    Unk_1459f60(self->field_58);
}
