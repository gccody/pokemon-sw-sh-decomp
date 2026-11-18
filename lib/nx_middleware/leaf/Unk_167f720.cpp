// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_167f720_48 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_167f720_48, field_8, 0x8);

struct Unk_167f720 {
    u8 _0[0x48];
    Unk_167f720_48* field_48;
};
PKMN_OFFSET_ASSERT(Unk_167f720, field_48, 0x48);

// 0x710167f720
u32 Unk_167f720_get(const Unk_167f720* self) {
    if (self->field_48 == nullptr) {
        return 0;
    }
    return self->field_48->field_8;
}
