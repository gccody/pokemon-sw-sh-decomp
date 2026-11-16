// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_c3fd90 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_c3fd90, field_60, 0x60);

// 0x7100c3fd90
u64 Unk_c3fd90_getField60(const Unk_c3fd90* self) {
    return self->field_60;
}

struct Unk_c3fda0 {
    u8 _0[0x6c];
    u32 field_6c;
};
PKMN_OFFSET_ASSERT(Unk_c3fda0, field_6c, 0x6c);

// 0x7100c3fda0
void Unk_c3fda0_setField6c(Unk_c3fda0* self, u32 value) {
    self->field_6c = value;
}

struct Unk_c41280 {
    u8 _0[0x720];
    u64 field_720;
};
PKMN_OFFSET_ASSERT(Unk_c41280, field_720, 0x720);

// 0x7100c41280
void Unk_c41280_setField720(Unk_c41280* self, u64 value) {
    self->field_720 = value;
}
