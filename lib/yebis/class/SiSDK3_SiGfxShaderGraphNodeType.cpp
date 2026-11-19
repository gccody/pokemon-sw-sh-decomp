// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_4dc440 {
    u8 _0[0x48];
    u8 field_48;
};
PKMN_OFFSET_ASSERT(Unk_4dc440, field_48, 0x48);

struct Unk_4dc450 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_4dc450, field_78, 0x78);

namespace SiSDK3 {
class SiGfxShaderGraphNodeType {
public:
    const u8* vf3();
    u32 vf4();
};
}  // namespace SiSDK3

// 0x71004dc440
const u8* SiSDK3::SiGfxShaderGraphNodeType::vf3() {
    const Unk_4dc440* self = reinterpret_cast<const Unk_4dc440*>(this);
    return &self->field_48;
}

// 0x71004dc450
u32 SiSDK3::SiGfxShaderGraphNodeType::vf4() {
    const Unk_4dc450* self = reinterpret_cast<const Unk_4dc450*>(this);
    return self->field_78;
}
