// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_5e3a50_0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_5e3a50_0, field_10, 0x10);

struct Unk_5e3a50 {
    Unk_5e3a50_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_5e3a50, field_0, 0x0);

// 0x71005e3a50
u32 Unk_5e3a50_get(const Unk_5e3a50* self) {
    if (self->field_0 == nullptr) {
        return 0;
    }
    return self->field_0->field_10;
}
