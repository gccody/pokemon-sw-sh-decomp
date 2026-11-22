// Scope: common
// SiSDK3::SiGfxTextureUtility: their functions, so far the constructor, the
// destructors and the reference counts their header defines.
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_TextureUtility_Impl.h>

namespace SiSDK3 {

// 0x71004eabd0
SiGfxTextureUtility::SiGfxTextureUtility(ISiAllocator* pAllocator) : field_8(pAllocator) {}

// 0x71004eabf0 (D2), 0x71004eac10 (D0)
SiGfxTextureUtility::~SiGfxTextureUtility() {}

}  // namespace SiSDK3
