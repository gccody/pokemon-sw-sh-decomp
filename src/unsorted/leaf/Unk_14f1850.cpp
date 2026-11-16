// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_14f1850 {
    u8 _0[0x79c];
    u32 field_79c;
};
PKMN_OFFSET_ASSERT(Unk_14f1850, field_79c, 0x79c);

// 0x71014f1850
void Unk_14f1850_setField79c(Unk_14f1850* self, u32 value) {
    self->field_79c = value;
}

// 0x71014f5c60
u32 Unk_14f5c60() {
    return 0;
}

struct Unk_14f8030 {
    u8 _0[0x1dc];
    u8 field_1dc;
};
PKMN_OFFSET_ASSERT(Unk_14f8030, field_1dc, 0x1dc);

// 0x71014f8030
u8 Unk_14f8030_getField1dc(const Unk_14f8030* self) {
    return self->field_1dc;
}

// 0x71015030e0
void Unk_15030e0() {}

struct Unk_1505fc0 {
    u8 _0[0x1b0];
    u8 field_1b0;
};
PKMN_OFFSET_ASSERT(Unk_1505fc0, field_1b0, 0x1b0);

// 0x7101505fc0
u8* Unk_1505fc0_getField1b0Ptr(Unk_1505fc0* self) {
    return &self->field_1b0;
}
