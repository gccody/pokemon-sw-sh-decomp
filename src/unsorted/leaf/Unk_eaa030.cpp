// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_eaa030 {
    u8 _0[0x50];
    u8 field_50;
};
PKMN_OFFSET_ASSERT(Unk_eaa030, field_50, 0x50);

// 0x7100eaa030
u8* Unk_eaa030_getField50Ptr(Unk_eaa030* self) {
    return &self->field_50;
}

struct Unk_eab4b0_58 {
    u8 _0[0x168];
    u32 field_168;
};
PKMN_OFFSET_ASSERT(Unk_eab4b0_58, field_168, 0x168);

struct Unk_eab4b0 {
    u8 _0[0x58];
    Unk_eab4b0_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_eab4b0, field_58, 0x58);

// 0x7100eab4b0
u32 Unk_eab4b0_get(const Unk_eab4b0* self) {
    return self->field_58->field_168;
}

struct Unk_eab4c0_58 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_eab4c0_58, field_0, 0x0);

struct Unk_eab4c0 {
    u8 _0[0x58];
    Unk_eab4c0_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_eab4c0, field_58, 0x58);

// 0x7100eab4c0
bool Unk_eab4c0_check(const Unk_eab4c0* self) {
    return self->field_58->field_0 != 0xffffffff;
}

struct Unk_ead140 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_ead140, field_10, 0x10);

// 0x7100ead140
u64 Unk_ead140_getField10(const Unk_ead140* self) {
    return self->field_10;
}
