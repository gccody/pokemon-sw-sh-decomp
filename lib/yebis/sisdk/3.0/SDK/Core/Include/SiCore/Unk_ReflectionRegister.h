// How a class registers itself with the reflection and takes itself out
// (placeholder names; the original's macros aren't known). Each class's
// header expands these in its own inline functions: the allocations and the
// delete have the header's __FILE__ and their own lines (put a #line before
// each). A registration takes the kernel's allocator for a null one, makes
// the class's SiReflectionObject (its name, typeid(Class).name(), no base),
// adds the properties and ends with Unk_4cb420.
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Reflection.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

#define UNK_REFLECTION_BEGIN(pointer, Class, typeInfo)                                                       \
    if (pAllocator == nullptr) {                                                                             \
        pAllocator = ::SiSDK3::Unk_GetKernel()->vf12();                                                      \
    }                                                                                                        \
    (pointer) = UNK_SI_NEW(pAllocator, 0x10) ::SiSDK3::SiReflectionObject(pAllocator, #Class, (typeInfo).field_8, \
                                                                          nullptr);                          \
    static_cast<::SiSDK3::SiReflectionObject*>(pointer)->Unk_4cb410()

// adds a property made with `new Property(arguments)`
#define UNK_REFLECTION_PROPERTY(pointer, Property, ...)                                                      \
    {                                                                                                        \
        ::SiSDK3::SiReflectionPropertyBase* pProperty = UNK_SI_NEW(pAllocator, 0x10) Property(__VA_ARGS__);  \
        static_cast<::SiSDK3::SiReflectionObject*>(pointer)->Unk_4cb770(pProperty);                         \
    }

#define UNK_REFLECTION_END(pointer) static_cast<::SiSDK3::SiReflectionObject*>(pointer)->Unk_4cb420()

#define UNK_REFLECTION_DELETE(pointer)                                                                       \
    if ((pointer) != nullptr) {                                                                              \
        ::SiSDK3::SiReflectionObject* pObject = static_cast<::SiSDK3::SiReflectionObject*>(pointer);        \
        SI_DELETE(pObject->field_8, pObject);                                                                \
        (pointer) = nullptr;                                                                                 \
    }
