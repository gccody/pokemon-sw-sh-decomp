// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_16f61b0 {
    u8 _0[0x138];
    u64 field_138;
    u8 _140[0x2c];
    u8 field_16c;
};
PKMN_OFFSET_ASSERT(Unk_16f61b0, field_138, 0x138);
PKMN_OFFSET_ASSERT(Unk_16f61b0, field_16c, 0x16c);

namespace nn {
namespace pia {
namespace nex {
class NexMatchJoinSessionJob {
public:
    void vf5();
    void vf13();
};
}  // namespace nex
}  // namespace pia
}  // namespace nn

// 0x71016f61b0
void nn::pia::nex::NexMatchJoinSessionJob::vf13() {
    Unk_16f61b0* self = reinterpret_cast<Unk_16f61b0*>(this);
    self->field_138 = 0;
    self->field_16c = 0;
}

// 0x71016f61c0
void nn::pia::nex::NexMatchJoinSessionJob::vf5() {
}
