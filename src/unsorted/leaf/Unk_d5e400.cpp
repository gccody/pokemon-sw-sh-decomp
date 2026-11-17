// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d5e400 {
    u8 _0[0x64];
    u32 field_64;
};
PKMN_OFFSET_ASSERT(Unk_d5e400, field_64, 0x64);

// 0x7100d5e400
bool Unk_d5e400_check(const Unk_d5e400* self) {
    return (self->field_64 & 0xfffffffe) == 0xa;
}

struct Unk_d5e420 {
    u8 _0[0x27c];
    u32 field_27c;
};
PKMN_OFFSET_ASSERT(Unk_d5e420, field_27c, 0x27c);

// 0x7100d5e420
u32 Unk_d5e420_getField27c(const Unk_d5e420* self) {
    return self->field_27c;
}
