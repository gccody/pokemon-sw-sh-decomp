// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia9transport22BandwidthCheckProtocolE
#include <types.h>

struct Unk_17368a0 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_17368a0, field_60, 0x60);

namespace nn {
namespace pia {
namespace transport {
class BandwidthCheckProtocol {
public:
    void vf2();
    u32 vf4();
    void vf6();
};
}  // namespace transport
}  // namespace pia
}  // namespace nn

// 0x71017368a0
void nn::pia::transport::BandwidthCheckProtocol::vf6() {
    Unk_17368a0* self = reinterpret_cast<Unk_17368a0*>(this);
    self->field_60 = 0;
}

// 0x7101737e50
void nn::pia::transport::BandwidthCheckProtocol::vf2() {
}

// 0x7101737e80
u32 nn::pia::transport::BandwidthCheckProtocol::vf4() {
    return 0x54;
}
