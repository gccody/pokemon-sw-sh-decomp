// Scope: common
// SiSDK3::SiGfxImageLoaderDDS: the function that makes one, its destructors
// and what picks the reading of an image's pixels by its kind (what tells a
// DDS file by its name, the header's reading and the pixels' aren't written
// yet). The reference counts are its header's.
#define UNK_SIGFX_IMAGELOADER_DDS_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/Image/DDS/SiGfx_ImageLoader_DDS.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/Image/SiGfx_Image.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_Stream.h>

// 0x71004ed0c0: how many bytes a pixel of a format is; 0x71004ed0f0: how many
// a block of a compressed one; 0x71004ed120: whether a format is compressed
s32 Unk_4ed0c0(u32 format);
s32 Unk_4ed0f0(u32 format);
bool Unk_4ed120(u32 format);

// 0x71004f5040: a new loader
SiSDK3::SiGfxImageLoaderDDS* Unk_4f5040(SiSDK3::ISiAllocator* pAllocator) {
#line 37
    return UNK_SI_NEW(pAllocator, 0x10) SiSDK3::SiGfxImageLoaderDDS(pAllocator);
}

namespace SiSDK3 {

// 0x71004f50a0 (D2), 0x71004f50c0 (D0)
SiGfxImageLoaderDDS::~SiGfxImageLoaderDDS() {}

// The larger of two numbers (placeholder name).
inline s32 Unk_Max(s32 a, s32 b) {
    return a > b ? a : b;
}

// NON_MATCHING: the same instructions with the registers of the width and the
// height exchanged (w25 and w26), and in the uncompressed rows' block the
// original loads the level's pixels before it multiplies (`ldr x22, [x22]`,
// then `mul`).
// 0x71004f5dd0: a 2D image's pixels, a row (of blocks) at a time
bool SiGfxImageLoaderDDS::Unk_4f5dd0(ISiIOStream* stream, SiGfxImage* image, const char* path, void* result,
                                     const Unk_4f5870_Header* header, const Unk_4f5870_HeaderDX10* headerDX10,
                                     const bool* isDX10) {
    s32 mipCount = Unk_Max(header->field_18, 1);
    s32 height = header->field_8;
    s32 width = header->field_c;
    for (s32 level = 0; level < mipCount; level++) {
        if (image->field_58.field_14 <= level) {
            break;
        }
        SiGfxImage::ImageData2D* data = image->vf17(0, level);
        if (data == nullptr) {
            return false;
        }
        if (data->field_0 == nullptr) {
            return false;
        }
        if (Unk_4ed120(image->field_58.field_4)) {
            s32 blockSize = Unk_4ed0f0(image->field_58.field_4);
            s32 blocksWide = width > 0 ? (width + 3) / 4 : 1;
            s32 blocksHigh = height < 4 ? 1 : height / 4;
            u8* p = data->field_0;
            s64 rowSize = blocksWide * blockSize;
            for (s32 y = 0; y < blocksHigh; y++) {
                stream->vf21(p, rowSize, true);
                p += rowSize;
            }
        } else {
            s32 pixelSize = Unk_4ed0c0(image->field_58.field_4);
            u8* p = data->field_0;
            s64 rowSize = pixelSize * width;
            for (s32 y = 0; y < height; y++) {
                stream->vf21(p, rowSize, true);
                p += rowSize;
            }
        }
        width = Unk_Max(width >> 1, 1);
        height = Unk_Max(height >> 1, 1);
    }
    return true;
}

// 0x71004f5d90
bool SiGfxImageLoaderDDS::Unk_4f5d90(ISiIOStream* stream, SiGfxImage* image, const char* path, void* result,
                                     const Unk_4f5870_Header* header, const Unk_4f5870_HeaderDX10* headerDX10,
                                     const bool* isDX10) {
    switch (image->field_58.field_0) {
    case 2:
        return Unk_4f5dd0(stream, image, path, result, header, headerDX10, isDX10);
    case 3:
        return Unk_4f6370(stream, image, path, result, header, headerDX10, isDX10);
    case 4:
        return Unk_4f6180(stream, image, path, result, header, headerDX10, isDX10);
    case 5:
        return Unk_4f5f80(stream, image, path, result, header, headerDX10, isDX10);
    default:
        return false;
    }
}

}  // namespace SiSDK3
