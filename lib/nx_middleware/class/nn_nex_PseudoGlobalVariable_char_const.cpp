// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex20PseudoGlobalVariableIPKcEE
#include <types.h>

struct Unk_1612d60 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1612d60, field_8, 0x8);

struct Unk_1612d70 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1612d70, field_8, 0x8);

namespace nn { namespace nex { template <class T0> class PseudoGlobalVariable; } }

namespace nn {
namespace nex {
template <> class PseudoGlobalVariable<char const*> {
public:
    u64 vf5();
    void vf6(u64 value);
};
}  // namespace nex
}  // namespace nn

// 0x7101612d60
u64 nn::nex::PseudoGlobalVariable<char const*>::vf5() {
    const Unk_1612d60* self = reinterpret_cast<const Unk_1612d60*>(this);
    return self->field_8;
}

// 0x7101612d70
void nn::nex::PseudoGlobalVariable<char const*>::vf6(u64 value) {
    Unk_1612d70* self = reinterpret_cast<Unk_1612d70*>(this);
    self->field_8 = value;
}
