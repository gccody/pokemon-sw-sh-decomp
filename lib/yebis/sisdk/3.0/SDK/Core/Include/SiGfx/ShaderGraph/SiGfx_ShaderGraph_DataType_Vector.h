// SiSDK3::SiGfxShaderGraphDataTypeVector's registration with the reflection: the
// inline functions SiGfx's kernel calls (0x71004cd490, 0x71004cd960), at this header's path and
// lines (their allocations' and delete's __FILE__ and __LINE__s). Placeholder
// names; the class itself is declared where its translation unit needs it.
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_ReflectionRegister.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/ShaderGraph/SiGfx_ShaderGraph_DataType_POD.h>

// typeid(int), libc++abi's (imported: declared by its symbol)
extern "C" const SiSDK3::Unk_TypeInfo _ZTIi;

// 0x710276da10: what the reflection knows of the class (its translation unit's)
extern void* Unk_276da10;
// 0x7102390620: the class's typeinfo
extern const SiSDK3::Unk_TypeInfo Unk_2390620;

namespace SiSDK3 {

template <>
inline const char* Unk_RttiName<int>() {
    return _ZTIi.field_8;
}

// 0x71004cf210
inline void Unk_4cf210(ISiAllocator* pAllocator) {
#line 117
    UNK_REFLECTION_BEGIN(Unk_276da10, SiGfxShaderGraphDataTypeVector, Unk_2390620);
#line 119
    UNK_REFLECTION_PROPERTY(Unk_276da10, SiReflectionPropertyEnum<SI_POD_TYPE>, "VectorPODType", "SI_POD_TYPE", 0x108, pAllocator, static_cast<SI_POD_TYPE>(11), 13, UNK_POD_TYPE_CONVERTERS);
#line 120
    UNK_REFLECTION_PROPERTY(Unk_276da10, SiReflectionProperty<int>, "VectorDimension", "SI_INT", 0x10c, pAllocator, 1);
    UNK_REFLECTION_END(Unk_276da10);
}

// (inline in 0x71004cd960)
inline void Unk_UnregisterDataTypeVector() {
#line 122
    UNK_REFLECTION_DELETE(Unk_276da10)
}

}  // namespace SiSDK3
