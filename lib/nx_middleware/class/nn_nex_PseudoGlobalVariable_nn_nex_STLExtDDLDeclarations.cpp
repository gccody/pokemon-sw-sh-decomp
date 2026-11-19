// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex20PseudoGlobalVariableINS0_21STLExtDDLDeclarationsEEE
#include <types.h>

struct Unk_162ddd0 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_162ddd0, field_8, 0x8);

struct Unk_162dde0 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_162dde0, field_8, 0x8);

namespace nn { namespace nex { class STLExtDDLDeclarations; } }
namespace nn { namespace nex { template <class T0> class PseudoGlobalVariable; } }

namespace nn {
namespace nex {
template <> class PseudoGlobalVariable<nn::nex::STLExtDDLDeclarations> {
public:
    u64 vf5();
    void vf6(u64 value);
};
}  // namespace nex
}  // namespace nn

// 0x710162ddd0
u64 nn::nex::PseudoGlobalVariable<nn::nex::STLExtDDLDeclarations>::vf5() {
    const Unk_162ddd0* self = reinterpret_cast<const Unk_162ddd0*>(this);
    return self->field_8;
}

// 0x710162dde0
void nn::nex::PseudoGlobalVariable<nn::nex::STLExtDDLDeclarations>::vf6(u64 value) {
    Unk_162dde0* self = reinterpret_cast<Unk_162dde0*>(this);
    self->field_8 = value;
}
