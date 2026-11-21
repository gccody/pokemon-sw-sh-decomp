#pragma once
// What the TUs with classes on Unk_24284d0 (src/unsorted/Unk_24284d0.h) share:
// how they make one, and what some of their callables do. In an anonymous
// namespace: the functions that make a class are local to their TU (called
// where there are several callers, inlined where there's one).
#include "gflib3/Unk_239a418_Make.h"
#include "unsorted/Unk_1127d00.h"
#include "unsorted/Unk_24284d0.h"

// 0x710126ac90: field_68 of Unk_24284d0, out of line (written as a leaf).
struct Unk_126ac90;
u64 Unk_126ac90_getField68(const Unk_126ac90*);

namespace {

// A reference to a new T.
template <class T>
void Unk_Make(Unk_239a418_Ref<Unk_24284d0>* out, Unk_239a418_Allocator* allocator) {
    ::new (out) Unk_239a418_Ref<Unk_24284d0>(Unk_Create<T>(allocator));
}

// What two callables of the classes run (0x7101280790, 0x7101282400): gives
// the owner's object an empty callable under `hash`, with the object locked,
// and makes the next object (a T) the one `self` hands out.
template <class T, class Self>
void Unk_Next(Self* self, u64 hash) {
    self->Unk_126aca0()->field_60->Unk_Register(hash, false);
    Unk_Assign(self->field_70, Unk_239a418_Ref<Unk_239a418>(Unk_Create<T>(self->field_8)));
}

}  // namespace
