// Scope: common
// PPFX::IGPUTexture (C:/workspace/YEBIS_draft/src/GPU/GPUInterfaceTexture.cpp, the __FILE__ of its log lines).
#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceTexture.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_SiGfxTextureCreateDesc.h>

#define PPFX_FILE "C:/workspace/YEBIS_draft/src/GPU/GPUInterfaceTexture.cpp"
#include <yebis/YEBIS_draft/src/GPU/Unk_Log.h>

// 0x710238c3f9
extern bool Unk_238c3f9;

// 0x71024e14f8: the device there is
extern PPFX::IGPUDevice* Unk_24e14f8;

// 0x710043fa90: the device's sampler `index` (GPUInterfaceDevice.cpp's)
u64 Unk_43fa90(u64 self, u32 index);

namespace PPFX {

u32 Unk_446a90(u32 size, u32 level);
// 0x7100446b20: a format's name (in `buffer` if it has none)
const char* Unk_446b20(s32 format, char* buffer);
IGPUTexture* Unk_4481c0(IGPUDevice* device, void* siTexture, u32 width, u32 height, u32 arg4, s32 format, u32 arg6);
IGPUVolumeTexture* Unk_4486b0(IGPUDevice* device, void* siTexture, u32 width, u32 height, u32 arg4, u32 arg5, s32 format,
                              u32 arg7);
u32 Unk_446ae0(s32 format);
s32 Unk_43e620(IGPUDevice* self, s32 n);
// 0x710043e600: counts memory the device's textures use
s32 Unk_43e600(IGPUDevice* self, s32 n);

// 0x71004472c0: what the texture is of goes before its last reference
s32 IGPUBaseTexture::vf1() {
    if (field_8 == 1) {
        vf11();
    }
    return IGPUInterface::vf1();
}

// 0x7100447300
u32 IGPUBaseTexture::vf12() {
    return field_80;
}

// 0x7100447310
void IGPUBaseTexture::vf13() {}

// 0x7100447640
s32 IGPUBaseTexture::vf5(void* a1, bool a2) {
    return IGPUPixelContainer::vf5(a1, a2);
}

// 0x7100447650
s32 IGPUBaseTexture::vf14() {
    field_7c = -1;
    return 0;
}

// 0x7100447660
s32 IGPUBaseTexture::vf15(u32 state) {
    if (state > 15) {
        return -6;
    }
    field_78 = state;
    return 0;
}

// 0x7100447680
u32 IGPUBaseTexture::vf16() {
    return field_78;
}

// 0x7100447690
s32 IGPUBaseTexture::vf17(u32 value) {
    if (value > 3) {
        return -6;
    }
    return vf15((field_78 & ~3u) | value);
}

// 0x71004476c0
u32 IGPUBaseTexture::vf19() {
    return field_78 & 3;
}

// 0x71004476d0
s32 IGPUBaseTexture::vf18(u32 value) {
    if (value > 3) {
        return -6;
    }
    return vf15((field_78 & ~0xcu) | (value << 2));
}

// 0x7100447700
u32 IGPUBaseTexture::vf20() {
    return (field_78 >> 2) & 3;
}

// 0x7100447710: takes a sampler state (-1: the one that is set) as the one
// applied; with check, tells whether it already was (1)
s32 IGPUBaseTexture::vf21(s32 state, bool check) {
    if (state == -1) {
        state = field_78;
    }
    if (static_cast<u32>(state) > 15) {
        return -6;
    }
    if (!Unk_238c3f9) {
        field_78 = state;
        field_7c = -1;
        return 0;
    }
    if (check) {
        s32 applied = field_7c;
        field_78 = state;
        if (state == applied) {
            return 1;
        }
    } else {
        field_78 = state;
    }
    field_7c = state;
    return 0;
}

// 0x7100447320: copies `data` into level `level` through a SiGfx texture made
// for it
s32 IGPUBaseTexture::vf9(void* data, u32 level, u32 a3, bool a4) {
    s32 result = vf7(data, level, a3, a4);
    if (result < 0) {
        return result;
    }
    if (field_c != 3) {
        return -6;
    }
    IGPUSurface* surface = static_cast<IGPUTexture*>(this)->field_88[level];
    Unk_SiGfxTexture* staging = field_18->field_38->vf49(2, nullptr, 0, nullptr);
    u32 bpp = Unk_446ae0(surface->field_44.field_0);
    Unk_SiGfxTextureLevelData pixels = {};
    pixels.field_0 = data;
    u32 pitch = surface->field_44.field_8 * bpp;
    u32 size = pitch * surface->field_44.field_c;
    pixels.field_10 = pitch;
    pixels.field_8 = size;
    Unk_SiGfxTextureCreateDesc desc;
    desc.field_1c = 1;
    desc.field_20 = 1;
    desc.field_10 = surface->field_44.field_8;
    desc.field_14 = surface->field_44.field_c;
    desc.field_40 = 8;
    desc.field_38 = 0;
    desc.field_30 = 0;
    desc.field_0 = surface->field_44.field_0;
    desc.field_60 = &pixels;
    desc.field_50 = pixels.field_8;
    desc.field_54 = 1;
    if (!staging->vf22(&desc)) {
        staging->vf3();
        return -1;
    }
    Unk_SiGfxDrawContext* context = field_18->field_30;
    void* source = staging->vf25(0);
    void* target = reinterpret_cast<Unk_SiGfxTexture*>(*field_70)->vf25(level);
    void* list = context->vf10();
    context->vf98(nullptr);
    context->vf71(target, source);
    context->vf98(list);
    staging->vf3();
    return 0;
}

// 0x7100447da0 (IGPUTexture::CreateTexture, its log lines say): a new
// texture of a SiGfx texture of its own
// NON_MATCHING: the original computes the description's kind, view flags
// and field_38 with selects before the device's CreateTexture() and spills
// them; here the view flags are computed after it, and the registers differ.
IGPUTexture* IGPUTexture::CreateTexture(IGPUDevice* pDevice, u32 width, u32 height, u32 levels, s32 format, s32 msaa,
                                        u32 quality, u32 usage, u32 flags) {
    if (width == 0 || height == 0) {
        return nullptr;
    }
    u32 kind = (usage & 0x200) ? 2 : (usage >> 11) & 1;
    u32 views = ((usage & 2) << 13) | ((usage & 1) << 5);
    u32 a38 = (flags & 0x2000000) >> 8;
    if (flags & 1) {
        views |= 8;
        a38 = 0x20000;
        kind = 3;
    }
    Unk_SiGfxTexture* siTexture = pDevice->field_38->vf49(2, nullptr, 0, nullptr);
    if (siTexture == nullptr) {
#line 4067
        PPFX_ERROR("IGPUTexture::CreateTexture(): ISiGfxDevice::CreateTexture() failed.\n");
        return nullptr;
    }
    Unk_SiGfxTextureCreateDesc desc;
    desc.field_0 = format;
    desc.field_4 = 0;
    desc.field_8 = 0;
    desc.field_c = 0;
    desc.field_10 = width;
    desc.field_14 = height;
    desc.field_18 = 1;
    desc.field_1c = levels;
    desc.field_20 = 1;
    desc.field_24 = msaa;
    desc.field_28 = quality;
    desc.field_30 = kind;
    desc.field_34 = views;
    desc.field_38 = a38;
    desc.field_3c = 0;
    desc.field_40 = (flags & 0x2000000) >> 22;
    desc.field_48 = 0;
    desc.field_54 = 0;
    desc.field_60 = nullptr;
    desc.field_68 = 0;
    desc.field_70 = 0;
    desc.field_78 = 1.0f;
    desc.field_7c = 0;
    desc.field_80 = 0;
    desc.field_84 = 0;
    if (!siTexture->vf22(&desc)) {
#line 4106
        PPFX_ERROR("IGPUTexture::CreateTexture(): ISiGfxTexture::Create() failed.\n");
        siTexture->vf3();
        return nullptr;
    }
    u32 count = siTexture->vf19()->field_20;
    for (u32 i = 0; i < count; i++) {
        const Unk_SiGfxSurfaceDesc* level = static_cast<Unk_SiGfxSurface*>(siTexture->vf25(i))->vf17();
        Unk_43e600(pDevice, level->field_14 * level->field_18 * level->field_28);
    }
#line 4129
    IGPUTexture* texture = UNK_NEW(IGPUTexture)(pDevice);
    s32 result = texture->vf22(siTexture, flags);
    texture->field_20 = true;
    siTexture->vf3();
    reinterpret_cast<Unk_SiGfxTexture*>(*texture->field_70)->vf4();
    if (result < 0) {
        if (texture != nullptr) {
            texture->vf1();
        }
        texture = nullptr;
    }
    return texture;
}

// 0x7100447970, 0x7100447a10 (deleting): gives back the memory the device
// counts for each level
IGPUTexture::~IGPUTexture() {
    if (field_20) {
        u32 levels = field_80;
        field_20 = false;
        for (u32 i = 0; i < levels; i++) {
            u32 width = Unk_446a90(field_44.field_8, i);
            u32 height = Unk_446a90(field_44.field_c, i);
            Unk_43e620(field_18, Unk_446ae0(field_44.field_0) * width * height);
        }
    }
}

// 0x7100447ac0: makes a surface for each level
s32 IGPUTexture::vf10() {
    u32 levels = vf12();
    if (levels == 0) {
        return -3;
    }
#line 2086
    field_88 = UNK_NEW_ARRAY(IGPUSurface*, levels);
    for (u32 i = 0; i < levels; i++) {
        field_88[i] = IGPUSurface::CreateSurface_SIGFX_TEXTURE_ATTACHED_SURFACE(field_18, this, i, 0, field_24);
    }
    return 0;
}

// 0x7100447b80: IGPUTexture::ReleaseLevelSurfacesAttachToTexture (its log
// line names it)
s32 IGPUTexture::vf11() {
    u32 levels = vf12();
    if (levels == 0) {
        return -3;
    }
    for (u32 i = 0; i < levels; i++) {
        if (static_cast<u32>(field_88[i]->field_8) >= 2) {
#line 2150
            PPFX_WARNING("IGPUTexture::ReleaseLevelSurfacesAttachToTexture(): m_apGPUSurfaceMipmap[%d]->GetRefCount() reference counter is non-zero: %d.\n",
                         i, field_88[i]->field_8);
            field_88[i]->field_40 = false;
            field_88[i]->field_68 = 0;
        }
        PPFX_SAFE_RELEASE_INTERFACE(field_88[i]);
    }
    UNK_DELETE_ARRAY(field_88);
    return 0;
}

// what a SiGfx texture describes, as the textures keep it (inline)
static inline IGPUPixelContainer::Unk_Desc Unk_TextureDesc(const IGPUPixelContainer* self, const Unk_SiGfxTextureDesc* desc,
                                                           u32 flags) {
    const u32* format;
    if (flags & 0x4000) {
        format = &desc->field_c;
    } else if (flags & 0x20) {
        format = &desc->field_10;
    } else if (flags & 8) {
        format = &desc->field_8;
    } else {
        format = &desc->field_4;
    }
    u32 view = *format;
    u32 base = desc->field_4;
    IGPUPixelContainer::Unk_Desc result;
    result.field_0 = view != 0 ? view : base;
    result.field_8 = desc->field_14;
    result.field_c = desc->field_18;
    result.field_10 = desc->field_30;
    result.field_14 = desc->field_34;
    result.field_4 = self->field_c;
    return result;
}

// 0x7100447790
Unk_SiGfxInterface* IGPUBaseTexture::Unk_447790() const {
    return reinterpret_cast<Unk_SiGfxInterface*>(Unk_43fa90(reinterpret_cast<u64>(field_18), field_78));
}

// 0x71004477a0
s32 IGPUTexture::vf22(Unk_SiGfxTexture* texture, u32 usage) {
    if (texture == nullptr) {
        return -6;
    }
    texture->vf19();
    if (texture->vf19()->field_0 != 2) {
        return -6;
    }
    if (field_90[0] != nullptr) {
        field_90[0]->vf3();
        field_90[0] = nullptr;
    }
    field_10 = 0;
    const Unk_SiGfxTextureDesc* desc = texture->vf19();
    field_44 = Unk_TextureDesc(this, desc, texture->vf8()->field_8);
    field_80 = desc->field_20;
    u32 flags = texture->vf8()->field_8;
    field_24 = ((flags >> 13) & 2) | ((flags >> 5) & 1);
    field_28 = usage;
    Unk_445f80();
    field_90[0] = texture;
    field_90[0]->vf2();
    field_90[0]->vf4();
    if (vf10() < 0) {
        vf11();
    } else {
        vf15(0);
    }
    return 0;
}

// 0x7100447cf0
s32 IGPUTexture::vf24(u32 level, IGPUPixelContainer::Unk_Desc* pDesc) {
    if (level >= field_80) {
        return -6;
    }
    field_88[level]->vf8(pDesc);
    return 0;
}

// 0x7100447d30
s32 IGPUTexture::vf23(u32 level, IGPUSurface** ppSurface) {
    if (level >= field_80) {
        return -6;
    }
    *ppSurface = field_88[level];
    (*ppSurface)->vf0();
    return 0;
}

// 0x7100448530, 0x71004485d0 (deleting)
IGPUVolumeTexture::~IGPUVolumeTexture() {
    if (field_20) {
        u32 levels = field_80;
        field_20 = false;
        for (u32 i = 0; i < levels; i++) {
            u32 width = Unk_446a90(field_44.field_8, i);
            u32 height = Unk_446a90(field_44.field_c, i);
            Unk_43e620(field_18, Unk_446ae0(field_44.field_0) * width * height);
        }
    }
}

// 0x71004483b0
s32 IGPUVolumeTexture::vf22(Unk_SiGfxTexture* texture, u32 arg2, u32 usage) {
    if (texture == nullptr) {
        return -6;
    }
    if (texture->vf19()->field_0 != 3) {
        return -6;
    }
    if (field_88[0] != nullptr) {
        field_88[0]->vf3();
        field_88[0] = nullptr;
    }
    field_10 = 0;
    const Unk_SiGfxTextureDesc* desc = texture->vf19();
    field_44 = Unk_TextureDesc(this, desc, texture->vf8()->field_8);
    field_80 = desc->field_20;
    field_84 = desc->field_1c;
    u32 flags = texture->vf8()->field_8;
    field_24 = ((flags >> 13) & 2) | ((flags >> 5) & 1);
    field_28 = usage;
    Unk_445f80();
    field_88[0] = texture;
    field_88[0]->vf2();
    vf15(0);
    return 0;
}

// 0x7100448680
s32 IGPUVolumeTexture::vf10() {
    return -4;
}

// 0x7100448690
s32 IGPUVolumeTexture::vf11() {
    return 0;
}

}  // namespace PPFX

// 0x71004481c0: a texture for a texture SiGfx made (null: the device there is)
PPFX::IGPUTexture* PPFX::Unk_4481c0(IGPUDevice* device, void* siTexture, u32 width, u32 height, u32 arg4, s32 format,
                                    u32 arg6) {
    static char names[2][0x100];
    if (device == nullptr) {
        device = Unk_24e14f8;
    }
#line 4351
    IGPUTexture* texture = UNK_NEW(IGPUTexture)(device);
    if (texture->vf22(static_cast<Unk_SiGfxTexture*>(siTexture), 0) < 0) {
        if (texture != nullptr) {
            texture->vf1();
        }
        texture = nullptr;
    }
    if (texture->field_44.field_8 != width) {
#line 4440
        PPFX_WARNING("Specified uiWidth(%d) doesn't match the resouce width(%d)\n", width,
                     texture->field_44.field_8);
    }
    if (texture->field_44.field_c != height) {
#line 4443
        PPFX_WARNING("Specified uiHeight(%d) doesn't match the resouce height(%d)\n", height,
                     texture->field_44.field_c);
    }
    if (texture->field_44.field_0 != format) {
#line 4447
        PPFX_WARNING("Specified eFormat(%s) doesn't match the resouce format(%s)\n", Unk_446b20(format, names[0]),
                     Unk_446b20(texture->field_44.field_0, names[1]));
    }
    return texture;
}

// 0x71004486b0: a volume texture for a texture SiGfx made (null: the device
// there is)
PPFX::IGPUVolumeTexture* PPFX::Unk_4486b0(IGPUDevice* device, void* siTexture, u32 width, u32 height, u32 arg4,
                                          u32 arg5, s32 format, u32 arg7) {
    static char names[2][0x100];
    // the formats the device's vf73 gives more uses, tested without branches
    bool flag = format != 0 && ((format == 91) | (format == 29) | (format == 93) | (format == 72) | (format == 75) | (format == 78) | (format == 99));
    if (device == nullptr) {
        device = Unk_24e14f8;
    }
#line 4962
    IGPUVolumeTexture* texture = UNK_NEW(IGPUVolumeTexture)(device);
    texture->vf22(static_cast<Unk_SiGfxTexture*>(siTexture), flag, 0);
    if (texture->field_44.field_8 != width) {
#line 5034
        PPFX_WARNING("Specified uiWidth(%d) doesn't match the resouce width(%d)\n", width,
                     texture->field_44.field_8);
    }
    if (texture->field_44.field_c != height) {
#line 5037
        PPFX_WARNING("Specified uiHeight(%d) doesn't match the resouce height(%d)\n", height,
                     texture->field_44.field_c);
    }
    if (texture->field_44.field_0 != format) {
#line 5041
        PPFX_WARNING("Specified eFormat(%s) doesn't match the resouce format(%s)\n", Unk_446b20(format, names[0]),
                     Unk_446b20(texture->field_44.field_0, names[1]));
    }
    Unk_446a90(reinterpret_cast<Unk_SiGfxTexture*>(texture->field_70[0])->vf19()->field_1c, 0);
    return texture;
}

// 0x7100448900: _GLOBAL__sub_I_GPUInterfaceTexture.cpp
