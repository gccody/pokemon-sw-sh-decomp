// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex20PseudoGlobalVariableINS0_27SubscriptionDDLDeclarationsEEE
#include <types.h>

struct Unk_1650100 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1650100, field_8, 0x8);

struct Unk_1650110 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1650110, field_8, 0x8);

namespace nn { namespace nex { class SubscriptionDDLDeclarations; } }
namespace nn { namespace nex { template <class T0> class PseudoGlobalVariable; } }

namespace nn {
namespace nex {
template <> class PseudoGlobalVariable<nn::nex::SubscriptionDDLDeclarations> {
public:
    u64 vf5();
    void vf6(u64 value);
};
}  // namespace nex
}  // namespace nn

// 0x7101650100
u64 nn::nex::PseudoGlobalVariable<nn::nex::SubscriptionDDLDeclarations>::vf5() {
    const Unk_1650100* self = reinterpret_cast<const Unk_1650100*>(this);
    return self->field_8;
}

// 0x7101650110
void nn::nex::PseudoGlobalVariable<nn::nex::SubscriptionDDLDeclarations>::vf6(u64 value) {
    Unk_1650110* self = reinterpret_cast<Unk_1650110*>(this);
    self->field_8 = value;
}
