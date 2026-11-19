// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia3nex23NexCreateSessionSettingE
#include <types.h>

struct Unk_16c4ba0 {
    u8 _0[0x234];
    u32 field_234;
};
PKMN_OFFSET_ASSERT(Unk_16c4ba0, field_234, 0x234);

struct Unk_16c4bb0 {
    u8 _0[0x639];
    u8 field_639;
};
PKMN_OFFSET_ASSERT(Unk_16c4bb0, field_639, 0x639);

namespace nn {
namespace pia {
namespace nex {
class NexCreateSessionSetting {
public:
    u32 vf6();
    u32 vf7();
    void vf9();
};
}  // namespace nex
}  // namespace pia
}  // namespace nn

// 0x71016c4ba0
u32 nn::pia::nex::NexCreateSessionSetting::vf6() {
    const Unk_16c4ba0* self = reinterpret_cast<const Unk_16c4ba0*>(this);
    return self->field_234;
}

// 0x71016c4bb0
u32 nn::pia::nex::NexCreateSessionSetting::vf7() {
    const Unk_16c4bb0* self = reinterpret_cast<const Unk_16c4bb0*>(this);
    return self->field_639 & 1;
}

// 0x71016c5200
void nn::pia::nex::NexCreateSessionSetting::vf9() {
}
