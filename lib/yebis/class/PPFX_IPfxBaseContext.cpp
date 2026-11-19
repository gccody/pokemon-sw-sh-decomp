// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_4b9820 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_4b9820, field_8, 0x8);

namespace PPFX {
class IPfxBaseContext {
public:
    u32 vf2();
};
}  // namespace PPFX

// 0x71004b9820
u32 PPFX::IPfxBaseContext::vf2() {
    const Unk_4b9820* self = reinterpret_cast<const Unk_4b9820*>(this);
    return self->field_8;
}
