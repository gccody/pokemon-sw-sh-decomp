// Scope: common
// SiCore's allocator of choice: the kernel's, or the static SiHeapAllocator.
// The file's name isn't in the executable. Its static initialiser,
// 0x71004bc6c0 (_GLOBAL__sub_I_Unk_4bc640.cpp), constructs the TU's
// SiReflectionPropertyHandle, whose array asks for that allocator inline.
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Reflection.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

namespace SiSDK3 {
class SiHeapAllocator;
}

// 0x71024e8f38: the static allocator (Unk_4c2cd0.cpp)
extern SiSDK3::SiHeapAllocator Unk_24e8f38;

// 0x71004bc690
SiSDK3::ISiAllocator* Unk_4bc690() {
    if (SiSDK3::Unk_GetKernel() == nullptr) {
        return nullptr;
    }
    return SiSDK3::Unk_GetKernel()->vf12();
}

// 0x71004bc640
SiSDK3::ISiAllocator* Unk_4bc640() {
    SiSDK3::ISiAllocator* pAllocator = reinterpret_cast<SiSDK3::ISiAllocator*>(&Unk_24e8f38);
    if (SiSDK3::Unk_GetKernel() != nullptr) {
        SiSDK3::ISiAllocator* pKernelAllocator = SiSDK3::Unk_GetKernel()->vf12();
        if (pKernelAllocator != nullptr) {
            pAllocator = pKernelAllocator;
        }
    }
    return pAllocator;
}

// 0x71024e7c70
static SiSDK3::SiReflectionPropertyHandle Unk_24e7c70;

// 0x71024e8f30 (lib/yebis/class's SiKernel reads and writes it)
extern u64 Unk_24e8f30;

// 0x71004bc760 (the next TU's only function: its static initialiser is
// lib/yebis/static/Unk_4bc770.cpp)
void Unk_4bc760(u64 value) {
    Unk_24e8f30 = value;
}
