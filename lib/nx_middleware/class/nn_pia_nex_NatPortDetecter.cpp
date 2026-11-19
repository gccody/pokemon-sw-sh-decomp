// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia3nex15NatPortDetecterE
#include <types.h>

struct Unk_16ce300 {
    u8 _0[0x5c0];
    u32 field_5c0;
};
PKMN_OFFSET_ASSERT(Unk_16ce300, field_5c0, 0x5c0);

struct Unk_16ce310 {
    u8 _0[0x5c0];
    u32 field_5c0;
};
PKMN_OFFSET_ASSERT(Unk_16ce310, field_5c0, 0x5c0);

namespace nn {
namespace pia {
namespace nex {
class NatPortDetecter {
public:
    bool vf5();
    bool vf6();
    u32 vf9();
};
}  // namespace nex
}  // namespace pia
}  // namespace nn

// 0x71016ce1f0
u32 nn::pia::nex::NatPortDetecter::vf9() {
    return 0x7d0;
}

// 0x71016ce300
bool nn::pia::nex::NatPortDetecter::vf5() {
    const Unk_16ce300* self = reinterpret_cast<const Unk_16ce300*>(this);
    return self->field_5c0 != 0;
}

// 0x71016ce310
bool nn::pia::nex::NatPortDetecter::vf6() {
    const Unk_16ce310* self = reinterpret_cast<const Unk_16ce310*>(this);
    return self->field_5c0 != 0;
}
