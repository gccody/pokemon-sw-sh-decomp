// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

u32 Unk_eb6530();

// 0x7100f52e70
u32 Unk_f52e70_call() {
    u32 r0 = Unk_eb6530();
    return ~r0 & 1;
}

struct Unk_f52f50 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_f52f50, field_5cc, 0x5cc);

// 0x7100f52f50
void Unk_f52f50_clearField5cc(Unk_f52f50* self) {
    self->field_5cc = 0;
}

struct Unk_f531c0 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_f531c0, field_5cc, 0x5cc);

// 0x7100f531c0
u32 Unk_f531c0_getField5cc(const Unk_f531c0* self) {
    return self->field_5cc;
}
