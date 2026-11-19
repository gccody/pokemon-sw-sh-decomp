// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_1724f10 {
    u8 _0[0x8];
    u64 field_8;
    u32 field_10;
    u16 field_14;
};
PKMN_OFFSET_ASSERT(Unk_1724f10, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1724f10, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_1724f10, field_14, 0x14);

namespace nn {
namespace pia {
namespace session {
class JoinSessionSetting {
public:
    void vf8();
};
}  // namespace session
}  // namespace pia
}  // namespace nn

// 0x7101724f10
void nn::pia::session::JoinSessionSetting::vf8() {
    Unk_1724f10* self = reinterpret_cast<Unk_1724f10*>(this);
    self->field_10 = 0;
    self->field_14 = 0;
    self->field_8 = 0;
}
