// Scope: common
// SiIO's initialisation (placeholder file and name: a function of its own
// translation unit, which calls the kernel's getter).
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_Kernel_Impl.h>

// 0x71004cad50: what SiIO is initialised after
bool Unk_4cad50();
// 0x710057cfb0 (leafgen's name): the kernel
SiSDK3::SiIOKernel* Unk_57cfb0();

// 0x710057a2c0
bool Unk_57a2c0(SiSDK3::ISiAllocator* pAllocator) {
    if (!Unk_4cad50()) {
        return false;
    }
    return Unk_57cfb0()->Unk_57d2a0(pAllocator);
}
