// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex28QueuingSocketTransportBufferE
#include <types.h>

struct Unk_160fc20_1a8 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_160fc20_1a8, field_8, 0x8);

struct Unk_160fc20 {
    u8 _0[0x1a8];
    Unk_160fc20_1a8* field_1a8;
    u8 _1b0[0xe8];
    u8 field_298;
};
PKMN_OFFSET_ASSERT(Unk_160fc20, field_1a8, 0x1a8);
PKMN_OFFSET_ASSERT(Unk_160fc20, field_298, 0x298);

namespace nn {
namespace nex {
class QueuingSocketTransportBuffer {
public:
    bool vf6();
};
}  // namespace nex
}  // namespace nn

// 0x710160fc20
bool nn::nex::QueuingSocketTransportBuffer::vf6() {
    const Unk_160fc20* self = reinterpret_cast<const Unk_160fc20*>(this);
    if (self->field_1a8->field_8 != 0) {
        return 1;
    }
    return self->field_298 == 0;
}
