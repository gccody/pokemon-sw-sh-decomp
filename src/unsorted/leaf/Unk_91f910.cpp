// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_91f910 {
    u8 _0[0x5f0];
    u64 field_5f0;
    u8 _5f8[0x8];
    u32 field_600;
    u8 _604[0x4];
    u32 field_608;
};
PKMN_OFFSET_ASSERT(Unk_91f910, field_5f0, 0x5f0);
PKMN_OFFSET_ASSERT(Unk_91f910, field_600, 0x600);
PKMN_OFFSET_ASSERT(Unk_91f910, field_608, 0x608);

// 0x710091f910
void Unk_91f910_set(Unk_91f910* self) {
    self->field_5f0 = 0;
    self->field_600 = 0;
    self->field_608 = 0;
}
