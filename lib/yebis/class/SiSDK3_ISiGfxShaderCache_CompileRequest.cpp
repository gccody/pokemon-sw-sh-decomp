// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_579970 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_579970, field_10, 0x10);

namespace SiSDK3 {
namespace ISiGfxShaderCache {
class CompileRequest {
public:
    u32 vf4();
};
}  // namespace ISiGfxShaderCache
}  // namespace SiSDK3

// 0x7100579970
u32 SiSDK3::ISiGfxShaderCache::CompileRequest::vf4() {
    const Unk_579970* self = reinterpret_cast<const Unk_579970*>(this);
    return self->field_10;
}
