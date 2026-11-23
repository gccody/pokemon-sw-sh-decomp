// SiSDK3::SiGfxShaderGraphObject (RTTI names the class and its four bases):
// what every class of the shader graph derives from. An object with a name
// (and the name's hash), an id, a second string and what the reflection needs
// of it. Placeholder members; the virtual functions are vf<slot>, except the
// overrides of ISiNamedObject's, which keep the names that interface has
// (vf18 to vf20: this class's slots 9 to 11).
//
// The small virtual functions are inline, as the original's are: their code is
// in the first translation unit that has a vtable with them (the node type's,
// 0x71004dc340 to 0x71004dc4b0), not in this class's own. That is also where
// the thunks of the other bases' vtables come from, with the function inlined
// (0x71004dc440, 0x71004dc450, 0x71004dc460, 0x71004dc470). The reference
// counts are defined in this header (their __FILE__), at the original's line.
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Guid.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Interface.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

// 0x71004c3510: a string's hash
u32 Unk_4c3510(const SiSDK3::SiString<char>* s);

namespace SiSDK3 {

// Releases the objects an array of pointers holds (their slot 3), then frees
// the array's buffer: SiCore_Array.h's Unk_ReleaseAll, but through the
// array's own inline clear. That is one inline level more, and it shows in
// the destructors that release two arrays (the node type's, the node's): the
// first array's three pointers are already one 24-byte clear when the second
// array's code follows it, which decides the registers of the second's
// addresses. (Inline in every caller: placeholder name.)
template <class T>
inline void Unk_ReleaseItems(SiArray<T*, 16>* array) {
    for (size_t i = 0; i < array->m_itemCount; i++) {
        T* item = array->m_pData[i];
        if (item != nullptr) {
            array->m_pData[i] = nullptr;
            item->vf3();
        }
    }
    array->Unk_FreeAll();
}

}  // namespace SiSDK3

// 0x710276d590: what the reflection knows of the class. Every class of the
// shader graph has such a pointer, in its own translation unit (right after
// the unit's static property handle); the constructors only read them, and
// SiGfx's functions at 0x71004cd490 and 0x71004cd960 are the ones outside
// these units that reference them.
extern void* Unk_276d590;

namespace SiSDK3 {

// RTTI: SiSDK3::ISiGUIDObject. The slots are named after the object's, which
// overrides them (its slots 5 and 6).
class ISiGUIDObject {
public:
    virtual ~ISiGUIDObject() {}
    virtual bool vf5(const SI_GUID& id) = 0;
    virtual const SI_GUID* vf6() = 0;
};

// RTTI: SiSDK3::ISiReflectedObject: the object and its class, as the
// reflection reads them. Its two functions aren't overridden (their names say
// which vtable they are in: vf2 and vf3 are the reference count's).
class ISiReflectedObject {
public:
    // two pointers that both have to be set (placeholder name)
    struct Unk_Pair {
        void* field_0;
        void* field_8;
    };

    ISiReflectedObject() : field_8(nullptr), field_10(nullptr) {}
    virtual ~ISiReflectedObject() {}
    virtual s32 reflected_vf2() { return -1; }  // 0x71004dc480
    // 0x71004dc490
    virtual bool reflected_vf3(const Unk_Pair& pair) { return pair.field_8 != nullptr && pair.field_0 != nullptr; }

    // The object and what the reflection knows of its class. Every
    // constructor of the hierarchy sets both for its own class, the object
    // first: the class is read after the object is stored (two statements,
    // not arguments of one function).
    void* field_8;
    void* field_10;
};

class SiGfxShaderGraphObject : public ISiInterface,
                               public ISiNamedObject,
                               public ISiGUIDObject,
                               public ISiReflectedObject {
public:
    explicit SiGfxShaderGraphObject(ISiAllocator* pAllocator);  // 0x71004dc730
    virtual ~SiGfxShaderGraphObject();                          // 0x71004dc7f0, 0x71004dc920
    inline virtual u32 vf2();                                   // 0x71004dc340
    inline virtual u32 vf3();                                   // 0x71004dc360
    virtual u32 vf4() { return field_30.m_count; }              // 0x71004dc3e0
    // 0x71004dc3f0
    virtual bool vf5(const SI_GUID& id) {
        field_40 = id;
        return true;
    }
    virtual const SI_GUID* vf6() { return &field_40; }  // 0x71004dc400
    virtual bool vf7();                                 // 0x71004dc9e0: a new id
    virtual void vf8();                                 // 0x71004dca10: empties the strings
    virtual bool vf18(const char* name);                // 0x71004dcab0 (slot 9)
    virtual const SiString<char>* vf19() { return &field_50; }  // 0x71004dc410 (slot 10)
    virtual u32 vf20() { return field_80; }                     // 0x71004dc420 (slot 11)
    virtual bool vf12(const char* text);                        // 0x71004dcb30
    virtual const SiString<char>* vf13() { return &field_88; }  // 0x71004dc430
    virtual void vf14();                                        // 0x71004dcb50
    virtual void vf15();                                        // 0x71004dcb60

    // the allocator that made the object (inline: placeholder name)
    ISiAllocator* Unk_Allocator() const { return field_30.m_pAllocator; }

    Unk_4bf660 field_30;
    SI_GUID field_40;
    SiString<char> field_50;  // the name
    u32 field_80;             // its hash
    SiString<char> field_88;
};
PKMN_OFFSET_ASSERT(SiGfxShaderGraphObject, field_30, 0x30);
PKMN_OFFSET_ASSERT(SiGfxShaderGraphObject, field_50, 0x50);
PKMN_OFFSET_ASSERT(SiGfxShaderGraphObject, field_88, 0x88);
PKMN_SIZE_ASSERT(SiGfxShaderGraphObject, 0xb8);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_SHADERGRAPH_OBJECT_IMPL
// 0x71004dc340 (vf2), 0x71004dc360 (vf3)
#line 34
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxShaderGraphObject, field_30.m_pAllocator, field_30.m_count)
#endif

#ifdef UNK_SIGFX_SHADERGRAPH_REFLECTION
// The class's registration with the reflection (placeholder names: the
// inline functions SiGfx's kernel calls, 0x71004cd490 and 0x71004cd960), for
// the translation unit that asks: they need the reflection's headers.
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_ReflectionRegister.h>

// 0x710238fa30: the class's typeinfo
extern const SiSDK3::Unk_TypeInfo Unk_238fa30;
// 0x7101eeae80, 0x7101eeaf10: typeid(SiSDK3::SiString<char>).name(),
// typeid(SiSDK3::SI_GUID).name()
extern const char Unk_1eeae80[];
extern const char Unk_1eeaf10[];

namespace SiSDK3 {

template <>
inline const char* Unk_RttiName<SiString<char>>() {
    return Unk_1eeae80;
}
template <>
inline const char* Unk_RttiName<SI_GUID>() {
    return Unk_1eeaf10;
}

// A string property's value is a copy in the kernel's allocator.
template <>
inline SiReflectionProperty<SiString<char>>::SiReflectionProperty(const char* name, const char* typeName, s64 offset,
                                                                 ISiAllocator* pAllocator,
                                                                 const SiString<char>& value)
    : SiReflectionPropertyBase(name, typeName, offset, pAllocator), field_value(value, nullptr) {
    field_a0 = Unk_RttiName<SiString<char>>();
    field_a8 = Unk_4c34a0(field_a0);
    field_90 = sizeof(SiString<char>);
}

// 0x71004cec00: the class, the handler of its events, its name, the text
// shown for it and its id
inline void Unk_4cec00(ISiAllocator* pAllocator) {
#line 139
    UNK_REFLECTION_BEGIN(Unk_276d590, SiGfxShaderGraphObject, Unk_238fa30);
#line 141
    SiReflectionEventHandlerClassMethod<SiGfxShaderGraphObject>* pHandler = UNK_SI_NEW(pAllocator, 0x10) SiReflectionEventHandlerClassMethod<SiGfxShaderGraphObject>(pAllocator);
    static_cast<SiReflectionObject*>(Unk_276d590)->Unk_4cb7b0(reinterpret_cast<ISiInterface*>(pHandler));
    if (pHandler != nullptr) {
        pHandler->vf3();
    }
#line 142
    UNK_REFLECTION_PROPERTY(Unk_276d590, SiReflectionProperty<SiString<char>>, "Name", "SiStringT", 0x50, pAllocator, SiString<char>());
#line 143
    UNK_REFLECTION_PROPERTY(Unk_276d590, SiReflectionProperty<SiString<char>>, "DisplayName", "SiStringT", 0x88, pAllocator, SiString<char>());
#line 144
    UNK_REFLECTION_PROPERTY(Unk_276d590, SiReflectionProperty<SI_GUID>, "GUID", "SI_GUID", 0x40, pAllocator, SI_GUID());
    UNK_REFLECTION_END(Unk_276d590);
}

// (inline in 0x71004cd960)
inline void Unk_UnregisterObject() {
#line 146
    UNK_REFLECTION_DELETE(Unk_276d590)
}

}  // namespace SiSDK3
#endif
