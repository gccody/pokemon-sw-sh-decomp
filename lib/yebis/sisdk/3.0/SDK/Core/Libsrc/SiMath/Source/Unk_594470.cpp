// Scope: common
// SiMath's initialisation and exit (placeholder file and names: the
// functions of a translation unit of their own, which call the kernel's
// getter).
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiMath/Source/SiMath_Kernel_Impl.h>

// 0x71004cad50, 0x71004cadb0: what SiMath is initialised after, and its reverse
bool Unk_4cad50(SiSDK3::ISiAllocator* pAllocator);
void Unk_4cadb0();
// 0x71005947c0 (leafgen's name): the kernel
SiSDK3::SiMathKernel* Unk_5947c0();

// 0x7100594470
bool Unk_594470(SiSDK3::ISiAllocator* pAllocator) {
    if (!Unk_4cad50(pAllocator)) {
        return false;
    }
    return Unk_5947c0()->Unk_594960(pAllocator);
}

// 0x71005944b0 (leafgen's name)
void Unk_5944b0_call() {
    Unk_5947c0()->Unk_594b10();
    Unk_4cadb0();
}
