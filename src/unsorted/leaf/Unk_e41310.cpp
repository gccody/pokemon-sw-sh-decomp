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

struct Unk_e420b0 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_e420b0, field_78, 0x78);

// 0x7100e420b0
void Unk_e420b0_set(Unk_e420b0* self) {
    self->field_78 = 1;
}

// 0x7100e420c0
void Unk_e420c0() {}

struct Unk_e42280 {
    u8 _0[0x80];
    u32 field_80;
};
PKMN_OFFSET_ASSERT(Unk_e42280, field_80, 0x80);

// 0x7100e42280
bool Unk_e42280_check(const Unk_e42280* self) {
    return self->field_80 == 0;
}
