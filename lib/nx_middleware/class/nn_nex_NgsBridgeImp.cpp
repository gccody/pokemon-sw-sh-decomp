// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex12NgsBridgeImpE
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

struct Unk_159b400 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_159b400, field_8, 0x8);

void Unk_163ece0(u64);

struct Unk_159b410 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_159b410, field_8, 0x8);

void Unk_163ecf0(u64);

namespace nn {
namespace nex {
class NgsBridgeImp {
public:
    u64 vf2();
    void vf4();
    void vf5();
};
}  // namespace nex
}  // namespace nn

// 0x710159b3d0
u64 nn::nex::NgsBridgeImp::vf2() {
    const Unk_159b3d0* self = reinterpret_cast<const Unk_159b3d0*>(this);
    return self->field_8->field_c0;
}

// 0x710159b400
void nn::nex::NgsBridgeImp::vf4() {
    const Unk_159b400* self = reinterpret_cast<const Unk_159b400*>(this);
    Unk_163ece0(self->field_8);
}

// 0x710159b410
void nn::nex::NgsBridgeImp::vf5() {
    const Unk_159b410* self = reinterpret_cast<const Unk_159b410*>(this);
    Unk_163ecf0(self->field_8);
}
