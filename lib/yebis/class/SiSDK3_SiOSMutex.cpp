// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_5966d0 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_5966d0, field_8, 0x8);

namespace SiSDK3 {
class SiOSMutex {
public:
    const u8* vf5();
};
}  // namespace SiSDK3

// 0x71005966d0
const u8* SiSDK3::SiOSMutex::vf5() {
    const Unk_5966d0* self = reinterpret_cast<const Unk_5966d0*>(this);
    return &self->field_8;
}
