// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_eb6230(void*, u32);

// 0x7100925470
void Unk_925470_call(void* self) {
    Unk_eb6230(self, 2);
}

void Unk_eb6230(void*, u32);

// 0x7100925480
void Unk_925480_call(void* self) {
    Unk_eb6230(self, 3);
}

struct Unk_925490 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_925490, field_5cc, 0x5cc);

// 0x7100925490
void Unk_925490_clearField5cc(Unk_925490* self) {
    self->field_5cc = 0;
}
