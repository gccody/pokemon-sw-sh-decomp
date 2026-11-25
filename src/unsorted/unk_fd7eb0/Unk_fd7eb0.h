#pragma once
// The object built at 0x7100fd7eb0 (vtable 0x7102404b68, class Unk_2404b58 in
// src/unsorted/types/Unk_fd8890.cpp) and what it points at. Placeholder names:
// rename once the classes are known. Its functions here are written as free
// functions on a mirror of its fields until its base (0x7100e7c210) is known.
#include <new>
#include <type_traits>
#include <vector>

#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_2771620.h"

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
        if (other.m_engaged)
            Construct(other.m_value);
    }
    ~Unk_fd7eb0_Optional() { Reset(); }

    Unk_fd7eb0_Optional& operator=(const Unk_fd7eb0_Optional& other) {
        if (m_engaged) {
            if (other.m_engaged)
                m_value = other.m_value;
            else
                Reset();
        } else if (other.m_engaged) {
            Construct(other.m_value);
        }
        return *this;
    }

    void Construct(const T& value) {
        ::new (&m_value) T(value);
        m_engaged = true;
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

// An entry of what the object's +0x68 holds at +0xf00: three references.
struct Unk_fd7eb0_Entry {
    Unk_fd7eb0_Entry(const Unk_fd7eb0_Entry& other) = default;
    Unk_fd7eb0_Entry& operator=(const Unk_fd7eb0_Entry& other) {
        Unk_fd7eb0_Assign(field_0, other.field_0);
        Unk_fd7eb0_Assign(field_8, other.field_8);
        Unk_fd7eb0_Assign(field_10, other.field_10);
        return *this;
    }

    Unk_fd7eb0_Ref field_0;
    Unk_fd7eb0_Ref field_8;
    Unk_fd7eb0_Ref field_10;
};
PKMN_SIZE_ASSERT(Unk_fd7eb0_Entry, 0x18);

// The allocator of the entries: Unk_2771620_Allocator's, but a copy keeps only
// the allocator (0x7100fc2480 zeroes the rest) and an assignment takes the
// other's allocator (0x7100f3c740 frees its memory first when they differ).
template <class T>
class Unk_fd7eb0_Allocator : public Unk_2771620_Allocator<T> {
public:
    using propagate_on_container_copy_assignment = std::true_type;

    Unk_fd7eb0_Allocator(const Unk_fd7eb0_Allocator& other)
        : Unk_2771620_Allocator<T>(other.field_0) {}
    Unk_fd7eb0_Allocator& operator=(const Unk_fd7eb0_Allocator& other) {
        this->field_0 = other.field_0;
        return *this;
    }
};

// The entries. Their copy (0x7100fc2480) and their assignment (0x7100f3c740)
// are called, in two other TUs, where its destruction is inlined.
struct Unk_fd7eb0_Entries {
    Unk_fd7eb0_Entries(const Unk_fd7eb0_Entries& other);
    Unk_fd7eb0_Entries& operator=(const Unk_fd7eb0_Entries& other);

    std::vector<Unk_fd7eb0_Entry, Unk_fd7eb0_Allocator<Unk_fd7eb0_Entry>> field_0;
};
PKMN_SIZE_ASSERT(Unk_fd7eb0_Entries, 0x30);

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
    Unk_fd7eb0_Optional<Unk_fd7eb0_Entries> field_ef8;
    Unk_fd7eb0_Optional<Unk_fd7eb0_Range> field_f30;
};
PKMN_OFFSET_ASSERT(Unk_fd7eb0_68, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_fd7eb0_68, field_8c, 0x8c);
PKMN_OFFSET_ASSERT(Unk_fd7eb0_68, field_d80, 0xd80);
PKMN_OFFSET_ASSERT(Unk_fd7eb0_68, field_ee8, 0xee8);
PKMN_OFFSET_ASSERT(Unk_fd7eb0_68, field_ef0, 0xef0);
PKMN_OFFSET_ASSERT(Unk_fd7eb0_68, field_ef8, 0xef8);
PKMN_OFFSET_ASSERT(Unk_fd7eb0_68, field_f30, 0xf30);

// What is told when the object's +0x60 changes.
class Unk_fd7eb0_Listener {
public:
    virtual void vf0();
    virtual void vf1();
};

// A pointer that is only used while its handle's count isn't zero.
struct Unk_fd7eb0_Weak {
    Unk_fd7eb0_Listener* Get() const {
        if (field_0 != nullptr && field_0->field_54.load() != 0)
            return field_8;
        return nullptr;
    }

    Unk_239a418_Handle* field_0;
    Unk_fd7eb0_Listener* field_8;
};

// An entry of what the object's +0x60 holds at +0xb8.
struct Unk_fd7eb0_Slot {
    u16 field_0[13];
    u8 field_1a;
    u8 field_1b;
    u32 field_1c;
    u32 field_20;
};
PKMN_SIZE_ASSERT(Unk_fd7eb0_Slot, 0x24);

// What the object holds at +0x60.
struct Unk_fd7eb0_60 {
    u8 _0[0x54];
    u8 field_54;
    u8 _55[0xb8 - 0x55];
    Unk_fd7eb0_Slot field_b8[4];
    u8 _148[0x168 - 0x148];
    u16 field_168[11];
    u8 _17e[0x184 - 0x17e];
    u32 field_184;
    u8 _188[0x198 - 0x188];
    Unk_fd7eb0_Weak field_198;
};
PKMN_OFFSET_ASSERT(Unk_fd7eb0_60, field_54, 0x54);
PKMN_OFFSET_ASSERT(Unk_fd7eb0_60, field_b8, 0xb8);
PKMN_OFFSET_ASSERT(Unk_fd7eb0_60, field_168, 0x168);
PKMN_OFFSET_ASSERT(Unk_fd7eb0_60, field_184, 0x184);
PKMN_OFFSET_ASSERT(Unk_fd7eb0_60, field_198, 0x198);

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
