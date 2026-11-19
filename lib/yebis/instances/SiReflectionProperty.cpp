// Scope: common
// SiSDK3::SiReflectionPropertyBase's virtual functions, and the deleting
// destructors of the property templates' instances the executable has (the
// vtables' RTTI names). SiReflectionProperty<SiString<char>> inlines its
// base's destructor differently (its TU decides), so it isn't here yet.
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Reflection.h>

namespace SiSDK3 {
enum SI_POD_TYPE {};
struct SI_GUID {
    u32 field_0[4];
};
template <class T>
struct SiMathVector3D {
    T x;
    T y;
    T z;
};
class SiGfxShaderGraphDataType;
}  // namespace SiSDK3

using namespace SiSDK3;

// SiReflectionPropertyBase: 0x71004d0140 (D1), 0x71004cfb90 (D0), 0x71004cfb40 (vf2),
// 0x71004cfb50 (vf3), 0x71004cfb60 (vf4), 0x71004cfb70 (vf5), 0x71004cfb80 (vf6)
template class SiSDK3::SiReflectionProperty<SI_POD_TYPE>;  // 0x71004cfe30 (D0)
template class SiSDK3::SiReflectionProperty<SI_GUID>;  // 0x71004cfc30 (D0)
template class SiSDK3::SiReflectionProperty<SiGfxShaderGraphDataType*>;  // 0x71004d0000 (D0)
template class SiSDK3::SiReflectionProperty<int>;  // 0x71004d00a0 (D0)
template class SiSDK3::SiReflectionProperty<bool>;  // 0x71004d01f0 (D0)
template class SiSDK3::SiReflectionProperty<SiMathVector3D<float>>;  // 0x71004d0290 (D0)
// 0x71004cff30 (D0), 0x71004cffd0 (vf4), 0x71004cffe0 (vf5), 0x71004cfff0 (vf6)
template class SiSDK3::SiReflectionPropertyArrayReference<SiGfxShaderGraphDataType*>;
