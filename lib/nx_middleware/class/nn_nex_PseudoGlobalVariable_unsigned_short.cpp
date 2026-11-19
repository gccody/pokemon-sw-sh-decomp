// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex20PseudoGlobalVariableItEE
#include <types.h>

struct Unk_1612f20 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1612f20, field_8, 0x8);

struct Unk_1612f30 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1612f30, field_8, 0x8);

namespace nn { namespace nex { template <class T0> class PseudoGlobalVariable; } }

namespace nn {
namespace nex {
template <> class PseudoGlobalVariable<unsigned short> {
public:
    u64 vf5();
    void vf6(u64 value);
};
}  // namespace nex
}  // namespace nn

// 0x7101612f20
u64 nn::nex::PseudoGlobalVariable<unsigned short>::vf5() {
    const Unk_1612f20* self = reinterpret_cast<const Unk_1612f20*>(this);
    return self->field_8;
}

// 0x7101612f30
void nn::nex::PseudoGlobalVariable<unsigned short>::vf6(u64 value) {
    Unk_1612f30* self = reinterpret_cast<Unk_1612f30*>(this);
    self->field_8 = value;
}
