// Scope: common
// A record's setter and getter, in the TU of 0x71008ec680-0x71008ec7f0.
// Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8ec680_Value {
    u8 field_0;
    u8 field_1;
};
PKMN_SIZE_ASSERT(Unk_8ec680_Value, 0x2);

struct Unk_8ec680 {
    u8 _0[0x20];
    Unk_8ec680_Value field_20;
    u8 _22[0x2];
    u32 field_24;
    bool field_28;
    bool field_29;
};
PKMN_OFFSET_ASSERT(Unk_8ec680, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_8ec680, field_24, 0x24);
PKMN_OFFSET_ASSERT(Unk_8ec680, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_8ec680, field_29, 0x29);

// 0x71008ec680
void Unk_8ec680_set(Unk_8ec680* self, const Unk_8ec680_Value* value) {
    self->field_24 = 0;
    self->field_28 = false;
    self->field_29 = false;
    self->field_20.field_0 = value->field_0;
    self->field_20.field_1 = value->field_1;
    self->field_28 = true;
}

struct Unk_8ec6b0_Out {
    bool field_0;
    u8 _1;
    u16 field_2;
};
PKMN_OFFSET_ASSERT(Unk_8ec6b0_Out, field_2, 0x2);

// 0x71008ec6b0
bool Unk_8ec6b0_get(const Unk_8ec680* self, Unk_8ec6b0_Out* out) {
    bool flag = self->field_29;
    if (out != nullptr) {
        out->field_0 = flag && self->field_24 != 0;
        out->field_2 = self->field_24;
    }
    return flag;
}
