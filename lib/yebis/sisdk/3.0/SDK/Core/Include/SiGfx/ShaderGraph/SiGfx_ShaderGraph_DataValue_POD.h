// SiSDK3::SiGfxShaderGraphDataValuePOD's registration with the reflection: the
// inline functions SiGfx's kernel calls (0x71004cd490, 0x71004cd960), at this header's path and
// lines (their allocations' and delete's __FILE__ and __LINE__s). Placeholder
// names; the class itself is declared where its translation unit needs it.
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_ReflectionRegister.h>

// 0x710276d790: what the reflection knows of the class (its translation unit's)
extern void* Unk_276d790;
// 0x710238ff90: the class's typeinfo
extern const SiSDK3::Unk_TypeInfo Unk_238ff90;

namespace SiSDK3 {

// (inline in 0x71004cd490)
inline void Unk_RegisterDataValuePOD(ISiAllocator* pAllocator) {
#line 90
    UNK_REFLECTION_BEGIN(Unk_276d790, SiGfxShaderGraphDataValuePOD, Unk_238ff90);
    UNK_REFLECTION_END(Unk_276d790);
}

// (inline in 0x71004cd960)
inline void Unk_UnregisterDataValuePOD() {
#line 93
    UNK_REFLECTION_DELETE(Unk_276d790)
}

}  // namespace SiSDK3
