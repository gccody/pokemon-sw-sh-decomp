// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_559d30 {
    u8 _0[0x250];
    u64 field_250;
};
PKMN_OFFSET_ASSERT(Unk_559d30, field_250, 0x250);

// 0x7100559d30
u64 Unk_559d30_get(const Unk_559d30* self) {
    return self->field_250;
}
