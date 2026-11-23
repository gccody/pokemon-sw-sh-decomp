// Scope: common
// PPFX::IGPUSurface (C:/workspace/YEBIS_draft/src/GPU/GPUInterfaceSurface.cpp,
// the __FILE__ of its log lines).
#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceSurface.h>

#define PPFX_FILE "C:/workspace/YEBIS_draft/src/GPU/GPUInterfaceSurface.cpp"
#include <yebis/YEBIS_draft/src/GPU/Unk_Log.h>

// 0x7100446df0: a result's name (Unk_447050.cpp)
const char* Unk_446df0(s32 result);

namespace PPFX {

// 0x71004437f0, 0x71004438f0 (deleting)
IGPUSurface::~IGPUSurface() {
    PPFX_SAFE_RELEASE_INTERFACE(field_70);
    vf14();
    if (field_c0) {
        if (field_b8 != nullptr) {
            field_b8->vf3();
            field_b8 = nullptr;
        }
    }
    if (field_b0) {
        if (field_a8 != nullptr) {
            field_a8->vf3();
            field_a8 = nullptr;
        }
    }
}

// 0x7100443d20
s32 IGPUSurface::vf14() {
    if (field_80 == nullptr) {
        return 0;
    }
    s32 result = 0;
    for (s32 i = 0; i < 10; i++) {
        s32 r = vf13(i);
        if (r < 0) {
            result = r;
        }
    }
    UNK_DELETE_ARRAY(field_80);
    return result;
}

// 0x7100443920
s32 IGPUSurface::CreateSiGfxRenderTarget() {
    Unk_443a60();
    Unk_SiGfxInterface* resource = field_18->field_38->vf72(nullptr, 0, nullptr);
    if (resource == nullptr) {
#line 610
        PPFX_ERROR("IGPUSurface::CreateSiGfxRenderTarget(): ISiGfxDevice::CreateRenderTarget() failed.\n");
        return -1;
    }
    field_b0 = true;
    SetSiGfxRenderTarget(resource);
#line 420
    field_80 = UNK_NEW_ARRAY(Unk_SurfaceUser*, 10);
    for (s32 i = 0; i < 10; i++) {
        field_80[i] = nullptr;
    }
    return 0;
}

// 0x7100443a60
s32 IGPUSurface::Unk_443a60() {
    if (field_80 != nullptr) {
        return 0;
    }
    if (field_10 == 5) {
        return 0;
    }
    s32 result = vf14();
    if (field_b0) {
        if (field_a8 != nullptr) {
            field_a8->vf3();
            field_a8 = nullptr;
        }
    }
    SetSiGfxRenderTarget(nullptr);
    UNK_DELETE_ARRAY(field_80);
    return result;
}

// 0x7100443b80
void IGPUSurface::SetSiGfxRenderTarget(Unk_SiGfxInterface* resource) {
    field_a8 = resource;
    if (field_24 != 1) {
        return;
    }
    Unk_SiGfxRenderTarget* target = field_b8;
    if (resource != nullptr && target == nullptr) {
        field_b8 = field_18->field_38->vf29(1, 0, nullptr);
        if (field_b8 == nullptr) {
#line 7164
            PPFX_ERROR("IGPUSurface::SetSiGfxRenderTarget(): ISiGfxDevice::CreateRenderPassState() failed.\n");
        }
        field_c0 = true;
    }
    if (field_b8 != nullptr && field_b8->vf8()) {
        void** resources = field_b8->vf10();
        *resources = field_a8;
        field_b8->vf9();
    }
}

// 0x7100443c70: hands the surface to a user, after the one that has it
// lets go
s32 IGPUSurface::vf12(s32 index, Unk_SurfaceUser* user) {
    s32 result = vf13(index);
    if (user != nullptr) {
        result = user->vf15(this, index);
        result = result < 0 ? result : 0;
    }
    return result;
}

// 0x7100443cd0
s32 IGPUSurface::vf13(s32 index) {
    if (field_80 == nullptr) {
        return 0;
    }
    if (index == -1) {
        return -6;
    }
    Unk_SurfaceUser* user = field_80[index];
    if (user == nullptr) {
        return 0;
    }
    s32 result = user->vf16(this, index);
    return result < 0 ? result : 0;
}

// what a SiGfx texture's level describes, as a surface keeps it (inline)
static inline IGPUPixelContainer::Unk_Desc Unk_LevelDesc(const IGPUPixelContainer* self, const Unk_SiGfxTextureDesc* desc,
                                                         u32 flags, u32 level) {
    const u32* format;
    if (flags & 0x20) {
        format = &desc->field_10;
    } else if (flags & 0x4000) {
        format = &desc->field_c;
    } else {
        format = &desc->field_4;
    }
    u32 view = *format;
    u32 base = desc->field_4;
    u32 width = desc->field_14 >> level;
    IGPUPixelContainer::Unk_Desc result;
    result.field_0 = view != 0 ? view : base;
    result.field_8 = width != 0 ? width : 1;
    u32 height = desc->field_18 >> level;
    result.field_c = height != 0 ? height : 1;
    result.field_10 = desc->field_30;
    result.field_14 = desc->field_34;
    result.field_4 = self->field_c;
    return result;
}

// SiGfx's render target as RegisterSiGfxTexture makes it (placeholder)
struct Unk_SiGfxTextureTarget {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();  // releases
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
    virtual void vf16();
    virtual void vf17();
    virtual bool vf18();  // whether it can be set up (vf21, then vf25)
    virtual void vf19();
    virtual void vf20();
    virtual void vf21(u32 index, Unk_SiGfxTexture* texture, u32 arg2, u32 level, u32 layer, u32 arg5);
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
};

// 0x7100444bc0 (its log lines name it)
s32 IGPUSurface::RegisterSiGfxTexture(Unk_SiGfxTexture* texture, u32 level, u32 layer, u32 flags) {
    if (field_a8 != nullptr) {
        field_a8->vf3();
        field_a8 = nullptr;
    }
    if (field_b8 != nullptr) {
        field_b8->vf3();
        field_b8 = nullptr;
    }
    field_10 = 0;
    field_38 = reinterpret_cast<Unk_SiGfxInterface*>(texture);
    if (texture != nullptr) {
        texture->vf19();
    }
    field_24 = flags;
    if (flags & 0x800) {
        field_28 &= ~0x300;
    }
    const Unk_SiGfxTextureDesc* desc = texture->vf19();
    field_44 = Unk_LevelDesc(this, desc, texture->vf8()->field_8, level);
    Unk_445f80();
    if (!(flags & 1)) {
        return 0;
    }
    Unk_SiGfxDevice* device = field_18->field_38;
    Unk_SiGfxTextureTarget* target = reinterpret_cast<Unk_SiGfxTextureTarget*>(device->vf72(nullptr, 0, nullptr));
    if (target == nullptr || !target->vf18()) {
#line 4988
        PPFX_ERROR("IGPUSurface::RegisterSiGfxTexture(): ISiGfxRenderTarget creation failed.\n");
        if (target != nullptr) {
            target->vf3();
        }
        return -1;
    }
    target->vf21(0, texture, 0, level, layer, 0);
    target->vf25();
    Unk_SiGfxRenderTarget* pass = device->vf29(1, 0, nullptr);
    if (pass == nullptr || !pass->vf8()) {
#line 5012
        PPFX_ERROR("IGPUSurface::RegisterSiGfxTexture(): ISiGfxRenderPass creation failed.\n");
        if (pass != nullptr) {
            pass->vf3();
        }
        target->vf3();
        return -1;
    }
    void** resources = pass->vf10();
    *resources = target;
    pass->vf9();
    field_a8 = reinterpret_cast<Unk_SiGfxInterface*>(target);
    field_b8 = pass;
#line 420
    field_80 = UNK_NEW_ARRAY(Unk_SurfaceUser*, 10);
    for (s32 i = 0; i < 10; i++) {
        field_80[i] = nullptr;
    }
    s32 result = vf12(0, reinterpret_cast<Unk_SurfaceUser*>(this));
    if (result < 0) {
#line 5029
        PPFX_ERROR("IGPUSurface::RegisterSiGfxTexture(): AttachFramebuffer() failed (0x%x: %s).\n", result,
                   Unk_446df0(result));
        vf1();
        return result;
    }
    return 0;
}

// 0x7100444f80
s32 IGPUSurface::vf11(Unk_SiGfxRenderTarget* target, u32 width, u32 height, s32 format, u32 msaa, u32 quality) {
    field_24 = 1;
    field_28 = 0;
    field_a8 = nullptr;
    field_10 = 5;
    if (target != nullptr) {
        field_a8 = *target->vf11();
    }
    field_b0 = false;
    field_b8 = target;
    field_c0 = false;
    Unk_Desc desc;
    desc.field_0 = format;
    desc.field_4 = field_c;
    desc.field_8 = width;
    desc.field_c = height;
    desc.field_10 = msaa;
    desc.field_14 = quality;
    field_44 = desc;
    Unk_445f80();
    return 0;
}

// 0x7100444720
s32 IGPUSurface::vf15(IGPUSurface* surface, s32 index) {
    if (index == -1) {
        return -6;
    }
    s32 result;
    if (surface != this) {
        if (surface->field_44.field_8 != field_44.field_8) {
#line 1916
            PPFX_ERROR("IGPUSurface::AttachToOtherSurfaceFramebuffer(): Surface width is not match. (framebuffer: %d != surface: %d).\n",
                       surface->field_44.field_8, field_44.field_8);
        }
        if (surface->field_44.field_c != field_44.field_c) {
#line 1922
            PPFX_ERROR("IGPUSurface::AttachToOtherSurfaceFramebuffer(): Surface width is not match. (framebuffer: %d != surface: %d).\n",
                       surface->field_44.field_c, field_44.field_c);
        }
        if (surface->field_44.field_10 != field_44.field_10) {
#line 1928
            PPFX_ERROR("IGPUSurface::AttachToOtherSurfaceFramebuffer(): Surface multisample type is not match. (framebuffer: %d != surface: %d).\n",
                       surface->field_44.field_10, field_44.field_10);
        }
        if (surface->field_44.field_14 != field_44.field_14) {
#line 1934
            PPFX_ERROR("IGPUSurface::AttachToOtherSurfaceFramebuffer(): Surface multisample quality is not match. (framebuffer: %d != surface: %d).\n",
                       surface->field_44.field_14, field_44.field_14);
        }
        if (surface->field_44.field_8 != field_44.field_8 || surface->field_44.field_c != field_44.field_c ||
            surface->field_44.field_10 != field_44.field_10 || surface->field_44.field_14 != field_44.field_14) {
            return -6;
        }
        result = surface->Unk_443ea0(index, this);
    } else {
        result = surface->Unk_443ea0(index, surface);
    }
    Unk_SurfaceAttachment attachment;
    attachment.field_0 = index;
    attachment.field_8 = surface;
    field_90.push_back(attachment);
    surface->field_80[index] = reinterpret_cast<Unk_SurfaceUser*>(this);
    if (surface != this) {
        vf0();
    } else {
        surface->field_88 = index;
    }
    return result;
}

// 0x71004449a0
// NON_MATCHING: the original's loop carries the node in two registers (the
// iterator that list::erase unlinks and the node it frees and reads the
// attachment from), with the matches' index test computed first; here one
// register, and the loop is laid out otherwise. A reference to the element
// and a pointer to it were tried.
s32 IGPUSurface::vf16(IGPUSurface* surface, s32 index) {
    for (auto it = field_90.begin(); it != field_90.end();) {
        if ((surface == nullptr || it->field_8 == surface) && (index == -1 || it->field_0 == index)) {
            IGPUSurface* other = it->field_8;
            s32 i = it->field_0;
            if (other->DetachFromSiGfxRenderTarget(i) >= 0) {
                other->field_80[i] = nullptr;
            }
            it = field_90.erase(it);
            if (other != this) {
                vf1();
            } else {
                field_88 = -1;
            }
        } else {
            ++it;
        }
    }
    return 0;
}

}  // namespace PPFX

// 0x7100445620: a surface for a render target SiGfx made
PPFX::IGPUSurface* Unk_445620(void* device, void* deviceSurface, u32 width, u32 height, u32 format, u32 msaa, u32 quality) {
    using namespace PPFX;
    if (width == 0 || height == 0) {
        return nullptr;
    }
#line 5480
    IGPUSurface* surface = UNK_NEW(IGPUSurface)(static_cast<IGPUDevice*>(device));
    Unk_SiGfxRenderTarget* target = static_cast<Unk_SiGfxRenderTarget*>(deviceSurface);
    if (target != nullptr) {
        surface->field_a8 = *target->vf11();
    }
    surface->field_b0 = false;
    surface->field_b8 = target;
    surface->field_c0 = false;
    surface->field_44.field_0 = format;
    surface->field_44.field_4 = surface->field_c;
    surface->field_44.field_8 = width;
    surface->field_44.field_c = height;
    surface->field_44.field_10 = msaa;
    surface->field_44.field_14 = quality;
    surface->Unk_445f80();
    return surface;
}

// 0x7100445b50: _GLOBAL__sub_I_GPUInterfaceSurface.cpp
