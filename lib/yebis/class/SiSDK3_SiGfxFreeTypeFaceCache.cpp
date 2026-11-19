// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK322SiGfxFreeTypeFaceCacheE
#include <types.h>

struct Unk_531a80 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_531a80, field_10, 0x10);

namespace SiSDK3 {
class SiGfxFreeTypeFaceCache {
public:
    u32 vf4();
};
}  // namespace SiSDK3

// 0x7100531a80
u32 SiSDK3::SiGfxFreeTypeFaceCache::vf4() {
    const Unk_531a80* self = reinterpret_cast<const Unk_531a80*>(this);
    return self->field_10;
}
