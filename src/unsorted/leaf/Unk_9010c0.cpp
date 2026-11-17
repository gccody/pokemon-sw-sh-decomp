// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_9010c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9010c0_arg1, field_0, 0x0);

struct Unk_9010c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9010c0, field_0, 0x0);

// 0x71009010c0
void Unk_9010c0_set(const Unk_9010c0* self, Unk_9010c0_arg1* value) {
    value->field_0 = self->field_0;
}
