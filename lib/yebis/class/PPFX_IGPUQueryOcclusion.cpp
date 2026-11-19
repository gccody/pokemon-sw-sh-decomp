// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_44a650 {
    u8 _0[0x2c];
    u32 field_2c;
};
PKMN_OFFSET_ASSERT(Unk_44a650, field_2c, 0x2c);

namespace PPFX {
class IGPUQueryOcclusion {
public:
    void vf5();
};
}  // namespace PPFX

// 0x710044a650
void PPFX::IGPUQueryOcclusion::vf5() {
    Unk_44a650* self = reinterpret_cast<Unk_44a650*>(this);
    self->field_2c = 0xffffffff;
}
