#pragma once
// The object built at 0x7100fd7eb0 (vtable 0x7102404b68, class Unk_2404b58 in
// src/unsorted/types/Unk_fd8890.cpp) and what it points at. Placeholder names:
// rename once the classes are known. Its functions here are written as free
// functions on a mirror of its fields until its base (0x7100e7c210) is known.
#include <new>

#include <types.h>

#include "gflib3/Unk_239a418.h"

using Unk_fd7eb0_Ref = Unk_239a418_Ref<Unk_239a418>;

// Copies a reference: the new one is added before the old one is dropped.
inline void Unk_fd7eb0_Assign(Unk_fd7eb0_Ref& to, const Unk_fd7eb0_Ref& from) {
    Unk_239a418* p = from.m_ptr;
    if (p)
        static_cast<Unk_239a458*>(p)->vf4();
    Unk_239a418* old = to.m_ptr;
    to.m_ptr = p;
    if (old)
        static_cast<Unk_239a458*>(old)->vf5();
}

// A value that may be missing: the flag comes first, the value after it.
template <class T>
class Unk_fd7eb0_Optional {
public:
    Unk_fd7eb0_Optional() : m_engaged(false) {}
    Unk_fd7eb0_Optional(const Unk_fd7eb0_Optional& other) : m_engaged(false) {
        if (other.m_engaged) {
            ::new (&m_value) T(other.m_value);
            m_engaged = true;
        }
    }
    ~Unk_fd7eb0_Optional() { Reset(); }

    Unk_fd7eb0_Optional& operator=(const Unk_fd7eb0_Optional& other) {
        if (m_engaged) {
            if (other.m_engaged)
                m_value = other.m_value;
            else
                Reset();
        } else if (other.m_engaged) {
            ::new (&m_value) T(other.m_value);
            m_engaged = true;
        }
        return *this;
    }

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

// What the object holds at +0x80.
struct Unk_fd7eb0_Info {
    struct Code {
        u8 field_0;
        u8 field_1;
        u8 field_2;
    };

    u64 field_0;
    u8 field_8;
    s32 field_c;
    Unk_fd7eb0_Optional<Code> field_10;
};
PKMN_SIZE_ASSERT(Unk_fd7eb0_Info, 0x18);
PKMN_OFFSET_ASSERT(Unk_fd7eb0_Info, field_10, 0x10);

// What the object's +0x68 holds at +0x68.
struct Unk_fd7eb0_Setup {
    Unk_fd7eb0_Setup(const Unk_fd7eb0_Setup& other)
        : field_0(other.field_0),
          field_8(other.field_8),
          field_10(other.field_10),
          field_18(other.field_18) {}
    Unk_fd7eb0_Setup& operator=(const Unk_fd7eb0_Setup& other) {
        field_0 = other.field_0;
        field_8 = other.field_8;
        field_10 = other.field_10;
        Unk_fd7eb0_Assign(field_18, other.field_18);
        return *this;
    }

    u64 field_0;
    u64 field_8;
    u64 field_10;
    Unk_fd7eb0_Ref field_18;
};
PKMN_SIZE_ASSERT(Unk_fd7eb0_Setup, 0x20);

// What the object's +0x68 holds at +0xf30.
struct Unk_fd7eb0_Range {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};

// What the object's +0x68 holds at +0xd80.
struct Unk_fd7eb0_d80 {
    u8 _0[0x58];
    Unk_fd7eb0_Ref field_58;
};
PKMN_OFFSET_ASSERT(Unk_fd7eb0_d80, field_58, 0x58);

// What the object's +0x68 holds at +0xef0: slot 2 gives a reference.
class Unk_fd7eb0_ef0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual Unk_fd7eb0_Ref vf2();
};

// What the object holds at +0x68.
struct Unk_fd7eb0_68 {
    u8 _0[0x68];
    Unk_fd7eb0_Setup field_68;
    u8 _88[0x4];
    u8 field_8c;
    u8 _8d[0xd80 - 0x8d];
    Unk_fd7eb0_d80* field_d80;
    u8 _d88[0xee8 - 0xd88];
    Unk_fd7eb0_Ref field_ee8;
    Unk_fd7eb0_ef0* field_ef0;
    u8 _ef8[0xf30 - 0xef8];
    Unk_fd7eb0_Optional<Unk_fd7eb0_Range> field_f30;
};
PKMN_OFFSET_ASSERT(Unk_fd7eb0_68, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_fd7eb0_68, field_8c, 0x8c);
PKMN_OFFSET_ASSERT(Unk_fd7eb0_68, field_d80, 0xd80);
PKMN_OFFSET_ASSERT(Unk_fd7eb0_68, field_ee8, 0xee8);
PKMN_OFFSET_ASSERT(Unk_fd7eb0_68, field_ef0, 0xef0);
PKMN_OFFSET_ASSERT(Unk_fd7eb0_68, field_f30, 0xf30);

// What the object holds at +0x60.
struct Unk_fd7eb0_60 {
    u8 _0[0x54];
    u8 field_54;
};
PKMN_OFFSET_ASSERT(Unk_fd7eb0_60, field_54, 0x54);

// The object.
struct Unk_fd7eb0 {
    u8 _0[0x60];
    Unk_fd7eb0_60* field_60;
    Unk_fd7eb0_68* field_68;
    Unk_fd7eb0_Ref field_70;
    u64 field_78;
    Unk_fd7eb0_Info field_80;
};
PKMN_OFFSET_ASSERT(Unk_fd7eb0, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_fd7eb0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_fd7eb0, field_80, 0x80);
