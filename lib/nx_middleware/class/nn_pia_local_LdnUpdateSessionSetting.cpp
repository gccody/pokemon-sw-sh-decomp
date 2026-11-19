// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia5local23LdnUpdateSessionSettingE
#include <types.h>

struct Unk_169af20 {
    u8 _0[0xc];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_169af20, field_c, 0xc);

struct Unk_1686f90 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1686f90, field_10, 0x10);

namespace nn {
namespace pia {
namespace local {
class LdnUpdateSessionSetting {
public:
    u32 vf4();
    const u8* vf10();
    u32 vf11();
};
}  // namespace local
}  // namespace pia
}  // namespace nn

// 0x7101686f90
const u8* nn::pia::local::LdnUpdateSessionSetting::vf10() {
    const Unk_1686f90* self = reinterpret_cast<const Unk_1686f90*>(this);
    return &self->field_10;
}

// 0x7101686fa0
u32 nn::pia::local::LdnUpdateSessionSetting::vf11() {
    return 0x168;
}

// 0x710169af20
u32 nn::pia::local::LdnUpdateSessionSetting::vf4() {
    const Unk_169af20* self = reinterpret_cast<const Unk_169af20*>(this);
    return self->field_c;
}
