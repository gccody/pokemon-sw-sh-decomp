// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_125a0f0 {
    u8 _0[0x90];
    u64 field_90;
};
PKMN_OFFSET_ASSERT(Unk_125a0f0, field_90, 0x90);

// 0x710125a0f0
u64 Unk_125a0f0_getField90(const Unk_125a0f0* self) {
    return self->field_90;
}

struct Unk_125b9f0 {
    u8 _0[0x610];
    u64 field_610;
};
PKMN_OFFSET_ASSERT(Unk_125b9f0, field_610, 0x610);

// 0x710125b9f0
u64 Unk_125b9f0_getField610(const Unk_125b9f0* self) {
    return self->field_610;
}
