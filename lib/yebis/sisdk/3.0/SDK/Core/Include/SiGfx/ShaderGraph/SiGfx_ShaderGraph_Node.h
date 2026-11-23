// SiSDK3::SiGfxShaderGraphNode's registration with the reflection: the
// inline functions SiGfx's kernel calls (0x71004cd490, 0x71004cd960), at this header's path and
// lines (their allocations' and delete's __FILE__ and __LINE__s). Placeholder
// names; the class itself is declared where its translation unit needs it.
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_ReflectionRegister.h>

namespace SiSDK3 {
// RTTI: SiSDK3::SiReflectionProperty<SiSDK3::SiMathVector3D<float>> (as far
// as the node's position shows it: placeholder members)
template <class T>
struct SiMathVector3D {
    SiMathVector3D() : field_0(0), field_4(0), field_8(0) {}

    T field_0;
    T field_4;
    T field_8;
};
}  // namespace SiSDK3

// typeid(bool), libc++abi's (imported: declared by its symbol)
extern "C" const SiSDK3::Unk_TypeInfo _ZTIb;
// 0x7101eeb1d0: typeid(SiSDK3::SiMathVector3D<float>).name()
extern const char Unk_1eeb1d0[];

// 0x710276db90: what the reflection knows of the class (its translation unit's)
extern void* Unk_276db90;
// 0x7102390a10: the class's typeinfo
extern const SiSDK3::Unk_TypeInfo Unk_2390a10;

namespace SiSDK3 {

template <>
inline const char* Unk_RttiName<bool>() {
    return _ZTIb.field_8;
}
template <>
inline const char* Unk_RttiName<SiMathVector3D<f32>>() {
    return Unk_1eeb1d0;
}

// 0x71004cf400
inline void Unk_4cf400(ISiAllocator* pAllocator) {
#line 165
    UNK_REFLECTION_BEGIN(Unk_276db90, SiGfxShaderGraphNode, Unk_2390a10);
#line 167
    UNK_REFLECTION_PROPERTY(Unk_276db90, SiReflectionProperty<bool>, "UIExpanded", "SI_BOOL", 0x160, pAllocator, true);
#line 168
    UNK_REFLECTION_PROPERTY(Unk_276db90, SiReflectionProperty<SiMathVector3D<f32>>, "UIPosition", "SiMathVector3Df", 0x164, pAllocator, SiMathVector3D<f32>());
    UNK_REFLECTION_END(Unk_276db90);
}

// (inline in 0x71004cd960)
inline void Unk_UnregisterNode() {
#line 170
    UNK_REFLECTION_DELETE(Unk_276db90)
}

}  // namespace SiSDK3
