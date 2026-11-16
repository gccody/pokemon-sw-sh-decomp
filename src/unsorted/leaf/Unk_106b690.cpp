// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_106b690 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_106b690, field_0, 0x0);

// 0x710106b690
u32 Unk_106b690_getField0(const Unk_106b690* self) {
    return self->field_0;
}

struct Unk_106b6a0 {
    u8 _0[0x4];
    u16 field_4;
};
PKMN_OFFSET_ASSERT(Unk_106b6a0, field_4, 0x4);

// 0x710106b6a0
u16 Unk_106b6a0_getField4(const Unk_106b6a0* self) {
    return self->field_4;
}
