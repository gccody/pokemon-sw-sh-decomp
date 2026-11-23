// Scope: common
// PPFX::CPostEffect (C:/workspace/YEBIS_draft/src/GPU/GPUPostEffect.cpp, the
// __FILE__ of its log lines).
#include <math.h>

#include <algorithm>

#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>
#include <yebis/YEBIS_draft/src/GPU/GPUPostEffect.h>
#include <nx_middleware/gfx/nvn.h>
#include <yebis/YEBIS_draft/src/GPU/GPUClassUtil.h>
#include <yebis/YEBIS_draft/src/GPU/GPUDepthOfField.h>
#include <yebis/YEBIS_draft/src/GPU/GPURenderTextureArray.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Luminance.h>
#include <yebis/YEBIS_draft/src/GPU/TinyEffect/TinyEffect.h>
#include <yebis/YEBIS_draft/src/GPU/GPUTextureLuminance.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>

// 0x7100418e20: the post effect
u64 Unk_418e20_get();

#define PPFX_FILE "C:/workspace/YEBIS_draft/src/GPU/GPUPostEffect.cpp"
#include <yebis/YEBIS_draft/src/GPU/Unk_Log.h>

namespace PPFX {

// 0x7100419550
CPostEffect::~CPostEffect() {
    Unk_419690(nullptr);
}

// 0x7100426a50: every render texture's viewport from the viewport's scale
s32 CPostEffect::Unk_426a50() {
    s32 result = Unk_SetViewport190(field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    if (field_70 != nullptr) {
        result = Unk_SetViewport(field_70, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_50 != nullptr) {
        result = Unk_SetViewport(field_50, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_a0 != nullptr) {
        result = Unk_SetViewport(field_a0, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_a8 != nullptr) {
        result = Unk_SetViewport(field_a8, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_b0 != nullptr) {
        result = Unk_SetViewport(field_b0, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_b8 != nullptr) {
        f32 width;
        f32 height;
        f32 x;
        f32 y;
        if (field_814.field_0 > 0.0f && field_814.field_4 > 0.0f) {
            width = field_814.field_0;
            height = field_814.field_4;
            x = field_814.field_8;
            y = field_814.field_c;
        } else {
            width = field_800.field_0;
            height = field_800.field_4;
            x = field_800.field_8;
            y = field_800.field_c;
        }
        result = Unk_SetViewport(field_b8, width, height, x, y);
    }
    if (field_df0 != nullptr) {
        result = Unk_SetViewport(field_df0, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_1f0 != nullptr) {
        result = Unk_SetViewport(field_1f0, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_1f8 != nullptr) {
        result = Unk_SetViewport(field_1f8, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_200 != nullptr) {
        result = Unk_SetViewport(field_200, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_208 != nullptr) {
        result = Unk_SetViewport(field_208, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_210 != nullptr) {
        result = Unk_SetViewport(field_210, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_218 != nullptr) {
        result = Unk_SetViewport(field_218, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_220 != nullptr) {
        result = Unk_SetViewport(field_220, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_228 != nullptr) {
        result = Unk_SetViewport(field_228, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_230 != nullptr) {
        result = Unk_SetViewport(field_230, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_238 != nullptr && field_238[field_298] != nullptr) {
        result = Unk_SetViewport(field_238[field_298], field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    for (s32 i = 0; i < field_280; i++) {
        result = Unk_SetViewport(field_288[i], field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    for (s32 i = 0; i < field_558; i++) {
        result = Unk_SetViewport(field_550[i], field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_5b8 != nullptr) {
        f32 width;
        f32 height;
        f32 x;
        f32 y;
        if (field_824.field_0 > 0.0f && field_824.field_4 > 0.0f) {
            width = field_824.field_0;
            height = field_824.field_4;
            x = field_824.field_8;
            y = field_824.field_c;
        } else {
            width = field_800.field_0;
            height = field_800.field_4;
            x = field_800.field_8;
            y = field_800.field_c;
        }
        result = Unk_SetViewport(field_5b8, width, height, x, y);
    }
    if (field_5c0 != nullptr) {
        f32 width;
        f32 height;
        f32 x;
        f32 y;
        if (field_834.field_0 > 0.0f && field_834.field_4 > 0.0f) {
            width = field_834.field_0;
            height = field_834.field_4;
            x = field_834.field_8;
            y = field_834.field_c;
        } else {
            width = field_800.field_0;
            height = field_800.field_4;
            x = field_800.field_8;
            y = field_800.field_c;
        }
        result = Unk_SetViewport(field_5c0, width, height, x, y);
    }
    if (field_d38 != nullptr) {
        result = Unk_SetViewport(field_d38, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_1d8 != nullptr) {
        result = Unk_SetViewport(field_1d8, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_1e0 != nullptr) {
        result = Unk_4a5d10(field_1e0, 0x7fffffff, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_1e8 != nullptr) {
        result = Unk_4a5d10(field_1e8, 0x7fffffff, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_810) {
        Unk_4a6160(field_190, nullptr, 0, 1.0f);
    }
    if (field_198 != nullptr) {
        Unk_45eb90(field_198, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    if (field_1a0 != nullptr) {
        Unk_4aa5a0(field_1a0, field_800.field_0, field_800.field_4, field_800.field_8, field_800.field_c);
    }
    return result;
}

// 0x7100423630
s32 CPostEffect::Unk_423630(bool enable) {
    field_895 = true;
    s32 result = 0;
    if (!field_1b8) {
        enable = false;
        result = 1;
    }
    field_bcd = enable;
    return result;
}

// 0x7100423850
s32 CPostEffect::SetAntialiasType(s32 type) {
    if (type < 0) {
        if (field_544 & 1) {
            type = 1;
        } else {
            type = (field_544 & 2) ? 2 : 1;
        }
    }
    if (type < 1 || type > 2) {
#line 13852
        PPFX_WARNING("CPostEffect::SetAntialiasType(): invalid argument.\n");
        field_f44 = 1;
        return 1;
    }
    if (!field_1ca && field_f44 == 2) {
#line 13862
        PPFX_WARNING("CPostEffect::SetAntialiasType(): Initialize with PFX_INITPARAM::m_uiAntialiasFlags |= PFXAA_SMAA.\n");
        field_f44 = 1;
        return 1;
    }
    field_f44 = type;
    return 0;
}

// The bodies of Unk_423990 and Unk_423ba0, which the game's code named as
// functions of (u64, u32).
// NON_MATCHING: the first two branches are swapped. The original tests the
// object's flag before the parameter, the order a bool parameter gives (an
// Argument is the second operand of the merged condition); the value computed
// from a u32 parameter comes first.
inline s32 CPostEffect::SetLightShaftEnable(bool enable) {
    bool available = field_198->field_108;
    if (available || enable) {
        if (available) {
            Unk_LightShaft(field_860).field_60 = false;
        }
        if (enable) {
            if (available) {
                Unk_LightShaft(field_860).field_60 = true;
            } else {
#line 12760
                PPFX_WARNING("CPostEffect::SetLightShaftEnable(): Initialize() with PFXINIT_LIGHTSHAFT flag for light shafts.\n");
                return 1;
            }
        }
    }
    return 0;
}

inline s32 CPostEffect::SetLightGhostEnable(bool enable) {
    bool available = field_198->field_110;
    if (available || enable) {
        if (available) {
            Unk_LightGhost(field_870).field_0 = false;
        }
        if (enable) {
            if (available) {
                Unk_LightGhost(field_870).field_0 = true;
            } else {
#line 12679
                PPFX_WARNING("CPostEffect::SetLightGhostEnable()\n");
                return 1;
            }
        }
    }
    return 0;
}

}  // namespace PPFX

// CPostEffect's functions that the game calls keep the placeholder names its
// code gave them (the object is their first argument); their log lines name them.

// the kinds of formats 0x7100423480 tells apart (inline)
static inline bool Unk_423480_A(s32 format) {
    switch (format) {
    case 2:
    case 10:
    case 24:
    case 28:
        return true;
    default:
        return false;
    }
}
static inline bool Unk_423480_B(s32 format) {
    return (format >= 1 && format <= 4) || (format >= 9 && format <= 12);
}
static inline bool Unk_423480_C(s32 format) {
    switch (format) {
    case 13:
    case 14:
    case 23:
    case 24:
    case 25:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 65:
    case 70:
    case 71:
    case 72:
    case 73:
    case 74:
    case 75:
    case 76:
    case 77:
    case 78:
    case 79:
    case 80:
    case 82:
    case 83:
    case 86:
    case 87:
        return true;
    default:
        return false;
    }
}

// 0x7100423480: whether a format is one of three kinds (placeholder)
// NON_MATCHING: the tests are the original's, but here the block of the second
// kind's test is duplicated for the path where the first kind's test failed
// (the original sets the result to 0 at the entry and branches back to it)
bool Unk_423480(s32 format) {
    bool result = Unk_423480_A(format);
    if (format == 0) {
        return false;
    }
    if (Unk_423480_B(format)) {
        return true;
    }
    if (Unk_423480_C(format)) {
        return true;
    }
    return result;
}

// 0x71004234f0: CPostEffect::SetActiveView
s32 Unk_4234f0(u64 self_, u32 index_) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    s32 index = index_;
#line 11029
    PPFX_FN("Frame: %d, View: %d, SetActiveView(iEffectViewIndex: %d);\n", self->Unk_Frame(self->field_298), self->field_298, index);
    if (self->field_0) {
#line 11037
        PPFX_ERROR("CPostEffect::SetActiveView(): Cannot be called between BeginPostEffectScene() and EndPostEffectScene().\n");
        return -1;
    }
    if (index < 0) {
        return -6;
    }
    if (self->field_400 < index) {
        return -6;
    }
    self->field_298 = index;
    if (self->field_198 != nullptr) {
        self->field_198->field_2ec = index;
    }
    return 0;
}

// 0x7100423660: CPostEffect::SetLensDistortionEnable
s32 Unk_423660(u64 self_, u32 enable_) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    bool enable = enable_ & 1;
    s32 result = 0;
    if (!self->field_1b9) {
        if (enable) {
#line 13283
            PPFX_WARNING("CPostEffect::SetLensDistortionEnable(): Initialize() with PFXINIT_LENSDISTORTION flag for lens distortion.\n");
        }
        enable = false;
        result = 1;
    }
    self->field_be4 = enable;
    return result;
}

// 0x71004236f0: CPostEffect::SetGaussianBlurEnable
s32 Unk_4236f0(u64 self_, u32 enable_) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    bool enable = enable_ & 1;
    s32 result = 0;
    if (!self->field_1c0) {
        if (enable) {
#line 13636
            PPFX_WARNING("CPostEffect::SetGaussianBlurEnable(): Initialize() with PFXINIT_GAUSSIANBLUR flag for feedback.\n");
        }
        enable = false;
        result = 1;
    }
    self->field_c7a = enable;
    return result;
}

// 0x71004237b0: CPostEffect::SetAntialiasEnable
s32 Unk_4237b0(u64 self_, u32 enable_, u32 quiet_) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    bool enable = enable_ & 1;
    bool quiet = quiet_ & 1;
    s32 result = 0;
    if (!self->field_1c8) {
        if (enable && !quiet) {
#line 13786
            PPFX_WARNING("CPostEffect::SetAntialiasEnable(): Initialize() with PFXINIT_ANTIALIAS flag for post-process antialias.\n");
        }
        enable = false;
        result = 1;
    }
    self->field_f38 = enable;
    return result;
}

// 0x7100423990: CPostEffect::SetLightShaftEnable
s32 Unk_423990(u64 self_, bool enable_) {
    return reinterpret_cast<PPFX::CPostEffect*>(self_)->SetLightShaftEnable(enable_);
}

// 0x7100423ba0: CPostEffect::SetLightGhostEnable
s32 Unk_423ba0(u64 self_, bool enable_) {
    return reinterpret_cast<PPFX::CPostEffect*>(self_)->SetLightGhostEnable(enable_);
}

// 0x7100423d00: CPostEffect::SetMotionBlurEnable
s32 Unk_423d00(u64 self_, u32 enable_) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    bool enable = enable_ & 1;
    self->field_895 = true;
    s32 result = 0;
    if (!self->field_1bc) {
        if (enable) {
#line 13999
            PPFX_WARNING("CPostEffect::SetMotionBlurEnable(): Initialize() with PFXINIT_MOTIONBLUR flag for motion blur.\n");
        }
        enable = false;
        result = 1;
    }
    self->field_ce5 = enable;
    return result;
}

// 0x7100423e20: CPostEffect::SetFeedbackEnable
s32 Unk_423e20(u64 self_, u32 enable_) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    bool enable = enable_ & 1;
    s32 result = 0;
    if (!self->field_1c6) {
        if (enable) {
#line 16798
            PPFX_WARNING("CPostEffect::SetFeedbackEnable(): Initialize() with PFXINIT_FEEDBACK flag for feedback.\n");
        }
        enable = false;
        result = 1;
    }
    self->field_bce = enable;
    return result;
}

// 0x7100423780
s32 Unk_423780(u64 self_, const PPFX::Unk_Rect* value, bool a, bool b, f32 c) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    self->field_c7c = *value;
    self->field_c8c = c;
    self->field_c90 = a;
    self->field_c91 = b;
    return 0;
}

// 0x7100423b50: two numbers of the light shaft that is being set
s32 Unk_423b50(u64 self_, f32 a, f32 b) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    PPFX::Unk_Float2 value(a, b);
    s32 view = self->field_860;
    self->field_858[view].field_44 = value;
    return 0;
}

// 0x7100423cd0: the same of the light ghost
s32 Unk_423cd0(u64 self_, f32 a, f32 b) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    PPFX::Unk_Float2 value(a, b);
    s32 view = self->field_870;
    self->field_868[view].field_14 = value;
    return 0;
}

// 0x71004253e0: two scales (1 for none) and two more numbers
s32 Unk_4253e0(u64 self_, f32 a, f32 b, f32 c, f32 d) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    self->field_5a4 = a == 0.0f ? 1.0f : a;
    self->field_5a8 = b == 0.0f ? 1.0f : b;
    self->field_5ac = c;
    self->field_5b0 = d;
    return 0;
}

// 0x7100429da0: a number of a view's settings (-1: the active view)
f32 Unk_429da0(u64 self_, s32 view) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    if (view == -1) {
        view = self->field_298;
    }
    return self->field_2a0[view].field_60;
}

// 0x7100429e60
f32 Unk_429e60(u64 self_, u32 view_) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    s32 view = view_;
    if (view == -1) {
        view = self->field_298;
    }
    return self->field_2a8[view].field_38;
}

// 0x7100446df0: a result's name (Unk_447050.cpp)
const char* Unk_446df0(s32 result);

// 0x71004346f0
s32 PPFX::CPostEffect::EndPostEffectScene(u32 flags, s32 samples) {
#line 29992
    PPFX_FN("Frame: %d, View: %d, EndPostEffectScene(uiEffectFlags: %08x, nManualMultisamples: %d);\n",
            Unk_Frame(field_298), field_298, flags, samples);
    s32 result = EndPostEffectScene_Process(flags, samples);
    if (result < 0) {
#line 30002
        PPFX_ERROR("CPostEffect::EndPostEffectScene(): EndPostEffectScene_Process() failed (0x%x: %s).\n", result,
                   Unk_446df0(result));
    }
    result = Unk_426210();
    return result < 0 ? result : 0;
}

// 0x7100425240: CPostEffect::SetMultisampleMode
s32 Unk_425240(u64 self_, u32 mode) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    if (self->field_0) {
#line 12316
        PPFX_ERROR("CPostEffect::SetMultisampleMode(): Cannot be called between BeginPostEffectScene() and EndPostEffectScene().\n");
        return -1;
    }
    self->field_6b0 = mode;
    if (self->field_1d3) {
        self->field_6b4 = 0;
        return 1;
    }
    PPFX::Unk_4a5d10_Self* textures = self->field_190;
    PPFX::Unk_RenderTexture* texture = textures->field_50;
    void* multisampled = textures->field_58;
    bool single = texture->field_54 == 0 && texture->field_58 == 0;
    bool multi = multisampled != nullptr;
    if (!multi) {
        if (mode == 3) {
            mode = 0;
        } else if (mode == 1) {
#line 12368
        PPFX_ERROR("CPostEffect::SetMultisampleMode(): Cannot set multisample mode to PFXMSM_SINGLESAMPLE.\n");
        return -6;
        }
    }
    if (single && mode == 2) {
#line 12380
        PPFX_ERROR("CPostEffect::SetMultisampleMode(): Cannot set multisample mode to PFXMSM_MULTISAMPLE.\n");
        return -6;
    }
    u32 value = mode == 3 ? 1 : (mode == 2 ? 0 : mode);
    self->field_6b4 = value;
    textures->field_94 = value;
    return 0;
}

// 0x7100425c50
s32 PPFX::CPostEffect::BeginCommandList_SiGfx() {
    if (field_11a0 != nullptr) {
        Unk_SiGfxDrawContext* context = field_18->field_30;
        void* current = context->vf10();
        if (current != nullptr) {
            if (current != field_11b0) {
                return -1;
            }
        } else {
            field_11b8 = field_11c8;
            if (field_11c8) {
                if (field_11c0 == nullptr) {
                    field_11c0 = field_11a0->vf22(1, 0, nullptr);
                }
                field_11b0 = field_11c0;
            } else {
                field_11b0 = field_1198;
                if (field_1200 == nullptr) {
#line 42012
                    PPFX_ERROR("CPostEffect::BeginCommandList_SiGfx(): m_pCurrentNVNcommandBuffer==NULL. Please call SetCurrentCommandBuffer_Nvn().\n");
                    return -1;
                }
                field_1198->vf18(field_1200);
            }
            if (!context->vf8(field_11b0)) {
#line 42025
                PPFX_ERROR("CPostEffect::BeginCommandList_SiGfx(): Failed pSiGfxDrawContext->BeginCommandList(m_pCurrentUsedSiGfxCommandList).\n");
                return -1;
            }
        }
    }
    field_11cc++;
    return 0;
}

namespace PPFX {

// what field_d8 maps a device surface to, as the post effect releases it
// (placeholder)
struct Unk_43c4e0 {
    virtual void vf0();
    virtual void vf1();  // releases a reference
};

}  // namespace PPFX

namespace PPFX {
// 0x7100446e60: the sample count of a number of samples (Unk_447050.cpp)
u32 Unk_446e60(s32 count);
}  // namespace PPFX

// 0x71004397e0
s32 PPFX::CPostEffect::Unk_4397e0(u64 key, u32 arg2, u32 arg3, u32 format, u32 arg5, u32 arg6, Unk_43c4e0** out) {
    if (field_18 == nullptr) {
        return -1;
    }
    Unk_43c4e0* object = nullptr;
    auto it = field_d8.find(key);
    u32 samples = Unk_446e60(arg5);
    if (it != field_d8.end()) {
        object = it->second;
    } else {
        s32 result = field_18->vf67(arg2, arg3, format, samples, arg6, reinterpret_cast<void*>(key),
                                    reinterpret_cast<IGPUInterface**>(&object));
        if (result < 0) {
            return result;
        }
        field_d8.insert(std::pair<const u64, Unk_43c4e0*>(key, object));
    }
    if (out != nullptr) {
        *out = object;
    }
    return 0;
}

// 0x71004399e0: CPostEffect::UnregisterDeviceSurface (its log lines name it)
s32 PPFX::CPostEffect::Unk_4399e0(SiSDK3::ISiInterface* object, void* arg2) {
    if (field_0) {
#line 36463
        PPFX_ERROR("CPostEffect::UnregisterDeviceSurface(): Cannot be called between BeginPostEffectScene() and EndPostEffectScene().\n");
        return -1;
    }
    auto it = field_d8.find(reinterpret_cast<u64>(object));
    if (it == field_d8.end()) {
        return -6;
    }
    if (arg2 != nullptr) {
#line 36497
        PPFX_ERROR("CPostEffect::UnregisterDeviceSurface(): Unable to replace the resource.\nThe specified resources are not compatible with each other.");
        return -6;
    }
    Unk_43c4e0* surface = it->second;
    if (surface == field_120) {
#line 36511
        PPFX_ERROR("CPostEffect::UnregisterDeviceSurface(): The resource is currently bound for SetTonemapDestination().\nUnbind the resource before unregistering.\n");
        return -6;
    }
    field_d8.erase(it);
    if (surface != nullptr) {
        surface->vf1();
    }
    return 0;
}

// 0x7100439630: CPostEffect::ApplyEffects
s32 Unk_439630(u64 self_, u32 flags) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
#line 34180
    PPFX_FN("Frame: %d, View: %d, ApplyEffects(uiEffectFlags: %08x);\n", self->Unk_Frame(self->field_298),
            self->field_298, flags);
    if (self->field_0) {
#line 34189
        PPFX_ERROR("CPostEffect::ApplyEffects(): Cannot be called between BeginPostEffectScene() and EndPostEffectScene().\n");
        return -1;
    }
    u32 mode;
    if (self->field_1d3) {
        if (self->field_70 == nullptr) {
#line 34214
            PPFX_ERROR("CPostEffect::ApplyEffects(): At least SetEffectSource() must be called if initialized with PFXINIT_RENDERSCENE_EXTERNAL flag.\n");
            return -1;
        }
        mode = self->field_6b0;
        self->field_6b0 = 3;
        self->field_6b4 = 0;
    } else {
        mode = self->field_6b0;
        self->field_6b0 = 3;
        u32 has = self->field_190->field_58 != nullptr;
        self->field_6b4 = has;
        self->field_190->field_94 = has;
    }
    self->Unk_426700(0, nullptr, 0, -1, -3.40282347e+38f);
    s32 result = self->EndPostEffectScene(flags, 0);
    Unk_425240(self_, mode);
    return result < 0 ? result : 0;
}

// 0x710043b580
void Unk_43b580(u64 self_, bool value) {
    reinterpret_cast<PPFX::CPostEffect*>(self_)->field_11c8 = value;
}

// the larger of two numbers (inline)
static inline const PPFX::Unk_Float& Unk_Max(const PPFX::Unk_Float& a, const PPFX::Unk_Float& b) {
    return a.field_0 < b.field_0 ? b : a;
}

// 0x71004248b0: CPostEffect::SetAutoExposureAdjustment (its log line names it)
// NON_MATCHING: the original moves the adaptation scale and speed limit into
// w21 and w22 at the entry (before the log line) and selects them as integers
// there; here their integer copies are made after the call, and the
// registers and the order of the clamps differ from there on
s32 Unk_4248b0(f32 sensitivity, PPFX::Unk_Float scale, PPFX::Unk_Float speed, f32 darkSensitivity, f32 darkScale,
               f32 darkSpeed, f32 border, u64 self_, s32 view) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
#line 19192
    PPFX_FN("Frame: %d, View: %d, SetAutoExposureAdjustment(iEffectViewIndex: %d, fAdaptationSensitivity: %f, fAdaptationScale: %f, fAdaptationSpeedLimit: %f, fDarkAdaptationSensitivity: %f, fDarkAdaptationScale: %f, fDarkAdaptationSpeedLimit: %f, fLightDarkExposureBorder: %f);\n",
            self->Unk_Frame(self->field_298), self->field_298, view, sensitivity, scale.field_0, speed.field_0,
            darkSensitivity, darkScale, darkSpeed, border);
    sensitivity = sensitivity < 0.0f ? 0.0f : (sensitivity > 1.0f ? 1.0f : sensitivity);
    PPFX::Unk_Float speedLimit = speed.field_0 > 0.0f ? speed : PPFX::Unk_Float(0.0f);
    PPFX::Unk_Float scaleLimit = scale.field_0 > 0.0f ? scale : PPFX::Unk_Float(0.0f);
    if (darkSensitivity < 0.0f) {
        darkSensitivity = sensitivity;
    }
    if (darkScale < 0.0f) {
        darkScale = scaleLimit.field_0;
    }
    if (darkSpeed < 0.0f) {
        darkSpeed = speedLimit.field_0;
    }
    PPFX::Unk_Float darkSpeedLimit = darkSpeed > 0.0f ? PPFX::Unk_Float(darkSpeed) : PPFX::Unk_Float(0.0f);
    PPFX::Unk_Float darkScaleLimit = darkScale > 0.0f ? PPFX::Unk_Float(darkScale) : PPFX::Unk_Float(0.0f);
    f32 dark = darkSensitivity * darkSensitivity * (3.0f - (darkSensitivity + darkSensitivity));
    if (darkScaleLimit.field_0 < 0.0f || scaleLimit.field_0 < 0.0f || darkSpeedLimit.field_0 < 0.0f ||
        speedLimit.field_0 < 0.0f || dark < 0.0f || sensitivity < 0.0f || dark > 1.0f) {
        return -6;
    }
    self->field_f6c = 1.0f;
    if (view == -1) {
        view = self->field_298;
    }
    s32 result = 0;
    for (s32 i = 0; i < self->field_400; i++) {
        if (view == 0x7fffffff || i == view) {
            PPFX::Unk_429da0_Item* item = &self->field_2a0[i];
            if (item->field_70 == nullptr) {
                result = 1;
            }
            item->field_38 = border;
            item->field_3c = sensitivity;
            item->field_40 = scaleLimit.field_0;
            item->field_44 = speedLimit.field_0;
            item->field_48 = dark;
            item->field_4c = darkScaleLimit.field_0;
            item->field_50 = darkSpeedLimit.field_0;
        }
    }
    return result;
}

// 0x7100424f40: CPostEffect::SetAutoExposureMeteringArea (its log line names
// it): the area made positive and moved and cut into the unit square;
// returns 1 if a view has no luminance to meter
s32 Unk_424f40(f32 width, f32 height, f32 x, f32 y, u64 self_, s32 view) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
#line 18979
    PPFX_FN("Frame: %d, View: %d, SetAutoExposureMeteringArea(iEffectViewIndex: %d, fWidth: %f, fHeight: %f, fOffsetX: %f, fOffsetY: %f);\n",
            self->Unk_Frame(self->field_298), self->field_298, view, width, height, x, y);
    if (width < 0.0f) {
        x = x + width;
        width = -width;
    }
    if (height < 0.0f) {
        y = y + height;
        height = -height;
    }
    if (x + width < 0.0f) {
        x = x - (x + width);
    }
    if (y + height < 0.0f) {
        y = y - (y + height);
    }
    if (x < 0.0f) {
        width = width + x;
        x = 0.0f;
    }
    if (y < 0.0f) {
        height = height + y;
        y = 0.0f;
    }
    PPFX::Unk_Float left = x < 1.0f ? PPFX::Unk_Float(x) : PPFX::Unk_Float(1.0f);
    PPFX::Unk_Float top = y < 1.0f ? PPFX::Unk_Float(y) : PPFX::Unk_Float(1.0f);
    if (left.field_0 + width > 1.0f) {
        width = width - (left.field_0 + width - 1.0f);
    }
    if (top.field_0 + height > 1.0f) {
        height = height - (top.field_0 + height - 1.0f);
    }
    if (view == -1) {
        view = self->field_298;
    }
    s32 result = 0;
    for (s32 i = 0; i < self->field_400; i++) {
        if (view == 0x7fffffff || i == view) {
            PPFX::Unk_429da0_Item* item = &self->field_2a0[i];
            if (item->field_70 == nullptr) {
                result = 1;
            }
            item->field_c = width;
            item->field_10 = height;
            item->field_14 = left.field_0;
            item->field_18 = top.field_0;
        }
    }
    return result;
}

// 0x7100423a50: the light shaft that is being set
s32 Unk_423a50(u64 self_, const PPFX::Unk_Rect* rect, u32 mode, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    self->Unk_LightShaft(self->field_860).field_0 = *rect;
    self->Unk_LightShaft(self->field_860).field_1c = a;
    self->Unk_LightShaft(self->field_860).field_10 = b;
    self->Unk_LightShaft(self->field_860).field_5c = c;
    self->Unk_LightShaft(self->field_860).field_64 = mode;
    self->Unk_LightShaft(self->field_860).field_20 = d;
    self->Unk_LightShaft(self->field_860).field_14 = e;
    self->Unk_LightShaft(self->field_860).field_18 = f;
    return 0;
}

// 0x7100423ae0: more of the light shaft
s32 Unk_423ae0(u64 self_, const PPFX::Unk_Rect* rect, f32 a, f32 b, f32 c, f32 d) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    self->Unk_LightShaft(self->field_860).field_24 = a;
    self->Unk_LightShaft(self->field_860).field_30 = b;
    self->Unk_LightShaft(self->field_860).field_28 = c;
    self->Unk_LightShaft(self->field_860).field_2c = d;
    self->Unk_LightShaft(self->field_860).field_34 = *rect;
    return 0;
}

// 0x7100423c60: the light ghost that is being set
s32 Unk_423c60(u64 self_, const PPFX::Unk_Rect* rect, u32 arg2, u32 arg3, f32 a, f32 b) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    self->Unk_LightGhost(self->field_870).field_4 = *rect;
    self->Unk_LightGhost(self->field_870).field_24 = arg2;
    self->Unk_LightGhost(self->field_870).field_28 = a;
    self->Unk_LightGhost(self->field_870).field_2c = b;
    self->Unk_LightGhost(self->field_870).field_30 = arg3;
    return 0;
}

// 0x7100423db0
// NON_MATCHING: the original selects the three clamped numbers as integers in
// registers (`fmov w8, s0 ; csel w8, w8, wzr, gt`); here the selection stays
// a choice between two stack slots.
s32 Unk_423db0(u64 self_, s32 count, u32 arg2, f32 a, f32 b, f32 c) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    self->field_cf0 = Unk_Max(0.0f, a);
    self->field_cf4 = Unk_Max(0.0f, b);
    if (count >= 0) {
        count = count < 3 ? 3 : (count < 8 ? count : 8);
    }
    self->field_cf8 = count;
    self->field_cfc = arg2;
    self->field_d00 = Unk_Max(1.0f, c);
    return 0;
}

// 0x71004243c0: CPostEffect::SetGlareParameters
s32 Unk_4243c0(u64 self_, u32 mode, f32 a, f32 b, PPFX::Unk_Float remap) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    if (remap.field_0 <= 0.0f) {
#line 12183
        PPFX_ERROR("CPostEffect::SetGlareParameters(): GlareRemapFactor must be greater than 0.0.\n");
        return -1;
    }
    self->field_848 = a;
    self->field_844 = b;
    self->field_f78 = mode;
    self->field_f7c = Unk_Max(0.001f, remap);
    return 0;
}

// 0x7100424670: CPostEffect::SetDeltaTime
s32 Unk_424670(PPFX::CPostEffect* self, f32 elapsed) {
#line 11492
    PPFX_FN("Frame: %d, View: %d, SetDeltaTime(fElapsedTimeInSeconds: %f);\n", self->Unk_Frame(self->field_298), self->field_298, elapsed);
    self->field_7f4 = elapsed;
    return 0;
}

// CPostEffect::SetTonemapExposure, SetTonemapFunction and SetTonemapBackend
// (inline: they have no code of their own)
static inline s32 Unk_SetTonemapExposure(PPFX::CPostEffect* self, f32 exposure) {
#line 17619
    PPFX_FN("Frame: %d, View: %d, SetTonemapExposure(fExposure: %f);\n", self->Unk_Frame(self->field_298), self->field_298,
            exposure);
    PPFX::Unk_Float value = Unk_Max(1.17549435e-38f, exposure);
    if (value.field_0 < 0.0f) {
        return -6;
    }
    self->field_8c0 = value;
    return 0;
}
static inline s32 Unk_SetTonemapFunction(PPFX::CPostEffect* self, u32 tonemap, f32 factor) {
#line 17671
    PPFX_FN("Frame: %d, View: %d, SetTonemapFunction(eTonemap: %d, fMappingFactor: %f);\n",
            self->Unk_Frame(self->field_298), self->field_298, tonemap, factor);
    self->field_8c8 = tonemap;
    if (self->field_59c) {
        self->field_8cc = 1.0f;
        self->field_8d0 = 1.0f / factor;
    } else {
        self->field_8cc = factor;
        self->field_8d0 = 1.0f;
    }
    return 0;
}
static inline s32 Unk_SetTonemapBackend(PPFX::CPostEffect* self, f32 gamma, f32 dither) {
#line 17843
    PPFX_FN("Frame: %d, View: %d, SetTonemapBackend(fGamma: %f, fDitherOffsetScale: %f);\n",
            self->Unk_Frame(self->field_298), self->field_298, gamma, dither);
    PPFX::Unk_Float value = Unk_Max(0.0f, gamma);
    if (value.field_0 < 0.0f) {
        return -6;
    }
    self->field_8c4 = value;
    self->field_968 = dither == 3.40282347e+38f ? 1.70141173e+38f : dither;
    return 0;
}

// 0x71004244a0: the tone map
// NON_MATCHING: the original selects the clamped exposure and gamma as
// integers (`fmov w23, s11` at the entry, `csel w8, w23, w8, gt`, the store a
// `str w8`) and compares the selected bits as a float; here they are
// `fmaxnm`s. Unk_Float parameters, by-value and by-reference maxima and
// two reads of the maximum were tried (as with Unk_423db0). The callers
// (lib/yebis/leaf's Unk_418470_call and its game caller) don't pass the
// floats yet.
s32 Unk_4244a0(u64 self_, u32 tonemap, f32 exposure, f32 gamma, f32 factor, f32 dither) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    Unk_SetTonemapExposure(self, exposure);
    Unk_SetTonemapFunction(self, tonemap, factor);
    return Unk_SetTonemapBackend(self, gamma, dither);
}

// 0x71004246f0
s32 Unk_4246f0(u64 self_, const PPFX::Unk_Rect* rect, f32 a, f32 b, f32 c) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    if (self->field_1a0 != nullptr) {
        self->field_1a0->field_3a8 = false;
    }
    if (a == 0.0f) {
        self->field_918 = 0;
        return 0;
    }
    self->field_918 = 1;
    self->field_91c = a;
    self->field_920 = b;
    self->field_924 = c;
    self->field_928 = *rect;
    return 0;
}

// 0x71004276e0: a camera's numbers (1, 1000 and tan(22.5 degrees) for none)
s32 Unk_4276e0(u64 self_, f32 a, f32 b, f32 c, f32 d, f32 e) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    self->field_895 = true;
    if (a <= 0.0f) {
        a = 1.0f;
    }
    if (b <= 0.0f) {
        b = 1000.0f;
    }
    if (c <= 0.0f) {
        c = 0.41421356f;
    }
    self->field_6d4 = d;
    self->field_6d8 = e;
    self->field_6c4 = a;
    self->field_6c8 = b;
    self->field_6d0 = c;
    self->field_6cc = atanf(c) * 2.0f;
    return 0;
}

// 0x71004275e0: CPostEffect::SetRenderScenePerspective
s32 Unk_4275e0(PPFX::CPostEffect* self, f32 nearZ, f32 farZ, f32 fov) {
#line 11507
    PPFX_FN("Frame: %d, View: %d, SetRenderScenePerspective(fNear: %f, fFar: %f, fVerticalFov: %f);\n",
            self->Unk_Frame(self->field_298), self->field_298, nearZ, farZ, fov);
    f32 tangent = tanf(fov * 0.5f);
    self->field_895 = true;
    if (nearZ <= 0.0f) {
        nearZ = 1.0f;
    }
    if (farZ <= 0.0f) {
        farZ = 1000.0f;
    }
    if (tangent <= 0.0f) {
        tangent = 0.41421356f;
    }
    self->field_6c4 = nearZ;
    self->field_6c8 = farZ;
    self->field_6d0 = tangent;
    self->field_6d4 = 0.0f;
    self->field_6d8 = 0.0f;
    self->field_6cc = atanf(tangent) * 2.0f;
    return 0;
}

// CPostEffect::SetRenderSceneLuminanceScale (inline: it has no code of its own)
static inline s32 Unk_SetRenderSceneLuminanceScale(PPFX::CPostEffect* self, f32 scale) {
#line 11845
    PPFX_FN("Frame: %d, View: %d, SetRenderSceneLuminanceScale(fSceneLuminanceScale: %f);\n",
            self->Unk_Frame(self->field_298), self->field_298, scale);
    if (scale <= 0.0f) {
#line 11854
        PPFX_ERROR("CPostEffect::SetRenderSceneLuminanceScale(): SceneLuminanceScale mest be greater than zero.\n");
        return -6;
    }
    self->field_7f8 = scale;
    return 0;
}

// 0x7100424100: the scene's camera, time step and luminance scale
s32 Unk_424100(PPFX::CPostEffect* self, f32 nearZ, f32 farZ, f32 fov, f32 elapsed, f32 scale) {
    Unk_4275e0(self, nearZ, farZ, fov);
    Unk_424670(self, elapsed);
    return Unk_SetRenderSceneLuminanceScale(self, scale);
}

// 0x7100427760: the same of another camera
s32 Unk_427760(u64 self_, f32 a, f32 b, f32 c, f32 d, f32 e) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    self->field_895 = true;
    if (a <= 0.0f) {
        a = 1.0f;
    }
    if (b <= 0.0f) {
        b = 1000.0f;
    }
    if (c <= 0.0f) {
        c = 0.41421356f;
    }
    self->field_6ec = d;
    self->field_6f0 = e;
    self->field_6dc = a;
    self->field_6e0 = b;
    self->field_6e8 = c;
    self->field_6e4 = atanf(c) * 2.0f;
    return 0;
}

// 0x71004278c0
s32 Unk_4278c0(u64 self_, void* data) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    if (data == nullptr) {
        return -6;
    }
    self->field_f80 = -1;
    self->field_f84 = *static_cast<const PPFX::Unk_4278c0_Data*>(data);
    return 0;
}

// 0x7100428ec0
s32 Unk_428ec0(u64 self_, f32 a, f32 b, f32 c) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    self->field_895 = true;
    self->field_8b8 = PPFX::Unk_Float2(0.0f, 0.0f);
    self->field_898 = a;
    if (c >= 0.0f) {
        self->field_89c = c;
    }
    self->field_895 = true;
    self->field_8a4 = b;
    self->field_8a0 = 0.0f;
    self->field_8a8 = PPFX::Unk_Float2(1.0f, 0.78539819f);
    return 0;
}

// 0x7100429dc0: CPostEffect::GetAutoExposureAdjustedApi
f32 Unk_429dc0(u64 self_, u32 view_) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    s32 view = view_;
    s32 index = view == -1 ? self->field_298 : view;
    f32 value = self->field_2a0[index].field_60;
#line 18580
    PPFX_FN("Frame: %d, View: %d, %f GetAutoExposureAdjustedApi(iEffectViewIndex: %d);\n", self->Unk_Frame(self->field_298), self->field_298, value, view);
    return value;
}

// The colour matrices' functions: each multiplies one of them by a matrix.
namespace PPFX {

// 0x710040fb30, 0x7100410130, 0x7100410200, 0x71004102a0 (Unk_415f40.cpp)
MATRIXT44* Unk_40fb30(MATRIXT44* out, bool luminance, f32 angle);
void Unk_410130(MATRIXT44* out, bool arg1, f32 r, f32 g, f32 b);
void Unk_410200(MATRIXT44* out, f32 x, f32 y, f32 z, f32 w);
void Unk_4102a0(MATRIXT44* out, f32 x, f32 y, f32 z);

}  // namespace PPFX

// a scale (inline)
static inline void Unk_Scale(PPFX::MATRIXT44* out, f32 x, f32 y, f32 z) {
    out->field_0[0][1] = out->field_0[0][2] = out->field_0[0][3] = out->field_0[1][0] = out->field_0[1][2] =
        out->field_0[1][3] = out->field_0[2][0] = out->field_0[2][1] = out->field_0[2][3] = out->field_0[3][0] =
            out->field_0[3][1] = out->field_0[3][2] = 0.0f;
    out->field_0[0][0] = x;
    out->field_0[1][1] = y;
    out->field_0[2][2] = z;
    out->field_0[3][3] = 1.0f;
}

// A rotation about a unit axis (inline)
static inline void Unk_RotationAxis(PPFX::MATRIXT44* out, f32 x, f32 y, f32 z, f32 angle) {
    f32 c = cosf(angle);
    f32 s = sinf(angle);
    out->field_0[0][0] = x * x + (1.0f - x * x) * c;
    out->field_0[0][1] = x * y * (1.0f - c) + z * s;
    out->field_0[0][2] = x * z * (1.0f - c) - y * s;
    out->field_0[1][0] = x * y * (1.0f - c) - z * s;
    out->field_0[1][1] = y * y + (1.0f - y * y) * c;
    out->field_0[1][2] = y * z * (1.0f - c) + x * s;
    out->field_0[2][0] = x * z * (1.0f - c) + y * s;
    out->field_0[2][1] = y * z * (1.0f - c) - x * s;
    out->field_0[2][2] = z * z + (1.0f - z * z) * c;
    out->field_0[0][3] = out->field_0[1][3] = out->field_0[2][3] = 0.0f;
    out->field_0[3][0] = out->field_0[3][1] = out->field_0[3][2] = 0.0f;
    out->field_0[3][3] = 1.0f;
}

// the identity's element (inline)
static inline f32 Unk_Identity(s32 i, s32 j) {
    return i == j ? 1.0f : 0.0f;
}

// the sepia tone's matrix (placeholder name)
static const f32 Unk_SepiaTone[4][4] = {
    {0.941f, 0.0f, 0.0f, 0.0f},
    {0.0f, 0.784f, 0.0f, 0.0f},
    {0.0f, 0.0f, 0.569f, 0.0f},
    {0.0f, 0.0f, 0.0f, 1.0f},
};

// colour matrix `index` times `m`
static inline void Unk_Apply(PPFX::CPostEffect* self, s32 index, const PPFX::MATRIXT44* m) {
    PPFX::MATRIXT44_MatrixMultiply(&self->field_9b4[index], &self->field_9b4[index], m);
    self->field_b34[index] = true;
}

// 0x710043a400
s32 Unk_43a400(u64 self_) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    PPFX::MATRIXT44 m;
    PPFX::Unk_4102a0(&m, -1.0f, -1.0f, -1.0f);
    Unk_Apply(self, 0, &m);
    return 0;
}

// 0x710043a460
s32 Unk_43a460(u64 self_, u32 index, f32 angle) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    PPFX::MATRIXT44 m;
    Unk_RotationAxis(&m, 0.0f, 0.0f, 1.0f, angle);
    Unk_Apply(self, index, &m);
    return 0;
}

// 0x710043a530
s32 Unk_43a530(u64 self_, u32 index, f32 scale) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    PPFX::MATRIXT44 m;
    Unk_Scale(&m, scale, scale, scale);
    Unk_Apply(self, index, &m);
    return 0;
}

// 0x710043a5b0
s32 Unk_43a5b0(u64 self_, u32 index, bool luminance, f32 angle) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    PPFX::MATRIXT44 m;
    PPFX::Unk_40fb30(&m, luminance, angle);
    Unk_Apply(self, index, &m);
    return 0;
}

// 0x710043a610
s32 Unk_43a610(u64 self_, u32 index, f32 scale) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    PPFX::MATRIXT44 m;
    PPFX::Unk_4102a0(&m, scale, scale, scale);
    Unk_Apply(self, index, &m);
    return 0;
}

// 0x710043a670
s32 Unk_43a670(u64 self_, u32 index, f32 saturation) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    PPFX::MATRIXT44 m;
    PPFX::Unk_410130(&m, false, saturation, saturation, saturation);
    Unk_Apply(self, index, &m);
    return 0;
}

// 0x710043a6e0
s32 Unk_43a6e0(u64 self_, u32 index, f32 x, f32 y, f32 z) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    PPFX::MATRIXT44 m;
    Unk_Scale(&m, x, y, z);
    Unk_Apply(self, index, &m);
    return 0;
}

// 0x710043a760
s32 Unk_43a760(u64 self_, u32 index, f32 scale) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    PPFX::MATRIXT44 m;
    Unk_Scale(&m, scale, scale, scale);
    Unk_Apply(self, index, &m);
    return 0;
}

// 0x710043a7e0
s32 Unk_43a7e0(u64 self_, u32 index, f32 x, f32 y, f32 z, f32 w) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    PPFX::MATRIXT44 m;
    PPFX::Unk_410200(&m, x, y, z, w);
    Unk_Apply(self, index, &m);
    return 0;
}

// 0x710043a840: `amount` of a sepia tone (the matrix between the identity
// and the tone's), then the saturation 1 - `amount`
// NON_MATCHING: the same arithmetic, but the tone's sixteen stores pair up at
// other offsets (here m[0][0] is stored alone first and the pairs are odd; the
// original pairs every row's elements 0-1 and 2-3). Element order, a loop by
// columns and a lerp of two matrices were tried.
s32 Unk_43a840(u64 self_, u32 index, f32 amount) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    PPFX::MATRIXT44 tone;
    for (s32 i = 0; i < 4; i++) {
        for (s32 j = 0; j < 4; j++) {
            tone.field_0[i][j] = Unk_Identity(i, j) + amount * (Unk_SepiaTone[i][j] - Unk_Identity(i, j));
        }
    }
    PPFX::MATRIXT44 saturation;
    PPFX::Unk_410130(&saturation, false, 1.0f - amount, 1.0f - amount, 1.0f - amount);
    PPFX::MATRIXT44 m;
    PPFX::MATRIXT44_MatrixMultiply(&m, &saturation, &tone);
    PPFX::MATRIXT44 copy = m;
    Unk_Apply(self, index, &copy);
    return 0;
}

// 0x7100429e80: a number of a view's settings (-1: the active view), or
// another one when it isn't set
f32 Unk_429e80(u64 self_, s32 view) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    if (view == -1) {
        view = self->field_298;
    }
    if (self->field_2a0[view].field_24 > 0.0f) {
        return self->field_2a0[view].field_24;
    }
    if (self->field_2a0[view].field_70 != nullptr) {
        return self->field_2a0[view].field_5c;
    }
    return 0.0f;
}

// 0x7100429ed0: the same of the other kind
f32 Unk_429ed0(u64 self_, s32 view) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    if (view == -1) {
        view = self->field_298;
    }
    if (self->field_2a8[view].field_1c > 0.0f) {
        return self->field_2a8[view].field_1c;
    }
    if (self->field_2a8[view].field_48 != nullptr) {
        return self->field_2a8[view].field_34;
    }
    return 0.0f;
}

// 0x7100424240: CPostEffect::SetRenderSceneViewportScale
s32 Unk_424240(u64 self_, u32 flag_, f32 width, f32 height, f32 x, f32 y) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    bool flag = flag_ & 1;
    if (self->field_0) {
#line 38261
        PPFX_ERROR("CPostEffect::SetRenderSceneViewportScale(): Cannot be called between BeginPostEffectScene() and EndPostEffectScene().\n");
        return -1;
    }
    if (x != 0.0f || y != 0.0f) {
#line 38269
        PPFX_ERROR("CPostEffect::SetRenderSceneViewportScale(): Not supported. Both of fOffsetX and fOffsetY must be zero.\n");
        return -4;
    }
    if (width >= 0.0f) {
        self->field_800.field_0 = width;
    }
    if (height >= 0.0f) {
        self->field_800.field_4 = height;
    }
    if (x >= 0.0f) {
        self->field_800.field_8 = x;
    }
    if (y >= 0.0f) {
        self->field_800.field_c = y;
    }
    if (self->field_800.field_0 == 0.0f) {
        self->field_800.field_0 = 1.0f;
    }
    if (self->field_800.field_4 == 0.0f) {
        self->field_800.field_4 = 1.0f;
    }
    self->field_810 = flag;
    return 0;
}

// 0x71004277e0: CPostEffect::SetVignetteByOpticsImageCircle
s32 Unk_4277e0(u64 self_, u32 a_, u32 b_, f32 c, f32 d, f32 e, f32 f, f32 g) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    bool a = a_ & 1;
    bool b = b_ & 1;
    self->field_918 = 0;
    self->field_1a0->field_3a8 = false;
    self->field_938 = c;
    self->field_950 = d;
    self->field_954 = e;
    self->field_920 = f;
    self->field_958 = g;
    self->field_94d = a;
    if (c <= 0.0f && d <= 0.0f) {
        return 0;
    }
    if (!self->field_1ba) {
        if (c > 0.0f || !(d <= 0.0f)) {
#line 12109
            PPFX_WARNING("CPostEffect::SetVignetteByOpticsImageCircle(): Initialize() with PFXINIT_OPTICALVIGNETTING flag for optical vignetting.\n");
        }
        return 1;
    }
    if (self->field_1a0 != nullptr) {
        self->field_1a0->field_3a8 = b;
    }
    self->field_918 = 3;
    return 0;
}

// NON_MATCHING: the register of one temporary and the order of two
// instructions differ (the original ands the comparison with the parameter,
// `and w12, w12, w2`, and compares the second loop's counter with a
// sign-extended load).
// 0x7100425170: which views' settings of the second kind are on (0x7fffffff:
// all of them, -1: the active one); 1 if one of them can't be
s32 Unk_425170(u64 self_, u64 view_, u32 enable_) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    s32 view = view_;
    bool enable = enable_ & 1;
    if (view == -1) {
        view = self->field_298;
    }
    s32 result = 0;
    if (self->field_400 < 1) {
        return 0;
    }
    if (view == 0x7fffffff) {
        for (s32 i = 0; i < self->field_400; i++) {
            bool available = self->field_2a8[i].field_48 != nullptr;
            self->field_2a8[i].field_0 = enable && available;
            if (!available) {
                result = 1;
            }
        }
    } else {
        for (s32 i = 0; i < self->field_400; i++) {
            if (i == view) {
                bool available = self->field_2a8[i].field_48 != nullptr;
                self->field_2a8[i].field_0 = enable && available;
                if (!available) {
                    result = 1;
                }
            }
        }
    }
    return result;
}

namespace PPFX {

// 0x710041af70
Unk_RenderTexture* CPostEffect::Unk_41af70() {
    Unk_4a5d10_Self* textures = field_190;
    s32 index = field_5d8;
    if (index == -1) {
        index = textures->field_90;
    }
    if (index < textures->field_30) {
        return textures->field_38[index];
    }
    return nullptr;
}

}  // namespace PPFX

// 0x7100423ee0: CPostEffect::SetGlareModulatorSource
s32 Unk_423ee0(PPFX::CPostEffect* self, u32 source, u64 object) {
    if (source >= 6) {
#line 39137
        PPFX_ERROR("CPostEffect::SetGlareModulatorSource(): Argument eGlareModulatorSource is invalid.\n");
        return -6;
    }
    self->field_c0 = source;
    if (source == 0) {
        self->field_b8 = nullptr;
        return 0;
    }
    if (!self->field_1cc) {
#line 39161
        PPFX_WARNING("CPostEffect::SetGlareModulatorSource(): Initialize() with PFXINIT_GLAREMODULATOR flag for glare modulation.\n");
        self->field_c0 = 0;
        self->field_b8 = nullptr;
        return 1;
    }
    self->field_b8 = reinterpret_cast<PPFX::Unk_RenderTexture*>(object);
    return 0;
}

// 0x7100423ff0: CPostEffect::SetEffectMaskColorSource
s32 Unk_423ff0(PPFX::CPostEffect* self, u32 source, u64 object) {
    if (source >= 5) {
#line 39306
        PPFX_ERROR("CPostEffect::SetEffectMaskColorSource(): Argument eEffectMaskColorSource is invalid.\n");
        return -6;
    }
    self->field_5c8 = source;
    if (source == 0) {
        self->field_5b8 = nullptr;
        return 0;
    }
    if (!self->field_1cd) {
#line 39329
        PPFX_WARNING("CPostEffect::SetEffectMaskColorSource(): Initialize() with PFXINIT_EFFECTMASK flag for effect mask.\n");
        self->field_5c8 = 0;
        self->field_5b8 = nullptr;
        return 1;
    }
    self->field_5b8 = reinterpret_cast<PPFX::Unk_RenderTexture*>(object);
    return 0;
}

// 0x710043a100, 0x710043a280: the same with a device texture (its render
// texture, made if there is none)
s32 Unk_43a100(PPFX::CPostEffect* self, u32 source, u64 key, u32 arg3, u32 arg4, u32 format) {
    if (source == 0) {
        return Unk_423ee0(self, 0, 0);
    }
    PPFX::Unk_RenderTexture* texture = PPFX::Unk_MapFind(self->field_108, key);
    if (texture == nullptr) {
        s32 result = self->Unk_427c10(key, arg3, arg4, format, nullptr, &texture);
        if (result < 0) {
            return result;
        }
    }
    return Unk_423ee0(self, source, reinterpret_cast<u64>(texture));
}

s32 Unk_43a280(PPFX::CPostEffect* self, u32 source, u64 key, u32 arg3, u32 arg4, u32 format) {
    if (source == 0) {
        return Unk_423ff0(self, 0, 0);
    }
    PPFX::Unk_RenderTexture* texture = PPFX::Unk_MapFind(self->field_108, key);
    if (texture == nullptr) {
        s32 result = self->Unk_427c10(key, arg3, arg4, format, nullptr, &texture);
        if (result < 0) {
            return result;
        }
    }
    return Unk_423ff0(self, source, reinterpret_cast<u64>(texture));
}

// 0x7100424b20: CPostEffect::SetAutoExposureRange
s32 Unk_424b20(u64 self_, s32 view, f32 minExposure, f32 maxExposure) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
#line 18870
    PPFX_FN("Frame: %d, View: %d, SetAutoExposureRange(iEffectViewIndex: %d, fMinExposure: %f, fMaxExposure: %f);\n",
            self->Unk_Frame(self->field_298), self->field_298, view, minExposure, maxExposure);
    if (minExposure > maxExposure) {
        return -6;
    }
    if (view == -1) {
        view = self->field_298;
    }
    s32 result = 0;
    if (self->field_400 < 1) {
        return 0;
    }
    if (view == 0x7fffffff) {
        for (s32 i = 0; i < self->field_400; i++) {
            PPFX::Unk_429da0_Item& item = self->field_2a0[i];
            if (item.field_70 == nullptr) {
                result = 1;
            }
            item.field_30 = minExposure;
            item.field_34 = maxExposure;
        }
    } else {
        for (s32 i = 0; i < self->field_400; i++) {
            if (i == view) {
                PPFX::Unk_429da0_Item& item = self->field_2a0[i];
                if (item.field_70 == nullptr) {
                    result = 1;
                }
                item.field_30 = minExposure;
                item.field_34 = maxExposure;
            }
        }
    }
    return result;
}

// 0x7100424740: CPostEffect::SetAutoExposureEnable
// NON_MATCHING: as Unk_425170, the operands of the `and` and the registers of
// the count and two temporaries.
s32 Unk_424740(u64 self_, s32 view, u32 enable_) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    bool enable = enable_ & 1;
#line 18677
    PPFX_FN("Frame: %d, View: %d, SetAutoExposureEnable(iEffectViewIndex: %d, bAutoExposureEnable: %s);\n",
            self->Unk_Frame(self->field_298), self->field_298, view, enable ? "true" : "false");
    if (view == -1) {
        view = self->field_298;
    }
    s32 result = 0;
    if (self->field_400 < 1) {
        return 0;
    }
    if (view == 0x7fffffff) {
        for (s32 i = 0; i < self->field_400; i++) {
            PPFX::Unk_429da0_Item& item = self->field_2a0[i];
            bool available = item.field_70 != nullptr;
            item.field_0 = available && enable;
            if (!available) {
                result = 1;
            }
        }
    } else {
        for (s32 i = 0; i < self->field_400; i++) {
            if (i == view) {
                PPFX::Unk_429da0_Item& item = self->field_2a0[i];
                bool available = item.field_70 != nullptr;
                item.field_0 = available && enable;
                if (!available) {
                    result = 1;
                }
            }
        }
    }
    return result;
}

// 0x7100424c90: CPostEffect::SetAutoExposureMiddleGray
s32 Unk_424c90(u64 self_, s32 view, f32 middleGray, f32 glare) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
#line 18932
    PPFX_FN("Frame: %d, View: %d, SetAutoExposureMiddleGray(iEffectViewIndex: %d, fMiddleGray: %f, fInfluencedByGlare: %f);\n",
            self->Unk_Frame(self->field_298), self->field_298, view, middleGray, glare);
    if (view == -1) {
        view = self->field_298;
    }
    s32 result = 0;
    if (self->field_400 < 1) {
        return 0;
    }
    if (view == 0x7fffffff) {
        for (s32 i = 0; i < self->field_400; i++) {
            PPFX::Unk_429da0_Item& item = self->field_2a0[i];
            if (item.field_70 == nullptr) {
                result = 1;
            }
            item.field_4 = middleGray;
            item.field_8 = glare;
        }
    } else {
        for (s32 i = 0; i < self->field_400; i++) {
            if (i == view) {
                PPFX::Unk_429da0_Item& item = self->field_2a0[i];
                if (item.field_70 == nullptr) {
                    result = 1;
                }
                item.field_4 = middleGray;
                item.field_8 = glare;
            }
        }
    }
    return result;
}

// 0x7100424de0: CPostEffect::SetAutoExposureMiddleGray (its log line's name),
// the delay
s32 Unk_424de0(u64 self_, s32 view, u32 mode, f32 delay) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
#line 19112
    PPFX_FN("Frame: %d, View: %d, SetAutoExposureMiddleGray(iEffectViewIndex: %d, eDelayMode: %d, fDelayTime: %f);\n",
            self->Unk_Frame(self->field_298), self->field_298, view, mode, delay);
    if (view == -1) {
        view = self->field_298;
    }
    s32 result = 0;
    if (self->field_400 < 1) {
        return 0;
    }
    if (view == 0x7fffffff) {
        for (s32 i = 0; i < self->field_400; i++) {
            PPFX::Unk_429da0_Item& item = self->field_2a0[i];
            if (item.field_70 == nullptr) {
                result = 1;
            }
            item.field_28 = mode;
            item.field_2c = delay;
        }
    } else {
        for (s32 i = 0; i < self->field_400; i++) {
            if (i == view) {
                PPFX::Unk_429da0_Item& item = self->field_2a0[i];
                if (item.field_70 == nullptr) {
                    result = 1;
                }
                item.field_28 = mode;
                item.field_2c = delay;
            }
        }
    }
    return result;
}

// the identity (inline)
static inline void Unk_Identity(PPFX::MATRIXT44* out) {
    out->field_0[3][2] = out->field_0[3][1] = out->field_0[3][0] = out->field_0[2][3] = out->field_0[2][1] =
        out->field_0[2][0] = out->field_0[1][3] = out->field_0[1][2] = out->field_0[1][0] = out->field_0[0][3] =
            out->field_0[0][2] = out->field_0[0][1] = 0.0f;
    out->field_0[0][0] = out->field_0[1][1] = out->field_0[2][2] = out->field_0[3][3] = 1.0f;
}

// 0x71004255b0: resets colour matrix `index` (-2: all of them)
s32 Unk_4255b0(u64 self_, u32 index_) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    s32 index = index_;
    if (index == -2) {
        for (s32 i = 0; i < 6; i++) {
            Unk_Identity(&self->field_9b4[i]);
            self->field_b34[i] = false;
        }
    } else {
        Unk_Identity(&self->field_9b4[index]);
        self->field_b34[index] = false;
    }
    return 0;
}

// 0x71024e09bc (placeholder)
extern s32 Unk_24e09bc;
// 0x71024e09c0, 0x71024e09c8: the memory pool storage buffer and its size
extern u64 Unk_24e09c0;
extern s32 Unk_24e09c8;

// 0x710043b590: the key of a device texture (placeholder signature)
u64 Unk_43b590(void* self, u64 arg1, u64 arg2, u64 arg3);

// 0x710043f080
namespace PPFX {
s32 Unk_43f080(IGPUDevice* self);
}

// 0x710043b9d0
s32 Unk_43b9d0(u64 self_, u64 arg1, u64 arg2, u64, u64) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    auto it = self->field_11e8.find(std::make_pair(arg1, arg2));
    if (it == self->field_11e8.end()) {
        return -6;
    }
    s32 result = self->Unk_4399e0(it->second.first, nullptr);
    if (result == 0) {
        if (it->second.first != nullptr) {
            it->second.first->vf3();
            it->second.first = nullptr;
        }
        if (it->second.second != nullptr) {
            it->second.second->vf3();
            it->second.second = nullptr;
        }
        self->field_11e8.erase(it);
    }
    PPFX::Unk_43f080(self->field_18);
    return result;
}

// 0x710043bb50
s32 Unk_43bb50(u64 self_, u64 arg1, u64 arg2, u64, u64) {
    PPFX::CPostEffect* self = reinterpret_cast<PPFX::CPostEffect*>(self_);
    auto it = self->field_11d0.find(std::make_pair(arg1, arg2));
    if (it == self->field_11d0.end()) {
        return -6;
    }
    s32 result = self->Unk_439c10(it->second.first, nullptr);
    if (result != 0) {
        return result;
    }
    PPFX::CTextureUtil* util = PPFX::Unk_GetTextureUtil();
    PPFX::Unk_ReleaseTextureUtil();
    if (util != nullptr && util->field_30.field_0 != nullptr && util->field_30.field_0->field_78 != nullptr) {
        util->field_30.field_0->field_78->Unk_44def0();
    }
    if (it->second.first != nullptr) {
        it->second.first->vf3();
        it->second.first = nullptr;
    }
    if (it->second.second != nullptr) {
        SiSDK3::ISiAllocator* allocator = SiSDK3::Unk_NXKernel()->vf6();
        if (allocator != nullptr && it->second.second != nullptr) {
#line 42359
            allocator->vf9(it->second.second, __FILE__, __LINE__);
        }
        it->second.second = nullptr;
    }
    self->field_11d0.erase(it);
    return 0;
}

// 0x710043bde0
s32 Unk_43bde0(PPFX::CPostEffect* self, u64 arg1, u64 arg2, u32 arg3, u32 arg4, u32 format, u32 arg6, u32 arg7) {
    u64 key = self->Unk_423160(arg1, arg2, nullptr);
    PPFX::Unk_43c4e0* object = PPFX::Unk_MapFind(self->field_d8, key);
    if (object == nullptr) {
        s32 result = self->Unk_4397e0(key, arg3, arg4, format, arg6, arg7, &object);
        if (result < 0) {
            return result;
        }
    }
    self->field_120 = object;
    self->field_128 = 0;
    self->field_130 = 0;
    self->field_1168 = 0;
    return 0;
}

// 0x710043bec0
s32 Unk_43bec0(PPFX::CPostEffect* self, u64 arg1, u64 arg2, u32 arg3, u32 arg4, u32 format) {
    u64 key = Unk_43b590(self, arg1, arg2, 0);
    PPFX::Unk_RenderTexture* texture = PPFX::Unk_MapFind(self->field_108, key);
    if (texture == nullptr) {
        s32 result = self->Unk_427c10(key, arg3, arg4, format, nullptr, &texture);
        if (result < 0) {
            return result;
        }
    }
    self->field_70 = texture;
    self->field_78 = 0;
    return 0;
}

// the formats 0x7100425410 and 0x7100428030 single out (inline)
static inline bool Unk_425410_Format(s32 format) {
    switch (format) {
    case 20:
    case 40:
    case 45:
    case 55:
        return true;
    default:
        return false;
    }
}

// what 0x7100425410 reads of its second kind of object (placeholder)
struct Unk_425410_Other {
    u8 pad_0[0x44];
    s32 field_44;  // the format
};

// the format of one of the two objects (inline)
static inline s32 Unk_425410_GetFormat(u64 object, u64 other) {
    if (object != 0) {
        return reinterpret_cast<PPFX::Unk_RenderTexture*>(object)->field_38;
    }
    return reinterpret_cast<Unk_425410_Other*>(other)->field_44;
}

// 0x7100425410: CPostEffect::SetDepthFactorSource (its log line names it)
// NON_MATCHING: the original keeps `has` a flag in w9 (cset, then tbz at
// each test) and sets the source to 3 before a branchy test of the format;
// here the tests use the pointers' `orr` again and the format's two
// conditions are merged with `ccmp`, and the stores of field_58 to field_6c
// come in another order. The scale and bias are selected as integers in both
// (Unk_Float).
s32 Unk_425410(PPFX::CPostEffect* self, u32 source, u64 object, u64 other, u32 mode, f32 scale, f32 bias) {
    self->field_895 = true;
    bool has = object != 0 || other != 0;
    if (source == 9) {
        if (has) {
            source = Unk_425410_Format(Unk_425410_GetFormat(object, other)) ? 0 : 3;
        } else {
            source = self->field_548 ? 8 : 3;
        }
    }
    if (mode == 5) {
        if (has) {
            mode = Unk_425410_Format(Unk_425410_GetFormat(object, other)) ? 0 : 2;
        } else {
            mode = source == 8 ? 0 : 2;
        }
    }
    if (has && !self->field_594) {
#line 40973
        PPFX_ERROR("CPostEffect::SetDepthFactorSource(): Initialize() with PFXINIT_DEPTHFACTORSOURCETEXTURE flag for user depth factor texture.\n");
        return -4;
    }
    bool use = has && source != 8;
    self->field_58 = source;
    self->field_5c = mode;
    self->field_50 = use ? reinterpret_cast<PPFX::Unk_RenderTexture*>(object) : nullptr;
    PPFX::Unk_Float s = use ? PPFX::Unk_Float(scale) : PPFX::Unk_Float(1.0f);
    PPFX::Unk_Float t = use ? PPFX::Unk_Float(bias) : PPFX::Unk_Float(0.0f);
    self->field_60 = s.field_0;
    self->field_64 = t.field_0;
    self->field_68 = 1.0f / s.field_0;
    self->field_6c = -t.field_0 / s.field_0;
    return 0;
}

// 0x710043b150: the same with a device texture (its render texture, made if
// it is neither one nor a device surface)
// NON_MATCHING: the original has one call of Unk_425410 (the object a phi,
// null for a device surface), with the floats copied into place first; with
// one call here the result's test becomes a select, so this has two, and
// the copies come in another order.
s32 PPFX::CPostEffect::Unk_43b150(u32 arg1, u64 key, u32 arg3, u32 arg4, u32 format, u32 arg6, f32 a, f32 b) {
    field_895 = true;
    Unk_RenderTexture* texture = Unk_MapFind(field_108, key);
    if (texture == nullptr) {
        Unk_43c490* surface = Unk_MapFind(field_f0, key);
        if (surface != nullptr) {
            return Unk_425410(this, arg1, 0, 0, arg6, a, b);
        }
        s32 result = Unk_427c10(key, arg3, arg4, format, &surface, &texture);
        if (result < 0) {
            return result;
        }
    }
    return Unk_425410(this, arg1, reinterpret_cast<u64>(texture), 0, arg6, a, b);
}

// 0x710043bf90
s32 Unk_43bf90(PPFX::CPostEffect* self, u32 arg1, u64 arg2, u64 arg3, u32 arg4, u32 arg5, u32 format, u32 arg7, f32 a,
               f32 b) {
    u64 key = Unk_43b590(self, arg2, arg3, 0);
    return self->Unk_43b150(arg1, key, arg4, arg5, format, arg7, a, b);
}

// 0x710043c020
s32 Unk_43c020(PPFX::CPostEffect* self, u32 arg1, u64 arg2, u64 arg3, u32 arg4, u32 arg5, u32 format) {
    u64 key = Unk_43b590(self, arg2, arg3, 0);
    return Unk_43a100(self, arg1, key, arg4, arg5, format);
}

// 0x710043c090
s32 Unk_43c090(PPFX::CPostEffect* self, u32 arg1, u64 arg2, u64 arg3, u32 arg4, u32 arg5, u32 format) {
    u64 key = Unk_43b590(self, arg2, arg3, 0);
    return Unk_43a280(self, arg1, key, arg4, arg5, format);
}

// 0x71024e09d0, 0x71024e09d8: the NVN texture and sampler pools the default
// callbacks register in
extern void* Unk_24e09d0;
extern void* Unk_24e09d8;

namespace PPFX {

// 0x710043b290
s32 CPostEffect::DefaultRegisterTextureHandleCallback_Nvn(const void* texture, const void* view) {
    CPostEffect* self = reinterpret_cast<CPostEffect*>(Unk_418e20_get());
    if (self == nullptr) {
        return -1;
    }
    if (self->field_1210.empty()) {
#line 42451
        PPFX_ERROR("CPostEffect::DefaultRegisterTextureHandleCallback_Nvn : reserved numIndices is empty.");
        return -1;
    }
    s32 index = self->field_1210.front();
    self->field_1210.pop_front();
    nvnTexturePoolRegisterTexture(Unk_24e09d0, index, texture, view);
    return index;
}

// 0x710043b370: gives an index back
void CPostEffect::Unk_43b370(s32 index) {
    CPostEffect* self = reinterpret_cast<CPostEffect*>(Unk_418e20_get());
    self->field_1210.push_back(index);
}

// 0x710043b3f0
s32 CPostEffect::DefaultRegisterSamplerHandleCallback_Nvn(const void* sampler) {
    CPostEffect* self = reinterpret_cast<CPostEffect*>(Unk_418e20_get());
    if (self == nullptr) {
        return -1;
    }
    if (self->field_1228.empty()) {
#line 42475
        PPFX_ERROR("CPostEffect::DefaultRegisterSamplerHandleCallback_Nvn : reserved numIndices is empty.");
        return -1;
    }
    s32 index = self->field_1228.front();
    self->field_1228.pop_front();
    nvnSamplerPoolRegisterSampler(Unk_24e09d8, index, sampler);
    return index;
}

// 0x710043b500: gives an index back
void CPostEffect::Unk_43b500(s32 index) {
    CPostEffect* self = reinterpret_cast<CPostEffect*>(Unk_418e20_get());
    self->field_1228.push_back(index);
}

}  // namespace PPFX

// 0x710043b920: CPostEffect::SetResourceMemoryAllocate_Nvn
s32 Unk_43b920(u64 buffer, u32 size_) {
    s32 size = size_;
    if (buffer != 0 && size < 0) {
#line 42394
        PPFX_ERROR("CPostEffect::SetResourceMemoryAllocate_Nvn() : (iMemoryPoolStorageBufferSizeInBytes < 0)&&(pMemoryPoolStorageBuffer!=NULL)\n");
        return 1;
    }
    Unk_24e09c0 = buffer;
    Unk_24e09c8 = size;
    return 0;
}

namespace PPFX {
class CRenderTexture;
}  // namespace PPFX

// 0x710043c530: the growth of a render texture's field_108 (0x710041afb0's,
// which isn't written yet)
template void std::vector<PPFX::CRenderTexture*, PPFX::Unk_StlAllocator<PPFX::CRenderTexture*>>::
    __push_back_slow_path<PPFX::CRenderTexture* const&>(PPFX::CRenderTexture* const&);

// 0x710049e3a0 (GPURenderTexture.cpp)
void Unk_49e3a0(u32 arg0, s32 arg1, s32 arg2, void* arg3, void* arg4, s32 arg5, void* arg6, void* arg7, f32 arg8);
// 0x710043fc30 (GPUInterfaceDevice.cpp)
s32 Unk_43fc30(void* device);
// 0x71004afa90, 0x71004afa70 (GPUDepthOfField.cpp, lib/yebis/leaf)
struct Unk_4afa90;
struct Unk_4afa70;
f32 Unk_4afa90_get(const Unk_4afa90* self);
f32 Unk_4afa70_get(const Unk_4afa70* self);

namespace PPFX {

// 0x7100438510: the end of the scene: the targets set back
s32 CPostEffect::Unk_438510() {
    if (field_1168 == field_20) {
        field_18->vf8(field_28);
    }
    field_18->vf44(0);
    field_18->vf41(-1, true);
    Unk_49e3a0(0x1f, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
    if (field_1) {
        field_1 = false;
        field_18->vf7(0, reinterpret_cast<void*>(field_1168), 0);
    }
    s32 result = Unk_43fc30(field_18);
    return result < 0 ? result : 0;
}

bool Unk_4385e0(s32 format);

// 0x7100429f20
// NON_MATCHING: the original reloads field_1a0 for the last call, as if
// Unk_4385e0 could write memory (here it is known not to, so field_1a0 stays
// in x19 and `this` doesn't: the prologue moves and the registers differ; with
// Unk_4385e0 only declared, that part matches); format0 is a select of two
// addresses here, a branch to each load in the original
s32 CPostEffect::Unk_429f20(bool set, bool enable) {
    Unk_4aa5a0_Self* dof = field_1a0;
    if (dof == nullptr) {
        return 0;
    }
    if (!set) {
        enable = field_914 != 0;
    }
    dof->field_1e0 = enable;
    Unk_RenderTexture* texture = Unk_41af70();
    s32 format0;
    if (texture != nullptr) {
        format0 = texture->field_38;
    } else {
        format0 = field_6a8;
    }
    s32 index = field_5e0;
    if (index == -1) {
        index = field_190->field_90;
    }
    s32 format1 = field_190->field_38[index]->field_38;
    s32 format2 = field_1a0->field_d4;
    // the fewest bits per channel of the three formats (~0: none known)
    s32 formats[3] = {format0, format1, format2};
    u32 bits = 0xffffffff;
    for (s32 i = 0; i < 3; i++) {
        switch (formats[i]) {
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 49:
        case 50:
        case 51:
        case 52:
        case 61:
        case 62:
        case 63:
        case 64:
        case 65:
        case 87:
        case 88:
        case 91:
        case 93:
            bits = bits < 8 ? bits : 8;
            break;
        case 11:
        case 12:
        case 13:
        case 14:
        case 35:
        case 36:
        case 37:
        case 38:
        case 55:
        case 56:
        case 57:
        case 58:
        case 59:
            bits = bits < 16 ? bits : 16;
            break;
        default:
            if (formats[i] != 0 && Unk_4385e0(formats[i])) {
                bits = bits < 24 ? bits : 24;
            }
            break;
        }
    }
    reinterpret_cast<CDepthOfField*>(field_1a0)->Unk_4aa030(bits == 0xffffffff ? 0 : bits);
    return 0;
}

// the greater of two values, by reference, the first one when they're equal
// (inline)
template <class T>
inline const T& Unk_Greater(const T& a, const T& b) {
    return a > b ? a : b;
}

// 0x710042b8a0: field_8f4 to field_8f8 follows field_6c4 to field_6c8 from
// last frame's range, and field_904 to field_908 follows that
// NON_MATCHING: scheduling only: the move of field_904's value into s1 and
// the store of field_908 come in the other order around the last select
s32 CPostEffect::Unk_42b8a0() {
    field_8f4 = field_8ec;
    field_8f8 = field_8f0;
    field_8f4 = std::max(field_6c4, field_8f4);
    field_8f4 = std::min(field_6c8 * 0.99f, field_8f4);
    f32 high = std::min(field_6c8, field_8f8);
    high = high <= 0.0f ? field_6c8 : high;
    if (high <= field_8f4) {
        high = (field_6c8 - field_8f4) * 0.01f + field_8f4;
    }
    field_8f8 = high;
    field_904 = field_8fc;
    field_908 = field_900;
    field_904 = Unk_Greater(field_904, field_8f4);
    field_904 = std::min(field_8f8 * 0.99f, field_904);
    f32 high2 = std::min(field_8f8, field_908);
    field_908 = high2 <= 0.0f ? field_8f8 : high2;
    if (field_908 <= field_904) {
        field_908 = (field_8f8 - field_904) * 0.01f + field_904;
        field_908 = std::min(field_8f8, field_908);
    }
    return 0;
}

// whether a format's channels are 32-bit floats (inline)
static inline bool Unk_IsFloat32Format(s32 format) {
    switch (format) {
    case 2:
    case 6:
    case 16:
    case 20:
    case 21:
    case 40:
    case 41:
        return true;
    default:
        return false;
    }
}
// whether they are 16-bit floats or shared-exponent ones (inline)
static inline bool Unk_IsFloat16Format(s32 format) {
    switch (format) {
    case 10:
    case 34:
    case 54:
    case 67:
        return true;
    default:
        return false;
    }
}
// the linear format of an sRGB one (inline)
static inline s32 Unk_LinearFormat(s32 format) {
    switch (format) {
    case 29:
        return 28;
    case 72:
        return 71;
    case 75:
        return 74;
    case 78:
        return 77;
    case 91:
        return 87;
    case 93:
        return 88;
    case 99:
        return 98;
    default:
        return format;
    }
}

// what render target the frame's feedback is in (inline)
inline Unk_RenderTexture* CPostEffect::Unk_FeedbackTexture() {
    if (field_260 == nullptr) {
        return nullptr;
    }
    s32 view = field_298;
    Unk_4a5d10_Self* textures = field_260[view];
    s32 index = field_290[view] & 1;
    if (index < textures->field_30) {
        return textures->field_38[index];
    }
    return nullptr;
}

// field_278, else the feedback texture (inline)
inline Unk_RenderTexture* CPostEffect::Unk_428f00_Copy() {
    if (field_278 != nullptr) {
        return field_278;
    }
    return Unk_FeedbackTexture();
}

// texture field_670 (-1: the current one) of `textures` (inline)
inline Unk_RenderTexture* CPostEffect::Unk_428f00_Previous(Unk_4a5d10_Self* textures) {
    s32 index = field_670;
    if (index == -1) {
        index = textures->field_90;
    }
    if (index < textures->field_30) {
        return textures->field_38[index];
    }
    return nullptr;
}

// what 0x7100428f00 reads of field_1168 (placeholder)
struct Unk_428f00_Target {
    u8 pad_0[0x4c];
    u32 field_4c;
    u32 field_50;
};

// 0x7100428f00: the render target the feedback is read from
// NON_MATCHING: the format test and the size comparisons are the original's;
// after them the original has one block for each of field_278's and
// field_670's paths (the second tests field_970 again when it is entered from
// the size branch), where here the paths are duplicated (844 bytes, not 704).
// Tried: the tests nested, field_970 tested in the field_670 helper, one
// return at the end.
Unk_RenderTexture* CPostEffect::Unk_428f00() {
    // CPostEffect::GetEffectiveFeedbackEnable(), its log line says
    bool feedback = field_bce;
    if (field_96c && field_970 != 0 && feedback) {
        s32 format = field_518;
        bool f32 = Unk_IsFloat32Format(format);
        if (!(Unk_IsFloat16Format(format) || ((format == 26) | f32))) {
#line 16846
            PPFX_WARNING("CPostEffect::GetEffectiveFeedbackEnable(): The feedback result will be clamped because the feedback buffer format is not floating point. Use PFXOETA_IMMEDIATE_IMPLICIT oetf or set floating point format to PFX_INITPARAM::m_eFeedbackFormat.\n");
        }
    }
    if (feedback) {
        return Unk_FeedbackTexture();
    }
    s32 count = field_f30;
    if (count == -1) {
        count = field_f2c;
    }
    s32 index = field_66c;
    Unk_4a5d10_Self* textures = field_190;
    if (index == -1) {
        index = textures->field_90;
    }
    Unk_RenderTexture* texture = textures->field_38[index];
    const Unk_428f00_Target* target = reinterpret_cast<const Unk_428f00_Target*>(field_1168);
    if ((texture->field_54 != static_cast<u32>(field_5a4 * static_cast<f32>(target->field_4c)) ||
         texture->field_58 != static_cast<u32>(field_5a8 * static_cast<f32>(target->field_50))) &&
        count >= 1) {
        if (!field_96c && Unk_24e09bc == 0) {
            return Unk_428f00_Copy();
        }
        if (field_96c && field_970 != 0) {
            return Unk_428f00_Previous(textures);
        }
    }
    if (!field_10d6) {
        return nullptr;
    }
    if (field_96c && field_970 != 0) {
        return Unk_428f00_Previous(textures);
    }
    return Unk_428f00_Copy();
}

// 0x710042f070 (its log line names it)
s32 CPostEffect::ApplyEffects_DepthOfField() {
    if (!field_104f) {
        return 0;
    }
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    Unk_4a5d10_Self* textures = field_190;
    textures->field_90 = field_60c;
    Unk_42e560();
    f32 scale = field_8b0;
    f32 a = field_8cc;
    f32 b = field_8d0;
    s32 mode = field_69c;
    if (scale != 1.0f) {
        if (mode == 0) {
            mode = 11;
            a = 1.0f;
            b = a / scale;
        } else {
            b = b / scale;
        }
    }
    reinterpret_cast<CDepthOfField*>(field_1a0)->Unk_4aeed0(mode, -1, -1);
    util->Unk_470610(a, b);
    f32 exposure = field_8c0.field_0;
    Unk_4aa5a0_Self* dof = field_1a0;
    dof->field_3ac = exposure / (field_59a ? exposure * field_7fc : field_7f8);
    s32 result = reinterpret_cast<CDepthOfField*>(field_1a0)
                     ->ApplyDepthOfField(reinterpret_cast<CRenderTexture*>(Unk_TextureAt(field_604)),
                                         Unk_TextureAt(field_608),
                                         reinterpret_cast<CRenderTexture*>(Unk_TextureAt(field_60c)), true);
    if (result < 0) {
#line 25785
        PPFX_ERROR("CPostEffect::ApplyEffects_DepthOfField(): m_pDepthOfField->ApplyDepthOfField() failed (0x%x: %s).\n",
                   result, Unk_446df0(result));
    }
    field_67a = true;
    return result;
}

// 0x710042bbe0: `source` (null: Unk_41af70's) drawn into each of
// field_550's textures that is narrower than the last one drawn; the last of
// them, if anything was drawn
Unk_RenderTexture* CPostEffect::Unk_42bbe0(Unk_RenderTexture* source) {
    if (source == nullptr) {
        source = Unk_41af70();
    }
    if (field_558 == 0) {
        return source;
    }
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    bool drawn = false;
    Unk_RenderTexture* current = source;
    Unk_RenderTexture* target;
    for (s32 i = 0; i < field_558; i++) {
        target = field_550[i];
        if (target->field_54 < current->field_54) {
            Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
            Unk_Float4 offset(0.0f, 0.0f, 0.0f, 0.0f);
            drawn = true;
            util->Unk_47dfa0(0.0f, 0.0f, 0.0f, 1.0f, current, reinterpret_cast<CRenderTexture*>(target), 0, &color, 0,
                             false, false, 1, &offset, nullptr, -1);
            current = target;
        }
    }
    return drawn ? target : source;
}

// 0x710042cba0
s32 CPostEffect::Unk_42cba0(bool arg) {
    if ((field_1051 || field_50 != nullptr) && !field_1053) {
        bool flag = true;
        if (!field_18->field_14efa) {
            Unk_49e3a0(1, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
            reinterpret_cast<CRenderTextureArray*>(field_190)->Unk_4a5ff0(1, 0x7fffffff);
            flag = false;
        }
        void* a6 = nullptr;
        u32 a7 = 0;
        u32 a8 = 2;
        u32 a9 = 0;
        f32 a10 = 0.0f;
        if (arg) {
            a6 = field_80;
            a7 = field_8c;
            a8 = field_90;
            a9 = field_94;
            a10 = field_98;
        }
        Unk_42cc90(-1, 0, nullptr, nullptr, flag, a6, a7, a8, a9, a10);
    }
    return 0;
}

// 0x71004280e0: a number by field_1008's mode (tan of half of field_6cc)
// NON_MATCHING: the default case's multiplication by 0 is merged into the
// others' (the original keeps its own block that loads field_100c into s0 and
// 0 into s1); the rest is the same
f32 CPostEffect::Unk_4280e0() {
    f32 value;
    switch (field_1008) {
    case 0:
        value = 1.1996114f - tanf(field_6cc * 0.5f);
        break;
    case 1:
        value = -0.09597635f - logf(tanf(field_6cc * 0.5f));
        break;
    case 2:
        value = 1.0f / tanf(field_6cc * 0.5f) * 0.2f + 0.30255502f;
        break;
    case 3:
        value = field_100c;
        break;
    default:
        value = 0.0f;
        break;
    }
    if (field_1008 == 3) {
        return value + field_1010;
    }
    f32 result = value * field_100c + field_1010;
    if (field_1a0 != nullptr && Unk_4afa90_get(reinterpret_cast<const Unk_4afa90*>(field_1a0)) > 0.0f) {
        result += Unk_4afa70_get(reinterpret_cast<const Unk_4afa70*>(field_1a0)) * -0.5f;
    }
    return result;
}

// 0x71004622e0 (GPUTextureUtil.cpp)
bool Unk_4622e0(f32 low, f32 high, f32 current, f32 previous);

// the smaller and the larger of two numbers (inline)
static inline const f32& Unk_Less(const f32& a, const f32& b) {
    return a < b ? a : b;
}
static inline const f32& Unk_Greater(const f32& a, const f32& b) {
    return a > b ? a : b;
}

// 0x7100427ad0: whether field_6c4 or field_6c8 is to change (each limited by
// field_8f4 to field_8f8 and by field_90c and field_910)
// NON_MATCHING: the original folds the last two selects into one with a
// `fccmp` (select(next < current && now < before, before, current)); one
// instruction more here
bool CPostEffect::Unk_427ad0() {
    f32 low = field_8f4;
    f32 x = field_90c;
    if (x > 0.0f) {
        f32 high = field_8f8;
        low = x < low ? low : (x > high ? high : x);
        f32 y = field_910;
        if (y > 0.0f) {
            low = Unk_Less(low, y);
        }
    }
    f32 current = field_6c4;
    f32 before = field_ef0;
    f32 now = field_eec;
    if (Unk_4622e0(current, field_6c8, now, before)) {
        f32 next = now > before ? before : current;
        current = next > current ? next : current;
    }
    if ((low > current ? low : current) != field_6c4) {
        return true;
    }
    f32 high = field_8f8;
    f32 y = field_910;
    if (y > 0.0f) {
        f32 low2 = field_8f4;
        high = y < low2 ? low2 : (y > high ? high : y);
        f32 x2 = field_90c;
        if (x2 > 0.0f) {
            high = Unk_Greater(high, x2);
        }
    }
    current = field_6c8;
    before = field_ef0;
    now = field_eec;
    if (Unk_4622e0(field_6c4, current, now, before)) {
        f32 next = now < before ? before : current;
        current = Unk_Less(next, current);
    }
    return (high < current ? high : current) != field_6c8;
}

// 0x7100429c50: field_b3c after field_1094 if field_b84 and field_ba4 differ
// (and `arg`)
MATRIXT44 CPostEffect::Unk_429c50(bool arg) {
    MATRIXT44 result;
    Unk_Identity(&result);
    if (arg) {
        for (s32 i = 0; i < 8; i++) {
            if (field_b84[i] != field_ba4[i]) {
                MATRIXT44 m = field_1094;
                MATRIXT44_MatrixMultiply(&result, &result, &m);
                break;
            }
        }
    }
    MATRIXT44_MatrixMultiply(&result, &result, &field_b3c);
    return result;
}

// 0x71004385e0: whether a format is a fixed-point one
// NON_MATCHING: here the three switches become one table; the original keeps
// one table for the 32-bit floats and the sRGB formats (case 0 on its own),
// then a bit test for the 16-bit ones, and combines the results with `bic`
bool Unk_4385e0(s32 format) {
    if (Unk_IsFloat32Format(format)) {
        return false;
    }
    s32 linear = Unk_LinearFormat(format);
    if (linear != 0 && Unk_IsFloat16Format(linear)) {
        return false;
    }
    return linear != 26;
}

// 0x7100434570: whether field_848 and the colour of field_f84 are positive
// NON_MATCHING: the comparison of field_848 is sunk to its use here (the
// original sets w20 with `cset` before the branch), and the colour space's
// address is kept in x20 across the calls (the original materialises it again
// for Unk_411b00's arguments)
bool CPostEffect::Unk_434570() {
    bool result = field_848 > 0.0f;
    if (field_f80 == -1) {
        Unk_410f90 space;
        Unk_410f90_set(&space, 0);
        if (Unk_Luminance(space, field_f84.field_0) <= 0.0f) {
            result = false;
        }
    }
    return result & (field_f80 != 0);
}

}  // namespace PPFX

// the formats 0x7100428030 takes at once (inline)
static inline bool Unk_428030_A(s32 format) {
    switch (format) {
    case 4:
    case 8:
    case 13:
    case 14:
    case 18:
    case 31:
    case 37:
    case 38:
    case 43:
    case 51:
    case 52:
    case 58:
    case 59:
    case 63:
    case 64:
    case 81:
    case 84:
        return true;
    default:
        return false;
    }
}

// 0x7100428030: whether a format is one of a kind (placeholder)
// NON_MATCHING: the original's table also covers case 0 (straight to the
// return of false) and the 32-bit floats' flag comes out of it in w8; here
// the zero test of the linear format stays a cbnz after the 16-bit test.
// Tried: the tests in other orders, the linear format left out, a zero test
// first, the result's last test on the linear format
bool Unk_428030(s32 format) {
    if (Unk_428030_A(format)) {
        return true;
    }
    bool f32 = PPFX::Unk_IsFloat32Format(format);
    s32 linear = PPFX::Unk_LinearFormat(format);
    if (!((linear != 0 && PPFX::Unk_IsFloat16Format(linear)) || ((format == 26) | f32))) {
        return false;
    }
    if (Unk_425410_Format(format)) {
        return false;
    }
    return format != 26;
}

namespace PPFX {

// 0x7100425dd0
s32 CPostEffect::InitializeAutoExposure(s32 view, f32 luminance, f32 adjusted) {
#line 18381
    PPFX_FN("Frame: %d, View: %d, InitializeAutoExposure(iEffectViewIndex: %d, fSceneLuminance: %f, fCurrentAutoExposureAdjusted: %f);\n",
            Unk_Frame(field_298), field_298, view, luminance, adjusted);
    if (view == -1) {
        view = field_298;
    }
    BeginCommandList_SiGfx();
    for (s32 i = 0; i < field_400; i++) {
        if (view == 0x7fffffff || i == view) {
            Unk_429da0_Item* item = &field_2a0[i];
            if (item->field_70 != nullptr) {
                f32 range = item->field_38 > adjusted ? item->field_40 : item->field_4c;
                f32 target = logf(adjusted) / 0.6931472f;
                f32 current = logf(item->field_38) / 0.6931472f;
                f32 exposure = exp2f(current + (target - current) / fmaxf(range, 0.001f));
                CTextureLuminanceManage* manage = static_cast<CTextureLuminanceManage*>(item->field_70);
                CTextureLuminanceManage::Unk_Value v;
                v.field_0[2] = luminance;
                v.field_0[3] = luminance;
                v.field_0[0] = luminance;
                v.field_0[1] = luminance;
                manage->Unk_4b9140(&v, true, luminance, exposure, 1.0f, field_6c4, field_6c8);
            }
            item->field_5c = luminance;
            item->field_60 = adjusted;
            item->field_54 = 0;
            item->field_58 = 0;
            item->field_64 = false;
            item->field_68 = 5;
        }
    }
    return Unk_426210();
}

// 0x7100426070: the exposure history reset to `value` (when not positive, the
// mean of field_6c4 and field_6c8's arithmetic and harmonic means)
s32 CPostEffect::Unk_426070(s32 view, f32 value) {
    if (value <= 0.0f) {
        f32 inv = (1.0f / field_6c4 + 1.0f / field_6c8) * 0.5f;
        f32 mean = (field_6c4 + field_6c8) * 0.5f;
        value = (mean + 1.0f / inv) * 0.5f;
    }
    if (view == -1) {
        view = field_298;
    }
    BeginCommandList_SiGfx();
    for (s32 i = 0; i < field_400; i++) {
        if (view == 0x7fffffff || i == view) {
            Unk_429e60_Item* item = &field_2a8[i];
            CTextureLuminanceManage* luminance = static_cast<CTextureLuminanceManage*>(item->field_48);
            if (luminance != nullptr) {
                // the original stores the second half first
                CTextureLuminanceManage::Unk_Value v;
                v.field_0[2] = value;
                v.field_0[3] = value;
                v.field_0[0] = value;
                v.field_0[1] = value;
                luminance->Unk_4b9140(&v, true, value, field_8c0.field_0, 1.0f, field_6c4, field_6c8);
            }
            item->field_34 = value;
            item->field_38 = value;
            item->field_2c = 0;
            item->field_30 = 0;
            item->field_3c = false;
            item->field_40 = 5;
        }
    }
    return Unk_426210();
}

}  // namespace PPFX
