// SiSDK3's reflection, as far as YEBIS's code shows it (placeholder members).
#pragma once

#include "SiCore_Array.h"
#include "SiCore_String.h"

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

}  // namespace SiSDK3
