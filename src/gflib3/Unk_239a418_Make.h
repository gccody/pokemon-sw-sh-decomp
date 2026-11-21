#pragma once
// How the camp's TUs make an object on gflib3's reference-counted object and
// hand a reference on (src/unsorted/Unk_127dd90.cpp and the files after it).
// In an anonymous namespace: these are local to their TU in the original
// (called where there are several callers, inlined where there's one).
#include <new>
#include <utility>

#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_2771620.h"

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

// Takes over the other's reference, letting go of its own first.
template <class T>
void Unk_Assign(Unk_239a418_Ref<T>& to, Unk_239a418_Ref<T>&& from) {
    if (to.m_ptr) {
        static_cast<Unk_239a458*>(to.m_ptr)->vf5();
        to.m_ptr = nullptr;
    }
    to.m_ptr = from.Release();
}

}  // namespace
