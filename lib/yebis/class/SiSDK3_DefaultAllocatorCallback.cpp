// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_4c9fc0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_4c9fc0, field_10, 0x10);

namespace SiSDK3 {
class DefaultAllocatorCallback {
public:
    u32 vf4();
    void vf5();
};
}  // namespace SiSDK3

// 0x71004c9fc0
u32 SiSDK3::DefaultAllocatorCallback::vf4() {
    const Unk_4c9fc0* self = reinterpret_cast<const Unk_4c9fc0*>(this);
    return self->field_10;
}

// 0x71004c9fd0
void SiSDK3::DefaultAllocatorCallback::vf5() {
}
