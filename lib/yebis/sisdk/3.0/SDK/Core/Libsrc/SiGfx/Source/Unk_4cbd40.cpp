// Scope: common
// SiGfx's initialisation and exit (placeholder file and names: the functions
// of a translation unit of their own, which lock around the kernel's), like
// SiOS's (SiOS/Source/Unk_5958c0.cpp).
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Reflection.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_Kernel_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiOS/Source/Unk_596410.h>

// 0x71004cad50, 0x71004cadb0: what SiCore is initialised with, and its reverse
bool Unk_4cad50(SiSDK3::ISiAllocator* pAllocator);
void Unk_4cadb0();
// 0x7100594470, 0x71005944b0: SiMath's
bool Unk_594470(SiSDK3::ISiAllocator* pAllocator);
void Unk_5944b0_call();
// 0x7100595810, 0x7100595880: SiOS's
bool Unk_595810(SiSDK3::ISiAllocator* pAllocator);
void Unk_595880();
// 0x710057a2c0, 0x710057a300: SiIO's
bool Unk_57a2c0(SiSDK3::ISiAllocator* pAllocator);
void Unk_57a300_call();
// 0x71004cbec0: the kernel
void* Unk_4cbec0();

// 0x710276cec8
static SiSDK3::SiReflectionPropertyHandle Unk_276cec8;

// 0x710276cf40: what the two functions lock
SiSDK3::SiOSCriticalSection Unk_276cf40(0);

// 0x71004cbd40
bool Unk_4cbd40(SiSDK3::ISiAllocator* pAllocator) {
    if (!Unk_4cad50(pAllocator)) {
        return false;
    }
    if (!Unk_594470(pAllocator)) {
        return false;
    }
    if (!Unk_595810(pAllocator)) {
        return false;
    }
    if (!Unk_57a2c0(pAllocator)) {
        return false;
    }
    Unk_596640 lock(&Unk_276cf40, true);
    return static_cast<SiSDK3::SiGfxKernel*>(Unk_4cbec0())->Unk_4ccb30(pAllocator);
}

// 0x71004cbdd0
void Unk_4cbdd0() {
    {
        Unk_596640 lock(&Unk_276cf40, true);
        static_cast<SiSDK3::SiGfxKernel*>(Unk_4cbec0())->Unk_4cc450();
    }
    Unk_57a300_call();
    Unk_595880();
    Unk_5944b0_call();
    Unk_4cadb0();
}

// 0x71004cbe20: _GLOBAL__sub_I_Unk_4cbd40.cpp
