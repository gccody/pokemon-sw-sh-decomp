// Scope: common
// SiSDK3::SiGfxTextureUtility: their functions, so far the constructor, the
// destructors and the reference counts their header defines.
#define UNK_SIGFX_TEXTUREUTILITY_IMPL
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
    ISiIOBinaryArchive::ChunkHandler* chunk = vf18(texture, platform);
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

}  // namespace SiSDK3

// 0x71004ec920: the reserve of the levels' array (vf18 and SiGfxNXTexture's
// slot 23 call it)
template bool SiSDK3::SiArray<SiSDK3::SIGFX_TEXTURE_INITDATA, 16>::Unk_4bf190(size_t, bool);
