// The static objects every YEBIS (PPFX) translation unit has, and so the
// header that defines them (its name isn't in the executable: placeholder).
// Each TU's static initialiser constructs them in this order: two colour
// spaces' primaries (0x7100410f90 fills them in: -1 and 25, one past the last
// colour space, are empty) and SiSDK3's reflection handle. Most TUs have
// Unk_ColorSpace.h's after them. They're all `static`, and dynamically
// initialised, so LLVM merges them into one object per TU, smallest first.
#pragma once

#include <types.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Reflection.h>

struct Unk_410f90;
// 0x7100410f90: a colour space's primaries and white point
void Unk_410f90_set(Unk_410f90* self, u32 colorSpace);

namespace PPFX {

// red, green, blue and white
struct Unk_Primaries {
    explicit Unk_Primaries(s32 colorSpace) { Unk_410f90_set(reinterpret_cast<Unk_410f90*>(this), colorSpace); }

    f32 field_0[8];
};
PKMN_SIZE_ASSERT(Unk_Primaries, 0x20);

static const Unk_Primaries Unk_PrimariesNone(-1);
static const Unk_Primaries Unk_PrimariesCount(25);
static SiSDK3::SiReflectionPropertyHandle Unk_ReflectionHandle;

}  // namespace PPFX
