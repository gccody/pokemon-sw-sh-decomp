// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100e67870
void Unk_e67870() {}

// 0x7100e67880
u32 Unk_e67880_get() {
    return 1;
}

struct Unk_e67a00 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_e67a00, field_18, 0x18);

void Unk_e67e80(u64);

// 0x7100e67a00
void Unk_e67a00_call(const Unk_e67a00* self) {
    Unk_e67e80(self->field_18);
}
