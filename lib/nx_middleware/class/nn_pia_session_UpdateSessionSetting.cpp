// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia7session20UpdateSessionSettingE
#include <types.h>

struct Unk_1735d70 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1735d70, field_8, 0x8);

namespace nn {
namespace pia {
namespace session {
class UpdateSessionSetting {
public:
    void vf5();
    void vf9();
};
}  // namespace session
}  // namespace pia
}  // namespace nn

// 0x7101735d70
void nn::pia::session::UpdateSessionSetting::vf9() {
    Unk_1735d70* self = reinterpret_cast<Unk_1735d70*>(this);
    self->field_8 = 0;
}

// 0x7101735dc0
void nn::pia::session::UpdateSessionSetting::vf5() {
}
