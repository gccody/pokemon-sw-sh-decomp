// Scope: common
// SiGfx's FreeType glyph (RTTI: the element type of
// SiSDK3::SiArray<SiSDK3::SiGfxFreeTypeGlyph, 16>, whose reserve and
// destructor call these for each element). Out of line, in a SiGfx TU between
// FreeType's ftsystem.c and ftinit.c; which one isn't known (placeholder file
// name). Placeholder members (SiGfx_FreeType_FaceCache.h names what the
// cache fills in).
#include <types.h>

namespace SiSDK3 {
class SiGfxFreeTypeGlyph {
public:
    SiGfxFreeTypeGlyph();
    ~SiGfxFreeTypeGlyph();

    SiGfxFreeTypeGlyph* m_pPrev;
    SiGfxFreeTypeGlyph* m_pNext;
    s64 field_10;
    bool field_18;
    u64 field_20;
    u64 field_28;
    u64 field_30;
    bool field_38;
    u64 field_40;  // (the constructor leaves it as it is)
    s32 field_48[20];
};
PKMN_OFFSET_ASSERT(SiGfxFreeTypeGlyph, field_38, 0x38);
PKMN_OFFSET_ASSERT(SiGfxFreeTypeGlyph, field_48, 0x48);
PKMN_SIZE_ASSERT(SiGfxFreeTypeGlyph, 0x98);
}  // namespace SiSDK3

// 0x710050ae10
SiSDK3::SiGfxFreeTypeGlyph::SiGfxFreeTypeGlyph()
    : m_pPrev(nullptr), m_pNext(nullptr), field_10(-1), field_18(false), field_20(0), field_28(0), field_30(0),
      field_38(true) {
    for (s32 i = 0; i < 20; i++) {
        field_48[i] = 0;
    }
}

// 0x710050ae50
SiSDK3::SiGfxFreeTypeGlyph::~SiGfxFreeTypeGlyph() {}
