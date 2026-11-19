// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia3nex11NexNatRelayE
#include <types.h>

struct Unk_16d4fc0 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_16d4fc0, field_58, 0x58);

struct Unk_16d5130 {
    u8 _0[0x80];
    u32 field_80;
};
PKMN_OFFSET_ASSERT(Unk_16d5130, field_80, 0x80);

struct Unk_16d5140 {
    u8 _0[0x80];
    u32 field_80;
};
PKMN_OFFSET_ASSERT(Unk_16d5140, field_80, 0x80);

struct Unk_16d5160 {
    u8 _0[0x84];
    u8 field_84;
};
PKMN_OFFSET_ASSERT(Unk_16d5160, field_84, 0x84);

namespace nn {
namespace pia {
namespace nex {
class NexNatRelay {
public:
    const u8* vf14();
    void vf17(u32 value);
    u32 vf18();
    const u8* vf20();
};
}  // namespace nex
}  // namespace pia
}  // namespace nn

// 0x71016d4fc0
const u8* nn::pia::nex::NexNatRelay::vf14() {
    const Unk_16d4fc0* self = reinterpret_cast<const Unk_16d4fc0*>(this);
    return &self->field_58;
}

// 0x71016d5130
void nn::pia::nex::NexNatRelay::vf17(u32 value) {
    Unk_16d5130* self = reinterpret_cast<Unk_16d5130*>(this);
    self->field_80 = value;
}

// 0x71016d5140
u32 nn::pia::nex::NexNatRelay::vf18() {
    const Unk_16d5140* self = reinterpret_cast<const Unk_16d5140*>(this);
    return self->field_80;
}

// 0x71016d5160
const u8* nn::pia::nex::NexNatRelay::vf20() {
    const Unk_16d5160* self = reinterpret_cast<const Unk_16d5160*>(this);
    return &self->field_84;
}
