// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d754d0 {
    u8 _0[0x13c];
    bool field_13c;
    bool field_13d;
};
PKMN_OFFSET_ASSERT(Unk_d754d0, field_13c, 0x13c);
PKMN_OFFSET_ASSERT(Unk_d754d0, field_13d, 0x13d);

// 0x7100d754d0
void Unk_d754d0_set(Unk_d754d0* self, bool value, bool arg2) {
    self->field_13c = value;
    self->field_13d = arg2;
}

struct Unk_d754f0 {
    u8 _0[0x13e];
    bool field_13e;
};
PKMN_OFFSET_ASSERT(Unk_d754f0, field_13e, 0x13e);

// 0x7100d754f0
void Unk_d754f0_set(Unk_d754f0* self, bool value) {
    self->field_13e = value;
}
