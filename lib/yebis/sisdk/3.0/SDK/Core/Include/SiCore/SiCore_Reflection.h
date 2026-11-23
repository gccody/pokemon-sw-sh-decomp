// SiSDK3's reflection, as far as YEBIS's code shows it (placeholder members).
#pragma once

#include "SiCore_Array.h"
#include "SiCore_LinkedList.h"
#include "SiCore_String.h"
#include "Unk_4bf660.h"
#include "Unk_Interface.h"

struct Unk_4cf870_arg1;
struct Unk_4cf890_arg1;

// 0x71004c34a0: a name's hash
u32 Unk_4c34a0(const char* name);

namespace SiSDK3 {

// What typeid(T).name() reads (std::type_info: its vtable, then the name).
// YEBIS was built with RTTI, this build isn't: the functions that register
// classes with the reflection read the names from these objects, declared
// as the placeholder globals they are in the executable (a class's typeinfo,
// whose name is loaded from it, or for other types the name's string, which
// clang reads directly).
struct Unk_TypeInfo {
    const void* field_0;
    const char* field_8;
};

// typeid(T).name() of a property's type (placeholder name): specialised for
// each type a property is made of, where the property is made.
template <class T>
const char* Unk_RttiName();

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
// strings (its name and its type's). Its derived templates' destructors are
// its own (clang aliases them to it): only their deleting destructors are
// theirs. It ends at 0xac: a derived property's value is in its tail padding
// (at 0xac, or 0xb0 for an 8-byte value).
class SiReflectionPropertyBase {
public:
    // 0x71004cf8b0 (SiGfx's kernel's translation unit)
    SiReflectionPropertyBase(const char* name, const char* typeName, s64 offset, ISiAllocator* pAllocator);
    virtual ~SiReflectionPropertyBase() {}
    virtual void* vf2() { return nullptr; }
    virtual u32 vf3() { return 0; }
    virtual u32 vf4() { return 0; }
    virtual u32 vf5() { return 0; }
    virtual u32 vf6() { return 0; }

    SiReflectionPropertyBase* m_pPrev;
    SiReflectionPropertyBase* m_pNext;
    SiString<char> field_18;  // the name
    u32 field_48;             // its hash (its object sorts by it)
    SiString<char> field_50;  // the type's name
    s64 field_80;             // where it is in its object
    u64 field_88;
    u64 field_90;             // its size
    s64 field_98;             // its index in its object
    const char* field_a0;     // its type's RTTI name
    u32 field_a8;             // that name's hash
};
PKMN_OFFSET_ASSERT(SiReflectionPropertyBase, field_a8, 0xa8);
PKMN_SIZE_ASSERT(SiReflectionPropertyBase, 0xb0);

// A property of type T (RTTI: SiSDK3::SiReflectionProperty<T>) with a value
// (SiReflectionProperty<SiString<char>>'s destructor destroys a string at
// 0xb0). The functions that make the properties have its constructor inline:
// it sets field_a0 to typeid(T).name(), its hash and the size, which needs
// RTTI (the build has none), so it isn't written.
template <class T>
class SiReflectionProperty : public SiReflectionPropertyBase {
public:
    // with its value (inline in the functions that register the classes)
    SiReflectionProperty(const char* name, const char* typeName, s64 offset, ISiAllocator* pAllocator,
                         const T& value)
        : SiReflectionPropertyBase(name, typeName, offset, pAllocator), field_value(value) {
        field_a0 = Unk_RttiName<T>();
        field_a8 = Unk_4c34a0(field_a0);
        field_90 = sizeof(T);
    }
    virtual ~SiReflectionProperty() {}

    T field_value;  // at 0xac, or 0xb0 (placeholder name)
};

// RTTI: SiSDK3::SiReflectionPropertyArrayReference<T>
template <class T>
class SiReflectionPropertyArrayReference : public SiReflectionProperty<T> {
public:
    SiReflectionPropertyArrayReference(const char* name, const char* typeName, s64 offset, ISiAllocator* pAllocator,
                                       const T& value, u64 a7)
        : SiReflectionProperty<T>(name, typeName, offset, pAllocator, value) {
        this->field_88 = a7;
        field_b8 = true;
    }
    virtual ~SiReflectionPropertyArrayReference() {}
    virtual u32 vf4() { return 1; }
    virtual u32 vf5() { return 1; }
    virtual u32 vf6() { return field_b8; }

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
    explicit SiReflectionEventHandlerClassMethod(ISiAllocator* pAllocator) : field_8(pAllocator) {}
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
    // (the functions are stored first: the order of the original's stores)
    SiEnumConverter(T value, s32 count, const char* (*toName)(T value), T (*fromName)(const char* name)) {
        field_18 = toName;
        field_20 = fromName;
        field_8 = value;
        field_10 = count;
    }
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
    s32 field_10;
    const char* (*field_18)(T value);
    T (*field_20)(const char* name);
};

// A property of an enumeration (RTTI: SiSDK3::SiReflectionPropertyEnum<T>),
// with what converts its values (slot 2 gives it: lib/yebis/class has the
// instance's).
template <class T>
class SiReflectionPropertyEnum : public SiReflectionProperty<T> {
public:
    SiReflectionPropertyEnum(const char* name, const char* typeName, s64 offset, ISiAllocator* pAllocator, T value,
                             s32 count, const char* (*toName)(T value), T (*fromName)(const char* name))
        : SiReflectionProperty<T>(name, typeName, offset, pAllocator, value),
          field_b0(value, count, toName, fromName) {}
    virtual ~SiReflectionPropertyEnum() {}
    virtual void* vf2();

    SiEnumConverter<T> field_b0;
};

// A reflected class (RTTI: SiSDK3::SiReflectionObject; SiCore_Reflection.cpp
// is the __FILE__ of its functions): its name, the object it derives from,
// and its properties, in a list while they are added and then in two arrays,
// in their order and by their names' hashes. Placeholder members.
class SiReflectionObject {
public:
    // the order of two properties' hashes (inline: placeholder names)
    struct Unk_Sorter {
        static int Unk_Compare(SiReflectionPropertyBase* a, SiReflectionPropertyBase* b) {
            if (a->field_48 < b->field_48) {
                return -1;
            }
            if (a->field_48 > b->field_48) {
                return 1;
            }
            return 0;
        }
        inline s64 Unk_Partition(s64 count, SiReflectionPropertyBase** items);
        inline bool Unk_4cb630(s64 count, SiReflectionPropertyBase** items);  // 0x71004cb630
    };

    // 0x71004caea0
    SiReflectionObject(ISiAllocator* pAllocator, const char* text, const char* name, SiReflectionObject* pBase);
    virtual ~SiReflectionObject();  // 0x71004cafe0, 0x71004cb3e0

    const char* Unk_GetName() const { return field_40; }

    void Unk_4cb170();  // deletes the properties that are its own
    void Unk_4cb420();  // takes the base's properties, then registers the class
    void Unk_4cb410();  // nothing (it's called once the object is made)
    bool Unk_4cb770(SiReflectionPropertyBase* pProperty);
    void Unk_4cb7b0(ISiInterface* pInterface);

    ISiAllocator* field_8;
    SiString<char> field_10;
    const char* field_40;  // the name
    u32 field_48;          // its hash
    SiReflectionObject* field_50;
    SiDirectLinkedList<SiReflectionPropertyBase*> field_58;
    SiArray<SiReflectionPropertyBase*, 16> field_80;
    SiArray<SiReflectionPropertyBase*, 16> field_d0;  // by hash
    s64 field_120;            // how many of the properties are the base's
    ISiInterface* field_128;  // (reference counted)
};
PKMN_OFFSET_ASSERT(SiReflectionObject, field_58, 0x58);
PKMN_OFFSET_ASSERT(SiReflectionObject, field_120, 0x120);
PKMN_SIZE_ASSERT(SiReflectionObject, 0x130);

}  // namespace SiSDK3
