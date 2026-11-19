// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_4d3010 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_4d3010, field_10, 0x10);

struct Unk_4d2f00 {
    u8 _0[0x28];
    u32 field_28;
};
PKMN_OFFSET_ASSERT(Unk_4d2f00, field_28, 0x28);

namespace SiSDK3 {
class SiGfxDisplayUtility {
public:
    u32 vf4();
    u32 vf5();
};
}  // namespace SiSDK3

// 0x71004d2f00
u32 SiSDK3::SiGfxDisplayUtility::vf5() {
    const Unk_4d2f00* self = reinterpret_cast<const Unk_4d2f00*>(this);
    return self->field_28;
}

// 0x71004d3010
u32 SiSDK3::SiGfxDisplayUtility::vf4() {
    const Unk_4d3010* self = reinterpret_cast<const Unk_4d3010*>(this);
    return self->field_10;
}
