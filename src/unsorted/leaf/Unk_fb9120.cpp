// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_fb9120 {
    u8 _0[0x154];
    u32 field_154;
};
PKMN_OFFSET_ASSERT(Unk_fb9120, field_154, 0x154);

// 0x7100fb9120
void Unk_fb9120_setField154(Unk_fb9120* self, u32 value) {
    self->field_154 = value;
}

struct Unk_fb9130 {
    u8 _0[0x154];
    u32 field_154;
};
PKMN_OFFSET_ASSERT(Unk_fb9130, field_154, 0x154);

// 0x7100fb9130
void Unk_fb9130_set(Unk_fb9130* self) {
    self->field_154 = 0xffffffff;
}
