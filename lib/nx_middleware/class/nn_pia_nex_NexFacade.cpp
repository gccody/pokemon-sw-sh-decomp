// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_16c8420 {
    u8 _0[0x18c];
    u32 field_18c;
};
PKMN_OFFSET_ASSERT(Unk_16c8420, field_18c, 0x18c);

struct Unk_16c8c60 {
    u8 _0[0x210];
    u8 field_210;
};
PKMN_OFFSET_ASSERT(Unk_16c8c60, field_210, 0x210);

namespace nn {
namespace pia {
namespace nex {
class NexFacade {
public:
    u32 vf2();
    u32 vf3();
    u32 vf10();
    u8 vf12();
};
}  // namespace nex
}  // namespace pia
}  // namespace nn

// 0x71016c8350
u32 nn::pia::nex::NexFacade::vf2() {
    return 0xc000;
}

// 0x71016c8360
u32 nn::pia::nex::NexFacade::vf3() {
    return 0xffff;
}

// 0x71016c8420
u32 nn::pia::nex::NexFacade::vf10() {
    const Unk_16c8420* self = reinterpret_cast<const Unk_16c8420*>(this);
    return self->field_18c;
}

// 0x71016c8c60
u8 nn::pia::nex::NexFacade::vf12() {
    const Unk_16c8c60* self = reinterpret_cast<const Unk_16c8c60*>(this);
    return self->field_210;
}
