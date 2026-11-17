// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_981b60 {
    u8 _0[0x541];
    bool field_541;
};
PKMN_OFFSET_ASSERT(Unk_981b60, field_541, 0x541);

// 0x7100981b60
void Unk_981b60_set(Unk_981b60* self, bool value) {
    self->field_541 = value;
}

struct Unk_983f60 {
    u8 _0[0x4b1];
    u8 field_4b1;
};
PKMN_OFFSET_ASSERT(Unk_983f60, field_4b1, 0x4b1);

// 0x7100983f60
u8 Unk_983f60_getField4b1(const Unk_983f60* self) {
    return self->field_4b1;
}
