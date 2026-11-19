// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex33PRUDPEndPointTemplatePRUDPLiteImpE
#include <types.h>

struct Unk_1610040 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1610040, field_10, 0x10);

namespace nn {
namespace nex {
class PRUDPEndPointTemplatePRUDPLiteImp {
public:
    const u8* vf4();
};
}  // namespace nex
}  // namespace nn

// 0x7101610040
const u8* nn::nex::PRUDPEndPointTemplatePRUDPLiteImp::vf4() {
    const Unk_1610040* self = reinterpret_cast<const Unk_1610040*>(this);
    return &self->field_10;
}
