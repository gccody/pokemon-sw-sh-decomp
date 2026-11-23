// Scope: common
// YEBIS's first translation unit (0x710040f610 to 0x7100417870, before
// ppfx.cpp): matrix and filter kernel helpers and the SiReflection
// properties its static initialiser 0x7100415f40 registers. Its name isn't
// in the executable.
#include <math.h>

#include <yebis/YEBIS_draft/src/Unk_415f40.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_410f90.h>

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

// 0x710040f9b0: a perspective projection rebuilt (with Unk_40f8d0's depth
// range of -1 to 1) from one with a depth range of 0 to 1 (the two atanf calls
// are the fields of view, which nothing uses)
// NON_MATCHING: register allocation only: the left edge's product and the
// constant -0.5 are in s6 and s7 here, s7 and s16 in the original (and far
// times -2 in s3, not s6)
MATRIXT44* Unk_40f9b0(MATRIXT44* out, const MATRIXT44* m, bool flip) {
    f32 sign = m->field_0[2][3] > 0.0f ? 1.0f : -1.0f;
    f32 b = -m->field_0[3][2];
    f32 a = sign * m->field_0[2][2];
    f32 near = b / a;
    f32 far = b / (a - 1.0f);
    f32 width = (near + near) / m->field_0[0][0];
    f32 height = (near + near) / m->field_0[1][1];
    f32 x = sign * m->field_0[2][0];
    f32 y = sign * m->field_0[2][1];
    f32 left = width * (x + 1.0f) * -0.5f;
    f32 right = width * (1.0f - x) * 0.5f;
    f32 bottom = height * (y + 1.0f) * -0.5f;
    f32 top = height * (1.0f - y) * 0.5f;
    f32 rx;
    f32 ry;
    Unk_40f980(m, &rx, &ry);
    atanf(rx);
    atanf(ry);
    Unk_40f8d0(out, true, sign > 0.0f && !flip, left, right, bottom, top, near, far);
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

// 0x71004155f0 (not written yet): the inverse of a matrix
void Unk_4155f0(MATRIXT44* out, const MATRIXT44* m);

}  // namespace PPFX

// 0x7100410960 (not written yet): the primaries and white point of a colour
// space by its number
void Unk_410960(Unk_410f90* self, u32 value);

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
    if (from->field_0 == to->field_0 && from->field_4 == to->field_4) {
        out->field_0[0][1] = out->field_0[0][2] = out->field_0[0][3] = out->field_0[1][0] = out->field_0[1][2] =
            out->field_0[1][3] = out->field_0[2][0] = out->field_0[2][1] = out->field_0[2][3] = out->field_0[3][0] =
                out->field_0[3][1] = out->field_0[3][2] = 0.0f;
        out->field_0[0][0] = out->field_0[1][1] = out->field_0[2][2] = out->field_0[3][3] = 1.0f;
        return out;
    }
    f32 fromScale = 1.0f / from->field_4;
    f32 fromZ = 1.0f - from->field_0 - from->field_4;
    f32 fromX = from->field_0 * fromScale;
    fromZ = fromScale * fromZ;
    f32 toZ = 1.0f - to->field_0 - to->field_4;
    f32 toScale = 1.0f / to->field_4;
    f32 toX = to->field_0 * toScale;
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

// 0x7100411b00: the RGB to XYZ matrix of three primaries and a white point
// (their CIE x and y)
// (the primaries' last row is set with [3][3] before [3][2]: with the four
// zeros from [2][3] to [3][2] stored one after the other, MemCpyOpt makes
// them a memset, whose two 8-byte stores come in descending order)
MATRIXT44* Unk_411b00(MATRIXT44* out, const Unk_410f90_Point* red, const Unk_410f90_Point* green,
                      const Unk_410f90_Point* blue, const Unk_410f90_Point* white) {
    f32 rx = red->field_0;
    f32 ry = red->field_4;
    f32 gx = green->field_0;
    f32 gy = green->field_4;
    f32 bx = blue->field_0;
    f32 by = blue->field_4;
    f32 wx = white->field_0;
    f32 wy = white->field_4;
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
// NON_MATCHING: two instructions. The original multiplies 2 sigma by sigma
// (here sigma by 2 sigma), and makes the flag with `csel` from the same
// comparison as the scale (`cset` of the inverted one here).
void Unk_413170(f32* weights, bool normalize, f32 sigma) {
    sigma = fmaxf(sigma, 1e-8f);
    f32 scale = 1.0f;
    bool scaled = false;
    if (normalize) {
        f32 s = sigma * 2.5066283f;
        if (!(s < 1.0f)) {
            scale = 1.0f / s;
            scaled = true;
        }
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
// two samples (the centre and +1 tap merged into one bilinear sample), from
// the last to the first
// NON_MATCHING: Unk_414af0's differences (the test of `normalize` is a branch
// in the original, with one block setting the scale to 1 for both failed
// tests; 2 sigma times sigma), and the original keeps the two samples'
// arrays on the stack (their stores stay, the loads are forwarded), so its
// loops over them were unrolled later than here
void Unk_413b10(u32 count, f32* offsets, f32* weights, bool normalize, f32 sigma, f32 x) {
    sigma = fmaxf(sigma, 1e-8f);
    f32 scale = 1.0f;
    bool scaled = false;
    if (normalize) {
        f32 s = sigma * 2.5066283f;
        if (!(s < 1.0f)) {
            scale = 1.0f / s * 2.0f;
            scaled = true;
        }
    }
    f32 k = 1.0f / (2.0f * sigma * sigma);
    f32 step = x / static_cast<f32>(count);
    f32 kernel[3];
    for (s32 i = -1; i <= 1; i++) {
        kernel[i + 1] = scale * expf(-static_cast<f32>(i * i) * k);
    }
    f32 w[2];
    f32 o[2];
    w[0] = kernel[0];
    o[0] = -step;
    f32 sum = kernel[1] + kernel[2];
    f32 t = 0.0f;
    if (sum > 0.0f) {
        t = kernel[1] / sum;
    }
    f32 p0 = step * 0.0f;
    o[1] = step + (p0 - step) * t;
    w[1] = sum * 0.5f * 2.0f;
    if (!scaled) {
        f32 total = 0.0f;
        for (s32 i = 0; i < 2; i++) {
            total += w[i];
        }
        f32 inv = 1.0f / total;
        for (s32 i = 0; i < 2; i++) {
            w[i] *= inv;
        }
    }
    for (s32 i = 0; i < 2; i++) {
        offsets[i] = o[1 - i];
        weights[i] = w[1 - i];
    }
}

// 0x7100414af0: three samples of a Gaussian at 0 and +-1 / `count`, its
// weights at 0 and `x` (divided by sigma * sqrt(2 pi) when `normalize` and
// that is at least 1, else scaled to add up to 1)
// NON_MATCHING: Unk_413170's two differences: the original keeps the test of
// `normalize` a branch (the flag a `csel` of the scale's comparison) and
// multiplies 2 sigma by sigma; here both tests become selects and sigma is
// multiplied by 2 sigma.
// (Reassociate puts the operand of lower rank first, and 2 sigma's rank is
// always above sigma's: the original's order needs the two sigmas to be two
// loads at that point, merged by GVN later. A sigma[2] filled in a loop and
// multiplied as 2 * s[0] * s[1] gives it, which isn't natural code. The
// k-first products and the centre-first sum come from loops over the taps,
// unrolled after Reassociate, as 0x7100414be0 shows: tap arrays on the stack.)
void Unk_414af0(u32 count, f32* offsets, f32* weights, bool normalize, f32 sigma, f32 x) {
    sigma = fmaxf(sigma, 1e-8f);
    f32 s = sigma * 2.5066283f;
    f32 norm = 1.0f;
    bool scaled = false;
    if (normalize) {
        if (!(s < 1.0f)) {
            norm = s;
            scaled = true;
        }
    }
    f32 k = 1.0f / (2.0f * sigma * sigma);
    f32 step = 1.0f / static_cast<f32>(count);
    f32 w1 = expf(-(k * (x * x)));
    f32 t = x * 0.0f;
    f32 w0 = expf(-(t * t * k));
    if (!scaled) {
        norm = w0 + 2.0f * w1;
    }
    f32 scale = 1.0f / norm;
    weights[0] = scale * w0;
    offsets[0] = 0.0f;
    weights[1] = scale * w1;
    offsets[1] = step;
    weights[2] = scale * w1;
    offsets[2] = -step;
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
