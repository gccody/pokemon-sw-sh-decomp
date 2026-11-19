// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex20PseudoGlobalVariableI18SendMultiParameterEE
#include <types.h>

struct Unk_16228d0 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_16228d0, field_8, 0x8);

struct Unk_16228e0 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_16228e0, field_8, 0x8);

class SendMultiParameter;
namespace nn { namespace nex { template <class T0> class PseudoGlobalVariable; } }

namespace nn {
namespace nex {
template <> class PseudoGlobalVariable<SendMultiParameter> {
public:
    u64 vf5();
    void vf6(u64 value);
};
}  // namespace nex
}  // namespace nn

// 0x71016228d0
u64 nn::nex::PseudoGlobalVariable<SendMultiParameter>::vf5() {
    const Unk_16228d0* self = reinterpret_cast<const Unk_16228d0*>(this);
    return self->field_8;
}

// 0x71016228e0
void nn::nex::PseudoGlobalVariable<SendMultiParameter>::vf6(u64 value) {
    Unk_16228e0* self = reinterpret_cast<Unk_16228e0*>(this);
    self->field_8 = value;
}
