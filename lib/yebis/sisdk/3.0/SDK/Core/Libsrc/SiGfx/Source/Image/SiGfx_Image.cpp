// Scope: common
// SiSDK3::SiGfxImage: an image's pixels in memory. Its constructor and
// destructors, its name, the functions that make the image of each kind
// (slots 9 to 14), give a mip level's description, set a channel, pass the
// image to SiGfx's image utility and make a 3D image an array, and an image of
// noise. The reference counts are its header's.
#define UNK_SIGFX_IMAGE_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/Image/SiGfx_Image.h>

#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Alloc.h>

// 0x71004c3510: a string's hash
u32 Unk_4c3510(const SiSDK3::SiString<char>* s);
// 0x71004c4700: assigns a string (Unk_StringFuncs.h's declaration)
void Unk_4c4700(void*, void*);
// 0x71004cbf40 (leafgen's name and type): SiGfx's kernel
u64 Unk_4cbf40_get();
// 0x71004ed0c0, 0x71004ed0f0: a format's bytes per pixel and a compressed
// one's per block; 0x71004ed120, 0x71004ed150: whether it's one of the
// compressed formats the image knows, and whether it's compressed;
// 0x71004ed1a0: how many mip levels a size has
s32 Unk_4ed0c0(u32 format);
s32 Unk_4ed0f0(u32 format);
bool Unk_4ed120(u32 format);
bool Unk_4ed150(u32 format);
s32 Unk_4ed1a0(s32 size, s32 minSize);
s32 Unk_4ed200(s32 width, s32 height, s32 minWidth, s32 minHeight);
s32 Unk_4ed300(s32 width, s32 height, s32 depth, s32 minWidth, s32 minHeight, s32 minDepth);
// 0x71004ed630, 0x71004ed680: where a channel of a format's pixel is and how
// many bytes it is (negative: none)
s32 Unk_4ed630(u32 format, u32 channel);
s32 Unk_4ed680(u32 format, u32 channel);
// 0x71004c9270: noise at a point, of a number of octaves
float Unk_4c9270(float x, float y, int octaves);
// 0x71004ee110: flips an image's rows
void Unk_4ee110(u32 format, u8* data, s32 width, s32 height, s32 rowSize);

// 0x71004f4850, 0x71004f4b30, 0x71004f4d90
template bool SiSDK3::SiArray<SiSDK3::SiGfxImage::ImageData1D, 16>::Unk_4bf190(size_t, bool);
template bool SiSDK3::SiArray<SiSDK3::SiGfxImage::ImageData2D, 16>::Unk_4bf190(size_t, bool);
template bool SiSDK3::SiArray<SiSDK3::SiGfxImage::ImageData3D, 16>::Unk_4bf190(size_t, bool);

namespace SiSDK3 {

// SiGfx's image utility as the image uses it: slots 16 and 17 save an image.
class Unk_4f3c00_Utility {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
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
    virtual bool vf16(SiGfxImage* image, u64 a2, const void* options);
    virtual bool vf17(SiGfxImage* image, u64 a2, const void* options);
};
// SiGfx's kernel as the image uses it: slot 22 is the image utility.
class Unk_4f3c00_Kernel {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual ISiAllocator* vf6();
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
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual Unk_4f3c00_Utility* vf22();
};
inline Unk_4f3c00_Kernel* Unk_GfxKernel() {
    return reinterpret_cast<Unk_4f3c00_Kernel*>(Unk_4cbf40_get());
}

// What slot 21 passes on when it is given no options (placeholder name).
struct Unk_4f3c00_Options {
    Unk_4f3c00_Options() : field_0(false), field_1(false), field_2(true), field_4(0), field_8(0) {}

    bool field_0;
    bool field_1;
    bool field_2;
    u32 field_4;
    u32 field_8;
    SiString<char> field_10;
};
PKMN_SIZE_ASSERT(Unk_4f3c00_Options, 0x40);

// What slot 22 passes on when it is given no options (placeholder name).
struct Unk_4f3cf0_Options {
    Unk_4f3cf0_Options() : field_0(0) {}

    u32 field_0;
    u32 field_4;
};

// 0x71004f1290
SiGfxImage::SiGfxImage(ISiAllocator* pAllocator)
    : field_10(pAllocator), field_20(pAllocator), field_50(0), field_54(0), field_58{2, 0, 0, 0, 0, 0, 0}, field_78(0), field_80(true),
      field_88(nullptr), field_e0(pAllocator), field_130(pAllocator) {}

// 0x71004f13c0 (D2), 0x71004f1790 (D0); 0x71004f1780 and 0x71004f17c0 are
// their thunks for the second base
SiGfxImage::~SiGfxImage() {
    SiGfxImage::vf15();
}

// 0x71004f17f0 (0x71004f1830: its thunk)
bool SiGfxImage::vf5(const char* name) {
    Unk_4c4700(&field_20, const_cast<char*>(name));
    field_50 = Unk_4c3510(&field_20);
    return true;
}

// 0x71004f1870 (0x71004f1880: its thunk)
const SiString<char>* SiGfxImage::vf6() {
    return &field_20;
}

// 0x71004f1890 (0x71004f18a0: its thunk)
u32 SiGfxImage::vf7() {
    return field_50;
}

// 0x71004f18b0
bool SiGfxImage::vf8(const Unk_Info* info) {
    switch (info->field_0) {
    case 1:
        return vf9(info->field_4, info->field_8, info->field_14);
    case 2:
        return vf10(info->field_4, info->field_8, info->field_c, info->field_14);
    case 3:
        return vf14(info->field_4, info->field_8, info->field_c, info->field_10, info->field_14);
    case 4:
        return vf12(info->field_4, info->field_8, info->field_14);
    case 5:
        return vf11(info->field_4, info->field_8, info->field_c, info->field_14, info->field_18);
    case 6:
        return vf13(info->field_4, info->field_8, info->field_14, info->field_18 / 6);
    default:
        return false;
    }
}

// 0x71004f3330
void SiGfxImage::vf15() {
    if (field_88 != nullptr) {
#line 1147
        UNK_FREE(field_10.m_pAllocator, field_88);
    }
    field_58.Unk_Reset();
    field_78 = 0;
    field_80 = true;
    field_90.Unk_4e3050();
    field_e0.Unk_4e3050();
    field_130.Unk_4e3050();
}

// 0x71004f34e0
SiGfxImage::ImageData1D* SiGfxImage::vf16(s32 level) {
    if (field_58.field_0 != 3 || level < 0) {
        return nullptr;
    }
    if (level >= field_58.field_14) {
        return nullptr;
    }
    return &field_90.m_pData[level];
}

// 0x71004f3520
SiGfxImage::ImageData2D* SiGfxImage::vf17(s32 index, s32 level) {
    switch (field_58.field_0) {
    case 2:
        if (index > 0 || level < 0) {
            return nullptr;
        }
        break;
    case 4:
        if (index > 5 || level < 0) {
            return nullptr;
        }
        break;
    case 5:
        if (index < 0 || index >= field_58.field_18) {
            return nullptr;
        }
        if (level < 0) {
            return nullptr;
        }
        break;
    case 6:
        if (index < 0 || index >= field_58.field_18 * 6) {
            return nullptr;
        }
        if (level < 0) {
            return nullptr;
        }
        break;
    default:
        return nullptr;
    }
    if (level >= field_58.field_14) {
        return nullptr;
    }
    s32 i = field_58.field_14 * index + level;
    return &field_e0.m_pData[i];
}

// 0x71004f35e0
SiGfxImage::ImageData2D* SiGfxImage::vf18(s32 index, s32 face, s32 level) {
    if (field_58.field_0 != 4 && field_58.field_0 != 6) {
        return nullptr;
    }
    if (level < 0) {
        return nullptr;
    }
    if (level >= field_58.field_14) {
        return nullptr;
    }
    s32 i = field_58.field_14 * (index * 6 + face) + level;
    return &field_e0.m_pData[i];
}

// 0x71004f3640
SiGfxImage::ImageData3D* SiGfxImage::vf19(s32 level) {
    if (field_58.field_0 != 3 || level < 0) {
        return nullptr;
    }
    if (level >= field_58.field_14) {
        return nullptr;
    }
    return &field_130.m_pData[level];
}

// 0x71004f3680
bool SiGfxImage::Unk_4f3680() {
    for (s64 i = 0; i < static_cast<s32>(field_e0.m_itemCount); i++) {
        ImageData2D* data = &field_e0.m_pData[i];
        Unk_4ee110(data->field_10, data->field_0, data->field_14, data->field_18, data->field_1c);
    }
    field_80 = !field_80;
    return true;
}

// NON_MATCHING: 8 bytes longer, other registers: the loops are unswitched as
// the original's are (on the index, then on the level where the index is
// negative), but where the index isn't negative the original tests the level
// without a branch (`cset; orr; ccmp`) and keeps the level on the stack in
// the 3D loop. Tried: the tests as one condition in both orders, `|`, the
// quotient in a local.
// Also tried: the 3D loop's sizes read inside the slice loop, the level
// test with `|` (3D: 252 lines; with `|` in the 2D tests too the loops
// aren't unswitched any more), the tests nested.
// 0x71004f3700: sets a channel of every pixel of the 2D images of an index
// and a mip level (negative: all of them) to a value
bool SiGfxImage::Unk_4f3700(s32 channel, s32 value, s32 index, s32 level) {
    if (Unk_4ed150(field_58.field_4)) {
        return false;
    }
    s32 offset = Unk_4ed630(field_58.field_4, channel);
    if (offset < 0) {
        return false;
    }
    s32 size = Unk_4ed680(field_58.field_4, channel);
    if (size < 0) {
        return false;
    }
    s32 bytesPerPixel = Unk_4ed0c0(field_58.field_4);
    if (field_58.field_0 == 4 || field_58.field_0 == 5 || field_58.field_0 == 2) {
        for (s32 i = 0; i < static_cast<s32>(field_e0.m_itemCount); i++) {
            if (index >= 0 && i / field_58.field_14 != index) {
                continue;
            }
            if (level < 0 || i % field_58.field_14 == level) {
                ImageData2D* data = &field_e0.m_pData[i];
                u8* row = data->field_0;
                s64 rowSize = data->field_1c;
                for (s32 y = 0; y < data->field_18; y++) {
                    u8* pixel = row + offset;
                    for (s32 x = 0; x < data->field_14; x++) {
                        memcpy(pixel, &value, size);
                        pixel += bytesPerPixel;
                    }
                    row += rowSize;
                }
            }
        }
    } else if (field_58.field_0 == 3) {
        for (s32 i = 0; i < static_cast<s32>(field_130.m_itemCount); i++) {
            if (level < 0 || i % field_58.field_14 == level) {
                ImageData3D* data = &field_130.m_pData[i];
                u8* slice = data->field_0;
                s64 rowSize = data->field_20;
                s64 sliceSize = data->field_24;
                for (s32 z = 0; z < data->field_1c; z++) {
                    u8* row = slice;
                    for (s32 y = 0; y < data->field_18; y++) {
                        u8* pixel = row + offset;
                        for (s32 x = 0; x < data->field_14; x++) {
                            memcpy(pixel, &value, size);
                            pixel += bytesPerPixel;
                        }
                        row += rowSize;
                    }
                    slice += sliceSize;
                }
            }
        }
    }
    return true;
}

// 0x71004f3c00
bool SiGfxImage::vf21(u64 a1, const void* options) {
    Unk_4f3c00_Options defaults;
    Unk_4f3c00_Utility* utility = Unk_GfxKernel()->vf22();
    if (utility == nullptr) {
        return false;
    }
    return utility->vf16(this, a1, options == nullptr ? &defaults : options);
}

// 0x71004f3cf0
bool SiGfxImage::vf22(u64 a1, const void* options) {
    Unk_4f3cf0_Options defaults;
    Unk_4f3c00_Utility* utility = Unk_GfxKernel()->vf22();
    if (utility == nullptr) {
        return false;
    }
    return utility->vf17(this, a1, options == nullptr ? &defaults : options);
}

// 0x71004f19a0: a 1D image. (Its loops count, and its compressed formats'
// mip levels and the pixels' addresses are kept, in the 2D images' array.)
bool SiGfxImage::vf9(u32 format, s32 width, s32 mipCount) {
    vf15();
    if (width < 1) {
        return false;
    }
    if (mipCount == 0) {
        mipCount = Unk_4ed1a0(width, 0);
    }
    field_58.field_8 = width;
    field_58.field_c = 1;
    field_58.field_0 = 1;
    field_58.field_4 = format;
    field_58.field_14 = mipCount;
    field_58.field_18 = 1;
    field_90.Unk_SetCount(mipCount);
    if (!Unk_4ed150(format)) {
        s32 bytesPerPixel = Unk_4ed0c0(format);
        s64 size = 0;
        s32 levelWidth = field_58.field_8;
        for (s32 i = 0; i < static_cast<s32>(field_e0.m_itemCount); i++) {
            ImageData1D* level = &field_90.m_pData[i];
            level->field_10 = field_58.field_4;
            level->field_14 = levelWidth;
            level->field_0 = reinterpret_cast<u8*>(size);
            level->field_8 = size;
            s32 levelSize = levelWidth * bytesPerPixel;
            level->field_18 = levelSize;
            size += levelSize;
            levelWidth >>= 1;
            levelWidth = levelWidth > 1 ? levelWidth : 1;
        }
#line 217
        field_88 = field_10.m_pAllocator != nullptr
                       ? static_cast<u8*>(field_10.m_pAllocator->vf8(1, size, 0x10, __FILE__, __LINE__))
                       : nullptr;
        if (field_88 == nullptr) {
            return false;
        }
        for (s64 i = 0; i < field_58.field_14; i++) {
            field_e0.m_pData[i].field_0 += reinterpret_cast<size_t>(field_88);
        }
        field_78 = size;
    } else {
        if (!Unk_4ed120(format)) {
            return true;
        }
        s32 blockSize = Unk_4ed0f0(format);
        s32 levelWidth = field_58.field_8;
        s64 size = 0;
        for (s64 i = 0; i < static_cast<s32>(field_e0.m_itemCount); i++) {
            ImageData2D* level = &field_e0.m_pData[i];
            level->field_10 = field_58.field_4;
            level->field_14 = levelWidth;
            level->field_0 = reinterpret_cast<u8*>(size);
            level->field_8 = size;
            s32 blocks = (levelWidth + 3) / 4;
            s32 rowSize = blocks * blockSize;
            level->field_1c = rowSize;
            size += static_cast<s64>(rowSize) * blocks;
            levelWidth >>= 1;
            levelWidth = levelWidth > 1 ? levelWidth : 1;
        }
#line 271
        field_88 = field_10.m_pAllocator != nullptr
                       ? static_cast<u8*>(field_10.m_pAllocator->vf8(1, size, 0x10, __FILE__, __LINE__))
                       : nullptr;
        if (field_88 == nullptr) {
            return false;
        }
        for (s64 i = 0; i < static_cast<s32>(field_e0.m_itemCount); i++) {
            field_e0.m_pData[i].field_0 += reinterpret_cast<size_t>(field_88);
        }
        field_78 = size;
    }
    return true;
}

// The end of each level's loop halves the width and the height, then
// clamps them (`w >>= 1; h >>= 1; if (w < 1) w = 1; ...`): written as
// `w < 2 ? 1 : w >> 1` the halvings are scheduled before the size's
// addition and the count's reload, whatever the statements' order.
// 0x71004f1cd0: a 2D image
bool SiGfxImage::vf10(u32 format, s32 width, s32 height, s32 mipCount) {
    vf15();
    if (width < 1 || height < 1) {
        return false;
    }
    if (mipCount == 0) {
        mipCount = Unk_4ed200(width, height, 0, 0);
    }
    field_58.field_0 = 2;
    field_58.field_4 = format;
    field_58.field_8 = width;
    field_58.field_c = height;
    field_58.field_14 = mipCount;
    field_58.field_18 = 1;
    field_e0.Unk_SetCount(mipCount);
    if (!Unk_4ed150(format)) {
        s32 bytesPerPixel = Unk_4ed0c0(format);
        s64 size = 0;
        s32 levelWidth = field_58.field_8;
        s32 levelHeight = field_58.field_c;
        for (s32 i = 0; i < static_cast<s32>(field_e0.m_itemCount); i++) {
            ImageData2D* level = &field_e0.m_pData[i];
            level->field_10 = field_58.field_4;
            level->field_14 = levelWidth;
            s32 rowSize = levelWidth * bytesPerPixel;
            level->field_18 = levelHeight;
            level->field_1c = rowSize;
            level->field_0 = reinterpret_cast<u8*>(size);
            level->field_8 = static_cast<s64>(rowSize) * levelHeight;
            size += static_cast<s64>(rowSize) * levelHeight;
            levelWidth >>= 1;
            levelHeight >>= 1;
            if (levelWidth < 1) levelWidth = 1;
            if (levelHeight < 1) levelHeight = 1;
        }
#line 374
        field_88 = field_10.m_pAllocator != nullptr
                       ? static_cast<u8*>(field_10.m_pAllocator->vf8(1, size, 0x10, __FILE__, __LINE__))
                       : nullptr;
        if (field_88 == nullptr) {
            return false;
        }
        for (s64 i = 0; i < field_58.field_14; i++) {
            field_e0.m_pData[i].field_0 += reinterpret_cast<size_t>(field_88);
        }
        field_78 = size;
    } else {
        if (!Unk_4ed120(format)) {
            return true;
        }
        s32 blockSize = Unk_4ed0f0(format);
        s64 size = 0;
        s32 levelWidth = field_58.field_8;
        s32 levelHeight = field_58.field_c;
        for (s32 i = 0; i < static_cast<s32>(field_e0.m_itemCount); i++) {
            ImageData2D* level = &field_e0.m_pData[i];
            level->field_10 = field_58.field_4;
            level->field_14 = levelWidth;
            s32 blocksWide = (levelWidth + 3) / 4;
            s32 rows = (levelHeight + 3) / 4;
            s32 rowSize = blocksWide * blockSize;
            level->field_18 = levelHeight;
            level->field_1c = rowSize;
            level->field_0 = reinterpret_cast<u8*>(size);
            level->field_8 = static_cast<s64>(rowSize) * rows;
            size += static_cast<s64>(rowSize) * rows;
            levelWidth >>= 1;
            levelHeight >>= 1;
            if (levelWidth < 1) {
                levelWidth = 1;
            }
            if (levelHeight < 1) {
                levelHeight = 1;
            }
        }
#line 434
        field_88 = field_10.m_pAllocator != nullptr
                       ? static_cast<u8*>(field_10.m_pAllocator->vf8(1, size, 0x10, __FILE__, __LINE__))
                       : nullptr;
        if (field_88 == nullptr) {
            return false;
        }
        for (s64 i = 0; i < static_cast<s32>(field_e0.m_itemCount); i++) {
            field_e0.m_pData[i].field_0 += reinterpret_cast<size_t>(field_88);
        }
        field_78 = size;
    }
    return true;
}

// 0x71004f2030: an array of 2D images
bool SiGfxImage::vf11(u32 format, s32 width, s32 height, s32 mipCount, s32 count) {
    vf15();
    if (width < 1 || height < 1 || count == 0) {
        return false;
    }
    if (mipCount == 0) {
        mipCount = Unk_4ed200(width, height, 0, 0);
    }
    field_58.field_0 = 5;
    field_58.field_4 = format;
    field_58.field_8 = width;
    field_58.field_c = height;
    field_58.field_14 = mipCount;
    field_58.field_18 = count;
    field_e0.Unk_SetCount(mipCount * count);
    if (!Unk_4ed150(format)) {
        s32 bytesPerPixel = Unk_4ed0c0(format);
        s64 size = 0;
        for (s32 i = 0; i < field_58.field_18; i++) {
            s32 levelWidth = field_58.field_8;
            s32 levelHeight = field_58.field_c;
            for (s32 level = 0; level < field_58.field_14; level++) {
                s32 index = i * field_58.field_14 + level;
                ImageData2D* data = &field_e0.m_pData[index];
                data->field_10 = field_58.field_4;
                data->field_14 = levelWidth;
                s32 rowSize = levelWidth * bytesPerPixel;
                data->field_18 = levelHeight;
                data->field_1c = rowSize;
                data->field_0 = reinterpret_cast<u8*>(size);
                data->field_8 = static_cast<s64>(rowSize) * levelHeight;
                size += static_cast<s64>(rowSize) * levelHeight;
                levelWidth >>= 1;
                levelHeight >>= 1;
                if (levelWidth < 1) {
                    levelWidth = 1;
                }
                if (levelHeight < 1) {
                    levelHeight = 1;
                }
            }
        }
#line 549
        field_88 = field_10.m_pAllocator != nullptr
                       ? static_cast<u8*>(field_10.m_pAllocator->vf8(1, size, 0x10, __FILE__, __LINE__))
                       : nullptr;
        if (field_88 == nullptr) {
            return false;
        }
        for (s64 i = 0; i < static_cast<s32>(field_e0.m_itemCount); i++) {
            field_e0.m_pData[i].field_0 += reinterpret_cast<size_t>(field_88);
        }
        field_78 = size;
    } else {
        if (!Unk_4ed120(format)) {
            return true;
        }
        s32 blockSize = Unk_4ed0f0(format);
        s64 size = 0;
        for (s32 i = 0; i < field_58.field_18; i++) {
            s32 levelWidth = field_58.field_8;
            s32 levelHeight = field_58.field_c;
            for (s32 level = 0; level < field_58.field_14; level++) {
                s32 index = i * field_58.field_14 + level;
                ImageData2D* data = &field_e0.m_pData[index];
                data->field_10 = field_58.field_4;
                data->field_14 = levelWidth;
                s32 blocksWide = (levelWidth + 3) / 4;
                s32 rows = (levelHeight + 3) / 4;
                s32 rowSize = blocksWide * blockSize;
                data->field_18 = levelHeight;
                data->field_1c = rowSize;
                data->field_0 = reinterpret_cast<u8*>(size);
                data->field_8 = static_cast<s64>(rowSize) * rows;
                size += static_cast<s64>(rowSize) * rows;
                levelWidth >>= 1;
                levelHeight >>= 1;
                if (levelWidth < 1) {
                    levelWidth = 1;
                }
                if (levelHeight < 1) {
                    levelHeight = 1;
                }
            }
        }
#line 612
        field_88 = field_10.m_pAllocator != nullptr
                       ? static_cast<u8*>(field_10.m_pAllocator->vf8(1, size, 0x10, __FILE__, __LINE__))
                       : nullptr;
        if (field_88 == nullptr) {
            return false;
        }
        for (s64 i = 0; i < static_cast<s32>(field_e0.m_itemCount); i++) {
            field_e0.m_pData[i].field_0 += reinterpret_cast<size_t>(field_88);
        }
        field_78 = size;
    }
    return true;
}

// 0x71004f23d0: a cube. The level counters are declared outside their loops
// (the uncompressed branch's before the size, the compressed branch's in the
// face's body after its face counter is declared before the size): that
// decides how the six faces' loops are unrolled (the first face's guard
// `cmp #1; b.lt`) and the order of the counters' zeroings.
bool SiGfxImage::vf12(u32 format, s32 width, s32 mipCount) {
    vf15();
    if (width < 1) {
        return false;
    }
    if (mipCount == 0) {
        mipCount = Unk_4ed1a0(width, 0);
    }
    field_58.field_0 = 4;
    field_58.field_4 = format;
    field_58.field_8 = width;
    field_58.field_c = width;
    field_58.field_14 = mipCount;
    field_58.field_18 = 1;
    field_e0.Unk_SetCount(mipCount * 6);
    if (!Unk_4ed150(format)) {
        s32 bytesPerPixel = Unk_4ed0c0(format);
        s32 level;
        s64 size = 0;
        for (s32 i = 0; i < 6; i++) {
            s32 levelWidth = field_58.field_8;
            s32 levelHeight = field_58.field_c;
            for (level = 0; level < field_58.field_14; level++) {
                s32 index = i * field_58.field_14 + level;
                ImageData2D* data = &field_e0.m_pData[index];
                data->field_10 = field_58.field_4;
                data->field_14 = levelWidth;
                s32 rowSize = levelWidth * bytesPerPixel;
                data->field_18 = levelHeight;
                data->field_1c = rowSize;
                data->field_0 = reinterpret_cast<u8*>(size);
                data->field_8 = static_cast<s64>(rowSize) * levelHeight;
                size += static_cast<s64>(rowSize) * levelHeight;
                levelWidth >>= 1;
                levelHeight >>= 1;
                if (levelWidth < 1) {
                    levelWidth = 1;
                }
                if (levelHeight < 1) {
                    levelHeight = 1;
                }
            }
        }
#line 716
        field_88 = field_10.m_pAllocator != nullptr
                       ? static_cast<u8*>(field_10.m_pAllocator->vf8(1, size, 0x10, __FILE__, __LINE__))
                       : nullptr;
        if (field_88 == nullptr) {
            return false;
        }
        for (s64 i = 0; i < static_cast<s32>(field_e0.m_itemCount); i++) {
            field_e0.m_pData[i].field_0 += reinterpret_cast<size_t>(field_88);
        }
        field_78 = size;
    } else {
        if (!Unk_4ed120(format)) {
            return true;
        }
        s32 blockSize = Unk_4ed0f0(format);
        s32 i;
        s64 size = 0;
        for (i = 0; i < 6; i++) {
            s32 levelWidth = field_58.field_8;
            s32 levelHeight = field_58.field_c;
            s32 level = 0;
            for (; level < field_58.field_14; level++) {
                s32 index = i * field_58.field_14 + level;
                ImageData2D* data = &field_e0.m_pData[index];
                data->field_10 = field_58.field_4;
                data->field_14 = levelWidth;
                s32 blocksWide = (levelWidth + 3) / 4;
                s32 rows = (levelHeight + 3) / 4;
                s32 rowSize = blocksWide * blockSize;
                data->field_18 = levelHeight;
                data->field_1c = rowSize;
                data->field_0 = reinterpret_cast<u8*>(size);
                data->field_8 = static_cast<s64>(rowSize) * rows;
                size += static_cast<s64>(rowSize) * rows;
                levelWidth >>= 1;
                levelHeight >>= 1;
                if (levelWidth < 1) {
                    levelWidth = 1;
                }
                if (levelHeight < 1) {
                    levelHeight = 1;
                }
            }
        }
#line 778
        field_88 = field_10.m_pAllocator != nullptr
                       ? static_cast<u8*>(field_10.m_pAllocator->vf8(1, size, 0x10, __FILE__, __LINE__))
                       : nullptr;
        if (field_88 == nullptr) {
            return false;
        }
        for (s64 i = 0; i < static_cast<s32>(field_e0.m_itemCount); i++) {
            field_e0.m_pData[i].field_0 += reinterpret_cast<size_t>(field_88);
        }
        field_78 = size;
    }
    return true;
}

// 0x71004f2bf0: an array of cubes (the blocks of a compressed format are laid out for the first cube's faces only)
bool SiGfxImage::vf13(u32 format, s32 width, s32 mipCount, s32 count) {
    vf15();
    if (width < 1) {
        return false;
    }
    if (mipCount == 0) {
        mipCount = Unk_4ed1a0(width, 0);
    }
    field_58.field_0 = 6;
    field_58.field_4 = format;
    field_58.field_8 = width;
    field_58.field_c = width;
    field_58.field_14 = mipCount;
    field_58.field_18 = count;
    field_e0.Unk_SetCount(mipCount * count * 6);
    if (!Unk_4ed150(format)) {
        s32 bytesPerPixel = Unk_4ed0c0(format);
        s64 size = 0;
        for (s32 i = 0; i < field_58.field_18 * 6; i++) {
            s32 levelWidth = field_58.field_8;
            s32 levelHeight = field_58.field_c;
            for (s32 level = 0; level < field_58.field_14; level++) {
                s32 index = i * field_58.field_14 + level;
                ImageData2D* data = &field_e0.m_pData[index];
                data->field_10 = field_58.field_4;
                data->field_14 = levelWidth;
                s32 rowSize = levelWidth * bytesPerPixel;
                data->field_18 = levelHeight;
                data->field_1c = rowSize;
                data->field_0 = reinterpret_cast<u8*>(size);
                data->field_8 = static_cast<s64>(rowSize) * levelHeight;
                size += static_cast<s64>(rowSize) * levelHeight;
                levelWidth >>= 1;
                levelHeight >>= 1;
                if (levelWidth < 1) {
                    levelWidth = 1;
                }
                if (levelHeight < 1) {
                    levelHeight = 1;
                }
            }
        }
#line 884
        field_88 = field_10.m_pAllocator != nullptr
                       ? static_cast<u8*>(field_10.m_pAllocator->vf8(1, size, 0x10, __FILE__, __LINE__))
                       : nullptr;
        if (field_88 == nullptr) {
            return false;
        }
        for (s64 i = 0; i < static_cast<s32>(field_e0.m_itemCount); i++) {
            field_e0.m_pData[i].field_0 += reinterpret_cast<size_t>(field_88);
        }
        field_78 = size;
    } else {
        if (!Unk_4ed120(format)) {
            return true;
        }
        s32 blockSize = Unk_4ed0f0(format);
        s64 size = 0;
        for (s32 i = 0; i < field_58.field_18; i++) {
            s32 levelWidth = field_58.field_8;
            s32 levelHeight = field_58.field_c;
            for (s32 level = 0; level < field_58.field_14; level++) {
                s32 index = i * field_58.field_14 + level;
                ImageData2D* data = &field_e0.m_pData[index];
                data->field_10 = field_58.field_4;
                data->field_14 = levelWidth;
                s32 blocksWide = (levelWidth + 3) / 4;
                s32 rows = (levelHeight + 3) / 4;
                s32 rowSize = blocksWide * blockSize;
                data->field_18 = levelHeight;
                data->field_1c = rowSize;
                data->field_0 = reinterpret_cast<u8*>(size);
                data->field_8 = static_cast<s64>(rowSize) * rows;
                size += static_cast<s64>(rowSize) * rows;
                levelWidth >>= 1;
                levelHeight >>= 1;
                if (levelWidth < 1) {
                    levelWidth = 1;
                }
                if (levelHeight < 1) {
                    levelHeight = 1;
                }
            }
        }
#line 946
        field_88 = field_10.m_pAllocator != nullptr
                       ? static_cast<u8*>(field_10.m_pAllocator->vf8(1, size, 0x10, __FILE__, __LINE__))
                       : nullptr;
        if (field_88 == nullptr) {
            return false;
        }
        for (s64 i = 0; i < static_cast<s32>(field_e0.m_itemCount); i++) {
            field_e0.m_pData[i].field_0 += reinterpret_cast<size_t>(field_88);
        }
        field_78 = size;
    }
    return true;
}

// 0x71004f2f90: a 3D image (a compressed format's blocks are laid out for as
// many mip levels as the image is deep, in the levels' array). What decided
// the registers: the level's bytes are the row size times the height and the
// depth; the compressed branch declares its face counter after the size and
// stores the height and depth before it computes the blocks.
bool SiGfxImage::vf14(u32 format, s32 width, s32 height, s32 depth, s32 mipCount) {
    vf15();
    if (width < 1 || height < 1 || depth < 1) {
        return false;
    }
    if (mipCount == 0) {
        mipCount = Unk_4ed300(width, height, depth, 0, 0, 0);
    }
    field_58.field_0 = 3;
    field_58.field_4 = format;
    field_58.field_8 = width;
    field_58.field_c = height;
    field_58.field_10 = depth;
    field_58.field_14 = mipCount;
    field_58.field_18 = 1;
    field_130.Unk_SetCount(mipCount);
    if (!Unk_4ed150(format)) {
        s32 bytesPerPixel = Unk_4ed0c0(format);
        s64 size = 0;
        s32 levelWidth = field_58.field_8;
        s32 levelHeight = field_58.field_c;
        s32 levelDepth = field_58.field_10;
        for (s32 i = 0; i < field_58.field_14; i++) {
            ImageData3D* data = &field_130.m_pData[i];
            data->field_10 = field_58.field_4;
            data->field_14 = levelWidth;
            s32 rowSize = levelWidth * bytesPerPixel;
            s64 bytes = static_cast<s64>(rowSize) * levelHeight * levelDepth;
            data->field_18 = levelHeight;
            data->field_1c = levelDepth;
            data->field_20 = rowSize;
            data->field_24 = rowSize * levelHeight;
            data->field_0 = reinterpret_cast<u8*>(size);
            data->field_8 = bytes;
            size += bytes;
            levelWidth >>= 1;
            levelHeight >>= 1;
            levelDepth >>= 1;
            if (levelWidth < 1) {
                levelWidth = 1;
            }
            if (levelHeight < 1) {
                levelHeight = 1;
            }
            if (levelDepth < 1) {
                levelDepth = 1;
            }
        }
#line 1057
        field_88 = field_10.m_pAllocator != nullptr
                       ? static_cast<u8*>(field_10.m_pAllocator->vf8(1, size, 0x10, __FILE__, __LINE__))
                       : nullptr;
        if (field_88 == nullptr) {
            return false;
        }
        for (s64 i = 0; i < static_cast<s32>(field_130.m_itemCount); i++) {
            field_130.m_pData[i].field_0 += reinterpret_cast<size_t>(field_88);
        }
        field_78 = size;
    } else {
        if (!Unk_4ed120(format)) {
            return true;
        }
        s32 blockSize = Unk_4ed0f0(format);
        s64 size = 0;
        s32 i;
        for (i = 0; i < depth; i++) {
            s32 levelWidth = field_58.field_8;
            s32 levelHeight = field_58.field_c;
            for (s32 level = 0; level < field_58.field_14; level++) {
                s32 index = i * field_58.field_14 + level;
                ImageData3D* data = &field_130.m_pData[index];
                data->field_10 = field_58.field_4;
                data->field_14 = levelWidth;
                data->field_18 = levelHeight;
                data->field_1c = field_58.field_10;
                s32 blocksWide = (levelWidth + 3) / 4;
                s32 rows = (levelHeight + 3) / 4;
                s32 rowSize = blocksWide * blockSize;
                data->field_20 = rowSize;
                data->field_0 = reinterpret_cast<u8*>(size);
                data->field_8 = static_cast<s64>(rowSize) * rows;
                size += static_cast<s64>(rowSize) * rows;
                levelWidth >>= 1;
                levelHeight >>= 1;
                if (levelWidth < 1) {
                    levelWidth = 1;
                }
                if (levelHeight < 1) {
                    levelHeight = 1;
                }
            }
        }
#line 1121
        field_88 = field_10.m_pAllocator != nullptr
                       ? static_cast<u8*>(field_10.m_pAllocator->vf8(1, size, 0x10, __FILE__, __LINE__))
                       : nullptr;
        if (field_88 == nullptr) {
            return false;
        }
        for (s64 i = 0; i < static_cast<s32>(field_130.m_itemCount); i++) {
            field_130.m_pData[i].field_0 += reinterpret_cast<size_t>(field_88);
        }
        field_78 = size;
    }
    return true;
}

// 0x71004f3d60
bool SiGfxImage::vf23(SiGfxImage* other) {
    if (!other->vf8(&field_58)) {
        return false;
    }
    memcpy(other->field_88, field_88, field_78);
    return true;
}

// 0x71004f3dd0: makes a 3D image an array of 2D images, one for each slice
// (of each mip level). The depth is read into a local and the count is the
// product in the call (the array's count is loaded before the depth of 1 is
// stored), and the compressed branch declares its image counter before the
// size (the size is zeroed first).
bool SiGfxImage::vf25() {
    field_58.field_0 = 5;
    s32 depth = field_58.field_10;
    field_58.field_18 = depth;
    field_58.field_10 = 1;
    field_e0.Unk_SetCount(depth * field_58.field_14);
    if (!Unk_4ed150(field_58.field_4)) {
        s32 bytesPerPixel = Unk_4ed0c0(field_58.field_4);
        s64 size = 0;
        for (s32 i = 0; i < field_58.field_18; i++) {
            s32 levelWidth = field_58.field_8;
            s32 levelHeight = field_58.field_c;
            for (s32 level = 0; level < field_58.field_14; level++) {
                s32 index = i * field_58.field_14 + level;
                ImageData2D* data = &field_e0.m_pData[index];
                data->field_10 = field_58.field_4;
                data->field_14 = levelWidth;
                s32 rowSize = levelWidth * bytesPerPixel;
                data->field_18 = levelHeight;
                data->field_1c = rowSize;
                data->field_0 = reinterpret_cast<u8*>(size);
                data->field_8 = static_cast<s64>(rowSize) * levelHeight;
                size += static_cast<s64>(rowSize) * levelHeight;
                levelWidth >>= 1;
                levelHeight >>= 1;
                if (levelWidth < 1) {
                    levelWidth = 1;
                }
                if (levelHeight < 1) {
                    levelHeight = 1;
                }
            }
        }
#line 1984
        u8* pixels = static_cast<u8*>(UNK_ALLOC(field_10.m_pAllocator, size));
        if (pixels == nullptr) {
            field_58.field_8 = 0;
            field_58.field_c = 0;
            field_130.Unk_4e3050();
            return false;
        }
        for (s32 i = 0; i < static_cast<s32>(field_e0.m_itemCount); i++) {
            field_e0.m_pData[i].field_0 += reinterpret_cast<size_t>(pixels);
        }
        for (s32 z = 0; z < field_58.field_18; z++) {
            for (s32 level = 0; level < field_58.field_14; level++) {
                s32 index = z * field_58.field_14 + level;
                ImageData2D* dst = &field_e0.m_pData[index];
                ImageData3D* src = &field_130.m_pData[level];
                s32 sliceSize = src->field_24;
                s32 bytes = static_cast<s32>(dst->field_8);
                bytes = sliceSize > bytes ? bytes : sliceSize;
                s32 slice = z < src->field_1c - 1 ? z : src->field_1c - 1;
                memcpy(dst->field_0, src->field_0 + slice * sliceSize, bytes);
            }
        }
        if (field_88 != nullptr) {
#line 2045
            UNK_FREE(field_10.m_pAllocator, field_88);
        }
        field_88 = pixels;
        field_78 = size;
    } else {
        if (!Unk_4ed120(field_58.field_4)) {
            field_130.Unk_4e3050();
            return true;
        }
        s32 blockSize = Unk_4ed0f0(field_58.field_4);
        s32 i;
        s64 size = 0;
        for (i = 0; i < field_58.field_18; i++) {
            s32 levelWidth = field_58.field_8;
            s32 levelHeight = field_58.field_c;
            for (s32 level = 0; level < field_58.field_14; level++) {
                s32 index = i * field_58.field_14 + level;
                ImageData2D* data = &field_e0.m_pData[index];
                data->field_10 = field_58.field_4;
                data->field_14 = levelWidth;
                s32 blocksWide = (levelWidth + 3) / 4;
                s32 rows = (levelHeight + 3) / 4;
                s32 rowSize = blocksWide * blockSize;
                data->field_18 = levelHeight;
                data->field_1c = rowSize;
                data->field_0 = reinterpret_cast<u8*>(size);
                data->field_8 = static_cast<s64>(rowSize) * rows;
                size += static_cast<s64>(rowSize) * rows;
                levelWidth >>= 1;
                levelHeight >>= 1;
                if (levelWidth < 1) {
                    levelWidth = 1;
                }
                if (levelHeight < 1) {
                    levelHeight = 1;
                }
            }
        }
#line 2098
        u8* pixels = static_cast<u8*>(UNK_ALLOC(field_10.m_pAllocator, size));
        if (pixels == nullptr) {
            field_58.field_8 = 0;
            field_58.field_c = 0;
            field_130.Unk_4e3050();
            return false;
        }
        for (s32 i = 0; i < static_cast<s32>(field_e0.m_itemCount); i++) {
            field_e0.m_pData[i].field_0 += reinterpret_cast<size_t>(pixels);
        }
        for (s32 z = 0; z < field_58.field_18; z++) {
            for (s32 level = 0; level < field_58.field_14; level++) {
                s32 index = z * field_58.field_14 + level;
                ImageData2D* dst = &field_e0.m_pData[index];
                ImageData3D* src = &field_130.m_pData[level];
                s32 sliceSize = src->field_24;
                s32 bytes = static_cast<s32>(dst->field_8);
                bytes = sliceSize > bytes ? bytes : sliceSize;
                s32 slice = z < src->field_1c - 1 ? z : src->field_1c - 1;
                memcpy(dst->field_0, src->field_0 + slice * sliceSize, bytes);
            }
        }
        if (field_88 != nullptr) {
#line 2138
            UNK_FREE(field_10.m_pAllocator, field_88);
        }
        field_88 = pixels;
        field_78 = size;
    }
    field_130.Unk_4e3050();
    return true;
}

// 0x71004f4320
bool SiGfxImage::vf26(s32 kind) {
    if (kind == 0 || field_58.field_0 == kind || field_58.field_0 == 0) {
        return true;
    }
    if (kind == 5 && field_58.field_0 == 3) {
        vf25();
        return true;
    }
    if (kind == 6 && field_58.field_0 == 4) {
        field_58.field_0 = 6;
    }
    return true;
}

// a value between 0 and 255 (inline: placeholder name)
static inline s32 Unk_ClampByte(s32 value) {
    value = value < 0xff ? value : 0xff;
    return value < 0 ? 0 : value;
}

// 0x71004f4390: an image of noise of a number of octaves (format 0x3d, one
// byte a pixel), each mip level stretched to the whole range of bytes; with
// mipmaps unless noMips
SiGfxImage* Unk_4f4390(s32 width, s32 height, s32 octaves, bool noMips) {
    ISiAllocator* pAllocator = Unk_GfxKernel()->vf6();
#line 2425
    SiGfxImage* image = UNK_SI_NEW(pAllocator, 0x10) SiGfxImage(pAllocator);
    if (image == nullptr) {
        return nullptr;
    }
    if (!image->vf10(0x3d, width, height, !noMips)) {
        image->vf3();
        return nullptr;
    }
    if (octaves < 1) {
        octaves = 1;
    }
    s32 levels = image->field_58.field_14;
    for (s32 level = 0; level < levels; level++) {
        SiGfxImage::ImageData2D* data = image->vf17(0, level);
        u8* pixel = data->field_0;
        s32 lowest = 0xff;
        s32 highest = 0;
        for (s32 x = 0; x < data->field_14; x++) {
            f32 u = static_cast<f32>(x) / data->field_14;
            for (s32 y = 0; y < data->field_18; y++) {
                f32 noise = Unk_4c9270(u, static_cast<f32>(y) / data->field_18, octaves);
                u8 value = Unk_ClampByte(static_cast<s32>((noise * 0.5f + 0.5f) * 255.0f));
                lowest = value < lowest ? value : lowest;
                highest = value > highest ? value : highest;
                *pixel++ = value;
            }
        }
        f32 low = lowest / 255.0f;
        f32 range = highest / 255.0f - low;
        u8* pixels = data->field_0;
        for (s64 i = 0; static_cast<s64>(data->field_8) > i; i++) {
            pixels[i] = Unk_ClampByte(static_cast<s32>((pixels[i] / 255.0f - low) / range * 255.0f));
        }
    }
    return image;
}

}  // namespace SiSDK3
