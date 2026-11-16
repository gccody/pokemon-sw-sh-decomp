// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_6ce100 {
    u8 _0[0x110];
    u32 field_110;
};
PKMN_OFFSET_ASSERT(Unk_6ce100, field_110, 0x110);

// 0x71006ce100
u32 Unk_6ce100_getField110(const Unk_6ce100* self) {
    return self->field_110;
}

struct Unk_6ce3c0 {
    u8 _0[0x110];
    u32 field_110;
};
PKMN_OFFSET_ASSERT(Unk_6ce3c0, field_110, 0x110);

// 0x71006ce3c0
void Unk_6ce3c0_setField110(Unk_6ce3c0* self, u32 value) {
    self->field_110 = value;
}
