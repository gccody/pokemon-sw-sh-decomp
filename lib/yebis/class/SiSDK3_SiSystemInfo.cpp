// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_4c8ee0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_4c8ee0, field_10, 0x10);

struct Unk_4c8d30 {
    u8 _0[0x178];
    u8 field_178;
};
PKMN_OFFSET_ASSERT(Unk_4c8d30, field_178, 0x178);

struct Unk_4c8e20 {
    u8 _0[0x148];
    u8 field_148;
};
PKMN_OFFSET_ASSERT(Unk_4c8e20, field_148, 0x148);

struct Unk_4c8e30 {
    u8 _0[0x118];
    u8 field_118;
};
PKMN_OFFSET_ASSERT(Unk_4c8e30, field_118, 0x118);

namespace SiSDK3 {
class SiSystemInfo {
public:
    u32 vf4();
    const u8* vf5();
    u64 vf8();
    u64 vf9();
    const u8* vf10();
    const u8* vf11();
};
}  // namespace SiSDK3

// 0x71004c8d30
const u8* SiSDK3::SiSystemInfo::vf5() {
    const Unk_4c8d30* self = reinterpret_cast<const Unk_4c8d30*>(this);
    return &self->field_178;
}

// 0x71004c8e00
u64 SiSDK3::SiSystemInfo::vf8() {
    return 0;
}

// 0x71004c8e10
u64 SiSDK3::SiSystemInfo::vf9() {
    return 0;
}

// 0x71004c8e20
const u8* SiSDK3::SiSystemInfo::vf10() {
    const Unk_4c8e20* self = reinterpret_cast<const Unk_4c8e20*>(this);
    return &self->field_148;
}

// 0x71004c8e30
const u8* SiSDK3::SiSystemInfo::vf11() {
    const Unk_4c8e30* self = reinterpret_cast<const Unk_4c8e30*>(this);
    return &self->field_118;
}

// 0x71004c8ee0
u32 SiSDK3::SiSystemInfo::vf4() {
    const Unk_4c8ee0* self = reinterpret_cast<const Unk_4c8ee0*>(this);
    return self->field_10;
}
