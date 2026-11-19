// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_16d3b40 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_16d3b40, field_8, 0x8);

struct Unk_16d3b50 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_16d3b50, field_8, 0x8);

namespace nn {
namespace pia {
namespace nex {
class NexNatRelayInterface {
public:
    void vf2(u64 value);
    void vf3();
    void vf4();
    void vf6();
    void vf7();
    void vf12();
};
}  // namespace nex
}  // namespace pia
}  // namespace nn

// 0x71016d3b40
void nn::pia::nex::NexNatRelayInterface::vf2(u64 value) {
    Unk_16d3b40* self = reinterpret_cast<Unk_16d3b40*>(this);
    if (value != 0) {
        self->field_8 = value;
    }
}

// 0x71016d3b50
void nn::pia::nex::NexNatRelayInterface::vf3() {
    Unk_16d3b50* self = reinterpret_cast<Unk_16d3b50*>(this);
    self->field_8 = 0;
}

// 0x71016d5cd0
void nn::pia::nex::NexNatRelayInterface::vf4() {
}

// 0x71016d5ce0
void nn::pia::nex::NexNatRelayInterface::vf6() {
}

// 0x71016d5cf0
void nn::pia::nex::NexNatRelayInterface::vf7() {
}

// 0x71016d5d00
void nn::pia::nex::NexNatRelayInterface::vf12() {
}
