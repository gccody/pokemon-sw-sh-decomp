// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_7c58b0;
struct Unk_7e4240_arg2 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7e4240_arg2, field_0, 0x0);

struct Unk_7e4240 {
    u8 _0[0x60];
    Unk_7c58b0* field_60;
};
PKMN_OFFSET_ASSERT(Unk_7e4240, field_60, 0x60);

u32 Unk_7c58b0_get(const Unk_7c58b0*);

// 0x71007e4240
void Unk_7e4240_call(const Unk_7e4240* self, u32 /*unused*/, Unk_7e4240_arg2* arg2) {
    u32 r0 = Unk_7c58b0_get(self->field_60);
    arg2->field_0 = r0 == 4 ? 0x24 : 2;
}
