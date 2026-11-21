// Scope: common
// SiSDK3::SiPool<SiGfxFreeTypeGlyph, 16>'s members (SiCore_Pool.h): explicit
// instantiations. The glyph is as SiArray_Elements.cpp has it: a pool's item
// whose constructor and destructor are out of line.
#define UNK_SIPOOL_WHOLE_ELEMENT
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Pool.h>

namespace SiSDK3 {

class SiGfxFreeTypeGlyph {
public:
    SiGfxFreeTypeGlyph();
    ~SiGfxFreeTypeGlyph();

    SiGfxFreeTypeGlyph* m_pPrev;
    SiGfxFreeTypeGlyph* m_pNext;
    s64 field_10;
    bool field_18;
    u8 field_19[0x7f];
};
PKMN_SIZE_ASSERT(SiGfxFreeTypeGlyph, 0x98);

}  // namespace SiSDK3

using namespace SiSDK3;

// 0x7100500ec0 = _ZN6SiSDK36SiPoolINS_18SiGfxFreeTypeGlyphELi16EE3vf2Em
template bool SiPool<SiGfxFreeTypeGlyph, 16>::vf2(size_t);
// 0x7100501210 = _ZN6SiSDK36SiPoolINS_18SiGfxFreeTypeGlyphELi16EE3vf5Em
template bool SiPool<SiGfxFreeTypeGlyph, 16>::vf5(size_t);
// 0x71004ffed0 = _ZN6SiSDK36SiPoolINS_18SiGfxFreeTypeGlyphELi16EEC1EPNS_12ISiAllocatorEb
template SiPool<SiGfxFreeTypeGlyph, 16>::SiPool(ISiAllocator*, bool);
