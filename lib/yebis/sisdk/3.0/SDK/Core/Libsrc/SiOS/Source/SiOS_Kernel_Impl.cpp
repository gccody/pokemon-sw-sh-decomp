// Scope: common
// SiSDK3::SiOSKernel: its singleton, construction, destruction,
// initialisation and factory.
#define UNK_SIOS_KERNEL_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiOS/Source/SiOS_Kernel_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiOS/Source/SiOS_SharedMemory_Impl.h>

// 0x71004c5930: a number as a string
void Unk_4c5930(char* dst, size_t size, u64 value);
// 0x71005967f0: SiOS's texts for a language
const void* Unk_5967f0(const Unk_4ca820_arg0& language);

// 0x7101f072e0: the id of SiOS's string table
extern const u8 Unk_1f072e0[] __attribute__((visibility("hidden")));

// 0x7102771340: the kernel (this translation unit's own variable in the
// original, read without the GOT)
extern SiSDK3::SiOSKernel* Unk_2771340 __attribute__((visibility("hidden")));

// The kernel, made the first time it's asked for.
// 0x7100595960
SiSDK3::SiOSKernel* Unk_595960() {
    static SiSDK3::SiOSKernel kernel;
    return &kernel;
}

namespace SiSDK3 {

// 0x71005959e0
// (the kernel's allocator is asked for each time it's used: a macro's argument)
#define UNK_ALLOCATOR Unk_GetKernel()->vf12()
SiOSKernel::SiOSKernel()
    : field_8(UNK_ALLOCATOR), field_18(nullptr), field_20(0), field_28(0), field_30(nullptr), field_38(nullptr) {
    Unk_2771340 = this;
    if (UNK_ALLOCATOR != nullptr) {
        UNK_ALLOCATOR->vf2();
    }
    if (field_18 != nullptr) {
        field_18->vf3();
    }
    field_18 = UNK_ALLOCATOR;
    field_40 = nullptr;
    field_48 = nullptr;
}
#undef UNK_ALLOCATOR

// 0x7100595aa0 (D2), 0x7100595bb0 (D0)
SiOSKernel::~SiOSKernel() {
    Unk_595ae0();
    Unk_2771340 = nullptr;
}

// 0x7100595ae0
void SiOSKernel::Unk_595ae0() {
    if (field_20 == 0) {
        return;
    }
    field_20--;
    if (field_20 != 0) {
        return;
    }
    if (field_40 != nullptr) {
        field_40->vf3();
        field_40 = nullptr;
    }
    if (field_48 != nullptr) {
        field_48->vf3();
        field_48 = nullptr;
    }
    if (field_38 != nullptr) {
        field_38->vf3();
        field_38 = nullptr;
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

// 0x7100595c00
bool SiOSKernel::Unk_595c00(ISiAllocator* pAllocator) {
    field_20++;
    if (field_20 != 1) {
        return true;
    }
    if (pAllocator != nullptr) {
        vf5(pAllocator);
    } else if (field_18 == nullptr) {
        vf5(Unk_GetKernel()->vf12());
    }
    Unk_595cc0();
    Unk_57d2a0_Info info;
    field_18->vf11(&info);
    char used[0x80];
    Unk_4c5930(used, sizeof(used), info.field_8);
    char total[0x80];
    Unk_4c5930(total, sizeof(total), info.field_28);
    return true;
}

// 0x7100595cc0
bool SiOSKernel::Unk_595cc0() {
    field_30 = Unk_GetKernel()->vf23(nullptr);
    field_30->vf8();
    field_30->vf11(Unk_4ca820_arg0(), Unk_5967f0(Unk_4ca820_arg0()));
    field_30->vf11(*Unk_GetKernel()->vf24(), Unk_5967f0(*Unk_GetKernel()->vf24()));
    field_30->vf9();
    Unk_GetKernel()->vf26(Unk_1f072e0, field_30);
    return true;
}

// 0x7100595db0
void SiOSKernel::vf5(ISiAllocator* pAllocator) {
    if (pAllocator != nullptr) {
        pAllocator->vf2();
    }
    if (field_18 != nullptr) {
        field_18->vf3();
    }
    field_18 = pAllocator;
}

// 0x7100595e20
SiOSSharedMemory* SiOSKernel::vf8(ISiAllocator* pAllocator) {
    if (pAllocator == nullptr) {
        pAllocator = vf6();
    }
#line 314
    return UNK_SI_NEW(pAllocator, 0x10) SiOSSharedMemory(pAllocator);
}

// 0x7100595e90
bool SiOSKernel::vf9(ISiInterface* object) {
    if (object != nullptr) {
        object->vf2();
    }
    if (field_38 != nullptr) {
        field_38->vf3();
    }
    field_38 = object;
    return true;
}

// 0x7100595ef0
bool SiOSKernel::vf11(s32 index, ISiInterface* object) {
    if (index == 0) {
        if (object != nullptr) {
            object->vf2();
        }
        if (field_40 != nullptr) {
            field_40->vf3();
        }
        field_40 = object;
    } else if (index == 1) {
        if (object != nullptr) {
            object->vf2();
        }
        if (field_48 != nullptr) {
            field_48->vf3();
        }
        field_48 = object;
    }
    return true;
}

// 0x7100595f70
ISiInterface* SiOSKernel::vf12(s32 index) {
    if (index == 0) {
        return field_40;
    }
    if (index == 1) {
        return field_48;
    }
    return nullptr;
}

}  // namespace SiSDK3
