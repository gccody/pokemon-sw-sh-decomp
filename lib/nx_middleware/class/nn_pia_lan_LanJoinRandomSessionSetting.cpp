// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia3lan27LanJoinRandomSessionSettingE
#include <types.h>

struct Unk_1662650 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1662650, field_8, 0x8);

struct Unk_1662680 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1662680, field_8, 0x8);

struct Unk_16626c0 {
    u8 _0[0x698];
    u32 field_698;
};
PKMN_OFFSET_ASSERT(Unk_16626c0, field_698, 0x698);

namespace nn {
namespace pia {
namespace lan {
class LanJoinRandomSessionSetting {
public:
    void vf5();
    const u8* vf6();
    const u8* vf8();
    u32 vf10();
};
}  // namespace lan
}  // namespace pia
}  // namespace nn

// 0x7101662650
const u8* nn::pia::lan::LanJoinRandomSessionSetting::vf6() {
    const Unk_1662650* self = reinterpret_cast<const Unk_1662650*>(this);
    return &self->field_8;
}

// 0x7101662680
const u8* nn::pia::lan::LanJoinRandomSessionSetting::vf8() {
    const Unk_1662680* self = reinterpret_cast<const Unk_1662680*>(this);
    return &self->field_8;
}

// 0x71016626b0
void nn::pia::lan::LanJoinRandomSessionSetting::vf5() {
}

// 0x71016626c0
u32 nn::pia::lan::LanJoinRandomSessionSetting::vf10() {
    const Unk_16626c0* self = reinterpret_cast<const Unk_16626c0*>(this);
    return self->field_698;
}
