// SiSDK3's reflection, as far as YEBIS's code shows it (placeholder members).
#pragma once

#include "SiCore_Array.h"
#include "SiCore_String.h"
#include "Unk_4bf660.h"

struct Unk_4cf870_arg1;
struct Unk_4cf890_arg1;

namespace SiSDK3 {

// 0x78 bytes: a property handle and its children (RTTI:
// SiSDK3::SiArray<SiSDK3::SiReflectionPropertyHandle, 16>, whose destructor
// destroys its elements with 0x710040f550, the destructor a static handle of
// many TUs registers with __cxa_atexit).
class SiReflectionPropertyHandle {
public:
    SiReflectionPropertyHandle()
        : field_0(nullptr), field_8(nullptr), field_10(nullptr), field_18(nullptr), field_20(-1) {}

    void* field_0;
    void* field_8;
    void* field_10;
    void* field_18;
    int field_20;
    SiArray<SiReflectionPropertyHandle, 16> field_28;
};
PKMN_SIZE_ASSERT(SiReflectionPropertyHandle, 0x78);

// A reflected property (RTTI: SiSDK3::SiReflectionPropertyBase), linked into a
// SiDirectLinkedList<SiReflectionPropertyBase*> (m_pPrev, m_pNext), with two
// strings. Its derived templates' destructors are its own (clang aliases them
// to it): only their deleting destructors are theirs.
class SiReflectionPropertyBase {
public:
    virtual ~SiReflectionPropertyBase() {}
    virtual void* vf2() { return nullptr; }
    virtual u32 vf3() { return 0; }
    virtual u32 vf4() { return 0; }
    virtual u32 vf5() { return 0; }
    virtual u32 vf6() { return 0; }

    SiReflectionPropertyBase* m_pPrev;
    SiReflectionPropertyBase* m_pNext;
    SiString<char> field_18;
    u64 field_48;
    SiString<char> field_50;
};
PKMN_SIZE_ASSERT(SiReflectionPropertyBase, 0x80);

// A property of type T (RTTI: SiSDK3::SiReflectionProperty<T>): its T at
// 0xb0 (SiReflectionProperty<SiString<char>>'s destructor destroys a string
// there).
template <class T>
class SiReflectionProperty : public SiReflectionPropertyBase {
public:
    virtual ~SiReflectionProperty() {}

    u8 field_80[0x30];
    T field_b0;
};

// RTTI: SiSDK3::SiReflectionPropertyArrayReference<T>
template <class T>
class SiReflectionPropertyArrayReference : public SiReflectionPropertyBase {
public:
    virtual ~SiReflectionPropertyArrayReference() {}
    virtual u32 vf4() { return 1; }
    virtual u32 vf5() { return 1; }
    virtual u32 vf6() { return field_b8; }

    u8 field_80[0x38];
    bool field_b8;
};

// An event's handler that calls a method of a T (RTTI:
// SiSDK3::SiReflectionEventHandlerClassMethod<T>). It is reference counted,
// with the count's functions in this header (their __FILE__, at the
// original's line); slots 4 to 6 are lib/yebis/class's for the instance the
// executable has, declared here with that file's placeholder argument types.
// Placeholder members.
template <class T>
class SiReflectionEventHandlerClassMethod {
public:
    virtual ~SiReflectionEventHandlerClassMethod() {}
    virtual u32 vf2();
    virtual u32 vf3();
    virtual u32 vf4();
    virtual void vf5(::Unk_4cf870_arg1* value, bool arg2);
    virtual void vf6(::Unk_4cf890_arg1* value, bool arg2);

    Unk_4bf660 field_8;
};

template <class T>
u32 SiReflectionEventHandlerClassMethod<T>::vf2() {
    return __atomic_add_fetch(&field_8.m_count, 1, __ATOMIC_SEQ_CST);
}

template <class T>
u32 SiReflectionEventHandlerClassMethod<T>::vf3() {
    u32 n = __atomic_sub_fetch(&field_8.m_count, 1, __ATOMIC_SEQ_CST);
    if (n == 0) {
        ISiAllocator* pAllocator = field_8.m_pAllocator;
        this->~SiReflectionEventHandlerClassMethod();
        if (pAllocator != nullptr && static_cast<void*>(pAllocator) != this) {
#line 731
            SI_FREE(pAllocator, this);
        }
    }
    return n;
}

// What turns an enumeration's values into names and back (RTTI:
// SiSDK3::SiEnumConverter<T>): two functions, either of which may be missing.
// Placeholder members.
template <class T>
class SiEnumConverter {
public:
    virtual ~SiEnumConverter() {}
    virtual const char* vf2(T value) {
        if (field_18 != nullptr) {
            return field_18(value);
        }
        return nullptr;
    }
    virtual T vf3(const char* name) {
        if (field_20 != nullptr) {
            return field_20(name);
        }
        return static_cast<T>(0);
    }

    u64 field_8;
    u64 field_10;
    const char* (*field_18)(T value);
    T (*field_20)(const char* name);
};

}  // namespace SiSDK3
