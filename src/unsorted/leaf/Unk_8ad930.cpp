// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8ad930 {
    u8 _0[0x2530];
    s32 field_2530;
};
PKMN_OFFSET_ASSERT(Unk_8ad930, field_2530, 0x2530);

// 0x71008ad930
bool Unk_8ad930_check(const Unk_8ad930* self) {
    return self->field_2530 > 2;
}

struct Unk_8ad940 {
    u8 _0[0x2530];
    u32 field_2530;
};
PKMN_OFFSET_ASSERT(Unk_8ad940, field_2530, 0x2530);

// 0x71008ad940
bool Unk_8ad940_check(const Unk_8ad940* self) {
    return self->field_2530 == 8;
}
