// SiSDK3::SiGfxShaderGraphNodeType's registration with the reflection: the
// inline functions SiGfx's kernel calls (0x71004cd490, 0x71004cd960), at this header's path and
// lines (their allocations' and delete's __FILE__ and __LINE__s). Placeholder
// names; the class itself is declared where its translation unit needs it.
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_ReflectionRegister.h>

// 0x710276d510: what the reflection knows of the class (its translation unit's)
extern void* Unk_276d510;
// 0x710238f8a0: the class's typeinfo
extern const SiSDK3::Unk_TypeInfo Unk_238f8a0;

namespace SiSDK3 {

// (inline in 0x71004cd490)
inline void Unk_RegisterNodeType(ISiAllocator* pAllocator) {
#line 195
    UNK_REFLECTION_BEGIN(Unk_276d510, SiGfxShaderGraphNodeType, Unk_238f8a0);
    UNK_REFLECTION_END(Unk_276d510);
}

// (inline in 0x71004cd960)
inline void Unk_UnregisterNodeType() {
#line 198
    UNK_REFLECTION_DELETE(Unk_276d510)
}

}  // namespace SiSDK3
