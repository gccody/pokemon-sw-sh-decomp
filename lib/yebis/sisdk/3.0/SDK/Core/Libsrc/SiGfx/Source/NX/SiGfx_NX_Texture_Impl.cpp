// Scope: common
// SiSDK3::SiGfxNXTexture: its construction and destruction, its name, its
// class's GUID, the functions that make its surfaces and volumes, the
// accessors of its surfaces, volumes and views, and the reference counts its
// header defines. (Most of the functions that make it aren't written yet; its
// other small accessors are lib/yebis/class's.)
#define UNK_SIGFX_NX_TEXTURE_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Texture_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/BinaryArchive/Texture/SiGfx_BinaryChunk_Texture.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_CommandList_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_CommandQueue_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_ShaderProgram_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Alloc.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

// 0x71004ed080: SiGfx's kind of texture for a kind of image
// (SiGfx_Utility.cpp)
u32 Unk_4ed080(u32 value);

// 0x71004fb360 (leafgen's name and type: the device and an NVN command buffer)
struct Unk_4fb360;
void Unk_4fb360_update(const Unk_4fb360* self, u64 value);

// (the reserve is SiGfx_TextureUtility_Impl.cpp's)
extern template bool SiSDK3::SiArray<SiSDK3::SIGFX_TEXTURE_INITDATA, 16>::Unk_4bf190(size_t count, bool keep);

// nvn.h declares these three without their types
inline int Unk_nvnTextureGetFlags(const void* texture) {
    return reinterpret_cast<int (*)(const void*)>(Unk_27fcce0)(texture);
}
inline NvnBoolean Unk_nvnTextureViewGetDepthStencilMode(const void* view, int* mode) {
    return reinterpret_cast<NvnBoolean (*)(const void*, int*)>(Unk_27fcc98)(view, mode);
}
inline NvnBoolean Unk_nvnTextureViewGetFormat(const void* view, int* format) {
    return reinterpret_cast<NvnBoolean (*)(const void*, int*)>(Unk_27fcc88)(view, format);
}

inline s64 Unk_nvnTextureBuilderGetStride(const void* builder) {
    return reinterpret_cast<s64 (*)(const void*)>(Unk_27fcc08)(builder);
}

// 0x7100563270: sets an NVN texture builder up for a texture of a kind from
// its description (Unk_562ee0.cpp's type: the texture's description)
struct Unk_563270_Desc;
void Unk_563270(void* device, s32 kind, const Unk_563270_Desc* desc, void* builder);

// 0x71004ed1a0, 0x71004ed200, 0x71004ed300: how many levels a 1D, 2D or 3D
// texture of a size has, down to a minimum size (SiGfx_Utility.cpp)
s32 Unk_4ed1a0(s32 size, s32 minSize);
s32 Unk_4ed200(s32 width, s32 height, s32 minWidth, s32 minHeight);
s32 Unk_4ed300(s32 width, s32 height, s32 depth, s32 minWidth, s32 minHeight, s32 minDepth);

// 0x7100562f10: an NVN texture format as SiGfx numbers it
u32 Unk_562f10(u32 format);
// 0x71004ed0f0: a format's block's size, 0x71004ed120: whether it's one of
// blocks, 0x71004ed6e0
s32 Unk_4ed0f0(u32 format);
bool Unk_4ed120(u32 format);
bool Unk_4ed6e0(u32 format);

// 0x71004c8f80: whether two GUIDs are the same
bool Unk_4c8f80(const void* a, const void* b);
// 0x7101f0028c: the texture class's GUID (placeholder type)
extern u8 Unk_1f0028c;

namespace SiSDK3 {

// 0x710055f1e0 (0x710055f250: its thunk)
bool SiGfxNXTexture::vf45(const char* name) {
    Unk_4c4700(&field_38, const_cast<char*>(name));
    field_a8 = Unk_4c3510(&field_38);
    if (field_328 != nullptr) {
        nvnTextureSetDebugLabel(field_328, Unk_StringCStr(&field_38));
    }
    return true;
}

// 0x710055f2c0 (0x710055f2d0: its thunk)
const SiString<char>* SiGfxNXTexture::vf46() {
    return &field_38;
}

// 0x710055f2e0 (0x710055f2f0: its thunk)
u32 SiGfxNXTexture::vf47() {
    return field_a8;
}

// NVN's objects as the texture allocates them (placeholder names): a texture
// and a texture view.
struct Unk_NXTextureNVNTexture {
    u64 field_0[24];
};
struct Unk_NXTextureNVNView {
    u64 field_0[5];
};

// 0x710055f3d0: a description that names files is only kept; otherwise the
// NVN texture is made in memory of its own heap (or the one the description
// gives), filled with the description's pixels, with a view of each level and
// layer. The NVN texture builder is a block's local: the null test of the view
// that follows it returns without the builder's lifetime end, as the
// original's direct branch to the return shows (AArch64's redundant copy
// elimination then drops the zero move). The test for the files is a bool
// local (without it the branch to the copy comes out inverted), and the
// pixels' loop has a guard of its own (`cmp #1; b.lt`).
bool SiGfxNXTexture::vf22(Unk_Desc* desc) {
    bool files = desc->field_88.field_10 != 0 || desc->field_b8.field_10 != 0;
    if (files) {
        field_b0 = *desc;
    } else {
        field_b0.Unk_55ffd0();
        field_451 = false;
        void* device = reinterpret_cast<void*>(field_28->vf85());
#line 298
        field_328 = UNK_SI_NEW(field_18.m_pAllocator, 0x10) Unk_NXTextureNVNTexture;
        if (field_328 == nullptr) {
            return false;
        }
        u32 flags = Unk_563620(1, desc->field_30, desc->field_34, desc->field_38);
        if (desc->field_34 & 0x4020) {
            if (desc->field_40 != 8) {
                flags |= 0x80;
            }
        }
        s32 width = static_cast<s32>(desc->field_10) > 1 ? desc->field_10 : 1;
        s32 height = static_cast<s32>(desc->field_14) > 1 ? desc->field_14 : 1;
        s32 depth = static_cast<s32>(desc->field_18) > 1 ? desc->field_18 : 1;
        s32 levels = desc->field_1c;
        if (levels == 0) {
            switch (field_1d4) {
            case 1:
                levels = Unk_4ed1a0(desc->field_10, 0);
                break;
            case 3:
                levels = Unk_4ed300(desc->field_10, desc->field_14, desc->field_18, 0, 0, 0);
                break;
            default:
                levels = Unk_4ed200(desc->field_10, desc->field_14, 0, 0);
                break;
            }
            desc->field_1c = levels;
        }
        {
            u64 builder[16] = {};  // NVNtextureBuilder
            Unk_563270(device, field_1d4, reinterpret_cast<const Unk_563270_Desc*>(desc), builder);
            for (s32 i = 0; i < 8; i++) {
                if (desc->field_48.field_0[i] != 0) {
                    nvnTextureBuilderSetPackagedTextureLayout(builder, &desc->field_48);
                    break;
                }
            }
            size_t size = nvnTextureBuilderGetStorageSize(builder);
            size_t alignment = nvnTextureBuilderGetStorageAlignment(builder);
            field_438 = desc->field_80;
            if (field_438 != nullptr) {
                field_438->vf2();
            }
            size_t poolSize = Unk_NXAlign(size, alignment);
            if (field_438 == nullptr) {
                field_438 = vf5()->vf30(0, nullptr);
                Unk_NXMemoryHeapDesc heapDesc(poolSize);
                heapDesc.field_24 = 1;
                heapDesc.field_1c = desc->field_38;
                heapDesc.field_10 = desc->field_30;
                heapDesc.field_30 = flags;
                u8* buffer = nullptr;
                if (static_cast<s32>(desc->field_50) >= 1 && desc->field_60 != nullptr &&
                    static_cast<const SIGFX_TEXTURE_INITDATA*>(desc->field_60)->field_0 != nullptr) {
#line 410
                    buffer = static_cast<u8*>(UNK_ALLOC(field_18.m_pAllocator, static_cast<s32>(poolSize)));
                    memset(buffer, 0, static_cast<s32>(poolSize));
                    if (desc->field_40 == 8) {
                        s32 stride = Unk_nvnTextureBuilderGetStride(builder);
                        u8* dst = buffer;
                        if (static_cast<s32>(desc->field_54) >= 1) {
                            for (s32 i = 0; i < static_cast<s32>(desc->field_54); i++) {
                                const SIGFX_TEXTURE_INITDATA* data =
                                    &static_cast<const SIGFX_TEXTURE_INITDATA*>(desc->field_60)[i];
                                s32 rows = static_cast<s32>(data->field_8) / static_cast<s32>(data->field_10);
                                heapDesc.field_34 += rows * stride;
                                for (s32 row = 0; row < rows; row++) {
                                    s32 pitch = data->field_10;
                                    s64 offset = pitch * row;
                                    memcpy(dst, &data->field_0[offset], pitch);
                                    dst += stride;
                                }
                            }
                        }
                        heapDesc.field_34 = poolSize;
                        heapDesc.field_40 = buffer;
                    } else {
                        heapDesc.field_34 = desc->field_50;
                        heapDesc.field_40 = static_cast<const SIGFX_TEXTURE_INITDATA*>(desc->field_60)->field_0;
                    }
                }
                if (!field_438->vf8(&heapDesc)) {
                    return false;
                }
                if (buffer != nullptr) {
#line 448
                    UNK_FREE(field_18.m_pAllocator, buffer);
                }
            }
            if (!field_438->Unk_552fc0(static_cast<s32>(poolSize), alignment, &field_440)) {
                return false;
            }
            field_448 = Unk_NXAlign(field_440, alignment);
            nvnTextureBuilderSetStorage(builder, field_438->vf16(), field_448);
            if (nvnTextureInitialize(field_328, builder) != 1) {
                return false;
            }
        }
        s32 levelCount = nvnTextureGetLevels(field_328);
#line 471
        field_330 = reinterpret_cast<u64>(UNK_SI_NEW(field_18.m_pAllocator, 0x10) Unk_NXTextureNVNView);
        if (field_330 == 0) {
            return false;
        }
        nvnTextureViewSetDefaults(reinterpret_cast<void*>(field_330));
        nvnTextureViewSetLevels(reinterpret_cast<void*>(field_330), 0, levelCount);
        nvnTextureViewSetFormat(reinterpret_cast<void*>(field_330), nvnTextureGetFormat(field_328));
        if (field_1d4 != 3) {
            nvnTextureViewSetLayers(reinterpret_cast<void*>(field_330), 0, nvnTextureGetDepth(field_328));
        }
        if (desc->field_34 & 0x4000) {
            nvnTextureViewSetDepthStencilMode(reinterpret_cast<void*>(field_330), 0);
        }
        nvnTextureViewSetTarget(reinterpret_cast<void*>(field_330), nvnTextureGetTarget(field_328));
        field_338 = field_28->Unk_4fb1d0(reinterpret_cast<u64>(field_328), field_330);
        if (field_338 == -1) {
            return false;
        }
        if (desc->field_34 & 0x8000) {
            field_340 = nvnDeviceGetImageHandle(device, field_338);
        }
        s32 layers = static_cast<s32>(desc->field_20) > 1 ? desc->field_20 : 1;
        if (field_1d4 == 4 || field_1d4 == 6) {
            layers *= 6;
        }
        s32 count = layers * levelCount;
        field_348.Unk_SetCount(count);
        if (count == 1) {
            field_348.m_pData[0] = reinterpret_cast<NVNtextureView*>(field_330);
        } else {
            for (s32 i = 0; i < count; i++) {
#line 532
                field_348.m_pData[i] =
                    reinterpret_cast<NVNtextureView*>(UNK_SI_NEW(field_18.m_pAllocator, 0x10) Unk_NXTextureNVNView);
                s32 layer = i / levelCount;
                s32 level = i % levelCount;
                nvnTextureViewSetDefaults(field_348.m_pData[i]);
                nvnTextureViewSetFormat(field_348.m_pData[i], nvnTextureGetFormat(field_328));
                if (desc->field_34 & 0x4000) {
                    nvnTextureViewSetDepthStencilMode(field_348.m_pData[i], 0);
                }
                if (field_1d4 != 3) {
                    nvnTextureViewSetLayers(field_348.m_pData[i], layer, 1);
                }
                nvnTextureViewSetTarget(field_348.m_pData[i], nvnTextureGetTarget(field_328));
                nvnTextureViewSetLevels(field_348.m_pData[i], level, 1);
            }
        }
        field_450 = true;
        field_1f8 = static_cast<s32>(desc->field_20) > 1 ? desc->field_20 : 1;
        if (field_1d4 == 4 || field_1d4 == 6) {
            field_1f8 *= 6;
        }
        field_1d8 = desc->field_0;
        field_1dc = desc->field_4;
        field_1e4 = desc->field_c;
        field_1e0 = desc->field_8;
        field_1e8 = width;
        field_1ec = height;
        field_1f0 = depth;
        field_20c = true;
        field_208 = desc->field_28;
        field_204 = desc->field_24;
        field_1f4 = levels;
        field_21c = desc->field_40;
        field_20e = Unk_4ed120(field_1d8);
        if (field_20e) {
            field_210 = (width + 3) / 4;
            field_214 = (height + 3) / 4;
            field_218 = Unk_4ed0f0(field_1d8);
        } else {
            field_210 = 0;
            field_214 = 0;
            field_218 = 0;
        }
        field_450 = true;
        field_230 = static_cast<s32>(desc->field_20) > 1 ? desc->field_20 : 1;
        field_22c = field_1f4;
        field_1c8 = desc->field_34;
        field_1cc = desc->field_38;
        field_1d0 = desc->field_3c;
        field_1c4 = desc->field_30;
        field_1c0 = 1;
        if (field_3e8.m_itemCount == 0 && (desc->field_3c & 1)) {
            field_3e8.Unk_SetCount(field_348.m_itemCount);
            field_398.Unk_SetCount(field_348.m_itemCount);
            for (s64 i = 0; i < static_cast<s32>(field_348.m_itemCount); i++) {
                field_398.m_pData[i] =
                    field_28->Unk_4fb200(reinterpret_cast<u64>(field_328), reinterpret_cast<u64>(field_348.m_pData[i]));
                field_3e8.m_pData[i] =
                    nvnDeviceGetImageHandle(reinterpret_cast<void*>(field_28->vf85()), field_398.m_pData[i]);
            }
        }
        if (!Unk_5601b0()) {
            return false;
        }
        if (field_328 != nullptr) {
            nvnTextureSetDebugLabel(field_328, Unk_StringCStr(&field_38));
        }
    }
    return true;
}

// NON_MATCHING: the copy is inline now (the pairs at 0x68 and 0x70 split the
// trivially copied members), but the original copies the pairs from the
// temporary where this stores their zeros directly, and the stores of the
// blocks before them come in another order (4 bytes, 27 instructions off).
// 0x710055ffd0
void SiGfxNXTexture::Unk_Desc::Unk_55ffd0() {
    *this = Unk_Desc();
}

// 0x7100560e10: what it is cleared (the zero, then the one, stored at 0x1c0:
// the zeros of 0x1c0 to 0x1cc are one memset that stops at the one) and what
// it was made with released
void SiGfxNXTexture::vf24() {
    field_1c0 = 0;
    field_1c4 = 0;
    field_1c8 = 0;
    field_1cc = 0;
    field_1c0 = 1;
    field_1d0 = 0;
    field_1d8 = 0;
    field_1e8 = 0;
    field_1ec = 0;
    field_1f0 = 0;
    field_1f4 = 0;
    field_1f8 = 0;
    field_204 = 0;
    field_208 = 0;
    field_20e = false;
    field_210 = 0;
    field_214 = 0;
    field_218 = 0;
    if (field_28 != nullptr) {
        for (s64 i = 0; i < static_cast<s32>(field_398.m_itemCount); i++) {
            field_28->Unk_4fb290(field_398.m_pData[i]);
        }
        if (field_338 != -1) {
            field_28->Unk_4fb290(field_338);
            field_338 = -1;
        }
    }
    if (field_451) {
        field_330 = 0;
        field_328 = nullptr;
    } else {
        if (field_450) {
            nvnTextureFinalize(field_328);
            if (field_328 != nullptr) {
#line 877
                UNK_FREE(field_18.m_pAllocator, field_328);
            }
            if (field_330 != 0) {
#line 878
                UNK_FREE(field_18.m_pAllocator, reinterpret_cast<void*&>(field_330));
            }
            if (field_348.m_itemCount > 1) {
                for (s64 i = 0; i < static_cast<s32>(field_348.m_itemCount); i++) {
                    if (field_348.m_pData[i] != nullptr) {
                        if (field_18.m_pAllocator != nullptr) {
#line 886
                            SI_FREE(field_18.m_pAllocator, field_348.m_pData[i]);
                        }
                        field_348.m_pData[i] = nullptr;
                    }
                }
            }
            field_450 = false;
        }
        if (field_438 != nullptr) {
            field_438->Unk_553010(field_440);
            field_448 = 0;
            field_440 = 0;
            if (field_438 != nullptr) {
                field_438->vf3();
                field_438 = nullptr;
            }
            field_438 = nullptr;
        }
    }
    field_450 = false;
    field_451 = false;
    if (field_318 != nullptr) {
        field_318->vf3();
        field_318 = nullptr;
    }
}

// 0x7100561040
SiGfxNXSurface* SiGfxNXTexture::vf25(s32 level) {
    u32 kind = field_1d4;
    if (level < 0 || kind == 3) {
        return nullptr;
    }
    if (field_22c <= level) {
        return nullptr;
    }
    return &field_238.m_pData[level];
}

// 0x7100561080
SiGfxNXSurface* SiGfxNXTexture::vf26(s32 layer, s32 level) {
    u32 kind = field_1d4;
    if (level < 0 || kind != 4) {
        return nullptr;
    }
    if (field_22c <= level) {
        return nullptr;
    }
    return &field_238.m_pData[field_22c * layer + level];
}

// 0x71005610c0
SiGfxNXSurface* SiGfxNXTexture::vf27(s32 layer, s32 level) {
    if (field_1d4 != 5 && field_1d4 != 2) {
        return nullptr;
    }
    s32 layers = field_230;
    if (layer < 0 || layers <= layer || level < 0) {
        return nullptr;
    }
    if (field_22c <= level) {
        return nullptr;
    }
    return &field_238.m_pData[field_22c * layer + level];
}

// 0x7100561120
SiGfxNXSurface* SiGfxNXTexture::vf28(s32 layer, s32 face, s32 level) {
    if (field_1d4 != 4 && field_1d4 != 6) {
        return nullptr;
    }
    s32 layers = field_230;
    if (layer < 0 || layers <= layer || level < 0) {
        return nullptr;
    }
    if (field_22c <= level) {
        return nullptr;
    }
    s32 index = field_22c * (layer * 6 + face) + level;
    return &field_238.m_pData[index];
}

// 0x7100561190
SiGfxNXVolume* SiGfxNXTexture::vf29(s32 level) {
    u32 kind = field_1d4;
    if (level < 0 || kind != 3) {
        return nullptr;
    }
    if (field_22c <= level) {
        return nullptr;
    }
    return &field_288.m_pData[level];
}

// NON_MATCHING: the original keeps the address of the views' count
// (this + 0x358) in a register and a stack slot from the start to the last
// loop, one value more than here: its callee-saved registers and stack
// slots are shifted by one (the frame is 0xa0, here 0x90); the code is
// otherwise the original's.
// 0x71005611d0
bool SiGfxNXTexture::vf30(Unk_NXTextureDrawContext* pContext) {
    void* commandBuffer = pContext->vf102();
    SiGfxNXCommandList* pList = nullptr;
    SiGfxNXCommandQueue* pQueue = nullptr;
    bool own = false;
    if (field_3e8.m_itemCount == 0) {
        field_3e8.Unk_SetCount(field_348.m_itemCount);
        field_398.Unk_SetCount(field_348.m_itemCount);
        for (s64 i = 0; i < static_cast<s32>(field_348.m_itemCount); i++) {
            field_398.m_pData[i] =
                field_28->Unk_4fb230(reinterpret_cast<u64>(field_328), reinterpret_cast<u64>(field_348.m_pData[i]));
            field_3e8.m_pData[i] = nvnDeviceGetImageHandle(Unk_NXDevice(field_28)->vf85(), field_398.m_pData[i]);
        }
        pList = reinterpret_cast<SiGfxNXCommandList*>(field_28->vf92());
        commandBuffer = pList->vf15();
        pQueue = reinterpret_cast<SiGfxNXCommandQueue*>(field_28->vf91());
        pQueue->vf8();
        nvnCommandBufferBeginRecording(commandBuffer);
        Unk_4fb360_update(reinterpret_cast<const Unk_4fb360*>(field_28), reinterpret_cast<u64>(commandBuffer));
        own = true;
    }
    SiGfxNXShaderProgram* pProgram = static_cast<SiGfxNXShaderProgram*>(vf5()->vf46(0x4b));
    nvnCommandBufferBindProgram(commandBuffer, pProgram->vf38(), pProgram->vf39());
    s32 layers = static_cast<s32>(field_348.m_itemCount) / field_22c;
    for (s32 layer = 0; layer < layers; layer++) {
        if (field_22c < 2) {
            continue;
        }
        s32 width = field_1e8;
        s32 height = field_1ec;
        for (s32 level = 0; level < field_22c - 1; level++) {
            width >>= 1;
            height >>= 1;
            nvnCommandBufferBindImage(commandBuffer, 5, 0, field_3e8.m_pData[layer * field_22c + level]);
            nvnCommandBufferBindImage(commandBuffer, 5, 1, field_3e8.m_pData[layer * field_22c + level + 1]);
            nvnCommandBufferDispatchCompute(commandBuffer, (width + 7) / 8, (height + 7) / 8, 1);
            nvnCommandBufferBarrier(commandBuffer, 0x10);
        }
    }
    if (!own) {
        return true;
    }
    pList->Unk_53a790();
    pQueue->vf10(1, &pList);
    bool result = pQueue->vf13(pQueue->vf12());
    pQueue->vf9();
    for (s64 i = 0; i < static_cast<s32>(field_348.m_itemCount); i++) {
        field_28->Unk_4fb2c0(field_398.m_pData[i]);
    }
    field_398.Unk_Clear();
    field_3e8.Unk_Clear();
    return result;
}

// 0x7100561630
bool SiGfxNXTexture::vf31(Unk_NXTextureTarget* pTarget) {
    if (pTarget == nullptr) {
        return false;
    }
    u32 a1 = field_1d8;
    u32 a2 = field_1e8;
    u32 a3 = field_1f4;
    switch (field_1d4) {
    case 3:
    case 4:
    case 5:
    case 6:
        pTarget->vf13(a1, a2, a3, field_230);
        break;
    case 2:
        pTarget->vf10(a1, a2, field_1ec, a3);
        break;
    }
    return true;
}

// 0x71005616b0
bool SiGfxNXTexture::vf32(Unk_NXTextureOwner* pOwner) {
    if (field_318 == pOwner) {
        return true;
    }
    if (field_318 != nullptr) {
        field_318->vf3();
        field_318 = nullptr;
    }
    if (pOwner == nullptr) {
        return false;
    }
    pOwner->vf2();
    if (field_318 != nullptr) {
        field_318->vf3();
    }
    field_318 = pOwner;
    return true;
}

// 0x71005601b0
// NON_MATCHING: the original peels the volumes' loop's first iteration (its
// element is the buffer the reserve just made) and lays the cube and array
// cases out after the volumes' (44 bytes more); the surfaces' case matches.
bool SiGfxNXTexture::Unk_5601b0() {
    field_238.Unk_FreeAll();
    field_288.Unk_FreeAll();
    switch (field_1d4) {
    case 2:
        field_238.Unk_SetCount(field_22c);
        for (s64 i = 0; i < static_cast<s32>(field_238.m_itemCount); i++) {
            SiGfxNXSurface* surface = &field_238.m_pData[i];
            surface->Unk_55cb60(field_28);
            surface->Unk_55d300(reinterpret_cast<Unk_NXSurfaceTexture*>(this), i, 0);
        }
        break;
    case 3:
        field_288.Unk_SetCount(field_22c);
        for (s64 i = 0; i < static_cast<s32>(field_288.m_itemCount); i++) {
            SiGfxNXVolume* volume = &field_288.m_pData[i];
            volume->Unk_565ab0(field_28);
            volume->Unk_565c10(this, i);
        }
        break;
    case 4:
        Unk_561730();
        break;
    case 5:
        Unk_561970();
        break;
    case 6:
        Unk_561aa0();
        break;
    default:
        return false;
    }
    return true;
}

// The description is copied by its implicit copy constructor (SiString's
// takes a default allocator): the trivially copyable runs become two inline
// memcpys and the two pairs at 0x68 and 0x70, whose copy constructor isn't
// trivial, are copied word by word between them.
// NON_MATCHING: the test of a volume made into a 2D array (the image's kind
// 3, the texture's 5) is one block with a `ccmp` in the original, image kind
// first; here Reassociate puts the texture's test first in the `and` and the
// branch is split in two (one instruction more), and the result's register
// is w22 instead of w19. Everything after it matches. Tried (round 12): both
// orders of the two tests with ||, && under !, nested ifs, | and &, a bool
// local, the kind and the texture's kind in locals or a reference, the
// format in a local.
// 0x71005604c0
bool SiGfxNXTexture::vf23(const Unk_Desc* desc, SiGfxImage* image) {
    if (image->field_58.field_0 == 0) {
        return false;
    }
    if (Unk_4ed080(image->field_58.field_0) != field_1d4) {
        if (field_1d4 != 5 || image->field_58.field_0 != 3) {
            return false;
        }
        if (!image->vf25()) {
            return false;
        }
    }
    if (image->field_58.field_8 < 1 || image->field_58.field_c < 1) {
        return false;
    }
    if (image->field_58.field_0 == 3 && image->field_58.field_10 < 1) {
        return false;
    }
    if (image->field_58.field_18 < 1 || image->field_58.field_14 < 1 || image->field_58.field_4 == 0) {
        return false;
    }
    SiGfxImage copy(field_18.m_pAllocator);
    SiGfxImage* src = image;
    if (!image->field_80) {
        image->vf23(&copy);
        copy.Unk_4f3680();
        src = &copy;
    }
    Unk_Desc made(*desc);
    made.field_0 = src->field_58.field_4;
    made.field_10 = src->field_58.field_8;
    made.field_14 = src->field_58.field_c;
    made.field_1c = src->field_58.field_14;
    if (src->field_58.field_0 == 3 && field_1d4 == 5) {
        made.field_18 = 1;
        made.field_20 = src->field_58.field_10;
    } else {
        made.field_18 = src->field_58.field_10;
        made.field_20 = src->field_58.field_18;
    }
    SiArray<SIGFX_TEXTURE_INITDATA, 16> data(field_18.m_pAllocator);
    s32 levels = made.field_1c;
    s32 layers = made.field_20;
    s32 count = layers * levels;
    if (field_1d4 == 4) {
        count = levels * 6;
    }
    if (field_1d4 == 6) {
        count = levels * 6 * layers;
    }
    data.Unk_SetCount(count);
    s32 n = 0;
    switch (field_1d4) {
    case 2:
    case 5:
        for (s32 layer = 0; layer < static_cast<s32>(made.field_20); layer++) {
            if (src->field_58.field_0 == 3) {
                for (s32 level = 0; level < static_cast<s32>(made.field_1c); level++) {
                    SiGfxImage::ImageData3D* pixels = src->vf19(level);
                    SIGFX_TEXTURE_INITDATA* p = &data.m_pData[n];
                    s32 offset = layer * pixels->field_24;
                    p->field_0 = &pixels->field_0[offset];
                    p->field_10 = pixels->field_20;
                    p->field_8 = pixels->field_8;
                    p->field_14 = pixels->field_24;
                    n++;
                }
            } else {
                for (s32 level = 0; level < static_cast<s32>(made.field_1c); level++) {
                    SiGfxImage::ImageData2D* pixels = src->vf17(layer, level);
                    SIGFX_TEXTURE_INITDATA* p = &data.m_pData[n];
                    p->field_0 = pixels->field_0;
                    p->field_10 = pixels->field_1c;
                    p->field_8 = pixels->field_8;
                    p->field_14 = pixels->field_1c * pixels->field_18;
                    n++;
                }
            }
        }
        break;
    case 4:
    case 6:
        for (s32 layer = 0; layer < static_cast<s32>(made.field_20); layer++) {
            for (s32 face = 0; face < 6; face++) {
                for (s32 level = 0; level < static_cast<s32>(made.field_1c); level++) {
                    SiGfxImage::ImageData2D* pixels = src->vf18(layer, face, level);
                    SIGFX_TEXTURE_INITDATA* p = &data.m_pData[n];
                    p->field_0 = pixels->field_0;
                    p->field_10 = pixels->field_1c;
                    p->field_8 = pixels->field_8;
                    p->field_14 = pixels->field_1c * pixels->field_18;
                    n++;
                }
            }
        }
        break;
    case 3:
        for (s32 level = 0; level < static_cast<s32>(made.field_1c); level++) {
            SiGfxImage::ImageData3D* pixels = src->vf19(level);
            SIGFX_TEXTURE_INITDATA* p = &data.m_pData[n];
            p->field_0 = pixels->field_0;
            p->field_10 = pixels->field_20;
            p->field_8 = pixels->field_8;
            p->field_14 = pixels->field_24;
            n++;
        }
        break;
    }
    u32 flags = made.field_30 == 3 ? 8 : 0;
    made.field_60 = data.m_pData;
    made.field_54 = n;
    made.field_40 = flags;
    return vf22(&made);
}

// 0x7100561730: a cube's six faces
bool SiGfxNXTexture::Unk_561730() {
    field_238.Unk_SetCount(field_22c * 6);
    for (s64 i = 0; i < static_cast<s32>(field_238.m_itemCount); i++) {
        field_238.m_pData[i].Unk_55cb60(field_28);
    }
    for (s32 face = 0; face < 6; face++) {
        for (s32 level = 0; level < field_22c; level++) {
            field_238.m_pData[face * field_22c + level].Unk_55d300(reinterpret_cast<Unk_NXSurfaceTexture*>(this),
                                                                  level, face);
        }
    }
    return true;
}

// 0x7100561970
bool SiGfxNXTexture::Unk_561970() {
    field_238.Unk_SetCount(field_22c * field_230);
    for (s64 i = 0; i < static_cast<s32>(field_238.m_itemCount); i++) {
        field_238.m_pData[i].Unk_55cb60(field_28);
    }
    for (s32 layer = 0; layer < field_230; layer++) {
        for (s32 level = 0; level < field_22c; level++) {
            field_238.m_pData[layer * field_22c + level].Unk_55d300(reinterpret_cast<Unk_NXSurfaceTexture*>(this),
                                                                   level, layer);
        }
    }
    return true;
}

// 0x7100561aa0: each layer's six faces
bool SiGfxNXTexture::Unk_561aa0() {
    field_238.Unk_SetCount(field_22c * 6 * field_230);
    for (s64 i = 0; i < static_cast<s32>(field_238.m_itemCount); i++) {
        field_238.m_pData[i].Unk_55cb60(field_28);
    }
    for (s32 layer = 0; layer < field_230; layer++) {
        for (s32 face = 0; face < 6; face++) {
            for (s32 level = 0; level < field_22c; level++) {
                field_238.m_pData[(layer * 6 + face) * field_22c + level].Unk_55d300(
                    reinterpret_cast<Unk_NXSurfaceTexture*>(this), level, layer * 6 + face);
            }
        }
    }
    return true;
}

// 0x7100561dc0
void* SiGfxNXTexture::vf42(s32 level, s32 layer) {
    s32 index = nvnTextureGetLevels(field_328) * layer + level;
    return field_348.m_pData[index];
}

// 0x7100561e10
void* SiGfxNXTexture::Unk_561e10() {
    void* pool = nvnTextureGetMemoryPool(field_328);
    if (pool == nullptr) {
        return nullptr;
    }
    return nvnMemoryPoolMap(pool);
}

// 0x7100561e50
void SiGfxNXTexture::Unk_561e50() {
    void* pool = nvnTextureGetMemoryPool(field_328);
    if (pool != nullptr) {
        s64 offset = nvnTextureGetMemoryOffset(field_328);
        nvnMemoryPoolFlushMappedRange(pool, offset, static_cast<s32>(nvnTextureGetStorageSize(field_328)));
    }
}

// 0x7100562370
bool SiGfxNXTexture::vf39(u32 kind) {
    if (!vf37()) {
        return false;
    }
    field_1d4 = kind;
    return true;
}

// NON_MATCHING: two registers exchanged: the original keeps the 3D flag in
// w22 and the access flags in w23, here the other way round. Tried: the
// three locals' declarations in each order, their types, the access flags
// as `~flags & 8`, declared first, from a local of the flags, the 3D flag as
// `kind == 3`.
// 0x7100561ef0
bool SiGfxNXTexture::vf44(void* texture, void* view) {
    if (texture == nullptr || view == nullptr) {
        return false;
    }
    field_328 = texture;
    field_330 = reinterpret_cast<u64>(view);
    field_338 = field_28->Unk_4fb380(reinterpret_cast<u64>(texture), reinterpret_cast<u64>(view));
    field_450 = true;
    field_451 = true;
    u32 kind = 0;
    bool volume = false;
    bool array = false;
    switch (nvnTextureGetTarget(field_328)) {
    case 0:
        kind = 1;
        break;
    case 1:
    case 5:
    case 7:
        kind = 2;
        break;
    case 2:
        kind = 3;
        volume = true;
        break;
    case 3:
        kind = 1;
        array = true;
        break;
    case 4:
        kind = 5;
        array = true;
        break;
    case 6:
        kind = 2;
        array = true;
        break;
    case 8:
        kind = 4;
        break;
    case 9:
        kind = 6;
        break;
    }
    u32 access = (Unk_nvnTextureGetFlags(field_328) & 8) ? 0 : 8;
    int mode;
    NvnBoolean hasMode = Unk_nvnTextureViewGetDepthStencilMode(reinterpret_cast<void*>(field_330), &mode);
    int viewFormat;
    Unk_nvnTextureViewGetFormat(reinterpret_cast<void*>(field_330), &viewFormat);
    u32 format = Unk_562f10(viewFormat);
    field_1c0 = 1;
    field_1c4 = 0;
    field_1c8 = 8;
    field_1cc = 0;
    field_1d0 = 0;
    field_1d4 = kind;
    field_1d8 = Unk_562f10(nvnTextureGetFormat(field_328));
    field_1dc = hasMode == 1 ? 0 : format;
    field_1e0 = hasMode == 1 ? format : 0;
    field_1e4 = 0;
    field_1e8 = nvnTextureGetWidth(field_328);
    field_1ec = nvnTextureGetHeight(field_328);
    field_1f0 = volume ? nvnTextureGetDepth(field_328) : 0;
    field_1f4 = nvnTextureGetLevels(field_328);
    field_1f8 = array ? nvnTextureGetDepth(field_328) : 0;
    field_1fc = field_1f4 * (array ? field_1f8 : 1);
    field_200 = field_1f4;
    field_204 = nvnTextureGetSamples(field_328);
    field_208 = 0;
    field_20c = true;
    field_20d = Unk_4ed6e0(format);
    field_20e = Unk_4ed120(field_1d8);
    field_20f = false;
    field_21c = access;
    if (field_20e) {
        field_210 = (field_1e8 + 3) / 4;
        field_214 = (field_1ec + 3) / 4;
        field_218 = Unk_4ed0f0(field_1d8);
    } else {
        field_210 = 0;
        field_214 = 0;
        field_218 = 0;
    }
    field_22c = field_1f4;
    field_230 = field_1f8;
    s32 count = (field_230 > 1 ? field_230 : 1) * field_22c;
    field_348.Unk_SetCount(count);
    for (s32 i = 0; i < count; i++) {
        field_348.m_pData[i] = reinterpret_cast<NVNtextureView*>(field_330);
    }
    return Unk_5601b0();
}

// 0x71005624f0 (0x7100562530: its thunk)
bool SiGfxNXTexture::vf17(const void* guid) {
    return Unk_4c8f80(guid, &Unk_1f0028c);
}

// 0x7100562510 (0x7100562550: its thunk)
const void* SiGfxNXTexture::vf18() {
    return &Unk_1f0028c;
}

// 0x710055e7c0
SiGfxNXTexture::SiGfxNXTexture(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice, u32 kind)
    : field_18(pAllocator), field_28(pDevice), field_30(0), field_38(pDevice->Unk_Allocator()), field_a8(0),
      field_22c(0), field_230(0), field_238(pAllocator), field_288(pAllocator), field_2d8(0xc), field_2dc(1),
      field_2e0(1), field_2e4(1), field_2e8(0), field_2f0(100.0f), field_2f4(1), field_2f8(8), field_2fc(),
      field_318(nullptr), field_320(0), field_328(nullptr), field_330(0), field_338(-1), field_340(0),
      field_438(nullptr), field_440(0), field_448(0), field_450(false) {
    memset(&field_1c0, 0, 0x6c);
    field_1c0 = 1;
    field_1d4 = kind;
}

// 0x710055eb20 (D2), 0x710055f130 (D0); 0x710055f110, 0x710055f160,
// 0x710055f120 and 0x710055f190 are their thunks for the second and third
// bases
SiGfxNXTexture::~SiGfxNXTexture() {
    if (field_28 != nullptr && field_30 != 0) {
        field_28->Unk_4f9640(Unk_NXResource(this));
        field_30 = 0;
    }
    vf24();
}

}  // namespace SiSDK3
