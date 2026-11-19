// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_160a2e0 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_160a2e0, field_8, 0x8);

struct Unk_1610020 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1610020, field_18, 0x18);

namespace nn {
namespace nex {
class PRUDPStreamTemplateImp {
public:
    void vf7();
    u32 vf8();
    void vf9(u32 value);
};
}  // namespace nex
}  // namespace nn

// 0x7101609f50
void nn::nex::PRUDPStreamTemplateImp::vf7() {
}

// 0x710160a2e0
u32 nn::nex::PRUDPStreamTemplateImp::vf8() {
    const Unk_160a2e0* self = reinterpret_cast<const Unk_160a2e0*>(this);
    return self->field_8;
}

// 0x7101610020
void nn::nex::PRUDPStreamTemplateImp::vf9(u32 value) {
    Unk_1610020* self = reinterpret_cast<Unk_1610020*>(this);
    self->field_18 = value;
}
