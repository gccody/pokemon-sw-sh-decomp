// SiSDK3::SiGfxShaderGraphDataTypePOD's registration with the reflection: the
// inline functions SiGfx's kernel calls (0x71004cd490, 0x71004cd960), at this header's path and
// lines (their allocations' and delete's __FILE__ and __LINE__s). Placeholder
// names; the class itself is declared where its translation unit needs it.
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_ReflectionRegister.h>

namespace SiSDK3 {
// the shader graph's kind of number (placeholder: its values' names are
// SiCore_Utility.cpp's)
enum SI_POD_TYPE {};
}  // namespace SiSDK3

// 0x7101eeafe0: typeid(SiSDK3::SI_POD_TYPE).name()
extern const char Unk_1eeafe0[];
// 0x71004c9cb0, 0x71004c9ce0 (SiCore_Utility.cpp): a kind's name and the
// kind of a name, as the kind's converter takes them
const char* Unk_4c9cb0(u32 value);
u32 Unk_4c9ce0(const char* name);
#define UNK_POD_TYPE_CONVERTERS                                                \
    reinterpret_cast<const char* (*)(::SiSDK3::SI_POD_TYPE)>(Unk_4c9cb0),      \
        reinterpret_cast<::SiSDK3::SI_POD_TYPE (*)(const char*)>(Unk_4c9ce0)

// 0x710276d690: what the reflection knows of the class (its translation unit's)
extern void* Unk_276d690;
// 0x710238fd00: the class's typeinfo
extern const SiSDK3::Unk_TypeInfo Unk_238fd00;

namespace SiSDK3 {

template <>
inline const char* Unk_RttiName<SI_POD_TYPE>() {
    return Unk_1eeafe0;
}

// 0x71004cef70
inline void Unk_4cef70(ISiAllocator* pAllocator) {
#line 105
    UNK_REFLECTION_BEGIN(Unk_276d690, SiGfxShaderGraphDataTypePOD, Unk_238fd00);
#line 107
    UNK_REFLECTION_PROPERTY(Unk_276d690, SiReflectionPropertyEnum<SI_POD_TYPE>, "PODType", "SI_POD_TYPE", 0x108, pAllocator, static_cast<SI_POD_TYPE>(6), 13, UNK_POD_TYPE_CONVERTERS);
    UNK_REFLECTION_END(Unk_276d690);
}

// (inline in 0x71004cd960)
inline void Unk_UnregisterDataTypePOD() {
#line 109
    UNK_REFLECTION_DELETE(Unk_276d690)
}

}  // namespace SiSDK3
