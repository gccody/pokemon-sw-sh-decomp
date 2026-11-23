// Scope: common
// PPFX::CDepthOfField (lib/yebis/YEBIS_draft/src/GPU/GPUDepthOfField.h): so
// far its destructors and three small virtual functions. The TU has statics
// of its own besides the common ones (its static initialiser, 0x71004b72d0,
// is 716 bytes), so Unk_Statics.h isn't included until they're known.
#include <math.h>

#include <yebis/YEBIS_draft/src/GPU/GPUClassUtil.h>
#include <yebis/YEBIS_draft/src/GPU/GPUDepthOfField.h>
#include <yebis/YEBIS_draft/src/GPU/TinyEffect/TFXString.h>

#define PPFX_FILE "C:/workspace/YEBIS_draft/src/GPU/GPUDepthOfField.cpp"
#include <yebis/YEBIS_draft/src/GPU/Unk_Log.h>

// 0x7100446df0: a result's name (Unk_447050.cpp)
const char* Unk_446df0(s32 result);

// 0x710049c8d0 (lib/yebis/leaf)
s32 Unk_49c8d0_call(void* self, void* value);

// 0x7100440c00 (lib/yebis/leaf)
u32 Unk_440c00_get(u64 device, u32 arg);

namespace PPFX {

// 0x7101eba3f4: "CDepthOfField"
extern const char Unk_1eba3f4[];

// 0x71004a7630
CDepthOfField::CDepthOfField(const char* name) : CGPUResourceManage(nullptr) {
    Unk_4a7760(name);
}

// 0x71004a7760
s32 CDepthOfField::Unk_4a7760(const char* name) {
    if (name != nullptr && name[0] != '\0') {
        field_10 = Unk_TFXString(Unk_1eba3f4) + " " + name;
    } else {
        field_10 = Unk_1eba3f4;
    }
    field_2c.Unk_Reset();
    field_c0.Unk_Reset();
    field_180 = 0;
    field_16c = 0;
    field_170 = 0;
    field_248 = 0;
    field_2c0 = 0;
    field_3f8 = 0;
    field_238 = nullptr;
    field_184 = false;
    field_188 = 0.0f;
    field_18c = 0.0f;
    field_198 = 0.0f;
    field_1c4 = 0.0f;
    field_1e4 = 0.0f;
    field_1a8 = 0.0f;
    field_1ac = 0.0f;
    field_1b0 = 0.0f;
    field_1b4 = 0.0f;
    field_1b8 = 0.0f;
    field_21c = 0;
    field_220 = 0;
    field_224 = 0;
    field_228 = nullptr;
    field_158 = 0;
    field_160 = 0;
    field_258 = 0;
    field_260 = 0;
    field_268 = 0;
    field_270 = 0;
    field_278 = 0;
    field_280[0] = 0;
    field_280[1] = 0;
    field_280[2] = 0;
    field_280[3] = 0;
    field_280[4] = 0;
    for (s32 i = 0; i < 5; i++) {
        field_2c8[i] = 0;
    }
    field_2f0 = 0;
    for (s32 i = 0; i < 12; i++) {
        field_2f8[i] = 0;
    }
    for (s32 i = 0; i < 8; i++) {
        field_358[i] = nullptr;
    }
    field_398 = nullptr;
    field_3a0 = 0;
    field_400 = nullptr;
    field_408 = nullptr;
    field_410 = nullptr;
    field_418 = nullptr;
    field_420 = nullptr;
    field_428 = nullptr;
    field_430 = nullptr;
    field_438 = nullptr;
    field_440 = 0;
    field_448 = nullptr;
    field_450 = nullptr;
    field_458 = 0;
    field_460 = 0;
    field_468 = nullptr;
    field_470 = nullptr;
    field_478 = 0;
    field_480 = 0;
    field_488 = nullptr;
    field_490 = nullptr;
    field_498 = 0;
    field_4a0 = nullptr;
    field_4a8 = nullptr;
    return 0;
}

// 0x71004aa290: hands `arg` to every render texture (0x710049c8d0)
s32 CDepthOfField::Unk_4aa290(void* arg) {
    s32 result = field_4a0->Unk_49fed0(arg);
    if (field_248 != nullptr && field_248 != field_228)
        result = Unk_49c8d0_call(field_248, arg);
    for (s32 i = 0; i <= field_3f8; i++) {
        if (field_430 != nullptr && field_430[i] != nullptr && field_430[i] != field_228)
            result = Unk_49c8d0_call(field_430[i], arg);
        if (i < field_3f8) {
            if (field_438 != nullptr)
                result = Unk_49c8d0_call(field_438[i], arg);
            if (field_440 != nullptr && field_440[i] != nullptr)
                result = Unk_49c8d0_call(field_440[i], arg);
            if (field_448 != nullptr && field_448[i] != nullptr)
                result = Unk_49c8d0_call(field_448[i], arg);
            if (field_450 != nullptr && field_450[i] != nullptr)
                result = Unk_49c8d0_call(field_450[i], arg);
            if (field_468 != nullptr && field_468[i] != nullptr)
                result = Unk_49c8d0_call(field_468[i], arg);
            if (field_470 != nullptr && field_470[i] != nullptr)
                result = Unk_49c8d0_call(field_470[i], arg);
            if (field_458 != nullptr && field_458[i] != nullptr)
                result = Unk_49c8d0_call(field_458[i], arg);
            if (field_460 != nullptr && field_460[i] != nullptr)
                result = Unk_49c8d0_call(field_460[i], arg);
            if (field_478 != nullptr && field_478[i] != nullptr)
                result = Unk_49c8d0_call(field_478[i], arg);
            if (field_480 != nullptr && field_480[i] != nullptr)
                result = Unk_49c8d0_call(field_480[i], arg);
            if (field_488 != nullptr)
                result = Unk_49c8d0_call(field_488[i], arg);
        }
    }
    for (s32 i = 0; i < field_498; i++) {
        result = Unk_49c8d0_call(field_490[i], arg);
    }
    for (s32 i = 0; i < field_c0.field_10; i++) {
        Unk_Level* level = &field_4a8[i];
        if (field_c0.field_64) {
            if (level->field_80 != nullptr)
                result = Unk_49c8d0_call(level->field_80, arg);
            if (level->field_88 != nullptr)
                result = Unk_49c8d0_call(level->field_88, arg);
            if (level->field_90 != nullptr)
                result = Unk_49c8d0_call(level->field_90, arg);
            if (level->field_98 != nullptr)
                result = Unk_49c8d0_call(level->field_98, arg);
        } else {
            result = Unk_49c8d0_call(level->field_a0, arg);
            if (level->field_a8 != nullptr)
                result = Unk_49c8d0_call(level->field_a8, arg);
        }
        CRenderTexture* first = level->field_48[0];
        CRenderTexture* second = level->field_48[1];
        CRenderTexture* third = level->field_48[2];
        if (first != nullptr)
            result = Unk_49c8d0_call(first, arg);
        if (second != nullptr)
            result = Unk_49c8d0_call(second, arg);
        // (the original tests the third and passes the second)
        if (third != nullptr)
            result = Unk_49c8d0_call(second, arg);
        if (level->field_b0 != nullptr)
            result = Unk_49c8d0_call(level->field_b0, arg);
        if (level->field_b8 != nullptr)
            result = Unk_49c8d0_call(level->field_b8, arg);
    }
    return result;
}

// 0x71004aa790, 0x71004aa7d0
CDepthOfField::~CDepthOfField() {
    Unk_49ec80();
}

// 0x71004aa810
s32 CDepthOfField::vf0(IGPUDevice* device) {
    s32 result = CGPUResourceManage::vf0(device);
    if (result < 0)
        return result;
    if (field_20 == nullptr)
        return 0;
    result = Unk_4aa860();
    return result < 0 ? result : 0;
}

// 0x71004ac220
s32 CDepthOfField::vf1() {
    field_4a0->vf1();
    for (s32 i = 0; i < field_c0.field_10; i++) {
        Unk_Level* level = &field_4a8[i];
        if (field_c0.field_64) {
            if (level->field_80 != nullptr)
                level->field_80->vf1();
            if (level->field_88 != nullptr)
                level->field_88->vf1();
        } else {
            level->field_a0->vf1();
        }
        for (s32 j = 0; j < field_180; j++) {
            if (level->field_48[j] != nullptr)
                level->field_48[j]->vf1();
        }
        if (level->field_a8 != nullptr && level->field_a8 != level->field_48[0]) {
            if (field_c0.field_64) {
                if (level->field_90 != nullptr)
                    level->field_90->vf1();
                if (level->field_98 != nullptr)
                    level->field_98->vf1();
            } else {
                level->field_a8->vf1();
            }
        }
        if (level->field_b0 != nullptr)
            level->field_b0->vf1();
        if (level->field_b8 != nullptr)
            level->field_b8->vf1();
    }
    return CGPUResourceManage::vf1();
}

// 0x71004ac3a0
s32 CDepthOfField::vf2() {
    s32 result = CGPUResourceManage::vf2();
    if (result < 0)
        return result;
    if (Unk_4a7390(field_228, &field_c0) < 0)
        return -1;
    for (s32 i = 0; i < field_c0.field_10; i++) {
        if (field_4a8[i].field_a0->field_2c.field_c == 0)
            return -1;
    }
    return 0;
}

// 0x71004aa030
// NON_MATCHING: in the block the 8 and 24 paths share, the store and the move of the
// constant the last test uses are the other way round.
s32 CDepthOfField::Unk_4aa030(s32 value) {
    if (value >= 0) {
        field_170 = value;
    } else {
        field_170 = 0;
        switch (field_c0.field_14) {
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
            field_170 = 16;
            break;
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
            field_170 = 8;
            break;
        default:
            if (Unk_4385e0(field_c0.field_14))
                field_170 = 24;
            break;
        }
    }
    field_16c = (field_170 != 0) | field_1e0;
    return 0;
}

// 0x71004aee10
CRenderTexture* CDepthOfField::Unk_4aee10(u32 width) {
    CRenderTexture* result = nullptr;
    for (s32 i = 0; i < field_498; i++) {
        CRenderTexture* texture = field_490[i];
        if (texture != nullptr) {
            if (static_cast<u32>(texture->field_54) < width)
                break;
            result = texture;
        }
    }
    if (!(field_154 & 8)) {
        for (s32 i = 0; i < field_20c; i++) {
            CRenderTexture* texture = field_4a8[i].field_38;
            if (texture != nullptr) {
                if (static_cast<u32>(texture->field_54) < width)
                    break;
                result = texture;
            }
        }
    }
    return result;
}

// 0x71004aeed0
s32 CDepthOfField::Unk_4aeed0(s32 arg0, s32 arg1, s32 arg2) {
    field_21c = arg0 == -1 ? 0 : arg0;
    if (arg1 == -1) {
        switch (field_21c) {
        case 7:
        case 8:
            arg1 = 9;
            break;
        case 0:
            arg1 = 0;
            break;
        case 1:
        case 2:
            arg1 = 3;
            break;
        case 4:
        case 5:
            arg1 = 6;
            break;
        case 10:
        case 11:
            arg1 = 12;
            break;
        case 13:
        case 14:
            arg1 = 15;
            break;
        default:
            arg1 = field_21c;
            break;
        }
    }
    field_224 = arg1;
    field_220 = arg2 == -1 ? 0 : arg2;
    return 0;
}

// 0x71004aef30
void CDepthOfField::Unk_4aef30() {
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    util->Unk_47abf0(field_1e8);
}

// 0x71004afaa0
f32 CDepthOfField::Unk_4afaa0(f32 arg0, f32 arg1) {
    f32 focal = field_1b0;
    f32 near = field_1a8;
    f32 scale = focal * field_1b4 / (focal - near);
    return arg0 * 2.4392f * scale / arg1 / field_1b8;
}

static inline f32 Unk_Abs(f32 x) {
    return x > 0.0f ? x : -x;
}
static inline f32 Unk_Sign(f32 x) {
    return x > 0.0f ? 1.0f : (x < 0.0f ? -1.0f : 0.0f);
}
static inline f32 Unk_Min(f32 a, f32 b) {
    return a < b ? a : b;
}

// 0x71004afae0
// NON_MATCHING: the original compares the distance with zero once (the
// absolute value reuses the flags of the early exit's test) and returns from
// each path; here a second `fcmp` and a shared return block.
s32 CDepthOfField::Unk_4afae0(f32* nearSize, f32* farSize) {
    switch (field_1c8) {
    case 0: {
        f32 aperture = field_1cc.field_0;
        f32 distance = field_1d0;
        if (aperture == 0.0f || distance == 0.0f) {
            if (nearSize != nullptr)
                *nearSize = 0.0f;
            if (farSize != nullptr)
                *farSize = 0.0f;
            return 1;
        }
        f32 focal = field_1b0;
        f32 near = field_1a8;
        f32 scale = focal * near / (focal - near);
        f32 absDistance = Unk_Abs(distance);
        f32 coc = aperture * 0.5f * scale / absDistance;
        f32 depth = distance > -scale ? distance : -scale;
        f32 blur;
        if (depth > 0.0f)
            blur = (depth - focal) * field_1c4;
        else
            blur = -((scale + depth) * field_1ac);
        blur = blur / depth * 0.5f;
        f32 absBlur = Unk_Abs(blur);
        coc = fmaxf(coc, 0.0f);
        if (absBlur > coc)
            blur = Unk_Sign(blur) * Unk_Min(absBlur, coc);
        f32 size = field_1b8;
        if (nearSize != nullptr)
            *nearSize = coc / size * 2.0f;
        if (farSize != nullptr)
            *farSize = blur / size * 2.0f;
        return 0;
    }
    case 1:
        if (field_1d8 < 0.0f) {
            if (nearSize != nullptr)
                *nearSize = 0.0f;
            if (farSize != nullptr)
                *farSize = 0.0f;
            return 1;
        }
        if (nearSize != nullptr)
            *nearSize = field_1d4;
        if (farSize != nullptr)
            *farSize = field_1d8;
        return 0;
    default:
        return -3;
    }
}

// 0x71004afd80
// NON_MATCHING: the same operations; the scheduling of the first block and the
// placement of the -6 return differ (registers follow).
s32 CDepthOfField::Unk_4afd80(f32 size, f32 distance, f32 angle) {
    f32 aperture;
    f32 focus;
    if (size == 0.0f) {
        aperture = 0.0f;
        focus = 0.0f;
    } else {
        f32 coc = field_1b8 * size * 0.5f;
        f32 depth = distance == 0.0f ? -2.9802322e-8f : distance * -0.5f;
        f32 near = field_1a8;
        f32 focal = field_1b0;
        f32 position = Unk_Sign(depth) * (near * 0.5f);
        f32 scale = near * focal / (focal - near);
        f32 absPosition = Unk_Abs(position);
        f32 ratio = coc * 2.0f / scale;
        f32 view = tanf(angle * 0.5f) / field_19c;
        focal = field_1b0;
        near = field_1a8;
        f32 factor = field_1b8 * (view / (focal * field_1b4 / (focal - near)));
        f32 limit = position > -near ? position : -near;
        f32 far = field_1ac;
        factor = depth * factor;
        f32 blur = 0.0f;
        if (limit > 0.0f)
            blur = far * (near * limit / (limit - near)) - near * far;
        else if (limit < 0.0f)
            blur = -(far * (near + limit)) / limit;
        factor = Unk_Abs(factor / (blur * 0.5f));
        f32 value = absPosition * ratio;
        if (depth > 0.0f) {
            factor = 1.0f / factor / near;
            aperture = value * factor;
            if (aperture < 0.0f)
                return -6;
        } else {
            factor = 2.0f / (factor + 1.0f);
            aperture = value * factor;
            if (aperture < 0.0f)
                return -6;
        }
        focus = position * factor;
    }
    field_1c8 = 0;
    field_1cc = aperture;
    field_1d0 = focus;
    return 0;
}

// 0x71004b35a0
// NON_MATCHING: the index's sign extension of the second load is a separate
// instruction here (the original folds it into both loads).
CRenderTexture* CDepthOfField::Unk_4b35a0(bool second, s32 index) {
    if (field_1dc != 0.0f) {
        CRenderTexture* texture = (second ? field_470 : field_468)[index];
        if (texture != nullptr)
            return texture;
    }
    return (second ? field_450 : field_448)[index];
}

// 0x71004b5ae0
// NON_MATCHING: the two tests of mode 0 are and-ed the other way round
// (`and w0, w9, w8`).
bool CDepthOfField::Unk_4b5ae0() {
    bool result = false;
    switch (field_1c8) {
    case 0: {
        f32 a = field_1cc.field_0;
        f32 b = field_1d0;
        result = a != 0.0f && b != 0.0f;
        break;
    }
    case 1:
        if (field_1d8 < 0.0f)
            return false;
        result = true;
        break;
    }
    return result;
}

// 0x71004b4c40
// NON_MATCHING: the loads of the first call's arguments are scheduled in another order
// (field_418's element and field_420 swap x10/x11).
s32 CDepthOfField::Unk_4b4c40() {
    s32 result = 0;
    if (field_c0.field_6d) {
        for (s32 i = 0; i < field_3f8; i++) {
            bool last = i == field_3f8 - 1;
            s32 status = Unk_4b35f0(i > 0 ? 2.2f : 3.0f, field_430[i], field_430[i + 1], field_488[i], field_438[i],
                                    field_400[i], field_408[i], field_410[i], field_418[i], &field_420[i],
                                    &field_428[i], i == 0, last);
            if (status < 0)
                result = status;
            status = Unk_4b48d0(i);
            if (status < 0)
                result = status;
            status = Unk_4b4540(i);
            if (status < 0)
                result = status;
        }
    }
    for (s32 i = 0; i < field_c0.field_10; i++) {
        s32 status;
        switch (field_4a8[i].field_10) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            status = Unk_4b29b0(i);
            break;
        case 7:
            status = Unk_4b3280(i);
            break;
        default:
            status = -4;
            break;
        }
        if (status < 0)
            result = status;
    }
    return result;
}

// 0x71004b4e10
// NON_MATCHING: the order of the loads and stores before the call (scheduling).
s32 CDepthOfField::Unk_4b4e10() {
    if (field_238 != nullptr) {
        CTextureUtil* util = Unk_GetTextureUtil();
        Unk_ReleaseTextureUtil();
        Unk_440c00_get(reinterpret_cast<u64>(field_20), 8);
        field_20->vf45(2);
        CRenderTexture* source = field_228;
        f32 u1;
        f32 v1;
        Unk_GetCoords(source, &u1, &v1);
        Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
        util->Unk_48b1e0(0.0f, 0.0f, static_cast<f32>(static_cast<u32>(source->field_54)),
                         static_cast<f32>(static_cast<u32>(source->field_58)), 0.0f, 0.0f, u1, v1, field_190,
                         field_194, field_1b0, field_238, field_16c, nullptr, 0, field_240, &field_1e8, nullptr,
                         nullptr, nullptr, 0, 0.5f, &color, 0);
        Unk_440c00_get(reinterpret_cast<u64>(field_20), 15);
        field_20->vf45(0);
    }
    return 0;
}

// NON_MATCHING: the original keeps the two size defaults as stores behind
// branches (the given size stored, then the other one if it isn't positive),
// where these become selects; the rest is the same up to scheduling (tried:
// the tests as `<= 0` and `!(> 0)`, the defaults read back from the members).
// 0x71004b6fc0 (its log lines name it)
s32 CDepthOfField::ApplyDepthOfField(CRenderTexture* source, void* arg2, CRenderTexture* target, bool arg4) {
    if (field_20 == nullptr) {
        return -1;
    }
    if (source == nullptr) {
        source = field_228;
    }
    if (target == nullptr) {
        target = field_228;
    }
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    if (arg4) {
        util->Unk_471410(16, 3, 2);
    }
    util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    util->Unk_47abf0(field_1e8);
    if (field_238 != nullptr) {
        Unk_4b4e10();
    }
    Unk_4a7dc0();
    Unk_4b4ff0(source);
    if (Unk_4b4c40() < 0) {
#line 14568
        PPFX_ERROR("CDepthOfField::ApplyDepthOfField(): ApplyDepthOfField_ApertureFilterAllLevels() failed.\n");
    }
    s32 result = Unk_4b6530(source, arg2, target);
    if (result < 0) {
#line 14576
        PPFX_ERROR("CDepthOfField::ApplyDepthOfField(): ApplyDepthOfField_Composite() failed.\n");
    }
    return result;
}

// 0x71004afc40
void CDepthOfField::Unk_4afc40(f32 width, f32 height, f32 tanHalfFov, f32 a3, f32 a4, f32 a5, f32 a6, f32 a7,
                               s32 mode, f32 b0, f32 b1, f32 b2, f32 b3, f32 b4, f32 width2, f32 height2) {
    if (tanHalfFov <= 0.0f) {
        tanHalfFov = 0.41421356f;
    }
    field_188 = width;
    field_18c = height;
    field_190 = width2;
    field_194 = height2;
    if (field_190 <= 0.0f) {
        field_190 = field_188;
    }
    if (field_194 <= 0.0f) {
        field_194 = field_18c;
    }
    field_19c = tanHalfFov;
    field_1a0 = a3;
    field_1a4 = a4;
    field_198 = atanf(tanHalfFov) * 2.0f;
    field_1b8 = a6;
    field_1b0 = a5;
    s32 result = Unk_4af020(mode, field_198, a5, a6, a7, b0, b1, b2, b3, &field_1a8, &field_1b4, &field_1ac,
                            &field_1c4, &field_1e4, &field_1e8, b4);
    field_184 = result == 0 && field_198 > 0.0f && field_198 < 3.14159265f;
}

// 0x71004aa0d0
// NON_MATCHING: the same instructions; the load of field_c0.field_6d is
// scheduled before the first stores here (after the third in the original),
// which swaps w8 and w9 in the constants, and two stores come in another order
s32 CDepthOfField::Initialize(CRenderTexture* source, const Unk_Desc* desc) {
    s32 result = Unk_4a7390(source, const_cast<Unk_Desc*>(desc));
    if (result < 0) {
#line 2896
        PPFX_ERROR("CDepthOfField::Initialize(): ValidateInitParam() failed (0x%x: %s).\n", result,
                   Unk_446df0(result));
        return result;
    }
    IGPUDevice* device = field_20;
    Unk_49ec80();
    field_228 = source;
    field_c0 = *desc;
    field_2c = *desc;
    Unk_4a7f60();
    field_3b8 = 0.75f;
    field_3bc = 0.0f;
    field_3c0 = 0.7853982f;
    field_3e8 = 0;
    field_3ec = 0.5f;
    field_1c8 = 0;
    field_1cc = 0.0f;
    field_1d0 = 0.0f;
    field_3a8 = true;
    field_3b0 = 0;
    field_3c4 = false;
    field_3b4 = false;
    field_3d0 = 0;
    field_3c8 = 0;
    if (field_c0.field_6d) {
        field_3f0 = false;
    }
    field_251 = true;
    field_2a8 = 1;
    field_2ac = 4;
    field_2b0 = 1.0f;
    field_2b4 = 0.5f;
    field_2b8 = 1.0f;
    field_2bc = 1.0f;
    field_3e0 = 4.0f;
    field_3d8 = 0.1f;
    field_3dc = 16.0f;
    field_3f4 = 1.0f;
    field_3ac = 1.0f;
    field_240 = false;
    field_1e0 = false;
    return Unk_49ec30(device);
}

// a value clamped to [0, 1] (inline)
static inline f32 Unk_Saturate(f32 value) {
    if (value < 0.0f) {
        return 0.0f;
    }
    return value > 1.0f ? 1.0f : value;
}

// 0x71004b4ab0
// NON_MATCHING: block placement: the original lays the search through
// field_398 out after the return (as if unlikely) and falls through to the
// bias; the instructions are the same. Tried: the tests as one condition, as
// nested ifs and through an inline clamp.
f32 CDepthOfField::Unk_4b4ab0(bool near) {
    if (!near) {
        return field_27c;
    }
    f32 t = 0.0f;
    if (field_c0.field_6d) {
        f32 size = field_1c0;
        f32 ratio = field_3e4 / size;
        if (!(field_3e4 > 0.0f)) {
            ratio = 0.0f;
        }
        f32 bias = field_3ec;
        t = bias;
        if (!(ratio < 0.0f)) {
            f32 m = ratio > 1.0f ? 1.0f : ratio;
            if (m > 0.0f && field_3e8 != 1) {
                t = 0.0f;
                f32 value = 1.0f / powf(m, powf(10.0f, -(bias * 2.0f - 1.0f)));
                s32 count = field_2f0;
                for (s32 i = 0; i < count; i++) {
                    if (value < field_398[i + 1]) {
                        f32 frac = (value - field_398[i]) / (field_398[i + 1] - field_398[i]);
                        f32 s = 1.0f - (frac + static_cast<f32>(i)) / static_cast<f32>(count);
                        t = Unk_Saturate(s);
                        break;
                    }
                }
            }
        }
    }
    s32 count = field_2f0;
    f32 pos = (1.0f - t) * static_cast<f32>(count) * 0.9999f;
    s32 index = static_cast<s32>(pos);
    s32 next = index + 1 < 0 ? 0 : (index + 1 > count - 1 ? count - 1 : index + 1);
    const f32* table = field_358[field_2a8];
    f32 a = table[index];
    f32 b = table[next];
    return (a + (b - a) * (pos - static_cast<f32>(index))) * 0.87890625f;
}

// a flag in .rodata the second kind of passes needs (placeholder name)
extern const bool Unk_1b35154;

// 0x71004a7390: checks a description (the ranges in field_20 are pairs, the
// first one used, the others used or not, each used one beyond the last)
// NON_MATCHING: in each pair's last test the original compares the begin with
// the previous one before it tests whether a pair was unused; here the unused
// test comes second. Tried: the three conditions in every order, with && and
// ||, the flag as a bool, an or of the values and per-pair variables.
s32 CDepthOfField::Unk_4a7390(void* source, void* descArg) {
    const Unk_Desc* desc = static_cast<const Unk_Desc*>(descArg);
    if (static_cast<u32>(desc->field_0[1]) < 16) {
        return -6;
    }
    if (static_cast<u32>(desc->field_0[2]) < 16) {
        return -6;
    }
    if (static_cast<u32>(desc->field_10 - 1) > 6) {
        return -6;
    }
    if (desc->field_6d) {
        if (!Unk_1b35154) {
            return -6;
        }
    } else if (desc->field_1c < 0) {
        if (desc->field_20[0] < 0) {
            return -6;
        }
        if (desc->field_20[1] < 0) {
            return -6;
        }
        bool unused = false;
        for (s32 i = 1; i < 7; i++) {
            s32 begin = desc->field_20[i * 2];
            s32 end = desc->field_20[i * 2 + 1];
            if (begin < 0 && end >= 0) {
                return -6;
            }
            if (begin >= 0 && end < 0) {
                return -6;
            }
            if (begin >= 0 && end >= 0 && unused) {
                return -6;
            }
            if (begin < 0 || end < 0) {
                unused = true;
            }
            if (!(end > desc->field_20[i * 2 - 1] || begin > desc->field_20[i * 2 - 2] || unused)) {
                return -6;
            }
        }
    }
    if (!desc->field_65 || source != nullptr) {
        return 0;
    }
    return -6;
}

}  // namespace PPFX
