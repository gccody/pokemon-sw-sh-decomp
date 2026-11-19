// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_583cf0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_583cf0, field_10, 0x10);

namespace SiSDK3 {
class SiIOVFSManager {
public:
    u32 vf4();
};
}  // namespace SiSDK3

// 0x7100583cf0
u32 SiSDK3::SiIOVFSManager::vf4() {
    const Unk_583cf0* self = reinterpret_cast<const Unk_583cf0*>(this);
    return self->field_10;
}
