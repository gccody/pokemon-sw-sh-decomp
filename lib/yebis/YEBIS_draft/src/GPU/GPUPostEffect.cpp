// Scope: common
// PPFX::CPostEffect (C:/workspace/YEBIS_draft/src/GPU/GPUPostEffect.cpp, the
// __FILE__ of its log lines).
#include <yebis/YEBIS_draft/include/PPFX/Unk_ColorSpace.h>
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

}  // namespace PPFX
