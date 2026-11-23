// SiMath's view volume and 4x4 matrix as SiGfx uses them (placeholder names).
#pragma once

#include <arm_neon.h>
#include <types.h>

// A view volume: 0 for a perspective one, 1 for an orthographic one, then
// its left, right, top, bottom, near and far planes.
struct Unk_594590_Volume {
    // 0x7100594550
    Unk_594590_Volume(u32 type, f32 left, f32 right, f32 top, f32 bottom, f32 zNear, f32 zFar);
    // 0x7100594580
    ~Unk_594590_Volume();

    s32 field_0;
    s32 field_4;
    f32 field_8;   // left
    f32 field_c;   // right
    f32 field_10;  // top
    f32 field_14;  // bottom
    f32 field_18;  // near
    f32 field_1c;  // far
};
PKMN_OFFSET_ASSERT(Unk_594590_Volume, field_1c, 0x1c);

// The matrix as SiGfx's callers have it: four 16-byte rows of four floats.
// It's returned in memory, not in the vector registers a plain aggregate of
// four vectors goes in, so it has its own copy constructor.
struct Unk_Matrix44 {
    Unk_Matrix44() {}
    Unk_Matrix44(const Unk_Matrix44& other) {
        for (int i = 0; i < 4; i++) {
            r[i] = other.r[i];
        }
    }

    float32x4_t r[4];
};
PKMN_SIZE_ASSERT(Unk_Matrix44, 0x40);

// The identity (inline: placeholder name).
inline Unk_Matrix44 Unk_Identity() {
    Unk_Matrix44 result;
    result.r[0] = float32x4_t{1.0f, 0.0f, 0.0f, 0.0f};
    result.r[1] = float32x4_t{0.0f, 1.0f, 0.0f, 0.0f};
    result.r[2] = float32x4_t{0.0f, 0.0f, 1.0f, 0.0f};
    result.r[3] = float32x4_t{0.0f, 0.0f, 0.0f, 1.0f};
    return result;
}

// m moved by (x, y, z): its last row is its rows weighed by them (inline:
// placeholder name).
inline void Unk_Translate(Unk_Matrix44* m, f32 x, f32 y, f32 z) {
    m->r[3] = m->r[0] * x + m->r[1] * y + m->r[2] * z + m->r[3];
}

// a times b, row by row (inline: placeholder name).
inline Unk_Matrix44 Unk_Multiply(const Unk_Matrix44& a, const Unk_Matrix44& b) {
    Unk_Matrix44 result;
    for (int i = 0; i < 4; i++) {
        result.r[i] = b.r[0] * a.r[i][0] + b.r[1] * a.r[i][1] + b.r[2] * a.r[i][2] + b.r[3] * a.r[i][3];
    }
    return result;
}
