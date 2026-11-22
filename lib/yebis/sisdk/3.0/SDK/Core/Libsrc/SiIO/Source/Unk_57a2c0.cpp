// Scope: common
// SiIO's initialisation and exit (placeholder file and names: the functions
// of a translation unit of their own, which call the kernel's getter).
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_Kernel_Impl.h>

// 0x71004cad50, 0x71004cadb0: what SiIO is initialised after, and its reverse
bool Unk_4cad50(SiSDK3::ISiAllocator* pAllocator);
void Unk_4cadb0();
// 0x710057cfb0 (leafgen's name): the kernel
SiSDK3::SiIOKernel* Unk_57cfb0();

// 0x710057a2c0
bool Unk_57a2c0(SiSDK3::ISiAllocator* pAllocator) {
    if (!Unk_4cad50(pAllocator)) {
        return false;
    }
    return Unk_57cfb0()->Unk_57d2a0(pAllocator);
}

// 0x710057a300 (leafgen's name)
void Unk_57a300_call() {
    Unk_57cfb0()->Unk_57d4e0();
    Unk_4cadb0();
}
