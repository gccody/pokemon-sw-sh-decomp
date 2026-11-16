// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_f4eb00 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_f4eb00, field_5cc, 0x5cc);

// 0x7100f4eb00
void Unk_f4eb00_clearField5cc(Unk_f4eb00* self) {
    self->field_5cc = 0;
}

struct Unk_f4eb10 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_f4eb10, field_5cc, 0x5cc);

// 0x7100f4eb10
u32 Unk_f4eb10_getField5cc(const Unk_f4eb10* self) {
    return self->field_5cc;
}
