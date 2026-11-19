// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_1724ea0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1724ea0, field_10, 0x10);

namespace nn {
namespace pia {
namespace nex {
class NexJoinSessionSetting {
public:
    void vf3(u32 value);
};
}  // namespace nex
}  // namespace pia
}  // namespace nn

// 0x7101724ea0
void nn::pia::nex::NexJoinSessionSetting::vf3(u32 value) {
    Unk_1724ea0* self = reinterpret_cast<Unk_1724ea0*>(this);
    self->field_10 = value;
}
