// SiSDK3::SiGfxShaderGraph's registration with the reflection: the
// inline functions SiGfx's kernel calls (0x71004cd490, 0x71004cd960), at this header's path and
// lines (their allocations' and delete's __FILE__ and __LINE__s). Placeholder
// names; the class itself is declared where its translation unit needs it.
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_ReflectionRegister.h>

// 0x710276dc90: what the reflection knows of the class (its translation unit's)
extern void* Unk_276dc90;
// 0x7102390bd0: the class's typeinfo
extern const SiSDK3::Unk_TypeInfo Unk_2390bd0;

namespace SiSDK3 {

// (inline in 0x71004cd490)
inline void Unk_RegisterShaderGraph(ISiAllocator* pAllocator) {
#line 237
    UNK_REFLECTION_BEGIN(Unk_276dc90, SiGfxShaderGraph, Unk_2390bd0);
    UNK_REFLECTION_END(Unk_276dc90);
}

// (inline in 0x71004cd960)
inline void Unk_UnregisterShaderGraph() {
#line 240
    UNK_REFLECTION_DELETE(Unk_276dc90)
}

}  // namespace SiSDK3
