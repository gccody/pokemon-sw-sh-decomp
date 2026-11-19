// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_4c7bc0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_4c7bc0, field_10, 0x10);

struct Unk_4c66b0 {
    u8 _0[0x20];
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_4c66b0, field_20, 0x20);

namespace SiSDK3 {
namespace SiStringTable {
class Entry {
public:
    u32 vf4();
    u32 vf5();
};
}  // namespace SiStringTable
}  // namespace SiSDK3

// 0x71004c66b0
u32 SiSDK3::SiStringTable::Entry::vf5() {
    const Unk_4c66b0* self = reinterpret_cast<const Unk_4c66b0*>(this);
    return self->field_20;
}

// 0x71004c7bc0
u32 SiSDK3::SiStringTable::Entry::vf4() {
    const Unk_4c7bc0* self = reinterpret_cast<const Unk_4c7bc0*>(this);
    return self->field_10;
}
