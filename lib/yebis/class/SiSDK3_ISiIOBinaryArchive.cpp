// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_57c750 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_57c750, field_10, 0x10);

namespace SiSDK3 {
class ISiIOBinaryArchive {
public:
    u32 vf4();
};
}  // namespace SiSDK3

// 0x710057c750
u32 SiSDK3::ISiIOBinaryArchive::vf4() {
    const Unk_57c750* self = reinterpret_cast<const Unk_57c750*>(this);
    return self->field_10;
}
