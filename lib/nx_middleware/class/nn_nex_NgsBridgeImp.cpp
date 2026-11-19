// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_159b3d0_8 {
    u8 _0[0xc0];
    u64 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_159b3d0_8, field_c0, 0xc0);

struct Unk_159b3d0 {
    u8 _0[0x8];
    Unk_159b3d0_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_159b3d0, field_8, 0x8);

namespace nn {
namespace nex {
class NgsBridgeImp {
public:
    u64 vf2();
};
}  // namespace nex
}  // namespace nn

// 0x710159b3d0
u64 nn::nex::NgsBridgeImp::vf2() {
    const Unk_159b3d0* self = reinterpret_cast<const Unk_159b3d0*>(this);
    return self->field_8->field_c0;
}
