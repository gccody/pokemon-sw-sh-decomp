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
#include <string.h>

#include <miniz/miniz_yebis.h>
#include <types.h>
#include <yebis/YEBIS_draft/src/GPU/GPUTextureUtil.h>
#include <yebis/YEBIS_draft/src/Unk_415f40.h>
#include <yebis/YEBIS_draft/src/GPU/TinyEffect/TFXString.h>

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

// The static variables of YEBIS's src/GPU code (each helper's suffix table and
// the flag that says it is filled in), where the executable has them. LLVM
// merged the internal globals of that TU (every src/GPU file, by the functions
// that use this block: 0x7100462fe0 to 0x7100499b70) into one object, so the
// code addresses them from one base, and it shrank each flag, a static bool
// only ever set to true, to one bit: the code tests bit 0 of its byte. Until
// the whole TU is here they can't be defined, so they are declared as the
// block they became.
struct Unk_24e45d0_Statics {
    u8 field_0;  // Unk_462fe0's
    u8 field_1;  // Unk_463500's
    u8 field_2;  // Unk_463750's
    u8 field_3;  // Unk_463980's
    u8 field_4;  // Unk_463a70's
    u8 _5[0x160 - 0x5];
    const char* field_160[7];  // Unk_463750's
    const char* field_198[2];  // Unk_463980's
    const char* field_1a8[7];  // Unk_463a70's
    u8 _1e0[0x318 - 0x1e0];
    const char* field_318[16];  // Unk_463500's
    const char* field_398[22];  // Unk_462fe0's
    // 0x71024e4a18 and 0x71024e4c18: the DrawRectGPU functions' scratch
    // vectors, written just before the effect reads them. They are in this
    // block (an element with a variable index is addressed from its start),
    // and their sizes matter: the compiler folds an element's constant offset
    // into the address it materialises only when it is inside the object.
    Unk_Float4 field_448[32];
    Unk_Float4 field_648[32];
};
PKMN_OFFSET_ASSERT(Unk_24e45d0_Statics, field_160, 0x160);
PKMN_OFFSET_ASSERT(Unk_24e45d0_Statics, field_398, 0x398);
PKMN_OFFSET_ASSERT(Unk_24e45d0_Statics, field_448, 0x448);
PKMN_OFFSET_ASSERT(Unk_24e45d0_Statics, field_648, 0x648);
extern Unk_24e45d0_Statics Unk_24e45d0 __attribute__((visibility("hidden")));

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
inline f32 Unk_Coord(f32 position, f32 size) {
    f32 scale = 1.0f / size;
    return scale * (position - size * 0.5f) / (scale - 1.0f) * 2.0f - 1.0f;
}
inline f32 Unk_Distance(const Unk_Float2* position, const Unk_Float2* size) {
    f32 x = Unk_Coord(position->field_0[0].field_0, size->field_0[0].field_0);
    f32 y = Unk_Coord(position->field_0[1].field_0, size->field_0[1].field_0);
    return Unk_Sqrt(x * x + y * y);
}

// 0x7100461e00: 1 inside `inner`, falling to 0 at the edge
// NON_MATCHING: the instructions are the original's, but the original
// computes the second coordinate's offset before its scale's division (and
// its registers follow).
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
f32 CTextureUtil::Unk_47c2f0(s32 encoding, s32 mode, const f32* params, f32 value, f32 base, f32 scale, f32 exponent,
                             f32 gamma, f32 threshold, f32 count, f32 arg0, f32 arg1, f32 exposure) {
    f32 x = value / scale;
    f32 limit = 1000.0f / scale;
    f32 white = powf(base, exponent);
    if (encoding != -1 && threshold > 1.0f) {
        white = powf(Unk_Encode(encoding, white), gamma);
    }
    return Unk_47c090(x, mode, params, white, limit, count, arg0, arg1, exposure) * scale;
}

// 0x7100462fe0: the technique `name` for each pair of HDR formats
s32 TEXSHADERSET::Unk_462fe0(s32* techniques, const char* name) {
    if (!(Unk_24e45d0.field_0 & 1)) {
        Unk_24e45d0.field_0 = 1;
        Unk_24e45d0.field_398[0] = "";
        Unk_24e45d0.field_398[1] = "_REINHARDRGB_RGB";
        Unk_24e45d0.field_398[2] = "_REINHARDRGB_RGBFAST";
        Unk_24e45d0.field_398[3] = "_RGB_REINHARDRGB";
        Unk_24e45d0.field_398[4] = "_REINHARDRGBLUM_RGB";
        Unk_24e45d0.field_398[5] = "_REINHARDRGBLUM_RGBFAST";
        Unk_24e45d0.field_398[6] = "_RGB_REINHARDRGBLUM";
        Unk_24e45d0.field_398[7] = "_LOGRGB_RGB";
        Unk_24e45d0.field_398[8] = "_LOGRGB_RGBFAST";
        Unk_24e45d0.field_398[9] = "_RGB_LOGRGB";
        Unk_24e45d0.field_398[10] = "_LOGRGBLUM_RGB";
        Unk_24e45d0.field_398[11] = "_LOGRGBLUM_RGBFAST";
        Unk_24e45d0.field_398[12] = "_RGB_LOGRGBLUM";
        Unk_24e45d0.field_398[13] = "_RGBALUM_RGB";
        Unk_24e45d0.field_398[14] = "_RGBALUM_RGBFAST";
        Unk_24e45d0.field_398[15] = "_RGB_RGBALUM";
        Unk_24e45d0.field_398[16] = "_REINHARDRGB_REINHARDRGB";
        Unk_24e45d0.field_398[17] = "_REINHARDRGBLUM_REINHARDRGBLUM";
        Unk_24e45d0.field_398[18] = "_LOGRGB_LOGRGB";
        Unk_24e45d0.field_398[19] = "_LOGRGBLUM_LOGRGBLUM";
        Unk_24e45d0.field_398[20] = "_RGBALUM_RGBALUM";
        Unk_24e45d0.field_398[21] = "_ALPHA_RGB";
    }
    Unk_TFXString text(name);
    s32 length = text.field_0;
    s32 result = 0;
    for (s32 i = 0; i < 22; i++) {
        text.Unk_451530(length);
        text += Unk_24e45d0.field_398[i];
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
    if (!(Unk_24e45d0.field_1 & 1)) {
        Unk_24e45d0.field_1 = 1;
        Unk_24e45d0.field_318[0] = "_LINEAR";
        Unk_24e45d0.field_318[2] = "_REINHARD";
        Unk_24e45d0.field_318[3] = "_REINHARD_PREMAP";
        Unk_24e45d0.field_318[4] = "_REINHARDLUM";
        Unk_24e45d0.field_318[5] = "_REINHARDLUM_PREMAP";
        Unk_24e45d0.field_318[6] = "_LOG";
        Unk_24e45d0.field_318[7] = "_LOG_PREMAP";
        Unk_24e45d0.field_318[8] = "_LOGLUM";
        Unk_24e45d0.field_318[9] = "_LOGLUM_PREMAP";
        Unk_24e45d0.field_318[10] = "";
        Unk_24e45d0.field_318[11] = "_SENSITOMETRIC_PREMAP";
        Unk_24e45d0.field_318[12] = "_REINHARD_LINEARSAT_PREMAP";
        Unk_24e45d0.field_318[13] = "_REINHARD_SENSITOMETRIC_PREMAP";
        Unk_24e45d0.field_318[14] = "_LINEARSAT";
        Unk_24e45d0.field_318[15] = "_ALPHALUM_PREMAP";
        Unk_24e45d0.field_318[1] = "_LINEARSAT";
    }
    Unk_TFXString prefix(name);
    Unk_TFXString text(prefix);
    s32 length = text.field_0;
    s32 result = 0;
    for (s32 i = 0; i < 16; i++) {
        text.Unk_451530(length);
        text += Unk_24e45d0.field_318[i];
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
    if (!(Unk_24e45d0.field_2 & 1)) {
        Unk_24e45d0.field_2 = 1;
        Unk_24e45d0.field_160[0] = "_RVALUE";
        Unk_24e45d0.field_160[1] = "_GVALUE";
        Unk_24e45d0.field_160[2] = "_BVALUE";
        Unk_24e45d0.field_160[3] = "_AVALUE";
        Unk_24e45d0.field_160[4] = "_RGBA8";
        Unk_24e45d0.field_160[5] = "_ARGB8";
        Unk_24e45d0.field_160[6] = "_ABGR8";
    }
    Unk_TFXString prefix(name);
    s32 result = 0;
    for (s32 i = 0; i < 7; i++) {
        Unk_TFXString full = prefix + Unk_24e45d0.field_160[i];
        s32 error = Unk_462fe0(techniques[i], full.field_8);
        if (error < 0)
            result = error;
    }
    return result;
}

// 0x7100463980: Unk_463750 with and without _USNORM
s32 TEXSHADERSET::Unk_463980(s32 (*techniques)[7][22], const char* name) {
    if (!(Unk_24e45d0.field_3 & 1)) {
        Unk_24e45d0.field_3 = 1;
        Unk_24e45d0.field_198[0] = "";
        Unk_24e45d0.field_198[1] = "_USNORM";
    }
    Unk_TFXString prefix(name);
    s32 result = 0;
    for (s32 i = 0; i < 2; i++) {
        Unk_TFXString full = prefix + Unk_24e45d0.field_198[i];
        s32 error = Unk_463750(techniques[i], full.field_8);
        if (error < 0)
            result = error;
    }
    return result;
}

// 0x7100463a70: Unk_463500 for each set of the tone map's seven options
s32 TEXSHADERSET::Unk_463a70(s32 (*techniques)[16], const char* name) {
    if (!(Unk_24e45d0.field_4 & 1)) {
        Unk_24e45d0.field_4 = 1;
        Unk_24e45d0.field_1a8[0] = "_PreMatrix";
        Unk_24e45d0.field_1a8[1] = "_Dither";
        Unk_24e45d0.field_1a8[2] = "_Vignette";
        Unk_24e45d0.field_1a8[3] = "_VignetteSim";
        Unk_24e45d0.field_1a8[4] = "_Exposure";
        Unk_24e45d0.field_1a8[5] = "_Matrix";
        Unk_24e45d0.field_1a8[6] = "_Gamma";
    }
    Unk_TFXString prefix(name);
    Unk_TFXString text(prefix);
    s32 length = text.field_0;
    s32 result = 0;
    for (s32 i = 0; i < 128; i++) {
        text.Unk_451530(length);
        for (s32 j = 0; j < 7; j++)
            if (i & (1 << j))
                text += Unk_24e45d0.field_1a8[j];
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
    Unk_GetTechs(field_1d024, "tech_MotionBlurVelocityDirDepthT2_Sn", 8);
    Unk_GetTechs(field_1e0a4, "tech_MotionBlurVelocityDirDepth_SM3_T2_Sn", 8);
    Unk_GetTechs(field_1d2e4, "tech_MotionBlurVelocityDirDepthInnerscreenT2_Sn", 8);
    Unk_GetTechs(field_1e364, "tech_MotionBlurVelocityDirDepthInnerscreen_SM3_T2_Sn", 8);
    Unk_GetTechs(field_1f124, "tech_MotionBlurVelocityDirDepthClampT2_Sn", 8);
    Unk_GetTechs(field_201a4, "tech_MotionBlurVelocityDirDepthClamp_SM3_T2_Sn", 8);
    Unk_GetTechs(field_1f3e4, "tech_MotionBlurVelocityDirDepthInnerscreenClampT2_Sn", 8);
    Unk_GetTechs(field_20464, "tech_MotionBlurVelocityDirDepthInnerscreenClamp_SM3_T2_Sn", 8);
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
s32 CTextureUtil::Unk_470880() {
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
            Unk_24e45d0.field_648[i] = matrix[i];
        }
    } else {
        memset(Unk_24e45d0.field_648, 0, sizeof(Unk_Float4) * 4);
    }
    field_30.field_0->vf22(field_30.field_c4, Unk_24e45d0.field_648, 4);
    field_30.field_0->vf22(field_30.field_c8, Unk_24e45d0.field_648, 0);
    Unk_24e45d0.field_648[0] = Unk_Float4(arg9, 1.0f / arg9, arg10, arg11);
    Unk_24e45d0.field_648[1] = *arg1;
    Unk_24e45d0.field_648[2] = *arg2;
    Unk_24e45d0.field_648[3].field_0[0] = arg12;
    Unk_24e45d0.field_648[3].field_0[1] = arg13;
    field_30.field_0->vf22(field_30.field_d0, Unk_24e45d0.field_648, 4);
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
        Unk_24e45d0.field_648[0].field_0[0] = source->field_88;
        Unk_24e45d0.field_648[0].field_0[1] = source->field_8c;
        Unk_24e45d0.field_648[0].field_0[2] = 0.0f;
        Unk_24e45d0.field_648[0].field_0[3] = 0.0f;
        field_30.field_0->vf22(field_30.field_d4, Unk_24e45d0.field_648, 1);
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
        Unk_24e45d0.field_448[0] = *arg3;
        Unk_24e45d0.field_448[1] = *arg4;
        Unk_24e45d0.field_448[2] = *arg5;
        Unk_24e45d0.field_448[3] = *arg6;
        field_30.field_0->vf22(field_30.field_d0, Unk_24e45d0.field_448, 4);
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
    Unk_24e45d0.field_648[0] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
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
        Unk_24e45d0.field_648[1 + i * 2] = Unk_Float4(dx, dy, weight, 0.0f);
        Unk_24e45d0.field_648[2 + i * 2] = Unk_Float4(-dx, -dy, weight, 0.0f);
    }
    field_30.field_0->vf22(field_30.field_c8, Unk_24e45d0.field_648, count);
    field_30.field_0->vf22(field_30.field_c4, Unk_24e45d0.field_648, count < 8 ? count : 8);
    Unk_24e45d0.field_648[0] = Unk_Float4(0.0f, -1.0f / (2.0f * arg10 * arg10), -1.0f / (2.0f * arg11 * arg11), 0.0f);
    field_30.field_0->vf22(field_30.field_cc, Unk_24e45d0.field_648, 1);
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
s32 CTextureUtil::Unk_4772f0(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 power,
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
    Unk_24e45d0.field_648[0] = *value;
    field_30.field_0->vf22(field_30.field_d4, Unk_24e45d0.field_648, 1);
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
    Unk_24e45d0.field_648[0].field_0[0] = value->field_0[0];
    Unk_24e45d0.field_648[0].field_0[1] = value->field_0[1];
    field_30.field_0->vf22(field_30.field_d0, Unk_24e45d0.field_648, 1);
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
    Unk_24e45d0.field_648[0] = *value;
    Unk_24e45d0.field_648[1].field_0[0] = 1.0f / arg18;
    Unk_24e45d0.field_648[1].field_0[1] = -arg17 / arg18;
    field_30.field_0->vf22(field_30.field_d4, Unk_24e45d0.field_648, 2);
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
    Unk_24e45d0.field_648[0].field_0[0] = arg3->field_0[0];
    Unk_24e45d0.field_648[0].field_0[1] = arg3->field_0[1];
    Unk_24e45d0.field_648[0].field_0[2] = arg4->field_0[0];
    Unk_24e45d0.field_648[0].field_0[3] = arg4->field_0[1];
    Unk_24e45d0.field_648[2].field_0[0].field_0 = 1.0f / arg3->field_0[0].field_0;
    Unk_24e45d0.field_648[2].field_0[1].field_0 = 1.0f / arg3->field_0[1].field_0;
    f32 scale = arg5->field_0[0].field_0;
    f32 offset = arg5->field_0[1].field_0;
    Unk_24e45d0.field_648[2].field_0[2].field_0 = 1.0f / scale;
    Unk_24e45d0.field_648[2].field_0[3].field_0 = -offset / scale;
    Unk_24e45d0.field_648[1].field_0[0] = arg7->field_0[0];
    Unk_24e45d0.field_648[1].field_0[1] = arg7->field_0[1];
    if (hasFalloff) {
        Unk_24e45d0.field_648[1].field_0[2].field_0 = falloff->field_0[0].field_0 / 0.99609375f;
        Unk_24e45d0.field_648[1].field_0[3].field_0 = falloff->field_0[1].field_0 - 0.00390625f;
    } else {
        Unk_24e45d0.field_648[1].field_0[2].field_0 = 0.0f;
        Unk_24e45d0.field_648[1].field_0[3].field_0 = 0.0f;
    }
    field_30.field_0->vf22(field_30.field_d0, Unk_24e45d0.field_648, 3);
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
    Unk_24e45d0.field_448[0] = *arg2;
    if (arg3 != nullptr) {
        Unk_24e45d0.field_448[1] = arg3[0];
        Unk_24e45d0.field_448[2] = arg3[1];
    } else {
        Unk_24e45d0.field_448[1] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
        Unk_24e45d0.field_448[2] = Unk_Float4(64512.0f, 64512.0f, 64512.0f, 64512.0f);
    }
    field_30.field_0->vf22(field_30.field_d0, arg1, 1);
    field_30.field_0->vf22(field_30.field_d4, Unk_24e45d0.field_448, 3);
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
s32 CTextureUtil::Unk_477350(f32 x, f32 y, f32 width, f32 height, f32 u0, f32 v0, f32 u1, f32 v1, f32 power,
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
            Unk_24e45d0.field_448[i] = colors[i];
        }
    } else {
        for (s32 i = 0; i < count; i++) {
            Unk_24e45d0.field_448[i] = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
        }
    }
    s32 used = last + 1;
    for (s32 i = count; i <= last; i++) {
        Unk_24e45d0.field_448[i] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    if (arg4 == nullptr) {
        Unk_24e45d0.field_448[16] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
        Unk_24e45d0.field_448[17] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
        Unk_24e45d0.field_448[18] = Unk_Float4(64512.0f, 64512.0f, 64512.0f, 64512.0f);
        arg4 = &Unk_24e45d0.field_448[16];
    }
    field_30.field_0->vf22(field_30.field_d0, Unk_24e45d0.field_448, used);
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
            Unk_24e45d0.field_648[i] = values[i];
        }
    } else {
        for (s32 i = 0; i < first; i++) {
            Unk_24e45d0.field_648[i] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
        }
    }
    for (s32 i = first; i < firstTotal; i++) {
        Unk_24e45d0.field_648[i] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    field_30.field_0->vf22(field_30.field_c4, Unk_24e45d0.field_648, firstTotal);
    if (values != nullptr) {
        for (s32 i = 0; i < rest; i++) {
            const Unk_Float4& value = values[max + i];
            Unk_24e45d0.field_648[i] = Unk_Float4(value.field_0[0].field_0 - values[0].field_0[0].field_0,
                                                 value.field_0[1].field_0 - values[0].field_0[1].field_0,
                                                 value.field_0[2].field_0 - values[0].field_0[2].field_0,
                                                 value.field_0[3].field_0 - values[0].field_0[3].field_0);
        }
    } else {
        for (s32 i = 0; i < rest; i++) {
            Unk_24e45d0.field_648[i] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
        }
    }
    for (s32 i = rest; i < restTotal; i++) {
        Unk_24e45d0.field_648[i] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    field_30.field_0->vf22(field_30.field_c8, Unk_24e45d0.field_648, restTotal);
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
            Unk_24e45d0.field_448[i] = colors[i];
        }
    } else {
        for (s32 i = 0; i < count; i++) {
            Unk_24e45d0.field_448[i] = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
        }
    }
    field_30.field_0->vf22(field_30.field_d0, Unk_24e45d0.field_448, count);
    Unk_24e45d0.field_648[0] = *arg4;
    if (Unk_24e45d0.field_648[0].field_0[2].field_0 > Unk_24e45d0.field_648[0].field_0[3].field_0) {
        f32 swap = Unk_24e45d0.field_648[0].field_0[2].field_0;
        Unk_24e45d0.field_648[0].field_0[2].field_0 = Unk_24e45d0.field_648[0].field_0[3].field_0;
        Unk_24e45d0.field_648[0].field_0[3].field_0 = swap;
    }
    field_30.field_0->vf22(field_30.field_d4, Unk_24e45d0.field_648, 1);
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
            Unk_24e45d0.field_448[i] = colors[i];
        }
    } else {
        for (s32 i = 0; i < count; i++) {
            Unk_24e45d0.field_448[i] = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
        }
    }
    for (s32 i = count; i < used; i++) {
        Unk_24e45d0.field_448[i] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    field_30.field_0->vf22(field_30.field_d0, Unk_24e45d0.field_448, used);
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
            Unk_24e45d0.field_448[i] = colors[i];
        }
    } else {
        for (s32 i = 0; i < count; i++) {
            Unk_24e45d0.field_448[i] = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
        }
    }
    for (s32 i = count; i <= last; i++) {
        Unk_24e45d0.field_448[i] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    field_30.field_0->vf22(field_30.field_d0, Unk_24e45d0.field_448, used);
    if (texture != nullptr) {
        field_30.field_0->vf26(field_30.field_10[0], texture);
    }
    lut->vf15(4);
    field_30.field_0->vf26(field_30.field_50[0], lut);
    f32 lutWidth = static_cast<f32>(lut->field_4c);
    f32 lutHeight = static_cast<f32>(lut->field_50);
    f32 lutDepth = static_cast<f32>(lut->field_84);
    Unk_24e45d0.field_648[0].field_0[0].field_0 = (lutWidth - 1.0f) / lutWidth;
    Unk_24e45d0.field_648[0].field_0[1].field_0 = (lutHeight - 1.0f) / lutHeight;
    Unk_24e45d0.field_648[0].field_0[2].field_0 = (lutDepth - 1.0f) / lutDepth;
    Unk_24e45d0.field_648[0].field_0[3].field_0 = 0.0f;
    Unk_24e45d0.field_648[1].field_0[0].field_0 = 0.5f / lutWidth;
    Unk_24e45d0.field_648[1].field_0[1].field_0 = 0.5f / lutHeight;
    Unk_24e45d0.field_648[1].field_0[2].field_0 = 0.5f / lutDepth;
    Unk_24e45d0.field_648[1].field_0[3].field_0 = 0.5f;
    field_30.field_0->vf22(field_30.field_d4, Unk_24e45d0.field_648, 2);
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
            Unk_24e45d0.field_448[i] = colors[i];
        }
    } else {
        for (s32 i = 0; i < count; i++) {
            Unk_24e45d0.field_448[i] = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
        }
    }
    for (s32 i = count; i < used; i++) {
        Unk_24e45d0.field_448[i] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    field_30.field_0->vf22(field_30.field_d0, Unk_24e45d0.field_448, used);
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
        Unk_24e45d0.field_648[i] = values[i];
    }
    for (s32 i = first; i < firstTotal; i++) {
        Unk_24e45d0.field_648[i] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    field_30.field_0->vf22(field_30.field_c4, Unk_24e45d0.field_648, firstTotal);
    for (s32 i = 0; i < rest; i++) {
        const Unk_Float4& value = values[8 + i];
        Unk_24e45d0.field_648[i] = Unk_Float4(value.field_0[0].field_0 - values[0].field_0[0].field_0,
                                             value.field_0[1].field_0 - values[0].field_0[1].field_0,
                                             value.field_0[2].field_0 - values[0].field_0[2].field_0,
                                             value.field_0[3].field_0 - values[0].field_0[3].field_0);
    }
    for (s32 i = rest; i < restTotal; i++) {
        Unk_24e45d0.field_648[i] = Unk_Float4(-values[0].field_0[0].field_0, -values[0].field_0[1].field_0,
                                             -values[0].field_0[2].field_0, -values[0].field_0[3].field_0);
    }
    field_30.field_0->vf22(field_30.field_c8, Unk_24e45d0.field_648, restTotal);
    // the weights fill the vectors' array four to an element
    for (s32 i = 0; i < count; i++) {
        Unk_24e45d0.field_448[0].field_0[i].field_0 = weights[i];
    }
    for (s32 i = count; i < used; i++) {
        Unk_24e45d0.field_448[0].field_0[i].field_0 = 0.0f;
    }
    field_30.field_0->vf22(field_30.field_d0, Unk_24e45d0.field_448, (used + 3) / 4);
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
    Unk_24e45d0.field_448[0] = *arg1;
    Unk_24e45d0.field_448[1] = *arg2;
    field_30.field_0->vf22(field_30.field_d0, Unk_24e45d0.field_448, 2);
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
        Unk_412cd0(1.0f, texture->field_4c, texture->field_50, Unk_24e45d0.field_648);
        field_30.field_0->vf22(field_30.field_c4, Unk_24e45d0.field_648, 5);
        field_30.field_0->vf22(field_30.field_c8, Unk_24e45d0.field_648, 0);
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
            Unk_24e45d0.field_448[i] = colors[i];
        }
    } else {
        for (s32 i = 0; i < count; i++) {
            Unk_24e45d0.field_448[i] = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
        }
    }
    field_30.field_0->vf22(field_30.field_d0, Unk_24e45d0.field_448, count);
    if (texture != nullptr) {
        field_30.field_0->vf26(field_30.field_10[0], texture);
    }
    return Unk_473150(x, y, width, height, u0, v0, u1, v1, count, flags);
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
    Unk_24e45d0.field_648[0].field_0[0].field_0 = 0.0f;
    Unk_24e45d0.field_648[0].field_0[1].field_0 = 0.0f;
    f32 textureWidth = static_cast<f32>(texture0->field_4c);
    Unk_24e45d0.field_648[0].field_0[2].field_0 = textureWidth;
    f32 textureHeight = static_cast<f32>(texture0->field_50);
    Unk_24e45d0.field_648[0].field_0[3].field_0 = textureHeight;
    Unk_24e45d0.field_648[1].field_0[0].field_0 = 1.0f / textureWidth;
    Unk_24e45d0.field_648[1].field_0[1].field_0 = 1.0f / textureHeight;
    Unk_24e45d0.field_648[1].field_0[2].field_0 = 0.5f / textureWidth;
    Unk_24e45d0.field_648[1].field_0[3].field_0 = 0.5f / textureHeight;
    field_30.field_0->vf22(field_30.field_d4, Unk_24e45d0.field_648, 2);
    Unk_24e45d0.field_648[0].field_0[0].field_0 = logf(arg9 + 1.0f) / 0.6931472f;
    Unk_24e45d0.field_648[0].field_0[1].field_0 = -1.0f / (2.0f * arg10 * arg10);
    Unk_24e45d0.field_648[0].field_0[2].field_0 = -1.0f / (2.0f * arg11 * arg11);
    Unk_24e45d0.field_648[0].field_0[3].field_0 = 0.0f;
    field_30.field_0->vf22(field_30.field_cc, Unk_24e45d0.field_648, 1);
    Unk_24e45d0.field_448[0].field_0[0].field_0 = arg19->field_0[0];
    Unk_24e45d0.field_448[0].field_0[1].field_0 = arg19->field_0[1];
    Unk_24e45d0.field_448[0].field_0[2].field_0 = arg19->field_0[2];
    Unk_24e45d0.field_448[0].field_0[3].field_0 = 0.0f;
    Unk_24e45d0.field_448[1].field_0[0].field_0 = arg22->field_0[0];
    Unk_24e45d0.field_448[1].field_0[1].field_0 = arg22->field_0[1];
    Unk_24e45d0.field_448[1].field_0[2].field_0 = arg22->field_0[2];
    Unk_24e45d0.field_448[1].field_0[3].field_0 = 0.0f;
    Unk_24e45d0.field_448[2].field_0[0].field_0 = arg23->field_0[0];
    Unk_24e45d0.field_448[2].field_0[1].field_0 = arg23->field_0[1];
    Unk_24e45d0.field_448[2].field_0[2].field_0 = arg23->field_0[2];
    Unk_24e45d0.field_448[2].field_0[3].field_0 = 0.0f;
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
        Unk_24e45d0.field_448[3] = first;
        Unk_24e45d0.field_448[4] = second;
    }
    field_30.field_0->vf22(field_30.field_d0, Unk_24e45d0.field_448, 5);
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

// 0x7100478880
f32 Unk_478880(f32 arg1, f32 arg2) {
    return arg1 / arg2;
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
// field_29994 with the curve of `a`, `b` and `c` in the scratch vectors
s32 CTextureUtil::Unk_480740(CRenderTexture* target, bool second, bool positive, const void* value, bool clear,
                             u32 flags, f32 a, f32 b, f32 c) {
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
    f32* v = &Unk_24e45d0.field_648[0].field_0[0].field_0;
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
    field_30.field_0->vf22(field_30.field_d0, Unk_24e45d0.field_648, 12);
    field_30.field_0->vf24(field_30.field_10c, value);
    return Unk_471c50(0.0f, 0.0f, w, h, 0.0f, 0.0f, 1.0f, 1.0f, flags);
}

// GPUTEXTUREUTIL_SECOND_HALF_BEGIN: functions of 0x7100481000 on

// 0x710048d020: `source` blurred into `target` with Unk_413160's samples of
// its first level (`mask`'s texture as the mask)
// NON_MATCHING: registers and scheduling only: the source's and the target's
// sizes are loaded into s15/s14 and s13/s12 in the original (s14/s15, s12/s13
// here), the device's load and the zero clamp's `csel` come one instruction
// apart. Tried: the reads and the clamp in other orders.
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
    u32 levelWidth = level->field_8;
    u32 levelHeight = level->field_c;
    u32 mode = second == 1 ? 0x21 : 0x11;
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
// NON_MATCHING: the five offsets are copied to Unk_24e45d0 in 64-bit halves
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
        Unk_24e45d0.field_648[i] = offsets[i];
    }
    field_30.field_0->vf22(field_30.field_c4, Unk_24e45d0.field_648, 5);
    field_30.field_0->vf22(field_30.field_c8, Unk_24e45d0.field_648, 0);
    Unk_24e45d0.field_448[0] = Unk_Float4(reinterpret_cast<const Unk_Float*>(scaleOffset)[0],
                                          reinterpret_cast<const Unk_Float*>(scaleOffset)[1], arg8, 0.0f);
    s32 count = 1;
    if (arg12 != nullptr) {
        const Unk_Float2* value = static_cast<const Unk_Float2*>(arg12);
        Unk_24e45d0.field_448[1] = Unk_Float4(value->field_0[0], value->field_0[1], 0.0f, 0.0f);
        count = 2;
    }
    field_30.field_0->vf22(field_30.field_d0, Unk_24e45d0.field_448, count);
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
    Unk_24e45d0.field_448[0] = *static_cast<const Unk_Float4*>(arg14);
    Unk_24e45d0.field_448[1] = Unk_Float4(1.5f, 1.5f, 1.5f, 0.0f);
    Unk_24e45d0.field_448[2] = Unk_Float4(1.0f, 1.0f, 1.0f, 0.0f);
    field_30.field_0->vf22(field_30.field_d0, Unk_24e45d0.field_448, 3);
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

// 0x7100481540
// NON_MATCHING: register allocation; the source's width and height swap
// callee-saved registers (s10/s11), and two loads are scheduled earlier.
s32 CTextureUtil::Unk_481540(CRenderTexture* source, CRenderTexture* target, bool arg2, bool arg3) {
    f32 u1;
    f32 v1;
    Unk_GetCoords(source, &u1, &v1);
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    Unk_Float4 weights[16];
    s32 count = Unk_411df0(source->field_80->field_8, source->field_80->field_c, weights, 4, true, 0,
                           static_cast<f32>(static_cast<u32>(source->field_54)),
                           static_cast<f32>(static_cast<u32>(source->field_58)), width, height, 0.0f, 0.0f, 0.0f);
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
    Unk_24e45d0.field_648[0] = Unk_Float4(1.0f, 1.0f, 1.0f, 0.25f);
    Unk_24e45d0.field_648[1] = Unk_Float4(arg8, 2.3255813f, powf(10.0f, arg9 + 1.0f), inverse);
    Unk_24e45d0.field_648[2] = Unk_Float4(10.0f, arg8, arg9, arg8);
    if (arg12) {
        Unk_24e45d0.field_648[3] = Unk_Float4(1.0f / 3.0f, 1.0f / 3.0f, 1.0f / 3.0f, 1.0f / 3.0f);
        Unk_24e45d0.field_648[4] = Unk_Float4(0.0f, 1.0f / 3.0f, 2.0f / 3.0f, 0.0f);
    } else {
        Unk_24e45d0.field_648[3] = Unk_Float4(1.0f, 1.0f, 1.0f, 1.0f);
        Unk_24e45d0.field_648[4] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    field_30.field_0->vf22(field_30.field_d0, Unk_24e45d0.field_648, 5);
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
        Unk_24e45d0.field_648[0] = Unk_Float4(1.0f / 3000.0f, 1.0f, 0.01f, 0.0f);
        field_30.field_0->vf22(field_30.field_d0, Unk_24e45d0.field_648, 1);
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
    Unk_24e45d0.field_448[0].field_0[0].field_0 = arg8;
    Unk_24e45d0.field_448[0].field_0[1].field_0 = arg9;
    field_30.field_0->vf22(field_30.field_d0, Unk_24e45d0.field_448, 1);
    Unk_24e45d0.field_648[0] = *arg12;
    field_30.field_0->vf22(field_30.field_c4, Unk_24e45d0.field_648, 1);
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
    Unk_24e45d0.field_448[0].field_0[0].field_0 = static_cast<f32>(arg11);
    Unk_24e45d0.field_448[0].field_0[1].field_0 = static_cast<f32>(arg12);
    f32 amount = static_cast<f32>(arg13) / 100.0f;
    Unk_24e45d0.field_448[0].field_0[2].field_0 = amount < 0.0f ? 0.0f : (amount < 1.0f ? amount : 1.0f);
    field_30.field_0->vf22(field_30.field_d0, Unk_24e45d0.field_448, 1);
    Unk_24e45d0.field_648[0] = *arg10;
    field_30.field_0->vf22(field_30.field_c4, Unk_24e45d0.field_648, 1);
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
        Unk_24e45d0.field_448[0].field_0[1] = arg12->field_0[0];
        Unk_24e45d0.field_448[0].field_0[2] = arg12->field_0[1];
    }
    field_30.field_0->vf22(field_30.field_d0, Unk_24e45d0.field_448, 1);
    Unk_24e45d0.field_648[0] = *arg11;
    field_30.field_0->vf22(field_30.field_c4, Unk_24e45d0.field_648, 1);
    result = Unk_471c50(x, y, width, height, u0, v0, u1, v1, flags);
    texture0->vf15(filter0);
    texture1->vf15(filter1);
    return result;
}

// 0x7100489c50
s32 CTextureUtil::Unk_489c50(f32 x, f32 y, f32 width, f32 height, Unk_GPUTexture* texture, f32 arg4, f32 arg5,
                             const Unk_Float2* arg9, f32 arg6, f32 arg7, s32 mode, s32 index, u32 flags) {
    s32 set = mode == 1;
    s32 technique = (&field_30.field_7b3c)[set][index];
    if (technique == 0)
        return -4;
    field_30.field_0->vf29(technique);
    Unk_Float u = arg9->field_0[0];
    Unk_Float v = arg9->field_0[1];
    Unk_24e45d0.field_448[0].field_0[0] = u;
    Unk_24e45d0.field_448[0].field_0[1] = v;
    Unk_24e45d0.field_448[0].field_0[2].field_0 = arg5 * arg6 / arg4;
    Unk_24e45d0.field_448[0].field_0[3].field_0 = arg6;
    Unk_24e45d0.field_448[1].field_0[0].field_0 = arg7;
    field_30.field_0->vf22(field_30.field_d0, Unk_24e45d0.field_448, 2);
    field_30.field_0->vf26(field_30.field_10[0], texture);
    s32 saved = texture->vf19();
    texture->vf17(0);
    s32 result = Unk_471960(x, y, width, height, flags);
    texture->vf17(saved);
    return result;
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

// 0x71004816a0
// NON_MATCHING: scheduling and two registers: the source's loads go through the copy of
// its pointer and the target's height and the offset field_90 swap s13/s14.
s32 CTextureUtil::Unk_4816a0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, CRenderTexture* source,
                             CRenderTexture* target, const Unk_Float4* arg7, const Unk_Float4* arg8) {
    f32 u1;
    f32 v1;
    Unk_GetCoords(source, &u1, &v1);
    f32 sourceWidth = static_cast<f32>(static_cast<u32>(source->field_54));
    f32 sourceHeight = static_cast<f32>(static_cast<u32>(source->field_58));
    f32 width = static_cast<f32>(static_cast<u32>(target->field_54));
    f32 height = static_cast<f32>(static_cast<u32>(target->field_58));
    Unk_Float4 weights[4];
    Unk_411df0(source->field_80->field_8, source->field_80->field_c, weights, 2, true, 0, sourceWidth, sourceHeight,
               width, height, 0.5f, 0.5f, 0.0f);
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

// 0x7100499890: the spherical interpolation of two quaternions
// NON_MATCHING: register allocation: the original keeps t and 1.0 in s5/s4
// (copied to v9/v8 around the sqrtf calls) and the first quaternion in
// s10-s13; here 1.0 is in a callee-saved register and its y in s3. The
// equality test's order (z, w, y, x in the source) gives the original's
// x, y, z, w chain.
Unk_Quaternion* Unk_499890(Unk_Quaternion* out, const Unk_Quaternion* from, const Unk_Quaternion* to, f32 t) {
    Unk_Quaternion a = Unk_Normalize(*from);
    Unk_Quaternion b = Unk_Normalize(*to);
    f32 dot = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
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
            a.x = a.x * wa + b.x * wb;
            a.y = a.y * wa + b.y * wb;
            a.z = a.z * wa + b.z * wb;
            a.w = a.w * wa + b.w * wb;
        }
    }
    *out = a;
    return out;
}

// GPUTEXTUREUTIL_SECOND_HALF_END

}  // namespace PPFX

