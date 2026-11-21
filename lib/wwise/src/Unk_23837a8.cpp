// Scope: common
// Functions of the class with the vtable 0x71023837a8: a subscriber to a
// switch or state group, a base class of the nodes that follow one.
// Placeholder names.
#include "Unk_23837a8.h"

extern u64 Unk_24bbbc8;  // the switch groups' manager
extern u64 Unk_24bbbd0;  // the state groups' manager

void Unk_3bb8e0(u64, void*);
void Unk_3b53c0(u64, void*);
u32 Unk_3bb230(u64 self, void* subscriber, u32 group);
u32 Unk_3b52e0(u64 self, void* subscriber, u32 group);

// 0x71003b7900: the subscriber (the object's member at 0xd8) follows `group`
u32 Unk_3b7900(void* self, u32 group, u32 type) {
    Unk_3bb8e0(Unk_24bbbc8, self);
    Unk_3b53c0(Unk_24bbbd0, self);
    if (group == 0)
        return 1;
    switch (type) {
    case 0:
        return Unk_3bb230(Unk_24bbbc8, self, group);
    case 1:
        return Unk_3b52e0(Unk_24bbbd0, self, group);
    default:
        return 0x1f;
    }
}

// 0x71003b78a0, 0x71003b78b0 (the deleting destructor of an abstract class: a trap)
Unk_23837a8::~Unk_23837a8() {}
