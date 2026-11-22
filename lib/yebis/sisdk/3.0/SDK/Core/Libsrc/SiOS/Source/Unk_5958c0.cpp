// Scope: common
// SiOS's initialisation and exit (placeholder file and names: the functions
// of a translation unit of their own, which lock around the kernel's).
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Reflection.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiOS/Source/SiOS_Kernel_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiOS/Source/Unk_596410.h>

// 0x71004cad50, 0x71004cadb0: what SiOS is initialised after, and its reverse
bool Unk_4cad50(SiSDK3::ISiAllocator* pAllocator);
void Unk_4cadb0();
// 0x7100595960: the kernel
SiSDK3::SiOSKernel* Unk_595960();

// 0x7102771220
static SiSDK3::SiReflectionPropertyHandle Unk_2771220;

// 0x7102771298: what the two functions lock
SiSDK3::SiOSCriticalSection Unk_2771298(0);

// 0x7100595810
bool Unk_595810(SiSDK3::ISiAllocator* pAllocator) {
    if (!Unk_4cad50(pAllocator)) {
        return false;
    }
    Unk_596640 lock(&Unk_2771298, true);
    return Unk_595960()->Unk_595c00(pAllocator);
}

// 0x7100595880
void Unk_595880() {
    {
        Unk_596640 lock(&Unk_2771298, true);
        Unk_595960()->Unk_595ae0();
    }
    Unk_4cadb0();
}

// 0x71005958c0: _GLOBAL__sub_I_Unk_5958c0.cpp
