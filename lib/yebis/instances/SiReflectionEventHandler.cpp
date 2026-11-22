// Scope: common
// The instances the executable has of SiCore_Reflection.h's event handler and
// enumeration converter templates (the vtables' RTTI names): their
// destructors, and the handler's reference counts and the converter's two
// functions.
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Reflection.h>

namespace SiSDK3 {
enum SI_POD_TYPE {};
class SiGfxShaderGraphObject;
}  // namespace SiSDK3

// 0x71004cf760 (D2), 0x71004cf780 (D0), 0x71004cf7c0 (vf2), 0x71004cf7e0 (vf3)
template class SiSDK3::SiReflectionEventHandlerClassMethod<SiSDK3::SiGfxShaderGraphObject>;
// 0x71004cff20 (D2), 0x71004cfed0 (D0), 0x71004cfee0 (vf2), 0x71004cff00 (vf3)
template class SiSDK3::SiEnumConverter<SiSDK3::SI_POD_TYPE>;
