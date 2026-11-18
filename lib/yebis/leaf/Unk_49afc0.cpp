// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_49afc0 {
    u8 _0[0x70];
    f32 field_70;
    f32 field_74;
};
PKMN_OFFSET_ASSERT(Unk_49afc0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_49afc0, field_74, 0x74);

// 0x710049afc0
u32 Unk_49afc0_update(Unk_49afc0* self, f32 fvalue, f32 farg1) {
    self->field_70 = fvalue;
    self->field_74 = farg1;
    return 0;
}

void Unk_49ca70(void*, u64, u32);

// 0x710049c8d0
void Unk_49c8d0_call(void* self, u64 value) {
    Unk_49ca70(self, value, 0xffffffff);
}
