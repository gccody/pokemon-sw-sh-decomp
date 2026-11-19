// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_4b9830 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_4b9830, field_10, 0x10);

namespace PPFX {
class IPfxInterface {
public:
    bool vf5();
};
}  // namespace PPFX

// 0x71004b9830
bool PPFX::IPfxInterface::vf5() {
    const Unk_4b9830* self = reinterpret_cast<const Unk_4b9830*>(this);
    return self->field_10 != 0;
}
