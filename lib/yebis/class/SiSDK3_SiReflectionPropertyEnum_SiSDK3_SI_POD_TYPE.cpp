// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK324SiReflectionPropertyEnumINS_11SI_POD_TYPEEEE
#include <types.h>

struct Unk_4cfe20 {
    u8 _0[0xb0];
    u8 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_4cfe20, field_b0, 0xb0);

namespace SiSDK3 { class SI_POD_TYPE; }
namespace SiSDK3 { template <class T0> class SiReflectionPropertyEnum; }

namespace SiSDK3 {
template <> class SiReflectionPropertyEnum<SiSDK3::SI_POD_TYPE> {
public:
    const u8* vf2();
};
}  // namespace SiSDK3

// 0x71004cfe20
const u8* SiSDK3::SiReflectionPropertyEnum<SiSDK3::SI_POD_TYPE>::vf2() {
    const Unk_4cfe20* self = reinterpret_cast<const Unk_4cfe20*>(this);
    return &self->field_b0;
}
