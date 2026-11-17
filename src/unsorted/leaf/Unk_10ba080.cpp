// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_10ba080 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ba080, field_0, 0x0);

// 0x71010ba080
bool Unk_10ba080_check(const Unk_10ba080* self) {
    return self->field_0 != 0;
}
