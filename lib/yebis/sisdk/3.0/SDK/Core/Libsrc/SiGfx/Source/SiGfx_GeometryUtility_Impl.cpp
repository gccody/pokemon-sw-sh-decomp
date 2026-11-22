// Scope: common
// SiSDK3::SiGfxGeometryUtility: their functions, so far the constructor, the
// destructors and the reference counts their header defines.
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_GeometryUtility_Impl.h>

namespace SiSDK3 {

// 0x71004d3100
SiGfxGeometryUtility::SiGfxGeometryUtility(ISiAllocator* pAllocator) : field_8(pAllocator) {}

// 0x71004d3120 (D2), 0x71004d3140 (D0)
SiGfxGeometryUtility::~SiGfxGeometryUtility() {}

}  // namespace SiSDK3
