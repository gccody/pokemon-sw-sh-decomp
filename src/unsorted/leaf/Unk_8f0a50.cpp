// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8f0a50_68 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_8f0a50_68, field_58, 0x58);

struct Unk_8f0a50 {
    u8 _0[0x68];
    Unk_8f0a50_68* field_68;
};
PKMN_OFFSET_ASSERT(Unk_8f0a50, field_68, 0x68);

// 0x71008f0a50
u32 Unk_8f0a50_get(const Unk_8f0a50* self) {
    if (self->field_68 == nullptr) {
        return 0;
    }
    return self->field_68->field_58 & 1;
}
