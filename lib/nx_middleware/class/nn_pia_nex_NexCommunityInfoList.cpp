// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_16d8270 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_16d8270, field_10, 0x10);

struct Unk_16d8280 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_16d8280, field_10, 0x10);

struct Unk_16d82b0 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_16d82b0, field_8, 0x8);

struct Unk_16d82c0 {
    u8 _0[0xc];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_16d82c0, field_c, 0xc);

namespace nn {
namespace pia {
namespace nex {
class NexCommunityInfoList {
public:
    u64 vf2();
    u64 vf3();
    u32 vf6();
    u32 vf7();
};
}  // namespace nex
}  // namespace pia
}  // namespace nn

// 0x71016d8270
u64 nn::pia::nex::NexCommunityInfoList::vf2() {
    const Unk_16d8270* self = reinterpret_cast<const Unk_16d8270*>(this);
    return self->field_10;
}

// 0x71016d8280
u64 nn::pia::nex::NexCommunityInfoList::vf3() {
    const Unk_16d8280* self = reinterpret_cast<const Unk_16d8280*>(this);
    return self->field_10;
}

// 0x71016d82b0
u32 nn::pia::nex::NexCommunityInfoList::vf6() {
    const Unk_16d82b0* self = reinterpret_cast<const Unk_16d82b0*>(this);
    return self->field_8;
}

// 0x71016d82c0
u32 nn::pia::nex::NexCommunityInfoList::vf7() {
    const Unk_16d82c0* self = reinterpret_cast<const Unk_16d82c0*>(this);
    return self->field_c;
}
