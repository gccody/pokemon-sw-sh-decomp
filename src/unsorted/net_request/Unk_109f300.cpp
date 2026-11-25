// Scope: common
// The destructor of Unk_240ff08 (a step on gflib3's object, declared by
// src/gflib3/families/Unk_1085320.cpp), and an abstract base, Unk_24100d0,
// with the class on it, Unk_2410040 (src/unsorted/virtual/Unk_109ef80.cpp
// writes the accessors their vtables share, under Unk_2410040's name).
// Placeholder classes, named after their vtables.
#include <atomic>

#include <types.h>

#include "gflib3/Unk_239a418.h"

// Stands for the interface at +0x60: only its vptr's place matters here.
class Unk_109f300_Interface {
public:
    virtual void vf0();
};

// As src/gflib3/families/Unk_1085320.cpp declares it (vtable 0x710240ff08).
class Unk_240ff08 : public Unk_239a418, public Unk_109f300_Interface {
public:
    ~Unk_240ff08() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();

    u8 field_68 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_70;
};
static_assert(sizeof(Unk_240ff08) == 0x78, "Unk_240ff08");

// The key function: its D2 (0x710109f040) and its thunks at +0x48
// (0x710109f1c0, 0x710109f250) and +0x50 (0x710109f300, 0x710109f390) come
// from here; the D0 deletes nothing (the family's operator delete is empty).
Unk_240ff08::~Unk_240ff08() {}

// An object it doesn't keep alive: the handle it counts in, and the object.
// Null once the handle's count is down to zero.
template <class T>
struct Unk_109f300_Weak {
    T* Get() const {
        if (m_handle.m_ptr == nullptr)
            return nullptr;
        if (m_handle.m_ptr->field_54.load() == 0)
            return nullptr;
        return m_ptr;
    }

    Unk_239a418_Ref<Unk_239a418_Handle> m_handle;
    T* m_ptr;
};

// vtable 0x71024100d0 (abstract: slots 2 and 3 are pure).
class Unk_24100d0 {
public:
    virtual ~Unk_24100d0();
    virtual void vf2() = 0;
    virtual u32 vf3() = 0;
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(u64 value);
    virtual u64 vf7();
    virtual u8 vf8();
    virtual void vf9(u32 value);
    virtual u32 vf10();
    virtual void* vf11();

    u64 field_8;
    u8 field_10;
    u32 field_14;
    Unk_109f300_Weak<void> field_18;
    Unk_109f300_Weak<void> field_28;
};
PKMN_OFFSET_ASSERT(Unk_24100d0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_24100d0, field_28, 0x28);
static_assert(sizeof(Unk_24100d0) == 0x38, "Unk_24100d0");

// 0x710109f5d0 (its D0, 0x710109f630, traps: the class is abstract)
Unk_24100d0::~Unk_24100d0() {}

// 0x710109f540
void Unk_24100d0::vf4() {
    field_18.m_handle.~Unk_239a418_Ref();
    field_18.m_handle.m_ptr = nullptr;
    field_18.m_ptr = nullptr;
}

// 0x710109f640
void* Unk_24100d0::vf11() {
    return field_18.Get();
}

// vtable 0x7102410040.
class Unk_2410040 : public Unk_24100d0 {
public:
    ~Unk_2410040() override;
    void vf2() override;
    u32 vf3() override;
    void* vf11() override;

    Unk_109f300_Weak<void> field_38;
};
static_assert(sizeof(Unk_2410040) == 0x48, "Unk_2410040");

// 0x710109f420 (D0: 0x710109f4b0)
Unk_2410040::~Unk_2410040() {}
