// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100cea2e0
void Unk_cea2e0_update() {}

struct Unk_cea2f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cea2f0_arg1, field_0, 0x0);

struct Unk_cea2f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cea2f0, field_0, 0x0);

// 0x7100cea2f0
void Unk_cea2f0_set(const Unk_cea2f0* self, Unk_cea2f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cea300_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cea300_arg1, field_0, 0x0);

struct Unk_cea300 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cea300, field_0, 0x0);

// 0x7100cea300
void Unk_cea300_set(const Unk_cea300* self, Unk_cea300_arg1* value) {
    value->field_0 = self->field_0;
}
