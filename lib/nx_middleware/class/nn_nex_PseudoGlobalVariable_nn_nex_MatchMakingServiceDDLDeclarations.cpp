// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex20PseudoGlobalVariableINS0_33MatchMakingServiceDDLDeclarationsEEE
#include <types.h>

struct Unk_15b48d0 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_15b48d0, field_8, 0x8);

struct Unk_15b48e0 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_15b48e0, field_8, 0x8);

namespace nn { namespace nex { class MatchMakingServiceDDLDeclarations; } }
namespace nn { namespace nex { template <class T0> class PseudoGlobalVariable; } }

namespace nn {
namespace nex {
template <> class PseudoGlobalVariable<nn::nex::MatchMakingServiceDDLDeclarations> {
public:
    u64 vf5();
    void vf6(u64 value);
};
}  // namespace nex
}  // namespace nn

// 0x71015b48d0
u64 nn::nex::PseudoGlobalVariable<nn::nex::MatchMakingServiceDDLDeclarations>::vf5() {
    const Unk_15b48d0* self = reinterpret_cast<const Unk_15b48d0*>(this);
    return self->field_8;
}

// 0x71015b48e0
void nn::nex::PseudoGlobalVariable<nn::nex::MatchMakingServiceDDLDeclarations>::vf6(u64 value) {
    Unk_15b48e0* self = reinterpret_cast<Unk_15b48e0*>(this);
    self->field_8 = value;
}
