// Scope: common
// SiSDK3::SiGfxFontDrawHelper: their functions, so far its event handler's
// and the reference counts their header defines.
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_FontDrawHelper.h>

namespace SiSDK3 {

// 0x7100543200, 0x7100543220 (deleting): defined here, so it is a function
// of its own (with the base's inline)
SiGfxFontDrawHelper::GfxEventHandler::~GfxEventHandler() {}

// 0x7100543260
void SiGfxFontDrawHelper::GfxEventHandler::vf5() {}

// 0x7100543270
void SiGfxFontDrawHelper::GfxEventHandler::vf6() {}

}  // namespace SiSDK3
