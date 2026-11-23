// SiSDK3::SiGfxShaderGraphDataTypeStruct's registration with the reflection: the
// inline functions SiGfx's kernel calls (0x71004cd490, 0x71004cd960), at this header's path and
// lines (their allocations' and delete's __FILE__ and __LINE__s). Placeholder
// names; the class itself is declared where its translation unit needs it.
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_ReflectionRegister.h>

namespace SiSDK3 {
class SiGfxShaderGraphDataType;
}  // namespace SiSDK3

// 0x7101eeb140: typeid(SiSDK3::SiGfxShaderGraphDataType*).name()
extern const char Unk_1eeb140[];

// 0x710276df00: what the reflection knows of the class (its translation unit's)
extern void* Unk_276df00;
// 0x7102390c30: the class's typeinfo
extern const SiSDK3::Unk_TypeInfo Unk_2390c30;

namespace SiSDK3 {

template <>
inline const char* Unk_RttiName<SiGfxShaderGraphDataType*>() {
    return Unk_1eeb140;
}

// 0x71004cf0d0
inline void Unk_4cf0d0(ISiAllocator* pAllocator) {
#line 171
    UNK_REFLECTION_BEGIN(Unk_276df00, SiGfxShaderGraphDataTypeStruct, Unk_2390c30);
#line 173
    UNK_REFLECTION_PROPERTY(Unk_276df00, SiReflectionPropertyArrayReference<SiGfxShaderGraphDataType*>, "Members", "SiGfxShaderGraphDataType*", 0x108, pAllocator, nullptr, 0x18);
    UNK_REFLECTION_END(Unk_276df00);
}

// (inline in 0x71004cd960)
inline void Unk_UnregisterDataTypeStruct() {
#line 175
    UNK_REFLECTION_DELETE(Unk_276df00)
}

}  // namespace SiSDK3
