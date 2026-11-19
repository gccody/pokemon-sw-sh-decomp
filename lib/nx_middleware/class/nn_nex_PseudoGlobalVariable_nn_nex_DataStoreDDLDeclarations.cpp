// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex20PseudoGlobalVariableINS0_24DataStoreDDLDeclarationsEEE
#include <types.h>

struct Unk_1599790 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1599790, field_8, 0x8);

struct Unk_15997a0 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_15997a0, field_8, 0x8);

namespace nn { namespace nex { class DataStoreDDLDeclarations; } }
namespace nn { namespace nex { template <class T0> class PseudoGlobalVariable; } }

namespace nn {
namespace nex {
template <> class PseudoGlobalVariable<nn::nex::DataStoreDDLDeclarations> {
public:
    u64 vf5();
    void vf6(u64 value);
};
}  // namespace nex
}  // namespace nn

// 0x7101599790
u64 nn::nex::PseudoGlobalVariable<nn::nex::DataStoreDDLDeclarations>::vf5() {
    const Unk_1599790* self = reinterpret_cast<const Unk_1599790*>(this);
    return self->field_8;
}

// 0x71015997a0
void nn::nex::PseudoGlobalVariable<nn::nex::DataStoreDDLDeclarations>::vf6(u64 value) {
    Unk_15997a0* self = reinterpret_cast<Unk_15997a0*>(this);
    self->field_8 = value;
}
