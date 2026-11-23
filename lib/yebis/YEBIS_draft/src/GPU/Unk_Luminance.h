// The luminance of a colour in PPFX's colour space (inline in the functions of
// several src/GPU TUs; placeholder names).
#pragma once

#include <types.h>
#include <yebis/YEBIS_draft/include/PPFX/ppfxTypes.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_StaticsBase.h>

namespace PPFX {

// 0x7100411b00 (Unk_415f40.cpp): the RGB to XYZ matrix of three primaries and
// a white point (their CIE x and y)
MATRIXT44* Unk_411b00(MATRIXT44* out, const Unk_410f90_Point* red, const Unk_410f90_Point* green,
                      const Unk_410f90_Point* blue, const Unk_410f90_Point* white);

// a dot product (inline)
inline f32 Unk_Dot(const Unk_Vector3& a, const Unk_Vector3& b) {
    return a.field_0[0] * b.field_0[0] + a.field_0[1] * b.field_0[1] + a.field_0[2] * b.field_0[2];
}

// the luminance of a colour: Rec. 709's weights when the colour space is the
// default one, else the Y row of its RGB to XYZ matrix
inline f32 Unk_Luminance(const Unk_410f90& space, const Unk_Vector3& color) {
    if (Unk_SameColorSpace(space, Unk_410f90_Object(0))) {
        Unk_Vector3 weights = {{0.2126f, 0.7152f, 0.0722f}};
        return Unk_Dot(color, weights);
    }
    MATRIXT44 m;
    Unk_411b00(&m, &space.field_0, &space.field_8, &space.field_10, &space.field_18);
    Unk_Vector3 y = {{m.field_0[0][1], m.field_0[1][1], m.field_0[2][1]}};
    return Unk_Dot(y, color);
}

}  // namespace PPFX
