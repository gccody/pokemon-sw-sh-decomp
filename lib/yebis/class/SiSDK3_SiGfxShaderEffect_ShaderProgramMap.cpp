// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK317SiGfxShaderEffect16ShaderProgramMapE
#include <types.h>

struct Unk_56dbf0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_56dbf0, field_10, 0x10);

namespace SiSDK3 {
namespace SiGfxShaderEffect {
class ShaderProgramMap {
public:
    u32 vf4();
};
}  // namespace SiGfxShaderEffect
}  // namespace SiSDK3

// 0x710056dbf0
u32 SiSDK3::SiGfxShaderEffect::ShaderProgramMap::vf4() {
    const Unk_56dbf0* self = reinterpret_cast<const Unk_56dbf0*>(this);
    return self->field_10;
}
