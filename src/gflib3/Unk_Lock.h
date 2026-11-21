#pragma once
// The lock of a weak reference's handle as a type: a reference to the
// handle's object if it still has references and is a T (or derived from
// T), else none. One template, an instance per T (0x710000e840 is
// Unk_239a360's); tools/lockgen.py writes them (src/unsorted/locks).
// Placeholder names: rename once the classes are known.
//
// The handle (src/gflib3/Unk_239a418.h) keeps the count at +0x54, the
// object's type at +0x58 and the object, as its +0x50 interface, at +0x60.
// The count is read without ordering and raised with a weak compare and
// exchange, as long as it isn't zero; the type is tested again on every try.
// The spelling matters to the register allocator alone: with `while (count
// != 0)` and a `break`, or with the type test written out in the loop, the
// same instructions come out with four registers permuted.
#include "gflib3/Unk_239a418.h"

// Whether a type is T's or one derived from it.
template <class T>
inline bool Unk_IsKind(const Unk_239a418_Type* type) {
    const Unk_239a418_Type* kind = T::Unk_GetType();
    for (; type != nullptr; type = type->field_0)
        if (type == kind)
            return true;
    return false;
}

template <class T>
Unk_239a418_Ref<T> Unk_Lock(Unk_239a418_Handle* handle) {
    s32 count = handle->field_54.load(std::memory_order_relaxed);
    if (count == 0)
        return Unk_239a418_Ref<T>();
    do {
        if (!Unk_IsKind<T>(static_cast<const Unk_239a418_Type*>(handle->field_58)))
            return Unk_239a418_Ref<T>();
        if (handle->field_54.compare_exchange_weak(count, count + 1, std::memory_order_relaxed)) {
            // the count is the reference: the object is taken as it is
            Unk_239a418_Ref<T> result;
            result.m_ptr = static_cast<T*>(reinterpret_cast<Unk_239a498*>(handle->field_60));
            return result;
        }
    } while (count != 0);
    return Unk_239a418_Ref<T>();
}
