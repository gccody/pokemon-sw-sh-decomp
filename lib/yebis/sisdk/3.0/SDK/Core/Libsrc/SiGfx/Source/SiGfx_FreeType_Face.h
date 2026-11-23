// SiSDK3::SiGfxFreeTypeFace (RTTI names the class): a FreeType face and its
// glyphs (a map of them by character and the pool they come from), with
// placeholder members. The reference counts are defined in this header
// (their __FILE__), at the original's lines, for the class's own translation
// unit (UNK_SIGFX_FREETYPE_FACE_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Pool.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_DirectMap.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Interface.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_FreeType_FaceCache.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_FreeType_Manager.h>

// FreeType's face (FT_FaceRec_, lib/freetype's freetype.h) and size
// (FT_SizeRec_) as the face reads them (placeholder names: FreeType's
// members' in the comments).
struct Unk_FTSize {
    u8 _0[0x18];
    u16 field_18;  // metrics.x_ppem
    u16 field_1a;  // metrics.y_ppem
};
struct Unk_FTFace {
    u8 _0[0x10];
    s64 field_10;  // face_flags
    s64 field_18;  // style_flags
    u8 _20[0x48];
    s64 field_68;  // bbox.xMin
    s64 field_70;  // bbox.yMin
    s64 field_78;  // bbox.xMax
    s64 field_80;  // bbox.yMax
    u16 field_88;  // units_per_EM
    u8 _8a[0xe];
    void* glyph;
    Unk_FTSize* field_a0;  // size
};
PKMN_OFFSET_ASSERT(Unk_FTFace, glyph, 0x98);

namespace SiSDK3 {

// What a font is made from (placeholder name and members): the face's file,
// or its data in memory, which face in it, the characters' size, its glyphs'
// texture's size and how many glyphs there's room for.
struct Unk_FontDesc {
    SiString<char> field_0;  // the file
    s32 field_30;            // the face's index in it
    s32 field_34;            // the characters' width (0: their height)
    s32 field_38;            // and height
    s32 field_3c;            // the texture's width
    s32 field_40;            // and height
    s32 field_44;            // how many glyphs
    const void* field_48;    // the data (null: the file)
    s32 field_50;            // its size
};
PKMN_SIZE_ASSERT(Unk_FontDesc, 0x58);

// (the glyphs' pool's destructor is instantiated in lib/yebis/instances:
// the face's destructor calls it)
extern template SiPool<SiGfxFreeTypeGlyph, 16>::~SiPool();

class SiGfxFreeTypeFace {
public:
    explicit SiGfxFreeTypeFace(ISiAllocator* pAllocator);  // 0x71004ffd70
    virtual ~SiGfxFreeTypeFace();                          // 0x7100500010, 0x7100500500
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    void Unk_500810();                // 0x7100500810
    void* Unk_500890(u32 character);  // 0x7100500890: a character's glyph
    void Unk_500da0();                // 0x7100500da0
    // 0x7100500550: the cache of its glyphs' texture
    void Unk_500550(SiGfxFreeTypeFaceCache* pCache);
    // 0x71005005c0: opens the face a font is made from
    bool Unk_5005c0(const Unk_FontDesc* desc);
    // 0x71005006c0: the characters' size
    bool Unk_5006c0(s32 width, s32 height);

    Unk_4bf660 field_8;
    SiGfxFreeTypeManager* field_18;
    SiString<char> field_20;  // the name
    s32 field_50;  // the characters' width
    s32 field_54;  // and height
    // FreeType's face flags and style flags, one by one
    bool field_58;
    bool field_59;
    bool field_5a;
    bool field_5b;
    bool field_5c;
    FT_FaceRec_* field_60;  // the FreeType face
    u32 field_68;
    SiDirectMap<wchar_t, SiGfxFreeTypeGlyph*, SiDirectMapCompareLess<wchar_t> > field_70;  // the glyphs by character
    u64 field_90;  // (the constructor leaves it as it is)
    SiPool<SiGfxFreeTypeGlyph, 16> field_98;
    SiGfxFreeTypeFaceCache* field_1c0;  // the cache of its glyphs' texture
    // the face's measures at its size (in pixels), its scales and in units of
    // its em
    s32 field_1c8;
    s32 field_1cc;
    s32 field_1d0;
    s32 field_1d4;
    f32 field_1d8;
    f32 field_1dc;
    f32 field_1e0;
    f32 field_1e4;
    f32 field_1e8;
    f32 field_1ec;
};
PKMN_OFFSET_ASSERT(SiGfxFreeTypeFace, field_70, 0x70);
PKMN_OFFSET_ASSERT(SiGfxFreeTypeFace, field_98, 0x98);
PKMN_OFFSET_ASSERT(SiGfxFreeTypeFace, field_1c0, 0x1c0);
PKMN_SIZE_ASSERT(SiGfxFreeTypeFace, 0x1f0);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_FREETYPE_FACE_IMPL
// 0x71005010f0 (vf2), 0x7100501110 (vf3)
#line 41
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxFreeTypeFace, field_8.m_pAllocator, field_8.m_count)
#endif
