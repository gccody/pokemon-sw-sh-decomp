// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_1610010 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1610010, field_8, 0x8);

namespace nn {
namespace nex {
class PRUDPStreamTemplatePRUDPLiteImp {
public:
    u32 vf8();
};
}  // namespace nex
}  // namespace nn

// 0x7101610010
u32 nn::nex::PRUDPStreamTemplatePRUDPLiteImp::vf8() {
    const Unk_1610010* self = reinterpret_cast<const Unk_1610010*>(this);
    return self->field_8;
}
