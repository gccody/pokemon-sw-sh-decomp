// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_1610050 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1610050, field_8, 0x8);

namespace nn {
namespace nex {
class MultiPRUDPStreamTemplateImp {
public:
    u32 vf8();
};
}  // namespace nex
}  // namespace nn

// 0x7101610050
u32 nn::nex::MultiPRUDPStreamTemplateImp::vf8() {
    const Unk_1610050* self = reinterpret_cast<const Unk_1610050*>(this);
    return self->field_8;
}
