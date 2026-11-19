// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_de8af0(void*, void*, u32, u64);

// 0x7100de8ae0
void Unk_de8ae0_call(void* self, void* value, u64 arg2) {
    Unk_de8af0(self, value, 0, arg2);
}

struct Unk_ded9e0 {
    f32 field_0;
    f32 field_4;
    f32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_ded9e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ded9e0, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_ded9e0, field_8, 0x8);

// 0x7100ded9e0
void Unk_ded9e0_set(Unk_ded9e0* self, f32 fvalue, f32 farg1, f32 farg2) {
    self->field_0 = fvalue;
    self->field_4 = farg1;
    self->field_8 = farg2;
}
