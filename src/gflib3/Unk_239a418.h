#pragma once
// gflib3's reference-counted object (vtable 0x710239a418): 3,006 functions
// reference its vtable, the constructors of the classes built on it. Its
// count lives in a handle object it holds at +0x58. Placeholder names:
// rename once the classes are known.
//
// Its primary base and the interface at +0x48 declare the same functions
// (get the handle, add a reference, drop one), so one override fills both
// vtables: the +0x48 vtable gets this-adjusting thunks with the body inlined.
// Both interfaces return the same type descriptor themselves (inline, so
// their copies are emitted with the object's vtables).
// Its D0 deletes nothing: the family's operator delete is empty, an object
// is freed by vf3 (destroy, then hand the memory back to its allocator).
#include <atomic>

#include <types.h>

class Unk_239a418_Handle;

// A reference: adds one when copied (slot 2 of the +0x48 vtable), drops it
// when it goes (slot 3). The copy tests the other reference's pointer, not
// its own copy: the battle sequence functions (src/battle/battle_scene) show
// it, where a null reference is used unchecked and the pointer it was loaded
// as stays in a register instead of folding to zero.
template <class T>
class Unk_239a418_Ref {
public:
    Unk_239a418_Ref() : m_ptr(nullptr) {}
    // Holds `ptr`, adding a reference.
    explicit Unk_239a418_Ref(T* ptr);
    Unk_239a418_Ref(const Unk_239a418_Ref& other);
    // Takes over the other's reference. Not noexcept: a vector that grows
    // copies its references (adding one each, then dropping the old ones).
    Unk_239a418_Ref(Unk_239a418_Ref&& other) : m_ptr(other.Release()) {}
    ~Unk_239a418_Ref();

    // Takes over the other's reference, letting go of its own first.
    Unk_239a418_Ref& operator=(Unk_239a418_Ref&& other);
    // Holds the other's object too: its reference added, then stored, then
    // the old one dropped (Unk_790260_Owner::Unk_790140, src/gflib3/create).
    Unk_239a418_Ref& operator=(const Unk_239a418_Ref& other);

    // Lets go of the object: cleared first, then released.
    void Reset();
    // Gives up the reference without dropping it.
    T* Release() {
        T* p = m_ptr;
        m_ptr = nullptr;
        return p;
    }

    T* m_ptr;
};

// Another reference with the same calls, whose copy tests its own (stored)
// pointer. The vectors of references (src/gflib3/families) hold these: their
// growth loads each old element once, stores it and tests what it stored,
// where Unk_239a418_Ref's copy loads the other's pointer again after the
// store (the new buffer may alias the old one). Whether the two are one
// class template in the original isn't known; one copy can't compile to
// both.
template <class T>
class Unk_239a418_Ref2 {
public:
    // Holds `ptr`, adding a reference.
    explicit Unk_239a418_Ref2(T* ptr);
    Unk_239a418_Ref2(const Unk_239a418_Ref2& other);
    Unk_239a418_Ref2(const Unk_239a418_Ref<T>& other);
    // Takes over the other's reference. Not noexcept: a vector that grows
    // copies its references (adding one each, then dropping the old ones).
    Unk_239a418_Ref2(Unk_239a418_Ref2&& other) : m_ptr(other.Release()) {}
    ~Unk_239a418_Ref2();

    // Gives up the reference without dropping it.
    T* Release() {
        T* p = m_ptr;
        m_ptr = nullptr;
        return p;
    }

    T* m_ptr;
};

// What frees an object: slot 3 takes the allocation the object kept. Slot 2
// allocates (the size and the alignment), and slot 23 is what the container
// allocators call when it returns nothing.
class Unk_239a418_Allocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void* vf2(u64 size, u64 alignment);
    virtual void vf3(u64 arg1, u64 arg2, u64 arg3);
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
};

// A container allocator that frees through Unk_239a418_Allocator::vf3 (the
// memory, its size and its alignment).
template <class T>
class Unk_239a418_StdAllocator {
public:
    using value_type = T;

    T* allocate(size_t n);
    void deallocate(T* p, size_t n) {
        field_0->vf3(reinterpret_cast<u64>(p), n * sizeof(T), alignof(T));
    }

    Unk_239a418_Allocator* field_0;
};

// The type descriptor the type getters return: its parent's.
struct Unk_239a418_Type {
    explicit Unk_239a418_Type(const Unk_239a418_Type* parent) : field_0(parent) {}

    const Unk_239a418_Type* field_0;
};

inline const Unk_239a418_Type& Unk_239a418_RootType() {
    static Unk_239a418_Type type(nullptr);
    return type;
}

inline const Unk_239a418_Type* Unk_239a418_GetType() {
    static Unk_239a418_Type type(&Unk_239a418_RootType());
    return &type;
}

// The root of both reference-counted objects (vtable 0x710236d378, 2 slots:
// its D2 0x710000a8d0 and D0 0x7100007d10, both `ret`s), 0x48 bytes: the
// allocator and the allocation from 0x8. 310 functions store its vptr, the
// constructors of the classes on it: its constructor is inlined, and its
// vptr is the one stored before the constructor's TLS call. It zeroes the
// allocation and what follows (32-bit stores at +0x30 and +0x40), then takes
// the allocator on top of the thread's stack: what made the object
// (Unk_New::Create, src/gflib3/Unk_New.h) records the allocation, and
// overwrites the allocator, after the constructor. The constructor is
// inline, defined with the stack (src/unsorted/Unk_2771620.h): what
// constructs an object includes that.
class Unk_236d378 {
public:
    Unk_236d378();
    virtual ~Unk_236d378() {}

    static void operator delete(void*) {}

    Unk_239a418_Allocator* field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    // Scalars, not bytes: a derived class's destructor thunk addresses its
    // members from the adjusted `this` only when that lands on a field here
    // (clang folds them into the thunk's own `this` through an array).
    u64 field_28;
    u32 field_30;
    u32 field_34;
    u64 field_38;
    u32 field_40;
    u32 field_44;
};
static_assert(sizeof(Unk_236d378) == 0x48, "Unk_236d378");
PKMN_OFFSET_ASSERT(Unk_236d378, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_236d378, field_40, 0x40);

// The primary base, 0x48 bytes: the root's fields.
class Unk_239a418_Base : public Unk_236d378 {
public:
    virtual ~Unk_239a418_Base() {}
    virtual Unk_239a418_Ref<Unk_239a418_Handle> vf2();  // the handle
    virtual void vf3();                                 // destroy and free
    virtual void vf4();                                 // add a reference
    virtual void vf5();                                 // drop a reference

    static void operator delete(void*) {}
};
static_assert(sizeof(Unk_239a418_Base) == 0x48, "Unk_239a418_Base");

// The interface at +0x48 (vtable 0x710239a458).
class Unk_239a458 {
public:
    virtual ~Unk_239a458() {}
    virtual void vf4();
    virtual void vf5();
    virtual Unk_239a418_Ref<Unk_239a418_Handle> vf2();
    virtual const Unk_239a418_Type* vf_type() { return Unk_239a418_GetType(); }
};

// The interface at +0x50 (vtable 0x710239a498).
class Unk_239a498 {
public:
    virtual const Unk_239a418_Type* vf_type() { return Unk_239a418_GetType(); }
    virtual ~Unk_239a498() {}
};

class Unk_239a418_Owner {
public:
    virtual void* vf0();
};

// gflib3's other reference-counted object (vtable 0x710239a4c0): it keeps its
// count itself, at +0x50, where Unk_239a418 keeps it in a handle. See
// src/gflib3/Unk_239a4c0.h. Its primary base is Unk_239a418_Base's shape,
// on the same root.
class Unk_239a4c0_Base : public Unk_236d378 {
public:
    virtual ~Unk_239a4c0_Base() {}
    virtual void vf2();  // destroy and free
    virtual void vf3();  // add a reference
    virtual void vf4();  // drop a reference

    static void operator delete(void*) {}
};
static_assert(sizeof(Unk_239a4c0_Base) == 0x48, "Unk_239a4c0_Base");

// The interface at +0x48 (vtable 0x710239a4f8).
class Unk_239a4f8 {
public:
    virtual ~Unk_239a4f8() {}
    virtual void vf3();
    virtual void vf4();
};

class Unk_239a4c0 : public Unk_239a4c0_Base, public Unk_239a4f8 {
public:
    Unk_239a4c0() : field_50(0) {}
    ~Unk_239a4c0() override {}
    void vf2() override;
    void vf3() override { ++field_50; }
    void vf4() override {
        if (--field_50 == 0)
            vf2();
    }

    std::atomic<s32> field_50;
};
static_assert(sizeof(Unk_239a4c0) == 0x58, "Unk_239a4c0");
static_assert(__builtin_offsetof(Unk_239a4c0, field_50) == 0x50, "Unk_239a4c0::field_50");

// The handle an object keeps its count in, 0x68 bytes, made by the object's
// constructor (from the allocator of Unk_27736e0, src/gflib3/Unk_5e2700.cpp):
// the shape of Unk_239a4c0, its own count at +0x50, then the object's count
// (+0x54), what the object's type getter gave (+0x58, asked for on the first
// reference) and the object's interface at +0x50 (+0x60).
//
// The original stores Unk_239a4c0's vtable (0x710239a4c0) in it, not one of
// its own, though the classes on Unk_239a4c0 put fields of their own at +0x58
// (Unk_23f5d00, src/unsorted/Unk_23f5d00.h; Unk_2398c40's constructor,
// 0x71005b4c20): which class that vtable is isn't settled. What uses a handle
// adds and drops its references through Unk_239a458 (slots 2 and 3 of the
// +0x48 vtable, as Unk_239a4f8's), so that's its interface here, and its
// vtable its own: the constructors that make one compile to the original's
// code, with the vtable as an unknown data symbol.
class Unk_239a418_Handle : public Unk_239a4c0_Base, public Unk_239a458 {
public:
    // `owner` is the object's interface at +0x50, kept as what gives its type
    // (its first slot).
    explicit Unk_239a418_Handle(Unk_239a498* owner)
        : field_50(0),
          field_54(0),
          field_58(nullptr),
          field_60(reinterpret_cast<Unk_239a418_Owner*>(owner)) {}
    // Out of line (not written here): the vtable isn't emitted with the
    // constructors.
    void vf3() override;

    std::atomic<s32> field_50;
    std::atomic<s32> field_54;
    void* field_58;
    Unk_239a418_Owner* field_60;
};
static_assert(sizeof(Unk_239a418_Handle) == 0x68, "Unk_239a418_Handle");
PKMN_OFFSET_ASSERT(Unk_239a418_Handle, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_239a418_Handle, field_54, 0x54);
PKMN_OFFSET_ASSERT(Unk_239a418_Handle, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_239a418_Handle, field_60, 0x60);

class Unk_239a418 : public Unk_239a418_Base, public Unk_239a458, public Unk_239a498 {
public:
    Unk_239a418();
    ~Unk_239a418() override {}
    Unk_239a418_Ref<Unk_239a418_Handle> vf2() override;
    void vf3() override;
    void vf4() override;
    void vf5() override;

    Unk_239a418_Ref<Unk_239a418_Handle> m_handle;
};
static_assert(sizeof(Unk_239a418) == 0x60, "Unk_239a418");
static_assert(__builtin_offsetof(Unk_239a418, m_handle) == 0x58, "Unk_239a418::m_handle");

template <class T>
Unk_239a418_Ref<T>::Unk_239a418_Ref(T* ptr) : m_ptr(ptr) {
    if (m_ptr)
        static_cast<Unk_239a458*>(m_ptr)->vf4();
}

template <class T>
Unk_239a418_Ref<T>::Unk_239a418_Ref(const Unk_239a418_Ref& other) : m_ptr(other.m_ptr) {
    if (other.m_ptr)
        static_cast<Unk_239a458*>(other.m_ptr)->vf4();
}

template <class T>
Unk_239a418_Ref<T>::~Unk_239a418_Ref() {
    if (m_ptr) {
        static_cast<Unk_239a458*>(m_ptr)->vf5();
        m_ptr = nullptr;
    }
}

template <class T>
Unk_239a418_Ref2<T>::Unk_239a418_Ref2(T* ptr) : m_ptr(ptr) {
    if (m_ptr)
        static_cast<Unk_239a458*>(m_ptr)->vf4();
}

template <class T>
Unk_239a418_Ref2<T>::Unk_239a418_Ref2(const Unk_239a418_Ref2& other) : m_ptr(other.m_ptr) {
    if (m_ptr)
        static_cast<Unk_239a458*>(m_ptr)->vf4();
}

template <class T>
Unk_239a418_Ref2<T>::Unk_239a418_Ref2(const Unk_239a418_Ref<T>& other) : m_ptr(other.m_ptr) {
    if (m_ptr)
        static_cast<Unk_239a458*>(m_ptr)->vf4();
}

template <class T>
Unk_239a418_Ref2<T>::~Unk_239a418_Ref2() {
    if (m_ptr) {
        static_cast<Unk_239a458*>(m_ptr)->vf5();
        m_ptr = nullptr;
    }
}

template <class T>
void Unk_239a418_Ref<T>::Reset() {
    T* p = m_ptr;
    m_ptr = nullptr;
    if (p)
        static_cast<Unk_239a458*>(p)->vf5();
}

template <class T>
Unk_239a418_Ref<T>& Unk_239a418_Ref<T>::operator=(Unk_239a418_Ref&& other) {
    if (m_ptr) {
        static_cast<Unk_239a458*>(m_ptr)->vf5();
        m_ptr = nullptr;
    }
    m_ptr = other.Release();
    return *this;
}

template <class T>
Unk_239a418_Ref<T>& Unk_239a418_Ref<T>::operator=(const Unk_239a418_Ref& other) {
    T* p = other.m_ptr;
    if (p)
        static_cast<Unk_239a458*>(p)->vf4();
    T* old = m_ptr;
    m_ptr = p;
    if (old)
        static_cast<Unk_239a458*>(old)->vf5();
    return *this;
}
