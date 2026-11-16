// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_104a170 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_104a170, field_0, 0x0);

// 0x710104a170
u32 Unk_104a170_getField0(const Unk_104a170* self) {
    return self->field_0;
}

struct Unk_104a190 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_104a190, field_8, 0x8);

// 0x710104a190
u64 Unk_104a190_getField8(const Unk_104a190* self) {
    return self->field_8;
}
