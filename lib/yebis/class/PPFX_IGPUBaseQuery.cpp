// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_44a2c0 {
    u8 _0[0x18];
    u32 field_18;
    u8 _1c[0xc];
    u32 field_28;
};
PKMN_OFFSET_ASSERT(Unk_44a2c0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_44a2c0, field_28, 0x28);

namespace PPFX {
class IGPUBaseQuery {
public:
    u32 vf8();
};
}  // namespace PPFX

// 0x710044a2c0
u32 PPFX::IGPUBaseQuery::vf8() {
    const Unk_44a2c0* self = reinterpret_cast<const Unk_44a2c0*>(this);
    if (self->field_18 != 1) {
        return 0xfffffffc;
    }
    return self->field_28 == 1 ? 0 : 0xfffffffd;
}
