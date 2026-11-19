// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia3lan17LanSessionMessageE
#include <types.h>

struct Unk_16759d0 {
    u8 _0[0x340];
    u32 field_340;
};
PKMN_OFFSET_ASSERT(Unk_16759d0, field_340, 0x340);

namespace nn {
namespace pia {
namespace lan {
class LanSessionMessage {
public:
    u32 vf4();
};
}  // namespace lan
}  // namespace pia
}  // namespace nn

// 0x71016759d0
u32 nn::pia::lan::LanSessionMessage::vf4() {
    const Unk_16759d0* self = reinterpret_cast<const Unk_16759d0*>(this);
    return self->field_340 + 0x18;
}
