// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK318SiGfxNXShaderInputE
#include <types.h>

struct Unk_55ad50 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_55ad50, field_10, 0x10);

struct Unk_55ac70 {
    u8 _0[0x20];
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_55ac70, field_20, 0x20);

struct Unk_55ac80 {
    u8 _0[0x24];
    u8 field_24;
};
PKMN_OFFSET_ASSERT(Unk_55ac80, field_24, 0x24);

namespace SiSDK3 {
class SiGfxNXShaderInput {
public:
    u32 vf4();
    u32 vf5();
    const u8* vf6();
};
}  // namespace SiSDK3

// 0x710055ac70
u32 SiSDK3::SiGfxNXShaderInput::vf5() {
    const Unk_55ac70* self = reinterpret_cast<const Unk_55ac70*>(this);
    return self->field_20;
}

// 0x710055ac80
const u8* SiSDK3::SiGfxNXShaderInput::vf6() {
    const Unk_55ac80* self = reinterpret_cast<const Unk_55ac80*>(this);
    return &self->field_24;
}

// 0x710055ad50
u32 SiSDK3::SiGfxNXShaderInput::vf4() {
    const Unk_55ad50* self = reinterpret_cast<const Unk_55ad50*>(this);
    return self->field_10;
}
