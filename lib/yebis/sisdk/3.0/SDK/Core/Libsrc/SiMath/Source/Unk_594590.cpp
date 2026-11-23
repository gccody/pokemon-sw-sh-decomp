// Scope: common
// SiMath's view volume and projection matrix (placeholder file, types and
// names): the matrix from a volume's six planes, perspective or orthographic,
// for one of two handednesses.
#include <types.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiMath/Unk_Matrix.h>

// A 4x4 matrix, the identity when it's made (placeholder).
struct Unk_594590_Matrix {
    Unk_594590_Matrix() {
        m[0][0] = 1.0f;
        m[0][1] = 0.0f;
        m[0][2] = 0.0f;
        m[0][3] = 0.0f;
        m[1][0] = 0.0f;
        m[1][1] = 1.0f;
        m[1][2] = 0.0f;
        m[1][3] = 0.0f;
        m[2][0] = 0.0f;
        m[2][1] = 0.0f;
        m[2][2] = 1.0f;
        m[2][3] = 0.0f;
        m[3][0] = 0.0f;
        m[3][1] = 0.0f;
        m[3][2] = 0.0f;
        m[3][3] = 1.0f;
    }

    f32 m[4][4];
};
PKMN_SIZE_ASSERT(Unk_594590_Matrix, 0x40);

// 0x7100594550
Unk_594590_Volume::Unk_594590_Volume(u32 type, f32 left, f32 right, f32 top, f32 bottom, f32 zNear, f32 zFar)
    : field_0(type), field_4(1), field_8(left), field_c(right), field_10(top), field_14(bottom), field_18(zNear),
      field_1c(zFar) {}

// 0x7100594580
Unk_594590_Volume::~Unk_594590_Volume() {}

// 0x7100594590
Unk_594590_Matrix Unk_594590(const Unk_594590_Volume* volume, s32 handedness) {
    f32 top = volume->field_10;
    f32 bottom = volume->field_14;
    f32 left = volume->field_8;
    f32 right = volume->field_c;
    f32 zNear = volume->field_18;
    f32 zFar = volume->field_1c;
    // (the planes are read before the identity is stored: the matrix is
    // declared after them, and top and bottom are read first)
    Unk_594590_Matrix result;
    if (volume->field_0 == 0) {
        if (handedness == 0) {
            result.m[0][0] = (zNear + zNear) / (right - left);
            result.m[1][1] = (zNear + zNear) / (top - bottom);
            result.m[2][0] = (left + right) / (left - right);
            result.m[2][1] = (top + bottom) / (bottom - top);
            result.m[3][3] = 0.0f;
            result.m[2][3] = 1.0f;
            result.m[2][2] = zFar / (zFar - zNear);
            result.m[3][2] = zNear * zFar / (zNear - zFar);
        } else if (handedness == 1) {
            result.m[0][0] = (zNear + zNear) / (right - left);
            result.m[1][1] = (zNear + zNear) / (top - bottom);
            result.m[2][0] = (left + right) / (right - left);
            result.m[2][1] = (top + bottom) / (top - bottom);
            result.m[3][3] = 0.0f;
            result.m[2][3] = -1.0f;
            result.m[2][2] = zFar / (zNear - zFar);
            result.m[3][2] = zNear * zFar / (zNear - zFar);
        }
    } else if (volume->field_0 == 1) {
        if (handedness == 0) {
            result.m[0][0] = 2.0f / (right - left);
            result.m[3][3] = 1.0f;
            result.m[1][1] = 2.0f / (top - bottom);
            result.m[2][2] = 1.0f / (zFar - zNear);
            result.m[2][3] = 0.0f;
            result.m[3][0] = (left + right) / (left - right);
            result.m[3][1] = (top + bottom) / (bottom - top);
            result.m[3][2] = -zNear / (zFar - zNear);
        } else if (handedness == 1) {
            result.m[0][0] = 2.0f / (right - left);
            result.m[3][3] = 1.0f;
            result.m[1][1] = 2.0f / (top - bottom);
            result.m[2][2] = -1.0f / (zFar - zNear);
            result.m[2][3] = 0.0f;
            result.m[3][0] = (left + right) / (left - right);
            result.m[3][1] = (top + bottom) / (bottom - top);
            result.m[3][2] = -zNear / (zFar - zNear);
        }
    }
    return result;
}
