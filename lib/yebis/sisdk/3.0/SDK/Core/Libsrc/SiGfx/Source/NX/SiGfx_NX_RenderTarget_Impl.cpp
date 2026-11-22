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

namespace SiSDK3 {

// NON_MATCHING: three instructions, the pairing of the first colour
// attachment's zero stores: the original has `str xzr, [x19, #0xc8]` in place
// and `stp xzr, xzr, [x19, #0xb8]` at the end, this has `str xzr, [x19,
// #0xb8]` and `stp xzr, xzr, [x19, #0xc0]` (as both have for the other seven).
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
        field_a0[i].field_2c = 0;
        field_a0[i].field_34 = 4;
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
