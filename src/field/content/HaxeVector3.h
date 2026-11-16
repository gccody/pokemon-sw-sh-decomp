#pragma once
// field::content::HaxeVector3, bound to Lua as fromcpp.Vector3. Class and namespace come
// from sol2's type-name strings (ctti_get_type_name), the members and their signatures
// from the bound member-pointer types in the same strings, the names from the Lua keys
// they are bound under. The methods are defined at 0x7100ded9e0-0x7100dedc60.
#include <types.h>

namespace field {
namespace content {

struct HaxeVector3 {
    // 0x7100ded9e0 (stores the three floats; PokemonObject's Vector3 getters call it).
    // Not default-constructible, see HaxeVector2.
    HaxeVector3(float x, float y, float z);

    float X;
    float Y;
    float Z;

    static HaxeVector3 Create(float, float, float);
    static HaxeVector3 CreateAdd(HaxeVector3, HaxeVector3);
    static HaxeVector3 CreateSub(HaxeVector3, HaxeVector3);
    static float Dot(HaxeVector3, HaxeVector3);
    static HaxeVector3 Cross(HaxeVector3, HaxeVector3);
    void Add(HaxeVector3);
    void Sub(HaxeVector3);
    void Mul(float);
    void Normalize();
    float Length() const;
    float LengthSq() const;
    HaxeVector3 Clone() const;
};
PKMN_OFFSET_ASSERT(HaxeVector3, Y, 0x4);
PKMN_OFFSET_ASSERT(HaxeVector3, Z, 0x8);
PKMN_SIZE_ASSERT(HaxeVector3, 0xc);

}  // namespace content
}  // namespace field
