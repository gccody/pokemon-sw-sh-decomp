// Scope: common
// SiSDK3::SiMathKernel: its singleton, construction, destruction and
// initialisation.
#define UNK_SIMATH_KERNEL_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiMath/Source/SiMath_Kernel_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

// 0x71004c5930: a number as a string
void Unk_4c5930(char* dst, size_t size, u64 value);

// 0x71005952e0: SiMath's texts for a language
const void* Unk_5952e0(const Unk_4ca820_arg0& language);

// 0x7101f07288: the id of SiMath's string table
extern const u8 Unk_1f07288[] __attribute__((visibility("hidden")));

// 0x7102770e50: the kernel (this translation unit's own variable in the
// original, read without the GOT)
extern SiSDK3::SiMathKernel* Unk_2770e50 __attribute__((visibility("hidden")));

// The kernel, made the first time it's asked for (leafgen's name).
// 0x71005947c0
SiSDK3::SiMathKernel* Unk_5947c0() {
    static SiSDK3::SiMathKernel kernel;
    return &kernel;
}

namespace SiSDK3 {

// 0x7100594840
// (the kernel's allocator is asked for each time it's used: a macro's argument)
#define UNK_ALLOCATOR Unk_GetKernel()->vf12()
SiMathKernel::SiMathKernel() : field_8(UNK_ALLOCATOR), field_18(nullptr), field_20(0), field_28(0), field_30(nullptr) {
    Unk_2770e50 = this;
    if (UNK_ALLOCATOR != nullptr) {
        UNK_ALLOCATOR->vf2();
    }
    if (field_18 != nullptr) {
        field_18->vf3();
    }
    field_18 = UNK_ALLOCATOR;
}
#undef UNK_ALLOCATOR

// 0x7100594900 (D2), 0x7100594920 (D0)
SiMathKernel::~SiMathKernel() {
    Unk_2770e50 = nullptr;
}

// 0x7100594960
bool SiMathKernel::Unk_594960(ISiAllocator* pAllocator) {
    field_20++;
    if (field_20 != 1) {
        return true;
    }
    if (pAllocator != nullptr) {
        vf5(pAllocator);
    } else if (field_18 == nullptr) {
        vf5(Unk_GetKernel()->vf12());
    }
    Unk_594a20();
    Unk_57d2a0_Info info;
    field_18->vf11(&info);
    char used[0x80];
    Unk_4c5930(used, sizeof(used), info.field_8);
    char total[0x80];
    Unk_4c5930(total, sizeof(total), info.field_28);
    return true;
}

// 0x7100594a20
bool SiMathKernel::Unk_594a20() {
    field_30 = Unk_GetKernel()->vf23(nullptr);
    field_30->vf8();
    field_30->vf11(Unk_4ca820_arg0(), Unk_5952e0(Unk_4ca820_arg0()));
    field_30->vf11(*Unk_GetKernel()->vf24(), Unk_5952e0(*Unk_GetKernel()->vf24()));
    field_30->vf9();
    Unk_GetKernel()->vf26(Unk_1f07288, field_30);
    return true;
}

// 0x7100594b10
void SiMathKernel::Unk_594b10() {
    if (field_20 == 0) {
        return;
    }
    field_20--;
    if (field_20 != 0) {
        return;
    }
    Unk_GetKernel()->vf27(field_30);
    if (field_30 != nullptr) {
        field_30->vf3();
        field_30 = nullptr;
    }
    if (field_18 != nullptr) {
        field_18->vf3();
        field_18 = nullptr;
    }
}

// 0x7100594b90
void SiMathKernel::vf5(ISiAllocator* pAllocator) {
    if (pAllocator != nullptr) {
        pAllocator->vf2();
    }
    if (field_18 != nullptr) {
        field_18->vf3();
    }
    field_18 = pAllocator;
}

}  // namespace SiSDK3
