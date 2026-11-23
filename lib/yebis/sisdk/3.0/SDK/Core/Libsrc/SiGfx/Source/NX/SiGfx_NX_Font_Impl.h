// SiSDK3::SiGfxNXFont (RTTI names the class; like the other NX resources it
// is on ISiInterface and, at 8, ISiNamedObject): a FreeType face and the
// cache of its glyphs' texture. Placeholder members; the virtual functions
// are vf<slot>. The reference counts are defined in this header (their
// __FILE__), at the original's lines, for the class's own translation unit
// (UNK_SIGFX_NX_FONT_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_FreeType_Face.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_FreeType_FaceCache.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiOS/Source/Unk_596410.h>

namespace SiSDK3 {

// The named object's functions are the font's slots 25 to 27.
UNK_NAMED_OBJECT(Unk_NXFontNamedObject, vf25, vf26, vf27);

class SiGfxNXFont : public Unk_NXInterface, public Unk_NXFontNamedObject {
public:
    SiGfxNXFont(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x71004ff510
    ~SiGfxNXFont() override;                    // 0x71004ff5b0, 0x71004ff670
    u32 vf2() override;                         // 0x71004ffc40
    u32 vf3() override;                         // 0x71004ffc60
    u32 vf4() override;
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual bool vf18(const Unk_FontDesc* desc);  // 0x71004ff920: makes it
    virtual void vf19();                        // 0x71004ffab0: lets go of the cache
    virtual void vf20();
    virtual bool vf21(const char* text);        // 0x71004ffb00: has the text's glyphs made
    virtual bool vf22(char character);          // 0x71004ffb80
    virtual SiGfxImage* vf23();                 // 0x71004ffbb0: the cache's image
    virtual void vf24();                        // 0x71004ffc10
    bool vf25(const char* name) override;       // 0x71004ff700
    const SiString<char>* vf26() override;      // 0x71004ff830
    u32 vf27() override;                        // 0x71004ff850

    // 0x71004ff6d0: its place in the pool, for the pool that made it
    bool Unk_4ff6d0(size_t index);
    // 0x71004ffbe0: a character's glyph
    void* Unk_4ffbe0(u32 character);

    Unk_4bf660 field_10;
    SiGfxNXDevice* field_20;
    size_t field_28;          // its index in the pool (0: it isn't in one)
    SiString<char> field_30;  // the name
    u32 field_60;             // its hash
    Unk_NXResourceInfo field_64;
    SiGfxFreeTypeFace field_78;
    SiGfxNXFreeTypeFaceCache* field_268;  // the cache of its glyphs
    SiOSCriticalSection field_270;
};
PKMN_OFFSET_ASSERT(SiGfxNXFont, field_78, 0x78);
PKMN_OFFSET_ASSERT(SiGfxNXFont, field_268, 0x268);
PKMN_SIZE_ASSERT(SiGfxNXFont, 0x2a0);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_NX_FONT_IMPL
// 0x71004ffc40 (vf2), 0x71004ffc60 (vf3)
#line 45
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxNXFont, field_10.m_pAllocator, field_10.m_count)
#endif
