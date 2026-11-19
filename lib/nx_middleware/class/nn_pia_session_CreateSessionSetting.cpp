// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia7session20CreateSessionSettingE
#include <types.h>

struct Unk_17233d0 {
    u8 _0[0x8];
    u16 field_8;
    u8 field_a;
    u8 _b[0x1];
    u16 field_c;
    u8 field_e;
};
PKMN_OFFSET_ASSERT(Unk_17233d0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_17233d0, field_a, 0xa);
PKMN_OFFSET_ASSERT(Unk_17233d0, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_17233d0, field_e, 0xe);

namespace nn {
namespace pia {
namespace session {
class CreateSessionSetting {
public:
    void vf8();
    void vf9();
};
}  // namespace session
}  // namespace pia
}  // namespace nn

// 0x71017233d0
void nn::pia::session::CreateSessionSetting::vf8() {
    Unk_17233d0* self = reinterpret_cast<Unk_17233d0*>(this);
    self->field_8 = 0;
    self->field_a = 0;
    self->field_c = 0;
    self->field_e = 0;
}

// 0x71017233f0
void nn::pia::session::CreateSessionSetting::vf9() {
}
