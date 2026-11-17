// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100e6d3d0
void Unk_e6d3d0() {}

// 0x7100e6da10
u32 Unk_e6da10_get() {
    return 1;
}

struct Unk_e6e3d0 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_e6e3d0, field_5cc, 0x5cc);

// 0x7100e6e3d0
bool Unk_e6e3d0_check(const Unk_e6e3d0* self) {
    return self->field_5cc == 0;
}

// 0x7100e6e820
void Unk_e6e820() {}

// 0x7100e6f180
u32 Unk_e6f180_get() {
    return 1;
}
