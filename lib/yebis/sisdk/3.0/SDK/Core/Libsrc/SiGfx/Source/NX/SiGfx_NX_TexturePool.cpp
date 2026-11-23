// Scope: common
// SiSDK3::SiGfxNXTexturePool: the function that makes a texture and its slot
// 7 and the device's own textures (the pool's constructor, destructor and
// other slots are in Unk_Pools.cpp).
// (the pools' header first: it keeps SiCore_Pool.h's member definitions,
// which the original doesn't inline here, out of this translation unit)
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_Pools.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Texture_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiGfx/Image/SiGfx_Image.h>

// 0x710055f1c0 (leafgen's name and type): the texture's index in its pool
struct Unk_55f1c0;
bool Unk_55f1c0_update(Unk_55f1c0* self, u64 value);

namespace SiSDK3 {

// 0x710055d6c0: under the name and type the device's translation unit calls
// it by (the pointer is the index of the pool's item to take, 0 for any).
SiGfxNXTexture* Unk_55d6c0(SiGfxNXTexturePool* pool, ISiAllocator* pAllocator, u32 kind, const void* index) {
    Unk_596640 lock(pool->field_18.Unk_Get(), true);
    SiGfxResourcePool::ResourceItem* item;
    if (index != nullptr) {
        item = pool->field_48.Unk_4fef10(reinterpret_cast<size_t>(index));
    } else {
        item = pool->field_48.Unk_Alloc();
    }
    if (item == nullptr) {
        return nullptr;
    }
#line 127
    SiGfxNXTexture* texture = UNK_SI_NEW(pAllocator, 0x10) SiGfxNXTexture(pAllocator, pool->field_178, kind);
    if (texture == nullptr) {
        pool->field_48.Unk_4be3f0(item);
        return nullptr;
    }
    if (!Unk_55f1c0_update(reinterpret_cast<Unk_55f1c0*>(texture), item->field_10)) {
        pool->field_48.Unk_4be3f0(item);
        return nullptr;
    }
    item->field_20 = reinterpret_cast<Unk_534460_Resource*>(texture);
    s32 number = static_cast<s32>(pool->field_48.m_usedList.m_count);
    if (Unk_NXDevice(pool->field_178)->vf11()->field_b5) {
        char name[0x80];
        Unk_4c5a90(name, sizeof(name), "Texture_%d", number);
        texture->vf45(name);
    }
    return texture;
}

// 0x710055d8c0
void SiGfxNXTexturePool::vf7() {
    if (Unk_NXDevice(field_178)->vf11()->field_52) {
        Unk_55d900();
    }
    SiGfxResourcePool::vf7();
}

// 0x71004f4390 (SiGfx_Image.cpp): an image of noise
SiGfxImage* Unk_4f4390(s32 width, s32 height, s32 octaves, bool noMips);

// 0x710055d900: the device's own textures (a pixel of black, white, grey and
// a flat normal, black and white cubes, noise, a black array)
void SiGfxNXTexturePool::Unk_55d900() {
    ISiAllocator* pAllocator = field_8.m_pAllocator;
    SiGfxNXTexture* pTexture = Unk_55d6c0(this, pAllocator, 2, reinterpret_cast<const void*>(1));
    if (pTexture != nullptr) {
        SiGfxNXTexture::Unk_Desc desc(0x1c, 1, 1, 0, 1, 1, 1);
        u32 pixel = 0;
        SiGfxNXTexture::Unk_LevelData level;
        level.field_0 = &pixel;
        level.field_8 = 4;
        level.field_10 = 4;
        level.field_14 = 0;
        desc.field_50 = 4;
        desc.field_54 = 1;
        desc.field_60 = &level;
        pTexture->vf22(&desc);
        pTexture->vf45("BlackTexture");
    }
    pTexture = Unk_55d6c0(this, pAllocator, 2, reinterpret_cast<const void*>(2));
    if (pTexture != nullptr) {
        SiGfxNXTexture::Unk_Desc desc(0x1c, 1, 1, 0, 1, 1, 1);
        u32 pixel = 0xffffffff;
        SiGfxNXTexture::Unk_LevelData level;
        level.field_0 = &pixel;
        level.field_8 = 4;
        level.field_10 = 4;
        level.field_14 = 0;
        desc.field_50 = 4;
        desc.field_54 = 1;
        desc.field_60 = &level;
        pTexture->vf22(&desc);
        pTexture->vf45("WhiteTexture");
    }
    pTexture = Unk_55d6c0(this, pAllocator, 2, reinterpret_cast<const void*>(3));
    if (pTexture != nullptr) {
        SiGfxNXTexture::Unk_Desc desc(0x1c, 1, 1, 0, 1, 1, 1);
        u32 pixel = 0x80808080;
        SiGfxNXTexture::Unk_LevelData level;
        level.field_0 = &pixel;
        level.field_8 = 4;
        level.field_10 = 4;
        level.field_14 = 0;
        desc.field_50 = 4;
        desc.field_54 = 1;
        desc.field_60 = &level;
        pTexture->vf22(&desc);
        pTexture->vf45("GreyTexture");
    }
    pTexture = Unk_55d6c0(this, pAllocator, 2, reinterpret_cast<const void*>(4));
    if (pTexture != nullptr) {
        SiGfxNXTexture::Unk_Desc desc(0x1c, 1, 1, 0, 1, 1, 1);
        u32 pixel = 0xffff8080;
        SiGfxNXTexture::Unk_LevelData level;
        level.field_0 = &pixel;
        level.field_8 = 4;
        level.field_10 = 4;
        level.field_14 = 0;
        desc.field_50 = 4;
        desc.field_54 = 1;
        desc.field_60 = &level;
        pTexture->vf22(&desc);
        pTexture->vf45("FlatNormalTexture");
    }
    pTexture = Unk_55d6c0(this, field_8.m_pAllocator, 4, reinterpret_cast<const void*>(5));
    if (pTexture != nullptr) {
        SiGfxNXTexture::Unk_Desc desc(0x1c, 1, 1, 0, 1, 1, 1);
        u32 pixels[6];
        SiGfxNXTexture::Unk_LevelData levels[6];
        for (s32 i = 0; i < 6; i++) {
            pixels[i] = 0;
            levels[i].field_0 = &pixels[i];
            levels[i].field_10 = 4;
            levels[i].field_8 = 4;
            levels[i].field_14 = 0;
        }
        desc.field_50 = sizeof(pixels);
        desc.field_54 = 6;
        desc.field_60 = levels;
        pTexture->vf22(&desc);
        pTexture->vf45("BlackCubeTexture");
    }
    pTexture = Unk_55d6c0(this, pAllocator, 4, reinterpret_cast<const void*>(6));
    if (pTexture != nullptr) {
        SiGfxNXTexture::Unk_Desc desc(0x1c, 1, 1, 0, 1, 1, 1);
        u32 pixels[6];
        SiGfxNXTexture::Unk_LevelData levels[6];
        for (s32 i = 0; i < 6; i++) {
            pixels[i] = 0xffffffff;
            levels[i].field_0 = &pixels[i];
            levels[i].field_10 = 4;
            levels[i].field_8 = 4;
            levels[i].field_14 = 0;
        }
        desc.field_50 = sizeof(pixels);
        desc.field_54 = 6;
        desc.field_60 = levels;
        pTexture->vf22(&desc);
        pTexture->vf45("WhiteCubeTexture");
    }
    pTexture = Unk_55d6c0(this, pAllocator, 2, reinterpret_cast<const void*>(7));
    if (pTexture != nullptr) {
        SiGfxImage* pImage = Unk_4f4390(0x200, 0x200, 8, false);
        SiGfxImage::ImageData2D* data = pImage->vf17(0, 0);
        SiGfxNXTexture::Unk_Desc desc(0x3d, 0x200, 0x200, 0, 1, 1, 1);
        SiGfxNXTexture::Unk_LevelData level = SiGfxNXTexture::Unk_LevelData();
        level.field_0 = data->field_0;
        level.field_10 = data->field_1c;
        level.field_8 = data->field_8;
        desc.field_50 = static_cast<u32>(level.field_8);
        desc.field_60 = &level;
        level.field_14 = 0;
        desc.field_54 = 1;
        pTexture->vf22(&desc);
        pTexture->vf45("PerlinNoiseTexture");
        if (pImage != nullptr) {
            pImage->vf3();
        }
    }
    pTexture = Unk_55d6c0(this, pAllocator, 5, reinterpret_cast<const void*>(8));
    if (pTexture != nullptr) {
        SiGfxNXTexture::Unk_Desc desc(0x1c, 1, 1, 0, 1, 1, 1);
        u32 pixel = 0;
        SiGfxNXTexture::Unk_LevelData level;
        level.field_0 = &pixel;
        level.field_8 = 4;
        level.field_10 = 4;
        level.field_14 = 0;
        desc.field_50 = 4;
        desc.field_54 = 1;
        desc.field_60 = &level;
        pTexture->vf22(&desc);
        pTexture->vf45("BlackTextureArray");
    }
}

}  // namespace SiSDK3
