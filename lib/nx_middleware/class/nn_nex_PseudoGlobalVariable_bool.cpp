// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex20PseudoGlobalVariableIbEE
#include <types.h>

struct Unk_1612690 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1612690, field_8, 0x8);

struct Unk_16126a0 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_16126a0, field_8, 0x8);

namespace nn { namespace nex { template <class T0> class PseudoGlobalVariable; } }

namespace nn {
namespace nex {
template <> class PseudoGlobalVariable<bool> {
public:
    u64 vf5();
    void vf6(u64 value);
};
}  // namespace nex
}  // namespace nn

// 0x7101612690
u64 nn::nex::PseudoGlobalVariable<bool>::vf5() {
    const Unk_1612690* self = reinterpret_cast<const Unk_1612690*>(this);
    return self->field_8;
}

// 0x71016126a0
void nn::nex::PseudoGlobalVariable<bool>::vf6(u64 value) {
    Unk_16126a0* self = reinterpret_cast<Unk_16126a0*>(this);
    self->field_8 = value;
}
