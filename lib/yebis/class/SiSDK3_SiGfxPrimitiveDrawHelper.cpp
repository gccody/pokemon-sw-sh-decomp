// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK324SiGfxPrimitiveDrawHelperE
#include <types.h>

struct Unk_54d3a0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_54d3a0, field_10, 0x10);

namespace SiSDK3 {
class SiGfxPrimitiveDrawHelper {
public:
    u32 vf4();
};
}  // namespace SiSDK3

// 0x710054d3a0
u32 SiSDK3::SiGfxPrimitiveDrawHelper::vf4() {
    const Unk_54d3a0* self = reinterpret_cast<const Unk_54d3a0*>(this);
    return self->field_10;
}
