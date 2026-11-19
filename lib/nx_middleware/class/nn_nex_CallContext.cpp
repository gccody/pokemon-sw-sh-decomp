// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_15caa40 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_15caa40, field_10, 0x10);

namespace nn {
namespace nex {
class CallContext {
public:
    bool vf2();
    void vf3();
    void vf4();
};
}  // namespace nex
}  // namespace nn

// 0x71015caa40
bool nn::nex::CallContext::vf2() {
    const Unk_15caa40* self = reinterpret_cast<const Unk_15caa40*>(this);
    return (self->field_10 & 0xc) != 8;
}

// 0x71015d4640
void nn::nex::CallContext::vf3() {
}

// 0x71015d4650
void nn::nex::CallContext::vf4() {
}
