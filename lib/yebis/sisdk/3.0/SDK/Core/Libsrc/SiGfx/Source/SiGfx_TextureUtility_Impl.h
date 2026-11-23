// SiSDK3::SiGfxTextureUtility: as far as the executable's functions show
// them, with placeholder members (RTTI names the classes). The reference
// counts are defined in this header (their __FILE__), at the original's lines.
// The virtual functions declared and not defined here or in the .cpp are
// lib/yebis/class's or not decompiled yet (placeholder signatures).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Interface.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/Image/SiGfx_Image.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_BinaryArchive.h>

namespace SiSDK3 {

// How the utility makes a texture (placeholder name): the slots that are
// given none make a default one on their stack; slot 8 fills one in from the
// image it read.
struct Unk_TextureDesc {
    Unk_TextureDesc()
        : field_0(0), field_4(0), field_8(0), field_10(0), field_14(0), field_18(0), field_1c(0), field_20(0),
          field_28(0), field_30(0), field_34(8), field_38(0), field_3c(0), field_40(0), field_44(0), field_50(0),
          field_58(0), field_60(0), field_68(0), field_70(0), field_78(1.0f), field_7c(0), field_80(0), field_84(0) {
        // (this order of the body's stores is the original's, found by a
        // search; the flags in the body, the last first: strb, then strh)
        field_e8.field_0 = 0;
        field_e8.field_4 = -1;
        field_e8.field_8 = -1;
        field_e8.field_c = Unk_ImageConvertDesc::Unk_Pair();
        field_e8.field_16 = false;
        field_e8.field_14 = false;
        field_e8.field_15 = false;
        field_48 = 0;
        field_34 = 8;
        field_100 = -1;
        field_30 = 1;
        field_108 = -1;
    }

    u32 field_0;  // the format
    u32 field_4;
    u64 field_8;
    s32 field_10;  // the width
    s32 field_14;  // the height
    u32 field_18;
    s32 field_1c;  // how many mip levels
    u64 field_20;
    u64 field_28;
    u32 field_30;
    u32 field_34;
    u32 field_38;
    u32 field_3c;
    u32 field_40;
    u32 field_44;
    u64 field_48;
    u64 field_50;
    u64 field_58;
    u64 field_60;
    u64 field_68;
    u64 field_70;
    f32 field_78;
    u32 field_7c;
    u32 field_80;
    u32 field_84;
    SiString<char> field_88;
    SiString<char> field_b8;
    // how an image read for the texture is converted (0xf4 and 0xf8 are one
    // 8-byte pair: store merging only joins stores of one size, and the
    // original stores 0xf0 alone and the pair as one, assigned from a
    // temporary)
    Unk_ImageConvertDesc field_e8;
    s64 field_100;
    s64 field_108;
};
PKMN_OFFSET_ASSERT(Unk_TextureDesc, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_TextureDesc, field_e8, 0xe8);
PKMN_OFFSET_ASSERT(Unk_TextureDesc, field_100, 0x100);
PKMN_SIZE_ASSERT(Unk_TextureDesc, 0x110);

// What an image is read with (placeholder name; SiGfx_Image.cpp's slot 21
// makes a default one): flags, two numbers and a string.
struct Unk_ImageReadOptions {
    explicit Unk_ImageReadOptions(ISiAllocator* pAllocator)
        : field_0(false), field_1(false), field_2(true), field_4(0), field_8(0), field_10(pAllocator) {}

    bool field_0;
    bool field_1;
    bool field_2;
    u32 field_4;
    u32 field_8;
    SiString<char> field_10;
};
PKMN_SIZE_ASSERT(Unk_ImageReadOptions, 0x40);

// A texture as the utility asks it (placeholder): slot 5 is its device.
class Unk_TextureInterface : public ISiInterface {
public:
    virtual void* vf5();
};

class SiGfxTextureUtility {
public:
    explicit SiGfxTextureUtility(ISiAllocator* pAllocator);
    virtual ~SiGfxTextureUtility();
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();
    // makes a texture from a file, with a default description (vf5) or one
    // given (vf6, vf7: on a device)
    virtual bool vf5(ISiInterface* texture, const char* path);  // 0x71004eac60
    virtual bool vf6(ISiInterface* texture, const Unk_TextureDesc* desc, const char* path);  // 0x71004eadf0
    virtual bool vf7(void* device, ISiInterface** texture, const Unk_TextureDesc* desc, const char* path);
    // 0x71004eae70: from an image file (an archive's through vf12), with the
    // texture's archive written to cachePath for platform if it's given
    virtual bool vf8(void* device, ISiInterface** texture, const Unk_TextureDesc* desc, const char* path,
                     const char* cachePath, u32 platform, u32 a7);
    // the same from something read (vf9, vf11) or written (vf10)
    virtual bool vf9(ISiInterface* texture, void* a2, void* a3);             // 0x71004eb370
    virtual bool vf10(void* device, void* a2, void* a3);                     // 0x71004eb520
    virtual bool vf11(void* device, ISiInterface** texture, void* a3, void* a4);  // 0x71004eb6c0
    // makes a texture from a file's archive (0x71004eb870)
    virtual bool vf12(void* device, ISiInterface** texture, const Unk_TextureDesc* desc, const char* path);
    // (from an archive's chunk: the first texture chunk without one)
    virtual bool vf13(void* device, ISiInterface** texture, const Unk_TextureDesc* desc, void* a4, void* a5);  // 0x71004eb990
    virtual u32 vf14();
    virtual u32 vf15();
    virtual u32 vf16();
    // writes a texture's archive for a platform (0x71004ebb20)
    virtual bool vf17(void* texture, const char* path, u32 platform, u32 a4);
    // the chunk of a texture for a platform
    virtual ISiIOBinaryArchive::ChunkHandler* vf18(void* texture, u32 platform);

    Unk_4bf660 field_8;
};

}  // namespace SiSDK3

#ifdef UNK_SIGFX_TEXTUREUTILITY_IMPL
// 0x71004ec870 (vf2), 0x71004ec890 (vf3)
#line 32
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxTextureUtility, field_8.m_pAllocator, field_8.m_count)
#endif
