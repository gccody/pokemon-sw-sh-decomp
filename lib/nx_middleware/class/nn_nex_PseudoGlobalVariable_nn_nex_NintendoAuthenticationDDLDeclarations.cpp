// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex20PseudoGlobalVariableINS0_37NintendoAuthenticationDDLDeclarationsEEE
#include <types.h>

struct Unk_1571110 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1571110, field_8, 0x8);

struct Unk_1571120 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1571120, field_8, 0x8);

namespace nn { namespace nex { class NintendoAuthenticationDDLDeclarations; } }
namespace nn { namespace nex { template <class T0> class PseudoGlobalVariable; } }

namespace nn {
namespace nex {
template <> class PseudoGlobalVariable<nn::nex::NintendoAuthenticationDDLDeclarations> {
public:
    u64 vf5();
    void vf6(u64 value);
};
}  // namespace nex
}  // namespace nn

// 0x7101571110
u64 nn::nex::PseudoGlobalVariable<nn::nex::NintendoAuthenticationDDLDeclarations>::vf5() {
    const Unk_1571110* self = reinterpret_cast<const Unk_1571110*>(this);
    return self->field_8;
}

// 0x7101571120
void nn::nex::PseudoGlobalVariable<nn::nex::NintendoAuthenticationDDLDeclarations>::vf6(u64 value) {
    Unk_1571120* self = reinterpret_cast<Unk_1571120*>(this);
    self->field_8 = value;
}
