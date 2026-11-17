// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_eb6230(void*, u32);

// 0x710141be00
void Unk_141be00_call(void* self) {
    Unk_eb6230(self, 2);
}

struct Unk_14249a0 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_14249a0, field_68, 0x68);

// 0x71014249a0
u64 Unk_14249a0_getField68(const Unk_14249a0* self) {
    return self->field_68;
}

struct Unk_14249b0 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_14249b0, field_b0, 0xb0);

// 0x71014249b0
u64 Unk_14249b0_getFieldb0(const Unk_14249b0* self) {
    return self->field_b0;
}

struct Unk_14249c0 {
    u8 _0[0xc0];
    u8 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_14249c0, field_c0, 0xc0);

// 0x71014249c0
u8* Unk_14249c0_getFieldc0Ptr(Unk_14249c0* self) {
    return &self->field_c0;
}

struct Unk_142a1b0 {
    u8 _0[0x74];
    u8 field_74;
};
PKMN_OFFSET_ASSERT(Unk_142a1b0, field_74, 0x74);

// 0x710142a1b0
void Unk_142a1b0_set(Unk_142a1b0* self) {
    self->field_74 = 1;
}
