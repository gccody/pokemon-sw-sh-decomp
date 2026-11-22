// SiSDK3::SiGfxNXFont (RTTI names the class; like the other NX resources it
// is on ISiInterface and, at 8, ISiNamedObject): a FreeType face and the
// cache of its glyphs' texture. Placeholder members; the virtual functions
// are vf<slot>. The reference counts are defined in this header (their
// __FILE__), at the original's lines, for the class's own translation unit
// (UNK_SIGFX_NX_FONT_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiOS/Source/Unk_596410.h>

namespace SiSDK3 {

// SiSDK3::SiGfxFreeTypeFace (RTTI) as the font holds it: 0x1f0 bytes.
// Placeholder names for its functions.
class SiGfxFreeTypeFace {
public:
    explicit SiGfxFreeTypeFace(ISiAllocator* pAllocator);  // 0x71004ffd70
    virtual ~SiGfxFreeTypeFace();                          // 0x7100500010, 0x7100500500
    void Unk_500810();                 // 0x7100500810
    void* Unk_500890(u32 character);   // 0x7100500890: a character's glyph
    void Unk_500da0();                 // 0x7100500da0

    u8 field_8[0x1e8];
};
PKMN_SIZE_ASSERT(SiGfxFreeTypeFace, 0x1f0);

// The cache of the font's glyphs as the font calls it (placeholder names; its
// class isn't identified): slot 3 drops a reference, and its second base, at
// 0x40, is what the font's slot 23 returns.
class Unk_NXFontCacheFirst {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();

    u8 field_8[0x38];
};
class Unk_NXFontCacheSecond {
public:
    virtual void vf0();
};
class Unk_NXFontCache : public Unk_NXFontCacheFirst, public Unk_NXFontCacheSecond {
public:
    void Unk_5316f0(const char* name);  // 0x71005316f0
    void Unk_531710();                  // 0x7100531710
};

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
    virtual void vf18();
    virtual void vf19();                        // 0x71004ffab0: lets go of the cache
    virtual void vf20();
    virtual bool vf21(const char* text);        // 0x71004ffb00: has the text's glyphs made
    virtual bool vf22(char character);          // 0x71004ffb80
    virtual Unk_NXFontCacheSecond* vf23();      // 0x71004ffbb0
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
    Unk_NXFontCache* field_268;
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
