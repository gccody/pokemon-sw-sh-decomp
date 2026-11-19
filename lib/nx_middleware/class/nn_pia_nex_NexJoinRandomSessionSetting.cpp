// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_16d3430 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_16d3430, field_8, 0x8);

struct Unk_16d3460 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_16d3460, field_8, 0x8);

struct Unk_16d3490 {
    u8 _0[0x20b8];
    u32 field_20b8;
};
PKMN_OFFSET_ASSERT(Unk_16d3490, field_20b8, 0x20b8);

namespace nn {
namespace pia {
namespace nex {
class NexJoinRandomSessionSetting {
public:
    void vf5();
    const u8* vf6();
    const u8* vf8();
    u32 vf10();
};
}  // namespace nex
}  // namespace pia
}  // namespace nn

// 0x71016d3430
const u8* nn::pia::nex::NexJoinRandomSessionSetting::vf6() {
    const Unk_16d3430* self = reinterpret_cast<const Unk_16d3430*>(this);
    return &self->field_8;
}

// 0x71016d3460
const u8* nn::pia::nex::NexJoinRandomSessionSetting::vf8() {
    const Unk_16d3460* self = reinterpret_cast<const Unk_16d3460*>(this);
    return &self->field_8;
}

// 0x71016d3490
u32 nn::pia::nex::NexJoinRandomSessionSetting::vf10() {
    const Unk_16d3490* self = reinterpret_cast<const Unk_16d3490*>(this);
    return self->field_20b8;
}

// 0x71016d34d0
void nn::pia::nex::NexJoinRandomSessionSetting::vf5() {
}
