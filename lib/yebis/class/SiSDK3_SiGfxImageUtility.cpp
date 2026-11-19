// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_4d2710 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_4d2710, field_10, 0x10);

struct Unk_4d13e0 {
    u8 _0[0x28];
    u32 field_28;
};
PKMN_OFFSET_ASSERT(Unk_4d13e0, field_28, 0x28);

struct Unk_4d1650 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_4d1650, field_78, 0x78);

namespace SiSDK3 {
class SiGfxImageUtility {
public:
    u32 vf4();
    u32 vf8();
    u32 vf13();
};
}  // namespace SiSDK3

// 0x71004d13e0
u32 SiSDK3::SiGfxImageUtility::vf8() {
    const Unk_4d13e0* self = reinterpret_cast<const Unk_4d13e0*>(this);
    return self->field_28;
}

// 0x71004d1650
u32 SiSDK3::SiGfxImageUtility::vf13() {
    const Unk_4d1650* self = reinterpret_cast<const Unk_4d1650*>(this);
    return self->field_78;
}

// 0x71004d2710
u32 SiSDK3::SiGfxImageUtility::vf4() {
    const Unk_4d2710* self = reinterpret_cast<const Unk_4d2710*>(this);
    return self->field_10;
}
