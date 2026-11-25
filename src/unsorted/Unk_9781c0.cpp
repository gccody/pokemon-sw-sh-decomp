// Scope: common
//
// Setters of the battle scene classes on Unk_23dc940 (src/unsorted/Unk_23dc940.h).
// Placeholder names: rename once the classes are known.
#include "unsorted/Unk_23dc940.h"

// Slot 55 of the 70-slot vtables on Unk_23dc940 (0x71023c1698 and six more).
struct Unk_978280_Self {
    u8 _0[0x462];
    bool field_462;
};
PKMN_OFFSET_ASSERT(Unk_978280_Self, field_462, 0x462);

// 0x7100978200
// Slot 39 of Unk_23dc940's vtable (0x71023dc950), which its header declares
// without the parameter.
void Unk_978200(Unk_23dc940* self, const u64& value) {
    self->field_188 = value;
}

// 0x7100978280
void Unk_978280(Unk_978280_Self* self, bool value) {
    self->field_462 = value;
}
