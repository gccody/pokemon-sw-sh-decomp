// SiSDK3::SiGfxFreeTypeManager (RTTI names the class): the FreeType library
// and the font files' data by face, with placeholder members. The reference
// counts are defined in this header (their __FILE__), at the original's lines,
// for the class's own translation unit (UNK_SIGFX_FREETYPE_MANAGER_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Map.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

struct FT_FaceRec_;
struct FT_LibraryRec_;

namespace SiSDK3 {

class SiGfxNXDevice;

class SiGfxFreeTypeManager {
public:
    typedef SiMap<FT_FaceRec_*, u8*, SiMapCompareLess<FT_FaceRec_*, 16>, 16> Unk_Map;

    explicit SiGfxFreeTypeManager(SiGfxNXDevice* pDevice);  // 0x710050aee0
    virtual ~SiGfxFreeTypeManager();                        // 0x710050af80, 0x710050b050
    UNK_REFCOUNT_DECLARE;
    // (slots 4 to 12 are lib/yebis/class's)
    virtual u32 vf4();
    virtual u32 vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual bool vf13();  // 0x710050b0e0: starts FreeType
    virtual void vf14();  // 0x710050b130: ends it and frees the faces' data
    // 0x710050b210: a face from a file (its data stays with the manager)
    bool Unk_50b210(FT_FaceRec_** pFace, const char* path, s32 index);
    // 0x710050ba10: a face from a copy of data in memory
    bool Unk_50ba10(FT_FaceRec_** pFace, const void* data, s32 size, s32 index);

    Unk_4bf660 field_8;
    SiGfxNXDevice* field_18;
    u64 field_20;
    FT_LibraryRec_* field_28;
    Unk_Map field_30;  // the data of each face
    u64 field_50;  // (the constructor leaves it as it is)
};
PKMN_OFFSET_ASSERT(SiGfxFreeTypeManager, field_28, 0x28);
PKMN_OFFSET_ASSERT(SiGfxFreeTypeManager, field_30, 0x30);
PKMN_SIZE_ASSERT(SiGfxFreeTypeManager, 0x58);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_FREETYPE_MANAGER_IMPL
// 0x710050c310 (vf2), 0x710050c330 (vf3)
#line 40
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxFreeTypeManager, field_8.m_pAllocator, field_8.m_count)
#endif
