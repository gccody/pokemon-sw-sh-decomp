// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100e71990
u32 Unk_e71990_get() {
    return 1;
}

struct Unk_e719a0 {
    u8 _0[0x1c];
    u8 field_1c;
    u8 _1d[0x3];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_e719a0, field_1c, 0x1c);
PKMN_OFFSET_ASSERT(Unk_e719a0, field_20, 0x20);

void Unk_e725a0(u64, u32);

// 0x7100e719a0
void Unk_e719a0_call(Unk_e719a0* self) {
    self->field_1c = 1;
    Unk_e725a0(self->field_20, 1);
}

struct Unk_e719c0 {
    u8 _0[0x1c];
    u8 field_1c;
    u8 _1d[0x3];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_e719c0, field_1c, 0x1c);
PKMN_OFFSET_ASSERT(Unk_e719c0, field_20, 0x20);

void Unk_e725a0(u64, u32);

// 0x7100e719c0
void Unk_e719c0_call(Unk_e719c0* self) {
    self->field_1c = 0;
    Unk_e725a0(self->field_20, 0);
}
