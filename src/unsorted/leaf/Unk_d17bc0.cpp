// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d17bc0 {
    u8 _0[0x600];
    u64 field_600;
};
PKMN_OFFSET_ASSERT(Unk_d17bc0, field_600, 0x600);

// 0x7100d17bc0
bool Unk_d17bc0_check(const Unk_d17bc0* self) {
    return self->field_600 != 0xcbf29ce484222645;
}
