// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_15d47c0 {
    u8 _0[0x50];
    u32 field_50;
};
PKMN_OFFSET_ASSERT(Unk_15d47c0, field_50, 0x50);

namespace nn {
namespace nex {
class ThreadSafeCallPolicy {
public:
    u32 vf2();
};
}  // namespace nex
}  // namespace nn

// 0x71015d47c0
u32 nn::nex::ThreadSafeCallPolicy::vf2() {
    const Unk_15d47c0* self = reinterpret_cast<const Unk_15d47c0*>(this);
    return self->field_50;
}
