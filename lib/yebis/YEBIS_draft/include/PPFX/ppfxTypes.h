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

#include <types.h>

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

    Unk_Float field_0[4];
};
PKMN_SIZE_ASSERT(Unk_Float4, 0x10);

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

}  // namespace PPFX
