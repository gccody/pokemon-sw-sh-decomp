// Scope: common
// YEBIS's first translation unit (0x710040f610 to 0x7100417870, before
// ppfx.cpp): matrix and filter kernel helpers and the SiReflection
// properties its static initialiser 0x7100415f40 registers. Its name isn't
// in the executable.
#include <math.h>

#include <yebis/YEBIS_draft/src/Unk_415f40.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>

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

void Unk_40f980(const MATRIXT44* matrix, f32* x, f32* y);

// 0x710040f6e0: a perspective projection's planes and angles (`arg1`: a
// depth range of -1 to 1, not 0 to 1); each output may be null
void Unk_40f6e0(const MATRIXT44* m, bool arg1, bool* arg2, f32* left, f32* right, f32* bottom, f32* top, f32* near,
                f32* far, f32* arg9, f32* arg10, f32* arg11, f32* arg12, f32* arg13, f32* arg14, f32* arg15) {
    bool positive = m->field_0[2][3] > 0.0f;
    f32 sign = positive ? 1.0f : -1.0f;
    f32 b = -m->field_0[3][2];
    f32 a = sign * m->field_0[2][2];
    f32 n = arg1 ? b / (a + 1.0f) : b / a;
    f32 f;
    if (arg1) {
        f = m->field_0[3][2] / (1.0f - a);
    } else {
        f = b / (a - 1.0f);
    }
    f32 width = (n + n) / m->field_0[0][0];
    f32 height = (n + n) / m->field_0[1][1];
    f32 x = sign * m->field_0[2][0];
    f32 y = sign * m->field_0[2][1];
    f32 l = width * (x + 1.0f) * -0.5f;
    f32 r = width * (1.0f - x) * 0.5f;
    f32 bo = height * (y + 1.0f) * -0.5f;
    f32 t = height * (1.0f - y) * 0.5f;
    f32 rx;
    f32 ry;
    Unk_40f980(m, &rx, &ry);
    f32 ax = atanf(rx);
    f32 ay = atanf(ry);
    f32 aspect = rx * m->field_0[1][1];
    if (arg2 != nullptr) {
        *arg2 = positive;
    }
    if (left != nullptr) {
        *left = l;
    }
    if (right != nullptr) {
        *right = r;
    }
    if (bottom != nullptr) {
        *bottom = bo;
    }
    if (top != nullptr) {
        *top = t;
    }
    if (near != nullptr) {
        *near = n;
    }
    if (far != nullptr) {
        *far = f;
    }
    if (arg9 != nullptr) {
        *arg9 = rx;
    }
    if (arg10 != nullptr) {
        *arg10 = ry;
    }
    if (arg11 != nullptr) {
        *arg11 = ax * 2.0f;
    }
    if (arg12 != nullptr) {
        *arg12 = ay * 2.0f;
    }
    if (arg13 != nullptr) {
        *arg13 = aspect;
    }
    if (arg14 != nullptr) {
        *arg14 = width;
    }
    if (arg15 != nullptr) {
        *arg15 = height;
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

// 0x710040f9b0: a perspective projection rebuilt (with Unk_40f8d0's depth
// range of -1 to 1) from one with a depth range of 0 to 1 (Unk_40f6e0 inlined:
// its two atanf calls stay, nothing uses them)
// NON_MATCHING: register allocation only: the left edge's product and the
// constant -0.5 are in s6 and s7 here, s7 and s16 in the original (and far
// times -2 in s3, not s6)
MATRIXT44* Unk_40f9b0(MATRIXT44* out, const MATRIXT44* m, bool flip) {
    bool positive;
    f32 left;
    f32 right;
    f32 bottom;
    f32 top;
    f32 near;
    f32 far;
    Unk_40f6e0(m, false, &positive, &left, &right, &bottom, &top, &near, &far, nullptr, nullptr, nullptr, nullptr,
               nullptr, nullptr, nullptr);
    Unk_40f8d0(out, true, positive && !flip, left, right, bottom, top, near, far);
    return out;
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

// 0x710040fd00: the angles of a rotation (the inverse of Unk_40fde0)
void Unk_40fd00(const MATRIXT44* m, f32* roll, f32* pitch, f32* yaw) {
    f32 y = atan2f(m->field_0[0][1], m->field_0[1][1]);
    f32 p = asinf(-m->field_0[2][1]);
    f32 r = atan2f(m->field_0[2][0], m->field_0[2][2]);
    if (fabsf(cosf(p)) < 1e-6f) {
        y += m->field_0[0][1] > 0.0f ? 3.1415927f : -3.1415927f;
        r += m->field_0[2][0] > 0.0f ? 3.1415927f : -3.1415927f;
    }
    if (roll != nullptr) {
        *roll = r;
    }
    if (pitch != nullptr) {
        *pitch = p;
    }
    if (yaw != nullptr) {
        *yaw = y;
    }
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

void Unk_4155f0(MATRIXT44* out, const MATRIXT44* m);

MATRIXT44* Unk_4114f0(MATRIXT44* out, u32 value);

// The CIE photopic luminous efficiency (each value with its wavelength, every
// 5 nm) and the CIE 1931 2-degree colour matching functions (x, y, z and the
// wavelength, a zero at each end)
static const Unk_Float2 Unk_Table1[83] = {
    Unk_Float2(0.0f, 375.0f), Unk_Float2(0.0002f, 380.0f), Unk_Float2(0.000396f, 385.0f),
    Unk_Float2(0.0008f, 390.0f), Unk_Float2(0.00155f, 395.0f), Unk_Float2(0.0028f, 400.0f),
    Unk_Float2(0.00466f, 405.0f), Unk_Float2(0.0074f, 410.0f), Unk_Float2(0.0118f, 415.0f),
    Unk_Float2(0.0175f, 420.0f), Unk_Float2(0.0227f, 425.0f), Unk_Float2(0.0273f, 430.0f),
    Unk_Float2(0.0326f, 435.0f), Unk_Float2(0.0379f, 440.0f), Unk_Float2(0.0424f, 445.0f),
    Unk_Float2(0.0468f, 450.0f), Unk_Float2(0.0521f, 455.0f), Unk_Float2(0.06f, 460.0f),
    Unk_Float2(0.0739f, 465.0f), Unk_Float2(0.091f, 470.0f), Unk_Float2(0.113f, 475.0f),
    Unk_Float2(0.139f, 480.0f), Unk_Float2(0.169f, 485.0f), Unk_Float2(0.208f, 490.0f),
    Unk_Float2(0.259f, 495.0f), Unk_Float2(0.323f, 500.0f), Unk_Float2(0.4073f, 505.0f),
    Unk_Float2(0.503f, 510.0f), Unk_Float2(0.6082f, 515.0f), Unk_Float2(0.71f, 520.0f),
    Unk_Float2(0.7932f, 525.0f), Unk_Float2(0.862f, 530.0f), Unk_Float2(0.91485f, 535.0f),
    Unk_Float2(0.954f, 540.0f), Unk_Float2(0.9803f, 545.0f), Unk_Float2(0.99495f, 550.0f),
    Unk_Float2(1.0f, 555.0f), Unk_Float2(0.995f, 560.0f), Unk_Float2(0.9786f, 565.0f),
    Unk_Float2(0.952f, 570.0f), Unk_Float2(0.9154f, 575.0f), Unk_Float2(0.87f, 580.0f),
    Unk_Float2(0.8163f, 585.0f), Unk_Float2(0.757f, 590.0f), Unk_Float2(0.6949f, 595.0f),
    Unk_Float2(0.631f, 600.0f), Unk_Float2(0.5668f, 605.0f), Unk_Float2(0.503f, 610.0f),
    Unk_Float2(0.4412f, 615.0f), Unk_Float2(0.381f, 620.0f), Unk_Float2(0.32f, 625.0f),
    Unk_Float2(0.265f, 630.0f), Unk_Float2(0.217f, 635.0f), Unk_Float2(0.175f, 640.0f),
    Unk_Float2(0.1382f, 645.0f), Unk_Float2(0.107f, 650.0f), Unk_Float2(0.0816f, 655.0f),
    Unk_Float2(0.061f, 660.0f), Unk_Float2(0.0446f, 665.0f), Unk_Float2(0.032f, 670.0f),
    Unk_Float2(0.0232f, 675.0f), Unk_Float2(0.017f, 680.0f), Unk_Float2(0.0119f, 685.0f),
    Unk_Float2(0.00821f, 690.0f), Unk_Float2(0.00572f, 695.0f), Unk_Float2(0.0041f, 700.0f),
    Unk_Float2(0.00293f, 705.0f), Unk_Float2(0.00209f, 710.0f), Unk_Float2(0.00148f, 715.0f),
    Unk_Float2(0.00105f, 720.0f), Unk_Float2(0.00074f, 725.0f), Unk_Float2(0.00052f, 730.0f),
    Unk_Float2(0.000361f, 735.0f), Unk_Float2(0.000249f, 740.0f), Unk_Float2(0.000172f, 745.0f),
    Unk_Float2(0.00012f, 750.0f), Unk_Float2(8.48e-5f, 755.0f), Unk_Float2(6e-5f, 760.0f),
    Unk_Float2(4.24e-5f, 765.0f), Unk_Float2(3e-5f, 770.0f), Unk_Float2(2.12e-5f, 775.0f),
    Unk_Float2(1.5e-5f, 780.0f), Unk_Float2(0.0f, 785.0f),
};
static const Unk_Float4 Unk_Table2[97] = {
    Unk_Float4(0.0f, 0.0f, 0.0f, 355.0f), Unk_Float4(0.0001299f, 3.917e-6f, 0.0006061f, 360.0f),
    Unk_Float4(0.0002321f, 6.965e-6f, 0.001086f, 365.0f), Unk_Float4(0.0004149f, 1.239e-5f, 0.001946f, 370.0f),
    Unk_Float4(0.0007416f, 2.202e-5f, 0.003486f, 375.0f), Unk_Float4(0.001368f, 3.9e-5f, 0.006450001f, 380.0f),
    Unk_Float4(0.002236f, 6.4e-5f, 0.01054999f, 385.0f), Unk_Float4(0.004243f, 0.00012f, 0.02005001f, 390.0f),
    Unk_Float4(0.00765f, 0.000217f, 0.03621f, 395.0f), Unk_Float4(0.01431f, 0.000396f, 0.06785001f, 400.0f),
    Unk_Float4(0.02319f, 0.00064f, 0.1102f, 405.0f), Unk_Float4(0.04351f, 0.00121f, 0.2074f, 410.0f),
    Unk_Float4(0.07763f, 0.00218f, 0.3713f, 415.0f), Unk_Float4(0.13438f, 0.004f, 0.6456f, 420.0f),
    Unk_Float4(0.21477f, 0.0073f, 1.0390501f, 425.0f), Unk_Float4(0.2839f, 0.0116f, 1.3856f, 430.0f),
    Unk_Float4(0.3285f, 0.01684f, 1.62296f, 435.0f), Unk_Float4(0.34828f, 0.023f, 1.74706f, 440.0f),
    Unk_Float4(0.34806f, 0.0298f, 1.7826f, 445.0f), Unk_Float4(0.3362f, 0.038f, 1.77211f, 450.0f),
    Unk_Float4(0.3187f, 0.048f, 1.7441f, 455.0f), Unk_Float4(0.2908f, 0.06f, 1.6692f, 460.0f),
    Unk_Float4(0.2511f, 0.0739f, 1.5281f, 465.0f), Unk_Float4(0.19536f, 0.09098f, 1.28764f, 470.0f),
    Unk_Float4(0.1421f, 0.1126f, 1.0419f, 475.0f), Unk_Float4(0.09564f, 0.13902f, 0.8129501f, 480.0f),
    Unk_Float4(0.05795001f, 0.1693f, 0.6162f, 485.0f), Unk_Float4(0.03201f, 0.20802f, 0.46518f, 490.0f),
    Unk_Float4(0.0147f, 0.2586f, 0.3533f, 495.0f), Unk_Float4(0.0049f, 0.323f, 0.272f, 500.0f),
    Unk_Float4(0.0024f, 0.4073f, 0.2123f, 505.0f), Unk_Float4(0.0093f, 0.503f, 0.1582f, 510.0f),
    Unk_Float4(0.0291f, 0.6082f, 0.1117f, 515.0f), Unk_Float4(0.06327f, 0.71f, 0.07824999f, 520.0f),
    Unk_Float4(0.1096f, 0.7932f, 0.05725001f, 525.0f), Unk_Float4(0.1655f, 0.862f, 0.04216f, 530.0f),
    Unk_Float4(0.2257499f, 0.9148501f, 0.02984f, 535.0f), Unk_Float4(0.2904f, 0.954f, 0.0203f, 540.0f),
    Unk_Float4(0.3597f, 0.9803f, 0.0134f, 545.0f), Unk_Float4(0.4334499f, 0.9949501f, 0.008749999f, 550.0f),
    Unk_Float4(0.5120501f, 1.0f, 0.005749999f, 555.0f), Unk_Float4(0.5945f, 0.995f, 0.0039f, 560.0f),
    Unk_Float4(0.6784f, 0.9786f, 0.002749999f, 565.0f), Unk_Float4(0.7621f, 0.952f, 0.0021f, 570.0f),
    Unk_Float4(0.8425f, 0.9154f, 0.0018f, 575.0f), Unk_Float4(0.9163f, 0.87f, 0.001650001f, 580.0f),
    Unk_Float4(0.9786f, 0.8163f, 0.0014f, 585.0f), Unk_Float4(1.0263f, 0.757f, 0.0011f, 590.0f),
    Unk_Float4(1.0567f, 0.6949f, 0.001f, 595.0f), Unk_Float4(1.0622f, 0.631f, 0.0008f, 600.0f),
    Unk_Float4(1.0456f, 0.5668f, 0.0006f, 605.0f), Unk_Float4(1.0026f, 0.503f, 0.00034f, 610.0f),
    Unk_Float4(0.9384f, 0.4412f, 0.00024f, 615.0f), Unk_Float4(0.8544499f, 0.381f, 0.00019f, 620.0f),
    Unk_Float4(0.7514f, 0.321f, 0.0001f, 625.0f), Unk_Float4(0.6424f, 0.265f, 5e-6f, 630.0f),
    Unk_Float4(0.5419f, 0.217f, 3e-5f, 635.0f), Unk_Float4(0.4479f, 0.175f, 2e-5f, 640.0f),
    Unk_Float4(0.3608f, 0.1382f, 1e-5f, 645.0f), Unk_Float4(0.2835f, 0.107f, 0.0f, 650.0f),
    Unk_Float4(0.2187f, 0.0816f, 0.0f, 655.0f), Unk_Float4(0.1649f, 0.061f, 0.0f, 660.0f),
    Unk_Float4(0.1212f, 0.04458f, 0.0f, 665.0f), Unk_Float4(0.0874f, 0.032f, 0.0f, 670.0f),
    Unk_Float4(0.0636f, 0.0232f, 0.0f, 675.0f), Unk_Float4(0.04677f, 0.017f, 0.0f, 680.0f),
    Unk_Float4(0.0329f, 0.01192f, 0.0f, 685.0f), Unk_Float4(0.0227f, 0.00821f, 0.0f, 690.0f),
    Unk_Float4(0.01584f, 0.005723f, 0.0f, 695.0f), Unk_Float4(0.01135916f, 0.004102f, 0.0f, 700.0f),
    Unk_Float4(0.008110916f, 0.002929f, 0.0f, 705.0f), Unk_Float4(0.005790346f, 0.002091f, 0.0f, 710.0f),
    Unk_Float4(0.004106457f, 0.001484f, 0.0f, 715.0f), Unk_Float4(0.002899327f, 0.001047f, 0.0f, 720.0f),
    Unk_Float4(0.00204919f, 0.00074f, 0.0f, 725.0f), Unk_Float4(0.001439971f, 0.00052f, 0.0f, 730.0f),
    Unk_Float4(0.000999949f, 0.0003611f, 0.0f, 735.0f), Unk_Float4(0.000690079f, 0.0002492f, 0.0f, 740.0f),
    Unk_Float4(0.000476021f, 0.0001719f, 0.0f, 745.0f), Unk_Float4(0.000332301f, 0.00012f, 0.0f, 750.0f),
    Unk_Float4(0.000234826f, 8.48e-5f, 0.0f, 755.0f), Unk_Float4(0.000166151f, 6e-5f, 0.0f, 760.0f),
    Unk_Float4(0.000117413f, 4.24e-5f, 0.0f, 765.0f), Unk_Float4(8.30753e-5f, 3e-5f, 0.0f, 770.0f),
    Unk_Float4(5.87065e-5f, 2.12e-5f, 0.0f, 775.0f), Unk_Float4(4.15099e-5f, 1.499e-5f, 0.0f, 780.0f),
    Unk_Float4(2.93533e-5f, 1.06e-5f, 0.0f, 785.0f), Unk_Float4(2.06738e-5f, 7.4657e-6f, 0.0f, 790.0f),
    Unk_Float4(1.45598e-5f, 5.2578e-6f, 0.0f, 795.0f), Unk_Float4(1.0254e-5f, 3.7029e-6f, 0.0f, 800.0f),
    Unk_Float4(7.22146e-6f, 2.6078e-6f, 0.0f, 805.0f), Unk_Float4(5.08587e-6f, 1.8366e-6f, 0.0f, 810.0f),
    Unk_Float4(3.58165e-6f, 1.2934e-6f, 0.0f, 815.0f), Unk_Float4(2.52253e-6f, 9.1093e-7f, 0.0f, 820.0f),
    Unk_Float4(1.77651e-6f, 6.4153e-7f, 0.0f, 825.0f), Unk_Float4(1.25114e-6f, 4.5181e-7f, 0.0f, 830.0f),
    Unk_Float4(0.0f, 0.0f, 0.0f, 835.0f),
};

// 0x7100410450: the largest red, green and blue (and the largest of the three)
// that the spectral colours have in colour space `space`, worked out for all
// of them the first time (the table of maxima is in the TU's merged statics,
// so not a function-local static: that would need a guard). The last loop is
// unrolled only with a pointer induction variable (an indexed one costs the
// unroller more than its threshold of 300).
// NON_MATCHING: the inner loop's pointer to the space's maxima: the original
// keeps a 64-bit index and a pointer to the maxima's fourth element (the
// elements at -12, -8, -4, the increment a separate add); here a 32-bit index
// and a pointer to the first element (post-incremented by the last store).
static Unk_Float4 s_max[24];
Unk_Float4 Unk_410450(s32 space) {
    static bool s_initialized;
    if (!s_initialized) {
        s_initialized = true;
        for (s32 i = 0; i < 24; i++) {
            s_max[i] = Unk_Float4(-3.4028235e38f, -3.4028235e38f, -3.4028235e38f, -3.4028235e38f);
        }
        for (s32 i = 0; i < 97; i++) {
            f32 x = Unk_Table2[i].field_0[0].field_0;
            f32 y = Unk_Table2[i].field_0[1].field_0;
            f32 z = Unk_Table2[i].field_0[2].field_0;
            Unk_Float4* max = s_max;
            for (u32 j = 0; j < 24; j++, max++) {
                MATRIXT44 m;
                Unk_4114f0(&m, j);
                f32 r = x * m.field_0[0][0] + y * m.field_0[1][0] + z * m.field_0[2][0] + m.field_0[3][0];
                f32 g = x * m.field_0[0][1] + y * m.field_0[1][1] + z * m.field_0[2][1] + m.field_0[3][1];
                f32 b = x * m.field_0[0][2] + y * m.field_0[1][2] + z * m.field_0[2][2] + m.field_0[3][2];
                max->field_0[0].field_0 = r > max->field_0[0].field_0 ? r : max->field_0[0].field_0;
                max->field_0[1].field_0 = g > max->field_0[1].field_0 ? g : max->field_0[1].field_0;
                max->field_0[2].field_0 = b > max->field_0[2].field_0 ? b : max->field_0[2].field_0;
            }
        }
        Unk_Float4* max = s_max;
        for (s32 i = 0; i < 24; i++, max++) {
            f32 m = max->field_0[0].field_0 > max->field_0[1].field_0 ? max->field_0[0].field_0 : max->field_0[1].field_0;
            max->field_0[3].field_0 = m > max->field_0[2].field_0 ? m : max->field_0[2].field_0;
        }
    }
    return s_max[space];
}

}  // namespace PPFX

// 0x7100410960: the primaries and white point of a colour space by its number
// (the two pairs of spaces that differ only in the white point are one case
// each, with a switch for the white point: SimplifyCFG sinks the rest of the
// two copies into one block, and the jump table goes to the white points)
// NON_MATCHING: two instructions: the entry computes the DCI white point's
// two element addresses (for the sunk block's phis) in the other order. The
// operator= that loads x first gives that order but then loads the merged
// blocks' elements in the other order.
void Unk_410960(Unk_410f90* self, u32 value) {
    *self = Unk_410f90();
    switch (value) {
    case 0:
        self->field_18 = PPFX::Unk_White_D65;
        self->field_0 = PPFX::Unk_Float2(0.64f, 0.33f);
        self->field_8 = PPFX::Unk_Float2(0.3f, 0.6f);
        self->field_10 = PPFX::Unk_Float2(0.15f, 0.06f);
        return;
    case 1:
        self->field_18 = PPFX::Unk_White_D65;
        self->field_0 = PPFX::Unk_Float2(0.708f, 0.292f);
        self->field_8 = PPFX::Unk_Float2(0.17f, 0.797f);
        self->field_10 = PPFX::Unk_Float2(0.131f, 0.046f);
        return;
    case 2:
        self->field_18 = PPFX::Unk_White_D65;
        self->field_0 = PPFX::Unk_Float2(0.64f, 0.33f);
        self->field_8 = PPFX::Unk_Float2(0.29f, 0.6f);
        self->field_10 = PPFX::Unk_Float2(0.15f, 0.06f);
        return;
    case 3:
    case 4:
        switch (value) {
        case 3:
            self->field_18 = PPFX::Unk_White_D65;
            break;
        case 4:
            self->field_18 = PPFX::Unk_White_D93;
            break;
        }
        self->field_0 = PPFX::Unk_Float2(0.63f, 0.34f);
        self->field_8 = PPFX::Unk_Float2(0.31f, 0.595f);
        self->field_10 = PPFX::Unk_Float2(0.155f, 0.07f);
        return;
    case 5:
        self->field_18 = PPFX::Unk_White_C;
        self->field_0 = PPFX::Unk_Float2(0.67f, 0.33f);
        self->field_8 = PPFX::Unk_Float2(0.21f, 0.71f);
        self->field_10 = PPFX::Unk_Float2(0.14f, 0.08f);
        return;
    case 6:
        self->field_18 = PPFX::Unk_White_D65;
        self->field_0 = PPFX::Unk_Float2(0.64f, 0.33f);
        self->field_8 = PPFX::Unk_Float2(0.21f, 0.71f);
        self->field_10 = PPFX::Unk_Float2(0.15f, 0.06f);
        return;
    case 7:
        self->field_18 = PPFX::Unk_White_D50;
        self->field_0 = PPFX::Unk_Float2(0.7347f, 0.2653f);
        self->field_8 = PPFX::Unk_Float2(0.1152f, 0.8264f);
        self->field_10 = PPFX::Unk_Float2(0.1566f, 0.0177f);
        return;
    case 8:
        self->field_18 = PPFX::Unk_White_D50;
        self->field_0 = PPFX::Unk_Float2(0.7347f, 0.2653f);
        self->field_8 = PPFX::Unk_Float2(0.1596f, 0.8404f);
        self->field_10 = PPFX::Unk_Float2(0.0366f, 0.0001f);
        return;
    case 9:
        self->field_18 = PPFX::Unk_White_D60;
        self->field_0 = PPFX::Unk_Float2(0.7347f, 0.2653f);
        self->field_8 = PPFX::Unk_Float2(0.0f, 1.0f);
        self->field_10 = PPFX::Unk_Float2(0.0001f, -0.077f);
        return;
    case 10:
        self->field_18 = PPFX::Unk_White_D60;
        self->field_0 = PPFX::Unk_Float2(0.713f, 0.293f);
        self->field_8 = PPFX::Unk_Float2(0.165f, 0.83f);
        self->field_10 = PPFX::Unk_Float2(0.128f, 0.044f);
        return;
    case 11:
    case 12:
        switch (value) {
        case 11:
            self->field_18 = PPFX::Unk_White_DCI;
            break;
        case 12:
            self->field_18 = PPFX::Unk_White_D65;
            break;
        }
        self->field_0 = PPFX::Unk_Float2(0.68f, 0.32f);
        self->field_8 = PPFX::Unk_Float2(0.265f, 0.69f);
        self->field_10 = PPFX::Unk_Float2(0.15f, 0.06f);
        return;
    case 13:
        self->field_18 = PPFX::Unk_White_DCI;
        self->field_0 = PPFX::Unk_Float2(0.74f, 0.27f);
        self->field_8 = PPFX::Unk_Float2(0.22f, 0.78f);
        self->field_10 = PPFX::Unk_Float2(0.09f, -0.09f);
        return;
    case 14:
        self->field_18 = PPFX::Unk_White_D65;
        self->field_0 = PPFX::Unk_Float2(0.74f, 0.27f);
        self->field_8 = PPFX::Unk_Float2(0.17f, 1.14f);
        self->field_10 = PPFX::Unk_Float2(0.08f, -0.1f);
        return;
    case 15:
        self->field_18 = PPFX::Unk_White_D65;
        self->field_0 = PPFX::Unk_Float2(0.73f, 0.28f);
        self->field_8 = PPFX::Unk_Float2(0.14f, 0.855f);
        self->field_10 = PPFX::Unk_Float2(0.1f, -0.05f);
        return;
    case 16:
        self->field_18 = PPFX::Unk_White_D65;
        self->field_0 = PPFX::Unk_Float2(0.766f, 0.275f);
        self->field_8 = PPFX::Unk_Float2(0.225f, 0.8f);
        self->field_10 = PPFX::Unk_Float2(0.089f, -0.087f);
        return;
    case 17:
        self->field_18 = PPFX::Unk_White_E;
        self->field_0 = PPFX::Unk_Float2(0.7347f, 0.2653f);
        self->field_8 = PPFX::Unk_Float2(0.2738f, 0.7174f);
        self->field_10 = PPFX::Unk_Float2(0.1666f, 0.0089f);
        return;
    case 18:
        self->field_18 = PPFX::Unk_White_E;
        self->field_0 = PPFX::Unk_Float2(1.0f, 0.0f);
        self->field_8 = PPFX::Unk_Float2(0.0f, 1.0f);
        self->field_10 = PPFX::Unk_Float2(0.0f, 0.0f);
        return;
    case 19:
        self->field_18 = PPFX::Unk_White_E;
        self->field_0 = PPFX::Unk_Float2(0.83738434f, 0.16261561f);
        self->field_8 = PPFX::Unk_Float2(2.302202f, -1.3022021f);
        self->field_10 = PPFX::Unk_Float2(0.16799065f, -6.7032556e-06f);
        return;
    case 20:
        self->field_18 = PPFX::Unk_White_D65;
        self->field_0 = PPFX::Unk_Float2(0.8373814f, 0.16261858f);
        self->field_8 = PPFX::Unk_Float2(2.301887f, -1.301887f);
        self->field_10 = PPFX::Unk_Float2(0.16799228f, -5.446892e-06f);
        return;
    case 21:
        self->field_18 = PPFX::Unk_White_E;
        self->field_0 = PPFX::Unk_Float2(0.69961315f, 0.30643222f);
        self->field_8 = PPFX::Unk_Float2(-0.35749286f, 1.2601477f);
        self->field_10 = PPFX::Unk_Float2(0.13582164f, 0.041852362f);
        return;
    case 22:
        self->field_18 = PPFX::Unk_White_E;
        self->field_0 = PPFX::Unk_Float2(0.6934638f, 0.3163464f);
        self->field_8 = PPFX::Unk_Float2(-0.5597244f, 1.4717051f);
        self->field_10 = PPFX::Unk_Float2(0.15031128f, 0.06715658f);
        return;
    case 23:
        self->field_18 = PPFX::Unk_White_E;
        self->field_0 = PPFX::Unk_Float2(0.711369f, 0.29487914f);
        self->field_8 = PPFX::Unk_Float2(-1.4757617f, 2.5059154f);
        self->field_10 = PPFX::Unk_Float2(0.14387473f, 0.056762394f);
        return;
    default:
        self->field_18 = Unk_410f90_Point(0.0f, 0.0f);
        return;
    }
}

// 0x7100410f90: a colour space by its number (0x19 and -1: none, all zero)
void Unk_410f90_set(Unk_410f90* self, u32 value) {
    if (value == 0x19 || value == 0xffffffff) {
        *self = Unk_410f90();
        return;
    }
    Unk_410960(self, value);
}

namespace PPFX {

MATRIXT44* Unk_411340(MATRIXT44* out, u32 value);
MATRIXT44* Unk_4114f0(MATRIXT44* out, u32 value);

// 0x7100410fb0: the adaptation of XYZ colours from one white point to another
// (a von Kries transform in the cone space of colour space `method`)
MATRIXT44* Unk_410fb0(MATRIXT44* out, const Unk_410f90_Point* from, const Unk_410f90_Point* to, u32 method) {
    if (from->field_0.field_0 == to->field_0.field_0 && from->field_4.field_0 == to->field_4.field_0) {
        out->field_0[0][1] = out->field_0[0][2] = out->field_0[0][3] = out->field_0[1][0] = out->field_0[1][2] =
            out->field_0[1][3] = out->field_0[2][0] = out->field_0[2][1] = out->field_0[2][3] = out->field_0[3][0] =
                out->field_0[3][1] = out->field_0[3][2] = 0.0f;
        out->field_0[0][0] = out->field_0[1][1] = out->field_0[2][2] = out->field_0[3][3] = 1.0f;
        return out;
    }
    f32 fromScale = 1.0f / from->field_4.field_0;
    f32 fromZ = 1.0f - from->field_0.field_0 - from->field_4.field_0;
    f32 fromX = from->field_0.field_0 * fromScale;
    fromZ = fromScale * fromZ;
    f32 toZ = 1.0f - to->field_0.field_0 - to->field_4.field_0;
    f32 toScale = 1.0f / to->field_4.field_0;
    f32 toX = to->field_0.field_0 * toScale;
    toZ = toScale * toZ;
    MATRIXT44 toCone;
    Unk_4114f0(&toCone, method);
    MATRIXT44 fromCone;
    Unk_411340(&fromCone, method);
    f32 r0 = fromX * toCone.field_0[0][0] + toCone.field_0[1][0] + fromZ * toCone.field_0[2][0] + toCone.field_0[3][0];
    f32 g0 = fromX * toCone.field_0[0][1] + toCone.field_0[1][1] + fromZ * toCone.field_0[2][1] + toCone.field_0[3][1];
    f32 b0 = fromX * toCone.field_0[0][2] + toCone.field_0[1][2] + fromZ * toCone.field_0[2][2] + toCone.field_0[3][2];
    f32 r1 = toX * toCone.field_0[0][0] + toCone.field_0[1][0] + toZ * toCone.field_0[2][0] + toCone.field_0[3][0];
    f32 g1 = toX * toCone.field_0[0][1] + toCone.field_0[1][1] + toZ * toCone.field_0[2][1] + toCone.field_0[3][1];
    f32 b1 = toX * toCone.field_0[0][2] + toCone.field_0[1][2] + toZ * toCone.field_0[2][2] + toCone.field_0[3][2];
    MATRIXT44 scale;
    scale.field_0[0][1] = 0.0f;
    scale.field_0[0][2] = 0.0f;
    scale.field_0[0][3] = 0.0f;
    scale.field_0[1][0] = 0.0f;
    scale.field_0[1][2] = 0.0f;
    scale.field_0[1][3] = 0.0f;
    scale.field_0[2][0] = 0.0f;
    scale.field_0[2][1] = 0.0f;
    scale.field_0[2][3] = 0.0f;
    scale.field_0[3][0] = 0.0f;
    scale.field_0[3][1] = 0.0f;
    scale.field_0[3][2] = 0.0f;
    scale.field_0[0][0] = r1 / r0;
    scale.field_0[1][1] = g1 / g0;
    scale.field_0[2][2] = b1 / b0;
    scale.field_0[3][3] = 1.0f;
    MATRIXT44 result;
    MATRIXT44 coneScale;
    MATRIXT44_MatrixMultiply(&coneScale, &toCone, &scale);
    MATRIXT44_MatrixMultiply(&result, &coneScale, &fromCone);
    *out = result;
    return out;
}

MATRIXT44* Unk_411b00(MATRIXT44* out, const Unk_410f90_Point* red, const Unk_410f90_Point* green,
                      const Unk_410f90_Point* blue, const Unk_410f90_Point* white);

// 0x7100411190: the matrix from one colour space's RGB to another's, through
// XYZ, adapting the white point when `adapt` (each matrix its own local: with
// one reused for all three the registers come out otherwise)
MATRIXT44* Unk_411190(MATRIXT44* out, const Unk_410f90* from, const Unk_410f90* to, bool adapt) {
    out->field_0[0][1] = out->field_0[0][2] = out->field_0[0][3] = out->field_0[1][0] = out->field_0[1][2] =
        out->field_0[1][3] = out->field_0[2][0] = out->field_0[2][1] = out->field_0[2][3] = out->field_0[3][0] =
            out->field_0[3][1] = out->field_0[3][2] = 0.0f;
    out->field_0[0][0] = out->field_0[1][1] = out->field_0[2][2] = out->field_0[3][3] = 1.0f;
    if (!Unk_SameColorSpace(*from, *to)) {
        {
            MATRIXT44 toXyz;
            Unk_411b00(&toXyz, &from->field_0, &from->field_8, &from->field_10, &from->field_18);
            MATRIXT44_MatrixMultiply(out, out, &toXyz);
        }
        if (adapt) {
            MATRIXT44 adaptation;
            Unk_410fb0(&adaptation, &from->field_18, &to->field_18, 0x15);
            MATRIXT44_MatrixMultiply(out, out, &adaptation);
        }
        MATRIXT44 toXyz;
        Unk_411b00(&toXyz, &to->field_0, &to->field_8, &to->field_10, &to->field_18);
        MATRIXT44 inverse;
        Unk_4155f0(&inverse, &toXyz);
        MATRIXT44 toRgb = inverse;
        MATRIXT44_MatrixMultiply(out, out, &toRgb);
    }
    return out;
}

// 0x7100411340: the RGB to XYZ matrix of a colour space by its number
MATRIXT44* Unk_411340(MATRIXT44* out, u32 value) {
    Unk_410f90 space;
    Unk_410f90_set(&space, value);
    Unk_411b00(out, &space.field_0, &space.field_8, &space.field_10, &space.field_18);
    return out;
}

// 0x71004114f0: the XYZ to RGB matrix of a colour space by its number
MATRIXT44* Unk_4114f0(MATRIXT44* out, u32 value) {
    MATRIXT44 toXyz;
    Unk_410f90 space;
    Unk_410f90_set(&space, value);
    Unk_411b00(&toXyz, &space.field_0, &space.field_8, &space.field_10, &space.field_18);
    MATRIXT44 inverse;
    Unk_4155f0(&inverse, &toXyz);
    *out = inverse;
    return out;
}

// k log(e^(a / k) + e^(b / k)): a smooth maximum of a and b (inline)
static inline f32 Unk_SmoothMax(f32 a, f32 b, f32 k) {
    return k * logf(expf(a / k) + expf(b / k));
}

// 0x71004116f0: the colour of light of one wavelength (nm) in colour space
// `space` and its luminous efficiency, optionally scaled by the space's
// largest spectral value, brought into range and gamma-encoded
// NON_MATCHING: 12 bytes shorter; the shape is the original's. The original
// loads all of a table entry's elements before the lerps, keeps the third
// component's range check a branch (the first two are selects, as here),
// materialises the 5.0 of the second lookup in the blocks before it, and
// tests the smooth maximum against the value before the peak.
Unk_Float4 Unk_4116f0(f32 wavelength, f32 gamma, f32 knee, u32 space, bool scale, bool limit) {
    f32 first = Unk_Table2[1].field_0[3].field_0;
    f32 w = first > wavelength ? first : (Unk_Table2[95].field_0[3].field_0 < wavelength ? Unk_Table2[95].field_0[3].field_0 : wavelength);
    f32 t = (w - first) / 5.0f + 1.0f;
    s32 i = static_cast<s32>(floorf(t));
    f32 frac = t - static_cast<f32>(i);
    s32 j = i + 1 < 96 ? i + 1 : 96;
    f32 x = Unk_Lerp(Unk_Table2[i].field_0[0].field_0, Unk_Table2[j].field_0[0].field_0, frac);
    f32 y = Unk_Lerp(Unk_Table2[i].field_0[1].field_0, Unk_Table2[j].field_0[1].field_0, frac);
    f32 z = Unk_Lerp(Unk_Table2[i].field_0[2].field_0, Unk_Table2[j].field_0[2].field_0, frac);
    MATRIXT44 m;
    Unk_4114f0(&m, space);
    f32 r = x * m.field_0[0][0] + y * m.field_0[1][0] + z * m.field_0[2][0] + m.field_0[3][0];
    f32 g = x * m.field_0[0][1] + y * m.field_0[1][1] + z * m.field_0[2][1] + m.field_0[3][1];
    f32 b = x * m.field_0[0][2] + y * m.field_0[1][2] + z * m.field_0[2][2] + m.field_0[3][2];
    bool encode = gamma != 1.0f;
    limit = limit || encode;
    scale = scale || encode;
    f32 peak = 0.0f;
    if (limit) {
        peak = Unk_410450(space).field_0[3].field_0;
    }
    f32 inverse = 1.0f / peak;
    if (scale) {
        r = inverse * r;
        g = inverse * g;
        b = inverse * b;
    }
    if (knee > 0.0f) {
        knee = (fmaxf(r, 0.0f) * 0.2126f + fmaxf(g, 0.0f) * 0.7152f + fmaxf(b, 0.0f) * 0.0722f) * knee;
    }
    if (limit) {
        if (knee > 0.0f) {
            f32 sr = Unk_SmoothMax(r, 0.0f, knee);
            f32 sg = Unk_SmoothMax(g, 0.0f, knee);
            f32 sb = Unk_SmoothMax(b, 0.0f, knee);
            r = sr >= r && sr <= peak ? sr : fmaxf(r, 0.0f);
            g = sg >= g && sg <= peak ? sg : fmaxf(g, 0.0f);
            b = sb >= b && sb <= peak ? sb : fmaxf(b, 0.0f);
        } else {
            r = fmaxf(r, 0.0f);
            g = fmaxf(g, 0.0f);
            b = fmaxf(b, 0.0f);
        }
    }
    f32 first1 = Unk_Table1[0].field_0[1].field_0;
    f32 w1 = first1 > wavelength ? first1 : (Unk_Table1[82].field_0[1].field_0 < wavelength ? Unk_Table1[82].field_0[1].field_0 : wavelength);
    f32 t1 = (w1 - first1) / 5.0f;
    s32 i1 = static_cast<s32>(floorf(t1));
    f32 frac1 = t1 - static_cast<f32>(i1);
    s32 j1 = i1 + 1 < 82 ? i1 + 1 : 82;
    f32 v = Unk_Lerp(Unk_Table1[i1].field_0[0].field_0, Unk_Table1[j1].field_0[0].field_0, frac1);
    if (encode) {
        if (r > 0.0f) {
            r = powf(r, 1.0f / 2.2f);
        }
        if (g > 0.0f) {
            g = powf(g, 1.0f / 2.2f);
        }
        if (b > 0.0f) {
            b = powf(b, 1.0f / 2.2f);
        }
        if (v > 0.0f) {
            v = powf(v, 1.0f / 2.2f);
        }
    }
    return Unk_Float4(r, g, b, v);
}

// 0x7100411b00: the RGB to XYZ matrix of three primaries and a white point
// (their CIE x and y)
// (the primaries' last row is set with [3][3] before [3][2]: with the four
// zeros from [2][3] to [3][2] stored one after the other, MemCpyOpt makes
// them a memset, whose two 8-byte stores come in descending order)
MATRIXT44* Unk_411b00(MATRIXT44* out, const Unk_410f90_Point* red, const Unk_410f90_Point* green,
                      const Unk_410f90_Point* blue, const Unk_410f90_Point* white) {
    f32 rx = red->field_0.field_0;
    f32 ry = red->field_4.field_0;
    f32 gx = green->field_0.field_0;
    f32 gy = green->field_4.field_0;
    f32 bx = blue->field_0.field_0;
    f32 by = blue->field_4.field_0;
    f32 wx = white->field_0.field_0;
    f32 wy = white->field_4.field_0;
    f32 rz = 1.0f - rx - ry;
    f32 gz = 1.0f - gx - gy;
    f32 bz = 1.0f - bx - by;
    f32 wz = 1.0f - wx - wy;
    MATRIXT44 primaries;
    primaries.field_0[0][0] = rx;
    primaries.field_0[0][1] = ry;
    primaries.field_0[0][2] = rz;
    primaries.field_0[0][3] = 0.0f;
    primaries.field_0[1][0] = gx;
    primaries.field_0[1][1] = gy;
    primaries.field_0[1][2] = gz;
    primaries.field_0[1][3] = 0.0f;
    primaries.field_0[2][0] = bx;
    primaries.field_0[2][1] = by;
    primaries.field_0[2][2] = bz;
    primaries.field_0[2][3] = 0.0f;
    primaries.field_0[3][0] = 0.0f;
    primaries.field_0[3][1] = 0.0f;
    primaries.field_0[3][3] = 1.0f;
    primaries.field_0[3][2] = 0.0f;
    MATRIXT44 inverse;
    Unk_4155f0(&inverse, &primaries);
    f32 scale = 1.0f / wy;
    f32 x = wx * scale;
    f32 y = wy * scale;
    f32 z = scale * wz;
    MATRIXT44 weights;
    weights.field_0[0][1] = 0.0f;
    weights.field_0[0][2] = 0.0f;
    weights.field_0[0][3] = 0.0f;
    weights.field_0[1][0] = 0.0f;
    weights.field_0[1][2] = 0.0f;
    weights.field_0[1][3] = 0.0f;
    weights.field_0[2][0] = 0.0f;
    weights.field_0[2][1] = 0.0f;
    weights.field_0[2][3] = 0.0f;
    weights.field_0[3][0] = 0.0f;
    weights.field_0[3][1] = 0.0f;
    weights.field_0[3][2] = 0.0f;
    f32 r = x * inverse.field_0[0][0] + y * inverse.field_0[1][0] + z * inverse.field_0[2][0];
    f32 g = x * inverse.field_0[0][1] + y * inverse.field_0[1][1] + z * inverse.field_0[2][1];
    f32 b = x * inverse.field_0[0][2] + y * inverse.field_0[1][2] + z * inverse.field_0[2][2];
    weights.field_0[0][0] = r;
    weights.field_0[1][1] = g;
    weights.field_0[2][2] = b;
    weights.field_0[3][3] = 1.0f;
    MATRIXT44 result;
    MATRIXT44_MatrixMultiply(&result, &weights, &primaries);
    *out = result;
    return out;
}

// 0x7100411c70: how many levels of a pyramid that shrinks by `base` each
// level a `size` needs (at most `maxLevels` when that is not negative), the
// first level's count (odd for mode 1, even for mode 2) and the scale that
// goes with them
// NON_MATCHING: the original computes the even case's `(mode == 2) & count`
// before the odd case's `~count & 1` and selects with `csel ne` (here the
// other way round, `csel eq`), and the last product lands in s3 here.
// Tried: if/else, switch and select forms of the adjustment
void Unk_411c70(f32 size, f32 ratio, s32 base, s32 mode, s32 maxLevels, s32* outLevels, s32* outCount, f32* outScale) {
    f32 b = static_cast<f32>(base);
    if (ratio > 1.0f && b * ratio >= size) {
        ratio = fmaxf(size / b, 1.0f);
    }
    f32 t = size / ratio + 1.0f;
    s32 levels;
    s32 count;
    f32 scale;
    if (t > 1.1f) {
        levels = static_cast<s32>(ceilf(fmaxf(logf(t) / logf(b), 1.0f)));
        count = static_cast<s32>(ceilf(t * b / powf(b, static_cast<f32>(levels))));
        if (count == 0) {
            count = base;
        }
        count = (mode == 1 ? (~count & 1) : (mode == 2) & count) + count;
        bool over = count > base;
        bool clamp = maxLevels >= 0 && levels > maxLevels;
        if (clamp | over) {
            count = base;
        }
        if (clamp) {
            levels = maxLevels;
        }
        scale = size / (powf(b, static_cast<f32>(levels - 1)) * static_cast<f32>(count) - 1.0f);
    } else {
        levels = 0;
        count = 0;
        scale = 0.0f;
    }
    if (outLevels != nullptr) {
        *outLevels = levels;
    }
    if (outCount != nullptr) {
        *outCount = count;
    }
    if (outScale != nullptr) {
        *outScale = scale;
    }
}

// 0x7100411df0: the sample offsets of a downsampling filter: up to `arg3`
// (5 when negative) per axis, every `arg5`th one, over a source of arg6 by arg7
// texels in steps of arg8 by arg9 (or arg6 * arg10 by arg7 * arg11), in texels
// of a `width` by `height` texture (`arg4`: half as far apart); their count.
// With a spread `arg12` and one sample, two at plus and minus arg12 instead.
s32 Unk_411df0(s32 width, s32 height, Unk_Float4* weights, s32 arg3, bool arg4, s32 arg5, f32 arg6, f32 arg7,
               f32 arg8, f32 arg9, f32 arg10, f32 arg11, f32 arg12) {
    s32 limit = arg3 < 0 ? 5 : arg3;
    if (arg10 > 0.0f) {
        arg8 = arg6 * arg10;
    }
    if (arg11 > 0.0f) {
        arg9 = arg7 * arg11;
    }
    s32 countX;
    s32 countY;
    if (arg4) {
        countX = static_cast<s32>(ceilf(arg6 / arg8));
        countY = static_cast<s32>(ceilf(arg7 / arg9));
        if (arg8 >= 8.0f && countX >= 2) {
            s32 n = countX - 1;
            f32 t = arg8 * static_cast<f32>(n);
            if (t < arg6 && t >= arg6 - static_cast<f32>(n)) {
                countX = n;
            }
        }
        if (arg9 >= 8.0f && countY >= 2) {
            s32 n = countY - 1;
            f32 t = arg9 * static_cast<f32>(n);
            if (t < arg7 && t >= arg7 - static_cast<f32>(n)) {
                countY = n;
            }
        }
    } else {
        countX = static_cast<s32>(ceilf(arg6 * 0.5f / arg8));
        countY = static_cast<s32>(ceilf(arg7 * 0.5f / arg9));
        if (arg8 >= 8.0f && countX >= 2) {
            s32 n = countX - 1;
            f32 t = arg8 * static_cast<f32>(n) * 2.0f;
            if (t < arg6 && t >= arg6 - static_cast<f32>(n * 2)) {
                countX = n;
            }
        }
        if (arg9 >= 8.0f && countY >= 2) {
            s32 n = countY - 1;
            f32 t = arg9 * static_cast<f32>(n) * 2.0f;
            if (t < arg7 && t >= arg7 - static_cast<f32>(n * 2)) {
                countY = n;
            }
        }
    }
    f32 invWidth = 1.0f / static_cast<f32>(static_cast<u32>(width));
    countX = countX < limit ? countX : limit;
    countY = countY < limit ? countY : limit;
    f32 scale = arg4 ? 0.5f : 1.0f;
    f32 x[5];
    f32 y[5];
    if (countX >= 1) {
        for (s32 i = 0; i != countX; i++) {
            f32 n = static_cast<f32>(countX);
            f32 position = scale * (2.0f * n / n * static_cast<f32>(i) - (n - 1.0f));
            x[i] = invWidth * position;
        }
    }
    f32 invHeight = 1.0f / static_cast<f32>(static_cast<u32>(height));
    if (countY >= 1) {
        for (s32 i = 0; i != countY; i++) {
            f32 n = static_cast<f32>(countY);
            f32 position = scale * (2.0f * n / n * static_cast<f32>(i) - (n - 1.0f));
            y[i] = invHeight * position;
        }
    }
    if (arg12 > 0.0f && countY == 1 && countX == 1 && !arg4) {
        // (any step that compares with the size)
        if (arg8 < arg6 || arg8 >= arg6) {
            x[0] = invWidth * -arg12;
            x[1] = invWidth * arg12;
            y[0] = invHeight * -arg12;
            y[1] = invHeight * arg12;
            countY = 2;
        } else {
            countY = 1;
        }
        countX = countY;
    }
    s32 stride = arg5 > 1 ? arg5 : 1;
    // the count, and the index of the last offset written (two variables)
    s32 count = 0;
    s32 index = -1;
    for (s32 j = 0; j < countY; j += stride) {
        for (s32 i = 0; i < countX; i += stride) {
            count++;
            index++;
            weights[index] = Unk_Float4(x[i], y[j], 0.0f, 0.0f);
        }
    }
    return count;
}

// 0x7100412170: four sample offsets around a texel of a `width` by
// `height` texture, and their weights
void Unk_412170(u32 width, u32 height, Unk_Float4* offsets, Unk_Float4* weights, f32 scale) {
    f32 dx = 1.0f / static_cast<f32>(width);
    f32 dy = 1.0f / static_cast<f32>(height);
    f32 s = scale - 0.5f;
    offsets[0] = Unk_Float4(-(dx * s), -(dy * s), 0.0f, 0.0f);
    offsets[1] = Unk_Float4(dx * s, -(dy * s), 0.0f, 0.0f);
    offsets[2] = Unk_Float4(-(dx * s), dy * s, 0.0f, 0.0f);
    offsets[3] = Unk_Float4(dx * s, dy * s, 0.0f, 0.0f);
    if (weights != nullptr) {
        weights[0] = Unk_Float4(0.25f, 0.25f, 0.25f, 0.25f);
        weights[1] = Unk_Float4(0.25f, 0.25f, 0.25f, 0.25f);
        weights[2] = Unk_Float4(0.25f, 0.25f, 0.25f, 0.25f);
        weights[3] = Unk_Float4(0.25f, 0.25f, 0.25f, 0.25f);
    }
}

// 0x71004121e0: a Gaussian's weights (divided by sigma * sqrt(2 pi) if `normalize`)
void Unk_4121e0(s32 count, f32* weights, bool normalize, f32 sigma) {
    f32 scale = 1.0f;
    if (normalize) {
        scale = 1.0f / (sigma * 2.5066283f);
    }
    f32 k = 1.0f / (2.0f * sigma * sigma);
    for (s32 i = 0; i < count; i++) {
        f32 x = static_cast<f32>(i);
        weights[i] = scale * expf(-(k * (x * x)));
    }
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

// 0x71004122b0: a 3x3 kernel's weights as five bilinear samples
void Unk_4122b0(u32 width, u32 height, const f32* kernel, Unk_Float4* offsets, f32* weights, f32 scale) {
    f32 dx = scale / static_cast<f32>(width);
    f32 dy = scale / static_cast<f32>(height);
    offsets[0].field_0[0].field_0 = 0.0f;
    offsets[0].field_0[1].field_0 = 0.0f;
    offsets[0].field_0[2].field_0 = 0.0f;
    offsets[0].field_0[3].field_0 = 0.0f;
    offsets[1].field_0[2].field_0 = 0.0f;
    offsets[1].field_0[3].field_0 = 0.0f;
    offsets[2].field_0[2].field_0 = 0.0f;
    offsets[2].field_0[3].field_0 = 0.0f;
    offsets[3].field_0[2].field_0 = 0.0f;
    offsets[3].field_0[3].field_0 = 0.0f;
    offsets[4].field_0[2].field_0 = 0.0f;
    offsets[4].field_0[3].field_0 = 0.0f;
    weights[0] = kernel[4];
    Unk_412270(-dx, dx * 0.0f, kernel[0], kernel[1], &offsets[1].field_0[0].field_0, &weights[1]);
    offsets[1].field_0[1].field_0 = -dy;
    weights[1] *= 2.0f;
    Unk_412270(-dy, dy * 0.0f, kernel[2], kernel[5], &offsets[2].field_0[1].field_0, &weights[2]);
    offsets[2].field_0[0].field_0 = dx;
    weights[2] *= 2.0f;
    Unk_412270(dy * 0.0f, dy, kernel[3], kernel[6], &offsets[3].field_0[1].field_0, &weights[3]);
    offsets[3].field_0[0].field_0 = -dx;
    weights[3] *= 2.0f;
    Unk_412270(dx * 0.0f, dx, kernel[7], kernel[8], &offsets[4].field_0[0].field_0, &weights[4]);
    offsets[4].field_0[1].field_0 = dy;
    weights[4] *= 2.0f;
}

// 0x7100412400: nine samples of a fixed kernel and their weights, which add up to 1
void Unk_412400(u32 width, u32 height, Unk_Float4* offsets, f32* weights, f32 scale) {
    f32 dx = scale / static_cast<f32>(width);
    f32 dy = scale / static_cast<f32>(height);
    offsets[0] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    weights[0] = 1.0f;
    offsets[1] = Unk_Float4(dx * -1.4444444f, dy * 0.0f, 0.0f, 0.0f);
    weights[1] = 1.8f;
    offsets[2] = Unk_Float4(dx * 1.4444444f, dy * 0.0f, 0.0f, 0.0f);
    weights[2] = 1.8f;
    offsets[3] = Unk_Float4(dx * 0.0f, dy * -1.4444444f, 0.0f, 0.0f);
    weights[3] = 1.8f;
    offsets[4] = Unk_Float4(dy * 0.0f, dy * 1.4444444f, 0.0f, 0.0f);
    weights[4] = 1.8f;
    offsets[5] = Unk_Float4(dx * -1.2982457f, dy * -1.2982457f, 0.0f, 0.0f);
    weights[5] = 2.03062487f;
    offsets[6] = Unk_Float4(dx * 1.2982457f, dy * -1.2982457f, 0.0f, 0.0f);
    weights[6] = 2.03062487f;
    offsets[7] = Unk_Float4(dx * -1.2982457f, dy * 1.2982457f, 0.0f, 0.0f);
    weights[7] = 2.03062487f;
    offsets[8] = Unk_Float4(dx * 1.2982457f, dy * 1.2982457f, 0.0f, 0.0f);
    weights[8] = 2.03062487f;
    f32 sum = 0.0f;
    for (s32 i = 0; i < 9; i++) {
        sum += weights[i];
    }
    f32 scaleWeights = 1.0f / sum;
    for (s32 i = 0; i < 9; i++) {
        weights[i] *= scaleWeights;
    }
}

// 0x7100412560: 25 samples of a fixed 5x5 kernel (bilinear pairs) and their
// weights, which add up to 1
void Unk_412560(u32 width, u32 height, Unk_Float4* offsets, f32* weights, f32 scale) {
    f32 dx = scale / static_cast<f32>(width);
    f32 dy = scale / static_cast<f32>(height);
    offsets[0] = Unk_Float4(0.0f, 0.0f, 0.0f, 0.0f);
    weights[0] = 1.0f;
    offsets[1] = Unk_Float4(dx * -1.5f, dy * 0.0f, 0.0f, 0.0f);
    weights[1] = 2.0f;
    offsets[2] = Unk_Float4(dx * 1.5f, dy * 0.0f, 0.0f, 0.0f);
    weights[2] = 2.0f;
    offsets[3] = Unk_Float4(dx * 0.0f, dy * -1.5f, 0.0f, 0.0f);
    weights[3] = 2.0f;
    offsets[4] = Unk_Float4(dx * 0.0f, dy * 1.5f, 0.0f, 0.0f);
    weights[4] = 2.0f;
    offsets[5] = Unk_Float4(dx * -1.5f, dy * -1.5f, 0.0f, 0.0f);
    weights[5] = 4.0f;
    offsets[6] = Unk_Float4(dx * 1.5f, dy * -1.5f, 0.0f, 0.0f);
    weights[6] = 4.0f;
    offsets[7] = Unk_Float4(dx * -1.5f, dy * 1.5f, 0.0f, 0.0f);
    weights[7] = 4.0f;
    offsets[8] = Unk_Float4(dx * 1.5f, dy * 1.5f, 0.0f, 0.0f);
    weights[8] = 4.0f;
    offsets[9] = Unk_Float4(dx * -3.4285715f, dy * 0.0f, 0.0f, 0.0f);
    weights[9] = 1.75f;
    offsets[10] = Unk_Float4(dx * 3.4285715f, dy * 0.0f, 0.0f, 0.0f);
    weights[10] = 1.75f;
    offsets[11] = Unk_Float4(dx * 0.0f, dy * -3.4285715f, 0.0f, 0.0f);
    weights[11] = 1.75f;
    offsets[12] = Unk_Float4(dx * 0.0f, dy * 3.4285715f, 0.0f, 0.0f);
    weights[12] = 1.75f;
    offsets[13] = Unk_Float4(dx * -3.1666667f, dy * -3.1666667f, 0.0f, 0.0f);
    weights[13] = 0.92160004f;
    offsets[14] = Unk_Float4(dx * 3.1666667f, dy * -3.1666667f, 0.0f, 0.0f);
    weights[14] = 0.92160004f;
    offsets[15] = Unk_Float4(dx * -3.1666667f, dy * 3.1666667f, 0.0f, 0.0f);
    weights[15] = 0.92160004f;
    offsets[16] = Unk_Float4(dx * 3.1666667f, dy * 3.1666667f, 0.0f, 0.0f);
    weights[16] = 0.92160004f;
    offsets[17] = Unk_Float4(dx * -1.4011977f, dy * -3.3788047f, 0.0f, 0.0f);
    weights[17] = 2.6883662f;
    offsets[18] = Unk_Float4(dx * 1.4011977f, dy * -3.3788047f, 0.0f, 0.0f);
    weights[18] = 2.6883662f;
    offsets[19] = Unk_Float4(dx * 3.3788047f, dy * -1.4011977f, 0.0f, 0.0f);
    weights[19] = 2.6883662f;
    offsets[20] = Unk_Float4(dx * 3.3788047f, dy * 1.4011977f, 0.0f, 0.0f);
    weights[20] = 2.6883662f;
    offsets[21] = Unk_Float4(dx * 1.4011977f, dy * 3.3788047f, 0.0f, 0.0f);
    weights[21] = 2.6883662f;
    offsets[22] = Unk_Float4(dx * -1.4011977f, dy * 3.3788047f, 0.0f, 0.0f);
    weights[22] = 2.6883662f;
    offsets[23] = Unk_Float4(dx * -3.3788047f, dy * 1.4011977f, 0.0f, 0.0f);
    weights[23] = 2.6883662f;
    offsets[24] = Unk_Float4(dx * -3.3788047f, dy * -1.4011977f, 0.0f, 0.0f);
    weights[24] = 2.6883662f;
    f32 sum = 0.0f;
    for (s32 i = 0; i < 25; i++) {
        sum += weights[i];
    }
    f32 scaleWeights = 1.0f / sum;
    for (s32 i = 0; i < 25; i++) {
        weights[i] *= scaleWeights;
    }
}

// 0x7100412940: 24 samples (28 when `large`) of a fixed kernel, most of them
// bilinear pairs, and their weights, which add up to 1
// NON_MATCHING: register allocation only: the first pairs' weight is
// multiplied through s22 here, in place in s17 in the original
void Unk_412940(u32 width, u32 height, Unk_Float4* offsets, f32* weights, bool large, f32 scale) {
    f32 dx = scale / static_cast<f32>(width);
    f32 dy = scale / static_cast<f32>(height);
    offsets[0] = Unk_Float4(dx * -7.4736843f, dy, 0.0f, 0.0f);
    weights[0] = 1.9f;
    offsets[1] = Unk_Float4(dx, dy * -7.4736843f, 0.0f, 0.0f);
    weights[1] = 1.9f;
    offsets[2] = Unk_Float4(dx * 7.4736843f, dy, 0.0f, 0.0f);
    weights[2] = 1.9f;
    offsets[3] = Unk_Float4(dx, dy * 7.4736843f, 0.0f, 0.0f);
    weights[3] = 1.9f;
    offsets[4] = Unk_Float4(dx * -7.4736843f, dy * -0.5f, 0.0f, 0.0f);
    weights[4] = 3.8f;
    offsets[5] = Unk_Float4(dx * -0.5f, dy * -7.4736843f, 0.0f, 0.0f);
    weights[5] = 3.8f;
    offsets[6] = Unk_Float4(dx * 7.4736843f, dy * -0.5f, 0.0f, 0.0f);
    weights[6] = 3.8f;
    offsets[7] = Unk_Float4(dx * -0.5f, dy * 7.4736843f, 0.0f, 0.0f);
    weights[7] = 3.8f;
    f32 a = large ? 1.7f : 1.8f;
    f32 b = large ? 1.85f : 1.9f;
    f32 pa = 8.0f - 1.0f / a;
    f32 pb = 3.0f - 1.0f / b;
    f32 wab = a * 0.5f * (b * 0.5f) * 4.0f;
    offsets[8] = Unk_Float4(dx * -pa, dy * pb, 0.0f, 0.0f);
    weights[8] = wab;
    offsets[9] = Unk_Float4(dx * -pa, dy * -pb, 0.0f, 0.0f);
    weights[9] = wab;
    offsets[10] = Unk_Float4(dx * -pb, dy * -pa, 0.0f, 0.0f);
    weights[10] = wab;
    offsets[11] = Unk_Float4(dx * pb, dy * -pa, 0.0f, 0.0f);
    weights[11] = wab;
    offsets[12] = Unk_Float4(dx * pa, dy * -pb, 0.0f, 0.0f);
    weights[12] = wab;
    offsets[13] = Unk_Float4(dx * pa, dy * pb, 0.0f, 0.0f);
    weights[13] = wab;
    offsets[14] = Unk_Float4(dx * pb, dy * pa, 0.0f, 0.0f);
    weights[14] = wab;
    offsets[15] = Unk_Float4(dx * -pb, dy * pa, 0.0f, 0.0f);
    weights[15] = wab;
    f32 c = large ? 1.05f : 1.1f;
    f32 pc = 8.0f - 1.0f / c;
    f32 pa5 = 5.0f - 1.0f / a;
    f32 wca = c * 0.5f * (a * 0.5f) * 4.0f * 0.9f;
    offsets[16] = Unk_Float4(dx * -pc, dy * pa5, 0.0f, 0.0f);
    weights[16] = wca;
    offsets[17] = Unk_Float4(dx * -pc, dy * -pa5, 0.0f, 0.0f);
    weights[17] = wca;
    offsets[18] = Unk_Float4(dx * -pa5, dy * -pc, 0.0f, 0.0f);
    weights[18] = wca;
    offsets[19] = Unk_Float4(dx * pa5, dy * -pc, 0.0f, 0.0f);
    weights[19] = wca;
    offsets[20] = Unk_Float4(dx * pc, dy * -pa5, 0.0f, 0.0f);
    weights[20] = wca;
    offsets[21] = Unk_Float4(dx * pc, dy * pa5, 0.0f, 0.0f);
    weights[21] = wca;
    offsets[22] = Unk_Float4(dx * pa5, dy * pc, 0.0f, 0.0f);
    weights[22] = wca;
    offsets[23] = Unk_Float4(dx * -pa5, dy * pc, 0.0f, 0.0f);
    weights[23] = wca;
    if (large) {
        offsets[24] = Unk_Float4(dx * -6.0f, dy * -6.0f, 0.0f, 0.0f);
        weights[24] = -0.5f;
        offsets[25] = Unk_Float4(dx * 6.0f, dy * -6.0f, 0.0f, 0.0f);
        weights[25] = -0.5f;
        offsets[26] = Unk_Float4(dx * 6.0f, dy * 6.0f, 0.0f, 0.0f);
        weights[26] = -0.5f;
        offsets[27] = Unk_Float4(dx * -6.0f, dy * 6.0f, 0.0f, 0.0f);
        weights[27] = -0.5f;
    }
    s32 count = large ? 28 : 24;
    f32 sum = 0.0f;
    for (s32 i = 0; i < count; i++) {
        sum += weights[i];
    }
    f32 scaleWeights = 1.0f / sum;
    for (s32 i = 0; i < count; i++) {
        weights[i] *= scaleWeights;
    }
}

// 0x7100412d20: the sample offsets of a blur of a `width` by `height`
// texture (at most `count` rings, `mode` / 4 decides how many it needs); the
// number of offsets, -1 for all of them
s32 Unk_412d20(u32 width, u32 height, s32 count, Unk_Float4* out, s32 mode, f32 scale) {
    s32 needed = (1 << (mode / 4)) + 1;
    if (needed < count) {
        scale = static_cast<f32>(count) / static_cast<f32>(needed) * scale;
    }
    f32 dx = 1.0f / static_cast<f32>(width) * scale;
    f32 dy = 1.0f / static_cast<f32>(height) * scale;
    s32 rings = needed < count ? needed : count;
    out[0] = Unk_Float4(dx * 0.0f, dy * 0.0f, 0.0f, 0.0f);
    out[1] = Unk_Float4(dx * 0.0f, -dy, 0.0f, 0.0f);
    out[2] = Unk_Float4(-dx, dy * 0.0f, 0.0f, 0.0f);
    out[3] = Unk_Float4(dx * 0.0f, dy, 0.0f, 0.0f);
    out[4] = Unk_Float4(dx, dy * 0.0f, 0.0f, 0.0f);
    if (rings < 4) {
        return 5;
    }
    out[5] = Unk_Float4(dx * 2.0f, dy, 0.0f, 0.0f);
    out[6] = Unk_Float4(dx, dy * -2.0f, 0.0f, 0.0f);
    out[7] = Unk_Float4(dx * -2.0f, -dy, 0.0f, 0.0f);
    out[8] = Unk_Float4(-dx, dy * 2.0f, 0.0f, 0.0f);
    if (rings < 6) {
        return 9;
    }
    out[9] = Unk_Float4(dx * -4.0f, dy, 0.0f, 0.0f);
    out[10] = Unk_Float4(dx, dy * 4.0f, 0.0f, 0.0f);
    out[11] = Unk_Float4(dx * 4.0f, -dy, 0.0f, 0.0f);
    out[12] = Unk_Float4(-dx, dy * -4.0f, 0.0f, 0.0f);
    if (rings < 10) {
        return 13;
    }
    out[13] = Unk_Float4(dx * 7.0f, dy * -8.0f, 0.0f, 0.0f);
    out[14] = Unk_Float4(dx * -8.0f, dy * -7.0f, 0.0f, 0.0f);
    out[15] = Unk_Float4(dx * -7.0f, dy * 8.0f, 0.0f, 0.0f);
    out[16] = Unk_Float4(dx * 8.0f, dy * 7.0f, 0.0f, 0.0f);
    if (rings < 18) {
        return 17;
    }
    return -1;
}

// 0x7100412ed0: the same with more offsets per ring (`mode` / 8 decides)
s32 Unk_412ed0(u32 width, u32 height, s32 count, Unk_Float4* out, s32 mode, f32 scale) {
    s32 needed = (1 << (mode / 8)) + 1;
    if (needed < count) {
        scale = static_cast<f32>(count) / static_cast<f32>(needed) * scale;
    }
    f32 dx = 1.0f / static_cast<f32>(width) * scale;
    f32 dy = 1.0f / static_cast<f32>(height) * scale;
    s32 rings = needed < count ? needed : count;
    out[0] = Unk_Float4(dx * 0.0f, dy * 0.0f, 0.0f, 0.0f);
    out[1] = Unk_Float4(dx * 0.0f, -dy, 0.0f, 0.0f);
    out[2] = Unk_Float4(-dx, -dy, 0.0f, 0.0f);
    out[3] = Unk_Float4(-dx, dy * 0.0f, 0.0f, 0.0f);
    out[4] = Unk_Float4(-dx, dy, 0.0f, 0.0f);
    out[5] = Unk_Float4(dx * 0.0f, dy, 0.0f, 0.0f);
    out[6] = Unk_Float4(dx, dy, 0.0f, 0.0f);
    out[7] = Unk_Float4(dx, dy * 0.0f, 0.0f, 0.0f);
    out[8] = Unk_Float4(dx, -dy, 0.0f, 0.0f);
    if (rings < 4) {
        return 9;
    }
    out[9] = Unk_Float4(dx * 2.0f, -dy, 0.0f, 0.0f);
    out[10] = Unk_Float4(dx, dy * -2.0f, 0.0f, 0.0f);
    out[11] = Unk_Float4(dx * 2.0f, dy, 0.0f, 0.0f);
    out[12] = Unk_Float4(dx, dy * 2.0f, 0.0f, 0.0f);
    out[13] = Unk_Float4(-dx, dy * 2.0f, 0.0f, 0.0f);
    out[14] = Unk_Float4(dx * -2.0f, dy, 0.0f, 0.0f);
    out[15] = Unk_Float4(dx * -2.0f, -dy, 0.0f, 0.0f);
    out[16] = Unk_Float4(-dx, dy * -2.0f, 0.0f, 0.0f);
    if (rings < 6) {
        return 17;
    }
    out[17] = Unk_Float4(dx * -3.0f, dy * -2.0f, 0.0f, 0.0f);
    out[18] = Unk_Float4(-dx, dy * -4.0f, 0.0f, 0.0f);
    out[19] = Unk_Float4(dx * -4.0f, dy, 0.0f, 0.0f);
    out[20] = Unk_Float4(dx * -2.0f, dy * 3.0f, 0.0f, 0.0f);
    out[21] = Unk_Float4(dx, dy * 4.0f, 0.0f, 0.0f);
    out[22] = Unk_Float4(dx * 3.0f, dy * 2.0f, 0.0f, 0.0f);
    out[23] = Unk_Float4(dx * 4.0f, -dy, 0.0f, 0.0f);
    out[24] = Unk_Float4(dx * 2.0f, dy * -3.0f, 0.0f, 0.0f);
    if (rings < 10) {
        return 25;
    }
    out[25] = Unk_Float4(dx * 8.0f, dy * 0.0f, 0.0f, 0.0f);
    out[26] = Unk_Float4(dx * 7.0f, dy * -8.0f, 0.0f, 0.0f);
    out[27] = Unk_Float4(dx * 0.0f, dy * -8.0f, 0.0f, 0.0f);
    out[28] = Unk_Float4(dx * 8.0f, dy * 7.0f, 0.0f, 0.0f);
    out[29] = Unk_Float4(dx * 0.0f, dy * 8.0f, 0.0f, 0.0f);
    out[30] = Unk_Float4(dx * -7.0f, dy * 8.0f, 0.0f, 0.0f);
    out[31] = Unk_Float4(dx * -8.0f, dy * 0.0f, 0.0f, 0.0f);
    out[32] = Unk_Float4(dx * -8.0f, dy * -7.0f, 0.0f, 0.0f);
    if (rings < 18) {
        return 33;
    }
    return -1;
}

// 0x7100413160: one of the two
s32 Unk_413160(u32 width, u32 height, u32 arg2, Unk_Float4* out, u32 mode, u32 second, f32 scale) {
    if (second != 0) {
        return Unk_412ed0(width, height, arg2, out, mode, scale);
    }
    return Unk_412d20(width, height, arg2, out, mode, scale);
}

// 0x7100413170: a 3x3 Gaussian kernel (divided by sigma * sqrt(2 pi) when
// `normalize` and that is at least 1, else scaled to add up to 1)
// The `&&` keeps the test a branch: SimplifyCFG can't fold the fcmp block into
// the test of `normalize` (its fmul has a second use, the fdiv), nor
// speculate the fdiv block (an fcmp condition, an expensive instruction);
// early if-conversion makes the csel/fcsel pair.
// NON_MATCHING: one instruction: the original multiplies 2 sigma by sigma,
// here sigma by 2 sigma (see Unk_414af0)
void Unk_413170(f32* weights, bool normalize, f32 sigma) {
    sigma = fmaxf(sigma, 1e-8f);
    f32 scale = 1.0f;
    bool scaled = false;
    if (normalize && !(sigma * 2.5066283f < 1.0f)) {
        scale = 1.0f / (sigma * 2.5066283f);
        scaled = true;
    }
    f32 k = 1.0f / (2.0f * sigma * sigma);
    f32 kernel[9];
    for (s32 y = -1; y <= 1; y++) {
        for (s32 x = -1; x <= 1; x++) {
            s32 i = (y + 1) * 3 + (x + 1);
            kernel[i] = scale * expf(-static_cast<f32>(x * x + y * y) * k);
            weights[i] = kernel[i];
        }
    }
    if (!scaled) {
        f32 sum = 0.0f;
        for (s32 i = 0; i < 9; i++) {
            sum += kernel[i];
        }
        f32 inv = 1.0f / sum;
        for (s32 i = 0; i < 9; i++) {
            weights[i] *= inv;
        }
    }
}

// 0x7100413330: a 3x3 Gaussian as five bilinear samples
void Unk_413330(u32 width, u32 height, Unk_Float4* offsets, f32* weights, bool normalize, f32 sigma, f32 scale) {
    f32 kernel[9];
    Unk_413170(kernel, normalize, sigma);
    Unk_4122b0(width, height, kernel, offsets, weights, scale);
}

// 0x71004134d0: a 5x5 Gaussian as nine bilinear samples (its taps at 1 and 2
// merged by Unk_412270), divided by sigma * sqrt(2 pi) (times 0.36) when `arg4`
// and that is at least 1, else scaled to add up to 1
// (the flag set, then cleared, as in Unk_414af0: that keeps the test a branch)
// NON_MATCHING: three instructions: Unk_414af0's 2 sigma times sigma, and the
// registers of two products after it
void Unk_4134d0(u32 width, u32 height, Unk_Float4* offsets, f32* weights, bool arg4, f32 sigma, f32 scale) {
    sigma = fmaxf(sigma, 1e-8f);
    bool scaled = false;
    if (arg4) {
        scaled = true;
        if (sigma * 2.5066283f < 1.0f) {
            scaled = false;
        }
    }
    f32 dx = scale / static_cast<f32>(width);
    f32 dy = scale / static_cast<f32>(height);
    f32 k = 1.0f / (2.0f * sigma * sigma);
    f32 centre = expf(-(k * 0.0f));
    offsets[0] = Unk_Float4(dx * 0.0f, dy * 0.0f, 0.0f, 0.0f);
    weights[0] = centre;
    f32 e1 = expf(-(k * 1.0f));
    f32 e2 = expf(-(k * 4.0f));
    f32 position;
    f32 weight;
    Unk_412270(1.0f, 2.0f, e1, e2, &position, &weight);
    f32 negative = -position;
    f32 edge = weight + weight;
    f32 corner = weight * weight * 4.0f;
    offsets[1] = Unk_Float4(dx * negative, dy * 0.0f, 0.0f, 0.0f);
    weights[1] = edge;
    offsets[2] = Unk_Float4(dx * position, dy * 0.0f, 0.0f, 0.0f);
    weights[2] = edge;
    offsets[3] = Unk_Float4(dx * 0.0f, dy * negative, 0.0f, 0.0f);
    weights[3] = edge;
    offsets[4] = Unk_Float4(dy * 0.0f, dy * position, 0.0f, 0.0f);
    weights[4] = edge;
    offsets[5] = Unk_Float4(dx * negative, dy * negative, 0.0f, 0.0f);
    weights[5] = corner;
    offsets[6] = Unk_Float4(dx * position, dy * negative, 0.0f, 0.0f);
    weights[6] = corner;
    offsets[7] = Unk_Float4(dx * negative, dy * position, 0.0f, 0.0f);
    weights[7] = corner;
    offsets[8] = Unk_Float4(dx * position, dy * position, 0.0f, 0.0f);
    weights[8] = corner;
    if (scaled) {
        f32 s = 1.0f / (sigma * 2.5066283f) * 0.36f;
        for (s32 i = 0; i < 9; i++) {
            weights[i] *= s;
        }
    } else {
        f32 sum = 0.0f;
        for (s32 i = 0; i < 9; i++) {
            sum += weights[i];
        }
        f32 s = 1.0f / sum;
        for (s32 i = 0; i < 9; i++) {
            weights[i] *= s;
        }
    }
}

// 0x7100413730: the nine samples of a 3x3 Gaussian
void Unk_413730(u32 width, u32 height, Unk_Float4* offsets, f32* weights, bool normalize, f32 sigma, f32 scale) {
    f32 kernel[9];
    Unk_413170(kernel, normalize, sigma);
    f32 dx = scale / static_cast<f32>(width);
    f32 dy = scale / static_cast<f32>(height);
    for (s32 y = -1; y <= 1; y++) {
        for (s32 x = -1; x <= 1; x++) {
            s32 i = (y + 1) * 3 + (x + 1);
            offsets[i] = Unk_Float4(dx * static_cast<f32>(x), dy * static_cast<f32>(y), 0.0f, 0.0f);
            weights[i] = kernel[i];
        }
    }
}

// 0x7100413860: the 25 samples of a 5x5 Gaussian (divided by sigma * sqrt(2 pi)
// when `normalize` and that is at least 1, else scaled to add up to 1); the
// rows in a loop, as in the original (not unrolled)
// NON_MATCHING: one instruction: Unk_414af0's 2 sigma times sigma
void Unk_413860(u32 width, u32 height, Unk_Float4* offsets, f32* weights, bool normalize, f32 sigma, f32 scale) {
    sigma = fmaxf(sigma, 1e-8f);
    f32 norm = 1.0f;
    bool scaled = false;
    if (normalize && !(sigma * 2.5066283f < 1.0f)) {
        norm = 1.0f / (sigma * 2.5066283f);
        scaled = true;
    }
    f32 dx = scale / static_cast<f32>(width);
    f32 dy = scale / static_cast<f32>(height);
    f32 k = 1.0f / (2.0f * sigma * sigma);
    f32 sum = 0.0f;
    for (s32 iy = 0; iy < 5; iy++) {
        f32 y = static_cast<f32>(iy) - 2.0f;
        for (s32 ix = 0; ix < 5; ix++) {
            f32 x = static_cast<f32>(ix) - 2.0f;
            s32 i = iy * 5 + ix;
            f32 w = norm * expf(-(k * (y * y + x * x)));
            offsets[i] = Unk_Float4(dx * x, dy * y, 0.0f, 0.0f);
            weights[i] = w;
            sum += w;
        }
    }
    if (!scaled) {
        f32 inv = 1.0f / sum;
        for (s32 i = 0; i < 25; i++) {
            weights[i] *= inv;
        }
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

// 0x7100413b10: a 3-tap Gaussian at -1, 0 and +1 times `x` / `count` as
// two samples (the taps at 0 and +1 merged into one bilinear sample by
// Unk_412270), the merged one first. 0x7100413b10, 0x7100413c60 and
// 0x7100413ea0 are one body with 1, 3 and 5 taps a side: the first tap alone,
// then pairs (the one at 0 and 1 is the middle sample), read back middle
// first, then alternately left and right.
// NON_MATCHING: the original keeps the samples' arrays on the stack (stores
// stay, the far loads are not forwarded), and doesn't if-convert the block
// that computes the scale (two instructions); plus Unk_414af0's 2 sigma times
// sigma
void Unk_413b10(u32 count, f32* offsets, f32* weights, bool normalize, f32 sigma, f32 x) {
    sigma = fmaxf(sigma, 1e-8f);
    f32 scale = 1.0f;
    bool scaled = false;
    if (normalize && !(sigma * 2.5066283f < 1.0f)) {
        scale = 1.0f / (sigma * 2.5066283f) * 2.0f;
        scaled = true;
    }
    f32 k = 1.0f / (2.0f * sigma * sigma);
    f32 step = x / static_cast<f32>(count);
    f32 w[2];
    f32 o[2];
    f32 tw[3];
    f32 tp[3];
    for (s32 i = 0; i < 3; i++) {
        s32 t = i - 1;
        tw[i] = scale * expf(-(k * static_cast<f32>(t * t)));
        tp[i] = t < 0 ? -(step * static_cast<f32>(-t)) : step * static_cast<f32>(t);
    }
    w[0] = tw[0];
    o[0] = tp[0];
    for (s32 i = 1; i < 2; i++) {
        Unk_412270(tp[2 * i - 1], tp[2 * i], tw[2 * i - 1], tw[2 * i], &o[i], &w[i]);
        w[i] *= 2.0f;
    }
    if (!scaled) {
        f32 sum = 0.0f;
        for (s32 i = 0; i < 2; i++) {
            sum += w[i];
        }
        f32 inv = 1.0f / sum;
        for (s32 i = 0; i < 2; i++) {
            w[i] *= inv;
        }
    }
    for (s32 j = 0; j < 2; j++) {
        s32 index = 1;
        if ((j & 1) != 0) {
            index = 1 - (j + 1) / 2;
        } else {
            index = 1 + j / 2;
        }
        offsets[j] = o[index];
        weights[j] = w[index];
    }
}

// 0x7100413c60: Unk_413b10's body with 3 taps a side (seven taps as four
// samples)
// NON_MATCHING: Unk_413b10's differences (frame 0xa0 in the original)
void Unk_413c60(u32 count, f32* offsets, f32* weights, bool normalize, f32 sigma, f32 x) {
    sigma = fmaxf(sigma, 1e-8f);
    f32 scale = 1.0f;
    bool scaled = false;
    if (normalize && !(sigma * 2.5066283f < 1.0f)) {
        scale = 1.0f / (sigma * 2.5066283f) * 2.0f;
        scaled = true;
    }
    f32 k = 1.0f / (2.0f * sigma * sigma);
    f32 step = x / static_cast<f32>(count);
    f32 w[4];
    f32 o[4];
    f32 tw[7];
    f32 tp[7];
    for (s32 i = 0; i < 7; i++) {
        s32 t = i - 3;
        tw[i] = scale * expf(-(k * static_cast<f32>(t * t)));
        tp[i] = t < 0 ? -(step * static_cast<f32>(-t)) : step * static_cast<f32>(t);
    }
    w[0] = tw[0];
    o[0] = tp[0];
    for (s32 i = 1; i < 4; i++) {
        Unk_412270(tp[2 * i - 1], tp[2 * i], tw[2 * i - 1], tw[2 * i], &o[i], &w[i]);
        w[i] *= 2.0f;
    }
    if (!scaled) {
        f32 sum = 0.0f;
        for (s32 i = 0; i < 4; i++) {
            sum += w[i];
        }
        f32 inv = 1.0f / sum;
        for (s32 i = 0; i < 4; i++) {
            w[i] *= inv;
        }
    }
    for (s32 j = 0; j < 4; j++) {
        s32 index = 2;
        if ((j & 1) != 0) {
            index = 2 - (j + 1) / 2;
        } else {
            index = 2 + j / 2;
        }
        offsets[j] = o[index];
        weights[j] = w[index];
    }
}

// 0x7100413ea0: Unk_413b10's body with 5 taps a side (eleven taps as six
// samples)
// NON_MATCHING: Unk_413b10's differences
void Unk_413ea0(u32 count, f32* offsets, f32* weights, bool normalize, f32 sigma, f32 x) {
    sigma = fmaxf(sigma, 1e-8f);
    f32 scale = 1.0f;
    bool scaled = false;
    if (normalize && !(sigma * 2.5066283f < 1.0f)) {
        scale = 1.0f / (sigma * 2.5066283f) * 2.0f;
        scaled = true;
    }
    f32 k = 1.0f / (2.0f * sigma * sigma);
    f32 step = x / static_cast<f32>(count);
    f32 w[6];
    f32 o[6];
    f32 tw[11];
    f32 tp[11];
    for (s32 i = 0; i < 11; i++) {
        s32 t = i - 5;
        tw[i] = scale * expf(-(k * static_cast<f32>(t * t)));
        tp[i] = t < 0 ? -(step * static_cast<f32>(-t)) : step * static_cast<f32>(t);
    }
    w[0] = tw[0];
    o[0] = tp[0];
    for (s32 i = 1; i < 6; i++) {
        Unk_412270(tp[2 * i - 1], tp[2 * i], tw[2 * i - 1], tw[2 * i], &o[i], &w[i]);
        w[i] *= 2.0f;
    }
    if (!scaled) {
        f32 sum = 0.0f;
        for (s32 i = 0; i < 6; i++) {
            sum += w[i];
        }
        f32 inv = 1.0f / sum;
        for (s32 i = 0; i < 6; i++) {
            w[i] *= inv;
        }
    }
    for (s32 j = 0; j < 6; j++) {
        s32 index = 3;
        if ((j & 1) != 0) {
            index = 3 - (j + 1) / 2;
        } else {
            index = 3 + j / 2;
        }
        offsets[j] = o[index];
        weights[j] = w[index];
    }
}

// 0x7100414af0: three samples of a Gaussian at 0 and +-1 / `count`, its
// weights at 0 and `x` (divided by sigma * sqrt(2 pi) when `normalize` and
// that is at least 1, else scaled to add up to 1). The four 1-D Gaussians
// (0x7100414af0, 0x7100414be0, 0x7100414db0, 0x7100415030) are one body with
// 1, 3, 5 and 7 taps a side: the taps in an array (the stack arrays of the
// larger ones), the kernel and its positions filled positive side first
// (LoopIdiomRecognize turns the copies into the memcpys of 0x7100414be0) and
// read back interleaved by an index (the csel chain of 0x71004146f0's loop).
// The flag is set and then cleared, which keeps its test a branch (see
// Unk_413170).
// NON_MATCHING: one instruction: the original multiplies 2 sigma by sigma,
// here sigma by 2 sigma (Reassociate puts the operand of lower rank first; the
// original's order needs the second sigma to be a separate, later load at
// that point, e.g. two array elements merged by GVN after the loops are
// unrolled; no natural source for that was found)
void Unk_414af0(u32 count, f32* offsets, f32* weights, bool normalize, f32 sigma, f32 x) {
    sigma = fmaxf(sigma, 1e-8f);
    f32 s = sigma * 2.5066283f;
    bool scaled = false;
    if (normalize) {
        scaled = true;
        if (s < 1.0f) {
            scaled = false;
        }
    }
    f32 step = 1.0f / static_cast<f32>(count);
    f32 k = 1.0f / (2.0f * sigma * sigma);
    f32 taps[1];
    for (s32 i = 0; i < 1; i++) {
        f32 t = x * static_cast<f32>(i + 1);
        taps[i] = expf(-(t * t * k));
    }
    f32 t = x * 0.0f;
    f32 centre = expf(-(t * t * k));
    f32 kernel[3];
    f32 position[3];
    kernel[0] = centre;
    position[0] = 0.0f;
    for (s32 i = 0; i < 1; i++) {
        kernel[1 + i] = taps[i];
        position[1 + i] = step * static_cast<f32>(i + 1);
        kernel[2 + i] = taps[i];
        position[2 + i] = -(step * static_cast<f32>(i + 1));
    }
    f32 sum = centre;
    for (s32 i = 0; i < 1; i++) {
        sum += 2.0f * taps[i];
    }
    f32 scale = 1.0f / (scaled ? s : sum);
    // the centre, then +1, -1, +2, -2, ...
    for (s32 j = 0; j < 3; j++) {
        s32 index = 0;
        if (j != 0) {
            if ((j & 1) != 0) {
                index = j / 2 + 1;
            } else {
                index = j / 2 + 1;
            }
        }
        weights[j] = scale * kernel[index];
        offsets[j] = position[index];
    }
}

// 0x7100414be0: seven samples of a Gaussian at 0 and +-1 .. +-3 / `count`, its
// taps at 0 and +-1 .. +-3 times `x`; Unk_414af0's body with 3 taps a side
// NON_MATCHING: Unk_414af0's 2 sigma times sigma, which moves the registers
// of what follows (the sum and the memcpys come out interleaved differently)
void Unk_414be0(u32 count, f32* offsets, f32* weights, bool normalize, f32 sigma, f32 x) {
    sigma = fmaxf(sigma, 1e-8f);
    f32 s = sigma * 2.5066283f;
    bool scaled = false;
    if (normalize) {
        scaled = true;
        if (s < 1.0f) {
            scaled = false;
        }
    }
    f32 step = 1.0f / static_cast<f32>(count);
    f32 k = 1.0f / (2.0f * sigma * sigma);
    f32 taps[3];
    for (s32 i = 0; i < 3; i++) {
        f32 t = x * static_cast<f32>(i + 1);
        taps[i] = expf(-(t * t * k));
    }
    f32 t = x * 0.0f;
    f32 centre = expf(-(t * t * k));
    f32 kernel[7];
    f32 position[7];
    kernel[0] = centre;
    position[0] = 0.0f;
    for (s32 i = 0; i < 3; i++) {
        kernel[1 + i] = taps[i];
        position[1 + i] = step * static_cast<f32>(i + 1);
        kernel[4 + i] = taps[i];
        position[4 + i] = -(step * static_cast<f32>(i + 1));
    }
    f32 sum = centre;
    for (s32 i = 0; i < 3; i++) {
        sum += 2.0f * taps[i];
    }
    f32 scale = 1.0f / (scaled ? s : sum);
    // the centre, then +1, -1, +2, -2, ...
    for (s32 j = 0; j < 7; j++) {
        s32 index = 0;
        if (j != 0) {
            if ((j & 1) != 0) {
                index = j / 2 + 1;
            } else {
                index = j / 2 + 3;
            }
        }
        weights[j] = scale * kernel[index];
        offsets[j] = position[index];
    }
}

// 0x7100414db0: eleven samples of a Gaussian at 0 and +-1 .. +-5 / `count`, its
// taps at 0 and +-1 .. +-5 times `x`; Unk_414af0's body with 5 taps a side
// NON_MATCHING: Unk_414af0's 2 sigma times sigma, which moves the registers
// of what follows (the sum and the memcpys come out interleaved differently)
void Unk_414db0(u32 count, f32* offsets, f32* weights, bool normalize, f32 sigma, f32 x) {
    sigma = fmaxf(sigma, 1e-8f);
    f32 s = sigma * 2.5066283f;
    bool scaled = false;
    if (normalize) {
        scaled = true;
        if (s < 1.0f) {
            scaled = false;
        }
    }
    f32 step = 1.0f / static_cast<f32>(count);
    f32 k = 1.0f / (2.0f * sigma * sigma);
    f32 taps[5];
    for (s32 i = 0; i < 5; i++) {
        f32 t = x * static_cast<f32>(i + 1);
        taps[i] = expf(-(t * t * k));
    }
    f32 t = x * 0.0f;
    f32 centre = expf(-(t * t * k));
    f32 kernel[11];
    f32 position[11];
    kernel[0] = centre;
    position[0] = 0.0f;
    for (s32 i = 0; i < 5; i++) {
        kernel[1 + i] = taps[i];
        position[1 + i] = step * static_cast<f32>(i + 1);
        kernel[6 + i] = taps[i];
        position[6 + i] = -(step * static_cast<f32>(i + 1));
    }
    f32 sum = centre;
    for (s32 i = 0; i < 5; i++) {
        sum += 2.0f * taps[i];
    }
    f32 scale = 1.0f / (scaled ? s : sum);
    // the centre, then +1, -1, +2, -2, ...
    for (s32 j = 0; j < 11; j++) {
        s32 index = 0;
        if (j != 0) {
            if ((j & 1) != 0) {
                index = j / 2 + 1;
            } else {
                index = j / 2 + 5;
            }
        }
        weights[j] = scale * kernel[index];
        offsets[j] = position[index];
    }
}

// 0x7100415030: fifteen samples of a Gaussian at 0 and +-1 .. +-7 / `count`, its
// taps at 0 and +-1 .. +-7 times `x`; Unk_414af0's body with 7 taps a side
// NON_MATCHING: Unk_414af0's 2 sigma times sigma, which moves the registers
// of what follows; with the kernel filled after the scale (as in its siblings) it is
// also 32 bytes shorter, so the sum comes first here
void Unk_415030(u32 count, f32* offsets, f32* weights, bool normalize, f32 sigma, f32 x) {
    sigma = fmaxf(sigma, 1e-8f);
    f32 s = sigma * 2.5066283f;
    bool scaled = false;
    if (normalize) {
        scaled = true;
        if (s < 1.0f) {
            scaled = false;
        }
    }
    f32 step = 1.0f / static_cast<f32>(count);
    f32 k = 1.0f / (2.0f * sigma * sigma);
    f32 taps[7];
    for (s32 i = 0; i < 7; i++) {
        f32 t = x * static_cast<f32>(i + 1);
        taps[i] = expf(-(t * t * k));
    }
    f32 t = x * 0.0f;
    f32 centre = expf(-(t * t * k));
    f32 sum = centre;
    for (s32 i = 0; i < 7; i++) {
        sum += 2.0f * taps[i];
    }
    f32 scale = 1.0f / (scaled ? s : sum);
    f32 kernel[15];
    f32 position[15];
    kernel[0] = centre;
    position[0] = 0.0f;
    for (s32 i = 0; i < 7; i++) {
        kernel[1 + i] = taps[i];
        position[1 + i] = step * static_cast<f32>(i + 1);
        kernel[8 + i] = taps[i];
        position[8 + i] = -(step * static_cast<f32>(i + 1));
    }
    // the centre, then +1, -1, +2, -2, ...
    for (s32 j = 0; j < 15; j++) {
        s32 index = 0;
        if (j != 0) {
            if ((j & 1) != 0) {
                index = j / 2 + 1;
            } else {
                index = j / 2 + 7;
            }
        }
        weights[j] = scale * kernel[index];
        offsets[j] = position[index];
    }
}

// 0x71004155f0: the inverse of a matrix (Gauss-Jordan elimination with
// partial pivoting, the rows swapped through a permutation; `out` is left as
// it is when the matrix is singular)
// NON_MATCHING: 100 bytes longer. The original keeps the eight rows'
// addresses of the two matrices in registers across the loop over the
// columns (x8 to x15) and loads each pivot-row element again where it is
// used; here they are recomputed at each use and the scaled pivot row is
// reused from the scaling. The stack layout and the control flow match.
void Unk_4155f0(MATRIXT44* out, const MATRIXT44* m) {
    MATRIXT44 a;
    MATRIXT44 b;
    s32 perm[4];
    for (s32 i = 0; i < 4; i++) {
        perm[i] = i;
    }
    Unk_Identity(&b);
    a = *m;
    for (s32 k = 0; k < 4; k++) {
        s32 p = k;
        for (s32 i = k + 1; i < 4; i++) {
            if (fabsf(a.field_0[k][perm[p]]) < fabsf(a.field_0[k][perm[i]])) {
                p = i;
            }
        }
        if (a.field_0[k][perm[p]] == 0.0f) {
            return;
        }
        s32 t = perm[k];
        perm[k] = perm[p];
        perm[p] = t;
        s32 pk = perm[k];
        f32 inverse = 1.0f / a.field_0[k][pk];
        for (s32 j = 0; j < 4; j++) {
            if (j >= k) {
                a.field_0[j][pk] *= inverse;
            }
            b.field_0[j][pk] *= inverse;
        }
        for (s32 i = 0; i < 4; i++) {
            if (i != k) {
                s32 pi = perm[i];
                f32 f = a.field_0[k][pi] / a.field_0[k][pk];
                for (s32 j = 0; j < 4; j++) {
                    if (j >= k) {
                        a.field_0[j][pi] -= f * a.field_0[j][pk];
                    }
                    b.field_0[j][pi] -= f * b.field_0[j][pk];
                }
            }
        }
    }
    for (s32 i = 0; i < 4; i++) {
        for (s32 j = 0; j < 4; j++) {
            out->field_0[j][i] = b.field_0[j][perm[i]];
        }
    }
}

// 0x7100415370: the points of `rings` rings around the centre of a disc of
// the given radius (6 times the ring's number on each); their count
s32 Unk_415370(s32 rings, Unk_Float2* out, f32 radius) {
    s32 count = 3 * rings * (rings + 1) + 1;
    if (out != nullptr) {
        out[0].field_0[0].field_0 = radius * 0.0f;
        out[0].field_0[1].field_0 = radius * 0.0f;
        s32 index = 0;
        for (s32 ring = 1; ring <= rings; ring++) {
            s32 points = ring * 6;
            f32 step = 6.2831855f / static_cast<f32>(points);
            f32 start = step * 0.5f;
            f32 r = static_cast<f32>(ring) * radius / static_cast<f32>(rings);
            for (s32 i = 0; i < points; i++) {
                f32 angle = start + step * static_cast<f32>(i);
                f32 c = cosf(angle);
                f32 s = sinf(angle);
                out[index + 1].field_0[0].field_0 = r * c;
                out[index + 1].field_0[1].field_0 = r * s;
                index++;
            }
        }
    }
    return count;
}

}  // namespace PPFX
