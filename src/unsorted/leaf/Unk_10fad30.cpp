// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_10fad30 {
    u8 _0[0x50];
    u32 field_50;
};
PKMN_OFFSET_ASSERT(Unk_10fad30, field_50, 0x50);

// 0x71010fad30
bool Unk_10fad30_check(const Unk_10fad30* self) {
    return self->field_50 == 0;
}

struct Unk_10fad40 {
    u8 _0[0x50];
    u32 field_50;
};
PKMN_OFFSET_ASSERT(Unk_10fad40, field_50, 0x50);

// 0x71010fad40
bool Unk_10fad40_check(const Unk_10fad40* self) {
    return self->field_50 == 2;
}
