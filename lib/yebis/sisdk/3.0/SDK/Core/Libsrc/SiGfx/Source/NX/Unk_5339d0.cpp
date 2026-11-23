// Scope: common
// SiSDK3::SiGfxNXFreeTypeFaceCache (SiGfx_FreeType_FaceCache.h): its
// construction, destruction and slots. A placeholder file name: the
// translation unit's isn't in the executable. (Slot 7 is lib/yebis/class's.)
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_FreeType_FaceCache.h>

namespace SiSDK3 {

// 0x71005339d0
SiGfxNXFreeTypeFaceCache::SiGfxNXFreeTypeFaceCache(SiGfxNXDevice* pDevice)
    : SiGfxFreeTypeFaceCache(pDevice->Unk_Allocator(), pDevice) {}

// 0x7100533a10 (D2), 0x7100533a90 (D0)
SiGfxNXFreeTypeFaceCache::~SiGfxNXFreeTypeFaceCache() {
    Unk_Release();
}

// 0x7100533b10
bool SiGfxNXFreeTypeFaceCache::vf5(u32 width, u32 height) {
    field_30 = field_18->vf49(2, nullptr, 0, nullptr);
    if (field_30 == nullptr) {
        return false;
    }
    SiGfxNXTexture::Unk_Desc desc(0x3d, width, height, 0, 1, 0, 2, 0x30000);
    desc.field_40 = 8;
    if (!field_30->vf22(&desc)) {
        if (field_30 != nullptr) {
            field_30->vf3();
            field_30 = nullptr;
        }
        return false;
    }
    field_1c0.vf2(width, height, 0x1000);
    ISiGfxDescriptorTable* table = field_18->vf27(1, 0, nullptr);
    table->vf8(1, 0);
    table->vf10(1);
    table->vf12(0, field_30);
    table->vf9();
    field_38 = table;
    return true;
}

// 0x7100533da0
void SiGfxNXFreeTypeFaceCache::vf6() {
    Unk_Release();
}

// 0x7100533e10
// NON_MATCHING: as the base's slot 8 (SiGfx_FreeType_FaceCache.cpp): the
// pixel modes' tests come out the other way round (the original compares 2
// first and lays the one-bit loop out first). The source pointer is read
// before the destination's address is computed (the original's registers).
// Tried: the two cases swapped, nested, as a switch in both orders with and
// without a default, `!=` forms, five forms of the first test.
bool SiGfxNXFreeTypeFaceCache::vf8(SiGfxFreeTypeGlyph* glyph, const Unk_FTBitmap* bitmap, SiGfxImage* image) {
    if (bitmap->field_1a != 1 && bitmap->field_1a != 2) {
        return false;
    }
    if (bitmap->field_10 == nullptr) {
        return false;
    }
    SiGfxNXTexture* pTexture = reinterpret_cast<SiGfxNXTexture*>(field_30);
    u8* pixels = static_cast<u8*>(pTexture->Unk_561e10());
    s64 width = field_30->vf19()->field_14;
    const u8* src = bitmap->field_10;
    u8* dst = pixels + glyph->field_70 + glyph->field_74 * width;
    if (bitmap->field_1a == 1) {
        s32 stride = glyph->field_78;
        for (u32 y = 0; y < bitmap->field_0; y++) {
            u8 mask = 0x80;
            for (u32 x = 0; x < bitmap->field_4; x++) {
                dst[x] = (*src & mask) != 0 ? 0xff : 0;
                mask >>= 1;
                if (mask == 0) {
                    mask = 0x80;
                    src++;
                }
            }
            dst += stride;
            src = bitmap->field_10 + bitmap->field_8 * y;
        }
    } else if (bitmap->field_1a == 2) {
        for (u32 y = 0; y < bitmap->field_0; y++) {
            memcpy(dst, src, bitmap->field_4);
            src += bitmap->field_8;
            dst += width;
        }
    }
    pTexture->Unk_561e50();
    return true;
}

}  // namespace SiSDK3
