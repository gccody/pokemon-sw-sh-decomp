// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d6eef0 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_d6eef0, field_68, 0x68);

// 0x7100d6eef0
bool Unk_d6eef0_check(const Unk_d6eef0* self) {
    return self->field_68 != 0;
}

struct Unk_d6ef30 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_d6ef30, field_60, 0x60);

// 0x7100d6ef30
bool Unk_d6ef30_check(const Unk_d6ef30* self) {
    return self->field_60 == 0;
}
