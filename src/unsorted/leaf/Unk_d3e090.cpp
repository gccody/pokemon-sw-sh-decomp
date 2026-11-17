// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d3e090 {
    u8 _0[0x650];
    u32 field_650;
    bool field_654;
};
PKMN_OFFSET_ASSERT(Unk_d3e090, field_650, 0x650);
PKMN_OFFSET_ASSERT(Unk_d3e090, field_654, 0x654);

// 0x7100d3e090
void Unk_d3e090_set(Unk_d3e090* self, u32 value, bool arg2) {
    self->field_650 = value;
    self->field_654 = arg2;
}

struct Unk_d45b60 {
    u8 _0[0x7e8];
    u32 field_7e8;
};
PKMN_OFFSET_ASSERT(Unk_d45b60, field_7e8, 0x7e8);

// 0x7100d45b60
bool Unk_d45b60_check(const Unk_d45b60* self) {
    return self->field_7e8 != 0;
}
