// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_db70f0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_db70f0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_db70f0_arg1, field_8, 0x8);

struct Unk_db70f0 {
    u8 _0[0x130];
    f32 field_130;
    f32 field_134;
    f32 field_138;
    u8 _13c[0x4];
    u64 field_140;
    u64 field_148;
};
PKMN_OFFSET_ASSERT(Unk_db70f0, field_130, 0x130);
PKMN_OFFSET_ASSERT(Unk_db70f0, field_134, 0x134);
PKMN_OFFSET_ASSERT(Unk_db70f0, field_138, 0x138);
PKMN_OFFSET_ASSERT(Unk_db70f0, field_140, 0x140);
PKMN_OFFSET_ASSERT(Unk_db70f0, field_148, 0x148);

// 0x7100db70f0
void Unk_db70f0_set(Unk_db70f0* self, const Unk_db70f0_arg1* value, f32 fvalue, f32 farg1) {
    self->field_130 = farg1;
    self->field_134 = farg1;
    self->field_148 = value->field_8;
    self->field_140 = value->field_0;
    self->field_138 = fvalue;
}
