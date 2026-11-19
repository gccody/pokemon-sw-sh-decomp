// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_167bb10 {
    u8 _0[0x1ac];
    u32 field_1ac;
};
PKMN_OFFSET_ASSERT(Unk_167bb10, field_1ac, 0x1ac);

struct Unk_1735d80 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1735d80, field_8, 0x8);

struct Unk_1735d90 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1735d90, field_8, 0x8);

struct Unk_1735db0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7(u32);
};

namespace nn {
namespace pia {
namespace lan {
class LanUpdateSessionSetting {
public:
    u32 vf4();
    void vf5();
    u32 vf6();
    bool vf7(u32 value);
    void vf8();
};
}  // namespace lan
}  // namespace pia
}  // namespace nn

// 0x710167bb10
u32 nn::pia::lan::LanUpdateSessionSetting::vf4() {
    const Unk_167bb10* self = reinterpret_cast<const Unk_167bb10*>(this);
    return self->field_1ac;
}

// 0x710167bb20
void nn::pia::lan::LanUpdateSessionSetting::vf5() {
}

// 0x7101735d80
u32 nn::pia::lan::LanUpdateSessionSetting::vf6() {
    const Unk_1735d80* self = reinterpret_cast<const Unk_1735d80*>(this);
    return self->field_8;
}

// 0x7101735d90
bool nn::pia::lan::LanUpdateSessionSetting::vf7(u32 value) {
    const Unk_1735d90* self = reinterpret_cast<const Unk_1735d90*>(this);
    return (self->field_8 & (1 << value)) != 0;
}

// 0x7101735db0
void nn::pia::lan::LanUpdateSessionSetting::vf8() {
    Unk_1735db0* self = reinterpret_cast<Unk_1735db0*>(this);
    self->vf7(1);
}
