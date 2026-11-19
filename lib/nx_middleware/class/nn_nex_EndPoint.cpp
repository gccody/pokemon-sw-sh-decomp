// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_160fde0 {
    u8 _0[0xa8];
    u64 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_160fde0, field_a8, 0xa8);

struct Unk_160fdf0 {
    u8 _0[0xa8];
    u64 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_160fdf0, field_a8, 0xa8);

namespace nn {
namespace nex {
class EndPoint {
public:
    void vf32(u64 value);
    void vf33();
    void vf34();
};
}  // namespace nex
}  // namespace nn

// 0x710160fde0
void nn::nex::EndPoint::vf32(u64 value) {
    Unk_160fde0* self = reinterpret_cast<Unk_160fde0*>(this);
    self->field_a8 = value;
}

// 0x710160fdf0
void nn::nex::EndPoint::vf33() {
    Unk_160fdf0* self = reinterpret_cast<Unk_160fdf0*>(this);
    self->field_a8 = 0;
}

// 0x710160fe00
void nn::nex::EndPoint::vf34() {
}
