// Scope: common
// The initialisation and copy of a battle Pokemon's field effect state
// (Unk_7ee6b0_Field), and the flags of the class with the vtable Unk_23ac938.
// Placeholder names: rename once the classes are known.
#include "battle/battle_engine/Unk_7ff840.h"

// 0x71007ff8f0
void Unk_7ff8f0(void* object) {
    Unk_7ee6b0_Field* self = static_cast<Unk_7ee6b0_Field*>(object);
    for (u32 i = 0; i < Unk_7ee6b0_Field::kSlots; i++)
        Unk_7ee6b0_Field_clearSlot(self, i);
    self->field_0 = 0;
    self->field_4 = 0xff;
    self->field_c = 0;
    self->field_10 = 0x1f;
}

// 0x71007ffa90
void Unk_7ffa90(Unk_7ee6b0_Field* self, const Unk_7ee6b0_Field* other) {
    *self = *other;
}

// The data of the Unk_23ac938 class: a flag per index after the vptr.
struct Unk_7ff880_Flags {
    u8 _0[0x8];
    bool field_8[1];
};
PKMN_OFFSET_ASSERT(Unk_7ff880_Flags, field_8, 0x8);

// 0x71007ff880
bool Unk_7ff880(void* self, u16 index) {
    return static_cast<Unk_7ff880_Flags*>(self)->field_8[index];
}

// 0x71007ff890
void Unk_7ff890(void* self, u16 index) {
    static_cast<Unk_7ff880_Flags*>(self)->field_8[index] = true;
}
