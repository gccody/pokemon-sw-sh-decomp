// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_117b380 {
    u8 _0[0x154];
    u32 field_154;
};
PKMN_OFFSET_ASSERT(Unk_117b380, field_154, 0x154);

// 0x710117b380
void Unk_117b380_setField154(Unk_117b380* self, u32 value) {
    self->field_154 = value;
}
