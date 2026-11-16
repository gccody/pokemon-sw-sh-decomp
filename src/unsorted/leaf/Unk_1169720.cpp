// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1169720 {
    u8 _0[0x60];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_1169720, field_60, 0x60);

// 0x7101169720
u8* Unk_1169720_getField60Ptr(Unk_1169720* self) {
    return &self->field_60;
}

struct Unk_1169730 {
    u8 _0[0x90];
    u8 field_90;
};
PKMN_OFFSET_ASSERT(Unk_1169730, field_90, 0x90);

// 0x7101169730
u8* Unk_1169730_getField90Ptr(Unk_1169730* self) {
    return &self->field_90;
}
