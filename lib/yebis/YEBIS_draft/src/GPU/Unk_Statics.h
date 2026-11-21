// The static objects every TU of PPFX's src/GPU has, from a header nothing
// names (placeholder names). Each TU's static initialiser sets them up in
// this order: two objects made by Unk_410f90_set (0x7100410f90), SiSDK3's
// reflection handle, the chromaticities of 24 white points (CIE x and y of
// the illuminants A, B, C, D50, D55, D60, D65, D70, D75, D93, E, F1 to F12 and
// DCI's) and an angle of 30 degrees. None of them is constant-initialised (the
// constructors aren't constexpr), and LLVM merges them, sorted by size, with
// the TU's other statics: that layout is what the static initialisers and
// every user of a TU's statics have to reproduce.
#pragma once

#include <types.h>
#include <yebis/YEBIS_draft/include/PPFX/ppfxTypes.h>
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

inline f32 Unk_Radians(f32 degrees) {
    return degrees * 3.14159265f / 180.0f;
}

static const Unk_410f90_Object Unk_Static_Object0(0xffffffff);
static const Unk_410f90_Object Unk_Static_Object1(0x19);
static SiSDK3::SiReflectionPropertyHandle Unk_Static_Handle;

static const Unk_Float2 Unk_White_A(0.44757f, 0.40745f);
static const Unk_Float2 Unk_White_B(0.34842f, 0.35161f);
static const Unk_Float2 Unk_White_C(0.31006f, 0.31616f);
static const Unk_Float2 Unk_White_D50(0.34567f, 0.35850f);
static const Unk_Float2 Unk_White_D55(0.33242f, 0.34743f);
static const Unk_Float2 Unk_White_D60(0.32168f, 0.33767f);
static const Unk_Float2 Unk_White_D65(0.31270f, 0.32900f);
static const Unk_Float2 Unk_White_D70(0.30540f, 0.32160f);
static const Unk_Float2 Unk_White_D75(0.29902f, 0.31485f);
static const Unk_Float2 Unk_White_D93(0.28300f, 0.29800f);
static const Unk_Float2 Unk_White_E(1.0f / 3.0f, 1.0f / 3.0f);
static const Unk_Float2 Unk_White_F1(0.31310f, 0.33727f);
static const Unk_Float2 Unk_White_F2(0.37208f, 0.37529f);
static const Unk_Float2 Unk_White_F3(0.40910f, 0.39430f);
static const Unk_Float2 Unk_White_F4(0.44018f, 0.40329f);
static const Unk_Float2 Unk_White_F5(0.31379f, 0.34531f);
static const Unk_Float2 Unk_White_F6(0.37790f, 0.38835f);
static const Unk_Float2 Unk_White_F7(0.31292f, 0.32933f);
static const Unk_Float2 Unk_White_F8(0.34588f, 0.35875f);
static const Unk_Float2 Unk_White_F9(0.37417f, 0.37281f);
static const Unk_Float2 Unk_White_F10(0.34609f, 0.35986f);
static const Unk_Float2 Unk_White_F11(0.38052f, 0.37713f);
static const Unk_Float2 Unk_White_F12(0.43695f, 0.40441f);
static const Unk_Float2 Unk_White_DCI(0.31400f, 0.35100f);

static const f32 Unk_Static_Angle = Unk_Radians(30.0f);

}  // namespace PPFX
