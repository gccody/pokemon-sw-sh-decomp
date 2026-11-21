// The static objects most YEBIS (PPFX) translation units have after
// Unk_Primaries.h's, and so the header that defines them (its name isn't in
// the executable: placeholder): the CIE standard illuminants' chromaticities
// (A, B, C, D50, D55, D60, D65, D70, D75, D93, E, F1 to F12, DCI) and an
// angle of 30 degrees. The chromaticities are copied member by member from a
// temporary: the static initialisers store them as integers (LLVM's constant
// hoisting then derives D60's x from D70's y, and the stores merge in pairs
// from there on).
#pragma once

#include <yebis/YEBIS_draft/include/PPFX/Unk_Primaries.h>

namespace PPFX {

// xy chromaticity
struct Unk_Float2 {
    f32 x;
    f32 y;
};
struct Unk_Chromaticity {
    Unk_Chromaticity(const Unk_Float2& value) : x(value.x), y(value.y) {}

    f32 x;
    f32 y;
};
PKMN_SIZE_ASSERT(Unk_Chromaticity, 8);

inline f32 Unk_DegToRad(f32 degrees) {
    return degrees * 3.14159265358979323846f / 180.0f;
}

static const Unk_Chromaticity Unk_WhitePointA = Unk_Float2{0.44757f, 0.40745f};
static const Unk_Chromaticity Unk_WhitePointB = Unk_Float2{0.34842f, 0.35161f};
static const Unk_Chromaticity Unk_WhitePointC = Unk_Float2{0.31006f, 0.31616f};
static const Unk_Chromaticity Unk_WhitePointD50 = Unk_Float2{0.34567f, 0.35850f};
static const Unk_Chromaticity Unk_WhitePointD55 = Unk_Float2{0.33242f, 0.34743f};
static const Unk_Chromaticity Unk_WhitePointD60 = Unk_Float2{0.32168f, 0.33767f};
static const Unk_Chromaticity Unk_WhitePointD65 = Unk_Float2{0.31270f, 0.32900f};
static const Unk_Chromaticity Unk_WhitePointD70 = Unk_Float2{0.30540f, 0.32160f};
static const Unk_Chromaticity Unk_WhitePointD75 = Unk_Float2{0.29902f, 0.31485f};
static const Unk_Chromaticity Unk_WhitePointD93 = Unk_Float2{0.28300f, 0.29800f};
static const Unk_Chromaticity Unk_WhitePointE = Unk_Float2{1.0f / 3.0f, 1.0f / 3.0f};
static const Unk_Chromaticity Unk_WhitePointF1 = Unk_Float2{0.31310f, 0.33727f};
static const Unk_Chromaticity Unk_WhitePointF2 = Unk_Float2{0.37208f, 0.37529f};
static const Unk_Chromaticity Unk_WhitePointF3 = Unk_Float2{0.40910f, 0.39430f};
static const Unk_Chromaticity Unk_WhitePointF4 = Unk_Float2{0.44018f, 0.40329f};
static const Unk_Chromaticity Unk_WhitePointF5 = Unk_Float2{0.31379f, 0.34531f};
static const Unk_Chromaticity Unk_WhitePointF6 = Unk_Float2{0.37790f, 0.38835f};
static const Unk_Chromaticity Unk_WhitePointF7 = Unk_Float2{0.31292f, 0.32933f};
static const Unk_Chromaticity Unk_WhitePointF8 = Unk_Float2{0.34588f, 0.35875f};
static const Unk_Chromaticity Unk_WhitePointF9 = Unk_Float2{0.37417f, 0.37281f};
static const Unk_Chromaticity Unk_WhitePointF10 = Unk_Float2{0.34609f, 0.35986f};
static const Unk_Chromaticity Unk_WhitePointF11 = Unk_Float2{0.38052f, 0.37713f};
static const Unk_Chromaticity Unk_WhitePointF12 = Unk_Float2{0.43695f, 0.40441f};
static const Unk_Chromaticity Unk_WhitePointDCI = Unk_Float2{0.31400f, 0.35100f};
static const f32 Unk_Angle30 = Unk_DegToRad(30.0f);

}  // namespace PPFX
