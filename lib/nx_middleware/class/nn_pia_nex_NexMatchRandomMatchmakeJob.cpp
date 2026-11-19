// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia3nex26NexMatchRandomMatchmakeJobE
#include <types.h>

struct Unk_170b390 {
    u8 _0[0x64];
    u32 field_64;
    u8 _68[0x17];
    u8 field_7f;
};
PKMN_OFFSET_ASSERT(Unk_170b390, field_64, 0x64);
PKMN_OFFSET_ASSERT(Unk_170b390, field_7f, 0x7f);

namespace nn {
namespace pia {
namespace nex {
class NexMatchRandomMatchmakeJob {
public:
    void vf5();
    void vf9(u32 value);
};
}  // namespace nex
}  // namespace pia
}  // namespace nn

// 0x710170b390
void nn::pia::nex::NexMatchRandomMatchmakeJob::vf9(u32 value) {
    Unk_170b390* self = reinterpret_cast<Unk_170b390*>(this);
    if (self->field_64 == value) {
        self->field_7f = 1;
    }
}

// 0x710170b9c0
void nn::pia::nex::NexMatchRandomMatchmakeJob::vf5() {
}
