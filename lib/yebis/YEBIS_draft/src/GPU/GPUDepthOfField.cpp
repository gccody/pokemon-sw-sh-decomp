// Scope: common
// PPFX::CDepthOfField (lib/yebis/YEBIS_draft/src/GPU/GPUDepthOfField.h): so
// far its destructors and three small virtual functions. The TU has statics
// of its own besides the common ones (its static initialiser, 0x71004b72d0,
// is 716 bytes), so Unk_Statics.h isn't included until they're known.
#include <math.h>
#include <string.h>

#include <yebis/YEBIS_draft/src/GPU/GPUClassUtil.h>
#include <yebis/YEBIS_draft/src/GPU/GPUDepthOfField.h>
#include <yebis/YEBIS_draft/src/GPU/TinyEffect/TFXString.h>

#define PPFX_FILE "C:/workspace/YEBIS_draft/src/GPU/GPUDepthOfField.cpp"
#include <yebis/YEBIS_draft/src/GPU/Unk_Log.h>

// 0x7100446df0: a result's name (Unk_447050.cpp)
const char* Unk_446df0(s32 result);

// 0x710049c8d0 (lib/yebis/leaf)
s32 Unk_49c8d0_call(void* self, void* value);

// 0x71004738c0 (lib/yebis/leaf): GPUTextureUtil.cpp's constants buffer
const u8* Unk_4738c0_get();

// 0x7100440c00 (lib/yebis/leaf)
u32 Unk_440c00_get(u64 device, u32 arg);

namespace PPFX {

// a xorshift128 generator seeded as GPUGlareDef.cpp's (placeholder; the
// function-local statics of 0x71004b0650 and 0x71004b1100)
struct Unk_Random {
    explicit Unk_Random(u32 seed) {
        for (s32 i = 0; i < 4; i++) {
            seed = 1812433253 * (seed ^ (seed >> 30)) + i + 1;
            field_0[i] = seed;
        }
    }
    u32 Unk_Next() {
        s32 t = field_0[0] ^ (field_0[0] << 11);
        field_0[0] = field_0[1];
        field_0[1] = field_0[2];
        field_0[2] = field_0[3];
        field_0[3] = field_0[3] ^ (field_0[3] >> 19) ^ (t ^ (t >> 8));
        return field_0[3];
    }
    // from 0 to 1
    f32 Unk_Get() { return static_cast<f32>(Unk_Next() & 0x7fffffff) * 4.65661287e-10f; }

    u32 field_0[4];
};

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
    field_15c = 0;
    field_160 = 0;
    field_258 = 0;
    field_260 = nullptr;
    field_268 = 0;
    field_270 = 0;
    field_278 = 0.0f;
    field_280[0] = 0;
    field_280[1] = 0;
    field_280[2] = 0;
    field_280[3] = 0;
    field_280[4] = 0;
    for (s32 i = 0; i < 5; i++) {
        field_2c8[i] = nullptr;
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

// 0x71004af690
// NON_MATCHING: the same blocks, but LLVM threads and duplicates the tails
// differently (the original keeps the first loads of field_3c8 and field_3d0
// in registers and duplicates the final size computation per path).
f32 CDepthOfField::Unk_4af690(f32 angle, f32 distance, f32 width) {
    if (field_3bc <= 0.0f)
        return 0.0f;
    if (field_3c0 <= 0.0f)
        return field_3bc;
    if (angle <= 0.0f || distance <= 0.0f || width <= 0.0f)
        return -1.0f;
    f32 value0;
    f32 size0;
    f32 exponent;
    if (field_3c8 <= 0.0f) {
        value0 = field_3bc;
        exponent = field_3b8;
        size0 = Unk_PairSize(field_3c0, distance, width);
    } else {
        f32 value1;
        f32 size1;
        if (field_3d0 <= 0.0f) {
            value0 = field_3bc;
            size0 = Unk_ViewSize(field_3c0, distance, width);
            value1 = field_3c8;
            size1 = Unk_PairSize(field_3cc, distance, width);
        } else if (field_198 < field_3c8) {
            value0 = field_3bc;
            value1 = field_3c8;
            size0 = Unk_PairSize(field_3c0, distance, width);
            size1 = Unk_PairSize(field_3cc, distance, width);
        } else {
            value0 = field_3c8;
            value1 = field_3d0;
            size0 = Unk_PairSize(field_3cc, distance, width);
            size1 = Unk_PairSize(field_3d4, distance, width);
        }
        f32 ratio = size1 / size0;
        exponent = 1.0f - logf(value1 / value0) / logf(ratio);
    }
    return value0 * powf(Unk_ViewSize(angle, distance, width) / size0, 1.0f - exponent);
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
    field_3d0 = 0.0f;
    field_3d4 = 0.0f;
    field_3c8 = 0.0f;
    field_3cc = 0.0f;
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

// 0x7101eba354: the blur sizes of each kind, by field_14
extern const s32 Unk_1eba354[8][5] __attribute__((visibility("hidden")));

// 0x71004a7050
void CDepthOfField::Unk_Level::Unk_4a7050() {
    s32 size = Unk_1eba354[field_10][field_14];
    field_18 = size;
    f32 value = static_cast<f32>(size);
    switch (field_10) {
    case 0:
        field_1c = static_cast<s32>(value);
        field_20 = value * 1.05f;
        break;
    case 1:
        field_1c = static_cast<s32>(value * 2.0f - 1.0f);
        field_20 = static_cast<f32>(field_1c) * 0.95f;
        break;
    case 2:
        field_20 = value * 1.4142135f;
        field_1c = static_cast<s32>(field_20);
        break;
    case 3:
        field_20 = exp2f(value) * 2.0f - 1.0f;
        field_1c = static_cast<s32>(field_20);
        break;
    case 4:
        field_20 = value;
        field_1c = static_cast<s32>(field_20);
        break;
    case 5: {
        static const f32 radii[4] = {3.15f, 6.3f, 12.6f, 25.2f};
        s32 index = static_cast<s32>(value);
        f32 radius = index < 0 ? 0.0f : radii[index];
        field_1c = static_cast<s32>(radius + 0.49999f);
        field_20 = radius;
        break;
    }
    case 6:
    case 7:
        field_20 = value * 1.4142135f;
        break;
    }
    field_24 = field_20;
    if (field_28 == 1 && field_10 != 5) {
        field_24 += field_2c;
    }
}

// 0x71004a71c0
s32 CDepthOfField::Unk_Level::Unk_4a71c0(u32 flags, bool arg2, s32 arg3) {
    Unk_4a7050();
    field_30 = field_24 / static_cast<f32>(field_4);
    field_38 = nullptr;
    field_68 = nullptr;
    field_70 = 0;
    field_60 = 0;
    field_48[0] = nullptr;
    field_48[1] = nullptr;
    field_48[2] = nullptr;
    field_78 = nullptr;
    field_80 = nullptr;
    field_88 = nullptr;
    field_90 = nullptr;
    field_98 = nullptr;
    field_a0 = nullptr;
    field_a8 = nullptr;
    field_b0 = nullptr;
    field_b8 = nullptr;
    switch (field_10) {
    case 0:
        if (field_18 == 17) {
            field_60 = arg2 ? 1 : 2;
        }
        break;
    case 1:
        field_60 = field_18 > 1;
        break;
    case 2:
        field_60 = 1;
        break;
    case 3:
        // (the subtraction is unsigned: compared as it is, not folded into the size)
        field_60 = static_cast<s32>(static_cast<u32>(field_18) - 1) < 2 ? static_cast<s32>(static_cast<u32>(field_18) - 1) : 2;
        break;
    case 4:
        field_60 = field_18 < 4 ? 0 : 4;
        break;
    case 5:
        field_60 = arg3 < 2 ? 2 : 1;
        break;
    case 6:
        field_60 = 3;
        break;
    case 7:
        field_60 = 4;
        break;
    }
    if (field_0 != field_8) {
        bool more = false;
        switch (field_10) {
        case 0:
            if (field_18 > 16)
                more = true;
            break;
        case 1:
        case 2:
        case 3:
        case 5:
            more = true;
            break;
        case 4:
            if (field_18 >= 9)
                more = true;
            break;
        }
        if (more) {
            field_60++;
        } else if (field_60 == 0) {
            field_60 = 1;
        }
    }
    if ((flags & 6) == 2) {
        field_60++;
    }
    if (arg3 < 0) {
        field_70 = 0;
    } else if (field_28 <= 1) {
        field_70 = field_28;
    }
    return 0;
}

// a scale and bias composed with a scale (inline)
static inline void Unk_ScaleBy(Unk_Float2* value, f32 scale) {
    value->field_0[0].field_0 = scale * value->field_0[0].field_0;
    value->field_0[1].field_0 = scale * value->field_0[1].field_0 + 0.0f;
}

// 0x71004a7dc0
// NON_MATCHING: scheduling: the original multiplies the first level's range by
// 0.25 before the four additions and reads the level's height and size before
// it stores field_e8; the last addition's operands are swapped (y + x * bias).
s32 CDepthOfField::Unk_4a7dc0() {
    for (s32 i = 0; i < field_c0.field_10; i++) {
        Unk_Level* level = &field_4a8[i];
        f32 far = level->field_30;
        f32 near = i == 0 ? far * 0.0001f : field_4a8[i - 1].field_30;
        f32 far1 = far;
        f32 near1 = near;
        f32 weight = 0.25f;
        if (field_154 & 4) {
            if (i == 0) {
                near1 = near * 0.0f;
                far1 = far * 0.51f;
                weight = 0.0f;
            } else {
                near1 = near * 0.61f;
                far1 = far * 0.51f;
                weight = 0.25f;
            }
        }
        f32 near2 = (field_154 & 2) == 0 ? near : near * 1.15f;
        f32 far2 = (field_154 & 2) == 0 ? far : far * 0.98f;
        f32 first = field_4a8[0].field_30;
        far1 += weight * first;
        near1 += weight * first;
        far2 += first * 0.25f;
        near2 += first * 0.25f;
        level->field_c0 = 1.0f / (far1 - near1);
        level->field_c4 = -near1 / (far1 - near1);
        level->field_c8 = 1.0f / (far2 - near2);
        level->field_cc = -near2 / (far2 - near2);
        level->field_d0 = level->field_c0 * field_1e4;
        level->field_d4 = level->field_c4;
        level->field_d8 = level->field_c8 * field_1e4;
        level->field_dc = level->field_cc;
        f32 scale = field_1e4;
        f32 height = static_cast<f32>(level->field_4);
        f32 size = level->field_20;
        level->field_e8 = Unk_Float2(1.0f, 0.0f);
        Unk_ScaleBy(&level->field_e8, scale);
        Unk_ScaleBy(&level->field_e8, height);
        Unk_ScaleBy(&level->field_e8, 1.0f / size);
        f32 scale2 = 1.0f;
        f32 bias = 0.0f;
        if (field_16c == 1) {
            scale2 = field_1f0;
            bias = field_1f4;
        }
        level->field_f0 = level->field_e8.field_0[0].field_0 * scale2;
        level->field_f4 = level->field_e8.field_0[1].field_0 + level->field_e8.field_0[0].field_0 * bias;
    }
    return 0;
}

// 0x71004b48d0
// NON_MATCHING: scheduling: the original materialises the zero before it halves the
// radius and multiplies x by it first (the aspect and the size swap s2/s3).
s32 CDepthOfField::Unk_4b48d0(s32 index) {
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    f32 width = static_cast<f32>(static_cast<u32>(field_c0.field_0[1]));
    f32 height = static_cast<f32>(static_cast<u32>(field_c0.field_0[2]));
    f32 aspect = width / height;
    const Unk_Pass* first = &field_420[index];
    const Unk_Pass* second = &field_428[index];
    f32 size = first->field_7c;
    f32 y = (width < height ? size * aspect : size) * 0.5f;
    f32 x = y / aspect;
    util->Unk_481820(field_438[index], field_448[index], Unk_Float2(x * 0.0f, y * 0.0f),
                     Unk_Float4(first->field_58.field_0[0], first->field_58.field_0[1], first->field_58.field_0[2],
                                first->field_58.field_0[3]));
    return util->Unk_481820(field_438[index], field_450[index], Unk_Float2(x * 0.0f, y * 0.0f),
                            Unk_Float4(second->field_58.field_0[0], second->field_58.field_0[1],
                                       second->field_58.field_0[2], second->field_58.field_0[3]));
}

}  // namespace PPFX

namespace PPFX {
struct Unk_4aa5a0_Self;
}

// a render texture's viewport from the fractions of its size (at least one
// pixel; inline, as GPURenderTextureArray.cpp's)
static inline s32 Unk_SetViewport(PPFX::CRenderTexture* texture, f32 width, f32 height, f32 x, f32 y) {
    s32 w = static_cast<s32>(width * static_cast<f32>(static_cast<u32>(texture->field_2c.field_4)));
    s32 h = static_cast<s32>(height * static_cast<f32>(static_cast<u32>(texture->field_2c.field_8)));
    s32 ix = static_cast<s32>(x * static_cast<f32>(static_cast<u32>(texture->field_2c.field_4)));
    s32 iy = static_cast<s32>(y * static_cast<f32>(static_cast<u32>(texture->field_2c.field_8)));
    if (width > 0.0f) {
        w = w > 1 ? w : 1;
    }
    if (height > 0.0f) {
        h = h > 1 ? h : 1;
    }
    return Unk_49ad30(reinterpret_cast<PPFX::Unk_RenderTexture*>(texture), w, h, ix, iy);
}

// 0x71004aa5a0: every texture of the chain's viewport
s32 Unk_4aa5a0(PPFX::Unk_4aa5a0_Self* selfArg, f32 width, f32 height, f32 x, f32 y) {
    PPFX::CDepthOfField* self = reinterpret_cast<PPFX::CDepthOfField*>(selfArg);
    s32 result = 0;
    for (s32 i = 0; i < self->field_498; i++) {
        s32 status = Unk_SetViewport(self->field_490[i], width, height, x, y);
        if (status < 0) {
            result = status;
        }
    }
    return result;
}

namespace PPFX {

// a level's range in the presets (placeholder)
struct Unk_Range {
    Unk_Range(s32 begin, s32 index) : field_0(begin), field_4(index) {}
    s32 field_0;
    s32 field_4;
};

// 0x71004a79e0
// NON_MATCHING: the presets' stores are scheduled in another order and the
// loop's blocks are laid out differently (registers follow).
s32 CDepthOfField::Unk_4a79e0() {
    field_1f8[0] = -1;
    field_1f8[1] = -1;
    field_1f8[2] = -1;
    field_1f8[3] = -1;
    Unk_Level levels[7];
    memset(levels, 0, sizeof(levels));
    u32 width = field_c0.field_0[1];
    u32 height = field_c0.field_0[2];
    f32 scale = static_cast<f32>(field_158);
    field_168 = scale / static_cast<f32>(width);
    const Unk_Range presets[7][7] = {
        {Unk_Range(0, 0), Unk_Range(1, 1), Unk_Range(2, 1), Unk_Range(2, 2), Unk_Range(-1, -1), Unk_Range(-1, -1), Unk_Range(-1, -1)},
        {Unk_Range(0, 0), Unk_Range(1, 1), Unk_Range(1, 2), Unk_Range(2, 2), Unk_Range(-1, -1), Unk_Range(-1, -1), Unk_Range(-1, -1)},
        {Unk_Range(0, 0), Unk_Range(0, 1), Unk_Range(1, 1), Unk_Range(1, 2), Unk_Range(-1, -1), Unk_Range(-1, -1), Unk_Range(-1, -1)},
        {Unk_Range(0, field_168 < 1.2f), Unk_Range(0, 2), Unk_Range(1, 2), Unk_Range(2, 2), Unk_Range(-1, -1), Unk_Range(-1, -1), Unk_Range(-1, -1)},
        {Unk_Range(0, 0), Unk_Range(0, 1), Unk_Range(0, 2), Unk_Range(1, 2), Unk_Range(-1, -1), Unk_Range(-1, -1), Unk_Range(-1, -1)},
        {Unk_Range(0, 0), Unk_Range(0, 1), Unk_Range(0, 2), Unk_Range(1, 2), Unk_Range(1, 3), Unk_Range(-1, -1), Unk_Range(-1, -1)},
        {Unk_Range(0, 0), Unk_Range(0, 1), Unk_Range(0, 2), Unk_Range(0, 3), Unk_Range(-1, -1), Unk_Range(-1, -1), Unk_Range(-1, -1)},
    };
    s32 preset = field_c0.field_1c < 6 ? field_c0.field_1c : 6;
    const s32* ranges = preset < 0 ? field_c0.field_20 : &presets[preset][0].field_0;
    static const f32 weights[4] = {0.0f, 0.5f, 0.75f, 1.0f};
    s32 count = field_c0.field_10;
    s32 kind = field_c0.field_18;
    s32 step = 0;
    s32 index = 0;
    for (s32 i = 0; i < count; i++) {
        bool unused = false;
        bool same = false;
        if (i < 7) {
            if (ranges[i * 2] < 0) {
                unused = true;
            } else {
                index = ranges[i * 2 + 1];
            }
            if (i != 0 && !unused && ranges[i * 2 - 2] == ranges[i * 2]) {
                same = true;
            }
        }
        if (i == 0) {
            if (!field_c0.field_6d &&
                !(width > static_cast<u32>(field_c0.field_5c) && field_c0.field_60 * scale < static_cast<f32>(width))) {
                step = 1;
            }
        } else if (!same) {
            width = static_cast<u32>(static_cast<f32>(width) * 0.5f + 0.99f);
            height = static_cast<u32>(static_cast<f32>(height) * 0.5f + 0.99f);
            width = width > 3 ? width : 3;
            height = height > 3 ? height : 3;
            bool grow;
            s32 pass;
            switch (field_c0.field_6d && i >= 2 ? i : 0) {
            case 2:
            case 3:
                pass = 0;
                break;
            case 4:
            case 5:
                pass = 1;
                break;
            case 6:
                pass = 2;
                break;
            default:
                pass = -1;
                break;
            }
            if (pass >= 0) {
                grow = width < field_420[pass].field_0;
            } else {
                grow = !(width > static_cast<u32>(field_c0.field_5c) &&
                         field_c0.field_60 * scale < static_cast<f32>(width));
            }
            if (grow) {
                step = step < 2 ? step + 1 : 3;
            }
        }
        Unk_Level* level = &levels[i];
        level->field_0 = width;
        level->field_4 = height;
        if (step == 0) {
            level->field_8 = width;
            level->field_c = height;
            level->field_28 = 0;
        } else {
            level->field_8 = width * 2 < field_158 ? width * 2 : field_158;
            level->field_c = height * 2 < field_15c ? height * 2 : field_15c;
            level->field_28 = 1;
        }
        level->field_10 = kind;
        level->field_14 = index;
        level->field_2c = weights[step];
    }
#line 1302
    field_4a8 = UNK_NEW_ARRAY(Unk_Level, count);
    for (s32 i = 0; i < field_c0.field_10; i++) {
        memcpy(&field_4a8[i], &levels[i], sizeof(Unk_Level));
        field_4a8[i].Unk_4a71c0(field_c0.field_0[3], field_c0.field_6c, field_c0.field_70);
    }
    Unk_4a7dc0();
    return 0;
}

// 0x71004b4540: the two sets' textures copied into their alternates, faded by
// the level
// NON_MATCHING: one swap: the original reads field_1dc before it stores the zero
// vector (with the read first here, `this` and the utilities exchange x19/x20).
s32 CDepthOfField::Unk_4b4540(s32 index) {
    // (written as a negated test: the return is laid out last)
    if (!(field_1dc != 0.0f))
        return 1;
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    CRenderTexture* sources[2] = {field_450[index], field_448[index]};
    CRenderTexture* targets[4] = {Unk_4b35a0(true, index), Unk_4b35a0(false, index), nullptr, nullptr};
    f32 scale = (static_cast<f32>(index) + 1.0f) * 0.8f * 0.25f + 0.25f;
    s32 result = 0;
    for (s32 i = 0; i < 2; i++) {
        CRenderTexture* source = sources[i];
        CRenderTexture* target = targets[i];
        if (source == target)
            continue;
        s32 filter = Unk_GetTexture(source)->vf16();
        Unk_GetTexture(source)->vf15(8);
        Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
        Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
        f32 alpha = scale * field_1dc;
        alpha = alpha < 0.0f ? 0.0f : (alpha > 1.0f ? 1.0f : alpha);
        s32 status = util->Unk_47dfa0(0.0f, 0.0f, alpha, 1.0f, source, target, 0, &color, 0, false, false, 1, &zero,
                                      nullptr, -1);
        if (status < 0)
            result = status;
        Unk_GetTexture(source)->vf15(filter);
    }
    return result;
}

// the constants 0x71004b0db0 hands the composite (placeholder)
struct Unk_4b0db0_Constants {
    f32 field_0;
    f32 field_4;
    f32 field_8;
    f32 field_c;
    f32 field_10;
    f32 field_14;
    Unk_Float field_18;
    Unk_Float field_1c;
    f32 field_20;
    f32 field_24;
    f32 field_28;
    f32 field_2c;
};

// the composite's offset (inline)
static inline f32 Unk_4b0db0_Distance(const CDepthOfField* self) {
    return self->field_3f0 ? self->field_3f4 * 2.0f : 0.0f;
}

// a flag in .rodata the second kind of passes needs (placeholder name)
extern const bool Unk_1b35154;

// the constants 0x71004b0650 sets (placeholder)
struct Unk_4b0650_Constants {
    f32 field_0;
    f32 field_4;
    f32 field_8;
    Unk_Float field_c;
    f32 field_10;
    f32 field_14;
    f32 field_18;
    f32 field_1c;
    Unk_Float field_20[4];
};

static inline f32 Unk_MaxF(f32 a, f32 b) {
    return a > b ? a : b;
}

// the larger of two elements, by reference (inline)
static inline const Unk_Float& Unk_MaxRef(const Unk_Float& a, const Unk_Float& b) {
    return a.field_0 > b.field_0 ? a : b;
}

// the technique of a blur with `count` taps (0: none) (inline)
static inline s32 Unk_BlurTechnique(CTextureUtil* util, s32 mode, bool flag, bool second, bool far, s32 count) {
    s32 technique = 0;
    switch (mode) {
    case 0:
        technique = flag ? util->field_30.field_1af6c.field_140[second][far][count - 1]
                         : util->field_30.field_1af6c.field_a0s[second][far][count - 1];
        break;
    case 1:
        technique = flag ? util->field_30.field_1af6c.field_280[second][far][count - 1]
                         : util->field_30.field_1af6c.field_1e0[second][far][count - 1];
        break;
    case 2:
        technique = util->field_30.field_1af6c.field_320[second][far][count - 1];
        break;
    }
    return technique;
}

// 0x71004b0650
// NON_MATCHING: only the generator's guard: the TU's merged statics aren't all
// here yet, so the guard isn't at the generator plus 0xe4 as in the original.
s32 CDepthOfField::Unk_4b0650(s32 count, s32 mode, CRenderTexture* source, CRenderTexture* target,
                              CRenderTexture* second, const Unk_Float4* color, bool flag, f32 a, f32 b) {
    s32 filter = Unk_GetTexture(source)->vf16();
    Unk_GetTexture(source)->vf15(8);
    s32 secondFilter;
    if (second != nullptr) {
        secondFilter = Unk_GetTexture(second)->vf16();
        Unk_GetTexture(second)->vf17(1);
    } else {
        secondFilter = -1;
    }
    bool far = Unk_1b35154 && field_3f0 && field_3f4 * 2.0f != 0.0f;
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    target->Unk_49d250(0, 0, 1, 0, 0);
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    bool near = field_251;
    s32 taps = count;
    s32 technique = Unk_BlurTechnique(util, mode, flag, near, far, taps);
    if (technique == 0) {
        taps = count - 1;
        technique = Unk_BlurTechnique(util, mode, flag, near, far, taps);
    }
    Unk_463fd0_Effect* effect = util->field_30.field_0;
    effect->vf29(technique);
    Unk_4b0db0(near, far);
    Unk_4b1100(near, far, taps, 0.0f);
    Unk_4b0650_Constants* constants = reinterpret_cast<Unk_4b0650_Constants*>(const_cast<u8*>(Unk_4738c0_get()));
    constants->field_0 = b;
    constants->field_4 = 0.0f;
    constants->field_8 = 0.0f;
    constants->field_c = Unk_Float(a);
    if (far) {
        f32 x = Unk_4b0db0_Distance(this) * -0.002f;
        f32 ax = Unk_Abs(x);
        f32 y = Unk_4b0db0_Distance(this) * 0.002f;
        f32 offset = Unk_MaxF(ax, Unk_Abs(y));
        constants->field_0 = offset + b;
        constants->field_c = Unk_MaxRef(Unk_Float(a - offset), Unk_Float(0.0f));
    }
    f32 lo;
    f32 hi;
    if (mode == 2) {
        lo = 0.1f;
        hi = 0.2f;
    } else {
        f32 size = field_178;
        lo = flag ? size + 0.25f : size * 2.0f + 0.5f;
        hi = flag ? size * 2.0f + 0.5f : size * 4.0f + 1.0f;
    }
    f32 scale = -1.0f / (hi - lo);
    constants->field_10 = scale;
    constants->field_14 = 1.0f - lo * scale;
    constants->field_18 = 0.0f;
    constants->field_1c = 0.0f;
    constants->field_20[0] = color->field_0[0];
    constants->field_20[1] = color->field_0[1];
    constants->field_20[2] = color->field_0[2];
    constants->field_20[3] = color->field_0[3];
    effect->vf22(util->field_30.field_d0, reinterpret_cast<const Unk_Float4*>(constants), 3);
    effect->vf26(util->field_30.field_10[0], Unk_GetTexture(source));
    if (second != nullptr)
        effect->vf26(util->field_30.field_10[1], Unk_GetTexture(second));
    else
        effect->vf26(util->field_30.field_10[1], Unk_GetTexture(source));
    Unk_GPUTexture* noise = field_260;
    effect->vf26(util->field_30.field_10[2], noise);
    s32 kind = field_2ac;
    effect->vf26(util->field_30.field_10[3], reinterpret_cast<Unk_GPUTexture* const*>(field_2c8[1])[kind]);
    f32 u1;
    f32 v1;
    Unk_GetCoords(source, &u1, &v1);
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    static Unk_Random random(1);
    f32 r0 = random.Unk_Get();
    f32 r1 = random.Unk_Get();
    s32 result = util->Unk_472250(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, r0, r1, r0 + 1.0f, r1 + 1.0f, 0.0f,
                                  0.0f, 0.0f, 0.0f, 0);
    Unk_GetTexture(source)->vf15(filter);
    if (second != nullptr)
        Unk_GetTexture(second)->vf15(secondFilter);
    return result;
}

// 0x71004b0db0
// NON_MATCHING: registers: the near size's last product lands in s3 in the
// original, and the mode 5 strength multiplies the absolute value by the ratio
// (operands swapped here).
void CDepthOfField::Unk_4b0db0(bool near, bool far) {
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    Unk_463fd0_Effect* effect = util->field_30.field_0;
    Unk_4b0db0_Constants* constants = reinterpret_cast<Unk_4b0db0_Constants*>(const_cast<u8*>(Unk_4738c0_get()));
    const f32* clip = &field_1e8;
    effect->vf20(util->field_30.field_b0, clip);
    f32 half = field_1e4 * 0.5f;
    constants->field_0 = half;
    f32 blur;
    f32 amount;
    if (near) {
        s32 mode = field_2ac;
        f32 size = field_2c8[3][mode];
        f32 scale = Unk_4b4ab0(true);
        constants->field_4 = 1.0f / (size * (scale / 0.7853982f) * 0.87890625f) * 0.5f;
        f32 depth = field_2b0;
        f32 a = powf(field_1b4 * 0.5f, field_2b8);
        f32 b = powf(field_19c * 4.0f, field_2b4);
        f32 focal = field_1b0;
        f32 nearPlane = field_1a8;
        f32 c = powf(nearPlane / (focal - nearPlane) + 1.0f, field_2bc);
        if (field_2ac == 5) {
            f32 ratio = 0.0f;
            if (field_3e4 > 0.0f)
                ratio = field_3e4 / field_1c0;
            if (ratio <= 0.0f)
                ratio = 1.0f;
            f32 strength = field_2b0 > 0.0f ? field_2b0 : -field_2b0;
            strength = strength * ratio;
            blur = 0.0f;
            amount = strength < 0.0f ? 0.0f : (strength > 1.0f ? 1.0f : strength);
        } else {
            blur = 8.0f / depth * a * b / c;
            amount = field_2c8[4][field_2ac];
        }
    } else {
        constants->field_4 = 1.0f / field_278 / 1.5707964f;
        blur = 0.0f;
        amount = 0.5f;
    }
    constants->field_8 = blur;
    constants->field_c = amount;
    Unk_Float y(0.0f);
    Unk_Float x(0.0f);
    if (far) {
        x = Unk_Float(Unk_4b0db0_Distance(this) * -0.002f);
        y = Unk_Float(Unk_4b0db0_Distance(this) * 0.002f);
    }
    constants->field_10 = half;
    constants->field_14 = half;
    constants->field_18 = x;
    constants->field_1c = y;
    if (field_c0.field_6d) {
        f32 radius = field_420[0].field_78 * 0.5f;
        f32 start = radius * 1.5f;
        f32 scale = 1.0f / (radius - start);
        constants->field_28 = scale;
        constants->field_2c = 0.0f - start * scale;
    }
    effect->vf22(util->field_30.field_d4, reinterpret_cast<const Unk_Float4*>(constants), 4);
}

// 0x71004b3280: a level of the seventh kind: two hexagonal blurs and their
// sum, faded into the alternate texture
// NON_MATCHING: scheduling and registers (the original keeps the levels'
// pointer in a stack slot and computes the level's address again for the
// last call; the constants 1 and 9 are materialised earlier). The callees
// 0x7100490780 and 0x7100496b40 have placeholder signatures.
s32 CDepthOfField::Unk_4b3280(s32 level) {
    Unk_Level* item = &field_4a8[level];
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    const f32 weights[9] = {0.71f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.71f};
    {
        Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
        util->Unk_490780(1.0f, item->field_38, item->field_68[3], item->field_68[0], 9, weights, 1, field_220, &color,
                         false, 0, 0);
    }
    {
        Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
        Unk_Float4 range(1.0f, 0.0f, -3.40282347e+38f, 3.40282347e+38f);
        util->Unk_490e70(0.52359879f, 9.0f, 1.0f, item->field_38, item->field_68[3], item->field_68[1], 9,
                         const_cast<f32*>(weights), 1, field_220, &color, nullptr, &range, false, 0, 0);
    }
    {
        Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
        Unk_Float4 range(1.0f, 0.0f, -3.40282347e+38f, 3.40282347e+38f);
        util->Unk_490e70(1.04719758f, 9.0f, 1.0f, item->field_38, item->field_68[3], item->field_68[2], 9,
                         const_cast<f32*>(weights), 1, field_220, &color, nullptr, &range, false, 0, 0);
    }
    CRenderTexture* sources[3] = {item->field_68[0], item->field_68[1], item->field_68[2]};
    s32 result = util->Unk_48d220(1.0f / 3.0f, 1.0f, item->field_a0, 3, sources, nullptr, field_224, 0);
    if (field_1dc != 0.0f && item->field_28 == 1) {
        Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
        Unk_Float value(item->field_2c);
        Unk_Float4 weight(value, value, value, value);
        util->Unk_496b40(1.0f, 0.002f, item->field_a0, item->field_78[0], item->field_a0, &weight, 0, &color, 0,
                         false, false, 0, 0);
    }
    return result;
}

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
