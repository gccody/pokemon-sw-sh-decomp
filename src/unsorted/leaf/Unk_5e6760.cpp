// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_5e6760_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5e6760_arg1, field_0, 0x0);

struct Unk_5e6760 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5e6760, field_0, 0x0);

// 0x71005e6760
void Unk_5e6760_set(Unk_5e6760* self, const Unk_5e6760_arg1* value) {
    self->field_0 = value->field_0;
}
