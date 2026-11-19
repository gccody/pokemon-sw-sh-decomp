// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex20PseudoGlobalVariableINS0_25OnlineCoreDDLDeclarationsEEE
#include <types.h>

struct Unk_162dae0 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_162dae0, field_8, 0x8);

struct Unk_162daf0 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_162daf0, field_8, 0x8);

namespace nn { namespace nex { class OnlineCoreDDLDeclarations; } }
namespace nn { namespace nex { template <class T0> class PseudoGlobalVariable; } }

namespace nn {
namespace nex {
template <> class PseudoGlobalVariable<nn::nex::OnlineCoreDDLDeclarations> {
public:
    u64 vf5();
    void vf6(u64 value);
};
}  // namespace nex
}  // namespace nn

// 0x710162dae0
u64 nn::nex::PseudoGlobalVariable<nn::nex::OnlineCoreDDLDeclarations>::vf5() {
    const Unk_162dae0* self = reinterpret_cast<const Unk_162dae0*>(this);
    return self->field_8;
}

// 0x710162daf0
void nn::nex::PseudoGlobalVariable<nn::nex::OnlineCoreDDLDeclarations>::vf6(u64 value) {
    Unk_162daf0* self = reinterpret_cast<Unk_162daf0*>(this);
    self->field_8 = value;
}
