// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8a6bc0 {
    u8 _0[0x70];
    u32 field_70;
    u8 field_74;
};
PKMN_OFFSET_ASSERT(Unk_8a6bc0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_8a6bc0, field_74, 0x74);

// 0x71008a6bc0
bool Unk_8a6bc0_check(const Unk_8a6bc0* self) {
    if (self->field_74 == 0) {
        return false;
    }
    return self->field_70 != 8;
}

struct Unk_8a6d00 {
    u8 _0[0x75];
    u8 field_75;
};
PKMN_OFFSET_ASSERT(Unk_8a6d00, field_75, 0x75);

// 0x71008a6d00
void Unk_8a6d00_set(Unk_8a6d00* self) {
    self->field_75 = 1;
}
