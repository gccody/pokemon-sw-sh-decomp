// Scope: common
// The owner of the items of 0x71003e1d40 (vtable 0x7102385670, on the owner
// 0x7102383cc0). Written from the executable. Placeholder names.
#include "Unk_3e2390.h"

extern void* _ZTV11Unk_2385670[];

// The owner, as its function's name has it: the items are at 8.
struct Unk_3e1c80_T {
    void** field_0;
    Unk_ListPolicy<Unk_3e2390_T, Unk_ListNoCount, Unk_ListNoLast> field_8;
};

// 0x71003e1580: the destructor
void Unk_3e1580(Unk_2383cc0* self) {
    self->field_0 = _ZTV11Unk_2385670 + 2;
    self->Unk_2383cc0::~Unk_2383cc0();
}

// 0x71003e1c80: the items that play `object` are told (with `replace`, only
// those that have nothing else to play)
// NON_MATCHING: the original keeps the item in one more register (what the
// iterator has and the item it reads from are two values there, one here).
void Unk_3e1c80(Unk_3e1c80_T* self, void* object, bool replace) {
    auto it = self->field_8.Begin();
    while (it != self->field_8.End()) {
        Unk_3e2390_T* item = *it;
        ++it;
        if (Unk_3e2390(item, object) && (!replace || !Unk_3e23a0(item, object))) {
            Unk_3e2390_Second& second = item->field_58;
            second.vf0(0xffffffff);
        }
    }
}
