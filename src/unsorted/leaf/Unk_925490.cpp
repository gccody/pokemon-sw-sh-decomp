// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_925490 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_925490, field_5cc, 0x5cc);

// 0x7100925490
void Unk_925490_clearField5cc(Unk_925490* self) {
    self->field_5cc = 0;
}
