// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_13b2310 {
    u8 _0[0x68];
    u8 field_68;
};
PKMN_OFFSET_ASSERT(Unk_13b2310, field_68, 0x68);

// 0x71013b2310
u8* Unk_13b2310_getField68Ptr(Unk_13b2310* self) {
    return &self->field_68;
}

struct Unk_13b2330 {
    u8 _0[0x70];
    u8 field_70;
};
PKMN_OFFSET_ASSERT(Unk_13b2330, field_70, 0x70);

// 0x71013b2330
u8* Unk_13b2330_getField70Ptr(Unk_13b2330* self) {
    return &self->field_70;
}
