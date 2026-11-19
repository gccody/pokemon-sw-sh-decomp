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

// The primary base, 0x48 bytes: the allocator and the allocation from 0x8.
class Unk_239a418_Base {
public:
    virtual ~Unk_239a418_Base() {}
    virtual Unk_239a418_Ref<Unk_239a418_Handle> vf2();  // the handle
    virtual void vf3();                                 // destroy and free
    virtual void vf4();                                 // add a reference
    virtual void vf5();                                 // drop a reference

    static void operator delete(void*) {}

    Unk_239a418_Allocator* field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    // Scalars, not bytes: a derived class's destructor thunk addresses its
    // members from the adjusted `this` only when that lands on a field here
    // (clang folds them into the thunk's own `this` through an array).
    u64 field_28;
    u64 field_30;
    u64 field_38;
    u64 field_40;
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

// The handle an object keeps its count in.
class Unk_239a418_Handle : public Unk_239a418_Base, public Unk_239a458 {
public:
    u32 field_50;
    std::atomic<s32> field_54;
    void* field_58;
    Unk_239a418_Owner* field_60;
};

class Unk_239a418 : public Unk_239a418_Base, public Unk_239a458, public Unk_239a498 {
public:
    Unk_239a418();  // 0x71005e2350, not decompiled yet
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
void Unk_239a418_Ref<T>::Reset() {
    T* p = m_ptr;
    m_ptr = nullptr;
    if (p)
        static_cast<Unk_239a458*>(p)->vf5();
}
