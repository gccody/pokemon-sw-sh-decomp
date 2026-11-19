// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex15SocketTransportE
#include <types.h>

struct Unk_15f3d30 {
    u8 _0[0x438];
    u8 field_438;
};
PKMN_OFFSET_ASSERT(Unk_15f3d30, field_438, 0x438);

struct Unk_160feb0 {
    u8 _0[0x458];
    u8 field_458;
};
PKMN_OFFSET_ASSERT(Unk_160feb0, field_458, 0x458);

struct Unk_160fec0 {
    u8 _0[0x2e0];
    u8 field_2e0;
};
PKMN_OFFSET_ASSERT(Unk_160fec0, field_2e0, 0x2e0);

namespace nn {
namespace nex {
class SocketTransport {
public:
    const u8* vf15();
    const u8* vf16();
    u64 vf17();
    u64 vf18();
    void vf21();
};
}  // namespace nex
}  // namespace nn

// 0x71015f3d30
const u8* nn::nex::SocketTransport::vf15() {
    const Unk_15f3d30* self = reinterpret_cast<const Unk_15f3d30*>(this);
    return &self->field_438;
}

// 0x71015f5f10
u64 nn::nex::SocketTransport::vf17() {
    return 0;
}

// 0x71015f5f20
u64 nn::nex::SocketTransport::vf18() {
    return 0;
}

// 0x710160feb0
const u8* nn::nex::SocketTransport::vf16() {
    const Unk_160feb0* self = reinterpret_cast<const Unk_160feb0*>(this);
    return &self->field_458;
}

// 0x710160fec0
void nn::nex::SocketTransport::vf21() {
    Unk_160fec0* self = reinterpret_cast<Unk_160fec0*>(this);
    self->field_2e0 = 1;
}
