// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8a7bd0 {
    u8 _0[0x2730];
    u8 field_2730;
};
PKMN_OFFSET_ASSERT(Unk_8a7bd0, field_2730, 0x2730);

// 0x71008a7bd0
const u8* Unk_8a7bd0_get(const Unk_8a7bd0* self) {
    return &self->field_2730;
}

struct Unk_8a7e70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8a7e70, field_0, 0x0);

void Unk_896c30(u64);

// 0x71008a7e70
void Unk_8a7e70_call(const Unk_8a7e70* self) {
    if (self->field_0 != 0) {
        Unk_896c30(self->field_0);
    }
}
