// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia5clone13ClockProtocolE
#include <types.h>

struct Unk_1652470 {
    u8 _0[0x28];
    u32 field_28;
};
PKMN_OFFSET_ASSERT(Unk_1652470, field_28, 0x28);

struct Unk_1652490 {
    u8 _0[0x30];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_1652490, field_30, 0x30);

namespace nn {
namespace pia {
namespace clone {
class ClockProtocol {
public:
    void vf2();
    u32 vf3();
    u32 vf4();
    void vf6();
    u32 vf11();
    void vf13(u64 value);
};
}  // namespace clone
}  // namespace pia
}  // namespace nn

// 0x7101652460
void nn::pia::clone::ClockProtocol::vf2() {
}

// 0x7101652470
u32 nn::pia::clone::ClockProtocol::vf3() {
    const Unk_1652470* self = reinterpret_cast<const Unk_1652470*>(this);
    return self->field_28;
}

// 0x7101652480
u32 nn::pia::clone::ClockProtocol::vf4() {
    return 0x77;
}

// 0x7101652490
void nn::pia::clone::ClockProtocol::vf13(u64 value) {
    Unk_1652490* self = reinterpret_cast<Unk_1652490*>(this);
    self->field_30 = value;
}

// 0x710173d030
void nn::pia::clone::ClockProtocol::vf6() {
}

// 0x710173d2d0
u32 nn::pia::clone::ClockProtocol::vf11() {
    return 1;
}
