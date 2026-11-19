// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_1724e90 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1724e90, field_8, 0x8);

struct Unk_1724ee0 {
    u8 _0[0x14];
    u16 field_14;
};
PKMN_OFFSET_ASSERT(Unk_1724ee0, field_14, 0x14);

struct Unk_1724e80 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1724e80, field_8, 0x8);

namespace nn {
namespace pia {
namespace lan {
class LanJoinSessionSetting {
public:
    u64 vf2();
    void vf3();
    void vf5(u16 value);
    void vf7(u64 value);
};
}  // namespace lan
}  // namespace pia
}  // namespace nn

// 0x7101662740
void nn::pia::lan::LanJoinSessionSetting::vf3() {
}

// 0x7101724e80
void nn::pia::lan::LanJoinSessionSetting::vf7(u64 value) {
    Unk_1724e80* self = reinterpret_cast<Unk_1724e80*>(this);
    self->field_8 = value;
}

// 0x7101724e90
u64 nn::pia::lan::LanJoinSessionSetting::vf2() {
    const Unk_1724e90* self = reinterpret_cast<const Unk_1724e90*>(this);
    return self->field_8;
}

// 0x7101724ee0
void nn::pia::lan::LanJoinSessionSetting::vf5(u16 value) {
    Unk_1724ee0* self = reinterpret_cast<Unk_1724ee0*>(this);
    self->field_14 = value;
}
