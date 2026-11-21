// The first static objects of every PPFX TU (placeholder names): two objects
// made by Unk_410f90_set (0x7100410f90) and SiSDK3's reflection handle. A TU
// that has only these (IGPUInterface's, TFXString.cpp) includes this header;
// the others include Unk_Statics.h, which adds the white points after them.
#pragma once

#include <types.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Reflection.h>

// 0x20 bytes, aligned to 4 (the merged statics put it at 0xcc)
struct Unk_410f90 {
    f32 field_0[8];
};
// 0x7100410f90
void Unk_410f90_set(Unk_410f90* self, u32 value);

namespace PPFX {

struct Unk_410f90_Object : Unk_410f90 {
    explicit Unk_410f90_Object(u32 value) { Unk_410f90_set(this, value); }
};

static const Unk_410f90_Object Unk_Static_Object0(0xffffffff);
static const Unk_410f90_Object Unk_Static_Object1(0x19);
static SiSDK3::SiReflectionPropertyHandle Unk_Static_Handle;

}  // namespace PPFX
