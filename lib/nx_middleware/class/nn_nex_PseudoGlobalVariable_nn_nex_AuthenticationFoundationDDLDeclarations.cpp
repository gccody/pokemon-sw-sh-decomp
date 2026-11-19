// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex20PseudoGlobalVariableINS0_39AuthenticationFoundationDDLDeclarationsEEE
#include <types.h>

struct Unk_1639140 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1639140, field_8, 0x8);

struct Unk_1639150 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1639150, field_8, 0x8);

namespace nn { namespace nex { class AuthenticationFoundationDDLDeclarations; } }
namespace nn { namespace nex { template <class T0> class PseudoGlobalVariable; } }

namespace nn {
namespace nex {
template <> class PseudoGlobalVariable<nn::nex::AuthenticationFoundationDDLDeclarations> {
public:
    u64 vf5();
    void vf6(u64 value);
};
}  // namespace nex
}  // namespace nn

// 0x7101639140
u64 nn::nex::PseudoGlobalVariable<nn::nex::AuthenticationFoundationDDLDeclarations>::vf5() {
    const Unk_1639140* self = reinterpret_cast<const Unk_1639140*>(this);
    return self->field_8;
}

// 0x7101639150
void nn::nex::PseudoGlobalVariable<nn::nex::AuthenticationFoundationDDLDeclarations>::vf6(u64 value) {
    Unk_1639150* self = reinterpret_cast<Unk_1639150*>(this);
    self->field_8 = value;
}
