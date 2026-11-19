// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3fa650 {
    u8 _0[0x268];
    u64 field_268;
};
PKMN_OFFSET_ASSERT(Unk_3fa650, field_268, 0x268);

namespace nn { namespace os { u64 GetSystemTick(); } }

class Unk_2385ab8 {
public:
    void vf4();
};

// 0x71003fa650
void Unk_2385ab8::vf4() {
    Unk_3fa650* self = reinterpret_cast<Unk_3fa650*>(this);
    u64 r0 = nn::os::GetSystemTick();
    self->field_268 = r0;
}
