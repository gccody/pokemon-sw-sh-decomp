// Scope: common
// A request step base (vtable 0x71024180a0): a value at +0x8 and a weak
// reference at +0x10 to a Unk_2417c28 (the lock is in
// src/unsorted/locks/Unk_10ff5b0.cpp). Its vf3 is in
// src/unsorted/virtual/Unk_10ff4a0.cpp. Placeholder types: rename and move
// once the classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

class Unk_2417c28 : public Unk_239a418 {};

// src/gflib3/Unk_Lock.h, instantiated in src/unsorted/locks/Unk_10ff5b0.cpp
template <class T>
Unk_239a418_Ref<T> Unk_Lock(Unk_239a418_Handle* handle);

struct Unk_10ff4b0_Arg;

class Unk_2418090 {
public:
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

// A result code: success when it isn't negative. It tests as a pointer to
// an empty member function (0x71006a5220), the safe bool idiom: the original
// selects that function's address, then tests it.
struct Unk_10ff4b0_Result {
    typedef void (Unk_10ff4b0_Result::*SafeBool)() const;
    void Unk_6a5220() const;
    operator SafeBool() const { return field_0 >= 0 ? &Unk_10ff4b0_Result::Unk_6a5220 : nullptr; }

    s32 field_0;
};

struct Unk_10ff4b0_Arg {
    u8 _0[0x14];
    s32 field_14;
    u8 _18[0x40];
    Unk_10ff4b0_Result field_58;
};
PKMN_OFFSET_ASSERT(Unk_10ff4b0_Arg, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_10ff4b0_Arg, field_58, 0x58);

// 0x71010ff440
void Unk_2418090::vf2(u64 value, const Unk_239a418_Ref<Unk_239a418>& object) {
    field_8 = value;
    if (object.m_ptr != nullptr) {
        Unk_239a418_Ref<Unk_239a418_Handle> handle = object.m_ptr->vf2();
        if (field_10.m_ptr != nullptr) {
            static_cast<Unk_239a458*>(field_10.m_ptr)->vf5();
            field_10.m_ptr = nullptr;
        }
        field_10.m_ptr = handle.Release();
    }
}

// 0x71010ff4b0
void Unk_2418090::Unk_10ff4b0(const Unk_10ff4b0_Arg* arg) {
    if (arg->field_14 != 4) {
        if (arg->field_58)
            vf4(true);
    }
    vf3();
}

// 0x71010ff530
Unk_239a418_Ref<Unk_2417c28> Unk_2418090::Unk_10ff530() const {
    if (field_10.m_ptr != nullptr)
        return Unk_Lock<Unk_2417c28>(field_10.m_ptr);
    return Unk_239a418_Ref<Unk_2417c28>();
}

// 0x71010ff550, and its D0 at 0x71010ff5a0
Unk_2418090::~Unk_2418090() = default;
