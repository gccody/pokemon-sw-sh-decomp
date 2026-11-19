// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia5local21LocalKickoutManageJobE
#include <types.h>

struct Unk_168e8e0_1b0_18 {
    u8 _0[0x484];
    u8 field_484;
};
PKMN_OFFSET_ASSERT(Unk_168e8e0_1b0_18, field_484, 0x484);

struct Unk_168e8e0_1b0 {
    u8 _0[0x18];
    Unk_168e8e0_1b0_18* field_18;
};
PKMN_OFFSET_ASSERT(Unk_168e8e0_1b0, field_18, 0x18);

struct Unk_168e8e0 {
    u8 _0[0x1b0];
    Unk_168e8e0_1b0* field_1b0;
};
PKMN_OFFSET_ASSERT(Unk_168e8e0, field_1b0, 0x1b0);

namespace nn {
namespace pia {
namespace local {
class LocalKickoutManageJob {
public:
    void vf5();
    void vf6();
};
}  // namespace local
}  // namespace pia
}  // namespace nn

// 0x710168e8e0
void nn::pia::local::LocalKickoutManageJob::vf6() {
    const Unk_168e8e0* self = reinterpret_cast<const Unk_168e8e0*>(this);
    self->field_1b0->field_18->field_484 = 1;
}

// 0x710168e910
void nn::pia::local::LocalKickoutManageJob::vf5() {
}
