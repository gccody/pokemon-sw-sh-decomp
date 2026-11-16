// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8a9060 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_8a9060, field_58, 0x58);

// 0x71008a9060
u64 Unk_8a9060_getField58(const Unk_8a9060* self) {
    return self->field_58;
}

struct Unk_8a9070 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_8a9070, field_58, 0x58);

// 0x71008a9070
u64 Unk_8a9070_getField58(const Unk_8a9070* self) {
    return self->field_58;
}

struct Unk_8aac00 {
    u8 _0[0x2];
    u8 field_2;
};
PKMN_OFFSET_ASSERT(Unk_8aac00, field_2, 0x2);

// 0x71008aac00
void Unk_8aac00_setField2(Unk_8aac00* self, u8 value) {
    self->field_2 = value;
}
