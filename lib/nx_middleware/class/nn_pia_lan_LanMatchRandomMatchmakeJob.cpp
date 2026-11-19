// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia3lan26LanMatchRandomMatchmakeJobE
#include <types.h>

struct Unk_166cae0 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_166cae0, field_60, 0x60);

namespace nn {
namespace pia {
namespace lan {
class LanMatchRandomMatchmakeJob {
public:
    void vf5();
    u32 vf7();
    void vf9();
    void vf11();
};
}  // namespace lan
}  // namespace pia
}  // namespace nn

// 0x710166cad0
void nn::pia::lan::LanMatchRandomMatchmakeJob::vf5() {
}

// 0x710166cae0
u32 nn::pia::lan::LanMatchRandomMatchmakeJob::vf7() {
    const Unk_166cae0* self = reinterpret_cast<const Unk_166cae0*>(this);
    return self->field_60;
}

// 0x710166caf0
void nn::pia::lan::LanMatchRandomMatchmakeJob::vf9() {
}

// 0x7101729240
void nn::pia::lan::LanMatchRandomMatchmakeJob::vf11() {
}
