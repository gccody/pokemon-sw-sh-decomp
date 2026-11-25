// Scope: common
// Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_fae1e0_0 {
    u8 _0[0x7c];
    u32 field_7c;
    u8 _80[0x3a7 - 0x80];
    bool field_3a7;
    bool field_3a8;
};
PKMN_OFFSET_ASSERT(Unk_fae1e0_0, field_7c, 0x7c);
PKMN_OFFSET_ASSERT(Unk_fae1e0_0, field_3a7, 0x3a7);
PKMN_OFFSET_ASSERT(Unk_fae1e0_0, field_3a8, 0x3a8);

struct Unk_fae1e0 {
    Unk_fae1e0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_fae1e0, field_0, 0x0);

// 0x7100fae1e0
void Unk_fae1e0_reset(const Unk_fae1e0* self) {
    Unk_fae1e0_0* obj = self->field_0;
    obj->field_3a7 = false;
    obj->field_3a8 = false;
    obj->field_7c = 1;
}

// 0x7100fae270
void Unk_fae270_reset(const Unk_fae1e0* self) {
    Unk_fae1e0_0* obj = self->field_0;
    obj->field_3a7 = false;
    obj->field_3a8 = false;
    obj->field_7c = 1;
}
