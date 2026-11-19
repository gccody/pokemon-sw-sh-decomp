// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex22SingleThreadCallPolicyE
#include <types.h>

struct Unk_15d4750 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_15d4750, field_8, 0x8);

namespace nn {
namespace nex {
class SingleThreadCallPolicy {
public:
    u32 vf2();
};
}  // namespace nex
}  // namespace nn

// 0x71015d4750
u32 nn::nex::SingleThreadCallPolicy::vf2() {
    const Unk_15d4750* self = reinterpret_cast<const Unk_15d4750*>(this);
    return self->field_8;
}
