// Scope: common
//
// gflib3's reference-counted objects (src/gflib3/Unk_239a418.h and
// src/gflib3/Unk_239a4c0.h): the functions of their vtables. Each one's
// first out-of-line virtual function is its key function, so their vtables,
// inline destructors and their thunks are emitted here.
#include "gflib3/Unk_239a418.h"
#include "gflib3/Unk_239a4c0.h"
#include "gflib3/Unk_5e2700_Task.h"
#include "gflib3/Unk_New.h"

// What makes the objects' handles: its allocator, at +0x8.
struct Unk_27736e0_Object {
    u64 field_0;
    Unk_239a418_Allocator* field_8;
};
PKMN_OFFSET_ASSERT(Unk_27736e0_Object, field_8, 0x8);

extern Unk_27736e0_Object* Unk_27736e0;

// 0x71005e2350
// NON_MATCHING: ordering. The allocator is stored before the three vptrs (the
// +0x50 one first, with the pre-indexed store that keeps this + 0x50 for the
// handle), where the original pairs it with the primary vptr; Unk_23f5d00's
// constructor (two vptrs) matches with the same root constructor.
//
// The handle's interface pointer is converted in Create (`this`, not
// this + 0x50, is passed): converted here, its null test would be next to the
// handle constructor's call, and LLVM's call site splitting makes a copy of it
// with a null `this`, which becomes a trap after vf23.
Unk_239a418::Unk_239a418() {
    m_handle = Unk_239a418_Ref<Unk_239a418_Handle>(
        Unk_New().Create<Unk_239a418_Handle>(Unk_27736e0->field_8, this));
}

// 0x71005e2700
void Unk_239a418::vf3() {
    Unk_239a418_Allocator* allocator = field_8;
    u64 arg1 = field_10;
    u64 arg2 = field_18;
    u64 arg3 = field_20;
    this->~Unk_239a418();
    allocator->vf3(arg1, arg2, arg3);
}

// 0x71005e3050, 0x71005e3290 (its thunk from +0x48)
Unk_239a418_Ref<Unk_239a418_Handle> Unk_239a418::vf2() {
    return m_handle;
}

// 0x71005e3070, 0x71005e3200 (its thunk from +0x48)
void Unk_239a418::vf4() {
    Unk_239a418_Handle* handle = m_handle.m_ptr;
    if (handle->field_58 == nullptr)
        handle->field_58 = handle->field_60->vf0();
    ++handle->field_54;
}

// 0x71005e30c0, 0x71005e3250 (its thunk from +0x48)
void Unk_239a418::vf5() {
    Unk_239a418_Handle* handle = m_handle.m_ptr;
    if (--handle->field_54 == 0) {
        handle->field_60 = nullptr;
        vf3();
    }
}

// 0x71005e3640; its D0 0x71005e3630 and the thunks from +0x48 0x71005e3690,
// 0x71005e36a0 come with its vtable
void Unk_239a4c0::vf2() {
    Unk_239a418_Allocator* allocator = field_8;
    u64 arg1 = field_10;
    u64 arg2 = field_18;
    u64 arg3 = field_20;
    this->~Unk_239a4c0();
    allocator->vf3(arg1, arg2, arg3);
}

// Called with the owner of the tasks (the global Unk_5e5020_Owner points to)
// and a task, before the task is destroyed.
void Unk_5e5020(void* owner, void* task);
extern void* Unk_5e5020_Owner;

// NON_MATCHING: register allocation. The original keeps the temporary's handle
// and the assigned one in two registers (copied), this in one.
// 0x71005e2500: sets the weak reference (or clears it).
void Unk_5e2500(Unk_239a360_Self* self, const Unk_239a360_Weak* weak) {
    self->field_160 = weak ? *weak : Unk_239a360_Weak();
}

// 0x71005e25c0: the weak reference, while its object is there.
Unk_239a360_Weak* Unk_5e25c0(Unk_239a360_Self* self) {
    return Unk_5e3aa0(&self->field_160) ? &self->field_160 : nullptr;
}

// 0x71005e26a0: waits until it's done.
void Unk_5e26a0(void* object) {
    Unk_239a360_Self* self = static_cast<Unk_239a360_Self*>(object);
    nn::os::LockMutex(&self->field_130);
    while (!self->field_170)
        nn::os::WaitConditionVariable(&self->field_150, &self->field_130);
    nn::os::UnlockMutex(&self->field_130);
}

// 0x71005e25f0: Unk_239a360's vf3, destroy and free once it's done.
void Unk_5e25f0(Unk_239a360_Self* self) {
    Unk_5e26a0(self);
    Unk_5e5020(Unk_5e5020_Owner, self);
    Unk_239a418_Allocator* allocator = self->field_8;
    u64 arg1 = self->field_10;
    u64 arg2 = self->field_18;
    u64 arg3 = self->field_20;
    self->~Unk_239a360_Self();
    allocator->vf3(arg1, arg2, arg3);
}
