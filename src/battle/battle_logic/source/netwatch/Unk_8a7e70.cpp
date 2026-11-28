// Scope: common
// Two more of the battle data exchange's calls on its peer (Unk_8a7910.h),
// after 0x71008a7e70 (src/unsorted/leaf/Unk_8a7bd0.cpp). Part of the segment
// 0x71008a7910-0x71008a7f30. Placeholder names: rename once the classes are
// known.
#include "battle/battle_logic/source/netwatch/Unk_8a7910.h"

struct Unk_896c60;
void Unk_896c60_clearField360(Unk_896c60* self);

// 0x71008a7e80
bool Unk_8a7e80(Unk_8a7ab0_Handle* self) {
    if (self->field_0.m_ptr != nullptr)
        return self->field_0.m_ptr->Unk_8969d0(self->field_4e59);
    return false;
}

// 0x71008a7ea0
void Unk_8a7ea0(Unk_8a7ab0_Handle* self) {
    if (self->field_0.m_ptr != nullptr)
        Unk_896c60_clearField360(reinterpret_cast<Unk_896c60*>(self->field_0.m_ptr));
}
