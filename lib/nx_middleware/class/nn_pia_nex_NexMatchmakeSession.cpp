// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_16da8a0 {
    u8 _0[0xa0];
    u64 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_16da8a0, field_a0, 0xa0);

struct Unk_16da8b0 {
    u8 _0[0xe8];
    u64 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_16da8b0, field_e8, 0xe8);

struct Unk_16da970 {
    u8 _0[0x2e0];
    u8 field_2e0;
};
PKMN_OFFSET_ASSERT(Unk_16da970, field_2e0, 0x2e0);

namespace nn {
namespace pia {
namespace nex {
class NexMatchmakeSession {
public:
    void vf34();
    u64 vf7();
    u64 vf26();
    const u8* vf36();
};
}  // namespace nex
}  // namespace pia
}  // namespace nn

// 0x71016da8a0
u64 nn::pia::nex::NexMatchmakeSession::vf7() {
    const Unk_16da8a0* self = reinterpret_cast<const Unk_16da8a0*>(this);
    return self->field_a0;
}

// 0x71016da8b0
u64 nn::pia::nex::NexMatchmakeSession::vf26() {
    const Unk_16da8b0* self = reinterpret_cast<const Unk_16da8b0*>(this);
    return self->field_e8;
}

// 0x71016da970
const u8* nn::pia::nex::NexMatchmakeSession::vf36() {
    const Unk_16da970* self = reinterpret_cast<const Unk_16da970*>(this);
    return &self->field_2e0;
}

// 0x7101722950
void nn::pia::nex::NexMatchmakeSession::vf34() {
}
