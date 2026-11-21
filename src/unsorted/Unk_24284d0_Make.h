#pragma once
// What the TUs with classes on Unk_24284d0 (src/unsorted/Unk_24284d0.h) share:
// how they make one, and what some of their callables do. In an anonymous
// namespace: the functions that make a class are local to their TU (called
// where there are several callers, inlined where there's one).
#include <new>
#include <utility>

#include "gflib3/Unk_2399590.h"
#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_24284d0.h"
#include "unsorted/Unk_2771620.h"

// 0x710126ac90: field_68 of Unk_24284d0, out of line (written as a leaf).
struct Unk_126ac90;
u64 Unk_126ac90_getField68(const Unk_126ac90*);

// The four functions of a callable that does nothing, all empty (written as
// leaves), and such a callable.
void Unk_1260810_update();
void Unk_1260820_update();
void Unk_1260830_update();
void Unk_1260840_update();

class Unk_1260810_Callable : public Unk_23d4470_Callable {
public:
    Unk_1260810_Callable() {
        field_0 = reinterpret_cast<u64>(&Unk_1260810_update);
        field_8 = reinterpret_cast<void (*)(void*)>(&Unk_1260820_update);
        field_10 = reinterpret_cast<u64>(&Unk_1260830_update);
        field_18 = reinterpret_cast<u64>(&Unk_1260840_update);
    }
};

// What Unk_24284d0::Unk_126aca0's result points at: an object with a lock
// that keeps callables by hash (0x7101127d00, not decompiled).
class Unk_1127d00_Owner {
public:
    void Unk_1127d00(u64 hash, Unk_23d4470_Callable& callable, bool arg3);

    u8 _0[0x60];
    Unk_2399590_Lock field_60;
};

namespace {

// Makes a T on `allocator`, as Unk_New::Create does (src/gflib3/Unk_New.h).
// The allocation is a T* when it's tested: the constructor's call is then
// split in two, one of them with a null pointer (LLVM's call site splitting
// needs the tested value to be the call's argument).
template <class T>
T* Unk_Create(Unk_239a418_Allocator* allocator) {
    Unk_2771620_Scope scope(allocator);
    T* p = static_cast<T*>(allocator->vf2(sizeof(T), alignof(T)));
    if (p == nullptr)
        allocator->vf23();
    T* object = ::new (p) T();
    object->field_8 = allocator;
    object->field_10 = reinterpret_cast<u64>(object);
    object->field_18 = sizeof(T);
    object->field_20 = alignof(T);
    return object;
}

// A reference to a new T.
template <class T>
void Unk_Make(Unk_239a418_Ref<Unk_24284d0>* out, Unk_239a418_Allocator* allocator) {
    ::new (out) Unk_239a418_Ref<Unk_24284d0>(Unk_Create<T>(allocator));
}

// Takes over the other's reference, letting go of its own first.
template <class T>
void Unk_Assign(Unk_239a418_Ref<T>& to, Unk_239a418_Ref<T>&& from) {
    if (to.m_ptr) {
        static_cast<Unk_239a458*>(to.m_ptr)->vf5();
        to.m_ptr = nullptr;
    }
    to.m_ptr = from.Release();
}

// What two callables of the classes run (0x7101280790, 0x7101282400): gives
// the owner's object an empty callable under `hash`, with the object locked,
// and makes the next object (a T) the one `self` hands out.
template <class T, class Self>
void Unk_Next(Self* self, u64 hash) {
    Unk_1127d00_Owner* owner = self->Unk_126aca0()->field_60;
    owner->field_60.Lock();
    {
        Unk_1260810_Callable callable;
        owner->Unk_1127d00(hash, callable, false);
    }
    owner->field_60.Unlock();
    Unk_Assign(self->field_70, Unk_239a418_Ref<Unk_239a418>(Unk_Create<T>(self->field_8)));
}

}  // namespace
