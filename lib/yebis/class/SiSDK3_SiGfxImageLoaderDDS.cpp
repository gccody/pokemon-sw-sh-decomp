// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_4f6620 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_4f6620, field_10, 0x10);

namespace SiSDK3 {
class SiGfxImageLoaderDDS {
public:
    u32 vf4();
};
}  // namespace SiSDK3

// 0x71004f6620
u32 SiSDK3::SiGfxImageLoaderDDS::vf4() {
    const Unk_4f6620* self = reinterpret_cast<const Unk_4f6620*>(this);
    return self->field_10;
}
