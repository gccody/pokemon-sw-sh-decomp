// Scope: common
// SiMath's initialisation (placeholder file and name: a function of its own
// translation unit, which calls the kernel's getter).
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiMath/Source/SiMath_Kernel_Impl.h>

// 0x71004cad50: what SiMath is initialised after
bool Unk_4cad50();
// 0x71005947c0 (leafgen's name): the kernel
SiSDK3::SiMathKernel* Unk_5947c0();

// 0x7100594470
bool Unk_594470(SiSDK3::ISiAllocator* pAllocator) {
    if (!Unk_4cad50()) {
        return false;
    }
    return Unk_5947c0()->Unk_594960(pAllocator);
}
