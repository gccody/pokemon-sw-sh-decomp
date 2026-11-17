// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_143fce0 {
    u8 _0[0x700];
    u64 field_700;
};
PKMN_OFFSET_ASSERT(Unk_143fce0, field_700, 0x700);

// 0x710143fce0
void Unk_143fce0_setField700(Unk_143fce0* self, u64 value) {
    self->field_700 = value;
}

void Unk_eb6230(void*, u32);

// 0x7101442c40
void Unk_1442c40_call(void* self) {
    Unk_eb6230(self, 3);
}

struct Unk_1448b60 {
    u8 _0[0x3198];
    u64 field_3198;
};
PKMN_OFFSET_ASSERT(Unk_1448b60, field_3198, 0x3198);

void Unk_14bacd0(u64);

// 0x7101448b60
void Unk_1448b60_call(const Unk_1448b60* self) {
    Unk_14bacd0(self->field_3198);
}
