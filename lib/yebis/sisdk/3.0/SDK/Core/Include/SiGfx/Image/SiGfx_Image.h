// SiSDK3::SiGfxImage (RTTI names the class; its bases are ISiInterface and,
// at 8, ISiNamedObject): an image's pixels in memory, with what tells where
// each mip level, face and slice is. Placeholder members; the virtual
// functions are vf<slot>. The reference counts are defined in this header
// (their __FILE__), at the original's lines, for the class's own translation
// unit (UNK_SIGFX_IMAGE_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Array.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Interface.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_NamedObject.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

class SiGfxImage;

// What slot 24 converts an image with (placeholder name and members; passed
// by value). The texture utility's description has one at 0xe8.
struct Unk_ImageConvertDesc {
    u32 field_0;
    s32 field_4;
    s32 field_8;
    // two numbers stored together (placeholder)
    struct Unk_Pair {
        Unk_Pair() : field_0(-1), field_4(0) {}
        s32 field_0;
        u32 field_4;
    };
    Unk_Pair field_c;
    bool field_14;
    bool field_15;
    bool field_16;  // whether field_c.field_4 is the image's to read
};
PKMN_SIZE_ASSERT(Unk_ImageConvertDesc, 0x18);

// The named object's functions are the image's slots 5 to 7.
UNK_NAMED_OBJECT(Unk_ImageNamedObject, vf5, vf6, vf7);

class SiGfxImage : public ISiInterface, public Unk_ImageNamedObject {
public:
    // What an image is (placeholder name): slot 8 makes an image from one.
    struct Unk_Info {
        // a 2D image of no size (inline in slot 15: placeholder name; the
        // image's constructor sets the members one by one)
        void Unk_Reset() {
            field_0 = 2;
            field_4 = 0;
            field_8 = 0;
            field_c = 0;
            field_10 = 0;
            field_14 = 0;
            field_18 = 0;
        }

        s32 field_0;   // 1: 1D, 2: 2D, 3: 3D, 4: a cube, 5: an array of 2D, 6: an array of cubes
        u32 field_4;   // the format
        s32 field_8;   // the width
        s32 field_c;   // the height
        s32 field_10;  // the depth
        s32 field_14;  // how many mip levels
        s32 field_18;  // how many 2D images (six for each cube)
    };
    PKMN_SIZE_ASSERT(Unk_Info, 0x1c);

    // A mip level of a 1D image, of a 2D one and of a 3D one (RTTI names
    // them): where its pixels are, its format and its size.
    struct ImageData1D {
        ImageData1D() : field_0(nullptr), field_8(0), field_10(0), field_14(0), field_18(0) {}

        u8* field_0;
        u64 field_8;
        u32 field_10;  // the format
        s32 field_14;  // the width
        s32 field_18;  // how many bytes
    };
    PKMN_SIZE_ASSERT(ImageData1D, 0x20);
    struct ImageData2D {
        ImageData2D() : field_0(nullptr), field_8(0), field_10(0), field_14(0), field_18(0), field_1c(0) {}

        u8* field_0;
        u64 field_8;
        u32 field_10;  // the format
        s32 field_14;  // the width
        s32 field_18;  // the height
        s32 field_1c;  // how many bytes a row is
    };
    PKMN_SIZE_ASSERT(ImageData2D, 0x20);
    struct ImageData3D {
        ImageData3D()
            : field_0(nullptr), field_8(0), field_10(0), field_14(0), field_18(0), field_1c(0), field_20(0), field_24(0) {}

        u8* field_0;
        u64 field_8;
        u32 field_10;  // the format
        s32 field_14;  // the width
        s32 field_18;  // the height
        s32 field_1c;  // the depth
        s32 field_20;  // how many bytes a row is
        s32 field_24;  // how many bytes a slice is
    };
    PKMN_SIZE_ASSERT(ImageData3D, 0x28);

    explicit SiGfxImage(ISiAllocator* pAllocator);  // 0x71004f1290
    ~SiGfxImage() override;                         // 0x71004f13c0, 0x71004f1790
    u32 vf2() override;                             // 0x71004f45f0
    u32 vf3() override;                             // 0x71004f4610
    u32 vf4() override;
    bool vf5(const char* name) override;      // 0x71004f17f0
    const SiString<char>* vf6() override;     // 0x71004f1870
    u32 vf7() override;                       // 0x71004f1890
    virtual bool vf8(const Unk_Info* info);   // 0x71004f18b0: makes the image of a kind
    virtual bool vf9(u32 format, s32 width, s32 mipCount);
    virtual bool vf10(u32 format, s32 width, s32 height, s32 mipCount);
    virtual bool vf11(u32 format, s32 width, s32 height, s32 mipCount, s32 count);
    virtual bool vf12(u32 format, s32 width, s32 mipCount);
    virtual bool vf13(u32 format, s32 width, s32 mipCount, s32 count);
    virtual bool vf14(u32 format, s32 width, s32 height, s32 depth, s32 mipCount);
    virtual void vf15();                                       // 0x71004f3330: frees the pixels
    virtual ImageData1D* vf16(s32 level);                      // 0x71004f34e0
    virtual ImageData2D* vf17(s32 index, s32 level);           // 0x71004f3520
    virtual ImageData2D* vf18(s32 index, s32 face, s32 level);  // 0x71004f35e0
    virtual ImageData3D* vf19(s32 level);                      // 0x71004f3640
    virtual bool vf20(u64 a1, u64 a2);
    virtual bool vf21(u64 a1, const void* options);  // 0x71004f3c00
    virtual bool vf22(u64 a1, const void* options);  // 0x71004f3cf0
    virtual bool vf23(SiGfxImage* other);            // 0x71004f3d60: copies itself into another image
    // 0x71004f3dc0: an image converted by desc, or none if it needn't be
    virtual bool vf24(SiGfxImage** pConverted, Unk_ImageConvertDesc desc);
    virtual bool vf25();
    virtual bool vf26(s32 kind);  // 0x71004f4320

    // 0x71004f3680
    bool Unk_4f3680();
    // 0x71004f3700 (SiGfxFreeTypeFaceCache calls it with 0, 0, -1, -1 to
    // clear the whole image)
    bool Unk_4f3700(s32 a1, s32 a2, s32 a3, s32 a4);

    Unk_4bf660 field_10;
    SiString<char> field_20;  // the name
    u32 field_50;             // its hash
    u32 field_54;
    Unk_Info field_58;
    u32 field_74;
    s64 field_78;   // how many bytes the pixels are
    bool field_80;
    u8* field_88;   // the pixels
    SiArray<ImageData1D, 16> field_90;
    SiArray<ImageData2D, 16> field_e0;
    SiArray<ImageData3D, 16> field_130;
};
PKMN_SIZE_ASSERT(SiGfxImage, 0x180);
PKMN_OFFSET_ASSERT(SiGfxImage, field_58, 0x58);
PKMN_OFFSET_ASSERT(SiGfxImage, field_90, 0x90);

}  // namespace SiSDK3

#ifdef UNK_SIGFX_IMAGE_IMPL
// 0x71004f45f0 (vf2), 0x71004f4610 (vf3)
#line 42
UNK_REFCOUNT_DEFINE(SiSDK3::SiGfxImage, field_10.m_pAllocator, field_10.m_count)
#endif
