// Scope: common
// SiGfx's FreeType glyph (RTTI: the element type of
// SiSDK3::SiArray<SiSDK3::SiGfxFreeTypeGlyph, 16>, whose destructor calls this
// for each element). Out of line, in a SiGfx TU between FreeType's ftsystem.c
// and ftinit.c; which one isn't known (placeholder file name).
#include <types.h>

namespace SiSDK3 {
class SiGfxFreeTypeGlyph {
public:
    ~SiGfxFreeTypeGlyph();
};
}  // namespace SiSDK3

// 0x710050ae50
SiSDK3::SiGfxFreeTypeGlyph::~SiGfxFreeTypeGlyph() {}
