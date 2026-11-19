// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_4db400 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_4db400, field_10, 0x10);

struct Unk_4dad50 {
    u8 _0[0x28];
    u32 field_28;
};
PKMN_OFFSET_ASSERT(Unk_4dad50, field_28, 0x28);

namespace SiSDK3 {
class SiGfxShaderGraphUtility {
public:
    u32 vf4();
    u32 vf9();
};
}  // namespace SiSDK3

// 0x71004dad50
u32 SiSDK3::SiGfxShaderGraphUtility::vf9() {
    const Unk_4dad50* self = reinterpret_cast<const Unk_4dad50*>(this);
    return self->field_28;
}

// 0x71004db400
u32 SiSDK3::SiGfxShaderGraphUtility::vf4() {
    const Unk_4db400* self = reinterpret_cast<const Unk_4db400*>(this);
    return self->field_10;
}
