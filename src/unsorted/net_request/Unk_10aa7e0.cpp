// Scope: common
// A request step class (vtable 0x7102411720) and the one derived from it
// (vtable 0x71024116b0): a weak reference to the step's target, a handle to
// lock, and a callable to fall back on. Its simple getters are in
// src/unsorted/virtual/Unk_10aa8f0.cpp. Placeholder types: rename and move
// once the classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

class Unk_24004b0 : public Unk_239a418 {};

// src/gflib3/Unk_Lock.h, instantiated in src/unsorted/locks/Unk_10aaaa0.cpp
template <class T>
Unk_239a418_Ref<T> Unk_Lock(Unk_239a418_Handle* handle);

bool Unk_11009d0(Unk_24004b0* object);

// What the steps call: slot 0.
class Unk_10aa7e0_Callable {
public:
    virtual void vf0();
};

class Unk_2411720 {
public:
    virtual ~Unk_2411720();
    virtual bool vf2() = 0;
    virtual u32 vf3() = 0;
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(u64 value);
    virtual u64 vf7();
    virtual u8 vf8();
    virtual void vf9(u32 value);
    virtual u32 vf10();
    virtual Unk_10aa7e0_Callable* vf11();

    u64 field_8;
    u8 field_10;
    u8 _11[0x3];
    u32 field_14;
    // A weak reference: the handle and its object.
    Unk_239a418_Ref<Unk_239a418_Handle> field_18;
    Unk_10aa7e0_Callable* field_20;
    Unk_239a418_Ref<Unk_239a418_Handle> field_28;
};
PKMN_OFFSET_ASSERT(Unk_2411720, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_2411720, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_2411720, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_2411720, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_2411720, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_2411720, field_28, 0x28);
static_assert(sizeof(Unk_2411720) == 0x30, "Unk_2411720");

class Unk_24116b0 final : public Unk_2411720 {
public:
    ~Unk_24116b0() override;
    bool vf2() override;
    u32 vf3() override;
    Unk_10aa7e0_Callable* vf11() override;

    Unk_10aa7e0_Callable field_30;
};
PKMN_OFFSET_ASSERT(Unk_24116b0, field_30, 0x30);

// 0x71010aa900 (and Unk_24116b0's)
Unk_2411720::~Unk_2411720() = default;

// 0x71010aa960
Unk_24116b0::~Unk_24116b0() = default;

// 0x71010aa9c0
void Unk_2411720::vf4() {
    if (field_18.m_ptr != nullptr) {
        static_cast<Unk_239a458*>(field_18.m_ptr)->vf5();
        field_18.m_ptr = nullptr;
    }
    field_18.m_ptr = nullptr;
    field_20 = nullptr;
}

// 0x71010aaa70
Unk_10aa7e0_Callable* Unk_2411720::vf11() {
    Unk_239a418_Handle* handle = field_18.m_ptr;
    if (handle != nullptr && handle->field_54.load() != 0)
        return field_20;
    return nullptr;
}

// 0x71010aa8b0
Unk_10aa7e0_Callable* Unk_24116b0::vf11() {
    Unk_10aa7e0_Callable* target = Unk_2411720::vf11();
    return target != nullptr ? target : &field_30;
}

// 0x71010aa7e0
bool Unk_24116b0::vf2() {
    Unk_10aa7e0_Callable* target = vf11();
    bool done;
    {
        Unk_239a418_Ref<Unk_24004b0> object = field_28.m_ptr != nullptr
                                                  ? Unk_Lock<Unk_24004b0>(field_28.m_ptr)
                                                  : Unk_239a418_Ref<Unk_24004b0>();
        done = Unk_11009d0(object.m_ptr);
    }
    if (!done)
        return false;
    target->vf0();
    return true;
}
