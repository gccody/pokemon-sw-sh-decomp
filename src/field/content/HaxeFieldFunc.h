#pragma once
// field::content::HaxeFieldFunc, bound to Lua as fromcpp.Field: static functions only.
// Class and namespace come from sol2's type-name strings (ctti_get_type_name), the
// signatures from the bound function types in the same strings, the names from the Lua
// keys they are bound under. Defined at 0x7100e36820-0x7100e36ec0.
#include "field/content/HaxeVector3.h"

namespace field {
namespace content {

class HaxeFieldFunc {
public:
    static HaxeVector3 GetPlayerPos();
    static HaxeVector3 GetPlayerRot();
    static bool IsPlayerFingerWhistle();
    static bool IsPlayerSquat();
    static bool IsPlayerRegionIn(const char*);
    static int GetWeather();
    static int GetRandomInt(int);
    static float GetRandomFloat(float);
    static bool IsPlayerRideBicycle();
    static bool IsPlayerRideBicycleType(int);
    static bool IsPlayerRideAndFingerWhistle();
};

}  // namespace content
}  // namespace field
