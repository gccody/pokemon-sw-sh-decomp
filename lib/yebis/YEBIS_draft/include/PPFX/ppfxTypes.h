// PPFX's vector types (../include\PPFX/ppfxTypes.h is the __FILE__ of an
// assert in an element accessor called `v`, at line 17945: a large header of
// HLSL-like types). Nothing else names them, so the names are placeholders,
// and only what the executable's code shows is here.
//
// A vector's elements are objects, not plain floats: the static initialisers
// store every element of a constant vector as an integer (one of them, in
// each src/GPU TU, as another's value plus a small difference, which LLVM's
// constant hoisting only does for integers), and that is what a constructor
// taking the elements by reference and copying them as objects compiles to.
#pragma once

#include <assert.h>
#include <types.h>

// YEBIS keeps its asserts while the build defines NDEBUG for everything; this
// is <assert.h>'s assert without that switch
#define PPFX_TYPES_ASSERT(x) ((void)((x) || (__assert_fail(#x, __FILE__, __LINE__, __func__), 0)))

namespace PPFX {

// one element
struct Unk_Float {
    Unk_Float() {}
    Unk_Float(f32 value) : field_0(value) {}

    f32 field_0;
};

// two elements
struct Unk_Float2 {
    Unk_Float2() {}
    Unk_Float2(const Unk_Float& x, const Unk_Float& y) {
        field_0[0] = x;
        field_0[1] = y;
    }

    Unk_Float field_0[2];
};
PKMN_SIZE_ASSERT(Unk_Float2, 8);

// four elements
struct Unk_Float4 {
    Unk_Float4() {}
    Unk_Float4(const Unk_Float& x, const Unk_Float& y, const Unk_Float& z, const Unk_Float& w) {
        field_0[0] = x;
        field_0[1] = y;
        field_0[2] = z;
        field_0[3] = w;
    }

    enum { ELMS = 4 };
    // an element (its assert names it and gives its line)
    Unk_Float& v(s32 i) {
#line 17945
        PPFX_TYPES_ASSERT(i >= 0 && i < ELMS);
        return field_0[i];
    }
    const Unk_Float& v(s32 i) const {
#line 17945
        PPFX_TYPES_ASSERT(i >= 0 && i < ELMS);
        return field_0[i];
    }
#line 65

    Unk_Float field_0[4];
};
PKMN_SIZE_ASSERT(Unk_Float4, 0x10);

// three elements
struct Unk_Float3 {
    Unk_Float3() {}
    Unk_Float3(const Unk_Float& x, const Unk_Float& y, const Unk_Float& z) {
        field_0[0] = x;
        field_0[1] = y;
        field_0[2] = z;
    }

    enum { ELMS = 3 };
    // an element (its assert names it and gives its line)
    Unk_Float& v(s32 i) {
#line 16810
        PPFX_TYPES_ASSERT(i >= 0 && i < ELMS);
        return field_0[i];
    }
#line 87

    Unk_Float field_0[3];
};
PKMN_SIZE_ASSERT(Unk_Float3, 0xc);

// three plain floats
struct Unk_Vector3 {
    f32 field_0[3];
};
PKMN_SIZE_ASSERT(Unk_Vector3, 0xc);

// A 4x4 matrix of plain floats. MATRIXT44_MatrixMultiply (0x7100415c00) is
// the function its asserts name, which is all that names the type.
struct MATRIXT44 {
    f32 field_0[4][4];
};
PKMN_SIZE_ASSERT(MATRIXT44, 0x40);

// 0x7100415c00 (its asserts name it, and give its lines)
inline void MATRIXT44_MatrixMultiply(MATRIXT44* pOut, const MATRIXT44* pM1, const MATRIXT44* pM2) {
#line 19571
    PPFX_TYPES_ASSERT(pOut);
    PPFX_TYPES_ASSERT(pM1);
    PPFX_TYPES_ASSERT(pM2);
    MATRIXT44 result;
    for (s32 i = 0; i < 4; i++) {
        for (s32 j = 0; j < 4; j++) {
            result.field_0[i][j] = pM1->field_0[i][0] * pM2->field_0[0][j] + pM1->field_0[i][1] * pM2->field_0[1][j] +
                                   pM1->field_0[i][2] * pM2->field_0[2][j] + pM1->field_0[i][3] * pM2->field_0[3][j];
        }
    }
    *pOut = result;
}

}  // namespace PPFX
