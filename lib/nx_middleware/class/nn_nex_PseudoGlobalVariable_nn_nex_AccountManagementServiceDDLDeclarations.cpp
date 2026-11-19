// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex20PseudoGlobalVariableINS0_39AccountManagementServiceDDLDeclarationsEEE
#include <types.h>

struct Unk_164bf90 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_164bf90, field_8, 0x8);

struct Unk_164bfa0 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_164bfa0, field_8, 0x8);

namespace nn { namespace nex { class AccountManagementServiceDDLDeclarations; } }
namespace nn { namespace nex { template <class T0> class PseudoGlobalVariable; } }

namespace nn {
namespace nex {
template <> class PseudoGlobalVariable<nn::nex::AccountManagementServiceDDLDeclarations> {
public:
    u64 vf5();
    void vf6(u64 value);
};
}  // namespace nex
}  // namespace nn

// 0x710164bf90
u64 nn::nex::PseudoGlobalVariable<nn::nex::AccountManagementServiceDDLDeclarations>::vf5() {
    const Unk_164bf90* self = reinterpret_cast<const Unk_164bf90*>(this);
    return self->field_8;
}

// 0x710164bfa0
void nn::nex::PseudoGlobalVariable<nn::nex::AccountManagementServiceDDLDeclarations>::vf6(u64 value) {
    Unk_164bfa0* self = reinterpret_cast<Unk_164bfa0*>(this);
    self->field_8 = value;
}
