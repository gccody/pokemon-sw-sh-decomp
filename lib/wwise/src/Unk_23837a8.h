#pragma once
// The class with the vtable 0x71023837a8: a subscriber to a switch or state
// group, an abstract base class of the objects that follow one. Placeholder
// names.
#include <types.h>

class Unk_23837a8 {
public:
    Unk_23837a8();
    virtual ~Unk_23837a8();
    virtual void vf2() = 0;  // the group's value changed
};

// 0x71003b78c0: stops following its group
void Unk_3b78c0_call(void* self);
// 0x71003b7900: follows `group`, a switch group (type 0) or a state group (1)
u32 Unk_3b7900(void* self, u32 group, u32 type);
