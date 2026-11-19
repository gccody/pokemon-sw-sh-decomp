// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia3nex22NexMatchJoinSessionJobE
#include <types.h>

struct Unk_16f5fa0 {
    u8 _0[0x114];
    u32 field_114;
    u8 _118[0x4];
    u8 field_11c;
};
PKMN_OFFSET_ASSERT(Unk_16f5fa0, field_114, 0x114);
PKMN_OFFSET_ASSERT(Unk_16f5fa0, field_11c, 0x11c);

struct Unk_16f61b0 {
    u8 _0[0x138];
    u64 field_138;
    u8 _140[0x2c];
    u8 field_16c;
};
PKMN_OFFSET_ASSERT(Unk_16f61b0, field_138, 0x138);
PKMN_OFFSET_ASSERT(Unk_16f61b0, field_16c, 0x16c);

namespace nn {
namespace pia {
namespace nex {
class NexMatchJoinSessionJob {
public:
    void vf5();
    void vf7(u32 value);
    void vf13();
};
}  // namespace nex
}  // namespace pia
}  // namespace nn

// 0x71016f5fa0
void nn::pia::nex::NexMatchJoinSessionJob::vf7(u32 value) {
    Unk_16f5fa0* self = reinterpret_cast<Unk_16f5fa0*>(this);
    if (self->field_114 == value) {
        self->field_11c = 1;
    }
}

// 0x71016f61b0
void nn::pia::nex::NexMatchJoinSessionJob::vf13() {
    Unk_16f61b0* self = reinterpret_cast<Unk_16f61b0*>(this);
    self->field_138 = 0;
    self->field_16c = 0;
}

// 0x71016f61c0
void nn::pia::nex::NexMatchJoinSessionJob::vf5() {
}
