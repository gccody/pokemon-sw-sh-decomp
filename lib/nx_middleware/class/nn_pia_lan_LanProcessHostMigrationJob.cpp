// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_16709f0 {
    u8 _0[0x1a1];
    u8 field_1a1;
};
PKMN_OFFSET_ASSERT(Unk_16709f0, field_1a1, 0x1a1);

namespace nn {
namespace pia {
namespace lan {
class LanProcessHostMigrationJob {
public:
    void vf5();
    u8 vf8();
    void vf9();
    u32 vf10();
};
}  // namespace lan
}  // namespace pia
}  // namespace nn

// 0x71016709f0
u8 nn::pia::lan::LanProcessHostMigrationJob::vf8() {
    const Unk_16709f0* self = reinterpret_cast<const Unk_16709f0*>(this);
    return self->field_1a1;
}

// 0x7101670a10
u32 nn::pia::lan::LanProcessHostMigrationJob::vf10() {
    return 1;
}

// 0x7101670a20
void nn::pia::lan::LanProcessHostMigrationJob::vf5() {
}

// 0x7101670a30
void nn::pia::lan::LanProcessHostMigrationJob::vf9() {
}
