// A colour space's primaries and white point, as CIE x and y (placeholder
// names; Unk_StaticsBase.h's static objects and the colour functions of the
// first TU use them).
#pragma once

#include <types.h>

// a CIE x and y (placeholder)
struct Unk_410f90_Point {
    f32 field_0;
    f32 field_4;
};
// 0x20 bytes, aligned to 4 (the merged statics put it at 0xcc): three
// primaries and a white point
struct Unk_410f90 {
    Unk_410f90_Point field_0;
    Unk_410f90_Point field_8;
    Unk_410f90_Point field_10;
    Unk_410f90_Point field_18;
};
// 0x7100410f90
void Unk_410f90_set(Unk_410f90* self, u32 value);
