// Scope: common
// PPFX::IGPUSurface (C:/workspace/YEBIS_draft/src/GPU/GPUInterfaceSurface.cpp,
// the __FILE__ of its log lines).
#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceSurface.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceTexture.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_SiGfxTextureCreateDesc.h>

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


// what a kind 1 attachment's slot 17 describes (placeholder): its size, its
// format as a colour and as a depth attachment, its multisampling
struct Unk_SiGfxBufferDesc {
    u8 pad_0[0x8];
    u32 field_8;
    u32 field_c;
    u8 pad_10[0xc];
    u32 field_1c;
    u8 pad_20[0x8];
    u32 field_28;
    u32 field_2c;
    u32 field_30;
};
PKMN_OFFSET_ASSERT(Unk_SiGfxBufferDesc, field_30, 0x30);

// a kind 1 attachment (placeholder)
struct Unk_SiGfxBuffer : Unk_SiGfxAttachment {
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
    virtual const Unk_SiGfxBufferDesc* vf17();
};

// a colour attachment: its kind (0: none) and what it is for each kind
struct Unk_SiGfxColorAttachment {
    u32 field_0;
    u32 field_4;
    Unk_SiGfxBuffer* field_8;  // kind 1
    u64 field_10;
    Unk_SiGfxSurface* field_18;  // kind 2
    Unk_SiGfxAttachment* field_20;  // kind 3: a texture (Unk_SiGfxTexture)
    u32 field_28;
    u32 field_2c;
    u32 field_30;  // its level
    u32 field_34;
};
PKMN_SIZE_ASSERT(Unk_SiGfxColorAttachment, 0x38);

// the depth attachment
struct Unk_SiGfxDepthAttachment {
    u32 field_0;
    u32 field_4;
    Unk_SiGfxBuffer* field_8;       // kind 1
    Unk_SiGfxSurface* field_10;     // kind 2
    Unk_SiGfxAttachment* field_18;  // kind 3: a texture (Unk_SiGfxTexture)
    u64 field_20;
    u32 field_28;  // its level
    u32 field_2c;
    u64 field_30;
};
PKMN_SIZE_ASSERT(Unk_SiGfxDepthAttachment, 0x38);

// what the render target's slot 17 describes: its colour attachments (the
// first and how many) and whether it has a depth and a stencil attachment
struct Unk_SiGfxRenderTargetDesc {
    u8 pad_0[0xc];
    s32 field_c;
    s32 field_10;
    u8 pad_14[0x4];
    bool field_18;
    bool field_19;
};

// SiGfx's render target as a surface changes its attachments (placeholder)
struct Unk_SiGfxRenderTargetEdit {
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
    virtual void vf16();
    virtual const Unk_SiGfxRenderTargetDesc* vf17();
    virtual bool vf18();  // starts a change of the attachments
    // a colour attachment of each kind
    virtual bool vf19(s32 index, Unk_SiGfxTexture* texture, u32 arg2);
    virtual bool vf20(s32 index, Unk_SiGfxTexture* texture);
    virtual bool vf21(s32 index, Unk_SiGfxTexture* texture, u32 arg2, u32 level, u32 layer, u32 slice);
    // the depth attachment of each kind
    virtual bool vf22(Unk_SiGfxTexture* texture, bool flag);
    virtual bool vf23(Unk_SiGfxTexture* texture, bool flag);
    virtual bool vf24(u32 arg1, Unk_SiGfxTexture* texture, bool flag, u32 arg4, u32 level, u32 layer, u32 slice);
    virtual bool vf25();  // ends the change
    virtual void vf26();  // detaches everything
    virtual Unk_SiGfxColorAttachment* vf27(s32 index);
    virtual Unk_SiGfxColorAttachment* vf28(s32 index);
    virtual Unk_SiGfxDepthAttachment* vf29();
    virtual Unk_SiGfxDepthAttachment* vf30();
};

// the surface's render target as it changes its attachments
static inline Unk_SiGfxRenderTargetEdit* Unk_EditTarget(const IGPUSurface* self) {
    return reinterpret_cast<Unk_SiGfxRenderTargetEdit*>(self->field_a8);
}

// 0x7100443ea0 (IGPUSurface::AttachSiGfxRenderTargetFromOtherSurface, its log
// line says): makes `other`'s texture the attachment `index` of the surface's
// render target, keeping the other attachments
// NON_MATCHING: register allocation and spills (the texture stays in x20 and
// the colour array is at sp+0x58 in the original; the two depth flags are
// spilled separately and or-ed at each use there, here one flag is kept), and
// the depth attachment's tail is kept in registers.
s32 IGPUSurface::AttachSiGfxRenderTargetFromOtherSurface(s32 index, IGPUSurface* other) {
    if (other == nullptr) {
        return -6;
    }
    Unk_SiGfxTexture* texture;
    u32 level;
    u32 layer;
    u32 slice;
    if (other->field_10 == 4) {
        IGPUPixelContainer* parent = other->field_68;
        if (parent != nullptr) {
            texture = reinterpret_cast<Unk_SiGfxTexture*>(parent->field_38);
            level = other->field_78;
            if (parent->field_44.field_4 == 4) {
                layer = other->field_7c;
                slice = 0;
            } else if (parent->field_44.field_4 == 5) {
                layer = 0;
                slice = other->field_7c;
            } else {
                layer = 0;
                slice = 0;
            }
        } else {
            level = 0;
            layer = 0;
            slice = 0;
            texture = nullptr;
        }
    } else {
        level = 0;
        layer = 0;
        texture = reinterpret_cast<Unk_SiGfxTexture*>(other->field_38);
        slice = 0;
    }
    const Unk_SiGfxFormatInfo* info = texture->vf8();
    const Unk_SiGfxRenderTargetDesc* desc = Unk_EditTarget(this)->vf17();
    Unk_SiGfxRenderTargetEdit* target = Unk_EditTarget(this);
    bool hasDepth = desc->field_18 || desc->field_19;
    s32 first = desc->field_c;
    s32 count = desc->field_10;
    Unk_SiGfxColorAttachment colors[8] = {};
    for (s32 i = first; i < first + count; i++) {
        if (i == index) {
            continue;
        }
        colors[i] = *target->vf28(i);
        switch (colors[i].field_0) {
        case 1:
            colors[i].field_8->vf2();
            break;
        case 2:
            colors[i].field_18->vf2();
            break;
        case 3:
            colors[i].field_20->vf2();
            break;
        }
    }
    Unk_SiGfxDepthAttachment depthAttachment;
    if (index >= 0 && index < 8 && hasDepth) {
        depthAttachment = *target->vf30();
        Unk_SiGfxAttachment* attachment;
        switch (depthAttachment.field_0) {
        case 1:
            attachment = depthAttachment.field_8;
            break;
        case 2:
            attachment = depthAttachment.field_10;
            break;
        case 3:
            attachment = depthAttachment.field_18;
            break;
        default:
            goto added;
        }
        attachment->vf2();
    }
added:
    Unk_EditTarget(this)->vf26();
    if (index >= 0 && index < 8) {
        if (Unk_EditTarget(this)->vf18()) {
            for (s32 i = first; i < first + count; i++) {
                if (i == index) {
                    continue;
                }
                *Unk_EditTarget(this)->vf27(i) = colors[i];
            }
            if (hasDepth) {
                *Unk_EditTarget(this)->vf29() = depthAttachment;
            }
            bool ok = false;
            switch (info->field_0) {
            case 1:
                ok = Unk_EditTarget(this)->vf21(index, texture, 0, level, layer, slice);
                break;
            case 3:
                ok = Unk_EditTarget(this)->vf20(index, texture);
                break;
            case 5:
                ok = Unk_EditTarget(this)->vf19(index, texture, 0);
                break;
            }
            Unk_EditTarget(this)->vf25();
            if (ok) {
                return 0;
            }
        }
    } else if (index == 8) {
        if (Unk_EditTarget(this)->vf18()) {
            for (s32 i = first; i < first + count; i++) {
                *Unk_EditTarget(this)->vf27(i) = colors[i];
            }
            bool ok = false;
            switch (info->field_0) {
            case 1:
                ok = Unk_EditTarget(this)->vf24(0, texture, false, 0, level, layer, slice);
                break;
            case 3:
                ok = Unk_EditTarget(this)->vf23(texture, false);
                break;
            case 5:
                ok = Unk_EditTarget(this)->vf22(texture, false);
                break;
            }
            Unk_EditTarget(this)->vf25();
            if (ok) {
                return 0;
            }
        }
    }
#line 1703
    PPFX_ERROR("IGPUSurface::AttachSiGfxRenderTargetFromOtherSurface(): ISiGfxRenderTerget creation failed.\n");
    return -1;
}

// adds a reference to what a colour attachment is, if it is something
static inline bool Unk_AddRef(const Unk_SiGfxColorAttachment& attachment) {
    switch (attachment.field_0) {
    case 1:
        attachment.field_8->vf2();
        return true;
    case 2:
        attachment.field_18->vf2();
        return true;
    case 3:
        attachment.field_20->vf2();
        return true;
    }
    return false;
}

// 0x71004443b0 (its log line names it): takes attachment `index` out of the
// surface's render target, keeping the others
// NON_MATCHING: the depth flags' tests come out in another order (the
// original tests the depth flag, the index's sign, the stencil flag, then the
// index's bound, with jump-threaded copies), the depth kinds are compared 1,
// 3, 2 instead of 3, 2, 1, and the registers differ throughout.
s32 IGPUSurface::DetachFromSiGfxRenderTarget(s32 index) {
    if (field_a8 == nullptr) {
        return 0;
    }
    const Unk_SiGfxRenderTargetDesc* desc = Unk_EditTarget(this)->vf17();
    Unk_SiGfxRenderTargetEdit* target = Unk_EditTarget(this);
    bool depth = desc->field_18;
    bool stencil = desc->field_19;
    s32 first = desc->field_c;
    s32 count = desc->field_10;
    Unk_SiGfxColorAttachment colors[8] = {};
    bool kept = false;
    for (s32 i = first; i < first + count; i++) {
        if (i == index) {
            continue;
        }
        colors[i] = *target->vf28(i);
        if (Unk_AddRef(colors[i])) {
            kept = true;
        }
    }
    Unk_SiGfxDepthAttachment depthAttachment;
    Unk_SiGfxAttachment* depthObject = nullptr;
    bool hasDepth = false;
    if (index >= 0 && (depth || stencil) && index < 8) {
        depthAttachment = *target->vf30();
        switch (depthAttachment.field_0) {
        case 1:
            depthObject = depthAttachment.field_8;
            break;
        case 2:
            depthObject = depthAttachment.field_10;
            break;
        case 3:
            depthObject = depthAttachment.field_18;
            break;
        }
        if (depthObject != nullptr) {
            depthObject->vf2();
        }
        hasDepth = true;
    }
    Unk_EditTarget(this)->vf26();
    if (!kept) {
        if (hasDepth && depthObject != nullptr) {
            depthObject->vf3();
        }
        return 0;
    }
    if (Unk_EditTarget(this)->vf18()) {
        for (s32 i = first; i < first + count; i++) {
            if (i == index) {
                continue;
            }
            *Unk_EditTarget(this)->vf27(i) = colors[i];
        }
        if (hasDepth) {
            *Unk_EditTarget(this)->vf29() = depthAttachment;
        }
        if (Unk_EditTarget(this)->vf25()) {
            return 0;
        }
    }
#line 1831
    PPFX_ERROR("IGPUSurface::DetachFromSiGfxRenderTarget(): ISiGfxRenderTarget recreation failed.\n");
    return -1;
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

// what the surface is when it is a level of a SiGfx texture
static inline IGPUPixelContainer::Unk_Desc Unk_SurfaceDesc(const IGPUPixelContainer* self,
                                                           const Unk_SiGfxSurfaceDesc* desc, u32 format) {
    IGPUPixelContainer::Unk_Desc result;
    result.field_0 = format;
    result.field_4 = self->field_c;
    result.field_8 = desc->field_14;
    result.field_c = desc->field_18;
    result.field_10 = desc->field_1c;
    result.field_14 = desc->field_20;
    return result;
}

// what the surface is when it is a kind 1 attachment, as a colour (format
// field_1c) or a depth attachment (field_28)
static inline IGPUPixelContainer::Unk_Desc Unk_BufferDesc(const IGPUPixelContainer* self,
                                                          const Unk_SiGfxBufferDesc* desc, u32 format) {
    IGPUPixelContainer::Unk_Desc result;
    result.field_0 = format;
    result.field_4 = self->field_c;
    result.field_8 = desc->field_8;
    result.field_c = desc->field_c;
    result.field_10 = desc->field_2c;
    result.field_14 = desc->field_30;
    return result;
}

// the surface's SiGfx render target becomes `target`, which isn't its own
static inline void Unk_SetTarget(IGPUSurface* self, Unk_SiGfxRenderTarget* target) {
    self->field_a8 = nullptr;
    self->field_a8 = *target->vf11();
    self->field_b0 = false;
    self->field_b8 = target;
    self->field_c0 = false;
}

// 0x7100445030 (IGPUSurface::CreateSurface_SiGfxDefaultRenderTarget, the
// device's log line says): a surface for SiGfx's render target `target`'s
// first colour attachment (kind 2) or its depth attachment (kind 3)
IGPUSurface* IGPUSurface::CreateSurface_SiGfxDefaultRenderTarget(IGPUDevice* pDevice, s32 kind,
                                                                 Unk_SiGfxRenderTarget* target) {
    switch (kind) {
    case 2:
    case 3:
        break;
    default:
        return nullptr;
    }
    Unk_SiGfxRenderTargetEdit* edit = reinterpret_cast<Unk_SiGfxRenderTargetEdit*>(*target->vf11());
    if (kind == 2) {
        const Unk_SiGfxColorAttachment* color = edit->vf27(0);
        switch (color->field_0) {
        case 1:
            if (color->field_8 == nullptr) {
                return nullptr;
            }
            break;
        case 2:
            if (color->field_18 == nullptr) {
                return nullptr;
            }
            break;
        case 3:
            if (color->field_20 == nullptr) {
                return nullptr;
            }
            break;
        default:
            return nullptr;
        }
    } else {
        const Unk_SiGfxDepthAttachment* depth = edit->vf29();
        switch (depth->field_0) {
        case 2:
            if (depth->field_10 == nullptr) {
                return nullptr;
            }
            break;
        case 3:
            if (depth->field_18 == nullptr) {
                return nullptr;
            }
            break;
        case 1:
            if (depth->field_8 == nullptr) {
                return nullptr;
            }
            break;
        default:
            return nullptr;
        }
    }
#line 5160
    IGPUSurface* surface = UNK_NEW(IGPUSurface)(pDevice);
    surface->field_10 = kind;
    if (kind == 2) {
        surface->field_24 = 1;
        const Unk_SiGfxColorAttachment* color = edit->vf27(0);
        switch (color->field_0) {
        case 1:
            if (color->field_8 != nullptr) {
                const Unk_SiGfxBufferDesc* desc = color->field_8->vf17();
                surface->field_44 = Unk_BufferDesc(surface, desc, desc->field_1c);
            }
            break;
        case 2:
            if (color->field_18 != nullptr) {
                const Unk_SiGfxSurfaceDesc* desc = color->field_18->vf17();
                surface->field_44 = Unk_SurfaceDesc(surface, desc, desc->field_4);
            }
            break;
        case 3: {
            Unk_SiGfxTexture* texture = reinterpret_cast<Unk_SiGfxTexture*>(color->field_20);
            u32 level = color->field_30;
            const Unk_SiGfxTextureDesc* desc = texture->vf19();
            surface->field_44 = Unk_LevelDesc(surface, desc, texture->vf8()->field_8, level);
            break;
        }
        }
    } else {
        surface->field_24 = 2;
        const Unk_SiGfxDepthAttachment* depth = edit->vf29();
        switch (depth->field_0) {
        case 1:
            if (depth->field_8 != nullptr) {
                const Unk_SiGfxBufferDesc* desc = depth->field_8->vf17();
                surface->field_44 = Unk_BufferDesc(surface, desc, desc->field_28);
            }
            break;
        case 2:
            if (depth->field_10 != nullptr) {
                const Unk_SiGfxSurfaceDesc* desc = depth->field_10->vf17();
                surface->field_44 = Unk_SurfaceDesc(surface, desc, desc->field_4);
            }
            break;
        case 3: {
            Unk_SiGfxTexture* texture = reinterpret_cast<Unk_SiGfxTexture*>(depth->field_18);
            u32 level = depth->field_28;
            const Unk_SiGfxTextureDesc* desc = texture->vf19();
            surface->field_44 = Unk_LevelDesc(surface, desc, texture->vf8()->field_8, level);
            break;
        }
        }
    }
    surface->Unk_445f80();
    Unk_SetTarget(surface, target);
    return surface;
}

// (inline in CreateSurface_SIGFX_TEXTURE_ATTACHED_SURFACE; its log line
// names it): a SiGfx render target of the surface's own, if its usage asks
inline s32 IGPUSurface::CreateOwnSiGfxRenderTarget() {
    u64 usage = field_24;
    if (!(usage & 7)) {
        return -6;
    }
    if (usage & 1) {
        CreateSiGfxRenderTarget();
        s32 result = vf12(0, reinterpret_cast<Unk_SurfaceUser*>(this));
        if (result < 0) {
#line 696
            PPFX_ERROR("IGPUSurface::CreateOwnSiGfxRenderTarget(): AttachFramebuffer() failed (0x%x: %s).\n", result,
                       Unk_446df0(result));
            return result;
        }
    }
    return 0;
}

// 0x7100445370 (IGPUSurface::CreateSurface_SIGFX_TEXTURE_ATTACHED_SURFACE,
// its log line says): the surface of `texture`'s level `level` (in layer
// `layer`)
IGPUSurface* IGPUSurface::CreateSurface_SIGFX_TEXTURE_ATTACHED_SURFACE(IGPUDevice* pDevice, IGPUBaseTexture* texture,
                                                                       u32 level, u32 layer, u32 usage) {
#line 5356
    IGPUSurface* surface = UNK_NEW(IGPUSurface)(pDevice);
    surface->field_24 = usage;
    if (usage & 0x800) {
        surface->field_28 &= ~0x300;
    }
    surface->field_28 = texture->field_28;
    if (surface->field_24 & 0x800) {
        surface->field_28 &= ~0x300;
    }
    surface->field_10 = 4;
    surface->field_68 = texture;
    Unk_SiGfxTexture* siTexture = reinterpret_cast<Unk_SiGfxTexture*>(*texture->field_70);
    Unk_SiGfxSurface* siSurface;
    switch (siTexture->vf19()->field_0) {
    case 2:
        siSurface = static_cast<Unk_SiGfxSurface*>(siTexture->vf25(level));
        break;
    case 4:
        siSurface = static_cast<Unk_SiGfxSurface*>(siTexture->vf26(layer, level));
        break;
    default:
        siSurface = nullptr;
        break;
    }
    const Unk_SiGfxSurfaceDesc* desc = siSurface->vf17();
    u32 flags = siSurface->vf8()->field_8;
    const u32* format;
    if (flags & 0x20) {
        format = &desc->field_10;
    } else if (flags & 0x4000) {
        format = &desc->field_c;
    } else {
        format = &desc->field_4;
    }
    IGPUPixelContainer::Unk_Desc desc2;
    desc2.field_0 = *format;
    desc2.field_8 = desc->field_14;
    desc2.field_c = desc->field_18;
    desc2.field_10 = desc->field_1c;
    desc2.field_14 = desc->field_20;
    desc2.field_4 = surface->field_c;
    surface->field_44 = desc2;
    surface->Unk_445f80();
    surface->field_78 = level;
    surface->field_7c = layer;
    if (usage & 7) {
        s32 result = surface->CreateOwnSiGfxRenderTarget();
        if (result < 0) {
#line 5434
            PPFX_ERROR("IGPUSurface::CreateSurface_SIGFX_TEXTURE_ATTACHED_SURFACE(): IGPUSurface::CreateOwnSiGfxRenderTarget() failed (0x%x: %s).\n",
                       result, Unk_446df0(result));
        }
    }
    return surface;
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
        result = surface->AttachSiGfxRenderTargetFromOtherSurface(index, this);
    } else {
        result = surface->AttachSiGfxRenderTargetFromOtherSurface(index, surface);
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
// (The iterator is advanced after an erase too, unless the erase gave the
// end: the original's test of the end on both paths. The two matches are
// computed before they're tested together.)
s32 IGPUSurface::vf16(IGPUSurface* surface, s32 index) {
    for (auto it = field_90.begin(); it != field_90.end();) {
        bool surfaceMatch = surface == nullptr || it->field_8 == surface;
        bool indexMatch = index == -1 || it->field_0 == index;
        if (surfaceMatch && indexMatch) {
            s32 i = it->field_0;
            IGPUSurface* other = it->field_8;
            if (other->DetachFromSiGfxRenderTarget(i) >= 0) {
                other->field_80[i] = nullptr;
            }
            it = field_90.erase(it);
            if (other != this) {
                vf1();
            } else {
                field_88 = -1;
            }
        }
        if (it != field_90.end()) {
            ++it;
        }
    }
    return 0;
}

// 0x7100445740 (IGPUSurface::CreateSurface, its log lines say): a new
// surface of a SiGfx texture of its own, of a usage (1 a render target, 2 a
// depth target, 4 one with unordered access)
IGPUSurface* IGPUSurface::CreateSurface(IGPUDevice* pDevice, u32 width, u32 height, s32 format, s32 usage, s32 msaa,
                                        u32 quality, u32 flags, void* arg8, u32 arg9) {
    if (width == 0 || height == 0) {
        return nullptr;
    }
    Unk_SiGfxTexture* texture = pDevice->field_38->vf49(2, nullptr, 0, nullptr);
    if (texture == nullptr) {
#line 6070
        PPFX_ERROR("IGPUSurface::CreateSurface(): ISiGfxDevice::CreateTexture() failed.\n");
        return nullptr;
    }
    u32 a38;
    u32 kind;
    if (flags & 1) {
        kind = 3;
        a38 = 0x20000;
    } else if (usage & 0x200) {
        kind = 2;
        a38 = 0x10000;
    } else {
        kind = (usage >> 11) & 1;
        a38 = 0;
    }
    u32 views = ((usage & 2) << 13) | ((usage & 1) << 5);
    Unk_SiGfxTextureCreateDesc desc(format, width, height, 1, 1, 1, msaa, quality, kind, views, a38);
    if (!texture->vf22(&desc)) {
#line 6117
        PPFX_ERROR("IGPUSurface::CreateSurface(): ISiGfxTexture::Create() failed.\n");
    } else {
#line 5452
        IGPUSurface* surface = UNK_NEW(IGPUSurface)(pDevice);
        if (surface->RegisterSiGfxTexture(texture, 0, 0, usage) < 0) {
            PPFX_SAFE_RELEASE_INTERFACE(surface);
        } else if (surface != nullptr) {
            return surface;
        }
#line 6128
        PPFX_ERROR("IGPUSurface::CreateSurface(): CreateSurface() failed.\n");
    }
    texture->vf3();
    return nullptr;
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
    surface->vf11(static_cast<Unk_SiGfxRenderTarget*>(deviceSurface), width, height, format, msaa, quality);
    return surface;
}

// 0x7100445b50: _GLOBAL__sub_I_GPUInterfaceSurface.cpp
