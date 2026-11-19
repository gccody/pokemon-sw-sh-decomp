// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex21OutputEmulationDeviceE
#include <types.h>

struct Unk_160fdc0 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_160fdc0, field_8, 0x8);

namespace nn {
namespace nex {
class OutputEmulationDevice {
public:
    void vf2();
};
}  // namespace nex
}  // namespace nn

// 0x710160fdc0
void nn::nex::OutputEmulationDevice::vf2() {
    Unk_160fdc0* self = reinterpret_cast<Unk_160fdc0*>(this);
    self->field_8 = 1;
}
