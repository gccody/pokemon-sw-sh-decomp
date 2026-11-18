// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100ff8ce0
void Unk_ff8ce0_update() {}

struct Unk_ff8cf0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff8cf0_arg1, field_0, 0x0);

struct Unk_ff8cf0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff8cf0, field_0, 0x0);

// 0x7100ff8cf0
void Unk_ff8cf0_set(const Unk_ff8cf0* self, Unk_ff8cf0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ff8d00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff8d00_arg1, field_0, 0x0);

struct Unk_ff8d00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff8d00, field_0, 0x0);

// 0x7100ff8d00
void Unk_ff8d00_set(const Unk_ff8d00* self, Unk_ff8d00_arg1* value) {
    value->field_0 = self->field_0;
}
