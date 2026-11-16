// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_120f9e0 {
    u8 _0[0x70];
    u64 field_70;
};
PKMN_OFFSET_ASSERT(Unk_120f9e0, field_70, 0x70);

// 0x710120f9e0
void Unk_120f9e0_setField70(Unk_120f9e0* self, u64 value) {
    self->field_70 = value;
}

struct Unk_1210230 {
    u8 _0[0x140];
    u32 field_140;
};
PKMN_OFFSET_ASSERT(Unk_1210230, field_140, 0x140);

// 0x7101210230
u32 Unk_1210230_getField140(const Unk_1210230* self) {
    return self->field_140;
}

struct Unk_1210240 {
    u8 _0[0x148];
    u8 field_148;
};
PKMN_OFFSET_ASSERT(Unk_1210240, field_148, 0x148);

// 0x7101210240
u8* Unk_1210240_getField148Ptr(Unk_1210240* self) {
    return &self->field_148;
}
