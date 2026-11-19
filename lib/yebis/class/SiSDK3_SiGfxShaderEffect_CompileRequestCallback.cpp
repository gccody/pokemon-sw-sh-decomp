// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_5793d0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_5793d0, field_10, 0x10);

namespace SiSDK3 {
namespace SiGfxShaderEffect {
class CompileRequestCallback {
public:
    u32 vf4();
};
}  // namespace SiGfxShaderEffect
}  // namespace SiSDK3

// 0x71005793d0
u32 SiSDK3::SiGfxShaderEffect::CompileRequestCallback::vf4() {
    const Unk_5793d0* self = reinterpret_cast<const Unk_5793d0*>(this);
    return self->field_10;
}
