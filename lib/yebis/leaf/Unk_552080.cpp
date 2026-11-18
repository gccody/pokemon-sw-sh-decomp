// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_552080 {
    u8 _0[0x5c];
    u32 field_5c;
};
PKMN_OFFSET_ASSERT(Unk_552080, field_5c, 0x5c);

// 0x7100552080
u32 Unk_552080_get(const Unk_552080* self) {
    return self->field_5c;
}

struct Unk_552840 {
    u8 _0[0x5c];
    u32 field_5c;
};
PKMN_OFFSET_ASSERT(Unk_552840, field_5c, 0x5c);

// 0x7100552840
u32 Unk_552840_get(const Unk_552840* self) {
    return self->field_5c;
}
