// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_e41310 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_e41310, field_60, 0x60);

// 0x7100e41310
void Unk_e41310_setField60(Unk_e41310* self, u64 value) {
    self->field_60 = value;
}

// 0x7100e420a0
void Unk_e420a0() {}

// 0x7100e420c0
void Unk_e420c0() {}
