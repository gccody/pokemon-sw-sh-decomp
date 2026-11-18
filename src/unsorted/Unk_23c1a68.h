#pragma once
// A class on gflib3's reference-counted object (vtable 0x71023c1a68), 0x188
// bytes. Unk_23dc940 (src/unsorted/Unk_23dc940.h) is on it, and the
// destructors of a few other classes call its destructor too. Placeholder
// names: rename once the classes are known.
#include <vector>

#include "gflib3/Unk_239a418.h"
#include "gflib3/Unk_5cf870.h"

// A container allocator, 0x18 bytes: what frees through
// Unk_239a418_Allocator::vf3 (the memory, its size and its alignment), and two
// fields its constructors zero.
template <class T>
class Unk_23c1a68_Allocator {
public:
    using value_type = T;

    T* allocate(size_t n);
    void deallocate(T* p, size_t n) {
        field_0->vf3(reinterpret_cast<u64>(p), n * sizeof(T), alignof(T));
    }

    Unk_239a418_Allocator* field_0;
    u64 field_8;
    u32 field_10;
};

// An object that is destroyed and freed (vf3) when its pointer goes.
template <class T>
class Unk_23c1a68_Owner {
public:
    ~Unk_23c1a68_Owner() {
        if (m_ptr) {
            m_ptr->vf3();
            m_ptr = nullptr;
        }
    }

    T* m_ptr;
};

// A light event, finalized when it goes.
class Unk_23c1a68_Event {
public:
    ~Unk_23c1a68_Event() { Unk_5cf8d0(&m_event); }

    nn::os::LightEventType m_event;
};
static_assert(sizeof(Unk_23c1a68_Event) == 0xc, "Unk_23c1a68_Event");

// The class whose type getter (0x7100967240, its type 0x71027771d8) is the
// parent of Unk_23c1a68's: two below the object (its type's parent is
// Unk_27771e8's, Unk_239c050's). Only its getter is known; it stays out of line.
struct Unk_27771d8 {
    static const Unk_239a418_Type* Unk_GetType();
};

// Its constructor (0x71005d8ee0) stores two more vtables between the object's
// and its own: those of the classes in between (their types are Unk_27771e8 and
// Unk_27771d8), whose fields are the ones before +0xe0. They destroy nothing,
// so it's declared on the object here. Its destructor releases its
// references, destroys the vectors and the events, then runs the object's
// destructor, inlined.
class Unk_23c1a68 : public Unk_239a418 {
public:
    // Its type (0x71027771c8), inlined into the types of the classes on it.
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27771d8::Unk_GetType());
        return &type;
    }

    ~Unk_23c1a68() override;
    const Unk_239a418_Type* vf_type() override;

    u64 field_60;
    u64 field_68;
    u64 field_70;
    u64 field_78;
    u64 field_80;
    u64 field_88;
    u64 field_90;
    u64 field_98;
    u64 field_a0;
    u64 field_a8;
    u64 field_b0;
    u64 field_b8;
    u8 field_c0;
    u64 field_c8;
    u64 field_d0;
    u64 field_d8;
    u32 field_e0;
    Unk_23c1a68_Event field_e4;
    u64 field_f0;
    u32 field_f8;
    Unk_23c1a68_Event field_fc;
    u64 field_108;
    std::vector<Unk_23c1a68_Owner<Unk_239a418>,
                Unk_23c1a68_Allocator<Unk_23c1a68_Owner<Unk_239a418>>>
        field_110;
    std::vector<Unk_23c1a68_Owner<Unk_239a418>,
                Unk_23c1a68_Allocator<Unk_23c1a68_Owner<Unk_239a418>>>
        field_140;
    Unk_239a418_Ref<Unk_239a418> field_170;
    Unk_239a418_Ref<Unk_239a418> field_178;
    u16 field_180;
};
static_assert(sizeof(Unk_23c1a68) == 0x188, "Unk_23c1a68");
static_assert(__builtin_offsetof(Unk_23c1a68, field_b0) == 0xb0, "Unk_23c1a68::field_b0");
static_assert(__builtin_offsetof(Unk_23c1a68, field_e4) == 0xe4, "Unk_23c1a68::field_e4");
static_assert(__builtin_offsetof(Unk_23c1a68, field_fc) == 0xfc, "Unk_23c1a68::field_fc");
static_assert(__builtin_offsetof(Unk_23c1a68, field_110) == 0x110, "Unk_23c1a68::field_110");
static_assert(__builtin_offsetof(Unk_23c1a68, field_140) == 0x140, "Unk_23c1a68::field_140");
static_assert(__builtin_offsetof(Unk_23c1a68, field_170) == 0x170, "Unk_23c1a68::field_170");
