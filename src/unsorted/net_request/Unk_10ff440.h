#pragma once
// A request step base (vtable 0x71024180a0) and the object its steps act on
// (vtable 0x7102417c28): the step keeps a value at +0x8 and a weak reference
// to the object at +0x10, and its vf4 hands the object a flag (and what the
// derived step holds). The base is in Unk_10ff440.cpp, the derived steps in
// Unk_10ff800.cpp. Placeholder types: rename and move once the classes are
// known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

namespace nn {
namespace nex {
template <class T>
class qVector;
}  // namespace nex
}  // namespace nn

// What the derived steps hold (Unk_10ff800.cpp).
class Unk_2418138_Item;
class Unk_2418170_Item;
class Unk_24181e0_Item;

// What the steps call: slots 7 and 9 to 12, after Unk_239a418's.
class Unk_2417c28 : public Unk_239a418 {
public:
    virtual void vf6();
    virtual void vf7(bool value, bool arg1, bool arg2);
    virtual void vf8();
    virtual void vf9(bool value, const nn::nex::qVector<Unk_2418138_Item>& items);
    virtual void vf10(bool value, const nn::nex::qVector<Unk_2418170_Item>& items);
    virtual void vf11(bool value);
    virtual void vf12(bool value, const nn::nex::qVector<Unk_24181e0_Item>& items);
};

// src/gflib3/Unk_Lock.h, instantiated in src/unsorted/locks/Unk_10ff5b0.cpp
template <class T>
Unk_239a418_Ref<T> Unk_Lock(Unk_239a418_Handle* handle);

struct Unk_10ff4b0_Arg;

class Unk_2418090 {
public:
    Unk_2418090() : field_8(0) {}
    virtual ~Unk_2418090();
    virtual void vf2(u64 value, const Unk_239a418_Ref<Unk_239a418>& object);
    virtual void vf3();
    virtual void vf4(bool value) = 0;

    void Unk_10ff4b0(const Unk_10ff4b0_Arg* arg);
    Unk_239a418_Ref<Unk_2417c28> Unk_10ff530() const;

    u64 field_8;
    // A weak reference: the handle of the object.
    Unk_239a418_Ref<Unk_239a418_Handle> field_10;
};
PKMN_OFFSET_ASSERT(Unk_2418090, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_2418090, field_10, 0x10);
static_assert(sizeof(Unk_2418090) == 0x18, "Unk_2418090");
