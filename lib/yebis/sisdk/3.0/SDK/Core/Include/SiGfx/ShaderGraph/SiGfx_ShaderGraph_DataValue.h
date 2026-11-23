// SiSDK3::SiGfxShaderGraphDataValue's registration with the reflection: the
// inline functions SiGfx's kernel calls (0x71004cd490, 0x71004cd960), at this header's path and
// lines (their allocations' and delete's __FILE__ and __LINE__s). Placeholder
// names; the class itself is declared where its translation unit needs it.
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_ReflectionRegister.h>

// 0x710276d810: what the reflection knows of the class (its translation unit's)
extern void* Unk_276d810;
// 0x71023900d0: the class's typeinfo
extern const SiSDK3::Unk_TypeInfo Unk_23900d0;

namespace SiSDK3 {

// (inline in 0x71004cd490)
inline void Unk_RegisterDataValue(ISiAllocator* pAllocator) {
#line 133
    UNK_REFLECTION_BEGIN(Unk_276d810, SiGfxShaderGraphDataValue, Unk_23900d0);
    UNK_REFLECTION_END(Unk_276d810);
}

// (inline in 0x71004cd960)
inline void Unk_UnregisterDataValue() {
#line 136
    UNK_REFLECTION_DELETE(Unk_276d810)
}

}  // namespace SiSDK3
