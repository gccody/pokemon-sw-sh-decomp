// Scope: common
// SiSDK3::SiGfxTextureUtility: their functions, so far the constructor, the
// destructors and the reference counts their header defines.
#define UNK_SIGFX_TEXTUREUTILITY_IMPL
#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_TextureUtility_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Guid.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/BinaryArchive/Texture/SiGfx_BinaryChunk_Texture.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_Stream.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_BinaryArchive_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_Kernel_Impl.h>

// 0x710057d030: SiIO's kernel
u64 Unk_57d030_get();
// 0x71004c9b60: a platform's name, 0x71004c9b90: its byte order
const char* Unk_4c9b60(u32 platform);
u32 Unk_4c9b90_get(u32 platform);
// 0x71004cbae0: a path's extension; 0x71004c5630: two strings compared, with
// case or without; 0x71004ed080: the texture format of an image format
const char* Unk_4cbae0(const char* path, char* out, size_t size);
s64 Unk_4c5630(const char* a, const char* b, bool caseSensitive);
u32 Unk_4ed080(u32 value);
// 0x71004ed0c0: a format's bytes per pixel; 0x71004ed0f0: a compressed
// format's bytes per block; 0x71004ed120: whether a format is compressed
s32 Unk_4ed0c0(u32 format);
s32 Unk_4ed0f0(u32 format);
bool Unk_4ed120(u32 format);
// 0x71004efa70: a new texture chunk
SiSDK3::SiGfxTextureChunkHandler* Unk_4efa70(SiSDK3::ISiAllocator* pAllocator);
// 0x7101eec778: the texture chunk's identifier
extern const SiSDK3::ISiIOBinaryArchive::Unk_Id Unk_1eec778;

namespace SiSDK3 {

// 0x71004eabd0
SiGfxTextureUtility::SiGfxTextureUtility(ISiAllocator* pAllocator) : field_8(pAllocator) {}

// 0x71004eabf0 (D2), 0x71004eac10 (D0)
SiGfxTextureUtility::~SiGfxTextureUtility() {}

// 0x71004eac60
bool SiGfxTextureUtility::vf5(ISiInterface* texture, const char* path) {
    Unk_TextureDesc desc;
    return vf6(texture, &desc, path);
}

// 0x71004eadf0
bool SiGfxTextureUtility::vf6(ISiInterface* texture, const Unk_TextureDesc* desc, const char* path) {
    if (texture == nullptr) {
        return false;
    }
    return vf7(nullptr, &texture, desc, path);
}

// 0x71004eae50
bool SiGfxTextureUtility::vf7(void* device, ISiInterface** texture, const Unk_TextureDesc* desc, const char* path) {
    return vf8(device, texture, desc, path, nullptr, 0, 0);
}

// 0x71004eae70
bool SiGfxTextureUtility::vf8(void* device, ISiInterface** texture, const Unk_TextureDesc* desc, const char* path,
                              const char* cachePath, u32 platform, u32 a7) {
    if (texture == nullptr) {
        return false;
    }
    char extension[0x400];
    Unk_4cbae0(path, extension, sizeof(extension));
    if (Unk_4c5630(extension, "mb_tex", false) == 0) {
        return vf12(device, texture, desc, path);
    }
    SiGfxImage image(field_8.m_pAllocator);
    Unk_ImageReadOptions options(field_8.m_pAllocator);
    if (desc->field_e8.field_16) {
        options.field_4 = desc->field_e8.field_c.field_4;
    }
    if (!image.vf21(reinterpret_cast<u64>(path), &options)) {
        return false;
    }
    u32 kind = Unk_4ed080(image.field_58.field_0);
    s32 created;
    if (*texture != nullptr) {
        reinterpret_cast<ISiGfxTexture*>(*texture)->vf39(kind);
        if (reinterpret_cast<ISiGfxTexture*>(*texture)->vf19()->field_0 == kind) {
            created = 0;
        } else {
            const Unk_FaceCacheTextureInfo* info = reinterpret_cast<ISiGfxTexture*>(*texture)->vf19();
            if (kind != 3 || info->field_0 != 5) {
                return false;
            }
            created = 0;
        }
    } else {
        if (device == nullptr) {
            return false;
        }
        SiGfxNXDevice* pDevice = static_cast<SiGfxNXDevice*>(device);
        *texture = reinterpret_cast<ISiInterface*>(pDevice->vf49(kind, nullptr, 0, nullptr));
        if (*texture == nullptr) {
            return false;
        }
        created = 1;
    }
    SiGfxImage* converted = nullptr;
    if (!image.vf24(&converted, desc->field_e8)) {
        if (created != 0 && *texture != nullptr) {
            (*texture)->vf3();
            *texture = nullptr;
        }
        return false;
    }
    SiGfxImage* source = converted != nullptr ? converted : &image;
    Unk_TextureDesc textureDesc;
    textureDesc.field_0 = source->field_58.field_4;
    textureDesc.field_10 = source->field_58.field_8;
    textureDesc.field_14 = source->field_58.field_c;
    textureDesc.field_1c = source->field_58.field_14;
    textureDesc.field_30 = desc->field_30;
    textureDesc.field_34 = desc->field_34;
    textureDesc.field_38 = desc->field_38;
    textureDesc.field_3c = desc->field_3c;
    textureDesc.field_40 = desc->field_40;
    if (!reinterpret_cast<ISiGfxTexture*>(*texture)->vf23(&textureDesc, source)) {
        if (created != 0 && *texture != nullptr) {
            (*texture)->vf3();
            *texture = nullptr;
        }
        if (converted != nullptr) {
            converted->vf3();
            converted = nullptr;
        }
        return false;
    }
    if (cachePath != nullptr && created == 0 && cachePath[0] != 0) {
        source->vf5(Unk_StringCStr(reinterpret_cast<ISiGfxTexture*>(*texture)->vf46()));
        vf17(source, cachePath, platform, a7);
    }
    if (converted != nullptr) {
        converted->vf3();
        converted = nullptr;
    }
    return true;
}

// 0x71004eb370
bool SiGfxTextureUtility::vf9(ISiInterface* texture, void* a2, void* a3) {
    if (texture == nullptr) {
        return false;
    }
    Unk_TextureDesc desc;
    return vf13(nullptr, &texture, &desc, a2, a3);
}

// 0x71004eb520
bool SiGfxTextureUtility::vf10(void* device, void* a2, void* a3) {
    Unk_TextureDesc desc;
    return vf12(device, static_cast<ISiInterface**>(a2), &desc, static_cast<const char*>(a3));
}

// 0x71004eb6c0
bool SiGfxTextureUtility::vf11(void* device, ISiInterface** texture, void* a3, void* a4) {
    Unk_TextureDesc desc;
    return vf13(device, texture, &desc, a3, a4);
}

// 0x71004eb870
bool SiGfxTextureUtility::vf12(void* device, ISiInterface** texture, const Unk_TextureDesc* desc, const char* path) {
    if (texture == nullptr) {
        return false;
    }
    ISiIOStream* stream = reinterpret_cast<SiIOKernel*>(Unk_57d030_get())->vf9(path, 8, nullptr);
    if (stream == nullptr) {
        return false;
    }
    SiIOBinaryArchive* archive = reinterpret_cast<SiIOKernel*>(Unk_57d030_get())->vf12(nullptr);
    if (archive == nullptr) {
        stream->vf3();
        return false;
    }
    if (!archive->vf6(stream, 7)) {
        archive->vf3();
        stream->vf3();
        return false;
    }
    bool result = vf13(device, texture, desc, archive, nullptr);
    archive->vf8();
    archive->vf3();
    stream->vf3();
    return result;
}

// 0x71004eb990: the texture of an archive's chunk (the first texture chunk
// without an id), on the texture's device without one
bool SiGfxTextureUtility::vf13(void* device, ISiInterface** texture, const Unk_TextureDesc* desc, void* a4, void* a5) {
    if (texture == nullptr) {
        return false;
    }
    SiIOBinaryArchive* archive = static_cast<SiIOBinaryArchive*>(a4);
    ISiIOBinaryArchive::Unk_ChunkHeader* header = static_cast<ISiIOBinaryArchive::Unk_ChunkHeader*>(a5);
    if (header == nullptr) {
        header = archive->vf15(&Unk_1eec778, nullptr, false);
        if (header == nullptr) {
            return false;
        }
    } else if (!Unk_4c8f80(header, &Unk_1eec778)) {
        return false;
    }
    if (device == nullptr) {
        if (*texture == nullptr) {
            return false;
        }
        device = static_cast<Unk_TextureInterface*>(*texture)->vf5();
    }
    SiGfxTextureChunkHandler handler(field_8.m_pAllocator);
    handler.Unk_4f0f90(static_cast<SiGfxNXDevice*>(device), reinterpret_cast<ISiGfxTexture*>(*texture));
    handler.field_458 = desc->field_34;
    handler.field_45c = desc->field_38;
    handler.field_460 = desc->field_3c;
    if (!archive->vf17(header, &handler)) {
        archive->vf18();
        return false;
    }
    if (handler.field_470 != nullptr) {
        handler.field_470->vf2();
    }
    if (*texture != nullptr) {
        (*texture)->vf3();
    }
    *texture = reinterpret_cast<ISiInterface*>(handler.field_470);
    return true;
}

// 0x71004ebb20
bool SiGfxTextureUtility::vf17(void* texture, const char* path, u32 platform, u32 a4) {
    ISiIOBinaryArchive::ChunkHandler* chunk = vf18(static_cast<SiGfxImage*>(texture), platform);
    if (chunk == nullptr) {
        return false;
    }
    SiIOBinaryArchive* archive = reinterpret_cast<SiIOKernel*>(Unk_57d030_get())->vf12(nullptr);
    if (archive == nullptr) {
        return false;
    }
    archive->vf19();
    archive->vf21("SSKKArchive", "Texture", Unk_4c9b60(platform), Unk_4c9b90_get(platform));
    archive->vf22(chunk);
    archive->vf20();
    archive->vf26(a4);
    bool result = archive->vf23(path);
    archive->vf8();
    chunk->vf3();
    archive->vf3();
    return result;
}


// NON_MATCHING: 4 bytes longer, register allocation only: in the 3D image's
// case the original keeps the bytes per pixel in w23 and spills the width
// (this keeps the width in w20 and spills the bytes per pixel, so the 2D
// image's case shares its tail), and in the array's case it spills the width
// after the count's test, not before the calls. Tried: the locals' order,
// the sizes' types and operand orders, the loops' counters and the
// declarations' order (which placed the zeroed counters as the original's).
// 0x71004ebc60: the chunk of an image's texture: its name, the description
// and the pixels of each level (copied in the order the texture has them:
// the faces' or the images' levels one after the other). Only the 2D image's
// case gives up when an array can't be made bigger.
ISiIOBinaryArchive::ChunkHandler* SiGfxTextureUtility::vf18(SiGfxImage* image, u32 platform) {
    SiGfxTextureChunkHandler* handler = Unk_4efa70(field_8.m_pAllocator);
    if (handler == nullptr) {
        return nullptr;
    }
    Unk_4efb80* chunk = &handler->field_b8;
    static_cast<SiString<char>&>(chunk->field_0) = *image->vf6();
    s32 kind = image->field_58.field_0;
    u32 format = image->field_58.field_4;
    s32 width = image->field_58.field_8;
    s32 height = image->field_58.field_c;
    s32 depth = image->field_58.field_10;
    s32 mipCount = image->field_58.field_14;
    s32 count = image->field_58.field_18;
    switch (kind) {
    case 2: {
        if (!chunk->field_188.Unk_SetCount(image->field_78)) {
            return nullptr;
        }
        if (!chunk->field_1d8.Unk_SetCount(image->field_58.field_14)) {
            return nullptr;
        }
        s32 bpp = Unk_4ed0c0(format);
        s32 blockBytes = Unk_4ed120(format) ? Unk_4ed0f0(format) : 0;
        (void)blockBytes;
        size_t offset = 0;
        for (s32 level = 0; level < image->field_58.field_14; level++) {
            SiGfxImage::ImageData2D* data = image->vf17(0, level);
            SIGFX_TEXTURE_INITDATA* init = &chunk->field_1d8.m_pData[level];
            init->field_0 = chunk->field_188.m_pData + offset;
            init->field_14 = 0;
            s32 size;
            if (Unk_4ed120(format)) {
                s32 blocksWide = data->field_14 < 1 ? 1 : (data->field_14 + 3) / 4;
                s32 blocksHigh = data->field_18 < 1 ? 1 : (data->field_18 + 3) / 4;
                init->field_10 = Unk_4ed0f0(format) * blocksWide;
                size = init->field_10 * blocksHigh;
            } else {
                init->field_10 = data->field_14 * bpp;
                size = data->field_18 * init->field_10;
            }
            size_t n = static_cast<s64>(data->field_8) > size ? size : data->field_8;
            memcpy(init->field_0, data->field_0, n);
            init->field_8 = n;
            offset += n;
        }
        break;
    }
    case 3: {
        chunk->field_188.Unk_SetCount(image->field_78);
        chunk->field_1d8.Unk_SetCount(image->field_58.field_14);
        s32 bpp = Unk_4ed0c0(format);
        s32 blockBytes = Unk_4ed120(format) ? Unk_4ed0f0(format) : 0;
        (void)blockBytes;
        size_t offset = 0;
        for (s32 level = 0; level < image->field_58.field_14; level++) {
            SiGfxImage::ImageData3D* data = image->vf19(level);
            SIGFX_TEXTURE_INITDATA* init = &chunk->field_1d8.m_pData[level];
            init->field_0 = chunk->field_188.m_pData + offset;
            init->field_14 = 0;
            s32 size;
            if (Unk_4ed120(format)) {
                s32 blocksHigh = data->field_18 < 1 ? 1 : (data->field_18 + 3) / 4;
                s32 blocksWide = data->field_14 < 1 ? 1 : (data->field_14 + 3) / 4;
                init->field_10 = Unk_4ed0f0(format) * blocksWide;
                init->field_14 = init->field_10 * blocksHigh;
                size = init->field_14 * depth;
            } else {
                init->field_10 = data->field_14 * bpp;
                init->field_14 = data->field_18 * init->field_10;
                size = data->field_1c * init->field_14;
            }
            size_t n = static_cast<s64>(data->field_8) > size ? size : data->field_8;
            memcpy(init->field_0, data->field_0, n);
            init->field_8 = n;
            offset += n;
        }
        break;
    }
    case 4: {
        chunk->field_188.Unk_SetCount(image->field_78);
        chunk->field_1d8.Unk_SetCount(image->field_58.field_14 * 6);
        s32 bpp = Unk_4ed0c0(format);
        s32 blockBytes = Unk_4ed120(format) ? Unk_4ed0f0(format) : 0;
        (void)blockBytes;
        size_t offset = 0;
        s32 face = 0;
        s32 index = 0;
        for (; face < 6; face++) {
            for (s32 level = 0; level < image->field_58.field_14; level++) {
                SiGfxImage::ImageData2D* data = image->vf17(face, level);
                SIGFX_TEXTURE_INITDATA* init = &chunk->field_1d8.m_pData[index];
                init->field_0 = chunk->field_188.m_pData + offset;
                init->field_14 = 0;
                s32 size;
                if (Unk_4ed120(format)) {
                    s32 blocksWide = data->field_14 < 1 ? 1 : (data->field_14 + 3) / 4;
                    s32 blocksHigh = data->field_18 < 1 ? 1 : (data->field_18 + 3) / 4;
                    init->field_10 = Unk_4ed0f0(format) * blocksWide;
                    size = init->field_10 * blocksHigh;
                } else {
                    init->field_10 = data->field_14 * bpp;
                    size = data->field_18 * init->field_10;
                }
                size_t n = static_cast<s64>(data->field_8) > size ? size : data->field_8;
                memcpy(init->field_0, data->field_0, n);
                init->field_8 = n;
                offset += n;
                index++;
            }
        }
        break;
    }
    case 5: {
        chunk->field_188.Unk_SetCount(image->field_78);
        chunk->field_1d8.Unk_SetCount(image->field_58.field_14 * image->field_58.field_18);
        s32 bpp = Unk_4ed0c0(format);
        s32 blockBytes = Unk_4ed120(format) ? Unk_4ed0f0(format) : 0;
        (void)blockBytes;
        s32 index = 0;
        s32 i = 0;
        size_t offset = 0;
        for (; i < image->field_58.field_18; i++) {
            for (s32 level = 0; level < image->field_58.field_14; level++) {
                SiGfxImage::ImageData2D* data = image->vf17(i, level);
                SIGFX_TEXTURE_INITDATA* init = &chunk->field_1d8.m_pData[index];
                init->field_0 = chunk->field_188.m_pData + offset;
                init->field_14 = 0;
                s32 size;
                if (Unk_4ed120(format)) {
                    s32 blocksWide = data->field_14 < 1 ? 1 : (data->field_14 + 3) / 4;
                    s32 blocksHigh = data->field_18 < 1 ? 1 : (data->field_18 + 3) / 4;
                    init->field_10 = Unk_4ed0f0(format) * blocksWide;
                    size = init->field_10 * blocksHigh;
                } else {
                    init->field_10 = data->field_14 * bpp;
                    size = data->field_18 * init->field_10;
                }
                size_t n = static_cast<s64>(data->field_8) > size ? size : data->field_8;
                memcpy(init->field_0, data->field_0, n);
                init->field_8 = n;
                offset += n;
                index++;
            }
        }
        break;
    }
    case 6: {
        chunk->field_188.Unk_SetCount(image->field_78);
        chunk->field_1d8.Unk_SetCount(6 * image->field_58.field_14 * image->field_58.field_18);
        s32 bpp = Unk_4ed0c0(format);
        s32 blockBytes = Unk_4ed120(format) ? Unk_4ed0f0(format) : 0;
        (void)blockBytes;
        size_t offset = 0;
        s32 i = 0;
        s32 index = 0;
        for (; i < image->field_58.field_18 * 6; i++) {
            for (s32 level = 0; level < image->field_58.field_14; level++) {
                SiGfxImage::ImageData2D* data = image->vf17(i, level);
                SIGFX_TEXTURE_INITDATA* init = &chunk->field_1d8.m_pData[index];
                init->field_0 = chunk->field_188.m_pData + offset;
                init->field_14 = 0;
                s32 size;
                if (Unk_4ed120(format)) {
                    s32 blocksWide = data->field_14 < 1 ? 1 : (data->field_14 + 3) / 4;
                    s32 blocksHigh = data->field_18 < 1 ? 1 : (data->field_18 + 3) / 4;
                    init->field_10 = Unk_4ed0f0(format) * blocksWide;
                    size = init->field_10 * blocksHigh;
                } else {
                    init->field_10 = data->field_14 * bpp;
                    size = data->field_18 * init->field_10;
                }
                size_t n = static_cast<s64>(data->field_8) > size ? size : data->field_8;
                memcpy(init->field_0, data->field_0, n);
                init->field_8 = n;
                offset += n;
                index++;
            }
        }
        break;
    }
    }
    chunk->field_70 = Unk_4ed080(kind);
    chunk->field_78.field_0 = format;
    chunk->field_78.field_4 = format;
    chunk->field_78.field_10 = width;
    chunk->field_78.field_14 = height;
    chunk->field_78.field_18 = depth;
    chunk->field_78.field_1c = mipCount;
    chunk->field_78.field_20 = count;
    chunk->field_78.field_38 = 0;
    chunk->field_78.field_24 = 0;
    chunk->field_78.field_28 = 0;
    chunk->field_78.field_30 = 1;
    chunk->field_78.field_34 = 8;
    chunk->field_78.field_50 = static_cast<u32>(image->field_78);
    chunk->field_78.field_54 = static_cast<u32>(chunk->field_1d8.m_itemCount);
    return handler;
}

}  // namespace SiSDK3

// 0x71004ec920: the reserve of the levels' array (vf18 and SiGfxNXTexture's
// slot 23 call it)
template bool SiSDK3::SiArray<SiSDK3::SIGFX_TEXTURE_INITDATA, 16>::Unk_4bf190(size_t, bool);
