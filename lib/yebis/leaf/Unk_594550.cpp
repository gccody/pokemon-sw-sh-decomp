// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_594550 {
    u32 field_0;
    u32 field_4;
    f32 field_8;
    f32 field_c;
    f32 field_10;
    f32 field_14;
    f32 field_18;
    f32 field_1c;
};
PKMN_OFFSET_ASSERT(Unk_594550, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_594550, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_594550, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_594550, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_594550, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_594550, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_594550, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_594550, field_1c, 0x1c);

// 0x7100594550
void Unk_594550_set(Unk_594550* self, u32 value, f32 fvalue, f32 farg1, f32 farg2, f32 farg3, f32 farg4, f32 farg5) {
    self->field_0 = value;
    self->field_4 = 1;
    self->field_8 = fvalue;
    self->field_c = farg1;
    self->field_10 = farg2;
    self->field_14 = farg3;
    self->field_18 = farg4;
    self->field_1c = farg5;
}

// 0x7100594580
void Unk_594580_update(void* /*unused*/) {
}
