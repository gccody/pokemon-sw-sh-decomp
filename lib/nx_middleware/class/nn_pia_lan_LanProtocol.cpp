// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia3lan11LanProtocolE
#include <types.h>

struct Unk_173d1f0 {
    u8 _0[0x30];
    u64 field_30;
    u8 field_38;
    u8 _39[0x7];
    u64 field_40;
};
PKMN_OFFSET_ASSERT(Unk_173d1f0, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_173d1f0, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_173d1f0, field_40, 0x40);

struct Unk_1674ea0 {
    u8 _0[0x30];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_1674ea0, field_30, 0x30);

namespace nn {
namespace pia {
namespace lan {
class LanProtocol {
public:
    void vf2();
    u32 vf4();
    void vf8();
    u32 vf11();
    u64 vf12();
};
}  // namespace lan
}  // namespace pia
}  // namespace nn

// 0x7101673e70
void nn::pia::lan::LanProtocol::vf2() {
}

// 0x7101674e80
u32 nn::pia::lan::LanProtocol::vf4() {
    return 0x44;
}

// 0x7101674e90
u32 nn::pia::lan::LanProtocol::vf11() {
    return 0;
}

// 0x7101674ea0
u64 nn::pia::lan::LanProtocol::vf12() {
    const Unk_1674ea0* self = reinterpret_cast<const Unk_1674ea0*>(this);
    return self->field_30;
}

// 0x710173d1f0
void nn::pia::lan::LanProtocol::vf8() {
    Unk_173d1f0* self = reinterpret_cast<Unk_173d1f0*>(this);
    self->field_30 = 0;
    self->field_40 = 0;
    self->field_38 = 0xfd;
}
