// Scope: common
// SiSDK3::SiGfxNXRenderTarget: its construction and destruction, its
// attachments, its name, and the reference counts its header defines. (Its
// small accessors are lib/yebis/class's.)
#define UNK_SIGFX_NX_RENDERTARGET_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_RenderTarget_Impl.h>

// Drops an attachment's reference and clears the pointer to it (placeholder
// name).
#define UNK_SAFE_RELEASE(p)   \
    if ((p) != nullptr) {     \
        (p)->vf3();           \
        (p) = nullptr;        \
    }

// 0x71004ed190: whether a format has a stencil (SiGfx_Utility.cpp)
bool Unk_4ed190(u32 format);

namespace SiSDK3 {

// 0x71005556d0
SiGfxNXRenderTarget::SiGfxNXRenderTarget(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice)
    : field_10(pAllocator), field_20(pDevice), field_28(0), field_30(pAllocator), field_60(0) {
    memset(&field_78, 0, sizeof(field_78));
    memset(&field_64, 0, sizeof(field_64));
    field_64.field_0 = 11;
    field_300 = 0;
    field_348 = 0;
    field_350 = false;
    field_351 = false;
    field_298.Unk_Clear();
    for (s32 i = 0; i < 8; i++) {
        field_a0[i].field_0 = 0;
        field_a0[i].field_8 = nullptr;
        field_a0[i].field_10 = 0;
        field_a0[i].field_30 = 0;
        field_a0[i].field_18 = nullptr;
        field_a0[i].field_20 = nullptr;
        field_a0[i].field_28 = 0;
        field_a0[i].field_34 = 4;
        field_a0[i].field_2c = 0;
        field_2c0[i] = 0;
        field_308[i] = 0;
    }
    field_260.field_0 = 0;
    field_260.field_28 = 0;
    field_260.field_8 = nullptr;
    field_260.field_10 = nullptr;
    field_260.field_18 = nullptr;
    field_260.field_20 = 0;
    field_260.field_24 = 0;
    field_260.field_2c = 4;
}

// 0x71005558c0 (D2), 0x7100555a00 (D0); 0x7100555960 and 0x7100555aa0 are
// their thunks for the second base
SiGfxNXRenderTarget::~SiGfxNXRenderTarget() {
    if (field_28 != 0) {
        field_20->Unk_4f9640(Unk_NXResource(this));
        field_28 = 0;
    }
    vf26();
}

// 0x7100555b50 (0x7100555b90: its thunk)
bool SiGfxNXRenderTarget::vf40(const char* name) {
    Unk_4c4700(&field_30, const_cast<char*>(name));
    field_60 = Unk_4c3510(&field_30);
    return true;
}

// 0x7100555bd0 (0x7100555be0: its thunk)
const SiString<char>* SiGfxNXRenderTarget::vf41() {
    return &field_30;
}

// 0x7100555bf0 (0x7100555c00: its thunk)
u32 SiGfxNXRenderTarget::vf42() {
    return field_60;
}

// 0x7100555d00
bool SiGfxNXRenderTarget::vf19(s32 index, Unk_NXAttachment* attachment, u32 a3) {
    if (static_cast<u32>(index) >= 8) {
        return false;
    }
    Unk_Color& color = field_a0[index];
    if (attachment != nullptr) {
        attachment->vf2();
    }
    if (color.field_8 != nullptr) {
        color.field_8->vf3();
    }
    color.field_8 = attachment;
    color.field_10 = a3;
    color.field_0 = 1;
    return true;
}

// 0x7100555d90
bool SiGfxNXRenderTarget::vf20(s32 index, Unk_NXAttachment* attachment) {
    if (static_cast<u32>(index) >= 8) {
        return false;
    }
    Unk_Color& color = field_a0[index];
    if (attachment != nullptr) {
        attachment->vf2();
    }
    if (color.field_18 != nullptr) {
        color.field_18->vf3();
    }
    color.field_18 = attachment;
    color.field_0 = 2;
    return true;
}

// 0x7100555e20
bool SiGfxNXRenderTarget::vf21(s32 index, Unk_NXAttachment* attachment, u32 a3, u32 a4, u32 a5, u32 a6) {
    if (static_cast<u32>(index) >= 8) {
        return false;
    }
    Unk_Color& color = field_a0[index];
    if (attachment != nullptr) {
        attachment->vf2();
    }
    if (color.field_20 != nullptr) {
        color.field_20->vf3();
    }
    color.field_20 = attachment;
    color.field_30 = a4;
    color.field_34 = a5;
    color.field_28 = a3;
    color.field_2c = a6;
    color.field_0 = 3;
    return true;
}

// 0x7100555ed0
bool SiGfxNXRenderTarget::vf22(Unk_NXAttachment* attachment, bool flag) {
    if (attachment != nullptr) {
        attachment->vf2();
    }
    if (field_260.field_8 != nullptr) {
        field_260.field_8->vf3();
    }
    field_260.field_8 = attachment;
    field_260.field_30 = flag;
    field_260.field_0 = 1;
    return true;
}

// 0x7100555f40
bool SiGfxNXRenderTarget::vf23(Unk_NXAttachment* attachment, bool flag) {
    if (attachment != nullptr) {
        attachment->vf2();
    }
    if (field_260.field_10 != nullptr) {
        field_260.field_10->vf3();
    }
    field_260.field_10 = attachment;
    field_260.field_30 = flag;
    field_260.field_0 = 2;
    return true;
}

// 0x7100555fb0
bool SiGfxNXRenderTarget::vf24(u64 a1, Unk_NXAttachment* attachment, bool flag, u32 a4, u32 a5, u32 a6, u32 a7) {
    if (attachment != nullptr) {
        attachment->vf2();
    }
    if (field_260.field_18 != nullptr) {
        field_260.field_18->vf3();
    }
    field_260.field_18 = attachment;
    field_260.field_28 = a5;
    field_260.field_2c = a6;
    field_260.field_20 = a4;
    field_260.field_24 = a7;
    field_260.field_30 = flag;
    field_260.field_0 = 3;
    return true;
}

// 0x7100556050
bool SiGfxNXRenderTarget::vf25() {
    if (!field_351) {
        return false;
    }
    if (!Unk_5560c0()) {
        return false;
    }
    Unk_5564a0();
    Unk_556730();
    field_351 = false;
    return true;
}

// A texture attached as the depth attachment, as the render target asks it
// for the surface of a level (placeholder name: SiGfxNXTexture's slots 25
// to 28, for a 2D texture, a 2D array's layer, a cube's face and a cube
// array's face in a layer).
class Unk_NXAttachmentTexture {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual u32 vf3();
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
    virtual void vf18();
    virtual const Unk_NXAttachmentVolumeDesc* vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual Unk_NXAttachment* vf25(u32 level);
    virtual Unk_NXAttachment* vf26(u32 face, u32 level);
    virtual Unk_NXAttachment* vf27(u32 layer, u32 level);
    virtual Unk_NXAttachment* vf28(u32 layer, u32 face, u32 level);
};

// The depth attachment's texture as such (inline: placeholder name).
static inline Unk_NXAttachmentTexture* Unk_Texture(Unk_NXAttachment* attachment) {
    return reinterpret_cast<Unk_NXAttachmentTexture*>(attachment);
}

// The larger of two values, the second evaluated again when it is the larger
// (placeholder name).
#define UNK_MAX(a, b) ((a) > (b) ? (a) : (b))

// 0x71005560c0
bool SiGfxNXRenderTarget::Unk_5560c0() {
    s32 first = -1;
    s32 last = -1;
    s32 height = -1;
    s32 width = -1;
    for (s32 i = 0; i < 8; i++) {
        Unk_Color& color = field_a0[i];
        if (color.field_0 == 0) {
            continue;
        }
        s32 w;
        s32 h;
        if (color.field_8 != nullptr) {
            w = color.field_8->vf17()->field_8;
            h = color.field_8->vf17()->field_c;
        } else if (color.field_18 != nullptr) {
            w = color.field_18->vf17()->field_14;
            h = color.field_18->vf17()->field_18;
        } else if (color.field_20 != nullptr) {
            w = UNK_MAX(1, color.field_20->vf19()->field_14 >> color.field_30);
            h = UNK_MAX(1, color.field_20->vf19()->field_18 >> color.field_30);
        } else {
            goto next;
        }
        if (w > 0) {
            if (width < 0) {
                width = w;
            } else {
                width = width < w ? width : w;
            }
        }
        if (h > 0) {
            if (height < 0) {
                height = h;
            } else {
                height = height < h ? height : h;
            }
        }
    next:
        if (first < 0) {
            first = i;
        }
        last = i;
    }
    field_78.field_18 = false;
    field_78.field_19 = false;
    if (last < 0) {
        field_78.field_c = 0;
        field_78.field_10 = 0;
    } else {
        field_78.field_c = first;
        field_78.field_10 = last + 1 - first;
    }
    Unk_NXAttachment* surface = nullptr;
    if (field_260.field_8 != nullptr) {
        surface = field_260.field_8->vf25();
    } else if (field_260.field_10 != nullptr) {
        surface = field_260.field_10;
    } else if (field_260.field_18 != nullptr) {
        if (Unk_Texture(field_260.field_18)->vf19()->field_0 == 2) {
            surface = Unk_Texture(field_260.field_18)->vf25(field_260.field_28);
        } else if (Unk_Texture(field_260.field_18)->vf19()->field_0 == 5) {
            surface = Unk_Texture(field_260.field_18)->vf27(field_260.field_20, field_260.field_28);
        } else if (Unk_Texture(field_260.field_18)->vf19()->field_0 == 4) {
            surface = Unk_Texture(field_260.field_18)->vf26(field_260.field_2c, field_260.field_28);
        } else if (Unk_Texture(field_260.field_18)->vf19()->field_0 == 6) {
            surface = Unk_Texture(field_260.field_18)->vf28(field_260.field_20, field_260.field_2c, field_260.field_28);
        }
    }
    if (surface != nullptr) {
        field_78.field_18 = true;
        field_78.field_19 = Unk_4ed190(surface->vf17()->field_4);
        s32 w = UNK_MAX(1, surface->vf17()->field_14 >> field_260.field_28);
        s32 h = UNK_MAX(1, surface->vf17()->field_18 >> field_260.field_28);
        width = width < 0 ? w : (width < w ? width : w);
        height = height < 0 ? h : (height < h ? height : h);
    }
    if (width < 0 || height < 0) {
        return false;
    }
    field_78.field_0 = width;
    field_78.field_4 = height;
    field_78.field_8 = 0;
    field_78.field_20 = 0;
    return true;
}

// NON_MATCHING: the same calls and stores; the original doesn't test the
// surface a texture's slot 24 returns (it calls it at once) and has no
// induction variable of its own for the formats' stores (`add x9, x19, x23,
// lsl #2` each time), where this keeps 0x29c + 4 * i in a register. Writing
// the surface's three statements in both branches drops the test but keeps
// the extra induction variable (and costs 8 bytes).
// 0x71005564a0
bool SiGfxNXRenderTarget::Unk_5564a0() {
    field_298.field_0 = 0;
    for (s32 i = 0; i < 8; i++) {
        Unk_NXAttachment* surface;
        if (field_a0[i].field_8 != nullptr) {
            surface = field_a0[i].field_8->vf24(field_a0[i].field_10);
        } else {
            surface = field_a0[i].field_18;
        }
        if (surface != nullptr) {
            field_298.field_4[i] = surface->vf17()->field_4;
            field_2c0[i] = reinterpret_cast<u64>(surface->vf25());
            field_308[i] = surface->vf26();
        } else if (field_a0[i].field_20 != nullptr) {
            Unk_NXAttachment* texture = field_a0[i].field_20;
            field_298.field_4[i] = texture->vf19()->field_4;
            field_2c0[i] = texture->vf40();
            s32 layer = field_a0[i].field_28;
            if (texture->vf19()->field_0 == 4 || texture->vf19()->field_0 == 6) {
                layer = field_a0[i].field_28 * 6 + field_a0[i].field_34;
            }
            field_308[i] = texture->vf42(field_a0[i].field_30, layer);
        }
        if (field_2c0[i] != 0 && field_308[i] != 0) {
            field_298.field_0++;
        }
    }
    Unk_NXAttachment* surface;
    if (field_260.field_8 != nullptr) {
        surface = field_260.field_8->vf25();
        if (surface == nullptr) {
            return true;
        }
    } else {
        surface = field_260.field_10;
    }
    if (surface != nullptr) {
        field_298.field_24 = surface->vf17()->field_4;
        field_300 = reinterpret_cast<u64>(surface->vf25());
        field_348 = surface->vf26();
    } else if (field_260.field_18 != nullptr) {
        Unk_NXAttachment* texture = field_260.field_18;
        field_298.field_24 = texture->vf19()->field_4;
        field_300 = texture->vf40();
        field_348 = texture->vf42(0, field_260.field_20);
    }
    return true;
}

// 0x7100556730
// NON_MATCHING: the loop's induction variables: the original steps the
// formats' offset (`cmp x20, #0x20`) and a pointer to the colour, here the
// colours' offset and a pointer to the format; and the depth's blocks are
// laid out in another order (4 bytes more). The formats are read through
// pointers computed in each branch (the descriptions are of two types), which
// gives the original's `add x8, x0, #4 ; ldr w8, [x8]` after the shared call.
// (Round 3: the index as s32/s64/u32/size_t, `!= 8`, the format pointer
// declared outside the loop, the element by reference, the value instead of
// a pointer, a pointer to the formats: no change; walking the elements with
// a pointer unrolls the loop fully.)
bool SiGfxNXRenderTarget::Unk_556730() {
    field_298.field_0 = 0;
    for (s32 i = 0; i < 8; i++) {
        const u32* format;
        if (field_a0[i].field_8 != nullptr) {
            format = &field_a0[i].field_8->vf24(0)->vf17()->field_4;
        } else if (field_a0[i].field_18 != nullptr) {
            format = &field_a0[i].field_18->vf17()->field_4;
        } else if (field_a0[i].field_20 != nullptr) {
            format = &field_a0[i].field_20->vf19()->field_4;
        } else {
            continue;
        }
        field_298.field_4[i] = *format;
        field_298.field_0++;
    }
    field_298.field_0 = field_78.field_10;
    if (field_260.field_8 != nullptr) {
        if (field_260.field_8->vf25() == nullptr) {
            return true;
        }
        field_298.field_24 = field_260.field_8->vf25()->vf17()->field_4;
    } else if (field_260.field_10 != nullptr) {
        field_298.field_24 = field_260.field_10->vf17()->field_4;
    } else if (field_260.field_18 != nullptr) {
        field_298.field_24 = field_260.field_18->vf19()->field_4;
    }
    return true;
}

// 0x7100556840
void SiGfxNXRenderTarget::vf26() {
    for (s32 i = 0; i < 8; i++) {
        UNK_SAFE_RELEASE(field_a0[i].field_8);
        UNK_SAFE_RELEASE(field_a0[i].field_18);
        UNK_SAFE_RELEASE(field_a0[i].field_20);
        field_a0[i].field_0 = 0;
        field_a0[i].field_28 = 0;
        field_a0[i].field_2c = 0;
        field_a0[i].field_30 = 0;
        field_a0[i].field_34 = 4;
    }
    UNK_SAFE_RELEASE(field_260.field_8);
    UNK_SAFE_RELEASE(field_260.field_10);
    UNK_SAFE_RELEASE(field_260.field_18);
    field_260.field_0 = 0;
    field_260.field_20 = 0;
    field_260.field_24 = 0;
    field_260.field_28 = 0;
    field_260.field_2c = 4;
    field_350 = false;
}

// 0x7100556930
SiGfxNXRenderTarget::Unk_Color* SiGfxNXRenderTarget::vf27(s32 index) {
    return &field_a0[index];
}

// 0x7100556940
SiGfxNXRenderTarget::Unk_Color* SiGfxNXRenderTarget::vf28(s32 index) {
    return &field_a0[index];
}

// 0x71005569c0
void SiGfxNXRenderTarget::vf15(u32 value) {
    s32 count = field_298.field_0;
    for (s32 i = 0; i < count; i++) {
        Unk_Color* color = vf27(i);
        if (color->field_18 != nullptr) {
            color->field_18->vf15(value);
        }
        if (color->field_20 != nullptr) {
            color->field_20->vf15(value);
        }
    }
}

// 0x7100556a60
u32 SiGfxNXRenderTarget::vf16() {
    u32 result = 0;
    s32 count = field_298.field_0;
    for (s32 i = 0; i < count; i++) {
        Unk_Color* color = vf28(i);
        if (color->field_18 != nullptr) {
            result |= color->field_18->vf16();
        }
        if (color->field_20 != nullptr) {
            result |= color->field_20->vf16();
        }
    }
    return result;
}

}  // namespace SiSDK3
