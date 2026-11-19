// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_167c190 {
    u8 _0[0x55];
    u8 field_55;
};
PKMN_OFFSET_ASSERT(Unk_167c190, field_55, 0x55);

struct Unk_167c1a0 {
    u8 _0[0x1d8];
    u32 field_1d8;
};
PKMN_OFFSET_ASSERT(Unk_167c1a0, field_1d8, 0x1d8);

namespace nn {
namespace pia {
namespace local {
class LdnCreateNetworkSetting {
public:
    const u8* vf2();
    u32 vf3();
};
}  // namespace local
}  // namespace pia
}  // namespace nn

// 0x710167c190
const u8* nn::pia::local::LdnCreateNetworkSetting::vf2() {
    const Unk_167c190* self = reinterpret_cast<const Unk_167c190*>(this);
    return &self->field_55;
}

// 0x710167c1a0
u32 nn::pia::local::LdnCreateNetworkSetting::vf3() {
    const Unk_167c1a0* self = reinterpret_cast<const Unk_167c1a0*>(this);
    return self->field_1d8;
}
