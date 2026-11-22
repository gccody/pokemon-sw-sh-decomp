// Scope: common
// SiSDK3::SiGfxNXFreeTypeManager: its construction and destruction and the
// slots that add to its base's (a placeholder file: the translation unit's
// name isn't in the executable).
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_551300.h>

// Drops a reference and clears the pointer (placeholder name).
#define UNK_SAFE_RELEASE(p)   \
    if ((p) != nullptr) {     \
        (p)->vf3();           \
        (p) = nullptr;        \
    }

namespace SiSDK3 {

// 0x7100551300
SiGfxNXFreeTypeManager::SiGfxNXFreeTypeManager(SiGfxNXDevice* pDevice)
    : SiGfxFreeTypeManager(pDevice), field_58(nullptr), field_60(0), field_68(nullptr), field_70(nullptr) {}

// 0x7100551340 (D2), 0x71005513c0 (D0)
SiGfxNXFreeTypeManager::~SiGfxNXFreeTypeManager() {
    SiGfxNXFreeTypeManager::vf6();
    vf14();
    field_58 = nullptr;
}

// 0x7100551450
void SiGfxNXFreeTypeManager::vf5() {
    SiGfxFreeTypeManager::vf5();
}

// 0x7100551460
void SiGfxNXFreeTypeManager::vf6() {
    UNK_SAFE_RELEASE(field_70);
    UNK_SAFE_RELEASE(field_68);
    field_58 = nullptr;
    SiGfxFreeTypeManager::vf6();
}

// 0x7100551770
void SiGfxNXFreeTypeManager::vf7() {
    SiGfxFreeTypeManager::vf7();
    field_58 = nullptr;
    field_58 = Unk_NXDevice(field_18)->vf46(0x44);
    Unk_5514c0();
}

// 0x71005517b0
void SiGfxNXFreeTypeManager::vf8() {
    UNK_SAFE_RELEASE(field_70);
    UNK_SAFE_RELEASE(field_68);
    field_58 = nullptr;
    SiGfxFreeTypeManager::vf8();
}

// 0x7100551810
void SiGfxNXFreeTypeManager::vf9() {
    SiGfxFreeTypeManager::vf9();
}

// 0x7100551820
void SiGfxNXFreeTypeManager::vf10() {
    SiGfxFreeTypeManager::vf10();
}

// 0x7100551830
void SiGfxNXFreeTypeManager::vf11() {
    SiGfxFreeTypeManager::vf11();
}

// 0x7100551840
void SiGfxNXFreeTypeManager::vf12() {
    SiGfxFreeTypeManager::vf12();
}

}  // namespace SiSDK3
