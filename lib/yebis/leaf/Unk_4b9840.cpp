// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_4b9840 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_4b9840, field_10, 0x10);

// 0x71004b9840
const u8* Unk_4b9840_get(const Unk_4b9840* self) {
    return &self->field_10;
}

struct Unk_4b9850 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_4b9850, field_10, 0x10);

// 0x71004b9850
const u8* Unk_4b9850_get(const Unk_4b9850* self) {
    return &self->field_10;
}
