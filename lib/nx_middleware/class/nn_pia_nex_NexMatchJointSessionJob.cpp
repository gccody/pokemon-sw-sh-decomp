// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia3nex23NexMatchJointSessionJobE
#include <types.h>

struct Unk_1705200 {
    u8 _0[0x230];
    u32 field_230;
};
PKMN_OFFSET_ASSERT(Unk_1705200, field_230, 0x230);

namespace nn {
namespace pia {
namespace nex {
class NexMatchJointSessionJob {
public:
    void vf5();
    u32 vf6();
};
}  // namespace nex
}  // namespace pia
}  // namespace nn

// 0x7101705200
u32 nn::pia::nex::NexMatchJointSessionJob::vf6() {
    const Unk_1705200* self = reinterpret_cast<const Unk_1705200*>(this);
    return self->field_230;
}

// 0x7101705210
void nn::pia::nex::NexMatchJointSessionJob::vf5() {
}
