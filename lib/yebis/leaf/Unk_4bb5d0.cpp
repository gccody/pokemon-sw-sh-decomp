// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_4bb5d0 {
    u8 _0[0x28];
    u32 field_28;
};
PKMN_OFFSET_ASSERT(Unk_4bb5d0, field_28, 0x28);

// 0x71004bb5d0
u32 Unk_4bb5d0_get(const Unk_4bb5d0* self) {
    return self->field_28;
}

struct Unk_4bb5e0 {
    u8 _0[0x40];
    u64 field_40;
};
PKMN_OFFSET_ASSERT(Unk_4bb5e0, field_40, 0x40);

// 0x71004bb5e0
u64 Unk_4bb5e0_get(const Unk_4bb5e0* self) {
    return self->field_40;
}
