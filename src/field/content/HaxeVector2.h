#pragma once
// field::content::HaxeVector2, bound to Lua as fromcpp.Vector2. Class and namespace come
// from sol2's type-name strings (ctti_get_type_name), the members and their signatures
// from the bound member-pointer types in the same strings, the names from the Lua keys
// they are bound under. The methods are defined at 0x7100e366b0-0x7100e36820.
#include <types.h>

namespace field {
namespace content {

struct HaxeVector2 {
    // Not default-constructible: sol2 gives a default-constructible usertype a
    // constructor ("new"), and the binary has none for Vector2 or Vector3.
    HaxeVector2(float x, float y) : X(x), Y(y) {}

    float X;
    float Y;

    static HaxeVector2 Create(float, float);
    static HaxeVector2 CreateAdd(HaxeVector2, HaxeVector2);
    static HaxeVector2 CreateSub(HaxeVector2, HaxeVector2);
    static float Dot(HaxeVector2, HaxeVector2);
    static float Cross(HaxeVector2, HaxeVector2);
    void Add(HaxeVector2);
    void Sub(HaxeVector2);
    void Mul(float);
    void Normalize();
    float Length() const;
    float LengthSq() const;
    HaxeVector2 Clone() const;
};
PKMN_OFFSET_ASSERT(HaxeVector2, Y, 0x4);
PKMN_SIZE_ASSERT(HaxeVector2, 0x8);

}  // namespace content
}  // namespace field
