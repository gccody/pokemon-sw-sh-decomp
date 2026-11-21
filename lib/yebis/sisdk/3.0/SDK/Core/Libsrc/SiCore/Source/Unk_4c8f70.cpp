// Scope: common
// SiCore's ids and its tick period: the first functions of the TU that ends
// with the static initialiser 0x71004ca620 (lib/yebis/static). The file's
// name isn't in the executable.
#include <nn/os.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Guid.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

// 0x71004c8f70
SiSDK3::SI_GUID Unk_4c8f70() {
    SiSDK3::SI_GUID id = {};
    return id;
}

// 0x71004c8f80
bool Unk_4c8f80(const void* a, const void* b) {
    const SiSDK3::SI_GUID* pA = static_cast<const SiSDK3::SI_GUID*>(a);
    const SiSDK3::SI_GUID* pB = static_cast<const SiSDK3::SI_GUID*>(b);
    for (int i = 0; i < 16; i++) {
        if (pA->field_0[i] != pB->field_0[i]) {
            return false;
        }
    }
    return true;
}

// 0x710276ba98: how long a system tick is, in seconds
double Unk_276ba98 __attribute__((visibility("hidden")));

// 0x71004c9300
void Unk_4c9300() {
    nn::os::GetSystemTick();
    SiSDK3::Unk_SystemInfoInterface* pInfo = SiSDK3::Unk_GetKernel()->vf15();
    if (pInfo != nullptr && *pInfo->vf5() > 0) {
        Unk_276ba98 = 1.0 / static_cast<double>(*pInfo->vf5());
    }
}

// 0x71004c9110: the noise of a point (not written: 344 bytes of float code)
float Unk_4c9110(float x, float y);

// 0x71004c9270: the noise's octaves, each at twice the frequency and half the
// weight of the one before
float Unk_4c9270(float x, float y, int octaves) {
    float sum = 0.0f;
    float scale = 1.0f;
    for (int i = 0; i < octaves; i++) {
        sum += scale * Unk_4c9110(x, y);
        scale *= 0.5f;
        x *= 2.0f;
        y *= 2.0f;
    }
    return sum;
}
