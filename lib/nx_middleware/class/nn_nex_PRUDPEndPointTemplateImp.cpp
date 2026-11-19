// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex24PRUDPEndPointTemplateImpE
#include <types.h>

struct Unk_1610030 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1610030, field_10, 0x10);

namespace nn {
namespace nex {
class PRUDPEndPointTemplateImp {
public:
    const u8* vf4();
};
}  // namespace nex
}  // namespace nn

// 0x7101610030
const u8* nn::nex::PRUDPEndPointTemplateImp::vf4() {
    const Unk_1610030* self = reinterpret_cast<const Unk_1610030*>(this);
    return &self->field_10;
}
