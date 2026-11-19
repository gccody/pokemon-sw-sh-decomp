// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_16037f0 {
    u8 _0[0x138];
    u64 field_138;
    u64 field_140;
};
PKMN_OFFSET_ASSERT(Unk_16037f0, field_138, 0x138);
PKMN_OFFSET_ASSERT(Unk_16037f0, field_140, 0x140);

namespace nn {
namespace nex {
class PRUDPStream {
public:
    const char* vf8();
    u64 vf13();
};
}  // namespace nex
}  // namespace nn

// 0x7101601d50
const char* nn::nex::PRUDPStream::vf8() {
    return "prudp";
}

// 0x71016037f0
u64 nn::nex::PRUDPStream::vf13() {
    const Unk_16037f0* self = reinterpret_cast<const Unk_16037f0*>(this);
    return (self->field_140 - self->field_138) >> 2;
}
