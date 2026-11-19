// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK314SiGfxNXManagerE
#include <types.h>

struct Unk_4f6f00 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_4f6f00, field_10, 0x10);

struct Unk_4f6c50 {
    u8 _0[0x70];
    u64 field_70;
};
PKMN_OFFSET_ASSERT(Unk_4f6c50, field_70, 0x70);

struct Unk_4f6c60 {
    u8 _0[0x68];
    u32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_4f6c60, field_68, 0x68);

namespace SiSDK3 {
class SiGfxNXManager {
public:
    u32 vf4();
    u64 vf6();
    u32 vf7();
};
}  // namespace SiSDK3

// 0x71004f6c50
u64 SiSDK3::SiGfxNXManager::vf6() {
    const Unk_4f6c50* self = reinterpret_cast<const Unk_4f6c50*>(this);
    return self->field_70;
}

// 0x71004f6c60
u32 SiSDK3::SiGfxNXManager::vf7() {
    const Unk_4f6c60* self = reinterpret_cast<const Unk_4f6c60*>(this);
    return self->field_68;
}

// 0x71004f6f00
u32 SiSDK3::SiGfxNXManager::vf4() {
    const Unk_4f6f00* self = reinterpret_cast<const Unk_4f6f00*>(this);
    return self->field_10;
}
