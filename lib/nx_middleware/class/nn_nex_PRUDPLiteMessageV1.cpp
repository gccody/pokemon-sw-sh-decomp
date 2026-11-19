// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_1609f30_arg1 {
    u8 _0[0x60];
    u16 field_60;
};
PKMN_OFFSET_ASSERT(Unk_1609f30_arg1, field_60, 0x60);

namespace nn {
namespace nex {
class PRUDPLiteMessageV1 {
public:
    u32 vf4(const Unk_1609f30_arg1* value);
};
}  // namespace nex
}  // namespace nn

// 0x7101609f30
u32 nn::nex::PRUDPLiteMessageV1::vf4(const Unk_1609f30_arg1* value) {
    return ((value->field_60 & 0x1f) == 1) << 3;
}
