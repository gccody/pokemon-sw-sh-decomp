// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_afb5f0 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_afb5f0, field_60, 0x60);

// 0x7100afb5f0
u64 Unk_afb5f0_getField60(const Unk_afb5f0* self) {
    return self->field_60;
}

struct Unk_afb7c0 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_afb7c0, field_68, 0x68);

// 0x7100afb7c0
u64 Unk_afb7c0_getField68(const Unk_afb7c0* self) {
    return self->field_68;
}
