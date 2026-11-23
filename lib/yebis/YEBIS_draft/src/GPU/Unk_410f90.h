// A colour space's primaries and white point, as CIE x and y (placeholder
// names; Unk_StaticsBase.h's static objects and the colour functions of the
// first TU use them).
#pragma once

#include <types.h>
#include <yebis/YEBIS_draft/include/PPFX/ppfxTypes.h>

// a CIE x and y (placeholder). The elements are PPFX's element objects:
// Unk_410960 stores the primaries as integers (LLVM's constant hoisting
// derives some of them from others), which copies of them compile to, and it
// copies a white point element by element (both read before either is
// written).
struct Unk_410f90_Point {
    Unk_410f90_Point() {}
    Unk_410f90_Point(const PPFX::Unk_Float& x, const PPFX::Unk_Float& y) : field_0(x), field_4(y) {}
    Unk_410f90_Point& operator=(const PPFX::Unk_Float2& v) {
        PPFX::Unk_Float y = v.field_0[1];
        PPFX::Unk_Float x = v.field_0[0];
        field_0 = x;
        field_4 = y;
        return *this;
    }

    PPFX::Unk_Float field_0;
    PPFX::Unk_Float field_4;
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

namespace PPFX {
// a colour space made by Unk_410f90_set (the static objects' type, and the
// temporary the luminance functions compare with)
struct Unk_410f90_Object : Unk_410f90 {
    explicit Unk_410f90_Object(u32 value) { Unk_410f90_set(this, value); }
};
}  // namespace PPFX

// whether two colour spaces are the same (inline). `&&`, not `&`: with one
// block of tests the not-same block is the entry's immediate successor, and
// MachineCSE then reuses the entry's `mov x0, sp` for Unk_411b00's arguments
// (a register kept across the calls) where the original materialises it again.
inline bool Unk_SameColorSpace(const Unk_410f90& a, const Unk_410f90& b) {
    return a.field_0.field_0.field_0 == b.field_0.field_0.field_0 &&
           a.field_0.field_4.field_0 == b.field_0.field_4.field_0 &&
           a.field_8.field_0.field_0 == b.field_8.field_0.field_0 &&
           a.field_8.field_4.field_0 == b.field_8.field_4.field_0 &&
           a.field_10.field_0.field_0 == b.field_10.field_0.field_0 &&
           a.field_10.field_4.field_0 == b.field_10.field_4.field_0 &&
           a.field_18.field_0.field_0 == b.field_18.field_0.field_0 &&
           a.field_18.field_4.field_0 == b.field_18.field_4.field_0;
}
