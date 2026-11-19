// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia5local24LdnSessionSearchCriteriaE
#include <types.h>

struct Unk_1686cf0 {
    u8 _0[0x20];
    u8 field_20;
};
PKMN_OFFSET_ASSERT(Unk_1686cf0, field_20, 0x20);

namespace nn {
namespace pia {
namespace local {
class LdnSessionSearchCriteria {
public:
    void vf4();
    const u8* vf5();
};
}  // namespace local
}  // namespace pia
}  // namespace nn

// 0x7101686ce0
void nn::pia::local::LdnSessionSearchCriteria::vf4() {
}

// 0x7101686cf0
const u8* nn::pia::local::LdnSessionSearchCriteria::vf5() {
    const Unk_1686cf0* self = reinterpret_cast<const Unk_1686cf0*>(this);
    return &self->field_20;
}
