// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_965ae0 {
    u8 _0[0x5b8];
    u64 field_5b8;
};
PKMN_OFFSET_ASSERT(Unk_965ae0, field_5b8, 0x5b8);

void Unk_c67c60(u64);

// 0x7100965ae0
void Unk_965ae0_call(const Unk_965ae0* self) {
    if (self->field_5b8 != 0) {
        Unk_c67c60(self->field_5b8);
    }
}

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
