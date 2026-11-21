// Scope: common
// PPFX::CPostEffect (C:/workspace/YEBIS_draft/src/GPU/GPUPostEffect.cpp, the
// __FILE__ of its log lines).
#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>
#include <yebis/YEBIS_draft/src/GPU/GPUPostEffect.h>

#define PPFX_FILE "C:/workspace/YEBIS_draft/src/GPU/GPUPostEffect.cpp"
#include <yebis/YEBIS_draft/src/GPU/Unk_Log.h>

namespace PPFX {

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
s32 Unk_423990(u64 self_, u32 enable_) {
    return reinterpret_cast<PPFX::CPostEffect*>(self_)->SetLightShaftEnable(enable_ & 1);
}

// 0x7100423ba0: CPostEffect::SetLightGhostEnable
s32 Unk_423ba0(u64 self_, u32 enable_) {
    return reinterpret_cast<PPFX::CPostEffect*>(self_)->SetLightGhostEnable(enable_ & 1);
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
