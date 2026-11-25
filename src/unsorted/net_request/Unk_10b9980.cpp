// Scope: common
// A request step base (vtable 0x7102412a28) and the step derived from it
// (vtable 0x71024129b8): a weak reference to the step's target, and a
// callable the derived step holds to fall back on. The base's simple
// accessors are in src/unsorted/virtual/Unk_10b9af0.cpp. Placeholder types:
// rename and move once the classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// src/unsorted/leaf/Unk_1049aa0.cpp: they tail-call tests, flags.
bool Unk_1049b00_call(u64 object);
bool Unk_1049b20_call(u64 object);
void Unk_1049ac0_call(void* object, u64 value);

extern void* Unk_27d92e8;

// A value that may be missing: the flag comes first, the value after it (as
// src/unsorted/unk_fd7eb0/Unk_fd7eb0.h's).
template <class T>
class Unk_10b9980_Optional {
public:
    Unk_10b9980_Optional() : m_engaged(false) {}
    ~Unk_10b9980_Optional() { Reset(); }

    void Reset() {
        if (m_engaged) {
            m_value.~T();
            m_engaged = false;
        }
    }

    bool m_engaged;
    union {
        T m_value;
    };
};

// What the step calls: slots 0 to 2.
class Unk_10b9980_Callable {
public:
    virtual void vf0();
    virtual void vf1(Unk_10b9980_Optional<u32>& result);
    virtual void vf2();
};

class Unk_2412a18 {
public:
    virtual ~Unk_2412a18();
    virtual bool vf2() = 0;
    virtual u32 vf3() = 0;
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(u64 value);
    virtual u64 vf7();
    virtual u8 vf8();
    virtual void vf9(u32 value);
    virtual u32 vf10();
    virtual Unk_10b9980_Callable* vf11();

    u64 field_8;
    u8 field_10;
    u8 _11[0x3];
    u32 field_14;
    // A weak reference: the handle and its object.
    Unk_239a418_Ref<Unk_239a418_Handle> field_18;
    Unk_10b9980_Callable* field_20;
};
PKMN_OFFSET_ASSERT(Unk_2412a18, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_2412a18, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_2412a18, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_2412a18, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_2412a18, field_20, 0x20);
static_assert(sizeof(Unk_2412a18) == 0x28, "Unk_2412a18");

class Unk_24129a8 final : public Unk_2412a18 {
public:
    ~Unk_24129a8() override;
    bool vf2() override;
    u32 vf3() override;
    Unk_10b9980_Callable* vf11() override;

    u32 field_28;
    Unk_10b9980_Callable field_30;
};
PKMN_OFFSET_ASSERT(Unk_24129a8, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_24129a8, field_30, 0x30);
static_assert(sizeof(Unk_24129a8) == 0x38, "Unk_24129a8");

// 0x71010b9c70 (and Unk_24129a8's); its D0, 0x71010b9cc0, traps: the class
// is abstract
Unk_2412a18::~Unk_2412a18() = default;

// 0x71010b9bf0
void Unk_2412a18::vf4() {
    if (field_18.m_ptr != nullptr) {
        static_cast<Unk_239a458*>(field_18.m_ptr)->vf5();
        field_18.m_ptr = nullptr;
    }
    field_18.m_ptr = nullptr;
    field_20 = nullptr;
}

// 0x71010b9cd0
Unk_10b9980_Callable* Unk_2412a18::vf11() {
    Unk_239a418_Handle* handle = field_18.m_ptr;
    if (handle != nullptr && handle->field_54.load() != 0)
        return field_20;
    return nullptr;
}

// 0x71010b9ba0
Unk_24129a8::~Unk_24129a8() = default;

// 0x71010b9ab0
Unk_10b9980_Callable* Unk_24129a8::vf11() {
    Unk_10b9980_Callable* target = Unk_2412a18::vf11();
    return target != nullptr ? target : &field_30;
}

// 0x71010b9980
bool Unk_24129a8::vf2() {
    Unk_10b9980_Callable* target = vf11();
    switch (field_14) {
        case 0:
            if (Unk_1049b20_call(reinterpret_cast<u64>(Unk_27d92e8))) {
                // read before the object: the original loads the field first
                // (passed straight in, the object's load is shared with the
                // other branch's and hoisted above the test)
                u32 value = field_28;
                Unk_1049ac0_call(Unk_27d92e8, value);
            } else if (Unk_1049b00_call(reinterpret_cast<u64>(Unk_27d92e8))) {
                target->vf0();
                return true;
            }
            field_14 = 1;
            return false;
        case 1:
            if (Unk_1049b00_call(reinterpret_cast<u64>(Unk_27d92e8))) {
                target->vf0();
                return true;
            }
            if (Unk_1049b20_call(reinterpret_cast<u64>(Unk_27d92e8))) {
                Unk_10b9980_Optional<u32> result;
                target->vf1(result);
                return true;
            }
            return false;
        default:
            return false;
    }
}

// 0x71010b9b10
u32 Unk_24129a8::vf3() {
    Unk_10b9980_Callable* target = vf11();
    if (Unk_1049b20_call(reinterpret_cast<u64>(Unk_27d92e8)) ||
        Unk_1049b00_call(reinterpret_cast<u64>(Unk_27d92e8))) {
        target->vf2();
        return 1;
    }
    return 0;
}
