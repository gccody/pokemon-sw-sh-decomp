// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK319SiGfxFontDrawHelperE
#include <types.h>

struct Unk_545f80 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_545f80, field_10, 0x10);

namespace SiSDK3 {
class SiGfxFontDrawHelper {
public:
    u32 vf4();
};
}  // namespace SiSDK3

// 0x7100545f80
u32 SiSDK3::SiGfxFontDrawHelper::vf4() {
    const Unk_545f80* self = reinterpret_cast<const Unk_545f80*>(this);
    return self->field_10;
}
