// SiSDK3::SiGfxShaderGraphFunctionNodeType's registration with the reflection: the
// inline functions SiGfx's kernel calls (0x71004cd490, 0x71004cd960), at this header's path and
// lines (their allocations' and delete's __FILE__ and __LINE__s). Placeholder
// names; the class itself is declared where its translation unit needs it.
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_ReflectionRegister.h>

// 0x710276dff8: what the reflection knows of the class (its translation unit's)
extern void* Unk_276dff8;
// 0x7102390c50: the class's typeinfo
extern const SiSDK3::Unk_TypeInfo Unk_2390c50;

namespace SiSDK3 {

// (inline in 0x71004cd490)
inline void Unk_RegisterFunctionNodeType(ISiAllocator* pAllocator) {
#line 147
    UNK_REFLECTION_BEGIN(Unk_276dff8, SiGfxShaderGraphFunctionNodeType, Unk_2390c50);
    UNK_REFLECTION_END(Unk_276dff8);
}

// (inline in 0x71004cd960)
inline void Unk_UnregisterFunctionNodeType() {
#line 150
    UNK_REFLECTION_DELETE(Unk_276dff8)
}

}  // namespace SiSDK3
