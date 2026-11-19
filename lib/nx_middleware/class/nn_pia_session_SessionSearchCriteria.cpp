// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_1733d70 {
    u8 _0[0x8];
    u64 field_8;
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1733d70, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1733d70, field_10, 0x10);

namespace nn {
namespace pia {
namespace session {
class SessionSearchCriteria {
public:
    void vf3();
    void vf4();
};
}  // namespace session
}  // namespace pia
}  // namespace nn

// 0x7101733d70
void nn::pia::session::SessionSearchCriteria::vf3() {
    Unk_1733d70* self = reinterpret_cast<Unk_1733d70*>(this);
    self->field_10 = 0;
    self->field_8 = 0x1400000000;
}

// 0x7101733e10
void nn::pia::session::SessionSearchCriteria::vf4() {
}
