// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_1627140 {
    u8 _0[0x20];
    u8 field_20;
};
PKMN_OFFSET_ASSERT(Unk_1627140, field_20, 0x20);

struct Unk_1626b00 {
    u8 _0[0x204];
    u8 field_204;
};
PKMN_OFFSET_ASSERT(Unk_1626b00, field_204, 0x204);

struct Unk_162a8f0 {
    u8 _0[0x250];
    u64 field_250;
};
PKMN_OFFSET_ASSERT(Unk_162a8f0, field_250, 0x250);

namespace nn {
namespace nex {
class CurlHttpConnection {
public:
    u8 vf7();
    u8 vf9();
    void vf21();
    u32 vf22();
    void vf23(u64 value);
};
}  // namespace nex
}  // namespace nn

// 0x7101626b00
u8 nn::nex::CurlHttpConnection::vf9() {
    const Unk_1626b00* self = reinterpret_cast<const Unk_1626b00*>(this);
    return self->field_204;
}

// 0x7101626e50
u32 nn::nex::CurlHttpConnection::vf22() {
    return 1;
}

// 0x7101627140
u8 nn::nex::CurlHttpConnection::vf7() {
    const Unk_1627140* self = reinterpret_cast<const Unk_1627140*>(this);
    return self->field_20;
}

// 0x710162a8e0
void nn::nex::CurlHttpConnection::vf21() {
}

// 0x710162a8f0
void nn::nex::CurlHttpConnection::vf23(u64 value) {
    Unk_162a8f0* self = reinterpret_cast<Unk_162a8f0*>(this);
    self->field_250 = value;
}
