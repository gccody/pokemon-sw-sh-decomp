// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_55c990 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_55c990, field_28, 0x28);

// 0x710055c990
u32 Unk_55c990_update(Unk_55c990* self, u64 value) {
    self->field_28 = value;
    return 1;
}

struct Unk_55d3b0 {
    u8 _0[0x108];
    u32 field_108;
};
PKMN_OFFSET_ASSERT(Unk_55d3b0, field_108, 0x108);

// 0x710055d3b0
u32 Unk_55d3b0_get(const Unk_55d3b0* self) {
    return self->field_108;
}
