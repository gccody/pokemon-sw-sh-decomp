// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_169ac90 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_169ac90, field_8, 0x8);

namespace nn {
namespace pia {
namespace local {
class LocalSessionInfo {
public:
    void vf10();
    void vf11();
};
}  // namespace local
}  // namespace pia
}  // namespace nn

// 0x710169ac90
void nn::pia::local::LocalSessionInfo::vf10() {
    Unk_169ac90* self = reinterpret_cast<Unk_169ac90*>(this);
    self->field_8 = 0;
}

// 0x710169ad50
void nn::pia::local::LocalSessionInfo::vf11() {
}
