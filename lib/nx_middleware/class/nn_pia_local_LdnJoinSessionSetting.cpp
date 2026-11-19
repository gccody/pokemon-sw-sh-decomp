// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_167c380 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_167c380, field_58, 0x58);

namespace nn {
namespace pia {
namespace local {
class LdnJoinSessionSetting {
public:
    void vf3();
    const u8* vf9();
};
}  // namespace local
}  // namespace pia
}  // namespace nn

// 0x710167c380
const u8* nn::pia::local::LdnJoinSessionSetting::vf9() {
    const Unk_167c380* self = reinterpret_cast<const Unk_167c380*>(this);
    return &self->field_58;
}

// 0x710168bf20
void nn::pia::local::LdnJoinSessionSetting::vf3() {
}
