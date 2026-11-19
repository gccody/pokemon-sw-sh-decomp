// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

extern u64 Unk_27fc0a8;
struct Unk_1713560 {
    u8 _0[0x1f9];
    u8 field_1f9;
};
PKMN_OFFSET_ASSERT(Unk_1713560, field_1f9, 0x1f9);

namespace nn {
namespace pia {
namespace nex {
class NexProcessHostMigrationJob {
public:
    void vf5();
    u32 vf8();
    u32 vf11();
};
}  // namespace nex
}  // namespace pia
}  // namespace nn

// 0x71017113d0
u32 nn::pia::nex::NexProcessHostMigrationJob::vf11() {
    return 0;
}

// 0x7101713560
u32 nn::pia::nex::NexProcessHostMigrationJob::vf8() {
    const Unk_1713560* self = reinterpret_cast<const Unk_1713560*>(this);
    return (self->field_1f9 != 0) & (Unk_27fc0a8 == 0);
}

// 0x7101713880
void nn::pia::nex::NexProcessHostMigrationJob::vf5() {
}
