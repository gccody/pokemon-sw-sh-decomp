// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_1591b20_10 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1591b20_10, field_10, 0x10);

struct Unk_1591b20 {
    u8 _0[0x10];
    Unk_1591b20_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_1591b20, field_10, 0x10);

namespace nn {
namespace nex {
class DataStoreLogicServerClient {
public:
    u64 vf71();
    u32 vf72();
};
}  // namespace nex
}  // namespace nn

// 0x7101591b20
u64 nn::nex::DataStoreLogicServerClient::vf71() {
    const Unk_1591b20* self = reinterpret_cast<const Unk_1591b20*>(this);
    if (self->field_10 == nullptr) {
        return 0;
    }
    return self->field_10->field_10;
}

// 0x7101591b40
u32 nn::nex::DataStoreLogicServerClient::vf72() {
    return 1;
}
