// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_1668f50 {
    u8 _0[0x110];
    u32 field_110;
};
PKMN_OFFSET_ASSERT(Unk_1668f50, field_110, 0x110);

namespace nn {
namespace pia {
namespace lan {
class LanMatchJoinSessionJob {
public:
    void vf5();
    void vf7();
    u32 vf11();
    void vf13();
};
}  // namespace lan
}  // namespace pia
}  // namespace nn

// 0x7101668f30
void nn::pia::lan::LanMatchJoinSessionJob::vf5() {
}

// 0x7101668f40
void nn::pia::lan::LanMatchJoinSessionJob::vf7() {
}

// 0x7101668f50
u32 nn::pia::lan::LanMatchJoinSessionJob::vf11() {
    const Unk_1668f50* self = reinterpret_cast<const Unk_1668f50*>(this);
    return self->field_110;
}

// 0x7101724d50
void nn::pia::lan::LanMatchJoinSessionJob::vf13() {
}
