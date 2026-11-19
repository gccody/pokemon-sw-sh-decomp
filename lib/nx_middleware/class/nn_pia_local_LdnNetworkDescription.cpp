// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_167e8f0 {
    u8 _0[0x50];
    u16 field_50;
};
PKMN_OFFSET_ASSERT(Unk_167e8f0, field_50, 0x50);

namespace nn {
namespace pia {
namespace local {
class LdnNetworkDescription {
public:
    u16 vf3();
    void vf6();
};
}  // namespace local
}  // namespace pia
}  // namespace nn

// 0x710167e8f0
u16 nn::pia::local::LdnNetworkDescription::vf3() {
    const Unk_167e8f0* self = reinterpret_cast<const Unk_167e8f0*>(this);
    return self->field_50;
}

// 0x710167e970
void nn::pia::local::LdnNetworkDescription::vf6() {
}
