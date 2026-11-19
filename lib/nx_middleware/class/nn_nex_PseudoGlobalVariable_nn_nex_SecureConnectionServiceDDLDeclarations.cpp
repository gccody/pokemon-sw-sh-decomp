// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex20PseudoGlobalVariableINS0_38SecureConnectionServiceDDLDeclarationsEEE
#include <types.h>

struct Unk_1639d00 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1639d00, field_8, 0x8);

struct Unk_1639d10 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1639d10, field_8, 0x8);

namespace nn { namespace nex { class SecureConnectionServiceDDLDeclarations; } }
namespace nn { namespace nex { template <class T0> class PseudoGlobalVariable; } }

namespace nn {
namespace nex {
template <> class PseudoGlobalVariable<nn::nex::SecureConnectionServiceDDLDeclarations> {
public:
    u64 vf5();
    void vf6(u64 value);
};
}  // namespace nex
}  // namespace nn

// 0x7101639d00
u64 nn::nex::PseudoGlobalVariable<nn::nex::SecureConnectionServiceDDLDeclarations>::vf5() {
    const Unk_1639d00* self = reinterpret_cast<const Unk_1639d00*>(this);
    return self->field_8;
}

// 0x7101639d10
void nn::nex::PseudoGlobalVariable<nn::nex::SecureConnectionServiceDDLDeclarations>::vf6(u64 value) {
    Unk_1639d10* self = reinterpret_cast<Unk_1639d10*>(this);
    self->field_8 = value;
}
