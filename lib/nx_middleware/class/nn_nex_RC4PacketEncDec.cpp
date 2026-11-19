// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_15e7d10 {
    u8 _0[0x40];
    u8 field_40;
};
PKMN_OFFSET_ASSERT(Unk_15e7d10, field_40, 0x40);

namespace nn {
namespace nex {
class RC4PacketEncDec {
public:
    const u8* vf7();
};
}  // namespace nex
}  // namespace nn

// 0x71015e7d10
const u8* nn::nex::RC4PacketEncDec::vf7() {
    const Unk_15e7d10* self = reinterpret_cast<const Unk_15e7d10*>(this);
    return &self->field_40;
}
