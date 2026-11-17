// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8d7c80 {
    u8 _0[0x6b4];
    u32 field_6b4;
};
PKMN_OFFSET_ASSERT(Unk_8d7c80, field_6b4, 0x6b4);

// 0x71008d7c80
u32 Unk_8d7c80_getField6b4(const Unk_8d7c80* self) {
    return self->field_6b4;
}

struct Unk_8e04b0 {
    u8 _0[0x188];
    u64 field_188;
};
PKMN_OFFSET_ASSERT(Unk_8e04b0, field_188, 0x188);

// 0x71008e04b0
bool Unk_8e04b0_check(const Unk_8e04b0* self) {
    return self->field_188 != 0;
}

struct Unk_8e0710_188 {
    u8 _0[0x5a1];
    u8 field_5a1;
};
PKMN_OFFSET_ASSERT(Unk_8e0710_188, field_5a1, 0x5a1);

struct Unk_8e0710 {
    u8 _0[0x188];
    Unk_8e0710_188* field_188;
};
PKMN_OFFSET_ASSERT(Unk_8e0710, field_188, 0x188);

// 0x71008e0710
u8 Unk_8e0710_get(const Unk_8e0710* self) {
    if (self->field_188 == nullptr) {
        return 0;
    }
    return self->field_188->field_5a1;
}
