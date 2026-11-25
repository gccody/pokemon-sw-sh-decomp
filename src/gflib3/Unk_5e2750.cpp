// Scope: common
//
// Functions of Unk_239a360 (src/gflib3/Unk_5e2700_Task.h), after Unk_239a418's
// in the same TU.
#include <algorithm>

#include "gflib3/Unk_5e2700_Task.h"

// 0x71005e2830
void Unk_5e2830(Unk_239a360_Self* self) {
    if (!self->field_171)
        Unk_5e6090(&self->field_90);
}

// NON_MATCHING: `this` and this + 0x130 swap registers, and the original
// branches from an empty field_b0 straight past the erase, where this tests
// the found iterator against its end first.
// 0x71005e2d80: marks it done, tells the listeners that weren't removed, and
// wakes what waits for it.
void Unk_5e2d80(Unk_239a360_Self* self) {
    nn::os::LockMutex(&self->field_110);
    nn::os::LockMutex(&self->field_130);
    self->field_170 = true;
    for (Unk_239a360_Listener* listener : self->field_b0) {
        if (std::find(self->field_e0.begin(), self->field_e0.end(), listener) ==
            self->field_e0.end())
            listener->vf0();
    }
    for (Unk_239a360_Listener* listener : self->field_e0) {
        auto it = std::find(self->field_b0.begin(), self->field_b0.end(), listener);
        if (it != self->field_b0.end())
            self->field_b0.erase(it);
    }
    self->field_e0.clear();
    nn::os::BroadcastConditionVariable(&self->field_150);
    nn::os::UnlockMutex(&self->field_130);
    nn::os::UnlockMutex(&self->field_110);
}
