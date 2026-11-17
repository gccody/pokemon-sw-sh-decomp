// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1411030 {
    u8 _0[0xc40];
    u64 field_c40;
};
PKMN_OFFSET_ASSERT(Unk_1411030, field_c40, 0xc40);

void Unk_14e1a00(u64, u32);

// 0x7101411030
void Unk_1411030_call(const Unk_1411030* self, bool value) {
    Unk_14e1a00(self->field_c40, value);
}

struct Unk_1411040 {
    u8 _0[0xc48];
    u64 field_c48;
};
PKMN_OFFSET_ASSERT(Unk_1411040, field_c48, 0xc48);

void Unk_14e1a00(u64, u32);

// 0x7101411040
void Unk_1411040_call(const Unk_1411040* self, bool value) {
    Unk_14e1a00(self->field_c48, value);
}
