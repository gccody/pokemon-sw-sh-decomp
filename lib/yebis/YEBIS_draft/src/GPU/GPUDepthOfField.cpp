// Scope: common
// PPFX::CDepthOfField (lib/yebis/YEBIS_draft/src/GPU/GPUDepthOfField.h). The
// TU's statics are Unk_Statics.h's and its own (below), which its static
// initialiser, 0x71004b72d0 (_GLOBAL__sub_I_GPUDepthOfField.cpp), sets up.
#include <math.h>
#include <string.h>

#include <algorithm>

#include <yebis/YEBIS_draft/src/GPU/GPUClassUtil.h>
#include <yebis/YEBIS_draft/src/GPU/GPUDepthOfField.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceTexture.h>
#include <yebis/YEBIS_draft/src/GPU/TinyEffect/TFXString.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>

#define PPFX_FILE "C:/workspace/YEBIS_draft/src/GPU/GPUDepthOfField.cpp"
#include <yebis/YEBIS_draft/src/GPU/Unk_Log.h>

// 0x7100446df0: a result's name (Unk_447050.cpp)
const char* Unk_446df0(s32 result);

// 0x710049c8d0 (lib/yebis/leaf)
s32 Unk_49c8d0_call(void* self, void* value);

// 0x71004738c0 (lib/yebis/leaf): GPUTextureUtil.cpp's constants buffer
const u8* Unk_4738c0_get();

// 0x71004738d0 (lib/yebis/leaf): its second constants buffer
const u8* Unk_4738d0_get();

// 0x710049fdc0 (lib/yebis/leaf)
void Unk_49fdc0_call(void* self, u64 value);

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

// 0x7100415370 (Unk_415f40.cpp): the points of `rings` rings around the
// centre of a disc of `radius`; their count
s32 Unk_415370(s32 rings, Unk_Float2* out, f32 radius);

// The TU's own statics (placeholder names). LLVM merged them with
// Unk_Statics.h's into one block (0x71024e7500), sorted by size: the angle,
// the number of points of three rings (+0x4), Unk_4b19a0's warning counter
// (+0x8), the generators of 0x71004b0650 and 0x71004b1100 (+0xc, +0x1c,
// each split into four words), the white points (+0x2c), the two
// generators' guards (+0xf0), Unk_StaticsBase.h's objects (+0x100) and the
// levels' colours (+0x1b8).
static const s32 Unk_RingPoints = Unk_415370(3, nullptr, 1.0f);
// what a level is drawn with when field_174 says the levels are coloured
static const Unk_Float4 Unk_LevelColours[8] = {
    Unk_Float4(0.25f, 1.0f, 0.25f, 1.0f), Unk_Float4(1.0f, 0.25f, 1.0f, 1.0f),  Unk_Float4(1.0f, 1.0f, 0.25f, 1.0f),
    Unk_Float4(0.25f, 0.25f, 1.0f, 1.0f), Unk_Float4(1.0f, 0.25f, 0.25f, 1.0f), Unk_Float4(0.25f, 1.0f, 0.75f, 1.0f),
    Unk_Float4(0.25f, 1.0f, 0.25f, 1.0f), Unk_Float4(1.0f, 0.25f, 1.0f, 1.0f),
};

// 0x7101eba3f4: "CDepthOfField"
extern const char Unk_1eba3f4[];

// the members as the constructor leaves them (inline in Unk_4a7760 and vf3)
inline void CDepthOfField::Unk_ResetMembers() {
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
    field_164 = 0;
    field_258 = 0;
    field_260 = nullptr;
    field_268 = 0;
    field_270 = 0;
    field_278 = 0.0f;
    field_280[0] = nullptr;
    field_280[1] = nullptr;
    field_280[2] = nullptr;
    field_280[3] = nullptr;
    field_280[4] = nullptr;
    field_2c8 = nullptr;
    field_2d0 = nullptr;
    field_2d8 = nullptr;
    field_2e0 = nullptr;
    field_2e8 = nullptr;
    field_2f0 = 0;
    for (s32 i = 0; i < 4; i++) {
        field_2f8[i] = nullptr;
    }
    for (s32 i = 0; i < 4; i++) {
        field_318[i] = nullptr;
    }
    for (s32 i = 0; i < 4; i++) {
        field_338[i] = nullptr;
    }
    for (s32 i = 0; i < 4; i++) {
        field_358[i] = nullptr;
    }
    for (s32 i = 0; i < 4; i++) {
        field_378[i] = nullptr;
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
}

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
    Unk_ResetMembers();
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
    result = CreateDeviceResources();
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
    if (ValidateInitParam(field_228, &field_c0) < 0)
        return -1;
    for (s32 i = 0; i < field_c0.field_10; i++) {
        if (field_4a8[i].field_a0->field_2c.field_c == 0)
            return -1;
    }
    return 0;
}

// 0x71004aa030
s32 CDepthOfField::Unk_4aa030(s32 value) {
    if (value < 0) {
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
    } else {
        field_170 = value;
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
    util->Unk_47abf0(field_1e8.field_0[0].field_0);
}

// 0x71004afaa0
f32 CDepthOfField::Unk_4afaa0(f32 arg0, f32 arg1) {
    f32 focal = field_1b0;
    f32 near = field_1a8;
    f32 scale = focal * field_1b4.field_0 / (focal - near);
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

// the larger of two elements, by reference (inline)
static inline const Unk_Float& Unk_MaxRef(const Unk_Float& a, const Unk_Float& b) {
    return a.field_0 > b.field_0 ? a : b;
}

// the larger of two values, by reference (inline)
static inline const f32& Unk_MaxRefF(const f32& a, const f32& b) {
    return a > b ? a : b;
}

// the size of a view whose tangent of half the angle is `tanHalf` (inline)
static inline f32 Unk_ViewSizeTan(f32 tanHalf, f32 distance, f32 width) {
    if (!(distance > 0.0f))
        return width / (2.0f * tanHalf);
    return distance * width * 0.5f / (tanHalf * distance + width * 0.5f);
}

// 0x71004af020
// (Unk_Quantize's scaled exponent is a named local: see the header.)
// NON_MATCHING: registers only: the entry copies of `mode` and `value` come in
// the other order (moving `mode` among the floats would change the signature
// that GPUPostEffect.cpp's call uses), and the clip's default elements get
// w12/w11 swapped, so the invalid path reuses a register the original sets
// again (the order of the result locals' declarations and assigning the
// default in each path don't change it).
s32 CDepthOfField::Unk_4af020(s32 mode, f32 fov, f32 distance, f32 width, f32 value, f32 exponent, f32 angle,
                              f32 focus, f32 a7, f32* outSize, Unk_Float* outFNumber, Unk_Float* outValue, f32* outCoc,
                              f32* outRatio, Unk_Float4* outClip, f32 limit) {
    f32 minimum = Unk_4af690(field_198, field_1b0, field_1b8);
    minimum = minimum < 0.0f ? 0.0f : minimum;
    field_3e4 = minimum;
    f32 height = 2.0f * tanf(fov * 0.5f);
    f32 size = Unk_ViewSizeTan(height * 0.5f, distance, width);
    f32 angleSize = 0.0f;
    if (angle > 0.0f)
        angleSize = width / (2.0f * tanf(angle * 0.5f));
    if (mode == 1 || mode == 3) {
        if (focus > 0.0f && a7 != 0.0f) {
            value = Unk_Abs(a7) * Unk_Sign(focus - distance) * height * (distance - size) * (focus - size) /
                    (focus - distance);
        }
    }
    field_1c0 = 0.0f;
    f32 fNumber;
    Unk_Float n;
    switch (mode) {
    case 2:
        field_1c0 = Unk_Quantize(value);
        value = value / angleSize * powf(size, 1.0f - exponent) * powf(angleSize, exponent);
        // fall through
    case 0:
        if (value > 0.0f) {
            fNumber = Unk_Quantize(value);
            if (field_3b4)
                fNumber = Unk_MaxRefF(fNumber, minimum);
            n = size / fNumber;
        } else {
            fNumber = value;
            n = 0.0f;
        }
        break;
    case 3:
        value = value / angleSize * powf(size, exponent) * powf(angleSize, 1.0f - exponent);
        // fall through
    case 1:
        n = value;
        if (value > 0.0f) {
            fNumber = size / value;
            if (field_3b0 > 0.0f) {
                fNumber = Unk_Quantize(fNumber);
                n = size / fNumber;
            }
            if (field_3b4 && fNumber < minimum) {
                fNumber = minimum;
                n = size / minimum;
            }
        } else {
            fNumber = 0.0f;
        }
        break;
    default:
        fNumber = 0.0f;
        n = 0.0f;
        break;
    }
    if (field_1c0 <= 0.0f)
        field_1c0 = fNumber;
    if (field_3b4)
        field_1c0 = Unk_MaxRefF(field_1c0, minimum);
    bool valid = distance > 0.0f && fNumber > 0.0f && n.field_0 > 0.0f && width > 0.0f;
    if (!valid && distance > 0.0f && width > 0.0f) {
        fNumber = 1.0e20f;
        n = size / fNumber;
        valid = true;
    }
    s32 result;
    f32 coc;
    f32 ratio;
    Unk_Float4 clip(1.0f, 0.0f, 1.0f, 0.0f);
    if (valid) {
        coc = size * n.field_0 / (distance - size);
        ratio = coc / width;
        if (field_16c == 1) {
            f32 scale;
            f32 bias;
            if (field_170 > 0) {
                f32 least = field_170 < 9 ? 0.2f : (field_170 < 11 ? 0.4f : 1.0f);
                if (limit > 0.0f && limit < distance) {
                    f32 blur;
                    if (limit == 0.0f)
                        blur = 0.0f;
                    else
                        blur = (limit - distance) / limit * coc;
                    blur = -(blur / width);
                    least = least > blur ? least : blur;
                }
                f32 fraction = ratio / (ratio + least);
                scale = fraction < 1.0e-4f ? 1.0e-4f : std::min(fraction, 0.5f);
                bias = 1.0f - scale;
            } else {
                f32 far = field_190;
                if (limit > 0.0f)
                    far = std::min(limit, far);
                if (far > 0.0f)
                    scale = 64000.0f / Unk_Abs((far - distance) / far - 1.0f);
                else
                    scale = 1.0f;
                bias = -scale;
            }
            clip = Unk_Float4(scale, bias, 1.0f / scale, -bias / scale);
        }
        result = 0;
    } else {
        coc = 0.0f;
        ratio = 0.0f;
        result = 1;
    }
    if (outSize != nullptr)
        *outSize = size;
    if (outFNumber != nullptr)
        *outFNumber = Unk_Float(fNumber);
    if (outValue != nullptr)
        *outValue = n;
    if (outCoc != nullptr)
        *outCoc = coc;
    if (outRatio != nullptr)
        *outRatio = ratio;
    if (outClip != nullptr)
        *outClip = clip;
    return result;
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
            size0 = Unk_PairSize(field_3c0, distance, width);
            value1 = field_3c8;
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

// 0x71004afae0
// (the absolute distance is taken before the early exit's test: its compare is
// then the test's; case 1 reads field_1d8 into a local, whose store shares the
// return with case 0's; the half aperture is a named local, read between the
// two lens fields, and each branch reads its factor into a local first)
s32 CDepthOfField::Unk_4afae0(f32* nearSize, f32* farSize) {
    switch (field_1c8) {
    case 0: {
        f32 aperture = field_1cc.field_0;
        f32 distance = field_1d0;
        f32 absDistance = Unk_Abs(distance);
        if (aperture == 0.0f || distance == 0.0f) {
            if (nearSize != nullptr)
                *nearSize = 0.0f;
            if (farSize != nullptr)
                *farSize = 0.0f;
            return 1;
        }
        f32 focal = field_1b0;
        f32 half = aperture * 0.5f;
        f32 near = field_1a8;
        f32 scale = focal * near / (focal - near);
        f32 coc = half * scale / absDistance;
        f32 depth = distance > -scale ? distance : -scale;
        f32 blur;
        if (depth > 0.0f) {
            f32 k = field_1c4;
            blur = (depth - focal) * k;
        } else {
            f32 k = field_1ac.field_0;
            blur = -((scale + depth) * k);
        }
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
    case 1: {
        f32 far = field_1d8;
        if (far < 0.0f) {
            if (nearSize != nullptr)
                *nearSize = 0.0f;
            if (farSize != nullptr)
                *farSize = 0.0f;
            return 1;
        }
        if (nearSize != nullptr)
            *nearSize = field_1d4;
        if (farSize != nullptr)
            *farSize = far;
        return 0;
    }
    default:
        return -3;
    }
}

// 0x71004afd80
// The sign test is `!(depth > 0.0f)` (the original's `b.le`), and `focus` is
// declared before `aperture` (the zero path's registers). The statement order
// is the best of 1204 (near read before focal, the doubled size its own
// local), `half` is named (its DBG_VALUE ends the A57 FP load balancing
// pass's chain there) and field_1b8 is read after the lens's division.
s32 CDepthOfField::Unk_4afd80(f32 size, f32 distance, f32 angle) {
    f32 focus;
    f32 aperture;
    if (size == 0.0f) {
        aperture = 0.0f;
        focus = 0.0f;
    } else {
        f32 depth = distance == 0.0f ? -2.9802322e-8f : distance * -0.5f;
        f32 near = field_1a8;
        f32 half = near * 0.5f;
        f32 position = Unk_Sign(depth) * half;
        f32 coc = field_1b8 * size * 0.5f;
        f32 diameter = coc * 2.0f;
        f32 focal = field_1b0;
        f32 scale = near * focal / (focal - near);
        f32 ratio = diameter / scale;
        f32 absPosition = Unk_Abs(position);
        f32 view = tanf(angle * 0.5f) / field_19c;
        focal = field_1b0;
        near = field_1a8;
        f32 factor = view / (focal * field_1b4.field_0 / (focal - near)) * field_1b8;
        f32 limit = position > -near ? position : -near;
        f32 far = field_1ac.field_0;
        factor = depth * factor;
        f32 blur = 0.0f;
        if (limit > 0.0f)
            blur = far * (near * limit / (limit - near)) - near * far;
        else if (limit < 0.0f)
            blur = -(far * (near + limit)) / limit;
        f32 value = absPosition * ratio;
        factor = Unk_Abs(factor / (blur * 0.5f));
        if (!(depth > 0.0f)) {
            factor = 2.0f / (factor + 1.0f);
            aperture = value * factor;
            if (aperture < 0.0f)
                return -6;
        } else {
            factor = 1.0f / factor / near;
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

// a channel of an RGBA8 pixel, squared (inline)
static inline f64 Unk_Channel2(u32 value) {
    f64 x = static_cast<f32>(value & 0xff) * (1.0 / 255.0);
    return x * x;
}

// a square root of what isn't negative (inline)
static inline f64 Unk_SqrtPositive(f64 x) {
    return x > 0.0 ? sqrt(x) : x;
}

// a value from 0 to 1 as a byte (inline)
static inline u32 Unk_ToByte(f64 x, s32 shift) {
    if (x >= 1.0)
        return 0xff << shift;
    if (x <= 0.0)
        return 0;
    return static_cast<u32>(x * 255.9999f) << shift;
}

// an RGB colour in double precision (whole-value operators, inline)
struct Unk_Rgb {
    f64 r;
    f64 g;
    f64 b;
};

static inline Unk_Rgb operator+(const Unk_Rgb& a, const Unk_Rgb& b) {
    return {a.r + b.r, a.g + b.g, a.b + b.b};
}

static inline Unk_Rgb operator*(const Unk_Rgb& a, const Unk_Rgb& b) {
    return {a.r * b.r, a.g * b.g, a.b * b.b};
}

static inline Unk_Rgb operator*(const Unk_Rgb& a, f64 s) {
    return {a.r * s, a.g * s, a.b * s};
}

// an RGBA8 pixel's colour, squared (inline)
static inline Unk_Rgb Unk_Linear(u32 pixel) {
    Unk_Rgb c = {static_cast<f32>((pixel >> 16) & 0xff), static_cast<f32>((pixel >> 8) & 0xff),
                 static_cast<f32>(pixel & 0xff)};
    c = c * (1.0 / 255.0);
    return c * c;
}

// 0x71004aff50
// The colours are whole values (Unk_Rgb's operators): the A57 FP load
// balancing pass only renames a product whose next use is the next product,
// and a named scalar's DBG_VALUE (the build has -g) is a use in between. The
// third loop isn't guarded by its own `height != 0` (with it, the column loop
// is unswitched and the zeroing isn't repeated), and the pixels are addressed
// from `data` in each loop.
s32 CDepthOfField::Unk_4aff50(u8* data, u32 width, u32 height, const f32* scale, bool merge) {
    u32 stride = width * 4;
    if (width != 0 && merge) {
        u8* next = data + stride;
        for (u32 i = 0; i < width; i++) {
            u32 pixel = *reinterpret_cast<u32*>(data + i * 4);
            Unk_Rgb c = Unk_Linear(pixel);
            if (c.r > 0.0 || c.g > 0.0 || c.b > 0.0) {
                u32 other = *reinterpret_cast<u32*>(next + i * 4);
                f32 alpha = static_cast<f32>(pixel >> 24);
                c = c + Unk_Linear(other);
                f64 r = c.r;
                f64 g = c.g;
                f64 b = c.b;
                f64 a = alpha * (1.0 / 255.0);
                r = Unk_SqrtPositive(r);
                g = Unk_SqrtPositive(g);
                b = Unk_SqrtPositive(b);
                f64 a2 = static_cast<f32>(other >> 24) * (1.0 / 255.0);
                *reinterpret_cast<u32*>(data + i * 4) = Unk_ToByte(a, 24);
                u32 cr = Unk_ToByte(r, 16);
                u32 cg = Unk_ToByte(g, 8);
                u32 cb = Unk_ToByte(b, 0);
                u32 ca = Unk_ToByte(a2, 24);
                *reinterpret_cast<u32*>(next + i * 4) = cr | cg | cb | ca;
            }
        }
    }
    if (width != 0) {
        f64 inverse = 1.0 / height;
        for (u32 x = 0; x < width; x++) {
            f64 sb = 0.0;
            f64 sg = 0.0;
            f64 sr = 0.0;
            for (u32 y = 0; y < height; y++) {
                u32 pixel = *reinterpret_cast<u32*>(data + x * 4 + y * stride);
                Unk_Rgb c = Unk_Linear(pixel);
                f32 position = static_cast<f32>(height - y) - 0.5f;
                f64 angle = inverse * position * 3.14159265f;
                c = c * angle * inverse;
                sr += c.r;
                sg += c.g;
                sb += c.b;
            }
            sr *= 2.0 / 3.14159265f;
            sg *= 2.0 / 3.14159265f;
            sb *= 2.0 / 3.14159265f;
            f64 fr = scale[0] / sr;
            f64 fg = scale[1] / sg;
            f64 fb = scale[2] / sb;
            Unk_Rgb f = {fr, fg, fb};
            for (u32 y = 0; y < height; y++) {
                u32 pixel = *reinterpret_cast<u32*>(data + x * 4 + y * stride);
                Unk_Rgb c = Unk_Linear(pixel) * f;
                f64 r = c.r;
                f64 g = c.g;
                f64 b = c.b;
                f64 a = static_cast<f32>(pixel >> 24) * (1.0 / 255.0);
                r = Unk_SqrtPositive(r);
                g = Unk_SqrtPositive(g);
                b = Unk_SqrtPositive(b);
                u32 cr = Unk_ToByte(r, 16);
                u32 cg = Unk_ToByte(g, 8);
                u32 cb = Unk_ToByte(b, 0);
                u32 ca = Unk_ToByte(a, 24);
                *reinterpret_cast<u32*>(data + x * 4 + y * stride) = cr | cg | cb | ca;
            }
        }
    }
    return 0;
}

// 0x71004b35a0
CRenderTexture* CDepthOfField::Unk_4b35a0(bool second, s32 index) {
    if (field_1dc != 0.0f) {
        CRenderTexture* texture = second ? field_470[index] : field_468[index];
        if (texture != nullptr)
            return texture;
    }
    return second ? field_450[index] : field_448[index];
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
// (the arguments are locals read in their order, the last level's flag just before the call)
s32 CDepthOfField::Unk_4b4c40() {
    s32 result = 0;
    if (field_c0.field_6d) {
        for (s32 i = 0; i < field_3f8; i++) {
            CRenderTexture* source = field_430[i];
            CRenderTexture* target = field_430[i + 1];
            void* arg3 = field_488[i];
            void* arg4 = field_438[i];
            s32 arg5 = field_400[i];
            s32 arg6 = field_408[i];
            void* arg7 = field_410[i];
            void* arg8 = field_418[i];
            Unk_Pass* arg9 = &field_420[i];
            Unk_Pass* arg10 = &field_428[i];
            bool last = i == field_3f8 - 1;
            s32 status = Unk_4b35f0(i == 0 ? 3.0f : 2.2f, source, target, arg3, arg4, arg5, arg6, arg7, arg8, arg9,
                                    arg10, i == 0, last);
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

// util's Unk_48b1e0 in white (inline: the colour is stored after the
// caller's arguments are read, which a local of the caller isn't)
static inline s32 Unk_DrawWhite(CTextureUtil* util, f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1,
                                f32 v1, f32 arg8, f32 arg9, f32 arg10, Unk_GPUTexture* texture, s32 arg12,
                                void* arg13, s32 arg14, bool mirror, void* arg16, void* arg17, void* arg18,
                                void* arg19, s32 arg20, f32 arg21, u32 flags) {
    Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
    return util->Unk_48b1e0(x, y, width, height, u0, v0, u1, v1, arg8, arg9, arg10, texture, arg12, arg13, arg14,
                            mirror, arg16, arg17, arg18, arg19, arg20, arg21, &color, flags);
}

// 0x71004b4e10
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
        Unk_DrawWhite(util, 0.0f, 0.0f, static_cast<f32>(static_cast<u32>(source->field_54)),
                         static_cast<f32>(static_cast<u32>(source->field_58)), 0.0f, 0.0f, u1, v1, field_190,
                         field_194, field_1b0, field_238, field_16c, nullptr, 0, field_240, &field_1e8, nullptr,
                         nullptr, nullptr, 0, 0.5f, 0);
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
    util->Unk_47abf0(field_1e8.field_0[0].field_0);
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

// 0x71004b6530: the levels' blurs composited into the target (the source's
// level 0, then the far blurs from the farthest, then the near ones)
// The textures' sizes, scales and biases are read in field order (source,
// first level, target); the order of the four coordinates is the closest of
// all 24 (and of the 120 orders of the read groups).
// NON_MATCHING: register allocation: the source's and the first level's
// scale/bias floats get other callee-saved registers, two loop temporaries in
// the first level loop swap, and the early `return result` keeps its copy to
// w0 in its own block (laid out after the size test) where here the returns
// share a phi in w26 (an `if (result >= 0)` body, `result = 0` at the end and
// the call inside the early return don't change that).
s32 CDepthOfField::Unk_4b6530(CRenderTexture* source, void* arg2, CRenderTexture* target) {
    if (target == nullptr) {
        target = field_228;
    }
    if (source == nullptr) {
        source = field_228;
    }
    if (field_c0.field_6d) {
        if (field_c0.field_70 > 0) {
            f32 half = field_4a8->field_30 * 0.5f;
            Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
            Unk_4b0650(2, 2, source, static_cast<CRenderTexture*>(arg2), nullptr, &color, true,
                       field_c0.field_70 == 1, -1, 0.0f, half + half);
            source = static_cast<CRenderTexture*>(arg2);
        }
        Unk_4b5b40();
    }
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    Unk_GPUTexture* textures[15];
    CRenderTexture* list[15] = {};
    Unk_Float2 weights[15];
    u32 flags = field_154;
    s32 far;
    s32 near;
    s32 count;
    CRenderTexture* first = nullptr;
    if (flags & 0xc) {
        near = field_20c;
        far = field_210;
        count = far + 1 + near;
        list[0] = source;
        textures[0] = Unk_GetTexture(source);
        weights[0] = Unk_Float2(0.0f, 0.0f);
        for (s32 i = 0; i < far; i++) {
            s32 index = i + 1;
            s32 level = far - 1 - i;
            Unk_Level* item = &field_4a8[level];
            textures[index] = reinterpret_cast<Unk_GPUTexture*>(util->field_29a70[2]);
            weights[index] = Unk_Float2(0.0f, 0.0f);
            if (level < far) {
                CRenderTexture* texture = item->field_b8 != nullptr ? item->field_b8 : item->field_a8;
                list[index] = texture;
                textures[index] = Unk_GetTexture(texture);
                weights[index] = *reinterpret_cast<const Unk_Float2*>(&item->field_d0);
                if (first == nullptr) {
                    first = texture;
                }
            }
        }
        for (s32 i = 0; i < near; i++) {
            s32 index = i + far + 1;
            Unk_Level* item = &field_4a8[i];
            textures[index] = reinterpret_cast<Unk_GPUTexture*>(util->field_29a70[2]);
            weights[index] = Unk_Float2(0.0f, 0.0f);
            CRenderTexture* texture = item->field_b0 != nullptr ? item->field_b0 : item->field_a0;
            list[index] = texture;
            textures[index] = Unk_GetTexture(texture);
            weights[index] = *reinterpret_cast<const Unk_Float2*>(&item->field_d8);
            if (first == nullptr) {
                first = texture;
            }
        }
    } else {
        if (flags & 2) {
            near = field_20c;
            far = field_210;
            count = near + far + 1;
        } else {
            count = field_208 + 1;
            far = 0;
            near = count;
        }
        list[0] = source;
        textures[0] = Unk_GetTexture(source);
        weights[0] = Unk_Float2(0.0f, 0.0f);
        for (s32 i = 1; i < count; i++) {
            Unk_Level* item = &field_4a8[i - 1];
            textures[i] = reinterpret_cast<Unk_GPUTexture*>(util->field_29a70[2]);
            weights[i] = Unk_Float2(0.0f, 0.0f);
            if (i <= field_208) {
                CRenderTexture* texture = item->field_a0;
                list[i] = texture;
                textures[i] = Unk_GetTexture(texture);
                weights[i] = *reinterpret_cast<const Unk_Float2*>(&item->field_d0);
                if (first == nullptr) {
                    first = item->field_a0;
                }
            }
        }
    }
    if (first == nullptr) {
        first = source;
    }
    u32 sourceWidth = source->field_54;
    u32 sourceHeight = source->field_58;
    f32 sourceScaleU = source->field_88;
    f32 sourceScaleV = source->field_8c;
    f32 sourceBiasU = source->field_90;
    f32 sourceBiasV = source->field_94;
    u32 firstWidth = first->field_54;
    u32 firstHeight = first->field_58;
    f32 firstScaleU = first->field_88;
    f32 firstScaleV = first->field_8c;
    f32 firstBiasU = first->field_90;
    f32 firstBiasV = first->field_94;
    u32 targetWidth = target->field_54;
    u32 targetHeight = target->field_58;
    for (s32 i = 0; i < 15; i++) {
        CRenderTexture* texture = list[i];
        if (texture != nullptr) {
            Unk_GPUTexture* gpuTexture = Unk_GetTexture(texture);
            gpuTexture->vf17(texture->field_54 == target->field_54 && texture->field_58 == target->field_58);
            gpuTexture->vf18(1);
        }
    }
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    if (result < 0) {
        return result;
    }
    f32 u3 = firstScaleU * static_cast<f32>(firstWidth) + firstBiasU;
    f32 v1 = sourceScaleV * static_cast<f32>(sourceHeight) + sourceBiasV;
    f32 u1 = sourceScaleU * static_cast<f32>(sourceWidth) + sourceBiasU;
    f32 v3 = firstScaleV * static_cast<f32>(firstHeight) + firstBiasV;
    bool sameSize = source->field_54 == target->field_54 && source->field_58 == target->field_58;
    bool sameSurface = source->field_b0 == target->field_b8[target->field_a0];
    bool same = sameSize || sameSurface;
    if (same) {
        Unk_GetTexture(source)->vf17(1);
    }
    f32 width = static_cast<f32>(targetWidth);
    f32 height = static_cast<f32>(targetHeight);
    switch (flags) {
    case 2:
        util->Unk_47ae50(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, 0.0f, 0.0f, u3, v3, far, near, textures,
                         weights, field_16c, 0, 0);
        break;
    case 6:
    case 14:
    case 22: {
        Unk_Float2 value(1.99f, 1.0f);
        s32 kind = field_4a8->field_10;
        bool single = field_c0.field_6d && field_c0.field_70 < 2;
        if (kind == 1 || single) {
            value = Unk_Float2(1.95f, 0.9f);
        }
        util->Unk_47b040(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, 0.0f, 0.0f, u3, v3, far, near, textures,
                         weights, &value, field_16c, 0, 0);
        break;
    }
    default:
        if (flags < 2) {
            util->Unk_47ac50(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, 0.0f, 0.0f, u3, v3, count, textures,
                             weights, false, field_16c, 0, 0);
        }
        break;
    }
    if (same) {
        Unk_GetTexture(source)->vf17(0);
    }
    for (s32 i = 0; i < 15; i++) {
        if (list[i] != nullptr) {
            Unk_GetTexture(list[i])->vf17(0);
        }
    }
    return 0;
}

// 0x71004b4ff0: the numbers of levels with a near and a far blur, and the
// levels' and the passes' sources scaled down from `source`
// `skip` is `same & (i >= field_218)`. In the passes' loop the width isn't a
// named float and y's half is (their DBG_VALUEs steer the FP load balancing).
// NON_MATCHING: 2744 vs 2792 bytes, same calls and arguments; registers and
// scheduling differ, and the two scale vectors (field_178 clamped) are stored
// as two float elements here, where the original stores the first element
// from an integer select and the second from a float one (with the clamp's
// condition materialised by cset/and/tst instead of a ccmp chain). Tried: the
// size as f32, as Unk_Float, the vector assigned in each branch, the
// condition with & and &=.
s32 CDepthOfField::Unk_4b4ff0(CRenderTexture* source) {
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    field_20c = 0;
    field_210 = 0;
    f32 nearDistance = field_194;
    f32 farDistance = field_190;
    for (s32 i = 0; i < field_c0.field_10; i++) {
        Unk_Level* item = &field_4a8[i];
        if (!(nearDistance > 0.0f && field_1b0 > 0.0f &&
              (nearDistance - field_1b0) / nearDistance * item->field_d0 + item->field_d4 < 0.0f)) {
            field_210 = i + 1;
        }
        if (!(farDistance > 0.0f && field_1b0 > 0.0f &&
              item->field_dc - (farDistance - field_1b0) / farDistance * item->field_d8 < 0.0f)) {
            field_20c = i + 1;
        }
    }
    if (field_1f8[0] >= 0) {
        field_20c = std::min(field_1f8[0], field_20c);
    }
    if (field_1f8[1] >= 0) {
        field_210 = std::min(field_1f8[1], field_210);
    }
    u32 flags = field_154;
    field_214 = field_20c;
    field_218 = field_210;
    if (flags & 0x10) {
        field_214 = 1;
        field_218 = 1;
    } else if (flags & 0x20) {
        field_214 = 0;
        field_218 = 0;
    }
    if (field_1f8[2] >= 0) {
        field_214 = std::min(field_1f8[2], field_214);
    }
    if (field_1f8[3] >= 0) {
        field_218 = std::min(field_1f8[3], field_218);
    }
    field_208 = std::max(field_210, field_20c);
    if (source == nullptr) {
        source = field_228;
    }
    // the chain of smaller copies
    CRenderTexture* current = source;
    CRenderTexture* next = nullptr;
    bool scaled = false;
    for (s32 i = 0; i < field_498; i++) {
        next = field_490[i];
        if (static_cast<u32>(next->field_54) < static_cast<u32>(current->field_54)) {
            scaled = true;
            Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
            Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
            util->Unk_47dfa0(0.0f, 0.0f, 0.0f, 1.0f, current, next, 0, &color, 0, false, false, 1, &zero, nullptr, -1);
            current = next;
        }
    }
    if (scaled) {
        source = next;
    }
    // the passes of the second kind
    if (field_c0.field_6d && field_3f8 >= 0) {
        CRenderTexture* current = source;
        for (s32 i = 0; i <= field_3f8; i++) {
            CRenderTexture* next = field_430[i];
            if (next != current) {
                Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
                Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
                util->Unk_47dfa0(0.0f, 0.0f, 0.0f, 1.0f, current, next, 0, &color, 0, false, false, 1, &zero, nullptr,
                                 -1);
            }
            current = next;
        }
        for (s32 i = 0; i < field_3f8; i++) {
            Unk_Pass* first = field_420;
            Unk_Pass* second = field_428;
            f32 size = (field_3e0 - 1.5f) * powf(0.5f, static_cast<f32>(i)) + 1.5f;
            size = size < 2.0f ? 2.0f : std::min(size, 65000.0f);
            f32 height = static_cast<f32>(static_cast<u32>(field_c0.field_0[2]));
            f32 last = field_3dc;
            if (i == field_3f8 - 1) {
                last = last * 0.5f;
            }
            f32 x = second[i].field_78.field_0;
            f32 y;
            if (static_cast<f32>(static_cast<u32>(field_c0.field_0[1])) < height) {
                f32 ratio = static_cast<f32>(static_cast<u32>(field_c0.field_0[1])) / height;
                x = x * ratio;
                y = ratio * first[i].field_78.field_0;
            } else {
                y = first[i].field_78.field_0;
            }
            x = x * 0.5f / field_1e4 * field_1e8.field_0[0].field_0 + field_1e8.field_0[1].field_0;
            f32 half = y * 0.5f;
            y = half / field_1e4 * field_1e8.field_0[0].field_0 + field_1e8.field_0[1].field_0;
            Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
            Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
            util->Unk_4816a0(size, field_3d8 / field_3ac, last / field_3ac, field_430[i],
                             static_cast<CRenderTexture*>(field_488[i]), &color, &zero, x, y);
        }
    }
    // the levels' sources
    s32 count = (field_154 & 4) != 0 ? field_20c : field_208;
    if (count > 0) {
        if ((field_154 & 8) == 0) {
            CRenderTexture* current = source;
            for (s32 i = 0; i < count; i++) {
                CRenderTexture* next = field_4a8[i].field_38;
                if (current != next) {
                    s32 mode = current == source ? field_21c : field_220;
                    Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
                    Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
                    util->Unk_47dfa0(0.0f, 0.0f, 0.0f, 1.0f, current, next, mode, &color, 0, false, false, 1, &zero,
                                     nullptr, -1);
                }
                current = next;
            }
        } else {
            CRenderTexture* current = source;
            for (s32 i = 0; i < count; i++) {
                Unk_Level* item = &field_4a8[i];
                CRenderTexture* next = item->field_38;
                if (current != next) {
                    s32 mode = current == source ? field_21c : field_220;
                    Unk_Float2 range = *reinterpret_cast<const Unk_Float2*>(&item->field_d8);
                    range.field_0[0].field_0 = -range.field_0[0].field_0;
                    Unk_Float size;
                    if (field_c0.field_70 < 2) {
                        size = field_178;
                        if (field_c0.field_70 == 1 && i == 1 && size.field_0 < 1.0f) {
                            size = 1.0f;
                        }
                    } else {
                        size = std::max(field_178, 1.0f);
                    }
                    Unk_Float2 scale(size, size);
                    util->Unk_48b810(0.0f, 0.0f, current, next, &range, &scale, field_16c, mode, false, false, true,
                                     1);
                }
                current = next;
            }
        }
    }
    // the far blurs' sources
    if ((field_154 & 4) != 0 && field_210 > 0) {
        CRenderTexture* current = source;
        for (s32 i = 0; i < field_210; i++) {
            Unk_Level* item = &field_4a8[i];
            s32 mode = current == source ? field_21c : 0;
            CRenderTexture* target = item->field_48[0];
            bool same = current->field_54 == target->field_54 && current->field_58 == target->field_58;
            same &= mode == 0;
            Unk_Float2 range = *reinterpret_cast<const Unk_Float2*>(&item->field_d0);
            Unk_Float size;
            if (field_c0.field_70 < 2) {
                size = field_178;
                if (field_c0.field_70 == 1 && i == 1 && size.field_0 < 1.0f) {
                    size = 1.0f;
                }
            } else {
                size = std::max(field_178, 1.0f);
            }
            Unk_Float2 scale(size, size);
            bool skip = same & (i >= field_218);
            CRenderTexture* next = skip ? current : target;
            if (i < field_218) {
                util->Unk_48b810(0.0f, 0.0f, current, next, &range, &scale, field_16c, mode, true, false, true, 1);
            } else if (!skip) {
                Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
                Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
                util->Unk_47dfa0(0.0f, 0.0f, 0.0f, 1.0f, current, next, mode, &color, 0, false, false, 1, &zero,
                                 nullptr, -1);
            }
            current = next;
        }
        for (s32 i = 0; i < field_210; i++) {
            Unk_Level* item = &field_4a8[i];
            CRenderTexture* target = item->field_48[0];
            s32 mode = current == source ? field_21c : 0;
            s32 limit = field_218;
            bool same = current->field_54 == target->field_54 && current->field_58 == target->field_58;
            same &= mode == 0;
            bool skip = same && i >= limit;
            current = skip ? current : target;
            if (i >= limit) {
                f32 scale = field_16c == 1 ? 0.5f : 1.0f;
                f32 x = item->field_d0 * field_1e8.field_0[2].field_0;
                f32 y = item->field_d4 + item->field_d0 * field_1e8.field_0[3].field_0;
                Unk_Float2 range(x * scale, y * scale + 0.0f);
                util->Unk_48ba10(current, item->field_48[1], &range, 0, false);
            } else {
                u32 bits = item->field_1c;
                CRenderTexture* mask = nullptr;
                if (field_c0.field_6d) {
                    if (field_c0.field_70 < 2 && !(i == 1 && field_c0.field_70 == 1)) {
                        switch (item->field_18) {
                        case 0:
                            bits = 3;
                            break;
                        case 1:
                            bits = 5;
                            break;
                        case 2:
                            bits = 9;
                            break;
                        case 3:
                            bits = 17;
                            break;
                        }
                    }
                    if (i >= 2) {
                        s32 index;
                        switch (i) {
                        case 2:
                        case 3:
                            index = 0;
                            break;
                        case 4:
                        case 5:
                            index = 1;
                            break;
                        case 6:
                            index = 2;
                            break;
                        default:
                            index = -1;
                            break;
                        }
                        mask = static_cast<CRenderTexture*>(field_488[index]);
                    }
                }
                util->Unk_48d020(current, item->field_48[1], mask, bits,
                                 reinterpret_cast<const Unk_Float2*>(&item->field_d0), field_16c, field_170, true,
                                 field_17c, false);
            }
        }
    }
    return 0;
}

// 0x71004afc40
s32 CDepthOfField::Unk_4afc40(f32 width, f32 height, f32 tanHalfFov, f32 a3, f32 a4, f32 a5, f32 a6, f32 a7,
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
    return result;
}

// 0x7100442bc0 (GPUInterfaceDevice.cpp): the first of some formats that a
// usage can have, or a fallback
s32 Unk_442bc0(IGPUDevice* self, s32 usage, s32 type, const s32* formats, s32 count, s32 fallback);
// 0x71024e55b0: the device (GPUResourceManage.cpp)
extern IGPUDevice* Unk_24e55b0;

// a new object made with one argument (inline: the argument, and the
// temporaries it is made of, are evaluated before the allocation and live
// past it)
template <class T, class A>
static inline T* Unk_NewWith(A arg, const char* file, int line) {
    return new (Unk_4b99a0(Unk_238d5f8, sizeof(T), file, line, nullptr)) T(arg);
}
#define UNK_NEW_WITH(T, arg) Unk_NewWith<T>(arg, __FILE__, __LINE__)

// 0x71004a7f60: the description's defaults, then the passes of the second kind
// and their textures, the levels and theirs
// The levels' and the passes' loop indices are `u32` (closer than `s32`).
// NON_MATCHING: the same calls, branches and allocation lines; register
// allocation and block placement differ (the texture utilities' creation
// blocks and the levels' m_pResult texture are laid out elsewhere, `this` is
// spilled in the pass loop), the frame is 0x10 bytes smaller, and the copies
// to field_68/field_70 are scheduled after both of field_58/field_60's stores
s32 CDepthOfField::Unk_4a7f60() {
    if (field_c0.field_6d) {
        field_c0.field_18 = 5;
        field_c0.field_0[3] = 6;
        field_c0.field_10 = 7;
        s32 passes = field_c0.field_70 < 2 ? field_c0.field_70 : 2;
        field_c0.field_70 = passes > 0 ? passes : 0;
    } else {
        field_c0.field_70 = -1;
        if (field_c0.field_10 == 0) {
            field_c0.field_10 = 2;
        }
    }
    if (field_c0.field_5c == 0) {
        field_c0.field_5c = 160;
    }
    if (field_c0.field_60 <= 0.0f) {
        field_c0.field_60 = 0.125f;
    }
    if (field_c0.field_74 <= 0.0f) {
        field_c0.field_74 = static_cast<f32>(static_cast<u32>(field_c0.field_0[1])) /
                            static_cast<f32>(static_cast<u32>(field_c0.field_0[2]));
    }
    if (field_c0.field_78 <= 0.0f) {
        field_c0.field_78 = 1.0f;
    }
    field_178 = 0.1f;
    field_17c = 0;
    field_180 = field_c0.field_6d && field_c0.field_70 >= 2 ? 3 : 2;
    if (field_c0.field_14 == 0) {
        s32 formats[1] = {10};
        field_c0.field_14 = Unk_442bc0(Unk_24e55b0, 0x20001, 3, formats, 1, 10);
    }
    CRenderTexture* source = field_228;
    field_158 = source->field_54;
    field_15c = source->field_58;
    field_160 = source->field_2c.field_c;
    field_164 = field_c0.field_14;
    field_21c = 0;
    field_220 = 0;
    field_224 = 0;
    Unk_4aa030(field_c0.field_58);
    u32 flags = field_c0.field_0[0] & 1;
    if (field_c0.field_65) {
        f32 x = static_cast<f32>(static_cast<u32>(field_c0.field_0[1] + 1)) /
                static_cast<f32>(static_cast<u32>(field_228->field_54));
        f32 y = static_cast<f32>(static_cast<u32>(field_c0.field_0[2] + 1)) /
                static_cast<f32>(static_cast<u32>(field_228->field_58));
        f32 scale = 1.0f / static_cast<f32>(static_cast<u32>(field_c0.field_68));
        s32 count = static_cast<s32>(ceilf(logf(x > y ? x : y) / logf(scale))) - 1;
        field_498 = count > 0 ? count : 0;
    }
    {
        Unk_TFXString name = field_10 + "::m_pApertureFilterSharedLevelSourcePool";
#line 1953
        field_4a0 = UNK_NEW(CRenderTexturePool)(name.field_8);
    }
    field_250 = false;
    if (field_c0.field_6d) {
        field_3f8 = 3;
        f32 radii[2][4] = {{0.035f, 0.14f, 0.56f, 2.0f}, {0.035f, 0.14f, 0.56f, 2.0f}};
        f32 scale = 360.0f / static_cast<f32>(static_cast<u32>(field_c0.field_0[2]));
        for (s32 i = 0; i < field_3f8; i++) {
            radii[0][i] *= scale;
            radii[1][i] *= scale;
        }
#line 2005
        field_430 = UNK_NEW_ARRAY(CRenderTexture*, field_3f8 + 1);
        field_438 = UNK_NEW_ARRAY(CRenderTexture*, field_3f8);
        field_440 = UNK_NEW_ARRAY(CRenderTexture*, field_3f8);
#line 2009
        field_488 = UNK_NEW_ARRAY(CRenderTexture*, field_3f8);
#line 2011
        field_448 = UNK_NEW_ARRAY(CRenderTexture*, field_3f8);
        field_450 = UNK_NEW_ARRAY(CRenderTexture*, field_3f8);
        field_468 = UNK_NEW_ARRAY(CRenderTexture*, field_3f8);
        field_470 = UNK_NEW_ARRAY(CRenderTexture*, field_3f8);
        field_460 = nullptr;
        field_458 = nullptr;
        field_480 = nullptr;
        field_478 = nullptr;
#line 2028
        field_400 = UNK_NEW_ARRAY(s32, field_3f8);
        field_408 = UNK_NEW_ARRAY(s32, field_3f8);
        field_410 = UNK_NEW_ARRAY(IGPUBuffer*, field_3f8);
        field_418 = UNK_NEW_ARRAY(IGPUBuffer*, field_3f8);
#line 2033
        field_420 = UNK_NEW_ARRAY(Unk_Pass, field_3f8);
        field_428 = UNK_NEW_ARRAY(Unk_Pass, field_3f8);
        u32 width = field_c0.field_0[1];
        u32 height = field_c0.field_0[2];
        for (s32 i = 0; i < field_3f8; i++) {
            field_430[i] = nullptr;
            field_438[i] = nullptr;
            field_440[i] = nullptr;
            field_448[i] = nullptr;
            field_450[i] = nullptr;
            field_468[i] = nullptr;
            field_470[i] = nullptr;
            if (field_488 != nullptr) {
                field_488[i] = nullptr;
            }
            if (i != 0) {
                width = static_cast<u32>(static_cast<f32>(width) * 0.5f + 0.99f);
                height = static_cast<u32>(static_cast<f32>(height) * 0.5f + 0.99f);
            }
            Unk_Pass* first = &field_420[i];
            Unk_Pass* second = &field_428[i];
            first->field_0 = width;
            first->field_4 = height;
            second->field_0 = width;
            second->field_4 = height;
            if (width == static_cast<u32>(field_228->field_54) && height == static_cast<u32>(field_228->field_58)) {
                field_430[i] = field_228;
                field_430[i]->field_8++;
            } else {
#line 2076
                field_430[i] = UNK_NEW_WITH(
                    CRenderTexture, (field_10 + "::m_apScatterSourceTexture[" + Unk_4525a0(i) + "]").field_8);
                field_430[i]->Unk_Create(flags, width, height, field_c0.field_14);
                if (i == field_3f8 - 1) {
                    u32 nextWidth = static_cast<u32>(static_cast<f32>(width) * 0.5f + 0.99f);
                    u32 nextHeight = static_cast<u32>(static_cast<f32>(height) * 0.5f + 0.99f);
#line 2093
                    field_430[i + 1] = UNK_NEW_WITH(
                        CRenderTexture, (field_10 + "::m_apScatterSourceTexture[" + Unk_4525a0(i + 1) + "]").field_8);
                    field_430[i + 1]->Unk_Create(flags, nextWidth, nextHeight, field_c0.field_14);
                }
            }
#line 2113
            field_438[i] = UNK_NEW_WITH(
                CRenderTexture, (field_10 + "::m_apScatterMultiViewportsTexture[" + Unk_4525a0(i) + "]").field_8);
#line 2116
            field_448[i] = UNK_NEW_WITH(
                CRenderTexture, (field_10 + "::m_apScatterDilationBackTexture[" + Unk_4525a0(i) + "]").field_8);
#line 2118
            field_450[i] = UNK_NEW_WITH(
                CRenderTexture, (field_10 + "::m_apScatterDilationFrontTexture[" + Unk_4525a0(i) + "]").field_8);
#line 2166
            field_488[i] = UNK_NEW_WITH(
                CRenderTexture, (field_10 + "::m_apScatterGradiantMaskTexture[" + Unk_4525a0(i) + "]").field_8);
            field_250 = false;
            f32 outer = radii[0][i + 1] > radii[1][i + 1] ? radii[0][i + 1] : radii[1][i + 1];
            f32 size = outer + 2.0f;
            f32 fwidth = static_cast<f32>(width);
            f32 fheight = static_cast<f32>(height);
            u32 viewportsWidth = static_cast<u32>(fwidth);
            u32 viewportsHeight = static_cast<u32>(size * fheight);
            field_438[i]->Unk_Create(flags, viewportsWidth, viewportsHeight, field_c0.field_14);
            if (field_440[i] != nullptr) {
                field_440[i]->Unk_Create(flags, viewportsWidth * 2, viewportsHeight * 2, field_c0.field_14);
            }
            field_448[i]->Unk_Create(flags, width, height, field_c0.field_14);
            field_450[i]->Unk_Create(flags, width, height, field_c0.field_14);
            if (field_468[i] != nullptr) {
                field_468[i]->Unk_Create(flags, width * 2 < field_158 ? width * 2 : field_158,
                                         height * 2 < field_15c ? height * 2 : field_15c, field_c0.field_14);
            }
            if (field_470[i] != nullptr) {
                field_470[i]->Unk_Create(flags, width * 2 < field_158 ? width * 2 : field_158,
                                         height * 2 < field_15c ? height * 2 : field_15c, field_c0.field_14);
            }
            field_488[i]
                ->Unk_Create(flags, static_cast<u32>(fwidth * 0.5f + 0.99f), static_cast<u32>(fheight * 0.5f + 0.99f),
                             28);
            Unk_Float2 scale(1.0f, 1.0f / size);
            first->field_8 = scale;
            first->field_10 = Unk_Float2(0.0f, 0.0f);
            first->field_18 = scale;
            first->field_20 = Unk_Float2(0.0f, 0.0f);
            Unk_Float2 offset(0.0f, (size - 1.0f) / size);
            second->field_8 = scale;
            second->field_10 = offset;
            second->field_18 = scale;
            second->field_20 = offset;
            f32 fw = static_cast<f32>(viewportsWidth);
            f32 fh = static_cast<f32>(viewportsHeight);
            for (s32 v = 0; v < 2; v++) {
                Unk_Pass* passes[2] = {first, second};
                for (s32 k = 0; k < 2; k++) {
                    Unk_Pass* pass = passes[k];
                    const Unk_Float2& s = v == 0 ? pass->field_8 : pass->field_18;
                    const Unk_Float2& o = v == 0 ? pass->field_10 : pass->field_20;
                    Unk_Pass::Unk_Viewport* viewport = &pass->field_28[v];
                    viewport->field_8 = static_cast<u32>(s.field_0[0].field_0 * fw + 0.999f);
                    viewport->field_c = static_cast<u32>(s.field_0[1].field_0 * fh + 0.999f);
                    viewport->field_10 = Unk_Float2(0.0f, 1.0f);
                    viewport->field_0 = static_cast<u32>(o.field_0[0].field_0 * fw);
                    viewport->field_4 = static_cast<u32>(o.field_0[1].field_0 * fh);
                }
            }
            for (s32 k = 0; k < 2; k++) {
                Unk_Pass* pass = k == 0 ? first : second;
                pass->field_58.field_0[0].field_0 = static_cast<f32>(pass->field_28[0].field_8) / fw;
                pass->field_58.field_0[1].field_0 = static_cast<f32>(pass->field_28[0].field_c) / fh;
                pass->field_68 = pass->field_58;
                pass->field_60.field_0[0].field_0 = static_cast<f32>(pass->field_28[0].field_0) / fw;
                pass->field_60.field_0[1].field_0 = static_cast<f32>(pass->field_28[0].field_4) / fh;
                pass->field_70 = pass->field_60;
            }
            first->field_78 = radii[0][i];
            second->field_78 = -radii[1][i];
            first->field_7c = radii[0][i + 1];
            second->field_7c = -radii[1][i + 1];
        }
    }
    Unk_4a79e0();
    u32 mode = field_c0.field_0[3];
    field_230 = false;
    if (!(mode & 8)) {
        if (CRenderTexturePool::Unk_49f7b0(field_228, field_c0.field_0[1], field_c0.field_0[2], field_c0.field_14,
                                           flags, 0)) {
            field_230 = true;
            field_4a0->Unk_49fdf0(field_228, true);
        }
    }
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    for (u32 i = 0; i < field_c0.field_10; i++) {
        Unk_Level* level = &field_4a8[i];
        u32 width = level->field_0;
        u32 largeWidth = level->field_8;
        level->field_40 = false;
        field_4a0->Unk_49fc10(&level->field_38, width, level->field_4, field_c0.field_14, !(mode & 8), flags, 0);
        if (level->field_60 != 0) {
#line 2531
            level->field_68 = UNK_NEW_ARRAY(CRenderTexture*, level->field_60);
            util->field_29a58->AllocateTextures(level->field_60, level->field_68, level->field_0, level->field_4,
                                                field_c0.field_14, true, flags, 1);
        }
        if (level->field_70 != 0) {
#line 2545
            level->field_78 = UNK_NEW_ARRAY(CRenderTexture*, level->field_70);
            util->field_29a58->AllocateTextures(level->field_70, level->field_78, level->field_8, level->field_c,
                                                field_164, true, flags, 1);
        }
        if (!field_c0.field_64) {
            Unk_TFXString name = field_10 + "::m_pDOFLevelParam[" + Unk_4525a0(i) + "].m_pResult";
#line 2563
            level->field_a0 = UNK_NEW(CRenderTexture)(name.field_8);
            level->field_a0->Unk_Create(flags, level->field_8, level->field_c, field_164);
        } else {
            Unk_TFXString name = field_10 + "::m_pDOFLevelParam[" + Unk_4525a0(i) + "].m_pResultSmall";
#line 2578
            level->field_80 = UNK_NEW(CRenderTexture)(name.field_8);
            level->field_80->Unk_Create(flags, level->field_0, level->field_4, field_164);
            if (width != largeWidth) {
                name = field_10 + "::m_pDOFLevelParam[" + Unk_4525a0(i) + "].m_pResultLarge";
#line 2589
                level->field_88 = UNK_NEW(CRenderTexture)(name.field_8);
                level->field_88->Unk_Create(flags, level->field_8, level->field_c, field_164);
                level->field_a0 = level->field_88;
            } else {
                level->field_a0 = level->field_80;
            }
        }
        if (!(field_c0.field_0[3] & 4)) {
            continue;
        }
        for (u32 j = 0; j < field_180; j++) {
            Unk_TFXString name = field_10 + "::m_pDOFLevelParam[" + Unk_4525a0(i) + "].m_apSourceMaskedBackground[" +
                                 Unk_4525a0(j) + "]";
#line 2614
            level->field_48[j] = UNK_NEW(CRenderTexture)(name.field_8);
            level->field_48[j]->Unk_Create(flags, level->field_0, level->field_4, field_c0.field_14);
        }
        if (field_180 == 2) {
            level->field_48[2] = level->field_48[1];
        }
        bool same = level->field_8 == level->field_0 && level->field_c == level->field_4;
        same &= field_164 == field_c0.field_14;
        if (field_c0.field_6d) {
            same &= field_c0.field_70 < 2;
        }
        if (!field_c0.field_64) {
            if (same) {
                level->field_a8 = level->field_48[0];
                level->field_a8->field_8++;
            } else {
                Unk_TFXString name = field_10 + "::m_pDOFLevelParam[" + Unk_4525a0(i) + "].m_pResultMaskedBackground";
#line 2668
                level->field_a8 = UNK_NEW(CRenderTexture)(name.field_8);
                level->field_a8->Unk_Create(flags, level->field_8, level->field_c, field_164);
            }
        } else if (same) {
            level->field_90 = level->field_48[0];
            level->field_90->field_8++;
            level->field_a8 = level->field_90;
        } else {
            {
                Unk_TFXString name =
                    field_10 + "::m_pDOFLevelParam[" + Unk_4525a0(i) + "].m_pResultMaskedBackgroundSmall";
#line 2698
                level->field_90 = UNK_NEW(CRenderTexture)(name.field_8);
                level->field_90->Unk_Create(flags, level->field_0, level->field_4, field_164);
            }
            if (width != largeWidth) {
                Unk_TFXString name =
                    field_10 + "::m_pDOFLevelParam[" + Unk_4525a0(i) + "].m_pResultMaskedBackgroundLarge";
#line 2711
                level->field_98 = UNK_NEW(CRenderTexture)(name.field_8);
                level->field_98->Unk_Create(flags, level->field_8, level->field_c, field_164);
                level->field_a8 = level->field_98;
            } else {
                level->field_a8 = level->field_90;
            }
        }
        if (field_c0.field_6d) {
            s32 pass;
            switch (i >= 2 ? i : 0) {
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
                Unk_Pass* scatter = &field_420[pass];
                u32 doubleWidth = scatter->field_0 * 2 < field_158 ? scatter->field_0 * 2 : field_158;
                u32 doubleHeight = scatter->field_4 * 2 < field_15c ? scatter->field_4 * 2 : field_15c;
                bool smaller = level->field_8 < scatter->field_0 || level->field_c < scatter->field_4;
                bool grow = scatter->field_0 <= static_cast<u32>(field_c0.field_5c) ||
                            field_c0.field_60 * static_cast<f32>(field_158) >= static_cast<f32>(scatter->field_0);
                if (smaller || grow) {
                    Unk_TFXString name =
                        field_10 + "::m_pDOFLevelParam[" + Unk_4525a0(i) + "].m_pResultMergedScatter";
                    Unk_TFXString background =
                        field_10 + "::m_pDOFLevelParam[" + Unk_4525a0(i) + "].m_pResultMergedScatterBackground";
#line 2777
                    level->field_b0 = UNK_NEW(CRenderTexture)(name.field_8);
                    level->field_b8 = UNK_NEW(CRenderTexture)(background.field_8);
                    u32 mergedWidth = doubleWidth;
                    u32 mergedHeight = doubleHeight;
                    if (!grow && smaller) {
                        mergedWidth = scatter->field_0;
                        mergedHeight = scatter->field_4;
                    }
                    level->field_b0->Unk_Create(flags, mergedWidth, mergedHeight, field_164);
                    level->field_b8->Unk_Create(flags, mergedWidth, mergedHeight, field_164);
                }
            }
        }
    }
    field_174 = false;
    field_248 = nullptr;
    if ((field_c0.field_0[3] & 4) && field_21c != 0) {
#line 2822
        field_248 = UNK_NEW_WITH(CRenderTexture, (field_10 + "::m_pApertureFrameBuffer").field_8);
        field_248->Unk_Create(flags, field_c0.field_0[1], field_c0.field_0[2], field_c0.field_14);
    }
    if (field_248 == nullptr) {
        field_248 = field_228;
        field_248->field_8++;
    }
    field_490 = nullptr;
    if (field_498 != 0) {
        util = Unk_GetTextureUtil();
        Unk_ReleaseTextureUtil();
#line 2846
        field_490 = UNK_NEW_ARRAY(CRenderTexture*, field_498);
        memset(field_490, 0, field_498 * sizeof(CRenderTexture*));
        u32 width = field_228->field_54;
        u32 height = field_228->field_58;
        for (s32 i = 0; i < field_498; i++) {
            f32 scale = static_cast<f32>(static_cast<u32>(field_c0.field_68));
            width = static_cast<u32>(static_cast<f32>(width) / scale + 0.99f);
            height = static_cast<u32>(static_cast<f32>(height) / scale + 0.99f);
            util->field_29a58->Unk_49fc10(&field_490[i], width, height, field_228->field_2c.field_c, false, 0, 0);
        }
    }
    field_1bc = -3.40282347e+38f;
    field_1dc = 1.0f;
    field_154 = field_c0.field_0[3];
    if (field_c0.field_64) {
        for (s32 i = 0; i < field_c0.field_10; i++) {
            Unk_Level* level = &field_4a8[i];
            if (level->field_88 != nullptr) {
                level->field_a0 = level->field_88;
            }
            if (level->field_98 != nullptr) {
                level->field_a8 = level->field_98;
            }
        }
    }
    return 0;
}

// 0x71004aa0d0
// NON_MATCHING: the same instructions; two stores are scheduled the other way
// round (field_3a8's before field_1d0's; the original has field_1d0's first).
// With field_3a8 set first the load of field_c0.field_6d comes after the
// third store, as in the original (set later, it comes first and swaps w8/w9).
// No other order of these stores is closer (every move and swap tried).
s32 CDepthOfField::Initialize(CRenderTexture* source, const Unk_Desc* desc) {
    s32 result = ValidateInitParam(source, desc);
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
    field_3a8 = true;
    field_1c8 = 0;
    field_3b8 = 0.75f;
    field_3bc = 0.0f;
    field_3c0 = 0.7853982f;
    field_3e8 = 0;
    field_3ec = 0.5f;
    field_1cc = 0.0f;
    field_1d0 = 0.0f;
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
    field_3f4 = 1.0f;
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
// The block placement (the clamp of the ratio to 1 after the return) comes
// from Unk_NearPosition testing `field_3e8 == 1 || m <= 0` (in that order);
// the clamp of `next` is a minimum followed by its own zero test (one select
// on each, no sign extension pulled into them).
// NON_MATCHING: one instruction: `count - 1` is scheduled before the scale's
// products here, after `index + 1` in the original (not the IR's order, which
// was tried both ways, nor the minimum's spelling).
f32 CDepthOfField::Unk_4b4ab0(bool near) {
    if (!near) {
        return field_27c;
    }
    f32 t = Unk_NearPosition(near);
    s32 count = field_2f0;
    f32 pos = (1.0f - t) * static_cast<f32>(count) * 0.9999f;
    s32 index = static_cast<s32>(pos);
    s32 next = index + 1 > count - 1 ? count - 1 : index + 1;
    if (index + 1 < 0) {
        next = 0;
    }
    f32 frac = pos - static_cast<f32>(index);
    const f32* table = field_358[field_2a8];
    f32 a = table[index];
    f32 b = table[next];
    return (a + (b - a) * frac) * 0.87890625f;
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
        level->field_c0 = 1.0f / (far1 - near1);
        far2 += first * 0.25f;
        near2 += first * 0.25f;
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
            scale2 = field_1e8.field_0[2].field_0;
            bias = field_1e8.field_0[3].field_0;
        }
        f32 x = level->field_e8.field_0[0].field_0;
        f32 y = level->field_e8.field_0[1].field_0;
        level->field_f0 = x * scale2;
        level->field_f4 = y + x * bias;
    }
    return 0;
}

// 0x71004b48d0
s32 CDepthOfField::Unk_4b48d0(s32 index) {
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    f32 height = static_cast<f32>(static_cast<u32>(field_c0.field_0[2]));
    const Unk_Pass* first = &field_420[index];
    f32 width = static_cast<f32>(static_cast<u32>(field_c0.field_0[1]));
    const Unk_Pass* second = &field_428[index];
    f32 size = first->field_7c.field_0;
    f32 aspect = width / height;
    f32 y = (width < height ? size * aspect : size) * 0.5f;
    f32 x = y / aspect;
    util->Unk_481820(field_438[index], field_448[index], Unk_Float2(x * 0.0f, y * 0.0f),
                     Unk_Float4(first->field_58.field_0[0], first->field_58.field_0[1], first->field_60.field_0[0],
                                first->field_60.field_0[1]));
    return util->Unk_481820(field_438[index], field_450[index], Unk_Float2(x * 0.0f, y * 0.0f),
                            Unk_Float4(second->field_58.field_0[0], second->field_58.field_0[1],
                                       second->field_60.field_0[0], second->field_60.field_0[1]));
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
    return Unk_49ad30(texture, w, h, ix, iy);
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
// The original's loop index is 64-bit (`ldrsw` count, `cmp x, x` exit test)
// and walks the ranges with a pointer; the pass lookup is a `switch` inside
// `if (i >= 2 && field_6d)` (tested in that order); the "same range" test is
// in the `else if` of `i == 0`; the level's sizes are computed into locals and
// stored together at the end; width is halved and clamped before height.
// NON_MATCHING: the presets' stores are scheduled in another order; the
// switch on the index is narrowed to 31 bits in the original (`add w, w13,
// #0x7ffffffe` and a mask) and 64-bit here; the original loads ranges[i * 2]
// again for the "same range" test (here GVN reuses the first load); the
// weight is loaded as a float in each predecessor of the step == 0 test (here
// one integer load at the end, InstCombine's load-to-store retyping); the
// loop exit is `b.lt` on the sign-extended count (here LFTR's `b.ne`).
s32 CDepthOfField::Unk_4a79e0() {
    field_1f8[0] = -1;
    field_1f8[1] = -1;
    field_1f8[2] = -1;
    field_1f8[3] = -1;
    Unk_Level levels[7];
    memset(levels, 0, sizeof(levels));
    u32 height = field_c0.field_0[2];
    u32 width = field_c0.field_0[1];
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
    s32 index = 0;
    s32 step = 0;
    for (s64 i = 0; i < count; i++) {
        bool unused = false;
        if (i < 7) {
            if (ranges[i * 2] < 0) {
                unused = true;
            } else {
                index = ranges[i * 2 + 1];
            }
        }
        if (i == 0) {
            if (!field_c0.field_6d &&
                (width <= static_cast<u32>(field_c0.field_5c) ||
                 static_cast<f32>(width) <= field_c0.field_60 * scale)) {
                step = 1;
            }
        } else if (i >= 7 || unused || ranges[i * 2] != ranges[i * 2 - 2]) {
            width = static_cast<u32>(static_cast<f32>(width) * 0.5f + 0.99f);
            height = static_cast<u32>(static_cast<f32>(height) * 0.5f + 0.99f);
            width = width > 3 ? width : 3;
            height = height > 3 ? height : 3;
            bool grow;
            s32 pass;
            pass = -1;
            if (i >= 2 && field_c0.field_6d) {
                switch (i) {
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
                }
            }
            if (pass >= 0) {
                grow = width < field_420[pass].field_0;
            } else {
                grow = width <= static_cast<u32>(field_c0.field_5c) ||
                       static_cast<f32>(width) <= field_c0.field_60 * scale;
            }
            if (grow) {
                step = step >= 2 ? 3 : step + 1;
            }
        }
        Unk_Level* level = &levels[i];
        level->field_0 = width;
        level->field_4 = height;
        u32 w2 = width;
        u32 h2 = height;
        u32 scaled = 0;
        if (step != 0) {
            w2 = width * 2 < field_158 ? width * 2 : field_158;
            h2 = height * 2 < field_15c ? height * 2 : field_15c;
            scaled = 1;
        }
        f32 weight = weights[step];
        level->field_8 = w2;
        level->field_c = h2;
        level->field_10 = kind;
        level->field_14 = index;
        level->field_28 = scaled;
        level->field_2c = weight;
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
// the level. The fade is read between the two vectors (the original's load
// order), and the release is given the object: with the global read again,
// `this` and the utilities exchange x19/x20.
s32 CDepthOfField::Unk_4b4540(s32 index) {
    // (written as a negated test: the return is laid out last)
    if (!(field_1dc != 0.0f))
        return 1;
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil(util);
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
        f32 alpha = scale * field_1dc;
        Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
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

// the technique of a blur with `count` taps (0: none) (inline; it ignores
// the last two arguments, which 0x71004b0650's callers still pass)
inline s32 Unk_BlurTechnique(CTextureUtil* util, s32 mode, bool flag, bool second, bool far, s32 count, bool arg6,
                             s32 arg7) {
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
                              CRenderTexture* second, const Unk_Float4* color, bool flag, bool arg9, s32 arg10, f32 a,
                              f32 b) {
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
    s32 technique = Unk_BlurTechnique(util, mode, flag, near, far, taps, arg9, arg10);
    if (technique == 0) {
        taps = count - 1;
        technique = Unk_BlurTechnique(util, mode, flag, near, far, taps, arg9, arg10);
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
    effect->vf26(util->field_30.field_10[3], field_2d0[kind]);
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

// the mode 5 strength's ratio (inline: written in the caller, the absolute
// value is multiplied the other way round)
static inline f32 Unk_Ratio(f32 a, f32 b) {
    f32 ratio = 0.0f;
    if (a > 0.0f)
        ratio = a / b;
    if (ratio <= 0.0f)
        ratio = 1.0f;
    return ratio;
}

// 0x71004b0db0
// NON_MATCHING: registers: the near size's last product (the store of
// constants->field_4) lands in s3 in the original, s0 here.
void CDepthOfField::Unk_4b0db0(bool near, bool far) {
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    Unk_463fd0_Effect* effect = util->field_30.field_0;
    Unk_4b0db0_Constants* constants = reinterpret_cast<Unk_4b0db0_Constants*>(const_cast<u8*>(Unk_4738c0_get()));
    const f32* clip = &field_1e8.field_0[0].field_0;
    effect->vf20(util->field_30.field_b0, clip);
    f32 half = field_1e4 * 0.5f;
    constants->field_0 = half;
    f32 blur;
    f32 amount;
    if (near) {
        s32 mode = field_2ac;
        f32 size = field_2e0[mode];
        f32 scale = Unk_4b4ab0(true);
        constants->field_4 = 1.0f / (size * (scale / 0.7853982f) * 0.87890625f) * 0.5f;
        f32 depth = field_2b0;
        f32 a = powf(field_1b4.field_0 * 0.5f, field_2b8);
        f32 b = powf(field_19c * 4.0f, field_2b4);
        f32 focal = field_1b0;
        f32 nearPlane = field_1a8;
        f32 c = powf(nearPlane / (focal - nearPlane) + 1.0f, field_2bc);
        if (field_2ac == 5) {
            f32 ratio = Unk_Ratio(field_3e4, field_1c0);
            f32 strength = field_2b0 > 0.0f ? field_2b0 : -field_2b0;
            strength = strength * ratio;
            blur = 0.0f;
            amount = strength < 0.0f ? 0.0f : (strength > 1.0f ? 1.0f : strength);
        } else {
            blur = 8.0f / depth * a * b / c;
            amount = field_2e8[field_2ac];
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
        f32 radius = field_420[0].field_78.field_0 * 0.5f;
        f32 start = radius * 1.5f;
        f32 scale = 1.0f / (radius - start);
        constants->field_28 = scale;
        constants->field_2c = 0.0f - start * scale;
    }
    effect->vf22(util->field_30.field_d4, reinterpret_cast<const Unk_Float4*>(constants), 4);
}

// 0x71004100f0 (Unk_415f40.cpp): a point through a matrix
void Unk_4100f0(Unk_Float2* out, const Unk_Float2* v, const MATRIXT44* m);

// what 0x7100462090 reads (GPUTextureUtil.cpp): an aperture's blades. The
// tables of field_358[4 + kind] hold them; a copy of one is assigned with a
// test for itself.
struct Unk_462090_Params {
    Unk_462090_Params() : field_0(6), field_4(0.0f), field_8(0.5f), field_c(0.75f), field_10(0.75f) {}
    Unk_462090_Params(const Unk_462090_Params& other) { *this = other; }
    Unk_462090_Params& operator=(const Unk_462090_Params& other) {
        if (this != &other) {
            memcpy(this, &other, sizeof(*this));
        }
        return *this;
    }

    s32 field_0;  // the number of blades
    f32 field_4;  // their rotation
    f32 field_8;
    f32 field_c;
    f32 field_10;
    f32 field_14;  // set: the cosine of half a blade's angle
};
PKMN_SIZE_ASSERT(Unk_462090_Params, 0x18);

// 0x7100462090 (GPUTextureUtil.cpp): a polygonal aperture's falloff
void Unk_462090(Unk_Float4* out, const Unk_Float2* position, const Unk_Float2* size, Unk_462090_Params* params);

// a square root that gives 0 and 1 as they are (inline)
inline f32 Unk_Sqrt(f32 value) {
    if (value == 0.0f || value == 1.0f) {
        return value;
    }
    return sqrtf(value);
}

// a point through a matrix (inline)
static inline Unk_Float2 Unk_Transform(const Unk_Float2& v, const MATRIXT44& m) {
    Unk_Float2 result;
    Unk_4100f0(&result, &v, &m);
    return result;
}

// A rotation about a unit axis (inline; as Unk_415f40.cpp's)
static inline void Unk_RotationAxis(MATRIXT44* out, f32 x, f32 y, f32 z, f32 angle) {
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

// a scale and a translation (inline; as Unk_415f40.cpp's 0x710040f660)
static inline void Unk_ScaleTranslation(MATRIXT44* out, const Unk_Vector3* scale, const Unk_Vector3* translation) {
    out->field_0[0][1] = out->field_0[0][2] = out->field_0[0][3] = out->field_0[1][0] = out->field_0[1][2] =
        out->field_0[1][3] = out->field_0[2][0] = out->field_0[2][1] = out->field_0[2][3] = 0.0f;
    if (scale != nullptr) {
        out->field_0[0][0] = scale->field_0[0];
        out->field_0[1][1] = scale->field_0[1];
        out->field_0[2][2] = scale->field_0[2];
    } else {
        out->field_0[0][0] = out->field_0[1][1] = out->field_0[2][2] = 1.0f;
    }
    out->field_0[3][3] = 1.0f;
    if (translation != nullptr) {
        out->field_0[3][0] = translation->field_0[0];
        out->field_0[3][1] = translation->field_0[1];
        out->field_0[3][2] = translation->field_0[2];
    } else {
        out->field_0[3][0] = out->field_0[3][1] = out->field_0[3][2] = 0.0f;
    }
}

// the identity (inline; as Unk_415f40.cpp's)
static inline void Unk_Identity(MATRIXT44* out) {
    out->field_0[0][1] = out->field_0[0][2] = out->field_0[0][3] = out->field_0[1][0] = out->field_0[1][2] =
        out->field_0[1][3] = out->field_0[2][0] = out->field_0[2][1] = out->field_0[2][3] = out->field_0[3][0] =
            out->field_0[3][1] = out->field_0[3][2] = 0.0f;
    out->field_0[0][0] = out->field_0[1][1] = out->field_0[2][2] = out->field_0[3][3] = 1.0f;
}

// the near blur's position in field_398's table, 0 to 1 (inline; as
// 0x71004b4ab0's search). `frac` and `s` are declared outside the loop: with
// them in the loop's scope, the two returns of the clamp meet in their
// cleanup block and SimplifyCFG folds the clamp into a select (the original
// keeps it a branch to the shared exit). The mode is tested before the
// clamped ratio (`field_3e8 == 1 || m <= 0.0f`; the code tests them the other
// way round): that places the ratio's blocks as the original in all three
// callers.
inline f32 CDepthOfField::Unk_NearPosition(bool far) {
    if (!field_c0.field_6d) {
        return 0.0f;
    }
    f32 size = field_1c0;
    f32 distance = field_3e4;
    f32 bias = field_3ec;
    f32 ratio = distance / size;
    if (!(distance > 0.0f)) {
        ratio = 0.0f;
    }
    if (ratio < 0.0f) {
        return bias;
    }
    f32 m = ratio > 1.0f ? 1.0f : ratio;
    if (field_3e8 == 1 || m <= 0.0f) {
        return bias;
    }
    f32 value = 1.0f / powf(m, powf(10.0f, -(bias * 2.0f - 1.0f)));
    s32 count = field_2f0;
    f32 frac;
    f32 s;
    for (s32 i = 0; i < count; i++) {
        if (value < field_398[i + 1]) {
            frac = (value - field_398[i]) / (field_398[i + 1] - field_398[i]);
            s = 1.0f - (frac + static_cast<f32>(i)) / static_cast<f32>(count);
            if (s < 0.0f) {
                return 0.0f;
            }
            return s > 1.0f ? 1.0f : s;
        }
    }
    return 0.0f;
}

// a scale, without a translation (inline)
static inline void Unk_ScaleOnly(MATRIXT44* out, const Unk_Vector3* scale) {
    out->field_0[0][1] = out->field_0[0][2] = out->field_0[0][3] = out->field_0[1][0] = out->field_0[1][2] =
        out->field_0[1][3] = out->field_0[2][0] = out->field_0[2][1] = out->field_0[2][3] = out->field_0[3][0] =
            out->field_0[3][1] = out->field_0[3][2] = 0.0f;
    out->field_0[0][0] = scale->field_0[0];
    out->field_0[1][1] = scale->field_0[1];
    out->field_0[2][2] = scale->field_0[2];
    out->field_0[3][3] = 1.0f;
}

// 0x71004b1100: the taps' offsets (the points of `count` rings, scaled to the
// aspect ratio and rotated), as the constants of field_c8
// The table position is a named float before its conversion (its DBG_VALUE
// decides how the A57 FP load balancing pass colours the two products), the
// near loop's size is converted where it is read (in the position's
// expression, as in the first near block), and the scale matrices are
// Unk_ScaleOnly's (all twelve zeros in one chain, so MemCpyOpt makes three
// 16-byte memsets and the diagonal's 1.0 is stored on its own). In the near
// loop the parameters are copied before the point is read (the original loads
// x and y after the copy), the length test is `!(length <= 0.0f)` (`b.hi`),
// and the scaled point's elements are named floats.
// NON_MATCHING: registers and the near loop's setup: the original walks the
// points through a pointer to the element (here to its y, `orr x, sp, #4`)
// and keeps the generator's state in another register, and keeps the
// position's `y * -0.5f + 0.5f` (`fmov s1, #-0.5` in the loop) where here
// InstCombine or Reassociate turn the direct form into a subtraction
// (`0.5f - p.x * -0.5f` keeps the -0.5 for x instead, closest overall; every
// combination of the two elements' spellings was tried).
s32 CDepthOfField::Unk_4b1100(bool near, bool far, s32 count, f32 angle) {
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    Unk_463fd0_Effect* effect = util->field_30.field_0;
    s32 taps = Unk_415370(count, nullptr, 1.0f);
    Unk_Float4* constants = reinterpret_cast<Unk_Float4*>(const_cast<u8*>(Unk_4738c0_get()));
    Unk_Float2 points[96];
    f32 rings = static_cast<f32>(count);
    Unk_415370(count, points, rings / (rings + 1.0f));
    f32 aspect = field_c0.field_74;
    if (!field_c0.field_84 && field_c0.field_78 != 1.0f) {
        aspect = static_cast<f32>(static_cast<u32>(field_c0.field_0[1])) /
                 static_cast<f32>(static_cast<u32>(field_c0.field_0[2]));
    }
    if (angle > 0.0f && aspect != angle) {
        aspect = aspect * (aspect / angle);
    }
    Unk_Vector3 scale = {{1.0f / aspect, 1.0f, 1.0f}};
    if (near) {
        f32 position = (1.0f - Unk_NearPosition(far)) * static_cast<f32>(field_2f0) * 0.9999f;
        s32 index = static_cast<s32>(position);
        f32 value = field_338[field_2a8][index];
        scale.field_0[0] = scale.field_0[0] * value;
        scale.field_0[1] = value;
    }
    MATRIXT44 matrix;
    Unk_Identity(&matrix);
    MATRIXT44 rotation;
    Unk_RotationAxis(&rotation, 0.0f, 0.0f, 1.0f, field_1bc);
    MATRIXT44_MatrixMultiply(&matrix, &matrix, &rotation);
    MATRIXT44 scaling;
    Unk_ScaleOnly(&scaling, &scale);
    MATRIXT44_MatrixMultiply(&matrix, &matrix, &scaling);
    if (near) {
        f32 t = Unk_NearPosition(far);
        static Unk_Random random(1);
        f32 jitter = 0.0f / rings;
        f32 position = (1.0f - t) * static_cast<f32>(field_2f0) * 0.9999f;
        s32 index = static_cast<s32>(position);
        for (s32 i = 0; i < taps; i++) {
            Unk_462090_Params params = field_378[field_2a8][index];
            f32 x = points[i].field_0[0].field_0;
            f32 y = points[i].field_0[1].field_0;
            Unk_Float2 p(-x, -y);
            Unk_Float2 position(0.5f - p.field_0[0].field_0 * -0.5f, 0.5f - y * 0.5f);
            Unk_Float2 area(0.0078125f, 0.0078125f);
            Unk_Float4 falloff;
            Unk_462090(&falloff, &position, &area, &params);
            falloff.field_0[0].field_0 =
                Unk_Saturate(falloff.field_0[0].field_0 + jitter * (random.Unk_Get() * 2.0f - 1.0f));
            falloff.field_0[3].field_0 = falloff.field_0[0].field_0 > 0.0f ? 1.0f : 0.0f;
            f32 length = Unk_Sqrt(x * x + y * y);
            f32 factor = 1.0f;
            if (!(length <= 0.0f)) {
                factor = length / (1.0f - falloff.field_0[0].field_0) / params.field_14;
            }
            f32 px = factor * points[i].field_0[0].field_0;
            f32 py = factor * points[i].field_0[1].field_0;
            p = Unk_Float2(px, py);
            p = Unk_Transform(p, matrix);
            constants[i].field_0[0] = p.field_0[0];
            constants[i].field_0[1] = p.field_0[1];
            f32 distance = Unk_Sqrt(points[i].field_0[0].field_0 * points[i].field_0[0].field_0 +
                                    points[i].field_0[1].field_0 * points[i].field_0[1].field_0);
            constants[i].field_0[2].field_0 = distance;
            constants[i].field_0[3].field_0 = 1.0f - distance;
        }
    } else {
        MATRIXT44 coords;
        Unk_Identity(&coords);
        Unk_Vector3 flip = {{-0.5f, -0.5f, 1.0f}};
        Unk_ScaleOnly(&scaling, &flip);
        MATRIXT44_MatrixMultiply(&coords, &coords, &scaling);
        MATRIXT44 offset;
        Unk_Vector3 centre = {{0.5f, 0.5f, 0.0f}};
        Unk_ScaleTranslation(&offset, nullptr, &centre);
        MATRIXT44_MatrixMultiply(&coords, &coords, &offset);
        for (s32 i = 0; i < taps; i++) {
            Unk_Float2 p = points[i];
            p = Unk_Transform(p, matrix);
            constants[i].field_0[0] = p.field_0[0];
            constants[i].field_0[1] = p.field_0[1];
            Unk_Float2 q = Unk_Transform(points[i], coords);
            constants[i].field_0[2] = q.field_0[0];
            constants[i].field_0[3] = q.field_0[1];
        }
    }
    effect->vf22(util->field_30.field_c8, constants, taps);
    return 0;
}

// 0x71004b35f0: a pass of the second kind: the blur of `source` (and
// `target`, through the mask `arg3`) into `arg4`, drawn with the vertices
// `arg7` and indices `arg8` (placeholder parameter names)
// NON_MATCHING: 3912 vs 3920 bytes, same calls, constants and stack layout up
// to registers: the original spills `scale` and `last` at entry, keeps 0.5f
// in a callee-saved register from the near test on and lays the near
// position's ratio test and the technique selection's two near branches out
// differently (the blades' table position is a named float, as in
// 0x71004b1100; so are the rectangles' scaled w and the far offset's
// diameter, for the FP load balancing). `first` is
// handed to Unk_NearPosition, which ignores it: an argument used only there
// survives DeadArgElim, so 0x71004b4c40 passes `i == 0` as the original does.
s32 CDepthOfField::Unk_4b35f0(f32 scale, CRenderTexture* source, CRenderTexture* target, void* arg3, void* arg4,
                              s32 arg5, s32 arg6, void* arg7, void* arg8, Unk_Pass* arg9, Unk_Pass* arg10, bool first,
                              bool last) {
    CRenderTexture* mask = static_cast<CRenderTexture*>(arg3);
    CRenderTexture* output = static_cast<CRenderTexture*>(arg4);
    Unk_GetTexture(source)->vf18(1);
    Unk_GetTexture(source)->vf17(1);
    Unk_GetTexture(target)->vf18(1);
    Unk_GetTexture(target)->vf17(1);
    Unk_GetTexture(output)->vf18(1);
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    f32 depthScale = field_1e4;
    f32 aspect = field_c0.field_74;
    if (!field_c0.field_84 && field_c0.field_78 != 1.0f) {
        aspect = static_cast<f32>(static_cast<u32>(field_c0.field_0[1])) /
                 static_cast<f32>(static_cast<u32>(field_c0.field_0[2]));
    }
    f32 width = static_cast<f32>(static_cast<u32>(field_c0.field_0[1]));
    f32 height = static_cast<f32>(static_cast<u32>(field_c0.field_0[2]));
    f32 radiusY = arg9->field_7c.field_0;
    f32 radiusX;
    if (width < height) {
        f32 ratio = width / height;
        radiusY = radiusY * ratio;
        radiusX = ratio * arg9->field_78.field_0;
    } else {
        radiusX = arg9->field_78.field_0;
    }
    bool near = field_251;
    bool far = Unk_1b35154 && field_3f0 && field_3f4 * 2.0f != 0.0f;
    f32 blur;
    f32 amount;
    if (near) {
        f32 depth = field_2b0;
        f32 a = powf(field_1b4.field_0 * 0.5f, field_2b8);
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
            amount = field_2e8[field_2ac];
        }
    } else {
        blur = 0.0f;
        amount = 0.5f;
    }
    Unk_Float offsetY(0.0f);
    Unk_Float offsetX(0.0f);
    if (far) {
        offsetX = Unk_Float(Unk_4b0db0_Distance(this) * -0.002f);
        offsetY = Unk_Float(Unk_4b0db0_Distance(this) * 0.002f);
    }
    const f32* clip = &field_1e8.field_0[0].field_0;
    f32 size;
    if (near) {
        size = field_2e0[field_2ac];
        size = size * (Unk_4b4ab0(true) / 0.7853982f) * 0.87890625f;
    } else {
        size = field_278;
    }
    f32 half = depthScale * 0.5f;
    radiusY = radiusY * 0.5f;
    radiusX = radiusX * 0.5f;
    f32 blurScale = Unk_4b4ab0(near);
    MATRIXT44 matrices[2];
    Unk_Identity(&matrices[0]);
    Unk_Identity(&matrices[1]);
    f32 inverseSize = 1.0f / size;
    f32 inverseScale = 1.0f / blurScale;
    {
        MATRIXT44 rotation;
        Unk_RotationAxis(&rotation, 0.0f, 0.0f, 1.0f, field_1bc);
        MATRIXT44_MatrixMultiply(&matrices[0], &matrices[0], &rotation);
        MATRIXT44 inverse;
        Unk_4155f0(&inverse, &matrices[0]);
        matrices[1] = inverse;
    }
    output->Unk_49d250(0, 0, 1, 0, 0);
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    {
        Unk_Float4 clear(0.0f, 0.0f, 0.0f, 0.0f);
        field_20->vf51(0xff0, &clear.field_0[0].field_0, 1.0f, 0);
    }
    field_20->vf44(2);
    const s32* techniques;
    if (near)
        techniques = last ? &util->field_30.field_1af6c.field_0[28] : &util->field_30.field_1af6c.field_0[24];
    else
        techniques = last ? &util->field_30.field_1af6c.field_0[16] : &util->field_30.field_1af6c.field_0[8];
    Unk_463fd0_Effect* effect = util->field_30.field_0;
    effect->vf29(techniques[far]);
    Unk_Float4* constants = reinterpret_cast<Unk_Float4*>(const_cast<u8*>(Unk_4738c0_get()));
    Unk_Float4* sizes = reinterpret_cast<Unk_Float4*>(const_cast<u8*>(Unk_4738d0_get()));
    effect->vf20(util->field_30.field_b0, clip);
    constants[5] = Unk_Float4(half, 0.0f, blur, amount);
    constants[6] = Unk_Float4(half, half, offsetX, offsetY);
    constants[7] = Unk_Float4(inverseSize, inverseScale, 0.0f, 0.0f);
    constants[8] = Unk_Float4(aspect, 1.0f, 1.0f / aspect, 1.0f);
    constants[12].field_0[0].field_0 = 0.5f / static_cast<f32>(output->field_80->field_8);
    constants[12].field_0[1].field_0 = 0.5f / static_cast<f32>(output->field_80->field_c);
    constants[13] = Unk_Float4(radiusY, radiusY * 0.5f, radiusX * scale, radiusX * 0.5f);
    f32 texelX = 1.0f / static_cast<f32>(arg9->field_0);
    f32 texelY = 1.0f / static_cast<f32>(arg9->field_4);
    constants[14] = Unk_Float4(texelX, texelY, 0.0f - texelX * 0.5f, 0.0f - texelY * 0.5f);
    // the two passes' rectangles, in clip space
    for (s32 n = 0; n < 2; n++) {
        Unk_Pass* pass = n == 0 ? arg9 : arg10;
        Unk_Float4* size = &sizes[n * 2];
        Unk_Float4* rects = &constants[n * 2];
        size->field_0[0].field_0 = static_cast<f32>(pass->field_0) * 2.0f;
        size->field_0[1].field_0 = static_cast<f32>(pass->field_4) * 2.0f;
        f32 radius = pass->field_78.field_0 * 0.5f;
        f32 w = static_cast<f32>(static_cast<u32>(field_c0.field_0[1]));
        f32 h = static_cast<f32>(static_cast<u32>(field_c0.field_0[2]));
        if (w < h) {
            radius = radius * (w / h);
        }
        size->field_0[2].field_0 = radius;
        size->field_0[3].field_0 = 0.0f;
        rects[0].field_0[0] = pass->field_58.field_0[0];
        rects[0].field_0[1] = pass->field_58.field_0[1];
        rects[0].field_0[2] = pass->field_60.field_0[0];
        rects[0].field_0[3] = pass->field_60.field_0[1];
        rects[1].field_0[0] = pass->field_68.field_0[0];
        rects[1].field_0[1] = pass->field_68.field_0[1];
        rects[1].field_0[2] = pass->field_70.field_0[0];
        rects[1].field_0[3] = pass->field_70.field_0[1];
        rects[0].field_0[2].field_0 = 0.0f / static_cast<f32>(output->field_80->field_8) + rects[0].field_0[2].field_0;
        rects[0].field_0[3].field_0 = 0.0f / static_cast<f32>(output->field_80->field_c) + rects[0].field_0[3].field_0;
        rects[1].field_0[2].field_0 = 0.0f / static_cast<f32>(output->field_80->field_8) + rects[1].field_0[2].field_0;
        rects[1].field_0[3].field_0 = 0.0f / static_cast<f32>(output->field_80->field_c) + rects[1].field_0[3].field_0;
        bool flip = field_20->field_58;
        f32 sign = flip ? 2.0f : -2.0f;
        f32 bias = flip ? -1.0f : 1.0f;
        for (s32 i = 0; i < 2; i++) {
            rects[i].field_0[0].field_0 = rects[i].field_0[0].field_0 * 2.0f;
            rects[i].field_0[1].field_0 = sign * rects[i].field_0[1].field_0;
            rects[i].field_0[2].field_0 = rects[i].field_0[2].field_0 * 2.0f - 1.0f;
            f32 scaled = rects[i].field_0[3].field_0 * sign;
            rects[i].field_0[3].field_0 = bias + scaled;
        }
    }
    constants[12].field_0[2].field_0 = 0.0f;
    if (far) {
        f32 sizeX = sizes[0].field_0[0].field_0;
        f32 sizeY = sizes[0].field_0[1].field_0;
        f32 x = Unk_4b0db0_Distance(this) * -0.002f;
        f32 ax = Unk_Abs(x);
        f32 y = Unk_4b0db0_Distance(this) * 0.002f;
        f32 offset = Unk_MaxF(ax, Unk_Abs(y));
        f32 diameter = offset * 2.0f;
        constants[12].field_0[2].field_0 = Unk_MaxF(sizeX, sizeY) * diameter;
    }
    effect->vf22(util->field_30.field_c4, constants, 15);
    effect->vf22(util->field_30.field_cc, sizes, 5);
    effect->vf25(util->field_30.field_114, matrices, 2);
    effect->vf26(util->field_30.field_90[0], Unk_GetTexture(source));
    effect->vf26(util->field_30.field_90[1], Unk_GetTexture(target));
    effect->vf26(util->field_30.field_90[2], Unk_GetTexture(mask));
    Unk_GPUTexture* noise;
    Unk_GPUTexture* blades;
    if (near) {
        f32 position = (1.0f - Unk_NearPosition(first)) * static_cast<f32>(field_2f0) * 0.9999f;
        s32 index = static_cast<s32>(position);
        blades = reinterpret_cast<Unk_GPUTexture*>(field_2f8[field_2a8][index]);
        noise = reinterpret_cast<Unk_GPUTexture*>(field_2c8[field_2ac]);
    } else {
        blades = nullptr;
        noise = reinterpret_cast<Unk_GPUTexture*>(field_258);
    }
    effect->vf26(util->field_30.field_10[0], noise);
    if (noise != nullptr) {
        if (near)
            noise->vf15(7);
        else
            noise->vf15(3);
    }
    effect->vf26(util->field_30.field_10[1], blades);
    if (blades != nullptr)
        blades->vf15(7);
    if (near) {
        f32 position = (1.0f - Unk_NearPosition(first)) * static_cast<f32>(field_2f0) * 0.9999f;
        if (position > 1.0f) {
            position = position - static_cast<f32>(static_cast<s32>(position));
        } else if (position < 0.0f) {
            position = position + 1.0f - static_cast<f32>(static_cast<s32>(position));
        }
        constants[0] = Unk_Float4(position, 0.0f, 0.0f, 0.0f);
        effect->vf22(util->field_30.field_d0, constants, 1);
    }
    field_20->vf41(-1, true);
    {
        u8 passes[0x20];
        effect->vf33(passes, 0);
        effect->vf35(0);
    }
    util->field_30.Unk_46cfe0();
    effect->vf42(util->field_30.field_299b8[1], static_cast<IGPUBuffer*>(arg7), 0, 0, 0, 1);
    field_20->vf9(arg8, 0);
    effect->SetupGraphicsPipelineState();
    field_20->vf58(4, arg6, 0, 0, arg5 - 1);
    effect->vf36();
    s32 result = effect->vf34();
    field_20->vf44(0);
    return result;
}

// 0x71004b19a0: a level's blur by its kind (0 to 5) and the visualisation of
// the aperture filter's level
// NON_MATCHING: the same calls with the same arguments, but the blocks and
// registers differ throughout (the original keeps the target and the list in
// stack slots, shares the texture filter calls' tails and lays the kinds out
// in another order). Kind 0's plain blur is the `if (field_18 <= 9)` branch
// (laid out first, as in the original: written as the early `if (> 9)`,
// the whole function's layout differs). Still different: the original keeps
// `!visualize` as a bool (cset ne) for kind 0 and places the visualisation
// right after it; here kind 0's test is threaded into the tail and the tail
// follows kind 5's. Case order and the `!` forms of the flag change nothing.
s32 CDepthOfField::Unk_4b19a0(s32 level, bool first, CRenderTexture* source, CRenderTexture* target,
                              CRenderTexture** list, CRenderTexture* extra, s32 mode) {
    bool flag = first ? (field_154 & 4) != 0 : (field_154 & 8) != 0;
    Unk_Level* levels = field_4a8;
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    Unk_Float4 colour = field_174 ? Unk_LevelColours[level] : Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
    Unk_Float4 range(1.0f, 0.0f, -3.40282347e+38f, 3.40282347e+38f);
    range.field_0[0].field_0 = levels[level].field_f0;
    range.field_0[1].field_0 = levels[level].field_f4;
    range.field_0[2].field_0 = 0.0f;
    range.field_0[3].field_0 = 2.0f;
    if (!first) {
        range.field_0[2].field_0 = -range.field_0[2].field_0;
        range.field_0[3].field_0 = -range.field_0[3].field_0;
    }
    s32 kind = levels[level].field_10;
    CRenderTexture* second = kind == 5 ? extra : nullptr;
    s32 result = -1;
    bool visualize = false;
    switch (kind) {
    case 0: {
        Unk_Level* item = &levels[level];
        if (item->field_18 <= 9) {
            Unk_GetTexture(source)->vf18(2);
            Unk_GetTexture(target)->vf18(2);
            result = util->Unk_493e20(1.0f, source, target, item->field_18, mode, &colour, false, false, 0, 0);
            visualize = item->field_18 == 9;
        } else {
            CRenderTexture* other = list[0];
            if (!field_c0.field_6c) {
                other = list[1];
                if (other == target)
                    other = list[2] == target ? list[0] : list[2];
            }
            if (source != nullptr)
                Unk_GetTexture(source)->vf18(2);
            if (target != nullptr)
                Unk_GetTexture(target)->vf18(2);
            if (other != nullptr)
                Unk_GetTexture(other)->vf18(2);
            if (list[0] != nullptr)
                Unk_GetTexture(list[0])->vf18(2);
            Unk_Float4 white(1.0f, 1.0f, 1.0f, 1.0f);
            util->Unk_493be0(source, other, target, list[0], 1.0f, true, 0, &white, false, false, 0, 0);
            result = util->Unk_493f30(1.0f, Unk_Float(0.75f), list[0], target, mode, &colour, false, false, 0, 0);
        }
        break;
    }
    case 1:
        if (!flag && levels[level].field_1c == 3) {
            Unk_GetTexture(source)->vf18(2);
            Unk_GetTexture(target)->vf18(2);
            result = util->Unk_493f30(1.0f, Unk_Float(1.0f), source, target, mode, &colour, false, false, 0, 0);
        } else {
            Unk_GetTexture(source)->vf18(2);
            Unk_GetTexture(target)->vf18(2);
            if (list[0] != nullptr)
                Unk_GetTexture(list[0])->vf18(2);
            f32 r = static_cast<f32>(levels[level].field_1c) * 0.5f * 0.4f;
            Unk_Float4 radius(r, r, r, r);
            result = util->Unk_496b40(1.0f, -static_cast<f32>(levels[level].field_18), source, list[0], target,
                                      &radius, mode, &colour, 0, false, false, 0, 0);
        }
        break;
    case 2: {
        f32 angle = field_1bc == -3.40282347e+38f ? 0.39269909f : field_1bc;
        angle = field_20->field_58 ? -angle : angle;
        Unk_GetTexture(source)->vf18(2);
        Unk_GetTexture(target)->vf18(2);
        if (list[0] != nullptr)
            Unk_GetTexture(list[0])->vf18(2);
        s32 size = levels[level].field_18;
        if (size == 15 || size == 5) {
            result = util->Unk_4915e0(angle, 0.0f, 1.0f, source, list[0], target, size, mode, &colour, second, &range,
                                      false, 0, 0);
        } else {
            result = util->Unk_491640(angle, 1.0f, source, list[0], target,
                                      static_cast<s32>(logf(static_cast<f32>(size)) / 1.0986123f), mode, &colour,
                                      second, &range, false, 0, 0);
        }
        break;
    }
    case 3: {
        Unk_GetTexture(source)->vf18(2);
        Unk_GetTexture(target)->vf18(2);
        if (list[0] != nullptr)
            Unk_GetTexture(list[0])->vf18(2);
        if (list[1] != nullptr)
            Unk_GetTexture(list[1])->vf18(2);
        f32 angle = field_1bc == -3.40282347e+38f ? 0.2617994f : field_1bc + 0.5235988f;
        angle = field_20->field_58 ? -angle : angle;
        result = util->Unk_4920b0(angle, 1.0f, 1.0f, 0.666667f, source, target, list[0], list[1],
                                  levels[level].field_18, mode, &colour, second, &range, false, 0, 0);
        break;
    }
    case 4: {
        f32 angle = field_1bc == -3.40282347e+38f ? 0.2617994f : field_1bc + 0.5235988f;
        Unk_GetTexture(source)->vf18(2);
        Unk_GetTexture(target)->vf18(2);
        if (list[0] != nullptr)
            Unk_GetTexture(list[0])->vf18(2);
        if (list[1] != nullptr)
            Unk_GetTexture(list[1])->vf18(2);
        angle = field_20->field_58 ? -angle : angle;
        result = util->Unk_4922a0(angle, 1.0f, 1.0f, source, target, list, levels[level].field_18, mode, &colour,
                                  second, &range, false, 0, 0);
        break;
    }
    case 5: {
        bool single = level == 1 && first;
        if (field_c0.field_70 > 1 || (single && field_c0.field_70 == 1)) {
            static const s32 taps[4] = {2, 3, 4, 5};
            s32 index = levels[level].field_18;
            s32 count = index < 0 ? 0 : taps[index];
            f32 half = levels[level].field_30 * 0.5f;
            f32 limit = level < 6 ? half * 2.0f : 3.40282347e+38f;
            f32 a = half * 0.5f;
            if (level >= 2 && !first && !(Unk_1b35154 && field_3f0 && field_3f4 * 2.0f != 0.0f))
                a = a * 2.0f;
            f32 aspect = 0.5f;
            f32 width = static_cast<f32>(static_cast<u32>(field_c0.field_0[1]));
            f32 height = static_cast<f32>(static_cast<u32>(field_c0.field_0[2]));
            if (width < height)
                aspect = width / height * 0.5f;
            f32 b = limit < aspect ? limit : aspect;
            CRenderTexture* temp = list[0];
            CRenderTexture* blurred = level == 1 ? temp : target;
            result = Unk_4b0650(count, !first, source, blurred, extra, &colour, first, field_c0.field_70 < 2, mode, a,
                                b);
            if (field_c0.field_10 - 2 <= level) {
                f32 r = static_cast<f32>(static_cast<u32>(blurred->field_58)) / 9.0f * 0.3f;
                if (field_c0.field_10 - 1 > level)
                    r = r * 0.25f;
                Unk_Float4 white(1.0f, 1.0f, 1.0f, 1.0f);
                Unk_Float4 radius(r, r, r, r);
                result = util->Unk_496b40(1.0f, 0.002f, blurred, level == 1 ? target : temp, blurred, &radius, 0,
                                          &white, 0, false, false, 0, 0);
            }
            if (level == 1)
                result = util->Unk_475150(blurred, target, false);
            if (!first) {
                CRenderTexture* other = list[0];
                field_20->vf45(2);
                Unk_GetTexture(source)->vf18(2);
                Unk_GetTexture(other)->vf18(2);
                f32 r = levels[level].field_30 * static_cast<f32>(levels[level].field_4) * 0.5f * 0.25f;
                Unk_Float4 white(1.0f, 1.0f, 1.0f, 1.0f);
                Unk_Float4 radius(r, r, r, r);
                util->Unk_496b40(1.0f, 0.002f, target, other, target, &radius, 0, &white, 0, false, false, 0, 0);
                field_20->vf45(0);
            }
            return result;
        }
        CRenderTexture* temp = list[0];
        s32 filter = Unk_GetTexture(source)->vf16();
        s32 tempFilter = Unk_GetTexture(temp)->vf16();
        Unk_GetTexture(source)->vf15(8);
        Unk_GetTexture(temp)->vf15(8);
        if (levels[level].field_18 > 2) {
            static const f32 radii[4] = {3.15f, 6.3f, 12.6f, 25.2f};
            f32 r = radii[levels[level].field_18] / 0.95f * 0.5f * 0.4f;
            const Unk_Float& m = r < 6.0f ? Unk_Float(r) : Unk_Float(6.0f);
            Unk_Float4 radius(m, m, m, m);
            result = util->Unk_496b40(1.0f, 0.0001f, source, temp, target, &radius, 0, &colour, 0, false, false, 0, 0);
        } else {
            Unk_GetTexture(source)->vf18(2);
            Unk_GetTexture(target)->vf18(2);
            s32 size = field_4a8[level].field_1c;
            if (field_c0.field_6d && !(field_c0.field_70 > 1 || (single && field_c0.field_70 == 1))) {
                switch (field_4a8[level].field_18) {
                case 0:
                    size = 3;
                    break;
                case 1:
                    size = 5;
                    break;
                case 2:
                    size = 9;
                    break;
                case 3:
                    size = 17;
                    break;
                }
            }
            result = util->Unk_493e20(1.0f, source, target, size, mode, &colour, false, false, 0, 0);
            visualize = size == 9;
        }
        Unk_GetTexture(source)->vf15(filter);
        Unk_GetTexture(temp)->vf15(tempFilter);
        break;
    }
    }
    if (visualize && field_174 && !Unk_442c50_get(reinterpret_cast<u64>(field_20))) {
        if (field_20->field_14ef0) {
            Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
            result = util->Unk_47dfa0(0.0f, 0.0f, 0.0f, 1.0f, target, target, 0, &colour, 0, false, false, 1, &zero,
                                      nullptr, -1);
        } else {
            static s32 count = 0;
            if (++count == 0 || count % 200 == 100) {
#line 9173
                PPFX_WARNING("SetApertureFilterLevelVisualize() does not work properly.\n");
            }
        }
    }
    return result;
}

// 0x71004b5b40: the levels of the second kind: each one's near and far blur
// brought back to its level's size and faded into its texture
// The test of the kind is `(i < 2) | !field_c0.field_6d`.
// NON_MATCHING: registers (the original keeps the levels and the far target
// in stack slots and the constant 0x108 in a register across the calls) and
// 24 bytes more in the original; the blocks are the same.
s32 CDepthOfField::Unk_4b5b40() {
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    for (s32 i = 0; i < field_208; i++) {
        if ((i < 2) | !field_c0.field_6d)
            continue;
        s32 index;
        switch (i) {
        case 2:
        case 3:
            index = 0;
            break;
        case 4:
        case 5:
            index = 1;
            break;
        case 6:
            index = 2;
            break;
        default:
            continue;
        }
        CRenderTexture* nearSource;
        CRenderTexture* farSource;
        Unk_Level* levels = field_4a8;
        if (field_1dc != 0.0f) {
            nearSource = field_470[index] != nullptr ? field_470[index] : field_450[index];
            farSource = field_468[index] != nullptr ? field_468[index] : field_448[index];
        } else {
            nearSource = field_450[index];
            farSource = field_448[index];
        }
        f32 scale = field_168 - 1.0f;
        scale = scale < 1.0f ? 1.0f : std::min(scale, 2.0f);
        CRenderTexture* farTarget = levels[i].field_a8;
        // the near blur, then the far one: halved through the lower levels'
        // first textures (or the level's own) until it is about the source's
        // size, the source drawn into what that gave, and the result faded
        // into the level's texture (or copied back)
        if (i < field_20c) {
            CRenderTexture* nearTarget = levels[i].field_a0;
            nearTarget->Unk_49d250(0, 0, 1, 0, 0);
            CRenderTexture* current = nearTarget;
            s32 lower = i;
            while (true) {
                u32 width = static_cast<u32>(current->field_54);
                if (width >= static_cast<u32>(nearSource->field_54) &&
                    static_cast<u32>(current->field_58) >= static_cast<u32>(nearSource->field_58))
                    break;
                f32 difference = static_cast<f32>(width) - static_cast<f32>(static_cast<u32>(nearSource->field_54));
                difference = difference > 0.0f ? difference : -difference;
                if (difference <= 2.0f)
                    break;
                u32 least = width * 2 - 2;
                u32 most = width * 2 + 2;
                CRenderTexture* next = field_4a8[lower - 1].field_68[0];
                lower--;
                CRenderTexture* other = levels[i].field_b0;
                if (other != nullptr && static_cast<u32>(other->field_54) >= least &&
                    static_cast<u32>(other->field_54) <= most)
                    next = other;
                if (static_cast<u32>(next->field_54) < least)
                    continue;
                s32 filter = Unk_GetTexture(current)->vf16();
                Unk_GetTexture(current)->vf15(8);
                Unk_Float4 white(1.0f, 1.0f, 1.0f, 1.0f);
                Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
                util->Unk_47dfa0(0.0f, 0.0f, 1.0f, 1.0f, current, next, 0, &white, 0, false, false, 1, &zero, nullptr, -1);
                Unk_GetTexture(current)->vf15(filter);
                current = next;
            }
            field_20->vf44(2);
            field_20->vf45(1);
            f32 u1;
            f32 v1;
            Unk_GetCoords(nearSource, &u1, &v1);
            f32 width = static_cast<f32>(static_cast<u32>(current->field_54));
            f32 height = static_cast<f32>(static_cast<u32>(current->field_58));
            Unk_Float4 colour = field_174 ? Unk_LevelColours[i] : Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
            util->DrawRectGPU_MadT1_Sn(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, 1, nullptr, &colour,
                                       Unk_GetTexture(nearSource), 0, 0);
            field_20->vf44(0);
            field_20->vf45(0);
            CRenderTexture* other = levels[i].field_b0;
            if (other != nullptr) {
                if (current != other) {
                    s32 filter = Unk_GetTexture(current)->vf16();
                    Unk_GetTexture(current)->vf15(8);
                    f32 amount = scale * (field_4a8[i].field_2c * 0.25f + 0.25f);
                    amount = amount < 0.0f ? 0.0f : std::min(amount, 1.0f);
                    Unk_Float4 white(1.0f, 1.0f, 1.0f, 1.0f);
                    Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
                    util->Unk_47dfa0(0.0f, 0.0f, amount, 1.0f, current, other, 0, &white, 0, false, false, 1, &zero, nullptr,
                                     -1);
                    Unk_GetTexture(current)->vf15(filter);
                }
            } else if (current != nearTarget) {
                Unk_Float4 white(1.0f, 1.0f, 1.0f, 1.0f);
                Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
                util->Unk_47dfa0(0.0f, 0.0f, 0.0f, 1.0f, current, nearTarget, 0, &white, 0, false, false, 1, &zero, nullptr, -1);
            }
        }
        if (i < field_210) {
            farTarget->Unk_49d250(0, 0, 1, 0, 0);
            CRenderTexture* current = farTarget;
            s32 lower = i;
            while (true) {
                u32 width = static_cast<u32>(current->field_54);
                if (width >= static_cast<u32>(farSource->field_54) &&
                    static_cast<u32>(current->field_58) >= static_cast<u32>(farSource->field_58))
                    break;
                f32 difference = static_cast<f32>(width) - static_cast<f32>(static_cast<u32>(farSource->field_54));
                difference = difference > 0.0f ? difference : -difference;
                if (difference <= 2.0f)
                    break;
                u32 least = width * 2 - 2;
                u32 most = width * 2 + 2;
                CRenderTexture* next = field_4a8[lower - 1].field_68[0];
                lower--;
                CRenderTexture* other = levels[i].field_b8;
                if (other != nullptr && static_cast<u32>(other->field_54) >= least &&
                    static_cast<u32>(other->field_54) <= most)
                    next = other;
                if (static_cast<u32>(next->field_54) < least)
                    continue;
                s32 filter = Unk_GetTexture(current)->vf16();
                Unk_GetTexture(current)->vf15(8);
                Unk_Float4 white(1.0f, 1.0f, 1.0f, 1.0f);
                Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
                util->Unk_47dfa0(0.0f, 0.0f, 1.0f, 1.0f, current, next, 0, &white, 0, false, false, 1, &zero, nullptr, -1);
                Unk_GetTexture(current)->vf15(filter);
                current = next;
            }
            field_20->vf44(2);
            field_20->vf45(1);
            f32 u1;
            f32 v1;
            Unk_GetCoords(farSource, &u1, &v1);
            f32 width = static_cast<f32>(static_cast<u32>(current->field_54));
            f32 height = static_cast<f32>(static_cast<u32>(current->field_58));
            Unk_Float4 colour = field_174 ? Unk_LevelColours[i] : Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
            util->DrawRectGPU_MadT1_Sn(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, 1, nullptr, &colour,
                                       Unk_GetTexture(farSource), 0, 0);
            field_20->vf44(0);
            field_20->vf45(0);
            CRenderTexture* other = levels[i].field_b8;
            if (other != nullptr) {
                if (current != other) {
                    s32 filter = Unk_GetTexture(current)->vf16();
                    Unk_GetTexture(current)->vf15(8);
                    f32 amount = scale * (field_4a8[i].field_2c * 0.25f + 0.25f);
                    amount = amount < 0.0f ? 0.0f : std::min(amount, 1.0f);
                    Unk_Float4 white(1.0f, 1.0f, 1.0f, 1.0f);
                    Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
                    util->Unk_47dfa0(0.0f, 0.0f, amount, 1.0f, current, other, 0, &white, 0, false, false, 1, &zero, nullptr,
                                     -1);
                    Unk_GetTexture(current)->vf15(filter);
                }
            } else if (current != farTarget) {
                Unk_Float4 white(1.0f, 1.0f, 1.0f, 1.0f);
                Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
                util->Unk_47dfa0(0.0f, 0.0f, 0.0f, 1.0f, current, farTarget, 0, &white, 0, false, false, 1, &zero, nullptr, -1);
            }
        }
    }
    return 0;
}

// 0x71004b29b0: a level of the first six kinds: the near blur, the far
// blur's source scaled down from the level's source, the far blur, each
// blur faded into its target when the level's size isn't the target's
// NON_MATCHING: 68 bytes shorter; the same calls with the same arguments,
// but the original loads field_38 before the test of field_20c (shared by
// the scaling and the plain path; written that way, here, the registers of
// source and target swap and it gets worse), keeps more of the level's
// addresses in stack slots (&field_a8, &field_38) and multiplies the
// source's size by its scale before Unk_49d250 (here after it, although
// the IR has it before). What decided the rest: the item's address taken
// before the texture util is fetched (the level's `sxtw` comes first in the
// original), the first fade's target
// (field_a8) read before its test, both fade tests `&&`, the bias read
// as an Unk_Float through the Unk_Float2 at field_d8 (integer loads and
// stores) and the range written element by element, the target's size
// converted where it is read.
s32 CDepthOfField::Unk_4b29b0(s32 level) {
    Unk_Level* levels = field_4a8;
    Unk_Level* item = &levels[level];
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    bool same = item->field_0 == static_cast<u32>(item->field_a0->field_54);
    if (!Unk_442c50_get(reinterpret_cast<u64>(field_20)))
        same &= field_224 == 0;
    s32 mode = same ? field_224 : field_220;
    CRenderTexture* list[7] = {};
    s32 i;
    for (i = 0; i < item->field_60; i++)
        list[i] = item->field_68[i];
    s32 result = 0;
    if ((field_154 & 4) != 0 && field_210 > level) {
        CRenderTexture* extra = item->field_48[0];
        if ((field_154 & 8) == 0 && field_20c > level)
            extra = item->field_38;
        CRenderTexture* near = item->field_48[1];
        if (same) {
            result = Unk_4b19a0(level, true, near, item->field_a8, list, extra, mode);
        } else {
            CRenderTexture* target = item->field_48[field_180 == 3 ? 2 : 0];
            Unk_4b19a0(level, true, near, target, list, extra, mode);
            CRenderTexture* final = item->field_a8;
            if (field_1dc != 0.0f && item->field_28 == 1) {
                Unk_GetTexture(target)->vf18(2);
                Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
                Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
                f32 fade = Unk_Saturate(field_1dc * (item->field_2c * 0.25f + 0.25f));
                result = util->Unk_47dfa0(0.0f, 0.0f, fade, 1.0f, target, final, field_224, &color, 0, false,
                                          false, 1, &zero, nullptr, -1);
            } else {
                Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
                Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
                result = util->Unk_47dfa0(0.0f, 0.0f, 0.0f, 1.0f, target, final, field_224, &color, 0, false,
                                          false, 1, &zero, nullptr, -1);
            }
        }
    }
    CRenderTexture* blurred;
    if ((field_154 & 2) != 0 && field_20c > level) {
        CRenderTexture* source = item->field_38;
        CRenderTexture* target;
        if ((field_c0.field_0[3] & 4) != 0)
            target = item->field_48[2];
        else
            target = item->field_68[item->field_60 + (same ? -1 : -2)];
        f32 u1 = source->field_88 * static_cast<f32>(static_cast<u32>(source->field_54));
        f32 v1 = source->field_8c * static_cast<f32>(static_cast<u32>(source->field_58));
        f32 u0 = source->field_90;
        f32 v0 = source->field_94;
        f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
        f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
        target->Unk_49d250(0, 0, 1, 0, 0);
        const Unk_Float2& pair = *reinterpret_cast<const Unk_Float2*>(&item->field_d8);
        f32 scale = -item->field_d8;
        Unk_Float bias = pair.field_0[1];
        if (field_16c == 1) {
            bias = field_1e8.field_0[3].field_0 * scale + bias.field_0;
            scale = field_1e8.field_0[2].field_0 * scale;
        }
        Unk_Float4 values[4] = {
            Unk_Float4(1.0f, 1.0f, 1.0f, scale),
            Unk_Float4(0.0f, 0.0f, 0.0f, bias),
            Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f),
            Unk_Float4(65500.0f, 65500.0f, 65500.0f, 1.0f),
        };
        u32 state = Unk_GetTexture(source)->vf16();
        Unk_GetTexture(source)->vf15(9);
        if ((field_154 & 8) == 0) {
            Unk_GPUTexture* mask = nullptr;
            if (field_c0.field_6d && level >= 2) {
                s32 index;
                switch (level) {
                case 2:
                case 3:
                    index = 0;
                    break;
                case 4:
                case 5:
                    index = 1;
                    break;
                case 6:
                    index = 2;
                    break;
                default:
                    index = -1;
                    break;
                }
                CRenderTexture* texture = static_cast<CRenderTexture*>(field_488[index]);
                if (texture != nullptr)
                    mask = Unk_GetTexture(texture);
            }
            result = util->Unk_47b8e0(0.0f, 0.0f, width, height, 0.0f, 0.0f,
                                      u1 + u0, v1 + v0, &values[0], &values[1], false, Unk_GetTexture(source), mask,
                                      0);
        } else {
            Unk_Float2 range;
            range.field_0[0] = scale;
            range.field_0[1] = bias;
            if (field_16c == 1) {
                range.field_0[0] = -item->field_d8;
                range.field_0[1] = pair.field_0[1];
            }
            CRenderTexture* mask = nullptr;
            if (field_c0.field_6d && level >= 2) {
                s32 index;
                switch (level) {
                case 2:
                case 3:
                    index = 0;
                    break;
                case 4:
                case 5:
                    index = 1;
                    break;
                case 6:
                    index = 2;
                    break;
                default:
                    index = -1;
                    break;
                }
                mask = static_cast<CRenderTexture*>(field_488[index]);
            }
            result = util->Unk_48d020(source, target, mask, item->field_1c, &range, field_16c, field_170, false,
                                      field_17c, false);
        }
        Unk_GetTexture(source)->vf15(state);
        blurred = target;
    } else {
        blurred = item->field_38;
    }
    if (((field_154 & 4) != 0 ? field_20c : field_208) > level) {
        if (same) {
            result = Unk_4b19a0(level, false, blurred, item->field_a0, list, item->field_38, mode);
        } else {
            CRenderTexture* target = item->field_68[item->field_60 - 1];
            Unk_4b19a0(level, false, blurred, target, list, item->field_38, mode);
            if (field_1dc != 0.0f && item->field_28 == 1) {
                Unk_GetTexture(target)->vf18(2);
                Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
                Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
                f32 fade = Unk_Saturate(field_1dc * (item->field_2c * 0.25f + 0.25f));
                result = util->Unk_47dfa0(0.0f, 0.0f, fade, 1.0f, target, item->field_a0, field_224, &color, 0, false,
                                          false, 1, &zero, nullptr, -1);
            } else {
                Unk_Float4 color(1.0f, 1.0f, 1.0f, 1.0f);
                Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
                result = util->Unk_47dfa0(0.0f, 0.0f, 0.0f, 1.0f, target, item->field_a0, field_224, &color, 0, false,
                                          false, 1, &zero, nullptr, -1);
            }
        }
    }
    return result;
}

// util's Unk_490780 in white (inline)
static inline s32 Unk_BlurWhite(CTextureUtil* util, Unk_Float4* color, f32 scale, CRenderTexture* source,
                                CRenderTexture* temp, CRenderTexture* target, s32 count, const f32* weights,
                                bool normalize, s32 index) {
    *color = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
    return util->Unk_490780(scale, source, temp, target, count, weights, normalize, index, color, false, 0, 0);
}
// util's Unk_490e70 in white over the full range (inline)
static inline s32 Unk_LineBlurWhite(CTextureUtil* util, Unk_Float4* color, Unk_Float4* range, f32 angle, f32 length,
                                    f32 scale, void* source, void* temp, void* target, s32 count, const f32* weights,
                                    bool normalize, s32 index) {
    *color = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
    *range = Unk_Float4(1.0f, 0.0f, -3.40282347e+38f, 3.40282347e+38f);
    return util->Unk_490e70(angle, length, scale, source, temp, target, count, weights, normalize, index, color,
                            nullptr, range, false, 0, 0);
}
// util's Unk_496b40 in white (inline)
static inline s32 Unk_FadeWhite(CTextureUtil* util, Unk_Float4* weight, Unk_Float4* color, f32 arg0, f32 arg1,
                                CRenderTexture* source, CRenderTexture* source2, CRenderTexture* target,
                                const Unk_Float& value) {
    weight->field_0[0] = weight->field_0[1] = weight->field_0[2] = weight->field_0[3] = value;
    *color = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
    return util->Unk_496b40(arg0, arg1, source, source2, target, weight, 0, color, 0, false, false, 0, 0);
}

// 0x71004b3280: a level of the seventh kind: two hexagonal blurs and their
// sum, faded into the alternate texture
// The colours and the range are locals of the caller in their own scopes,
// declared after the weights (that gives the original's stack layout: weights
// highest, then the range, the colour sharing the sources' slot, the fade's
// colour), and filled in place by inline helpers (so their stores come after
// the calls' other arguments).
// The fade's weight is filled in before its colour, with one chained
// assignment (the highest pair is stored first).
// NON_MATCHING: the test of field_28: the original reads it through the
// pre-indexed field_a0 pointer (`ldur w8, [x24, #-0x78]`, so the IR had its
// address relative to &item->field_a0); here it is read through field_4a8
// again (closer than `item->field_28`, which recomputes the address; a local
// `levels` array pointer and a reference to field_a0 don't change that). The
// blur calls' argument copies are also scheduled a little differently.
// The callees 0x7100490780 and 0x7100496b40 have placeholder signatures.
s32 CDepthOfField::Unk_4b3280(s32 level) {
    Unk_Level* item = &field_4a8[level];
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    const f32 weights[9] = {0.71f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.71f};
    {
        Unk_Float4 color;
        Unk_BlurWhite(util, &color, 1.0f, item->field_38, item->field_68[3], item->field_68[0], 9, weights, 1,
                      field_220);
    }
    {
        Unk_Float4 color;
        Unk_Float4 range;
        Unk_LineBlurWhite(util, &color, &range, 0.52359879f, 9.0f, 1.0f, item->field_38, item->field_68[3],
                          item->field_68[1], 9, weights, 1, field_220);
    }
    {
        Unk_Float4 color;
        Unk_Float4 range;
        Unk_LineBlurWhite(util, &color, &range, 1.04719758f, 9.0f, 1.0f, item->field_38, item->field_68[3],
                          item->field_68[2], 9, weights, 1, field_220);
    }
    CRenderTexture* sources[3] = {item->field_68[0], item->field_68[1], item->field_68[2]};
    s32 result = util->Unk_48d220(1.0f / 3.0f, 1.0f, item->field_a0, 3, sources, nullptr, field_224, 0);
    if (field_1dc != 0.0f && field_4a8[level].field_28 == 1) {
        Unk_Float4 weight;
        Unk_Float4 color;
        Unk_FadeWhite(util, &weight, &color, 1.0f, 0.002f, item->field_a0, item->field_78[0], item->field_a0,
                      Unk_Float(item->field_2c));
    }
    return result;
}

// 0x71004a7390: checks a description (the ranges in field_20 are pairs, the
// first one used, the others used or not, each used one beyond the last).
// The order of the four loads decides the last test's: Reassociate ranks the
// compares by their loads, and only the previous begin read last puts its
// compare before the unused flag.
s32 CDepthOfField::ValidateInitParam(CRenderTexture* source, const Unk_Desc* desc) {
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
            s32 prevEnd = desc->field_20[i * 2 - 1];
            s32 end = desc->field_20[i * 2 + 1];
            s32 prevBegin = desc->field_20[i * 2 - 2];
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
            if (!(end > prevEnd || begin > prevBegin || unused)) {
                return -6;
            }
        }
    }
    if (!desc->field_65 || source != nullptr) {
        return 0;
    }
    return -6;
}

// 0x71004ac430: lets go of the levels, the passes and the tables, and resets
// the members (the casts: members whose placeholder types other functions
// read as other types)
s32 CDepthOfField::vf3() {
    CTextureUtil* util = Unk_GetTextureUtil();
    Unk_ReleaseTextureUtil();
    for (s32 i = 0; i < field_c0.field_10; i++) {
        Unk_Level* level = &field_4a8[i];
        if (!level->field_40) {
            Unk_49fdc0_call(field_4a0, reinterpret_cast<u64>(level->field_38));
        }
        Unk_49fc60(util->field_29a58, level->field_60, level->field_68);
        UNK_DELETE_ARRAY(level->field_68);
        Unk_49fc60(util->field_29a58, level->field_70, level->field_78);
        UNK_DELETE_ARRAY(level->field_78);
        if (field_c0.field_64) {
            level->field_a0 = nullptr;
            PPFX_SAFE_RELEASE(level->field_80);
            PPFX_SAFE_RELEASE(level->field_88);
        } else {
            PPFX_SAFE_RELEASE(level->field_a0);
        }
        for (s32 j = 0; j < field_180; j++) {
            PPFX_SAFE_RELEASE(level->field_48[j]);
        }
        if (field_c0.field_64) {
            level->field_a8 = nullptr;
            PPFX_SAFE_RELEASE(level->field_90);
            PPFX_SAFE_RELEASE(level->field_98);
        } else {
            PPFX_SAFE_RELEASE(level->field_a8);
        }
        PPFX_SAFE_RELEASE(level->field_b0);
        PPFX_SAFE_RELEASE(level->field_b8);
    }
    PPFX_SAFE_RELEASE(field_248);
    for (s32 k = 0; k < 4; k++) {
        for (s32 i = 0; i < field_2f0; i++) {
            PPFX_SAFE_RELEASE_INTERFACE(field_2f8[k][i]);
            PPFX_SAFE_RELEASE_INTERFACE(field_318[k][i]);
        }
        UNK_DELETE_ARRAY(field_2f8[k]);
        UNK_DELETE_ARRAY(field_318[k]);
        UNK_DELETE_ARRAY(field_338[k]);
        UNK_DELETE_ARRAY(field_358[k]);
        UNK_DELETE_ARRAY(field_378[k]);
    }
    field_2f0 = 0;
    UNK_DELETE_ARRAY(field_398);
    PPFX_SAFE_RELEASE_INTERFACE(reinterpret_cast<IGPUInterface*&>(field_258));
    PPFX_SAFE_RELEASE_INTERFACE(reinterpret_cast<IGPUInterface*&>(field_260));
    PPFX_SAFE_RELEASE_INTERFACE(field_280[0]);
    PPFX_SAFE_RELEASE_INTERFACE(field_280[1]);
    PPFX_SAFE_RELEASE_INTERFACE(reinterpret_cast<IGPUInterface*&>(field_3a0));
    for (s32 i = 0; i < field_2c0; i++) {
        PPFX_SAFE_RELEASE_INTERFACE(field_2c8[i]);
        PPFX_SAFE_RELEASE_INTERFACE(field_2d0[i]);
    }
    UNK_DELETE_ARRAY(field_2c8);
    UNK_DELETE_ARRAY(field_2d0);
    UNK_DELETE_ARRAY(field_2d8);
    UNK_DELETE_ARRAY(field_2e0);
    UNK_DELETE_ARRAY(field_2e8);
    if (field_3f8 > 0) {
        for (s32 i = 0; i <= field_3f8; i++) {
            PPFX_SAFE_RELEASE(field_430[i]);
            if (i < field_3f8) {
                PPFX_SAFE_RELEASE_INTERFACE(reinterpret_cast<IGPUInterface*&>(field_410[i]));
                PPFX_SAFE_RELEASE_INTERFACE(reinterpret_cast<IGPUInterface*&>(field_418[i]));
                PPFX_SAFE_RELEASE(field_438[i]);
                PPFX_SAFE_RELEASE(field_440[i]);
                PPFX_SAFE_RELEASE(field_448[i]);
                PPFX_SAFE_RELEASE(field_450[i]);
                PPFX_SAFE_RELEASE(field_468[i]);
                PPFX_SAFE_RELEASE(field_470[i]);
                if (field_488 != nullptr) {
                    PPFX_SAFE_RELEASE(reinterpret_cast<CRenderTexture*&>(field_488[i]));
                }
            }
        }
    }
    UNK_DELETE_ARRAY(field_430);
    UNK_DELETE_ARRAY(field_438);
    UNK_DELETE_ARRAY(field_440);
    UNK_DELETE_ARRAY(field_448);
    UNK_DELETE_ARRAY(field_450);
    UNK_DELETE_ARRAY(field_468);
    UNK_DELETE_ARRAY(field_470);
    UNK_DELETE_ARRAY(field_458);
    UNK_DELETE_ARRAY(field_460);
    UNK_DELETE_ARRAY(field_478);
    UNK_DELETE_ARRAY(field_480);
    UNK_DELETE_ARRAY(field_488);
    UNK_DELETE_ARRAY(field_410);
    UNK_DELETE_ARRAY(field_418);
    if (field_400 != nullptr) {
        Unk_4b9a60(Unk_238d5f8, reinterpret_cast<u64*>(field_400) - 1);
        field_400 = nullptr;
    }
    if (field_408 != nullptr) {
        Unk_4b9a60(Unk_238d5f8, reinterpret_cast<u64*>(field_408) - 1);
        field_408 = nullptr;
    }
    UNK_DELETE_ARRAY(field_420);
    UNK_DELETE_ARRAY(field_428);
    field_3f8 = 0;
    UNK_DELETE_ARRAY(field_4a8);
    UNK_DELETE(field_4a0);
    if (field_490 != nullptr) {
        Unk_49fc60(util->field_29a58, field_498, field_490);
        UNK_DELETE_ARRAY(field_490);
        field_498 = 0;
    }
    Unk_ResetMembers();
    s32 result = CGPUResourceManage::vf3();
    return result < 0 ? result : 0;
}

// 0x710040fb30, 0x7100410130, 0x7100410070 (Unk_415f40.cpp): a hue rotation,
// a saturation and a point through a matrix
MATRIXT44* Unk_40fb30(MATRIXT44* out, bool luminance, f32 angle);
void Unk_410130(MATRIXT44* out, bool arg1, f32 r, f32 g, f32 b);
void Unk_410070(Unk_Vector3* out, const Unk_Vector3* v, const MATRIXT44* m);
// 0x7100446a90, 0x7100446ae0 (Unk_447050.cpp): a size at a mip level, a
// format's bytes per pixel
u32 Unk_446a90(u32 size, u32 level);
u32 Unk_446ae0(s32 format);

// a power of what is positive (inline)
static inline f64 Unk_PowPositive(f64 x, f64 e) {
    return x > 0.0 ? pow(x, e) : x;
}
static inline f32 Unk_PowPositiveF(f32 x, f32 e) {
    return x > 0.0f ? powf(x, e) : x;
}
// a square root of what is positive (inline)
static inline f32 Unk_SqrtPositiveF(f32 x) {
    return x > 0.0f ? sqrtf(x) : x;
}
// a value from 0 to 1 as a byte (inline)
static inline u32 Unk_ToByteF(f32 x, s32 shift) {
    if (x >= 1.0f)
        return 0xff << shift;
    if (x <= 0.0f)
        return 0;
    return static_cast<u32>(x * 255.9999f) << shift;
}
// a value clamped to [0, max] (inline)
static inline f32 Unk_Clamp(f32 value, f32 max) {
    if (value < 0.0f) {
        return 0.0f;
    }
    return value > max ? max : value;
}
static inline f64 Unk_Clamp64(f64 value, f64 max) {
    if (value < 0.0) {
        return 0.0;
    }
    return value > max ? max : value;
}

// 0x71004ad3d0 (its log lines name it)
// The row and column loops' indices are `s64` (closer than `u32`).
// The pixels' channels are scaled in place before their square roots, and
// the minimum texture's channels read into locals before they are summed.
// NON_MATCHING: same calls, loops and arithmetic; register allocation and
// spills differ (the original's frame is 0x20 bytes larger and addresses the
// matrix, colour and textures from one base register), the error blocks are
// laid out after the second pass, and the three peak values stay on the stack
// for an address select (here SROA promotes them: fcsel).
s32 CDepthOfField::CreateScatterBokehOpticsTexture(u32 width, u32 height, const void* image, IGPUTexture** outTexture,
                                                   IGPUTexture** outMinTexture, Unk_Float4* outColor, Unk_Float* outRed,
                                                   f32* outPosition, f32 gamma, f32 hue, f32 saturation,
                                                   f32 exponent) {
    IGPUTexture* texture;
    IGPUTexture* minTexture;
    Unk_Float4 color;
    MATRIXT44 matrix;
    Unk_Identity(&matrix);
    const MATRIXT44* transform = nullptr;
    if (hue != 0.0f || saturation != 1.0f) {
        if (hue != 0.0f) {
            MATRIXT44 rotation;
            Unk_40fb30(&rotation, true, hue);
            MATRIXT44_MatrixMultiply(&matrix, &matrix, &rotation);
        }
        if (saturation != 1.0f) {
            MATRIXT44 scaling;
            Unk_410130(&scaling, false, saturation, saturation, saturation);
            MATRIXT44_MatrixMultiply(&matrix, &matrix, &scaling);
        }
        transform = &matrix;
    }
    u32 levels = static_cast<u32>(logf(static_cast<f32>(width < height ? width : height)) / 0.6931472f) - 1;
    u32 flags = levels == 1 ? 0 : 4;
    s32 result =
        field_20->vf60(width, height, levels, 0, 0x1c, 0, 0, reinterpret_cast<IGPUInterface**>(&texture), flags);
    if (result < 0) {
#line 7107
        PPFX_ERROR("CDepthOfField::CreateScatterBokehOpticsTexture(): "
                   "m_pGPUDevice->CreateTexture(&pGPUScatterBokehOpticsTexture) failed (0x%x: %s).\n",
                   result, Unk_446df0(result));
        return result;
    }
    s32 rows = static_cast<s32>(ldexp(1.0, 3));
    u32 minHeight = static_cast<u32>(rows) < height ? rows : height;
    result = field_20->vf60(width, minHeight, 1, 0, 0x1c, 0, 0, reinterpret_cast<IGPUInterface**>(&minTexture),
                            flags);
    if (result < 0) {
#line 7137
        PPFX_ERROR("CDepthOfField::CreateScatterBokehOpticsTexture(): "
                   "m_pGPUDevice->CreateTexture(&pGPUScatterBokehOpticsMinTexture) failed (0x%x: %s).\n",
                   result, Unk_446df0(result));
        return result;
    }
    u32 bpp = Unk_446ae0(0x1c);
    u32 stride = bpp * width;
    u32 size = stride * height;
#line 7185
    u8* pixels = UNK_NEW_ARRAY(u8, size);
    memcpy(pixels, image, size);

    // the image's colours, and the centre column's weighted sums
    f64 heightF = height;
    f64 inverse = 1.0 / heightF;
    f64 maxR = 0.0;
    f64 maxG = 0.0;
    f64 maxB = 0.0;
    f64 sumR = 0.0;
    f64 sumG = 0.0;
    f64 sumB = 0.0;
    for (u32 x = 0; x < width; x++) {
        u8* column = pixels + x * bpp;
        for (s64 y = 0; y < height; y++) {
            u32 pixel = *reinterpret_cast<u32*>(column + y * stride);
            f64 r = static_cast<f32>((pixel >> 16) & 0xff) * (1.0 / 255.0);
            f64 g = static_cast<f32>((pixel >> 8) & 0xff) * (1.0 / 255.0);
            f64 b = static_cast<f32>(pixel & 0xff) * (1.0 / 255.0);
            r = Unk_PowPositive(r, gamma);
            g = Unk_PowPositive(g, gamma);
            b = Unk_PowPositive(b, gamma);
            bool changed = false;
            if (transform != nullptr) {
                Unk_Vector3 v = {{static_cast<f32>(r), static_cast<f32>(g), static_cast<f32>(b)}};
                Unk_410070(&v, &v, transform);
                r = Unk_Clamp(v.field_0[0], 1.0f);
                g = Unk_Clamp(v.field_0[1], 1.0f);
                b = Unk_Clamp(v.field_0[2], 1.0f);
                changed = true;
            }
            if (exponent != 1.0f) {
                f64 luminance = 0.2126 * r + 0.7152 * g + 0.0722 * b;
                if (luminance > 0.0) {
                    f64 scale = 1.0 / luminance;
                    r *= scale;
                    g *= scale;
                    b *= scale;
                    scale = pow(luminance, exponent);
                    r *= scale;
                    g *= scale;
                    b *= scale;
                }
                changed = true;
            }
            f64 t = 1.0 - static_cast<f64>(y) / (height - 1);
            t = t * t;
            f64 weight = Unk_Clamp64(t * -5.333333333333333 + 4.666666666666666, 1.0);
            f64 high = r > g ? r : g;
            f64 low = r < g ? r : g;
            high = high > b ? high : b;
            f64 chroma = 0.0;
            if (!(high <= 0.0)) {
                low = low < b ? low : b;
                chroma = 1.0 - low / high;
            }
            f64 luminance = 0.2126 * r + 0.7152 * g + 0.0722 * b;
            if (luminance > 0.0) {
                f64 amount = weight * (t * chroma) * 0.25;
                f64 target = luminance + (0.5 - luminance) * amount;
                f64 scale = (luminance > target ? luminance : target) / luminance;
                r *= scale;
                g *= scale;
                b *= scale;
                changed = true;
            }
            if (changed) {
                f64 cr = Unk_PowPositive(r, 1.0 / gamma);
                f64 cg = Unk_PowPositive(g, 1.0 / gamma);
                f64 cb = Unk_PowPositive(b, 1.0 / gamma);
                f64 a = static_cast<f32>(pixel >> 24) * (1.0 / 255.0);
                u32 br = Unk_ToByte(cr, 16);
                u32 bg = Unk_ToByte(cg, 8);
                u32 bb = Unk_ToByte(cb, 0);
                u32 ba = Unk_ToByte(a, 24);
                *reinterpret_cast<u32*>(column + y * stride) = br | bg | bb | ba;
            }
            maxR = maxR > r ? maxR : r;
            maxG = maxG > g ? maxG : g;
            maxB = maxB > b ? maxB : b;
            if (x == width / 2) {
                f64 angle = (static_cast<f64>(height - y) - 0.5) / heightF * 2.0 * 3.14159265f;
                sumR += inverse * (angle * r);
                sumG += inverse * (angle * g);
                sumB += inverse * (angle * b);
            }
        }
    }
    f64 averageR = sumR * (2.0 / 3.14159265f);
    f64 averageG = sumG * (2.0 / 3.14159265f);
    f64 averageB = sumB * (2.0 / 3.14159265f);
    f64 lowest = averageR < averageG ? averageR : averageG;
    lowest = lowest < averageB ? lowest : averageB;
    f32 low = lowest;
    f32 factorR = low / static_cast<f32>(averageR);
    f32 factorG = low / static_cast<f32>(averageG);
    f32 factorB = low / static_cast<f32>(averageB);
    f32 peakR = factorR * static_cast<f32>(maxR);
    f32 peakG = factorG * static_cast<f32>(maxG);
    f32 peakB = factorB * static_cast<f32>(maxB);
    f32 normal = 1.0f / Unk_MaxRefF(Unk_MaxRefF(peakR, peakG), peakB);
    f32 scaleR = factorR * normal;
    f32 scaleG = factorG * normal;
    f32 scaleB = factorB * normal;

    // the centre column's sums with the colours scaled
    color = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    f64 totalR = 0.0;
    f64 totalG = 0.0;
    f64 totalB = 0.0;
    f64 totalA = 0.0;
    u8* centre = pixels + bpp * (width / 2);
    for (u32 y = 0; y < height; y++) {
        u32 pixel = *reinterpret_cast<u32*>(centre + y * stride);
        f64 r = static_cast<f32>((pixel >> 16) & 0xff) * (1.0 / 255.0);
        f64 g = static_cast<f32>((pixel >> 8) & 0xff) * (1.0 / 255.0);
        f64 b = static_cast<f32>(pixel & 0xff) * (1.0 / 255.0);
        r = Unk_PowPositive(r, gamma);
        g = Unk_PowPositive(g, gamma);
        b = Unk_PowPositive(b, gamma);
        f64 a = static_cast<f32>(pixel >> 24) * (1.0 / 255.0);
        f64 angle = (static_cast<f64>(height - y) - 0.5) / heightF * 3.14159265f;
        totalR += inverse * (angle * (r * scaleR));
        totalG += inverse * (angle * (g * scaleG));
        totalB += inverse * (angle * (b * scaleB));
        totalA += inverse * (angle * a);
    }
    f32 red = static_cast<f32>(totalR) * (2.0f / 3.14159265f);
    f32 green = static_cast<f32>(totalG) * (2.0f / 3.14159265f);
    f32 blue = static_cast<f32>(totalB) * (2.0f / 3.14159265f);
    f32 highest = red > green ? red : green;
    highest = highest > blue ? highest : blue;
    Unk_Float first;
    if (highest > 0.0f) {
        color = Unk_Float4(red, green, blue, static_cast<f32>(totalA) * (2.0f / 3.14159265f));
        first = red;
    } else {
        first = 0.0f;
    }

    // the texture's levels
    u32 count = texture->vf12();
#line 7418
    u8** mips = UNK_NEW_ARRAY(u8*, count);
    // a 4x4 ordered dither, in quarters of a step
    f32 dither[4][4];
    dither[0][0] = 0.0f; dither[0][1] = 2.0f; dither[0][2] = 0.5f; dither[0][3] = 2.5f;
    dither[1][0] = 3.0f; dither[1][1] = 1.0f; dither[1][2] = 3.5f; dither[1][3] = 1.5f;
    dither[2][0] = 0.75f; dither[2][1] = 2.75f; dither[2][2] = 0.25f; dither[2][3] = 2.25f;
    dither[3][0] = 3.75f; dither[3][1] = 1.75f; dither[3][2] = 3.25f; dither[3][3] = 1.25f;
    for (u32 level = 0; level < count; level++) {
        u32 previous = level == 0 ? 0 : level - 1;
        u32 levelWidth = Unk_446a90(width, level);
        u32 levelHeight = Unk_446a90(height, level);
        u32 previousWidth = Unk_446a90(width, previous);
        u32 previousHeight = Unk_446a90(height, previous);
        u32 levelStride = levelWidth * bpp;
#line 7452
        mips[level] = UNK_NEW_ARRAY(u8, levelStride * levelHeight);
        if (level == 0) {
            for (u32 y = 0; y < height; y++) {
                for (u32 x = 0; x < width; x++) {
                    u32 pixel = *reinterpret_cast<u32*>(pixels + y * stride + x * bpp);
                    u8* out = mips[level] + y * stride + x * bpp;
                    f32 r = static_cast<f32>((pixel >> 16) & 0xff) * (1.0f / 255.0f);
                    f32 g = static_cast<f32>((pixel >> 8) & 0xff) * (1.0f / 255.0f);
                    f32 b = static_cast<f32>(pixel & 0xff) * (1.0f / 255.0f);
                    r = Unk_PowPositiveF(r, gamma);
                    g = Unk_PowPositiveF(g, gamma);
                    b = Unk_PowPositiveF(b, gamma);
                    r *= scaleR;
                    g *= scaleG;
                    b *= scaleB;
                    r = Unk_SqrtPositiveF(r);
                    g = Unk_SqrtPositiveF(g);
                    b = Unk_SqrtPositiveF(b);
                    f32 a = static_cast<f32>(pixel >> 24) * (1.0f / 255.0f);
                    u32 br = Unk_ToByteF(r, 0);
                    u32 bg = Unk_ToByteF(g, 8);
                    u32 bb = Unk_ToByteF(b, 16);
                    u32 ba = Unk_ToByteF(a, 24);
                    *reinterpret_cast<u32*>(out) = br | bg | bb | ba;
                }
            }
        } else {
            u32 largest = levelWidth > levelHeight ? levelWidth : levelHeight;
            u32 previousStride = previousWidth * bpp;
            for (u32 y = 0; y < levelHeight; y++) {
                u32 y0 = previousHeight > levelHeight ? 2 * y : y;
                u32 y1 = previousHeight > levelHeight ? 2 * y + 1 : y;
                for (u32 x = 0; x < levelWidth; x++) {
                    u32 x0 = previousWidth > levelWidth ? 2 * x : x;
                    u32 x1 = previousWidth > levelWidth ? 2 * x + 1 : x;
                    u8* out = mips[level] + y * levelStride + x * bpp;
                    u8* source = mips[previous];
                    u32 p00 = *reinterpret_cast<u32*>(source + y0 * previousStride + x0 * bpp);
                    u32 p01 = *reinterpret_cast<u32*>(source + y0 * previousStride + x1 * bpp);
                    u32 p10 = *reinterpret_cast<u32*>(source + y1 * previousStride + x0 * bpp);
                    u32 p11 = *reinterpret_cast<u32*>(source + y1 * previousStride + x1 * bpp);
                    f32 r00 = Unk_PowPositiveF(static_cast<f32>((p00 >> 16) & 0xff) * (1.0f / 255.0f), 2.0f);
                    f32 g00 = Unk_PowPositiveF(static_cast<f32>((p00 >> 8) & 0xff) * (1.0f / 255.0f), 2.0f);
                    f32 b00 = Unk_PowPositiveF(static_cast<f32>(p00 & 0xff) * (1.0f / 255.0f), 2.0f);
                    f32 a00 = static_cast<f32>(p00 >> 24) * (1.0f / 255.0f);
                    f32 r01 = Unk_PowPositiveF(static_cast<f32>((p01 >> 16) & 0xff) * (1.0f / 255.0f), 2.0f);
                    f32 g01 = Unk_PowPositiveF(static_cast<f32>((p01 >> 8) & 0xff) * (1.0f / 255.0f), 2.0f);
                    f32 b01 = Unk_PowPositiveF(static_cast<f32>(p01 & 0xff) * (1.0f / 255.0f), 2.0f);
                    f32 a01 = static_cast<f32>(p01 >> 24) * (1.0f / 255.0f);
                    f32 r10 = Unk_PowPositiveF(static_cast<f32>((p10 >> 16) & 0xff) * (1.0f / 255.0f), 2.0f);
                    f32 g10 = Unk_PowPositiveF(static_cast<f32>((p10 >> 8) & 0xff) * (1.0f / 255.0f), 2.0f);
                    f32 b10 = Unk_PowPositiveF(static_cast<f32>(p10 & 0xff) * (1.0f / 255.0f), 2.0f);
                    f32 a10 = static_cast<f32>(p10 >> 24) * (1.0f / 255.0f);
                    f32 r11 = Unk_PowPositiveF(static_cast<f32>((p11 >> 16) & 0xff) * (1.0f / 255.0f), 2.0f);
                    f32 g11 = Unk_PowPositiveF(static_cast<f32>((p11 >> 8) & 0xff) * (1.0f / 255.0f), 2.0f);
                    f32 b11 = Unk_PowPositiveF(static_cast<f32>(p11 & 0xff) * (1.0f / 255.0f), 2.0f);
                    f32 a11 = static_cast<f32>(p11 >> 24) * (1.0f / 255.0f);
                    f32 a = (a00 + a01 + a10 + a11) * 0.25f;
                    f32 r = (r00 + r01 + r10 + r11) * 0.25f;
                    f32 g = (g00 + g01 + g10 + g11) * 0.25f;
                    f32 b = (b00 + b01 + b10 + b11) * 0.25f;
                    r = Unk_PowPositiveF(r, 0.5f);
                    g = Unk_PowPositiveF(g, 0.5f);
                    b = Unk_PowPositiveF(b, 0.5f);
                    f32 d = largest > 3 ? dither[x & 3][y & 3] : 2.0f;
                    f32 bias = d * 0.25f - 0.25f;
                    out[0] = static_cast<s32>(Unk_Clamp(b * 255.9999f + bias, 255.0f));
                    out[1] = static_cast<s32>(Unk_Clamp(g * 255.9999f + bias, 255.0f));
                    out[2] = static_cast<s32>(Unk_Clamp(r * 255.9999f + bias, 255.0f));
                    out[3] = static_cast<s32>(Unk_Clamp(a * 255.9999f + bias, 255.0f));
                }
            }
        }
    }
    if (pixels != nullptr) {
        Unk_4b9a60(Unk_238d5f8, reinterpret_cast<u64*>(pixels) - 1);
    }

    // the minimum texture: the first level's rows averaged in groups
    u32 minSize = stride * minHeight;
#line 7635
    u8* minData = UNK_NEW_ARRAY(u8, minSize);
    if (width != 0) {
        u32 step = height / minHeight;
        f64 scale = 1.0 / step;
        for (s64 x = 0; x < width; x++) {
            for (s64 j = 0; j < minHeight; j++) {
                f64 r = 0.0;
                f64 g = 0.0;
                f64 b = 0.0;
                f64 a = 0.0;
                u8* column = mips[0] + x * bpp;
                for (u32 k = 0; k < step; k++) {
                    u32 pixel = *reinterpret_cast<u32*>(column + (j * step + k) * stride);
                    f64 cr = Unk_Channel2(pixel >> 16);
                    f64 cg = Unk_Channel2(pixel >> 8);
                    f64 cb = Unk_Channel2(pixel);
                    f64 ca = static_cast<f32>(pixel >> 24) * (1.0 / 255.0);
                    r += cr;
                    g += cg;
                    b += cb;
                    a += ca;
                }
                r *= scale;
                g *= scale;
                b *= scale;
                r = Unk_SqrtPositive(r);
                g = Unk_SqrtPositive(g);
                b = Unk_SqrtPositive(b);
                u32 br = Unk_ToByte(r, 16);
                u32 bg = Unk_ToByte(g, 8);
                u32 bb = Unk_ToByte(b, 0);
                u32 ba = Unk_ToByte(scale * a, 24);
                *reinterpret_cast<u32*>(minData + x * bpp + j * stride) = br | bg | bb | ba;
            }
        }
    }
    Unk_4aff50(minData, width, minHeight, &color.field_0[0].field_0, false);
    u32 brightest = 0;
    f32 brightness = 0.0f;
    for (u32 x = 0; x < width; x++) {
        f32 r = 0.0f;
        f32 g = 0.0f;
        f32 b = 0.0f;
        for (u32 y = 0; y < minHeight; y++) {
            u32 pixel = *reinterpret_cast<u32*>(minData + x * 4 + y * (width * 4));
            f32 cr = static_cast<f32>((pixel >> 16) & 0xff) * (1.0f / 255.0f);
            f32 cg = static_cast<f32>((pixel >> 8) & 0xff) * (1.0f / 255.0f);
            f32 cb = static_cast<f32>(pixel & 0xff) * (1.0f / 255.0f);
            r += cr * cr;
            g += cg * cg;
            b += cb * cb;
        }
        f32 luminance = r * 0.2126f + g * 0.7152f + b * 0.0722f;
        if (luminance > brightness) {
            brightness = luminance;
            brightest = x;
        }
    }
    f32 position = (static_cast<f32>(brightest) + 1.0f) / static_cast<f32>(width);
    if (position > 0.9f || position < 0.1f) {
        position = 0.5f;
    }
    for (u32 level = 0; level < count; level++) {
        Unk_4aff50(mips[level], Unk_446a90(width, level), Unk_446a90(height, level), &color.field_0[0].field_0,
                   true);
    }
    for (u32 level = 0; level < count; level++) {
        texture->vf9(mips[level], level, 0, true);
    }
    minTexture->vf9(minData, 0, 0, true);
    for (u32 level = 0; level < count; level++) {
        if (mips[level] != nullptr) {
            Unk_4b9a60(Unk_238d5f8, reinterpret_cast<u64*>(mips[level]) - 1);
            mips[level] = nullptr;
        }
    }
    UNK_DELETE_ARRAY(mips);
    if (minData != nullptr) {
        Unk_4b9a60(Unk_238d5f8, reinterpret_cast<u64*>(minData) - 1);
    }
    texture->vf15(7);
    minTexture->vf15(7);
    if (outTexture != nullptr) {
        *outTexture = texture;
    } else {
        PPFX_SAFE_RELEASE_INTERFACE(texture);
    }
    if (outMinTexture != nullptr) {
        *outMinTexture = minTexture;
    } else {
        PPFX_SAFE_RELEASE_INTERFACE(minTexture);
    }
    if (outColor != nullptr) {
        *outColor = color;
    }
    if (outRed != nullptr) {
        *outRed = first;
    }
    if (outPosition != nullptr) {
        *outPosition = position;
    }
    return 0;
}

// 0x7100461f20 (GPUTextureUtil.cpp): a cosine falloff to the edge
void Unk_461f20(Unk_Float4* out, const Unk_Float2* position, const Unk_Float2* size, const f32* params);
// 0x7100462330 (GPUTextureUtil.cpp): a texture's levels from an image
// (`levels`: the levels' data, made for the caller)
s32 Unk_462330(IGPUBaseTexture* texture, const void* data, bool arg2, bool arg3, u8*** levels, f32 arg5);
// 0x710040f610 (Unk_415f40.cpp)
s32 Unk_40f610(s32 value, bool up, s32 count);

// 0x7101eda4bc, 0x7101ee24bc, 0x7101ec24bc, 0x7101eca4bc, 0x7101ed24bc,
// 0x7101eba4bc: the scatter textures' images (128 by 64)
extern const u8 Unk_1eda4bc[];
extern const u8 Unk_1ee24bc[];
extern const u8 Unk_1ec24bc[];
extern const u8 Unk_1eca4bc[];
extern const u8 Unk_1ed24bc[];
extern const u8 Unk_1eba4bc[];

// a colour as A8B8G8R8 (inline)
static inline u32 Unk_PackABGR(Unk_Float4 color) {
    u32 r = Unk_ToByteF(color.field_0[0].field_0, 0);
    u32 g = Unk_ToByteF(color.field_0[1].field_0, 8);
    u32 b = Unk_ToByteF(color.field_0[2].field_0, 16);
    u32 a = Unk_ToByteF(color.field_0[3].field_0, 24);
    return r | g | b | a;
}

// an array of plain values freed (inline: no destructors)
template <class T>
static inline void Unk_FreeArray(T*& items) {
    if (items != nullptr) {
        Unk_4b9a60(Unk_238d5f8, reinterpret_cast<u64*>(items) - 1);
        items = nullptr;
    }
}

// the power of two at or above a value (inline)
static inline s32 Unk_Pow2(s32 value) {
    f64 exponent = log(static_cast<f64>(value)) / log(2.0);
    s32 e = static_cast<s32>(exponent);
    return static_cast<s32>(pow(2.0, exponent != e ? static_cast<s32>(exponent + 1.0) : e));
}

// 0x71004aa860 (its log lines name it)
// The Morton loops' indices are `s64` and the corners' `u32` (closer than
// `u32` and `s32`).
// NON_MATCHING: 6364 bytes of 6588. The original unswitches the Morton loop
// of the passes' vertices on `bitsX + bitsY == 0` (a copy with every corner a
// constant); here LoopUnswitch's size budget is gone (it unswitches when the
// checkerboard loop before it is a single loop), so the corners' stack array
// is folded away and the frame is 0x10 smaller. The aperture tables' array new
// isn't runtime-unrolled (by 4 in the original: Unk_NewArray's pointer loop?).
// The rest is the original's up to register allocation.
s32 CDepthOfField::CreateDeviceResources() {
    if (field_20 == nullptr) {
        return -1;
    }
    s32 result = field_4a0->vf0(field_20);
    if (result < 0) {
        return result;
    }
    for (s32 i = 0; i < field_c0.field_10; i++) {
        Unk_Level* level = &field_4a8[i];
        if (field_c0.field_64) {
            if (level->field_80 != nullptr) {
                result = level->field_80->vf0(field_20);
                if (result < 0) {
                    return result;
                }
            }
            if (level->field_88 != nullptr) {
                result = level->field_88->vf0(field_20);
                if (result < 0) {
                    return result;
                }
            }
        } else {
            result = level->field_a0->vf0(field_20);
            if (result < 0) {
                return result;
            }
        }
        for (s32 j = 0; j < field_180; j++) {
            if (level->field_48[j] != nullptr) {
                result = level->field_48[j]->vf0(field_20);
                if (result < 0) {
                    return result;
                }
            }
        }
        if (level->field_a8 != nullptr && level->field_a8 != level->field_48[0]) {
            if (field_c0.field_64) {
                if (level->field_90 != nullptr) {
                    result = level->field_90->vf0(field_20);
                    if (result < 0) {
                        return result;
                    }
                }
                if (level->field_98 != nullptr) {
                    result = level->field_98->vf0(field_20);
                    if (result < 0) {
                        return result;
                    }
                }
            } else {
                result = level->field_a8->vf0(field_20);
                if (result < 0) {
                    return result;
                }
            }
        }
        if (level->field_b0 != nullptr) {
            result = level->field_b0->vf0(field_20);
            if (result < 0) {
                return result;
            }
        }
        if (level->field_b8 != nullptr) {
            result = level->field_b8->vf0(field_20);
            if (result < 0) {
                return result;
            }
        }
    }
    if (field_248 != nullptr && field_248 != field_228) {
        result = field_248->vf0(field_20);
        if (result < 0) {
            return result;
        }
    }
    for (s32 i = 0; i <= field_3f8; i++) {
        if (field_430 != nullptr && field_430[i] != nullptr && field_430[i] != field_228) {
            result = field_430[i]->vf0(field_20);
            if (result < 0) {
                return result;
            }
        }
        if (i < field_3f8) {
            if (field_438[i] != nullptr) {
                result = field_438[i]->vf0(field_20);
                if (result < 0) {
                    return result;
                }
            }
            if (field_440 != nullptr && field_440[i] != nullptr) {
                result = field_440[i]->vf0(field_20);
                if (result < 0) {
                    return result;
                }
            }
            if (field_448 != nullptr && field_448[i] != nullptr) {
                result = field_448[i]->vf0(field_20);
                if (result < 0) {
                    return result;
                }
            }
            if (field_450 != nullptr && field_450[i] != nullptr) {
                result = field_450[i]->vf0(field_20);
                if (result < 0) {
                    return result;
                }
            }
            // (the original tests field_468 for field_470's texture too, and
            // field_478 for field_480's)
            if (field_468 != nullptr && field_468[i] != nullptr) {
                result = field_468[i]->vf0(field_20);
                if (result < 0) {
                    return result;
                }
            }
            if (field_468 != nullptr && field_470[i] != nullptr) {
                result = field_470[i]->vf0(field_20);
                if (result < 0) {
                    return result;
                }
            }
            if (field_458 != nullptr && field_458[i] != nullptr) {
                result = field_458[i]->vf0(field_20);
                if (result < 0) {
                    return result;
                }
            }
            if (field_460 != nullptr && field_460[i] != nullptr) {
                result = field_460[i]->vf0(field_20);
                if (result < 0) {
                    return result;
                }
            }
            if (field_478 != nullptr && field_478[i] != nullptr) {
                result = field_478[i]->vf0(field_20);
                if (result < 0) {
                    return result;
                }
            }
            if (field_478 != nullptr && field_480[i] != nullptr) {
                result = field_480[i]->vf0(field_20);
                if (result < 0) {
                    return result;
                }
            }
            if (field_488 != nullptr && field_488[i] != nullptr) {
                result = static_cast<CRenderTexture*>(field_488[i])->vf0(field_20);
                if (result < 0) {
                    return result;
                }
            }
        }
    }
    // the passes of the second kind: a quad for each of their texels, in a
    // vertex and an index buffer
    if (field_c0.field_6d) {
        for (s32 i = 0; i < field_3f8; i++) {
            s32 width = field_420[i].field_0;
            s32 height = field_420[i].field_4;
            s32 quads = height * width;
            s32 vertexCount = quads * 4;
            field_400[i] = vertexCount;
            s32 indexCount = quads * 6;
            field_408[i] = indexCount;
            u64 indexSize = indexCount * sizeof(u32);
#line 3663
            u32* indices = reinterpret_cast<u32*>(UNK_NEW_ARRAY(u8, indexSize));
            // the triangles' corners (the other way round for a device whose
            // viewport's origin is at the lower left)
            bool flip = field_20->field_58;
            u32 corner5 = flip ? 1 : 3;
            u32 corner4 = flip ? 3 : 1;
            u32 corner2 = flip ? 1 : 2;
            u32 corner1 = flip ? 2 : 1;
            for (s32 k = 0; k < quads; k++) {
                u32* quad = &indices[k * 6];
                u32 first = k * 4;
                quad[0] = first;
                quad[1] = corner1 + first;
                quad[2] = corner2 + first;
                quad[3] = first + 2;
                quad[4] = corner4 + first;
                quad[5] = corner5 + first;
            }
            field_20->vf69(indexSize, 1, 0x2a, 0x800, &field_418[i], 0, indices);
            Unk_FreeArray(indices);
            u64 vertexSize = vertexCount * sizeof(Unk_Float4);
#line 3715
            Unk_Float4* vertices = reinterpret_cast<Unk_Float4*>(UNK_NEW_ARRAY(u8, vertexSize));
#line 3720
            u8* mask = UNK_NEW_ARRAY(u8, quads);
            memset(mask, 0, quads);
            for (s32 y = 0; y < height / 2; y++) {
                for (s32 x = 0; x < width / 2; x++) {
                    mask[y * 2 * width + x * 2] = 1;
                }
            }
            u32 width2 = Unk_40f610(width, true, 32);
            u32 height2 = Unk_40f610(height, true, 32);
            u32 count = height2 * width2;
            u32 bitsX = static_cast<u32>(logf(static_cast<f32>(width2)) / 0.6931472f);
            u32 bitsY = static_cast<u32>(logf(static_cast<f32>(height2)) / 0.6931472f);
            for (s64 index = 0; index != count; index++) {
                // the texel of the index along a Morton curve (the bits of
                // the longer side last)
                s32 x = 0;
                s32 y = 0;
                u32 xBits = 0;
                u32 yBits = 0;
                s32 axis = 0;
                for (s64 bit = 0; bit < bitsX + bitsY; bit++) {
                    s32 value = (index >> bit) & 1;
                    if (axis == 0) {
                        x |= value << xBits;
                        xBits++;
                        if (yBits < bitsY) {
                            axis = 1;
                        }
                    } else {
                        y |= value << yBits;
                        yBits++;
                        if (xBits < bitsX) {
                            axis = 0;
                        }
                    }
                }
                if (static_cast<u32>(x) < static_cast<u32>(width) && static_cast<u32>(y) < static_cast<u32>(height)) {
                    s32 texel = y * width + x;
                    f32 sign = mask[texel] == 0 ? 1.0f : -1.0f;
                    f32 u = (static_cast<f32>(x) + 1.0f) * sign;
                    f32 v = (static_cast<f32>(y) + 1.0f) * sign;
                    Unk_Float2 corners[4];
                    corners[0] = Unk_Float2(-1.0f, -1.0f);
                    corners[1] = Unk_Float2(-1.0f, 1.0f);
                    corners[2] = Unk_Float2(1.0f, -1.0f);
                    corners[3] = Unk_Float2(1.0f, 1.0f);
                    for (u32 j = 0; j < 4; j++) {
                        vertices[texel * 4 + j] = Unk_Float4(u, v, corners[j].field_0[0], corners[j].field_0[1]);
                    }
                }
            }
            field_20->vf68(vertexSize, 1, 0x800, &field_410[i], 0, vertices);
            Unk_FreeArray(vertices);
            Unk_FreeArray(mask);
        }
    }
    // the eclipse texture
    if (field_c0.field_6d) {
        result = field_20->vf60(256, 256, 7, 0, 0x1c, 0, 0, &field_3a0, 4);
        if (result < 0) {
#line 4047
            PPFX_ERROR("CDepthOfField::CreateDeviceResources(): m_pGPUDevice->CreateTexture(&m_pGPUScatterEclipseTexture) failed (0x%x: %s).\n", result, Unk_446df0(result));
        }
        u32 bpp = Unk_446ae0(0x1c);
#line 4061
        u32* image = UNK_NEW_ARRAY(u32, 0x10000);
        f32 params[2] = {32.0f, 0.125f};
        Unk_Float2 size(0.00390625f, 0.00390625f);
        for (u32 y = 0; y < 256; y++) {
            f32 v = (static_cast<f32>(y) + 0.5f) * 0.00390625f;
            u8* row = reinterpret_cast<u8*>(image) + bpp * 256 * y;
            for (u32 x = 0; x < 256; x++) {
                Unk_Float2 position((static_cast<f32>(x) + 0.5f) * 0.00390625f, v);
                Unk_Float4 color;
                Unk_461f20(&color, &position, &size, params);
                *reinterpret_cast<u32*>(row + x * bpp) = Unk_PackABGR(color);
            }
        }
        Unk_462330(static_cast<IGPUTexture*>(field_3a0), image, true, false, nullptr, 1.0f);
        static_cast<IGPUTexture*>(field_3a0)->vf15(3);
        Unk_FreeArray(image);
    }
    // the scatter textures
    if (field_c0.field_6d) {
        const u8* images[6] = {Unk_1eda4bc, Unk_1ee24bc, Unk_1ec24bc, Unk_1eca4bc, Unk_1ed24bc, Unk_1eba4bc};
        field_2c0 = 6;
#line 4280
        field_2c8 = UNK_NEW_ARRAY(IGPUInterface*, field_2c0);
        field_2d0 = UNK_NEW_ARRAY(Unk_GPUTexture*, field_2c0);
        field_2d8 = UNK_NEW_ARRAY(Unk_Float4, field_2c0);
        field_2e0 = UNK_NEW_ARRAY(f32, field_2c0);
        field_2e8 = UNK_NEW_ARRAY(f32, field_2c0);
        for (s32 i = 0; i < field_2c0; i++) {
            CreateScatterBokehOpticsTexture(128, 64, images[i], reinterpret_cast<IGPUTexture**>(&field_2c8[i]),
                                            reinterpret_cast<IGPUTexture**>(&field_2d0[i]), &field_2d8[i],
                                            reinterpret_cast<Unk_Float*>(&field_2e0[i]), &field_2e8[i], 2.0f,
                                            field_c0.field_88, field_c0.field_8c, field_c0.field_90);
        }
    }
    // the bokeh tables: for each of four shapes, a texture of each of
    // field_2f0 sizes and a smaller one, and their apertures
    if (field_c0.field_6d) {
        const f32 exponents[4] = {0.0f, 0.75f, 1.75f, 3.0f};
        field_2f0 = 4;
#line 4337
        field_398 = UNK_NEW_ARRAY(f32, field_2f0);
        for (s32 s = 0; s < 4; s++) {
#line 4341
            field_2f8[s] = UNK_NEW_ARRAY(IGPUInterface*, field_2f0);
            field_318[s] = UNK_NEW_ARRAY(IGPUInterface*, field_2f0);
            field_338[s] = UNK_NEW_ARRAY(f32, field_2f0);
            field_358[s] = UNK_NEW_ARRAY(f32, field_2f0);
            field_378[s] = UNK_NEW_ARRAY(Unk_462090_Params, field_2f0);
            f32 bladeCurve = field_c0.field_7c;
            f32 bladeSplit = field_c0.field_80;
#line 4407
            u32** images = UNK_NEW_ARRAY(u32*, field_2f0);
            for (s32 j = 0; j < field_2f0; j++) {
#line 4411
                images[j] = UNK_NEW_ARRAY(u32, 0x4000);
            }
            for (s32 i = field_2f0 - 1; i >= 0; i--) {
                s32 count = field_2f0;
                s32 next = std::min(i + 1, count - 1);
                field_2f8[s][i] = nullptr;
                field_318[s][i] = nullptr;
                field_398[i] = exp2f(exponents[i]);
                result = field_20->vf60(128, 128, 6, 0, 0x1c, 0, 0,
                                        &field_2f8[s][i], 4);
                if (result < 0) {
#line 4436
                    PPFX_ERROR("CDepthOfField::CreateDeviceResources(): m_pGPUDevice->CreateTexture(&m_aapGPUScatterBokehLutTexture[s][i]) failed (0x%x: %s).\n", result, Unk_446df0(result));
                }
                u32 size = Unk_Pow2(static_cast<u32>(sqrtf(static_cast<f32>(Unk_RingPoints) * 1.2732395f)));
                result = field_20->vf60(size, size, 1, 0, 0x1c, 0, 0,
                                        &field_318[s][i], 4);
                if (result < 0) {
#line 4457
                    PPFX_ERROR("CDepthOfField::CreateDeviceResources(): m_pGPUDevice->CreateTexture(&m_aapGPUScatterBokehLutMinTexture[s][i]) failed (0x%x: %s).\n", result, Unk_446df0(result));
                    return result;
                }
                u32 bpp = Unk_446ae0(0x1c);
                u8* image = reinterpret_cast<u8*>(images[i]);
                u8* nextImage = reinterpret_cast<u8*>(images[next]);
                Unk_462090_Params* params = &field_378[s][i];
                params->field_0 = s + 5;
                f32 position = static_cast<f32>(i) + 0.7499999f;
                params->field_8 = expf(position * position / -4.5918365f);
                if (i == 0) {
                    params->field_8 = 1.0f;
                } else if (i + 1 == field_2f0) {
                    params->field_8 = params->field_8 * 0.1f;
                }
                params->field_c = bladeCurve;
                params->field_10 = bladeSplit;
                params->field_4 = 360.0f / static_cast<f32>(params->field_0) * 0.5f * 3.1415927f / 180.0f;
                Unk_Float2 area(0.0078125f, 0.0078125f);
                u32 covered = 0;
                for (u32 y = 0; y < 128; y++) {
                    f32 v = (static_cast<f32>(y) + 0.5f) * 0.0078125f;
                    u8* row = image + bpp * 128 * y;
                    u8* nextRow = nextImage + bpp * 128 * y;
                    for (u32 x = 0; x < 128; x++) {
                        Unk_Float2 point((static_cast<f32>(x) + 0.5f) * 0.0078125f, v);
                        Unk_Float4 color;
                        Unk_462090(&color, &point, &area, params);
                        covered += color.field_0[0].field_0 > 0.0f || color.field_0[1].field_0 > 0.0f ||
                                   color.field_0[2].field_0 > 0.0f;
                        u32 pixel = Unk_PackABGR(color);
                        if (i + 1 < count) {
                            pixel = (pixel & 0xffff00ff) | ((*reinterpret_cast<u32*>(nextRow + x * bpp) & 0xff) << 8);
                        }
                        *reinterpret_cast<u32*>(row + x * bpp) = pixel;
                    }
                }
                field_338[s][i] = params->field_14;
                field_358[s][i] = static_cast<f32>(covered / 16384.0);
                u8** levels = nullptr;
                Unk_462330(static_cast<IGPUTexture*>(field_2f8[s][i]), image, false, false, &levels, 1.0f);
                u32 level = static_cast<u32>(logf(128.0f / static_cast<f32>(size)) / 0.6931472f);
                static_cast<IGPUTexture*>(field_318[s][i])->vf9(levels[level], 0, 0, true);
                for (s32 k = 0; k < 6; k++) {
                    Unk_FreeArray(levels[k]);
                }
                UNK_DELETE_ARRAY(levels);
                static_cast<IGPUTexture*>(field_2f8[s][i])->vf15(3);
                static_cast<IGPUTexture*>(field_318[s][i])->vf15(3);
            }
            for (s32 j = 0; j < field_2f0; j++) {
                Unk_FreeArray(images[j]);
            }
            UNK_DELETE_ARRAY(images);
        }
    }
    field_240 = false;
    return 0;
}

}  // namespace PPFX
