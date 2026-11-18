// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1079e10 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1079e10, field_0, 0x0);

// 0x7101079e10
void Unk_1079e10_set(Unk_1079e10* self) {
    if (self->field_0 != 0) {
        self->field_0 = 0;
    }
}
