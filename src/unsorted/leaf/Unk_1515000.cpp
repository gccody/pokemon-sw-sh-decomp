// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1515000 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_1515000, field_5cc, 0x5cc);

// 0x7101515000
void Unk_1515000_clearField5cc(Unk_1515000* self) {
    self->field_5cc = 0;
}

struct Unk_1515010 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_1515010, field_5cc, 0x5cc);

// 0x7101515010
u32 Unk_1515010_getField5cc(const Unk_1515010* self) {
    return self->field_5cc;
}

// 0x710151a420
u32 Unk_151a420() {
    return 9;
}
