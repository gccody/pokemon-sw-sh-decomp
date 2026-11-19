// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3pia5local21LdnJoinSessionSettingE
#include <types.h>

struct Unk_168bf30_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

struct Unk_168bf30 {
    u8 _0[0x8];
    Unk_168bf30_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_168bf30, field_8, 0x8);

struct Unk_167c380 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_167c380, field_58, 0x58);

namespace nn {
namespace pia {
namespace local {
class LdnJoinSessionSetting {
public:
    void vf3();
    void vf4();
    const u8* vf9();
};
}  // namespace local
}  // namespace pia
}  // namespace nn

// 0x710167c380
const u8* nn::pia::local::LdnJoinSessionSetting::vf9() {
    const Unk_167c380* self = reinterpret_cast<const Unk_167c380*>(this);
    return &self->field_58;
}

// 0x710168bf20
void nn::pia::local::LdnJoinSessionSetting::vf3() {
}

// 0x710168bf30
void nn::pia::local::LdnJoinSessionSetting::vf4() {
    const Unk_168bf30* self = reinterpret_cast<const Unk_168bf30*>(this);
    if (self->field_8 != nullptr) {
        self->field_8->vf3();
    }
}
