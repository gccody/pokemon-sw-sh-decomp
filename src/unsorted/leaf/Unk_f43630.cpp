// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_f43630 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_f43630, field_5cc, 0x5cc);

// 0x7100f43630
u32 Unk_f43630_getField5cc(const Unk_f43630* self) {
    return self->field_5cc;
}
