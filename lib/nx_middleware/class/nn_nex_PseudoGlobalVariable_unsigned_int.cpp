// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex20PseudoGlobalVariableIjEE
#include <types.h>

struct Unk_162e190 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_162e190, field_8, 0x8);

struct Unk_162e1a0 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_162e1a0, field_8, 0x8);

namespace nn { namespace nex { template <class T0> class PseudoGlobalVariable; } }

namespace nn {
namespace nex {
template <> class PseudoGlobalVariable<unsigned int> {
public:
    u64 vf5();
    void vf6(u64 value);
};
}  // namespace nex
}  // namespace nn

// 0x710162e190
u64 nn::nex::PseudoGlobalVariable<unsigned int>::vf5() {
    const Unk_162e190* self = reinterpret_cast<const Unk_162e190*>(this);
    return self->field_8;
}

// 0x710162e1a0
void nn::nex::PseudoGlobalVariable<unsigned int>::vf6(u64 value) {
    Unk_162e1a0* self = reinterpret_cast<Unk_162e1a0*>(this);
    self->field_8 = value;
}
