// Scope: common
// SiSDK3::SiGfxImageUtility: its constructor and destructors, the lists of
// loaders and savers, and loading and saving an image with them. The
// reference counts are its header's.
#define UNK_SIGFX_IMAGEUTILITY_IMPL
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/Image/SiGfx_Image.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_ImageUtility_Impl.h>

bool Unk_582d80(const char* path, bool searchArchives);
// 0x71004ed0c0: a format's bytes per element; 0x71004ed4f0: writes a pixel
// (four floats) in a format
s32 Unk_4ed0c0(u32 format);
void Unk_4ed4f0(u32 format, void* pPixel, const f32* pValue);
// 0x71004f5040: makes the DDS loader (it returns SiGfxImageLoaderDDS*)
SiSDK3::ISiGfxImageLoader* Unk_4f5040(SiSDK3::ISiAllocator* pAllocator);

namespace SiSDK3 {

// 0x71004d0df0
SiGfxImageUtility::SiGfxImageUtility(ISiAllocator* pAllocator)
    : field_8(pAllocator), field_18(pAllocator), field_68(pAllocator) {}

// 0x71004d0ea0 (D2), 0x71004d1120 (D0)
SiGfxImageUtility::~SiGfxImageUtility() {
    Unk_ReleaseAll(&field_18);
    vf12();
}

// 0x71004d1150
bool SiGfxImageUtility::Unk_4d1150() {
    ISiGfxImageLoader* pLoader = Unk_4f5040(field_8.m_pAllocator);
    vf5(pLoader);
    if (pLoader != nullptr) {
        pLoader->vf3();
    }
    return true;
}

// 0x71004d11b0
bool SiGfxImageUtility::vf5(ISiGfxImageLoader* pLoader) {
    if (pLoader == nullptr) {
        return false;
    }
    field_18.Unk_Add(pLoader);
    pLoader->vf2();
    return true;
}

// 0x71004d1260
void SiGfxImageUtility::vf6(ISiGfxImageLoader* pLoader) {
    if (pLoader == nullptr) {
        return;
    }
    field_18.Unk_RemoveValue(pLoader);
    pLoader->vf3();
}

// 0x71004d1330
void SiGfxImageUtility::vf7() {
    Unk_ReleaseAll(&field_18);
}

// 0x71004d13f0
ISiGfxImageLoader* SiGfxImageUtility::vf9(s32 index) {
    if (index < 0) {
        return nullptr;
    }
    if (index >= static_cast<s32>(field_18.m_itemCount)) {
        return nullptr;
    }
    return field_18.m_pData[index];
}

// 0x71004d1420
bool SiGfxImageUtility::vf10(ISiGfxImageSaver* pSaver) {
    if (pSaver == nullptr) {
        return false;
    }
    field_68.Unk_Add(pSaver);
    pSaver->vf2();
    return true;
}

// 0x71004d14d0
void SiGfxImageUtility::vf11(ISiGfxImageSaver* pSaver) {
    if (pSaver == nullptr) {
        return;
    }
    field_68.Unk_RemoveValue(pSaver);
    pSaver->vf3();
}

// 0x71004d15a0
void SiGfxImageUtility::vf12() {
    Unk_ReleaseAll(&field_68);
}

// 0x71004d1660
ISiGfxImageSaver* SiGfxImageUtility::vf14(s32 index) {
    if (index < 0) {
        return nullptr;
    }
    if (index >= static_cast<s32>(field_68.m_itemCount)) {
        return nullptr;
    }
    return field_68.m_pData[index];
}

// 0x71004d1690: the saver for a file name extension, the last one added
// first: each is asked about a made up file name with the extension
ISiGfxImageSaver* SiGfxImageUtility::vf15(const char* extension) {
    SiString<char> name;
    name.Unk_SetExternal("hoge.");
    Unk_StringAppend(&name, extension);
    for (s32 i = static_cast<s32>(field_68.m_itemCount - 1); i >= 0; i--) {
        ISiGfxImageSaver* pSaver = field_68.m_pData[i];
        if (pSaver->vf5(Unk_StringCStr(&name), nullptr)) {
            return pSaver;
        }
    }
    return nullptr;
}

// 0x71004d17f0: loads an image from a file with the first loader that takes
// it, the last one added first; the image gets the file's name and, if the
// options ask for one, another kind
bool SiGfxImageUtility::vf16(SiGfxImage* image, const char* path, const Unk_LoadOptions* options) {
    if (!Unk_582d80(path, true)) {
        return false;
    }
    for (s32 i = static_cast<s32>(field_18.m_itemCount - 1); i >= 0; i--) {
        ISiGfxImageLoader* pLoader = field_18.m_pData[i];
        if (pLoader->vf5(path, image) && pLoader->vf6(path, image, options)) {
            image->vf5(path);
            if (options->field_8 != 0) {
                image->vf26(options->field_8);
            }
            return true;
        }
    }
    return false;
}

// 0x71004d18d0: saves an image with the first saver that takes the file
bool SiGfxImageUtility::vf17(SiGfxImage* image, const char* path, const void* options) {
    for (s32 i = static_cast<s32>(field_68.m_itemCount - 1); i >= 0; i--) {
        ISiGfxImageSaver* pSaver = field_68.m_pData[i];
        if (pSaver->vf5(path, image) && pSaver->vf6(path, image, options)) {
            return true;
        }
    }
    return false;
}

// 0x71004d2280: fills a mip level of a 2D image with value noise (a sum of
// octaves, each at twice the frequency of the one before)
bool Unk_4d2280(SiGfxImage::ImageData2D* data, f32 scaleX, f32 scaleY, s32 octaves);

// 0x71004d1970: a 3D image isn't filled (the test that says so comes before
// its case). The kind's test is the last of the three: Reassociate puts it in
// front of the height's, which it is merged with (a test of the kind written
// first is merged with the width's instead, and moves in front of that).
bool SiGfxImageUtility::vf18(SiGfxImage* image, f32 scaleX, f32 scaleY, s32 octaves) {
    if (image == nullptr) {
        return false;
    }
    s32 kind = image->field_58.field_0;
    switch (kind) {
    case 2:
    case 3:
    case 4:
        break;
    default:
        return false;
    }
    if (image->field_58.field_8 < 1 || image->field_58.field_c < 1 || kind == 3) {
        return false;
    }
    switch (kind) {
    case 2:
        if (image->field_58.field_14 < 1) {
            return false;
        }
        return Unk_4d2280(image->vf17(0, 0), scaleX, scaleY, octaves);
    case 3:
        return Unk_4d1a70(image, scaleX, scaleY, octaves);
    case 4:
        return Unk_4d2110(image, scaleX, scaleY, octaves);
    }
    return false;
}

// 0x71004d2110: each face of the cube
bool SiGfxImageUtility::Unk_4d2110(SiGfxImage* image, f32 scaleX, f32 scaleY, s32 octaves) {
    if (image->field_58.field_14 < 1) {
        return false;
    }
    for (s32 face = 0; face < 6; face++) {
        if (!Unk_4d2280(image->vf18(0, face, 0), scaleX, scaleY, octaves)) {
            return false;
        }
    }
    return true;
}

// The value noise's helpers (placeholder names): a number from -1 to 1 for a
// lattice point, and the smooth step's weight
static inline f32 Unk_NoiseValue(s32 x, s32 y) {
    s32 n = x + y * 57;
    n = (n << 13) ^ n;
    return static_cast<f32>(1.0 - ((n * (n * n * 15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0);
}
static inline f32 Unk_NoiseWeight(f32 t) {
    return static_cast<f32>(t * t * 3.0 - 2.0 * pow(t, 3.0));
}

// NON_MATCHING: the same computation; the spill slots, the float registers
// and the order the four lattice values are hashed and weighted in differ
// (the original keeps 3.0 in d15 and the values at sp+0x40).
bool Unk_4d2280(SiGfxImage::ImageData2D* data, f32 frequency, f32 persistence, s32 octaves) {
    u8* pixels = data->field_0;
    if (pixels == nullptr) {
        return false;
    }
    s32 bpp = Unk_4ed0c0(data->field_10);
    s32 offsetX = static_cast<s32>(static_cast<f32>(rand()) * (1.0f / 2147483648.0f) * 5000.0f);
    s32 offsetY = static_cast<s32>(static_cast<f32>(rand()) * (1.0f / 2147483648.0f) * 5000.0f);
    for (s32 y = 0; y < data->field_18; y++) {
        for (s32 x = 0; x < data->field_14; x++) {
            f32 sum = 0.0f;
            f32 amplitude = 1.0f;
            f32 scale = frequency;
            for (s32 i = 0; i < octaves; i++) {
                f32 u = scale * static_cast<f32>(y + offsetY);
                f32 v = scale * static_cast<f32>(x + offsetX);
                s32 iu = static_cast<s32>(u);
                s32 iv = static_cast<s32>(v);
                f32 fu = u - static_cast<f32>(iu);
                f32 fv = v - static_cast<f32>(iv);
                f32 n11 = Unk_NoiseValue(iv + 1, iu + 1);
                f32 n01 = Unk_NoiseValue(iv + 1, iu);
                f32 n00 = Unk_NoiseValue(iv, iu);
                f32 n10 = Unk_NoiseValue(iv, iu + 1);
                f32 a = n00 * Unk_NoiseWeight(1.0f - fv) + n01 * Unk_NoiseWeight(fv);
                f32 b = n10 * Unk_NoiseWeight(1.0f - fv) + n11 * Unk_NoiseWeight(fv);
                sum += amplitude * (a * Unk_NoiseWeight(1.0f - fu) + b * Unk_NoiseWeight(fu));
                amplitude *= persistence;
                scale += scale;
            }
            f32 value = sum * 0.5f + 0.5f;
            value = value < 0.0f ? 0.0f : value;
            value = value > 1.0f ? 1.0f : value;
            f32 color[4] = {value, value, value, value};
            Unk_4ed4f0(data->field_10, pixels + x * bpp + y * bpp * data->field_14, color);
        }
    }
    return true;
}

}  // namespace SiSDK3
