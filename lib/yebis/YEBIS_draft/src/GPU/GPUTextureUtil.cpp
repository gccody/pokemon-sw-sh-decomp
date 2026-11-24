// Scope: common
// PPFX::TEXSHADERSET, the shader set of YEBIS's texture utilities
// (C:/workspace/YEBIS_draft/src/GPU/GPUTextureUtil.cpp, the __FILE__ of its log
// lines and allocations). The class and CreateEffect are named by the log
// lines ("TEXSHADERSET::CreateEffect(): IGPUEffect::CreateEffectFromFile() ..."),
// which leave the namespace out as they do for PPFX::IGPUEffect; everything
// else is a placeholder. CreateEffect's body is the list of the effect's
// parameters and techniques: field_<offset> is where each handle goes.
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <miniz/miniz_yebis.h>
#include <types.h>
#include <yebis/YEBIS_draft/src/GPU/GPUTextureUtil.h>
#include <yebis/YEBIS_draft/src/GPU/GPUGlareDef.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceTexture.h>
#include <yebis/YEBIS_draft/src/GPU/GPURenderTextureArray.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_410f90.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>
#include <yebis/YEBIS_draft/src/Unk_415f40.h>
#include <yebis/YEBIS_draft/src/GPU/TinyEffect/TFXString.h>

// the device's blend switches 0x71004797a0 sets (IGPUDevice's,
// lib/yebis/leaf/Unk_43dc00.cpp: they do nothing)
u32 Unk_440c40_get(u64 device, u32 arg);
u32 Unk_440c60_get(u64 device, u32 arg1, u32 arg2);
u32 Unk_440c80_get(u64 device, f32 r, f32 g, f32 b, f32 a);

extern "C" int mz_uncompress(unsigned char* pDest, unsigned long* pDest_len, const unsigned char* pSource,
                             unsigned long source_len);

// log switches: all messages, PPFX_ERROR's and PPFX_LOG's
extern s32 Unk_238c1e0;
extern s32 Unk_238c1e8;
extern s32 Unk_24e0008;
// the effect file, compressed: its size, then miniz's stream
extern const u8 Unk_1b61595[];

// 0x7101b3516c: "CTextureUtil"
extern const char Unk_1b3516c[];

// 0x7100417a30: printf to the log
s32 Unk_417a30(const char* format, ...);
// 0x7100446df0: an error code's name
const char* Unk_446df0(s32 result);

#define PPFX_LOG(...)                                                                                 \
    do {                                                                                              \
        if (Unk_238c1e0 != 0 && Unk_24e0008 != 0) {                                                   \
            Unk_417a30("C:/workspace/YEBIS_draft/src/GPU/GPUTextureUtil.cpp(%d) : PPFX: ", __LINE__); \
            Unk_417a30(__VA_ARGS__);                                                                  \
        }                                                                                             \
    } while (0)
#define PPFX_ERROR(...)                                                                                     \
    do {                                                                                                    \
        if (Unk_238c1e0 != 0 && Unk_238c1e8 != 0) {                                                         \
            Unk_417a30("C:/workspace/YEBIS_draft/src/GPU/GPUTextureUtil.cpp(%d) : PPFX ERROR: ", __LINE__); \
            Unk_417a30(__VA_ARGS__);                                                                        \
        }                                                                                                   \
    } while (0)

namespace PPFX {

// the bokeh kernels' sample counts
static const s32 Unk_1b35158[5] = {7, 19, 37, 61, 91};

// 0x71024e4a18 and 0x71024e4c18: the DrawRectGPU functions' scratch
// vectors, written just before the effect reads them. Their sizes matter: the
// compiler folds an element's constant offset into the address it
// materialises only when it is inside the object.
//
// They and the TU's other internal statics (the helpers' suffix tables and
// flags, the function-local statics of 0x7100478890, 0x710047c8d0,
// 0x7100487670, 0x710048c1b0 and Unk_HexagonOffsets, Unk_Statics.h's) are
// one object in the executable (0x71024e45d0, `.L_MergedGlobals`): LLVM's
// GlobalMerge sorted the zero-initialised ones by size, stably, in module
// order, after GlobalOpt had shrunk each flag (a static bool only ever set to
// true) to one bit and split the ones only accessed at constant indices into
// scalars appended at the module's end. What it gives (worked out from the
// static initialiser 0x7100499b70 and the users):
//   +0x000  1-byte flags: 0x7100462fe0, 463500, 463750, 463980, 463a70,
//           48c1b0 and Unk_HexagonOffsets (emitted last, with its users)
//   +0x008  Unk_Statics.h's angle, then 4-byte statics: 0x7100478890's and
//           0x710047c8d0's four generator seeds each, 48c1b0's xorshift state
//           (16 bytes, split into four)
//   +0x03c  Unk_Statics.h's 24 white points, then (+0x100) the guards:
//           478890's four, 47c8d0's four, 487670's, 48c1b0's two,
//           Unk_HexagonOffsets', then 463750's, 463980's and 463a70's suffix
//           tables split into pointers (their loops are fully unrolled)
//   +0x1e0  0x7100487670's Unk_Float4(1, 1, 1, 1)
//   +0x1f0  Unk_StaticsBase.h's two colour spaces, +0x230 the hexagon
//           offsets (Unk_Float4[7]), +0x2a0 the reflection handle
//   +0x318  463500's and 462fe0's tables, +0x448 and +0x648 these two
// 48c1b0's Unk_Float4[6][64] (0x71024e2dd0) is too large to be merged. So the
// order of the functions in this file and of their statics decides the
// offsets every user of the block has.
static Unk_Float4 Unk_24e4a18[32];
static Unk_Float4 Unk_24e4c18[32];

// 0x7100461d60: the type a depth format is read as (named by its log line)
s32 FXDCT_GetDepthCastTypeFromDepthFormat(s32 format) {
    switch (format) {
    case 20:
    case 21:
    case 40:
    case 41:
    case 45:
    case 46:
    case 55:
    case 56:
        return 0;
    default:
#line 421
        PPFX_ERROR("FXDCT_GetDepthCastTypeFromDepthFormat(): eDepthFormat: 0x%x.\n", format);
        return -1;
    }
}

// a square root that gives 0 and 1 as they are
inline f32 Unk_Sqrt(f32 value) {
    if (value == 0.0f || value == 1.0f) {
        return value;
    }
    return sqrtf(value);
}

// a position's distance from the centre of the area `size` leaves around it,
// as -1 to 1 in each direction
inline f32 Unk_Coord(const f32& position, const f32& size) {
    f32 scale = 1.0f / size;
    f32 half = size * 0.5f;
    return scale * (position - half) / (scale - 1.0f) * 2.0f - 1.0f;
}
inline f32 Unk_Distance(const Unk_Float2* position, const Unk_Float2* size) {
    f32 x = Unk_Coord(position->field_0[0].field_0, size->field_0[0].field_0);
    f32 y = Unk_Coord(position->field_0[1].field_0, size->field_0[1].field_0);
    return Unk_Sqrt(x * x + y * y);
}

// 0x7100461e00: 1 inside `inner`, falling to 0 at the edge
void Unk_461e00(Unk_Float4* out, const Unk_Float2* position, const Unk_Float2* size, const f32* inner) {
    Unk_Float value;
    if (size->field_0[0].field_0 >= 1.0f || size->field_0[1].field_0 >= 1.0f) {
        value = 0.0f;
    } else {
        f32 distance = Unk_Distance(position, size);
        if (!(distance > *inner)) {
            value = 1.0f;
        } else if (distance < 1.0f) {
            value = (1.0f - distance) / (1.0f - *inner);
        } else {
            value = 0.0f;
        }
    }
    *out = Unk_Float4(value, value, value, value);
}

// 0x7100461f20: a cosine falloff to the edge, faded out from 0.8 on
// NON_MATCHING: two registers of the cosine's argument are exchanged (s1/s4).
void Unk_461f20(Unk_Float4* out, const Unk_Float2* position, const Unk_Float2* size, const f32* params) {
    f32 distance = Unk_Distance(position, size);
    f32 value;
    if (distance >= 1.0f) {
        value = 0.0f;
    } else {
        value = (cosf(distance * 3.14159274f * params[0] + 3.14159274f) * params[1] + 1.0f) * 0.5f;
    }
    if (distance > 0.8f) {
        f32 fade = 0.0f;
        if (distance < 1.0f) {
            f32 t = (1.0f - distance) / (1.0f - 0.8f);
            f32 s = sinf(t * 3.14159274f);
            fade = t + s * s * 1.1f;
        }
        value *= fade;
    }
    Unk_Float element = value;
    *out = Unk_Float4(element, element, element, element);
}

// what 0x7100462090 reads (and writes field_14 of): an aperture's blades
struct Unk_462090_Params {
    s32 field_0;  // the number of blades
    f32 field_4;  // their rotation
    f32 field_8;
    f32 field_c;
    f32 field_10;
    f32 field_14;  // set: the cosine of half a blade's angle
};
PKMN_SIZE_ASSERT(Unk_462090_Params, 0x18);

// 0x7100462090: a polygonal aperture's falloff
// NON_MATCHING: as 0x7100461e00, the second coordinate's `scale - 1` is
// computed before its product here; and the blade count's reload takes s3
// for s1. The instructions are otherwise the original's.
void Unk_462090(Unk_Float4* out, const Unk_Float2* position, const Unk_Float2* size, Unk_462090_Params* params) {
    f32 x = Unk_Coord(position->field_0[0].field_0, size->field_0[0].field_0);
    f32 y = Unk_Coord(position->field_0[1].field_0, size->field_0[1].field_0);
    f32 distance = Unk_Sqrt(x * x + y * y);
    f32 sector = 6.28318548f / static_cast<f32>(params->field_0);
    f32 half = sector * 0.5f;
    f32 edge = cosf(half);
    f32 angle = atan2f(y, x) - params->field_4 + 1.57079637f;
    if (angle > 6.28318548f) {
        angle = angle - static_cast<f32>(static_cast<s32>(angle / 6.28318548f)) * 6.28318548f;
    } else if (angle < 0.0f) {
        angle = angle - static_cast<f32>(static_cast<s32>(angle / 6.28318548f)) * 6.28318548f + 6.28318548f;
    }
    f32 t = angle / sector;
    f32 frac = t - floorf(t);
    f32 d = sector * frac - half;
    f32 scale = edge / cosf(d > 0.0f ? d : -d);
    f32 split = params->field_c < 0.0f ? 1.0f - params->field_10 : params->field_10;
    f32 wave;
    if (frac < split) {
        wave = powf(sinf(frac / split * 3.14159274f), 0.75f);
    } else {
        f32 rest = 1.0f - split;
        wave = -(powf(-sinf(((1.0f / rest) * (frac - split) + 1.0f) * 3.14159274f), 0.75f) * (rest / split));
    }
    f32 curve = params->field_8 * (params->field_c * (wave / static_cast<f32>(params->field_0)));
    f32 q = scale * (sinf(params->field_8 * 3.14159274f) * curve + 1.0f);
    f32 radius = q + (1.0f - q) * params->field_8;
    f32 ratio = distance / radius;
    f32 value = 1.0f - (distance + ratio * (ratio - distance));
    params->field_14 = edge;
    *out = Unk_Float4(value, value, value, value > 0.0f ? 1.0f : 0.0f);
}

// 0x71004622e0: whether a value that changed from `previous` to `current`
// (both positive) is to be taken, given the range from `low` to `high`
bool Unk_4622e0(f32 low, f32 high, f32 current, f32 previous) {
    if (previous <= 0.0f || current <= 0.0f || previous == current) {
        return false;
    }
    if (current <= low && current > previous) {
        return false;
    }
    if (previous > current && current >= high) {
        return false;
    }
    return true;
}

// 0x7100446a90, 0x7100446ae0 (Unk_447050.cpp): a level's size, a format's
// bytes per pixel
u32 Unk_446a90(u32 size, u32 level);
u32 Unk_446ae0(s32 format);

// 0x7100462330: a texture's levels from an image, each next one the average of
// 2x2 of the one before (with a 4x4 ordered dither: `arg2` for the colour,
// `arg3` for the alpha, where the level is larger than 3), set into the
// texture; `levels`, if any, gets them, else they are deleted (`arg5` is not
// read)
// NON_MATCHING: registers and scheduling of the 2x2 loops (the original keeps
// the colour dither flag and the level sizes on the stack and steps x as 2x
// and x); the loops are unswitched on the colour dither as the original's
s32 Unk_462330(IGPUBaseTexture* texture, const void* data, bool arg2, bool arg3, u8*** levels, f32 arg5) {
    u32 width = texture->field_44.field_8;
    u32 height = texture->field_44.field_c;
    u32 bpp = Unk_446ae0(texture->field_44.field_0);
    u32 count = texture->vf12();
#line 871
    u8** images = UNK_NEW_ARRAY(u8*, count);
    // a 4x4 ordered dither, in quarters of a step
    f32 dither[4][4];
    dither[0][0] = 0.0f; dither[0][1] = 2.0f; dither[0][2] = 0.5f; dither[0][3] = 2.5f;
    dither[1][0] = 3.0f; dither[1][1] = 1.0f; dither[1][2] = 3.5f; dither[1][3] = 1.5f;
    dither[2][0] = 0.75f; dither[2][1] = 2.75f; dither[2][2] = 0.25f; dither[2][3] = 2.25f;
    dither[3][0] = 3.75f; dither[3][1] = 1.75f; dither[3][2] = 3.25f; dither[3][3] = 1.25f;
    for (u32 level = 0; level < count; level++) {
        s32 previous = level == 0 ? 0 : level - 1;
        u32 levelWidth = Unk_446a90(width, level);
        u32 levelHeight = Unk_446a90(height, level);
        u32 previousWidth = Unk_446a90(width, previous);
        u32 previousHeight = Unk_446a90(height, previous);
        u32 levelStride = levelWidth * bpp;
#line 905
        images[level] = UNK_NEW_ARRAY(u8, levelStride * levelHeight);
        if (level == 0) {
            memcpy(images[level], data, width * height * bpp);
        } else {
            u32 largest = levelWidth > levelHeight ? levelWidth : levelHeight;
            bool ditherColor = arg2 && largest > 3;
            bool ditherAlpha = arg3 && largest > 3;
            u32 previousStride = previousWidth * bpp;
            for (u32 y = 0; y < levelHeight; y++) {
                u32 y0 = previousHeight > levelHeight ? 2 * y : y;
                u32 y1 = previousHeight > levelHeight ? 2 * y + 1 : y;
                for (u32 x = 0; x < levelWidth; x++) {
                    u32 x0 = previousWidth > levelWidth ? 2 * x : x;
                    u32 x1 = previousWidth > levelWidth ? 2 * x + 1 : x;
                    u8* source = images[previous];
                    u8* p00 = source + y0 * previousStride + x0 * bpp;
                    u8* p01 = source + y0 * previousStride + x1 * bpp;
                    u8* p10 = source + y1 * previousStride + x0 * bpp;
                    u8* p11 = source + y1 * previousStride + x1 * bpp;
                    u8* out = images[level] + y * levelStride + x * bpp;
                    f32 dc = ditherColor ? dither[x & 3][y & 3] : 2.0f;
                    f32 da = ditherAlpha ? dither[x & 3][y & 3] : 2.0f;
                    s32 c0 = p00[0] + p01[0] + p10[0] + p11[0];
                    s32 c1 = p00[1] + p01[1] + p10[1] + p11[1];
                    s32 c2 = p00[2] + p01[2] + p10[2] + p11[2];
                    s32 c3 = p00[3] + p01[3] + p10[3] + p11[3];
                    out[0] = static_cast<s32>((dc + static_cast<f32>(c0)) * 0.25f);
                    out[1] = static_cast<s32>((dc + static_cast<f32>(c1)) * 0.25f);
                    out[2] = static_cast<s32>((dc + static_cast<f32>(c2)) * 0.25f);
                    out[3] = static_cast<s32>((da + static_cast<f32>(c3)) * 0.25f);
                }
            }
        }
    }
    s32 result = 0;
    for (u32 level = 0; level < count; level++) {
        result = texture->vf9(images[level], level, 0, true);
    }
    if (levels != nullptr) {
        *levels = images;
    } else {
        for (u32 level = 0; level < count; level++) {
            UNK_DELETE_ARRAY(images[level]);
        }
        UNK_DELETE_ARRAY(images);
    }
    return result;
}

// 0x71004628f0: the rotation of a matrix as a quaternion
Unk_Float4* Unk_4628f0(Unk_Float4* out, const MATRIXT44* matrix) {
    const f32(*m)[4] = matrix->field_0;
    f32 trace = m[0][0] + m[1][1] + m[2][2] + 1.0f;
    if (trace >= 1.0f) {
        f32 s = sqrtf(trace);
        f32 f = 0.5f / s;
        out->field_0[0].field_0 = (m[1][2] - m[2][1]) * f;
        out->field_0[1].field_0 = (m[2][0] - m[0][2]) * f;
        out->field_0[2].field_0 = (m[0][1] - m[1][0]) * f;
        out->field_0[3].field_0 = 0.25f / f;
        return out;
    }
    const f32* max = m[2][3] > m[2][2] ? &m[1][1] : &m[2][2];
    if (*max < m[0][0]) {
        f32 s = sqrtf(m[0][0] - (m[1][1] + m[2][2]) + 1.0f);
        f32 half = s * 0.5f;
        f32 f = 0.5f / s;
        out->field_0[0].field_0 = half;
        out->field_0[1].field_0 = (m[0][1] + m[1][0]) * f;
        out->field_0[2].field_0 = (m[2][0] + m[0][2]) * f;
        out->field_0[3].field_0 = (m[1][2] - m[2][1]) * f;
    } else if (*max == m[1][1]) {
        f32 s = sqrtf(m[1][1] - (m[0][0] + m[2][2]) + 1.0f);
        f32 half = s * 0.5f;
        f32 f = 0.5f / s;
        out->field_0[0].field_0 = (m[0][1] + m[1][0]) * f;
        out->field_0[1].field_0 = half;
        out->field_0[2].field_0 = (m[1][2] + m[2][1]) * f;
        out->field_0[3].field_0 = (m[2][0] - m[0][2]) * f;
    } else {
        f32 s = sqrtf(m[2][2] - (m[0][0] + m[1][1]) + 1.0f);
        f32 half = s * 0.5f;
        f32 f = 0.5f / s;
        out->field_0[0].field_0 = (m[2][0] + m[0][2]) * f;
        out->field_0[1].field_0 = (m[1][2] + m[2][1]) * f;
        out->field_0[2].field_0 = half;
        out->field_0[3].field_0 = (m[0][1] - m[1][0]) * f;
    }
    return out;
}

// clamped to 0 to 1 (inline)
static inline f32 Unk_Saturate(f32 x) {
    if (x < 0.0f) {
        return 0.0f;
    }
    return x > 1.0f ? 1.0f : x;
}

// 0x7100462af0: the tone curve `mode` at `x` (with `params` from Unk_47ba90),
// clamped to 0 to 1 except for mode 0
f32 Unk_462af0(s32 mode, const f32* params, bool flag, f32 x) {
    f32 value = mode != 0 && flag ? fmaxf(x, 5.96046448e-08f) : x;
    f32 result = 0.0f;
    switch (mode) {
    case 0:
    case 1:
        result = value;
        break;
    case 2: {
        f32 a = value * params[1];
        result = a * (a * params[2] + 1.0f) / (a + 1.0f);
        break;
    }
    case 4: {
        f32 a = value * params[1];
        result = a * (a * params[2] + 1.0f) / (a + 1.0f);
        break;
    }
    case 6:
        result = Unk_Saturate(logf(value * params[2] + 1.0f) * params[1]);
        break;
    case 8:
        result = Unk_Saturate(logf(value * params[2] + 1.0f) * params[1]);
        break;
    case 10: {
        f32 e = 1.0f - expf(-(value * params[0]));
        f32 t = (e - 1.0f) * params[1] + 1.0f;
        result = t * (e * t);
        break;
    }
    }
    if (mode != 0) {
        if (result < 0.0f) {
            return 0.0f;
        }
        return result > 1.0f ? 1.0f : result;
    }
    return result;
}

// the tone curve a mode is a variant of (inline)
static inline s32 Unk_BaseMode(s32 mode) {
    if (mode == 12 || mode == 13) {
        return 2;
    }
    if (mode == 7) {
        return 6;
    }
    if (mode == 9) {
        return 8;
    }
    return mode;
}

// whether tone curve `mode` is a logarithmic one (inline)
static inline bool Unk_IsLogMode(s32 mode) {
    s32 base = Unk_BaseMode(mode);
    return base == 8 || base == 6;
}

// 0x7100462c30: the inverse of tone curve `mode` at `x`, for the range
// `value` / `scale` (kept to 1.01 to 4096 for the logarithmic curves)
// NON_MATCHING: the tests of the mode: LLVM folds the two logarithmic tests
// into one range test (`mode - 6 <= 3`) here; the original keeps the mapping
// of the variants (12/13 to 2 as a select, 7 to 6, 9 to 8) and the two
// tests, and threads the final switch into a bit test (0xb828) and two jump
// tables (932 bytes against 640). The mapping as a switch, a conditional
// and an if-chain, and computed once, were tried.
f32 Unk_462c30(s32 mode, f32 x, f32 value, f32 scale) {
    if (Unk_IsLogMode(mode)) {
        f32 ratio = value / scale;
        if (ratio < 1.01f || ratio > 4096.0f) {
            f32 clamped = ratio < 1.01f ? 1.01f : (ratio > 4096.0f ? 4096.0f : ratio);
            scale = value / clamped;
        }
    }
    if (Unk_IsLogMode(mode)) {
        f32 ratio = value / scale;
        if (ratio < 1.01f || ratio > 4096.0f) {
            f32 clamped = ratio < 1.01f ? 1.01f : (ratio > 4096.0f ? 4096.0f : ratio);
            scale = value / clamped;
        }
    }
    switch (mode) {
    case 2:
    case 3:
    case 4:
    case 5: {
        f32 t = Unk_Saturate(x);
        f32 ratio = value / scale;
        f32 square = ratio * ratio;
        f32 root = sqrtf(t * (t + 4.0f / square - 2.0f) + 1.0f);
        return fmaxf(square * (scale * (t + root - 1.0f)) * 0.5f, 0.0f);
    }
    case 6:
    case 7:
    case 8:
    case 9: {
        f32 t = Unk_Saturate(x);
        f32 ratio = fmaxf(value / scale, 1.0f);
        f32 y;
        if (ratio <= 1.0f) {
            y = 0.0f;
        } else {
            s32 count;
            if (ratio >= 10.0f) {
                count = 5;
            } else if (ratio >= 1.7f) {
                count = 10;
            } else if (ratio >= 1.5f) {
                count = 20;
            } else if (ratio >= 1.1f) {
                count = 100;
            } else {
                count = 0;
            }
            if (count != 0) {
                y = 1.0f;
                for (s32 i = 0; i < count; i++) {
                    y = logf(ratio * y + 1.0f);
                }
            } else {
                f32 y0 = 0.0f;
                f32 y1 = 1.0f;
                for (s32 i = 0; i < 100; i++) {
                    y1 = logf(y1 * 1.1f + 1.0f);
                }
                y = y0 + (ratio - 1.0f) * (y1 - y0);
            }
        }
        return fmaxf((expf(t * y) - 1.0f) * value / (expf(y) - 1.0f), 0.0f);
    }
    case 10:
    case 11:
    case 13: {
        f32 r = -logf(1.0f - Unk_Saturate(x));
        return (r > 0.0f ? r : 0.0f) * scale;
    }
    case 14:
    case 15:
        return x * scale;
    default:
        return x;
    }
}

// 0x7101b350ac: a table Unk_47ba90 and Unk_47bf10 interpolate in steps of 0.05
static const f32 Unk_1b350ac[21] = {
    0.0f,   0.0f,   0.0f,   0.0f,   0.0f,   0.0f,   0.0f,   0.15f,  0.215f, 0.281f, 0.335f,
    0.375f, 0.421f, 0.465f, 0.489f, 0.518f, 0.545f, 0.567f, 0.587f, 0.609f, 0.626f,
};

// Unk_1b350ac at `x` (0 to 1) (inline)
static inline f32 Unk_Interpolate(f32 x) {
    f32 position = x / 0.05f;
    s32 index = static_cast<s32>(floorf(position));
    s32 next = index + 1 < 20 ? index + 1 : 20;
    f32 frac = position - index;
    return Unk_1b350ac[index] + (Unk_1b350ac[next] - Unk_1b350ac[index]) * frac;
}

// 0x710047ba90: the parameters of tone curve `mode` for the range `value` /
// `scale` (the vector of Unk_470610's three the curve reads)
// NON_MATCHING: the tests of the mode before the clamps, as in Unk_462c30 (LLVM
// folds them into one range test here; the original threads them into bit
// tests 0xb828/0x280): 852 bytes against 1152. From the ratio on it is the
// original's code. The original calls expf(-ratio) and drops the result.
Unk_Float4 CTextureUtil::Unk_47ba90(s32 mode, const f32* params, f32 value, f32 scale) {
    switch (mode) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        Unk_470610(value, scale);
        break;
    }
    if (Unk_IsLogMode(mode)) {
        f32 ratio = value / scale;
        if (ratio < 1.01f || ratio > 4096.0f) {
            f32 clamped = ratio < 1.01f ? 1.01f : (ratio > 4096.0f ? 4096.0f : ratio);
            scale = value / clamped;
        }
    }
    if (Unk_IsLogMode(mode)) {
        f32 ratio = value / scale;
        if (ratio < 1.01f || ratio > 4096.0f) {
            f32 clamped = ratio < 1.01f ? 1.01f : (ratio > 4096.0f ? 4096.0f : ratio);
            scale = value / clamped;
        }
    }
    f32 ratio = value / scale;
    f32 decay = expf(-ratio);
    Unk_Float4 result(0.0f, 0.0f, 0.0f, 0.0f);
    f32 inverse = 1.0f / scale;
    switch (mode) {
    case 2:
    case 3:
    case 4:
    case 5: {
        f32 square = 1.0f / (ratio * ratio);
        result = Unk_Float4(square * 4.0f - 2.0f, inverse, square, value * value / (scale + scale));
        break;
    }
    case 6:
    case 7:
    case 8:
    case 9: {
        f32 x = fmaxf(ratio < 1.01f ? fmaxf(ratio, 1.01f) : ratio, 1.0f);
        f32 y;
        if (x <= 1.0f) {
            y = 0.0f;
        } else {
            s32 count;
            if (x >= 10.0f) {
                count = 5;
            } else if (x >= 1.7f) {
                count = 10;
            } else if (x >= 1.5f) {
                count = 20;
            } else if (x >= 1.1f) {
                count = 100;
            } else {
                count = 0;
            }
            if (count != 0) {
                y = 1.0f;
                for (s32 i = 0; i < count; i++) {
                    y = logf(x * y + 1.0f);
                }
            } else {
                f32 y0 = 0.0f;
                f32 y1 = 1.0f;
                for (s32 i = 0; i < 100; i++) {
                    y1 = logf(y1 * 1.1f + 1.0f);
                }
                y = y0 + (x - 1.0f) * (y1 - y0);
            }
        }
        result = Unk_Float4(y, 1.0f / y, (expf(y) - 1.0f) / value, value / (expf(y) - 1.0f));
        break;
    }
    case 10:
    case 11:
    case 13: {
        // 0x7101b35100
        static const f32 Unk_1b35100[21] = {
            0.0f,      0.048482f, 0.090533f, 0.127458f,  0.16023f,  0.1896f,   0.217f,
            0.246554f, 0.279004f, 0.3145025f, 0.353307f, 0.395699f, 0.441984f, 0.4927219f,
            0.547603f, 0.6077f,   0.673252f, 0.7447f,   0.822589f, 0.907482f, 1.0f,
        };
        f32 p = powf(*params, 0.333333343f);
        result.field_0[0] = p * 2.0891273f + 1.0f;
        f32 position = Unk_Saturate(p) / 0.05f;
        s32 index = static_cast<s32>(floorf(position));
        s32 next = index + 1 < 20 ? index + 1 : 20;
        f32 frac = position - index;
        result.field_0[1] = Unk_1b35100[index] + (Unk_1b35100[next] - Unk_1b35100[index]) * frac;
        break;
    }
    case 14:
    case 15:
        result.field_0[0] = inverse;
        result.field_0[2] = ratio - 1.0f;
        result.field_0[3] = 1.0f / (ratio - 1.0f);
        break;
    }
    return result;
}

// 0x710047bf10
f32 CTextureUtil::Unk_47bf10(f32 x, f32 white, f32 scale, s32 mode, const f32* params, f32 arg0, f32 arg1,
                             f32 exposure) {
    if (mode == 0) {
        return x;
    }
    Unk_Float4 curve = Unk_47ba90(mode, params, arg0, arg1);
    f32 knee = 0.0f;
    if (mode == 10) {
        knee = Unk_Interpolate(Unk_Saturate(powf(*params, 0.333333343f)));
    }
    f32 limit = white / scale / exposure;
    f32 value = x / exposure;
    f32 low = Unk_462af0(mode, &curve.field_0[0].field_0, false, knee);
    f32 ratio = (limit - low) / (1.0f - low);
    if (value > knee) {
        value = knee + (value - knee) * ((1.0f - knee) / (limit - knee));
    }
    f32 result = Unk_462af0(mode, &curve.field_0[0].field_0, false, value);
    if (result > low) {
        result = low + ratio * (result - low);
    }
    result *= exposure;
    return result * scale;
}

// the knee of tone curve `mode` (inline)
static inline f32 Unk_Knee(s32 mode, const f32* params) {
    f32 knee = 0.0f;
    if (mode == 10) {
        knee = Unk_Interpolate(Unk_Saturate(powf(*params, 0.333333343f)));
    }
    return knee;
}

// 0x710047c090
// NON_MATCHING: the copy of arg1 back to s5 after the knee is made in each of
// the recursive path's blocks here, in the block they share in the original
// (and the blocks after it are laid out one block earlier)
f32 CTextureUtil::Unk_47c090(f32 x, s32 mode, const f32* params, f32 white, f32 limit, f32 count, f32 arg0,
                             f32 arg1, f32 exposure) {
    if (count <= 0.0f) {
        return x;
    }
    f32 n = fminf(count, 16.0f);
    if (mode == 0) {
        return x;
    }
    f32 current;
    f32 knee;
    if (!(n - 1.0f > 0.0f)) {
        current = x;
        knee = Unk_Knee(mode, params);
    } else {
        current = Unk_47c090(x, mode, params, white, limit, ceilf(n - 1.0f), arg0, arg1, exposure);
        if (current == x || current >= limit) {
            return current;
        }
        knee = Unk_Knee(mode, params);
    }
    f32 rounded = n + 0.9999f;
    f32 fraction = rounded - static_cast<s32>(rounded) + 0.0001f;
    f32 base = knee * exposure;
    f32 result = Unk_47bf10(white > x ? white : x, current, 1.0f, mode, params, arg0, arg1, exposure);
    f32 value = base + (current - base) * ((x - base) / (result - base));
    value = value < limit ? value : limit;
    return current + fraction * (value - current);
}

// a value encoded with a colour space's transfer function (inline)
static inline f32 Unk_Encode(s32 encoding, f32 x) {
    switch (encoding) {
    case 6: {
        f32 linear = x * 12.92f;
        f32 curve = powf(fmaxf(x, 1.17549435e-38f), 0.416666657f) * 1.05499995f - 0.0549999997f;
        return fmaxf(x < 0.0031308f ? linear : curve, 0.0f);
    }
    case 7:
    case 8: {
        f32 linear = x * 4.5f;
        f32 curve = powf(fmaxf(x, 1.17549435e-38f), 0.449999988f) * 1.09929681f - 0.0992968231f;
        return fmaxf(x < 0.0180539694f ? linear : curve, 0.0f);
    }
    case 9:
        return powf(fmaxf(x, 1.17549435e-38f), 0.454706937f);
    case 10:
        return powf(fmaxf(x, 1.17549435e-38f), 0.384615391f);
    case 11: {
        f32 linear = x * 16.0f;
        f32 curve = powf(fmaxf(x, 1.17549435e-38f), 0.555555582f);
        return fmaxf(x < 0.001953125f ? linear : curve, 0.0f);
    }
    case 12:
        return powf(fmaxf(x, 1.17549435e-38f), 0.555555582f);
    case 13:
        return powf(fmaxf(x, 1.17549435e-38f), 0.454545438f);
    case 14:
        return powf(fmaxf(x, 1.17549435e-38f), 0.416666657f);
    default:
        return x;
    }
}

// 0x710047c2f0: Unk_47c090 with the white point encoded as `encoding` and
// raised to `gamma` (when `threshold` is over 1), in units of `scale`
// NON_MATCHING: the store of `gamma` and `arg0` to the stack and the copy of
// `mode` are in each other's order (the parameters' positions were searched)
f32 CTextureUtil::Unk_47c2f0(f32 value, f32 base, f32 scale, s32 encoding, f32 exponent, f32 gamma, f32 threshold,
                             f32 count, f32 arg0, s32 mode, const f32* params, f32 arg1, f32 exposure) {
    f32 limit = 1000.0f / scale;
    f32 x = value / scale;
    f32 white = powf(base, exponent);
    if (encoding != -1 && threshold > 1.0f) {
        white = powf(Unk_Encode(encoding, white), gamma);
    }
    return Unk_47c090(x, mode, params, white, limit, count, arg0, arg1, exposure) * scale;
}

// clamped to the smallest normal float, and to 1 with `saturate` (inline)
static inline f32 Unk_Clamp(f32 x, bool saturate) {
    if (saturate) {
        if (x < 1.17549435e-38f) {
            return 1.17549435e-38f;
        }
        return x > 1.0f ? 1.0f : x;
    }
    return fmaxf(x, 1.17549435e-38f);
}

// an argument Unk_47c530 takes and doesn't use (inline)
inline void Unk_Ignore(bool) {}

// 0x710047c530: `*x` encoded with transfer function `encoding` (6 to 14, the
// gamma curves), clamped to 0 to 1 with `saturate`
// each case returns its result this way (written out in each case: as an
// inline function, its two returns become a select)
#define UNK_ENCODED_RETURN(result, saturate) \
    do {                                     \
        if (saturate) {                      \
            if ((result) < 0.0f) {           \
                return 0.0f;                 \
            }                                \
            return (result) > 1.0f ? 1.0f : (result); \
        }                                    \
        return fmaxf((result), 0.0f);        \
    } while (0)
f32 Unk_47c530(const f32* x, s32 encoding, bool flag, bool saturate) {
    Unk_Ignore(flag);
    f32 value = *x;
    switch (encoding) {
    case 6: {
        f32 linear = value * 12.92f;
        f32 curve = powf(Unk_Clamp(value, saturate), 0.416666657f) * 1.05499995f - 0.0549999997f;
        f32 result = *x < 0.0031308f ? linear : curve;
        UNK_ENCODED_RETURN(result, saturate);
    }
    case 7: {
        f32 linear = value * 4.5f;
        f32 curve = powf(Unk_Clamp(value, saturate), 0.449999988f) * 1.09929681f - 0.0992968231f;
        f32 result = *x < 0.0180539694f ? linear : curve;
        UNK_ENCODED_RETURN(result, saturate);
    }
    case 8: {
        f32 linear = value * 4.5f;
        f32 curve = powf(Unk_Clamp(value, saturate), 0.449999988f) * 1.09929681f - 0.0992968231f;
        f32 result = *x < 0.0180539694f ? linear : curve;
        UNK_ENCODED_RETURN(result, saturate);
    }
    case 9:
        return powf(Unk_Clamp(value, saturate), 0.454706937f);
    case 10:
        return powf(Unk_Clamp(value, saturate), 0.384615391f);
    case 11: {
        f32 linear = value * 16.0f;
        f32 curve = powf(Unk_Clamp(value, saturate), 0.555555582f);
        f32 result = *x < 0.001953125f ? linear : curve;
        UNK_ENCODED_RETURN(result, saturate);
    }
    case 12:
        return powf(Unk_Clamp(value, saturate), 0.555555582f);
    case 13:
        return powf(Unk_Clamp(value, saturate), 0.454545438f);
    case 14:
        return powf(Unk_Clamp(value, saturate), 0.416666657f);
    default:
        return value;
    }
}
#undef UNK_ENCODED_RETURN

// whether Unk_47c530 encodes with `encoding` (inline)
inline bool Unk_IsGammaEncoding(s32 encoding) {
    return (encoding >= 6 && encoding <= 14) || encoding == 16;
}

// 0x7100480410: `*x` encoded with transfer function `encoding` (the HDR and
// log curves here, the gamma curves through Unk_47c530), clamped to 0 to 1
f32 Unk_480410(const f32* x, s32 encoding, bool flag) {
    f32 value = *x;
    switch (encoding) {
    case 0:
    case 15:
    case 17: {
        f32 y = powf(fmaxf(value * 0.01f, 1.17549435e-38f), 0.1593017578125f);
        return Unk_Saturate(powf((y * 18.8515625f + 0.8359375f) / (y * 18.6875f + 1.0f), 78.84375f));
    }
    case 1: {
        f32 result = 0.0f;
        if (value > 0.0f) {
            result = value < 1.0f ? sqrtf(value) * 0.5f : logf(value - 0.284668922f) * 0.178832769f + 0.559910715f;
            if (result < 0.0f) {
                return 0.0f;
            }
        }
        return result > 1.0f ? 1.0f : result;
    }
    case 2: {
        f32 t = value / 0.9f;
        f32 linear = t * 5.0f + 0.030001223f;
        f32 curve = logf(t + 0.037584f) / 2.30258512f * 0.432699f + 0.616596f + 0.03f;
        f32 result = (*x < -5.770545e-05f ? linear : curve) * 876.0f + 64.0f;
        return Unk_Saturate(result / 1023.0f);
    }
    case 3: {
        f32 t = value / 0.9f;
        f32 linear = t * 3.5388129f + 0.030001223f;
        f32 curve = logf(t * 0.70776254f + 0.037584f) / 2.30258512f * 0.432699f + 0.646596f;
        f32 result = (*x < -8.153227e-05f ? linear : curve) * 876.0f + 64.0f;
        return Unk_Saturate(result / 1023.0f);
    }
    case 4: {
        f32 linear = value * 76.2103f / 0.01125f + 95.0f;
        f32 curve = logf((value + 0.01f) / 0.19f) / 2.30258512f * 261.5f + 420.0f;
        f32 result = *x < 0.01125f ? linear : curve;
        return Unk_Saturate(result / 1023.0f);
    }
    default:
        if (Unk_IsGammaEncoding(encoding)) {
            return Unk_47c530(x, encoding, flag, true);
        }
        return value;
    }
}

// 0x7100462fe0: the technique `name` for each pair of HDR formats
s32 TEXSHADERSET::Unk_462fe0(s32* techniques, const char* name) {
    static bool initialised = false;
    static const char* suffixes[22];
    if (!initialised) {
        initialised = true;
        suffixes[0] = "";
        suffixes[1] = "_REINHARDRGB_RGB";
        suffixes[2] = "_REINHARDRGB_RGBFAST";
        suffixes[3] = "_RGB_REINHARDRGB";
        suffixes[4] = "_REINHARDRGBLUM_RGB";
        suffixes[5] = "_REINHARDRGBLUM_RGBFAST";
        suffixes[6] = "_RGB_REINHARDRGBLUM";
        suffixes[7] = "_LOGRGB_RGB";
        suffixes[8] = "_LOGRGB_RGBFAST";
        suffixes[9] = "_RGB_LOGRGB";
        suffixes[10] = "_LOGRGBLUM_RGB";
        suffixes[11] = "_LOGRGBLUM_RGBFAST";
        suffixes[12] = "_RGB_LOGRGBLUM";
        suffixes[13] = "_RGBALUM_RGB";
        suffixes[14] = "_RGBALUM_RGBFAST";
        suffixes[15] = "_RGB_RGBALUM";
        suffixes[16] = "_REINHARDRGB_REINHARDRGB";
        suffixes[17] = "_REINHARDRGBLUM_REINHARDRGBLUM";
        suffixes[18] = "_LOGRGB_LOGRGB";
        suffixes[19] = "_LOGRGBLUM_LOGRGBLUM";
        suffixes[20] = "_RGBALUM_RGBALUM";
        suffixes[21] = "_ALPHA_RGB";
    }
    Unk_TFXString text(name);
    s32 length = text.field_0;
    s32 result = 0;
    for (s32 i = 0; i < 22; i++) {
        text.Unk_451530(length);
        text += suffixes[i];
        techniques[i] = field_0->vf15(text.field_8);
        if (techniques[i] == 0)
            result = -1;
        if (techniques[i] != 0 && field_0->vf28(techniques[i]) < 0)
            techniques[i] = 0;
        if (techniques[i] != 0) {
            s32 error = field_0->vf27(techniques[i]);
            if (error < 0)
                result = error;
        }
    }
    return result;
}

// 0x7100463220: the techniques `name` with its last character replaced by 1, 2, ...
s32 TEXSHADERSET::Unk_463220(s32* techniques, const char* name, s32 count) {
    Unk_TFXString prefix(name);
    prefix.Unk_451530(prefix.field_0 - 1);
    s32 result = 0;
    char buffer[1024];
    for (s32 i = 0; i < count; i++) {
        sprintf(buffer, "%s%d", prefix.field_8, i + 1);
        techniques[i] = field_0->vf15(buffer);
        if (techniques[i] != 0 && field_0->vf28(techniques[i]) < 0)
            techniques[i] = 0;
        if (techniques[i] != 0) {
            s32 error = field_0->vf27(techniques[i]);
            if (error < 0)
                result = error;
        }
    }
    return result;
}

// 0x7100463340: the techniques `name` with its last three characters replaced by 0_0 to 7_7
s32 TEXSHADERSET::Unk_463340(s32 (*techniques)[8][22], const char* name) {
    Unk_TFXString prefix(name);
    prefix.Unk_451530(prefix.field_0 - 3);
    char buffer[1024];
    for (s32 i = 0; i < 8; i++) {
        for (s32 j = 0; j < 8; j++) {
            sprintf(buffer, "%s%d_%d", prefix.field_8, i, j);
            Unk_462fe0(techniques[i][j], buffer);
        }
    }
    return 0;
}

// 0x7100463500: the technique `name` for each tone map
s32 TEXSHADERSET::Unk_463500(s32* techniques, const char* name) {
    static bool initialised = false;
    static const char* suffixes[16];
    if (!initialised) {
        initialised = true;
        suffixes[0] = "_LINEAR";
        suffixes[2] = "_REINHARD";
        suffixes[3] = "_REINHARD_PREMAP";
        suffixes[4] = "_REINHARDLUM";
        suffixes[5] = "_REINHARDLUM_PREMAP";
        suffixes[6] = "_LOG";
        suffixes[7] = "_LOG_PREMAP";
        suffixes[8] = "_LOGLUM";
        suffixes[9] = "_LOGLUM_PREMAP";
        suffixes[10] = "";
        suffixes[11] = "_SENSITOMETRIC_PREMAP";
        suffixes[12] = "_REINHARD_LINEARSAT_PREMAP";
        suffixes[13] = "_REINHARD_SENSITOMETRIC_PREMAP";
        suffixes[14] = "_LINEARSAT";
        suffixes[15] = "_ALPHALUM_PREMAP";
        suffixes[1] = "_LINEARSAT";
    }
    Unk_TFXString prefix(name);
    Unk_TFXString text(prefix);
    s32 length = text.field_0;
    s32 result = 0;
    for (s32 i = 0; i < 16; i++) {
        text.Unk_451530(length);
        text += suffixes[i];
        techniques[i] = field_0->vf15(text.field_8);
        if (techniques[i] == 0)
            result = -1;
        if (techniques[i] != 0 && field_0->vf28(techniques[i]) < 0)
            techniques[i] = 0;
        if (techniques[i] != 0) {
            s32 error = field_0->vf27(techniques[i]);
            if (error < 0)
                result = error;
        }
    }
    return result;
}

// 0x7100463750: Unk_462fe0 for each value format
s32 TEXSHADERSET::Unk_463750(s32 (*techniques)[22], const char* name) {
    static bool initialised = false;
    static const char* suffixes[7];
    if (!initialised) {
        initialised = true;
        suffixes[0] = "_RVALUE";
        suffixes[1] = "_GVALUE";
        suffixes[2] = "_BVALUE";
        suffixes[3] = "_AVALUE";
        suffixes[4] = "_RGBA8";
        suffixes[5] = "_ARGB8";
        suffixes[6] = "_ABGR8";
    }
    Unk_TFXString prefix(name);
    s32 result = 0;
    for (s32 i = 0; i < 7; i++) {
        Unk_TFXString full = prefix + suffixes[i];
        s32 error = Unk_462fe0(techniques[i], full.field_8);
        if (error < 0)
            result = error;
    }
    return result;
}

// 0x7100463980: Unk_463750 with and without _USNORM
s32 TEXSHADERSET::Unk_463980(s32 (*techniques)[7][22], const char* name) {
    static bool initialised = false;
    static const char* suffixes[2];
    if (!initialised) {
        initialised = true;
        suffixes[0] = "";
        suffixes[1] = "_USNORM";
    }
    Unk_TFXString prefix(name);
    s32 result = 0;
    for (s32 i = 0; i < 2; i++) {
        Unk_TFXString full = prefix + suffixes[i];
        s32 error = Unk_463750(techniques[i], full.field_8);
        if (error < 0)
            result = error;
    }
    return result;
}

// 0x7100463a70: Unk_463500 for each set of the tone map's seven options
s32 TEXSHADERSET::Unk_463a70(s32 (*techniques)[16], const char* name) {
    static bool initialised = false;
    static const char* suffixes[7];
    if (!initialised) {
        initialised = true;
        suffixes[0] = "_PreMatrix";
        suffixes[1] = "_Dither";
        suffixes[2] = "_Vignette";
        suffixes[3] = "_VignetteSim";
        suffixes[4] = "_Exposure";
        suffixes[5] = "_Matrix";
        suffixes[6] = "_Gamma";
    }
    Unk_TFXString prefix(name);
    Unk_TFXString text(prefix);
    s32 length = text.field_0;
    s32 result = 0;
    for (s32 i = 0; i < 128; i++) {
        text.Unk_451530(length);
        for (s32 j = 0; j < 7; j++)
            if (i & (1 << j))
                text += suffixes[j];
        s32 error = Unk_463500(techniques[i], text.field_8);
        if (error < 0)
            result = error;
    }
    // a set with the simulated vignette but not the vignette falls back on ...
    for (u32 i = 0; i < 128; i++) {
        if ((i & 0xc) == 8) {
            for (s32 j = 0; j < 16; j++)
                if (techniques[i][j] != 0)
                    techniques[i | 4][j] = techniques[i][j];
        }
    }
    return result;
}

// 0x7100463d90: the parameters `name`, an array's, with each index in its brackets
s32 TEXSHADERSET::Unk_463d90(s32* parameters, s32 count, const char* name) {
    Unk_TFXString text(name);
    s32 bracket = text.Unk_452400("[]", 0, -1);
    Unk_TFXString head;
    Unk_TFXString tail;
    bool split = false;
    if (bracket >= 1) {
        head = text;
        head.Unk_451530(bracket);
        tail = text.field_8 + bracket;
        split = true;
    }
    s32 result = 0;
    for (s32 i = 0; i < count; i++) {
        char number[16];
        sprintf(number, "%d", i);
        Unk_TFXString index(number);
        Unk_TFXString full;
        if (split)
            full = head + index + tail;
        else
            full = text + index;
        parameters[i] = field_0->vf12(0, full.field_8);
        if (parameters[i] == 0)
            result = -1;
    }
    return result;
}

// 0x7100463fd0
s32 TEXSHADERSET::CreateEffect(void* device) {
#line 2849
    PPFX_LOG("==== TEXSHADERSET::CreateEffect() ====\n");
    if (field_0 != nullptr)
        return 0;

    char* errors = nullptr;
    s32 size = *reinterpret_cast<const s32*>(Unk_1b61595);
    if (field_29a20 != nullptr)
        Unk_4b9a60(Unk_238d5f8, reinterpret_cast<u64*>(field_29a20) - 1);
    u64* block = static_cast<u64*>(Unk_4b99a0(Unk_238d5f8, size + sizeof(u64), __FILE__, 2925, nullptr));
    if (block != nullptr)
        *block++ = size;
    field_29a20 = reinterpret_cast<u8*>(block);
    {
        unsigned long length = size;
        mz_uncompress(field_29a20, &length, Unk_1b61595 + 4, 0x318b62);
    }
    s32 result = Unk_49a300(device, field_29a20, size, nullptr, &field_0, &errors, 1);
    if (result < 0) {
#line 2967
        PPFX_ERROR("TEXSHADERSET::CreateEffect(): IGPUEffect::CreateEffectFromFile() failed (0x%x: %s).\n", result, Unk_446df0(result));
        if (errors != nullptr) {
#line 2972
            PPFX_ERROR("%s\n", errors);
        }
        return result;
    }
#line 2976
    PPFX_LOG("TEXSHADERSET::CreateEffect(): IGPUEffect::CreateEffectFromFile() succeeded.\n");
#line 2986
    PPFX_LOG("TEXSHADERSET::CreateEffect(): get parameter handles ...\n");

    field_a0 = field_0->vf12(0, "fParam_ScreenSpaceScale");
    field_a4 = field_0->vf12(0, "fParam_PerspectiveFactor");
    field_a8 = field_0->vf12(0, "fParam_DepthOfFieldConvertDepthFactor");
    field_ac = field_0->vf12(0, "fParam_FocusDistance");
    field_b0 = field_0->vf12(0, "fParam_DepthOfFieldFactorScaleOffset");
    field_b4 = field_0->vf12(0, "afXY_DepthOfFieldLevelBlendFactor16");
    field_b8 = field_0->vf12(0, "fParam_DepthOfFieldLayerMaskThreshold");
    field_bc = field_0->vf12(0, "fParam_DepthOfFieldFactorThreshold");
    field_c0 = field_0->vf12(0, "fParam_DepthCastScaleOffset");
    field_c4 = field_0->vf12(0, "afUV_TexCoordOffsetV16");
    field_c8 = field_0->vf12(0, "afUV_TexCoordOffsetP32");
    field_cc = field_0->vf12(0, "afParam_TexCoordScaler8");
    field_d0 = field_0->vf12(0, "afRGBA_Modulate");
    field_d4 = field_0->vf12(0, "afRGBA_Offset");
    field_d8 = field_0->vf12(0, "fRGBA_Constant");
    field_dc = field_0->vf12(0, "afRGBA_Constant");
    field_e0 = field_0->vf12(0, "afUVWQ_TexCoordScaleOffset");
    field_e4 = field_0->vf12(0, "fParam_VignetteSimulate");
    field_e8 = field_0->vf12(0, "fParam_VignettePowerOfCosine");
    field_ec = field_0->vf12(0, "fParam_HDRFormatFactor_LOGRGB");
    field_f0 = field_0->vf12(0, "fParam_HDRFormatFactor_RGBALUM");
    field_f4 = field_0->vf12(0, "fParam_HDRFormatFactor_REINHARDRGB");
    field_f8 = field_0->vf12(0, "fParam_BrightPass_LensDistortion");
    field_fc = field_0->vf12(0, "fParam_GammaCorrection");
    field_100 = field_0->vf12(0, "fParam_DitherOffsetScale");
    field_104 = field_0->vf12(0, "fParam_TonemapMaxMappingLuminance");
    field_108 = field_0->vf12(0, "m44_ColorTransformMatrix");
    field_10c = field_0->vf12(0, "m44_PreTonemapColorTransformMatrix");
    field_110 = field_0->vf12(0, "m44_PreTonemapGlareColorTransformMatrix");
    field_114 = field_0->vf12(0, "am44_TransformMatrix");
    Unk_GetTechs(field_118, "tech_MadT1_Sn", 32);
    Unk_GetTechs(field_c18, "tech_MadScalarWeightT1_Sn", 32);
    Unk_GetTechs(field_1718, "tech_MadAlphaT1_Sn", 32);
    Unk_GetTechs(field_2218, "tech_MadT2_Sn", 32);
    Unk_GetTechs(field_74a8, "tech_MadColorGradingLutT1_Sn", 4);
    Unk_GetTechs(field_2d18, "tech_MadAlphaColorT2_R_Sn", 1);
    Unk_GetTechs(field_3298, "tech_MadAlphaColorT2_G_Sn", 1);
    Unk_GetTechs(field_3818, "tech_MadAlphaColorT2_B_Sn", 1);
    Unk_GetTechs(field_3d98, "tech_MadAlphaColorT2_A_Sn", 1);
    field_4318 = field_0->vf15("tech_Alpha_R");
    field_431c = field_0->vf15("tech_Alpha_G");
    field_4320 = field_0->vf15("tech_Alpha_B");
    field_4324 = field_0->vf15("tech_Alpha_A");
    Unk_GetTechs(field_4328, "tech_TexCoordOffsetMadTn", 16);
    Unk_GetTechs(field_48a8, "tech_MadTn", 16);
    Unk_GetTechs(field_4e28, "tech_MadLumGammaTn", 16);
    Unk_GetTechs(field_53a8, "tech_MadLumGammaWithLensDirtTn", 16);
    Unk_GetTechs(field_5928, "tech_MadOffsetTn", 16);
    Unk_GetTechs(field_69a8, "tech_MaxColorTn", 16);
    Unk_GetTechs(field_6f28, "tech_MaxColorLumGammaTn", 16);
    Unk_GetTechs(field_5ea8, "tech_MadOffsetVignetteTn", 1);
    Unk_GetTechs(field_6428, "tech_MadOffsetVignetteSimulateTn", 1);
    Unk_463220(field_1b3f4, "tech_TransformMadT1_Sn", 8);
    Unk_463220(field_1b414, "tech_TexCoordMadT1_Sn", 4);
    Unk_GetTechs(field_7710, "tech_BrightPassT1_THRESHOLD_Sn", 1);
    Unk_GetTechs(field_7818, "tech_BrightPassT1_THRESHOLD_LUMINANCE_Sn", 1);
    Unk_GetTechs(field_7920, "tech_BrightPassT1_THRESHOLD_LUMINANCE_REMAP_Sn", 1);
    Unk_GetTechs(field_7768, "tech_BrightPassT1_Vignette_THRESHOLD_Sn", 1);
    Unk_GetTechs(field_7870, "tech_BrightPassT1_Vignette_THRESHOLD_LUMINANCE_Sn", 1);
    Unk_GetTechs(field_7978, "tech_BrightPassT1_Vignette_THRESHOLD_LUMINANCE_REMAP_Sn", 1);
    Unk_GetTechs(field_77c0, "tech_BrightPassT1_VignetteSimulate_THRESHOLD_Sn", 1);
    Unk_GetTechs(field_78c8, "tech_BrightPassT1_VignetteSimulate_THRESHOLD_LUMINANCE_Sn", 1);
    Unk_GetTechs(field_79d0, "tech_BrightPassT1_VignetteSimulate_THRESHOLD_LUMINANCE_REMAP_Sn", 1);
    field_7a28 = field_0->vf15("tech_LightShaftMask");
    field_7a2c = field_0->vf15("tech_LightShaftMask_SM3");
    field_7a30 = field_0->vf15("tech_Corona");
    Unk_462fe0(field_7a34, "tech_GlareGhost_PointSymmetryT4_S8_TrimT1_S8");
    Unk_462fe0(field_7a8c, "tech_GlareGhost_PointSymmetryDistScaleT4_S8_TrimT1_S8");
    Unk_462fe0(field_7ae4, "tech_GlareGhost_PointSymmetryT3_S8");
    Unk_462fe0(field_7b3c, "tech_LightGhostLuminance");
    Unk_462fe0(field_7b94, "tech_LightGhostLuminance_Depth");
    Unk_462fe0(field_7bec, "tech_LightGhost_N5");
    Unk_462fe0(field_7c44, "tech_LightGhost_N6");
    Unk_462fe0(field_7c9c, "tech_LightGhost_N7");
    Unk_462fe0(field_7cf4, "tech_LightGhost_N8");
    Unk_GetTechs(field_7eac[0], "tech_DepthOfField_CompositeBlurredLevels_Tn", 8);
    Unk_GetTechs(field_7eac[1], "tech_DepthOfField_CompositeBlurredLevels_USNORM_Tn", 8);
    Unk_GetTechs(field_842c[0], "tech_DepthOfField_CompositeBlurredLevelsFrontBlur_Tn", 8);
    Unk_GetTechs(field_842c[1], "tech_DepthOfField_CompositeBlurredLevelsFrontBlur_USNORM_Tn", 8);
    Unk_463340(field_89ac[0], "tech_DepthOfField_CompositeBlurLevelsFrontBlur_TSn_n");
    Unk_463340(field_89ac[1], "tech_DepthOfField_CompositeBlurLevelsFrontBlur_USNORM_TSn_n");
    Unk_463340(field_b5ac[0], "tech_DepthOfField_CompositeMaskedBlurLevels_TSn_n");
    Unk_463340(field_b5ac[1], "tech_DepthOfField_CompositeMaskedBlurLevels_USNORM_TSn_n");
    Unk_GetTechs(field_e1ac[0], "tech_DepthOfField_BackgroundLayerMaskT1_Sn", 25);
    Unk_GetTechs(field_e1ac[1], "tech_DepthOfField_BackgroundLayerMaskT1_USNORM_Sn", 25);
    Unk_GetTechs(field_f2dc[0], "tech_DepthOfField_ForegroundLayerMaskT1_Sn", 25);
    Unk_GetTechs(field_f2dc[1], "tech_DepthOfField_ForegroundLayerMaskT1_USNORM_Sn", 25);
    Unk_463220(field_1040c[0][0], "tech_DepthOfField_BackgroundLayerMaskMakeColorT1_Sn", 17);
    Unk_463220(field_1040c[0][1], "tech_DepthOfField_BackgroundLayerMaskMakeColorT1_USNORM_Sn", 17);
    Unk_463220(field_1061c[0][0], "tech_DepthOfField_ForegroundLayerMaskMakeColorT1_Sn", 17);
    Unk_463220(field_1061c[0][1], "tech_DepthOfField_ForegroundLayerMaskMakeColorT1_USNORM_Sn", 17);
    Unk_463220(field_1082c[0][0], "tech_DepthOfField_BackgroundLayerMaskMakeColorMaskT1_Sn", 17);
    Unk_463220(field_1082c[0][1], "tech_DepthOfField_BackgroundLayerMaskMakeColorMaskT1_USNORM_Sn", 17);
    Unk_463220(field_10a3c[0][0], "tech_DepthOfField_ForegroundLayerMaskMakeColorMaskT1_Sn", 17);
    Unk_463220(field_10a3c[0][1], "tech_DepthOfField_ForegroundLayerMaskMakeColorMaskT1_USNORM_Sn", 17);
    Unk_463220(field_1040c[1][0], "tech_DepthOfField_BackgroundLayerMaskMakeColorDenseT1_Sn", 33);
    Unk_463220(field_1040c[1][1], "tech_DepthOfField_BackgroundLayerMaskMakeColorDenseT1_USNORM_Sn", 33);
    Unk_463220(field_1061c[1][0], "tech_DepthOfField_ForegroundLayerMaskMakeColorDenseT1_Sn", 33);
    Unk_463220(field_1061c[1][1], "tech_DepthOfField_ForegroundLayerMaskMakeColorDenseT1_USNORM_Sn", 33);
    Unk_463220(field_1082c[1][0], "tech_DepthOfField_BackgroundLayerMaskMakeColorDenseMaskT1_Sn", 33);
    Unk_463220(field_1082c[1][1], "tech_DepthOfField_BackgroundLayerMaskMakeColorDenseMaskT1_USNORM_Sn", 33);
    Unk_463220(field_10a3c[1][0], "tech_DepthOfField_ForegroundLayerMaskMakeColorDenseMaskT1_Sn", 33);
    Unk_463220(field_10a3c[1][1], "tech_DepthOfField_ForegroundLayerMaskMakeColorDenseMaskT1_USNORM_Sn", 33);
    field_7da4 = field_0->vf15("tech_ValidatePixel");
    field_7da8 = field_0->vf15("tech_ValidatePixelEx");
    field_7dac = field_0->vf15("tech_MedianFilter_Separablex3x3");
    field_7dc0 = field_0->vf15("tech_GenerateNormalDepth_NormRGB");
    field_7db0 = field_0->vf15("tech_GenerateNormalDepth_NormGen2D");
    field_7db4 = field_0->vf15("tech_GenerateNormalDepth_NormGen2DMan");
    field_7db8 = field_0->vf15("tech_GenerateNormalDepth_NormGen3D");
    field_7dbc = field_0->vf15("tech_GenerateNormalDepth_NormGen3DMan");
    field_7dc4 = field_0->vf15("tech_DownsampleNormalDepth");
    {
        char name[1024];
        for (s32 i = 0; i < 6; i++) {
            s32 size = (i + 3) * (i + 3);
            sprintf(name, "tech_AlchemySsao_T1_S%d", size);
            field_7dc8[i] = field_0->vf15(name);
            sprintf(name, "tech_AlchemySsao_Falloff_T1_S%d", size);
            field_7de0[i] = field_0->vf15(name);
            sprintf(name, "tech_AlchemySsaoIgn_T1_S%d", size);
            field_7df8[i] = field_0->vf15(name);
            sprintf(name, "tech_AlchemySsaoIgn_Falloff_T1_S%d", size);
            field_7e10[i] = field_0->vf15(name);
        }
        for (s32 i = 0; i < 7; i++) {
            sprintf(name, "tech_CrossBilateralForSsao_S%d", 5 + i * 2);
            field_7e28[i] = field_0->vf15(name);
        }
    }
    field_7e48 = field_0->vf15("tech_UpsampleSsao_IM");
    field_7e4c[0][0] = field_0->vf15("tech_UpsampleSsao");
    field_7e4c[0][1] = field_0->vf15("tech_UpsampleSsao_MC");
    field_7e4c[0][2] = field_0->vf15("tech_UpsampleSsao_MC_Mask");
    field_7e4c[1][0] = field_0->vf15("tech_UpsampleSsao_LN");
    field_7e4c[1][1] = field_0->vf15("tech_UpsampleSsao_LN_MC");
    field_7e4c[1][2] = field_0->vf15("tech_UpsampleSsao_LN_MC_Mask");
    field_7e64 = field_0->vf15("tech_TemporalAntialias");
    field_7e68 = field_0->vf15("tech_TemporalAntialias_DynamicPixel");
    field_7e6c = field_0->vf15("tech_TemporalAntialias_DynamicPixel_DepthR");
    field_7e70 = field_0->vf15("tech_TemporalAntialias_DynamicPixel_DepthG");
    field_7e74 = field_0->vf15("tech_TemporalAntialias_DynamicPixel_DepthB");
    field_7e78 = field_0->vf15("tech_TemporalAntialias_DynamicPixel_DepthA");
    field_7e7c = field_0->vf15("tech_TemporalAntialias_DynamicPixel_DepthRGBA8");
    field_7e88 = field_0->vf15("tech_TemporalAntialias_Tonemap");
    field_7e8c = field_0->vf15("tech_TemporalAntialias_Tonemap_DynamicPixel");
    field_7e90 = field_0->vf15("tech_TemporalAntialias_Tonemap_DynamicPixel_DepthR");
    field_7e94 = field_0->vf15("tech_TemporalAntialias_Tonemap_DynamicPixel_DepthG");
    field_7e98 = field_0->vf15("tech_TemporalAntialias_Tonemap_DynamicPixel_DepthB");
    field_7e9c = field_0->vf15("tech_TemporalAntialias_Tonemap_DynamicPixel_DepthA");
    field_7ea0 = field_0->vf15("tech_TemporalAntialias_Tonemap_DynamicPixel_DepthRGBA8");
    field_10c4c = field_0->vf15("tech_DepthOfField_BlurFactorAlphaFromDepthTextureTypeCast_RVALUE");
    field_10c54 = field_0->vf15("tech_DepthOfField_BlurFactorAlphaFromDepthTextureTypeCast_GVALUE");
    field_10c5c = field_0->vf15("tech_DepthOfField_BlurFactorAlphaFromDepthTextureTypeCast_BVALUE");
    field_10c64 = field_0->vf15("tech_DepthOfField_BlurFactorAlphaFromDepthTextureTypeCast_AVALUE");
    field_10c6c = field_0->vf15("tech_DepthOfField_BlurFactorAlphaFromDepthTextureTypeCast_RGBA8");
    field_15984 = field_0->vf15("tech_DepthOfField_BlurFactorAlphaFromDepthTextureTypeCastLut_RVALUE");
    field_1598c = field_0->vf15("tech_DepthOfField_BlurFactorAlphaFromDepthTextureTypeCastLut_GVALUE");
    field_15994 = field_0->vf15("tech_DepthOfField_BlurFactorAlphaFromDepthTextureTypeCastLut_BVALUE");
    field_1599c = field_0->vf15("tech_DepthOfField_BlurFactorAlphaFromDepthTextureTypeCastLut_AVALUE");
    field_159a4 = field_0->vf15("tech_DepthOfField_BlurFactorAlphaFromDepthTextureTypeCastLut_RGBA8");
    field_1a6bc = field_0->vf15("tech_DepthOfField_NormalizeBackgroundBlurFactor");
    field_1a6c0 = field_0->vf15("tech_DepthOfField_NormalizeBackgroundBlurFactor_USNORM");
    field_1a6c4[0][0] = field_0->vf15("tech_DepthOfField_FrontBlurBlendFactor");
    field_1a6c4[1][0] = field_0->vf15("tech_DepthOfField_FrontBlurBlendFactorMask");
    field_1a6c4[0][1] = field_0->vf15("tech_DepthOfField_FrontBlurBlendFactorDilation");
    field_1a6c4[1][1] = field_0->vf15("tech_DepthOfField_FrontBlurBlendFactorDilationMask");
    Unk_GetTechs(field_1a6d4, "tech_MadCocT2_Sn", 25);
    memset(&field_1af6c, 0, sizeof(field_1af6c));
    field_1af6c.field_0[0] = field_0->vf15("tech_ScatterCoc");
    field_1af6c.field_0[4] = field_0->vf15("tech_ScatterCoc_Rad");
    field_1af6c.field_0[2] = field_0->vf15("tech_ScatterCoc_Eclipse");
    field_1af6c.field_0[6] = field_0->vf15("tech_ScatterCoc_RadEclipse");
    field_1af6c.field_0[1] = field_0->vf15("tech_ScatterCoc_SeparateXY");
    field_1af6c.field_0[5] = field_0->vf15("tech_ScatterCoc_RadSeparateXY");
    field_1af6c.field_0[3] = field_0->vf15("tech_ScatterCoc_EclipseSeparateXY");
    field_1af6c.field_0[7] = field_0->vf15("tech_ScatterCoc_RadEclipseSeparateXY");
    field_1af6c.field_0[8] = field_0->vf15("tech_ScatterCocLevel");
    field_1af6c.field_0[12] = field_0->vf15("tech_ScatterCocLevel_Rad");
    field_1af6c.field_0[10] = field_0->vf15("tech_ScatterCocLevel_Eclipse");
    field_1af6c.field_0[14] = field_0->vf15("tech_ScatterCocLevel_RadEclipse");
    field_1af6c.field_0[9] = field_0->vf15("tech_ScatterCocLevel_SeparateXY");
    field_1af6c.field_0[13] = field_0->vf15("tech_ScatterCocLevel_RadSeparateXY");
    field_1af6c.field_0[11] = field_0->vf15("tech_ScatterCocLevel_EclipseSeparateXY");
    field_1af6c.field_0[15] = field_0->vf15("tech_ScatterCocLevel_RadEclipseSeparateXY");
    field_1af6c.field_0[16] = field_0->vf15("tech_ScatterCocLevelClamp");
    field_1af6c.field_0[20] = field_0->vf15("tech_ScatterCocLevelClamp_Rad");
    field_1af6c.field_0[18] = field_0->vf15("tech_ScatterCocLevelClamp_Eclipse");
    field_1af6c.field_0[22] = field_0->vf15("tech_ScatterCocLevelClamp_RadEclipse");
    field_1af6c.field_0[17] = field_0->vf15("tech_ScatterCocLevelClamp_SeparateXY");
    field_1af6c.field_0[21] = field_0->vf15("tech_ScatterCocLevelClamp_RadSeparateXY");
    field_1af6c.field_0[19] = field_0->vf15("tech_ScatterCocLevelClamp_EclipseSeparateXY");
    field_1af6c.field_0[23] = field_0->vf15("tech_ScatterCocLevelClamp_RadEclipseSeparateXY");
    field_1af6c.field_0[24] = field_0->vf15("tech_ScatterCocLevel_Rad_Lerp");
    field_1af6c.field_0[26] = field_0->vf15("tech_ScatterCocLevel_RadEclipse_Lerp");
    field_1af6c.field_0[25] = field_0->vf15("tech_ScatterCocLevel_RadSeparateXY_Lerp");
    field_1af6c.field_0[27] = field_0->vf15("tech_ScatterCocLevel_RadEclipseSeparateXY_Lerp");
    field_1af6c.field_0[28] = field_0->vf15("tech_ScatterCocLevelClamp_Rad_Lerp");
    field_1af6c.field_0[30] = field_0->vf15("tech_ScatterCocLevelClamp_RadEclipse_Lerp");
    field_1af6c.field_0[29] = field_0->vf15("tech_ScatterCocLevelClamp_RadSeparateXY_Lerp");
    field_1af6c.field_0[31] = field_0->vf15("tech_ScatterCocLevelClamp_RadEclipseSeparateXY_Lerp");
    field_1af6c.field_80[0] = field_0->vf15("tech_DepthOfField_CompositeScatteredLevels");
    field_1af6c.field_80[1] = field_0->vf15("tech_DepthOfField_CompositeScatteredLevels_Eclipse");
    field_1af6c.field_80[4] = field_0->vf15("tech_DepthOfField_CompositeScatteredLevels_Blur");
    field_1af6c.field_80[5] = field_0->vf15("tech_DepthOfField_CompositeScatteredLevels_BlurEclipse");
    field_1af6c.field_80[6] = field_0->vf15("tech_DepthOfField_CompositeScatteredLevels_BlurRad");
    field_1af6c.field_80[7] = field_0->vf15("tech_DepthOfField_CompositeScatteredLevels_BlurRadEclipse");
    field_1b330 = field_0->vf15("tech_DilateScatteredColorT1_S37");
    {
        Unk_TFXString str0("tech_BokehBlur_S");
        Unk_TFXString str1("tech_BokehBlur_Rad_S");
        Unk_TFXString str2("tech_BokehBlur_Eclipse_S");
        Unk_TFXString str3("tech_BokehBlur_RadEclipse_S");
        Unk_TFXString str4("tech_BokehBlur_SeparateXY_S");
        Unk_TFXString str5("tech_BokehBlur_RadSeparateXY_S");
        Unk_TFXString str6("tech_BokehBlur_EclipseSeparateXY_S");
        Unk_TFXString str7("tech_BokehBlur_RadEclipseSeparateXY_S");
        Unk_TFXString str8("tech_BokehBlurConditional_S");
        Unk_TFXString str9("tech_BokehBlurConditional_Rad_S");
        Unk_TFXString str10("tech_BokehBlurConditional_Eclipse_S");
        Unk_TFXString str11("tech_BokehBlurConditional_RadEclipse_S");
        Unk_TFXString str12("tech_BokehBlurConditional_SeparateXY_S");
        Unk_TFXString str13("tech_BokehBlurConditional_RadSeparateXY_S");
        Unk_TFXString str14("tech_BokehBlurConditional_EclipseSeparateXY_S");
        Unk_TFXString str15("tech_BokehBlurConditional_RadEclipseSeparateXY_S");
        Unk_TFXString str16("tech_BokehBlurSmallAlpha_S");
        Unk_TFXString str17("tech_BokehBlurSmallAlpha_Rad_S");
        Unk_TFXString str18("tech_BokehBlurSmallAlpha_Eclipse_S");
        Unk_TFXString str19("tech_BokehBlurSmallAlpha_RadEclipse_S");
        Unk_TFXString str20("tech_BokehBlurSmallAlpha_SeparateXY_S");
        Unk_TFXString str21("tech_BokehBlurSmallAlpha_RadSeparateXY_S");
        Unk_TFXString str22("tech_BokehBlurSmallAlpha_EclipseSeparateXY_S");
        Unk_TFXString str23("tech_BokehBlurSmallAlpha_RadEclipseSeparateXY_S");
        Unk_TFXString str24("tech_BokehBlurSmallAlphaConditional_S");
        Unk_TFXString str25("tech_BokehBlurSmallAlphaConditional_Rad_S");
        Unk_TFXString str26("tech_BokehBlurSmallAlphaConditional_Eclipse_S");
        Unk_TFXString str27("tech_BokehBlurSmallAlphaConditional_RadEclipse_S");
        Unk_TFXString str28("tech_BokehBlurSmallAlphaConditional_SeparateXY_S");
        Unk_TFXString str29("tech_BokehBlurSmallAlphaConditional_RadSeparateXY_S");
        Unk_TFXString str30("tech_BokehBlurSmallAlphaConditional_EclipseSeparateXY_S");
        Unk_TFXString str31("tech_BokehBlurSmallAlphaConditional_RadEclipseSeparateXY_S");
        Unk_TFXString str32("tech_BokehBlurCenterAlpha_S");
        Unk_TFXString str33("tech_BokehBlurCenterAlpha_Rad_S");
        Unk_TFXString str34("tech_BokehBlurCenterAlpha_Eclipse_S");
        Unk_TFXString str35("tech_BokehBlurCenterAlpha_RadEclipse_S");
        Unk_TFXString str36("tech_BokehBlurCenterAlpha_SeparateXY_S");
        Unk_TFXString str37("tech_BokehBlurCenterAlpha_RadSeparateXY_S");
        Unk_TFXString str38("tech_BokehBlurCenterAlpha_EclipseSeparateXY_S");
        Unk_TFXString str39("tech_BokehBlurCenterAlpha_RadEclipseSeparateXY_S");
        Unk_TFXString full;
        for (s32 i = 0; i < 5; i++) {
            s32 size = Unk_1b35158[i];
            Unk_TFXString num = Unk_4525a0(size);
            full = str0 + num;
            field_1af6c.field_a0[0][i] = field_0->vf15(full.field_8);
            full = str1 + num;
            field_1af6c.field_a0[4][i] = field_0->vf15(full.field_8);
            full = str2 + num;
            field_1af6c.field_a0[2][i] = field_0->vf15(full.field_8);
            full = str3 + num;
            field_1af6c.field_a0[6][i] = field_0->vf15(full.field_8);
            full = str8 + num;
            field_1af6c.field_a0[8][i] = field_0->vf15(full.field_8);
            full = str9 + num;
            field_1af6c.field_a0[12][i] = field_0->vf15(full.field_8);
            full = str10 + num;
            field_1af6c.field_a0[10][i] = field_0->vf15(full.field_8);
            full = str11 + num;
            field_1af6c.field_a0[14][i] = field_0->vf15(full.field_8);
            full = str16 + num;
            field_1af6c.field_a0[16][i] = field_0->vf15(full.field_8);
            full = str17 + num;
            field_1af6c.field_a0[20][i] = field_0->vf15(full.field_8);
            full = str18 + num;
            field_1af6c.field_a0[18][i] = field_0->vf15(full.field_8);
            full = str19 + num;
            field_1af6c.field_a0[22][i] = field_0->vf15(full.field_8);
            full = str24 + num;
            field_1af6c.field_a0[24][i] = field_0->vf15(full.field_8);
            full = str25 + num;
            field_1af6c.field_a0[28][i] = field_0->vf15(full.field_8);
            full = str26 + num;
            field_1af6c.field_a0[26][i] = field_0->vf15(full.field_8);
            full = str27 + num;
            field_1af6c.field_a0[30][i] = field_0->vf15(full.field_8);
            {
                Unk_TFXString num2 = Unk_4525a0(size);
                full = str4 + num2;
                field_1af6c.field_a0[1][i] = field_0->vf15(full.field_8);
                full = str5 + num2;
                field_1af6c.field_a0[5][i] = field_0->vf15(full.field_8);
                full = str6 + num2;
                field_1af6c.field_a0[3][i] = field_0->vf15(full.field_8);
                full = str7 + num2;
                field_1af6c.field_a0[7][i] = field_0->vf15(full.field_8);
                full = str12 + num2;
                field_1af6c.field_a0[9][i] = field_0->vf15(full.field_8);
                full = str13 + num2;
                field_1af6c.field_a0[13][i] = field_0->vf15(full.field_8);
                full = str14 + num2;
                field_1af6c.field_a0[11][i] = field_0->vf15(full.field_8);
                full = str15 + num2;
                field_1af6c.field_a0[15][i] = field_0->vf15(full.field_8);
                full = str20 + num2;
                field_1af6c.field_a0[17][i] = field_0->vf15(full.field_8);
                full = str21 + num2;
                field_1af6c.field_a0[21][i] = field_0->vf15(full.field_8);
                full = str22 + num2;
                field_1af6c.field_a0[19][i] = field_0->vf15(full.field_8);
                full = str23 + num2;
                field_1af6c.field_a0[23][i] = field_0->vf15(full.field_8);
                full = str28 + num2;
                field_1af6c.field_a0[25][i] = field_0->vf15(full.field_8);
                full = str29 + num2;
                field_1af6c.field_a0[29][i] = field_0->vf15(full.field_8);
                full = str30 + num2;
                field_1af6c.field_a0[27][i] = field_0->vf15(full.field_8);
                full = str31 + num2;
                field_1af6c.field_a0[31][i] = field_0->vf15(full.field_8);
            }
            if (i < 3) {
                full = str32 + num;
                field_1af6c.field_a0[32][i] = field_0->vf15(full.field_8);
                full = str33 + num;
                field_1af6c.field_a0[36][i] = field_0->vf15(full.field_8);
                full = str34 + num;
                field_1af6c.field_a0[34][i] = field_0->vf15(full.field_8);
                full = str35 + num;
                field_1af6c.field_a0[38][i] = field_0->vf15(full.field_8);
                full = str36 + num;
                field_1af6c.field_a0[33][i] = field_0->vf15(full.field_8);
                full = str37 + num;
                field_1af6c.field_a0[37][i] = field_0->vf15(full.field_8);
                full = str38 + num;
                field_1af6c.field_a0[35][i] = field_0->vf15(full.field_8);
                full = str39 + num;
                field_1af6c.field_a0[39][i] = field_0->vf15(full.field_8);
            }
        }
    }
    field_1b32c = field_0->vf15("tech_GradientMaskT1_S4");
    Unk_GetTechs(field_10c84, "tech_DepthOfField_BlurFactorAlphaFromDepthTextureTypeCastT1_Sn", 1);
    Unk_GetTechs(field_159bc, "tech_DepthOfField_BlurFactorAlphaFromDepthTextureTypeCastLutT1_Sn", 1);
    field_1b334 = field_0->vf15("tech_DepthEncode_RVALUE");
    field_1b344 = field_0->vf15("tech_DepthEncode_RGBA8");
    field_1b350 = field_0->vf15("tech_DepthFromDofFactor_R");
    field_1b354 = field_0->vf15("tech_DepthFromDofFactor_G");
    field_1b358 = field_0->vf15("tech_DepthFromDofFactor_B");
    field_1b35c = field_0->vf15("tech_DepthFromDofFactor_A");
    field_1b360 = field_0->vf15("tech_DepthFromDofFactor_USNORM_R");
    field_1b364 = field_0->vf15("tech_DepthFromDofFactor_USNORM_G");
    field_1b368 = field_0->vf15("tech_DepthFromDofFactor_USNORM_B");
    field_1b36c = field_0->vf15("tech_DepthFromDofFactor_USNORM_A");
    field_10c80 = field_0->vf15("tech_DepthOfField_BlurFactorAlphaFromDepthTextureTypeCast_USNORM_ABGR8");
    field_1b370 = field_0->vf15("tech_LensDistortion");
    field_1b374 = field_0->vf15("tech_LensDistortionConv");
    field_1b378 = field_0->vf15("tech_LensDistortionFalloff");
    field_1b37c = field_0->vf15("tech_LensDistortion_Noise");
    field_1b380 = field_0->vf15("tech_LensDistortionConv_Noise");
    field_1b384 = field_0->vf15("tech_LensDistortion_Noise_Additive");
    field_1b388 = field_0->vf15("tech_LensDistortionConv_Noise_Additive");
    field_1b38c = field_0->vf15("tech_ImageSensorNoise");
    field_1b390 = field_0->vf15("tech_ImageSensorNoise_Additive");
    Unk_463220(field_1b394, "tech_LateralChromaticAberration_Sn", 8);
    Unk_463220(field_1b3b4, "tech_ChromaticAberrationWithMask_Sn", 8);
    Unk_463220(field_1b3d4, "tech_ChromaticAberrationWithMask_Noise_Sn", 8);
    field_1b424 = field_0->vf15("tech_Feedback");
    field_1b428 = field_0->vf15("tech_Feedback_Matrix");
    field_1b42c = field_0->vf15("tech_Feedback_Blend");
    field_1b430 = field_0->vf15("tech_Feedback_Blend_Matrix");
    Unk_GetTechs(field_1b434, "tech_MotionBlurCameraRotatePerspectiveT1_Sn", 8);
    Unk_GetTechs(field_1b9b4, "tech_MotionBlurCameraRotatePerspective_SM3_T1_Sn", 8);
    Unk_GetTechs(field_1b6f4, "tech_MotionBlurCameraRotatePerspectiveFalloffT1_Sn", 8);
    Unk_GetTechs(field_1bc74, "tech_MotionBlurCameraRotatePerspectiveFalloff_SM3_T1_Sn", 8);
    Unk_GetTechs(field_1bf34, "tech_MotionBlurCameraRotatePerspectiveFalloffBiLinearT1_Sn", 8);
    Unk_GetTechs(field_1c1f4, "tech_MotionBlurCameraRotatePerspectiveFalloffBiLinear_SM3_T1_Sn", 8);
    field_1c4b4[0] = field_0->vf15("tech_MotionBlurMakeCameraVelocity_R");
    field_1c4b4[1] = field_0->vf15("tech_MotionBlurMakeCameraVelocity_G");
    field_1c4b4[2] = field_0->vf15("tech_MotionBlurMakeCameraVelocity_B");
    field_1c4b4[3] = field_0->vf15("tech_MotionBlurMakeCameraVelocity_A");
    field_1c4b4[4] = field_0->vf15("tech_MotionBlurMakeCameraVelocity_RGBA8");
    field_1c4d0[0] = field_0->vf15("tech_MotionBlurMakeCameraVelocityFalloff_R");
    field_1c4d0[1] = field_0->vf15("tech_MotionBlurMakeCameraVelocityFalloff_G");
    field_1c4d0[2] = field_0->vf15("tech_MotionBlurMakeCameraVelocityFalloff_B");
    field_1c4d0[3] = field_0->vf15("tech_MotionBlurMakeCameraVelocityFalloff_A");
    field_1c4d0[4] = field_0->vf15("tech_MotionBlurMakeCameraVelocityFalloff_RGBA8");
    field_1c4ec[0] = field_0->vf15("tech_MotionBlurMakeCameraVelocityOverwrite_R");
    field_1c4ec[1] = field_0->vf15("tech_MotionBlurMakeCameraVelocityOverwrite_G");
    field_1c4ec[2] = field_0->vf15("tech_MotionBlurMakeCameraVelocityOverwrite_B");
    field_1c4ec[3] = field_0->vf15("tech_MotionBlurMakeCameraVelocityOverwrite_A");
    field_1c4ec[4] = field_0->vf15("tech_MotionBlurMakeCameraVelocityOverwrite_RGBA8");
    field_1c508[0] = field_0->vf15("tech_MotionBlurMakeCameraVelocityOverwriteFalloff_R");
    field_1c508[1] = field_0->vf15("tech_MotionBlurMakeCameraVelocityOverwriteFalloff_G");
    field_1c508[2] = field_0->vf15("tech_MotionBlurMakeCameraVelocityOverwriteFalloff_B");
    field_1c508[3] = field_0->vf15("tech_MotionBlurMakeCameraVelocityOverwriteFalloff_A");
    field_1c508[4] = field_0->vf15("tech_MotionBlurMakeCameraVelocityOverwriteFalloff_RGBA8");
    Unk_GetTechs(field_1c524, "tech_MotionBlurVelocityT2_Sn", 8);
    Unk_GetTechs(field_1d5a4, "tech_MotionBlurVelocity_SM3_T2_Sn", 8);
    Unk_GetTechs(field_1c7e4, "tech_MotionBlurVelocityInnerscreenT2_Sn", 8);
    Unk_GetTechs(field_1d864, "tech_MotionBlurVelocityInnerscreen_SM3_T2_Sn", 8);
    Unk_GetTechs(field_1e624, "tech_MotionBlurVelocityClampT2_Sn", 8);
    Unk_GetTechs(field_1f6a4, "tech_MotionBlurVelocityClamp_SM3_T2_Sn", 8);
    Unk_GetTechs(field_1e8e4, "tech_MotionBlurVelocityInnerscreenClampT2_Sn", 8);
    Unk_GetTechs(field_1f964, "tech_MotionBlurVelocityInnerscreenClamp_SM3_T2_Sn", 8);
    Unk_GetTechs(field_1caa4, "tech_MotionBlurVelocityDirT2_Sn", 8);
    Unk_GetTechs(field_1db24, "tech_MotionBlurVelocityDir_SM3_T2_Sn", 8);
    Unk_GetTechs(field_1cd64, "tech_MotionBlurVelocityDirInnerscreenT2_Sn", 8);
    Unk_GetTechs(field_1dde4, "tech_MotionBlurVelocityDirInnerscreen_SM3_T2_Sn", 8);
    Unk_GetTechs(field_1eba4, "tech_MotionBlurVelocityDirClampT2_Sn", 8);
    Unk_GetTechs(field_1fc24, "tech_MotionBlurVelocityDirClamp_SM3_T2_Sn", 8);
    Unk_GetTechs(field_1ee64, "tech_MotionBlurVelocityDirInnerscreenClampT2_Sn", 8);
    Unk_GetTechs(field_1fee4, "tech_MotionBlurVelocityDirInnerscreenClamp_SM3_T2_Sn", 8);
    Unk_GetTechs(field_1d024[0], "tech_MotionBlurVelocityDirDepthT2_Sn", 8);
    Unk_GetTechs(field_1e0a4[0], "tech_MotionBlurVelocityDirDepth_SM3_T2_Sn", 8);
    Unk_GetTechs(field_1d024[1], "tech_MotionBlurVelocityDirDepthInnerscreenT2_Sn", 8);
    Unk_GetTechs(field_1e0a4[1], "tech_MotionBlurVelocityDirDepthInnerscreen_SM3_T2_Sn", 8);
    Unk_GetTechs(field_1f124[0], "tech_MotionBlurVelocityDirDepthClampT2_Sn", 8);
    Unk_GetTechs(field_201a4[0], "tech_MotionBlurVelocityDirDepthClamp_SM3_T2_Sn", 8);
    Unk_GetTechs(field_1f124[1], "tech_MotionBlurVelocityDirDepthInnerscreenClampT2_Sn", 8);
    Unk_GetTechs(field_201a4[1], "tech_MotionBlurVelocityDirDepthInnerscreenClamp_SM3_T2_Sn", 8);
    field_20724 = field_0->vf15("tech_MotionBlurVelocityUpsample");
    field_20728 = field_0->vf15("tech_MotionBlurVelocityDecode");
    field_2072c = field_0->vf15("tech_TonemapToAnalyzeSceneLuminance");
    Unk_463a70(field_20730, "tech_TonemapHDR");
    field_8 = field_0->vf12(0, "asamp2D_Texture[0]");
    field_c = field_0->vf12(0, "asamp2D_Texture[1]");
    Unk_463d90(field_10, 16, "asamp2D_Texture[]");
    Unk_463d90(field_50, 16, "asamp3D_Texture[]");
    Unk_463d90(field_90, 4, "asamp2D_VertexTexture[]");
    field_22730 = field_0->vf15("tech_UpdateWaterHeight");
    field_22734 = field_0->vf15("tech_GenerateNormalMap");
    field_22738 = field_0->vf15("tech_ConstantColor");
    Unk_463220(field_2273c, "tech_ConstantColorO4", 4);
    field_2273c[0] = field_22738;
    field_2274c = field_0->vf15("tech_AnalyzeIntensity");
    field_22750 = field_0->vf15("tech_AnalyzeIntensityTest");
    field_22754 = field_0->vf15("tech_Fxaa2");
    field_22758 = field_0->vf15("tech_Fxaa2_Falloff");
    field_2275c = field_0->vf15("tech_Fxaa2_Tonemap");
    field_22760 = field_0->vf15("tech_Fxaa2_Tonemap_Falloff");
    field_22764 = field_0->vf15("tech_Smaa_EdgeDetection");
    field_2276c = field_0->vf15("tech_Smaa_BlendingWeightCalculation");
    field_22774 = field_0->vf15("tech_Smaa_BlendingWeightCalculation_Diag");
    field_22770 = field_0->vf15("tech_Smaa_BlendingWeightCalculation_Corner");
    field_22778 = field_0->vf15("tech_Smaa_BlendingWeightCalculation_Diag_Corner");
    field_2277c = field_0->vf15("tech_Smaa_NeighborhoodBlending");
    field_22780 = field_0->vf15("tech_Smaa_NeighborhoodBlending_Falloff");
    field_22788 = field_0->vf15("tech_ColorModulateByChannel_R");
    field_2278c = field_0->vf15("tech_ColorModulateByChannel_G");
    field_22790 = field_0->vf15("tech_ColorModulateByChannel_B");
    field_22794 = field_0->vf15("tech_ColorModulateByChannel_A");
    field_22798 = field_0->vf15("tech_ColorModulateByChannel_RGB");
    field_227b0 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_R");
    field_227c4 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_G");
    field_227d8 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_B");
    field_227ec = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_A");
    field_227b4 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_R_R");
    field_227b8 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_R_G");
    field_227bc = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_R_B");
    field_227c0 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_R_A");
    field_227c8 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_G_R");
    field_227cc = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_G_G");
    field_227d0 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_G_B");
    field_227d4 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_G_A");
    field_227dc = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_B_R");
    field_227e0 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_B_G");
    field_227e4 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_B_B");
    field_227e8 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_B_A");
    field_227f0 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_A_R");
    field_227f4 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_A_G");
    field_227f8 = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_A_B");
    field_227fc = field_0->vf15("tech_CompositeColorAndAlphaEffectsMask_A_A");
    field_22800 = field_0->vf15("tech_RenderSceneRect");
    field_22804 = field_0->vf15("tech_RenderSceneRect_OutReinhard");
    field_22808 = field_0->vf15("tech_RenderSceneRect_InLinearDepth");
    field_2280c = field_0->vf15("tech_RenderSceneRect_InLinearDepth_OutReinhard");
    Unk_463220(field_22810, "tech_HeatShimmerParticle_Sn", 4);
    Unk_463220(field_22820, "tech_HeatShimmerParticle_SM3_Sn", 4);
    Unk_463220(field_22830, "tech_HeatShimmerParticle_BlendAlpha_Sn", 4);
    Unk_463220(field_22840, "tech_HeatShimmerParticle_SM3_BlendAlpha_Sn", 4);
    Unk_463220(field_22850, "tech_MinMaxAverageOfMaxChannelT1_Sn", 16);
    Unk_463220(field_22890, "tech_MinMaxAverageT1_Sn", 16);
    Unk_463220(field_228d0, "tech_MinMaxAverageEncodeT1_Sn", 16);
    Unk_463500(field_22910, "tech_OptoElectronicTransferT2_S1_PQ");
    Unk_463500(field_22d50, "tech_OptoElectronicTransferT2_S1_PQSCRGB");
    Unk_463500(field_22950, "tech_OptoElectronicTransferT2_S1_HLG");
    Unk_463500(field_22990, "tech_OptoElectronicTransferT2_S1_SLOG");
    Unk_463500(field_22a50, "tech_OptoElectronicTransferT2_S1_CLAMP");
    Unk_463500(field_22c50, "tech_OptoElectronicTransferT2_S1_GAMMA");
    Unk_463500(field_22d10, "tech_OptoElectronicTransferT2_S1_GAMMASCRGB");
    Unk_463500(field_22cd0, "tech_OptoElectronicTransferT2_S1_PQ_YCBCR12_422_RGB8");
    Unk_463500(field_23210, "tech_OptoElectronicTransferGamutT2_S1_PQ");
    Unk_463500(field_23650, "tech_OptoElectronicTransferGamutT2_S1_PQSCRGB");
    Unk_463500(field_23250, "tech_OptoElectronicTransferGamutT2_S1_HLG");
    Unk_463500(field_23290, "tech_OptoElectronicTransferGamutT2_S1_SLOG");
    Unk_463500(field_23350, "tech_OptoElectronicTransferGamutT2_S1_CLAMP");
    Unk_463500(field_23550, "tech_OptoElectronicTransferGamutT2_S1_GAMMA");
    Unk_463500(field_23610, "tech_OptoElectronicTransferGamutT2_S1_GAMMASCRGB");
    Unk_463500(field_235d0, "tech_OptoElectronicTransferGamutT2_S1_PQ_YCBCR12_422_RGB8");
    Unk_463500(field_23b10, "tech_OptoElectronicTransferGamutPostColorT2_S1_PQ");
    Unk_463500(field_23f50, "tech_OptoElectronicTransferGamutPostColorT2_S1_PQSCRGB");
    Unk_463500(field_23b50, "tech_OptoElectronicTransferGamutPostColorT2_S1_HLG");
    Unk_463500(field_23b90, "tech_OptoElectronicTransferGamutPostColorT2_S1_SLOG");
    Unk_463500(field_23c50, "tech_OptoElectronicTransferGamutPostColorT2_S1_CLAMP");
    Unk_463500(field_23e50, "tech_OptoElectronicTransferGamutPostColorT2_S1_GAMMA");
    Unk_463500(field_23f10, "tech_OptoElectronicTransferGamutPostColorT2_S1_GAMMASCRGB");
    Unk_463500(field_23ed0, "tech_OptoElectronicTransferGamutPostColorT2_S1_PQ_YCBCR12_422_RGB8");
    Unk_463500(field_22d90, "tech_OptoElectronicTransferAdjustGammaT2_S1_PQ");
    Unk_463500(field_231d0, "tech_OptoElectronicTransferAdjustGammaT2_S1_PQSCRGB");
    Unk_463500(field_22dd0, "tech_OptoElectronicTransferAdjustGammaT2_S1_HLG");
    Unk_463500(field_22e10, "tech_OptoElectronicTransferAdjustGammaT2_S1_SLOG");
    Unk_463500(field_22ed0, "tech_OptoElectronicTransferAdjustGammaT2_S1_CLAMP");
    Unk_463500(field_23150, "tech_OptoElectronicTransferAdjustGammaT2_S1_PQ_YCBCR12_422_RGB8");
    Unk_463500(field_23690, "tech_OptoElectronicTransferAdjustGammaGamutT2_S1_PQ");
    Unk_463500(field_23ad0, "tech_OptoElectronicTransferAdjustGammaGamutT2_S1_PQSCRGB");
    Unk_463500(field_236d0, "tech_OptoElectronicTransferAdjustGammaGamutT2_S1_HLG");
    Unk_463500(field_23710, "tech_OptoElectronicTransferAdjustGammaGamutT2_S1_SLOG");
    Unk_463500(field_237d0, "tech_OptoElectronicTransferAdjustGammaGamutT2_S1_CLAMP");
    Unk_463500(field_23a50, "tech_OptoElectronicTransferAdjustGammaGamutT2_S1_PQ_YCBCR12_422_RGB8");
    Unk_463500(field_23f90, "tech_OptoElectronicTransferAdjustGammaGamutPostColorT2_S1_PQ");
    Unk_463500(field_243d0, "tech_OptoElectronicTransferAdjustGammaGamutPostColorT2_S1_PQSCRGB");
    Unk_463500(field_23fd0, "tech_OptoElectronicTransferAdjustGammaGamutPostColorT2_S1_HLG");
    Unk_463500(field_24010, "tech_OptoElectronicTransferAdjustGammaGamutPostColorT2_S1_SLOG");
    Unk_463500(field_240d0, "tech_OptoElectronicTransferAdjustGammaGamutPostColorT2_S1_CLAMP");
    Unk_463500(field_24350, "tech_OptoElectronicTransferAdjustGammaGamutPostColorT2_S1_PQ_YCBCR12_422_RGB8");
    Unk_463500(field_25f10, "tech_OptoElectronicTransferT2_S4_PQ");
    Unk_463500(field_26350, "tech_OptoElectronicTransferT2_S4_PQSCRGB");
    Unk_463500(field_25f50, "tech_OptoElectronicTransferT2_S4_HLG");
    Unk_463500(field_25f90, "tech_OptoElectronicTransferT2_S4_SLOG");
    Unk_463500(field_26050, "tech_OptoElectronicTransferT2_S4_CLAMP");
    Unk_463500(field_26250, "tech_OptoElectronicTransferT2_S4_GAMMA");
    Unk_463500(field_26310, "tech_OptoElectronicTransferT2_S4_GAMMASCRGB");
    Unk_463500(field_262d0, "tech_OptoElectronicTransferT2_S4_PQ_YCBCR12_422_RGB8");
    Unk_463500(field_26810, "tech_OptoElectronicTransferGamutT2_S4_PQ");
    Unk_463500(field_26c50, "tech_OptoElectronicTransferGamutT2_S4_PQSCRGB");
    Unk_463500(field_26850, "tech_OptoElectronicTransferGamutT2_S4_HLG");
    Unk_463500(field_26890, "tech_OptoElectronicTransferGamutT2_S4_SLOG");
    Unk_463500(field_26950, "tech_OptoElectronicTransferGamutT2_S4_CLAMP");
    Unk_463500(field_26b50, "tech_OptoElectronicTransferGamutT2_S4_GAMMA");
    Unk_463500(field_26c10, "tech_OptoElectronicTransferGamutT2_S4_GAMMASCRGB");
    Unk_463500(field_26bd0, "tech_OptoElectronicTransferGamutT2_S4_PQ_YCBCR12_422_RGB8");
    Unk_463500(field_27110, "tech_OptoElectronicTransferGamutPostColorT2_S4_PQ");
    Unk_463500(field_27550, "tech_OptoElectronicTransferGamutPostColorT2_S4_PQSCRGB");
    Unk_463500(field_27150, "tech_OptoElectronicTransferGamutPostColorT2_S4_HLG");
    Unk_463500(field_27190, "tech_OptoElectronicTransferGamutPostColorT2_S4_SLOG");
    Unk_463500(field_27250, "tech_OptoElectronicTransferGamutPostColorT2_S4_CLAMP");
    Unk_463500(field_27450, "tech_OptoElectronicTransferGamutPostColorT2_S4_GAMMA");
    Unk_463500(field_27510, "tech_OptoElectronicTransferGamutPostColorT2_S4_GAMMASCRGB");
    Unk_463500(field_274d0, "tech_OptoElectronicTransferGamutPostColorT2_S4_PQ_YCBCR12_422_RGB8");
    Unk_463500(field_26390, "tech_OptoElectronicTransferAdjustGammaT2_S4_PQ");
    Unk_463500(field_267d0, "tech_OptoElectronicTransferAdjustGammaT2_S4_PQSCRGB");
    Unk_463500(field_263d0, "tech_OptoElectronicTransferAdjustGammaT2_S4_HLG");
    Unk_463500(field_26410, "tech_OptoElectronicTransferAdjustGammaT2_S4_SLOG");
    Unk_463500(field_264d0, "tech_OptoElectronicTransferAdjustGammaT2_S4_CLAMP");
    Unk_463500(field_26750, "tech_OptoElectronicTransferAdjustGammaT2_S4_PQ_YCBCR12_422_RGB8");
    Unk_463500(field_26c90, "tech_OptoElectronicTransferAdjustGammaGamutT2_S4_PQ");
    Unk_463500(field_270d0, "tech_OptoElectronicTransferAdjustGammaGamutT2_S4_PQSCRGB");
    Unk_463500(field_26cd0, "tech_OptoElectronicTransferAdjustGammaGamutT2_S4_HLG");
    Unk_463500(field_26d10, "tech_OptoElectronicTransferAdjustGammaGamutT2_S4_SLOG");
    Unk_463500(field_26dd0, "tech_OptoElectronicTransferAdjustGammaGamutT2_S4_CLAMP");
    Unk_463500(field_27050, "tech_OptoElectronicTransferAdjustGammaGamutT2_S4_PQ_YCBCR12_422_RGB8");
    Unk_463500(field_27590, "tech_OptoElectronicTransferAdjustGammaGamutPostColorT2_S4_PQ");
    Unk_463500(field_279d0, "tech_OptoElectronicTransferAdjustGammaGamutPostColorT2_S4_PQSCRGB");
    Unk_463500(field_275d0, "tech_OptoElectronicTransferAdjustGammaGamutPostColorT2_S4_HLG");
    Unk_463500(field_27610, "tech_OptoElectronicTransferAdjustGammaGamutPostColorT2_S4_SLOG");
    Unk_463500(field_276d0, "tech_OptoElectronicTransferAdjustGammaGamutPostColorT2_S4_CLAMP");
    Unk_463500(field_27950, "tech_OptoElectronicTransferAdjustGammaGamutPostColorT2_S4_PQ_YCBCR12_422_RGB8");
    Unk_463500(field_247d0, "tech_OptoElectronicTransferT2_S1_PQ_YCBCR12_422_RGB8_DBVMETA");
    Unk_463500(field_27dd0, "tech_OptoElectronicTransferT2_S4_PQ_YCBCR12_422_RGB8_DBVMETA");
    Unk_463500(field_250d0, "tech_OptoElectronicTransferGamutT2_S1_PQ_YCBCR12_422_RGB8_DBVMETA");
    Unk_463500(field_286d0, "tech_OptoElectronicTransferGamutT2_S4_PQ_YCBCR12_422_RGB8_DBVMETA");
    Unk_463500(field_259d0, "tech_OptoElectronicTransferGamutPostColorT2_S1_PQ_YCBCR12_422_RGB8_DBVMETA");
    Unk_463500(field_28fd0, "tech_OptoElectronicTransferGamutPostColorT2_S4_PQ_YCBCR12_422_RGB8_DBVMETA");
    Unk_463500(field_24c50, "tech_OptoElectronicTransferAdjustGammaT2_S1_PQ_YCBCR12_422_RGB8_DBVMETA");
    Unk_463500(field_28250, "tech_OptoElectronicTransferAdjustGammaT2_S4_PQ_YCBCR12_422_RGB8_DBVMETA");
    Unk_463500(field_25550, "tech_OptoElectronicTransferAdjustGammaGamutT2_S1_PQ_YCBCR12_422_RGB8_DBVMETA");
    Unk_463500(field_28b50, "tech_OptoElectronicTransferAdjustGammaGamutT2_S4_PQ_YCBCR12_422_RGB8_DBVMETA");
    Unk_463500(field_25e50, "tech_OptoElectronicTransferAdjustGammaGamutPostColorT2_S1_PQ_YCBCR12_422_RGB8_DBVMETA");
    Unk_463500(field_29450, "tech_OptoElectronicTransferAdjustGammaGamutPostColorT2_S4_PQ_YCBCR12_422_RGB8_DBVMETA");
    Unk_463500(field_29510, "tech_OptoElectronicTransferTonemapGraph_PQ");
    Unk_463500(field_29950, "tech_OptoElectronicTransferTonemapGraph_PQSCRGB");
    Unk_463500(field_29550, "tech_OptoElectronicTransferTonemapGraph_HLG");
    Unk_463500(field_29590, "tech_OptoElectronicTransferTonemapGraph_SLOG");
    Unk_463500(field_29650, "tech_OptoElectronicTransferTonemapGraph_CLAMP");
    Unk_463500(field_29850, "tech_OptoElectronicTransferTonemapGraph_GAMMA");
    Unk_463500(field_29910, "tech_OptoElectronicTransferTonemapGraph_GAMMA");
    return 0;
}


// 0x710046cfe0
s32 TEXSHADERSET::Unk_46cfe0() {
    if (field_0 == nullptr) {
        return -1;
    }
    IGPUDevice* device;
    Unk_InputElement elements[2] = {
        Unk_InputElement(0, 0, 0x10),
        Unk_InputElement(2, 0, 0x10),
    };
    if (field_299b8[1] != nullptr) {
        return 1;
    }
    Unk_446620(field_0, &device);
    device->vf1();
    void* arg3 = field_0->vf37(0);
    s32 arg4 = field_0->vf39(0);
    return device->vf70(elements, 2, arg3, arg4, &field_299b8[1]);
}

// 0x710046d0c0
s32 TEXSHADERSET::Unk_46d0c0() {
    if (field_0 == nullptr) {
        return -1;
    }
    IGPUDevice* device;
    Unk_InputElement elements[3] = {
        Unk_InputElement(0, 0, 0x10),
        Unk_InputElement(2, 0, 0x10),
        Unk_InputElement(2, 1, 0x10),
    };
    if (field_299b8[2] != nullptr) {
        return 1;
    }
    Unk_446620(field_0, &device);
    device->vf1();
    void* arg3 = field_0->vf37(0);
    s32 arg4 = field_0->vf39(0);
    return device->vf70(elements, 3, arg3, arg4, &field_299b8[2]);
}

// 0x710046d1b0
s32 TEXSHADERSET::Unk_46d1b0() {
    if (field_0 == nullptr) {
        return -1;
    }
    IGPUDevice* device;
    Unk_InputElement elements[4] = {
        Unk_InputElement(0, 0, 0x10),
        Unk_InputElement(2, 0, 0x10),
        Unk_InputElement(2, 1, 0x10),
        Unk_InputElement(2, 2, 0x10),
    };
    if (field_299b8[3] != nullptr) {
        return 1;
    }
    Unk_446620(field_0, &device);
    device->vf1();
    void* arg3 = field_0->vf37(0);
    s32 arg4 = field_0->vf39(0);
    return device->vf70(elements, 4, arg3, arg4, &field_299b8[3]);
}

// 0x710046d2a0
s32 TEXSHADERSET::Unk_46d2a0() {
    if (field_0 == nullptr) {
        return -1;
    }
    IGPUDevice* device;
    if (field_299b8[4] != nullptr) {
        return 1;
    }
    Unk_446620(field_0, &device);
    device->vf1();
    Unk_InputElement elements[5] = {
        Unk_InputElement(0, 0, 0x10),
        Unk_InputElement(2, 0, 0x10),
        Unk_InputElement(2, 1, 0x10),
        Unk_InputElement(2, 2, 0x10),
        Unk_InputElement(2, 3, 0x10),
    };
    void* arg3 = field_0->vf37(0);
    s32 arg4 = field_0->vf39(0);
    return device->vf70(elements, 5, arg3, arg4, &field_299b8[4]);
}

// 0x710046d3a0
s32 TEXSHADERSET::Unk_46d3a0() {
    if (field_0 == nullptr) {
        return -1;
    }
    IGPUDevice* device;
    if (field_299b8[5] != nullptr) {
        return 1;
    }
    Unk_446620(field_0, &device);
    device->vf1();
    Unk_InputElement elements[6] = {
        Unk_InputElement(0, 0, 0x10),
        Unk_InputElement(2, 0, 0x10),
        Unk_InputElement(2, 1, 0x10),
        Unk_InputElement(2, 2, 0x10),
        Unk_InputElement(2, 3, 0x10),
        Unk_InputElement(2, 4, 0x10),
    };
    void* arg3 = field_0->vf37(0);
    s32 arg4 = field_0->vf39(0);
    return device->vf70(elements, 6, arg3, arg4, &field_299b8[5]);
}

// 0x710046d4b0
s32 TEXSHADERSET::Unk_46d4b0() {
    if (field_0 == nullptr) {
        return -1;
    }
    IGPUDevice* device;
    if (field_299b8[6] != nullptr) {
        return 1;
    }
    Unk_446620(field_0, &device);
    device->vf1();
    Unk_InputElement elements[7] = {
        Unk_InputElement(0, 0, 0x10),
        Unk_InputElement(2, 0, 0x10),
        Unk_InputElement(2, 1, 0x10),
        Unk_InputElement(2, 2, 0x10),
        Unk_InputElement(2, 3, 0x10),
        Unk_InputElement(2, 4, 0x10),
        Unk_InputElement(2, 5, 0x10),
    };
    void* arg3 = field_0->vf37(0);
    s32 arg4 = field_0->vf39(0);
    return device->vf70(elements, 7, arg3, arg4, &field_299b8[6]);
}

// 0x710046d5e0
s32 TEXSHADERSET::Unk_46d5e0() {
    if (field_0 == nullptr) {
        return -1;
    }
    IGPUDevice* device;
    Unk_InputElement elements[6] = {
        Unk_InputElement(0, 0, 0x10),
        Unk_InputElement(2, 0, 0x2),
        Unk_InputElement(2, 1, 0x2),
        Unk_InputElement(2, 2, 0x2),
        Unk_InputElement(2, 3, 0x2),
        Unk_InputElement(2, 4, 0x2),
    };
    if (field_299b8[11] != nullptr) {
        return 1;
    }
    Unk_446620(field_0, &device);
    device->vf1();
    void* arg3 = field_0->vf37(0);
    s32 arg4 = field_0->vf39(0);
    return device->vf70(elements, 6, arg3, arg4, &field_299b8[11]);
}

// 0x710046d6f0
s32 TEXSHADERSET::Unk_46d6f0() {
    if (field_0 == nullptr) {
        return -1;
    }
    IGPUDevice* device;
    Unk_InputElement elements[3] = {
        Unk_InputElement(0, 0, 0x6),
        Unk_InputElement(2, 0, 0x2),
        Unk_InputElement(2, 1, 0x2),
    };
    if (field_299b8[12] != nullptr) {
        return 1;
    }
    Unk_446620(field_0, &device);
    device->vf1();
    void* arg3 = field_0->vf37(0);
    s32 arg4 = field_0->vf39(0);
    return device->vf70(elements, 3, arg3, arg4, &field_299b8[12]);
}

// 0x710046d7e0
s32 TEXSHADERSET::InitializeDevice(IGPUDevice* device, bool keepEffect) {
#line 4908
    PPFX_LOG("==== TEXSHADERSET::InitializeDevice() ====\n");
    if (!keepEffect) {
        s32 result = CreateEffect(device);
        if (result < 0) {
#line 4924
            PPFX_ERROR("TEXSHADERSET::InitializeDevice(): CreateEffect() failed (0x%x: %s).\n", result, Unk_446df0(result));
            return result;
        }
    }
    if (field_0 != nullptr) {
        s32 result = field_0->vf10();
        if (result < 0) {
#line 4940
            PPFX_ERROR("TEXSHADERSET::InitializeDevice(): m_pEffect->OnResetDevice() failed (0x%x: %s).\n", result, Unk_446df0(result));
            return result;
        }
        f32 value[4] = {};
        bool flag = device->field_58;
        value[0] = 1.0f;
        value[1] = flag ? 1.0f : -1.0f;
        field_0->vf20(field_a0, value);
    }
#line 5367
    PPFX_LOG("==== TEXSHADERSET::InitializeDevice() succeeded. ====\n");
    return 0;
}

// 0x710046db60
CTextureUtil::CTextureUtil(const char* name) : CGPUResourceManage(nullptr) {
    Unk_46dc60(name);
}

// A member object named after its owner: the name is made first, and the
// object from its text (one line each in the original, by their __LINE__s).
#define UNK_NEW_NAMED(member, T, suffix)                   do {                                                       Unk_TFXString name_ = field_10 + suffix;               const char* text_ = name_.field_8;                     member = UNK_NEW(T)(text_);                        } while (0)

// 0x710046dc60: names the object, makes its texture pool and its measurement
// texture, and fills the sample points
s32 CTextureUtil::Unk_46dc60(const char* name) {
    if (name != nullptr && name[0] != '\0') {
        field_10 = Unk_TFXString(Unk_1b3516c) + " " + name;
    } else {
        field_10 = Unk_1b3516c;
    }
#line 5530
    UNK_NEW_NAMED(field_29a58, CRenderTexturePool, "::m_pTexturePool");
    Unk_24e2d50[0] = Unk_SamplePoint(0.12545430660247803f, -0.6233202219009399f);
    Unk_24e2d50[1] = Unk_SamplePoint(-0.012919187545776367f, 0.2008380889892578f);
    Unk_24e2d50[2] = Unk_SamplePoint(-0.013421475887298584f, -0.9243490695953369f);
    Unk_24e2d50[3] = Unk_SamplePoint(0.391507625579834f, -0.02421402931213379f);
    Unk_24e2d50[4] = Unk_SamplePoint(-0.47500234842300415f, 0.5201195478439331f);
    Unk_24e2d50[5] = Unk_SamplePoint(0.185394287109375f, -0.7468999624252319f);
    Unk_24e2d50[6] = Unk_SamplePoint(-0.9652976989746094f, -0.2772960662841797f);
    Unk_24e2d50[7] = Unk_SamplePoint(0.7774732112884521f, -0.8726856708526611f);
    Unk_Clear();
#line 5694
    UNK_NEW_NAMED(field_29a98, CRenderTexture, "::m_pTextureMeasurement");
    s32 result = field_29a98->Unk_Create(0, 0x10, 0x10, 0x1c);
    return result < 0 ? result : 0;
}

// 0x710046e360: the colour chart's bars (the members' names are in the strings)
s32 CTextureUtil::Unk_46e360(s32 width, s32 height, s32 format) {
    s32 result;
    if (field_29b00 != nullptr) {
        if (field_29b00->field_a8 != nullptr && field_29b00->field_b8[0] != nullptr) {
            return 1;
        }
        if (field_20 == nullptr) {
            return 0;
        }
        field_29b00->vf0(field_20);
        field_29b08[1]->vf0(field_20);
        field_29b08[0]->vf0(field_20);
        field_29b08[2]->vf0(field_20);
        return field_29b08[3]->vf0(field_20);
    }
#line 5893
    UNK_NEW_NAMED(field_29b00, CRenderTexture, "::m_pRenderTextureColorChart_ColorBar");
    UNK_NEW_NAMED(field_29b08[0], CRenderTexture, "::m_pRenderTextureColorChart_ColorBarGraded");
    UNK_NEW_NAMED(field_29b08[1], CRenderTexture, "::m_pRenderTextureColorChart_ColorBar_Small");
    UNK_NEW_NAMED(field_29b08[2], CRenderTexture, "::m_pRenderTextureColorChart_ColorBarGraded_Small");
    UNK_NEW_NAMED(field_29b08[3], CRenderTexture, "::m_pRenderTextureColorChart_ColorBarLuminance");
    field_29b00->Unk_Create(0, width, height, format);
    field_29b08[0]->Unk_Create(0, width, height, format);
    field_29b08[1]->Unk_Create(0, width, height, format);
    field_29b08[2]->Unk_Create(0, width, height, format);
    result = field_29b08[3]->Unk_Create(0, width, 4, format);
    if (field_20 != nullptr) {
        field_29b00->vf0(field_20);
        field_29b08[0]->vf0(field_20);
        field_29b08[1]->vf0(field_20);
        field_29b08[2]->vf0(field_20);
        result = field_29b08[3]->vf0(field_20);
    }
    return result;
}

// 0x710046e740: the colour chart's chromaticity diagrams
s32 CTextureUtil::Unk_46e740(s32 width, s32 height, s32 format) {
    s32 result;
    if (field_29b08[4] != nullptr) {
        if (field_29b08[4]->field_a8 != nullptr && field_29b08[4]->field_b8[0] != nullptr) {
            return 1;
        }
        if (field_20 == nullptr) {
            return 0;
        }
        field_29b08[4]->vf0(field_20);
        field_29b08[5]->vf0(field_20);
        field_29b08[6]->vf0(field_20);
        return field_29b08[7]->vf0(field_20);
    }
#line 5973
    UNK_NEW_NAMED(field_29b08[4], CRenderTexture, "::m_pRenderTextureColorChart_ChromaticityDiagram");
    UNK_NEW_NAMED(field_29b08[5], CRenderTexture, "::m_pRenderTextureColorChart_ChromaticityDiagramLegacy");
    UNK_NEW_NAMED(field_29b08[6], CRenderTexture, "::m_pRenderTextureColorChart_ChromaticityDiagramUV");
    UNK_NEW_NAMED(field_29b08[7], CRenderTexture, "::m_pRenderTextureColorChart_ChromaticityDiagramLegacyUV");
    field_29b08[4]->Unk_Create(0, width, height, format);
    field_29b08[5]->Unk_Create(0, width, height, format);
    field_29b08[6]->Unk_Create(0, width, height, format);
    result = field_29b08[7]->Unk_Create(0, width, height, format);
    if (field_20 != nullptr) {
        field_29b08[4]->vf0(field_20);
        field_29b08[5]->vf0(field_20);
        field_29b08[6]->vf0(field_20);
        result = field_29b08[7]->vf0(field_20);
    }
    return result;
}

// 0x710046ea80: the colour chart's waveform monitor and its source
s32 CTextureUtil::Unk_46ea80(s32 width, s32 height) {
    s32 result;
    if (field_29b08[8] != nullptr) {
        if (field_29b08[8]->field_a8 != nullptr && field_29b08[8]->field_b8[0] != nullptr) {
            return 1;
        }
        if (field_20 == nullptr) {
            return 0;
        }
        field_29b08[8]->vf0(field_20);
        return field_29b08[9]->vf0(field_20);
    }
#line 6026
    UNK_NEW_NAMED(field_29b08[8], CRenderTexture, "::m_pRenderTextureColorChart_WaveformMonitor");
    field_29b08[8]->Unk_Create(0, width, height, 0x1c);
#line 6039
    UNK_NEW_NAMED(field_29b08[9], CRenderTexture, "::m_pRenderTextureColorChart_WaveformSource");
    result = field_29b08[9]->Unk_Create(0, width, height, 0xa);
    if (field_20 != nullptr) {
        field_29b08[8]->vf0(field_20);
        result = field_29b08[9]->vf0(field_20);
    }
    return result;
}

// the power of two that isn't less than `value`
static inline f64 Unk_PowerOfTwo(s32 value) {
    f64 exponent = log(static_cast<f64>(value)) / log(2.0);
    s32 whole = static_cast<s32>(exponent);
    if (exponent != static_cast<f64>(whole)) {
        whole = static_cast<s32>(exponent + 1.0);
    }
    return ldexp(1.0, whole);
}

// 0x710046ec80: the colour chart's textures for a target of that size
s32 CTextureUtil::Unk_46ec80(u32 width, u32 height) {
    s32 barWidth = static_cast<s32>(Unk_PowerOfTwo(width >> 1));
    u32 barHeight = static_cast<u32>(barWidth) >> 3;
    barHeight = barHeight > 0x80 ? barHeight : 0x80;
    f64 diagram = Unk_PowerOfTwo(height >> 1);
    f64 waveform = Unk_PowerOfTwo(width >> 1);
    s32 result = Unk_46e360(barWidth, barHeight, 0xa);
    if (result < 0) {
        return result;
    }
    result = Unk_46e740(static_cast<s32>(diagram), static_cast<s32>(diagram), 0xa);
    if (result < 0) {
        return result;
    }
    return Unk_46ea80(static_cast<s32>(waveform), static_cast<s32>(waveform));
}

// 0x710046d990: releases the effect's objects, and with no argument the
// effect and its file too
s32 TEXSHADERSET::Unk_46d990(void* arg) {
    if (field_0 != nullptr) {
        s32 result = field_0->vf11();
        if (result < 0) {
            return result;
        }
    }
    if (arg == nullptr) {
        PPFX_SAFE_RELEASE_INTERFACE(field_0);
        // an array of bytes: nothing to destroy (the count is still before it)
        if (field_29a20 != nullptr) {
            Unk_4b9a60(Unk_238d5f8, reinterpret_cast<u64*>(field_29a20) - 1);
            field_29a20 = nullptr;
        }
    }
    for (s32 i = 0; i < 13; i++) {
        PPFX_SAFE_RELEASE_INTERFACE(field_299b8[i]);
    }
    return 0;
}

}  // namespace PPFX

// 0x710046e270: CTextureUtil::InitializeDeviceSharedTexturePoolWithCheck (its
// log lines), under the placeholder name its caller gave it
s32 Unk_46e270(void* self_, u32) {
    PPFX::CTextureUtil* self = static_cast<PPFX::CTextureUtil*>(self_);
    s32 result = self->field_29a58->vf0(self->field_20);
    if (result < 0) {
#line 5837
        PPFX_ERROR("CTextureUtil::InitializeDeviceSharedTexturePoolWithCheck(): m_pTexturePool->InitializeDevice() failed (0x%x: %s).\n", result, Unk_446df0(result));
        return result;
    }
#line 5841
    PPFX_LOG("CTextureUtil::InitializeDeviceSharedTexturePoolWithCheck(): m_pTexturePool->InitializeDevice() succeeded.\n");
    return result;
}

namespace PPFX {

// 0x710046edd0: CTextureUtil::InitializeDevice (its log lines): the device's
// objects, and the shared textures (the dither matrix, the film grain, the
// spectrum, the radius's Gaussian fade, the zero, grey and one textures, the
// analyzer's) and the rectangles' and lights' vertex and index buffers
// NON_MATCHING: a first draft with the original's calls, constants and
// arguments. The original passes Unk_46e270 its 0 and Unk_462330 its 2.2
// (the definitions here don't read them, so DeadArgElim drops them at these
// call sites), folds only the first nine of the dither levels (here 13), stores
// the order table as 32-bit pairs, and has no empty-array test in the lights'
// constructor loop (Unk_NewArray's pointer loop keeps one).
s32 CTextureUtil::vf0(IGPUDevice* device) {
#line 6099
    PPFX_LOG("==== CTextureUtil::InitializeDevice() ====\n");
    s32 effect = field_29bb0 != nullptr ? static_cast<Unk_29bb0*>(field_29bb0)->vf4(device) : -1;
    s32 result = CGPUResourceManage::vf0(device);
    if (result < 0) {
#line 6112
        PPFX_ERROR("CTextureUtil::InitializeDevice(): CGPUResourceManage::InitializeDevice() failed (0x%x: %s).\n", result, Unk_446df0(result));
        return result;
    }
    if (field_20 == nullptr) {
        return 0;
    }
    result = field_30.InitializeDevice(field_20, effect >= 0);
    if (result < 0) {
#line 6136
        PPFX_ERROR("CTextureUtil::InitializeDevice(): m_shaderSet.InitializeDevice() failed (0x%x: %s).\n", result, Unk_446df0(result));
        return result;
    }
#line 6140
    PPFX_LOG("CTextureUtil::InitializeDevice(): m_shaderSet.InitializeDevice() succeeded.\n");
    Unk_470610(32.0f, 1.0f);
    field_29a64 = 0;
    field_29a68 = 1;
    field_29a6c = false;
    if (field_29a60) {
        result = Unk_46e270(this, 0);
        if (result < 0) {
#line 6165
            PPFX_ERROR("CTextureUtil::InitializeDevice(): InitializeDeviceSharedTexturePool() failed (0x%x: %s).\n", result, Unk_446df0(result));
            return result;
        }
    }
    result = field_29a98->vf0(field_20);
    if (result < 0) {
        return result;
    }
    if (field_29b00 != nullptr) {
        field_29b00->vf0(field_20);
    }
    for (s32 i = 0; i < 10; i++) {
        if (field_29b08[i] != nullptr) {
            field_29b08[i]->vf0(field_20);
        }
    }

    // the 4 x 4 dither matrix
    {
        Unk_Float order[16] = {0.0f, 8.0f, 2.0f, 10.0f, 12.0f, 4.0f, 14.0f, 6.0f,
                         3.0f, 11.0f, 1.0f, 9.0f, 15.0f, 7.0f, 13.0f, 5.0f};
        f32 levels[16][4];
        for (s32 i = 0; i < 16; i++) {
            for (s32 j = 0; j < 4; j++) {
                levels[i][j] = order[i].field_0 / 16.0f + 1.0f / 32.0f;
            }
        }
        u8 pixels[64];
        for (s32 i = 0; i < 64; i++) {
            pixels[i] = static_cast<u8>((&levels[0][0])[i] * 255.9999f);
        }
        result = field_20->vf60(4, 4, 1, 0, 0x1c, 0, 0, &field_29a70[0], 0);
        if (result < 0) {
#line 6299
            PPFX_ERROR("CTextureUtil::InitializeDevice(): m_pGPUDevice->CreateTexture(&m_pGPUTextureFullColorDitherMatrix) failed (0x%x: %s).\n", result, Unk_446df0(result));
            return result;
        }
        static_cast<IGPUBaseTexture*>(field_29a70[0])->vf9(pixels, 0, 0, false);
        static_cast<IGPUBaseTexture*>(field_29a70[0])->vf15(0xd);
    }

    // the film grain
    if (field_29ab0) {
        result = field_20->vf60(0x100, 0x100, 0, 0, 0x1c, 0, 0, &field_29ab8[0], 4);
        if (result < 0) {
#line 6385
            PPFX_ERROR("CTextureUtil::InitializeDevice(): m_pGPUDevice->CreateTexture(&m_pGPUTextureFilmGrain) failed (0x%x: %s).\n", result, Unk_446df0(result));
            return result;
        }
        Unk_446ae0(0x1c);
        Unk_462330(static_cast<IGPUBaseTexture*>(field_29ab8[0]), Unk_1e7a12c, true, true, nullptr, 2.2f);
        static_cast<IGPUBaseTexture*>(field_29ab8[0])->vf15(0xf);
    }

    // the spectrum, 350 to 730 nm
    result = field_20->vf60(0x100, 1, 0, 0, 0x1c, 0, 0, &field_29ab8[1], 4);
    if (result < 0) {
#line 6595
        PPFX_ERROR("CTextureUtil::InitializeDevice(): m_pGPUDevice->CreateTexture(&m_pGPUTextureSpectrum) failed (0x%x: %s).\n", result, Unk_446df0(result));
        return result;
    }
    {
        u32 bpp = Unk_446ae0(0x1c);
#line 6609
        u8* pixels = UNK_NEW_ARRAY(u8, bpp * 0x100);
        for (u32 i = 0; i < 0x100; i++) {
            Unk_Float4 color = Unk_4116f0(static_cast<f32>(i) * (380.0f / 255.0f) + 350.0f, 2.2f, 0.2f, 0, true, true);
            if (i == 0 || i == 0xff) {
                color = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
            }
            *reinterpret_cast<u32*>(&pixels[i * bpp]) = Unk_PackColorABGR(color);
        }
        Unk_462330(static_cast<IGPUBaseTexture*>(field_29ab8[1]), pixels, true, true, nullptr, 2.2f);
        Unk_4b9a60(Unk_238d5f8, reinterpret_cast<u64*>(pixels) - 1);
        static_cast<IGPUBaseTexture*>(field_29ab8[1])->vf15(3);
    }

    // the lights
    if (field_29ae8 != 0) {
        field_29af0 = field_29ae8;
#line 6861
        field_29af8 = UNK_NEW_ARRAY(Unk_29af8, static_cast<u32>(field_29ae8));
    }

    // the radius's Gaussian fade, with its levels
    {
        u32 levels = Unk_446aa0(0x40, 0, 0) - 2;
        result = field_20->vf60(0x40, 0x40, levels, 0, 0x3d, 0, 0, &field_29ab8[2], levels == 1 ? 0 : 4);
        if (result < 0) {
#line 6895
            PPFX_ERROR("CTextureUtil::InitializeDevice(): m_pGPUDevice->CreateTexture(&m_pGPUTextureRadiusGaussianFade) failed (0x%x: %s).\n", result, Unk_446df0(result));
            return result;
        }
        u32 bpp = Unk_446ae0(0x3d);
#line 6907
        u8* pixels = UNK_NEW_ARRAY(u8, bpp * 0x40 * 0x40);
        IGPUBaseTexture* texture = static_cast<IGPUBaseTexture*>(field_29ab8[2]);
        u32 count = texture->vf12();
        for (u32 level = 0; level < count; level++) {
            u32 size = 0x40u >> level;
            size = size > 1 ? size : 1;
            Unk_Float2 extent;
            extent.field_0[0].field_0 = 1.0f / static_cast<f32>(size);
            extent.field_0[1].field_0 = 1.0f / static_cast<f32>(size);
            for (u32 y = 0; y < size; y++) {
                for (u32 x = 0; x < size; x++) {
                    Unk_Float2 position;
                    position.field_0[0].field_0 = (static_cast<f32>(x) + 0.5f) / static_cast<f32>(size);
                    position.field_0[1].field_0 = (static_cast<f32>(y) + 0.5f) / static_cast<f32>(size);
                    Unk_Float value;
                    if (extent.field_0[0].field_0 >= 1.0f || extent.field_0[1].field_0 >= 1.0f) {
                        value = 0.0f;
                    } else {
                        f32 distance = Unk_Distance(&position, &extent);
                        f32 sigma = 1.0f / 1.7f;
                        f32 fade = expf(-(distance * distance) / (sigma * sigma));
                        if (distance > 0.75f) {
                            if (distance < 1.0f) {
                                fade *= (1.0f - distance) / (1.0f - 0.75f);
                            } else {
                                fade = 0.0f;
                            }
                        }
                        value = fade;
                    }
                    Unk_Float4 color(value, value, value, value);
                    pixels[(y * size + x) * bpp] = Unk_PackColorABGR(color) >> 24;
                }
            }
            static_cast<IGPUBaseTexture*>(field_29ab8[2])->vf9(pixels, level, 0, true);
        }
        if (pixels != nullptr) {
            Unk_4b9a60(Unk_238d5f8, reinterpret_cast<u64*>(pixels) - 1);
        }
        static_cast<IGPUBaseTexture*>(field_29ab8[2])->vf15(3);
    }

    // two textures from images (their messages are the dither matrix's)
    if (field_29ad0) {
        result = field_20->vf60(0xa0, 0x230, 1, 0, 0x1c, 0, 0, &field_29ad8[0], 0);
        if (result < 0) {
#line 6978
            PPFX_ERROR("CTextureUtil::InitializeDevice(): m_pGPUDevice->CreateTexture(&m_pGPUTextureFullColorDitherMatrix) failed (0x%x: %s).\n", result, Unk_446df0(result));
            return result;
        }
#line 6998
        u8* pixels = UNK_NEW_ARRAY(u8, 0xa0 * 0x230 * 4);
        const u16* source = reinterpret_cast<const u16*>(Unk_1b35249);
        u16* target = reinterpret_cast<u16*>(pixels);
        for (u32 i = 0; i < 0xa0 * 0x230; i++) {
            target[i * 2] = source[i];
            target[i * 2 + 1] = source[i];
        }
        static_cast<IGPUBaseTexture*>(field_29ad8[0])->vf9(pixels, 0, 0, false);
        static_cast<IGPUBaseTexture*>(field_29ad8[0])->vf15(0xd);
        Unk_4b9a60(Unk_238d5f8, reinterpret_cast<u64*>(pixels) - 1);
    }
    if (field_29ad0) {
        result = field_20->vf60(0x40, 0x10, 1, 0, 0x3d, 0, 0, &field_29ad8[1], 0);
        if (result < 0) {
#line 7035
            PPFX_ERROR("CTextureUtil::InitializeDevice(): m_pGPUDevice->CreateTexture(&m_pGPUTextureFullColorDitherMatrix) failed (0x%x: %s).\n", result, Unk_446df0(result));
            return result;
        }
#line 7053
        u8* pixels = UNK_NEW_ARRAY(u8, 0x400);
        memcpy(pixels, Unk_1b60e49, 0x400);
        static_cast<IGPUBaseTexture*>(field_29ad8[1])->vf9(pixels, 0, 0, false);
        static_cast<IGPUBaseTexture*>(field_29ad8[1])->vf15(0xd);
        if (pixels != nullptr) {
            Unk_4b9a60(Unk_238d5f8, reinterpret_cast<u64*>(pixels) - 1);
        }
    }

    // one pixel of zero, grey and one
    field_29a70[1] = nullptr;
    result = field_20->vf60(1, 1, 1, 0, 0x1c, 0, 0, &field_29a70[2], 0);
    if (result < 0) {
#line 7166
        PPFX_ERROR("CTextureUtil::InitializeDevice(): m_pGPUDevice->CreateTexture(&m_pGPUTextureZero) failed (0x%x: %s).\n", result, Unk_446df0(result));
        return result;
    }
    {
        u32 bpp = Unk_446ae0(0x1c);
#line 7190
        u8* pixels = UNK_NEW_ARRAY(u8, bpp);
        memset(pixels, 0, bpp);
        static_cast<IGPUBaseTexture*>(field_29a70[2])->vf9(pixels, 0, 0, false);
        if (pixels != nullptr) {
            Unk_4b9a60(Unk_238d5f8, reinterpret_cast<u64*>(pixels) - 1);
        }
        static_cast<IGPUBaseTexture*>(field_29a70[2])->vf15(5);
    }
    result = field_20->vf60(1, 1, 1, 0, 0x1c, 0, 0, &field_29a70[3], 0);
    if (result < 0) {
#line 7229
        PPFX_ERROR("CTextureUtil::InitializeDevice(): m_pGPUDevice->CreateTexture(&m_pGPUTextureGray) failed (0x%x: %s).\n", result, Unk_446df0(result));
        return result;
    }
    {
        u32 bpp = Unk_446ae0(0x1c);
#line 7240
        u8* pixels = UNK_NEW_ARRAY(u8, bpp);
        memset(pixels, 0x7f, bpp);
        static_cast<IGPUBaseTexture*>(field_29a70[3])->vf9(pixels, 0, 0, false);
        if (pixels != nullptr) {
            Unk_4b9a60(Unk_238d5f8, reinterpret_cast<u64*>(pixels) - 1);
        }
        static_cast<IGPUBaseTexture*>(field_29a70[3])->vf15(5);
    }
    result = field_20->vf60(1, 1, 1, 0, 0x1c, 0, 0, &field_29a70[4], 0);
    if (result < 0) {
#line 7279
        PPFX_ERROR("CTextureUtil::InitializeDevice(): m_pGPUDevice->CreateTexture(&m_pGPUTextureOne) failed (0x%x: %s).\n", result, Unk_446df0(result));
        return result;
    }
    {
        u32 bpp = Unk_446ae0(0x1c);
#line 7290
        u8* pixels = UNK_NEW_ARRAY(u8, bpp);
        memset(pixels, 0xff, bpp);
        static_cast<IGPUBaseTexture*>(field_29a70[4])->vf9(pixels, 0, 0, false);
        if (pixels != nullptr) {
            Unk_4b9a60(Unk_238d5f8, reinterpret_cast<u64*>(pixels) - 1);
        }
        static_cast<IGPUBaseTexture*>(field_29a70[4])->vf15(5);
    }

    // the analyzer's 16 x 16 ramp
    result = field_20->vf60(0x10, 0x10, 1, 0, 0x1c, 0, 0, &field_29aa0[1], 0);
    if (result < 0) {
#line 7347
        PPFX_ERROR("CTextureUtil::InitializeDevice(): m_pGPUDevice->CreateTexture(&m_pGPUTextureAnalyzer) failed (0x%x: %s).\n", result, Unk_446df0(result));
        return result;
    }
    {
#line 7363
        u8* pixels = UNK_NEW_ARRAY(u8, 0x400);
        for (u32 i = 0; i < 0x100; i++) {
            pixels[i * 4 + 0] = i;
            pixels[i * 4 + 1] = i;
            pixels[i * 4 + 2] = i;
            pixels[i * 4 + 3] = i;
        }
        static_cast<IGPUBaseTexture*>(field_29aa0[1])->vf9(pixels, 0, 0, false);
        Unk_4b9a60(Unk_238d5f8, reinterpret_cast<u64*>(pixels) - 1);
        static_cast<IGPUBaseTexture*>(field_29aa0[1])->vf15(5);
    }

    // the rectangles' vertex and index buffers
    field_29bb8 = 0;
    field_29bbc = 0xc0;
    field_29bc0 = 0;
    field_29bc4 = 0xc0;
    field_20->vf68(field_29bbc, 0x300, 0x200, reinterpret_cast<IGPUBuffer**>(&field_29bc8[0]), 0x100, nullptr);
    {
        static const u16 indices[4] = {0, 1, 2, 3};
        field_20->vf69(sizeof(indices), 1, 0x39, 0x800, reinterpret_cast<IGPUBuffer**>(&field_29bc8[1]), 0,
                       const_cast<u16*>(indices));
        if ((static_cast<IGPUBuffer*>(field_29bc8[1])->field_24 & 0x800) == 0) {
            memcpy(static_cast<IGPUBuffer*>(field_29bc8[1])->Map(2, 0, 0), indices, sizeof(indices));
            static_cast<IGPUBuffer*>(field_29bc8[1])->Unmap();
        }
    }
    field_20->vf69(field_29bc4, 0x300, 0x39, 0x200, reinterpret_cast<IGPUBuffer**>(&field_29bc8[2]), 0x100, nullptr);

    // a quad for each light, and for each of field_29c00's
    if (field_29ae8 != 0) {
        field_20->vf68(field_29ae8 * 0xb0, field_29aec * 3, 0x200, reinterpret_cast<IGPUBuffer**>(&field_29bc8[3]),
                       0x100, nullptr);
        u32 count = field_29ae8 * 6;
#line 7504
        u16* indices = UNK_NEW_ARRAY(u16, count);
        for (u32 i = 0; i < field_29ae8; i++) {
            u16 index = i * 6;
            indices[index + 0] = i * 4 + 0;
            indices[index + 1] = i * 4 + 1;
            indices[index + 2] = i * 4 + 2;
            indices[index + 3] = i * 4 + 2;
            indices[index + 4] = i * 4 + 1;
            indices[index + 5] = i * 4 + 3;
        }
        field_20->vf69(count * sizeof(u16), 1, 0x39, 0x800, reinterpret_cast<IGPUBuffer**>(&field_29bc8[4]), 0,
                       indices);
        UNK_DELETE_ARRAY(indices);
    }
    if (field_29c00 != 0) {
        field_20->vf68(field_29c00 * 0x160, field_29c04 * 3, 0x200, reinterpret_cast<IGPUBuffer**>(&field_29bc8[5]),
                       0x100, nullptr);
        u32 count = field_29c00 * 6;
#line 7561
        u16* indices = UNK_NEW_ARRAY(u16, count);
        for (u32 i = 0; i < field_29c00; i++) {
            u16 index = i * 6;
            indices[index + 0] = i * 4 + 0;
            indices[index + 1] = i * 4 + 1;
            indices[index + 2] = i * 4 + 2;
            indices[index + 3] = i * 4 + 2;
            indices[index + 4] = i * 4 + 1;
            indices[index + 5] = i * 4 + 3;
        }
        field_20->vf69(count * sizeof(u16), 1, 0x39, 0x800, reinterpret_cast<IGPUBuffer**>(&field_29bc8[6]), 0,
                       indices);
        UNK_DELETE_ARRAY(indices);
    }
#line 7718
    PPFX_LOG("==== CTextureUtil::InitializeDevice() succeeded. ====\n");
    return 0;
}

// the fixed point of y = log(1 + x * y), `count` steps from 1 (inline)
static inline f32 Unk_LogFixedPoint(f32 x, s32 count) {
    f32 y = 1.0f;
    for (s32 i = 0; i < count; i++) {
        y = logf(x * y + 1.0f);
    }
    return y;
}

// 0x7100470610: the effect's three vectors of a curve with the range
// `value` / `scale` (kept to 1.01 to 4096)
void CTextureUtil::Unk_470610(f32 value, f32 scale) {
    f32 ratio = value / scale;
    if (ratio < 1.01f || ratio > 4096.0f) {
        f32 clamped = ratio < 1.01f ? 1.01f : (ratio > 4096.0f ? 4096.0f : ratio);
        scale = value / clamped;
        ratio = value / scale;
    }
    if (ratio < 1.01f || ratio > 4096.0f) {
        f32 clamped = ratio < 1.01f ? 1.01f : (ratio > 4096.0f ? 4096.0f : ratio);
        scale = value / clamped;
        ratio = value / scale;
    }
    f32 inverse = 1.0f / scale;
    f32 x = fmaxf(ratio, 1.0f);
    f32 y;
    if (x <= 1.0f) {
        y = 0.0f;
    } else {
        s32 count;
        if (x >= 10.0f) {
            count = 5;
        } else if (x >= 1.7f) {
            count = 10;
        } else if (x >= 1.5f) {
            count = 20;
        } else if (x >= 1.1f) {
            count = 100;
        } else {
            count = 0;
        }
        if (count != 0) {
            y = Unk_LogFixedPoint(x, count);
        } else {
            f32 y0 = 0.0f;
            f32 y1 = Unk_LogFixedPoint(1.1f, 100);
            y = y0 + (x - 1.0f) * (y1 - y0);
        }
    }
    f32 values[4];
    values[0] = y;
    values[1] = 1.0f / y;
    values[2] = (expf(y) - 1.0f) / value;
    values[3] = value / (expf(y) - 1.0f);
    field_30.field_0->vf20(field_30.field_ec, values);
    values[0] = scale;
    values[1] = inverse;
    values[2] = ratio - 1.0f;
    values[3] = 1.0f / (ratio - 1.0f);
    field_30.field_0->vf20(field_30.field_f0, values);
    values[0] = 4.0f / (ratio * ratio) - 2.0f;
    values[1] = inverse;
    values[2] = 1.0f / (ratio * ratio);
    values[3] = value * value / (scale + scale);
    field_30.field_0->vf20(field_30.field_f4, values);
}

// 0x7100470860
s32 CTextureUtil::Unk_470860(s32 value) {
    field_29a64 = value;
    return 0;
}

// 0x7100470880
s32 CTextureUtil::Unk_470880(bool arg) {
    field_29a6c = false;
    return 0;
}

// 0x71004708a0
s32 CTextureUtil::Unk_4708a0(void* arg) {
    return field_29a58->Unk_49fed0(arg);
}

// 0x7100471410
void CTextureUtil::Unk_471410(s32 arg0, s32 arg1, s32 arg2) {
    field_20->vf39();
    field_20->vf40(-1);
    field_20->vf42(0);
}

// 0x7100471470: the corners of a rectangle in clip space, and of `sets`
// rectangles of texture coordinates (`from` and `to` are opposite corners),
// each through the inverse of its transform in field_29b68 when it has one.
// Without flag 0x10000 the rectangle is a triangle twice its size (`*count`
// corners).
// NON_MATCHING: register allocation and scheduling: the original keeps
// `this` in x19 and `count` in x20 (x20 and x21 here), the viewport's width
// in s13, and orders the hoisted element addresses and the matrices' stores
// otherwise; the frame, the calls and the arithmetic are the same.
s32 CTextureUtil::Unk_471470(s32 sets, const Unk_Float2* from, const Unk_Float2* to, u32 flags, s32* count,
                             Unk_RectPosition* positions, Unk_Float2 (*coords)[4], f32 x, f32 y, f32 width,
                             f32 height) {
    void Unk_4155f0(MATRIXT44 * out, const MATRIXT44* m);
    void Unk_4100f0(Unk_Float2 * out, const Unk_Float2* v, const MATRIXT44* m);
    Unk_Viewport viewport;
    field_20->vf17(&viewport);
    f32 targetWidth = static_cast<f32>(viewport.field_8);
    f32 targetHeight = static_cast<f32>(viewport.field_c);
    f32 x0 = x - targetWidth * 0.5f;
    f32 y0 = y - targetHeight * 0.5f;
    *count = 4;
    Unk_Float2 froms[8];
    Unk_Float2 tos[8];
    f32 x1 = x0 + width;
    f32 y1 = y0 + height;
    f32 scaleX = 2.0f / targetWidth;
    f32 scaleY = 2.0f / targetHeight;
    for (s32 i = 0; i < sets; i++) {
        froms[i] = from[i];
    }
    for (s32 i = 0; i < sets; i++) {
        tos[i] = to[i];
    }
    if (!(flags & 0x10000)) {
        x1 = x0 + (x1 - x0) * 2.0f;
        y0 = y1 + (y0 - y1) * 2.0f;
        *count = 3;
        for (s32 i = 0; i < sets; i++) {
            tos[i].field_0[0] = froms[i].field_0[0].field_0 + (tos[i].field_0[0].field_0 - froms[i].field_0[0].field_0) * 2.0f;
            froms[i].field_0[1] = tos[i].field_0[1].field_0 + (froms[i].field_0[1].field_0 - tos[i].field_0[1].field_0) * 2.0f;
        }
    }
    const f32 offset = 0.0f;
    positions[0].field_0[0] = scaleX * (x0 + offset);
    positions[0].field_0[1] = scaleY * (y1 + offset);
    positions[0].field_0[2] = 0.0f;
    positions[1].field_0[0] = scaleX * (x0 + offset);
    positions[1].field_0[1] = scaleY * (y0 + offset);
    positions[1].field_0[2] = 0.0f;
    positions[2].field_0[0] = scaleX * (x1 + offset);
    positions[2].field_0[1] = scaleY * (y1 + offset);
    positions[2].field_0[2] = 0.0f;
    positions[3].field_0[0] = scaleX * (x1 + offset);
    positions[3].field_0[1] = scaleY * (y0 + offset);
    positions[3].field_0[2] = 0.0f;
    for (s32 i = 0; i < sets; i++) {
        coords[i][0] = Unk_Float2(froms[i].field_0[0], tos[i].field_0[1]);
        coords[i][1] = Unk_Float2(froms[i].field_0[0], froms[i].field_0[1]);
        coords[i][2] = Unk_Float2(tos[i].field_0[0], tos[i].field_0[1]);
        coords[i][3] = Unk_Float2(tos[i].field_0[0], froms[i].field_0[1]);
        if (field_29b68[i] == nullptr) {
            continue;
        }
        MATRIXT44 inverse;
        Unk_4155f0(&inverse, static_cast<const MATRIXT44*>(field_29b68[i]));
        f32 aspectX = field_29ba8;
        f32 dx = to[i].field_0[0].field_0 - from[i].field_0[0].field_0;
        f32 dy = to[i].field_0[1].field_0 - from[i].field_0[1].field_0;
        f32 centerX = from[i].field_0[0].field_0 + dx * 0.5f;
        f32 centerY = from[i].field_0[1].field_0 + dx * 0.5f;
        MATRIXT44 translation;
        translation.field_0[0][0] = 1.0f;
        translation.field_0[0][1] = 0.0f;
        translation.field_0[0][2] = 0.0f;
        translation.field_0[0][3] = 0.0f;
        translation.field_0[1][0] = 0.0f;
        translation.field_0[1][1] = 1.0f;
        translation.field_0[1][2] = 0.0f;
        translation.field_0[1][3] = 0.0f;
        translation.field_0[2][0] = 0.0f;
        translation.field_0[2][1] = 0.0f;
        translation.field_0[2][2] = 1.0f;
        translation.field_0[2][3] = 0.0f;
        translation.field_0[3][0] = -centerX;
        translation.field_0[3][1] = -centerY;
        translation.field_0[3][2] = 0.0f;
        translation.field_0[3][3] = 1.0f;
        MATRIXT44 scale;
        scale.field_0[0][0] = 1.0f / dx * 2.0f;
        scale.field_0[0][1] = 0.0f;
        scale.field_0[0][2] = 0.0f;
        scale.field_0[0][3] = 0.0f;
        scale.field_0[1][0] = 0.0f;
        scale.field_0[1][1] = 1.0f / dy * 2.0f;
        scale.field_0[1][2] = 0.0f;
        scale.field_0[1][3] = 0.0f;
        scale.field_0[2][0] = 0.0f;
        scale.field_0[2][1] = 0.0f;
        scale.field_0[2][2] = 1.0f;
        scale.field_0[2][3] = 0.0f;
        scale.field_0[3][0] = 0.0f;
        scale.field_0[3][1] = 0.0f;
        scale.field_0[3][2] = 0.0f;
        scale.field_0[3][3] = 1.0f;
        MATRIXT44 aspect;
        aspect.field_0[0][0] = aspectX;
        aspect.field_0[0][1] = 0.0f;
        aspect.field_0[0][2] = 0.0f;
        aspect.field_0[0][3] = 0.0f;
        aspect.field_0[1][0] = 0.0f;
        aspect.field_0[1][1] = 1.0f;
        aspect.field_0[1][2] = 0.0f;
        aspect.field_0[1][3] = 0.0f;
        aspect.field_0[2][0] = 0.0f;
        aspect.field_0[2][1] = 0.0f;
        aspect.field_0[2][2] = 1.0f;
        aspect.field_0[2][3] = 0.0f;
        aspect.field_0[3][0] = 0.0f;
        aspect.field_0[3][1] = 0.0f;
        aspect.field_0[3][2] = 0.0f;
        aspect.field_0[3][3] = 1.0f;
        MATRIXT44 flip;
        flip.field_0[0][0] = 1.0f;
        flip.field_0[0][1] = 0.0f;
        flip.field_0[0][2] = 0.0f;
        flip.field_0[0][3] = 0.0f;
        flip.field_0[1][0] = 0.0f;
        Unk_Float sign = field_20->field_58 ? -1.0f : 1.0f;
        flip.field_0[1][1] = sign.field_0;
        flip.field_0[1][2] = 0.0f;
        flip.field_0[1][3] = 0.0f;
        flip.field_0[2][0] = 0.0f;
        flip.field_0[2][1] = 0.0f;
        flip.field_0[2][2] = 1.0f;
        flip.field_0[2][3] = 0.0f;
        flip.field_0[3][0] = 0.0f;
        flip.field_0[3][1] = 0.0f;
        flip.field_0[3][2] = 0.0f;
        flip.field_0[3][3] = 1.0f;
        MATRIXT44 toTexture;
        MATRIXT44 fromTexture;
        MATRIXT44 transform;
        MATRIXT44 product;
        MATRIXT44 product2;
        MATRIXT44_MatrixMultiply(&product, &translation, &scale);
        MATRIXT44_MatrixMultiply(&transform, &product, &aspect);
        MATRIXT44_MatrixMultiply(&fromTexture, &transform, &flip);
        toTexture = fromTexture;
        Unk_4155f0(&fromTexture, &toTexture);
        MATRIXT44_MatrixMultiply(&product2, &toTexture, &inverse);
        MATRIXT44_MatrixMultiply(&product, &product2, &fromTexture);
        transform = product;
        for (s32 j = 0; j < *count; j++) {
            Unk_Float2 point = coords[i][j];
            Unk_4100f0(&coords[i][j], &point, &transform);
        }
    }
    return 0;
}

// 0x7100471960
// NON_MATCHING: the same instructions, but the corners' temporaries are in
// other floating-point registers (the height's half and scale in s3 and s5
// in the original, s2 and s5 here): no order of these eight statements gave
// the original's allocation.
s32 CTextureUtil::Unk_471960(f32 x, f32 y, f32 width, f32 height, u32 flags) {
    if (!(flags & 0x40000)) {
        field_20->vf41(-1, 1);
    }
    if (!(flags & 0x20000)) {
        u8 passes[0x20];
        field_30.field_0->vf33(passes, flags & 0xffff);
        field_30.field_0->vf35(0);
    }
    f32 targetWidth;
    f32 targetHeight;
    {
        Unk_Viewport viewport;
        field_20->vf17(&viewport);
        targetWidth = static_cast<f32>(viewport.field_8);
        targetHeight = static_cast<f32>(viewport.field_c);
    }
    f32 halfWidth = targetWidth * 0.5f;
    f32 halfHeight = targetHeight * 0.5f;
    f32 scaleX = 2.0f / targetWidth;
    f32 scaleY = 2.0f / targetHeight;
    f32 x0 = x - halfWidth;
    f32 x1 = x0 + width;
    f32 y0 = y - halfHeight;
    f32 y1 = y0 + height;
    s32 count;
    if (flags & 0x10000) {
        count = 4;
    } else {
        x1 = x0 + (x1 - x0) * 2.0f;
        y0 = y1 + (y0 - y1) * 2.0f;
        count = 3;
    }
    const f32 offset = 0.0f;
    f32 vertices[4][2];
    vertices[0][0] = scaleX * (x0 + offset);
    vertices[0][1] = scaleY * (y1 + offset);
    vertices[1][0] = scaleX * (x0 + offset);
    vertices[1][1] = scaleY * (y0 + offset);
    vertices[2][0] = scaleX * (x1 + offset);
    vertices[2][1] = scaleY * (y1 + offset);
    vertices[3][0] = scaleX * (x1 + offset);
    vertices[3][1] = scaleY * (y0 + offset);
    field_30.Unk_Layout1();
    s32 result = Unk_DrawVertices(vertices, count, sizeof(vertices[0]), 0);
    if (!(flags & 0x20000)) {
        field_30.field_0->vf36();
        result = field_30.field_0->vf34();
    }
    return result;
}

// 0x7100471c50 to 0x7100472cd0: a rectangle with 1 to 6 rectangles of
// texture coordinates (`from` and `to` are their opposite corners). The
// result is the last call's, and the flags are the last parameter.
// 0x7100471c50
s32 CTextureUtil::Unk_471c50(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 s0, f32 t0, u32 flags) {
    if ((flags & 0x40000) == 0) {
        field_20->vf41(-1, 1);
    }
    if ((flags & 0x20000) == 0) {
        u8 passes[0x20];
        field_30.field_0->vf33(passes, flags & 0xffff);
        field_30.field_0->vf35(0);
    }
    s32 count;
    Unk_RectPosition positions[4];
    Unk_Float2 from[1] = {Unk_Float2(u0, v0)};
    Unk_Float2 to[1] = {Unk_Float2(s0, t0)};
    Unk_Float2 coords[1][4];
    Unk_471470(1, from, to, flags, &count, positions, coords, x, y, width, height);
    Unk_RectVertex<1> vertices[4];
    for (s32 i = 0; i < 4; i++) {
        vertices[i] = Unk_RectVertex<1>(positions[i], coords, i);
    }
    field_30.Unk_46cfe0();
    s32 result = Unk_DrawVertices(vertices, count, sizeof(vertices[0]), 1);
    if ((flags & 0x20000) == 0) {
        field_30.field_0->vf36();
        result = field_30.field_0->vf34();
    }
    return result;
}

// 0x7100471f60
s32 CTextureUtil::Unk_471f60(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 s0, f32 t0, f32 u1, f32 v1, f32 s1, f32 t1, u32 flags) {
    if ((flags & 0x40000) == 0) {
        field_20->vf41(-1, 1);
    }
    if ((flags & 0x20000) == 0) {
        u8 passes[0x20];
        field_30.field_0->vf33(passes, flags & 0xffff);
        field_30.field_0->vf35(0);
    }
    s32 count;
    Unk_RectPosition positions[4];
    Unk_Float2 from[2] = {Unk_Float2(u0, v0), Unk_Float2(u1, v1)};
    Unk_Float2 to[2] = {Unk_Float2(s0, t0), Unk_Float2(s1, t1)};
    Unk_Float2 coords[2][4];
    Unk_471470(2, from, to, flags, &count, positions, coords, x, y, width, height);
    Unk_RectVertex<2> vertices[4];
    for (s32 i = 0; i < 4; i++) {
        vertices[i] = Unk_RectVertex<2>(positions[i], coords, i);
    }
    field_30.Unk_46d0c0();
    s32 result = Unk_DrawVertices(vertices, count, sizeof(vertices[0]), 2);
    if ((flags & 0x20000) == 0) {
        field_30.field_0->vf36();
        result = field_30.field_0->vf34();
    }
    return result;
}

// 0x7100472250
s32 CTextureUtil::Unk_472250(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 s0, f32 t0, f32 u1, f32 v1, f32 s1, f32 t1, f32 u2, f32 v2, f32 s2, f32 t2, u32 flags) {
    if ((flags & 0x40000) == 0) {
        field_20->vf41(-1, 1);
    }
    if ((flags & 0x20000) == 0) {
        u8 passes[0x20];
        field_30.field_0->vf33(passes, flags & 0xffff);
        field_30.field_0->vf35(0);
    }
    s32 count;
    Unk_RectPosition positions[4];
    Unk_Float2 from[3] = {Unk_Float2(u0, v0), Unk_Float2(u1, v1), Unk_Float2(u2, v2)};
    Unk_Float2 to[3] = {Unk_Float2(s0, t0), Unk_Float2(s1, t1), Unk_Float2(s2, t2)};
    Unk_Float2 coords[3][4];
    Unk_471470(3, from, to, flags, &count, positions, coords, x, y, width, height);
    Unk_RectVertex<3> vertices[4];
    for (s32 i = 0; i < 4; i++) {
        vertices[i] = Unk_RectVertex<3>(positions[i], coords, i);
    }
    field_30.Unk_46d1b0();
    s32 result = Unk_DrawVertices(vertices, count, sizeof(vertices[0]), 3);
    if ((flags & 0x20000) == 0) {
        field_30.field_0->vf36();
        result = field_30.field_0->vf34();
    }
    return result;
}

// 0x7100472590
s32 CTextureUtil::Unk_472590(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 s0, f32 t0, f32 u1, f32 v1, f32 s1, f32 t1, f32 u2, f32 v2, f32 s2, f32 t2, f32 u3, f32 v3, f32 s3, f32 t3, u32 flags) {
    if ((flags & 0x40000) == 0) {
        field_20->vf41(-1, 1);
    }
    if ((flags & 0x20000) == 0) {
        u8 passes[0x20];
        field_30.field_0->vf33(passes, flags & 0xffff);
        field_30.field_0->vf35(0);
    }
    s32 count;
    Unk_RectPosition positions[4];
    Unk_Float2 from[4] = {Unk_Float2(u0, v0), Unk_Float2(u1, v1), Unk_Float2(u2, v2), Unk_Float2(u3, v3)};
    Unk_Float2 to[4] = {Unk_Float2(s0, t0), Unk_Float2(s1, t1), Unk_Float2(s2, t2), Unk_Float2(s3, t3)};
    Unk_Float2 coords[4][4];
    Unk_471470(4, from, to, flags, &count, positions, coords, x, y, width, height);
    Unk_RectVertex<4> vertices[4];
    for (s32 i = 0; i < 4; i++) {
        vertices[i] = Unk_RectVertex<4>(positions[i], coords, i);
    }
    field_30.Unk_46d2a0();
    s32 result = Unk_DrawVertices(vertices, count, sizeof(vertices[0]), 4);
    if ((flags & 0x20000) == 0) {
        field_30.field_0->vf36();
        result = field_30.field_0->vf34();
    }
    return result;
}

// 0x7100472900
s32 CTextureUtil::Unk_472900(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 s0, f32 t0, f32 u1, f32 v1, f32 s1, f32 t1, f32 u2, f32 v2, f32 s2, f32 t2, f32 u3, f32 v3, f32 s3, f32 t3, f32 u4, f32 v4, f32 s4, f32 t4, u32 flags) {
    if ((flags & 0x40000) == 0) {
        field_20->vf41(-1, 1);
    }
    if ((flags & 0x20000) == 0) {
        u8 passes[0x20];
        field_30.field_0->vf33(passes, flags & 0xffff);
        field_30.field_0->vf35(0);
    }
    s32 count;
    Unk_RectPosition positions[4];
    Unk_Float2 from[5] = {Unk_Float2(u0, v0), Unk_Float2(u1, v1), Unk_Float2(u2, v2), Unk_Float2(u3, v3), Unk_Float2(u4, v4)};
    Unk_Float2 to[5] = {Unk_Float2(s0, t0), Unk_Float2(s1, t1), Unk_Float2(s2, t2), Unk_Float2(s3, t3), Unk_Float2(s4, t4)};
    Unk_Float2 coords[5][4];
    Unk_471470(5, from, to, flags, &count, positions, coords, x, y, width, height);
    Unk_RectVertex<5> vertices[4];
    for (s32 i = 0; i < 4; i++) {
        vertices[i] = Unk_RectVertex<5>(positions[i], coords, i);
    }
    field_30.Unk_46d3a0();
    s32 result = Unk_DrawVertices(vertices, count, sizeof(vertices[0]), 5);
    if ((flags & 0x20000) == 0) {
        field_30.field_0->vf36();
        result = field_30.field_0->vf34();
    }
    return result;
}

// 0x7100472cd0
s32 CTextureUtil::Unk_472cd0(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 s0, f32 t0, f32 u1, f32 v1, f32 s1, f32 t1, f32 u2, f32 v2, f32 s2, f32 t2, f32 u3, f32 v3, f32 s3, f32 t3, f32 u4, f32 v4, f32 s4, f32 t4, f32 u5, f32 v5, f32 s5, f32 t5, u32 flags) {
    if ((flags & 0x40000) == 0) {
        field_20->vf41(-1, 1);
    }
    if ((flags & 0x20000) == 0) {
        u8 passes[0x20];
        field_30.field_0->vf33(passes, flags & 0xffff);
        field_30.field_0->vf35(0);
    }
    s32 count;
    Unk_RectPosition positions[4];
    Unk_Float2 from[6] = {Unk_Float2(u0, v0), Unk_Float2(u1, v1), Unk_Float2(u2, v2), Unk_Float2(u3, v3), Unk_Float2(u4, v4), Unk_Float2(u5, v5)};
    Unk_Float2 to[6] = {Unk_Float2(s0, t0), Unk_Float2(s1, t1), Unk_Float2(s2, t2), Unk_Float2(s3, t3), Unk_Float2(s4, t4), Unk_Float2(s5, t5)};
    Unk_Float2 coords[6][4];
    Unk_471470(6, from, to, flags, &count, positions, coords, x, y, width, height);
    Unk_RectVertex<6> vertices[4];
    for (s32 i = 0; i < 4; i++) {
        vertices[i] = Unk_RectVertex<6>(positions[i], coords, i);
    }
    field_30.Unk_46d4b0();
    s32 result = Unk_DrawVertices(vertices, count, sizeof(vertices[0]), 6);
    if ((flags & 0x20000) == 0) {
        field_30.field_0->vf36();
        result = field_30.field_0->vf34();
    }
    return result;
}

// DRAWRECTGPU_BEGIN
// 0x7100473d90
s32 CTextureUtil::Unk_473d90(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 arg9, f32 arg10,
                             f32 arg11, f32 arg12, f32 arg13, const Unk_Float4* arg1, const Unk_Float4* arg2,
                             const Unk_Float4* matrix, Unk_GPUTexture* texture, u32 flags) {
    field_30.field_0->vf29(field_30.field_1b32c);
    if (matrix != nullptr) {
        for (s32 i = 0; i < 4; i++) {
            Unk_24e4c18[i] = matrix[i];
        }
    } else {
        memset(Unk_24e4c18, 0, sizeof(Unk_Float4) * 4);
    }
    field_30.field_0->vf22(field_30.field_c4, Unk_24e4c18, 4);
    field_30.field_0->vf22(field_30.field_c8, Unk_24e4c18, 0);
    Unk_24e4c18[0] = Unk_Float4(arg9, 1.0f / arg9, arg10, arg11);
    Unk_24e4c18[1] = *arg1;
    Unk_24e4c18[2] = *arg2;
    Unk_24e4c18[3].field_0[0] = arg12;
    Unk_24e4c18[3].field_0[1] = arg13;
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4c18, 4);
    if (texture != nullptr) {
        field_30.field_0->vf26(field_30.field_8, texture);
        s32 filter = texture->vf16();
        texture->vf17(1);
        s32 result = Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
        texture->vf15(filter);
        return result;
    }
    return Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
}

// 0x7100475150
s32 CTextureUtil::Unk_475150(CRenderTexture* source, CRenderTexture* target, bool clear) {
    if (clear) {
        Unk_471410();
    }
    f32 u1;
    f32 v1;
    Unk_GetCoords(source, &u1, &v1);
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result >= 0) {
        CRenderTexture::Unk_49cf50(nullptr, nullptr);
        Unk_GPUTexture* texture = Unk_GetTexture(source);
        field_30.field_0->vf29(field_30.field_7dac);
        field_30.field_0->vf26(field_30.field_10[0], texture);
        Unk_24e4c18[0].field_0[0] = source->field_88;
        Unk_24e4c18[0].field_0[1] = source->field_8c;
        Unk_24e4c18[0].field_0[2] = 0.0f;
        Unk_24e4c18[0].field_0[3] = 0.0f;
        field_30.field_0->vf22(field_30.field_d4, Unk_24e4c18, 1);
        s32 filter = texture->vf16();
        texture->vf15(5);
        result = Unk_471c50(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, 0);
        texture->vf15(filter);
        result = result < 0 ? result : 0;
    }
    return result;
}

// 0x7100475320
// NON_MATCHING: the flags' mask (`and w, w, #1`) is before the loop that finds
// the source's texture here and after it in the original, and the registers
// of the parameters follow from that.
s32 CTextureUtil::Unk_475320(f32 arg8, f32 arg9, CRenderTexture* source, CRenderTexture* target,
                             const Unk_Float4* arg3, const Unk_Float4* arg4, const Unk_Float4* arg5,
                             const Unk_Float4* arg6, u32 flags) {
    if (flags & 1) {
        Unk_471410();
    }
    f32 u1;
    f32 v1;
    Unk_GetCoords(source, &u1, &v1);
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result >= 0) {
        CRenderTexture::Unk_49cf50(nullptr, nullptr);
        Unk_GPUTexture* texture = Unk_GetTexture(source);
        field_30.field_0->vf29(field_30.field_7da8);
        Unk_24e4a18[0] = *arg3;
        Unk_24e4a18[1] = *arg4;
        Unk_24e4a18[2] = *arg5;
        Unk_24e4a18[3] = *arg6;
        field_30.field_0->vf22(field_30.field_d0, Unk_24e4a18, 4);
        Unk_Float4 value(arg8, arg9, 0.0f, 0.0f);
        field_30.field_0->vf20(field_30.field_f8, &value.field_0[0].field_0);
        field_30.field_0->vf26(field_30.field_10[0], texture);
        s32 filter = texture->vf16();
        texture->vf15(5);
        result = Unk_471c50(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, flags & 1);
        texture->vf15(filter);
        result = result < 0 ? result : 0;
    }
    return result;
}

// 0x7100473150: a rectangle with `count` (1 to 4) rectangles of texture
// coordinates, given as four arrays
s32 CTextureUtil::Unk_473150(f32 x, f32 y, f32 width, f32 height, const f32* u0, const f32* v0, const f32* u1,
                             const f32* v1, s32 count, u32 flags) {
    if (count < 1 || count > 4) {
        return -4;
    }
    switch (count) {
    case 1:
        return Unk_471c50(x, y, width, height, u0[0], v0[0], u1[0], v1[0], flags);
    case 2:
        return Unk_471f60(x, y, width, height, u0[0], v0[0], u1[0], v1[0], u0[1], v0[1], u1[1], v1[1], flags);
    case 3:
        return Unk_472250(x, y, width, height, u0[0], v0[0], u1[0], v1[0], u0[1], v0[1], u1[1], v1[1], u0[2], v0[2],
                          u1[2], v1[2], flags);
    case 4:
        return Unk_472590(x, y, width, height, u0[0], v0[0], u1[0], v1[0], u0[1], v0[1], u1[1], v1[1], u0[2], v0[2],
                          u1[2], v1[2], u0[3], v0[3], u1[3], v1[3], flags);
    }
    return 0;
}

// 0x71004732b0: draws indexed triangles from the caller's buffers
s32 CTextureUtil::Unk_4732b0(s32 count, s32 arg2, s32 arg3, IGPUBuffer* vertices, void* indices, u32 offset, s32 arg7,
                             u32 flags) {
    if ((flags & 0x40000) == 0) {
        field_20->vf41(-1, 1);
    }
    if ((flags & 0x20000) == 0) {
        u32 passes;
        field_30.field_0->vf33(&passes, flags & 0xffff);
        field_30.field_0->vf35(0);
    }
    field_30.Unk_46d6f0();
    field_30.field_0->vf42(field_30.field_299b8[12], vertices, offset, 0, 0, 1);
    field_20->vf9(indices, arg7);
    field_30.field_0->SetupGraphicsPipelineState();
    s32 result = field_20->vf58(4, count, 0, arg2, arg3);
    if ((flags & 0x20000) == 0) {
        field_30.field_0->vf36();
        result = field_30.field_0->vf34();
    }
    return result;
}

// 0x7100473410: the outline of a rectangle, the space between it and the
// rectangle inside it (the last four numbers), as four rectangles of two
// triangles through the vertex and index buffers. The last rectangle's
// corners are read back from the stack (GVN's scan limit: the indices are
// written in the same loop, which is what puts them out of its reach).
// The buffers' offsets are 32-bit sums (the sizes as u32: with size_t the
// wrap tests are 64-bit compares), and `(flags & 0x20000) == 0` lays the
// first test's blocks out as the original (falling into the vf33/vf35 calls).
// NON_MATCHING: scheduling only: the scheduler interleaves the third and
// fourth rectangles' vertex stores (and the stores of rects[2][0] and
// rects[3][1] to the stack) differently, which renumbers the registers of
// the last rectangle's corners. Tried: the 48 orders of the vertices'
// statements (corner order, x or y first).
s32 CTextureUtil::Unk_473410(f32 x, f32 y, f32 width, f32 height, f32 arg5, f32 arg6, f32 arg7, f32 arg8,
                             u32 flags) {
    Unk_Viewport viewport;
    field_20->vf17(&viewport);
    f32 targetWidth = static_cast<f32>(viewport.field_8);
    f32 targetHeight = static_cast<f32>(viewport.field_c);
    if (!(flags & 0x40000)) {
        field_20->vf41(-1, 1);
    }
    if ((flags & 0x20000) == 0) {
        u8 passes[0x20];
        field_30.field_0->vf33(passes, flags & 0xffff);
        field_30.field_0->vf35(0);
    }
    f32 halfWidth = targetWidth * 0.5f;
    f32 halfHeight = targetHeight * 0.5f;
    f32 scaleX = 2.0f / targetWidth;
    f32 scaleY = 2.0f / targetHeight;
    f32 x0 = x - halfWidth;
    f32 x1 = x0 + width;
    f32 y0 = y - halfHeight;
    f32 y1 = y0 + height;
    f32 innerX0 = arg5 - halfWidth;
    f32 innerX1 = innerX0 + arg7;
    f32 innerY0 = arg6 - halfHeight;
    f32 innerY1 = innerY0 + arg8;
    f32 rects[4][2][2] = {
        {{x0, y0}, {innerX0, innerY1}},
        {{x0, innerY1}, {innerX1, y1}},
        {{innerX1, innerY0}, {x1, y1}},
        {{innerX0, y0}, {x1, innerY0}},
    };
    u16 indices[24];
    f32 vertices[16][2];
    const f32 offset = 0.0f;
    for (s32 i = 0; i < 4; i++) {
        vertices[i * 4 + 0][0] = scaleX * (rects[i][0][0] + offset);
        vertices[i * 4 + 0][1] = scaleY * (rects[i][1][1] + offset);
        vertices[i * 4 + 2][0] = scaleX * (rects[i][1][0] + offset);
        vertices[i * 4 + 2][1] = scaleY * (rects[i][0][1] + offset);
        vertices[i * 4 + 1][0] = scaleX * (rects[i][0][0] + offset);
        vertices[i * 4 + 1][1] = scaleY * (rects[i][0][1] + offset);
        vertices[i * 4 + 3][0] = scaleX * (rects[i][1][0] + offset);
        vertices[i * 4 + 3][1] = scaleY * (rects[i][1][1] + offset);
        indices[i * 6 + 0] = i * 4 + 0;
        indices[i * 6 + 1] = i * 4 + 1;
        indices[i * 6 + 2] = i * 4 + 2;
        indices[i * 6 + 3] = i * 4 + 2;
        indices[i * 6 + 4] = i * 4 + 3;
        indices[i * 6 + 5] = i * 4 + 0;
    }
    field_30.Unk_Layout1();
    u32 vertexStart = field_29bb8;
    bool wrap = vertexStart + static_cast<u32>(sizeof(vertices)) >= field_29bbc;
    if (wrap) {
        vertexStart = 0;
        field_29bb8 = 0;
    }
    field_29bb8 = vertexStart + static_cast<u32>(sizeof(vertices));
    memcpy(static_cast<IGPUBuffer*>(field_29bc8[0])->Map(wrap ? 6 : 2, vertexStart, sizeof(vertices)), vertices,
           sizeof(vertices));
    static_cast<IGPUBuffer*>(field_29bc8[0])->Unmap();
    u32 indexStart = field_29bc0;
    wrap = indexStart + static_cast<u32>(sizeof(indices)) >= field_29bc4;
    if (wrap) {
        indexStart = 0;
        field_29bc0 = 0;
    }
    field_29bc0 = indexStart + static_cast<u32>(sizeof(indices));
    memcpy(static_cast<IGPUBuffer*>(field_29bc8[2])->Map(wrap ? 6 : 2, indexStart, sizeof(indices)), indices,
           sizeof(indices));
    static_cast<IGPUBuffer*>(field_29bc8[2])->Unmap();
    field_30.field_0->vf42(field_30.field_299b8[0], static_cast<IGPUBuffer*>(field_29bc8[0]), vertexStart, 0, 0, 1);
    field_20->vf9(field_29bc8[2], indexStart);
    field_30.field_0->SetupGraphicsPipelineState();
    s32 result = field_20->vf58(4, 24, 0, 0, 15);
    if (!(flags & 0x20000)) {
        field_30.field_0->vf36();
        result = field_30.field_0->vf34();
    }
    return result;
}

// 0x7100474ae0: four taps, half a texel around each corner
s32 CTextureUtil::Unk_474ae0(CRenderTexture* target, CRenderTexture* source, bool clear) {
    if (clear) {
        Unk_471410();
    }
    f32 width0 = static_cast<f32>(static_cast<u32>(source->field_54));
    f32 height0 = static_cast<f32>(static_cast<u32>(source->field_58));
    f32 sx = source->field_88;
    f32 sy = source->field_8c;
    f32 ox = source->field_90;
    f32 oy = source->field_94;
    f32 a = sx * 0.5f + ox;
    f32 b = sy * 0.5f + oy;
    f32 u1 = sx * width0 + ox;
    f32 v1 = sy * height0 + oy;
    Unk_Float4 rects[4];
    rects[0] = Unk_Float4(-a, -b, u1 - a, v1 - b);
    rects[1] = Unk_Float4(a, -b, u1 + a, v1 - b);
    rects[2] = Unk_Float4(-a, b, u1 - a, v1 + b);
    rects[3] = Unk_Float4(a, b, u1 + a, v1 + b);
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    target->Unk_49d250(0, 0, 1, 0, 0);
    s32 result = CRenderTexture::Unk_49cf50(nullptr, nullptr);
    if (result >= 0) {
        Unk_GPUTexture* texture = Unk_GetTexture(source);
        field_30.field_0->vf29(field_30.field_7dc4);
        field_30.field_0->vf26(field_30.field_10[0], texture);
        s32 filter = texture->vf16();
        texture->vf15(5);
        result = Unk_472590(0.0f, 0.0f, width, height, rects[0].field_0[0].field_0, rects[0].field_0[1].field_0,
                            rects[0].field_0[2].field_0, rects[0].field_0[3].field_0, rects[1].field_0[0].field_0,
                            rects[1].field_0[1].field_0, rects[1].field_0[2].field_0, rects[1].field_0[3].field_0,
                            rects[2].field_0[0].field_0, rects[2].field_0[1].field_0, rects[2].field_0[2].field_0,
                            rects[2].field_0[3].field_0, rects[3].field_0[0].field_0, rects[3].field_0[1].field_0,
                            rects[3].field_0[2].field_0, rects[3].field_0[3].field_0, 0);
        texture->vf15(filter);
        result = result < 0 ? result : 0;
    }
    return result;
}

// 0x7100473fd0: one direction of a Gaussian blur with up to 8 pairs of taps
// (the offsets step by 1, by 1.5 around the limit and by 2 beyond it)
s32 CTextureUtil::Unk_473fd0(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 sigma,
                             f32 arg10, f32 arg11, const Unk_Float2* direction, Unk_GPUTexture* texture, s32 taps,
                             u32 flags) {
    s32 n = taps;
    if (taps < 1) {
        n = static_cast<s32>(sigma + 0.9999f);
    }
    n = n < 8 ? n : 8;
    n = n > 2 ? n : 2;
    s32 count = n * 2 + 1;
    field_30.field_0->vf29(field_30.field_7e28[n - 2]);
    f32 scale = -1.0f / (2.0f * sigma * sigma);
    f32 limit = sigma * 1.4823039f;
    Unk_24e4c18[0] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    bool nearest = limit <= static_cast<f32>(n);
    f32 offset = 0.0f;
    for (s32 i = 0; i < n; i++) {
        f32 next = offset + 1.0f;
        if (offset > limit) {
            next = offset + 2.0f;
        } else if (next > limit) {
            next = offset + 1.5f;
        }
        offset = next;
        f32 dx = offset * direction->field_0[0].field_0;
        f32 dy = offset * direction->field_0[1].field_0;
        f32 weight = offset * (scale * offset);
        Unk_24e4c18[1 + i * 2] = Unk_Float4(dx, dy, weight, 0.0f);
        Unk_24e4c18[2 + i * 2] = Unk_Float4(-dx, -dy, weight, 0.0f);
    }
    field_30.field_0->vf22(field_30.field_c8, Unk_24e4c18, count);
    field_30.field_0->vf22(field_30.field_c4, Unk_24e4c18, count < 8 ? count : 8);
    Unk_24e4c18[0] = Unk_Float4(0.0f, -1.0f / (2.0f * arg10 * arg10), -1.0f / (2.0f * arg11 * arg11), 0.0f);
    field_30.field_0->vf22(field_30.field_cc, Unk_24e4c18, 1);
    field_30.field_0->vf26(field_30.field_10[0], texture);
    if (static_cast<f32>(texture->field_4c) != width || static_cast<f32>(texture->field_50) != height) {
        nearest = true;
    }
    s32 filter = texture->vf16();
    texture->vf15(nearest ? 8 : 9);
    s32 result = Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
    texture->vf15(filter);
    return result;
}

// 0x7100474d00: the same from one render texture into another, along x or y
s32 CTextureUtil::Unk_474d00(f32 sigma, f32 arg2, f32 arg3, CRenderTexture* source, CRenderTexture* target,
                             bool horizontal, s32 taps, bool clear) {
    if (clear) {
        Unk_471410();
    }
    Unk_Float2 direction = *reinterpret_cast<const Unk_Float2*>(&source->field_88);
    if (horizontal) {
        direction.field_0[1] = 0.0f;
    } else {
        direction.field_0[0] = 0.0f;
    }
    f32 u1;
    f32 v1;
    Unk_GetCoords(source, &u1, &v1);
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    target->Unk_49d250(0, 0, 1, 0, 0);
    s32 result = CRenderTexture::Unk_49cf50(nullptr, nullptr);
    if (result >= 0) {
        result = Unk_473fd0(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, sigma, arg2, arg3, &direction,
                            Unk_GetTexture(source), taps, 0);
        result = result < 0 ? result : 0;
    }
    return result;
}

// 0x71004768b0: `count` textures (1 to 16), each times a colour, with the
// technique for that many textures or the nearest one that exists
s32 CTextureUtil::Unk_4768b0(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, s32 count,
                             Unk_GPUTexture** textures, const Unk_Float4* colors, s32 index, u32 flags) {
    if (count < 1 || count > 16) {
        return -4;
    }
    s32 technique;
    s32 used;
    if (Unk_442c50_get(reinterpret_cast<u64>(field_20))) {
        used = count - 1;
        do {
            technique = field_30.field_48a8[used][index];
            used++;
        } while (used < 16 && technique == 0);
    } else {
        used = count + 1;
        do {
            technique = field_30.field_48a8[used - 2][index];
            used--;
        } while (used > 0 && technique == 0);
    }
    if (technique == 0) {
        return -4;
    }
    field_30.field_0->vf29(technique);
    Unk_Float4 values[16];
    if (colors != nullptr) {
        for (s32 i = 0; i < count; i++) {
            values[i] = colors[i];
        }
    } else {
        for (s32 i = 0; i < count; i++) {
            values[i] = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
        }
    }
    for (s32 i = count; i < used; i++) {
        values[i] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    field_30.field_0->vf22(field_30.field_d0, values, used);
    for (s32 i = 0; i < count; i++) {
        field_30.field_0->vf26(GetHandle_tex2D_aTexture(i), textures[i]);
    }
    for (s32 i = count; i < used; i++) {
        field_30.field_0->vf26(GetHandle_tex2D_aTexture(i), nullptr);
    }
    return Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
}

// 0x7100476bc0: the same with a power applied (1 / `power` goes to the
// effect); with a power of 1, or none, it is the function above
s32 CTextureUtil::Unk_476bc0(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 power,
                             s32 count, Unk_GPUTexture** textures, const Unk_Float4* colors, s32 index, u32 flags) {
    if (power == 1.0f || power <= 0.0f) {
        return Unk_4768b0(x, y, width, height, u0, v0, u1, v1, count, textures, colors, index, flags);
    }
    if (count < 1 || count > 16) {
        return -4;
    }
    s32 technique;
    s32 last = count - 1;
    for (;; last++) {
        technique = field_30.field_4e28[last][index];
        if (last >= 15 || technique != 0) {
            break;
        }
    }
    s32 used = last + 1;
    if (technique == 0) {
        return -4;
    }
    field_30.field_0->vf29(technique);
    Unk_Float4 values[16];
    if (colors != nullptr) {
        for (s32 i = 0; i < count; i++) {
            values[i] = colors[i];
        }
    } else {
        for (s32 i = 0; i < count; i++) {
            values[i] = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
        }
    }
    for (s32 i = count; i <= last; i++) {
        values[i] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    field_30.field_0->vf22(field_30.field_d0, values, used);
    field_30.field_0->vf18(field_30.field_fc, 1.0f / power);
    for (s32 i = 0; i < count; i++) {
        field_30.field_0->vf26(GetHandle_tex2D_aTexture(i), textures[i]);
    }
    for (s32 i = count; i <= last; i++) {
        field_30.field_0->vf26(GetHandle_tex2D_aTexture(i), nullptr);
    }
    return Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
}

// 0x71004772f0: the same from render textures
s32 CTextureUtil::DrawRectGPU_MadLumGammaTn(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 power,
                             s32 count, CRenderTexture** sources, const Unk_Float4* colors, s32 index, u32 flags) {
    Unk_GPUTexture* textures[16];
    for (s32 i = 0; i < count; i++) {
        textures[i] = Unk_GetTexture(sources[i]);
    }
    return Unk_476bc0(x, y, width, height, u0, v0, u1, v1, power, count, textures, colors, index, flags);
}

// 0x710047aa60
s32 CTextureUtil::Unk_47aa60(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1,
                             const Unk_Float4* value, Unk_GPUTexture* texture, void* arg3, u32 flags) {
    field_30.field_0->vf29(field_30.field_20728);
    Unk_24e4c18[0] = *value;
    field_30.field_0->vf22(field_30.field_d4, Unk_24e4c18, 1);
    if (texture != nullptr) {
        s32 filter = texture->vf16();
        texture->vf15(4);
        field_30.field_0->vf26(field_30.field_10[0], texture);
        s32 result = Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
        texture->vf15(filter);
        return result;
    }
    return Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
}

// 0x710047abf0
void CTextureUtil::Unk_47abf0(f32 value) {
    Unk_Float4 vector;
    vector.field_0[0] = value;
    vector.field_0[1] = 1.0f - value;
    vector.field_0[2] = 1.0f / value;
    vector.field_0[3] = -(1.0f - value) / value;
    field_30.field_0->vf20(field_30.field_b0, &vector.field_0[0].field_0);
}

// 0x710047ac50: `count` textures with a pair of weights each, and two
// rectangles of texture coordinates
s32 CTextureUtil::Unk_47ac50(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 u2, f32 v2,
                             f32 u3, f32 v3, s32 count, Unk_GPUTexture** textures, const Unk_Float2* weights,
                             bool arg4, s32 arg5, s32 index, u32 flags) {
    s32 technique = arg4 ? field_30.field_842c[arg5][count - 1][index] : field_30.field_7eac[arg5][count - 1][index];
    if (technique == 0) {
        return -4;
    }
    field_30.field_0->vf29(technique);
    Unk_Float4 values[16];
    for (s32 i = 0; i < count; i++) {
        values[i] = Unk_Float4(weights[i].field_0[0], weights[i].field_0[1], 0.0f, 0.0f);
    }
    field_30.field_0->vf22(field_30.field_b4, values, count);
    for (s32 i = 0; i < count; i++) {
        field_30.field_0->vf26(GetHandle_tex2D_aTexture(i), textures[i]);
    }
    return Unk_471f60(x, y, width, height, u0, v0, u1, v1, u2, v2, u3, v3, flags);
}

// 0x710047ae50: the same with the technique of two counts (the larger one
// is the number of textures, less one)
s32 CTextureUtil::Unk_47ae50(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 u2, f32 v2,
                             f32 u3, f32 v3, s32 arg1, s32 arg2, Unk_GPUTexture** textures,
                             const Unk_Float2* weights, s32 arg5, s32 index, u32 flags) {
    s32 technique = field_30.field_89ac[arg5][arg1][arg2][index];
    if (technique == 0) {
        return -4;
    }
    field_30.field_0->vf29(technique);
    s32 last = arg1 > arg2 ? arg1 : arg2;
    s32 count = last + 1;
    Unk_Float4 values[16];
    for (s32 i = 0; i <= last; i++) {
        values[i] = Unk_Float4(weights[i].field_0[0], weights[i].field_0[1], 0.0f, 0.0f);
    }
    field_30.field_0->vf22(field_30.field_b4, values, count);
    for (s32 i = 0; i <= last; i++) {
        field_30.field_0->vf26(GetHandle_tex2D_aTexture(i), textures[i]);
    }
    return Unk_471f60(x, y, width, height, u0, v0, u1, v1, u2, v2, u3, v3, flags);
}

// 0x710047b040: the same with the textures of both counts, and a pair of
// values for the effect
s32 CTextureUtil::Unk_47b040(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 u2, f32 v2,
                             f32 u3, f32 v3, s32 arg1, s32 arg2, Unk_GPUTexture** textures,
                             const Unk_Float2* weights, const Unk_Float2* value, s32 arg6, s32 index, u32 flags) {
    s32 count = arg1 + 1 + arg2;
    s32 technique = field_30.field_b5ac[arg6][arg1][arg2][index];
    bool arg = Unk_442c50_get(reinterpret_cast<u64>(field_20));
    if (technique == 0 && !arg) {
        technique = field_30.field_b5ac[arg6][arg1][6][index];
        if (technique == 0) {
            return -4;
        }
    }
    field_30.field_0->vf29(technique);
    Unk_Float4 values[16];
    for (s32 i = 0; i < count; i++) {
        values[i] = Unk_Float4(weights[i].field_0[0], weights[i].field_0[1], 0.0f, 0.0f);
    }
    field_30.field_0->vf22(field_30.field_b4, values, count);
    Unk_24e4c18[0].field_0[0] = value->field_0[0];
    Unk_24e4c18[0].field_0[1] = value->field_0[1];
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4c18, 1);
    for (s32 i = 0; i < count; i++) {
        field_30.field_0->vf26(GetHandle_tex2D_aTexture(i), textures[i]);
    }
    return Unk_471f60(x, y, width, height, u0, v0, u1, v1, u2, v2, u3, v3, flags);
}

// 0x710047a850: up to three textures, three rectangles of texture coordinates
s32 CTextureUtil::Unk_47a850(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 u2, f32 v2,
                             f32 u3, f32 v3, f32 u4, f32 v4, f32 u5, f32 v5, f32 arg17, f32 arg18,
                             const Unk_Float4* value, Unk_GPUTexture* texture0, Unk_GPUTexture* texture1,
                             Unk_GPUTexture* texture2, s32 arg5, u32 flags) {
    field_30.field_0->vf29(field_30.field_20724);
    Unk_24e4c18[0] = *value;
    Unk_24e4c18[1].field_0[0] = 1.0f / arg18;
    Unk_24e4c18[1].field_0[1] = -arg17 / arg18;
    field_30.field_0->vf22(field_30.field_d4, Unk_24e4c18, 2);
    s32 filter = -1;
    if (texture0 != nullptr) {
        filter = texture0->vf16();
        texture0->vf15(4);
        field_30.field_0->vf26(field_30.field_10[0], texture0);
    }
    if (texture1 != nullptr) {
        texture1->vf15(4);
        field_30.field_0->vf26(field_30.field_10[1], texture1);
    }
    if (texture2 != nullptr) {
        texture2->vf15(4);
        field_30.field_0->vf26(field_30.field_10[2], texture2);
    }
    s32 result = Unk_472250(x, y, width, height, u0, v0, u1, v1, u2, v2, u3, v3, u4, v4, u5, v5, flags);
    if (texture0 != nullptr) {
        texture0->vf15(filter);
    }
    return result;
}

// 0x710047a030: the motion blur's camera velocity (tech_MotionBlurMakeCameraVelocity,
// its Falloff and Overwrite variants)
s32 CTextureUtil::Unk_47a030(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 u2, f32 v2,
                             f32 u3, f32 v3, const Unk_47a030_Arg1* arg1, const void* arg2, const Unk_Float2* arg3,
                             const Unk_Float2* arg4, const Unk_Float2* arg5, s32 index, const Unk_Float2* arg7,
                             const Unk_Float2* falloff, Unk_GPUTexture* texture0, Unk_GPUTexture* texture1,
                             u32 flags) {
    bool hasFalloff = false;
    if (falloff != nullptr && falloff->field_0[0].field_0 != 0.0f) {
        hasFalloff = true;
    }
    s32 technique;
    if (texture1 != nullptr) {
        technique = hasFalloff ? field_30.field_1c508[index] : field_30.field_1c4ec[index];
    } else {
        technique = hasFalloff ? field_30.field_1c4d0[index] : field_30.field_1c4b4[index];
    }
    field_30.field_0->vf29(technique);
    f32 far = arg1->field_30;
    f32 near = arg1->field_2c;
    Unk_Float4 planes(near, far, far * near, far - near);
    field_30.field_0->vf20(field_30.field_a4, &planes.field_0[0].field_0);
    Unk_24e4c18[0].field_0[0] = arg3->field_0[0];
    Unk_24e4c18[0].field_0[1] = arg3->field_0[1];
    Unk_24e4c18[0].field_0[2] = arg4->field_0[0];
    Unk_24e4c18[0].field_0[3] = arg4->field_0[1];
    Unk_24e4c18[2].field_0[0].field_0 = 1.0f / arg3->field_0[0].field_0;
    Unk_24e4c18[2].field_0[1].field_0 = 1.0f / arg3->field_0[1].field_0;
    f32 scale = arg5->field_0[0].field_0;
    f32 offset = arg5->field_0[1].field_0;
    Unk_24e4c18[2].field_0[2].field_0 = 1.0f / scale;
    Unk_24e4c18[2].field_0[3].field_0 = -offset / scale;
    Unk_24e4c18[1].field_0[0] = arg7->field_0[0];
    Unk_24e4c18[1].field_0[1] = arg7->field_0[1];
    if (hasFalloff) {
        Unk_24e4c18[1].field_0[2].field_0 = falloff->field_0[0].field_0 / 0.99609375f;
        Unk_24e4c18[1].field_0[3].field_0 = falloff->field_0[1].field_0 - 0.00390625f;
    } else {
        Unk_24e4c18[1].field_0[2].field_0 = 0.0f;
        Unk_24e4c18[1].field_0[3].field_0 = 0.0f;
    }
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4c18, 3);
    field_30.field_0->vf25(field_30.field_114, arg2, 1);
    Unk_Float4 one(1.0f, 0.0f, 1.0f, 0.0f);
    field_30.field_0->vf20(field_30.field_c0, &one.field_0[0].field_0);
    if (texture0 != nullptr) {
        field_30.field_0->vf26(field_30.field_8, texture0);
    }
    if (texture1 != nullptr) {
        field_30.field_0->vf26(field_30.field_c, texture1);
    }
    f32 sign = field_20->field_58 ? 1.0f : -1.0f;
    if (texture1 != nullptr) {
        return Unk_472250(x, y, width, height, u0, v0, u1, v1, -1.0f, -sign, 1.0f, sign, u2, v2, u3, v3, flags);
    }
    return Unk_471f60(x, y, width, height, u0, v0, u1, v1, -1.0f, -sign, 1.0f, sign, flags);
}

// 0x71004773e0
s32 CTextureUtil::Unk_4773e0(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1,
                             const Unk_Float4* arg1, const Unk_Float4* arg2, const Unk_Float4* arg3,
                             const Unk_Float4* rect, bool arg5, const Unk_Float4* arg6, Unk_GPUTexture* texture,
                             s32 index, u32 flags) {
    Unk_24e4a18[0] = *arg2;
    if (arg3 != nullptr) {
        Unk_24e4a18[1] = arg3[0];
        Unk_24e4a18[2] = arg3[1];
    } else {
        Unk_24e4a18[1] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
        Unk_24e4a18[2] = Unk_Float4(64512.0f, 64512.0f, 64512.0f, 64512.0f);
    }
    field_30.field_0->vf22(field_30.field_d0, arg1, 1);
    field_30.field_0->vf22(field_30.field_d4, Unk_24e4a18, 3);
    if (texture != nullptr) {
        field_30.field_0->vf26(field_30.field_8, texture);
    }
    if (rect != nullptr && (rect->field_0[0].field_0 != 0.0f || rect->field_0[1].field_0 != 0.0f ||
                            rect->field_0[2].field_0 != 0.0f || rect->field_0[3].field_0 != 0.0f)) {
        field_30.field_0->vf29(arg5 ? field_30.field_6428[0][index] : field_30.field_5ea8[0][index]);
        if (arg5) {
            f32 arg = arg6->field_0[1].field_0;
            Unk_Float first = arg6->field_0[0];
            f32 range = arg6->field_0[2].field_0;
            f32 d = arg6->field_0[3].field_0;
            f32 distance = d > 0.0f ? d : -d;
            f32 a;
            f32 b;
            f32 c;
            if (distance < 0.0f) {
                a = 0.0f;
                b = 1.0f;
                c = 1.0f;
            } else {
                a = -0.5f / distance;
                b = 0.5f - range * a;
                c = distance > range ? range / distance : 1.0f;
                c = c * c;
            }
            Unk_Float4 value;
            value.field_0[0].field_0 = a;
            value.field_0[1].field_0 = b;
            value.field_0[3].field_0 = c;
            value.field_0[2] = first;
            f32 half = arg * 0.5f;
            field_30.field_0->vf20(field_30.field_e4, &value.field_0[0].field_0);
            field_30.field_0->vf18(field_30.field_e8, half);
        }
        return Unk_471f60(x, y, width, height, u0, v0, u1, v1, rect->field_0[0].field_0, rect->field_0[1].field_0,
                          rect->field_0[2].field_0, rect->field_0[3].field_0, flags);
    }
    field_30.field_0->vf29(field_30.field_5928[0][index]);
    return Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
}

// 0x7100476f40: `count` textures and one more with its own colour and its
// own rectangle of texture coordinates (`rect`: scale and offset)
s32 CTextureUtil::Unk_476f40(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 power,
                             Unk_Float4 color, Unk_Float4 rect, s32 count, Unk_GPUTexture** textures,
                             Unk_GPUTexture* extra, const Unk_Float4* colors, s32 index, u32 flags) {
    if (count < 1 || count > 16) {
        return -4;
    }
    s32 technique;
    s32 last = count;
    for (;; last++) {
        technique = field_30.field_53a8[last][index];
        if (last >= 15 || technique != 0) {
            break;
        }
    }
    s32 used = last + 1;
    if (technique == 0) {
        return -4;
    }
    field_30.field_0->vf29(technique);
    Unk_Float4 values[16];
    if (colors != nullptr) {
        for (s32 i = 0; i < count; i++) {
            values[i] = colors[i];
        }
    } else {
        for (s32 i = 0; i < count; i++) {
            values[i] = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
        }
    }
    values[count] = color;
    for (s32 i = count + 1; i <= last; i++) {
        values[i] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    field_30.field_0->vf22(field_30.field_d0, values, used);
    field_30.field_0->vf18(field_30.field_fc, 1.0f / power);
    for (s32 i = 0; i < count; i++) {
        field_30.field_0->vf26(GetHandle_tex2D_aTexture(i), textures[i]);
    }
    extra->vf17(0);
    extra->vf18(3);
    field_30.field_0->vf26(GetHandle_tex2D_aTexture(count), extra);
    for (s32 i = count + 1; i <= last; i++) {
        field_30.field_0->vf26(GetHandle_tex2D_aTexture(i), nullptr);
    }
    return Unk_471f60(x, y, width, height, u0, v0, u1, v1, -rect.field_0[2].field_0 / rect.field_0[0].field_0,
                      -rect.field_0[3].field_0 / rect.field_0[1].field_0,
                      (1.0f - rect.field_0[2].field_0) / rect.field_0[0].field_0,
                      (1.0f - rect.field_0[3].field_0) / rect.field_0[1].field_0, flags);
}

// 0x7100477350: the same from render textures
s32 CTextureUtil::DrawRectGPU_MadLumGammaWithLensDirtTn(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 power,
                             Unk_Float4 color, Unk_Float4 rect, s32 count, CRenderTexture** sources,
                             CRenderTexture* extra, const Unk_Float4* colors, s32 index, u32 flags) {
    Unk_GPUTexture* textures[16];
    for (s32 i = 0; i < count; i++) {
        textures[i] = Unk_GetTexture(sources[i]);
    }
    return Unk_476f40(x, y, width, height, u0, v0, u1, v1, power, color, rect, count, textures, Unk_GetTexture(extra),
                      colors, index, flags);
}

// 0x71004776f0: `count` textures with their colours in the scratch vectors,
// and three more vectors for the effect (defaults when there are none)
s32 CTextureUtil::Unk_4776f0(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, s32 count,
                             Unk_GPUTexture** textures, const Unk_Float4* colors, const Unk_Float4* arg4, s32 index,
                             u32 flags) {
    if (count < 1 || count > 16) {
        return -4;
    }
    s32 technique;
    s32 last = count - 1;
    for (;; last++) {
        technique = field_30.field_5928[last][index];
        if (last >= 15 || technique != 0) {
            break;
        }
    }
    if (technique == 0) {
        return -4;
    }
    field_30.field_0->vf29(technique);
    if (colors != nullptr) {
        for (s32 i = 0; i < count; i++) {
            Unk_24e4a18[i] = colors[i];
        }
    } else {
        for (s32 i = 0; i < count; i++) {
            Unk_24e4a18[i] = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
        }
    }
    s32 used = last + 1;
    for (s32 i = count; i <= last; i++) {
        Unk_24e4a18[i] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    if (arg4 == nullptr) {
        Unk_24e4a18[16] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
        Unk_24e4a18[17] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
        Unk_24e4a18[18] = Unk_Float4(64512.0f, 64512.0f, 64512.0f, 64512.0f);
        arg4 = &Unk_24e4a18[16];
    }
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4a18, used);
    field_30.field_0->vf22(field_30.field_d4, arg4, 3);
    for (s32 i = 0; i < count; i++) {
        field_30.field_0->vf26(GetHandle_tex2D_aTexture(i), textures[i]);
    }
    for (s32 i = count; i <= last; i++) {
        field_30.field_0->vf26(GetHandle_tex2D_aTexture(i), nullptr);
    }
    return Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
}

// 0x7100477a50: `count` textures, each with one weight, and a colour for all
// (one texture: the weight goes into the colour, and it is Unk_4768b0)
s32 CTextureUtil::Unk_477a50(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, s32 count,
                             Unk_GPUTexture** textures, const Unk_Float4* color, const Unk_Float* weights, s32 index,
                             u32 flags) {
    if (count < 1 || count > 16) {
        return -4;
    }
    if (count == 1) {
        Unk_Float4 value = *color;
        if (weights != nullptr) {
            for (s32 i = 0; i < 4; i++) {
                value.field_0[i].field_0 = weights[0].field_0 * value.field_0[i].field_0;
            }
        }
        return Unk_4768b0(x, y, width, height, u0, v0, u1, v1, 1, textures, &value, index, flags);
    }
    s32 technique;
    s32 last = count - 1;
    for (;; last++) {
        technique = field_30.field_69a8[last][index];
        if (last >= 15 || technique != 0) {
            break;
        }
    }
    if (technique == 0) {
        return -4;
    }
    field_30.field_0->vf29(technique);
    for (s32 i = 0; i < count; i++) {
        field_30.field_0->vf26(GetHandle_tex2D_aTexture(i), textures[i]);
    }
    for (s32 i = count; i <= last; i++) {
        field_30.field_0->vf26(GetHandle_tex2D_aTexture(i), nullptr);
    }
    s32 used = last + 1;
    Unk_Float4 values[16];
    if (weights != nullptr) {
        for (s32 i = 0; i < count; i++) {
            values[i] = Unk_Float4(weights[i], weights[i], weights[i], weights[i]);
        }
    } else {
        for (s32 i = 0; i < count; i++) {
            values[i] = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
        }
    }
    for (s32 i = count; i <= last; i++) {
        values[i] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    field_30.field_0->vf22(field_30.field_d0, values, used);
    field_30.field_0->vf22(field_30.field_d4, color, 1);
    return Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
}

// 0x7100477d80: the same with a power (1 / `power` goes to the effect); with
// a power of 1, or none, it is the function above
s32 CTextureUtil::Unk_477d80(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 power,
                             s32 count, Unk_GPUTexture** textures, const Unk_Float4* color,
                             const Unk_Float* weights, s32 index, u32 flags) {
    if (count < 1 || count > 16) {
        return -4;
    }
    if (power == 1.0f || power <= 0.0f) {
        return Unk_477a50(x, y, width, height, u0, v0, u1, v1, count, textures, color, weights, index, flags);
    }
    s32 technique;
    s32 last = count - 1;
    for (;; last++) {
        technique = field_30.field_6f28[last][index];
        if (last >= 15 || technique != 0) {
            break;
        }
    }
    if (technique == 0) {
        return -4;
    }
    field_30.field_0->vf29(technique);
    for (s32 i = 0; i < count; i++) {
        field_30.field_0->vf26(GetHandle_tex2D_aTexture(i), textures[i]);
    }
    for (s32 i = count; i <= last; i++) {
        field_30.field_0->vf26(GetHandle_tex2D_aTexture(i), nullptr);
    }
    s32 used = last + 1;
    Unk_Float4 values[16];
    if (weights != nullptr) {
        for (s32 i = 0; i < count; i++) {
            values[i] = Unk_Float4(weights[i], weights[i], weights[i], weights[i]);
        }
    } else {
        for (s32 i = 0; i < count; i++) {
            values[i] = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
        }
    }
    for (s32 i = count; i <= last; i++) {
        values[i] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    field_30.field_0->vf22(field_30.field_d0, values, used);
    field_30.field_0->vf22(field_30.field_d4, color, 1);
    field_30.field_0->vf18(field_30.field_fc, 1.0f / power);
    return Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
}

// 0x71004738e0
void CTextureUtil::Unk_4738e0(s32 count, const Unk_Float4* values, s32 total, s32 max) {
    if (total == 0) {
        total = count;
    }
    s32 first = count < max ? count : max;
    s32 firstTotal = total < max ? total : max;
    s32 restTotal = total - max > 0 ? total - max : 0;
    s32 rest = count - max > 0 ? count - max : 0;
    if (values != nullptr) {
        for (s32 i = 0; i < first; i++) {
            Unk_24e4c18[i] = values[i];
        }
    } else {
        for (s32 i = 0; i < first; i++) {
            Unk_24e4c18[i] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
        }
    }
    for (s32 i = first; i < firstTotal; i++) {
        Unk_24e4c18[i] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    field_30.field_0->vf22(field_30.field_c4, Unk_24e4c18, firstTotal);
    if (values != nullptr) {
        for (s32 i = 0; i < rest; i++) {
            const Unk_Float4& value = values[max + i];
            Unk_24e4c18[i] = Unk_Float4(value.field_0[0].field_0 - values[0].field_0[0].field_0,
                                                 value.field_0[1].field_0 - values[0].field_0[1].field_0,
                                                 value.field_0[2].field_0 - values[0].field_0[2].field_0,
                                                 value.field_0[3].field_0 - values[0].field_0[3].field_0);
        }
    } else {
        for (s32 i = 0; i < rest; i++) {
            Unk_24e4c18[i] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
        }
    }
    for (s32 i = rest; i < restTotal; i++) {
        Unk_24e4c18[i] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    field_30.field_0->vf22(field_30.field_c8, Unk_24e4c18, restTotal);
}

// 0x710047b2a0
s32 CTextureUtil::DrawRectGPU_DepthOfFieldLayerMask(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1,
                                                    f32 v1, bool background, bool arg2, s32 count,
                                                    const Unk_Float4* values, const Unk_Float2* arg5,
                                                    const Unk_Float2* arg6, Unk_GPUTexture* texture, s32 arg8,
                                                    s32 index, u32 flags) {
    s32 technique;
    bool found;
    if (background) {
        for (s32 i = count + 1;; i--) {
            technique = field_30.field_e1ac[arg8][i - 2][index];
            found = technique != 0;
            if (i < 2 || found) {
                break;
            }
        }
    } else {
        for (s32 i = count + 1;; i--) {
            technique = field_30.field_f2dc[arg8][i - 2][index];
            found = technique != 0;
            if (i < 2 || found) {
                break;
            }
        }
    }
    if (!found) {
#line 17169
        PPFX_ERROR("CTextureUtil::DrawRectGPU_DepthOfFieldLayerMask(): GetHandle_tech_DepthOfField_BackgroundLayerMaskT1_Sn(%d, %d) failed.\n", count, index);
        return -4;
    }
    field_30.field_0->vf29(technique);
    Unk_Float4 first(arg5->field_0[0], arg5->field_0[1], 0.0f, 0.0f);
    field_30.field_0->vf22(field_30.field_b4, &first, 1);
    Unk_Float4 second(arg6->field_0[0], arg6->field_0[1], 0.0f, 0.0f);
    field_30.field_0->vf20(field_30.field_b8, &second.field_0[0].field_0);
    Unk_4738e0(count, values, 0, 8);
    s32 result;
    if (texture != nullptr) {
        field_30.field_0->vf26(field_30.field_10[0], texture);
        s32 filter = texture->vf16();
        texture->vf15(arg2 ? 5 : 4);
        result = Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
        texture->vf15(filter);
    } else {
        result = Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
    }
    return result;
}

// 0x7100476290 (its log line names it)
s32 CTextureUtil::DrawRectGPU_MadCocT2_Sn(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1,
                                          s32 count, const Unk_Float4* values, const Unk_Float4* colors,
                                          const Unk_Float4* arg4, Unk_GPUTexture* texture0,
                                          Unk_GPUTexture* texture1, s32 arg7, u32 flags) {
    switch (count) {
    case 3:
    case 4:
    case 5:
    case 7:
    case 8:
    case 9:
    case 15:
    case 19:
        break;
    default:
        return -4;
    }
    if (arg7 != 0) {
        return -4;
    }
    s32 technique = field_30.field_1a6d4[count - 1][arg7];
    if (technique == 0) {
#line 12457
        PPFX_ERROR("CTextureUtil::DrawRectGPU_MadCocT2_Sn(): GetHandle_tech_MadCocT2_Sn(%d, %d) failed.\n", count, arg7);
        return -4;
    }
    field_30.field_0->vf29(technique);
    Unk_4738e0(count, values, count, 0);
    if (colors != nullptr) {
        for (s32 i = 0; i < count; i++) {
            Unk_24e4a18[i] = colors[i];
        }
    } else {
        for (s32 i = 0; i < count; i++) {
            Unk_24e4a18[i] = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
        }
    }
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4a18, count);
    Unk_24e4c18[0] = *arg4;
    if (Unk_24e4c18[0].field_0[2].field_0 > Unk_24e4c18[0].field_0[3].field_0) {
        f32 swap = Unk_24e4c18[0].field_0[2].field_0;
        Unk_24e4c18[0].field_0[2].field_0 = Unk_24e4c18[0].field_0[3].field_0;
        Unk_24e4c18[0].field_0[3].field_0 = swap;
    }
    field_30.field_0->vf22(field_30.field_d4, Unk_24e4c18, 1);
    if (texture0 != nullptr) {
        field_30.field_0->vf26(field_30.field_8, texture0);
    }
    if (texture1 != nullptr) {
        field_30.field_0->vf26(field_30.field_c, texture1);
    }
    return Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
}

// 0x7100476580: the same for two textures (tech_MadT2_Sn, which has no
// technique 21). Its log line is DrawRectGPU_MadT1_Sn's
s32 CTextureUtil::Unk_476580(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, s32 count,
                             const Unk_Float4* values, const Unk_Float4* colors, Unk_GPUTexture* texture1,
                             Unk_GPUTexture* texture0, s32 index, u32 flags) {
    if (count < 1 || count > 5) {
        return -4;
    }
    s32 technique;
    s32 used;
    if (Unk_442c50_get(reinterpret_cast<u64>(field_20))) {
        s32 last = count - 1;
        for (;; last++) {
            technique = index == 21 ? 0 : field_30.field_2218[last][index];
            if (last >= 4 || technique != 0) {
                break;
            }
        }
        used = last + 1;
    } else {
        technique = field_30.field_118[count - 1][index];
        used = count;
    }
    if (technique == 0) {
#line 12584
        PPFX_ERROR("CTextureUtil::DrawRectGPU_MadT1_Sn(): GetHandle_tech_MadT1_Sn(%d, %d) failed.\n", count, index);
        return -4;
    }
    field_30.field_0->vf29(technique);
    Unk_4738e0(count, values, used, 8);
    if (colors != nullptr) {
        for (s32 i = 0; i < count; i++) {
            Unk_24e4a18[i] = colors[i];
        }
    } else {
        for (s32 i = 0; i < count; i++) {
            Unk_24e4a18[i] = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
        }
    }
    for (s32 i = count; i < used; i++) {
        Unk_24e4a18[i] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4a18, used);
    if (texture1 != nullptr) {
        field_30.field_0->vf26(field_30.field_c, texture1);
    }
    if (texture0 != nullptr) {
        field_30.field_0->vf26(field_30.field_8, texture0);
    }
    return Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
}

// 0x7100475560: the same through a colour grading LUT
// (tech_MadColorGradingLutT1_Sn); without one it is the function below. Its
// log line is DrawRectGPU_MadT1_Sn's
s32 CTextureUtil::Unk_475560(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, s32 count,
                             const Unk_Float4* values, const Unk_Float4* colors, Unk_GPUTexture* texture,
                             Unk_GPUTexture* lut, s32 index, u32 flags) {
    if (lut == nullptr) {
        return DrawRectGPU_MadT1_Sn(x, y, width, height, u0, v0, u1, v1, count, values, colors, texture, index, flags);
    }
    if (count < 1 || count > 4) {
        return -4;
    }
    s32 technique;
    s32 last = count - 1;
    for (;; last++) {
        technique = field_30.field_74a8[last][index];
        if (last >= 3 || technique != 0) {
            break;
        }
    }
    if (technique == 0) {
#line 12205
        PPFX_ERROR("CTextureUtil::DrawRectGPU_MadT1_Sn(): GetHandle_tech_MadT1_Sn(%d, %d) failed.\n", count, index);
        return -4;
    }
    s32 used = last + 1;
    field_30.field_0->vf29(technique);
    Unk_4738e0(count, values, used, 8);
    if (colors != nullptr) {
        for (s32 i = 0; i < count; i++) {
            Unk_24e4a18[i] = colors[i];
        }
    } else {
        for (s32 i = 0; i < count; i++) {
            Unk_24e4a18[i] = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
        }
    }
    for (s32 i = count; i <= last; i++) {
        Unk_24e4a18[i] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4a18, used);
    if (texture != nullptr) {
        field_30.field_0->vf26(field_30.field_10[0], texture);
    }
    lut->vf15(4);
    field_30.field_0->vf26(field_30.field_50[0], lut);
    f32 lutWidth = static_cast<f32>(lut->field_4c);
    f32 lutHeight = static_cast<f32>(lut->field_50);
    f32 lutDepth = static_cast<f32>(lut->field_84);
    Unk_24e4c18[0].field_0[0].field_0 = (lutWidth - 1.0f) / lutWidth;
    Unk_24e4c18[0].field_0[1].field_0 = (lutHeight - 1.0f) / lutHeight;
    Unk_24e4c18[0].field_0[2].field_0 = (lutDepth - 1.0f) / lutDepth;
    Unk_24e4c18[0].field_0[3].field_0 = 0.0f;
    Unk_24e4c18[1].field_0[0].field_0 = 0.5f / lutWidth;
    Unk_24e4c18[1].field_0[1].field_0 = 0.5f / lutHeight;
    Unk_24e4c18[1].field_0[2].field_0 = 0.5f / lutDepth;
    Unk_24e4c18[1].field_0[3].field_0 = 0.5f;
    field_30.field_0->vf22(field_30.field_d4, Unk_24e4c18, 2);
    return Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
}

// 0x7100475960 (its log line names it, and its techniques are
// tech_MadT1_Sn's): `count` samples of one texture (1 to 28), each at an
// offset and times a colour. Where only tech_MadScalarWeightT1_Sn has a
// technique, the colours' alphas go to the function below as weights
s32 CTextureUtil::DrawRectGPU_MadT1_Sn(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, s32 count,
                                       const Unk_Float4* values, const Unk_Float4* colors, Unk_GPUTexture* texture,
                                       s32 index, u32 flags) {
    if (count < 1 || count > 28) {
        return -4;
    }
    s32 technique;
    s32 used;
    if (Unk_442c50_get(reinterpret_cast<u64>(field_20))) {
        used = count - 1;
        do {
            technique = field_30.field_118[used][index];
            used++;
        } while (used < 28 && technique == 0);
    } else {
        used = count + 1;
        do {
            technique = field_30.field_118[used - 2][index];
            s32 scalar = index == 21 ? 0 : field_30.field_c18[used - 2][index];
            if (technique == 0 && scalar != 0) {
                f32 weights[32];
                for (s32 i = 0; i < count; i++) {
                    weights[i] = colors[i].field_0[3].field_0;
                }
                return Unk_475d80(x, y, width, height, u0, v0, u1, v1, count, values, weights, texture, index, flags);
            }
            used--;
        } while (used > 0 && technique == 0);
    }
    if (technique == 0) {
#line 12347
        PPFX_ERROR("CTextureUtil::DrawRectGPU_MadT1_Sn(): GetHandle_tech_MadT1_Sn(%d, %d) failed.\n", count, index);
        return -4;
    }
    field_30.field_0->vf29(technique);
    Unk_4738e0(count, values, used, 8);
    if (colors != nullptr) {
        for (s32 i = 0; i < count; i++) {
            Unk_24e4a18[i] = colors[i];
        }
    } else {
        for (s32 i = 0; i < count; i++) {
            Unk_24e4a18[i] = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
        }
    }
    for (s32 i = count; i < used; i++) {
        Unk_24e4a18[i] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4a18, used);
    if (texture != nullptr) {
        field_30.field_0->vf26(field_30.field_8, texture);
    }
    return Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
}

// 0x7100475d80: the same with one weight per sample (1 to 32,
// tech_MadScalarWeightT1_Sn, which has no technique 21). Up to 20 samples,
// or where tech_MadT1_Sn has a technique, it is the function above
s32 CTextureUtil::Unk_475d80(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, s32 count,
                             const Unk_Float4* values, const f32* weights, Unk_GPUTexture* texture, s32 index,
                             u32 flags) {
    if (count < 1 || count > 32) {
        return -4;
    }
    if (count <= 20 || field_30.field_118[count - 1][index] != 0) {
        Unk_Float4 colors[32];
        for (s32 i = 0; i < count; i++) {
            colors[i] = Unk_Float4(weights[i], weights[i], weights[i], weights[i]);
        }
        return DrawRectGPU_MadT1_Sn(x, y, width, height, u0, v0, u1, v1, count, values, colors, texture, index, flags);
    }
    s32 technique;
    s32 used;
    if (Unk_442c50_get(reinterpret_cast<u64>(field_20))) {
        used = count - 1;
        do {
            technique = index == 21 ? 0 : field_30.field_c18[used][index];
            used++;
        } while (used < 32 && technique == 0);
    } else {
        used = count + 1;
        do {
            technique = index == 21 ? 0 : field_30.field_c18[used - 2][index];
            used--;
        } while (used > 0 && technique == 0);
    }
    if (technique == 0) {
        return -4;
    }
    field_30.field_0->vf29(technique);
    s32 first = count < 8 ? count : 8;
    s32 rest = count - 8 > 0 ? count - 8 : 0;
    s32 firstTotal = used < 8 ? used : 8;
    s32 restTotal = used - 8 > 0 ? used - 8 : 0;
    for (s32 i = 0; i < first; i++) {
        Unk_24e4c18[i] = values[i];
    }
    for (s32 i = first; i < firstTotal; i++) {
        Unk_24e4c18[i] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    field_30.field_0->vf22(field_30.field_c4, Unk_24e4c18, firstTotal);
    for (s32 i = 0; i < rest; i++) {
        const Unk_Float4& value = values[8 + i];
        Unk_24e4c18[i] = Unk_Float4(value.field_0[0].field_0 - values[0].field_0[0].field_0,
                                             value.field_0[1].field_0 - values[0].field_0[1].field_0,
                                             value.field_0[2].field_0 - values[0].field_0[2].field_0,
                                             value.field_0[3].field_0 - values[0].field_0[3].field_0);
    }
    for (s32 i = rest; i < restTotal; i++) {
        Unk_24e4c18[i] = Unk_Float4(-values[0].field_0[0].field_0, -values[0].field_0[1].field_0,
                                             -values[0].field_0[2].field_0, -values[0].field_0[3].field_0);
    }
    field_30.field_0->vf22(field_30.field_c8, Unk_24e4c18, restTotal);
    // the weights fill the vectors' array four to an element
    for (s32 i = 0; i < count; i++) {
        Unk_24e4a18[0].field_0[i].field_0 = weights[i];
    }
    for (s32 i = count; i < used; i++) {
        Unk_24e4a18[0].field_0[i].field_0 = 0.0f;
    }
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4a18, (used + 3) / 4);
    if (texture != nullptr) {
        field_30.field_0->vf26(field_30.field_8, texture);
    }
    return Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
}

// 0x710047b560: the layer mask that also makes the colour
// (tech_DepthOfField_..LayerMaskMakeColor..), with or without a mask texture
s32 CTextureUtil::Unk_47b560(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, bool background,
                             s32 count, const Unk_Float4* values, const Unk_Float2* arg4, Unk_GPUTexture* texture,
                             Unk_GPUTexture* mask, s32 usnorm, s32 bits, s32 dense, u32 flags) {
    s32 technique = mask != nullptr ? (background ? field_30.field_1082c[dense][usnorm][count - 1]
                                                  : field_30.field_10a3c[dense][usnorm][count - 1])
                                    : (background ? field_30.field_1040c[dense][usnorm][count - 1]
                                                  : field_30.field_1061c[dense][usnorm][count - 1]);
    if (technique == 0) {
        return -4;
    }
    field_30.field_0->vf29(technique);
    Unk_Float4 first(0.50251257f, 0.0f, 0.0f, 0.0f);
    field_30.field_0->vf22(field_30.field_d0, &first, 1);
    Unk_Float4 second(arg4->field_0[0], arg4->field_0[1], 0.0f, 0.0f);
    field_30.field_0->vf22(field_30.field_b4, &second, 1);
    f32 bias;
    if (bits < 0 ? usnorm == 1 : bits != 0) {
        bool low;
        if (bits < 0) {
            low = texture != nullptr && Unk_47b560_Format(texture->field_44);
        } else {
            low = bits >= 8 && bits <= 14;
        }
        bias = low ? 0.01f : 0.0004f;
    } else {
        bias = usnorm == 1 ? 0.001f : 0.0f;
    }
    f32 value = background ? bias : -bias;
    field_30.field_0->vf18(field_30.field_bc, value);
    Unk_4738e0(count, values, 0, 0);
    s32 filter = -1;
    if (texture != nullptr) {
        field_30.field_0->vf26(field_30.field_10[0], texture);
        filter = texture->vf16();
        texture->vf15(9);
    }
    s32 maskFilter = -1;
    if (mask != nullptr) {
        field_30.field_0->vf26(field_30.field_10[1], mask);
        maskFilter = mask->vf16();
        mask->vf15(5);
    }
    s32 result = Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
    if (texture != nullptr) {
        texture->vf15(filter);
    }
    if (mask != nullptr) {
        mask->vf15(maskFilter);
    }
    return result;
}

// 0x710047b8e0: the depth of field's front blur blend factor
// (tech_DepthOfField_FrontBlurBlendFactor..), dilated or not, with or
// without a mask
s32 CTextureUtil::Unk_47b8e0(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1,
                             const Unk_Float4* arg1, const Unk_Float4* arg2, bool dilation, Unk_GPUTexture* texture,
                             Unk_GPUTexture* mask, u32 flags) {
    Unk_24e4a18[0] = *arg1;
    Unk_24e4a18[1] = *arg2;
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4a18, 2);
    if (texture != nullptr) {
        field_30.field_0->vf26(field_30.field_8, texture);
    }
    s32 technique;
    if (mask != nullptr) {
        field_30.field_0->vf26(field_30.field_10[1], mask);
        technique = dilation ? field_30.field_1a6c4[1][1] : field_30.field_1a6c4[1][0];
    } else {
        technique = dilation ? field_30.field_1a6c4[0][1] : field_30.field_1a6c4[0][0];
    }
    field_30.field_0->vf29(technique);
    if (dilation) {
        Unk_412cd0(1.0f, texture->field_4c, texture->field_50, Unk_24e4c18);
        field_30.field_0->vf22(field_30.field_c4, Unk_24e4c18, 5);
        field_30.field_0->vf22(field_30.field_c8, Unk_24e4c18, 0);
    }
    return Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
}

// 0x710047e000
void CTextureUtil::Unk_47e000(s32* arg1, s32* arg2, s32* arg3, s32* arg4) {
    if (arg1 != nullptr) {
        *arg1 = field_29b58[0];
    }
    if (arg2 != nullptr) {
        *arg2 = field_29b58[1];
    }
    if (arg3 != nullptr) {
        *arg3 = field_29b58[2];
    }
    if (arg4 != nullptr) {
        *arg4 = field_29b58[3];
    }
}

// 0x7100473b50 (its log line names it): `count` samples (1 to 4) of one
// texture, each times a colour, through the rectangle with four texture
// coordinate sets
s32 CTextureUtil::DrawRectGPU_TexCoordMadT1_Sn(f32 x, f32 y, f32 width, f32 height, const f32* u0, const f32* v0,
                                               const f32* u1, const f32* v1, s32 count, const Unk_Float4* colors,
                                               Unk_GPUTexture* texture, s32 arg8, u32 flags) {
    if (count < 1 || count > 4) {
        return -4;
    }
    if (arg8 != 0) {
        return -4;
    }
    s32 technique = field_30.field_1b414[count - 1];
    if (technique == 0) {
#line 11261
        PPFX_ERROR("CTextureUtil::DrawRectGPU_TexCoordMadT1_Sn(): GetHandle_tech_TexCoordMadT1_Sn(%d) failed.\n", count);
        return -4;
    }
    field_30.field_0->vf29(technique);
    if (colors != nullptr) {
        for (s32 i = 0; i < count; i++) {
            Unk_24e4a18[i] = colors[i];
        }
    } else {
        for (s32 i = 0; i < count; i++) {
            Unk_24e4a18[i] = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
        }
    }
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4a18, count);
    if (texture != nullptr) {
        field_30.field_0->vf26(field_30.field_10[0], texture);
    }
    return Unk_473150(x, y, width, height, u0, v0, u1, v1, count, flags);
}

// 0x71004780c0: the bright pass (tech_BrightPassT1_.._Sn): `mode` 0 to 3 is
// the threshold's kind (0: the first, with no offset), with a vignette when
// `rect` is given and `arg12` is positive (simulated with `arg13` or
// `arg15`)
// NON_MATCHING: the two tests of the vignette are one `ccmp` here (two
// branches in the original), and AArch64StorePairSuppress keeps the first two
// stores of each colour apart here (`stp s12, s12` in the original).
s32 CTextureUtil::Unk_4780c0(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 arg8, f32 arg9,
                             f32 arg10, f32 arg11, f32 arg12, f32 arg13, f32 arg14, f32 arg15,
                             Unk_GPUTexture* texture, s32 mode, void* rect, s32 index, s32 flags) {
    s32 kind = mode == 0 ? 1 : mode;
    Unk_Float offset = mode == 0 ? Unk_Float(0.0f) : Unk_Float(arg10);
    bool vignette = rect != nullptr;
    bool simulate = false;
    if (rect != nullptr && arg12 > 0.0f) {
        simulate = !(arg13 <= 0.0f) || !(arg15 <= 0.0f);
        vignette = simulate;
    }
    s32 technique = field_30.field_7608_table[kind][vignette ? (simulate ? 2 : 1) : 0][index];
    if (technique == 0) {
        return -4;
    }
    field_30.field_0->vf29(technique);
    if (texture != nullptr) {
        field_30.field_0->vf26(field_30.field_10[0], texture);
    }
    Unk_24e4c18[0] = Unk_Float4(arg8, arg8, arg8, 1.0f);
    Unk_24e4c18[1] = Unk_Float4(arg9, arg9, arg9, 1.0f);
    Unk_24e4c18[2] = Unk_Float4(offset, offset, offset, offset);
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4c18, 3);
    if (kind == 3) {
        f32 square = arg11 * arg11;
        f32 inverse = 1.0f / square;
        f32 values[4];
        values[0] = inverse * 4.0f + -2.0f;
        values[1] = 1.0f;
        values[2] = inverse;
        values[3] = square * 0.5f;
        field_30.field_0->vf20(field_30.field_f8, values);
    }
    if (simulate) {
        f32 values[4];
        if (arg15 < 0.0f) {
            values[0] = 0.0f;
            values[1] = 1.0f;
            values[2] = arg12;
            values[3] = 1.0f;
        } else {
            f32 scale = -0.5f / arg15;
            f32 offset = 0.5f - scale * arg14;
            f32 ratio = arg15 > arg14 ? arg14 / arg15 : 1.0f;
            values[0] = scale;
            values[1] = offset;
            values[2] = arg12;
            values[3] = ratio * ratio;
        }
        f32 radius = arg13 * 0.5f;
        field_30.field_0->vf20(field_30.field_e4, values);
        field_30.field_0->vf18(field_30.field_e8, radius);
    }
    if (vignette) {
        const f32* coords = static_cast<const f32*>(rect);
        return Unk_471f60(x, y, width, height, u0, v0, u1, v1, coords[0], coords[1], coords[2], coords[3], flags);
    }
    return Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
}


// sets the device's blend colour (inline: placeholder)
static inline void Unk_SetBlendColor(IGPUDevice* device, f32 r, f32 g, f32 b, f32 a) {
    f32 color[4];
    color[3] = a;
    color[2] = b;
    color[1] = g;
    color[0] = r;
    device->vf50(reinterpret_cast<const Unk_BlendColor*>(color));
}

// the feedback's technique (inline, not static: placeholder); `index`, the
// sample count the other techniques are chosen by, isn't used (there's one
// of each), but it is passed (its callers keep the argument)
inline s32 Unk_FeedbackTechnique(const TEXSHADERSET& set, bool blend, u32 transformed, s32 index) {
    return set.field_1b424_table[!blend][transformed];
}

// whether the 4x4 matrix `m` is the identity (inline: placeholder)
static inline bool Unk_IsIdentity(const f32* m) {
    return m[0] == 1.0f && m[1] == 0.0f && m[2] == 0.0f && m[3] == 0.0f && m[4] == 0.0f && m[5] == 1.0f &&
           m[6] == 0.0f && m[7] == 0.0f && m[8] == 0.0f && m[9] == 0.0f && m[10] == 1.0f && m[11] == 0.0f &&
           m[12] == 0.0f && m[13] == 0.0f && m[14] == 0.0f && m[15] == 1.0f;
}

// an identity matrix (inline)
static inline void Unk_SetIdentity(MATRIXT44* m) {
    m->field_0[0][1] = m->field_0[0][2] = m->field_0[0][3] = m->field_0[1][0] = m->field_0[1][2] = m->field_0[1][3] =
        m->field_0[2][0] = m->field_0[2][1] = m->field_0[2][3] = m->field_0[3][0] = m->field_0[3][1] =
            m->field_0[3][2] = 0.0f;
    m->field_0[0][0] = m->field_0[1][1] = m->field_0[2][2] = m->field_0[3][3] = 1.0f;
}

// a matrix scaling the three colours by `scale` (inline)
static inline void Unk_SetScale(MATRIXT44* m, f32 scale) {
    m->field_0[0][1] = m->field_0[0][2] = m->field_0[0][3] = m->field_0[1][0] = m->field_0[1][2] = m->field_0[1][3] =
        m->field_0[2][0] = m->field_0[2][1] = m->field_0[2][3] = m->field_0[3][0] = m->field_0[3][1] =
            m->field_0[3][2] = 0.0f;
    m->field_0[0][0] = m->field_0[1][1] = m->field_0[2][2] = scale;
    m->field_0[3][3] = 1.0f;
}

// 0x71004797a0: tech_Feedback(_Blend)(_Matrix) (with `transform` unless it's
// the identity): blended by the device with the constant `arg9` (`blend`) or
// in the shader with a second texture; `other` goes to field_29b68 while it
// draws
s32 CTextureUtil::Unk_4797a0(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 arg8, f32 arg9,
                             f32 arg10, bool blend, Unk_GPUTexture* texture0, Unk_GPUTexture* texture1,
                             const f32* transform, void* other, s32 arg16, s32 flags) {
    u32 transformed = 0;
    if (transform != nullptr && !Unk_IsIdentity(transform)) {
        transformed = 1;
    }
    bool slot = other != nullptr && !Unk_IsIdentity(static_cast<const f32*>(other));
    if (slot) {
        field_29b68[0] = other;
        field_29ba8 = arg10;
    }
    field_30.field_0->vf29(Unk_FeedbackTechnique(field_30, blend, transformed, arg16));
    Unk_24e4a18[0] = Unk_Float4(arg8, arg8, arg8, arg8);
    Unk_24e4a18[1] = Unk_Float4(arg9, arg9, arg9, arg9);
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4a18, 2);
    if (transformed) {
        f32 identity[16];
        if (transform == nullptr) {
            identity[1] = identity[2] = identity[3] = identity[4] = identity[6] = identity[7] = identity[8] =
                identity[9] = identity[11] = identity[12] = identity[13] = identity[14] = 0.0f;
            identity[0] = identity[5] = identity[10] = identity[15] = 1.0f;
            transform = identity;
        }
        field_30.field_0->vf24(field_30.field_108, transform);
    }
    field_30.field_0->vf26(field_30.field_10[0], texture0);
    s32 result;
    if (blend) {
        Unk_440c40_get(reinterpret_cast<u64>(field_20), 1);
        Unk_440c60_get(reinterpret_cast<u64>(field_20), 2, 14);
        Unk_440c80_get(reinterpret_cast<u64>(field_20), arg9, arg9, arg9, arg9);
        field_20->vf44(5);
        Unk_SetBlendColor(field_20, arg9, arg9, arg9, arg9);
        result = Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
    } else {
        field_30.field_0->vf26(field_30.field_10[1], texture1);
        result = Unk_471f60(x, y, width, height, u0, v0, u1, v1, u0, v0, u1, v1, flags);
        Unk_440c40_get(reinterpret_cast<u64>(field_20), 0);
        field_20->vf44(0);
    }
    if (slot) {
        field_29b68[0] = nullptr;
        field_29ba8 = 1.0f;
    }
    return result;
}

// 0x7100479c30: `count` textures (1 to 8) with their weights in the scratch
// vectors (1 / count each when there are none) and their sum after them, the
// rectangle `left` to `bottom` mapped to the target, and with `scale`'s
// first value nonzero a second set of techniques that rescales with it
// NON_MATCHING: the sum's loop keeps a `count < 1` guard here (the original
// knows count is 1 to 8 after the two fill loops' merge; with one loop whose
// body chooses, the guard goes but LICM hoists 1 / count and its 1.0 is kept
// in v8 for the rectangle), and `height` is in v8 instead of a spill slot
s32 CTextureUtil::Unk_479c30(f32 x, f32 y, f32 width, f32 height, f32 left, f32 top, f32 right, f32 bottom,
                             s32 count, Unk_GPUTexture** textures, const f32* scale, const Unk_Float4* weights,
                             Unk_GPUTexture* texture, s32 index, u32 flags) {
    if (count < 1 || count > 8) {
        return -4;
    }
    bool scaled = false;
    if (scale != nullptr && *scale != 0.0f) {
        scaled = true;
    }
    s32 technique = scaled ? field_30.field_1bc74[count - 1][index] : field_30.field_1b9b4[count - 1][index];
    if (technique == 0) {
        technique = scaled ? field_30.field_1b6f4[count - 1][index] : field_30.field_1b434[count - 1][index];
    }
    field_30.field_0->vf29(technique);
    field_30.field_0->vf25(field_30.field_114, textures, count);
    if (weights != nullptr) {
        for (s32 i = 0; i < count; i++) {
            Unk_24e4a18[i] = weights[i];
        }
    } else {
        for (s32 i = 0; i < count; i++) {
            f32 weight = 1.0f / count;
            Unk_24e4a18[i] = Unk_Float4(weight, weight, weight, weight);
        }
    }
    Unk_24e4a18[count].field_0[0].field_0 = 0.0f;
    Unk_24e4a18[count].field_0[1].field_0 = 0.0f;
    Unk_24e4a18[count].field_0[2].field_0 = 0.0f;
    Unk_24e4a18[count].field_0[3].field_0 = 0.0f;
    for (s32 i = 0; i < count; i++) {
        for (s32 j = 0; j < 4; j++) {
            Unk_24e4a18[count].field_0[j].field_0 += Unk_24e4a18[i].field_0[j].field_0;
        }
    }
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4a18, count + 1);
    if (texture != nullptr) {
        field_30.field_0->vf26(field_30.field_8, texture);
    }
    bool flag = field_20->field_58;
    f32 sign = flag ? -1.0f : 1.0f;
    f32 halfWidth = (right - left) * 0.5f;
    f32 halfHeight = (bottom - top) / (flag ? 2.0f : -2.0f);
    f32 bottomV = flag ? 1.0f : -1.0f;
    Unk_Float4* rect = Unk_24e4c18;
    rect[0].field_0[0].field_0 = halfWidth;
    rect[0].field_0[1].field_0 = halfHeight;
    rect[0].field_0[2].field_0 = halfWidth + left;
    rect[0].field_0[3].field_0 = top - sign * halfHeight;
    if (scaled) {
        rect[1].field_0[0].field_0 = scale[0] / 0.99609375f;
        rect[1].field_0[1].field_0 = scale[1] + -0.00390625f;
        rect[1].field_0[3].field_0 = -rect[1].field_0[1].field_0 / rect[1].field_0[0].field_0;
        rect[1].field_0[2].field_0 = 1.0f / rect[1].field_0[0].field_0;
    }
    field_30.field_0->vf22(field_30.field_e0, Unk_24e4c18, scaled ? 2 : 1);
    Unk_Float4 range(1.0f, 1000.0f, 0.0f, 0.0f);
    field_30.field_0->vf20(field_30.field_a4, &range.field_0[0].field_0);
    return Unk_471c50(x, y, width, height, -1.0f, sign, 1.0f, bottomV, flags);
}

// 0x710047a380: the motion blur's velocity, direction and depth with `count`
// textures (1 to 8, tech_MotionBlurVelocityDirDepth(Innerscreen)(Clamp)T2_Sn,
// the SM3 ones first; Clamp when `clamp` is positive) and their weights as
// in Unk_479c30, the scale and offsets in seven vectors
// NON_MATCHING: the instructions are the original's but for the schedule of
// the fifth vector (its -1.0 and the z element are computed a little later
// here)
s32 CTextureUtil::Unk_47a380(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 u2, f32 v2,
                             f32 u3, f32 v3, f32 arg12, f32 clamp, f32 arg14, f32 arg15, s32 count,
                             const Unk_Float4* scale, const Unk_Float2* arg2, const Unk_Float2* arg3,
                             const Unk_Float2* arg4, bool innerscreen, const Unk_Float4* weights,
                             Unk_GPUTexture* texture0, Unk_GPUTexture* texture1, s32 index, u32 flags) {
    if (count < 1 || count > 8) {
        return -4;
    }
    s32 technique = clamp > 0.0f ? field_30.field_201a4[innerscreen][count - 1][index]
                                 : field_30.field_1e0a4[innerscreen][count - 1][index];
    if (technique == 0) {
        technique = clamp > 0.0f ? field_30.field_1f124[innerscreen][count - 1][index]
                                 : field_30.field_1d024[innerscreen][count - 1][index];
    }
    field_30.field_0->vf29(technique);
    if (weights != nullptr) {
        for (s32 i = 0; i < count; i++) {
            Unk_24e4a18[i] = weights[i];
        }
    } else {
        for (s32 i = 0; i < count; i++) {
            f32 weight = 1.0f / count;
            Unk_24e4a18[i] = Unk_Float4(weight, weight, weight, weight);
        }
    }
    Unk_24e4a18[count].field_0[0].field_0 = 0.0f;
    Unk_24e4a18[count].field_0[1].field_0 = 0.0f;
    Unk_24e4a18[count].field_0[2].field_0 = 0.0f;
    Unk_24e4a18[count].field_0[3].field_0 = 0.0f;
    for (s32 i = 0; i < count; i++) {
        for (s32 j = 0; j < 4; j++) {
            Unk_24e4a18[count].field_0[j].field_0 += Unk_24e4a18[i].field_0[j].field_0;
        }
    }
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4a18, count + 1);
    Unk_Float4* v = Unk_24e4c18;
    v[0] = *scale;
    {
        f32 s0 = scale->field_0[0].field_0 * arg2->field_0[0].field_0;
        f32 o0 = arg2->field_0[0].field_0 * scale->field_0[2].field_0 + 0.0f;
        v[1].field_0[2].field_0 = o0;
        v[1].field_0[0].field_0 = s0;
    }
    {
        f32 s1 = scale->field_0[1].field_0 * arg2->field_0[1].field_0;
        f32 o1 = arg2->field_0[1].field_0 * scale->field_0[3].field_0 + 0.0f;
        v[1].field_0[3].field_0 = o1;
        v[1].field_0[1].field_0 = s1;
    }
    {
        f32 s0 = scale->field_0[0].field_0 * arg3->field_0[0].field_0;
        f32 o0 = arg3->field_0[0].field_0 * scale->field_0[2].field_0 + 0.0f;
        v[2].field_0[2].field_0 = o0;
        v[2].field_0[0].field_0 = s0;
    }
    {
        f32 s1 = scale->field_0[1].field_0 * arg3->field_0[1].field_0;
        f32 o1 = arg3->field_0[1].field_0 * scale->field_0[3].field_0 + 0.0f;
        v[2].field_0[3].field_0 = o1;
        v[2].field_0[1].field_0 = s1;
    }
    v[3].field_0[0] = arg2->field_0[0];
    v[3].field_0[1] = arg2->field_0[1];
    v[3].field_0[2] = arg3->field_0[0];
    v[3].field_0[3] = arg3->field_0[1];
    v[4].field_0[0].field_0 = arg12;
    v[4].field_0[1].field_0 = clamp;
    v[4].field_0[2].field_0 = arg14;
    v[4].field_0[3].field_0 = arg15;
    v[5].field_0[0].field_0 = 2.0f / (u1 - u0);
    v[5].field_0[2].field_0 = -1.0f - v[5].field_0[0].field_0 * u0;
    v[5].field_0[1].field_0 = 2.0f / (v1 - v0);
    v[5].field_0[3].field_0 = -1.0f - v[5].field_0[1].field_0 * v0;
    v[6].field_0[0] = arg4->field_0[0];
    v[6].field_0[1] = arg4->field_0[1];
    field_30.field_0->vf22(field_30.field_d4, Unk_24e4c18, 7);
    s32 filter = -1;
    if (texture0 != nullptr) {
        filter = texture0->vf16();
        texture0->vf15(4);
        field_30.field_0->vf26(field_30.field_8, texture0);
    }
    if (texture1 != nullptr) {
        field_30.field_0->vf26(field_30.field_c, texture1);
    }
    s32 result = Unk_471f60(x, y, width, height, u0, v0, u1, v1, u2, v2, u3, v3, flags);
    if (texture0 != nullptr) {
        texture0->vf15(filter);
    }
    return result;
}

// 0x71004783a0: the outline 0x7100473410 draws, in one colour
// (tech_ConstantColor); the effect's technique and colour are put back after
void CTextureUtil::Unk_4783a0(f32 x, f32 y, f32 width, f32 height, f32 arg5, f32 arg6, f32 arg7, f32 arg8,
                              const f32* color, u32 flags) {
    s32 technique = field_30.field_22738;
    s32 saved = field_30.field_0->vf30();
    field_30.field_0->vf29(technique);
    f32 previous[16];
    field_30.field_0->vf21(field_30.field_d8, previous);
    field_30.field_0->vf20(field_30.field_d8, color);
    Unk_473410(x, y, width, height, arg5, arg6, arg7, arg8, flags);
    field_30.field_0->vf29(saved);
    field_30.field_0->vf20(field_30.field_d8, previous);
}

// 0x7100474570: the SSAO upsample (tech_UpsampleSsao.., one technique per
// combination of LN, MC and Mask, and tech_UpsampleSsao_IM)
s32 CTextureUtil::Unk_474570(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 arg9, f32 arg10,
                             f32 arg11, const f32* coords, Unk_GPUTexture* texture0, Unk_GPUTexture* texture1,
                             Unk_GPUTexture* texture2, Unk_GPUTexture* texture3, bool mc, bool im,
                             const Unk_Vector3* arg19, s32 arg20, s32 mode, const Unk_Vector3* arg22,
                             const Unk_Vector3* arg23, s32 linear, bool arg25, u32 flags) {
    s32 technique = im ? field_30.field_7e48 : field_30.field_7e4c[linear != 0][mc ? (mode != 0 ? 2 : 1) : 0];
    field_30.field_0->vf29(technique);
    Unk_24e4c18[0].field_0[0].field_0 = 0.0f;
    Unk_24e4c18[0].field_0[1].field_0 = 0.0f;
    f32 textureWidth = static_cast<f32>(texture0->field_4c);
    Unk_24e4c18[0].field_0[2].field_0 = textureWidth;
    f32 textureHeight = static_cast<f32>(texture0->field_50);
    Unk_24e4c18[0].field_0[3].field_0 = textureHeight;
    Unk_24e4c18[1].field_0[0].field_0 = 1.0f / textureWidth;
    Unk_24e4c18[1].field_0[1].field_0 = 1.0f / textureHeight;
    Unk_24e4c18[1].field_0[2].field_0 = 0.5f / textureWidth;
    Unk_24e4c18[1].field_0[3].field_0 = 0.5f / textureHeight;
    field_30.field_0->vf22(field_30.field_d4, Unk_24e4c18, 2);
    Unk_24e4c18[0].field_0[0].field_0 = logf(arg9 + 1.0f) / 0.6931472f;
    Unk_24e4c18[0].field_0[1].field_0 = -1.0f / (2.0f * arg10 * arg10);
    Unk_24e4c18[0].field_0[2].field_0 = -1.0f / (2.0f * arg11 * arg11);
    Unk_24e4c18[0].field_0[3].field_0 = 0.0f;
    field_30.field_0->vf22(field_30.field_cc, Unk_24e4c18, 1);
    Unk_24e4a18[0].field_0[0].field_0 = arg19->field_0[0];
    Unk_24e4a18[0].field_0[1].field_0 = arg19->field_0[1];
    Unk_24e4a18[0].field_0[2].field_0 = arg19->field_0[2];
    Unk_24e4a18[0].field_0[3].field_0 = 0.0f;
    Unk_24e4a18[1].field_0[0].field_0 = arg22->field_0[0];
    Unk_24e4a18[1].field_0[1].field_0 = arg22->field_0[1];
    Unk_24e4a18[1].field_0[2].field_0 = arg22->field_0[2];
    Unk_24e4a18[1].field_0[3].field_0 = 0.0f;
    Unk_24e4a18[2].field_0[0].field_0 = arg23->field_0[0];
    Unk_24e4a18[2].field_0[1].field_0 = arg23->field_0[1];
    Unk_24e4a18[2].field_0[2].field_0 = arg23->field_0[2];
    Unk_24e4a18[2].field_0[3].field_0 = 0.0f;
    if (mode != 0) {
        Unk_Float4 first(1.0f, 0.0f, 0.0f, 0.0f);
        Unk_Float4 second(1.0f, 0.0f, 0.0f, 0.0f);
        switch (mode) {
        case 2:
            first = Unk_Float4(0.0f, 1.0f, 0.0f, 0.0f);
            break;
        case 3:
            first = Unk_Float4(0.0f, 0.0f, 1.0f, 0.0f);
            break;
        case 4:
            first = Unk_Float4(0.0f, 0.0f, 0.0f, 1.0f);
            break;
        case 5:
            first = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
            second = Unk_Float4(0.0f, 1.0f, 0.0f, 0.0f);
            break;
        }
        Unk_24e4a18[3] = first;
        Unk_24e4a18[4] = second;
    }
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4a18, 5);
    field_30.field_0->vf26(field_30.field_10[0], texture0);
    if (linear == 0) {
        field_30.field_0->vf26(field_30.field_10[1], texture1);
    }
    if (texture2 != nullptr) {
        field_30.field_0->vf26(field_30.field_10[2], texture2);
    }
    if (texture3 != nullptr) {
        field_30.field_0->vf26(field_30.field_10[3], texture3);
    }
    s32 filter0 = texture0->vf16();
    s32 filter1 = texture1->vf16();
    s32 filter2 = -1;
    if (texture2 != nullptr) {
        filter2 = texture2->vf16();
    }
    texture0->vf15(linear == 0 && arg25 ? 9 : 8);
    texture1->vf15(9);
    if (texture2 != nullptr) {
        texture2->vf15(9);
    }
    s32 saved = field_20->vf47();
    field_20->vf44(arg20);
    s32 result;
    if (linear != 0) {
        result = Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
    } else {
        result = Unk_472900(x, y, width, height, u0, v0, u1, v1, coords[0], coords[1], coords[2], coords[3], coords[4],
                            coords[5], coords[6], coords[7], coords[8], coords[9], coords[10], coords[11], coords[12],
                            coords[13], coords[14], coords[15], flags);
    }
    field_20->vf44(saved);
    texture0->vf15(filter0);
    texture1->vf15(filter1);
    if (texture2 != nullptr) {
        texture2->vf15(filter2);
    }
    return result;
}

// 0x7100474e70: the same from render textures, into a render texture or a
// GPU texture (one of the two)
// NON_MATCHING: the same instructions, three runs of them in another order
// (the copies of the parameters, the stores of the sixteen coordinates, the
// last arguments' stores).
s32 CTextureUtil::Unk_474e70(f32 arg9, f32 arg10, f32 arg11, CRenderTexture* target, Unk_GPUTexture* targetTexture,
                             CRenderTexture* source0, CRenderTexture* source1, s32 arg20, CRenderTexture* source2,
                             bool im, const Unk_Vector3* arg19, s32 mode, CRenderTexture* source3,
                             const Unk_Vector3* arg22, const Unk_Vector3* arg23, s32 linear, bool clear) {
    if ((targetTexture != nullptr) == (target != nullptr)) {
        return -6;
    }
    if (clear) {
        Unk_471410();
    }
    u32 targetWidth;
    u32 targetHeight;
    if (targetTexture != nullptr) {
        targetWidth = targetTexture->field_4c;
        targetHeight = targetTexture->field_50;
    } else {
        targetWidth = target->field_54;
        targetHeight = target->field_58;
    }
    f32 width = static_cast<f32>(targetWidth);
    f32 height = static_cast<f32>(targetHeight);
    s32 result;
    if (targetTexture != nullptr) {
        field_20->vf8(nullptr);
        result = field_20->vf7(0, targetTexture, 0);
    } else {
        target->Unk_49d250(0, 0, 1, 0, 0);
        result = CRenderTexture::Unk_49cf50(nullptr, nullptr);
    }
    if (result < 0) {
        return result;
    }
    f32 u1;
    f32 v1;
    Unk_GetCoords(source1, &u1, &v1);
    f32 du = source1->field_88 + source1->field_90;
    f32 dv = source1->field_8c + source1->field_94;
    f32 coords[16];
    coords[0] = -du;
    coords[1] = -dv;
    coords[2] = u1 - du;
    coords[3] = v1 - dv;
    coords[4] = du;
    coords[5] = -dv;
    coords[6] = u1 + du;
    coords[7] = v1 - dv;
    coords[8] = -du;
    coords[9] = dv;
    coords[10] = u1 - du;
    coords[11] = v1 + dv;
    coords[12] = du;
    coords[13] = dv;
    coords[14] = u1 + du;
    coords[15] = v1 + dv;
    f32 ratio = static_cast<f32>(static_cast<u32>(source0->field_58)) / height - 0.5f;
    ratio = ratio > 0.0f ? ratio : -ratio;
    bool same = ratio <= 0.005f;
    result = Unk_474570(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, arg9, arg10, arg11, coords,
                        Unk_GetTexture(source0), Unk_GetTexture(source1),
                        source2 != nullptr ? Unk_GetTexture(source2) : nullptr,
                        source3 != nullptr ? Unk_GetTexture(source3) : nullptr, source2 != nullptr, im, arg19, arg20,
                        mode, arg22, arg23, linear, same, 0);
    return result < 0 ? result : 0;
}

// 0x71004784e0: an angle and two scales from a projection's numbers (by
// `mode`); every output is optional
// NON_MATCHING: `value` and `arg7` have each other's callee-saved registers
// (s8/s9); the instructions are otherwise the original's.
s32 Unk_4784e0(s32 mode, f32* angleOut, f32* xOut, f32* yOut, f32* valueOut, f32 angle, f32 aspect, f32 value,
               f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    if (arg3 > 0.0f && arg3 <= 3.14159274f) {
        if (angle >= arg3) {
            if (angle < arg5) {
                value = powf((angle - arg3) / (arg5 - arg3), 0.333333343f) * value;
            }
        } else {
            if (angle > arg4) {
                value = (angle - arg3) / (arg3 - arg4) * value;
            } else {
                value = -value;
            }
            angle = atanf(powf(tanf(Unk_Saturate(1.0f - (angle - arg4) / arg3) * arg6), 0.333333343f));
        }
    }
    f32 root = sqrtf(aspect * aspect + 1.0f);
    f32 t = tanf(angle * 0.5f);
    f32 th = t * aspect;
    f32 td = root * t;
    f32 horizontal = atanf(th);
    f32 diagonal = atanf(td);
    f32 result;
    f32 x;
    f32 y;
    if (mode == 0) {
        result = angle;
        x = aspect;
        y = 1.0f;
    } else if (mode == 1) {
        result = horizontal + horizontal;
        x = 1.0f;
        y = 1.0f / aspect;
    } else if (mode == 2) {
        result = diagonal + diagonal;
        y = 1.0f / root;
        x = y * aspect;
    } else {
        result = 0.0f;
        x = 0.0f;
        y = 0.0f;
    }
    f32 out = atanf(tanf(result * 0.5f) * arg7);
    if (angleOut != nullptr) {
        *angleOut = out + out;
    }
    if (xOut != nullptr) {
        *xOut = x / arg7;
        *yOut = y / arg7;
    }
    if (valueOut != nullptr) {
        *valueOut = value;
    }
    return 0;
}

// 0x71004786d0: where a position of the target is read from, through the
// projection of Unk_4784e0 (`flag`: the other mapping)
// NON_MATCHING: the x and y coordinates' values have each other's registers
// (s10/s11, s13/s14, s2/s12); the instructions are otherwise the original's.
Unk_Float2 Unk_4786d0(bool flag, const Unk_Float2* position, s32 mode, f32 angle, f32 aspect, f32 value, f32 arg3,
                      f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    f32 power = value;
    f32 fov;
    f32 scaleX;
    f32 scaleY;
    Unk_4784e0(mode, &fov, &scaleX, &scaleY, &power, angle, aspect, value, arg3, arg4, arg5, arg6, arg7);
    f32 ix = 1.0f / (scaleX + scaleX);
    f32 iy = 1.0f / (scaleY + scaleY);
    f32 dx = position->field_0[0].field_0 * (1.0f / ix) - 0.5f / ix;
    f32 dy = position->field_0[1].field_0 * (1.0f / iy) - 0.5f / iy;
    f32 r = Unk_Sqrt(dx * dx + dy * dy);
    f32 ox;
    f32 oy;
    if (flag) {
        ox = 0.0f;
        oy = 0.0f;
        if (r > 0.0f) {
            f32 half = fov * 0.5f;
            f32 t = tanf(half);
            f32 k = fminf(r * half, 1.5707947f);
            if (k >= 1.57079637f) {
            } else {
                f32 m = (1.0f / t) * tanf(k);
                f32 s = powf(m / r, power);
                ox = dx * s;
                oy = dy * s;
            }
        }
    } else {
        ox = 0.0f;
        oy = 0.0f;
        if (r > 0.0f) {
            f32 m = (2.0f / fov) * atanf(r * tanf(fov * 0.5f));
            f32 s = powf(m / r, power);
            ox = dx * s;
            oy = dy * s;
        }
    }
    Unk_Float2 result;
    result.field_0[0].field_0 = ix * ox + 0.5f;
    result.field_0[1].field_0 = iy * oy + 0.5f;
    return result;
}

// a seed of 0x7100478890's and 0x710047c8d0's noise (placeholder; a linear
// congruential generator's state)
struct Unk_NoiseSeed {
    Unk_NoiseSeed(u32 seed) : field_0(seed) {}
    void Next() { field_0 = field_0 * 0x5d588b65 + 0x1000001; }
    // -1 to 1
    f32 Get() const { return static_cast<f32>(field_0 >> 14) / 262143.0f * 2.0f - 1.0f; }

    u32 field_0;
};
PKMN_SIZE_ASSERT(Unk_NoiseSeed, 0x4);

// 0x7100478890: the lens distortion (tech_LensDistortion(Conv/Falloff), with
// `noise` nonzero tech_LensDistortionConv_Noise(_Additive) or, with no
// distortion, tech_ImageSensorNoise(_Additive)), the projection from
// Unk_4784e0; the noise's offsets come from four seeds that `animate` moves on
// NON_MATCHING: the four seeds are this function's guarded statics as in the
// original, but until the TU's merged statics are real they aren't at
// 0x71024e45dc; besides, the frame is 0x10 smaller and the floating-point
// registers and the schedule of the projection's vectors differ (the original
// keeps the 1.0 of the cotangent in s15 for the noise's signs)
s32 CTextureUtil::Unk_478890(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 angle,
                             f32 ratio, f32 value, f32 arg11, f32 arg12, f32 arg13, f32 arg14, f32 limit,
                             f32 arg16, f32 arg17, f32 arg18, f32 noise, f32 noiseScale, f32 noiseAspect, u32 mode,
                             bool falloff, bool additive, bool animate, Unk_GPUTexture* texture, s32 arg27,
                             s32 flags) {
    f32 aspect = noiseAspect != 0.0f ? noiseAspect : ratio;
    s32 technique;
    if (falloff) {
        technique = field_30.field_1b378;
    } else if (noise == 0.0f) {
        technique = field_30.field_1b374;
    } else if (value != 0.0f) {
        technique = additive ? field_30.field_1b388 : field_30.field_1b380;
    } else {
        technique = additive ? field_30.field_1b390 : field_30.field_1b38c;
    }
    field_30.field_0->vf29(technique);
    f32 fov;
    f32 scaleX;
    f32 scaleY;
    Unk_4784e0(mode, &fov, &scaleX, &scaleY, &value, angle, ratio, value, arg11, arg12, arg13, arg14, arg18);
    f32 sx = u1 / (scaleX + scaleX);
    f32 cx = u1 * 0.5f;
    f32 sy = v1 / (scaleY + scaleY);
    f32 cy = v1 * 0.5f;
    f32 isx = 1.0f / sx;
    f32 isy = 1.0f / sy;
    f32 ox = u1 * -0.5f / sx;
    f32 oy = v1 * -0.5f / sy;
    f32 half = fov * 0.5f;
    f32 cotangent = 1.0f / tanf(half);
    Unk_Float4* v = Unk_24e4c18;
    v[0].field_0[0].field_0 = isx;
    v[0].field_0[1].field_0 = isy;
    v[0].field_0[2].field_0 = ox;
    v[0].field_0[3].field_0 = oy;
    v[1].field_0[0].field_0 = sx;
    v[1].field_0[1].field_0 = sy;
    v[1].field_0[2].field_0 = cx;
    v[1].field_0[3].field_0 = cy;
    v[2].field_0[0].field_0 = half;
    v[2].field_0[1].field_0 = cotangent;
    v[2].field_0[2].field_0 = (u1 - u0) / static_cast<f32>(texture->field_4c) * 0.375f;
    v[2].field_0[3].field_0 = (v1 - v0) / static_cast<f32>(texture->field_50) * 0.375f;
    f32 depth = fmaxf(limit, 0.0001f);
    f32 q = u1 / depth;
    v[3].field_0[0].field_0 = q * (u1 / scaleX);
    v[3].field_0[1].field_0 = q * (u1 / scaleY);
    v[3].field_0[2].field_0 = q * 0.0f - (u1 - depth) * q;
    v[3].field_0[3].field_0 = q * 0.0f - (u1 - depth) * q;
    field_30.field_0->vf22(field_30.field_e0, Unk_24e4c18, 4);
    Unk_Float4 params(value, arg16, 0.0f, arg17);
    field_30.field_0->vf20(field_30.field_f8, &params.field_0[0].field_0);
    field_30.field_0->vf26(field_30.field_10[0], texture);
    f32 u2 = 0.0f;
    f32 v2 = 0.0f;
    f32 s2 = 0.0f;
    f32 t2 = 0.0f;
    if (noise != 0.0f) {
        static Unk_NoiseSeed seed0(1);
        static Unk_NoiseSeed seed1(0x3391);
        static Unk_NoiseSeed seed2(0x61e9b);
        static Unk_NoiseSeed seed3(0xbf1);
        if (animate) {
            seed0.Next();
            seed1.Next();
            seed2.Next();
            seed3.Next();
        }
        f32 r0 = seed0.Get();
        f32 r1 = seed1.Get();
        f32 r2 = seed2.Get();
        f32 r3 = seed3.Get();
        Unk_GPUTexture* noiseTexture = Unk_Texture29ab8(0);
        f32 stepX = aspect * (1024.0f / static_cast<f32>(noiseTexture->field_4c) * 2.0f) / noiseScale;
        f32 stepY = 1024.0f / static_cast<f32>(noiseTexture->field_50) * 2.0f / noiseScale;
        u2 = r0;
        v2 = r1;
        s2 = r0 + (r2 >= 0.0f ? 1.0f : -1.0f) * stepX;
        t2 = r1 + stepY * (r3 >= 0.0f ? 1.0f : -1.0f);
        v[0].field_0[0].field_0 = 2.0f;
        v[0].field_0[1].field_0 = -1.0f;
        v[0].field_0[2].field_0 = additive ? noise * 0.001f : noise;
        v[0].field_0[3].field_0 = additive ? 0.0f : 1.0f;
        v[1].field_0[0].field_0 = 0.5f;
        v[1].field_0[1].field_0 = 0.0f;
        v[1].field_0[2].field_0 = 0.0f;
        v[1].field_0[3].field_0 = 0.0f;
        field_30.field_0->vf22(field_30.field_d0, Unk_24e4c18, 2);
        field_30.field_0->vf26(field_30.field_10[1], noiseTexture);
    }
    texture->vf17(0);
    if (noise != 0.0f) {
        return Unk_471f60(x, y, width, height, u0, v0, u1, v1, u2, v2, s2, t2, flags);
    }
    return Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
}

// whether tone map `mode` is applied before the mapping (named by its log
// line) (inline)
inline bool HDRTMAP_IsPremap(s32 mode) {
    switch (mode) {
    case 3:
    case 5:
    case 7:
    case 9:
    case 11:
    case 12:
    case 13:
    case 15:
        return true;
    default:
        return false;
    }
}

// tone maps 2 to 9 (inline)
inline bool Unk_IsTonemap2To9(s32 mode) {
    switch (mode) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        return true;
    default:
        return false;
    }
}

// 0x7100478e90
// NON_MATCHING: a first draft with the original's calls, tables and matrices.
// The original keeps arg10 in its incoming stack slot (an alloca that isn't
// promoted: written there by the clamp and by the arg11 case, reread for the
// depth range), copies arg18's two sizes as integers, and branches in the
// arg11 case where this selects; the registers and spill slots differ.
s32 CTextureUtil::Unk_478e90(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 arg8,
                             f32 ratio, f32 arg10, f32 arg11, f32 arg12, s32 arg13, void* arg14, void* arg15,
                             void* arg16, void* arg17, void* arg18, bool arg19, Unk_GPUTexture* texture,
                             void* arg21, s32 arg22, s32 arg23) {
    s32 count = arg13 < 4 ? 3 : (arg13 > 6 ? 7 : 5);
    const f32* center = static_cast<const f32*>(arg14);
    const f32* offset = static_cast<const f32*>(arg15);
    const f32* shift = static_cast<const f32*>(arg16);
    const f32* depthOffset = static_cast<const f32*>(arg17);
    const f32* size = static_cast<const f32*>(arg18);
    Unk_GPUTexture* depth = static_cast<Unk_GPUTexture*>(arg21);
    f32 sizeX = size[0];
    f32 sizeY = size[1];
    bool sized = false;
    if (arg10 >= 0.0f && sizeX != 0.0f && sizeY != 0.0f) {
        f32 extent = 2.0f / ((sizeX > sizeY ? sizeX : sizeY) * height);
        arg10 = extent < arg10 ? arg10 : extent;
        sized = true;
    }
    f32 offsetX = offset[0];
    f32 depthX = depthOffset[0];
    bool flip = field_20->field_58;
    f32 offsetY = flip ? offset[1] : -offset[1];
    f32 shiftX = shift[0];
    f32 shiftY = flip ? -shift[1] : shift[1];
    f32 depthY = flip ? -depthOffset[1] : depthOffset[1];
    if (arg11 != 0.0f && !sized) {
        sizeX = ratio * 10.0f;
        sizeY = 10.0f;
        sized = true;
        arg10 = 0.0f;
    }
    bool useDepth = arg11 != 0.0f && sized && depth != nullptr;
    f32 half = 0.5f / ratio;
    s32 depthFilter = depth->vf19();
    s32 technique;
    if (sized) {
        technique = useDepth ? field_30.field_1b3d4[count - 1] : field_30.field_1b3b4[count - 1];
    } else {
        technique = field_30.field_1b3f4[count - 1];
    }
    field_30.field_0->vf29(technique);
    Unk_Float4 weights3[3] = {
        Unk_Float4(1.0f, 0.0f, 0.0f, 1.0f / 3.0f),
        Unk_Float4(0.0f, 1.0f, 0.0f, 1.0f / 3.0f),
        Unk_Float4(0.0f, 0.0f, 1.0f, 1.0f / 3.0f),
    };
    Unk_Float4 weights5[5] = {
        Unk_Float4(0.583333373f, 0.0f, 0.0f, 0.200000018f),
        Unk_Float4(0.416666687f, 1.0f / 6.0f, 0.0f, 0.200000018f),
        Unk_Float4(0.0f, 2.0f / 3.0f, 0.0f, 0.200000018f),
        Unk_Float4(0.0f, 1.0f / 6.0f, 1.0f / 3.0f, 0.200000018f),
        Unk_Float4(0.0f, 0.0f, 2.0f / 3.0f, 0.200000018f),
    };
    Unk_Float4 weights7[7] = {
        Unk_Float4(0.162500009f, 0.0f, 0.0f, 1.0f / 7.0f),
        Unk_Float4(0.5625f, 0.0f, 0.0f, 1.0f / 7.0f),
        Unk_Float4(0.25f, 0.25f, 0.0f, 1.0f / 7.0f),
        Unk_Float4(0.0f, 0.5f, 0.0f, 1.0f / 7.0f),
        Unk_Float4(0.0f, 0.25f, 0.25f, 1.0f / 7.0f),
        Unk_Float4(0.0f, 0.0f, 0.5f, 1.0f / 7.0f),
        Unk_Float4(0.025f, 0.0f, 0.25f, 1.0f / 7.0f),
    };
    f32 step = 1.0f / (static_cast<f32>(count) - 1.0f);
    const Unk_Float4* weights = nullptr;
    switch (count) {
    case 3:
        weights = weights3;
        break;
    case 5:
        weights = weights5;
        break;
    case 7:
        weights = weights7;
        step = 0.25f;
        break;
    }
    field_30.field_0->vf22(field_30.field_d0, weights, count);
    Unk_Vector3 toScale = {{u1 / (ratio + ratio), v1 * 0.5f, 1.0f}};
    Unk_Vector3 toOffset = {{u1 * 0.5f + half * shiftX, v1 * 0.5f + shiftY * 0.5f, 0.0f}};
    MATRIXT44 toTexture;
    Unk_40f660(&toTexture, &toScale, &toOffset);
    MATRIXT44 fromTexture;
    Unk_4155f0(&fromTexture, &toTexture);
    f32 nx = -center[0];
    f32 ny = -center[1];
    f32 rateX = powf((nx > 0.0f ? nx : -nx) + 1.0f, (nx > 0.0f ? 1.0f : (nx < 0.0f ? -1.0f : 0.0f)) * step);
    f32 rateY = powf((ny > 0.0f ? ny : -ny) + 1.0f, (ny > 0.0f ? 1.0f : (ny < 0.0f ? -1.0f : 0.0f)) * step);
    f32 lastX = powf(rateX, static_cast<f32>(count));
    f32 lastY = powf(rateY, static_cast<f32>(count));
    f32 scaleY = lastY > 1.0f ? 1.0f / lastY : 1.0f;
    f32 scaleX = lastX > 1.0f ? 1.0f / lastX : 1.0f;
    f32 moveX = offsetX * 0.5f;
    f32 moveY = -(offsetY * 0.5f);
    f32 stepX = offsetX * step;
    f32 stepY = offsetY * step;
    MATRIXT44 matrices[9];
    if (sized) {
        Unk_SetIdentity(&matrices[0]);
    }
    for (s32 i = 0; i < count; i++) {
        MATRIXT44* m = &matrices[i + (sized ? 1 : 0)];
        Unk_SetIdentity(m);
        MATRIXT44_MatrixMultiply(m, m, &fromTexture);
        MATRIXT44 transform;
        Unk_SetIdentity(&transform);
        transform.field_0[0][0] = scaleX;
        transform.field_0[1][1] = scaleY;
        MATRIXT44_MatrixMultiply(m, m, &transform);
        Unk_SetIdentity(&transform);
        transform.field_0[3][0] = moveX;
        transform.field_0[3][1] = moveY;
        MATRIXT44_MatrixMultiply(m, m, &transform);
        MATRIXT44_MatrixMultiply(m, m, &toTexture);
        scaleX *= rateX;
        scaleY *= rateY;
        moveX -= stepX;
        moveY += stepY;
    }
    field_30.field_0->vf25(field_30.field_114, matrices, count + (sized ? 1 : 0));
    field_30.field_0->vf26(field_30.field_10[0], texture);
    s32 filter = texture->vf16();
    texture->vf15(4);
    if (sized) {
        MATRIXT44 m;
        Unk_SetIdentity(&m);
        MATRIXT44_MatrixMultiply(&m, &m, &fromTexture);
        MATRIXT44 transform;
        Unk_SetIdentity(&transform);
        transform.field_0[3][0] = -depthX;
        transform.field_0[3][1] = -depthY;
        MATRIXT44_MatrixMultiply(&m, &m, &transform);
        Unk_SetIdentity(&transform);
        transform.field_0[0][0] = 1.0f / sizeX;
        transform.field_0[1][1] = 1.0f / sizeY;
        MATRIXT44_MatrixMultiply(&m, &m, &transform);
        f32 k = 1.0f / arg10;
        Unk_24e4c18[0].field_0[0] = m.field_0[0][0];
        Unk_24e4c18[0].field_0[1] = m.field_0[1][1];
        Unk_24e4c18[0].field_0[2] = m.field_0[3][0];
        Unk_24e4c18[0].field_0[3] = m.field_0[3][1];
        f32 range = 0.0f - k;
        Unk_24e4c18[1].field_0[0] = range;
        Unk_24e4c18[1].field_0[1] = k - range * 0.0f;
        s32 vectors = 2;
        if (useDepth) {
            if (arg19) {
                depth->vf17(1);
            }
            field_30.field_0->vf26(field_30.field_10[1], depth);
            f32 low = 0.5f - arg11;
            f32 depthRange = (arg11 + 0.5f) - low;
            Unk_24e4c18[2] = Unk_Float4(ratio * arg12, arg12, 0.0f, 0.0f);
            Unk_24e4c18[3] = Unk_Float4(depthRange, low - depthRange * 0.0f, 0.0f, 1.0f);
            vectors = 4;
        }
        field_30.field_0->vf22(field_30.field_e0, Unk_24e4c18, vectors);
    }
    s32 result = Unk_471c50(x, y, width, height, u0, v0, u1, v1, arg23);
    texture->vf15(filter);
    if (useDepth) {
        depth->vf17(depthFilter);
    }
    return result;
}

// the index of tech_TonemapHDR's options (inline)
inline u32 Unk_TonemapOptions(bool colorMatrix, bool fullColorDither, bool vignette, bool vignetteSim,
                              bool gammaCorrect, bool preColorMatrix, bool exposure) {
    return (colorMatrix ? 1 : 0) | (fullColorDither ? 2 : 0) | (vignette ? 4 : 0) | (vignetteSim ? 8 : 0) |
           (gammaCorrect ? 0x10 : 0) | (preColorMatrix ? 0x20 : 0) | (exposure ? 0x40 : 0);
}

// 0x710047c8d0 (its log line names it): the HDR tone map `mode` of texture0
// (and texture1) with its options: the colour matrices, the exposure, the
// full colour dither (field_29a70[0]'s texture), the vignette and its
// simulation, and the noise of four seeds that `animate` moves on
// NON_MATCHING: the four seeds are this function's guarded statics as in the
// original (not at 0x71024e45ec until the TU's merged statics are real); the
// original keeps the option flags in branches (the identity tests and the
// gamma test are jump-threaded into the computation of the index, the
// fallbacks recompute them), keeps its two Unk_472900 calls apart and calls
// MATRIXT44_MatrixMultiply; registers and the frame (0x10 larger) follow
s32 CTextureUtil::DrawRectGPU_TonemapHDR(f32 x, f32 y, f32 width, f32 height, f32 gamma, f32 arg5, f32 exposure,
                                         f32 white, const Unk_Float4* rect, Unk_GPUTexture* texture0,
                                         Unk_GPUTexture* texture1, s32 mode, const f32* params,
                                         const MATRIXT44* preMatrix, const MATRIXT44* matrix, f32 scale,
                                         Unk_Float dither, f32 vignette, f32 vignetteA, f32 vignetteB, f32 vignetteC,
                                         const Unk_Float4* arg21, s32 arg22, f32 arg23, f32 arg24,
                                         const Unk_Float4* arg25, f32 arg26, bool filter0, bool filter1, f32 arg29,
                                         f32 arg30, f32 arg31, f32 arg32, f32 noiseScale, f32 noiseAspect,
                                         bool animate, u32 flags) {
    Unk_GPUTexture* noiseTexture = arg30 != 0.0f || arg29 != 0.0f ? Unk_Texture29ab8(0)
                                                                   : reinterpret_cast<Unk_GPUTexture*>(field_29a70[3]);
    bool useExposure = exposure != 0.0f && exposure != 1.0f;
    f32 divisor = 1.0f;
    if (HDRTMAP_IsPremap(mode)) {
        white = white / scale;
    } else {
        divisor = scale;
    }
    if (!Unk_IsTonemap2To9(mode)) {
        gamma = gamma / divisor;
    }
    if (dither.field_0 == -3.40282347e+38f) {
        dither = Unk_Float(0.00392156886f);
    }
    field_20->vf30(1);
    bool vignetteOn = rect[2].field_0[0].field_0 != 0.0f || rect[2].field_0[1].field_0 != 0.0f ||
                      rect[2].field_0[2].field_0 != 0.0f || rect[2].field_0[3].field_0 != 0.0f;
    bool vignetteSim = false;
    if (vignette > 0.0f && vignetteOn) {
        vignetteSim = vignetteA > 0.0f || vignetteC > 0.0f;
        vignetteOn = vignetteSim;
    }
    Unk_GPUTexture* ditherTexture = reinterpret_cast<Unk_GPUTexture*>(field_29a70[0]);
    bool fullColorDither = dither.field_0 != 0.0f && dither.field_0 != 3.40282347e+38f;
    Unk_Float ditherValue = dither.field_0 == 3.40282347e+38f ? Unk_Float(0.0f) : dither;
    bool preColorMatrix = preMatrix != nullptr && !Unk_IsIdentity(&preMatrix->field_0[0][0]);
    bool colorMatrix = matrix != nullptr && !Unk_IsIdentity(&matrix->field_0[0][0]);
    bool gammaCorrect = !colorMatrix && gamma != 1.0f;
    s32 technique = field_30.field_20730[Unk_TonemapOptions(colorMatrix, fullColorDither, vignetteOn, vignetteSim,
                                                            gammaCorrect, preColorMatrix, useExposure)][mode];
    if (technique == 0 && !HDRTMAP_IsPremap(mode) && !gammaCorrect) {
        gammaCorrect = !colorMatrix;
        technique = field_30.field_20730[Unk_TonemapOptions(colorMatrix, fullColorDither, vignetteOn, vignetteSim,
                                                                gammaCorrect, preColorMatrix, useExposure)][mode];
    }
    if (technique == 0 && vignetteSim && !(dither.field_0 != 3.40282347e+38f && dither.field_0 != 0.0f && gammaCorrect)) {
        gammaCorrect = gammaCorrect || !colorMatrix;
        fullColorDither = true;
        technique = field_30.field_20730[Unk_TonemapOptions(colorMatrix, fullColorDither, vignetteOn, vignetteSim,
                                                                gammaCorrect, preColorMatrix, useExposure)][mode];
    }
    if (technique == 0) {
#line 18549
        PPFX_ERROR("CTextureUtil::DrawRectGPU_TonemapHDR(): 0x%04x, HDRTMAP_IsPremap(eTonemap: %d): %s,\n\tbFullColorDither: %s, bVignette: %s, bVignetteSim: %s, bExposure: %s,\n\tbPreColorMatrix: %s, bColorMatrix: %s, bGammaCorrect: %s\n",
                   Unk_TonemapOptions(colorMatrix, fullColorDither, vignetteOn, vignetteSim, gammaCorrect,
                                      preColorMatrix, useExposure),
                   mode, HDRTMAP_IsPremap(mode) ? "true" : "false", fullColorDither ? "true" : "false",
                   vignetteOn ? "true" : "false", vignetteSim ? "true" : "false", useExposure ? "true" : "false",
                   preColorMatrix ? "true" : "false", colorMatrix ? "true" : "false",
                   gammaCorrect ? "true" : "false");
        return -4;
    }
    field_30.field_0->vf29(technique);
    Unk_Float4 curve = Unk_47ba90(mode, params, white, divisor);
    field_30.field_0->vf20(field_30.field_104, &curve.field_0[0].field_0);
    Unk_Float4 values[3];
    values[0] = Unk_Float4(gamma, arg5, 1.0f, arg26);
    values[1] = *arg25;
    values[2] = *arg21;
    field_30.field_0->vf22(field_30.field_d0, values, 3);
    if (useExposure) {
        field_30.field_0->vf18(field_30.field_fc, 1.0f / exposure);
    }
    if (preColorMatrix) {
        MATRIXT44 identity;
        if (preMatrix == nullptr) {
            Unk_SetIdentity(&identity);
            preMatrix = &identity;
        }
        field_30.field_0->vf24(field_30.field_108, preMatrix);
    }
    if (colorMatrix) {
        MATRIXT44 color;
        if (matrix != nullptr) {
            color = *matrix;
        } else {
            Unk_SetIdentity(&color);
        }
        MATRIXT44 scale1;
        Unk_SetScale(&scale1, arg5);
        MATRIXT44 scale2;
        Unk_SetScale(&scale2, gamma);
        MATRIXT44 product;
        MATRIXT44_MatrixMultiply(&product, &scale1, &color);
        MATRIXT44 glare = product;
        MATRIXT44_MatrixMultiply(&product, &scale2, &color);
        color = product;
        field_30.field_0->vf24(field_30.field_10c, &color);
        field_30.field_0->vf24(field_30.field_110, &glare);
    }
    s32 saved0 = -1;
    if (texture0 != nullptr) {
        saved0 = texture0->vf16();
        field_30.field_0->vf26(field_30.field_8, texture0);
        texture0->vf17(filter0);
        texture0->vf18(1);
    }
    s32 saved1 = -1;
    if (texture1 != nullptr) {
        saved1 = texture1->vf16();
        field_30.field_0->vf26(field_30.field_c, texture1);
        texture1->vf17(filter1);
        texture1->vf18(1);
    }
    if (fullColorDither) {
        Unk_Float4 offsets(ditherValue, ditherValue, -ditherValue.field_0, 0.0f);
        if (ditherValue.field_0 < 0.0f) {
            offsets.field_0[1].field_0 = 0.0f;
            offsets.field_0[2].field_0 = ditherValue.field_0 * -0.5f;
        }
        if (ditherTexture == reinterpret_cast<Unk_GPUTexture*>(field_29a70[1])) {
            offsets.field_0[1].field_0 = 0.0f;
            offsets.field_0[2].field_0 = 0.0f;
        }
        field_30.field_0->vf20(field_30.field_100, &offsets.field_0[0].field_0);
        field_30.field_0->vf26(field_30.field_10[3], ditherTexture);
        ditherTexture->vf15(ditherTexture == reinterpret_cast<Unk_GPUTexture*>(field_29a70[1]) ? 1 : 13);
    }
    if (vignetteSim) {
        f32 a;
        f32 b;
        f32 d;
        if (vignetteC < 0.0f) {
            a = 0.0f;
            b = 1.0f;
            d = 1.0f;
        } else {
            a = -0.5f / vignetteC;
            f32 c = a * vignetteB;
            f32 r = vignetteC > vignetteB ? vignetteB / vignetteC : 1.0f;
            b = 0.5f - c;
            d = r * r;
        }
        Unk_Float4 v(a, b, vignette, d);
        field_30.field_0->vf20(field_30.field_e4, &v.field_0[0].field_0);
        field_30.field_0->vf18(field_30.field_e8, vignetteA * 0.5f);
    } else {
        Unk_Float4 v(-1.0f, vignetteB * vignetteB + 1.0f, 0.0f, 0.0f);
        field_30.field_0->vf20(field_30.field_e4, &v.field_0[0].field_0);
    }
    static Unk_NoiseSeed seed0(1);
    static Unk_NoiseSeed seed1(0x3391);
    static Unk_NoiseSeed seed2(0x61e9b);
    static Unk_NoiseSeed seed3(0xbf1);
    if (animate) {
        seed0.Next();
        seed1.Next();
        seed2.Next();
        seed3.Next();
    }
    f32 r0 = seed0.Get();
    f32 r1 = seed1.Get();
    f32 r2 = seed2.Get();
    f32 r3 = seed3.Get();
    f32 stepX = 1024.0f / static_cast<f32>(noiseTexture->field_4c) * 2.0f * noiseAspect;
    f32 stepY = 1024.0f / static_cast<f32>(noiseTexture->field_50) * 2.0f;
    if (noiseScale != 0.0f) {
        stepX = stepX / noiseScale;
        stepY = stepY / noiseScale;
    }
    f32 s2 = r0 + (r2 >= 0.0f ? 1.0f : -1.0f) * stepX;
    f32 t2 = r1 + (r3 >= 0.0f ? 1.0f : -1.0f) * stepY;
    Unk_Float4* v = Unk_24e4c18;
    v[0].field_0[0].field_0 = 2.0f;
    v[0].field_0[1].field_0 = -1.0f;
    v[0].field_0[2].field_0 = arg30 * 0.1f;
    v[0].field_0[3].field_0 = 0.0f;
    v[1].field_0[0].field_0 = arg32;
    v[1].field_0[1].field_0 = 0.0f;
    v[1].field_0[2].field_0 = 0.0f;
    v[1].field_0[3].field_0 = 0.0f;
    v[2].field_0[0].field_0 = 2.0f;
    v[2].field_0[1].field_0 = -1.0f;
    v[2].field_0[2].field_0 = arg29 * 0.5f;
    v[2].field_0[3].field_0 = 1.0f;
    v[3].field_0[0].field_0 = arg31;
    v[3].field_0[1].field_0 = 0.0f;
    v[3].field_0[2].field_0 = 0.0f;
    v[3].field_0[3].field_0 = 0.0f;
    field_30.field_0->vf22(field_30.field_d4, Unk_24e4c18, 4);
    field_30.field_0->vf26(field_30.field_10[2], noiseTexture);
    s32 result;
    if (fullColorDither) {
        f32 sizeX = width / static_cast<f32>(ditherTexture->field_4c);
        f32 sizeY = height / static_cast<f32>(ditherTexture->field_50);
        f32 left;
        f32 top;
        f32 right;
        f32 bottom;
        if (ditherTexture == reinterpret_cast<Unk_GPUTexture*>(field_29a70[1])) {
            f32 fitX = width >= 1920.0f ? 1920.0f / width : 1.0f;
            f32 fitY = height >= 1080.0f ? 1080.0f / height : 1.0f;
            f32 fit = fitX > fitY ? fitX : fitY;
            left = (1.0f - sizeX / fit) * 0.5f;
            top = 1.0f - sizeY / fit + 0.046875f;
            ditherTexture->vf15(fit == 1.0f);
            right = 1.0f - left;
            bottom = 1.046875f;
        } else {
            ditherTexture->vf15(13);
            left = 0.0f;
            top = 0.0f;
            right = sizeX;
            bottom = sizeY;
        }
        bool flip = field_20->field_58;
        result = Unk_472900(x, y, width, height, rect[0].field_0[0].field_0, rect[0].field_0[1].field_0,
                            rect[0].field_0[2].field_0, rect[0].field_0[3].field_0, rect[1].field_0[0].field_0,
                            rect[1].field_0[1].field_0, rect[1].field_0[2].field_0, rect[1].field_0[3].field_0,
                            rect[2].field_0[0].field_0, rect[2].field_0[1].field_0, rect[2].field_0[2].field_0,
                            rect[2].field_0[3].field_0, r0, r1, s2, t2, left, flip ? bottom : top, right,
                            flip ? top : bottom, flags);
    } else {
        result = Unk_472900(x, y, width, height, rect[0].field_0[0].field_0, rect[0].field_0[1].field_0,
                            rect[0].field_0[2].field_0, rect[0].field_0[3].field_0, rect[1].field_0[0].field_0,
                            rect[1].field_0[1].field_0, rect[1].field_0[2].field_0, rect[1].field_0[3].field_0,
                            rect[2].field_0[0].field_0, rect[2].field_0[1].field_0, rect[2].field_0[2].field_0,
                            rect[2].field_0[3].field_0, r0, r1, s2, t2, 0.0f, 0.0f, 0.0f, 0.0f, flags);
    }
    if (texture0 != nullptr) {
        texture0->vf15(saved0);
    }
    // (the original puts texture0's filter back twice)
    if (texture1 != nullptr) {
        texture0->vf15(saved1);
    }
    return result;
}

// 0x7100478880 (its callers pass a flag it doesn't read)
f32 Unk_478880(f32 arg1, f32 arg2, bool flag) {
    return arg1 / arg2;
}

// `target` as the device's only target (inline)
static inline s32 Unk_SetTargets(CRenderTexture* target, s32 arg) {
    CRenderTexture* targets[8] = {target};
    return Unk_49da70(8, targets, nullptr, nullptr, 0, nullptr, 0, arg, 0, 1.0f);
}

// 0x710047d960: `arg5` filtered into `target` or `targetTexture` (one of the
// two) with Unk_411df0's weights scaled to `arg4` by `arg9`, and `arg15`
// added with `arg14` where its largest value is positive
// NON_MATCHING: the filter flag (`clear` or the texture's 0x20000 bit) is a
// `cset` here, branches to two constants in the original; the scaled colours'
// stores are not paired, and spill slots and registers differ (the frame is
// 16 bytes larger). Unk_SetTargets' array is above the others as the
// original's (an inline function's alloca)
s32 CTextureUtil::Unk_47d960(f32 arg1, f32 arg2, f32 arg3, f32 arg4, void* arg5, CRenderTexture* target,
                             Unk_GPUTexture* targetTexture, s32 arg8, void* arg9, s32 arg10, bool arg11, bool clear,
                             s32 arg13, const Unk_Float4* arg14, void* arg15, s32 arg16) {
    if ((targetTexture != nullptr) == (target != nullptr)) {
        return -6;
    }
    if (field_20 == nullptr) {
        return -1;
    }
    CRenderTexture* source = static_cast<CRenderTexture*>(arg5);
    const Unk_Float4* color = static_cast<const Unk_Float4*>(arg9);
    f32 most = arg14->field_0[0].field_0 > arg14->field_0[1].field_0 ? arg14->field_0[0].field_0
                                                                     : arg14->field_0[1].field_0;
    most = most > arg14->field_0[2].field_0 ? most : arg14->field_0[2].field_0;
    most = most > arg14->field_0[3].field_0 ? most : arg14->field_0[3].field_0;
    CRenderTexture* second = most > 0.0f ? static_cast<CRenderTexture*>(arg15) : nullptr;
    if (arg11) {
        field_20->vf39();
        field_20->vf40(-1);
        field_20->vf42(0);
    }
    if (targetTexture != nullptr) {
        Unk_49e3a0(1, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
    }
    bool linear;
    if (clear || !(Unk_GetTexture(source)->field_5c & 0x20000)) {
        linear = true;
    } else {
        linear = false;
    }
    f32 sourceWidth = static_cast<f32>(static_cast<u32>(source->field_54));
    f32 sourceHeight = static_cast<f32>(static_cast<u32>(source->field_58));
    f32 u1;
    f32 v1;
    Unk_GetCoords(source, &u1, &v1);
    u32 targetWidth = target != nullptr ? static_cast<u32>(target->field_54) : targetTexture->field_4c;
    u32 targetHeight = target != nullptr ? static_cast<u32>(target->field_58) : targetTexture->field_50;
    f32 width = arg1 > 0.0f ? sourceWidth * arg1 : static_cast<f32>(targetWidth);
    f32 height = arg2 > 0.0f ? sourceHeight * arg2 : static_cast<f32>(targetHeight);
    s32 first = most > 0.0f;
    Unk_Float4 values[26];
    Unk_Float4 colors[26];
    s32 count = Unk_411df0(source->field_80->field_8, source->field_80->field_c, &values[first], arg16, linear,
                           arg13, sourceWidth, sourceHeight, width, height, arg1, arg2, arg3);
    if (count >= 1) {
        f32 scale = arg4 / static_cast<f32>(count);
        for (s32 i = 0; i < count; i++) {
            colors[first + i] = Unk_Float4(scale * color->field_0[0].field_0, scale * color->field_0[1].field_0,
                                           scale * color->field_0[2].field_0, scale * color->field_0[3].field_0);
        }
    }
    if (most > 0.0f) {
        count++;
        colors[0] = Unk_Float4(color->field_0[0].field_0 * arg14->field_0[0].field_0,
                               color->field_0[1].field_0 * arg14->field_0[1].field_0,
                               color->field_0[2].field_0 * arg14->field_0[2].field_0,
                               color->field_0[3].field_0 * arg14->field_0[3].field_0);
        values[0] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    if (!Unk_442c50_get(reinterpret_cast<u64>(field_20))) {
        s32 n = count + 1;
        if (most > 0.0f) {
            for (;; n--) {
                s32 technique = arg8 == 21 ? 0 : field_30.field_2218[n - 2][arg8];
                if (n < 2 || technique != 0) {
                    break;
                }
            }
        } else {
            for (;; n--) {
                s32 technique = field_30.field_118[n - 2][arg8];
                if (n < 2 || technique != 0) {
                    break;
                }
            }
        }
        s32 used = n - 1;
        if (used < count) {
            if (used >= 1) {
                f32 scale = static_cast<f32>(count) / static_cast<f32>(used);
                for (s32 i = 0; i < used; i++) {
                    for (s32 c = 0; c < 4; c++) {
                        colors[i].field_0[c].field_0 *= scale;
                    }
                }
            }
            count = used;
        }
    }
    s32 result;
    if (targetTexture != nullptr) {
        field_20->vf8(nullptr);
        result = field_20->vf7(0, targetTexture, arg10);
        if (result < 0) {
            return result;
        }
    } else {
        Unk_SetTargets(target, arg10);
        result = CRenderTexture::Unk_49cf50(nullptr, nullptr);
        if (result < 0) {
            return result;
        }
    }
    if (arg3 == 0.0f && static_cast<u32>(source->field_54) == targetWidth &&
        static_cast<u32>(source->field_58) == targetHeight) {
        linear = true;
    }
    bool linear2 = second != nullptr && static_cast<u32>(second->field_54) == targetWidth &&
                   static_cast<u32>(second->field_58) == targetHeight;
    Unk_GetTexture(source)->vf17(linear);
    if (second != nullptr) {
        Unk_GetTexture(second)->vf15(linear2);
    }
    Unk_GPUTexture* texture = Unk_GetTexture(source);
    if (most > 0.0f) {
        result = Unk_476580(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, count, values, colors, texture,
                            Unk_GetTexture(second), arg8, 0);
    } else {
        result = DrawRectGPU_MadT1_Sn(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, count, values, colors, texture,
                                      arg8, 0);
    }
    Unk_GetTexture(source)->vf17(0);
    if (second != nullptr) {
        Unk_GetTexture(second)->vf17(0);
    }
    return result < 0 ? result : 0;
}

// 0x710047dfa0: 0x710047d960 into a render texture
s32 CTextureUtil::Unk_47dfa0(f32 arg1, f32 arg2, f32 arg3, f32 arg4, void* arg5, CRenderTexture* target, u32 arg8,
                             void* arg9, s32 arg10, bool arg11, bool clear, s32 arg13, const Unk_Float4* arg14,
                             void* arg15, s32 arg16) {
    return Unk_47d960(arg1, arg2, arg3, arg4, arg5, target, nullptr, arg8, arg9, arg10, arg11, clear, arg13, arg14,
                      arg15, arg16);
}

// DRAWRECTGPU_END

// 0x71004708b0: releases what the device made
s32 CTextureUtil::Unk_4708b0(void* arg) {
    field_29bb0 = arg;
    field_30.Unk_46d990(arg);
    field_29a58->vf1();
    field_29a98->vf1();
    PPFX_SAFE_RELEASE(field_29b00);
    for (s32 i = 0; i < 10; i++) {
        PPFX_SAFE_RELEASE(field_29b08[i]);
    }
    PPFX_SAFE_RELEASE_INTERFACE(field_29a70[0]);
    PPFX_SAFE_RELEASE_INTERFACE(field_29a70[1]);
    PPFX_SAFE_RELEASE_INTERFACE(field_29a70[2]);
    PPFX_SAFE_RELEASE_INTERFACE(field_29a70[3]);
    PPFX_SAFE_RELEASE_INTERFACE(field_29a70[4]);
    PPFX_SAFE_RELEASE_INTERFACE(field_29aa0[1]);
    PPFX_SAFE_RELEASE_INTERFACE(field_29aa0[0]);
    PPFX_SAFE_RELEASE_INTERFACE(field_29ab8[0]);
    PPFX_SAFE_RELEASE_INTERFACE(field_29ab8[1]);
    PPFX_SAFE_RELEASE_INTERFACE(field_29ab8[2]);
    PPFX_SAFE_RELEASE_INTERFACE(field_29ad8[0]);
    PPFX_SAFE_RELEASE_INTERFACE(field_29ad8[1]);
    for (s32 i = 0; i < 7; i++) {
        PPFX_SAFE_RELEASE_INTERFACE(field_29bc8[i]);
    }
    UNK_DELETE_ARRAY(field_29af8);
    field_29af0 = 0;
    return CGPUResourceManage::vf1();
}

// 0x7100470e40
s32 CTextureUtil::vf1() {
    Unk_4708b0(nullptr);
    return CGPUResourceManage::vf1();
}

// 0x7100470e70
s32 CTextureUtil::vf2() {
    s32 result = CGPUResourceManage::vf2();
    return result < 0 ? result : 0;
}

// 0x7100470e90: releases the rest, and puts the members back as the
// constructor left them
s32 CTextureUtil::vf3() {
    PPFX_SAFE_RELEASE(field_29a98);
    PPFX_SAFE_RELEASE(field_29b00);
    for (s32 i = 0; i < 10; i++) {
        PPFX_SAFE_RELEASE(field_29b08[i]);
    }
    Unk_Clear();
    s32 result = CGPUResourceManage::vf3();
    return result < 0 ? result : 0;
}

// 0x710046e110, 0x710046e1c0 (deleting)
CTextureUtil::~CTextureUtil() {
    if (field_29bb0 != nullptr) {
        CTextureUtil::vf1();
    }
    Unk_49ec80();
    UNK_DELETE(field_29a58);
}

// 0x7100480740: a full-target rectangle of the technique pair field_29990 /
// field_29994 with the curve of `a`, `b` and `c` in the scratch vectors (`d`
// is not read)
s32 CTextureUtil::Unk_480740(CRenderTexture* target, bool second, bool positive, const void* value, bool clear,
                             u32 flags, f32 a, f32 b, f32 c, f32 d) {
    if (clear) {
        Unk_471410();
    }
    u32 width = target->field_54;
    u32 height = target->field_58;
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0) {
        return result;
    }
    f32 h = static_cast<f32>(height);
    f32 w = static_cast<f32>(width);
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    field_30.field_0->vf29(second ? field_30.field_29994 : field_30.field_29990);
    f32 inverse = 1.0f / b;
    f32 power = powf(10.0f, c + 1.0f);
    f32* v = &Unk_24e4c18[0].field_0[0].field_0;
    v[0] = positive ? 0.0f : -1.0f;
    v[1] = inverse;
    v[2] = a;
    v[4] = b;
    v[5] = 2.32558131f;
    v[6] = power;
    v[7] = 0.0f;
    v[8] = 10.0f;
    v[9] = b;
    v[10] = c;
    v[11] = 0.0f;
    v[12] = 6.0f;
    v[13] = 6.0f;
    v[14] = 6.0f;
    v[15] = 1.0f;
    v[16] = 1.0f;
    v[17] = 1.0f;
    v[18] = 1.0f;
    v[19] = 1.0f;
    v[20] = 1.0f;
    v[21] = 1.0f;
    v[22] = 1.0f;
    v[23] = 1.0f;
    v[24] = 1.0f;
    v[25] = 0.0f;
    v[26] = 0.0f;
    v[27] = 1.0f;
    v[28] = 1.0f;
    v[29] = 1.0f;
    v[30] = 0.0f;
    v[31] = 1.0f;
    v[32] = 0.0f;
    v[33] = 1.0f;
    v[34] = 0.0f;
    v[35] = 1.0f;
    v[36] = 0.0f;
    v[37] = 1.0f;
    v[38] = 1.0f;
    v[39] = 1.0f;
    v[40] = 0.0f;
    v[41] = 0.0f;
    v[42] = 1.0f;
    v[43] = 1.0f;
    v[44] = 1.0f;
    v[45] = 0.0f;
    v[46] = 1.0f;
    v[47] = 1.0f;
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4c18, 12);
    field_30.field_0->vf24(field_30.field_10c, value);
    return Unk_471c50(0.0f, 0.0f, w, h, 0.0f, 0.0f, 1.0f, 1.0f, flags);
}

// 0x71004809a0: technique field_29998[...] (by `arg11`, `arg13` and `arg14`)
// with the colour space `space`'s matrices and a table of hues fading to grey
// NON_MATCHING: the stores of the hue table (the original merges a few of
// them into other pairs: [13] and [4] as one pair each, [26].w with [27].x),
// two constants of the fallback technique's select materialised the other
// way round, and the scheduling of the constants before the first table
// (the frame keeps the 0x3f80000000000000 pair in x24, here x23). Tried: the
// components and the entries in other orders, the clamp and the fallback
// written in other forms.
s32 CTextureUtil::Unk_4809a0(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 arg8,
                             f32 arg9, f32 arg10, bool arg11, void* arg12, bool arg13, bool arg14, void* arg15,
                             s32 arg16) {
    MATRIXT44* Unk_411b00(MATRIXT44* out, const Unk_410f90_Point* red, const Unk_410f90_Point* green,
                          const Unk_410f90_Point* blue, const Unk_410f90_Point* white);
    void Unk_4155f0(MATRIXT44* out, const MATRIXT44* m);
    void Unk_411190(MATRIXT44* out, const Unk_410f90* from, const Unk_410f90* to, bool arg3);
    const Unk_410f90* space = static_cast<const Unk_410f90*>(arg12);
    f32 bottom = 1.0f - v1;
    f32 top = 1.0f - v0;
    s32 technique;
    if (arg11) {
        if (arg14) {
            technique = arg13 ? field_30.field_29998[5] : field_30.field_29998[4];
        } else {
            technique = field_30.field_29998[3];
        }
    } else {
        if (arg14) {
            technique = arg13 ? field_30.field_29998[2] : field_30.field_29998[1];
        } else {
            technique = field_30.field_29998[0];
        }
    }
    if (technique == 0) {
        technique = arg11 ? field_30.field_29998[3] : field_30.field_29998[0];
    }
    field_30.field_0->vf29(technique);
    MATRIXT44 toXyz;
    Unk_411b00(&toXyz, &space->field_0, &space->field_8, &space->field_10, &space->field_18);
    MATRIXT44 inverse;
    Unk_4155f0(&inverse, &toXyz);
    MATRIXT44 fromXyz = inverse;
    field_30.field_0->vf24(field_30.field_108, &fromXyz);
    Unk_411190(&toXyz, static_cast<const Unk_410f90*>(arg15), space, false);
    field_30.field_0->vf24(field_30.field_10c, &toXyz);
    Unk_4155f0(&inverse, &fromXyz);
    field_30.field_0->vf24(field_30.field_110, &inverse);
    f32 k = arg11 ? 0.008f : 0.01f;
    f32* v = &Unk_24e4c18[0].field_0[0].field_0;
    v[0] = 1.0f;
    v[1] = -1.0f;
    v[2] = 0.0f;
    v[3] = 1.0f;
    v[4] = 0.7f;
    v[5] = 0.7f;
    v[6] = 0.7f;
    v[7] = 0.7f;
    Unk_24e4c18[2].field_0[0] = space->field_18.field_0;
    Unk_24e4c18[2].field_0[1] = space->field_18.field_4;
    v[10] = 1.0f;
    v[11] = arg8;
    v[12] = 0.0f;
    v[13] = 2.0f;
    v[14] = 0.6f;
    v[15] = 0.35f;
    v[16] = k;
    v[17] = k * 0.6f;
    v[18] = k * 0.8f;
    v[19] = k * 0.2f;
    v[20] = arg9;
    f32 c = arg10 < 0.0f ? 0.0f : (arg10 >= 0.999f ? 0.999f : arg10);
    v[21] = 1.0f / (1.0f - powf(c, 0.25f));
    v[22] = 0.0f;
    v[23] = 0.0f;
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4c18, 6);
    v[3] = 0.5f;
    v[0] = 1.0f;
    v[1] = 0.0f;
    v[2] = 0.0f;
    v[27] = 0.5f;
    v[24] = 0.5f;
    v[25] = 0.5f;
    v[26] = 0.0f;
    v[51] = 0.5f;
    v[48] = 0.0f;
    v[49] = 1.0f;
    v[50] = 0.0f;
    v[75] = 0.5f;
    v[72] = 0.0f;
    v[73] = 0.5f;
    v[74] = 0.5f;
    v[99] = 0.5f;
    v[96] = 0.0f;
    v[97] = 0.0f;
    v[98] = 1.0f;
    v[123] = 0.5f;
    v[120] = 0.5f;
    v[121] = 0.0f;
    v[122] = 0.5f;
    v[7] = 0.5f;
    v[4] = 0.8888889f;
    v[5] = 0.055555556f;
    v[6] = 0.055555556f;
    v[31] = 0.5f;
    v[28] = 0.4722222f;
    v[29] = 0.4722222f;
    v[30] = 0.055555556f;
    v[55] = 0.5f;
    v[52] = 0.055555556f;
    v[53] = 0.8888889f;
    v[54] = 0.055555556f;
    v[79] = 0.5f;
    v[76] = 0.055555556f;
    v[77] = 0.4722222f;
    v[78] = 0.4722222f;
    v[103] = 0.5f;
    v[100] = 0.055555556f;
    v[101] = 0.055555556f;
    v[102] = 0.8888889f;
    v[127] = 0.5f;
    v[124] = 0.4722222f;
    v[125] = 0.055555556f;
    v[126] = 0.4722222f;
    v[11] = 0.5f;
    v[8] = 0.7777778f;
    v[9] = 0.11111111f;
    v[10] = 0.11111111f;
    v[35] = 0.5f;
    v[32] = 0.44444445f;
    v[33] = 0.44444445f;
    v[34] = 0.11111111f;
    v[59] = 0.5f;
    v[56] = 0.11111111f;
    v[57] = 0.7777778f;
    v[58] = 0.11111111f;
    v[83] = 0.5f;
    v[80] = 0.11111111f;
    v[81] = 0.44444445f;
    v[82] = 0.44444445f;
    v[107] = 0.5f;
    v[104] = 0.11111111f;
    v[105] = 0.11111111f;
    v[106] = 0.7777778f;
    v[131] = 0.5f;
    v[128] = 0.44444445f;
    v[129] = 0.11111111f;
    v[130] = 0.44444445f;
    v[15] = 0.5f;
    v[12] = 0.6666666f;
    v[13] = 0.16666667f;
    v[14] = 0.16666667f;
    v[39] = 0.5f;
    v[36] = 0.41666666f;
    v[37] = 0.41666666f;
    v[38] = 0.16666667f;
    v[63] = 0.5f;
    v[60] = 0.16666667f;
    v[61] = 0.6666666f;
    v[62] = 0.16666667f;
    v[87] = 0.5f;
    v[84] = 0.16666667f;
    v[85] = 0.41666666f;
    v[86] = 0.41666666f;
    v[111] = 0.5f;
    v[108] = 0.16666667f;
    v[109] = 0.16666667f;
    v[110] = 0.6666666f;
    v[135] = 0.5f;
    v[132] = 0.41666666f;
    v[133] = 0.16666667f;
    v[134] = 0.41666666f;
    v[19] = 0.5f;
    v[16] = 0.5555556f;
    v[17] = 0.22222222f;
    v[18] = 0.22222222f;
    v[43] = 0.5f;
    v[40] = 0.3888889f;
    v[41] = 0.3888889f;
    v[42] = 0.22222222f;
    v[67] = 0.5f;
    v[64] = 0.22222222f;
    v[65] = 0.5555556f;
    v[66] = 0.22222222f;
    v[91] = 0.5f;
    v[88] = 0.22222222f;
    v[89] = 0.3888889f;
    v[90] = 0.3888889f;
    v[115] = 0.5f;
    v[112] = 0.22222222f;
    v[113] = 0.22222222f;
    v[114] = 0.5555556f;
    v[139] = 0.5f;
    v[136] = 0.3888889f;
    v[137] = 0.22222222f;
    v[138] = 0.3888889f;
    v[23] = 0.5f;
    v[20] = 0.44444448f;
    v[21] = 0.27777776f;
    v[22] = 0.27777776f;
    v[47] = 0.5f;
    v[44] = 0.3611111f;
    v[45] = 0.3611111f;
    v[46] = 0.27777776f;
    v[71] = 0.5f;
    v[68] = 0.27777776f;
    v[69] = 0.44444448f;
    v[70] = 0.27777776f;
    v[95] = 0.5f;
    v[92] = 0.27777776f;
    v[93] = 0.3611111f;
    v[94] = 0.3611111f;
    v[119] = 0.5f;
    v[116] = 0.27777776f;
    v[117] = 0.27777776f;
    v[118] = 0.44444448f;
    v[143] = 0.5f;
    v[140] = 0.3611111f;
    v[141] = 0.27777776f;
    v[142] = 0.3611111f;
    v[147] = 1.0f;
    v[144] = 1.0f;
    v[145] = 1.0f;
    v[146] = 1.0f;
    field_30.field_0->vf22(field_30.field_c8, Unk_24e4c18, 37);
    return Unk_471c50(x, y, width, height, u0, bottom, u1, top, arg16);
}

// GPUTEXTUREUTIL_SECOND_HALF_BEGIN: functions of 0x7100481000 on

// 0x710048d020: `source` blurred into `target` with Unk_413160's samples of
// its first level (`mask`'s texture as the mask)
// NON_MATCHING: scheduling only: the device's load for Unk_442c50_get and
// the zero clamp's `csel` come one instruction apart. Tried: the reads, the
// clamp and the fallback's two assignments in other orders and as selects.
s32 CTextureUtil::Unk_48d020(CRenderTexture* source, CRenderTexture* target, CRenderTexture* mask, u32 arg3,
                             const Unk_Float2* arg4, s32 usnorm, s32 bits, bool background, s32 dense, bool clear) {
    if (clear) {
        Unk_471410();
    }
    CRenderTexture::Unk_Level* level = source->field_80;
    s32 second = dense < 1 ? dense : 1;
    second = second < 0 ? 0 : second;
    f32 u1;
    f32 v1;
    Unk_GetCoords(source, &u1, &v1);
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    u32 levelHeight = level->field_c;
    u32 mode = second == 1 ? 0x21 : 0x11;
    u32 levelWidth = level->field_8;
    if (!Unk_442c50_get(reinterpret_cast<u64>(field_20))) {
        second = 0;
        mode = 9;
    }
    Unk_Float4 values[33];
    s32 count = Unk_413160(levelWidth, levelHeight, arg3, values, mode, second, 1.0f);
    Unk_442c50_get(reinterpret_cast<u64>(field_20));
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0) {
        return result;
    }
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    Unk_GPUTexture* texture = Unk_GetTexture(source);
    Unk_GPUTexture* maskTexture = mask != nullptr ? Unk_GetTexture(mask) : nullptr;
    result = Unk_47b560(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, background, count, values, arg4, texture,
                        maskTexture, usnorm, bits, second, 0);
    return result < 0 ? result : 0;
}

// 0x710048fb40: Unk_490020 from `source`, `history`, `arg11` (and `depth`)
// into `target`; without `history`, `source` and `arg11` blended by
// Unk_48d220, and `source` copied when arg5 and arg6 are both 1 or more
// NON_MATCHING: the register allocation of the history path. The address of
// `source->field_88` is shared with Unk_GetCoords' loads here (a pre-indexed
// load, then spilled), so `source` dies in its texture walk; the original
// keeps `source` in x20 and computes the address again at the call. The
// other statements are the original's.
s32 CTextureUtil::Unk_48fb40(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7,
                             CRenderTexture* target, CRenderTexture* source, CRenderTexture* history,
                             CRenderTexture* arg11, CRenderTexture* depth, bool dynamic, s32 arg14,
                             const Unk_Float2* arg15, s32 channel, const Unk_Float2* arg17, const Unk_Float2* arg18,
                             f32 arg19, f32 arg20, f32 arg21, f32 arg22, const Unk_Float4* color,
                             const Unk_Float4* arg24, bool clear) {
    if (field_20 == nullptr) {
        return -1;
    }
    if (clear) {
        Unk_471410();
    }
    if ((arg5 < arg6 ? arg5 : arg6) >= 1.0f) {
        Unk_Float4 one(1.0f, 1.0f, 1.0f, 1.0f);
        Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
        return Unk_47d960(0.0f, 0.0f, 0.0f, 1.0f, source, target, nullptr, 0, &one, 0, false, false, 1, &zero,
                          nullptr, -1);
    }
    if (history == nullptr) {
        Unk_Float4 colors[2];
        colors[0].field_0[0].field_0 = arg5;
        colors[0].field_0[1].field_0 = arg5;
        colors[0].field_0[2].field_0 = arg5;
        colors[0].field_0[3].field_0 = 1.0f;
        CRenderTexture* sources[2] = {source, arg11};
        colors[1].field_0[0].field_0 = (1.0f - arg5) *
            (color->field_0[0].field_0 + (1.0f - color->field_0[0].field_0) * arg5) * arg22;
        colors[1].field_0[1].field_0 = (1.0f - arg5) *
            (color->field_0[1].field_0 + (1.0f - color->field_0[1].field_0) * arg5) * arg22;
        colors[1].field_0[2].field_0 = (1.0f - arg5) *
            (color->field_0[2].field_0 + (1.0f - color->field_0[2].field_0) * arg5) * arg22;
        colors[1].field_0[3].field_0 = 0.0f;
        return Unk_48d220(1.0f, 1.0f, target, 2, sources, colors, 0, false);
    }
    f32 u0, v0;
    Unk_GetCoords(source, &u0, &v0);
    f32 u1, v1;
    Unk_GetCoords(history, &u1, &v1);
    f32 u2, v2;
    Unk_GetCoords(depth != nullptr ? depth : source, &u2, &v2);
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0) {
        return result;
    }
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    result = Unk_490020(0.0f, 0.0f, width, height, 0.0f, 0.0f, u0, v0, 0.0f, 0.0f, u1, v1, 0.0f, 0.0f, u2, v2,
                        Unk_GetTexture(source), Unk_GetTexture(history), Unk_GetTexture(arg11),
                        depth != nullptr ? Unk_GetTexture(depth) : nullptr,
                        reinterpret_cast<const Unk_Float2*>(&source->field_88),
                        reinterpret_cast<const Unk_Float2*>(depth != nullptr ? &depth->field_88 : &source->field_88),
                        reinterpret_cast<const Unk_Float2*>(&history->field_88), arg0, arg1, dynamic, arg2, arg3,
                        arg14, arg15, channel, arg17, arg18, arg4, arg5, arg6, arg7, arg19, arg20, arg21, arg22,
                        color, arg24, 0);
    return result < 0 ? result : 0;
}

// 0x7100490020: tech_TemporalAntialias(_Tonemap)(_DynamicPixel(_Depth<channel>))
// of three textures (and `depth`'s channel `channel`)
s32 CTextureUtil::Unk_490020(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 s0, f32 t0, f32 u1, f32 v1,
                             f32 s1, f32 t1, f32 u2, f32 v2, f32 s2, f32 t2, Unk_GPUTexture* texture0,
                             Unk_GPUTexture* texture2, Unk_GPUTexture* texture1, Unk_GPUTexture* depth,
                             const Unk_Float2* size, const Unk_Float2* arg21, const Unk_Float2* arg22, f32 arg23,
                             f32 tonemap, bool dynamic, f32 arg26, f32 arg27, s32 arg28, const Unk_Float2* arg29,
                             s32 channel, const Unk_Float2* arg31, const Unk_Float2* arg32, f32 arg33, f32 arg34,
                             f32 arg35, f32 arg36, f32 arg37, f32 arg38, f32 arg39, f32 arg40,
                             const Unk_Float4* arg41, const Unk_Float4* arg42, u32 flags) {
    s32 mode = (depth != nullptr && dynamic) ? channel : -1;
    s32 index;
    if (!dynamic) {
        index = 0;
    } else if (mode == -1) {
        index = 1;
    } else {
        index = mode + 2;
    }
    bool tonemapped = tonemap > 0.0f;
    s32 technique = field_30.field_7e64_table[tonemapped][index];
    field_30.field_0->vf29(technique);
    f32 scale = arg28 == 0 ? 1.0f : 2.0f;
    f32 offset = arg28 == 0 ? 0.0f : -1.0f;
    Unk_24e4c18[0].field_0[0].field_0 = scale * arg29->field_0[0].field_0;
    Unk_24e4c18[0].field_0[1].field_0 = scale * arg29->field_0[1].field_0;
    Unk_24e4c18[0].field_0[2].field_0 = offset * arg29->field_0[0].field_0;
    Unk_24e4c18[0].field_0[3].field_0 = offset * arg29->field_0[1].field_0;
    f32 jitterX = -(size->field_0[0].field_0 / size->field_0[1].field_0 * (arg29->field_0[0].field_0 * s0));
    f32 jitterY = -(arg29->field_0[1].field_0 * t0);
    Unk_24e4c18[1].field_0[0].field_0 = scale * jitterX;
    Unk_24e4c18[1].field_0[1].field_0 = scale * jitterY;
    Unk_24e4c18[1].field_0[2].field_0 = offset * jitterX;
    Unk_24e4c18[1].field_0[3].field_0 = offset * jitterY;
    Unk_24e4c18[2].field_0[0].field_0 = size->field_0[1].field_0 * arg36;
    Unk_24e4c18[2].field_0[1].field_0 = size->field_0[1].field_0 * arg37;
    Unk_24e4c18[2].field_0[2].field_0 = arg34;
    Unk_24e4c18[2].field_0[3].field_0 = arg23;
    Unk_24e4c18[3].field_0[0].field_0 = arg38;
    Unk_24e4c18[3].field_0[1].field_0 = arg39;
    Unk_24e4c18[3].field_0[2].field_0 = arg35;
    Unk_24e4c18[3].field_0[3].field_0 = 1.0f / arg23;
    Unk_24e4c18[4].field_0[0] = arg21->field_0[0];
    Unk_24e4c18[4].field_0[1] = arg21->field_0[1];
    Unk_24e4c18[4].field_0[2] = arg32->field_0[0];
    Unk_24e4c18[4].field_0[3] = arg32->field_0[1];
    Unk_24e4c18[5].field_0[0].field_0 = arg33;
    Unk_24e4c18[5].field_0[1].field_0 = 0.0f;
    Unk_24e4c18[5].field_0[2].field_0 = 0.001f;
    Unk_24e4c18[5].field_0[3].field_0 = 0.0f;
    Unk_24e4c18[6].field_0[0].field_0 = arg22->field_0[0].field_0 * 0.0f;
    Unk_24e4c18[6].field_0[1].field_0 = arg22->field_0[1].field_0 * 0.0f;
    Unk_24e4c18[6].field_0[2] = size->field_0[0];
    Unk_24e4c18[6].field_0[3] = size->field_0[1];
    Unk_24e4c18[7].field_0[0].field_0 = 10.0f;
    Unk_24e4c18[7].field_0[1].field_0 = 20.0f;
    Unk_24e4c18[7].field_0[2].field_0 = 4.0f;
    Unk_24e4c18[7].field_0[3].field_0 = 0.0f;
    field_30.field_0->vf22(field_30.field_d4, Unk_24e4c18, 8);
    Unk_Float4 value(arg31->field_0[0], arg31->field_0[1], 0.0f, 0.0f);
    field_30.field_0->vf20(field_30.field_c0, &value.field_0[0].field_0);
    value = Unk_Float4(arg26, arg27, arg40, 0.0f);
    field_30.field_0->vf20(field_30.field_a4, &value.field_0[0].field_0);
    Unk_24e4a18[0] = *arg41;
    Unk_24e4a18[1] = *arg42;
    Unk_24e4a18[2].field_0[0].field_0 = tonemap;
    Unk_24e4a18[2].field_0[1].field_0 = 0.0f;
    Unk_24e4a18[2].field_0[2].field_0 = 0.0f;
    Unk_24e4a18[2].field_0[3].field_0 = 0.0f;
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4a18, 3);
    field_30.field_0->vf26(field_30.field_10[0], texture0);
    field_30.field_0->vf26(field_30.field_10[1], texture1);
    field_30.field_0->vf26(field_30.field_10[2], texture2);
    if (depth != nullptr) {
        field_30.field_0->vf26(field_30.field_10[3], depth);
    }
    s32 filter0 = texture0->vf16();
    s32 filter1 = texture1->vf16();
    s32 filter2 = texture2->vf16();
    s32 filter3 = depth != nullptr ? depth->vf16() : -1;
    texture1->vf15(dynamic ? 4 : 5);
    texture0->vf15(5);
    texture2->vf15(5);
    if (depth != nullptr) {
        depth->vf15(5);
    }
    s32 result = Unk_472250(x, y, width, height, u0, v0, s0, t0, u1, v1, s1, t1, u2, v2, s2, t2, flags);
    texture0->vf15(filter0);
    texture1->vf15(filter1);
    texture2->vf15(filter2);
    if (depth != nullptr) {
        depth->vf15(filter3);
    }
    return result;
}

// 0x7100490570: `a` and `b` drawn into `target` with
// tech_ColorModulateByChannel_<channel> (1: R)
s32 CTextureUtil::Unk_490570(CRenderTexture* target, CRenderTexture* a, CRenderTexture* b, s32 channel, bool clear) {
    if (field_20 == nullptr) {
        return -1;
    }
    if (clear) {
        Unk_471410();
    }
    f32 ua;
    f32 va;
    Unk_GetCoords(a, &ua, &va);
    f32 ub;
    f32 vb;
    Unk_GetCoords(b, &ub, &vb);
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0) {
        return result;
    }
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    Unk_GPUTexture* textureA = Unk_GetTexture(a);
    Unk_GPUTexture* textureB = Unk_GetTexture(b);
    field_30.field_0->vf29((&field_30.field_22784)[channel]);
    field_30.field_0->vf26(field_30.field_10[0], textureA);
    field_30.field_0->vf26(field_30.field_10[1], textureB);
    result = Unk_471f60(0.0f, 0.0f, width, height, 0.0f, 0.0f, ua, va, 0.0f, 0.0f, ub, vb, 0);
    return result < 0 ? result : 0;
}

// 0x7100481bc0
// NON_MATCHING: register allocation: the original spills all eight floating-
// point parameters and keeps the eight values it reads of the two textures in
// d8 to d15; here the source's field_94 is spilled and the eighth parameter
// kept in d12 (and the loads and spills come in another order)
s32 CTextureUtil::Unk_481bc0(f32 arg0, f32 ratio, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7,
                             f32 arg8, f32 arg9, f32 arg10, f32 arg11, f32 arg12, f32 arg13, CRenderTexture* source,
                             CRenderTexture* target, u32 arg14, bool arg15, bool arg16, bool arg17, s32 arg18,
                             s32 arg19) {
    f32 sourceWidth = static_cast<f32>(static_cast<u32>(source->field_54));
    f32 sourceHeight = static_cast<f32>(static_cast<u32>(source->field_58));
    f32 u1 = source->field_88 * sourceWidth + source->field_90;
    f32 v1 = source->field_8c * sourceHeight + source->field_94;
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0) {
        return result;
    }
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    Unk_GPUTexture* texture = Unk_GetTexture(source);
    if (ratio <= 0.0f) {
        ratio = sourceWidth / sourceHeight;
    }
    result = Unk_478890(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, arg0, ratio, arg2, arg3, arg4, arg5, arg6,
                        arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, texture, arg18,
                        arg19);
    return result < 0 ? result : 0;
}

// 0x710048b810
// NON_MATCHING: the order of four argument copies for Unk_411df0 (scaleX's
// mov v4 before the integer arguments in the original). Tried: the
// parameters' positions, local types and orders, the selects' forms.
s32 CTextureUtil::Unk_48b810(f32 scaleX, f32 scaleY, CRenderTexture* source, CRenderTexture* target,
                             const Unk_Float2* arg2, const Unk_Float2* arg3, s32 arg4, s32 index, bool background,
                             bool clear, bool arg8, s32 arg9) {
    if (clear) {
        Unk_471410();
    }
    u32 levelWidth = source->field_80->field_8;
    u32 levelHeight = source->field_80->field_c;
    f32 u1;
    f32 v1;
    Unk_GetCoords(source, &u1, &v1);
    f32 sourceWidth = static_cast<f32>(static_cast<u32>(source->field_54));
    f32 sourceHeight = static_cast<f32>(static_cast<u32>(source->field_58));
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    if (scaleX > 0.0f) {
        width = sourceWidth * scaleX;
    }
    if (scaleY > 0.0f) {
        height = sourceHeight * scaleY;
    }
    Unk_Float4 values[25];
    s32 count = Unk_411df0(levelWidth, levelHeight, values, 5, arg8, arg9, sourceWidth,
                           sourceHeight, width, height, scaleX, scaleY, 0.0f);
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0) {
        return result;
    }
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    result = DrawRectGPU_DepthOfFieldLayerMask(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, background, arg8, count,
                                               values, arg2, arg3, Unk_GetTexture(source), arg4, index, 0);
    return result < 0 ? result : 0;
}

// 0x710048e710
// NON_MATCHING: register allocation and spill slots (the original spills y
// and width as a pair and height alone, and keeps the sum and the aspect
// ratio in s15/s12), with the corner terms' order of 0x710048eb30.
s32 CTextureUtil::Unk_48e710(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 arg8, f32 arg9,
                             f32 arg10, f32 arg11, f32 arg12, f32 arg13, f32 arg14, Unk_GPUTexture* texture,
                             const Unk_Float2* center, const f32* color, u32 flags) {
    Unk_Float2 position = *center;
    if (field_20->field_58) {
        position.field_0[1].field_0 = 1.0f - position.field_0[1].field_0;
    }
    f32 centerX = position.field_0[0].field_0;
    f32 centerY = position.field_0[1].field_0;
    f32 sum = centerX + centerY + 0.0f;
    f32 aspect = width / height;
    s32 technique = field_30.field_7a2c;
    if (technique == 0) {
        technique = field_30.field_7a28;
    }
    field_30.field_0->vf29(technique);
    field_30.field_0->vf26(field_30.field_10[0], texture);
    field_30.field_0->vf26(field_30.field_10[1], Unk_Texture29ab8(0));
    Unk_Float4 value(arg11, arg10, arg9, arg8);
    field_30.field_0->vf20(field_30.field_a4, reinterpret_cast<const f32*>(&value));
    value = Unk_Float4(color[0] * arg9, color[1] * arg9, color[2] * arg9, arg9 * 0.0f);
    field_30.field_0->vf22(field_30.field_d0, &value, 1);
    value = Unk_Float4(256.0f, arg12, sum, 0.0f);
    field_30.field_0->vf20(field_30.field_f8, reinterpret_cast<const f32*>(&value));
    f32 tangent = tanf(arg13 * 0.5f);
    f32 scale = arg14 * 0.125f;
    f32 top = scale * tangent;
    f32 bottom = -(scale * tangent);
    f32 left = aspect * bottom;
    f32 right = aspect * top;
    f32 sizeX = right - left;
    f32 sizeY = top - bottom;
    f32 originX = left - sizeX * 0.0f;
    f32 originY = bottom - sizeY * 0.0f;
    return Unk_472250(x, y, width, height, u0, v0, u1, v1, 0.0f, 0.0f, aspect * 4.0f, 4.0f,
                      (0.0f - centerX + 0.5f) * sizeX + originX, (0.0f - centerY + 0.5f) * sizeY + originY,
                      (1.0f - centerX + 0.5f) * sizeX + originX, (1.0f - centerY + 0.5f) * sizeY + originY, flags);
}

// whether a format's channels are 32-bit floats (inline; as GPURenderGlare.cpp's)
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
// whether a format is a fixed-point one (inline)
static inline bool Unk_IsFixedFormat(s32 format) {
    bool f32 = Unk_IsFloat32Format(format);
    bool f16 = Unk_IsFloat16Format(format);
    if (f32) {
        return false;
    }
    return !f16 && format != 26;
}

// 0x710048ef10
// NON_MATCHING: the five offsets are copied to Unk_24e4c18 in 64-bit halves
// read back from the stack in the original; here the zero halves are
// forwarded (stored as zeros directly) and the loads come in another order.
// Tried: memmove/memcpy, per element and whole. The technique's choice
// matches (two blocks, see Unk_IsFixedFormat).
s32 CTextureUtil::Unk_48ef10(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 arg8, f32 arg9,
                             Unk_GPUTexture* texture, const f32* scaleOffset, const void* arg12, u32 flags) {
    bool fixed = Unk_IsFixedFormat(texture->field_44);
    s32 set = arg12 != nullptr;
    if (!fixed) {
        field_30.field_0->vf29((&field_30.field_2275c)[set]);
    } else {
        field_30.field_0->vf29((&field_30.field_22754)[set]);
    }
    field_30.field_0->vf26(field_30.field_10[0], texture);
    s32 filter = texture->vf16();
    texture->vf15(4);
    f32 scaleX = scaleOffset[0];
    f32 scaleY = scaleOffset[1];
    f32 offset = arg9 + 0.5f;
    f32 near = 0.0f - offset;
    f32 far = 1.0f - offset;
    Unk_Float4 offsets[5];
    offsets[0] = Unk_Float4(scaleX * 0.0f, scaleY * 0.0f, 0.0f, 0.0f);
    offsets[1] = Unk_Float4(near * scaleX, near * scaleY, 0.0f, 0.0f);
    offsets[2] = Unk_Float4(far * scaleX, near * scaleY, 0.0f, 0.0f);
    offsets[3] = Unk_Float4(near * scaleX, far * scaleY, 0.0f, 0.0f);
    offsets[4] = Unk_Float4(far * scaleX, far * scaleY, 0.0f, 0.0f);
    for (s32 i = 0; i < 5; i++) {
        Unk_24e4c18[i] = offsets[i];
    }
    field_30.field_0->vf22(field_30.field_c4, Unk_24e4c18, 5);
    field_30.field_0->vf22(field_30.field_c8, Unk_24e4c18, 0);
    Unk_24e4a18[0] = Unk_Float4(reinterpret_cast<const Unk_Float*>(scaleOffset)[0],
                                          reinterpret_cast<const Unk_Float*>(scaleOffset)[1], arg8, 0.0f);
    s32 count = 1;
    if (arg12 != nullptr) {
        const Unk_Float2* value = static_cast<const Unk_Float2*>(arg12);
        Unk_24e4a18[1] = Unk_Float4(value->field_0[0], value->field_0[1], 0.0f, 0.0f);
        count = 2;
    }
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4a18, count);
    s32 result = Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
    texture->vf15(filter);
    return result;
}

// 0x710048eb30
// NON_MATCHING: scheduling at the end: the original computes 1 - centerX and
// 1 - centerY before 0 - centerX and 0 - centerY. Tried: the corners and
// their offsets in locals in every order, before and after the rectangle.
s32 CTextureUtil::Unk_48eb30(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 arg8, f32 arg9,
                             f32 arg10, f32 arg11, f32 arg12, Unk_GPUTexture* texture, const void* arg14,
                             const Unk_Float2* arg15, u32 flags) {
    Unk_Float2 center = *arg15;
    if (field_20->field_58) {
        center.field_0[1].field_0 = 1.0f - center.field_0[1].field_0;
    }
    f32 centerX = center.field_0[0].field_0;
    f32 centerY = center.field_0[1].field_0;
    field_30.field_0->vf29(field_30.field_7a30);
    field_30.field_0->vf26(field_30.field_10[0], texture);
    Unk_Texture29ab8(1)->vf15(15);
    field_30.field_0->vf26(field_30.field_10[1], Unk_Texture29ab8(1));
    field_30.field_0->vf26(field_30.field_10[2], Unk_Texture29ab8(0));
    Unk_24e4a18[0] = *static_cast<const Unk_Float4*>(arg14);
    Unk_24e4a18[1] = Unk_Float4(1.5f, 1.5f, 1.5f, 0.0f);
    Unk_24e4a18[2] = Unk_Float4(1.0f, 1.0f, 1.0f, 0.0f);
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4a18, 3);
    f32 value[4];
    value[0] = arg8;
    value[1] = arg9;
    value[2] = arg10;
    value[3] = 0.0f;
    field_30.field_0->vf20(field_30.field_a4, value);
    value[0] = 2.0f;
    value[1] = 4.0f;
    value[2] = 0.0f;
    value[3] = 1.0f;
    field_30.field_0->vf20(field_30.field_f8, value);
    f32 aspect = width / height;
    f32 tangent = tanf(arg12 * 0.5f);
    f32 scale = 3.14159265f / arg11;
    f32 top = scale * tangent;
    f32 bottom = -(scale * tangent);
    f32 left = aspect * bottom;
    f32 right = aspect * top;
    f32 sizeX = right - left;
    f32 sizeY = top - bottom;
    f32 originX = left - sizeX * 0.0f;
    f32 originY = bottom - sizeY * 0.0f;
    return Unk_471f60(x, y, width, height, u0, v0, u1, v1, (0.0f - centerX + 0.5f) * sizeX + originX,
                      (0.0f - centerY + 0.5f) * sizeY + originY, (1.0f - centerX + 0.5f) * sizeX + originX,
                      (1.0f - centerY + 0.5f) * sizeY + originY, flags);
}

// 0x7100481db0 (the source first: its position decides the registers)
s32 CTextureUtil::Unk_481db0(CRenderTexture* source, f32 arg0, f32 arg1, f32 arg2, f32 fov, f32 ratio,
                             CRenderTexture* target, const Unk_Float4* arg5, s32 index, u32 flags) {
    f32 sourceWidth = static_cast<f32>(static_cast<u32>(source->field_54));
    f32 sourceHeight = static_cast<f32>(static_cast<u32>(source->field_58));
    f32 u1 = source->field_88 * sourceWidth + source->field_90;
    f32 v1 = source->field_8c * sourceHeight + source->field_94;
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0) {
        return result;
    }
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    if (ratio <= 0.0f) {
        ratio = sourceWidth / sourceHeight;
    }
    Unk_Float4 rect(-ratio, -1.0f, ratio, 1.0f);
    Unk_Float4 projection(tanf(fov * 0.5f), arg0 * 0.5f, arg1, arg2);
    Unk_Float4 range[2] = {Unk_Float4(0.0f, 0.0f, 0.0f, -64512.0f),
                           Unk_Float4(64512.0f, 64512.0f, 64512.0f, 64512.0f)};
    bool same = source->field_54 == target->field_54 && source->field_58 == target->field_58;
    s32 filter = Unk_GetTexture(source)->vf16();
    Unk_GetTexture(source)->vf17(same);
    Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
    result = Unk_4773e0(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, arg5, &zero, range, &rect, true, &projection,
                        Unk_GetTexture(source), index, flags);
    Unk_GetTexture(source)->vf15(filter);
    return result < 0 ? result : 0;
}

// 0x710049ca70 (GPURenderTexture.cpp's; placeholder signature: here its result is tested)
s32 Unk_49ca70(void* self, void* arg1, u32 arg2);

// 0x710048f230
// NON_MATCHING: the original's frame has 0x20 bytes more below the size
// vector, passes 0 for 0x710048f470's arg13 (which that function doesn't read:
// in the original TU something kept it alive until dead-argument elimination
// ran), and keeps `this` and `target` in each other's registers.
s32 CTextureUtil::Unk_48f230(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, CRenderTexture* target,
                             CRenderTexture* source, CRenderTexture* temp, CRenderTexture* temp2,
                             const Unk_Float2* arg10, s32 arg11, s32 arg12, s32 arg13, bool arg14, void* arg15,
                             bool clear) {
    if (field_20 == nullptr) {
        return -1;
    }
    if (clear) {
        Unk_471410();
    }
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    f32 u1;
    f32 v1;
    Unk_GetCoords(source, &u1, &v1);
    s32 a = arg11 < 0x70 ? arg11 : 0x70;
    s32 b = arg12 < 0x14 ? arg12 : 0x14;
    s32 c = arg13 < 100 ? arg13 : 100;
    a = a < 0 ? 0 : a;
    b = b < 0 ? 0 : b;
    c = c < 0 ? 0 : c;
    Unk_Float4 size(1.0f / width, 1.0f / height, width, height);
    s32 result = Unk_49ca70(temp, nullptr, 0xffffffff);
    if (result < 0) {
        return result;
    }
    f32 amount = arg1 < 0.0f ? 0.0f : (arg1 > 0.5f ? 0.5f : arg1);
    result = Unk_48f470(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, amount, arg0, temp, source, &size, 0, 0, 0);
    if (result < 0) {
        return result;
    }
    result = Unk_48f620(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, temp2, temp, &size, a, b, c, 0);
    if (result < 0) {
        return result;
    }
    result = Unk_48f900(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, target, source, temp2, &size, arg10, 0);
    return result < 0 ? result : 0;
}

// 0x7100482010
// NON_MATCHING: can't match before 0x7100478e90 is defined in the TU: the
// original passes nothing for the argument the callee ignores (arg0, its
// arg8: dead-argument elimination). With a stand-in callee the rest is the
// original's but for the float registers (as 0x7100481bc0).
s32 CTextureUtil::Unk_482010(f32 arg0, f32 ratio, f32 arg2, f32 arg3, f32 arg4, CRenderTexture* source,
                             CRenderTexture* target, s32 arg5, void* arg6, void* arg7, void* arg8, void* arg9,
                             void* arg10, bool arg11, void* arg12, s32 arg13, s32 arg14) {
    f32 sourceWidth = static_cast<f32>(static_cast<u32>(source->field_54));
    f32 sourceHeight = static_cast<f32>(static_cast<u32>(source->field_58));
    f32 u1 = source->field_88 * sourceWidth + source->field_90;
    f32 v1 = source->field_8c * sourceHeight + source->field_94;
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0) {
        return result;
    }
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    Unk_GPUTexture* texture = Unk_GetTexture(source);
    if (ratio <= 0.0f) {
        ratio = sourceWidth / sourceHeight;
    }
    result = Unk_478e90(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, arg0, ratio, arg2, arg3, arg4, arg5, arg6,
                        arg7, arg8, arg9, arg10, arg11, texture, arg12, arg13, arg14);
    return result < 0 ? result : 0;
}

// 0x7100481540 (the sizes in locals, the source's first, the coordinates
// last: the order decides the registers)
s32 CTextureUtil::Unk_481540(CRenderTexture* source, CRenderTexture* target, bool arg2, bool arg3) {
    f32 sourceWidth = static_cast<f32>(static_cast<u32>(source->field_54));
    f32 sourceHeight = static_cast<f32>(static_cast<u32>(source->field_58));
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    u32 levelWidth = source->field_80->field_8;
    u32 levelHeight = source->field_80->field_c;
    f32 u1;
    f32 v1;
    Unk_GetCoords(source, &u1, &v1);
    Unk_Float4 weights[16];
    s32 count = Unk_411df0(levelWidth, levelHeight, weights, 4, true, 0, sourceWidth, sourceHeight, width, height,
                           0.0f, 0.0f, 0.0f);
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0)
        return result;
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    Unk_GPUTexture* texture = Unk_GetTexture(source);
    result = Unk_481340(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, arg2, arg3, count, weights, texture, 0);
    return result < 0 ? result : 0;
}

// 0x7100481180
s32 CTextureUtil::Unk_481180(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 arg8,
                             f32 arg9, f32 arg10, Unk_GPUTexture* texture, bool arg12, u32 flags) {
    field_30.field_0->vf29(field_30.field_299b0);
    f32 inverse = 1.0f / arg8;
    Unk_24e4c18[0] = Unk_Float4(1.0f, 1.0f, 1.0f, 0.25f);
    Unk_24e4c18[1] = Unk_Float4(arg8, 2.3255813f, powf(10.0f, arg9 + 1.0f), inverse);
    Unk_24e4c18[2] = Unk_Float4(10.0f, arg8, arg9, arg8);
    if (arg12) {
        Unk_24e4c18[3] = Unk_Float4(1.0f / 3.0f, 1.0f / 3.0f, 1.0f / 3.0f, 1.0f / 3.0f);
        Unk_24e4c18[4] = Unk_Float4(0.0f, 1.0f / 3.0f, 2.0f / 3.0f, 0.0f);
    } else {
        Unk_24e4c18[3] = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
        Unk_24e4c18[4] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4c18, 5);
    f32 value[4];
    value[0] = width;
    value[1] = height / arg10;
    value[2] = x;
    value[3] = y;
    if (!field_20->field_58) {
        value[1] = -value[1];
        value[3] = height - y;
    }
    field_30.field_0->vf20(field_30.field_a4, value);
    if (texture != nullptr)
        field_30.field_0->vf26(field_30.field_8, texture);
    return Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
}

// a light ghost's vertex (DrawLightGhost's, four per ghost)
struct Unk_GhostVertex {
    Unk_Float2 field_0;   // the position
    Unk_Float2 field_8;   // the corner (-1 or 1 each)
    Unk_Float2 field_10;
    Unk_Float4 field_18;  // the colour at the corner
    Unk_Float4 field_28;
    Unk_Float4 field_38;
    Unk_Float4 field_48;
};
PKMN_OFFSET_ASSERT(Unk_GhostVertex, field_18, 0x18);
PKMN_SIZE_ASSERT(Unk_GhostVertex, 0x58);

// `x` clamped to `low` to `high` (inline)
static inline f32 Unk_Clamp(f32 x, f32 low, f32 high) {
    if (x < low) {
        return low;
    }
    return x > high ? high : x;
}

// the sign of `x`: -1, 0 or 1 (inline)
static inline f32 Unk_Sign(f32 x) {
    return x > 0.0f ? 1.0f : (x < 0.0f ? -1.0f : 0.0f);
}

// `v` made unit length (inline; those of length 0 and 1 as they are)
static inline void Unk_NormalizeGhost(Unk_Float2* v) {
    f32 squared = v->field_0[0].field_0 * v->field_0[0].field_0 + v->field_0[1].field_0 * v->field_0[1].field_0;
    if (squared != 0.0f && squared != 1.0f) {
        f32 scale = 1.0f / sqrtf(squared);
        v->field_0[0].field_0 *= scale;
        v->field_0[1].field_0 *= scale;
    }
}

// a vector's length (inline; 0 and 1 as they are)
static inline f32 Unk_LengthGhost(f32 x, f32 y) {
    f32 length = x * x + y * y;
    if (length != 0.0f && length != 1.0f) {
        length = sqrtf(length);
    }
    return length;
}

// a corner of a ghost's quad stretched by `along` and `across` the direction
// (`dx`, `dy`) and moved to (`x`, `y`) (inline)
static inline Unk_Float2 Unk_Stretch(const Unk_Float2& corner, f32 dx, f32 dy, f32 along, f32 across) {
    f32 px = corner.field_0[0].field_0;
    f32 py = corner.field_0[1].field_0;
    f32 u = across * (py * dy + px * dx);
    f32 v = along * (py * dx - px * dy);
    return Unk_Float2(dx * u - dy * v, dy * u + dx * v);
}

// (`x`, `y`) turned by `angle` (inline)
static inline Unk_Float2 Unk_Rotate(f32 x, f32 y, f32 angle) {
    f32 c = cosf(angle);
    f32 s = sinf(angle);
    return Unk_Float2(c * x - s * y, s * x + c * y);
}

// 0x7100482fd0's (below)
static inline Unk_Float Unk_Abs(f32 x);

// 0x7100489db0: a quad per ghost of `ghosts` (GPUGlareDef.cpp's lines, up to
// field_29c00 of them) along the line from `position` through `center`,
// with tech_LightGhost_N<set> (`set` 5 to 8)
// NON_MATCHING: a draft: the blocks, calls and arithmetic are the original's,
// but registers, spill slots and the scheduling inside the loop differ (and
// the frame is 0x10 bytes larger).
s32 CTextureUtil::DrawLightGhost(f32 width, f32 height, f32 arg2, f32 arg3, f32 fov, f32 arg5, f32 arg6, f32 arg7,
                                 Unk_GPUTexture* texture, s32 count, const void* ghosts, const Unk_Float2* position,
                                 const Unk_Float4* color, const Unk_Float2* center, s32 set, f32 arg13, f32 angle,
                                 f32 arg15, f32 arg16, f32 arg17, f32 arg18, s32 index, u32 flags) {
    u32 n = static_cast<u32>(field_29c00) < static_cast<u32>(count) ? field_29c00 : count;
    f32 tangent = tanf(Unk_Clamp(fov, 0.001f, 1.0f) * 1.570796f);
    f32 aspect = width / height;
    Unk_Float2 delta(aspect * (position->field_0[0].field_0 - center->field_0[0].field_0),
                     position->field_0[1].field_0 - center->field_0[1].field_0);
    Unk_GhostVertex* vertices =
        static_cast<Unk_GhostVertex*>(static_cast<IGPUBuffer*>(field_29bc8[5])->Map(6, 0, n * sizeof(Unk_GhostVertex) * 4));
    const Unk_4a2be0_Line* lines = static_cast<const Unk_4a2be0_Line*>(ghosts);
    for (s32 i = 0; i < static_cast<s32>(n); i++) {
        const Unk_4a2be0_Line* ghost = &lines[i];
        const Unk_SamplePoint& sample = Unk_24e2d50[ghost->field_0 % 8];
        Unk_Float2 dir = delta;
        Unk_NormalizeGhost(&dir);
        Unk_Float2 d(dir.field_0[0].field_0 + sample.field_0 * arg6, dir.field_0[1].field_0 + sample.field_4 * arg6);
        Unk_NormalizeGhost(&d);
        f32 f10 = ghost->field_10;
        f32 l = logf(arg13);
        f32 e = exp2f(sinf(f10 * 29.0f + f10 * l * 2.0f) * Unk_Abs(f10).field_0);
        Unk_Float2 from = *center;
        Unk_Float2 to = *position;
        f32 x = aspect * (to.field_0[0].field_0 - from.field_0[0].field_0);
        f32 y = to.field_0[1].field_0 - from.field_0[1].field_0;
        f32 distance = Unk_Sqrt(x * x + y * y);
        if (distance > 5.9604645e-08f) {
            f32 inverse = 1.0f / distance;
            x *= inverse;
            y *= inverse;
        }
        Unk_Float2 toward(x + sample.field_0 * arg6, y + sample.field_4 * arg6);
        Unk_NormalizeGhost(&toward);
        f32 f8 = ghost->field_8;
        f32 t = 1.0f - f8;
        if (!(Unk_Abs(t).field_0 < 0.001f)) {
            f32 knee = powf(f8, 1.0f / t);
            if (distance - 0.05f > knee) {
                distance = knee + powf(distance - 0.05f, f8) - powf(knee, f8) + 0.05f;
            }
        }
        f32 cx = (from.field_0[0].field_0 +
                  e * (distance * (toward.field_0[0].field_0 * ghost->field_4 * arg3))) * 2.0f - 1.0f;
        f32 cy = (from.field_0[1].field_0 +
                  e * (distance * (toward.field_0[1].field_0 * ghost->field_4 * arg3))) * 2.0f - 1.0f;
        f32 q = arg16 / arg17;
        f32 level = Unk_Clamp(q + (arg16 - q) * ghost->field_14, 0.0f, q);
        f32 c = Unk_Abs(ghost->field_c).field_0;
        f32 falloff = powf(1.0f / (arg7 * 2.0f), 1.0f - c / (c + 1.0f));
        f32 brightness = e * arg2 * falloff;
        f32 b = brightness * (q * ghost->field_50);
        f32 size = brightness * (Unk_Abs(ghost->field_c).field_0 * level);
        f32 spread = powf(arg7 * 2.0f, ghost->field_58 * -0.25f) * (ghost->field_4c * arg5);
        f32 r = Unk_LengthGhost(cx, cy);
        f32 ox = from.field_0[0].field_0 * 2.0f - 1.0f;
        f32 oy = from.field_0[1].field_0 * 2.0f - 1.0f;
        if (b < 0.0f) {
            f32 s = -b / spread;
            if (s > 0.0f) {
                s = s / (s + 1.0f) + 0.0f;
            }
            spread = -b / s;
        }
        f32 absB = Unk_Abs(b).field_0;
        f32 radius = r * ((b + spread) / spread);
        f32 red = color->field_0[0].field_0 * ghost->field_18.field_0[0].field_0;
        f32 green = color->field_0[1].field_0 * ghost->field_18.field_0[1].field_0;
        f32 blue = color->field_0[2].field_0 * ghost->field_18.field_0[2].field_0;
        f32 sign = Unk_Sign(ghost->field_c * ghost->field_4);
        f32 half = size * sign;
        u32 first = i * 4;
        Unk_Float2 c0 = Unk_Rotate(-half, -half, angle);
        Unk_Float2 c1 = Unk_Rotate(half, -half, angle);
        Unk_Float2 c2 = Unk_Rotate(-half, half, angle);
        Unk_Float2 c3 = Unk_Rotate(half, half, angle);
        f32 s4 = Unk_Sign(ghost->field_4);
        f32 offsetX = ox + d.field_0[0].field_0 * radius * s4;
        f32 offsetY = oy + d.field_0[1].field_0 * radius * s4;
        vertices[first + 0].field_8.field_0[0].field_0 = -1.0f;
        vertices[first + 0].field_8.field_0[1].field_0 = 1.0f;
        vertices[first + 0].field_10.field_0[0].field_0 = (cx + c0.field_0[0].field_0 - offsetX) / absB;
        vertices[first + 0].field_10.field_0[1].field_0 = (cy + c0.field_0[1].field_0 - offsetY) / absB;
        vertices[first + 1].field_8.field_0[0].field_0 = 1.0f;
        vertices[first + 1].field_8.field_0[1].field_0 = 1.0f;
        vertices[first + 1].field_10.field_0[0].field_0 = (cx + c1.field_0[0].field_0 - offsetX) / absB;
        vertices[first + 1].field_10.field_0[1].field_0 = (cy + c1.field_0[1].field_0 - offsetY) / absB;
        vertices[first + 2].field_8.field_0[0].field_0 = -1.0f;
        vertices[first + 2].field_8.field_0[1].field_0 = -1.0f;
        vertices[first + 2].field_10.field_0[0].field_0 = (cx + c2.field_0[0].field_0 - offsetX) / absB;
        vertices[first + 2].field_10.field_0[1].field_0 = (cy + c2.field_0[1].field_0 - offsetY) / absB;
        vertices[first + 3].field_8.field_0[0].field_0 = 1.0f;
        vertices[first + 3].field_8.field_0[1].field_0 = -1.0f;
        vertices[first + 3].field_10.field_0[0].field_0 = (cx + c3.field_0[0].field_0 - offsetX) / absB;
        vertices[first + 3].field_10.field_0[1].field_0 = (cy + c3.field_0[1].field_0 - offsetY) / absB;
        f32 root = powf(arg7 * 2.0f, 0.5f);
        f32 r2 = Unk_LengthGhost(cx, cy);
        f32 ee = 1.0f / (e * e);
        red = ee * red;
        green = ee * green;
        blue = ee * blue;
        f32 f2 = r2 * root;
        f32 along = 1.0f;
        if (ghost->field_5c.field_0[0].field_0 > 0.0f) {
            f32 m = fmaxf(ghost->field_5c.field_0[0].field_0, 0.01f);
            f32 k = f2 * (4.4934096f / fmaxf(ghost->field_64.field_0[0].field_0, 0.0001f));
            f32 sinc = 1.0f;
            if (k != 0.0f) {
                sinc = sinf(k) / k;
            }
            along = m + (1.0f - m) * (sinc * 0.821535f + 0.178465f);
        }
        f32 across = 1.0f;
        if (ghost->field_5c.field_0[1].field_0 > 0.0f) {
            f32 m = fmaxf(ghost->field_5c.field_0[1].field_0, 0.01f);
            f32 k = f2 * (3.14159274f / fmaxf(ghost->field_64.field_0[1].field_0, 0.0001f));
            across = m + (1.0f - m) * (cosf(k) * 0.5f + 0.5f);
        }
        f32 dx = 1.0f;
        f32 dy = 0.0f;
        if (r2 > 0.001f) {
            dx = -cx / r2;
            dy = -cy / r2;
        }
        f32 inv = 1.0f / (falloff * falloff);
        Unk_Float2 p0 = Unk_Stretch(c0, dx, dy, along, across);
        Unk_Float2 p1 = Unk_Stretch(c1, dx, dy, along, across);
        Unk_Float2 p2 = Unk_Stretch(c2, dx, dy, along, across);
        Unk_Float2 p3 = Unk_Stretch(c3, dx, dy, along, across);
        f32 normal = 1.0f / fmaxf(along * across, 1e-05f);
        red = inv * red * normal;
        green = inv * green * normal;
        blue = inv * blue * normal;
        vertices[first + 0].field_0 = Unk_Float2((cx + p0.field_0[0].field_0) / aspect, cy + p0.field_0[1].field_0);
        vertices[first + 1].field_0 = Unk_Float2((cx + p1.field_0[0].field_0) / aspect, cy + p1.field_0[1].field_0);
        vertices[first + 2].field_0 = Unk_Float2((cx + p2.field_0[0].field_0) / aspect, cy + p2.field_0[1].field_0);
        vertices[first + 3].field_0 = Unk_Float2((cx + p3.field_0[0].field_0) / aspect, cy + p3.field_0[1].field_0);
        f32 fade = Unk_Saturate(1.0f - 1.0f / tangent * (1.0f - (1.0f + (arg15 - 1.0f) * ghost->field_14)));
        f32 p = powf(along < across ? along : across, 0.85f);
        f32 edge = 5.0f / (size * height * p * 0.5f);
        f32 inner = 1.0f / Unk_Clamp(ghost->field_48, Unk_Saturate(edge * 2.0f), 1.0f);
        f32 extent = absB * height * p;
        f32 soft = fminf(Unk_Saturate(5.0f / extent), 1.0f);
        f32 mix = Unk_Saturate(ghost->field_54);
        f32 scale = 1.0f + ghost->field_14 * (powf(arg17, 0.5f) - 1.0f);
        vertices[first + 0].field_18 =
            Unk_Float4(red * ((ghost->field_28.field_0[0].field_0 - 0.5f) * scale + 0.5f),
                       green * ((ghost->field_28.field_0[1].field_0 - 0.5f) * scale + 0.5f),
                       blue * ((ghost->field_28.field_0[2].field_0 - 0.5f) * scale + 0.5f), 1.0f - edge);
        vertices[first + 1].field_18 = vertices[first + 0].field_18;
        vertices[first + 2].field_18 = vertices[first + 0].field_18;
        vertices[first + 3].field_18 = vertices[first + 0].field_18;
        vertices[first + 0].field_28 =
            Unk_Float4(red * (scale * (ghost->field_38.field_0[0].field_0 - 0.5f) + 0.5f),
                       green * (scale * (ghost->field_38.field_0[1].field_0 - 0.5f) + 0.5f),
                       blue * (scale * (ghost->field_38.field_0[2].field_0 - 0.5f) + 0.5f), inner);
        vertices[first + 1].field_28 = vertices[first + 0].field_28;
        vertices[first + 2].field_28 = vertices[first + 0].field_28;
        vertices[first + 3].field_28 = vertices[first + 0].field_28;
        vertices[first + 0].field_38 = Unk_Float4(fade, 0.0f, 1.0f, 0.0f);
        vertices[first + 1].field_38 = vertices[first + 0].field_38;
        vertices[first + 2].field_38 = vertices[first + 0].field_38;
        vertices[first + 3].field_38 = vertices[first + 0].field_38;
        vertices[first + 0].field_48 = Unk_Float4(2.0f / soft, 1.0f - mix, mix, 10.0f / extent + 1.0f);
        vertices[first + 1].field_48 = vertices[first + 0].field_48;
        vertices[first + 2].field_48 = vertices[first + 0].field_48;
        vertices[first + 3].field_48 = vertices[first + 0].field_48;
    }
    static_cast<IGPUBuffer*>(field_29bc8[5])->Unmap();
    s32 technique = (&field_30.field_7a34)[set][index];
    if (technique == 0) {
        return -4;
    }
    field_30.field_0->vf29(technique);
    f32 value[4] = {0.001f, 0.0f, 0.0f, 0.0f};
    field_30.field_0->vf20(field_30.field_a4, value);
    s32 saved;
    if (texture != nullptr) {
        saved = texture->vf19();
        texture->vf17(1);
        field_30.field_0->vf26(field_30.field_10[0], texture);
    } else {
        saved = 0x7fffffff;
    }
    field_20->vf44(2);
    field_20->vf45(1);
    if ((flags & 0x40000) == 0) {
        field_20->vf41(-1, 1);
    }
    if ((flags & 0x20000) == 0) {
        u32 passes;
        field_30.field_0->vf33(&passes, flags & 0xffff);
        field_30.field_0->vf35(0);
    }
    field_30.Unk_46d5e0();
    field_30.field_0->vf42(field_30.field_299b8[11], static_cast<IGPUBuffer*>(field_29bc8[5]), 0, 0, 0, 1);
    field_20->vf9(field_29bc8[6], 0);
    field_30.field_0->SetupGraphicsPipelineState();
    s32 result = field_20->vf58(4, n * 6, 0, 0, -1);
    if ((flags & 0x20000) == 0) {
        field_30.field_0->vf36();
        result = field_30.field_0->vf34();
    }
    field_20->vf44(0);
    field_20->vf45(0);
    if (texture != nullptr) {
        texture->vf17(saved);
    }
    return result;
}

// 0x7100481340
s32 CTextureUtil::Unk_481340(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, bool arg8,
                             bool arg9, s32 count, const Unk_Float4* weights, Unk_GPUTexture* texture, u32 flags) {
    s32 technique;
    if (arg8)
        technique = field_30.field_22850[count - 1];
    else if (!arg9)
        technique = field_30.field_22890[count - 1];
    else
        technique = field_30.field_228d0[count - 1];
    field_30.field_0->vf29(technique);
    Unk_4738e0(count, weights, 0, 8);
    if (arg9) {
        Unk_24e4c18[0] = Unk_Float4(1.0f / 3000.0f, 1.0f, 0.01f, 0.0f);
        field_30.field_0->vf22(field_30.field_d0, Unk_24e4c18, 1);
    }
    if (texture != nullptr) {
        field_30.field_0->vf26(field_30.field_8, texture);
        s32 filter = texture->vf16();
        texture->vf17(1);
        s32 result = Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
        texture->vf15(filter);
        return result;
    }
    return Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
}

// 0x710048b540
s32 CTextureUtil::Unk_48b540(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1,
                             Unk_GPUTexture* texture, bool arg9, u32 flags) {
    s32 type = FXDCT_GetDepthCastTypeFromDepthFormat(texture->field_44);
    s32 technique = (&field_30.field_1b334)[type];
    if (technique == 0)
        return -4;
    field_30.field_0->vf29(technique);
    Unk_Float4 value(arg9 ? -1.0f : 1.0f, arg9 ? 1.0f : 0.0f, 0.0f, 0.0f);
    field_30.field_0->vf20(field_30.field_c0, reinterpret_cast<const f32*>(&value));
    field_30.field_0->vf26(field_30.field_8, texture);
    return Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
}

// 0x710048ba10
s32 CTextureUtil::Unk_48ba10(CRenderTexture* source, CRenderTexture* target, const Unk_Float2* arg2, s32 index,
                             bool clear) {
    if (clear) {
        Unk_471410();
    }
    f32 u1;
    f32 v1;
    Unk_GetCoords(source, &u1, &v1);
    u32 targetWidth = target->field_54;
    u32 targetHeight = target->field_58;
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0)
        return result;
    f32 height = static_cast<f32>(targetHeight);
    f32 width = static_cast<f32>(targetWidth);
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    Unk_GPUTexture* texture = Unk_GetTexture(source);
    field_30.field_0->vf29((&field_30.field_1a6bc)[index]);
    Unk_Float4 value(arg2->field_0[0], arg2->field_0[1], 0.0f, 0.0f);
    field_30.field_0->vf22(field_30.field_b4, &value, 1);
    if (texture != nullptr) {
        field_30.field_0->vf26(field_30.field_8, texture);
    }
    result = Unk_471c50(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, 0);
    return result < 0 ? result : 0;
}

// 0x710048bbc0: field_7db0's technique `mode` (0 to 3: one rectangle of
// texture coordinates, the offset ones, the clip-space ones, both) from
// `texture` (and `texture2`), with channel mask `channel` and the range
// [arg23 or arg19, arg24 or 0.999 * arg20] (log2 scaled)
// NON_MATCHING: register allocation (same size): the clip-space cases (2
// and 3) number their temporaries differently and store the arguments in
// another order. Tried: the flips as ifs and selects in both orders, the
// corners declared in other orders.
s32 CTextureUtil::Unk_48bbc0(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, s32 channel,
                             s32 mode, const Unk_Float2* arg10, const Unk_Float2* size, Unk_GPUTexture* texture,
                             const Unk_Float2* offset, Unk_GPUTexture* texture2, f32 s0, f32 t0, f32 s1, f32 t1,
                             f32 arg19, f32 arg20, const MATRIXT44* arg21, const MATRIXT44* arg22, f32 arg23,
                             f32 arg24, u32 flags) {
    if (arg23 <= 0.0f)
        arg23 = arg19;
    if (arg24 <= 0.0f)
        arg24 = arg20 * 0.999f;
    s32 technique = (&field_30.field_7db0)[mode];
    if (technique == 0)
        return -4;
    bool inverse = mode == 2 || mode == 3;
    field_30.field_0->vf29(technique);
    Unk_Float4 value(arg19, arg20, width / size->field_0[0].field_0, -height / size->field_0[1].field_0);
    field_30.field_0->vf20(field_30.field_a4, reinterpret_cast<const f32*>(&value));
    Unk_Float4 value2(arg10->field_0[0], arg10->field_0[1], 0.0f, 0.0f);
    field_30.field_0->vf20(field_30.field_c0, reinterpret_cast<const f32*>(&value2));
    MATRIXT44 matrices[2];
    matrices[0] = *arg22;
    if (inverse) {
        MATRIXT44 m;
        Unk_4155f0(&m, arg21);
        matrices[1] = m;
    }
    field_30.field_0->vf25(field_30.field_114, matrices, 2);
    f32 a = 0.0f;
    f32 b = 0.0f;
    f32 g = 0.0f;
    f32 r = 0.0f;
    switch (channel) {
    case 0:
        r = 1.0f;
        break;
    case 1:
        g = 1.0f;
        break;
    case 2:
        b = 1.0f;
        break;
    case 3:
        a = 1.0f;
        break;
    case 4:
        r = 0.99609375f;
        g = 0.0038909912f;
        b = 1.5199184e-05f;
        break;
    case 5:
        r = 0.0038909912f;
        g = 1.5199184e-05f;
        a = 0.99609375f;
        break;
    case 6:
        g = 1.5199184e-05f;
        b = 0.0038909912f;
        a = 0.99609375f;
        break;
    }
    Unk_24e4a18[0] = Unk_Float4(r, g, b, a);
    Unk_24e4a18[1].field_0[0].field_0 = arg23;
    Unk_24e4a18[1].field_0[1].field_0 = arg24;
    Unk_24e4a18[1].field_0[2].field_0 = 1.0f / (logf(arg24 + 1.0f) / 0.693147182f);
    Unk_24e4a18[1].field_0[3].field_0 = 0.0f;
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4a18, 2);
    s32 filter = texture->vf16();
    bool same = static_cast<f32>(texture->field_4c) == width && static_cast<f32>(texture->field_50) == height;
    texture->vf15(same && static_cast<u32>(mode) < 4 ? 5 : 4);
    field_30.field_0->vf26(field_30.field_10[0], texture);
    s32 filter2;
    if (texture2 != nullptr) {
        filter2 = texture2->vf16();
        bool same2 = static_cast<f32>(texture2->field_4c) == width && static_cast<f32>(texture2->field_50) == height;
        texture2->vf15(same2 ? 5 : 4);
        field_30.field_0->vf26(field_30.field_10[1], texture2);
    } else {
        filter2 = -1;
    }
    s32 result;
    switch (mode) {
    case 0:
        result = Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
        break;
    case 1: {
        f32 oy = offset->field_0[1].field_0 * (field_20->field_58 ? -1.0f : 1.0f);
        f32 ox = offset->field_0[0].field_0;
        result = Unk_472250(x, y, width, height, u0, v0, u1, v1, ox + u0, v0, ox + u1, v1, u0, oy + v0, u1, oy + v1,
                            flags);
        break;
    }
    case 2: {
        f32 a = u0 * 2.0f - 1.0f;
        f32 b = v0 * 2.0f - 1.0f;
        f32 c = u1 * 2.0f - 1.0f;
        f32 d = v1 * 2.0f - 1.0f;
        f32 d2 = field_20->field_58 ? d : -d;
        f32 b2 = field_20->field_58 ? b : -b;
        result = Unk_471f60(x, y, width, height, u0, v0, u1, v1, a, b2, c, d2, flags);
        break;
    }
    case 3: {
        f32 a = u0 * 2.0f - 1.0f;
        f32 b = v0 * 2.0f - 1.0f;
        f32 c = u1 * 2.0f - 1.0f;
        f32 d = v1 * 2.0f - 1.0f;
        f32 sign = field_20->field_58 ? -1.0f : 1.0f;
        if (!field_20->field_58) {
            b = -b;
            d = -d;
        }
        f32 ox = offset->field_0[0].field_0;
        f32 oy = offset->field_0[1].field_0;
        f32 oys = oy * sign;
        result = Unk_472cd0(x, y, width, height, u0, v0, u1, v1, ox + u0, v0, ox + u1, v1, u0, oys + v0, u1,
                            oys + v1, a, b, c, d, a + ox * 2.0f, b, c + ox * 2.0f, d, a, b - oy * 2.0f, c,
                            d - oy * 2.0f, flags);
        break;
    }
    default:
        result = Unk_471f60(x, y, width, height, u0, v0, u1, v1, s0, t0, s1, t1, flags);
        break;
    }
    texture->vf15(filter);
    if (texture2 != nullptr)
        texture2->vf15(filter2);
    return result;
}
// 0x710048b6e0
s32 CTextureUtil::Unk_48b6e0(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1,
                             const Unk_Float2* factor, Unk_GPUTexture* texture, s32 channel, u32 flags) {
    s32 technique = (&field_30.field_1b350)[channel];
    if (technique == 0)
        return -4;
    field_30.field_0->vf29(technique);
    Unk_Float4 value;
    value.field_0[2] = factor->field_0[0];
    value.field_0[3] = factor->field_0[1];
    f32 a = 1.0f / value.field_0[2].field_0;
    f32 b = -value.field_0[3].field_0 / value.field_0[2].field_0;
    value.field_0[0].field_0 = a;
    value.field_0[1].field_0 = b;
    field_30.field_0->vf20(field_30.field_a8, reinterpret_cast<const f32*>(&value));
    field_30.field_0->vf26(field_30.field_8, texture);
    return Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
}

// 0x710048f470
s32 CTextureUtil::Unk_48f470(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 arg8,
                             f32 arg9, CRenderTexture* target, CRenderTexture* source, const Unk_Float4* arg12,
                             s32 arg13, s32 arg14, u32 flags) {
    Unk_GPUTexture* texture = Unk_GetTexture(source);
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0)
        return result;
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    field_30.field_0->vf29(field_30.field_22764);
    field_30.field_0->vf26(field_30.field_10[0], texture);
    s32 filter = texture->vf16();
    texture->vf15(5);
    Unk_24e4a18[0].field_0[0].field_0 = arg8;
    Unk_24e4a18[0].field_0[1].field_0 = arg9;
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4a18, 1);
    Unk_24e4c18[0] = *arg12;
    field_30.field_0->vf22(field_30.field_c4, Unk_24e4c18, 1);
    result = Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
    texture->vf15(filter);
    return result;
}

// 0x710048f620
// NON_MATCHING: the fallback technique's load reuses the table's base address
// here (CodeGenPrepare shares it); the original materialises the offset again
// (8 bytes more). The rest is the original's.
s32 CTextureUtil::Unk_48f620(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1,
                             CRenderTexture* target, CRenderTexture* source, const Unk_Float4* arg10, s32 arg11,
                             s32 arg12, s32 arg13, u32 flags) {
    Unk_GPUTexture* texture = Unk_GetTexture(source);
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0)
        return result;
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    s32 technique = field_30.field_2276c_table[arg12 > 0][arg13 > 0];
    if (technique == 0)
        technique = field_30.field_2276c;
    field_30.field_0->vf29(technique);
    field_30.field_0->vf26(field_30.field_10[0], texture);
    field_30.field_0->vf26(field_30.field_10[1], Unk_Texture29ad8(0));
    field_30.field_0->vf26(field_30.field_10[2], Unk_Texture29ad8(1));
    s32 filter = texture->vf16();
    s32 filter0 = Unk_Texture29ad8(0)->vf16();
    s32 filter1 = Unk_Texture29ad8(1)->vf16();
    texture->vf15(4);
    Unk_Texture29ad8(0)->vf15(4);
    Unk_Texture29ad8(1)->vf15(4);
    Unk_24e4a18[0].field_0[0].field_0 = static_cast<f32>(arg11);
    Unk_24e4a18[0].field_0[1].field_0 = static_cast<f32>(arg12);
    f32 amount = static_cast<f32>(arg13) / 100.0f;
    Unk_24e4a18[0].field_0[2].field_0 = amount < 0.0f ? 0.0f : (amount < 1.0f ? amount : 1.0f);
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4a18, 1);
    Unk_24e4c18[0] = *arg10;
    field_30.field_0->vf22(field_30.field_c4, Unk_24e4c18, 1);
    result = Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
    texture->vf15(filter);
    Unk_Texture29ad8(0)->vf15(filter0);
    Unk_Texture29ad8(1)->vf15(filter1);
    return result;
}

// 0x710048f900
s32 CTextureUtil::Unk_48f900(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1,
                             CRenderTexture* target, CRenderTexture* source0, CRenderTexture* source1,
                             const Unk_Float4* arg11, const Unk_Float2* arg12, u32 flags) {
    Unk_GPUTexture* texture0 = Unk_GetTexture(source0);
    Unk_GPUTexture* texture1 = Unk_GetTexture(source1);
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0)
        return result;
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    field_30.field_0->vf29((&field_30.field_2277c)[arg12 != nullptr]);
    field_30.field_0->vf26(field_30.field_10[0], texture0);
    field_30.field_0->vf26(field_30.field_10[1], texture1);
    s32 filter0 = texture0->vf16();
    s32 filter1 = texture1->vf16();
    texture0->vf15(4);
    texture1->vf15(4);
    if (arg12 != nullptr) {
        Unk_24e4a18[0].field_0[1] = arg12->field_0[0];
        Unk_24e4a18[0].field_0[2] = arg12->field_0[1];
    }
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4a18, 1);
    Unk_24e4c18[0] = *arg11;
    field_30.field_0->vf22(field_30.field_c4, Unk_24e4c18, 1);
    result = Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
    texture0->vf15(filter0);
    texture1->vf15(filter1);
    return result;
}

// 0x7100489c50
s32 CTextureUtil::DrawLightGhostLuminance(f32 x, f32 y, f32 width, f32 height, Unk_GPUTexture* texture, f32 arg4, f32 arg5,
                             const Unk_Float2* arg9, f32 arg6, f32 arg7, s32 mode, s32 index, u32 flags) {
    s32 set = mode == 1;
    s32 technique = (&field_30.field_7b3c)[set][index];
    if (technique == 0)
        return -4;
    field_30.field_0->vf29(technique);
    Unk_Float u = arg9->field_0[0];
    Unk_Float v = arg9->field_0[1];
    Unk_24e4a18[0].field_0[0] = u;
    Unk_24e4a18[0].field_0[1] = v;
    Unk_24e4a18[0].field_0[2].field_0 = arg5 * arg6 / arg4;
    Unk_24e4a18[0].field_0[3].field_0 = arg6;
    Unk_24e4a18[1].field_0[0].field_0 = arg7;
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4a18, 2);
    field_30.field_0->vf26(field_30.field_10[0], texture);
    s32 saved = texture->vf19();
    texture->vf17(0);
    s32 result = Unk_471960(x, y, width, height, flags);
    texture->vf17(saved);
    return result;
}

// 0x7101b35184: the default weights of Unk_490780 and Unk_490e70
static const f32 Unk_1b35184[29] = {1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
                                    1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
                                    1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f};

// 0x7100490780: `source` blurred by `count` taps of `weights` (bilinear pairs
// of them; normalised if asked, scaled by the square root of `scale`),
// horizontally into `temp`, then vertically into `target` (weighted by
// `color` there unless it is white)
// NON_MATCHING: 4 bytes short: the first pass's colour stores are paired here
// (the original's four stores aren't), and the pass's coordinates are
// scheduled in another order; the statements and calls are the original's.
s32 CTextureUtil::Unk_490780(f32 scale, CRenderTexture* source, CRenderTexture* temp, CRenderTexture* target,
                             s32 count, const f32* weights, bool normalize, s32 index, const Unk_Float4* color,
                             bool clear, s32 width, s32 height) {
    if (field_20 == nullptr) {
        return -1;
    }
    if (clear) {
        Unk_471410();
    }
    if (weights == nullptr) {
        weights = Unk_1b35184;
    }
    f32 offsets[15];
    f32 taps[15];
    Unk_Float4 colors[15];
    f32 tapWeights[15];
    Unk_Float4 values[15];
    s32 half = (count + 1) / 2;
    if (count >= 1) {
        f32 center = static_cast<f32>(count / 2);
        for (s32 i = 0; i < half; i++) {
            f32 x = static_cast<f32>(i * 2) - center;
            if ((count & 1) == 0 || i < half - 1) {
                Unk_412270(x, x + 1.0f, weights[i * 2], weights[i * 2 + 1], &offsets[i], &taps[i]);
            } else {
                offsets[i] = x;
                taps[i] = weights[i * 2] * 0.5f;
            }
        }
    }
    f32 norm = 1.0f;
    if (normalize) {
        f32 total = 0.0f;
        for (s32 i = 0; i < half; i++) {
            total += taps[i];
        }
        norm = 1.0f / total;
    }
    u32 sourceWidth = width != 0 ? width : source->field_54;
    u32 sourceHeight = height != 0 ? height : source->field_58;
    f32 scaleX = source->field_88;
    f32 scaleY = source->field_8c;
    f32 offsetX = source->field_90;
    f32 offsetY = source->field_94;
    u32 tempWidth = width != 0 ? width : temp->field_54;
    u32 tempHeight = height != 0 ? height : temp->field_58;
    norm *= sqrtf(scale);
    bool colored = color->field_0[0].field_0 != 1.0f || color->field_0[1].field_0 != 1.0f ||
                   color->field_0[2].field_0 != 1.0f || color->field_0[3].field_0 != 1.0f;
    for (s32 i = 0; i < half; i++) {
        f32 weight = norm * taps[i];
        if (colored) {
            colors[i].field_0[0].field_0 = weight;
            colors[i].field_0[1].field_0 = weight;
            colors[i].field_0[2].field_0 = weight;
            colors[i].field_0[3].field_0 = weight;
        } else {
            tapWeights[i] = weight;
        }
        values[i] = Unk_Float4(scaleX * offsets[i], 0.0f, 0.0f, 0.0f);
    }
    s32 result = temp->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0) {
        return result;
    }
    f32 u1 = scaleX * static_cast<f32>(sourceWidth) + offsetX;
    f32 v1 = scaleY * static_cast<f32>(sourceHeight) + offsetY;
    f32 fw = static_cast<f32>(tempWidth);
    f32 fh = static_cast<f32>(tempHeight);
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    if (colored) {
        result = DrawRectGPU_MadT1_Sn(0.0f, 0.0f, fw, fh, 0.0f, 0.0f, u1, v1, half, values, colors,
                                      Unk_GetTexture(source), index, 0);
    } else {
        result = Unk_475d80(0.0f, 0.0f, fw, fh, 0.0f, 0.0f, u1, v1, half, values, tapWeights, Unk_GetTexture(source),
                            index, 0);
    }
    if (result < 0) {
        return result;
    }
    u32 width2 = width != 0 ? width : temp->field_54;
    u32 height2 = height != 0 ? height : temp->field_58;
    f32 tempScaleX = temp->field_88;
    f32 tempScaleY = temp->field_8c;
    f32 tempOffsetX = temp->field_90;
    f32 tempOffsetY = temp->field_94;
    u32 targetWidth = width != 0 ? width : target->field_54;
    u32 targetHeight = height != 0 ? height : target->field_58;
    for (s32 i = 0; i < half; i++) {
        f32 weight = norm * taps[i];
        if (colored) {
            colors[i] = Unk_Float4(weight * color->field_0[0].field_0, weight * color->field_0[1].field_0,
                                   weight * color->field_0[2].field_0, weight * color->field_0[3].field_0);
        } else {
            tapWeights[i] = weight;
        }
        values[i] = Unk_Float4(0.0f, source->field_8c * offsets[i], 0.0f, 0.0f);
    }
    result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0) {
        return result;
    }
    u1 = tempScaleX * static_cast<f32>(width2) + tempOffsetX;
    v1 = tempScaleY * static_cast<f32>(height2) + tempOffsetY;
    if (colored) {
        result = DrawRectGPU_MadT1_Sn(0.0f, 0.0f, static_cast<f32>(targetWidth), static_cast<f32>(targetHeight),
                                      0.0f, 0.0f, u1, v1, half, values, colors, Unk_GetTexture(temp), index, 0);
    } else {
        result = Unk_475d80(0.0f, 0.0f, static_cast<f32>(targetWidth), static_cast<f32>(targetHeight), 0.0f, 0.0f,
                            u1, v1, half, values, tapWeights, Unk_GetTexture(temp), index, 0);
    }
    return result < 0 ? result : 0;
}

// 0x7100490e70: `arg3` blurred along a line of `count` taps of `weights`
// (`length` long, at `angle`; normalised if asked, scaled by the square root
// of `scale`) into `arg4`, then along the line at right angles to it into
// `arg5` (weighted by `arg10`'s colour there unless it is white), with the
// circle of confusion of `arg11` (and `arg12`'s range) when there is one
// NON_MATCHING: 8 bytes more: register allocation (`index` stays in a register
// here, the original spills it and `this`; 0x10 more frame), and the length's
// select comes after cosf/sinf; the statements and calls are the original's.
s32 CTextureUtil::Unk_490e70(f32 angle, f32 length, f32 scale, void* arg3, void* arg4, void* arg5, s32 count,
                             const f32* weights, bool normalize, s32 index, void* arg10, void* arg11, void* arg12,
                             bool clear, s32 width, s32 height) {
    if (field_20 == nullptr) {
        return -1;
    }
    CRenderTexture* source = static_cast<CRenderTexture*>(arg3);
    CRenderTexture* temp = static_cast<CRenderTexture*>(arg4);
    CRenderTexture* target = static_cast<CRenderTexture*>(arg5);
    CRenderTexture* coc = static_cast<CRenderTexture*>(arg11);
    const Unk_Float4* range = static_cast<const Unk_Float4*>(arg12);
    if (clear) {
        Unk_471410();
    }
    if (length <= 0.0f) {
        length = static_cast<f32>(count);
    }
    if (weights == nullptr) {
        weights = Unk_1b35184;
    }
    f32 step = length / static_cast<f32>(count);
    f32 cosine = cosf(angle);
    f32 sine = sinf(angle);
    Unk_Float2 offsets[15];
    Unk_Float4 colors[15];
    f32 tapWeights[15];
    Unk_Float4 values[15];
    for (s32 i = 0; i < count; i++) {
        f32 x = step * static_cast<f32>(i - (count - 1) / 2);
        offsets[i] = Unk_Float2(cosine * x - sine * 0.0f, cosine * 0.0f + sine * x);
    }
    f32 norm = 1.0f;
    if (normalize) {
        f32 total = 0.0f;
        for (s32 i = 0; i < count; i++) {
            total += weights[i];
        }
        if (total != 0.0f) {
            norm = 1.0f / total;
        }
    }
    u32 sourceWidth = width != 0 ? width : source->field_54;
    u32 sourceHeight = height != 0 ? height : source->field_58;
    f32 scaleX = source->field_88;
    f32 scaleY = source->field_8c;
    f32 offsetX = source->field_90;
    f32 offsetY = source->field_94;
    u32 tempWidth = width != 0 ? width : temp->field_54;
    u32 tempHeight = height != 0 ? height : temp->field_58;
    const Unk_Float4* color = static_cast<const Unk_Float4*>(arg10);
    norm *= sqrtf(scale);
    bool colored = color->field_0[0].field_0 != 1.0f || color->field_0[1].field_0 != 1.0f ||
                   color->field_0[2].field_0 != 1.0f || color->field_0[3].field_0 != 1.0f;
    for (s32 i = 0; i < count; i++) {
        f32 weight = norm * weights[i];
        if (colored) {
            colors[i] = Unk_Float4(weight, weight, weight, weight);
        } else {
            tapWeights[i] = weight;
        }
        values[i] = Unk_Float4(scaleX * offsets[i].field_0[0].field_0, scaleY * offsets[i].field_0[1].field_0,
                               0.0f, 0.0f);
    }
    s32 result = temp->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0) {
        return result;
    }
    f32 u1 = scaleX * static_cast<f32>(sourceWidth) + offsetX;
    f32 v1 = scaleY * static_cast<f32>(sourceHeight) + offsetY;
    f32 fw = static_cast<f32>(tempWidth);
    f32 fh = static_cast<f32>(tempHeight);
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    if (coc != nullptr) {
        result = DrawRectGPU_MadCocT2_Sn(0.0f, 0.0f, fw, fh, 0.0f, 0.0f, u1, v1, count, values, colors, range,
                                         Unk_GetTexture(source), Unk_GetTexture(coc), 0, 0);
    } else if (colored) {
        result = DrawRectGPU_MadT1_Sn(0.0f, 0.0f, fw, fh, 0.0f, 0.0f, u1, v1, count, values, colors,
                                      Unk_GetTexture(source), 0, 0);
    } else {
        result = Unk_475d80(0.0f, 0.0f, fw, fh, 0.0f, 0.0f, u1, v1, count, values, tapWeights,
                            Unk_GetTexture(source), 0, 0);
    }
    if (result < 0) {
        return result;
    }
    u32 width2 = width != 0 ? width : temp->field_54;
    u32 height2 = height != 0 ? height : temp->field_58;
    f32 tempScaleX = temp->field_88;
    f32 tempScaleY = temp->field_8c;
    f32 tempOffsetX = temp->field_90;
    f32 tempOffsetY = temp->field_94;
    u32 targetWidth = width != 0 ? width : target->field_54;
    u32 targetHeight = height != 0 ? height : target->field_58;
    for (s32 i = 0; i < count; i++) {
        f32 weight = norm * weights[i];
        if (colored) {
            colors[i] = Unk_Float4(weight * color->field_0[0].field_0, weight * color->field_0[1].field_0,
                                   weight * color->field_0[2].field_0, weight * color->field_0[3].field_0);
        } else {
            tapWeights[i] = weight;
        }
        values[i] = Unk_Float4(-(scaleX * offsets[i].field_0[1].field_0), scaleY * offsets[i].field_0[0].field_0,
                               0.0f, 0.0f);
    }
    result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0) {
        return result;
    }
    u1 = tempScaleX * static_cast<f32>(width2) + tempOffsetX;
    v1 = tempScaleY * static_cast<f32>(height2) + tempOffsetY;
    fw = static_cast<f32>(targetWidth);
    fh = static_cast<f32>(targetHeight);
    if (coc != nullptr) {
        result = DrawRectGPU_MadCocT2_Sn(0.0f, 0.0f, fw, fh, 0.0f, 0.0f, u1, v1, count, values, colors, range,
                                         Unk_GetTexture(temp), Unk_GetTexture(coc), index, 0);
    } else if (colored) {
        result = DrawRectGPU_MadT1_Sn(0.0f, 0.0f, fw, fh, 0.0f, 0.0f, u1, v1, count, values, colors,
                                      Unk_GetTexture(temp), index, 0);
    } else {
        result = Unk_475d80(0.0f, 0.0f, fw, fh, 0.0f, 0.0f, u1, v1, count, values, tapWeights, Unk_GetTexture(temp),
                            index, 0);
    }
    return result < 0 ? result : 0;
}
// 0x71004915e0
s32 CTextureUtil::Unk_4915e0(f32 arg0, f32 arg1, f32 arg2, void* arg3, void* arg4, void* arg5, s32 arg6,
                             s32 arg9, void* arg10, void* arg11, void* arg12, bool clear, s32 arg14, s32 arg15) {
    return Unk_490e70(arg0, arg1, arg2, arg3, arg4, arg5, arg6, nullptr, 1, arg9, arg10, arg11, arg12, clear, arg14,
                      arg15);
}

// 0x710048b1e0
s32 CTextureUtil::Unk_48b1e0(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 arg8, f32 arg9,
                             f32 arg10, Unk_GPUTexture* texture, s32 arg12, void* arg13, s32 arg14, bool mirror,
                             void* arg16, void* arg17, void* arg18, void* arg19, s32 arg20, f32 arg21, void* arg22,
                             u32 flags) {
    Unk_Float4 scale(1.0f, 0.0f, 1.0f, 0.0f);
    if (mirror)
        scale = Unk_Float4(-1.0f, 1.0f, -1.0f, 1.0f);
    return Unk_48ad80(x, y, width, height, u0, v0, u1, v1, arg8, arg9, arg10, true, texture, arg12, arg13, arg14, 3,
                      &scale, arg16, arg17, arg18, arg19, arg20, arg21, arg22, flags);
}

// 0x7100482f10
s32 CTextureUtil::Unk_482f10(f32 x, f32 y, CRenderTexture* target, void* arg4, void* arg5,
                             const MATRIXT44* arg6, const MATRIXT44* arg7, void* arg8, s32 arg9, f32 arg2, void* arg10,
                             s32 arg11, void* arg12, bool arg13) {
    Unk_Float2 offset = Unk_4827b0(arg6, arg7, arg8, x, y);
    if (field_20->field_58)
        offset.field_0[1].field_0 = -offset.field_0[1].field_0;
    Unk_4823b0(arg2, target, arg4, arg5, &offset, arg9, arg11, arg12, arg13);
    return 0;
}

// 0x7100493e20
s32 CTextureUtil::Unk_493e20(f32 scale, CRenderTexture* source, CRenderTexture* target, s32 size, s32 mode,
                             const Unk_Float4* color, bool clear, bool arg7, s32 arg8, s32 arg9) {
    switch (size) {
    case 3: {
        f32 weights[9] = {0.4f, 1.0f, 0.4f, 1.0f, 1.0f, 1.0f, 0.4f, 1.0f, 0.4f};
        Unk_Float4 value(color->field_0[0].field_0 * scale, color->field_0[1].field_0 * scale,
                         color->field_0[2].field_0 * scale, color->field_0[3].field_0 * scale);
        return Unk_4930d0(source, target, weights, 1, mode, &value, clear, arg7, arg8, arg9);
    }
    case 5:
        return Unk_4934a0(scale, source, target, mode, color, clear, arg7, arg8, arg9);
    case 9:
        return Unk_4937b0(scale, source, target, mode, color, clear, arg7, arg8, arg9);
    default:
        return -4;
    }
}

// 0x71004934a0
s32 CTextureUtil::Unk_4934a0(f32 scale, CRenderTexture* source, CRenderTexture* target, s32 mode,
                             const Unk_Float4* color, bool arg5, bool clear, s32 arg7, s32 arg8) {
    if (field_20 == nullptr)
        return -1;
    Unk_BeginFilter(clear, arg5);
    u32 sourceWidth = arg7 != 0 ? arg7 : source->field_54;
    u32 sourceHeight = arg8 != 0 ? arg8 : source->field_58;
    f32 u1 = source->field_88 * static_cast<f32>(sourceWidth) + source->field_90;
    f32 v1 = source->field_8c * static_cast<f32>(sourceHeight) + source->field_94;
    f32 width = static_cast<f32>(static_cast<u32>(arg7 != 0 ? arg7 : target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(arg8 != 0 ? arg8 : target->field_58));
    Unk_Float4 offsets[9];
    f32 weights[9];
    Unk_412400(source->field_80->field_8, source->field_80->field_c, offsets, weights, 1.0f);
    Unk_Float4 colors[9];
    for (s32 i = 0; i < 9; i++) {
        f32 weight = weights[i] * scale;
        colors[i] = Unk_Float4(color->field_0[0].field_0 * weight, weight * color->field_0[1].field_0,
                               weight * color->field_0[2].field_0, weight * color->field_0[3].field_0);
    }
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0)
        return result;
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    result = DrawRectGPU_MadT1_Sn(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1,
                                  9, offsets, colors, Unk_GetTexture(source), mode, 0);
    return result < 0 ? result : 0;
}

// 0x71004937b0
s32 CTextureUtil::Unk_4937b0(f32 scale, CRenderTexture* source, CRenderTexture* target, s32 mode,
                             const Unk_Float4* color, bool clear, bool arg6, s32 arg7, s32 arg8) {
    if (field_20 == nullptr)
        return -1;
    Unk_BeginFilter(clear, arg6);
    u32 sourceWidth = arg7 != 0 ? arg7 : source->field_54;
    u32 sourceHeight = arg8 != 0 ? arg8 : source->field_58;
    f32 u1 = source->field_88 * static_cast<f32>(sourceWidth) + source->field_90;
    f32 v1 = source->field_8c * static_cast<f32>(sourceHeight) + source->field_94;
    f32 width = static_cast<f32>(static_cast<u32>(arg7 != 0 ? arg7 : target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(arg8 != 0 ? arg8 : target->field_58));
    Unk_Float4 offsets[25];
    f32 weights[25];
    Unk_412560(source->field_80->field_8, source->field_80->field_c, offsets, weights, 1.0f);
    Unk_Float4 colors[25];
    for (s32 i = 0; i < 25; i++) {
        f32 weight = weights[i] * scale;
        colors[i] = Unk_Float4(color->field_0[0].field_0 * weight, weight * color->field_0[1].field_0,
                               weight * color->field_0[2].field_0, weight * color->field_0[3].field_0);
    }
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0)
        return result;
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    result = DrawRectGPU_MadT1_Sn(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1,
                                  25, offsets, colors, Unk_GetTexture(source), mode, 0);
    return result < 0 ? result : 0;
}

// 0x71004939c0
s32 CTextureUtil::Unk_4939c0(f32 scale, CRenderTexture* source, CRenderTexture* target, bool large, s32 mode,
                             const Unk_Float4* color, bool clear, bool arg7, s32 arg8, s32 arg9) {
    if (field_20 == nullptr)
        return -1;
    Unk_BeginFilter(clear, arg7);
    f32 sourceWidth = static_cast<f32>(static_cast<u32>(arg8 != 0 ? arg8 : source->field_54));
    f32 sourceHeight = static_cast<f32>(static_cast<u32>(arg9 != 0 ? arg9 : source->field_58));
    f32 u1 = source->field_88 * sourceWidth + source->field_90;
    f32 v1 = source->field_8c * sourceHeight + source->field_94;
    f32 width = static_cast<f32>(static_cast<u32>(arg8 != 0 ? arg8 : target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(arg9 != 0 ? arg9 : target->field_58));
    s32 count = large ? 28 : 24;
    Unk_Float4 offsets[28];
    f32 weights[28];
    Unk_412940(source->field_80->field_8, source->field_80->field_c, offsets, weights, large, 1.0f);
    Unk_Float4 colors[28];
    for (s32 i = 0; i < count; i++) {
        f32 weight = weights[i] * scale;
        colors[i] = Unk_Float4(color->field_0[0].field_0 * weight, weight * color->field_0[1].field_0,
                               weight * color->field_0[2].field_0, weight * color->field_0[3].field_0);
    }
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0)
        return result;
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    result = DrawRectGPU_MadT1_Sn(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, count, offsets, colors,
                                  Unk_GetTexture(source), mode, 0);
    return result < 0 ? result : 0;
}

// 0x71004816a0 (as 0x7100481540: the sizes in locals, the source's first;
// the last two floats after the pointers: the registers are the same, the
// order decides the entry's spills)
s32 CTextureUtil::Unk_4816a0(f32 arg0, f32 arg1, f32 arg2, CRenderTexture* source, CRenderTexture* target,
                             const Unk_Float4* arg7, const Unk_Float4* arg8, f32 arg3, f32 arg4) {
    f32 sourceWidth = static_cast<f32>(static_cast<u32>(source->field_54));
    f32 sourceHeight = static_cast<f32>(static_cast<u32>(source->field_58));
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    u32 levelWidth = source->field_80->field_8;
    u32 levelHeight = source->field_80->field_c;
    f32 u1;
    f32 v1;
    Unk_GetCoords(source, &u1, &v1);
    Unk_Float4 weights[4];
    Unk_411df0(levelWidth, levelHeight, weights, 2, true, 0, sourceWidth, sourceHeight, width, height, 0.5f, 0.5f,
               0.0f);
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0)
        return result;
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    result = Unk_473d90(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, arg0, arg1, arg2, arg3, arg4, arg7, arg8,
                        weights, Unk_GetTexture(source), 0);
    return result < 0 ? result : 0;
}

// 0x7100481000
s32 CTextureUtil::Unk_481000(CRenderTexture* target, bool arg4, const Unk_Float2* arg5, const Unk_Float2* arg6,
                             f32 arg0, f32 arg1, f32 arg2, void* arg7, bool arg8, bool arg9, void* arg10, bool clear,
                             s32 arg12) {
    if (clear) {
        Unk_471410();
    }
    u32 targetWidth = target->field_54;
    u32 targetHeight = target->field_58;
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0)
        return result;
    f32 height = static_cast<f32>(targetHeight);
    f32 width = static_cast<f32>(targetWidth);
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    return Unk_4809a0(0.0f, 0.0f, width, height, arg5->field_0[0].field_0, arg5->field_0[1].field_0,
                      arg6->field_0[0].field_0, arg6->field_0[1].field_0, arg0, arg1, arg2, arg4, arg7, arg8, arg9,
                      arg10, arg12);
}

// 0x710048e9a0 (the target's position among the floats decides the entry's copies)
s32 CTextureUtil::Unk_48e9a0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, CRenderTexture* target, f32 arg4,
                             CRenderTexture* source, const void* arg7, const Unk_Float2* arg8, bool clear) {
    if (field_20 == nullptr)
        return -1;
    if (clear) {
        Unk_471410();
    }
    f32 u1;
    f32 v1;
    Unk_GetCoords(source, &u1, &v1);
    u32 targetWidth = target->field_54;
    u32 targetHeight = target->field_58;
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0)
        return result;
    f32 height = static_cast<f32>(targetHeight);
    f32 width = static_cast<f32>(targetWidth);
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    result = Unk_48eb30(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, arg0, arg1, arg2, arg3, arg4,
                        Unk_GetTexture(source), arg7, arg8, 0);
    return result < 0 ? result : 0;
}

// 0x710048edb0
// NON_MATCHING: the address of the source's field_88 (an argument) is computed once at
// the start and its loads go through it; the original computes it for the call.
s32 CTextureUtil::Unk_48edb0(f32 arg0, f32 arg1, CRenderTexture* target, CRenderTexture* source, const void* arg4,
                             bool clear) {
    if (field_20 == nullptr)
        return -1;
    if (clear) {
        Unk_471410();
    }
    f32 u1;
    f32 v1;
    Unk_GetCoords(source, &u1, &v1);
    u32 targetWidth = target->field_54;
    u32 targetHeight = target->field_58;
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0)
        return result;
    f32 height = static_cast<f32>(targetHeight);
    f32 width = static_cast<f32>(targetWidth);
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    result = Unk_48ef10(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, arg0, arg1, Unk_GetTexture(source),
                        &source->field_88, arg4, 0);
    return result < 0 ? result : 0;
}

// a quaternion (placeholder)
struct Unk_Quaternion {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

// a quaternion scaled to length 1 (inline; 0 and 1 long ones are kept)
static inline Unk_Quaternion Unk_Normalize(const Unk_Quaternion& q) {
    f32 length = q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w;
    if (length != 0.0f && length != 1.0f) {
        f32 inverse = 1.0f / sqrtf(length);
        Unk_Quaternion result = {q.x * inverse, q.y * inverse, q.z * inverse, q.w * inverse};
        return result;
    }
    return q;
}

// `from` copied into `to` with Unk_47d960 (`filter` its third value; inline)
static inline s32 Unk_CopyTexture(CTextureUtil* self, CRenderTexture* from, CRenderTexture* to, f32 filter) {
    Unk_Float4 one(1.0f, 1.0f, 1.0f, 1.0f);
    Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
    return self->Unk_47d960(0.0f, 0.0f, filter, 1.0f, from, to, nullptr, 0, &one, 0, false, false, 1, &zero, nullptr,
                            -1);
}

// 0x7100499250: Unk_497b20 at the level of `list` (pairs of textures, halving
// in size) where `color`'s largest value falls to `arg2`: `arg3` is
// downsampled to it (skipping levels by log2 `arg12` while they are exact
// halves larger than 320), its fraction past the next level's threshold
// blended in from that level, and the result scaled back up into `arg6`
// NON_MATCHING: 32 bytes short: Unk_47d960's eighth argument is a 32-bit
// zero in the original (`mov w4, wzr`; its declaration has u64), the copies'
// colours are at other stack offsets, the half colour's sign is a branch
// there, and registers differ; the statements and calls are the original's.
s32 CTextureUtil::Unk_499250(f32 arg0, f32 arg1, f32 arg2, CRenderTexture* arg3, CRenderTexture* arg4,
                             CRenderTexture* arg5, CRenderTexture* arg6, const Unk_Float4* color, s32 arg8,
                             const Unk_Float4* arg9, s32 count, void* list, u32 arg12, bool arg13, bool arg14,
                             bool arg15, s32 arg16, s32 arg17) {
    if (field_20 == nullptr) {
        return -1;
    }
    CRenderTexture** textures = static_cast<CRenderTexture**>(list);
    f32 cx = color->field_0[0].field_0;
    f32 x = cx > 0.0f ? cx : -cx;
    f32 y = color->field_0[1].field_0 > 0.0f ? color->field_0[1].field_0 : -color->field_0[1].field_0;
    f32 z = color->field_0[2].field_0 > 0.0f ? color->field_0[2].field_0 : -color->field_0[2].field_0;
    f32 w = color->field_0[3].field_0 > 0.0f ? color->field_0[3].field_0 : -color->field_0[3].field_0;
    f32 largest = x > y ? x : y;
    largest = largest > z ? largest : z;
    largest = largest > w ? largest : w;
    f32 level = logf(largest / arg2) / 0.693147182f + 1.0f;
    f32 most = static_cast<f32>(count);
    f32 clamped = level < 0.0f ? 0.0f : (level > most ? most : level);
    s32 levels = static_cast<s32>(clamped);
    f32 threshold = levels == 0 ? 0.75f : 0.65f;
    Unk_Float fraction = 0.0f;
    if (levels < count) {
        f32 rest = clamped - static_cast<f32>(levels);
        if (rest > threshold) {
            f32 t = (rest - threshold) / (1.0f - threshold);
            fraction = Unk_Saturate(t);
        }
    }
    f32 scale = ldexpf(1.0f, -levels);
    f32 factor = logf(static_cast<f32>(arg12));
    CRenderTexture* from = arg3;
    CRenderTexture* last = arg6;
    CRenderTexture* target = arg4;
    if (levels != 0) {
        last = arg3;
        s32 skip = static_cast<s32>(factor / 0.693147182f);
        f32 filter = 0.0f;
        for (s32 i = 0; i < levels;) {
            CRenderTexture* next = textures[i * 2];
            bool resized = next->field_54 * 2 != last->field_54 || next->field_58 * 2 != last->field_58;
            bool single = i > 0 || static_cast<u32>(next->field_54) < 321 || resized;
            if (single) {
                skip = 1;
                filter = 1.0f;
            }
            i += skip;
            CRenderTexture* to = textures[(i < levels ? i : levels) * 2 - 2];
            Unk_CopyTexture(this, last, to, filter);
            last = to;
        }
        from = last;
        target = textures[levels * 2 - 1];
    }
    CRenderTexture* blend = nullptr;
    CRenderTexture* blendTarget = nullptr;
    if (fraction.field_0 != 0.0f) {
        blend = textures[levels * 2];
        blendTarget = textures[levels * 2 + 1];
        Unk_CopyTexture(this, from, blend, 1.0f);
        if (levels == 0) {
            last = arg5 != nullptr ? arg5 : arg3;
        }
    }
    f32 r = x * scale;
    f32 g = y * scale;
    f32 b = z * scale;
    f32 a = w * scale;
    Unk_Float4 value(r, g, b, a);
    if (cx < 0.0f) {
        value = Unk_Float4(-r, -g, -b, -a);
    }
    Unk_497b20(arg0, arg1, from, target, last, &value, arg8, arg9, arg13, arg14, arg15, arg16, arg17);
    if (fraction.field_0 != 0.0f) {
        f32 sign = cx < 0.0f ? -0.5f : 0.5f;
        Unk_Float4 half(r * sign, g * sign, b * sign, a * sign);
        Unk_497b20(arg0, arg1, blend, blendTarget, blend, &half, arg8, arg9, arg13, arg14, arg15, arg16, arg17);
        if (levels >= 1) {
            Unk_CopyTexture(this, blend, from, 1.0f);
        } else {
            from = blend;
        }
    }
    Unk_Float4 weights[2];
    f32 rest = 1.0f - fraction.field_0;
    weights[0] = Unk_Float4(rest, rest, rest, rest);
    weights[1] = Unk_Float4(fraction, fraction, fraction, fraction);
    if (levels != 0) {
        if (levels >= 2) {
            CRenderTexture* to = textures[levels * 2 - 4];
            Unk_CopyTexture(this, last, to, 1.0f);
            last = to;
        }
        if (fraction.field_0 == 0.0f) {
            Unk_CopyTexture(this, last, arg6, 0.0f);
            return 0;
        }
    } else if (fraction.field_0 == 0.0f) {
        return 0;
    }
    CRenderTexture* sources[2] = {last, from};
    Unk_48d220(1.0f, 1.0f, arg6, 2, sources, weights, 0, false);
    return 0;
}

// 0x7100499890: the spherical interpolation of two quaternions
// NON_MATCHING: 8 bytes more: register allocation (the original keeps t and
// 1.0 in s5/s4, copied to v9/v8 around the sqrtf calls, and the second
// quaternion's x/y the other way round) and the interpolation's products are
// scheduled differently. The equality test's order (z, w, y, x in the source)
// gives the original's x, y, z, w chain; the dot product nested from x and the
// components' order w, x, z, y came closest.
Unk_Quaternion* Unk_499890(Unk_Quaternion* out, const Unk_Quaternion* from, const Unk_Quaternion* to, f32 t) {
    Unk_Quaternion a = Unk_Normalize(*from);
    Unk_Quaternion b = Unk_Normalize(*to);
    f32 dot = a.w * b.w + (a.z * b.z + (a.y * b.y + a.x * b.x));
    if (dot < 0.0f) {
        b.x = -b.x;
        b.y = -b.y;
        b.z = -b.z;
        b.w = -b.w;
        dot = -dot;
    }
    if (!(a.z == b.z && a.w == b.w && a.y == b.y && a.x == b.x)) {
        dot = dot > 1.0f ? 1.0f : dot;
        f32 difference = dot - 1.0f;
        if ((difference > 0.0f ? difference : -difference) < 4.76837158e-07f) {
            Unk_Quaternion c = {a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t, a.z + (b.z - a.z) * t,
                                a.w + (b.w - a.w) * t};
            a = Unk_Normalize(c);
        } else {
            f32 angle = acosf(dot);
            f32 inverse = 1.0f / sinf(angle);
            f32 wa = sinf((1.0f - t) * angle) * inverse;
            f32 wb = inverse * sinf(angle * t);
            a.w = a.w * wa + b.w * wb;
            a.x = a.x * wa + b.x * wb;
            a.z = a.z * wa + b.z * wb;
            a.y = a.y * wa + b.y * wb;
        }
    }
    *out = a;
    return out;
}

// 0x7100411c70
void Unk_411c70(f32 size, f32 ratio, s32 base, s32 mode, s32 maxLevels, s32* outLevels, s32* outCount,
                f32* outScale);

// 0x7100482d70
s32 CTextureUtil::Unk_482d70(f32 x, f32 y, CRenderTexture* target, const MATRIXT44* arg1,
                             const MATRIXT44* arg2, void* arg3, s32 maxLevels, f32 ratio, const Unk_Float2* scale, s32 index,
                             s32* outCount, s32* outLevels, s32* outFirst, Unk_Float2* outOffset,
                             Unk_Float2* outDirection) {
    Unk_Float2 offset = Unk_4827b0(arg1, arg2, arg3, x, y);
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    f32 offsetY = field_20->field_58 ? -offset.field_0[1].field_0 : offset.field_0[1].field_0;
    f32 dy = offsetY * height;
    f32 dx = offset.field_0[0].field_0 * width;
    f32 length = Unk_Sqrt(dx * dx + dy * dy);
    s32 count = field_29a64 < 2 ? 4 : field_29a64;
    s32 used = count + 1;
    s32 technique;
    do {
        technique = field_30.field_118[used - 2][index];
        used--;
    } while (used > 1 && technique == 0);
    s32 levels;
    s32 first;
    f32 s;
    Unk_411c70(length, ratio, used, 0, maxLevels, &levels, &first, &s);
    f32 k = s / length;
    if (outCount != nullptr) {
        *outCount = used;
    }
    if (outLevels != nullptr) {
        *outLevels = levels;
    }
    if (outFirst != nullptr) {
        *outFirst = first;
    }
    if (outDirection != nullptr) {
        outDirection->field_0[0].field_0 = -(dx * k);
        outDirection->field_0[1].field_0 = -(dy * k);
    }
    if (outOffset != nullptr) {
        outOffset->field_0[0].field_0 = offset.field_0[0].field_0;
        outOffset->field_0[1].field_0 = offsetY;
    }
    return 0;
}

}  // namespace PPFX

// 0x710043fc90 (lib/yebis/leaf; its argument isn't read)
u32 Unk_43fc90_get(u64 arg);

namespace PPFX {

// Unk_411c70's levels for a blur of `length` texels with up to `count` taps
// (inline: its locals end with it)
inline void Unk_BlurLevels(f32 length, f32 ratio, s32 count, s32 maxLevels, s32* outLevels, s32* outTaps,
                           f32* outStep) {
    s32 levels;
    s32 taps;
    f32 step;
    Unk_411c70(length, ratio, count, 0, maxLevels, &levels, &taps, &step);
    *outLevels = levels;
    *outTaps = taps;
    *outStep = step;
}

// 0x71004823b0: `source` blurred along `offset` (in its texels) in passes of
// up to Unk_411c70's taps, ping-ponging between `temp` and `source` and
// ending in `target`, the last pass weighted by `color`
// NON_MATCHING: register allocation (the last pass's colour and the weights'
// count have each other's registers, the colour's y is spilled instead of its
// x) and the offsets' products: the original multiplies `scaleX * j` by the
// direction, here the direction comes first (Reassociate ranks the outer
// loop's phi lower). Tried: every order of the branches' assignments and the
// declarations, the colour as four floats or a pointer, the products'
// spellings.
s32 CTextureUtil::Unk_4823b0(f32 ratio, CRenderTexture* source, void* target, void* temp, const Unk_Float2* offset,
                             s32 maxLevels, s32 index, void* color, bool clear) {
    f32 sourceWidth = static_cast<f32>(static_cast<u32>(source->field_54));
    f32 sourceHeight = static_cast<f32>(static_cast<u32>(source->field_58));
    f32 dx = offset->field_0[0].field_0 * sourceWidth;
    f32 dy = offset->field_0[1].field_0 * sourceHeight;
    f32 length = Unk_Sqrt(dx * dx + dy * dy);
    s32 count = field_29a64 < 2 ? 4 : field_29a64;
    s32 used = count + 1;
    s32 technique;
    do {
        technique = field_30.field_118[used - 2][index];
        used--;
    } while (used > 1 && technique == 0);
    s32 levels;
    s32 first;
    f32 step;
    Unk_BlurLevels(length, ratio, used, maxLevels, &levels, &first, &step);
    f32 directionY;
    f32 directionX;
    if (levels != 0) {
        f32 k = step / length;
        directionY = -(dy * k);
        directionX = -(dx * k);
    } else {
        if (source == target) {
            return 0;
        }
        directionX = 0.0f;
        directionY = 0.0f;
        first = 1;
        levels = 1;
    }
    s32 mode = levels == 1 && first == 1 ? 0 : index;
    if (clear) {
        Unk_471410();
    }
    f32 width = static_cast<f32>(static_cast<u32>(source->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(source->field_58));
    f32 scaleX = source->field_88;
    f32 scaleY = source->field_8c;
    f32 u1 = scaleX * width + source->field_90;
    f32 v1 = scaleY * height + source->field_94;
    CRenderTexture* targets[2] = {static_cast<CRenderTexture*>(temp), source};
    f32 usedWeight = static_cast<f32>(used);
    f32 firstWeight = static_cast<f32>(first);
    for (s32 i = 0; i < levels; i++) {
        CRenderTexture* destination;
        Unk_Float4 weight;
        f32 total;
        s32 n;
        if (i == levels - 1) {
            weight = *static_cast<const Unk_Float4*>(color);
            total = firstWeight;
            destination = static_cast<CRenderTexture*>(target);
            n = first;
        } else {
            weight = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
            total = usedWeight;
            destination = targets[i & 1];
            n = used;
        }
        destination->Unk_49d250(0, 0, 1, 0, 0);
        CRenderTexture::Unk_49cf50(nullptr, nullptr);
        Unk_Float4 colors[16];
        Unk_Float4 offsets[16];
        for (s32 j = 0; j < n; j++) {
            f32 inverse = 1.0f / total;
            colors[j] = Unk_Float4(weight.field_0[0].field_0 * inverse, weight.field_0[1].field_0 * inverse,
                                   weight.field_0[2].field_0 * inverse, weight.field_0[3].field_0 * inverse);
            offsets[j] = Unk_Float4(scaleX * j * directionX, scaleY * j * directionY, 0.0f, 0.0f);
        }
        s32 filter = Unk_GetTexture(source)->vf16();
        Unk_GetTexture(source)->vf15(4);
        DrawRectGPU_MadT1_Sn(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, n, offsets, colors,
                             Unk_GetTexture(source), mode, 0);
        Unk_GetTexture(source)->vf15(filter);
        if (i < levels - 1) {
            Unk_43fc90_get(reinterpret_cast<u64>(field_20));
        }
        directionX *= usedWeight;
        directionY *= usedWeight;
        source = destination;
    }
    return 0;
}

// 0x71004821a0
s32 CTextureUtil::Unk_4821a0(CRenderTexture* source, CRenderTexture* other, CRenderTexture* target, bool arg4, bool clear, const f32* arg6, void* arg7, f32 arg0, f32 arg1, f32 ratio, s32 arg8, s32 arg9) {
    f32 sourceWidth = static_cast<f32>(static_cast<u32>(source->field_54));
    f32 sourceHeight = static_cast<f32>(static_cast<u32>(source->field_58));
    f32 u1 = source->field_88 * sourceWidth + source->field_90;
    f32 v1 = source->field_8c * sourceHeight + source->field_94;
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    if (clear) {
        s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
        if (result < 0) {
            return result;
        }
        CRenderTexture::Unk_49cf50(nullptr, nullptr);
    }
    if (ratio <= 0.0f) {
        ratio = sourceWidth / sourceHeight;
    }
    s32 filter = Unk_GetTexture(source)->vf16();
    Unk_GetTexture(source)->vf15(4);
    s32 result = Unk_4797a0(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, arg0, arg1, ratio, arg4,
                            Unk_GetTexture(source), Unk_GetTexture(other), arg6, arg7, arg8, arg9);
    Unk_GetTexture(source)->vf15(filter);
    return result < 0 ? result : 0;
}

// 0x71004155f0 (Unk_415f40.cpp): a matrix's inverse
void Unk_4155f0(MATRIXT44* out, const MATRIXT44* m);

// 0x7100410070 (Unk_415f40.cpp): a point through a matrix
void Unk_410070(Unk_Vector3* out, const Unk_Vector3* v, const MATRIXT44* m);
// 0x710040f6e0 (placeholder signature, from its callers): a projection's
// planes and angles
void Unk_40f6e0(const MATRIXT44* projection, bool arg1, bool* arg2, f32* arg3, f32* arg4, f32* arg5, f32* arg6,
                f32* near, f32* far, f32* arg9, f32* arg10, f32* arg11, f32* arg12, f32* arg13, f32* arg14,
                f32* arg15);

// a vector made unit length (inline)
static inline Unk_Vector3 Unk_Normalized(const Unk_Vector3& v) {
    f32 length = v.field_0[0] * v.field_0[0] + v.field_0[1] * v.field_0[1] + v.field_0[2] * v.field_0[2];
    if (length == 0.0f || length == 1.0f)
        return v;
    f32 inverse = 1.0f / sqrtf(length);
    Unk_Vector3 r;
    r.field_0[0] = v.field_0[0] * inverse;
    r.field_0[1] = v.field_0[1] * inverse;
    r.field_0[2] = v.field_0[2] * inverse;
    return r;
}

// a matrix row's first three elements made unit length (inline)
static inline void Unk_NormalizeRow(f32* row) {
    *reinterpret_cast<Unk_Vector3*>(row) = Unk_Normalized(*reinterpret_cast<const Unk_Vector3*>(row));
}

// 0x710040f660 (Unk_415f40.cpp): a scale and a translation (without them, 1 and 0)
void Unk_40f660(MATRIXT44* out, const Unk_Vector3* scale, const Unk_Vector3* translation);
// 0x710040f980 (Unk_415f40.cpp): the reciprocals of a matrix's first two scales
void Unk_40f980(const MATRIXT44* matrix, f32* x, f32* y);
// 0x710040f9b0 (Unk_415f40.cpp): a projection with a depth range of 0 to 1
// rebuilt with one of -1 to 1
MATRIXT44* Unk_40f9b0(MATRIXT44* out, const MATRIXT44* m, bool flip);
// 0x710040fd00 (Unk_415f40.cpp): the angles of a rotation
void Unk_40fd00(const MATRIXT44* m, f32* roll, f32* pitch, f32* yaw);
// 0x710040fde0 (Unk_415f40.cpp): a rotation from yaw, pitch and roll
MATRIXT44* Unk_40fde0(MATRIXT44* out, f32 yaw, f32 pitch, f32 roll);

// a diagonal matrix, its elements in row order (inline)
static inline void Unk_Diagonal(MATRIXT44* m, f32 x, f32 y, f32 z, f32 w) {
    m->field_0[0][0] = x;
    m->field_0[0][1] = 0.0f;
    m->field_0[0][2] = 0.0f;
    m->field_0[0][3] = 0.0f;
    m->field_0[1][0] = 0.0f;
    m->field_0[1][1] = y;
    m->field_0[1][2] = 0.0f;
    m->field_0[1][3] = 0.0f;
    m->field_0[2][0] = 0.0f;
    m->field_0[2][1] = 0.0f;
    m->field_0[2][2] = z;
    m->field_0[2][3] = 0.0f;
    m->field_0[3][0] = 0.0f;
    m->field_0[3][1] = 0.0f;
    m->field_0[3][2] = 0.0f;
    m->field_0[3][3] = w;
}

// a translation, its elements in row order (inline)
static inline void Unk_Translation(MATRIXT44* m, f32 x, f32 y, f32 z) {
    m->field_0[0][0] = 1.0f;
    m->field_0[0][1] = 0.0f;
    m->field_0[0][2] = 0.0f;
    m->field_0[0][3] = 0.0f;
    m->field_0[1][0] = 0.0f;
    m->field_0[1][1] = 1.0f;
    m->field_0[1][2] = 0.0f;
    m->field_0[1][3] = 0.0f;
    m->field_0[2][0] = 0.0f;
    m->field_0[2][1] = 0.0f;
    m->field_0[2][2] = 1.0f;
    m->field_0[2][3] = 0.0f;
    m->field_0[3][0] = x;
    m->field_0[3][1] = y;
    m->field_0[3][2] = z;
    m->field_0[3][3] = 1.0f;
}

// a view depth's projected depth (inline)
static inline f32 Unk_ProjectedDepth(f32 z, f32 near, f32 far) {
    return far * (z - near) / (far - near) / z;
}

// one corner of a light's quad in 0x7100487670's vertex buffer
struct Unk_487670_Vertex {
    Unk_Float field_0[3];  // the position
    Unk_Float2 field_c;    // the corner's texture coordinates
    f32 field_14;          // ... through the light's transform
    f32 field_18;
    f32 field_1c;  // the brightness
    f32 field_20;
    f32 field_24;  // the depth range's scale
    f32 field_28;  // and offset
};
PKMN_SIZE_ASSERT(Unk_487670_Vertex, 0x2c);

// 0x7100487670: a quad per light of `lights` (Unk_488380's, in view space),
// with the techniques field_30.field_22810 to field_22840 (`samples` 1 to 4)
// NON_MATCHING: register allocation and scheduling (same blocks, calls,
// frame and stack slots, 16 bytes shorter): `this` and `count` swap x20 and
// x21, the constant 1.0 is kept in s15 over the three row normalisations
// (the original materialises it in each), the viewport's scale and offset
// are computed in another order, and `height` is reloaded in both branches
// of the first colour (the original keeps it in s12 from the viewport on).
s32 CTextureUtil::Unk_487670(f32 arg0, f32 height, f32 left, f32 top, f32 right, f32 bottom, f32 depth0,
                             f32 depth1, s32 count, const Unk_29af8* lights, Unk_GPUTexture* texture,
                             Unk_GPUTexture* texture1, Unk_GPUTexture* texture2, const MATRIXT44* view,
                             const MATRIXT44* projection, const Unk_Float2* arg15, const Unk_Float4* color,
                             f32 size, f32 depthScale, const Unk_Float4* weights, const Unk_Float2* scale,
                             const Unk_Vector3* offset, f32 arg22, f32 arg23, s32 samples, bool flag, u32 flags) {
    if (texture1 == nullptr) {
        texture1 = Unk_Texture29ab8(0);
    }
    if (texture2 == nullptr) {
        texture2 = Unk_Texture29ab8(2);
    }
    if (count == 0 || lights == nullptr || texture1 == nullptr || texture2 == nullptr) {
        return -6;
    }
    MATRIXT44 m = *view;
    Unk_NormalizeRow(m.field_0[0]);
    Unk_NormalizeRow(m.field_0[1]);
    Unk_NormalizeRow(m.field_0[2]);
    MATRIXT44 inverse;
    Unk_4155f0(&inverse, &m);
    s32 n = samples < 4 ? samples : 4;
    n = n > 1 ? n : 1;
    s32 technique = flag ? field_30.field_22840[n - 1] : field_30.field_22820[n - 1];
    if (technique == 0) {
        technique = flag ? field_30.field_22830[n - 1] : field_30.field_22810[n - 1];
        if (technique == 0) {
            return -4;
        }
    }
    field_30.field_0->vf29(technique);
    MATRIXT44 matrices[2];
    if (field_20->field_59) {
        Unk_40f9b0(&matrices[0], projection, false);
    } else {
        matrices[0] = *projection;
    }
    bool flip = field_20->field_58;
    f32 h = bottom - top;
    Unk_Vector3 viewportScale;
    viewportScale.field_0[1] = h / (flip ? 2.0f : -2.0f);
    Unk_Vector3 viewportOffset;
    viewportScale.field_0[0] = (right - left) * 0.5f;
    viewportOffset.field_0[0] = viewportScale.field_0[0] + left;
    viewportOffset.field_0[1] = top - (flip ? -1.0f : 1.0f) * viewportScale.field_0[1];
    viewportScale.field_0[2] = 1.0f;
    viewportOffset.field_0[2] = 0.0f;
    MATRIXT44 viewport;
    Unk_40f660(&viewport, &viewportScale, &viewportOffset);
    MATRIXT44 transform;
    MATRIXT44_MatrixMultiply(&transform, projection, &viewport);
    matrices[1] = transform;
    field_30.field_0->vf25(field_30.field_114, matrices, 2);
    bool a2;
    f32 a3;
    f32 a4;
    f32 a5;
    f32 a6;
    f32 near;
    f32 far;
    f32 a9;
    f32 a10;
    f32 a11;
    f32 a12;
    f32 a13;
    Unk_40f6e0(&matrices[0], false, &a2, &a3, &a4, &a5, &a6, &near, &far, &a9, &a10, &a11, &a12, &a13, nullptr,
               nullptr);
    f32 depthScaleFactor = 0.0f;
    f32 depthOffset;
    if (depth0 == depth1 || depth0 <= 0.0f || depth1 <= 0.0f || (depth1 > depth0 && near >= depth1) ||
        (depth0 > depth1 && far <= depth1)) {
        depthOffset = 1.0f;
    } else {
        f32 d0 = Unk_ProjectedDepth(near < depth0 ? depth0 : near, near, far);
        f32 d1 = Unk_ProjectedDepth(depth1, near, far);
        depthScaleFactor = 1.0f / (d1 - d0);
        depthOffset = 0.0f - d0 * depthScaleFactor;
    }
    Unk_24e4c18[0].field_0[0] = arg15->field_0[0];
    Unk_24e4c18[0].field_0[1] = arg15->field_0[1];
    Unk_24e4c18[0].field_0[2].field_0 = arg22;
    Unk_24e4c18[0].field_0[3].field_0 = arg23;
    field_30.field_0->vf22(field_30.field_c8, Unk_24e4c18, 1);
    Unk_Diagonal(&transform, 1.0f, 1.0f, 1.0f, 1.0f);
    MATRIXT44 identity;
    Unk_Diagonal(&identity, 1.0f, 1.0f, 1.0f, 1.0f);
    f32 roll;
    f32 pitch;
    f32 yaw;
    Unk_40fd00(&inverse, &roll, &pitch, &yaw);
    MATRIXT44 rotation;
    Unk_40fde0(&rotation, 0.0f, pitch, yaw);
    MATRIXT44 rotationInverse;
    Unk_4155f0(&rotationInverse, &rotation);
    f32 t = pitch / 1.5707964f;
    f32 squash = 1.0f - Unk_Saturate(t > 0.0f ? t : -t);
    MATRIXT44 squashing;
    Unk_Diagonal(&squashing, squash, squash, 1.0f, 1.0f);
    MATRIXT44 unprojection;
    Unk_Float2 reciprocal;
    Unk_40f980(projection, &reciprocal.field_0[0].field_0, &reciprocal.field_0[1].field_0);
    Unk_Diagonal(&unprojection, 1.0f / reciprocal.field_0[0].field_0, 1.0f / reciprocal.field_0[1].field_0, 1.0f,
                 1.0f);
    MATRIXT44 toViewport;
    Unk_Diagonal(&toViewport, (viewportScale.field_0[0] + viewportScale.field_0[0]) * a13,
                 viewportScale.field_0[1] + viewportScale.field_0[1], 1.0f, 1.0f);
    MATRIXT44_MatrixMultiply(&transform, &transform, &identity);
    MATRIXT44_MatrixMultiply(&transform, &transform, &rotation);
    MATRIXT44_MatrixMultiply(&transform, &transform, &squashing);
    MATRIXT44_MatrixMultiply(&transform, &transform, &unprojection);
    MATRIXT44_MatrixMultiply(&transform, &transform, &toViewport);
    field_30.field_0->vf24(field_30.field_108, &transform);
    Unk_24e4c18[0].field_0[0].field_0 = 0.01f;
    if (flag) {
        Unk_24e4c18[0].field_0[1].field_0 = 5.9604645e-08f;
    } else {
        Unk_24e4c18[0].field_0[1].field_0 =
            (h > 0.0f ? h : -h) / height * 0.5f * color->field_0[3].field_0;
    }
    static Unk_Float4 white(1.0f, 1.0f, 1.0f, 1.0f);
    Unk_24e4c18[1] = white;
    Unk_24e4c18[1].field_0[0].field_0 *= color->field_0[0].field_0;
    Unk_24e4c18[1].field_0[1].field_0 *= color->field_0[1].field_0;
    Unk_24e4c18[1].field_0[2].field_0 *= color->field_0[2].field_0;
    if (flag) {
        Unk_24e4c18[1].field_0[3].field_0 *= (h > 0.0f ? h : -h) * height * color->field_0[3].field_0;
    } else {
        Unk_24e4c18[1].field_0[3].field_0 = 1.0f;
    }
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4c18, 2);
    field_30.field_0->vf26(field_30.field_10[0], texture);
    field_30.field_0->vf26(field_30.field_10[1], texture1);
    field_30.field_0->vf26(field_30.field_10[2], texture2);
    IGPUBuffer* buffer = static_cast<IGPUBuffer*>(field_29bc8[3]);
    Unk_487670_Vertex* vertices =
        static_cast<Unk_487670_Vertex*>(buffer->Map(6, 0, count * sizeof(Unk_487670_Vertex) * 4));
    MATRIXT44 tilt;
    Unk_40fde0(&tilt, 0.0f, pitch, 0.0f);
    MATRIXT44 tiltInverse;
    Unk_4155f0(&tiltInverse, &tilt);
    f32 s = sinf(-yaw);
    f32 c = cosf(yaw);
    MATRIXT44 coordTransform;
    Unk_Diagonal(&coordTransform, 1.0f, 1.0f, 1.0f, 1.0f);
    Unk_Float2 corners[4];
    corners[0].field_0[0].field_0 = -size;
    corners[0].field_0[1].field_0 = size;
    corners[1].field_0[0].field_0 = size;
    corners[1].field_0[1].field_0 = size;
    corners[2].field_0[0].field_0 = -size;
    corners[2].field_0[1].field_0 = -size;
    corners[3].field_0[0].field_0 = size;
    corners[3].field_0[1].field_0 = -size;
    Unk_Float2 coords[4];
    coords[0] = Unk_Float2(0.0f, 1.0f);
    coords[1] = Unk_Float2(1.0f, 1.0f);
    coords[2] = Unk_Float2(0.0f, 0.0f);
    coords[3] = Unk_Float2(1.0f, 0.0f);
    for (s32 i = 0; i < count; i++) {
        const Unk_29af8* light = &lights[i];
        Unk_487670_Vertex* quad = &vertices[i * 4];
        f32 z = light->field_0[2].field_0;
        f32 nearZ = z - light->field_c * depthScale;
        f32 d0 = Unk_Saturate(Unk_ProjectedDepth(z, near, far));
        f32 d1 = Unk_Saturate(Unk_ProjectedDepth(nearZ, near, far));
        f32 range = d0 - d1;
        f32 rangeScale = 1.0f / (range + 0.0f);
        f32 fade = Unk_Saturate(depthOffset + depthScaleFactor * d1);
        f32 rangeOffset = range * rangeScale + 0.0f;
        f32 dim = 1.0f - light->field_34;
        f32 brightness = dim + (1.0f - dim) * fade;
        for (s32 j = 0; j < 4; j++) {
            Unk_487670_Vertex* v = &quad[j];
            f32 cx = corners[j].field_0[0].field_0;
            f32 cy = corners[j].field_0[1].field_0;
            f32 r = light->field_c;
            v->field_0[0].field_0 = light->field_0[0].field_0 + r * (c * cx - s * cy);
            v->field_0[1].field_0 = light->field_0[1].field_0 + r * (s * cx + c * cy);
            v->field_0[2] = light->field_0[2];
            v->field_c.field_0[0] = coords[j].field_0[0];
            v->field_c.field_0[1] = coords[j].field_0[1];
            MATRIXT44 lightScale;
            Unk_Diagonal(&lightScale, light->field_20 * scale->field_0[0].field_0,
                         light->field_24 * scale->field_0[1].field_0, 1.0f, 1.0f);
            MATRIXT44 lightOffset;
            Unk_Translation(&lightOffset, offset->field_0[0] + light->field_28[0],
                            offset->field_0[1] + light->field_28[1], offset->field_0[2] + light->field_28[2]);
            MATRIXT44 m1;
            MATRIXT44 m0;
            MATRIXT44_MatrixMultiply(&m0, &lightScale, &lightOffset);
            MATRIXT44_MatrixMultiply(&m1, &m0, &coordTransform);
            f32 u = coords[j].field_0[0].field_0;
            f32 w = coords[j].field_0[1].field_0;
            v->field_14 = m1.field_0[3][0] + (m1.field_0[0][0] * u + m1.field_0[1][0] * w);
            v->field_18 = m1.field_0[3][1] + (m1.field_0[0][1] * u + m1.field_0[1][1] * w);
            v->field_1c = brightness * (light->field_10[j] * weights->field_0[j].field_0);
            v->field_20 = 1.0f;
            v->field_24 = rangeScale;
            v->field_28 = rangeOffset;
        }
    }
    static_cast<IGPUBuffer*>(field_29bc8[3])->Unmap();
    return Unk_4732b0(count * 6, 0, count * 4 - 1, static_cast<IGPUBuffer*>(field_29bc8[3]), field_29bc8[4], 0, 0,
                      flags);
}


// xorshift128, seeded like MT19937 (inline)
struct Unk_XorShift {
    Unk_XorShift(u32 seed) {
        field_0 = 0x6c078965 * (seed ^ (seed >> 30)) + 1;
        field_4 = 0x6c078965 * (field_0 ^ (field_0 >> 30)) + 2;
        field_8 = 0x6c078965 * (field_4 ^ (field_4 >> 30)) + 3;
        field_c = 0x6c078965 * (field_8 ^ (field_8 >> 30)) + 4;
    }
    u32 Next() {
        s32 t = field_0 ^ (field_0 << 11);
        field_0 = field_4;
        field_4 = field_8;
        field_8 = field_c;
        field_c = field_c ^ (field_c >> 19) ^ (t ^ (t >> 8));
        return field_c & 0x7fffffff;
    }
    // a value from `low` to `high`
    f32 Unk_Range(f32 low, f32 high) {
        return low + (high - low) * (static_cast<f32>(Next()) * (1.0f / 2147483648.0f));
    }

    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
};
PKMN_SIZE_ASSERT(Unk_XorShift, 0x10);

// 0x710048c1b0: a disc of `count` (a square, 9 to 64) jittered samples
// around each texel, the disc's points made once per size (and again when
// `regenerate` is set) from `seed`
// NON_MATCHING: a first version. The original unrolls the technique search
// (five steps, the clamps as selects), keeps the samples' constants in
// registers across the generation loops and orders the uniform stores
// differently; the statics (the flag, the guarded points and generator) are
// laid out as in the original's merged block.
s32 CTextureUtil::Unk_48c1b0(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 arg8, f32 arg9,
                             f32 arg10, f32 arg11, f32 arg12, f32 arg13, f32 arg14, f32 arg15, f32 arg16, f32 arg17,
                             void* arg18, Unk_GPUTexture* texture, s32 count, s32 seed, bool regenerate,
                             const f32* arg23, s32 flags) {
    s32 type = 0;
    if (arg23 != nullptr) {
        type = arg23[0] == 0.0f ? 0 : 1;
    }
    s32 side = static_cast<s32>(ceilf(sqrtf(static_cast<f32>(count))));
    s32 index = side > 3 ? (side - 3 < 5 ? side - 3 : 5) : 0;
    s32 technique;
    for (;;) {
        technique = (&field_30.field_7df8)[type][index];
        if (index < 1 || technique != 0)
            break;
        index--;
    }
    if (technique == 0) {
        return -4;
    }
    field_30.field_0->vf29(technique);
    s32 samples = (index + 3) * (index + 3);
    static Unk_Float4 points[6][64];
    static bool initialised = false;
    s32 level = static_cast<s32>(sqrtf(static_cast<f32>(samples))) - 3;
    if (!initialised || regenerate) {
        s32 first = initialised ? level : 0;
        s32 last = initialised ? level : 5;
        for (s32 l = first; l <= last; l++) {
            static Unk_XorShift random(seed);
            s32 side = l + 3;
            f32 step = 1.0f / side;
            for (s32 i = 0; i < side; i++) {
                f32 ring = static_cast<f32>(i) / side;
                for (s32 j = 0; j < side; j++) {
                    f32 radius = sqrtf(ring + step * random.Unk_Range(0.0f, 1.0f)) * 0.99f + 0.01f;
                    f32 angle = (static_cast<f32>(j) / side + step * random.Unk_Range(0.0f, 1.0f)) * 2.0f * 3.141592f;
                    points[l][i * side + j] = Unk_Float4(radius * cosf(angle), radius * sinf(angle), 0.0f, 0.0f);
                }
            }
        }
        initialised = true;
    }
    field_30.field_0->vf22(field_30.field_c8, points[level], samples);
    Unk_24e4c18[0] = Unk_Float4(logf(arg9 + 1.0f) / 0.693147182f, 0.0f, 0.0f, 0.0f);
    field_30.field_0->vf22(field_30.field_d4, Unk_24e4c18, 1);
    Unk_Float texel(0.5f / height * 2.0f);
    if (!(arg13 > 0.0f)) {
        arg13 = 1000000.0f;
    }
    Unk_Float low = arg12 > texel.field_0 ? Unk_Float(arg12) : texel;
    Unk_Float high = arg13 > texel.field_0 ? Unk_Float(arg13) : texel;
    f32 ratio = arg11 / arg10;
    f32 aspect = height / width;
    Unk_24e4c18[0] = Unk_Float4(aspect * ratio, ratio, 0.0f, 0.0f);
    Unk_24e4c18[1] = Unk_Float4(aspect * low.field_0, low, aspect * high.field_0, high);
    Unk_24e4c18[2] = Unk_Float4(arg16, arg17, arg11 * arg14 / samples, arg15);
    Unk_24e4c18[3] = Unk_Float4(arg8, arg9, 0.0f, 0.0f);
    if (type) {
        Unk_24e4c18[3].field_0[2].field_0 = arg23[0] / 0.99609375f;
        Unk_24e4c18[3].field_0[3].field_0 = arg23[1] + -0.00390625f;
    }
    f32 du = u1 - u0;
    f32 dv = v1 - v0;
    Unk_24e4c18[4] =
        Unk_Float4(du * 0.5f, dv * 0.5f, (u0 + 0.5f) * du, (v0 + 0.5f) * dv);
    if (!field_20->field_58) {
        Unk_24e4c18[4].field_0[3].field_0 = -(dv * 0.5f);
    }
    Unk_24e4c18[5] = Unk_Float4(width / du * (seed & 1 ? -1.0f : 1.0f),
                                          height / dv * (seed / 2 & 1 ? -1.0f : 1.0f), 0.0f, 0.0f);
    field_30.field_0->vf22(field_30.field_cc, Unk_24e4c18, 6);
    MATRIXT44 matrices[2];
    matrices[0] = *static_cast<const MATRIXT44*>(arg18);
    MATRIXT44 inverse;
    Unk_4155f0(&inverse, static_cast<const MATRIXT44*>(arg18));
    matrices[1] = inverse;
    field_30.field_0->vf25(field_30.field_114, matrices, 2);
    texture->vf15(4);
    texture->vf17(1);
    field_30.field_0->vf26(field_30.field_10[0], texture);
    bool flip = field_20->field_58;
    return Unk_471f60(x, y, width, height, u0, v0, u1, v1, -1.0f, flip ? -1.0f : 1.0f, 1.0f, flip ? 1.0f : -1.0f,
                      flags);
}

// 0x710048ca20
s32 CTextureUtil::Unk_48ca20(CRenderTexture* source, CRenderTexture* target, void* arg14, f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, f32 arg11, s32 count, s32 arg16, bool arg17, const f32* arg18, bool clear) {
    if (field_20 == nullptr) {
        return -1;
    }
    if (clear) {
        Unk_471410();
    }
    if (arg10 <= 0.0f) {
        arg10 = arg0;
    }
    if (arg11 <= 0.0f) {
        arg11 = arg1 * 0.999f;
    }
    f32 u1;
    f32 v1;
    Unk_GetCoords(source, &u1, &v1);
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0) {
        return result;
    }
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    result = Unk_48c1b0(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, arg10, arg11, arg2, arg3, arg4, arg5, arg6, arg7,
                        arg8, arg9, arg14, Unk_GetTexture(source), count, arg16, arg17, arg18, 0);
    return result < 0 ? result : 0;
}

// 0x710049e3a0 (GPURenderTexture.cpp's)
s32 Unk_49e3a0(u32 arg0, s32 arg1, s32 arg2, void* arg3, void* arg4, s32 arg5, void* arg6, void* arg7, f32 arg8);

// 0x710048cc30: Unk_48ca20 from `source` (copied through `copy` first) into
// `temp`, blurred both ways with `blur`, and composed (Unk_474e70) into
// `target` or `targetTexture` (exactly one of them)
// NON_MATCHING: the original loads `count` with the other stack arguments
// but clamps it after the blend calls, in w26 (here before them, spilled);
// its stack slots and copies follow from that.
s32 CTextureUtil::Unk_48cc30(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7,
                             CRenderTexture* source, CRenderTexture* temp, CRenderTexture* copy, CRenderTexture* blur0,
                             CRenderTexture* blur1, CRenderTexture* composite, CRenderTexture* target,
                             Unk_GPUTexture* targetTexture, void* arg14, s32 count, f32 arg8, f32 arg9, s32 arg16,
                             bool arg17, const f32* arg18, f32 arg10, f32 arg11, s32 arg20, CRenderTexture* source2,
                             s32 blurCount, f32 sigma, f32 blur2, f32 blur3, const Unk_Vector3* arg19, s32 mode,
                             CRenderTexture* source3, const Unk_Vector3* arg22, const Unk_Vector3* arg23, s32 linear,
                             bool resetBlend) {
    if ((targetTexture != nullptr) == (target != nullptr)) {
        return -6;
    }
    if (mode == 0 ? source3 != nullptr : source3 == nullptr) {
        return -6;
    }
    if (field_20 == nullptr) {
        return -1;
    }
    s32 n = count < 64 ? count : 64;
    n = n > 9 ? n : 9;
    if (resetBlend) {
        field_20->vf39();
        field_20->vf40(-1);
        field_20->vf42(0);
    }
    CRenderTexture* from = source;
    if (copy != nullptr) {
        Unk_474ae0(copy, source, false);
        from = copy;
    }
    Unk_474ae0(temp, from, false);
    Unk_48ca20(temp, blur0, arg14, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, n,
               arg16, arg17, arg18, false);
    Unk_474d00(sigma, blur2, blur3, blur0, blur1, true, blurCount, false);
    Unk_474d00(sigma, blur2, blur3, blur1, blur0, false, blurCount, false);
    CRenderTexture* blurred = blur0;
    if (composite != nullptr) {
        Unk_Float4 half(0.5f, 0.5f, 0.5f, 0.5f);
        Unk_Float4 ones(1.0f, 1.0f, 1.0f, 1.0f);
        Unk_Float4 zeros(0.0f, 0.0f, 0.0f, 0.0f);
        Unk_474e70(arg11, blur2, blur3, composite, nullptr, blur0, copy, 0, nullptr, true,
                   reinterpret_cast<const Unk_Vector3*>(&half), 0, nullptr, reinterpret_cast<const Unk_Vector3*>(&ones),
                   reinterpret_cast<const Unk_Vector3*>(&zeros), 0, false);
        blurred = composite;
    }
    if (targetTexture != nullptr) {
        ::Unk_49e3a0(1, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
    }
    s32 result = Unk_474e70(arg11, blur2, blur3, target, targetTexture, blurred, source, arg20, source2, false, arg19,
                            mode, source3, arg22, arg23, linear, false);
    return result < 0 ? result : 0;
}

// 0x710048e4e0
s32 CTextureUtil::Unk_48e4e0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
                             CRenderTexture* target, CRenderTexture* source, const Unk_Float2* center,
                             const f32* color, bool clear) {
    if (field_20 == nullptr) {
        return -1;
    }
    if (clear) {
        Unk_471410();
    }
    f32 u1;
    f32 v1;
    Unk_GetCoords(source, &u1, &v1);
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    bool same = source->field_54 == target->field_54 && source->field_58 == target->field_58;
    s32 filter = Unk_GetTexture(source)->vf16();
    Unk_GetTexture(source)->vf17(same);
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0) {
        return result;
    }
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    result = Unk_48e710(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, arg0, arg1, arg2, arg3, arg4, arg5, arg6,
                        Unk_GetTexture(source), center, color, 0);
    Unk_GetTexture(source)->vf15(filter);
    return result < 0 ? result : 0;
}

// 0x7100493be0
s32 CTextureUtil::Unk_493be0(CRenderTexture* source, CRenderTexture* a, CRenderTexture* b, void* target, f32 scale, bool flag, s32 arg6, const Unk_Float4* color, bool clear, bool arg9, s32 arg10, s32 arg11) {
    CRenderTexture* sources[2];
    if (field_20 == nullptr) {
        return -1;
    }
    if (clear) {
        Unk_471410();
    }
    f32 k = flag ? 54.399998f : 59.199997f;
    f32 total = k + 169.0f;
    f32 first = 169.0f / total;
    f32 second = k / total;
    f32 weights[13];
    weights[12] = 0.95f;
    weights[0] = 0.95f;
    for (s32 i = 1; i < 12; i++) {
        weights[i] = 1.0f;
    }
    Unk_490780(first * scale, source, b, a, 13, weights, 1, 0, color, false, arg10, arg11);
    Unk_4939c0(second * scale, source, b, flag, 0, color, false, false, arg10, arg11);
    Unk_GetTexture(a)->vf17(1);
    Unk_GetTexture(b)->vf17(1);
    sources[0] = a;
    sources[1] = b;
    Unk_48d220(1.0f, 1.0f, target, 2, sources, nullptr, arg6, 0);
    Unk_GetTexture(a)->vf17(0);
    Unk_GetTexture(b)->vf17(0);
    return 0;
}

// 0x710048e260
s32 CTextureUtil::Unk_48e260(CRenderTexture* source, CRenderTexture* target, f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, s32 arg10, void* arg11, s32 arg12, u32 arg13, bool clear) {
    if (field_20 == nullptr) {
        return -1;
    }
    if (clear) {
        Unk_471410();
    }
    u32 flags = Unk_GetTexture(source)->field_5c;
    s32 same = source->field_54 == target->field_54 && source->field_58 == target->field_58;
    Unk_GetTexture(source)->vf17((flags & 0x20000) ? same : 1);
    f32 u1;
    f32 v1;
    Unk_GetCoords(source, &u1, &v1);
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    s32 result = target->Unk_49d250(0, arg13, 1, 0, 0);
    if (result < 0) {
        return result;
    }
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    if (arg4 > 0.0f && arg7 >= 0.0f) {
        f32 minimum = 1.5f / height;
        arg7 = minimum < arg7 ? arg7 : minimum;
    }
    result = Unk_4780c0(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, arg0, arg1, arg2, arg3, arg4, arg5, arg6,
                        arg7, Unk_GetTexture(source), arg10, arg11, arg12, 0);
    Unk_GetTexture(source)->vf17(0);
    return result < 0 ? result : 0;
}

// 0x7100477d80 of the device textures of `count` render textures (inline)
inline s32 Unk_477d80_Sources(CTextureUtil* self, f32 width, f32 height, f32 u1, f32 v1, f32 power, s32 count,
                              CRenderTexture** sources, const Unk_Float4* color, const Unk_Float* weights,
                              s32 index) {
    Unk_GPUTexture* textures[16];
    for (s32 i = 0; i < count; i++) {
        textures[i] = Unk_GetTexture(sources[i]);
    }
    return self->Unk_477d80(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, power, count, textures, color, weights,
                            index, 0);
}

// 0x710048d550 (the floats after the pointers: with them first, `count` and
// the first source have each other's registers). The textures' array and the
// call are an inline function: its lifetime ends after the call, which stops
// jump threading from copying the call into the path where `count` is below
// 1, and inlined arrays sit above the caller's in the frame.
s32 CTextureUtil::Unk_48d550(CRenderTexture* target, s32 count, CRenderTexture** sources, const Unk_Float* weights,
                             f32 r, f32 g, f32 b, f32 a, f32 power, s32 index, bool clear) {
    Unk_Float4 color(r, g, b, a);
    s32 filters[16];
    if (field_20 == nullptr) {
        return -1;
    }
    if (clear) {
        Unk_471410();
    }
    f32 u1;
    f32 v1;
    Unk_GetCoords(sources[0], &u1, &v1);
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    for (s32 i = 0; i < count; i++) {
        CRenderTexture* source = sources[i];
        Unk_GPUTexture* texture = Unk_GetTexture(source);
        filters[i] = texture->vf16();
        texture->vf17(source->field_54 == target->field_54 && source->field_58 == target->field_58);
        texture->vf18(1);
    }
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0) {
        return result;
    }
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    result = Unk_477d80_Sources(this, width, height, u1, v1, power, count, sources, &color, weights, index);
    for (s32 i = 0; i < count; i++) {
        Unk_GetTexture(sources[i])->vf15(filters[i]);
    }
    return result < 0 ? result : 0;
}

// 0x7100498800
// NON_MATCHING: scheduling only: the original loads the effect after
// `mov w9, #4` and multiplies the row after the column's `csel` (the row as
// a local is the closest; tried both indices as locals in either order, as
// ifs, the effect or the row's pointer as locals, the flag tests reordered).
s32 CTextureUtil::Unk_498800(f32 x, f32 y, f32 width, f32 height, const f32* coords, Unk_GPUTexture* texture0,
                             bool flag, Unk_Float amount, Unk_GPUTexture* texture1, Unk_GPUTexture* texture2, s32 a, s32 b,
                             f32 value, Unk_GPUTexture* texture3, Unk_GPUTexture* texture4,
                             Unk_GPUTexture* texture5, u32 flags) {
    if (!flag) {
        texture1 = nullptr;
        b = 0;
        amount = 0.0f;
    }
    if (amount.field_0 == 0.0f) {
        texture2 = reinterpret_cast<Unk_GPUTexture*>(field_29a70[2]);
    }
    if (a == 0) {
        texture4 = reinterpret_cast<Unk_GPUTexture*>(field_29a70[4]);
    }
    if (b == 0) {
        texture5 = reinterpret_cast<Unk_GPUTexture*>(field_29a70[4]);
    }
    if (a == 0 && b == 0) {
        texture3 = reinterpret_cast<Unk_GPUTexture*>(field_29a70[2]);
    }
    if (texture4 == nullptr) {
        texture4 = reinterpret_cast<Unk_GPUTexture*>(field_29a70[4]);
    }
    if (texture5 == nullptr) {
        texture5 = reinterpret_cast<Unk_GPUTexture*>(field_29a70[4]);
    }
    s32 row = a == 0 ? 4 : a;
    field_30.field_0->vf29(field_30.field_2279c_table[row][flag && b == 0 ? 4 : b]);
    field_30.field_0->vf26(field_30.field_10[0], texture0);
    field_30.field_0->vf26(field_30.field_10[1], texture3);
    field_30.field_0->vf26(field_30.field_10[2], texture4);
    field_30.field_0->vf26(field_30.field_10[3], texture1);
    field_30.field_0->vf26(field_30.field_10[4], texture2);
    field_30.field_0->vf26(field_30.field_10[5], texture5);
    Unk_24e4c18[0] = Unk_Float4(value, 0.0f, 0.0f, amount);
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4c18, 1);
    Unk_472590(x, y, width, height, coords[0], coords[1], coords[2], coords[3], coords[4], coords[5], coords[6],
               coords[7], coords[8], coords[9], coords[10], coords[11], coords[12], coords[13], coords[14],
               coords[15], flags);
    return 0;
}

// what Unk_498ab0 sets as the render target (placeholder: its size)
struct Unk_498ab0_Surface {
    u8 pad_0[0x4c];
    u32 field_4c;
    u32 field_50;
};

// a render texture's far texture coordinates, 0 without one (inline)
static inline void Unk_CoordsOrZero(const CRenderTexture* texture, f32 width, f32 height, f32* u, f32* v) {
    if (texture != nullptr) {
        *u = texture->field_88 * width + texture->field_90;
        *v = texture->field_8c * height + texture->field_94;
    } else {
        *u = 0.0f;
        *v = 0.0f;
    }
}

// 0x7100498ab0: Unk_498800 from render textures into the part of `surface`
// (the target, set if `set`) that `x`, `y`, `width` and `height` cover (0: its
// size), each texture filtered unless it has the rectangle's size; the
// missing ones replaced by field_29a70's
// NON_MATCHING: 80 bytes short: the rectangle's corners are integer selects
// as in the original (Unk_Float lvalues assigned in an if/else, as in
// 0x710048de50), but the textures' nulls are tested in another order, the
// rectangle is scheduled differently and registers differ; the statements and
// calls are the original's.
s32 CTextureUtil::Unk_498ab0(f32 width, f32 height, f32 x, f32 y, f32 amount, f32 value, void* surface, bool set,
                             CRenderTexture* source, CRenderTexture* texture1, CRenderTexture* texture2, s32 a,
                             s32 b, CRenderTexture* texture3, CRenderTexture* texture4, CRenderTexture* texture5,
                             s32 state, bool clear, u32 flags) {
    if (texture1 == nullptr) {
        amount = 0.0f;
        b = 0;
        texture2 = nullptr;
    }
    if (amount == 0.0f) {
        texture2 = nullptr;
    }
    if (a == 0) {
        texture4 = nullptr;
    }
    if (b == 0) {
        texture5 = nullptr;
    }
    if (a == 0 && b == 0) {
        texture3 = nullptr;
    }
    if (clear) {
        Unk_471410();
    }
    const Unk_498ab0_Surface* target = static_cast<const Unk_498ab0_Surface*>(surface);
    if (set) {
        field_20->vf8(nullptr);
        if (target != nullptr) {
            field_20->vf7(0, surface, 0);
        }
    }
    if (target != nullptr) {
        f32 surfaceWidth = static_cast<f32>(target->field_4c);
        f32 surfaceHeight = static_cast<f32>(target->field_50);
        width = width == 0.0f ? surfaceWidth : width;
        height = height == 0.0f ? surfaceHeight : height;
    }
    Unk_Viewport viewport;
    f32 left;
    f32 top;
    {
        field_20->vf17(&viewport);
        Unk_Float right(width + x);
        Unk_Float bottom(height + y);
        Unk_Float leftEdge(x);
        Unk_Float topEdge(y);
        Unk_Float minX;
        Unk_Float maxX;
        if (right.field_0 < x) {
            minX = right;
            maxX = leftEdge;
        } else {
            minX = leftEdge;
            maxX = right;
        }
        Unk_Float minY;
        Unk_Float maxY;
        if (bottom.field_0 < y) {
            minY = bottom;
            maxY = topEdge;
        } else {
            minY = topEdge;
            maxY = bottom;
        }
        f32 viewportWidth = static_cast<f32>(viewport.field_8);
        f32 viewportHeight = static_cast<f32>(viewport.field_c);
        f32 x0 = minX.field_0 < 0.0f ? 0.0f : (minX.field_0 > viewportWidth ? viewportWidth : minX.field_0);
        f32 y0 = minY.field_0 < 0.0f ? 0.0f : (minY.field_0 > viewportHeight ? viewportHeight : minY.field_0);
        f32 x1 = maxX.field_0 < 0.0f ? 0.0f : (maxX.field_0 > viewportWidth ? viewportWidth : maxX.field_0);
        f32 y1 = maxY.field_0 < 0.0f ? 0.0f : (maxY.field_0 > viewportHeight ? viewportHeight : maxY.field_0);
        Unk_Viewport rect;
        rect.field_0 = static_cast<u32>(x0);
        rect.field_4 = static_cast<u32>(y0);
        rect.field_8 = static_cast<u32>(x1 - x0);
        rect.field_c = static_cast<u32>(y1 - y0);
        rect.field_10 = 0.0f;
        rect.field_14 = 1.0f;
        field_20->vf16(&rect);
        left = static_cast<f32>(static_cast<u32>(rect.field_0));
        top = static_cast<f32>(static_cast<u32>(rect.field_4));
    }
    f32 sourceWidth = static_cast<f32>(static_cast<u32>(source->field_54));
    f32 sourceHeight = static_cast<f32>(static_cast<u32>(source->field_58));
    f32 width1 = 0.0f;
    f32 height1 = 0.0f;
    if (texture1 != nullptr) {
        width1 = static_cast<f32>(static_cast<u32>(texture1->field_54));
        height1 = static_cast<f32>(static_cast<u32>(texture1->field_58));
    }
    f32 width2 = 0.0f;
    f32 height2 = 0.0f;
    if (texture2 != nullptr) {
        width2 = static_cast<f32>(static_cast<u32>(texture2->field_54));
        height2 = static_cast<f32>(static_cast<u32>(texture2->field_58));
    }
    f32 width3 = 0.0f;
    f32 height3 = 0.0f;
    if (texture3 != nullptr) {
        width3 = static_cast<f32>(static_cast<u32>(texture3->field_54));
        height3 = static_cast<f32>(static_cast<u32>(texture3->field_58));
    }
    f32 width4 = 0.0f;
    f32 height4 = 0.0f;
    if (texture4 != nullptr) {
        width4 = static_cast<f32>(static_cast<u32>(texture4->field_54));
        height4 = static_cast<f32>(static_cast<u32>(texture4->field_58));
    }
    f32 width5 = 0.0f;
    f32 height5 = 0.0f;
    if (texture5 != nullptr) {
        width5 = static_cast<f32>(static_cast<u32>(texture5->field_54));
        height5 = static_cast<f32>(static_cast<u32>(texture5->field_58));
    }
    u32 filter0 = width == sourceWidth && height == sourceHeight ? 5 : 4;
    Unk_GPUTexture* t0 = Unk_GetTexture(source);
    bool point1 = (width == width1 && height == height1) || texture1 == nullptr;
    bool point2 = (width == width2 && height == height2) || texture2 == nullptr;
    bool point3 = (width == width3 && height == height3) || texture3 == nullptr;
    bool point4 = (width == width4 && height == height4) || texture4 == nullptr;
    bool point5 = (width == width5 && height == height5) || texture5 == nullptr;
    Unk_GPUTexture* t1 =
        texture1 != nullptr ? Unk_GetTexture(texture1) : reinterpret_cast<Unk_GPUTexture*>(field_29a70[2]);
    Unk_GPUTexture* t2 =
        texture2 != nullptr ? Unk_GetTexture(texture2) : reinterpret_cast<Unk_GPUTexture*>(field_29a70[2]);
    Unk_GPUTexture* t3 =
        texture3 != nullptr ? Unk_GetTexture(texture3) : reinterpret_cast<Unk_GPUTexture*>(field_29a70[2]);
    Unk_GPUTexture* t4 =
        texture4 != nullptr ? Unk_GetTexture(texture4) : reinterpret_cast<Unk_GPUTexture*>(field_29a70[4]);
    Unk_GPUTexture* t5 =
        texture5 != nullptr ? Unk_GetTexture(texture5) : reinterpret_cast<Unk_GPUTexture*>(field_29a70[4]);
    u32 saved0 = t0->vf16();
    u32 saved1 = t1->vf16();
    u32 saved2 = t2->vf16();
    u32 saved3 = t3->vf16();
    u32 saved4 = t4->vf16();
    u32 saved5 = t5->vf16();
    t0->vf15(filter0);
    t1->vf15(point1 ? 5 : 4);
    t2->vf15(point2 ? 5 : 4);
    t3->vf15(point3 ? 5 : 4);
    t4->vf15(point4 ? 5 : 4);
    t5->vf15(point5 ? 5 : 4);
    field_20->vf44(state);
    f32 coords[16];
    coords[0] = 0.0f;
    coords[1] = 0.0f;
    coords[2] = source->field_88 * sourceWidth + source->field_90;
    coords[3] = source->field_8c * sourceHeight + source->field_94;
    coords[4] = 0.0f;
    coords[5] = 0.0f;
    Unk_CoordsOrZero(texture3, width3, height3, &coords[6], &coords[7]);
    coords[8] = 0.0f;
    coords[9] = 0.0f;
    Unk_CoordsOrZero(texture4, width4, height4, &coords[10], &coords[11]);
    coords[12] = 0.0f;
    coords[13] = 0.0f;
    Unk_CoordsOrZero(texture5, width5, height5, &coords[14], &coords[15]);
    Unk_498800(x - left, y - top, width, height, coords, t0, texture1 != nullptr, amount, t1, t2, a, b, value, t3,
               t4, t5, flags);
    t0->vf15(saved0);
    t1->vf15(saved1);
    t2->vf15(saved2);
    t3->vf15(saved3);
    t4->vf15(saved4);
    t5->vf15(saved5);
    return 0;
}

}  // namespace PPFX

// 0x7100488840 (lib/yebis/leaf): the lights' order, the brightest first
struct Unk_488840;
s32 Unk_488840_compare(const Unk_488840* a, const Unk_488840* b);

namespace PPFX {

// 0x7100488380: the lights of `lights` in front of the camera, nearer than
// `maxDistance` (at least the near plane) and inside the frustum, in view
// space and brightest first in field_29af8; nothing without `color`
// NON_MATCHING: three spots. The original copies the light's x and y for the
// mirrored position as two 32-bit words and loads its z as a float (here one
// 64-bit copy, and z is read back from the copy: four bytes longer), gives
// the count and the capacity each other's registers in the loops' exit test,
// and schedules the colour test's first compare after the argument copies.
s32 CTextureUtil::Unk_488380(f32 maxDistance, f32 arg1, f32 scale, s32 count, void* data, const MATRIXT44* view,
                             const MATRIXT44* projection, bool rightHanded, const Unk_Float4* color) {
    const Unk_29af8* lights = static_cast<const Unk_29af8*>(data);
    if (count == 0 || lights == nullptr) {
        return 0;
    }
    if (color->field_0[0].field_0 == 0.0f && color->field_0[1].field_0 == 0.0f && color->field_0[2].field_0 == 0.0f &&
        color->field_0[3].field_0 == 0.0f) {
        return 0;
    }
    MATRIXT44 m = *view;
    Unk_NormalizeRow(m.field_0[0]);
    Unk_NormalizeRow(m.field_0[1]);
    Unk_NormalizeRow(m.field_0[2]);
    f32 a3;
    f32 a4;
    f32 a5;
    f32 a6;
    f32 near;
    f32 far;
    f32 a9;
    f32 a10;
    f32 a11;
    f32 a12;
    Unk_40f6e0(projection, false, nullptr, &a3, &a4, &a5, &a6, &near, &far, &a9, &a10, &a11, &a12, nullptr, nullptr,
               nullptr);
    f32 nearPlane = near;
    field_29af4 = 0;
    for (s32 i = 0; i < count; i++) {
        const Unk_29af8* light = &lights[i];
        Unk_Vector3 v;
        Unk_Float4 p;
        if (rightHanded) {
            Unk_410070(reinterpret_cast<Unk_Vector3*>(&p), reinterpret_cast<const Unk_Vector3*>(light->field_0), &m);
        } else {
            v = *reinterpret_cast<const Unk_Vector3*>(light->field_0);
            v.field_0[2] = -v.field_0[2];
            Unk_410070(reinterpret_cast<Unk_Vector3*>(&p), &v, &m);
        }
        f32 z = p.field_0[2].field_0;
        f32 limit = nearPlane < maxDistance ? maxDistance : nearPlane;
        if (light->field_34 > 0.0f && z <= limit)
            continue;
        if (z <= near || z >= far)
            continue;
        p.field_0[3].field_0 = 1.0f;
        f32 px = p.field_0[0].field_0;
        f32 sx = px * projection->field_0[0][0] + z * projection->field_0[2][0];
        f32 py = p.field_0[1].field_0;
        f32 radius = light->field_c * scale;
        if ((sx > 0.0f ? sx : -sx) - projection->field_0[0][0] * radius > z) {
            f32 sy = py * projection->field_0[1][1] + z * projection->field_0[2][1];
            f32 ry = radius * projection->field_0[1][1];
            if ((sy > 0.0f ? sy : -sy) - ry > z)
                continue;
        }
        s32 index = field_29af4++;
        Unk_29af8* out = &field_29af8[index];
        *out = *light;
        out->field_0[0].field_0 = px;
        out->field_0[1].field_0 = py;
        out->field_0[2].field_0 = z;
        if (field_29af4 >= field_29af0)
            break;
    }
    if (field_29af4 == 0) {
        return 0;
    }
    qsort(field_29af8, field_29af4, sizeof(Unk_29af8),
          reinterpret_cast<int (*)(const void*, const void*)>(Unk_488840_compare));
    return field_29af4;
}

// 0x7100488860: the lights (found again by Unk_488380 when `update` is set)
// drawn as quads (Unk_487670) over `source` copied into `target`
// NON_MATCHING: register allocation: the original spills `size` (0x10 more
// frame), loads the target's size into s13/s9 with the source's (here its
// width goes through w26) and gives `this` x19 first.
s32 CTextureUtil::Unk_488860(f32 maxDistance, f32 arg1, f32 size, f32 depthScale, f32 arg4, f32 arg5, bool update,
                             s32 count, void* data, CRenderTexture* source, CRenderTexture* target,
                             Unk_GPUTexture* texture1, Unk_GPUTexture* texture2, const MATRIXT44* view,
                             const MATRIXT44* projection, const Unk_Float2* arg15, bool rightHanded,
                             const Unk_Float4* color, const Unk_Float4* colors, const Unk_Float2* scale,
                             const Unk_Vector3* offset, s32 samples, bool blend) {
    if (field_29af8 == nullptr) {
        return -4;
    }
    if (texture1 == nullptr) {
        texture1 = Unk_Texture29ab8(0);
    }
    if (texture2 == nullptr) {
        texture2 = Unk_Texture29ab8(2);
    }
    if (update) {
        if (count == 0 || data == nullptr) {
            return -6;
        }
        Unk_488380(maxDistance, arg1, size, count, data, view, projection, rightHanded, colors);
    }
    if (field_29af4 == 0) {
        return 1;
    }
    if (source == nullptr || target == nullptr) {
        return -6;
    }
    if (source == target && !field_20->field_14ef1) {
        return -6;
    }
    MATRIXT44 m = *view;
    Unk_NormalizeRow(m.field_0[0]);
    Unk_NormalizeRow(m.field_0[1]);
    Unk_NormalizeRow(m.field_0[2]);
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    f32 u1;
    f32 v1;
    Unk_GetCoords(source, &u1, &v1);
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0) {
        return result;
    }
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    Unk_Float4 ones(1.0f, 1.0f, 1.0f, 1.0f);
    DrawRectGPU_MadT1_Sn(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, 1, nullptr, &ones, Unk_GetTexture(source), 0,
                         0);
    bool add =
        blend && (reinterpret_cast<Unk_GPUTexture*>(target->field_b8[target->field_a0])->field_5c & 0x80000) != 0;
    field_20->vf44(add);
    field_20->vf45(add);
    texture1->vf15(0xf);
    texture2->vf15(3);
    Unk_GPUTexture* texture = Unk_GetTexture(source);
    s32 filter = texture->vf16();
    texture->vf15(8);
    result = Unk_487670(width, height, 0.0f, 0.0f, u1, v1, maxDistance, arg1, field_29af4, field_29af8,
                        Unk_GetTexture(source), texture1, texture2, &m, projection, arg15, color, size, depthScale,
                        colors, scale, offset, arg4, arg5, samples, add, 0);
    texture->vf15(filter);
    field_20->vf44(0);
    field_20->vf45(0);
    return result;
}

// 0x710048b280
// NON_MATCHING: the original addresses both technique tables from
// `&field_30.field_8` (CodeGenPrepare's split of the large offsets: in its
// TEXSHADERSET they are members of one object at offset 8), and spills
// `v1` instead of keeping it in a callee-saved register.
s32 CTextureUtil::Unk_48b280(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1,
                             Unk_GPUTexture* texture0, Unk_GPUTexture* texture1, const Unk_Float4* scale,
                             f32* factor, s32 channel, s32 index, void* arg7, void* arg8, void* arg9, s32 arg10,
                             f32 arg11, Unk_Float4* offset, u32 flags) {
    if (index == 21 || arg7 != nullptr) {
        return Unk_48ad80(x, y, width, height, u0, v0, u1, v1, 0.0f, 0.0f, 0.0f, false, texture0, -1, texture1,
                          index, channel, scale, factor, arg7, arg8, arg9, arg10, arg11, offset, flags);
    }
    s32 technique =
        texture1 != nullptr ? field_30.field_2d18_table[channel][0][index] : field_30.field_4318_table[channel];
    if (technique == 0) {
        return -4;
    }
    field_30.field_0->vf29(technique);
    Unk_24e4c18[0] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    field_30.field_0->vf22(field_30.field_c4, Unk_24e4c18, 1);
    field_30.field_0->vf22(field_30.field_c8, Unk_24e4c18, 0);
    f32 scaleZ = 1.0f;
    f32 scaleW = 0.0f;
    if (scale != nullptr) {
        scaleZ = scale->field_0[2].field_0;
        scaleW = scale->field_0[3].field_0;
    }
    f32 factorX = 1.0f;
    f32 factorY = 0.0f;
    if (factor != nullptr) {
        factorX = factor[0];
        factorY = factor[1];
    }
    f32 a = scaleZ * factorX;
    Unk_24e4a18[0] = Unk_Float4(a, a, a, a);
    Unk_24e4a18[1] = *offset;
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4a18, 2);
    f32 b = scaleW * factorX + factorY;
    Unk_24e4a18[0] = Unk_Float4(b, b, b, b);
    field_30.field_0->vf22(field_30.field_d4, Unk_24e4a18, 1);
    if (texture0 != nullptr) {
        field_30.field_0->vf26(field_30.field_8, texture0);
    }
    if (texture1 != nullptr) {
        field_30.field_0->vf26(field_30.field_c, texture1);
    }
    return Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
}

// 0x7100476bc0 of the device textures of `count` render textures (inline)
inline s32 Unk_476bc0_Sources(CTextureUtil* self, f32 width, f32 height, f32 u1, f32 v1, f32 power, s32 count,
                              CRenderTexture** sources, const Unk_Float4* colors, s32 index) {
    Unk_GPUTexture* textures[16];
    for (s32 i = 0; i < count; i++) {
        textures[i] = Unk_GetTexture(sources[i]);
    }
    return self->Unk_476bc0(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, power, count, textures, colors, index, 0);
}

// 0x710048d220: Unk_476bc0 from `count` render textures into `target`, the
// colours (all `scale` without them) scaled by `scale`
// NON_MATCHING: as 0x710048d550 (the textures and the call are an inline
// function, which keeps one call), `count` and the first source have each
// other's registers; the scaled colours are stored in pairs here, one by one
// (elements 3, 1, 2, 0) in the original, whose loop guard is `cmp #0; b.le`
// (`cmp #1; b.lt` here). Tried: element-wise stores in every order.
s32 CTextureUtil::Unk_48d220(f32 scale, f32 power, void* target, s32 count, CRenderTexture** sources,
                             const Unk_Float4* colors, s32 index, bool clear) {
    if (field_20 == nullptr) {
        return -1;
    }
    if (clear) {
        Unk_471410();
    }
    CRenderTexture* first = sources[0];
    CRenderTexture* destination = static_cast<CRenderTexture*>(target);
    Unk_Float4 scaled[16];
    s32 filters[16];
    if (scale != 1.0f) {
        for (s32 i = 0; i < count; i++) {
            if (colors != nullptr) {
                scaled[i] = Unk_Float4(colors[i].field_0[0].field_0 * scale, colors[i].field_0[1].field_0 * scale,
                                       colors[i].field_0[2].field_0 * scale, colors[i].field_0[3].field_0 * scale);
            } else {
                scaled[i] = Unk_Float4(scale, scale, scale, scale);
            }
        }
        colors = scaled;
    }
    for (s32 i = 0; i < count; i++) {
        CRenderTexture* source = sources[i];
        Unk_GPUTexture* texture = Unk_GetTexture(source);
        filters[i] = texture->vf16();
        texture->vf17(source->field_54 == destination->field_54 && source->field_58 == destination->field_58);
        texture->vf18(1);
    }
    f32 u1;
    f32 v1;
    Unk_GetCoords(first, &u1, &v1);
    u32 targetWidth = destination->field_54;
    u32 targetHeight = destination->field_58;
    s32 result = destination->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0) {
        return result;
    }
    f32 height = static_cast<f32>(targetHeight);
    f32 width = static_cast<f32>(targetWidth);
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    result = Unk_476bc0_Sources(this, width, height, u1, v1, power, count, sources, colors, index);
    for (s32 i = 0; i < count; i++) {
        Unk_GetTexture(sources[i])->vf15(filters[i]);
    }
    return result < 0 ? result : 0;
}

// the centre and the corners of a hexagon, filled in on the first call
// (0x71004920b0 and 0x71004922a0 inline it)
static const Unk_Float4* Unk_HexagonOffsets() {
    static Unk_Float4 offsets[7];
    static bool initialised = false;
    if (!initialised) {
        initialised = true;
        offsets[0] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
        for (s32 i = 0; i < 6; i++) {
            f32 angle = 60.0f * i * 3.14159265f / 180.0f;
            offsets[i + 1].field_0[0].field_0 = 0.0f - sinf(angle);
            offsets[i + 1].field_0[1].field_0 = cosf(angle);
            offsets[i + 1].field_0[2].field_0 = 0.0f;
            offsets[i + 1].field_0[3].field_0 = 0.0f;
        }
    }
    return offsets;
}

// 0x7100491640: `arg2` filtered in `passes` passes of two three-tap
// passes each (at -1, 0 and 1 times 3 to the pass, rotated by `arg0`, then
// at right angles to that), through `arg3` into `arg4`; the last pass
// weighted by `arg7`'s colour (DrawRectGPU_MadCocT2_Sn with `arg8`'s
// texture, else DrawRectGPU_MadT1_Sn)
// NON_MATCHING: register allocation and scheduling (16 bytes more): the
// original keeps 0.0f in s9 across the pass and spills the rotated taps in
// another order; the statements and calls are the original's.
s32 CTextureUtil::Unk_491640(f32 arg0, f32 arg1, void* arg2, void* arg3, void* arg4, s32 passes, s32 arg6,
                             void* arg7, void* arg8, void* arg9, bool clear, s32 arg11, s32 arg12) {
    if (field_20 == nullptr) {
        return -1;
    }
    if (clear) {
        Unk_471410();
    }
    CRenderTexture* source = static_cast<CRenderTexture*>(arg2);
    CRenderTexture* temp = static_cast<CRenderTexture*>(arg3);
    CRenderTexture* target = static_cast<CRenderTexture*>(arg4);
    CRenderTexture* coc = static_cast<CRenderTexture*>(arg8);
    f32 base = powf(arg1, 1.0f / (static_cast<f32>(passes) * 2.0f));
    f32 weight = base * 0.333333343f;
    CRenderTexture* current = source;
    s32 mode = 0;
    for (s32 pass = 0; pass < passes; pass++) {
        f32 scale = powf(3.0f, static_cast<f32>(pass));
        f32 cosine = cosf(arg0);
        f32 sine = sinf(arg0);
        u32 sourceWidth = arg11 != 0 ? arg11 : current->field_54;
        u32 sourceHeight = arg12 != 0 ? arg12 : current->field_58;
        f32 rx[3];
        f32 ry[3];
        for (s32 j = 0; j < 3; j++) {
            f32 x = static_cast<f32>(j - 1) * scale;
            rx[j] = cosine * x - sine * 0.0f;
            ry[j] = sine * x + cosine * 0.0f;
        }
        f32 u0 = current->field_88 * static_cast<f32>(sourceWidth) + current->field_90;
        f32 v0 = current->field_8c * static_cast<f32>(sourceHeight) + current->field_94;
        u32 width = arg11 != 0 ? arg11 : temp->field_54;
        u32 height = arg12 != 0 ? arg12 : temp->field_58;
        f32 scaleX = source->field_88;
        f32 scaleY = source->field_8c;
        Unk_Float4 values[3];
        Unk_Float4 colors[3];
        for (s32 j = 0; j < 3; j++) {
            colors[j] = Unk_Float4(weight, weight, weight, weight);
            values[j] = Unk_Float4(scaleX * rx[j], scaleY * ry[j], 0.0f, 0.0f);
        }
        s32 result = temp->Unk_49d250(0, 0, 1, 0, 0);
        if (result < 0) {
            return result;
        }
        CRenderTexture::Unk_49cf50(nullptr, nullptr);
        Unk_GPUTexture* texture = Unk_GetTexture(current);
        if (coc != nullptr) {
            result = DrawRectGPU_MadCocT2_Sn(0.0f, 0.0f, static_cast<f32>(width), static_cast<f32>(height), 0.0f,
                                             0.0f, u0, v0, 3, values, colors, static_cast<const Unk_Float4*>(arg9),
                                             texture, Unk_GetTexture(coc), mode, 0);
        } else {
            result = DrawRectGPU_MadT1_Sn(0.0f, 0.0f, static_cast<f32>(width), static_cast<f32>(height), 0.0f, 0.0f,
                                          u0, v0, 3, values, colors, texture, mode, 0);
        }
        if (result < 0) {
            return result;
        }
        u32 tempWidth = arg11 != 0 ? arg11 : temp->field_54;
        u32 tempHeight = arg12 != 0 ? arg12 : temp->field_58;
        f32 u1 = temp->field_88 * static_cast<f32>(tempWidth) + temp->field_90;
        f32 v1 = temp->field_8c * static_cast<f32>(tempHeight) + temp->field_94;
        u32 targetWidth = arg11 != 0 ? arg11 : target->field_54;
        u32 targetHeight = arg12 != 0 ? arg12 : target->field_58;
        const Unk_Float4* color = static_cast<const Unk_Float4*>(arg7);
        Unk_Float4 last = pass == passes - 1
                              ? Unk_Float4(weight * color->field_0[0].field_0, weight * color->field_0[1].field_0,
                                           weight * color->field_0[2].field_0, weight * color->field_0[3].field_0)
                              : Unk_Float4(weight, weight, weight, weight);
        for (s32 j = 0; j < 3; j++) {
            colors[j] = last;
            values[j] = Unk_Float4(-(scaleX * ry[j]), scaleY * rx[j], 0.0f, 0.0f);
        }
        result = target->Unk_49d250(0, 0, 1, 0, 0);
        if (result < 0) {
            return result;
        }
        texture = Unk_GetTexture(temp);
        if (pass == passes - 1) {
            mode = arg6;
        }
        if (coc != nullptr) {
            result = DrawRectGPU_MadCocT2_Sn(0.0f, 0.0f, static_cast<f32>(targetWidth),
                                             static_cast<f32>(targetHeight), 0.0f, 0.0f, u1, v1, 3, values, colors,
                                             static_cast<const Unk_Float4*>(arg9), texture, Unk_GetTexture(coc), mode,
                                             0);
        } else {
            result = DrawRectGPU_MadT1_Sn(0.0f, 0.0f, static_cast<f32>(targetWidth), static_cast<f32>(targetHeight),
                                          0.0f, 0.0f, u1, v1, 3, values, colors, texture, mode, 0);
        }
        if (result < 0) {
            return result;
        }
        current = target;
    }
    return 0;
}

// 0x7100491bb0: `source` filtered with `count` taps at `offsets` (rotated by
// `arg0`, scaled by `arg2` times `arg3` to the pass) in `passes` passes,
// ping-ponging between `temp0` and `temp1` and ending in `target`; the
// last pass weighted by `arg14`'s colour (DrawRectGPU_MadCocT2_Sn with
// `arg15`'s texture, else DrawRectGPU_MadT1_Sn). The position of the four
// scale floats among the parameters decides the registers and the entry's
// spills: they come last.
s32 CTextureUtil::Unk_491bb0(f32 arg0, f32 arg1, CRenderTexture* source, CRenderTexture* target,
                             CRenderTexture* temp0, CRenderTexture* temp1, s32 count, const Unk_Float4* offsets,
                             s32 passes, s32 arg13, void* arg14, void* arg15, void* arg16, bool arg17, s32 arg18,
                             s32 arg19, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    if (field_20 == nullptr) {
        return -1;
    }
    if (arg17) {
        Unk_471410();
    }
    f32 base = powf(arg1, 1.0f / static_cast<f32>(passes));
    CRenderTexture* temps[2] = {temp0, temp1};
    u32 sourceWidth = arg18 != 0 ? arg18 : source->field_54;
    u32 sourceHeight = arg19 != 0 ? arg19 : source->field_58;
    f32 scaleX = source->field_88;
    f32 scaleY = source->field_8c;
    f32 u1 = scaleX * static_cast<f32>(sourceWidth) + source->field_90;
    f32 v1 = scaleY * static_cast<f32>(sourceHeight) + source->field_94;
    u32 targetWidth = arg18 != 0 ? arg18 : target->field_54;
    u32 targetHeight = arg19 != 0 ? arg19 : target->field_58;
    f32 width = static_cast<f32>(targetWidth);
    f32 height = static_cast<f32>(targetHeight);
    f32 sine = sinf(arg0);
    f32 cosine = cosf(arg0);
    f32 weights[25];
    Unk_Float4 values[25];
    Unk_Float4 colors[25];
    u32 next = 0;
    s32 mode = 0;
    for (s32 pass = 0; pass < passes; pass++) {
        f32 scale = powf(arg3, static_cast<f32>(pass));
        f32 first = pass == passes - 1 ? arg4 : arg5;
        CRenderTexture* destination = pass == passes - 1 ? target : temps[next];
        f32 total = 0.0f;
        for (s32 j = 0; j < count; j++) {
            weights[j] = j == 0 ? base * first : base;
            total += weights[j];
        }
        for (s32 j = 0; j < count; j++) {
            f32 weight = 1.0f / total * weights[j];
            if (pass == passes - 1) {
                const Unk_Float4* color = static_cast<const Unk_Float4*>(arg14);
                colors[j] = Unk_Float4(weight * color->field_0[0].field_0, weight * color->field_0[1].field_0,
                                       weight * color->field_0[2].field_0, weight * color->field_0[3].field_0);
            } else {
                colors[j] = Unk_Float4(weight, weight, weight, weight);
            }
            f32 ox = offsets[j].field_0[0].field_0;
            f32 oy = offsets[j].field_0[1].field_0;
            values[j] = Unk_Float4(scaleX * (scale * arg2) * (cosine * ox - sine * oy),
                                   scaleY * (scale * arg2) * (sine * ox + cosine * oy), 0.0f, 0.0f);
        }
        s32 result = destination->Unk_49d250(0, 0, 1, 0, 0);
        if (result < 0) {
            return result;
        }
        if (pass == passes - 1) {
            mode = arg13;
        }
        Unk_GPUTexture* texture = Unk_GetTexture(source);
        if (arg15 != nullptr) {
            result = DrawRectGPU_MadCocT2_Sn(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, count, values, colors,
                                             static_cast<const Unk_Float4*>(arg16), texture,
                                             Unk_GetTexture(static_cast<CRenderTexture*>(arg15)), mode, 0);
        } else {
            result = DrawRectGPU_MadT1_Sn(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, count, values, colors,
                                          texture, mode, 0);
        }
        if (result < 0) {
            return result;
        }
        next = (next + 1) & 1;
        source = destination;
    }
    return 0;
}

// 0x71004920b0: 0x7100491bb0 with seven offsets, the centre and the corners
// of a hexagon (filled in on the first call)
// NON_MATCHING: only the guard path differs: it spills the arguments around
// __cxa_guard_acquire to other slots (0x10 more frame here). The parameters'
// order changes them (arg2 and arg3 after temp1 gives the original's frame
// size, not its slots); tried every position of the four floats.
s32 CTextureUtil::Unk_4920b0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, CRenderTexture* source, CRenderTexture* target,
                             CRenderTexture* temp0, CRenderTexture* temp1, s32 arg8, s32 arg9, void* arg10,
                             void* arg11, void* arg12, bool arg13, s32 arg14, s32 arg15) {
    const Unk_Float4* offsets = Unk_HexagonOffsets();
    return Unk_491bb0(arg0, arg1, source, target, temp0, temp1, 7, offsets, arg8, arg9, arg10, arg11, arg12, arg13,
                      arg14, arg15, arg2, 2.0f, arg3, 2.0f);
}

// 0x71004922a0: a hexagonal bokeh of `arg3` into `arg4`: with arg6 3 or 5
// the hexagon's 7 (or 19: also its corners doubled and the midpoints of
// those) offsets rotated by `arg0` in one pass weighted by `arg8`'s colour
// (and `arg1`), with 9 or 17 three directions of arg6 / 2 taps through
// `arg5`'s fourth texture into its first three (each 120 degrees on and a
// second leg at -120 degrees) added up with Unk_48d220
// NON_MATCHING: 64 bytes short (first draft): the 19-tap offsets are
// computed in another order (the original reloads some of the stored ones),
// the texel scales and the colours are scheduled differently, and registers
// differ; the calls and the control flow are the original's.
s32 CTextureUtil::Unk_4922a0(f32 arg0, f32 arg1, f32 arg2, void* arg3, void* arg4, void* arg5, s32 arg6, s32 arg7,
                             void* arg8, void* arg9, void* arg10, bool clear, s32 arg12, s32 arg13) {
    if (field_20 == nullptr) {
        return -1;
    }
    if (clear) {
        Unk_471410();
    }
    CRenderTexture* source = static_cast<CRenderTexture*>(arg3);
    CRenderTexture* target = static_cast<CRenderTexture*>(arg4);
    CRenderTexture** list = static_cast<CRenderTexture**>(arg5);
    const Unk_Float4* color = static_cast<const Unk_Float4*>(arg8);
    CRenderTexture* coc = static_cast<CRenderTexture*>(arg9);
    const Unk_Float4* range = static_cast<const Unk_Float4*>(arg10);
    u32 sourceFilter = Unk_GetTexture(source)->vf16();
    u32 targetFilter = Unk_GetTexture(target)->vf16();
    Unk_GetTexture(source)->vf15(8);
    Unk_GetTexture(target)->vf15(8);
    s32 filters[4];
    for (s32 i = 0; i < 4; i++) {
        filters[i] = -1;
        if (list[i] != nullptr) {
            filters[i] = Unk_GetTexture(list[i])->vf16();
            Unk_GetTexture(list[i])->vf15(8);
        }
    }
    u32 sourceWidth = arg12 != 0 ? arg12 : source->field_54;
    u32 sourceHeight = arg13 != 0 ? arg13 : source->field_58;
    f32 u1 = source->field_88 * static_cast<f32>(sourceWidth) + source->field_90;
    f32 v1 = source->field_8c * static_cast<f32>(sourceHeight) + source->field_94;
    u32 targetWidth = arg12 != 0 ? arg12 : target->field_54;
    u32 targetHeight = arg13 != 0 ? arg13 : target->field_58;
    f32 width = static_cast<f32>(targetWidth);
    f32 height = static_cast<f32>(targetHeight);
    f32 scaleX = (source->field_88 + source->field_90) * arg2;
    f32 scaleY = (source->field_8c + source->field_94) * arg2;
    f32 sine = sinf(arg0);
    f32 cosine = cosf(arg0);
    Unk_Float4 values[19];
    Unk_Float4 colors[19];
    s32 result;
    if (arg6 <= 5) {
        const Unk_Float4* offsets = Unk_HexagonOffsets();
        for (s32 i = 0; i < 7; i++) {
            f32 ox = offsets[i].field_0[0].field_0;
            f32 oy = offsets[i].field_0[1].field_0;
            values[i].field_0[0].field_0 = scaleX * (cosine * ox - sine * oy);
            values[i].field_0[1].field_0 = scaleY * (sine * ox + cosine * oy);
            values[i].field_0[2].field_0 = 0.0f;
            values[i].field_0[3].field_0 = 0.0f;
        }
        s32 count = arg6 == 3 ? 7 : 19;
        if (arg6 == 5) {
            for (s32 i = 0; i < 6; i++) {
                for (s32 c = 0; c < 4; c++) {
                    values[7 + i].field_0[c].field_0 = values[1 + i].field_0[c].field_0 * 2.0f;
                }
            }
            for (s32 i = 0; i < 6; i++) {
                for (s32 c = 0; c < 4; c++) {
                    values[13 + i].field_0[c].field_0 =
                        (values[7 + i].field_0[c].field_0 + values[7 + (i + 1) % 6].field_0[c].field_0) * 0.5f;
                }
            }
        }
        f32 weight = 1.0f / static_cast<f32>(count) * arg1;
        f32 r = weight * color->field_0[0].field_0;
        f32 g = weight * color->field_0[1].field_0;
        f32 b = weight * color->field_0[2].field_0;
        f32 a = weight * color->field_0[3].field_0;
        for (s32 i = 0; i < count; i++) {
            colors[i].field_0[0].field_0 = r;
            colors[i].field_0[1].field_0 = g;
            colors[i].field_0[2].field_0 = b;
            colors[i].field_0[3].field_0 = a;
        }
        result = target->Unk_49d250(0, 0, 1, 0, 0);
        if (result < 0) {
            return result;
        }
        if (coc != nullptr) {
            result = DrawRectGPU_MadCocT2_Sn(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, count, values, colors,
                                             range, Unk_GetTexture(source), Unk_GetTexture(coc), arg7, 0);
        } else {
            result = DrawRectGPU_MadT1_Sn(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, count, values, colors,
                                          Unk_GetTexture(source), arg7, 0);
        }
    } else if (arg6 == 9 || arg6 == 17) {
        s32 taps = arg6 / 2;
        s32 taps2 = taps + 1;
        f32 weight = 1.0f / static_cast<f32>(taps);
        f32 weight2 = 1.0f / static_cast<f32>(taps2);
        for (s32 dir = 0; dir < 3; dir++) {
            f32 angle = static_cast<f32>(dir) * 120.0f * 3.14159274f / 180.0f + arg0;
            f32 s = sinf(angle);
            f32 c = cosf(angle);
            f32 dx = scaleX * (c * 0.0f - s);
            f32 dy = scaleY * (s * 0.0f + c);
            for (s32 i = 0; i < taps; i++) {
                f32 k = static_cast<f32>(i) + 1.0f;
                values[i] = Unk_Float4(dx * k, dy * k, 0.0f, 0.0f);
                colors[i] = Unk_Float4(weight, weight, weight, weight);
            }
            CRenderTexture* temp = list[3];
            result = temp->Unk_49d250(0, 0, 1, 0, 0);
            if (result < 0) {
                return result;
            }
            if (coc != nullptr) {
                DrawRectGPU_MadCocT2_Sn(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, taps, values, colors, range,
                                        Unk_GetTexture(source), Unk_GetTexture(coc), 0, 0);
            } else {
                DrawRectGPU_MadT1_Sn(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, taps, values, colors,
                                     Unk_GetTexture(source), 0, 0);
            }
            angle = angle - 120.0f * 3.14159274f / 180.0f;
            s = sinf(angle);
            c = cosf(angle);
            dx = scaleX * (c * 0.0f - s);
            dy = scaleY * (s * 0.0f + c);
            for (s32 i = 0; i < taps2; i++) {
                f32 k = static_cast<f32>(i);
                values[i] = Unk_Float4(dx * k, dy * k, 0.0f, 0.0f);
                colors[i] = Unk_Float4(weight2, weight2, weight2, weight2);
            }
            CRenderTexture* out = list[dir];
            result = out->Unk_49d250(0, 0, 1, 0, 0);
            if (result < 0) {
                return result;
            }
            if (coc != nullptr) {
                DrawRectGPU_MadCocT2_Sn(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, taps2, values, colors, range,
                                        Unk_GetTexture(temp), Unk_GetTexture(coc), 0, 0);
            } else {
                DrawRectGPU_MadT1_Sn(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, taps2, values, colors,
                                     Unk_GetTexture(temp), 0, 0);
            }
        }
        f32 k = 1.0f / static_cast<f32>(taps2 * taps);
        f32 total = 1.0f / (k + 3.0f);
        Unk_Float4 weights[4];
        for (s32 c = 0; c < 4; c++) {
            weights[0].field_0[c].field_0 = total * (k * color->field_0[c].field_0);
        }
        for (s32 i = 1; i < 4; i++) {
            for (s32 c = 0; c < 4; c++) {
                weights[i].field_0[c].field_0 = total * color->field_0[c].field_0;
            }
        }
        CRenderTexture* sources[4] = {source, list[0], list[1], list[2]};
        for (s32 i = 0; i < 4; i++) {
            Unk_GetTexture(sources[i])->vf17(1);
        }
        result = Unk_48d220(1.0f, 1.0f, target, 4, sources, weights, arg7, false);
    } else {
        result = -3;
    }
    Unk_GetTexture(source)->vf15(sourceFilter);
    Unk_GetTexture(target)->vf15(targetFilter);
    for (s32 i = 0; i < 4; i++) {
        if (list[i] != nullptr) {
            Unk_GetTexture(list[i])->vf15(filters[i]);
        }
    }
    return result;
}

// What the render textures share (GPURenderTexture.cpp): the targets in use
// and their levels, and the context
extern CRenderTexture* Unk_24e53a0[8];
extern u32 Unk_238d228[8];
extern void* Unk_24e53e0;

// IGPUDevice's slot 24 as 0x710048d7f0 calls it (with an argument; the
// base class's placeholder in GPUInterfaceDevice.h takes none)
struct Unk_48d7f0_Device {
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
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24(s32 arg);
};

// `target` (and `depth`) as the device's targets
static inline s32 Unk_SetTarget(CRenderTexture* target, Unk_49b230_Object* depth) {
    CRenderTexture* targets[8];
    targets[0] = target;
    for (s32 i = 1; i < 8; i++)
        targets[i] = nullptr;
    return Unk_49da70(8, targets, depth, nullptr, 0, nullptr, 0, 0, 0, 1.0f);
}

// 0x710048d7f0: the technique field_30.field_22750 of field_29aa0[1] into
// each of `count` surfaces, with one row of a channel matrix each (the
// luminance weights for one surface, then luminance and alpha, rgb, rgba)
s32 CTextureUtil::Unk_48d7f0(Unk_GPUTexture* texture, Unk_49b230_Object** objects, s32 count, void* arg4) {
    s32 result = Unk_SetTarget(field_29a98, reinterpret_cast<Unk_49b230_Object*>(field_29aa0[0]));
    if (result < 0)
        return result;
    Unk_Float4 luminance(0.29891f, 0.58661f, 0.11448f, 0.0f);
    const Unk_Float4* weights = static_cast<const Unk_Float4*>(arg4);
    if (weights == nullptr)
        weights = &luminance;
    Unk_Float4 matrices[4][4];
    matrices[0][0] = Unk_Float4(weights->field_0[0], weights->field_0[1], weights->field_0[2], weights->field_0[3]);
    matrices[1][0] = Unk_Float4(weights->field_0[0], weights->field_0[1], weights->field_0[2], weights->field_0[3]);
    matrices[1][1] = Unk_Float4(0.0f, 0.0f, 0.0f, 1.0f);
    matrices[2][0] = Unk_Float4(1.0f, 0.0f, 0.0f, 0.0f);
    matrices[2][1] = Unk_Float4(0.0f, 1.0f, 0.0f, 0.0f);
    matrices[2][2] = Unk_Float4(0.0f, 0.0f, 1.0f, 0.0f);
    matrices[3][0] = Unk_Float4(1.0f, 0.0f, 0.0f, 0.0f);
    matrices[3][1] = Unk_Float4(0.0f, 1.0f, 0.0f, 0.0f);
    matrices[3][2] = Unk_Float4(0.0f, 0.0f, 1.0f, 0.0f);
    matrices[3][3] = Unk_Float4(0.0f, 0.0f, 0.0f, 1.0f);
    result = 0;
    for (s32 i = 0; i < count; i++) {
        Unk_49b230_Object* object = objects[i];
        s32 status = object->vf9();
        if (status < 0)
            result = status;
        field_30.field_0->vf29(field_30.field_22750);
        field_30.field_0->vf26(field_30.field_10[0], texture);
        Unk_GPUTexture* source = reinterpret_cast<Unk_GPUTexture*>(field_29aa0[1]);
        field_30.field_0->vf26(field_30.field_10[1], source);
        field_30.field_0->vf22(field_30.field_d0, &matrices[count - 1][i], 1);
        reinterpret_cast<Unk_GPUTexture*>(field_29aa0[1])->vf17(1);
        status = Unk_471f60(0.0f, 0.0f, static_cast<f32>(source->field_4c), static_cast<f32>(source->field_50), 0.0f,
                            0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0);
        reinterpret_cast<Unk_GPUTexture*>(field_29aa0[1])->vf17(0);
        if (status < 0)
            result = status;
        status = object->vf10();
        if (status < 0)
            result = status;
    }
    reinterpret_cast<Unk_48d7f0_Device*>(field_20)->vf24(0);
    memset(Unk_24e53a0, 0, sizeof(Unk_24e53a0));
    memset(Unk_238d228, 0, sizeof(Unk_238d228));
    Unk_24e53e0 = nullptr;
    return result < 0 ? result : 0;
}

// 0x7100412170 (Unk_415f40.cpp): the offsets (and weights) of four bilinear taps
void Unk_412170(u32 width, u32 height, Unk_Float4* offsets, Unk_Float4* weights, f32 scale);

// the modes that write RGB from another encoding (inline)
static inline bool Unk_IsFastMode(s32 mode) {
    switch (mode) {
    case 2:
    case 5:
    case 8:
    case 11:
    case 14:
        return true;
    default:
        return false;
    }
}
// (a bit mask, not a switch: the original tests it as `lsr` of 0x109209
// between the other two sets' bit tests, which a switch would merge with)
static inline bool Unk_IsFromRGBMode(s32 mode) {
    const u32 modes = 1u << 0 | 1u << 3 | 1u << 9 | 1u << 12 | 1u << 15 | 1u << 20;
    return static_cast<u32>(mode) <= 20 && (modes >> mode & 1) != 0;
}
static inline bool Unk_IsRGBALumMode(s32 mode) {
    switch (mode) {
    case 13:
    case 14:
    case 20:
        return true;
    default:
        return false;
    }
}

// the larger of two values (inline)
static inline const Unk_Float& Unk_Max(const Unk_Float& a, const Unk_Float& b) {
    return a.field_0 > b.field_0 ? a : b;
}

// 0x7100493f30 (`amount` clamped by an if on Unk_Float objects: the
// original's integer select)
s32 CTextureUtil::Unk_493f30(f32 scale, Unk_Float amount, CRenderTexture* source, CRenderTexture* target, s32 mode,
                             const Unk_Float4* color, bool clear, bool arg7, s32 arg8, s32 arg9) {
    if (field_20 == nullptr)
        return -1;
    Unk_Float sigma;
    if (amount.field_0 > 0.5f) {
        sigma = amount;
    } else {
        sigma = 0.5f;
    }
    if (!arg7 && (Unk_IsFastMode(mode) || Unk_IsFromRGBMode(mode) || Unk_IsRGBALumMode(mode)) && (Unk_GetTexture(source)->field_5c & 0x20000)) {
        Unk_BeginFilter(clear, arg7);
        u32 sourceWidth = arg8 != 0 ? arg8 : source->field_54;
        u32 sourceHeight = arg9 != 0 ? arg9 : source->field_58;
        f32 u1 = source->field_88 * static_cast<f32>(sourceWidth) + source->field_90;
        f32 v1 = source->field_8c * static_cast<f32>(sourceHeight) + source->field_94;
        f32 width = static_cast<f32>(static_cast<u32>(arg8 != 0 ? arg8 : target->field_54));
        f32 height = static_cast<f32>(static_cast<u32>(arg9 != 0 ? arg9 : target->field_58));
        Unk_Float4 offsets[4];
        Unk_412170(source->field_80->field_8, source->field_80->field_c, offsets, nullptr, sigma.field_0);
        f32 weight = scale * 0.25f;
        Unk_Float4 colors[4];
        for (s32 i = 0; i < 4; i++) {
            colors[i] = Unk_Float4(weight * color->field_0[0].field_0, weight * color->field_0[1].field_0,
                                   weight * color->field_0[2].field_0, weight * color->field_0[3].field_0);
        }
        s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
        if (result < 0)
            return result;
        CRenderTexture::Unk_49cf50(nullptr, nullptr);
        result = DrawRectGPU_MadT1_Sn(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, 4, offsets, colors,
                                      Unk_GetTexture(source), mode, 0);
        return result < 0 ? result : 0;
    }
    f32 k = (1.0f - sigma.field_0 * 0.5f) / (sigma.field_0 * 0.5f);
    f32 weights[9] = {1.0f, k * 2.0f, 1.0f, k * 2.0f, k * (k * 4.0f), k * 2.0f, 1.0f, k * 2.0f, 1.0f};
    Unk_Float4 value(color->field_0[0].field_0 * scale, color->field_0[1].field_0 * scale,
                     color->field_0[2].field_0 * scale, color->field_0[3].field_0 * scale);
    return Unk_4930d0(source, target, weights, 1, mode, &value, clear, arg7, arg8, arg9);
}

// 0x71004121e0 (Unk_415f40.cpp): a Gaussian's weights (divided by sigma *
// sqrt(2 pi) if `normalize`)
void Unk_4121e0(s32 count, f32* weights, bool normalize, f32 sigma);
// 0x71004146f0 (Unk_415f40.cpp): thirty-one taps of a 1-D Gaussian of `sigma`,
// two samples to a tap
void Unk_4146f0(u32 count, f32* offsets, f32* weights, bool normalize, f32 sigma, f32 x);

// 0x7100413b10 (Unk_415f40.cpp): a 3-tap Gaussian as two bilinear samples
void Unk_413b10(u32 count, f32* offsets, f32* weights, bool normalize, f32 sigma, f32 x);
// 0x7100414af0 (Unk_415f40.cpp): three samples of a Gaussian at 0 and +-1 / `count`
void Unk_414af0(u32 count, f32* offsets, f32* weights, bool normalize, f32 sigma, f32 x);

// 0x7100494270: Unk_496b40 with three taps (`threshold`, -2, isn't read):
// `source` blurred across into `target`, then down into `temp`, by a
// Gaussian of `sigma`'s absolute values (one kernel, or one a channel), the
// second pass with `color`; three point samples, or two bilinear ones
// NON_MATCHING: a draft (72 bytes longer): the blocks and calls are the
// original's; registers, spills and the colour loops' tail merging differ.
s32 CTextureUtil::Unk_494270(f32 scale, f32 threshold, CRenderTexture* source, CRenderTexture* target,
                             CRenderTexture* temp, const Unk_Float4* sigma, s32 mode, const Unk_Float4* color,
                             bool normalize, bool clear, bool arg10, s32 width, s32 height) {
    if (field_20 == nullptr)
        return -1;
    f32 x = sigma->field_0[0].field_0 > 0.0f ? sigma->field_0[0].field_0 : -sigma->field_0[0].field_0;
    f32 y = sigma->field_0[1].field_0 > 0.0f ? sigma->field_0[1].field_0 : -sigma->field_0[1].field_0;
    f32 z = sigma->field_0[2].field_0 > 0.0f ? sigma->field_0[2].field_0 : -sigma->field_0[2].field_0;
    f32 w = sigma->field_0[3].field_0 > 0.0f ? sigma->field_0[3].field_0 : -sigma->field_0[3].field_0;
    f32 sigmas[4] = {x, y, z, w};
    bool same;
    f32 maximum;
    if (x == y && y == z && z == w) {
        same = true;
        maximum = x;
    } else {
        same = false;
        if (!(sigma->field_0[0].field_0 < 0.0f))
            arg10 = true;
        maximum = x;
        for (s32 i = 1; i < 4; i++) {
            if (sigmas[i] > maximum) {
                maximum = sigmas[i];
            }
        }
    }
    bool white = color->field_0[0].field_0 == 1.0f && color->field_0[1].field_0 == 1.0f &&
                 color->field_0[2].field_0 == 1.0f && color->field_0[3].field_0 == 1.0f;
    bool separate = !white || !same;
    Unk_BeginFilter(clear, arg10);
    bool large;
    if (!arg10 && (Unk_IsFastMode(mode) || Unk_IsFromRGBMode(mode) || Unk_IsRGBALumMode(mode)) &&
        (Unk_GetTexture(source)->field_5c & 0x20000) && (Unk_GetTexture(target)->field_5c & 0x20000))
        large = false;
    else
        large = true;
    u32 count = large ? 3 : 2;
    Unk_GetTexture(source)->vf17(large);
    Unk_GetTexture(target)->vf17(large);
    u32 sourceWidth = width != 0 ? width : source->field_54;
    u32 sourceHeight = height != 0 ? height : source->field_58;
    f32 scaleX = source->field_88;
    f32 scaleY = source->field_8c;
    f32 offsetX = source->field_90;
    f32 offsetY = source->field_94;
    u32 targetWidth = width != 0 ? width : target->field_54;
    u32 targetHeight = height != 0 ? height : target->field_58;
    u32 size = source->field_80->field_8;
    f32 offsets[3];
    f32 weights[4][3];
    if (large) {
        if (same) {
            Unk_414af0(size, offsets, weights[0], normalize, maximum, 1.0f);
        } else {
            for (s32 i = 0; i < 4; i++) {
                Unk_414af0(size, offsets, weights[i], normalize, sigmas[i], 1.0f);
            }
        }
    } else {
        if (same) {
            Unk_413b10(size, offsets, weights[0], normalize, maximum, 1.0f);
        } else {
            f32 channels[4][2];
            for (s32 i = 0; i < 4; i++) {
                Unk_413b10(size, channels[i], weights[i], normalize, sigmas[i], 1.0f);
            }
            for (u32 i = 0; i < count; i++) {
                f32 sum = 0.0f;
                for (s32 c = 0; c < 4; c++) {
                    sum += channels[c][i];
                }
                offsets[i] = sum * 0.25f;
            }
        }
    }
    f32 norm = sqrtf(scale);
    Unk_Float4 values[3];
    Unk_Float4 colors[3];
    bool zero = true;
    for (u32 i = 0; i < count; i++) {
        if (!separate) {
            f32 weight = norm * weights[0][i];
            colors[i] = Unk_Float4(weight, weight, weight, weight);
        } else if (same) {
            f32 weight = norm * weights[0][i];
            colors[i] = Unk_Float4(weight, weight, weight, weight);
        } else {
            for (s32 c = 0; c < 4; c++) {
                colors[i].field_0[c].field_0 = norm * weights[c][i];
            }
        }
        values[i] = Unk_Float4(offsets[i], 0.0f, 0.0f, 0.0f);
        if (i != 0) {
            bool none = colors[i].field_0[0].field_0 == 0.0f && colors[i].field_0[1].field_0 == 0.0f &&
                        colors[i].field_0[2].field_0 == 0.0f && colors[i].field_0[3].field_0 == 0.0f;
            zero = none && zero;
        }
    }
    if (zero)
        count = 1;
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0)
        return result;
    f32 u1 = scaleX * static_cast<f32>(sourceWidth) + offsetX;
    f32 v1 = scaleY * static_cast<f32>(sourceHeight) + offsetY;
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    result = DrawRectGPU_MadT1_Sn(0.0f, 0.0f, static_cast<f32>(targetWidth), static_cast<f32>(targetHeight), 0.0f,
                                  0.0f, u1, v1, count, values, colors, Unk_GetTexture(source), mode, 0);
    if (result < 0)
        return result;
    u32 width2 = width != 0 ? width : target->field_54;
    u32 height2 = height != 0 ? height : target->field_58;
    f32 targetScaleX = target->field_88;
    f32 targetScaleY = target->field_8c;
    f32 targetOffsetX = target->field_90;
    f32 targetOffsetY = target->field_94;
    u32 tempWidth = width != 0 ? width : temp->field_54;
    u32 tempHeight = height != 0 ? height : temp->field_58;
    size = target->field_80->field_c;
    if (large) {
        if (same) {
            Unk_414af0(size, offsets, weights[0], normalize, maximum, 1.0f);
        } else {
            for (s32 i = 0; i < 4; i++) {
                Unk_414af0(size, offsets, weights[i], normalize, sigmas[i], 1.0f);
            }
        }
    } else {
        if (same) {
            Unk_413b10(size, offsets, weights[0], normalize, maximum, 1.0f);
        } else {
            f32 channels[4][2];
            for (s32 i = 0; i < 4; i++) {
                Unk_413b10(size, channels[i], weights[i], normalize, sigmas[i], 1.0f);
            }
            for (u32 i = 0; i < count; i++) {
                f32 sum = 0.0f;
                for (s32 c = 0; c < 4; c++) {
                    sum += channels[c][i];
                }
                offsets[i] = sum * 0.25f;
            }
        }
    }
    for (u32 i = 0; i < count; i++) {
        if (!separate) {
            f32 weight = norm * weights[0][i];
            colors[i] = Unk_Float4(weight * color->field_0[0].field_0, weight * color->field_0[1].field_0,
                                   weight * color->field_0[2].field_0, weight * color->field_0[3].field_0);
        } else if (same) {
            f32 weight = norm * weights[0][i];
            colors[i] = Unk_Float4(weight * color->field_0[0].field_0, weight * color->field_0[1].field_0,
                                   weight * color->field_0[2].field_0, weight * color->field_0[3].field_0);
        } else {
            for (s32 c = 0; c < 4; c++) {
                colors[i].field_0[c].field_0 = norm * (color->field_0[c].field_0 * weights[c][i]);
            }
        }
        values[i] = Unk_Float4(0.0f, offsets[i], 0.0f, 0.0f);
    }
    result = temp->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0)
        return result;
    u1 = targetScaleX * static_cast<f32>(width2) + targetOffsetX;
    v1 = targetScaleY * static_cast<f32>(height2) + targetOffsetY;
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    result = DrawRectGPU_MadT1_Sn(0.0f, 0.0f, static_cast<f32>(tempWidth), static_cast<f32>(tempHeight), 0.0f, 0.0f,
                                  u1, v1, count, values, colors, Unk_GetTexture(target), mode, 0);
    if (result < 0)
        return result;
    Unk_GetTexture(source)->vf17(0);
    Unk_GetTexture(target)->vf17(0);
    return 0;
}

// 0x7100413c60 (Unk_415f40.cpp): a 7-tap Gaussian as four bilinear samples
void Unk_413c60(u32 count, f32* offsets, f32* weights, bool normalize, f32 sigma, f32 x);
// 0x7100414be0 (Unk_415f40.cpp): seven samples of a Gaussian at 0 and +-1 .. +-3 / `count`
void Unk_414be0(u32 count, f32* offsets, f32* weights, bool normalize, f32 sigma, f32 x);

// 0x7100495040: 0x7100494270 with seven taps (`threshold` is -4): seven point samples, or
// four bilinear ones
// NON_MATCHING: a draft (as 0x7100494270's; same size within 8 bytes).
s32 CTextureUtil::Unk_495040(f32 scale, f32 threshold, CRenderTexture* source, CRenderTexture* target,
                             CRenderTexture* temp, const Unk_Float4* sigma, s32 mode, const Unk_Float4* color,
                             bool normalize, bool clear, bool arg10, s32 width, s32 height) {
    if (field_20 == nullptr)
        return -1;
    f32 x = sigma->field_0[0].field_0 > 0.0f ? sigma->field_0[0].field_0 : -sigma->field_0[0].field_0;
    f32 y = sigma->field_0[1].field_0 > 0.0f ? sigma->field_0[1].field_0 : -sigma->field_0[1].field_0;
    f32 z = sigma->field_0[2].field_0 > 0.0f ? sigma->field_0[2].field_0 : -sigma->field_0[2].field_0;
    f32 w = sigma->field_0[3].field_0 > 0.0f ? sigma->field_0[3].field_0 : -sigma->field_0[3].field_0;
    f32 sigmas[4] = {x, y, z, w};
    bool same;
    f32 maximum;
    if (x == y && y == z && z == w) {
        same = true;
        maximum = x;
    } else {
        same = false;
        if (!(sigma->field_0[0].field_0 < 0.0f))
            arg10 = true;
        maximum = x;
        for (s32 i = 1; i < 4; i++) {
            if (sigmas[i] > maximum) {
                maximum = sigmas[i];
            }
        }
    }
    bool white = color->field_0[0].field_0 == 1.0f && color->field_0[1].field_0 == 1.0f &&
                 color->field_0[2].field_0 == 1.0f && color->field_0[3].field_0 == 1.0f;
    bool separate = !white || !same;
    Unk_BeginFilter(clear, arg10);
    bool large;
    if (!arg10 && (Unk_IsFastMode(mode) || Unk_IsFromRGBMode(mode) || Unk_IsRGBALumMode(mode)) &&
        (Unk_GetTexture(source)->field_5c & 0x20000) && (Unk_GetTexture(target)->field_5c & 0x20000))
        large = false;
    else
        large = true;
    u32 count = large ? 7 : 4;
    Unk_GetTexture(source)->vf17(large);
    Unk_GetTexture(target)->vf17(large);
    u32 sourceWidth = width != 0 ? width : source->field_54;
    u32 sourceHeight = height != 0 ? height : source->field_58;
    f32 scaleX = source->field_88;
    f32 scaleY = source->field_8c;
    f32 offsetX = source->field_90;
    f32 offsetY = source->field_94;
    u32 targetWidth = width != 0 ? width : target->field_54;
    u32 targetHeight = height != 0 ? height : target->field_58;
    u32 size = source->field_80->field_8;
    f32 offsets[7];
    f32 weights[4][7];
    if (large) {
        if (same) {
            Unk_414be0(size, offsets, weights[0], normalize, maximum, 1.0f);
        } else {
            for (s32 i = 0; i < 4; i++) {
                Unk_414be0(size, offsets, weights[i], normalize, sigmas[i], 1.0f);
            }
        }
    } else {
        if (same) {
            Unk_413c60(size, offsets, weights[0], normalize, maximum, 1.0f);
        } else {
            f32 channels[4][4];
            for (s32 i = 0; i < 4; i++) {
                Unk_413c60(size, channels[i], weights[i], normalize, sigmas[i], 1.0f);
            }
            for (u32 i = 0; i < count; i++) {
                f32 sum = 0.0f;
                for (s32 c = 0; c < 4; c++) {
                    sum += channels[c][i];
                }
                offsets[i] = sum * 0.25f;
            }
        }
    }
    f32 norm = sqrtf(scale);
    Unk_Float4 values[7];
    Unk_Float4 colors[7];
    for (u32 i = 0; i < count; i++) {
        if (!separate) {
            f32 weight = norm * weights[0][i];
            colors[i] = Unk_Float4(weight, weight, weight, weight);
        } else if (same) {
            f32 weight = norm * weights[0][i];
            colors[i] = Unk_Float4(weight, weight, weight, weight);
        } else {
            for (s32 c = 0; c < 4; c++) {
                colors[i].field_0[c].field_0 = norm * weights[c][i];
            }
        }
        values[i] = Unk_Float4(offsets[i], 0.0f, 0.0f, 0.0f);
    }
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0)
        return result;
    f32 u1 = scaleX * static_cast<f32>(sourceWidth) + offsetX;
    f32 v1 = scaleY * static_cast<f32>(sourceHeight) + offsetY;
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    result = DrawRectGPU_MadT1_Sn(0.0f, 0.0f, static_cast<f32>(targetWidth), static_cast<f32>(targetHeight), 0.0f,
                                  0.0f, u1, v1, count, values, colors, Unk_GetTexture(source), mode, 0);
    if (result < 0)
        return result;
    u32 width2 = width != 0 ? width : target->field_54;
    u32 height2 = height != 0 ? height : target->field_58;
    f32 targetScaleX = target->field_88;
    f32 targetScaleY = target->field_8c;
    f32 targetOffsetX = target->field_90;
    f32 targetOffsetY = target->field_94;
    u32 tempWidth = width != 0 ? width : temp->field_54;
    u32 tempHeight = height != 0 ? height : temp->field_58;
    size = target->field_80->field_c;
    if (large) {
        if (same) {
            Unk_414be0(size, offsets, weights[0], normalize, maximum, 1.0f);
        } else {
            for (s32 i = 0; i < 4; i++) {
                Unk_414be0(size, offsets, weights[i], normalize, sigmas[i], 1.0f);
            }
        }
    } else {
        if (same) {
            Unk_413c60(size, offsets, weights[0], normalize, maximum, 1.0f);
        } else {
            f32 channels[4][4];
            for (s32 i = 0; i < 4; i++) {
                Unk_413c60(size, channels[i], weights[i], normalize, sigmas[i], 1.0f);
            }
            for (u32 i = 0; i < count; i++) {
                f32 sum = 0.0f;
                for (s32 c = 0; c < 4; c++) {
                    sum += channels[c][i];
                }
                offsets[i] = sum * 0.25f;
            }
        }
    }
    for (u32 i = 0; i < count; i++) {
        if (!separate) {
            f32 weight = norm * weights[0][i];
            colors[i] = Unk_Float4(weight * color->field_0[0].field_0, weight * color->field_0[1].field_0,
                                   weight * color->field_0[2].field_0, weight * color->field_0[3].field_0);
        } else if (same) {
            f32 weight = norm * weights[0][i];
            colors[i] = Unk_Float4(weight * color->field_0[0].field_0, weight * color->field_0[1].field_0,
                                   weight * color->field_0[2].field_0, weight * color->field_0[3].field_0);
        } else {
            for (s32 c = 0; c < 4; c++) {
                colors[i].field_0[c].field_0 = norm * (color->field_0[c].field_0 * weights[c][i]);
            }
        }
        values[i] = Unk_Float4(0.0f, offsets[i], 0.0f, 0.0f);
    }
    result = temp->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0)
        return result;
    u1 = targetScaleX * static_cast<f32>(width2) + targetOffsetX;
    v1 = targetScaleY * static_cast<f32>(height2) + targetOffsetY;
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    result = DrawRectGPU_MadT1_Sn(0.0f, 0.0f, static_cast<f32>(tempWidth), static_cast<f32>(tempHeight), 0.0f, 0.0f,
                                  u1, v1, count, values, colors, Unk_GetTexture(target), mode, 0);
    if (result < 0)
        return result;
    Unk_GetTexture(source)->vf17(0);
    Unk_GetTexture(target)->vf17(0);
    return 0;
}

// 0x7100413ea0 (Unk_415f40.cpp): an 11-tap Gaussian as six bilinear samples
void Unk_413ea0(u32 count, f32* offsets, f32* weights, bool normalize, f32 sigma, f32 x);
// 0x7100414db0 (Unk_415f40.cpp): eleven samples of a Gaussian at 0 and +-1 .. +-5 / `count`
void Unk_414db0(u32 count, f32* offsets, f32* weights, bool normalize, f32 sigma, f32 x);

// 0x7100496020: 0x7100494270 with eleven taps (`threshold` is -6): eleven point samples, or
// six bilinear ones
// NON_MATCHING: a draft (as 0x7100494270's; 36 bytes shorter).
s32 CTextureUtil::Unk_496020(f32 scale, f32 threshold, CRenderTexture* source, CRenderTexture* target,
                             CRenderTexture* temp, const Unk_Float4* sigma, s32 mode, const Unk_Float4* color,
                             bool normalize, bool clear, bool arg10, s32 width, s32 height) {
    if (field_20 == nullptr)
        return -1;
    f32 x = sigma->field_0[0].field_0 > 0.0f ? sigma->field_0[0].field_0 : -sigma->field_0[0].field_0;
    f32 y = sigma->field_0[1].field_0 > 0.0f ? sigma->field_0[1].field_0 : -sigma->field_0[1].field_0;
    f32 z = sigma->field_0[2].field_0 > 0.0f ? sigma->field_0[2].field_0 : -sigma->field_0[2].field_0;
    f32 w = sigma->field_0[3].field_0 > 0.0f ? sigma->field_0[3].field_0 : -sigma->field_0[3].field_0;
    f32 sigmas[4] = {x, y, z, w};
    bool same;
    f32 maximum;
    if (x == y && y == z && z == w) {
        same = true;
        maximum = x;
    } else {
        same = false;
        if (!(sigma->field_0[0].field_0 < 0.0f))
            arg10 = true;
        maximum = x;
        for (s32 i = 1; i < 4; i++) {
            if (sigmas[i] > maximum) {
                maximum = sigmas[i];
            }
        }
    }
    bool white = color->field_0[0].field_0 == 1.0f && color->field_0[1].field_0 == 1.0f &&
                 color->field_0[2].field_0 == 1.0f && color->field_0[3].field_0 == 1.0f;
    bool separate = !white || !same;
    Unk_BeginFilter(clear, arg10);
    bool large;
    if (!arg10 && (Unk_IsFastMode(mode) || Unk_IsFromRGBMode(mode) || Unk_IsRGBALumMode(mode)) &&
        (Unk_GetTexture(source)->field_5c & 0x20000) && (Unk_GetTexture(target)->field_5c & 0x20000))
        large = false;
    else
        large = true;
    u32 count = large ? 11 : 6;
    Unk_GetTexture(source)->vf17(large);
    Unk_GetTexture(target)->vf17(large);
    u32 sourceWidth = width != 0 ? width : source->field_54;
    u32 sourceHeight = height != 0 ? height : source->field_58;
    f32 scaleX = source->field_88;
    f32 scaleY = source->field_8c;
    f32 offsetX = source->field_90;
    f32 offsetY = source->field_94;
    u32 targetWidth = width != 0 ? width : target->field_54;
    u32 targetHeight = height != 0 ? height : target->field_58;
    u32 size = source->field_80->field_8;
    f32 offsets[11];
    f32 weights[4][11];
    if (large) {
        if (same) {
            Unk_414db0(size, offsets, weights[0], normalize, maximum, 1.0f);
        } else {
            for (s32 i = 0; i < 4; i++) {
                Unk_414db0(size, offsets, weights[i], normalize, sigmas[i], 1.0f);
            }
        }
    } else {
        if (same) {
            Unk_413ea0(size, offsets, weights[0], normalize, maximum, 1.0f);
        } else {
            f32 channels[4][6];
            for (s32 i = 0; i < 4; i++) {
                Unk_413ea0(size, channels[i], weights[i], normalize, sigmas[i], 1.0f);
            }
            for (u32 i = 0; i < count; i++) {
                f32 sum = 0.0f;
                for (s32 c = 0; c < 4; c++) {
                    sum += channels[c][i];
                }
                offsets[i] = sum * 0.25f;
            }
        }
    }
    f32 norm = sqrtf(scale);
    Unk_Float4 values[11];
    Unk_Float4 colors[11];
    for (u32 i = 0; i < count; i++) {
        if (!separate) {
            f32 weight = norm * weights[0][i];
            colors[i] = Unk_Float4(weight, weight, weight, weight);
        } else if (same) {
            f32 weight = norm * weights[0][i];
            colors[i] = Unk_Float4(weight, weight, weight, weight);
        } else {
            for (s32 c = 0; c < 4; c++) {
                colors[i].field_0[c].field_0 = norm * weights[c][i];
            }
        }
        values[i] = Unk_Float4(offsets[i], 0.0f, 0.0f, 0.0f);
    }
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0)
        return result;
    f32 u1 = scaleX * static_cast<f32>(sourceWidth) + offsetX;
    f32 v1 = scaleY * static_cast<f32>(sourceHeight) + offsetY;
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    result = DrawRectGPU_MadT1_Sn(0.0f, 0.0f, static_cast<f32>(targetWidth), static_cast<f32>(targetHeight), 0.0f,
                                  0.0f, u1, v1, count, values, colors, Unk_GetTexture(source), mode, 0);
    if (result < 0)
        return result;
    u32 width2 = width != 0 ? width : target->field_54;
    u32 height2 = height != 0 ? height : target->field_58;
    f32 targetScaleX = target->field_88;
    f32 targetScaleY = target->field_8c;
    f32 targetOffsetX = target->field_90;
    f32 targetOffsetY = target->field_94;
    u32 tempWidth = width != 0 ? width : temp->field_54;
    u32 tempHeight = height != 0 ? height : temp->field_58;
    size = target->field_80->field_c;
    if (large) {
        if (same) {
            Unk_414db0(size, offsets, weights[0], normalize, maximum, 1.0f);
        } else {
            for (s32 i = 0; i < 4; i++) {
                Unk_414db0(size, offsets, weights[i], normalize, sigmas[i], 1.0f);
            }
        }
    } else {
        if (same) {
            Unk_413ea0(size, offsets, weights[0], normalize, maximum, 1.0f);
        } else {
            f32 channels[4][6];
            for (s32 i = 0; i < 4; i++) {
                Unk_413ea0(size, channels[i], weights[i], normalize, sigmas[i], 1.0f);
            }
            for (u32 i = 0; i < count; i++) {
                f32 sum = 0.0f;
                for (s32 c = 0; c < 4; c++) {
                    sum += channels[c][i];
                }
                offsets[i] = sum * 0.25f;
            }
        }
    }
    for (u32 i = 0; i < count; i++) {
        if (!separate) {
            f32 weight = norm * weights[0][i];
            colors[i] = Unk_Float4(weight * color->field_0[0].field_0, weight * color->field_0[1].field_0,
                                   weight * color->field_0[2].field_0, weight * color->field_0[3].field_0);
        } else if (same) {
            f32 weight = norm * weights[0][i];
            colors[i] = Unk_Float4(weight * color->field_0[0].field_0, weight * color->field_0[1].field_0,
                                   weight * color->field_0[2].field_0, weight * color->field_0[3].field_0);
        } else {
            for (s32 c = 0; c < 4; c++) {
                colors[i].field_0[c].field_0 = norm * (color->field_0[c].field_0 * weights[c][i]);
            }
        }
        values[i] = Unk_Float4(0.0f, offsets[i], 0.0f, 0.0f);
    }
    result = temp->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0)
        return result;
    u1 = targetScaleX * static_cast<f32>(width2) + targetOffsetX;
    v1 = targetScaleY * static_cast<f32>(height2) + targetOffsetY;
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    result = DrawRectGPU_MadT1_Sn(0.0f, 0.0f, static_cast<f32>(tempWidth), static_cast<f32>(tempHeight), 0.0f, 0.0f,
                                  u1, v1, count, values, colors, Unk_GetTexture(target), mode, 0);
    if (result < 0)
        return result;
    Unk_GetTexture(source)->vf17(0);
    Unk_GetTexture(target)->vf17(0);
    return 0;
}

// 0x71004141e0 (Unk_415f40.cpp): fifteen samples of a Gaussian, two taps to a sample
void Unk_4141e0(u32 count, f32* offsets, f32* weights, bool normalize, f32 sigma, f32 x);
// 0x7100415030 (Unk_415f40.cpp): fifteen samples of a Gaussian at 0 and +-1 .. +-7 / `count`
void Unk_415030(u32 count, f32* offsets, f32* weights, bool normalize, f32 sigma, f32 x);

// 0x7100496b40: `source` blurred across into `target`, then down into
// `temp`, by a Gaussian of `sigma`'s absolute values (one kernel, or one a
// channel) of up to fifteen taps (from `threshold`: the smallest that covers
// all but it at each end, or minus it when it isn't positive; point samples,
// or bilinear pairs when the textures allow), the second pass with `color`
// (a grey one goes into `scale`). Two, four and six taps go to 0x7100494270,
// 0x7100495040 and 0x7100496020 (two to 0x7100486a80 in one pass when
// `source` isn't drawn from `temp`).
// NON_MATCHING: a draft (52 bytes shorter): the original reloads the
// absolute sigmas and keeps `sigma`'s x from the entry, copies the colour in
// each branch of the grey test and saves one register less.
s32 CTextureUtil::Unk_496b40(f32 scale, f32 threshold, CRenderTexture* source, CRenderTexture* target,
                             CRenderTexture* temp, const Unk_Float4* sigma, s32 mode, const Unk_Float4* color,
                             bool normalize, bool clear, bool arg10, s32 width, s32 height) {
    if (field_20 == nullptr)
        return -1;
    f32 x = sigma->field_0[0].field_0 > 0.0f ? sigma->field_0[0].field_0 : -sigma->field_0[0].field_0;
    f32 y = sigma->field_0[1].field_0 > 0.0f ? sigma->field_0[1].field_0 : -sigma->field_0[1].field_0;
    f32 z = sigma->field_0[2].field_0 > 0.0f ? sigma->field_0[2].field_0 : -sigma->field_0[2].field_0;
    f32 w = sigma->field_0[3].field_0 > 0.0f ? sigma->field_0[3].field_0 : -sigma->field_0[3].field_0;
    f32 sigmas[4] = {x, y, z, w};
    bool same;
    f32 maximum;
    if (x == y && y == z && z == w) {
        same = true;
        maximum = x;
    } else {
        same = false;
        if (!(sigma->field_0[0].field_0 < 0.0f))
            arg10 = true;
        maximum = x;
        for (s32 i = 1; i < 4; i++) {
            if (sigmas[i] > maximum) {
                maximum = sigmas[i];
            }
        }
    }
    Unk_Float4 colour = *color;
    bool separate;
    if (color->field_0[0].field_0 == color->field_0[1].field_0 &&
        color->field_0[1].field_0 == color->field_0[2].field_0 &&
        color->field_0[2].field_0 == color->field_0[3].field_0) {
        separate = !same;
        if (colour.field_0[0].field_0 != 1.0f) {
            scale = colour.field_0[0].field_0 * scale;
            colour = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
        }
    } else {
        separate = true;
    }
    bool large;
    if (!arg10 && (Unk_GetTexture(source)->field_5c & 0x20000) && (Unk_GetTexture(target)->field_5c & 0x20000))
        large = false;
    else
        large = true;
    s32 count;
    s32 taps;
    if (threshold <= 0.0f) {
        count = -static_cast<s32>(threshold);
        if (large)
            count = count * 2 - 1;
        taps = (count & 1) == 0 || count > 28 ? 15 : count;
    } else {
        f32 gauss[15];
        Unk_4121e0(15, gauss, true, maximum);
        count = 15;
        f32 sum = gauss[0];
        for (s32 i = 1; i < 14; i++) {
            sum += gauss[i] * 2.0f;
            if (sum > 1.0f - threshold * 2.0f && gauss[i + 1] < threshold) {
                count = i + 1;
                break;
            }
        }
        taps = large ? count * 2 - 1 : count | 1;
        taps = taps < 15 ? taps : 15;
    }
    switch (count) {
    case 2: {
        if (!arg10 && source->field_b8[source->field_a0] != temp->field_b0) {
            Unk_Float4 s = sigma->field_0[0].field_0 < 0.0f ? Unk_Float4(-sigmas[0], -sigmas[1], -sigmas[2], -sigmas[3])
                                                          : Unk_Float4(sigmas[0], sigmas[1], sigmas[2], sigmas[3]);
            return Unk_486a80(source, temp, scale, &s, mode, &colour, normalize, clear, false, width, height);
        }
        Unk_Float4 s = sigma->field_0[0].field_0 < 0.0f ? Unk_Float4(-sigmas[0], -sigmas[1], -sigmas[2], -sigmas[3])
                                                          : Unk_Float4(sigmas[0], sigmas[1], sigmas[2], sigmas[3]);
        return Unk_494270(scale, -2.0f, source, target, temp, &s, mode, &colour, normalize, clear, arg10, width,
                          height);
    }
    case 4: {
        Unk_Float4 s = sigma->field_0[0].field_0 < 0.0f ? Unk_Float4(-sigmas[0], -sigmas[1], -sigmas[2], -sigmas[3])
                                                          : Unk_Float4(sigmas[0], sigmas[1], sigmas[2], sigmas[3]);
        return Unk_495040(scale, -4.0f, source, target, temp, &s, mode, &colour, normalize, clear, arg10, width,
                          height);
    }
    case 6: {
        Unk_Float4 s = sigma->field_0[0].field_0 < 0.0f ? Unk_Float4(-sigmas[0], -sigmas[1], -sigmas[2], -sigmas[3])
                                                          : Unk_Float4(sigmas[0], sigmas[1], sigmas[2], sigmas[3]);
        return Unk_496020(scale, -6.0f, source, target, temp, &s, mode, &colour, normalize, clear, arg10, width,
                          height);
    }
    }
    Unk_BeginFilter(clear, arg10);
    Unk_GetTexture(source)->vf17(large);
    Unk_GetTexture(target)->vf17(large);
    u32 sourceWidth = width != 0 ? width : source->field_54;
    u32 sourceHeight = height != 0 ? height : source->field_58;
    f32 scaleX = source->field_88;
    f32 scaleY = source->field_8c;
    f32 offsetX = source->field_90;
    f32 offsetY = source->field_94;
    u32 targetWidth = width != 0 ? width : target->field_54;
    u32 targetHeight = height != 0 ? height : target->field_58;
    u32 size = source->field_80->field_8;
    f32 offsets[15];
    f32 weights[4][15];
    if (large) {
        if (same) {
            Unk_415030(size, offsets, weights[0], normalize, maximum, 1.0f);
        } else {
            for (s32 i = 0; i < 4; i++) {
                Unk_415030(size, offsets, weights[i], normalize, sigmas[i], 1.0f);
            }
        }
    } else {
        if (same) {
            Unk_4141e0(size, offsets, weights[0], normalize, maximum, 1.0f);
        } else {
            f32 channels[4][15];
            for (s32 i = 0; i < 4; i++) {
                Unk_4141e0(size, channels[i], weights[i], normalize, sigmas[i], 1.0f);
            }
            for (s32 i = 0; i < taps; i++) {
                f32 sum = 0.0f;
                for (s32 c = 0; c < 4; c++) {
                    sum += channels[c][i];
                }
                offsets[i] = sum * 0.25f;
            }
        }
    }
    f32 norm = sqrtf(scale);
    Unk_Float4 values[15];
    Unk_Float4 colors[15];
    f32 tapWeights[15];
    for (s32 i = 0; i < taps; i++) {
        if (separate) {
            colors[i].field_0[0].field_0 = norm * weights[0][i];
            if (same) {
                colors[i].field_0[1].field_0 = colors[i].field_0[0].field_0;
                colors[i].field_0[2].field_0 = colors[i].field_0[0].field_0;
                colors[i].field_0[3].field_0 = colors[i].field_0[0].field_0;
            } else {
                colors[i].field_0[1].field_0 = norm * weights[1][i];
                colors[i].field_0[2].field_0 = norm * weights[2][i];
                colors[i].field_0[3].field_0 = norm * weights[3][i];
            }
        } else {
            tapWeights[i] = norm * weights[0][i];
        }
        values[i] = Unk_Float4(offsets[i], 0.0f, 0.0f, 0.0f);
    }
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0)
        return result;
    f32 u1 = scaleX * static_cast<f32>(sourceWidth) + offsetX;
    f32 v1 = scaleY * static_cast<f32>(sourceHeight) + offsetY;
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    if (separate) {
        result = DrawRectGPU_MadT1_Sn(0.0f, 0.0f, static_cast<f32>(targetWidth), static_cast<f32>(targetHeight), 0.0f,
                                      0.0f, u1, v1, taps, values, colors, Unk_GetTexture(source), 0, 0);
    } else {
        result = Unk_475d80(0.0f, 0.0f, static_cast<f32>(targetWidth), static_cast<f32>(targetHeight), 0.0f, 0.0f,
                            u1, v1, taps, values, tapWeights, Unk_GetTexture(source), 0, 0);
    }
    if (result < 0)
        return result;
    u32 width2 = width != 0 ? width : target->field_54;
    u32 height2 = height != 0 ? height : target->field_58;
    f32 targetScaleX = target->field_88;
    f32 targetScaleY = target->field_8c;
    f32 targetOffsetX = target->field_90;
    f32 targetOffsetY = target->field_94;
    u32 tempWidth = width != 0 ? width : temp->field_54;
    u32 tempHeight = height != 0 ? height : temp->field_58;
    size = target->field_80->field_c;
    if (large) {
        if (same) {
            Unk_415030(size, offsets, weights[0], normalize, maximum, 1.0f);
        } else {
            for (s32 i = 0; i < 4; i++) {
                Unk_415030(size, offsets, weights[i], normalize, sigmas[i], 1.0f);
            }
        }
    } else {
        if (same) {
            Unk_4141e0(size, offsets, weights[0], normalize, maximum, 1.0f);
        } else {
            f32 channels[4][15];
            for (s32 i = 0; i < 4; i++) {
                Unk_4141e0(size, channels[i], weights[i], normalize, sigmas[i], 1.0f);
            }
            for (s32 i = 0; i < taps; i++) {
                f32 sum = 0.0f;
                for (s32 c = 0; c < 4; c++) {
                    sum += channels[c][i];
                }
                offsets[i] = sum * 0.25f;
            }
        }
    }
    for (s32 i = 0; i < taps; i++) {
        if (separate) {
            if (same) {
                f32 weight = norm * weights[0][i];
                colors[i] = Unk_Float4(weight * colour.field_0[0].field_0, weight * colour.field_0[1].field_0,
                                       weight * colour.field_0[2].field_0, weight * colour.field_0[3].field_0);
            } else {
                for (s32 c = 0; c < 4; c++) {
                    colors[i].field_0[c].field_0 = norm * (colour.field_0[c].field_0 * weights[c][i]);
                }
            }
        } else {
            tapWeights[i] = norm * weights[0][i];
        }
        values[i] = Unk_Float4(0.0f, offsets[i], 0.0f, 0.0f);
    }
    result = temp->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0)
        return result;
    u1 = targetScaleX * static_cast<f32>(width2) + targetOffsetX;
    v1 = targetScaleY * static_cast<f32>(height2) + targetOffsetY;
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    if (separate) {
        result = DrawRectGPU_MadT1_Sn(0.0f, 0.0f, static_cast<f32>(tempWidth), static_cast<f32>(tempHeight), 0.0f,
                                      0.0f, u1, v1, taps, values, colors, Unk_GetTexture(target), mode, 0);
    } else {
        result = Unk_475d80(0.0f, 0.0f, static_cast<f32>(tempWidth), static_cast<f32>(tempHeight), 0.0f, 0.0f, u1,
                            v1, taps, values, tapWeights, Unk_GetTexture(target), mode, 0);
    }
    if (result < 0)
        return result;
    Unk_GetTexture(source)->vf17(0);
    Unk_GetTexture(target)->vf17(0);
    return 0;
}

// 0x7100497b20: `source` blurred by a Gaussian of `sigma`'s absolute values;
// when they are all the same, the colour is grey and the modes allow it, in
// two 1-D passes through `target` into `temp` (the tap count from
// `threshold`: the smallest that covers all but it at each end, or minus it
// when it isn't positive), else (and for an even count under 16) by
// Unk_496b40 (`sigma` negated when its x is negative)
// NON_MATCHING: 224 bytes short (first draft): the original keeps the
// absolute sigmas in memory and has a path for unequal ones inside the
// uniform branch (dead there: it returns -4 unless x is negative, negates the
// sigmas and takes their maximum, like 0x7100486a80's), so every tap count's
// tail is duplicated; it tests the target's flag with a 32-bit load and
// allocates registers differently. The calls and the tap search are the
// original's.
s32 CTextureUtil::Unk_497b20(f32 scale, f32 threshold, CRenderTexture* source, CRenderTexture* target,
                             CRenderTexture* temp, const Unk_Float4* sigma, s32 mode, const Unk_Float4* color,
                             bool normalize, bool clear, bool arg10, s32 width, s32 height) {
    if (field_20 == nullptr)
        return -1;
    f32 x = sigma->field_0[0].field_0 > 0.0f ? sigma->field_0[0].field_0 : -sigma->field_0[0].field_0;
    f32 y = sigma->field_0[1].field_0 > 0.0f ? sigma->field_0[1].field_0 : -sigma->field_0[1].field_0;
    f32 z = sigma->field_0[2].field_0 > 0.0f ? sigma->field_0[2].field_0 : -sigma->field_0[2].field_0;
    f32 w = sigma->field_0[3].field_0 > 0.0f ? sigma->field_0[3].field_0 : -sigma->field_0[3].field_0;
    Unk_Float4 sigmas;
    sigmas.field_0[0].field_0 = x;
    sigmas.field_0[1].field_0 = y;
    sigmas.field_0[2].field_0 = z;
    sigmas.field_0[3].field_0 = w;
    bool same = x == y && y == z && z == w;
    if (color->field_0[0].field_0 == color->field_0[1].field_0 &&
        color->field_0[1].field_0 == color->field_0[2].field_0 &&
        color->field_0[2].field_0 == color->field_0[3].field_0 && same) {
        if (color->field_0[0].field_0 != 1.0f) {
            scale = color->field_0[0].field_0 * scale;
        }
        if (arg10 || !(Unk_IsFastMode(mode) || Unk_IsFromRGBMode(mode) || Unk_IsRGBALumMode(mode)) ||
            !(Unk_GetTexture(source)->field_5c & 0x20000))
            return -4;
        Unk_GPUTexture* targetTexture = Unk_GetTexture(target);
        if (mode != 0 || !(targetTexture->field_5c & 0x20000))
            return -4;
        s32 count;
        s32 taps;
        if (threshold <= 0.0f) {
            count = -static_cast<s32>(threshold);
            taps = (count & 1) == 0 || count > 60 ? 31 : count;
        } else {
            f32 gauss[31];
            Unk_4121e0(31, gauss, true, x);
            count = 31;
            f32 sum = gauss[0];
            for (s32 i = 1; i < 30; i++) {
                sum += gauss[i] * 2.0f;
                if (sum > 1.0f - threshold * 2.0f && gauss[i + 1] < threshold) {
                    count = i + 1;
                    break;
                }
            }
            taps = count | 1;
        }
        if ((count & 1) == 0 && count <= 15) {
            Unk_Float4 s = sigma->field_0[0].field_0 < 0.0f ? Unk_Float4(-x, -y, -z, -w) : sigmas;
            return Unk_496b40(scale, threshold, source, target, temp, &s, mode, color, normalize, clear, arg10, width,
                              height);
        }
        {
            Unk_BeginFilter(clear, arg10);
            Unk_GetTexture(source)->vf17(0);
            Unk_GetTexture(target)->vf17(0);
            u32 sourceWidth = width != 0 ? width : source->field_54;
            u32 sourceHeight = height != 0 ? height : source->field_58;
            f32 scaleX = source->field_88;
            f32 scaleY = source->field_8c;
            f32 offsetX = source->field_90;
            f32 offsetY = source->field_94;
            u32 targetWidth = width != 0 ? width : target->field_54;
            u32 targetHeight = height != 0 ? height : target->field_58;
            f32 offsets[31];
            f32 kernel[31];
            Unk_4146f0(source->field_80->field_8, offsets, kernel, normalize, x, 1.0f);
            f32 norm = sqrtf(scale);
            Unk_Float4 values[31];
            f32 tapWeights[31];
            for (s32 i = 0; i < taps; i++) {
                tapWeights[i] = norm * kernel[i];
                values[i] = Unk_Float4(offsets[i], 0.0f, 0.0f, 0.0f);
            }
            s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
            if (result < 0)
                return result;
            f32 u1 = scaleX * static_cast<f32>(sourceWidth) + offsetX;
            f32 v1 = scaleY * static_cast<f32>(sourceHeight) + offsetY;
            CRenderTexture::Unk_49cf50(nullptr, nullptr);
            Unk_475d80(0.0f, 0.0f, static_cast<f32>(targetWidth), static_cast<f32>(targetHeight), 0.0f, 0.0f, u1, v1,
                       taps, values, tapWeights, Unk_GetTexture(source), 0, 0);
            u32 width2 = width != 0 ? width : target->field_54;
            u32 height2 = height != 0 ? height : target->field_58;
            f32 targetScaleX = target->field_88;
            f32 targetScaleY = target->field_8c;
            f32 targetOffsetX = target->field_90;
            f32 targetOffsetY = target->field_94;
            u32 tempWidth = width != 0 ? width : temp->field_54;
            u32 tempHeight = height != 0 ? height : temp->field_58;
            Unk_4146f0(target->field_80->field_c, offsets, kernel, normalize, x, 1.0f);
            for (s32 i = 0; i < taps; i++) {
                tapWeights[i] = norm * kernel[i];
                values[i] = Unk_Float4(0.0f, offsets[i], 0.0f, 0.0f);
            }
            result = temp->Unk_49d250(0, 0, 1, 0, 0);
            if (result < 0)
                return result;
            u1 = targetScaleX * static_cast<f32>(width2) + targetOffsetX;
            v1 = targetScaleY * static_cast<f32>(height2) + targetOffsetY;
            CRenderTexture::Unk_49cf50(nullptr, nullptr);
            result = Unk_475d80(0.0f, 0.0f, static_cast<f32>(tempWidth), static_cast<f32>(tempHeight), 0.0f, 0.0f,
                                u1, v1, taps, values, tapWeights, Unk_GetTexture(target), 0, 0);
            Unk_GetTexture(source)->vf17(0);
            Unk_GetTexture(target)->vf17(0);
            return result < 0 ? result : 0;
        }
    }
    Unk_Float4 s = sigma->field_0[0].field_0 < 0.0f ? Unk_Float4(-x, -y, -z, -w) : sigmas;
    return Unk_496b40(scale, threshold, source, target, temp, &s, mode, color, normalize, clear, arg10, width,
                      height);
}

// 0x7100411b00 (Unk_415f40.cpp): the RGB to XYZ matrix of three primaries and
// a white point
MATRIXT44* Unk_411b00(MATRIXT44* out, const Unk_410f90_Point* red, const Unk_410f90_Point* green,
                      const Unk_410f90_Point* blue, const Unk_410f90_Point* white);

// the luminance weights of a colour space: Rec. 709's for the default one,
// else the Y row of its RGB to XYZ matrix (inline; as Unk_Luminance.h's)
static inline Unk_Vector3 Unk_LuminanceWeights(const Unk_410f90& space) {
    if (Unk_SameColorSpace(space, Unk_410f90_Object(0))) {
        Unk_Vector3 weights = {{0.2126f, 0.7152f, 0.0722f}};
        return weights;
    }
    MATRIXT44 m;
    Unk_411b00(&m, &space.field_0, &space.field_8, &space.field_10, &space.field_18);
    Unk_Vector3 y = {{m.field_0[0][1], m.field_0[1][1], m.field_0[2][1]}};
    return y;
}

// 0x710048dad0
// NON_MATCHING: the original moves `low` and `high` into w21/w28 at the entry
// (before the technique's call) and clamps them as integers after the
// luminance; here only one of the copies is made at the entry (the clamps
// before the call give both, but then the selects move up as well), and the
// registers and the frame (the original spills `filter0`) differ from there.
// Tried: if-forms, the clamps elsewhere, element-wise stores. As Unk_4248b0's.
s32 CTextureUtil::Unk_48dad0(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 s0, f32 t0,
                             f32 s1, f32 t1, f32 arg12, f32 arg13, Unk_Float low, Unk_Float high, f32 arg16, f32 arg17,
                             const Unk_410f90* space, const MATRIXT44* matrix, Unk_GPUTexture* texture0,
                             Unk_GPUTexture* texture1, bool filter0, bool filter1, u32 flags) {
    if (field_30.field_2072c == 0)
        return -4;
    field_30.field_0->vf29(field_30.field_2072c);
    Unk_24e4a18[0] = Unk_Float4(arg12, arg13, arg16, arg17);
    Unk_Vector3 weights = Unk_LuminanceWeights(*space);
    Unk_24e4a18[1].field_0[0].field_0 = weights.field_0[0];
    Unk_24e4a18[1].field_0[1].field_0 = weights.field_0[1];
    Unk_24e4a18[1].field_0[2].field_0 = weights.field_0[2];
    Unk_24e4a18[1].field_0[3].field_0 = 0.0f;
    Unk_Float lowLimit = low.field_0 > 1.17549435e-38f ? low : Unk_Float(1.17549435e-38f);
    Unk_Float highLimit = lowLimit.field_0 < high.field_0 ? high : lowLimit;
    Unk_24e4a18[2] = Unk_Float4(lowLimit, highLimit, 0.0f, 0.0f);
    field_30.field_0->vf22(field_30.field_d0, Unk_24e4a18, 3);
    MATRIXT44 m;
    if (matrix != nullptr) {
        m = *matrix;
    } else {
        m.field_0[0][0] = 1.0f;
        m.field_0[0][1] = 0.0f;
        m.field_0[0][2] = 0.0f;
        m.field_0[0][3] = 0.0f;
        m.field_0[1][0] = 0.0f;
        m.field_0[1][1] = 1.0f;
        m.field_0[1][2] = 0.0f;
        m.field_0[1][3] = 0.0f;
        m.field_0[2][0] = 0.0f;
        m.field_0[2][1] = 0.0f;
        m.field_0[2][2] = 1.0f;
        m.field_0[2][3] = 0.0f;
        m.field_0[3][0] = 0.0f;
        m.field_0[3][1] = 0.0f;
        m.field_0[3][2] = 0.0f;
        m.field_0[3][3] = 1.0f;
    }
    field_30.field_0->vf24(field_30.field_10c, &m);
    field_30.field_0->vf26(field_30.field_8, texture0);
    field_30.field_0->vf26(field_30.field_c, texture1);
    s32 saved0 = texture0->vf19();
    s32 saved1 = texture1->vf19();
    texture0->vf17(filter0);
    texture1->vf17(filter1);
    s32 result = Unk_471f60(x, y, width, height, u0, v0, u1, v1, s0, t0, s1, t1, flags);
    texture0->vf17(saved0);
    texture1->vf17(saved1);
    return result;
}

// 0x710048de50: 0x710048dad0 from `source` (and `other`, unless `amount` is
// 0) into the part of `target` that `x`, `y`, `width` and `height` cover,
// with the texture coordinates scaled and offset by `scale`
// NON_MATCHING: same size: the rectangle's corners are integer selects as in
// the original (Unk_Float lvalues assigned in an if/else), but they and the
// viewport's size are scheduled differently, the rectangle's fields are
// stored in another order, the scaled coordinates are scheduled differently
// and the `||` of the first test is or'ed the other way round.
s32 CTextureUtil::Unk_48de50(f32 width, f32 height, f32 x, f32 y, f32 arg4, f32 amount, f32 low, f32 high,
                             CRenderTexture* source, CRenderTexture* other, CRenderTexture* target,
                             const Unk_Float4* scale, const Unk_410f90* space, const MATRIXT44* matrix, bool clear,
                             f32 arg16, f32 arg17, u32 flags) {
    if (field_20 == nullptr) {
        return -1;
    }
    if (clear) {
        Unk_471410();
    }
    if (other == nullptr || amount <= 0.0f) {
        amount = 0.0f;
        other = nullptr;
    }
    Unk_GPUTexture* otherTexture =
        other != nullptr ? Unk_GetTexture(other) : reinterpret_cast<Unk_GPUTexture*>(field_29a70[2]);
    if (width == 0.0f) {
        width = static_cast<f32>(static_cast<u32>(target->field_54));
    }
    // (sic: the height's default goes to the width)
    if (height == 0.0f) {
        width = static_cast<f32>(static_cast<u32>(target->field_58));
    }
    s32 result = Unk_SetTarget(target, nullptr);
    if (result < 0) {
        return result;
    }
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    Unk_Viewport rect;
    Unk_Viewport viewport;
    field_20->vf17(&viewport);
    Unk_Float right(width + x);
    Unk_Float bottom(height + y);
    Unk_Float lo(x);
    Unk_Float to0(y);
    Unk_Float minX;
    Unk_Float maxX;
    if (right.field_0 < x) {
        minX = right;
        maxX = lo;
    } else {
        minX = lo;
        maxX = right;
    }
    Unk_Float minY;
    Unk_Float maxY;
    if (bottom.field_0 < y) {
        minY = bottom;
        maxY = to0;
    } else {
        minY = to0;
        maxY = bottom;
    }
    f32 viewportWidth = static_cast<f32>(viewport.field_8);
    f32 viewportHeight = static_cast<f32>(viewport.field_c);
    f32 x0 = minX.field_0 < 0.0f ? 0.0f : (minX.field_0 > viewportWidth ? viewportWidth : minX.field_0);
    f32 y0 = minY.field_0 < 0.0f ? 0.0f : (minY.field_0 > viewportHeight ? viewportHeight : minY.field_0);
    f32 x1 = maxX.field_0 < 0.0f ? 0.0f : (maxX.field_0 > viewportWidth ? viewportWidth : maxX.field_0);
    f32 y1 = maxY.field_0 < 0.0f ? 0.0f : (maxY.field_0 > viewportHeight ? viewportHeight : maxY.field_0);
    rect.field_0 = static_cast<u32>(x0);
    rect.field_4 = static_cast<u32>(y0);
    rect.field_8 = static_cast<u32>(x1 - x0);
    rect.field_c = static_cast<u32>(y1 - y0);
    rect.field_10 = 0.0f;
    rect.field_14 = 1.0f;
    field_20->vf16(&rect);
    f32 sourceWidth = static_cast<f32>(static_cast<u32>(source->field_54));
    f32 sourceHeight = static_cast<f32>(static_cast<u32>(source->field_58));
    f32 otherWidth = 0.0f;
    f32 otherHeight = 0.0f;
    f32 left = static_cast<f32>(static_cast<u32>(rect.field_0));
    f32 top = static_cast<f32>(static_cast<u32>(rect.field_4));
    if (other != nullptr) {
        otherWidth = static_cast<f32>(static_cast<u32>(other->field_54));
        otherHeight = static_cast<f32>(static_cast<u32>(other->field_58));
    }
    f32 t0 = 0.0f;
    f32 u0 = 0.0f;
    f32 v0 = 0.0f;
    f32 u1 = source->field_88 * sourceWidth + source->field_90;
    f32 v1 = source->field_8c * sourceHeight + source->field_94;
    f32 s0 = 0.0f;
    f32 s1 = 0.0f;
    f32 t1 = 0.0f;
    if (other != nullptr) {
        s1 = other->field_88 * otherWidth + other->field_90;
        t1 = other->field_8c * otherHeight + other->field_94;
    }
    bool filter0;
    bool filter1;
    if (scale != nullptr) {
        f32 du = u1 - u0;
        f32 dv = v1 - v0;
        f32 ds = s1 - s0;
        f32 dt = t1 - t0;
        u0 = u0 + du * scale->field_0[2].field_0;
        v0 = v0 + dv * scale->field_0[3].field_0;
        u1 = u0 + du * scale->field_0[0].field_0;
        v1 = v0 + dv * scale->field_0[1].field_0;
        s0 = s0 + ds * scale->field_0[2].field_0;
        t0 = t0 + dt * scale->field_0[3].field_0;
        s1 = s0 + ds * scale->field_0[0].field_0;
        t1 = t0 + dt * scale->field_0[1].field_0;
        filter0 = false;
        filter1 = false;
    } else {
        filter1 = width == otherWidth && otherHeight == height;
        filter0 = width == sourceWidth && sourceHeight == height;
    }
    result = Unk_48dad0(x - left, y - top, width, height, u0, v0, u1, v1, s0, t0, s1, t1, arg4, amount, low, high,
                        arg16, arg17, space, matrix, Unk_GetTexture(source), otherTexture, filter0,
                        filter1 | (otherTexture == reinterpret_cast<Unk_GPUTexture*>(field_29a70[2])), flags);
    return result < 0 ? result : 0;
}

// 0x71004122b0 (Unk_415f40.cpp): the offsets and weights of a 3x3 kernel's
// five bilinear taps
void Unk_4122b0(u32 width, u32 height, const f32* kernel, Unk_Float4* offsets, f32* weights, f32 scale);

// 0x71004930d0: a 3x3 filter of `weights` (normalised if asked), as nine
// point samples or, where the texture is filtered, five bilinear ones
s32 CTextureUtil::Unk_4930d0(CRenderTexture* source, CRenderTexture* target, const f32* weights, bool normalize,
                             s32 mode, const Unk_Float4* color, bool clear, bool arg7, s32 arg8, s32 arg9) {
    if (field_20 == nullptr)
        return -1;
    Unk_BeginFilter(clear, arg7);
    bool point;
    if (!arg7 && (Unk_IsFastMode(mode) || Unk_IsFromRGBMode(mode) || Unk_IsRGBALumMode(mode)) &&
        (Unk_GetTexture(source)->field_5c & 0x20000)) {
        point = false;
    } else {
        point = true;
    }
    u32 sourceWidth = arg8 != 0 ? arg8 : source->field_54;
    u32 sourceHeight = arg9 != 0 ? arg9 : source->field_58;
    f32 dx = source->field_88;
    f32 dy = source->field_8c;
    f32 u1 = dx * static_cast<f32>(sourceWidth) + source->field_90;
    f32 v1 = dy * static_cast<f32>(sourceHeight) + source->field_94;
    f32 width = static_cast<f32>(static_cast<u32>(arg8 != 0 ? arg8 : target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(arg9 != 0 ? arg9 : target->field_58));
    s32 count = point ? 9 : 5;
    Unk_Float4 offsets[9];
    f32 taps[9];
    if (point) {
        for (s32 y = 0; y < 3; y++) {
            for (s32 x = 0; x < 3; x++) {
                offsets[y * 3 + x] = Unk_Float4(dx * static_cast<f32>(x - 1), dy * static_cast<f32>(y - 1), 0.0f,
                                                0.0f);
                taps[y * 3 + x] = weights[y * 3 + x];
            }
        }
    } else {
        Unk_4122b0(source->field_80->field_8, source->field_80->field_c, weights, offsets, taps, 1.0f);
    }
    f32 scale = 1.0f;
    if (normalize) {
        f32 sum = 0.0f;
        for (s32 i = 0; i < count; i++)
            sum += taps[i];
        if (sum != 0.0f)
            scale = 1.0f / sum;
    }
    Unk_Float4 colors[9];
    for (s32 i = 0; i < count; i++) {
        f32 weight = scale * taps[i];
        colors[i] = Unk_Float4(color->field_0[0].field_0 * weight, weight * color->field_0[1].field_0,
                               weight * color->field_0[2].field_0, weight * color->field_0[3].field_0);
    }
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0)
        return result;
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    result = DrawRectGPU_MadT1_Sn(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, count, offsets, colors,
                                  Unk_GetTexture(source), mode, 0);
    return result < 0 ? result : 0;
}

// the formats the not-depth path reads as one channel (inline)
static inline bool Unk_IsSingleChannelFormat(s32 format) {
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

// a scale and an offset applied after another (inline): `first`'s, then `second`'s
static inline void Unk_Concat(Unk_Float4* out, const f32* first, const f32* second) {
    out->field_0[0].field_0 = first[0] * second[0];
    out->field_0[1].field_0 = first[1] * second[0] + second[1];
}

// the technique 0x710048ad80 draws with (inline: `count`, which it doesn't
// read, stays an argument of 0x710048ad80's callers)
inline s32 Unk_BlurFactorTechnique(const TEXSHADERSET* set, s32 type, Unk_GPUTexture* mask, s32 index,
                                   s32 count, Unk_GPUTexture* lut) {
    if (mask != nullptr) {
        if (lut != nullptr)
            return set->field_159bc[0][0][type][index];
        return set->field_10c84[0][0][type][index];
    }
    if (lut != nullptr)
        return (&set->field_15984)[type * 2];
    return (&set->field_10c4c)[type * 2];
}

// 0x710048ad80: tech_DepthOfField_BlurFactorAlphaFromDepthTextureTypeCast..
// (the Lut ones with `lut`, the T1_Sn ones with `mask`): a depth or one
// channel of `texture` as a blur factor
// NON_MATCHING: the same computations, but the original loads arg18 at the
// entry, makes the two flags (arg13 == 1, arg18 != nullptr) after the first
// vf17 call, spills `mask` and computes the technique's address in two
// branches before one csel; the registers and the order differ from there.
// Tried: the technique as nested ternaries and if/else, the flags as locals
// in several places, a 64-bit type.
s32 CTextureUtil::Unk_48ad80(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 arg8,
                             f32 arg9, f32 arg10, bool arg11, Unk_GPUTexture* texture, s32 arg13, void* arg14,
                             s32 arg15, s32 arg16, const Unk_Float4* scale, void* arg18, void* arg19, void* arg20,
                             void* arg21, s32 arg22, f32 arg23, void* arg24, u32 flags) {
    bool linear = arg11 && arg13 == 1 && arg18 != nullptr;
    s32 type;
    if (arg11) {
        type = FXDCT_GetDepthCastTypeFromDepthFormat(texture->field_44);
    } else if (Unk_IsSingleChannelFormat(texture->field_44)) {
        type = 0;
    } else {
        type = static_cast<u32>(arg16) < 4 ? arg16 : -1;
    }
    texture->vf17(1);
    Unk_GPUTexture* mask = static_cast<Unk_GPUTexture*>(arg14);
    Unk_GPUTexture* lut = static_cast<Unk_GPUTexture*>(arg19);
    s32 technique = Unk_BlurFactorTechnique(&field_30, type, mask, arg15, arg22, lut);
    if (technique == 0)
        return -4;
    field_30.field_0->vf29(technique);
    Unk_Float4 value(1.0f, 0.0f, 1.0f, 0.0f);
    if (scale != nullptr) {
        value.field_0[0] = scale->field_0[2];
        value.field_0[1] = scale->field_0[3];
        if (arg11) {
            f32 k = (arg9 - arg8) * arg10 / (arg8 * arg9);
            value.field_0[0].field_0 = k * value.field_0[0].field_0;
            value.field_0[1].field_0 = (1.0f - arg10 / arg8) + k * value.field_0[1].field_0;
        }
    }
    Unk_Float4 factor(1.0f, 0.0f, 1.0f, 0.0f);
    if (lut != nullptr) {
        Unk_Concat(&value, &value.field_0[0].field_0, static_cast<const f32*>(arg20));
        Unk_Concat(&factor, static_cast<const f32*>(arg21), &factor.field_0[0].field_0);
    }
    if (!arg11 && arg18 != nullptr)
        Unk_Concat(&factor, &factor.field_0[0].field_0, static_cast<const f32*>(arg18));
    if (linear)
        Unk_Concat(&factor, &factor.field_0[0].field_0, static_cast<const f32*>(arg18));
    factor.field_0[2].field_0 = 1.0f / factor.field_0[0].field_0;
    factor.field_0[3].field_0 = -factor.field_0[1].field_0 / factor.field_0[0].field_0;
    field_30.field_0->vf20(field_30.field_c0, &value.field_0[0].field_0);
    field_30.field_0->vf20(field_30.field_a8, &factor.field_0[0].field_0);
    Unk_Float4 range(65504.0f, -65504.0f, 0.0f, 0.0f);
    field_30.field_0->vf20(field_30.field_a4, &range.field_0[0].field_0);
    if (lut != nullptr) {
        Unk_24e4c18[0] = Unk_Float4(arg23, 0.0f, 0.0f, 0.0f);
        field_30.field_0->vf22(field_30.field_c8, Unk_24e4c18, 1);
    }
    s32 saved = texture->vf19();
    texture->vf17(1);
    field_30.field_0->vf26(field_30.field_10[0], texture);
    if (mask != nullptr)
        field_30.field_0->vf26(field_30.field_10[1], mask);
    if (lut != nullptr) {
        lut->vf15(13);
        field_30.field_0->vf26(field_30.field_10[2], lut);
    }
    if (mask != nullptr)
        field_30.field_0->vf22(field_30.field_d0, static_cast<const Unk_Float4*>(arg24), 1);
    s32 result = Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
    texture->vf17(saved);
    return result;
}

// 0x7100415370 (Unk_415f40.cpp): the points of `rings` rings around the
// centre of a disc of `radius`
s32 Unk_415370(s32 rings, Unk_Float2* out, f32 radius);

// a vector's length (inline)
inline f32 Unk_Length(const Unk_Float2& v) {
    return Unk_Sqrt(v.field_0[0].field_0 * v.field_0[0].field_0 + v.field_0[1].field_0 * v.field_0[1].field_0);
}
// a vector of length 1 in its direction (inline; those of length 0 and 1 as they are)
inline Unk_Float2 Unk_Normalize(const Unk_Float2& v) {
    f32 squared = v.field_0[0].field_0 * v.field_0[0].field_0 + v.field_0[1].field_0 * v.field_0[1].field_0;
    if (squared == 0.0f || squared == 1.0f)
        return v;
    f32 scale = 1.0f / sqrtf(squared);
    return Unk_Float2(v.field_0[0].field_0 * scale, scale * v.field_0[1].field_0);
}

// 0x7100481820: a bokeh of `source`'s `rect` (three rings of samples, scaled
// by `offset`) into `target`, or the rectangle itself without an offset
// NON_MATCHING: register allocation and spills: the original keeps rect's
// first two numbers in s13/s15 and spills the rest and the target's size,
// and its sample loop needs one register less (x26 here); the loop guards
// come out as `cmp #1; b.lt` / `cmp #0; b.le` the other way round.
s32 CTextureUtil::Unk_481820(CRenderTexture* source, CRenderTexture* target, const Unk_Float2& offset,
                             const Unk_Float4& rect) {
    f32 u1;
    f32 v1;
    Unk_GetCoords(source, &u1, &v1);
    f32 u0 = source->field_88 * 0.0f + source->field_90;
    f32 v0 = source->field_8c * 0.0f + source->field_94;
    f32 rectWidth = rect.field_0[0].field_0;
    f32 rectHeight = rect.field_0[1].field_0;
    f32 rectX = rect.field_0[2].field_0;
    f32 rectY = rect.field_0[3].field_0;
    f32 w = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 h = static_cast<f32>(static_cast<u32>(target->field_58));
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0)
        return result;
    f32 left = u1 * rectX;
    f32 top = v1 * rectY;
    f32 width = u1 * rectWidth - u0;
    f32 height = v1 * rectHeight - v0;
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    s32 filter = Unk_GetTexture(source)->vf16();
    Unk_GetTexture(source)->vf17(0);
    Unk_Float2 points[61];
    Unk_Float4 offsets[61];
    s32 count = Unk_415370(3, points, 1.0f);
    for (s32 i = 0; i < count; i++) {
        f32 length = Unk_Length(points[i]);
        Unk_Float2 direction = Unk_Normalize(points[i]);
        points[i].field_0[0].field_0 = length * direction.field_0[0].field_0;
        points[i].field_0[1].field_0 = length * direction.field_0[1].field_0;
    }
    f32 scaleX = width * offset.field_0[0].field_0;
    f32 scaleY = height * offset.field_0[1].field_0;
    for (s32 i = 0; i < count; i++) {
        offsets[i] = Unk_Float4(scaleX * points[i].field_0[0].field_0, scaleY * points[i].field_0[1].field_0, 0.0f,
                                0.0f);
    }
    f32 right = width + left;
    f32 bottom = height + top;
    Unk_GPUTexture* texture = Unk_GetTexture(source);
    if (offset.field_0[0].field_0 == 0.0f && offset.field_0[1].field_0 == 0.0f) {
        result = DrawRectGPU_MadT1_Sn(0.0f, 0.0f, w, h, left, top, right, bottom, 1, offsets, nullptr, texture, 0, 0);
    } else {
        field_30.field_0->vf29(field_30.field_1b330);
        Unk_4738e0(37, offsets, 0, 8);
        if (texture != nullptr)
            field_30.field_0->vf26(field_30.field_8, texture);
        result = Unk_471c50(0.0f, 0.0f, w, h, left, top, right, bottom, 0);
    }
    Unk_GetTexture(source)->vf15(filter);
    return result < 0 ? result : 0;
}

// 0x71004870b0: `source` blurred into `target` by a Gaussian of `sigma` (one
// per channel unless the four are the same), 25 point taps or, where the
// texture is filtered, nine bilinear ones
// NON_MATCHING: the colour loops' preheaders: here both begin with the same
// address computations, which branch folding hoists into the block after the
// calls (so that block isn't tail-duplicated into the calls' blocks, and the
// 5x5 calls are tail-merged); the original's per-channel loop sets up the
// weights' pointer first. The source's fields sit in other registers. Tried:
// the loops as one loop, `!same` first, per-channel inner loops.
// (The coordinates come before Unk_49d250 and the texture's root is found by
// a loop written out: with Unk_GetTexture the first InstCombine, which runs
// before inlining, sinks the coordinates into the draw call's block and
// IndVarSimplify then moves some of them past Unk_49cf50.)
s32 CTextureUtil::Unk_4870b0(CRenderTexture* source, CRenderTexture* target, f32 scale, const Unk_Float4* sigma,
                             s32 mode, const Unk_Float4* color, bool arg6, bool clear, bool arg8, s32 arg9,
                             s32 arg10) {
    if (field_20 == nullptr)
        return -1;
    f32 x = sigma->field_0[0].field_0 > 0.0f ? sigma->field_0[0].field_0 : -sigma->field_0[0].field_0;
    f32 y = sigma->field_0[1].field_0 > 0.0f ? sigma->field_0[1].field_0 : -sigma->field_0[1].field_0;
    f32 z = sigma->field_0[2].field_0 > 0.0f ? sigma->field_0[2].field_0 : -sigma->field_0[2].field_0;
    f32 w = sigma->field_0[3].field_0 > 0.0f ? sigma->field_0[3].field_0 : -sigma->field_0[3].field_0;
    f32 sigmas[4] = {x, y, z, w};
    bool same;
    s32 largest;
    f32 maximum;
    if (x == y && y == z && z == w) {
        same = true;
        largest = 0;
        maximum = x;
    } else {
        same = false;
        if (!(sigma->field_0[0].field_0 < 0.0f))
            arg8 = true;
        largest = 0;
        maximum = x;
        for (s32 i = 1; i < 4; i++) {
            if (sigmas[i] > maximum) {
                maximum = sigmas[i];
                largest = i;
            }
        }
    }
    Unk_BeginFilter(clear, arg8);
    bool large;
    if (!arg8 && (Unk_IsFastMode(mode) || Unk_IsFromRGBMode(mode) || Unk_IsRGBALumMode(mode)) &&
        (Unk_GetTexture(source)->field_5c & 0x20000))
        large = false;
    else
        large = true;
    u32 sourceWidth = arg9 != 0 ? arg9 : source->field_54;
    u32 sourceHeight = arg10 != 0 ? arg10 : source->field_58;
    f32 scaleX = source->field_88;
    f32 scaleY = source->field_8c;
    f32 offsetX = source->field_90;
    f32 offsetY = source->field_94;
    u32 targetWidth = arg9 != 0 ? arg9 : target->field_54;
    u32 targetHeight = arg10 != 0 ? arg10 : target->field_58;
    s32 count = large ? 25 : 9;
    Unk_Float4 offsets[25];
    f32 weights[4][25];
    if (large) {
        if (same) {
            Unk_413860(source->field_80->field_8, source->field_80->field_c, offsets, weights[0], arg6, maximum,
                       1.0f);
        } else {
            for (s32 i = 0; i < 4; i++) {
                Unk_413860(source->field_80->field_8, source->field_80->field_c, offsets, weights[i], arg6,
                           sigmas[i], 1.0f);
            }
        }
    } else {
        if (same) {
            Unk_4134d0(source->field_80->field_8, source->field_80->field_c, offsets, weights[0], arg6, maximum,
                       1.0f);
        } else {
            Unk_Float4 channels[4][9];
            for (s32 i = 0; i < 4; i++) {
                Unk_4134d0(source->field_80->field_8, source->field_80->field_c, channels[i], weights[i], arg6,
                           sigmas[i], 1.0f);
            }
            for (s32 i = 0; i < count; i++) {
                offsets[i] = channels[largest][i];
            }
        }
    }
    Unk_Float4 colors[25];
    if (same) {
        for (s32 i = 0; i < count; i++) {
            f32 weight = weights[0][i] * scale;
            colors[i] = Unk_Float4(color->field_0[0].field_0 * weight, weight * color->field_0[1].field_0,
                                   weight * color->field_0[2].field_0, weight * color->field_0[3].field_0);
        }
    } else {
        for (s32 i = 0; i < count; i++) {
            colors[i].field_0[0].field_0 = color->field_0[0].field_0 * (weights[0][i] * scale);
            colors[i].field_0[1].field_0 = color->field_0[1].field_0 * (weights[1][i] * scale);
            colors[i].field_0[2].field_0 = color->field_0[2].field_0 * (weights[2][i] * scale);
            colors[i].field_0[3].field_0 = color->field_0[3].field_0 * (weights[3][i] * scale);
        }
    }
    f32 u1 = scaleX * static_cast<f32>(sourceWidth) + offsetX;
    f32 v1 = scaleY * static_cast<f32>(sourceHeight) + offsetY;
    f32 width = static_cast<f32>(targetWidth);
    f32 height = static_cast<f32>(targetHeight);
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0)
        return result;
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    CRenderTexture* root = source;
    while (root->field_120 != nullptr)
        root = root->field_120;
    result = DrawRectGPU_MadT1_Sn(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, count, offsets, colors,
                                  reinterpret_cast<Unk_GPUTexture*>(root->field_a8), mode, 0);
    return result < 0 ? result : 0;
}

// 0x71004827b0: the screen-space offset (half its size, y down) of the
// view's centre moved by `arg2` against `arg1` (their rotations), through
// `arg3` (a projection); `x` times its angle, at most `y` times two long
// NON_MATCHING: register allocation: the rows' elements sit in other
// registers, so the sqrtf slow paths' spills and copies differ (the original
// also moves four values through callee-saved registers around each call:
// 180 bytes more). The frame, the loads and the stores are the original's.
Unk_Float2 CTextureUtil::Unk_4827b0(const MATRIXT44* arg1, const MATRIXT44* arg2, void* arg3, f32 x, f32 y) {
    const MATRIXT44* projection = static_cast<const MATRIXT44*>(arg3);
    MATRIXT44 rotation = *arg1;
    MATRIXT44 view = *arg2;
    Unk_NormalizeRow(rotation.field_0[0]);
    Unk_NormalizeRow(rotation.field_0[1]);
    Unk_NormalizeRow(rotation.field_0[2]);
    Unk_NormalizeRow(view.field_0[0]);
    Unk_NormalizeRow(view.field_0[1]);
    Unk_NormalizeRow(view.field_0[2]);
    MATRIXT44 b = view;
    b.field_0[3][2] = 0.0f;
    b.field_0[3][1] = 0.0f;
    b.field_0[3][0] = 0.0f;
    MATRIXT44 inverse;
    inverse.field_0[0][0] = rotation.field_0[0][0];
    inverse.field_0[0][1] = rotation.field_0[1][0];
    inverse.field_0[0][2] = rotation.field_0[2][0];
    inverse.field_0[0][3] = 0.0f;
    inverse.field_0[1][0] = rotation.field_0[0][1];
    inverse.field_0[1][1] = rotation.field_0[1][1];
    inverse.field_0[1][2] = rotation.field_0[2][1];
    inverse.field_0[1][3] = 0.0f;
    inverse.field_0[2][0] = rotation.field_0[0][2];
    inverse.field_0[2][1] = rotation.field_0[1][2];
    inverse.field_0[2][2] = rotation.field_0[2][2];
    inverse.field_0[2][3] = 0.0f;
    inverse.field_0[3][0] = 0.0f;
    inverse.field_0[3][1] = 0.0f;
    inverse.field_0[3][2] = 0.0f;
    inverse.field_0[3][3] = 1.0f;
    MATRIXT44 transform;
    {
        MATRIXT44 m;
        MATRIXT44_MatrixMultiply(&m, &b, &inverse);
        MATRIXT44_MatrixMultiply(&transform, &m, projection);
    }
    f32 px;
    f32 py;
    {
        Unk_Float4 p;
        Unk_Float4 centre(0.0f, 0.0f, 1.0f, 1.0f);
        Unk_40ffc0(&p, &centre, &transform);
        f32 w = 1.0f / p.field_0[3].field_0;
        px = p.field_0[0].field_0 * w;
        py = p.field_0[1].field_0 * w;
    }
    f32 rx;
    f32 ry;
    Unk_40f980(projection, &rx, &ry);
    f32 ax = px * rx;
    f32 ay = py * ry;
    f32 length = Unk_Sqrt(ax * ax + ay * ay);
    f32 angle = atanf(length);
    f32 k = 1.0f;
    if (length > 0.0f)
        k = angle / length;
    f32 dx = px * k * x;
    f32 dy = py * k * x;
    f32 aspect = rx / ry;
    dx = aspect * dx;
    f32 distance = Unk_Sqrt(dy * dy + dx * dx);
    f32 limit = y + y;
    if (limit > 0.0f && distance > limit) {
        f32 f = limit / distance;
        dx *= f;
        dy *= f;
    }
    return Unk_Float2(dx / aspect * -0.5f, dy * 0.5f);
}

// 0x7100489690 (`scale` after the pointers: the arguments' order decides the
// order of the entry's copies of them)
s32 CTextureUtil::Unk_489690(CRenderTexture* a, CRenderTexture* b, CRenderTexture* c, CRenderTexture* target,
                             const Unk_Float4* params, const Unk_Float4* colors, f32 scale, s32 index, u32 flags) {
    f32 u1;
    f32 v1;
    Unk_GetCoords(a, &u1, &v1);
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    target->Unk_49d250(0, 1, 1, 0, 0);
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    field_30.field_0->vf29(field_30.field_7ae4[index]);
    for (s32 i = 0; i < 8; i++) {
        Unk_24e4c18[i] = Unk_Float4(u1 * 0.5f, v1 * 0.5f, 0.0f, 0.0f);
        Unk_24e4c18[8 + i] = Unk_Float4(Unk_24e2d50[7 - i].field_0 * scale, Unk_24e2d50[7 - i].field_4 * scale,
                                        scale * 0.0f, scale * 0.0f);
    }
    field_30.field_0->vf22(field_30.field_c4, Unk_24e4c18, 16);
    Unk_Float4 values[8];
    for (s32 i = 0; i < 8; i++) {
        f32 x = params[i].field_0[0].field_0;
        values[i].field_0[0] = x != 0.0f ? 1.0f / x : 1000.0f;
        values[i].field_0[2] = params[i].field_0[2];
        values[i].field_0[3] = params[i].field_0[3];
    }
    field_30.field_0->vf22(field_30.field_cc, values, 8);
    field_30.field_0->vf22(field_30.field_d0, colors, 8);
    field_30.field_0->vf26(field_30.field_10[0], Unk_GetTexture(a));
    field_30.field_0->vf26(field_30.field_10[1], Unk_GetTexture(b));
    field_30.field_0->vf26(field_30.field_10[2], Unk_GetTexture(c));
    Unk_GPUTexture* textures[3] = {Unk_GetTexture(a), Unk_GetTexture(b), Unk_GetTexture(c)};
    s32 filters[3];
    for (s32 i = 0; i < 3; i++) {
        if (textures[i] != nullptr) {
            filters[i] = textures[i]->vf16();
            textures[i]->vf15(2);
        }
    }
    s32 result = Unk_471c50(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, flags | 0x10000);
    for (s32 i = 0; i < 3; i++) {
        if (textures[i] != nullptr)
            textures[i]->vf15(filters[i]);
    }
    return result;
}

// 0x7100486a80: 0x71004870b0 with a 3x3 Gaussian (nine point taps or five
// bilinear ones); only the first tap when the others weigh nothing
// NON_MATCHING: as 0x71004870b0: the colour loops' preheaders both begin
// with the colours' address here, which branch folding hoists (the
// original's per-channel loop sets up the weights first); the source's
// fields are in other registers, and `mode` is spilled as a 32-bit value
// (64-bit in the original). The rest is the original's.
s32 CTextureUtil::Unk_486a80(CRenderTexture* source, CRenderTexture* target, f32 scale, const Unk_Float4* sigma,
                             s32 mode, const Unk_Float4* color, bool arg6, bool clear, bool arg8, s32 arg9,
                             s32 arg10) {
    if (field_20 == nullptr)
        return -1;
    f32 x = sigma->field_0[0].field_0 > 0.0f ? sigma->field_0[0].field_0 : -sigma->field_0[0].field_0;
    f32 y = sigma->field_0[1].field_0 > 0.0f ? sigma->field_0[1].field_0 : -sigma->field_0[1].field_0;
    f32 z = sigma->field_0[2].field_0 > 0.0f ? sigma->field_0[2].field_0 : -sigma->field_0[2].field_0;
    f32 w = sigma->field_0[3].field_0 > 0.0f ? sigma->field_0[3].field_0 : -sigma->field_0[3].field_0;
    f32 sigmas[4] = {x, y, z, w};
    bool same;
    s32 largest;
    f32 maximum;
    if (x == y && y == z && z == w) {
        same = true;
        largest = 0;
        maximum = x;
    } else {
        same = false;
        if (!(sigma->field_0[0].field_0 < 0.0f))
            arg8 = true;
        largest = 0;
        maximum = x;
        for (s32 i = 1; i < 4; i++) {
            if (sigmas[i] > maximum) {
                maximum = sigmas[i];
                largest = i;
            }
        }
    }
    Unk_BeginFilter(clear, arg8);
    bool large;
    if (!arg8 && (Unk_IsFastMode(mode) || Unk_IsFromRGBMode(mode) || Unk_IsRGBALumMode(mode)) &&
        (Unk_GetTexture(source)->field_5c & 0x20000))
        large = false;
    else
        large = true;
    u32 sourceWidth = arg9 != 0 ? arg9 : source->field_54;
    u32 sourceHeight = arg10 != 0 ? arg10 : source->field_58;
    f32 scaleX = source->field_88;
    f32 scaleY = source->field_8c;
    f32 offsetX = source->field_90;
    f32 offsetY = source->field_94;
    u32 targetWidth = arg9 != 0 ? arg9 : target->field_54;
    u32 targetHeight = arg10 != 0 ? arg10 : target->field_58;
    s32 count = large ? 9 : 5;
    Unk_Float4 offsets[9];
    f32 weights[4][9];
    if (large) {
        if (same) {
            Unk_413730(source->field_80->field_8, source->field_80->field_c, offsets, weights[0], arg6, maximum,
                       1.0f);
        } else {
            for (s32 i = 0; i < 4; i++) {
                Unk_413730(source->field_80->field_8, source->field_80->field_c, offsets, weights[i], arg6,
                           sigmas[i], 1.0f);
            }
        }
    } else {
        if (same) {
            Unk_413330(source->field_80->field_8, source->field_80->field_c, offsets, weights[0], arg6, maximum,
                       1.0f);
        } else {
            Unk_Float4 channels[4][5];
            for (s32 i = 0; i < 4; i++) {
                Unk_413330(source->field_80->field_8, source->field_80->field_c, channels[i], weights[i], arg6,
                           sigmas[i], 1.0f);
            }
            for (s32 i = 0; i < count; i++) {
                offsets[i] = channels[largest][i];
            }
        }
    }
    Unk_Float4 colors[9];
    bool zero = true;
    for (s32 i = 0; i < count; i++) {
        if (same) {
            f32 weight = weights[0][i] * scale;
            colors[i] = Unk_Float4(color->field_0[0].field_0 * weight, weight * color->field_0[1].field_0,
                                   weight * color->field_0[2].field_0, weight * color->field_0[3].field_0);
        } else {
            for (s32 c = 0; c < 4; c++) {
                colors[i].field_0[c].field_0 = color->field_0[c].field_0 * (weights[c][i] * scale);
            }
        }
        if (i != 0) {
            bool none = colors[i].field_0[0].field_0 == 0.0f && colors[i].field_0[1].field_0 == 0.0f &&
                        colors[i].field_0[2].field_0 == 0.0f && colors[i].field_0[3].field_0 == 0.0f;
            zero = none && zero;
        }
    }
    if (zero)
        count = 1;
    f32 u1 = scaleX * static_cast<f32>(sourceWidth) + offsetX;
    f32 v1 = scaleY * static_cast<f32>(sourceHeight) + offsetY;
    f32 width = static_cast<f32>(targetWidth);
    f32 height = static_cast<f32>(targetHeight);
    s32 result = target->Unk_49d250(0, 0, 1, 0, 0);
    if (result < 0)
        return result;
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    CRenderTexture* root = source;
    while (root->field_120 != nullptr)
        root = root->field_120;
    result = DrawRectGPU_MadT1_Sn(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, count, offsets, colors,
                                  reinterpret_cast<Unk_GPUTexture*>(root->field_a8), mode, 0);
    return result < 0 ? result : 0;
}

// 0x710040f8d0 (Unk_415f40.cpp): a projection from its planes
void Unk_40f8d0(MATRIXT44* out, bool arg1, bool arg2, f32 left, f32 right, f32 bottom, f32 top, f32 near, f32 far);

// a view matrix: the inverse of rotation `q` at `position` (inline)
static inline void Unk_ViewMatrix(MATRIXT44* m, const Unk_Quaternion& q, const Unk_Vector3& position) {
    f32 yy = q.y * q.y;
    f32 xy = q.x * q.y;
    f32 zz = q.z * q.z;
    f32 yz = q.y * q.z;
    f32 xz = q.x * q.z;
    f32 yw = q.y * q.w;
    f32 zw = q.z * q.w;
    f32 xw = q.x * q.w;
    f32 xx = q.x * q.x;
    m->field_0[0][0] = 1.0f - 2.0f * yy - 2.0f * zz;
    m->field_0[0][1] = 2.0f * xy - 2.0f * zw;
    m->field_0[0][2] = 2.0f * xz + 2.0f * yw;
    m->field_0[1][0] = 2.0f * xy + 2.0f * zw;
    m->field_0[1][1] = 1.0f - 2.0f * zz - 2.0f * xx;
    m->field_0[1][2] = 2.0f * yz - 2.0f * xw;
    m->field_0[2][0] = 2.0f * xz - 2.0f * yw;
    m->field_0[2][1] = 2.0f * yz + 2.0f * xw;
    m->field_0[2][2] = 1.0f - 2.0f * xx - 2.0f * yy;
    m->field_0[3][0] = -(m->field_0[0][0] * position.field_0[0] + m->field_0[1][0] * position.field_0[1] +
                         m->field_0[2][0] * position.field_0[2]);
    m->field_0[3][1] = -(m->field_0[0][1] * position.field_0[0] + m->field_0[1][1] * position.field_0[1] +
                         m->field_0[2][1] * position.field_0[2]);
    m->field_0[3][2] = -(m->field_0[0][2] * position.field_0[0] + m->field_0[1][2] * position.field_0[1] +
                         m->field_0[2][2] * position.field_0[2]);
    m->field_0[2][3] = 0.0f;
    m->field_0[1][3] = 0.0f;
    m->field_0[0][3] = 0.0f;
    m->field_0[3][3] = 1.0f;
}

// the absolute value (inline)
static inline Unk_Float Unk_Abs(f32 x) {
    return x > 0.0f ? x : -x;
}

// the most taps (`count` or fewer) Unk_482fd0's techniques have (inline:
// `unused`, which it doesn't read, stays an argument of Unk_482fd0's callers)
inline s32 Unk_MotionTaps(const TEXSHADERSET* set, bool flag, s32 count, s32 index, void* unused) {
    s32 used = count + 1;
    s32 technique;
    do {
        technique = flag ? set->field_1bc74[used - 2][index] : set->field_1b9b4[used - 2][index];
        used--;
        if (technique == 0) {
            technique = flag ? set->field_1b6f4[used - 1][index] : set->field_1b434[used - 1][index];
        }
    } while (technique == 0 && used > 1);
    return used;
}

// `a` and `b` mixed: their rotations interpolated spherically, the rest
// linearly (inline)
static inline Unk_484f50_View Unk_LerpView(const Unk_484f50_View& a, const Unk_484f50_View& b, f32 t) {
    Unk_Float4 q;
    Unk_499890(reinterpret_cast<Unk_Quaternion*>(&q), reinterpret_cast<const Unk_Quaternion*>(&a.field_0),
               reinterpret_cast<const Unk_Quaternion*>(&b.field_0), t);
    Unk_484f50_View r;
    r.field_0 = Unk_Float4(q.field_0[0], q.field_0[1], q.field_0[2], q.field_0[3]);
    for (s32 c = 0; c < 3; c++) {
        f32 d = b.field_10.field_0[c] - a.field_10.field_0[c];
        r.field_10.field_0[c] = a.field_10.field_0[c] + d * t;
    }
    r.field_1c = a.field_1c + (b.field_1c - a.field_1c) * t;
    r.field_20 = a.field_20 + (b.field_20 - a.field_20) * t;
    r.field_24 = a.field_24 + (b.field_24 - a.field_24) * t;
    r.field_28 = a.field_28 + (b.field_28 - a.field_28) * t;
    r.field_2c = a.field_2c + (b.field_2c - a.field_2c) * t;
    r.field_30 = a.field_30 + (b.field_30 - a.field_30) * t;
    return r;
}

// a view's view matrix times its projection (inline)
static inline MATRIXT44 Unk_ViewProjection(const Unk_484f50_View& view) {
    MATRIXT44 m;
    Unk_ViewMatrix(&m, *reinterpret_cast<const Unk_Quaternion*>(&view.field_0), view.field_10);
    MATRIXT44 p;
    Unk_40f8d0(&p, false, true, view.field_1c, view.field_20, view.field_24, view.field_28, view.field_2c,
               view.field_30);
    MATRIXT44_MatrixMultiply(&m, &m, &p);
    return m;
}

// a product of two matrices (inline)
static inline MATRIXT44 Unk_Product(const MATRIXT44& a, const MATRIXT44& b) {
    MATRIXT44 r;
    MATRIXT44_MatrixMultiply(&r, &a, &b);
    return r;
}

// a matrix's inverse (inline)
static inline MATRIXT44 Unk_Inverse(const MATRIXT44& m) {
    MATRIXT44 r;
    Unk_4155f0(&r, &m);
    return r;
}

// a point through a matrix (inline)
static inline Unk_Float4 Unk_Transform(const Unk_Float4& v, const MATRIXT44& m) {
    Unk_Float4 r;
    Unk_40ffc0(&r, &v, &m);
    return r;
}

// 0x7100482fd0: how far the view's motion from `previous` to `view` (through
// `projection` and `previousProjection`) moves 17 points on the screen in
// `scale` of it, in eight steps: the longest movement (`outLength`, in the
// target's texels, `scale` reduced so that it is at most twice `limit` in
// screen units), the techniques' tap count for it (`outCount`) and
// Unk_411c70's levels; the rotation and planes of the view and of the one
// `scale` of the way to the previous one
// NON_MATCHING: 24 bytes short: the first projections' stores are paired,
// the second step's loop shares its latch, maxLevels and ratio swap spill
// slots, and the view matrix's arithmetic is scheduled in another order with
// other registers; the statements, calls and stack layout are the original's.
s32 CTextureUtil::Unk_482fd0(f32 scale, f32 limit, f32 ratio, CRenderTexture* target, const MATRIXT44* view,
                             const MATRIXT44* previous, const MATRIXT44* projection,
                             const MATRIXT44* previousProjection, const f32* arg, s32 maxLevels, void* unused,
                             s32 index, s32* outCount, s32* outLevels, s32* outFirst, f32* outLength,
                             f32* outRatio, Unk_484f50_View* outView, Unk_484f50_View* outLerped) {
    bool flag;
    if (arg != nullptr && *arg != 0.0f) {
        flag = true;
    } else {
        flag = false;
    }
    MATRIXT44 a = *view;
    MATRIXT44 b = *previous;
    Unk_NormalizeRow(a.field_0[0]);
    Unk_NormalizeRow(a.field_0[1]);
    Unk_NormalizeRow(a.field_0[2]);
    Unk_NormalizeRow(b.field_0[0]);
    Unk_NormalizeRow(b.field_0[1]);
    Unk_NormalizeRow(b.field_0[2]);
    Unk_484f50_View camera;
    Unk_4628f0(&camera.field_0, &a);
    camera.field_10 = *reinterpret_cast<const Unk_Vector3*>(a.field_0[3]);
    Unk_40f6e0(projection, false, nullptr, &camera.field_1c, &camera.field_20, &camera.field_24, &camera.field_28,
               &camera.field_2c, &camera.field_30, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
    Unk_484f50_View last;
    Unk_4628f0(&last.field_0, &b);
    last.field_10 = *reinterpret_cast<const Unk_Vector3*>(b.field_0[3]);
    Unk_40f6e0(previousProjection, false, nullptr, &last.field_1c, &last.field_20, &last.field_24, &last.field_28,
               &last.field_2c, &last.field_30, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
    Unk_Vector3 zero = {{0.0f, 0.0f, 0.0f}};
    camera.field_10 = zero;
    last.field_10 = zero;
    f32 rx;
    f32 ry;
    Unk_40f980(projection, &rx, &ry);
    f32 aspect = rx / ry;
    MATRIXT44 inverse;
    Unk_4155f0(&inverse, projection);
    MATRIXT44 rotation = a;
    rotation.field_0[3][2] = 0.0f;
    rotation.field_0[3][1] = 0.0f;
    rotation.field_0[3][0] = 0.0f;
    MATRIXT44 unproject;
    MATRIXT44_MatrixMultiply(&unproject, &inverse, &rotation);
    f32 far = camera.field_30;
    f32 near = camera.field_2c;
    f32 depth = -far * near / ((far - near) * 0.5f - far);
    f32 z = depth * 0.5f;
    f32 r0 = depth;
    f32 r1 = depth * 0.5f;
    f32 r2 = r1 * 0.75f;
    f32 r3 = depth * 0.25f;
    Unk_Float4 points[17] = {
        Unk_Float4(0.0f, 0.0f, z, depth),   Unk_Float4(-r0, -r0, z, depth), Unk_Float4(-r0, r0, z, depth),
        Unk_Float4(r0, -r0, z, depth),      Unk_Float4(r0, r0, z, depth),   Unk_Float4(-r1, -r1, z, depth),
        Unk_Float4(-r1, r1, z, depth),      Unk_Float4(r1, -r1, z, depth),  Unk_Float4(r1, r1, z, depth),
        Unk_Float4(-r2, -r2, z, depth),     Unk_Float4(-r2, r2, z, depth),  Unk_Float4(r2, -r2, z, depth),
        Unk_Float4(r2, r2, z, depth),       Unk_Float4(-r3, -r3, z, depth), Unk_Float4(-r3, r3, z, depth),
        Unk_Float4(r3, -r3, z, depth),      Unk_Float4(r3, r3, z, depth),
    };
    Unk_Float4 projected[9][17];
    MATRIXT44 transforms[9];
    Unk_SetIdentity(&transforms[0]);
    for (s32 j = 0; j < 17; j++) {
        projected[0][j] = points[j];
        f32 inv = 1.0f / projected[0][j].field_0[3].field_0;
        projected[0][j].field_0[0].field_0 = projected[0][j].field_0[0].field_0 * inv;
        projected[0][j].field_0[1].field_0 = inv * projected[0][j].field_0[1].field_0;
        projected[0][j].field_0[2].field_0 = inv * projected[0][j].field_0[2].field_0;
    }
    for (s32 i = 1; i < 9; i++) {
        f32 t = static_cast<f32>(i) * scale * 0.125f;
        Unk_484f50_View step = Unk_LerpView(camera, last, t);
        step.field_10 = zero;
        MATRIXT44 m = Unk_ViewProjection(step);
        transforms[i] = Unk_Product(unproject, m);
        transforms[i] = Unk_Inverse(transforms[i]);
        for (s32 j = 0; j < 17; j++) {
            Unk_Float4 v = Unk_Transform(points[j], transforms[i]);
            projected[i][j].field_0[3].field_0 = v.field_0[3].field_0;
            Unk_Float extent = Unk_Abs(v.field_0[0].field_0);
            Unk_Float y = Unk_Abs(v.field_0[1].field_0);
            extent = Unk_Max(extent, y);
            projected[i][j].field_0[3] = Unk_Max(projected[i][j].field_0[3], extent);
            f32 inv = 1.0f / projected[i][j].field_0[3].field_0;
            projected[i][j].field_0[0].field_0 = v.field_0[0].field_0 * inv;
            projected[i][j].field_0[1].field_0 = inv * v.field_0[1].field_0;
            projected[i][j].field_0[2].field_0 = inv * v.field_0[2].field_0;
        }
    }
    Unk_Float2 moves[17];
    for (s32 j = 0; j < 17; j++) {
        moves[j].field_0[0].field_0 = 0.0f;
        moves[j].field_0[1].field_0 = 0.0f;
    }
    for (s32 i = 1; i < 9; i++) {
        for (s32 j = 0; j < 17; j++) {
            f32 dx = projected[i][j].field_0[0].field_0 - projected[i - 1][j].field_0[0].field_0;
            f32 dy = projected[i][j].field_0[1].field_0 - projected[i - 1][j].field_0[1].field_0;
            if (dx == 0.0f && dy == 0.0f) {
                if (i > 1) {
                    f32 k = static_cast<f32>(i) / static_cast<f32>(i - 1);
                    moves[j].field_0[0].field_0 = k * moves[j].field_0[0].field_0;
                    moves[j].field_0[1].field_0 = k * moves[j].field_0[1].field_0;
                }
            } else {
                moves[j].field_0[0].field_0 = (dx > 0.0f ? dx : -dx) + moves[j].field_0[0].field_0;
                moves[j].field_0[1].field_0 = (dy > 0.0f ? dy : -dy) + moves[j].field_0[1].field_0;
            }
        }
    }
    f32 screen = 0.0f;
    f32 length = 0.0f;
    for (s32 j = 0; j < 17; j++) {
        f32 x = moves[j].field_0[0].field_0;
        f32 y = moves[j].field_0[1].field_0;
        f32 ax = aspect * x;
        f32 s = Unk_Sqrt(ax * ax + y * y);
        screen = screen > s ? screen : s;
        f32 tx = x * (static_cast<f32>(static_cast<u32>(target->field_54)) * 0.5f);
        f32 ty = y * (static_cast<f32>(static_cast<u32>(target->field_58)) * 0.5f);
        f32 l = Unk_Sqrt(tx * tx + ty * ty);
        length = length > l ? length : l;
    }
    f32 most = limit * 2.0f;
    if (most > 0.0f && screen > most) {
        f32 k = most / screen;
        scale = k * scale;
        length = k * length;
    }
    Unk_484f50_View lerped = Unk_LerpView(camera, last, scale);
    s32 count = field_29a64 < 2 ? 4 : field_29a64;
    s32 used = Unk_MotionTaps(&field_30, flag, count, index, unused);
    s32 levels;
    s32 first;
    f32 step;
    Unk_411c70(length, ratio, used, 0, maxLevels, &levels, &first, &step);
    f32 k = step / length;
    if (outCount != nullptr) {
        *outCount = used;
    }
    if (outLevels != nullptr) {
        *outLevels = levels;
    }
    if (outFirst != nullptr) {
        *outFirst = first;
    }
    if (outLength != nullptr) {
        *outLength = length;
    }
    if (outRatio != nullptr) {
        *outRatio = k;
    }
    if (outView != nullptr) {
        *outView = camera;
    }
    if (outLerped != nullptr) {
        *outLerped = lerped;
    }
    return 0;
}

// 0x7100483e50: Unk_482fd0's motion of the view (`outMotion`), and the
// techniques' tap count and Unk_411c70's levels for a blur `length` of the
// target's height long (1 if it isn't positive), the tap counts in steps of
// field_29a68's mode (1: odd ones, 2: even ones)
// NON_MATCHING: same size, 12 instructions: the post-RA scheduler moves the
// copy of `this` and the first normalisation's fcmp ahead of the other
// argument copies, and the techniques' loop tests the count with a ccmp (the
// original keeps cbnz and cmp/b.lt). Tried: the loop as do/while, while and
// for, the tests split and in either order.
s32 CTextureUtil::Unk_483e50(f32 scale, f32 length, f32 ratio, CRenderTexture* target, const MATRIXT44* view,
                             const MATRIXT44* previous, const MATRIXT44* projection,
                             const MATRIXT44* previousProjection, bool flag, s32 maxLevels, void* unused,
                             s32 index, s32* outCount, s32* outLevels, s32* outFirst, f32* outLength,
                             f32* outMotion, f32* outRatio, Unk_484f50_View* outView, Unk_484f50_View* outLerped) {
    MATRIXT44 a = *view;
    MATRIXT44 b = *previous;
    Unk_NormalizeRow(a.field_0[0]);
    Unk_NormalizeRow(a.field_0[1]);
    Unk_NormalizeRow(a.field_0[2]);
    Unk_NormalizeRow(b.field_0[0]);
    Unk_NormalizeRow(b.field_0[1]);
    Unk_NormalizeRow(b.field_0[2]);
    s32 levels;
    s32 first;
    s32 count;
    f32 motion;
    f32 step;
    Unk_484f50_View motionView;
    Unk_484f50_View motionLerped;
    Unk_482fd0(scale, length, ratio, target, &a, &b, projection, previousProjection, nullptr, maxLevels, unused,
               index, &count, &levels, &first, &motion, &step, &motionView, &motionLerped);
    Unk_484f50_View camera;
    Unk_4628f0(&camera.field_0, &a);
    camera.field_10 = *reinterpret_cast<const Unk_Vector3*>(a.field_0[3]);
    Unk_40f6e0(projection, false, nullptr, &camera.field_1c, &camera.field_20, &camera.field_24, &camera.field_28,
               &camera.field_2c, &camera.field_30, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
    Unk_484f50_View last;
    Unk_4628f0(&last.field_0, &b);
    last.field_10 = *reinterpret_cast<const Unk_Vector3*>(b.field_0[3]);
    Unk_40f6e0(previousProjection, false, nullptr, &last.field_1c, &last.field_20, &last.field_24, &last.field_28,
               &last.field_2c, &last.field_30, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
    Unk_484f50_View current = camera;
    Unk_484f50_View lerped = Unk_LerpView(camera, last, scale);
    if (length <= 0.0f) {
        length = 1.0f;
    }
    length = length * static_cast<f32>(static_cast<u32>(target->field_58));
    s32 mode = field_29a68;
    s32 stride = mode == 1 ? 2 : mode == 2 ? 2 : 1;
    s32 taps = field_29a64 < 2 ? 5 : field_29a64;
    switch (mode) {
    case 1:
        taps = taps / 2 * 2 + 1;
        break;
    case 2:
        taps = (taps + 1) / 2 * 2;
        break;
    }
    s32 used = taps + stride;
    s32 technique;
    do {
        used -= stride;
        technique = (flag ? field_30.field_201a4[1][used - 1][index] : field_30.field_1e0a4[1][used - 1][index]);
        if (technique != 0 || used < 2) {
            break;
        }
        technique = (flag ? field_30.field_1f124[1][used - 1][index] : field_30.field_1d024[1][used - 1][index]);
    } while (technique == 0);
    Unk_411c70(length, ratio, used, mode == 1 ? 1 : mode == 2 ? 2 : 0, maxLevels, &levels, &first, &step);
    f32 k = step / length;
    if (outCount != nullptr) {
        *outCount = used;
    }
    if (outLevels != nullptr) {
        *outLevels = levels;
    }
    if (outFirst != nullptr) {
        *outFirst = first;
    }
    if (outLength != nullptr) {
        *outLength = length;
    }
    if (outMotion != nullptr) {
        *outMotion = motion;
    }
    if (outRatio != nullptr) {
        *outRatio = k;
    }
    if (outView != nullptr) {
        *outView = current;
    }
    if (outLerped != nullptr) {
        *outLerped = lerped;
    }
    return 0;
}

// the two filters Unk_4845c0 sets on its textures (with and without `arg`)
extern s32 Unk_238d00c;
extern s32 Unk_238d008;

// 0x71004845c0: `source` blurred along the view's motion (Unk_482fd0's) in
// its levels: each pass draws its taps' transforms (the views between the
// view and the one Unk_482fd0 gives `scale` of the way to the previous one)
// with Unk_479c30, ping-ponging between `temp` and `source`, the last pass
// into `target` weighted by `color`
// NON_MATCHING: same size: register allocation and scheduling (`this`
// and `arg` are spilled at the entry in the original, `arg` here only before
// the passes; the source's coordinates, the per-tap view arithmetic and the
// colours' registers differ); the statements, calls and stack layout are the
// original's.
s32 CTextureUtil::Unk_4845c0(f32 scale, f32 limit, f32 ratio, CRenderTexture* source, CRenderTexture* target,
                             CRenderTexture* temp, const MATRIXT44* view, const MATRIXT44* previous,
                             const MATRIXT44* projection, const MATRIXT44* previousProjection, const f32* arg,
                             s32 maxLevels, void* unused, s32 index, const Unk_Float4* color, bool clear) {
    bool flag;
    if (arg != nullptr && *arg != 0.0f) {
        flag = true;
    } else {
        flag = false;
    }
    MATRIXT44 a = *view;
    MATRIXT44 b = *previous;
    Unk_NormalizeRow(a.field_0[0]);
    Unk_NormalizeRow(a.field_0[1]);
    Unk_NormalizeRow(a.field_0[2]);
    Unk_NormalizeRow(b.field_0[0]);
    Unk_NormalizeRow(b.field_0[1]);
    Unk_NormalizeRow(b.field_0[2]);
    s32 levels;
    s32 first;
    s32 count;
    f32 length;
    f32 step;
    Unk_484f50_View current;
    Unk_484f50_View lerped;
    Unk_482fd0(scale, limit, ratio, source, &a, &b, projection, previousProjection, arg, maxLevels, unused, index,
               &count, &levels, &first, &length, &step, &current, &lerped);
    if (levels == 0) {
        if (source == target) {
            return 0;
        }
        levels = 1;
        first = 1;
        length = 0.0f;
        step = 0.0f;
    }
    s32 drawIndex = levels == 1 && first == 1 ? 0 : index;
    if (clear) {
        Unk_471410();
    }
    s32 filter = flag ? Unk_238d00c : Unk_238d008;
    Unk_GetTexture(source)->vf15(filter);
    Unk_GetTexture(target)->vf15(filter);
    if (temp != nullptr) {
        Unk_GetTexture(temp)->vf15(filter);
    }
    MATRIXT44 inverse;
    Unk_4155f0(&inverse, projection);
    MATRIXT44 rotation = a;
    rotation.field_0[3][2] = 0.0f;
    rotation.field_0[3][1] = 0.0f;
    rotation.field_0[3][0] = 0.0f;
    MATRIXT44 unproject;
    MATRIXT44_MatrixMultiply(&unproject, &inverse, &rotation);
    f32 width = static_cast<f32>(static_cast<u32>(source->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(source->field_58));
    f32 u1;
    f32 v1;
    Unk_GetCoords(source, &u1, &v1);
    CRenderTexture* targets[2] = {temp, source};
    Unk_Vector3 zero = {{0.0f, 0.0f, 0.0f}};
    MATRIXT44 transforms[16];
    Unk_Float4 colors[16];
    CRenderTexture* from = source;
    f32 offset = step;
    for (s32 pass = 0; pass < levels; pass++) {
        CRenderTexture* to;
        const s32* taps;
        Unk_Float4 c;
        if (pass != levels - 1) {
            to = targets[pass & 1];
            c = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
            taps = &count;
        } else {
            c = *color;
            to = target;
            taps = &first;
        }
        s32 n = *taps;
        to->Unk_49d250(0, 0, 1, 0, 0);
        CRenderTexture::Unk_49cf50(nullptr, nullptr);
        if (n > 0) {
            f32 inv = 1.0f / static_cast<f32>(n);
            f32 r = c.field_0[0].field_0 * inv;
            f32 g = c.field_0[1].field_0 * inv;
            f32 bl = c.field_0[2].field_0 * inv;
            f32 al = c.field_0[3].field_0 * inv;
            for (s32 i = 0; i < n; i++) {
                f32 t = offset * static_cast<f32>(i);
                Unk_484f50_View v = Unk_LerpView(current, lerped, t);
                v.field_10 = zero;
                MATRIXT44 m = Unk_ViewProjection(v);
                transforms[i] = Unk_Product(unproject, m);
                transforms[i] = Unk_Inverse(transforms[i]);
                colors[i].field_0[0].field_0 = r;
                colors[i].field_0[1].field_0 = g;
                colors[i].field_0[2].field_0 = bl;
                colors[i].field_0[3].field_0 = al;
            }
        }
        Unk_479c30(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, n, reinterpret_cast<Unk_GPUTexture**>(transforms),
                   arg, colors, Unk_GetTexture(from), drawIndex, 0);
        if (pass < levels - 1) {
            Unk_43fc90_get(reinterpret_cast<u64>(field_20));
        }
        offset *= static_cast<f32>(count);
        from = to;
    }
    Unk_GetTexture(source)->vf15(0);
    Unk_GetTexture(target)->vf15(0);
    if (temp != nullptr) {
        Unk_GetTexture(temp)->vf15(0);
    }
    return 0;
}

// 0x7100484f50: Unk_47a030 from `source` (and `depth`) into `target`, with
// the view's rotation and translation, the motion from `previous` to `view`
// through `projection`, and the encodings of the target and of the depth
// (`mode`, -2: from the depth's format; given back in `outMode`)
s32 CTextureUtil::Unk_484f50(f32 scale, CRenderTexture* source, CRenderTexture* target, CRenderTexture* depth,
                             const MATRIXT44* view, const MATRIXT44* previous, const MATRIXT44* projection,
                             const MATRIXT44* arg7, s32 index, const Unk_Float2* arg9, const Unk_Float2* falloff,
                             s32 mode, const Unk_Float2* range, bool clear, s32* outMode) {
    f32 rx;
    f32 ry;
    if (clear) {
        Unk_471410();
    }
    MATRIXT44 a = *view;
    MATRIXT44 b = *previous;
    Unk_NormalizeRow(a.field_0[0]);
    Unk_NormalizeRow(a.field_0[1]);
    Unk_NormalizeRow(a.field_0[2]);
    Unk_NormalizeRow(b.field_0[0]);
    Unk_NormalizeRow(b.field_0[1]);
    Unk_NormalizeRow(b.field_0[2]);
    Unk_484f50_View camera;
    Unk_4628f0(&camera.field_0, &a);
    camera.field_10 = *reinterpret_cast<const Unk_Vector3*>(a.field_0[3]);
    Unk_40f6e0(projection, false, nullptr, &camera.field_1c, &camera.field_20, &camera.field_24, &camera.field_28,
               &camera.field_2c, &camera.field_30, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
    Unk_Float2 given = *range;
    Unk_Float sx;
    Unk_Float sy;
    if (depth != nullptr) {
        sx = given.field_0[0];
        sy = given.field_0[1];
    } else {
        sx = scale;
        sy = scale;
    }
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    bool srgb = Unk_428030(target->field_2c.field_c);
    if (depth != nullptr && mode == -2) {
        mode = !Unk_428030(depth->field_2c.field_c);
    }
    Unk_40f980(projection, &rx, &ry);
    f32 aspect = rx / ry;
    s32 saved = target->field_a0;
    target->Unk_SetA0(1);
    MATRIXT44 inverse;
    Unk_4155f0(&inverse, projection);
    MATRIXT44 t = a;
    MATRIXT44 m1;
    MATRIXT44_MatrixMultiply(&m1, &inverse, &t);
    MATRIXT44 previousInverse;
    Unk_4155f0(&previousInverse, &b);
    MATRIXT44 m2;
    MATRIXT44_MatrixMultiply(&m2, &previousInverse, arg7);
    MATRIXT44 m3;
    MATRIXT44_MatrixMultiply(&m3, &m1, &m2);
    MATRIXT44 m4;
    Unk_4155f0(&m4, &m3);
    MATRIXT44 transform = m4;
    Unk_Float2 factor(0.5f / sx.field_0 * aspect, -0.5f / sy.field_0);
    Unk_Float2 targetEncoding = srgb ? Unk_Float2(1.0f, 0.0f) : Unk_Float2(0.5f, 0.5f);
    Unk_Float2 depthEncoding = mode == 0 ? Unk_Float2(1.0f, 0.0f) : Unk_Float2(0.5f, 0.5f);
    target->Unk_49d250(0, 0, 1, 0, 0);
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    f32 u1;
    f32 v1;
    Unk_GetCoords(source, &u1, &v1);
    f32 u3;
    f32 v3;
    if (depth != nullptr) {
        Unk_GetCoords(depth, &u3, &v3);
    } else {
        u3 = 1.0f;
        v3 = 1.0f;
    }
    Unk_47a030(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, 0.0f, 0.0f, u3, v3,
               reinterpret_cast<const Unk_47a030_Arg1*>(&camera), &transform, &factor, &targetEncoding,
               &depthEncoding, index, arg9, falloff, Unk_GetTexture(source),
               depth != nullptr ? Unk_GetTexture(depth) : nullptr, 0);
    s32 result = ::Unk_49e3a0(0x1f, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
    target->Unk_SetA0(saved);
    if (result < 0)
        return result;
    if (outMode != nullptr)
        *outMode = mode;
    return 0;
}

// 0x7100485610: `source` blurred along the velocity into `target`: the
// levels and taps of Unk_483e50 for the view's motion, `velocity` generated
// from the depth first with `generate` (Unk_484f50's body, with
// Unk_483e50's view), reduced into `velocityWork`'s first texture when the
// blur runs at `work`'s size or must be decoded, and dilated (a 3x3 Gaussian
// of `sigma`) when `*dilation` is 1; then every level's pass of Unk_47a380
// ping-pongs between the work textures (or `temp` and `source`), the last
// one weighted by `color`, and a half-size result is composed into `target`
// with Unk_47a850
// NON_MATCHING: a first draft with the original's calls, arguments and
// branches; the registers, spill slots and the order of some blocks differ.
s32 CTextureUtil::Unk_485610(f32 scale, f32 length, f32 arg2, f32 arg3, f32 ratio, CRenderTexture* source,
                             CRenderTexture* target, CRenderTexture* temp, CRenderTextureArray* work,
                             CRenderTexture* velocity, CRenderTexture* reduced, CRenderTextureArray* velocityWork,
                             const u64* dilation, const f32* sigma, bool generate, const MATRIXT44* view,
                             const MATRIXT44* previous, const MATRIXT44* projection,
                             const MATRIXT44* previousProjection, CRenderTexture* depth, s32 type,
                             const Unk_Float2* depthScale, const Unk_Float2* linear, const Unk_Float2* range,
                             s32 mode, const Unk_Float2* offset, bool arg26, bool arg27, const Unk_Float2* arg28,
                             u32 count, const Unk_Float2* arg30, s32 arg31, const Unk_Float4* color, bool clear) {
    CRenderTexture* half;
    CRenderTexture* from;
    bool downsampled;
    if (work != nullptr && source->field_54 > work->field_38[work->field_90]->field_54) {
        half = work->field_30 < 2 ? nullptr : work->field_38[1];
        Unk_Float4 one(1.0f, 1.0f, 1.0f, 1.0f);
        Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
        Unk_47d960(0.0f, 0.0f, 0.0f, 1.0f, source, half, nullptr, 0, &one, 0, false, false, 1, &zero, nullptr, -1);
        downsampled = true;
        from = half;
    } else {
        half = nullptr;
        downsampled = false;
        from = source;
    }
    MATRIXT44 a = *view;
    MATRIXT44 b = *previous;
    Unk_NormalizeRow(a.field_0[0]);
    Unk_NormalizeRow(a.field_0[1]);
    Unk_NormalizeRow(a.field_0[2]);
    Unk_NormalizeRow(b.field_0[0]);
    Unk_NormalizeRow(b.field_0[1]);
    Unk_NormalizeRow(b.field_0[2]);
    CRenderTexture* depthSource = depth != nullptr ? depth : source;
    s32 taps;
    s32 levels;
    s32 first;
    f32 blurLength;
    f32 motion;
    f32 step;
    Unk_484f50_View camera;
    Unk_484f50_View lerped;
    Unk_483e50(scale, length, ratio, from, &a, &b, projection, previousProjection, arg27, count,
               const_cast<Unk_Float2*>(arg30), arg31, &taps, &levels, &first, &blurLength, &motion, &step, &camera,
               &lerped);
    f32 k = blurLength / static_cast<f32>(static_cast<u32>(from->field_58));
    Unk_Float2 velocityScale = reduced != nullptr || !generate ? *offset : Unk_Float2(k, k);
    if (levels == 0) {
        if (source == target) {
            return 0;
        }
        levels = first = 0;
        blurLength = step = 0.0f;
        CRenderTexture::Unk_49cf50(nullptr, nullptr);
        Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
        return Unk_47d960(0.0f, 0.0f, 0.0f, 1.0f, source, target, nullptr, 0, const_cast<Unk_Float4*>(color), 0,
                          false, false, 1, &zero, nullptr, -1);
    }
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    if (clear) {
        Unk_471410();
    }
    Unk_GPUTexture* fromTexture = Unk_GetTexture(from);
    Unk_GPUTexture* velocityTexture = Unk_GetTexture(velocity);
    bool sameSize =
        fromTexture->field_4c == velocityTexture->field_4c && fromTexture->field_50 == velocityTexture->field_50;
    s32 filter = Unk_238d008;
    Unk_GetTexture(from)->vf15(filter);
    Unk_GetTexture(target)->vf15(filter);
    if (temp != nullptr) {
        Unk_GetTexture(temp)->vf15(filter);
    }
    Unk_GetTexture(velocity)->vf15(sameSize ? Unk_238d00c : Unk_238d008);
    f32 fromWidth = static_cast<f32>(static_cast<u32>(from->field_54));
    f32 fromHeight = static_cast<f32>(static_cast<u32>(from->field_58));
    f32 u1 = from->field_88 * fromWidth + from->field_90;
    f32 v1 = from->field_8c * fromHeight + from->field_94;
    bool srgb = Unk_428030(velocity->field_2c.field_c);
    if (reduced != nullptr && mode == -2) {
        mode = !Unk_428030(reduced->field_2c.field_c);
    }
    f32 rx;
    f32 ry;
    Unk_40f980(projection, &rx, &ry);
    f32 aspect = rx / ry;
    if (generate) {
        s32 saved = velocity->field_a0;
        velocity->Unk_SetA0(1);
        MATRIXT44 inverse;
        Unk_4155f0(&inverse, projection);
        MATRIXT44 t = a;
        MATRIXT44 m1;
        MATRIXT44_MatrixMultiply(&m1, &inverse, &t);
        MATRIXT44 previousInverse;
        Unk_4155f0(&previousInverse, &b);
        MATRIXT44 m2;
        MATRIXT44_MatrixMultiply(&m2, &previousInverse, previousProjection);
        MATRIXT44 m3;
        MATRIXT44_MatrixMultiply(&m3, &m1, &m2);
        MATRIXT44 m4;
        Unk_4155f0(&m4, &m3);
        MATRIXT44 transform = m4;
        Unk_Float2 factor(0.5f / velocityScale.field_0[0].field_0 * aspect, -0.5f / velocityScale.field_0[1].field_0);
        Unk_Float2 targetEncoding = srgb ? Unk_Float2(1.0f, 0.0f) : Unk_Float2(0.5f, 0.5f);
        Unk_Float2 depthEncoding = mode == 0 ? Unk_Float2(1.0f, 0.0f) : Unk_Float2(0.5f, 0.5f);
        velocity->Unk_49d250(0, 0, 1, 0, 0);
        f32 width = static_cast<f32>(static_cast<u32>(velocity->field_54));
        f32 height = static_cast<f32>(static_cast<u32>(velocity->field_58));
        f32 u3;
        f32 v3;
        if (reduced != nullptr) {
            Unk_GetCoords(reduced, &u3, &v3);
        } else {
            u3 = 1.0f;
            v3 = 1.0f;
        }
        Unk_47a030(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, 0.0f, 0.0f, u3, v3,
                   reinterpret_cast<const Unk_47a030_Arg1*>(&camera), &transform, &factor, &targetEncoding,
                   &depthEncoding, type, depthScale, range, Unk_GetTexture(depthSource),
                   reduced != nullptr ? Unk_GetTexture(reduced) : nullptr, 0);
        ::Unk_49e3a0(0x1f, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
        velocity->Unk_SetA0(saved);
        arg27 = false;
    }
    CRenderTexture* vel = velocity;
    if (velocityWork != nullptr) {
        bool linearWork = srgb && !Unk_428030(velocityWork->field_38[velocityWork->field_90]->field_2c.field_c);
        u32 next = 0;
        if ((downsampled && velocity->field_54 > velocityWork->field_38[velocityWork->field_90]->field_54) ||
            (*dilation != 0 && linearWork)) {
            vel = velocityWork->Unk_Texture(0);
            next = velocityWork->field_30 != 1;
            vel->Unk_49d250(0, 0, 1, 0, 0);
            f32 s = linearWork ? 0.5f : 1.0f;
            f32 o = linearWork ? 0.5f : 0.0f;
            Unk_Float4 decode(s, s, o, o);
            f32 width = static_cast<f32>(static_cast<u32>(vel->field_54));
            f32 height = static_cast<f32>(static_cast<u32>(vel->field_58));
            f32 vu;
            f32 vv;
            Unk_GetCoords(velocity, &vu, &vv);
            Unk_47aa60(0.0f, 0.0f, width, height, 0.0f, 0.0f, vu, vv, &decode, Unk_GetTexture(velocity), nullptr,
                       0);
            srgb = srgb && !linearWork;
        }
        if (*dilation != 0) {
            CRenderTexture* out = vel;
            if (*dilation == 1) {
                f32 m = sigma[0] > sigma[1] ? sigma[0] : sigma[1];
                if (m > 0.0f) {
                    out = static_cast<s32>(next) < velocityWork->field_30 ? velocityWork->field_38[next] : nullptr;
                    Unk_Float4 one(1.0f, 1.0f, 1.0f, 1.0f);
                    if (m < 0.744f) {
                        Unk_486a80(vel, out, 1.0f, reinterpret_cast<const Unk_Float4*>(sigma), 0, &one, false,
                                   false, false, 0, 0);
                    } else {
                        Unk_4870b0(vel, out, 1.0f, reinterpret_cast<const Unk_Float4*>(sigma), 0, &one, false,
                                   false, false, 0, 0);
                    }
                }
            }
            if (vel != out) {
                velocity = out;
            }
            vel = out;
        }
    }
    if (field_20->field_58) {
        velocityScale.field_0[1].field_0 = -velocityScale.field_0[1].field_0;
    }
    CRenderTexture* targets[2];
    CRenderTexture* input;
    if (downsampled) {
        targets[1] = half;
        targets[0] = nullptr;
        if (work->Unk_Texture(0) == half) {
            targets[0] = work->Unk_Texture(1);
        }
        if (work->Unk_Texture(1) == half) {
            targets[0] = work->Unk_Texture(0);
        }
        input = half;
    } else {
        input = source;
        targets[0] = temp;
        targets[1] = source;
    }
    Unk_Float2 near = *arg28;
    Unk_484f50_View current;
    Unk_4628f0(&current.field_0, &a);
    current.field_10 = *reinterpret_cast<const Unk_Vector3*>(a.field_0[3]);
    Unk_40f6e0(projection, false, nullptr, &current.field_1c, &current.field_20, &current.field_24,
               &current.field_28, &current.field_2c, &current.field_30, nullptr, nullptr, nullptr, nullptr, nullptr,
               nullptr, nullptr);
    f32 blend;
    f32 distance = near.field_0[0].field_0;
    f32 depthRange = near.field_0[1].field_0;
    if (depthRange > 0.0f) {
        if (distance == 0.0f) {
            blend = 0.0f;
        } else {
            f32 zFar = current.field_30;
            f32 zNear = current.field_2c;
            f32 d = depthRange > zFar ? zFar : depthRange;
            d = depthRange < zNear ? zNear : d;
            f32 z0 = zFar * (d - zNear) / (zFar - zNear) / d;
            f32 d1 = distance + d;
            f32 z1 = zFar * (d1 - zNear) / (zFar - zNear) / d1;
            blend = (linear->field_0[1].field_0 + linear->field_0[0].field_0 * z1) -
                    (linear->field_0[1].field_0 + linear->field_0[0].field_0 * z0);
        }
    } else {
        blend = distance * linear->field_0[0].field_0;
    }
    f32 texel = 1.0f / fromHeight + 1.0f / fromHeight;
    f32 motionScale = arg27 ? k : 0.0f;
    CRenderTexture* to = input;
    if (levels >= 1) {
        f32 q = u1 / aspect;
        f32 mul = srgb ? 1.0f : 2.0f;
        f32 add = (srgb ? 0.0f : -1.0f) + mul * 0.0f;
        f32 sx = velocityScale.field_0[0].field_0 * scale;
        f32 sy = velocityScale.field_0[1].field_0 * scale;
        f32 decodeX = sx * mul;
        f32 decodeY = sy * mul;
        f32 decodeZ = sx * add + 0.0f;
        f32 decodeW = sy * add + 0.0f;
        for (s32 pass = 0; pass < levels; pass++) {
            s32 n = pass == 0 ? first : taps;
            Unk_Float4 c;
            if (pass == levels - 1) {
                to = downsampled ? targets[pass & 1] : target;
                c = *color;
            } else {
                to = targets[pass & 1];
                c = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
            }
            to->Unk_49d250(0, 0, 1, 0, 0);
            Unk_Float4 colors[16];
            if (n >= 1) {
                f32 w = 1.0f / n;
                for (s32 i = 0; i < n; i++) {
                    colors[i] = Unk_Float4(w * c.field_0[0].field_0, w * c.field_0[1].field_0,
                                           w * c.field_0[2].field_0, w * c.field_0[3].field_0);
                }
            }
            f32 p = powf(static_cast<f32>(taps), static_cast<f32>(levels + ~pass));
            f32 velWidth = static_cast<f32>(static_cast<u32>(vel->field_54));
            f32 velHeight = static_cast<f32>(static_cast<u32>(vel->field_58));
            f32 vu = vel->field_88 * velWidth + vel->field_90;
            f32 vv = vel->field_8c * velHeight + vel->field_94;
            f32 st = p * step;
            f32 inv = 1.0f / p;
            Unk_Float4 decode(decodeX, decodeY, decodeZ, decodeW);
            Unk_Float2 scale1(q * (u1 * st), v1 * (v1 * st));
            Unk_Float2 scale2(st * vu * (vu / aspect), vv * (st * vv));
            Unk_Float2 steps(inv, inv * -0.5f);
            Unk_47a380(0.0f, 0.0f, fromWidth, fromHeight, 0.0f, 0.0f, u1, v1, 0.0f, 0.0f, vu, vv, texel,
                       motionScale, arg2, blend, n, &decode, &scale1, &scale2, &steps, arg26, colors,
                       Unk_GetTexture(input), Unk_GetTexture(vel), arg31, 0);
            input = to;
        }
    }
    if (downsampled) {
        CRenderTexture* final = source;
        if (source == target) {
            Unk_Float4 one(1.0f, 1.0f, 1.0f, 1.0f);
            Unk_Float4 zero(0.0f, 0.0f, 0.0f, 0.0f);
            Unk_47d960(0.0f, 0.0f, 0.0f, 1.0f, source, temp, nullptr, 0, &one, 0, false, false, 1, &zero, nullptr,
                       -1);
            final = temp;
        }
        target->Unk_49d250(0, 0, 1, 0, 0);
        f32 targetWidth = static_cast<f32>(static_cast<u32>(target->field_54));
        f32 targetHeight = static_cast<f32>(static_cast<u32>(target->field_58));
        f32 limit = 1.0f / static_cast<f32>(static_cast<u32>(to->field_58)) * 4.0f;
        bool linearVelocity = Unk_428030(velocity->field_2c.field_c);
        f32 mul = linearVelocity ? 1.0f : 2.0f;
        f32 add = (linearVelocity ? 0.0f : -1.0f) + mul * 0.0f;
        f32 sx = velocityScale.field_0[0].field_0 * scale;
        f32 sy = velocityScale.field_0[1].field_0 * scale;
        Unk_Float4 decode(sx * mul, sy * mul, sx * add + 0.0f, sy * add + 0.0f);
        f32 fu;
        f32 fv;
        Unk_GetCoords(final, &fu, &fv);
        f32 tu;
        f32 tv;
        Unk_GetCoords(to, &tu, &tv);
        f32 vu;
        f32 vv;
        Unk_GetCoords(velocity, &vu, &vv);
        Unk_47a850(0.0f, 0.0f, targetWidth, targetHeight, 0.0f, 0.0f, fu, fv, 0.0f, 0.0f, tu, tv, 0.0f, 0.0f, vu, vv,
                   texel, limit > arg3 ? limit : arg3, &decode, Unk_GetTexture(final), Unk_GetTexture(to),
                   Unk_GetTexture(velocity), arg31, 0);
    }
    Unk_GetTexture(source)->vf15(0);
    Unk_GetTexture(target)->vf15(0);
    if (temp != nullptr) {
        Unk_GetTexture(temp)->vf15(0);
    }
    Unk_GetTexture(vel)->vf15(0);
    return 0;
}

// 0x7100488d90 (the DistScale technique unless every params[i].y is 1, or
// it has none)
// NON_MATCHING: registers and scheduling only: the sample points' block has x8 and x9
// swapped, and the aspect selects and the divisions of data[8] and data[9]
// come in another order. Tried: the technique, the selects and the
// divisions in other spellings, the loop unswitched by hand.
s32 CTextureUtil::Unk_488d90(CRenderTexture* a, CRenderTexture* b, CRenderTexture* c, CRenderTexture* d,
                             Unk_GPUTexture* trim, CRenderTexture* target, const Unk_Float4* params,
                             const Unk_Float4* colors, f32 scale, s32 index, u32 flags) {
    f32 u1;
    f32 v1;
    Unk_GetCoords(a, &u1, &v1);
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    target->Unk_49d250(0, 1, 1, 0, 0);
    CRenderTexture::Unk_49cf50(nullptr, nullptr);
    bool simple = true;
    for (s32 i = 0; i < 8; i++) {
        if (params[i].field_0[1].field_0 != 1.0f) {
            simple = false;
            break;
        }
    }
    s32 technique = !simple ? field_30.field_7a8c[index] : field_30.field_7a34[index];
    if (technique == 0) {
        technique = field_30.field_7a34[index];
        simple = true;
    }
    field_30.field_0->vf29(technique);
    for (s32 i = 0; i < 8; i++) {
        Unk_24e4c18[i] = Unk_Float4(u1 * 0.5f, v1 * 0.5f, 0.0f, 0.0f);
        if (simple) {
            Unk_24e4c18[8 + i] = Unk_Float4(Unk_24e2d50[i].field_0 * scale, Unk_24e2d50[i].field_4 * scale,
                                            scale * 0.0f, scale * 0.0f);
        } else {
            Unk_24e4c18[8 + i] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
        }
    }
    field_30.field_0->vf22(field_30.field_c4, Unk_24e4c18, 16);
    Unk_Float4 values[8];
    for (s32 i = 0; i < 8; i++) {
        f32 x = params[i].field_0[0].field_0;
        values[i].field_0[0] = x != 0.0f ? 1.0f / x : 1000.0f;
        values[i].field_0[1] = 0.0f;
        values[i].field_0[2] = params[i].field_0[2];
        values[i].field_0[3] = params[i].field_0[3];
    }
    field_30.field_0->vf22(field_30.field_cc, values, 8);
    f32 aspect = static_cast<f32>(static_cast<u32>(a->field_54)) / static_cast<f32>(static_cast<u32>(a->field_58));
    f32 sx = aspect > 1.0f ? u1 / aspect : u1;
    Unk_Float4 data[19];
    f32 sy = aspect > 1.0f ? v1 : v1 * aspect;
    f32 kx = 2.0f / sx;
    f32 ox = -1.0f / sx;
    f32 oy = -1.0f / sy;
    f32 ky = 2.0f / sy;
    data[8] = Unk_Float4(kx, ky, ox, oy);
    data[9] = Unk_Float4(1.0f / kx, 1.0f / ky, -ox / kx, -oy / ky);
    data[10] = Unk_Float4(0.0f, 0.0f, u1, v1);
    for (s32 i = 0; i < 8; i++) {
        data[i] = Unk_Float4(params[i].field_0[1], 0.0f, 0.0f, 0.0f);
        data[11 + i] = Unk_Float4(Unk_24e2d50[i].field_0 * scale, Unk_24e2d50[i].field_4 * scale, scale * 0.0f,
                                  scale * 0.0f);
    }
    field_30.field_0->vf22(field_30.field_c8, data, 19);
    field_30.field_0->vf22(field_30.field_d0, colors, 8);
    field_30.field_0->vf26(field_30.field_10[0], Unk_GetTexture(a));
    field_30.field_0->vf26(field_30.field_10[1], Unk_GetTexture(b));
    field_30.field_0->vf26(field_30.field_10[2], Unk_GetTexture(c));
    field_30.field_0->vf26(field_30.field_10[3], Unk_GetTexture(d));
    field_30.field_0->vf26(field_30.field_10[4], trim);
    Unk_GPUTexture* textureA = Unk_GetTexture(a);
    Unk_GPUTexture* textureB = Unk_GetTexture(b);
    Unk_GPUTexture* textureC = Unk_GetTexture(c);
    Unk_GPUTexture* textureD = Unk_GetTexture(d);
    s32 filterA = textureA->vf16();
    textureA->vf15(2);
    s32 filterB = textureB->vf16();
    textureB->vf15(2);
    s32 filterC = textureC->vf16();
    textureC->vf15(2);
    s32 filterD = textureD->vf16();
    textureD->vf15(2);
    s32 filterTrim = trim->vf16();
    trim->vf15(2);
    s32 result = Unk_471c50(0.0f, 0.0f, width, height, 0.0f, 0.0f, u1, v1, flags | 0x10000);
    textureA->vf15(filterA);
    textureB->vf15(filterB);
    textureC->vf15(filterC);
    textureD->vf15(filterD);
    trim->vf15(filterTrim);
    return result;
}

// GPUTEXTUREUTIL_SECOND_HALF_END

}  // namespace PPFX

