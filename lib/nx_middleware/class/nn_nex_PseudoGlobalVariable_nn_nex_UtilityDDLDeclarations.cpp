// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex20PseudoGlobalVariableINS0_22UtilityDDLDeclarationsEEE
#include <types.h>

struct Unk_1651310 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1651310, field_8, 0x8);

struct Unk_1651320 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1651320, field_8, 0x8);

namespace nn { namespace nex { class UtilityDDLDeclarations; } }
namespace nn { namespace nex { template <class T0> class PseudoGlobalVariable; } }

namespace nn {
namespace nex {
template <> class PseudoGlobalVariable<nn::nex::UtilityDDLDeclarations> {
public:
    u64 vf5();
    void vf6(u64 value);
};
}  // namespace nex
}  // namespace nn

// 0x7101651310
u64 nn::nex::PseudoGlobalVariable<nn::nex::UtilityDDLDeclarations>::vf5() {
    const Unk_1651310* self = reinterpret_cast<const Unk_1651310*>(this);
    return self->field_8;
}

// 0x7101651320
void nn::nex::PseudoGlobalVariable<nn::nex::UtilityDDLDeclarations>::vf6(u64 value) {
    Unk_1651320* self = reinterpret_cast<Unk_1651320*>(this);
    self->field_8 = value;
}
