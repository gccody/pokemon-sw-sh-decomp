#pragma once
// The fields of Unk_241c218 (vtable 0x710241c228, constructor 0x71011716f0)
// that its non-virtual functions use. The class is declared by tools/typegen.py
// (src/unsorted/types/Unk_116fb50.cpp) on gflib3's object alone, without its
// base (the 0x7102419560 group) and members, so its functions are written as
// free functions over this struct. Placeholder names: rename once the classes
// are known.
//
// It keeps three weak references (handles, src/gflib3/Unk_239a418.h) to an
// Unk_241c3c0: +0x88 is the one in use, +0x90 and +0x98 two others, the +0x98
// one preferred while its object is alive. +0x68 is a weak reference to what
// owns it, locked as an Unk_27771c8.
#include <arm_neon.h>
#include <utility>

#include <types.h>

#include "gflib3/Unk_239a418.h"

// Its getter is out of line (0x7100967240).
struct Unk_27771d8 {
    static const Unk_239a418_Type* Unk_GetType();
};

// What the owner's weak reference is locked as (the type 0x71027771c8).
class Unk_27771c8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27771d8::Unk_GetType());
        return &type;
    }

    ~Unk_27771c8() override;
    const Unk_239a418_Type* vf_type() override;
};

// What the weak references at +0x88, +0x90 and +0x98 lock to (vtable
// 0x710241c3d0).
class Unk_241c3c0 : public Unk_239a418 {
public:
    ~Unk_241c3c0() override;
    const Unk_239a418_Type* vf_type() override;
};

// Locks a weak reference as an Unk_241c3c0: none if it has no handle or its
// object is gone.
Unk_239a418_Ref<Unk_241c3c0> Unk_11719d0(const Unk_239a418_Ref<Unk_239a418_Handle>& handle);

// Whether a weak reference's object is still alive: it has a handle whose
// count isn't zero.
inline bool Unk_241c218_IsAlive(const Unk_239a418_Ref<Unk_239a418_Handle>& handle) {
    return handle.m_ptr != nullptr && handle.m_ptr->field_54.load() != 0;
}

// Takes another reference's object: the new one is added and stored before the
// old one is dropped.
template <class T>
void Unk_241c218_Assign(Unk_239a418_Ref<T>& ref, const Unk_239a418_Ref<T>& other) {
    Unk_239a418_Ref<T> copy(other);
    std::swap(ref.m_ptr, copy.m_ptr);
}

// A reference whose add and drop are inline, as Unk_239a418's (src/gflib3/
// Unk_5e2700.cpp): the handle's count is changed here, and the object is
// destroyed (its slot 3) when the count reaches zero.
class Unk_241c218_Ref {
public:
    static void Add(Unk_239a418* object) {
        Unk_239a418_Handle* handle = object->m_handle.m_ptr;
        if (handle->field_58 == nullptr)
            handle->field_58 = handle->field_60->vf0();
        ++handle->field_54;
    }
    static void Drop(Unk_239a418* object) {
        Unk_239a418_Handle* handle = object->m_handle.m_ptr;
        if (--handle->field_54 == 0) {
            handle->field_60 = nullptr;
            object->vf3();
        }
    }

    Unk_241c218_Ref& operator=(const Unk_241c218_Ref& other) {
        Unk_239a418* object = other.m_ptr;
        if (object != nullptr)
            Add(object);
        Unk_239a418* old = m_ptr;
        m_ptr = object;
        if (old != nullptr)
            Drop(old);
        return *this;
    }

    void Reset() {
        Unk_239a418* old = m_ptr;
        m_ptr = nullptr;
        if (old != nullptr)
            Drop(old);
    }

    Unk_239a418* m_ptr;
};

// A callable, 0x80 bytes (the shape of Unk_23d4470_Callable, src/unsorted/
// Unk_23d4470.h, and Unk_eaa580_Func, src/unsorted/Unk_ece010.cpp): four
// functions, then the storage. Its manager (+0x8) disposes of the storage and
// +0x10 moves it into another callable's; a move takes the functions only when
// there's something to move.
class Unk_241c218_Callable {
public:
    struct Header {
        u64 field_0;
        void (*field_8)(void* storage);
        void (*field_10)(void* src, void* dst);
        u64 field_18;
    };

    Unk_241c218_Callable(Unk_241c218_Callable&& other) : header() { Take(other); }
    ~Unk_241c218_Callable() { Clear(); }

    Unk_241c218_Callable& operator=(Unk_241c218_Callable&& other) {
        Clear();
        Take(other);
        return *this;
    }

    void Clear() {
        if (void (*manager)(void*) = header.field_8) {
            header = {};
            manager(storage);
        }
    }
    void Take(Unk_241c218_Callable& other) {
        if (other.header.field_10 != nullptr) {
            other.header.field_10(other.storage, storage);
            header = other.header;
        }
    }

    Header header;
    alignas(16) u8 storage[0x60];
};
PKMN_OFFSET_ASSERT(Unk_241c218_Callable, storage, 0x20);
PKMN_SIZE_ASSERT(Unk_241c218_Callable, 0x80);

// 16 bytes the target's functions take (+0xb0, +0x1a0).
struct Unk_241c218_Pair {
    u64 field_0;
    u64 field_8;
};
PKMN_SIZE_ASSERT(Unk_241c218_Pair, 0x10);

// A vector of four floats, kept with 4-byte alignment.
struct Unk_241c218_Vec {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};
PKMN_SIZE_ASSERT(Unk_241c218_Vec, 0x10);

// The rotation (0, 0, 0, 1) and the scale (1, 1, 1, 0) a transform is reset to.
extern const Unk_241c218_Vec Unk_1f07bd0;
extern const Unk_241c218_Vec Unk_1f07af0;

struct Unk_241c218_Self {
    u8 _0[0x68];
    Unk_239a418_Ref<Unk_239a418_Handle> field_68;
    u8 _70[0x10];
    Unk_239a418_Ref<Unk_239a418> field_80;
    Unk_239a418_Ref<Unk_239a418_Handle> field_88;
    Unk_239a418_Ref<Unk_239a418_Handle> field_90;
    Unk_239a418_Ref<Unk_239a418_Handle> field_98;
    f32 field_a0;
    f32 field_a4;
    u8 _a8[0x8];
    // A request: the two words its setters take, a value, and what it's for
    // (a pointer or a reference).
    u64 field_b0;
    u64 field_b8;
    u32 field_c0;
    void* field_c8;
    Unk_241c218_Ref field_d0;
    u8 _d8[0x8];
    Unk_241c218_Vec field_e0;
    Unk_241c218_Vec field_f0;
    Unk_241c218_Vec field_100;
    Unk_241c218_Callable field_110;
    u8 field_190;
    u32 field_194;
    u8 field_198;
    Unk_241c218_Pair field_1a0;
};
PKMN_OFFSET_ASSERT(Unk_241c218_Self, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_241c218_Self, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_241c218_Self, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_241c218_Self, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_241c218_Self, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_241c218_Self, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_241c218_Self, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(Unk_241c218_Self, field_d0, 0xd0);
PKMN_OFFSET_ASSERT(Unk_241c218_Self, field_e0, 0xe0);
PKMN_OFFSET_ASSERT(Unk_241c218_Self, field_100, 0x100);
PKMN_OFFSET_ASSERT(Unk_241c218_Self, field_110, 0x110);
PKMN_OFFSET_ASSERT(Unk_241c218_Self, field_190, 0x190);
PKMN_OFFSET_ASSERT(Unk_241c218_Self, field_198, 0x198);
PKMN_OFFSET_ASSERT(Unk_241c218_Self, field_1a0, 0x1a0);
