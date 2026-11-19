// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_17493f0 {
    u8 _0[0x8];
    u8 field_8;
    u8 _9[0x47];
    u64 field_50;
};
PKMN_OFFSET_ASSERT(Unk_17493f0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_17493f0, field_50, 0x50);

namespace nn {
namespace pia {
namespace transport {
class Station {
public:
    void vf2();
};
}  // namespace transport
}  // namespace pia
}  // namespace nn

// 0x71017493f0
void nn::pia::transport::Station::vf2() {
    Unk_17493f0* self = reinterpret_cast<Unk_17493f0*>(this);
    self->field_8 = 0;
    self->field_50 = 0;
}
