// Scope: common
// YEBIS's first translation unit (0x710040f610 to 0x7100417870, before
// ppfx.cpp): matrix and filter kernel helpers and the SiReflection
// properties its static initialiser 0x7100415f40 registers. Its name isn't
// in the executable.
#include <math.h>

#include <yebis/YEBIS_draft/src/Unk_415f40.h>

namespace PPFX {

// 0x710040f610: the power of two (below 1 << count) that is `value`, or the
// one above or below it
s32 Unk_40f610(s32 value, bool up, s32 count) {
    for (s32 i = 0; i < count; i++) {
        s32 bit = 1 << i;
        if (bit == value) {
            return bit;
        }
        if (bit > value) {
            return bit >> (up ? 0 : 1);
        }
    }
    return 0;
}

// 0x710040f660: a scale and a translation (without them, 1 and 0)
void Unk_40f660(MATRIXT44* out, const Unk_Vector3* scale, const Unk_Vector3* translation) {
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

// 0x710040f8d0: an off-centre perspective projection
void Unk_40f8d0(MATRIXT44* out, bool arg1, bool arg2, f32 left, f32 right, f32 bottom, f32 top, f32 near, f32 far) {
    f32 sign = arg2 ? 1.0f : -1.0f;
    out->field_0[0][0] = (near + near) / (right - left);
    out->field_0[1][1] = (near + near) / (top - bottom);
    out->field_0[2][0] = sign * ((left + right) / (left - right));
    out->field_0[2][1] = sign * ((bottom + top) / (bottom - top));
    f32 a;
    f32 b;
    if (arg1) {
        a = (near + far) / (far - near);
        b = far * -2.0f * near / (far - near);
    } else {
        a = far / (far - near);
        b = -(near * far) / (far - near);
    }
    out->field_0[2][2] = sign * a;
    out->field_0[2][3] = sign;
    out->field_0[3][2] = b;
    out->field_0[0][1] = out->field_0[0][2] = out->field_0[0][3] = out->field_0[1][0] = out->field_0[1][2] =
        out->field_0[1][3] = out->field_0[3][0] = out->field_0[3][1] = out->field_0[3][3] = 0.0f;
}

// 0x710040f980: the reciprocals of a matrix's first two scales
void Unk_40f980(const MATRIXT44* matrix, f32* x, f32* y) {
    f32 scaleX = 1.0f / matrix->field_0[0][0];
    f32 scaleY = 1.0f / matrix->field_0[1][1];
    if (x != nullptr) {
        *x = scaleX;
    }
    if (y != nullptr) {
        *y = scaleY;
    }
}

// A rotation about a unit axis (inline in the three functions below)
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

// The SVG hueRotate matrix: Unk_HueBase + cos * Unk_HueCos + sin * Unk_HueSin
static const MATRIXT44 Unk_HueBase = {{
    {0.213f, 0.213f, 0.213f, 0.0f},
    {0.715f, 0.715f, 0.715f, 0.0f},
    {0.072f, 0.072f, 0.072f, 0.0f},
    {0.0f, 0.0f, 0.0f, 1.0f},
}};
static const MATRIXT44 Unk_HueCos = {{
    {0.787f, -0.213f, -0.213f, 0.0f},
    {-0.715f, 0.285f, -0.715f, 0.0f},
    {-0.072f, -0.072f, 0.928f, 0.0f},
    {0.0f, 0.0f, 0.0f, 0.0f},
}};
static const MATRIXT44 Unk_HueSin = {{
    {-0.213f, 0.143f, -0.787f, 0.0f},
    {-0.715f, 0.14f, 0.715f, 0.0f},
    {0.928f, -0.283f, 0.072f, 0.0f},
    {0.0f, 0.0f, 0.0f, 0.0f},
}};

static inline void Unk_HueLuminance(MATRIXT44* out, f32 c, f32 s) {
    for (s32 i = 0; i < 4; i++) {
        for (s32 j = 0; j < 4; j++) {
            out->field_0[i][j] = Unk_HueBase.field_0[i][j] + c * Unk_HueCos.field_0[i][j] + s * Unk_HueSin.field_0[i][j];
        }
    }
}

// 0x710040fb30: a hue rotation, about the grey axis or keeping the luminance
// (the SVG hueRotate matrix)
// NON_MATCHING: the same size, another instruction order. Here the last
// stores of the two branches (m[0][3], m[1][3], m[3][3]) are merged into the
// block after them; the original keeps all sixteen in each branch.
MATRIXT44* Unk_40fb30(MATRIXT44* out, bool luminance, f32 angle) {
    if (luminance) {
        f32 s = sinf(angle);
        f32 c = cosf(angle);
        Unk_HueLuminance(out, c, s);
    } else {
        Unk_RotationAxis(out, 0.57735026f, 0.57735026f, 0.57735026f, angle);
    }
    return out;
}

// 0x710040fde0: a rotation from yaw (about y), pitch (about x) and roll
// (about z): roll, then pitch, then yaw
MATRIXT44* Unk_40fde0(MATRIXT44* out, f32 yaw, f32 pitch, f32 roll) {
    MATRIXT44 y;
    Unk_RotationAxis(&y, 0.0f, 1.0f, 0.0f, yaw);
    MATRIXT44 x;
    Unk_RotationAxis(&x, 1.0f, 0.0f, 0.0f, pitch);
    MATRIXT44 z;
    Unk_RotationAxis(&z, 0.0f, 0.0f, 1.0f, roll);
    MATRIXT44 result;
    MATRIXT44 rollPitch;
    MATRIXT44_MatrixMultiply(&rollPitch, &z, &x);
    MATRIXT44_MatrixMultiply(&result, &rollPitch, &y);
    *out = result;
    return out;
}

// 0x710040ffc0: a row vector times a matrix
void Unk_40ffc0(Unk_Float4* out, const Unk_Float4* v, const MATRIXT44* m) {
    f32 x = m->field_0[0][0] * v->field_0[0].field_0 + m->field_0[1][0] * v->field_0[1].field_0 +
            m->field_0[2][0] * v->field_0[2].field_0 + m->field_0[3][0] * v->field_0[3].field_0;
    f32 y = m->field_0[0][1] * v->field_0[0].field_0 + m->field_0[1][1] * v->field_0[1].field_0 +
            m->field_0[2][1] * v->field_0[2].field_0 + m->field_0[3][1] * v->field_0[3].field_0;
    f32 z = m->field_0[0][2] * v->field_0[0].field_0 + m->field_0[1][2] * v->field_0[1].field_0 +
            m->field_0[2][2] * v->field_0[2].field_0 + m->field_0[3][2] * v->field_0[3].field_0;
    f32 w = m->field_0[0][3] * v->field_0[0].field_0 + m->field_0[1][3] * v->field_0[1].field_0 +
            m->field_0[2][3] * v->field_0[2].field_0 + m->field_0[3][3] * v->field_0[3].field_0;
    out->field_0[0].field_0 = x;
    out->field_0[1].field_0 = y;
    out->field_0[2].field_0 = z;
    out->field_0[3].field_0 = w;
}

// 0x7100410070: a point (three elements) through a matrix
// NON_MATCHING: the same instructions in another order. The original does the
// three elements side by side, as the four of Unk_40ffc0 come out; this does
// them one after the other, and so did every other way of writing it.
void Unk_410070(Unk_Vector3* out, const Unk_Vector3* v, const MATRIXT44* m) {
    f32 x = m->field_0[0][0] * v->field_0[0] + m->field_0[1][0] * v->field_0[1] + m->field_0[2][0] * v->field_0[2] +
            m->field_0[3][0];
    f32 y = m->field_0[0][1] * v->field_0[0] + m->field_0[1][1] * v->field_0[1] + m->field_0[2][1] * v->field_0[2] +
            m->field_0[3][1];
    f32 z = m->field_0[0][2] * v->field_0[0] + m->field_0[1][2] * v->field_0[1] + m->field_0[2][2] * v->field_0[2] +
            m->field_0[3][2];
    out->field_0[0] = x;
    out->field_0[1] = y;
    out->field_0[2] = z;
}

// 0x71004100f0: a point (two elements) through a matrix
void Unk_4100f0(Unk_Float2* out, const Unk_Float2* v, const MATRIXT44* m) {
    f32 x = m->field_0[0][0] * v->field_0[0].field_0 + m->field_0[1][0] * v->field_0[1].field_0 + m->field_0[3][0];
    f32 y = m->field_0[0][1] * v->field_0[0].field_0 + m->field_0[1][1] * v->field_0[1].field_0 + m->field_0[3][1];
    out->field_0[0].field_0 = x;
    out->field_0[1].field_0 = y;
}

// 0x7100410130: a saturation per row, about one of two sets of luminance
// weights
// NON_MATCHING: the stores of the 3x3 part come in another order (the
// original: rows 0 and 1's first two elements, then the third column, then
// row 2's first two).
void Unk_410130(MATRIXT44* out, bool arg1, f32 r, f32 g, f32 b) {
    f32 lr = arg1 ? 0.29891f : 0.2126f;
    f32 lg = arg1 ? 0.58661f : 0.7152f;
    f32 lb = arg1 ? 0.11448f : 0.0722f;
    f32 off0 = lr + (0.0f - lr) * r;
    f32 on0 = lr + (1.0f - lr) * r;
    f32 off1 = lg + (0.0f - lg) * g;
    f32 on1 = lg + (1.0f - lg) * g;
    f32 off2 = lb + (0.0f - lb) * b;
    f32 on2 = lb + (1.0f - lb) * b;
    out->field_0[0][0] = on0;
    out->field_0[0][1] = off0;
    out->field_0[0][2] = off0;
    out->field_0[1][0] = off1;
    out->field_0[1][1] = on1;
    out->field_0[1][2] = off1;
    out->field_0[2][0] = off2;
    out->field_0[2][1] = off2;
    out->field_0[2][2] = on2;
    out->field_0[0][3] = out->field_0[1][3] = out->field_0[2][3] = 0.0f;
    out->field_0[3][0] = out->field_0[3][1] = out->field_0[3][2] = 0.0f;
    out->field_0[3][3] = 1.0f;
}

// the identity (inline)
static inline void Unk_Identity(MATRIXT44* out) {
    out->field_0[0][1] = out->field_0[0][2] = out->field_0[0][3] = out->field_0[1][0] = out->field_0[1][2] =
        out->field_0[1][3] = out->field_0[2][0] = out->field_0[2][1] = out->field_0[2][3] = out->field_0[3][0] =
            out->field_0[3][1] = out->field_0[3][2] = 0.0f;
    out->field_0[0][0] = out->field_0[1][1] = out->field_0[2][2] = out->field_0[3][3] = 1.0f;
}

static inline f32 Unk_Lerp(f32 a, f32 b, f32 t) {
    return (b - a) * t + a;
}

// 0x7100410200: a translation, with a scale of 1 - x, 1 - y, 1 - z weighted
// by `w`
// NON_MATCHING: the original shares the translation's stores and the last
// store of 1.0f (to m[0][0] or m[3][3], through a selected pointer) between
// the two branches; here each branch keeps its own.
void Unk_410200(MATRIXT44* out, f32 x, f32 y, f32 z, f32 w) {
    if (w == 0.0f) {
        Unk_Identity(out);
        out->field_0[3][0] = x;
        out->field_0[3][1] = y;
        out->field_0[3][2] = z;
    } else {
        Unk_Vector3 scale = {{Unk_Lerp(1.0f, 1.0f - x, w), Unk_Lerp(1.0f, 1.0f - y, w), Unk_Lerp(1.0f, 1.0f - z, w)}};
        Unk_40f660(out, &scale, nullptr);
        out->field_0[3][0] = x;
        out->field_0[3][1] = y;
        out->field_0[3][2] = z;
    }
}

// 0x71004102a0: a scale about the centre of the unit cube
// NON_MATCHING: the three subtractions and the three multiplications of the
// translation come in another order (the original: x, z, y and z, y, x).
void Unk_4102a0(MATRIXT44* out, f32 x, f32 y, f32 z) {
    out->field_0[0][0] = x;
    out->field_0[1][1] = y;
    out->field_0[2][2] = z;
    out->field_0[3][0] = (1.0f - x) * 0.5f;
    out->field_0[3][1] = (1.0f - y) * 0.5f;
    out->field_0[3][2] = (1.0f - z) * 0.5f;
    out->field_0[0][1] = out->field_0[0][2] = out->field_0[0][3] = out->field_0[1][0] = out->field_0[1][2] =
        out->field_0[1][3] = out->field_0[2][0] = out->field_0[2][1] = out->field_0[2][3] = 0.0f;
    out->field_0[3][3] = 1.0f;
}

// What 0x7100410300, 0x7100410380 and 0x7100410400 give 1, 1 and 0 for
static inline bool Unk_410300_Is(s32 type) {
    return (type >= 6 && type <= 14) || type == 16;
}

// 0x7100410300
f32 Unk_410300(s32 type) {
    switch (type) {
    case 0:
    case 15:
    case 17:
        return 100.0f;
    case 1:
        return 51.794735f;
    case 2:
        return 9.737591f;
    case 3:
        return 13.758274f;
    case 4:
        return 38.420933f;
    default:
        break;
    }
    return Unk_410300_Is(type) ? 1.0f : 3.4028235e38f;
}

// 0x7100410380
f32 Unk_410380(s32 type) {
    switch (type) {
    case 0:
    case 15:
    case 17:
        return 100.0f;
    case 1:
        return 10.0f;
    case 2:
        return 5.87f;
    case 3:
        return 8.29f;
    case 4:
        return 18.49f;
    default:
        break;
    }
    return Unk_410300_Is(type) ? 1.0f : 3.4028235e38f;
}

// 0x7100410400
s32 Unk_410400(s32 type) {
    switch (type) {
    case 0:
    case 1:
    case 8:
    case 15:
    case 17:
        return 1;
    case 2:
    case 3:
        return 15;
    case 4:
        return 16;
    case 9:
        return 6;
    case 10:
        return 11;
    case 11:
        return 8;
    default:
        break;
    }
    return Unk_410300_Is(type) ? 0 : -1;
}

// 0x7100412270
void Unk_412270(f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32* out1, f32* out2) {
    f32 sum = arg3 + arg4;
    if (out1 != nullptr) {
        f32 ratio = sum > 0.0f ? arg3 / sum : 0.0f;
        *out1 = (arg1 - arg2) * ratio + arg2;
    }
    if (out2 != nullptr) {
        *out2 = sum * 0.5f;
    }
}

// 0x7100412cd0
void Unk_412cd0(f32 scale, u32 width, u32 height, Unk_Float4* out) {
    f32 dx = scale / static_cast<f32>(width);
    f32 dy = scale / static_cast<f32>(height);
    out[0] = Unk_Float4(dx * 0.0f, dy * 0.0f, 0.0f, 0.0f);
    out[1] = Unk_Float4(dx * -1.0f, dy * -1.0f, 0.0f, 0.0f);
    out[2] = Unk_Float4(dx * 1.0f, dy * 1.0f, 0.0f, 0.0f);
    out[3] = Unk_Float4(dx * -1.0f, dy * 1.0f, 0.0f, 0.0f);
    out[4] = Unk_Float4(dx * -1.0f, dy * -1.0f, 0.0f, 0.0f);
}

}  // namespace PPFX
