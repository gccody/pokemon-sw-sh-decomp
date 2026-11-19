// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK320SiGfxFreeTypeManagerE
#include <types.h>

struct Unk_50c3b0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_50c3b0, field_10, 0x10);

namespace SiSDK3 {
class SiGfxFreeTypeManager {
public:
    u32 vf4();
    u32 vf5();
    void vf6();
    void vf7();
    void vf8();
    void vf9();
    void vf10();
    void vf11();
    void vf12();
};
}  // namespace SiSDK3

// 0x710050b0c0
u32 SiSDK3::SiGfxFreeTypeManager::vf5() {
    return 1;
}

// 0x710050b0d0
void SiSDK3::SiGfxFreeTypeManager::vf6() {
}

// 0x710050c2b0
void SiSDK3::SiGfxFreeTypeManager::vf7() {
}

// 0x710050c2c0
void SiSDK3::SiGfxFreeTypeManager::vf8() {
}

// 0x710050c2d0
void SiSDK3::SiGfxFreeTypeManager::vf9() {
}

// 0x710050c2e0
void SiSDK3::SiGfxFreeTypeManager::vf10() {
}

// 0x710050c2f0
void SiSDK3::SiGfxFreeTypeManager::vf11() {
}

// 0x710050c300
void SiSDK3::SiGfxFreeTypeManager::vf12() {
}

// 0x710050c3b0
u32 SiSDK3::SiGfxFreeTypeManager::vf4() {
    const Unk_50c3b0* self = reinterpret_cast<const Unk_50c3b0*>(this);
    return self->field_10;
}
