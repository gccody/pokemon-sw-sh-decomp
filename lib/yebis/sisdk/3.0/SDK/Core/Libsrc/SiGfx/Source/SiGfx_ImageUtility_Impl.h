// SiSDK3::SiGfxImageUtility: what keeps the image loaders and savers, and
// loads and saves images with them. As far as the executable's functions show
// it, with placeholder members (RTTI names the classes). The reference
// counts are defined in this header (their __FILE__), at the original's lines.
// The virtual functions declared and not defined here or in the .cpp are
// lib/yebis/class's or not decompiled yet.
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

class SiGfxImage;

// What loads or saves images of one file format (RTTI: ISiGfxImageLoader,
// ISiGfxImageSaver): the slots SiGfxImageUtility calls. Placeholder names.
class ISiGfxImageLoader {
public:
    virtual ~ISiGfxImageLoader();
    virtual u32 vf2();
    virtual u32 vf3();
    virtual u32 vf4();
    // whether a file is one of its format; loads it
    virtual bool vf5(const char* path, SiGfxImage* image);
    virtual bool vf6(const char* path, SiGfxImage* image, const void* options);
};
class ISiGfxImageSaver {
public:
    virtual ~ISiGfxImageSaver();
    virtual u32 vf2();
    virtual u32 vf3();
    virtual u32 vf4();
    virtual bool vf5(const char* path, SiGfxImage* image);
    virtual bool vf6(const char* path, SiGfxImage* image, const void* options);
};

class SiGfxImageUtility {
public:
    // what vf16 is given besides the file: the kind to make the image
    // (0: as it is)
    struct Unk_LoadOptions {
        u64 field_0;
        s32 field_8;
    };

    explicit SiGfxImageUtility(ISiAllocator* pAllocator);
    virtual ~SiGfxImageUtility();
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    virtual bool vf5(ISiGfxImageLoader* pLoader);  // 0x71004d11b0: adds a loader
    virtual void vf6(ISiGfxImageLoader* pLoader);  // 0x71004d1260: takes one out
    virtual void vf7();                            // 0x71004d1330: releases them all
    virtual u32 vf8();
    virtual ISiGfxImageLoader* vf9(s32 index);     // 0x71004d13f0
    virtual bool vf10(ISiGfxImageSaver* pSaver);   // 0x71004d1420: the same for the savers
    virtual void vf11(ISiGfxImageSaver* pSaver);   // 0x71004d14d0
    virtual void vf12();                           // 0x71004d15a0
    virtual u32 vf13();
    virtual ISiGfxImageSaver* vf14(s32 index);     // 0x71004d1660
    virtual ISiGfxImageSaver* vf15(const char* extension);  // 0x71004d1690
    virtual bool vf16(SiGfxImage* image, const char* path, const Unk_LoadOptions* options);  // 0x71004d17f0
    virtual bool vf17(SiGfxImage* image, const char* path, const void* options);             // 0x71004d18d0
    virtual void vf18();

    Unk_4bf660 field_8;
    SiArray<ISiGfxImageLoader*, 16> field_18;
    SiArray<ISiGfxImageSaver*, 16> field_68;
};
PKMN_SIZE_ASSERT(SiGfxImageUtility, 0xb8);

}  // namespace SiSDK3

// 0x71004d2670 (vf2), 0x71004d2690 (vf3)
#line 32
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxImageUtility, field_8.m_pAllocator, field_8.m_count)
